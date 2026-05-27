#include <assert.h>
#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h>
#include <stdbool.h>
#include "distance.h"
#include "ioutils.h"
#include "misclassifications.h"

void cluster(int n, int d, double x[n][d], int y[n], int k, double centroids[k][d], distance dist);

void initialize_cluster_assignment(int n, int y[n], int value) {
    for (int i = 0; i < n; i++) {
        y[i] = value;
    }
}

void copy_cluster_assignment(int n, const int from_y[n], int to_y[n]) {
    for (int i = 0; i < n; i++) {
        to_y[i] = from_y[i];
    }
}

bool is_identical_cluster_assignment(int n, const int a[n], const int b[n]) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

/* return a truly uniform random value in the range 0..n-1 inclusive */
int rand_in_range(int n) {
    int limit;
    int r;
    limit = RAND_MAX - (RAND_MAX % n);
    while((r = rand()) >= limit);
    return r % n;
}

bool tests() {
    // --- Test initialize_cluster_assignment ---
    {
        int y[5];
        initialize_cluster_assignment(5, y, -1);
        for (int i = 0; i < 5; i++)
            assert(y[i] == -1);
    }

    // --- Test copy_cluster_assignment ---
    {
        int from[4] = {1, 2, 3, 4};
        int to[4] = {0, 0, 0, 0};
        copy_cluster_assignment(4, from, to);
        for (int i = 0; i < 4; i++)
            assert(to[i] == from[i]);
    }

    // --- Test is_identical_cluster_assignment ---
    {
        int a[3] = {1, 2, 3};
        int b[3] = {1, 2, 3};
        int c[3] = {1, 2, 4};
        assert(is_identical_cluster_assignment(3, a, b) == true);
        assert(is_identical_cluster_assignment(3, a, c) == false);
    }

    // --- Test rand_in_range ---
    {
        int n = 10;
        for (int i = 0; i < 1000; i++) {
            int r = rand_in_range(n);
            assert(r >= 0 && r < n);
        }
    }

    printf("All tests passed successfully!\n");
    return true;
}


void cluster(int n, int d,
             double x[n][d],
             int y[n],
             int k,
             double centroids[k][d],
             distance dist) {

    int used[n];
    memset(used, 0, sizeof(used));

    // --- initialize centroids with random distinct points ---
    for (int c = 0; c < k; c++) {
        int r;
        do {
            r = rand_in_range(n);
        } while (used[r]);
        used[r] = 1;

        for (int j = 0; j < d; j++) {
            centroids[c][j] = x[r][j];
        }
    }

    int old_y[n];
    int num_iterations = 0;

    while (true) {
        copy_cluster_assignment(n, y, old_y);

        // --- assign each point to nearest centroid ---
        for (int i = 0; i < n; i++) {
            double best_dist = -1.0;
            int best_cluster = -1;

            for (int c = 0; c < k; c++) {
                double dist_c = compute_distance(d, x[i], centroids[c], dist);
                if (best_cluster == -1 || dist_c < best_dist) {
                    best_dist = dist_c;
                    best_cluster = c;
                }
            }
            y[i] = best_cluster;
        }

        // --- recompute centroids ---
        double sum[k][d];
        int count[k];

        memset(sum, 0, sizeof(sum));
        memset(count, 0, sizeof(count));

        for (int i = 0; i < n; i++) {
            int c = y[i];
            count[c]++;
            for (int j = 0; j < d; j++) {
                sum[c][j] += x[i][j];
            }
        }

        for (int c = 0; c < k; c++) {
            if (count[c] == 0) {
                // reinitialize empty cluster
                int r = rand_in_range(n);
                for (int j = 0; j < d; j++) {
                    centroids[c][j] = x[r][j];
                }
            } else {
                for (int j = 0; j < d; j++) {
                    centroids[c][j] = sum[c][j] / count[c];
                }
            }
        }

        if (is_identical_cluster_assignment(n, y, old_y))
            break;

        num_iterations++;
    }
    printf("Converged in %d iterations\n", num_iterations);
}

void check_usage(int argc, char** argv) {
    if (argc != 6) {
        printf("usage: %s <n> <d> <filename.csv> <k> <distance-metric>\n", argv[0]);
        printf("<n> number of data points to be read\n");
        printf("<d> dimensionality of data points\n");
        printf("<filename.csv> contains the data to be classified (1st line will be ignored)\n");
        printf("<k> number of neighbours for majority voting\n");
        printf("<distance-metric>: must be \"manhattan\" or \"euclidean\"\n");
        exit(1);
    }
}

int main(int argc, char** argv) {
    assert(tests() && printf("tests have passed\n"));
    srand(1);
    check_usage(argc, argv);
    int n = atoi(argv[1]);
    int d = atoi(argv[2]);
    char* filename = argv[3];
    int k = atoi(argv[4]);
    distance dist = strcmp(argv[5], "manhattan") == 0 ? MANHATTAN : EUCLIDEAN;

    double x[n][d];
    int y[n];
    n = read_csv(filename, n, d, x, y);

    int y_true[n];
    memcpy(y_true, y, n * sizeof(int));

    //printf("Original data:\n");
    //print_csv(n, d, x, y);
    initialize_cluster_assignment(n, y, -1); // overwrite clusterIDs so that cluster() can't use it.

    double centroids[k][d];

    cluster(n, d, x, y, k, centroids, dist);

    printf("Clustering result:\n");
    for (int i = 0; i < k; i++) {
        printf("Centroid for cluster %d: ", i);
        print_datapoint(d, centroids[i]);
        printf("\n");
    }
    //print_csv(n, d, x, (int*) y);

    print_cluster_label_distribution(n, k, y, y_true);

    return 0;
}
