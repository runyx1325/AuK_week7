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
	int help;
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
			help = gci;
			array[gci] = array[nodeIndex];
			array[nodeIndex] = array[help];
			HeapBubbleDown(array, gci, end);
		}
	}
}

//Stellt Heap-Eigenschaft in einem Array (als Binaerbaum interpretiert) her
void Heapify(Student_p *array, int count) {
	int end = count;
	int last = (count - 1) / 2;
	for (int i = last; i >= 0; i--) {
		HeapBubbleDown(array, i, end);
	}
}


//Heapsort mit Array
//Tipp: Hilfsfunktionen benutzen
void HeapSortArray(Student_p *array, int count) {
	int last = count - 1;
	int help;
	Heapify(array, count);
	for (int i = last; i > 0; i--) {
		help = i;
		array[i] = array[0];
		array[0] = array[help];
		HeapBubbleDown(array, 0, i);
	}
}

