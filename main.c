#include "header/sudoku.h"
#include "header/io.h"
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    int matrix[N][N];
    const char* inputFilename = "./sudoku_input.txt";
    const char* outputFilename = "./sudoku_output.txt";
    bool print = false;
    if (!readSudoku(inputFilename, matrix)) {
        fprintf(stderr, "Failed to read Sudoku from file.\n");
        return EXIT_FAILURE;
    }
    printSudoku(matrix);
    printf("\nSolving...\n \n");
    if (solveSudoku(matrix)) {
        if(print == true){
            printSudoku(matrix);
        }
        if (!writeSudoku(outputFilename, matrix)) {
            fprintf(stderr, "Failed to write Sudoku to file.\n");
            return EXIT_FAILURE;
        }
    } else {
        printf("No solution exists\n");
    }
    printf("File 'sudoku_output.txt' saved successfully!\n");
    return EXIT_SUCCESS;
}
