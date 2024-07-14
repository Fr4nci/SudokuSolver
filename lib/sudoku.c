#include "../header/sudoku.h"
#include <math.h>

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
