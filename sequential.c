#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int** buildMatrix(char* mFileArg, int* mR, int* mC) {
    FILE* mFile = fopen(mFileArg, "r");
    fscanf(mFile, "%d %d", mR, mC);
    // allocate rows
    int** matrix = (int**)malloc(*mR * sizeof(int*));
    // allocate collumns
    for(int r = 0; r < *mR; r++) {
        matrix[r] = (int*)malloc(*mC * sizeof(int));
    }

    for(int r = 0; r < *mR; r++) {
        for(int c = 0; c < *mC; c++) {
            fscanf(mFile, "%d", &matrix[r][c]);            
        }
    }
    
    return matrix;
}

int** multMatrix(int** m1, int** m2, int m1R, int m2R, int m2C, double* timeSpent) {
    // allocate rows
    int** matrix = (int**)malloc(m1R * sizeof(int*));
    // allocate collumns
    for(int r = 0; r < m1R; r++) {
        matrix[r] = (int*)malloc(m2C * sizeof(int));
    }

    // multiplication start
    clock_t begin = clock();
    for(int r = 0; r < m1R; r++) {
        for(int c = 0; c < m2C; c++) {
            matrix[r][c] = 0;
 
            for(int k = 0; k < m2R; k++) {
                matrix[r][c] += m1[r][k] * m2[k][c];
            }
        }
    }
    // multiplication end
    clock_t end = clock();

    *timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;    

    return matrix;
}

void writeMatrix(int** m, int mR, int mC, double timeSpent) {
    FILE* mResFile = fopen("mResFile.txt", "w");
    fprintf(mResFile, "%d %d\n", mR, mC);
    for(int r = 0; r < mR; r++) {
        for(int c = 0; c < mC; c++) {
            fprintf(mResFile, "c%d%d %d\n", r + 1, c + 1, m[r][c]);                        
        }
    }
    fprintf(mResFile, "%f\n", timeSpent);
    fclose(mResFile);
}

int main(int argc, char* argv[]) {
    int m1R, m1C, m2R, m2C;
    double timeSpent = 0;

    int** m1 = buildMatrix(argv[1], &m1R, &m1C);
    int** m2 = buildMatrix(argv[2], &m2R, &m2C);
    int** mRes = multMatrix(m1, m2, m1R, m2R, m2C, &timeSpent);
    writeMatrix(mRes, m1R, m2C, timeSpent);

    return 0;
}