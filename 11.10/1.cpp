#include <iostream>
#include "omp.h"
 
void parallel_vector_matrix();
 
int main() {
    parallel_vector_matrix();
    return 0;
}
void parallel_vector_matrix() {
    double vector[] = {1.0, 1.0};
    double matrix[][2] = {{3.0, 4.0}, {5.0, 6.0}};
    double result[] = {0.0, 0.0};
    int i, j;
    #pragma omp parallel for private (j)
        for (i = 0; i < 2; ++i) {
            for (j = 0; j < 2; ++j) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
    for (int k = 0; k < 2; ++k) {
        std::cout << result[k] << std::endl;
    }
}