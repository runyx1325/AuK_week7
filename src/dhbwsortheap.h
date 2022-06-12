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


#ifndef DHBWSORTHEAP_H_
#define DHBWSORTHEAP_H_


//Auf true setzen, damit Heapsort getestet wird
bool HeapSortImplemented();

//Hilfsfunktionen

//Lasse kleinen Knoten nach unten sinken
void HeapBubbleDown(Student_p *array, int nodeIndex, int end);

//Stellt Heap-Eigenschaft in einem Array (als Binaerbaum interpretiert) her
void Heapify(Student_p *array, int count);


//Heapsort mit Array
//Tipp: Hilfsfunktionen benutzen
void HeapSortArray(Student_p *array, int count);

#endif /* DHBWSORTHEAP_H_ */
