/*
 ============================================================================
 Aufgabe     : Sortieren - Woche 7
 Autor       : Burst
 Matrikel    : 4581869
 Version     : 1.0
 ============================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dhbwsortsimple.h"

//Ab hier Aufgaben


//Auf true setzen, damit BubbleSort getestet wird
bool BubbleSortImplemented() {
	return true;
}

//BubbleSort
void BubbleSortArray(Student_p *array, int count) {
	for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (array[j]->matrnr > array[j + 1]->matrnr) {
                Student_p temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
	}
}


//Auf true setzen, damit SelectionSort getestet wird
bool SelectionSortImplemented() {
	return true;
}

//SelectionSort
void SelectionSortArray(Student_p *array, int count) {   
    int i, j;
    
    for (i = 0; i < count - 1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (j = i + 1; j < count; j++) {
            if (array[j]->matrnr < array[min_idx]->matrnr) {
                min_idx = j;
            }
        }

        // Swap the found minimum element
        // with the first element
        Student_p temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}
