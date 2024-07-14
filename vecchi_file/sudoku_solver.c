#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define N 9 // Fisso la grandezza del sudoku siccome in C se lavoro con i puntatori non posso effettivamente capire quanto è grande un array

/* Sudoku Solver 
Il sudoku posso visualizzarlo come una matrice 9x9 dunque
i = numero della riga
j = numero della colonna
*/

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

bool CheckRow(int arr[N][N], int j, int n) {
    for (int i = 0; i < N; i++) {
        if (arr[i][j] == n) {
            return false;
        }
    }
    return true;
}

bool CheckCol(int arr[N][N], int i, int n) {
    for (int j = 0; j < N; j++) {
        if (arr[i][j] == n) {
            return false;
        }
    }
    return true;
}

bool checkBox(int arr[N][N], int gridx, int gridy, int n) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[gridx + i][gridy + j] == n) {
                return false;
            }
        }
    }
    return true;
}

bool UnassignedEntry(int arr[N][N], int* i, int* j) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (arr[row][col] == 0) {
                *i = row;
                *j = col;
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int arr[N][N], int i, int j, int n) {
    if (arr[i][j] != 0) {
        return false; // Il numero qua è diverso da zero dunque non posso aggiungere niente perché è un "dato" iniziale
    }
    bool status = true;
    int gridx = floor(i / 3) * 3;
    int gridy = floor(j / 3) * 3;
    if (!checkBox(arr, gridx, gridy, n) || !CheckRow(arr, j, n) || !CheckCol(arr, i, n)) {
        status = false;
    }
    return status;
}

bool solveSudoku(int arr[N][N]) {
    int i, j;
    if (!UnassignedEntry(arr, &i, &j)) {
        return true; // Sudoku risolto
    }
    for (int n = 1; n <= 9; n++) {
        if (isSafe(arr, i, j, n)) {
            arr[i][j] = n;
            if (solveSudoku(arr)) {
                return true;
            }
            arr[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int matrix[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    printSudoku(matrix);
    printf("\nSolving...\n");
    if (solveSudoku(matrix)) {
        printSudoku(matrix);
    } else {
        printf("No solution exists\n");
    }
    return 0;
}
