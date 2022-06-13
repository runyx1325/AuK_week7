/*
 ============================================================================
 Aufgabe     : Labyrinth
 Autor       : koetter
 Matrikel    : DIESE DATEI NICHT AENDERN
 Version     : DIESE DATEI NICHT AENDERN
 ============================================================================
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dhbwmaze.h"


#ifndef DHBWMAZESOLVE_H_
#define DHBWMAZESOLVE_H_

//Auf true setzen, damit Heapsort getestet wird
bool calcMazeDistanceImplemented();

//Berechne für jedes passierbare Feld die Distanz zum Start
//Markiere die Distanz mittels setCellCharacterByIndex
void calcMazeDistance(MazeP maze);

bool findMazePathImplemented();

//Finde mittels Tiefensuche (irgend)einen Weg vom Start zum Ziel
//Markiere den Weg der Reihe nach mittels setCellCharacterByIndex
void findMazePath(MazeP maze);

#endif /* DHBWMAZESOLVE_H_ */
