#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "studentUtil.h"

//Christian Giovanni Martinez
//Id 991770196
//Date 07/03/2025

//Assignment 2

static int size;


int main() {

	while (1) {
		printf("Enter how many students: ");
		int parseCount = scanf("%d", &size);
		if (parseCount != 1) {
			printf("Error, enter a valid value \n");
		} else {
			if (size < 2){
				printf("Error, must enter at least 2 students\n");
			}
			else{
				break;
			}
		}
		fflush(stdin);
	}


	Student* students = malloc(size * sizeof(Student));
	if (students == NULL) {
		printf("Out of memory!");
		exit(10);
	}

	inputStudents(students, size);

	double* stats = malloc(size * sizeof(double));
	if (stats == NULL) {
		printf("Out of memory!");
		exit(10);
	}

	statsStudents(students, size, stats);

	printStudents(students, size, stats);
}
