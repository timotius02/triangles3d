#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parse_util.h"
#include "mat4.h"

int convert_screen(double x, char * num);
void render_cyclops(Mat4 * matrix, double * coors);
void render_stereo(Mat4 * matrix, double * coors1, double *coors2);


void render_cyclops(Mat4 * matrix, double * coors){ 
    int i;
    int numLines = mat4_columns(matrix);

    //original vars of matrix
    double x, y, z;
    //coors of eyes
    double x1, y1, z1;

    //new vars
    double x2, y2, z2;

    x1 = coors[0];
    y1 = coors[1];
    z1 = coors[2];

    for(i = 0; i < numLines; i++){
        x = mat4_get(matrix, 0, i);
        y = mat4_get(matrix, 1, i);
        z = mat4_get(matrix, 2, i);

        // convert x coor
        x2 = x1 - ((z1 * (x1-x)) / (z1-z));
        // convert y coor
        y2 = y1 - ((z1 * (y1-y)) / (z1-z));
        // convert z coor
        z2 = 0;

        mat4_set(matrix, 0, i, x2);
        mat4_set(matrix, 1, i, y2);
        mat4_set(matrix, 2, i, z2);

    }
}

void render_stereo(Mat4 * matrix, double * coors1, double * coors2){ 
    int i;
    double temp[4];
    int numLines  = mat4_columns(matrix);
    Mat4 * matrix2 = mat4_copy(matrix);

    render_cyclops(matrix, coors1);
    render_cyclops(matrix2, coors2);

    //joining matrices
    for(i = 0; i < numLines; i++){
        temp[0] = mat4_get(matrix2, 0, i);  
        temp[1] = mat4_get(matrix2, 1, i);  
        temp[2] = mat4_get(matrix2, 2, i);  
        temp[3] = 1; 
        mat4_add_column(matrix, temp);
    }

}