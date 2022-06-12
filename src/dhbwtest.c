/*
 ============================================================================
 Aufgabe     : Datenstrukturen
 Autor       : koetter
 Matrikel    : DIESE DATEI NICHT AENDERN
 Version     : DIESE DATEI NICHT AENDERN
 ============================================================================
 */
#include <stdbool.h>
#include <stdlib.h>
#include "dhbwtest.h"



const char* lastnames[] = {"Mueller", "Schmidt", "Schneider", "Fischer", "Weber", "Meyer", "Wagner", "Becker", "Schulz", "Hoffmann", "Schaefer", "Bauer", "Koch", "Richter", "Klein", "Wolf", "Schroeder", "Neumann", "Schwarz", "Braun", "Hofmann", "Zimmermann", "Schmitt", "Hartmann", "Krueger", "Schmid", "Werner", "Lange", "Schmitz", "Meier", "Krause", "Maier", "Lehmann", "Huber", "Mayer", "Herrmann", "Koehler", "Walter", "Koenig", "Schulze", "Fuchs", "Kaiser", "Lang", "Weiss", "Peters", "Scholz", "Jung", "Moeller", "Hahn", "Keller", "Vogel", "Schubert", "Roth", "Frank", "Friedrich", "Beck", "Guenther", "Berger", "Winkler", "Lorenz", "Baumann", "Schuster", "Kraus", "Boehm", "Simon", "Franke", "Albrecht", "Winter", "Ludwig", "Martin", "Kraemer", "Schumacher", "Vogt", "Jaeger", "Stein", "Otto", "Gross", "Sommer", "Haas", "Graf", "Heinrich", "Seidel", "Schreiber", "Ziegler", "Brandt", "Kuhn", "Schulte", "Dietrich", "Kuehn", "Engel", "Pohl", "Horn", "Sauer", "Arnold", "Thomas", "Bergmann", "Busch", "Pfeiffer", "Voigt", "Goetz", "Kotter"};


/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */
void shuffle(int *array, size_t n) {
	if (n > 1) {
		size_t i;
		for (i = 0; i < n - 1; i++) {
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}


//https://benpfaff.org/writings/clc/shuffle.html
//Last updated 04 Apr 2004 16:19. Copyright © 2004 Ben Pfaff.
//May be freely redistributed, but copyright notice must be retained.

bool testNoNulls(StudentLP* anchor_adr) {


	StudentLP current = *anchor_adr;

	bool nullfree = true;
	while(current != NULL) {
		if(current->student == NULL) {
			nullfree = false;
			break;
		}
		current = current->next;
	}

	return nullfree;
}

bool testMatrSort(StudentLP* anchor_adr) {

	//at first we compare the first element to itself. This will always work and saves a nullpointer check.
	StudentLP current = *anchor_adr;
	StudentLP previous = *anchor_adr;

	bool sorted = true;
	while(current != NULL) {
		//printf("i=%d\n", current->student->matrnr);
		if(previous->student->matrnr > current->student->matrnr) {
			sorted = false;
			break;
		}
		previous = current;
		current = current->next;
	}

	return sorted;
}

bool testMatrSortArray(Student_p *array, int count) {

	bool sorted = true;

	for(int i = 1; i < count; i++) {

		//printf("i=%d\n", array[i-1]->matrnr);
		if(array[i-1]->matrnr > array[i]->matrnr) {
			sorted = false;
			break;
		}
	}

	return sorted;
}


Student_p generateTestStudent(int matr_nr) {
	char buf[255];

	int n1 = rand() % 100;
	int n2 = rand() % 100;
	snprintf(buf, sizeof(buf), "%06d %s%s", matr_nr, lastnames[n1], lastnames[n2]);
	return StudentAlloc(buf);
}


StudentLP* generateTestData(int amount, bool shuffleData) {
	StudentLP* test_students = malloc(sizeof(StudentLP));
	*test_students=NULL;

	int* matrs = (int*) malloc(amount * sizeof(int));
	int matr_nr = 0;
	for(int i = 0; i < amount; i++) {
		matr_nr += (999999/(amount));
		matrs[i] = matr_nr;
	}
	if(shuffleData) {
		shuffle(matrs, amount);
	}

	//reverse loop because we insert at beginng
	for(int i = amount - 1; i >= 0 ; --i) {
		StudentLInsertFirst(test_students, generateTestStudent(matrs[i]));
	}

	free(matrs);

	return test_students;
}

void outputBenchmarkScore(const char *datastructure, const char *operation,
		clock_t begin, clock_t end) {
	double time = ((end - begin) * 1000.0) / CLOCKS_PER_SEC;
	printf("|%-20s|%-20s|%10.2f|\n", datastructure, operation,
				time);
}

void outputTestResult(const char *datastructure, const char *operation,
bool result, Student_p element) {
	printf("|%-20s|%-20s|%-6s|%-20s|\n", datastructure, operation,
			(result ? TRUETEXT : FALSETEXT),
			element != NULL ? toString(element) : "");
}


void outputStudentList(StudentLP* anchor_adr) {

	StudentLP current = *anchor_adr;

	while(current != NULL) {
		printf("%06d    %s\n", current->student->matrnr, current->student->lastname);
		current = current->next;
	}
}

void outputStudentArray(Student_p *array, int count) {

	for(int i = 0; i < count; i++) {

		printf("%06d    %s\n", array[i]->matrnr, array[i]->lastname);
	}

}






