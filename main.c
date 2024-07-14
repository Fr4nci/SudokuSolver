#include "sudoku.h"
#include "io.h"
#include <stdlib.h>

int main() {
    int matrix[N][N];
    const char* inputFilename = "sudoku_input.txt";
    const char* outputFilename = "sudoku_output.txt";

    if (!readSudoku(inputFilename, matrix)) {
        fprintf(stderr, "Failed to read Sudoku from file.\n");
        return EXIT_FAILURE;
    }

    printSudoku(matrix);
    printf("Ecco il Sudoku risolto: \n");
    if (solveSudoku(matrix)) {
        printSudoku(matrix);
        if (!writeSudoku(outputFilename, matrix)) {
            fprintf(stderr, "Failed to write Sudoku to file.\n");
            return EXIT_FAILURE;
        }
    } else {
        printf("No solution exists\n");
    }

    return EXIT_SUCCESS;
}
