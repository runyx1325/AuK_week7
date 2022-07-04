/*
 ============================================================================
 Aufgabe     : Sortieren - Woche 8
 Autor       : Burst
 Matrikel    : 4581869
 Version     : 1.0
 ============================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dhbwsortmerge.h"


//Ab hier Aufgaben


//Auf true setzen, damit Array-MergeSort getestet wird
bool MergeSortArrayImplemented() {
	return true;
}
//MergeSort mit Array
void MergeSortArray(Student_p *array, int count) {
	if (count <= 1) {
		return;
	}
	if (count % 2 == 0) {
		Student_p arr1[(count / 2)];
		Student_p arr2[(count / 2)];
		MergeSortArray(arr1, count / 2);
		MergeSortArray(arr2, count / 2);
	}
	else {
		Student_p arr1[(count / 2)];
		Student_p arr2[(count / 2) + 1];
		MergeSortArray(arr1, count / 2);
		MergeSortArray(arr2, (count / 2) + 1);
	}
	int e1 = 0, e2 = 0;
	for (int i = 0; i < count; i++) {
		if () {

		}
	}
	


}




//Auf true setzen, damit Listen-MergeSort getestet wird
bool MergeSortListImplemented() {
	return false;
}
//MergeSort mit Liste
void MergeSortList(StudentLP *anchor_adr) {
}

