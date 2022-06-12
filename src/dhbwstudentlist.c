/*
 ============================================================================
 Aufgabe     : Datenstrukturen - Woche 4
 Autor       :
 Matrikel    :
 Version     :
 ============================================================================
 */
#include <stdbool.h>
#include <stdlib.h>
#include "dhbwstudentlist.h"
#include "dhbwstudent.h"


//DIESE METHODEN NICHT AENDERN

StudentLP StudentLPAlloc(Student_p newStudent) {

	StudentLP newStudentLP = malloc(sizeof(StudentL));

	newStudentLP->student = newStudent;
	newStudentLP->next = NULL;

	return newStudentLP;
}

void StudentLInsertFirst(StudentLP *anchor_adr, Student_p newStudent) {
	StudentLP oldFirst = *anchor_adr;
	StudentLP newFirst = StudentLPAlloc(newStudent);
	*anchor_adr = newFirst;
	newFirst->next = oldFirst;
}

void StudentLInsertLast(StudentLP *anchor_adr, Student_p newStudent) {

	StudentLP current = *anchor_adr;
	StudentLP previous = NULL;

	StudentLP newLP = StudentLPAlloc(newStudent);

	while (current != NULL) {
		previous = current;
		current = current->next;
	}

	if (previous != NULL) {
		previous->next = newLP;
	} else {
		*anchor_adr = newLP;
	}

}

int StudentLSize(StudentLP *anchor_adr) {

	StudentLP current = *anchor_adr;

	int size = 0;

	while (current != NULL) {
		size++;
		current = current->next;
	}

	return size;
}

void StudentLPFree(StudentLP info) {
	if (info == NULL)
		return;

	StudentFree(info->student);
	free(info);
	return;
}

void StudentLFree(StudentLP *anchor_adr) {

	StudentLP current = *anchor_adr;

	while (current) {
		StudentLP newCurrent = current->next;
		StudentLPFree(current);
		current = newCurrent;
	}

	*anchor_adr = NULL;
	return;
}

StudentLP deepLPCopy(StudentLP info) {
	if (info == NULL)
		return NULL;
	StudentLP copy = StudentLPAlloc(deepCopy(info->student));
	copy->next = NULL;
	return copy;
}

StudentLP* deepLCopy(StudentLP *anchor_adr) {
	if (anchor_adr == NULL)
		return NULL;

	StudentLP *copy = malloc(sizeof(StudentLP));
	*copy = NULL;

	StudentLP current = *anchor_adr;

	while (current) {
		StudentLInsertLast(copy, deepCopy(current->student));
		current = current->next;
	}

	return copy;
}

StudentLP* StudentsFromFile(char *filename) {

	FILE *in = fopen(filename, "r");

	char string[BUF_SIZE];
	StudentLP *all_students = malloc(sizeof(StudentLP));
	*all_students = NULL;
	StudentLP reverse_students_anchor = NULL;
	StudentLP *reverse_students = &reverse_students_anchor;

	while (fgets(string, BUF_SIZE, in)) {

		//remove newline (works for both windows and unix)
		string[strcspn(string, "\r\n")] = 0;

		//printf("%s\n", string);
		StudentLInsertFirst(reverse_students, StudentAlloc(string));
	}

	//create normal ordered list
	{
		StudentLP current = *reverse_students;
		while (current != NULL) {
			StudentLInsertFirst(all_students, deepCopy(current->student));
			current = current->next;
		}
	}

	StudentLFree(reverse_students);

	return all_students;
}

StudentLP* ArrayToStudentL(Student_p *array, int count, bool doDeepCopy) {

	StudentLP* list = malloc(sizeof(StudentLP));
	*list=NULL;

	for(int i = count -1; i >= 0; i--) {
		if(doDeepCopy) {
			StudentLInsertFirst(list, deepCopy(array[i]));
		}
		else {
			StudentLInsertFirst(list, array[i]);
		}
	}
	return list;
}

Student_p *StudentLToArray(StudentLP *anchor_adr, int *outcount, bool doDeepCopy) {

	*outcount = StudentLSize(anchor_adr);

	Student_p * array = calloc(*outcount, sizeof(Student_p));

	StudentLP current = *anchor_adr;
	int i = 0;
	while (current != NULL) {
		if(doDeepCopy) {
			array[i] = deepCopy(current->student);
		}
		else {
			array[i] = current->student;
		}
		current = current->next;
		i++;
	}

	return array;
}

//Bis hier nicht aendern



//Ab hier Aufgaben

bool StudentLImplemented() {
	//TODO: hier auf true aendern, damit Ihre Implementierung getestet wird
	return false;
}

bool StudentLContainsStudent(StudentLP *anchor_adr, Student_p student) {
	return false;
}

StudentLP StudentLExtractStudent(StudentLP *anchor_adr, Student_p student) {
	return NULL;
}

StudentLP StudentLFindStudent(StudentLP *anchor_adr, Student_p student) {
	return NULL;
}

StudentLP StudentLFindByMatr(StudentLP *anchor_adr, int matrnr) {
	return NULL;
}

StudentLP StudentLFindByName(StudentLP *anchor_adr, char *lastname) {
	return NULL;
}

void StudentLInsertSorted(StudentLP *anchor_adr, Student_p newStudent) {

}
