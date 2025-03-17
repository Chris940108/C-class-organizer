#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "studentUtil.h"


double getGrade() {
	double grade;
	while (1) {
		int parseCount = scanf("%lfd", &grade);
		if (parseCount != 1) {
			printf("Error, enter a valid value \n");
		} else {
			if (grade < 0 || grade > 100) {
				printf("Error, grade must be between 0 and 100\n");
			} else {
				break;
			}
		}
		fflush(stdin);
	}
}

void inputStudents(Student students[ ], int size) {
	for (int i = 0; i < size; i++) {
		printf("Enter the name for the student No %d: ", i+1);
		scanf("%s", students[i].name);
		fflush(stdin);
		printf("cSharp grade: ");
		students[i].cSharp = getGrade();
		printf("Math grade: ");
		students[i].math = getGrade();
		printf("Systems grade: ");
		students[i].systems = getGrade();
		students[i].total = students[i].cSharp + students[i].math + students[i].systems;
	}
}



void statsStudents(Student students[ ], int size, double stats [ ]) {

	double sumAvg= 0;
	stats[0]= students[0].total;
	stats[1]= students[0].total;

	for (int i = 0; i< size; i++) {
		if (students[i].total < stats[0]) {
			stats[0] = students[i].total;
		}
		if (students[i].total > stats[1]) {
			stats[1] = students[i].total;
		}
		sumAvg += students[i].total;
	}
	stats[3]= sumAvg/size;

}
void printStudents(Student students[ ], int size, const double stats [ ]) {

	printf("\n\n=======================================================\n\n");

	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n", "No", "cSharp", "Math", "Systems", "Total", "Name");

	for (int i = 0; i < size; i++) {
		printf("%-10d", i+1);
		printf("%-10.2lf", students[i].cSharp);
		printf("%-10.2lf", students[i].math);
		printf("%-10.2lf", students[i].systems);
		printf("%-10.2lf", students[i].total);
		printf("%-10s\n", students[i].name);
	}
	printf("\n\nStatics of Class:\n");
	printf("Min: %.2lf,\t", stats[0]);
	printf("Max: %.2lf,\t", stats[1]);
	printf("Average: %.2lf\n", stats[3]);

}



