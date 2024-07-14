#include "header/sudoku.h"
#include "header/io.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int matrix[N][N];
    const char* inputFilename = "./sudoku_input.txt";
    const char* outputFilename = "./sudoku_output.txt";
    bool print = false;
    printf("Reading the input file...\n");
    if (!readSudoku(inputFilename, matrix)) {
        fprintf(stderr, "Failed to read Sudoku from file.\n");
        return EXIT_FAILURE;
    }
    if(argc != 0){
        for(int k = 0; k < argc; k++){
            if(strcmp(argv[k], "-h") == 0){
                printf("Simple program to solve Sudoku \n");
                printf("Save your sudoku in a file called 'sudoku_input.txt' and then the result will be avaible in 'sudoku_output.txt'\n");
                printf("If you use -pS option when calling the program, the solved sudoku will also be printed on the terminal. The option -pI will print the parsed sudoku while the option -p will print both");
                printf("Have fun!");
                return EXIT_SUCCESS;
            }
            if(strcmp(argv[k], "-pS") == 0){
                print = true;
            }
            if(strcmp(argv[k], "-pI") == 0){
                printSudoku(matrix);
            }
            if(strcmp(argv[k], "-p") == 0){
                print = true;
                printSudoku(matrix);
            }
        }
    }
    printf("Solving...\n \n");
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
