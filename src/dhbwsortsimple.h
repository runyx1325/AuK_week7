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


#ifndef DHBWSORTSIMPLE_H_
#define DHBWSORTSIMPLE_H_


//Auf true setzen, damit BubbleSort getestet wird
bool BubbleSortImplemented();
//BubbleSort
void BubbleSortArray(Student_p *array, int count);


//Auf true setzen, damit SelectionSort getestet wird
bool SelectionSortImplemented();
//SelectionSort
void SelectionSortArray(Student_p *array, int count);


#endif /* DHBWSORTSIMPLE_H_ */
