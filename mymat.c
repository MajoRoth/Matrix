#include "mat.h"


int main(){
    matrix MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;
    int i;

    struct mats_list mats[] = {
            {"MAT_A", &MAT_A},
            {"MAT_B", &MAT_B},
            {"MAT_C", &MAT_C},
            {"MAT_D", &MAT_D},
            {"MAT_E", &MAT_E},
            {"MAT_F", &MAT_F}
    };


    char temp[32];
    char command[32];
    char line[512];
    int line_index;
    double *read_args;
    matrix *p1, *p2, *p3;
    enum boolean COMMAND;
    /*
    struct mats_list mats[6];
    mats[0].name = "MAT_A";
    mats[0].mat = &MAT_A;
    mats[0].name = "MAT_B";
    mats[0].mat = &MAT_B;
    mats[0].name = "MAT_C";
    mats[0].mat = &MAT_C;
    mats[0].name = "MAT_D";
    mats[0].mat = &MAT_D;
    mats[0].name = "MAT_E";
    mats[0].mat = &MAT_E;
    mats[0].name = "MAT_F";
    mats[0].mat = &MAT_F;
    */
    memset(temp, 0, sizeof temp);
    memset(command, 0, sizeof command);
    memset(line, 0, sizeof line);
    RUN = TRUE;


    zero_mat(MAT_A);
    zero_mat(MAT_B);
    zero_mat(MAT_C);
    zero_mat(MAT_D);
    zero_mat(MAT_E);
    zero_mat(MAT_F);



    while (RUN==TRUE){
        printf("Enter Your Next Command (stop to exit)\n");
        get_line(line);
        printf("%s\n", line);

        line_index = 0;
        COMMAND = TRUE;
        NEW_LINE = FALSE;

        line_index = next_argument(command, line, line_index, COMMAND);
        COMMAND = FALSE;



        if (line_index==-1){
            printf("Illegal comma\n");
        }
        else if (line_index==-2){
            break;
        }


        else if (strcmp(command, "read_mat")==0){

            read_args = (double *)malloc(16*sizeof(double ));

            line_index = next_argument(temp, line, line_index, COMMAND);

            if (*temp == '\0'){
                printf("Missing argument\n");
            }
            else {
                printf("hey\n");

                p1 = search_mat(temp, mats);

                if (p1 != NULL) {
                    memset(temp, 0, sizeof temp); /* cleans temp */
                    for (i = 0; i < pow(SIZE, 2) && NEW_LINE == FALSE; i++) {
                        line_index = next_argument(temp, line, line_index, COMMAND);
                        *(read_args + i) = atof(temp);
                        memset(temp, 0, sizeof temp); /* cleans temp */

                    }
                    if (NEW_LINE == FALSE) {
                        printf("Extraneous text after end of command\n");
                    } else if (i==1) {
                        printf("Missing argument\n");
                    } else {
                        read_mat(*p1, read_args, i);
                        free(read_args);
                    }
                }
                else {
                    printf("Undefined matrix name\n");
                }
            }
        }


        else if (strcmp(command, "print_mat")==0){
            line_index = next_argument(temp, line, line_index, COMMAND);
            if (*temp == '\0'){
                printf("Missing argument\n");
            }
            else {
                p1 = search_mat(temp, mats);
                if (*p1 != NULL) {
                    if (NEW_LINE == FALSE) {
                        printf("Extraneous text after end of command\n");
                    } else {
                        print_mat(*p1);
                    }
                }
                else{
                    printf("Undefined matrix name\n");
                }
            }
        }


        else if (strcmp(command, "add_mat")==0){
            line_index = next_argument(temp, line, line_index, COMMAND);
            if (*temp == '\0'){
                printf("Missing argument\n");
            }
            else {
                p1 = search_mat(temp, mats);
                line_index = next_argument(temp, line, line_index, COMMAND);
                if (*temp == '\0'){
                    printf("Missing argument\n");
                }
                else {
                    p2 = search_mat(temp, mats);
                    line_index = next_argument(temp, line, line_index, COMMAND);
                    if (*temp == '\0'){
                        printf("Missing argument\n");
                    }
                    else {
                        p3 = search_mat(temp, mats);
                        if (*p1 != NULL && *p2 != NULL && *p3 != NULL) {
                            if (NEW_LINE == FALSE) {
                                printf("Extraneous text after end of command\n");
                            } else {
                                add_mat(*p1, *p2, *p3);
                            }
                        }
                        else{
                            printf("Undefined matrix name\n");
                        }
                    }
                }
            }
        }


        else if (strcmp(command, "sub_mat")==0){
            line_index = next_argument(temp, line, line_index, COMMAND);
            if (*temp == '\0'){
                printf("Missing argument\n");
            }
            else {
                p1 = search_mat(temp, mats);
                line_index = next_argument(temp, line, line_index, COMMAND);
                if (*temp == '\0'){
                    printf("Missing argument\n");
                }
                else {
                    p2 = search_mat(temp, mats);
                    line_index = next_argument(temp, line, line_index, COMMAND);
                    if (*temp == '\0'){
                        printf("Missing argument\n");
                    }
                    else {
                        p3 = search_mat(temp, mats);
                        if (*p1 != NULL && *p2 != NULL && *p3 != NULL) {
                            if (NEW_LINE == FALSE) {
                                printf("Extraneous text after end of command\n");
                            } else {
                                sub_mat(*p1, *p2, *p3);
                            }
                        } else {
                            printf("Undefined matrix name\n");
                        }
                    }
                }
            }
        }


        else if (strcmp(command, "mul_mat")==0){
            line_index = next_argument(temp, line, line_index, COMMAND);
            if (*temp == '\0'){
                printf("Missing argument\n");
            }
            else {
                p1 = search_mat(temp, mats);
                line_index = next_argument(temp, line, line_index, COMMAND);
                if (*temp == '\0'){
                    printf("Missing argument\n");
                }
                else {
                    p2 = search_mat(temp, mats);
                    line_index = next_argument(temp, line, line_index, COMMAND);
                    if (*temp == '\0'){
                        printf("Missing argument\n");
                    }
                    else {
                        p3 = search_mat(temp, mats);
                        if (*p1 != NULL && *p2 != NULL && *p3 != NULL) {
                            if (NEW_LINE == FALSE) {
                                printf("Extraneous text after end of command\n");
                            } else {
                                mul_mat(*p1, *p2, *p3);
                            }
                        } else {
                            printf("Undefined matrix name\n");
                        }
                    }
                }
            }
        }


        else if (strcmp(command, "mul_scalar")==0){
            line_index = next_argument(temp, line, line_index, COMMAND);
            p1 = search_mat(temp, mats);
            line_index = next_argument(temp, line, line_index, COMMAND);
            if (*temp == '\0'){
                printf("Missing argument\n");
            }
            else {
                if (*p1 != NULL) {
                    if (NEW_LINE == FALSE) {
                        printf("Extraneous text after end of command\n");
                    } else {
                        mul_scalar(*p1, atof(temp));
                    }
                }
                else {
                    printf("Undefined matrix name\n");
                }
            }
        }


        else if (strcmp(command, "trans_mat")==0){
            line_index = next_argument(temp, line, line_index, COMMAND);
            if (*temp == '\0'){
                printf("Missing argument\n");
            }
            else {
                p1 = search_mat(temp, mats);
                line_index = next_argument(temp, line, line_index, COMMAND);
                if (*temp == '\0'){
                    printf("Missing argument\n");
                }
                else {
                    p2 = search_mat(temp, mats);
                    if (*p1 != NULL && *p2 != NULL) {
                        if (NEW_LINE == FALSE) {
                            printf("Extraneous text after end of command\n");
                        } else {
                            trans_mat(*p1, *p2);
                        }
                    } else {
                        printf("Undefined matrix name\n");
                    }
                }
            }
        }


        else if (strcmp(command, "stop")==0){
            if (NEW_LINE == FALSE){
                printf("Extraneous text after end of command\n");
            }
            else {
                stop();
            }
        }


        else{
            printf("Undefined command name\n");
        }



        memset(temp, 0, sizeof temp);
        memset(command, 0, sizeof command);
        memset(line, 0, sizeof line);
    }
}




