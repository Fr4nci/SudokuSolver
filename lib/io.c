#include "../header/io.h"

void printSudoku(int matrix[9][9]) {
    printf("----------------------------------\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d | ", matrix[i][j]);
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("----------------------------------\n");
        }
    }
}

bool readSudoku(const char* filename, int matrix[9][9]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                perror("Error reading file");
                fclose(file);
                return false;
            }
        }
    }

    fclose(file);
    return true;
}

bool writeSudoku(const char* filename, int matrix[9][9]) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return true;
}
