#include "libgeometry/libgeometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define N 30 

int main()
{
    struct circle data_circle[50]; 
                                   
    float r = 0;                  
    float area = 0, perimetr = 0;
    int ncircle = 0; 
    FILE* fptr = NULL;

    fptr = fopen("bin/ex.txt", "r");
    if (!fptr) {
        printf("Невозможно открыть файл\n");
    } else {
        while (!feof(fptr)) 
        {
            char r_arr[10] = {0};
            char x_arr[10] = {0}; 
            char y_arr[10] = {0};
            char input_arr[N]
                    = {0}; 
            fgets(input_arr, 30, fptr);
            printf("\n");

            int counter_1 = name_verification(input_arr);
            int counter_2 = checking_parameters_figure(input_arr);

            if (counter_1 > 0) {
                for (int i = 0; i < N; i++) {
                    printf("%c", input_arr[i]);
                }
                printf("incorrect name of figure\n");
                printf("please correct\n"); 

            } else {
                if (counter_2 > 0) {
                    for (int i = 0; i < N; i++) {
                        printf("%c", input_arr[i]);
                    }
                    printf("invalid values\n");
                    printf("please correct\n"); 
                } else {
                    for (int i = 0; i < N; i++) {
                        if ((input_arr[i] == ',')
                            && (input_arr[i + 1] == ' ')) { 
                            for (int k = i; input_arr[k + 1] != ')'; k++) {
                                r_arr[k - i] = input_arr[k + 1];
                            }
                        }
                        if (input_arr[i] == '(') { 
                            for (int k = i; input_arr[k + 1] != ' '; k++) {
                                x_arr[k - i] = input_arr[k + 1];
                            }
                        }
                        if (input_arr[i] == ' ') { 
                            for (int k = i - 1; input_arr[k] != ','; k++) {
                                y_arr[k - i] = input_arr[k];
                            }
                        }
                    }
                    ++ncircle;
                    r = atof(r_arr);
                    area = area_f(r);
                    perimetr = perimetr_f(r);

                    printf("%d. ", ncircle);
                    for (int i = 0; i < N; i++) {
                        printf("%c", input_arr[i]);
                    }
                    printf("area = %.2f\n", area);
                    printf("perimeter = %.2f\n", perimetr);

                    data_circle[ncircle].r = r;
                    data_circle[ncircle].x = atoi(x_arr);
                    data_circle[ncircle].y = atoi(y_arr);
                }
            }
        }
    }

    fclose(fptr);
    printf("\n");
    print_superimposed(ncircle, data_circle);

    return 0;
}