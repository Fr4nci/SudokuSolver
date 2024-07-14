#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdbool.h>

#define N 9

void printSudoku(int matrix[9][9]);
bool readSudoku(const char* filename, int matrix[9][9]);
bool writeSudoku(const char* filename, int matrix[9][9]);

#endif // IO_H
