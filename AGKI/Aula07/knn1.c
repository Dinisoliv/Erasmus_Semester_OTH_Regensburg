#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef enum distance {MANHATTAN, EUCLIDEAN} distance;

typedef struct {
    double dist;
    int label;
} Neighbor;
    
/**
 * Read CSV file
 */
int read_csv(char* filename, int n, int d, double x[n][d], int y[n]) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("%s cannot be found\n", filename);
        exit(2);
    }
    char line[65536];
    fgets(line, 65536, f); // discard header

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            int ret = fscanf(f, "%lf,", &x[i][j]);
            if (ret == EOF) {
                fclose(f);
                return i;
            }
        }
        int ret = fscanf(f, "%d", &y[i]);
        if (ret == EOF) {
            fclose(f);
            return i;
        }
    }
    fclose(f);
    return n;
}

void copy_instance(int d, double src[d], double tgt[d]) {
    for (int i = 0; i < d; i++)
        tgt[i] = src[i];
}

/**
 * Split dataset (LOO)
 */
void split_train_test(int test, int n, int d,
                      double full_x[n][d], const int full_y[n],
                      double train_x[n-1][d], int train_y[n-1],
                      double test_x[d], int* test_y) {
    int i = 0, j = 0;

    while (i < n) {
        if (i == test) {
            copy_instance(d, full_x[i], test_x);
            *test_y = full_y[i];
            i++;
        } else {
            copy_instance(d, full_x[i], train_x[j]);
            train_y[j] = full_y[i];
            i++;
            j++;
        }
    }
}

/**
 * Distance
 */
double distance_between(int d, double a[d], double b[d], distance dist) {
    double sum = 0.0;

    if (dist == MANHATTAN) {
        for (int i = 0; i < d; i++)
            sum += fabs(a[i] - b[i]);
        return sum;
    }

    // Euclidean
    for (int i = 0; i < d; i++)
        sum += (a[i] - b[i]) * (a[i] - b[i]);

    return sqrt(sum);
}

/**
 * k-NN classifier supporting ANY NUMBER OF CLASSES
 */
int classify_knn(int n_train, int d,
                 double train_x[n_train][d], int train_y[n_train],
                 double test_x[d], int k, distance dist) {

    Neighbor neighbors[n_train];

    // compute distances
    for (int i = 0; i < n_train; i++) {
        neighbors[i].dist = distance_between(d, train_x[i], test_x, dist);
        neighbors[i].label = train_y[i];
    }

    int max_class = -1;

    // sort neighbors by ascending distance
    for (int i = 0; i < n_train - 1; i++) {
        if (train_y[i] > max_class) max_class = train_y[i]; // find max class label
        for (int j = i + 1; j < n_train; j++) {
            if (neighbors[j].dist < neighbors[i].dist) {
                Neighbor tmp = neighbors[i];
                neighbors[i] = neighbors[j];
                neighbors[j] = tmp;
            }
        }
    }

    // ---------- Majority voting for ANY number of classes ----------
    int num_classes = max_class + 1;

    // allocate freq counter
    int* votes = calloc(num_classes, sizeof(int));
    if (votes == NULL) {
        printf("Memory allocation error\n");
        exit(3);
    }

    // vote using first k neighbors
    for (int i = 0; i < k; i++) {
        int label = neighbors[i].label;
        if (label >= 0 && label < num_classes)
            votes[label]++;
    }

    // find class with maximum votes
    int best_class = 0;
    int best_votes = votes[0];

    for (int c = 1; c < num_classes; c++) {
        if (votes[c] > best_votes) {
            best_votes = votes[c];
            best_class = c;
        }
    }

    free(votes);
    return best_class;
}

/**
 * LOO experiment
 */
int loo_knn_experiment(int n, int d, double full_x[n][d], int full_y[n],
                       int k, distance dist) {

    double train_x[n-1][d];
    int train_y[n-1];
    double test_x[d];
    int test_y;

    int correctly_classified = 0;

    for (int i = 0; i < n; i++) {
        split_train_test(i, n, d, full_x, full_y,
                         train_x, train_y, test_x, &test_y);

        int pred = classify_knn(n-1, d, train_x, train_y, test_x, k, dist);
        if (pred == test_y)
            correctly_classified++;
    }

    return correctly_classified;
}

/**
 * CLI checker
 */
void check_usage(int argc, char** argv) {
    if (argc != 6) {
        printf("Usage: %s <n> <d> <file.csv> <k> <manhattan|euclidean>\n", argv[0]);
        exit(1);
    }
}

/**
 * MAIN
 */
int main(int argc, char** argv) {
    check_usage(argc, argv);

    int n = atoi(argv[1]);
    int d = atoi(argv[2]);
    char* filename = argv[3];
    int k = atoi(argv[4]);
    distance dist =
        (strcmp(argv[5], "manhattan") == 0) ? MANHATTAN : EUCLIDEAN;

    double x[n][d];
    int y[n];

    n = read_csv(filename, n, d, x, y);

    int correct = loo_knn_experiment(n, d, x, y, k, dist);

    printf("%d out of %d correct (accuracy = %f)\n",
           correct, n, (float) correct / n);
    return 0;
}
