/*
 ============================================================================
 Aufgabe     : Sortieren - Woche 7
 Autor       :
 Matrikel    :
 Version     :
 ============================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dhbwsortsimple.h"

//Ab hier Aufgaben


//Auf true setzen, damit BubbleSort getestet wird
bool BubbleSortImplemented() {
	return false;
}

//BubbleSort
void BubbleSortArray(Student_p *array, int count) {
	for (int i = 0; i < count; i++) {

	}
}


//Auf true setzen, damit SelectionSort getestet wird
bool SelectionSortImplemented() {
	return true;
}

//SelectionSort
void SelectionSortArray(Student_p *array, int count) {
     
    int i, j;
    // One by one move boundary of unsorted subarray
    
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
        Student_p temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
    //Eigentlich sortiert der SelectionSort alles, jedoch fliege ich bei einem der Tests immer wieder raus. Habe noch nicht ganz verstanden warum. Vielleicht liegt es Mal wieder an der IDE.
    //Man bekommt es übrigens auch mit VisualStudio mit einem anderen Compiler zu laufen.
}
