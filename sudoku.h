#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdbool.h>

#define N 9

bool solveSudoku(int arr[N][N]);
bool isSafe(int arr[N][N], int i, int j, int n);
bool UnassignedEntry(int arr[N][N], int* i, int* j);
bool checkBox(int arr[N][N], int gridx, int gridy, int n);
bool CheckRow(int arr[N][N], int j, int n);
bool CheckCol(int arr[N][N], int i, int n);

#endif // SUDOKU_H
