#ifndef MISCLASSIFICATIONS_H
#define MISCLASSIFICATIONS_H

void print_cluster_label_distribution(int n, int k,
                                      const int y_pred[n],
                                      const int y_true[n]);

#endif
