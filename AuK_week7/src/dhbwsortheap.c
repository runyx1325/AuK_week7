/*
 ============================================================================
 Aufgabe     : Sortieren - Woche 9
 Autor       : Burst
 Matrikel    :
 Version     :
 ============================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dhbwsortheap.h"


//Ab hier Aufgaben

//Auf true setzen, damit Heapsort getestet wird
bool HeapSortImplemented() {
	return true;
}

//Hilfsfunktionen

//Lasse kleinen Knoten nach unten sinken
void HeapBubbleDown(Student_p *array, int nodeIndex, int end) {
	int gci, rci;
	int lci = 2 * nodeIndex + 1;
	if (lci < end) {
		gci = lci;
		rci = lci + 1;
		if (rci < end) {
			if (array[rci] > array[lci]) {
				gci = rci;
			}
		}
		if (array[gci] > array[lci]) {
			//swap
			Student_p temp = array[gci];
			array[gci] = array[nodeIndex];
			array[nodeIndex] = temp;
			HeapBubbleDown(array, gci, end);
		}
	}
}

//Stellt Heap-Eigenschaft in einem Array (als Binaerbaum interpretiert) her
void Heapify(Student_p *array, int count) {
	int end = count;
	int last = (count - 1) / 2;
	//int i = last;
	for (int i = last; i >= 0; i--) {
		HeapBubbleDown(array, i, end);
	}
}


//Heapsort mit Array
//Tipp: Hilfsfunktionen benutzen
void HeapSortArray(Student_p *array, int count) {
	Heapify(array, count);
	for (int i = count - 1; i > 0; i--) {
		Student_p temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		HeapBubbleDown(array, 0, i);
	}
	return;
}

