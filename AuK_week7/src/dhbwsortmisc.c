/*
 ============================================================================
 Aufgabe     : Sortieren
 Autor       : koetter
 Matrikel    : DIESE DATEI NICHT AENDERN
 Version     : DIESE DATEI NICHT AENDERN
 ============================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dhbwsortmisc.h"

int matrCompare(const void * s1, const void * s2) {
	Student_p student1 = *((Student_p *)s1);
	Student_p student2 = *((Student_p *)s2);
	return student1->matrnr - student2->matrnr;
}

//Built-in quicksort
void QSortArray(Student_p *array, int count) {
	qsort(array, count, sizeof(Student_p), matrCompare);
}

//Use tree datastructure if implemented
void TreeSortArray(Student_p *array, int count) {
	StudentTP *tree = malloc(sizeof(StudentTP));
	*tree = NULL;

	for (int i = 0; i < count; i++) {
		StudentTInsertSorted(tree, array[i]);
	}

	//sorted list creates deepcopy, so we free the old list
	//not optimal, but we reuse the interface...
	StudentLP *new_anchor = StudentTToSortedList(tree);

	StudentLP current = *new_anchor;
	StudentLP oldcurrent = NULL;
	int i = 0;

	while (current) {
		array[i] = current->student;

		oldcurrent=current;
		current = current->next;
		i++;

		//we manually free to avoid freeing the students
		free(oldcurrent);
	}

	free(new_anchor);
	//this will free original students because we've created a copy
	StudentTFree(tree);

}

void TreeSortList(StudentLP *anchor_adr) {
	StudentTP *tree = malloc(sizeof(StudentTP));
	*tree = NULL;

	StudentLP current = *anchor_adr;

	while (current) {
		StudentLP newCurrent = current->next;
		StudentTInsertSorted(tree, current->student);

		//we manually free to avoid freeing the students
		free(current);

		current = newCurrent;
	}

	//sorted list creates deepcopy, so we free the old list
	//not optimal, but we reuse the interface...
	StudentLP *new_anchor = StudentTToSortedList(tree);
	//this will free original students because we've created a copy
	StudentTFree(tree);
	*anchor_adr = *new_anchor;
}

//Use list datastructure if implemented
void ListSortArray(Student_p *array, int count) {

	StudentLP *list = malloc(sizeof(StudentLP));
	*list = NULL;

	for (int i = 0; i < count; i++) {
		StudentLInsertSorted(list, array[i]);
	}

	StudentLP current = *list;
	StudentLP oldcurrent = NULL;
	int i = 0;

	while (current != NULL) {
		array[i] = current->student;
		oldcurrent = current;
		current = current->next;
		i++;

		//we manually free to avoid freeing the students
		free(oldcurrent);
	}
	free(list);
}

void ListSortList(StudentLP *anchor_adr) {

	StudentLP *newlist = malloc(sizeof(StudentLP));
	*newlist = NULL;

	StudentLP current = *anchor_adr;
	while (current != NULL) {
		StudentLP next = current->next;
		StudentLInsertSorted(newlist, current->student);
		//we manually free to avoid freeing the students
		free(current);
		current = next;
	}
	*anchor_adr = *newlist;
	free(newlist);
}

