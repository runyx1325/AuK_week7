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
#include "dhbwtest.h"

#ifndef DHBWADJLIST_H_
#define DHBWADJLIST_H_

//Datentyp fuer Knoten des Graphen
//Bilden die "Hauptliste" der Adjazenzliste
typedef struct adj_node {
	char label;
	struct adj_node *next;
	struct adj_edge_l *edges;

	//Nutzen Sie diese Felder fuer eigene Algorithmen
	bool marked; //initialisiert auf false
	char predecessor; //initialisiert auf 0
	int result; //output if >= 0, initialisiert auf -1
} AdjNode, *AdjNodeP;

//Datentyp fuer ungerichtete Kanten
typedef struct adj_edge {
	char first;
	struct adj_node *first_node;
	char second;
	struct adj_node *second_node;
	int weight;
	//Nutzen Sie diese Felder fuer eigene Algorithmen
	bool marked; //initialisiert auf false
} AdjEdge, *AdjEdgeP;

//Datentyp fuer Liste aus Kanten eines Knotens
//Eine Kante ist im ungerichteten Graph in den Listen beider Knoten, die sie verbindet!
typedef struct adj_edge_l {
	struct adj_edge *edge;
	struct adj_edge_l *next;
} AdjEdgeL, *AdjEdgeLP;



//Funktionen fuer die Allokation
AdjNodeP *AdjListAlloc() ;
AdjNodeP AdjNodeAlloc(char label);
AdjEdgeP AdjEdgeAlloc(char first, char second, int weight) ;
void AdjListFree(AdjNodeP *list);

//Entfernt alle Markierungen, predecessors und results von Knoten und Kanten
void AdjListResetMarksAndResults(AdjNodeP *list);

//Fuegt eine ungerichtete Kante hinzu (in die Listen beider Knoten)
void AdjEdgeAdd(AdjNodeP *list, char first, char second, int weight);

//Gibt das Gewicht einer Kante zurueck
//-1 falls die Kante nicht existiert
int AdjEdgeWeight(AdjNodeP *list, char first, char second) ;

//Navigiert zum anderen Knoten einer verbundenen Kante
//z.B. Knoten A und Kante A--B gibt Knoten B zurueck
AdjNodeP otherAdjNode(AdjNodeP node, AdjEdgeP edge);

//Gibt die Adjazenzliste als Graphen im Graphviz-format dot aus
//Falls directed auf true gesetzt ist, werden gerichtete Kanten ausgegeben
void AdjListPrintGraphviz(AdjNodeP *list, bool directed);

//Liste eine Adjazenzliste aus einer Textdatei ein
AdjNodeP* AdjListFromFile(char *filename);

//Generiert eine zufaellige Adjazenzliste
AdjNodeP *generateTestAdjList(int nodeAmount);

#endif /* DHBWADJLIST_H_ */
