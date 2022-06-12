/*
 ============================================================================
 Aufgabe     : Graphen
 Autor       : koetter
 Matrikel    : DIESE DATEI NICHT AENDERN
 Version     : DIESE DATEI NICHT AENDERN
 ============================================================================
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dhbwadjlist.h"


#ifndef DHBWGRAPHSOLVE_H_
#define DHBWGRAPHSOLVE_H_

//Auf true setzen, damit Prim getestet wird
bool primImplemented();

//Berechnet den minimalen Spannbaum mittels Prim's Algorithmus
//Ausgabe: Kanten und Knoten, die zum minimalen Spannbaum gehoeren, sind markiert (marked=true)
void primMinimalSpanningTree(AdjNodeP *list);

//Auf true setzen, damit Dijkstra getestet wird
bool dijkstraImplemented();

//Berechnet die kuerzesten Wege vom ersten Knoten der Adjazenzliste (meistens:A) zu allen anderen mit Dijkstra's Algorithmus
//Ausgabe: Kanten, die zu einem kuerzesten Weg gehoeren, sind markiert (marked=true)
//Knoten, die vom ersten Knoten erreichbar sind, sind markkiert (marked=true)
//In jedem Knoten steht als result die Distanz vom ersten Knoten der Adjazenzliste
void dijkstraFindShortestFromFirst(AdjNodeP *list);






#endif /* DHBWGRAPHSOLVE_H_ */
