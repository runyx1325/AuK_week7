/*
 ============================================================================
 Aufgabe     : Graphen
 Autor       : koetter
 Matrikel    : DIESE DATEI NICHT AENDERN
 Version     : DIESE DATEI NICHT AENDERN
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#include "dhbwtest.h"
#include "dhbwadjlist.h"
#include "dhbwgraphsolve.h"


int main(int argc, char *argv[]) {

	clock_t begin, end;

	begin = clock();

	if (argc != 2) {
		fprintf(stderr, "Usage: %s [<file>|<number of random graph nodes>]\n",
				argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Argument=%s\n", argv[1]);
	int amount = atoi(argv[1]);
	printf("Amount=%d\n", amount);





	AdjNodeP *inputGraph;
	if (amount > 0) {
		inputGraph = generateTestAdjList(amount);
	} else {
		inputGraph = AdjListFromFile(argv[1]);
	}


	printf("\n\n\nOriginal graph\n\n");
	AdjListPrintGraphviz(inputGraph, false);

	if(primImplemented()) {
		AdjListResetMarksAndResults(inputGraph);
		printf("\n\n\nMinimal spanning tree (Prim)\n\n");
		primMinimalSpanningTree(inputGraph);
		AdjListPrintGraphviz(inputGraph, false);
	}



	if(dijkstraImplemented()) {
		AdjListResetMarksAndResults(inputGraph);
		printf("\n\n\nShortest paths (Dijkstra)\n\n");
		dijkstraFindShortestFromFirst(inputGraph);
		AdjListPrintGraphviz(inputGraph, false);
	}

	end = clock();

	AdjListFree(inputGraph);

	exit(EXIT_SUCCESS);
}
