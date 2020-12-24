#include "mat.h"


void read_mat(matrix mat, double *args, int length)
{
    int i;
    zero_mat(mat);
    for (i = 0; i < length; i++) {
        (mat[i / 4][i % 4]) = *(args+i);
    }
}

void print_mat(matrix mat){
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%7.2f", mat[i][j]);
        }
        printf("\n");
    }
}

void add_mat(matrix mat1, matrix mat2, matrix mat3){
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            mat3[i][j] = mat1[i][j]+ mat2[i][j];
        }
    }
}

void sub_mat(matrix mat1, matrix mat2, matrix mat3){
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void mul_mat(matrix mat1, matrix mat2, matrix mat3){
    int i, j, k;
    double sum;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++) {
            sum = 0;
            for(k=0; k<SIZE; k++){
                sum += (mat1[i][k])*(mat2[k][j]);
            }
            mat3[i][j] = sum;
        }
    }
}

void mul_scalar(matrix mat1, double scalar){
    int i, j;
    for (i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            mat1[i][j] = scalar * mat1[i][j];
        }
    }
}

void trans_mat(matrix mat1, matrix mat2){
    int i, j;
    for (i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            mat2[j][i] = mat1[i][j];
        }
    }
}

void stop(void){
    RUN= FALSE;
    printf("Program Ended\n");
}


/*
 * HELP FUNCTIONS
 */
matrix *search_mat(char *name, struct mats_list *mats){
    /*
     * returns a pointer for matrix
     * gets a matrix name
     * if name is not valid returns NULL
     */
    matrix *pm = NULL;
    int i;
    for (i=0; i<MATS_NUM; i++){
        if (strcmp(mats[i].name, name)==0){
            pm = mats[i].mat;
            break;
        }
    }
    if (*pm == NULL){
        return NULL;
    }
    return pm;
}


void zero_mat(matrix mat){
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++){
            mat[i][j] = 0;
        }
    }
}

int next_argument(char *temp, char *line, int i, enum boolean COMMAND){
    /*
     * ignores white spaces
     * return null if next argument is new line
     * else returns the nest argument
     * COMMAND - if the next argument should be a command - for error check
     */

    char c;
    int j;

    while ((c=*(line+i)) == ' ' || c =='\t' || c == '\n' || c==','){
        if (c == EOF){
            printf("ERROR: program stopped by EOF and not by stop()");
            return -2;
        }
        else if (c == '\n'){
            NEW_LINE = TRUE;
            return 0;
        }
        i++;
    }

    i++;
    *temp = c;

    for (j=1; (c=*(line+i)) != ',' && c != '\n' && c != ' ' && c != '\t' && c != '\0'; i++, j++) {
         *(temp + j)= c;
    }
    if (c == EOF){
        printf("ERROR: program stopped by EOF and not by stop()");
        return -2;
    }
    else if (COMMAND == TRUE && c == ','){
        return -1;
    }
    else if (c == '\n' || c == '\0'){
        NEW_LINE = TRUE;
    }
    return i;
}

int get_line(char *line){
    char c;
    int i=0;
    while ((c=getchar()) != '\n'){
        *(line+i) = c;
        i++;
    }
   return 1;
}


