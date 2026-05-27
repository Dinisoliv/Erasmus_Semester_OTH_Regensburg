#include <stdio.h>
#include "misclassifications.h"

void print_cluster_label_distribution(int n, int k,
                                      const int y_pred[n],
                                      const int y_true[n]) {

    int counts[k][k];

    // initialize matrix to 0
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            counts[i][j] = 0;

    // fill counts
    for (int i = 0; i < n; i++) {
        int c_pred = y_pred[i];
        int c_true = y_true[i];
        counts[c_pred][c_true]++;
    }

    // print results
    printf("\nCluster composition (rows = predicted clusters, columns = true labels):\n\n");

    printf("        ");
    for (int t = 0; t < k; t++)
        printf("T%d   ", t);
    printf("\n");

    for (int c = 0; c < k; c++) {
        printf("C%d |   ", c);
        for (int t = 0; t < k; t++) {
            printf("%3d  ", counts[c][t]);
        }
        printf("\n");
    }
}
