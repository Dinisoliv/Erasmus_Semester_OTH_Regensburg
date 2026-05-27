#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LINE 5000
#define EPS 1e-9      // very small number to avoid division by zero

// ----------------------- Distance Functions -----------------------
double euclidean(double *a, double *b, int d) {
    double sum = 0.0;
    for (int i = 0; i < d; i++)
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    return sqrt(sum);
}

double manhattan(double *a, double *b, int d) {
    double sum = 0.0;
    for (int i = 0; i < d; i++)
        sum += fabs(a[i] - b[i]);
    return sum;
}

// ----------------------- Distance Record -----------------------
typedef struct {
    double dist;
    int label;
} Neighbor;

// sort by distance
int cmp(const void *x, const void *y) {
    double a = ((Neighbor*)x)->dist;
    double b = ((Neighbor*)y)->dist;
    return (a > b) - (a < b);
}

// ----------------------- Weighted KNN -----------------------
int weighted_knn(Neighbor *N, int k, int num_classes) {
    double *class_weight = calloc(num_classes, sizeof(double));

    for (int i = 0; i < k; i++) {
        double w = 1.0 / (N[i].dist + EPS);   // Weighted vote
        class_weight[N[i].label] += w;
    }

    // pick class with highest total weight
    int best = 0;
    for (int c = 1; c < num_classes; c++)
        if (class_weight[c] > class_weight[best])
            best = c;

    free(class_weight);
    return best;
}

// ----------------------- Main Program -----------------------
int main(int argc, char **argv) {

    if (argc != 6) {
        printf("Usage: ./knn <N> <D> <file.csv> <k> <distance>\n");
        return 1;
    }

    int N = atoi(argv[1]);
    int D = atoi(argv[2]);
    char *fname = argv[3];
    int k = atoi(argv[4]);
    char *dist_name = argv[5];

    double (*distf)(double*,double*,int);
    if (strcmp(dist_name,"euclidean")==0)
        distf = euclidean;
    else if (strcmp(dist_name,"manhattan")==0)
        distf = manhattan;
    else {
        printf("Unknown distance\n");
        return 1;
    }

    // ----------------------- Read CSV -----------------------
    FILE *f = fopen(fname,"r");
    if (!f) { printf("Error opening file\n"); return 1; }

    double **X = malloc(N * sizeof(double*));
    int *Y = malloc(N * sizeof(int));

    char line[MAX_LINE];
    fgets(line, MAX_LINE, f); // skip header

    for (int i=0; i<N; i++) {
        X[i] = malloc(D * sizeof(double));

        for (int j=0; j<D; j++)
            fscanf(f, "%lf,", &X[i][j]);

        fscanf(f, "%d", &Y[i]);
    }
    fclose(f);

    // ----------------------- Classification -----------------------
    int correct = 0;
    Neighbor *neighbors = malloc(N * sizeof(Neighbor));

    for (int test = 0; test < N; test++) {

        for (int i = 0; i < N; i++) {
            if (i == test) {
                neighbors[i].dist = 1e9;
                neighbors[i].label = -1;
            } else {
                neighbors[i].dist = distf(X[test], X[i], D);
                neighbors[i].label = Y[i];
            }
        }

        qsort(neighbors, N, sizeof(Neighbor), cmp);

        int pred = weighted_knn(neighbors, k, 10); // MNIST has 10 classes
        if (pred == Y[test]) correct++;
    }

    printf("%d out of %d correct (accuracy = %.6f)\n",
           correct, N, (double)correct / N);

    return 0;
}
