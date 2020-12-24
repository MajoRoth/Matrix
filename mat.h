#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 4
#define MATS_NUM 6

/*
 * STRUCTS
 */
typedef double matrix[SIZE][SIZE];

struct mats_list{
    char *name;
    matrix *mat;
};

enum boolean {FALSE, TRUE} RUN, NEW_LINE; /* If we reached new line - set true */
/*
 * COMMANDS
 */
void read_mat(matrix mat, double *args, int length);
void print_mat(matrix mat);
void add_mat(matrix mat1, matrix mat2, matrix mat3);
void sub_mat(matrix mat1, matrix mat2, matrix mat3);
void mul_mat(matrix mat1, matrix mat2, matrix mat3);
void mul_scalar(matrix mat1, double scalar);
void trans_mat(matrix mat1, matrix mat2);

void stop(void);


/*
 * HELP FUNCTIONS
 */
void zero_mat(matrix mat);
matrix *search_mat(char *name, struct mats_list mats[]);
int next_argument(char *temp, char *line, int i, enum boolean COMMAND);
int get_line(char *line);





