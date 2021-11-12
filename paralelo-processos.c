#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>

int** buildMatrix(char* mFileArg, int* mR, int* mC) {
    FILE* mFile = fopen(mFileArg, "r");
    fscanf(mFile, "%d %d", mR, mC);
    // allocate rows
    int** matrix = (int**)malloc(*mR * sizeof(int*));
    // allocate columns
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

void deallocateMatrix(int** m, int mR) {
    for(int r = 0; r < mR; r++) {
        free(m[r]);
    }
    free(m);
}

void multMatrix(int** m1, int** m2, int i, int P, int m1R, int m1C, int m2C, struct timeval begin) {
    int index = i * P;
    int row = index/m2C;
    int column = index%m2C;
    int count = 0;
    int r, c, ans;
    long long int* auxV = (long long int*)malloc(3 * P * sizeof(long long int)); // r c ans
    
    // start multiplication
    for(r = row; r < m1R && count < P; r++) {
        if(r == row) { // first row
            for(c = column; c < m2C && count < P; c++) {
                ans = 0;
                for(int k = 0; k < m1C; k++) {
                    ans += m1[r][k] * m2[k][c];
                }
                auxV[count*3] = r+1;
                auxV[count*3+1] = c+1;
                auxV[count*3+2] = ans;
                count++;
                //fprintf(mResFile, "c%d%d %d\n", r+1, c+1, ans);
            }
        } else { // other rows
            for(c = 0; c < m2C && count < P; c++) {
                ans = 0;
                for(int k = 0; k < m1C; k++) {
                    ans += m1[r][k] * m2[k][c];
                }
                auxV[count*3] = r+1;
                auxV[count*3+1] = c+1;
                auxV[count*3+2] = ans;
                count++;
                //fprintf(mResFile, "c%d%d %d\n", r+1, c+1, ans);
            }
        }
    }
    // end multiplication
    // stop measuring time and calculate the elapsed time
    struct timeval end;
    gettimeofday(&end, 0);
    long secondsToMicroseconds = (end.tv_sec - begin.tv_sec) * 1000000; 
    long microseconds = end.tv_usec - begin.tv_usec; 
    double milliseconds = (double)(secondsInMicroseconds + microseconds)/1000;

    // write
    char filename[20];
    sprintf(filename, "resPro%d.txt", i+1);
    FILE* mResFile = fopen(filename, "w");
    fprintf(mResFile, "%d %d\n", m1R, m2C);
    for(int i = 0; i < 3 * P - 2; i += 3) {
        fprintf(mResFile, "m%lld_%lld %lld\n", auxV[i], auxV[i+1], auxV[i+2]);
    }
    fprintf(mResFile, "%lf", milliseconds);
    fclose(mResFile);
    free(auxV);
}

int main(int argc, char* argv[]) {
    int m1R, m1C, m2R, m2C;
    double timeSpent = 0;
    int P = atoi(argv[3]);

    int** m1 = buildMatrix(argv[1], &m1R, &m1C);
    int** m2 = buildMatrix(argv[2], &m2R, &m2C);

    int numberOfFiles = ceil((double)m1R*m2C / (double)P);
    
    // start measuring time
    struct timeval begin;
    gettimeofday(&begin, 0);
    for(int i = 0; i < numberOfFiles; i++) {
        pid_t pid = fork();
        if(pid == 0) {
            // multiplication start
            multMatrix(m1, m2, i, P, m1R, m1C, m2C, begin);
            // multiplication end
            break;
        } 
    }

    deallocateMatrix(m1, m1R);
    deallocateMatrix(m2, m2R);

    return 0;
}
