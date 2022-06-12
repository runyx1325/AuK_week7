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


#ifndef DHBWSORTMISC_H_
#define DHBWSORTMISC_H_

//Eingebauter Quicksort
void QSortArray(Student_p *array, int count);

//Sortieren mit Binärbaum (falls StudentT implementiert)
void TreeSortArray(Student_p *array, int count);
void TreeSortList(StudentLP *anchor_adr);

//Sortieren mit Liste (falls StudentL implementiert)
void ListSortArray(Student_p *array, int count);
void ListSortList(StudentLP *anchor_adr);

#endif /* DHBWSORTMISC_H_ */
