/*
 ============================================================================
 Aufgabe     : Datenstrukturen - Woche 10
 Autor       : Burst
 Matrikel    : 4581869
 Version     : 1.0
 ============================================================================
 */
#include <stdbool.h>
#include <stdlib.h>
#include "dhbwgraphsolve.h"

// addEdgeToNode(AdjNodeP node, AdjEdgeP edge)
// AdjEdgeAdd(AdjNodeP *list, char first, char second, int weight)
// otherAdjNode(AdjNodeP node, AdjEdgeP edge)
// //-1 if edge doesn't exist
// int AdjEdgeWeight(AdjNodeP* list, char from, char to)
// AdjListPrintGraphviz(AdjNodeP *list, bool directed)
// 
//Ab hier Aufgaben

//Auf true setzen, damit Prim getestet wird
bool primImplemented() {
	return true;
}

//Berechnet den minimalen Spannbaum mittels Prim's Algorithmus
//Ausgabe: Kanten und Knoten, die zum minimalen Spannbaum gehoeren, sind markiert (marked=true)
void primMinimalSpanningTree(AdjNodeP* list) {
	
	int countNodes = countN(list);
	(*list)->marked = true;
	for (int i = 0; i < countNodes - 1; i++) {
		AdjNodeP currentNode = *list;
		AdjEdgeP minEdge = NULL;
		while (currentNode) {
			AdjEdgeLP currentEdge = currentNode->edges;
			while (currentEdge) {
				if (possibleEdge(currentEdge->edge)) {
					if (!minEdge) {
						if (!currentEdge->edge->marked) {
							minEdge = currentEdge->edge;
						}
					}
					else {
						if (!currentEdge->edge->marked) {
							if (minEdge->weight > currentEdge->edge->weight) {
								minEdge = currentEdge->edge;
							}
						}
					}
				}
				currentEdge = currentEdge->next;
			}
			currentNode = currentNode->next;
		}
		minEdge->marked = true;
		minEdge->first_node->marked = true;
		minEdge->second_node->marked = true;
	}
}

bool possibleEdge(AdjEdgeP edge) {
	return !(edge->first_node->marked == true && edge->second_node->marked == true) || (edge->first_node->marked == false && edge->second_node->marked == false);
}
	

int countN(AdjNodeP* list) {
	int counter = 0;
	AdjNodeP cur = *list;
	while (cur->next != 0) {
		counter++;
		cur = cur->next;
	}
}

//Auf true setzen, damit Dijkstra getestet wird
bool dijkstraImplemented() {
	return false;
}

//Berechnet die kuerzesten Wege vom ersten Knoten der Adjazenzliste (meistens:A) zu allen anderen mit Dijkstra's Algorithmus
//Ausgabe: Kanten, die zu einem kuerzesten Weg gehoeren, sind markiert (marked=true)
//Knoten, die vom ersten Knoten erreichbar sind, sind markkiert (marked=true)
//In jedem Knoten steht als result die Distanz vom ersten Knoten der Adjazenzliste
void dijkstraFindShortestFromFirst(AdjNodeP *list) {

}

