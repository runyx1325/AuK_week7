/*
 ============================================================================
 Aufgabe     : Datenstrukturen - Woche 6
 Autor       :
 Matrikel    :
 Version     :
 ============================================================================
 */
#include <stdbool.h>
#include <stdlib.h>
#include "dhbwstudent.h"
#include "dhbwstudentmap.h"

//DIESE METHODEN NICHT AENDERN

StudentMP StudentMPAlloc(int mapsize, int (*hashf)(Student_p student, int maxsize)) {
	StudentMP newStudentMP = malloc(sizeof(StudentM));

	newStudentMP->currsize = 0;
	newStudentMP->maxsize = mapsize;
	newStudentMP->hashf = hashf;
	newStudentMP->table = calloc(mapsize, sizeof(Student_p));
	return newStudentMP;
}

void StudentMPFree(StudentMP map) {
	if (map == NULL)
			return;

	for(int i = 0; i < map->maxsize; i++) {
		StudentFree(map->table[i]);
	}

	free(map);
}

int dumbHashByMatr(Student_p student, int maxsize) {
	//this is a bad hash function as it only gives you 10 possible values
	//and ignores the lower digits completely
	return (student->matrnr / 100000) % maxsize;
}


//Bis hier nicht ändern



//Ab hier Aufgaben



bool StudentMImplemented() {
	//TODO: hier auf true aendern, damit Ihre Implementierung getestet wird
	return false;
}
int hashByMatr(Student_p student, int maxsize) {
	return -1;
}

int hashByName(Student_p student, int maxsize) {
	return -1;
}

int hashByBoth(Student_p student, int maxsize) {
	return -1;
}

Student_p StudentMFind(StudentMP map, Student_p student) {
	return NULL;
}

void StudentMRehash(StudentMP map, int newsize) {

}

bool StudentMInsert(StudentMP map, Student_p newStudent) {
	return false;
}

int StudentMSize(StudentMP map) {
	return -1;
}

StudentLP* StudentMToList(StudentMP map) {
	return NULL;
}

