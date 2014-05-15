/*	4-row matrices */

struct mat4 {
	int cols;		/* number of columns */
	double *cells;	/* the data in column-major order, namely a11, a21, a31, .. an1, a12, a22, a32, ... */
};

typedef struct mat4 Mat4;

// Prototypes:
Mat4 *mat4_create(int ncolumns);
void mat4_delete(Mat4 *m);
Mat4 *mat4_create_identity();
Mat4 *mat4_copy(Mat4 *original);
Mat4 *mat4_add_column(Mat4 *old, double *new_cells);
Mat4 *mat4_set(Mat4 *matrix, int row, int col, double value);
double mat4_get(Mat4 *matrix, int row, int col);
int mat4_columns(Mat4 *m);
void mat4_print(char *s, Mat4 *matrix);
Mat4 * mat4_combine(Mat4 * matrix1, Mat4 * matrix2);

