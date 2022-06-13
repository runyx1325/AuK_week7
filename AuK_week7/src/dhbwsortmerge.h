/*
 ============================================================================
 Aufgabe     : Sortieren
 Autor       : koetter
 Matrikel    : DIESE DATEI NICHT AENDERN
 Version     : DIESE DATEI NICHT AENDERN
 ============================================================================
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dhbwstudent.h"
#include "dhbwstudentlist.h"
#include "dhbwstudenttree.h"


#ifndef DHBWSORTMERGE_H_
#define DHBWSORTMERGE_H_


//Auf true setzen, damit Array-MergeSort getestet wird
bool MergeSortArrayImplemented();
//MergeSort mit Array
void MergeSortArray(Student_p *array, int count);


//Auf true setzen, damit Listen-MergeSort getestet wird
bool MergeSortListImplemented();
//MergeSort mit Liste
void MergeSortList(StudentLP *anchor_adr);

#endif /* DHBWSORTMERGE_H_ */
