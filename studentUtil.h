



typedef struct {
char name[60];
double cSharp, math, systems;
double total;
}Student;


void inputStudents(Student students[ ], int size); // to input student(s) info
void statsStudents(Student students[ ], int size, double stats [ ]); // to calculate class statistics
void printStudents(Student students[ ], int size, const double stats [ ]); // to print students & the stats