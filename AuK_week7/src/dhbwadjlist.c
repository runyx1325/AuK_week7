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
#include "dhbwadjlist.h"

AdjNodeP *AdjListAlloc() {
	AdjNodeP *newAdjList = malloc(sizeof(AdjNodeP));

		*newAdjList = NULL;

		return newAdjList;
}

AdjNodeP AdjNodeAlloc(char label) {
	AdjNodeP newAdjNode = malloc(sizeof(AdjNode));

	newAdjNode->next = NULL;
	newAdjNode->edges = NULL;
	newAdjNode->label = label;

	newAdjNode->result = -1;
	newAdjNode->predecessor = 0;
	newAdjNode->marked = false;

	return newAdjNode;
}

AdjEdgeP AdjEdgeAlloc(char from, char to, int weight) {
	AdjEdgeP newAdjEdge = malloc(sizeof(AdjEdge));

	newAdjEdge->first = from;
	newAdjEdge->first_node = NULL;
	newAdjEdge->second = to;
	newAdjEdge->second_node = NULL;
	newAdjEdge->weight = weight;

	newAdjEdge->marked = false;

	return newAdjEdge;
}

AdjEdgeLP AdjEdgeLAlloc(AdjEdgeP edge) {
	AdjEdgeLP newAdjEdgeL = malloc(sizeof(AdjEdgeL));

	newAdjEdgeL->edge = edge;
	newAdjEdgeL->next = NULL;
	return newAdjEdgeL;
}

void AdjListFree(AdjNodeP *list) {

	AdjNodeP currentN = *list;
	AdjEdgeLP currentE = NULL;

	currentN = *list;

	//free edges

	while(currentN != NULL) {
		currentE = currentN->edges;
		while(currentE != NULL) {
			AdjEdgeP currentEdge = currentE->edge;
			//avoid duplicate free of edge
			if(currentEdge->first == currentN->label) {
				free(currentEdge);
			}
			AdjEdgeLP nextE = currentE->next;
			free(currentE);
			currentE = nextE;
		}
		currentN = currentN->next;
	}

	//free nodes

	currentN = *list;

	while(currentN != NULL) {

		AdjNodeP nextN = currentN->next;
		free(currentN);
		currentN = nextN;
	}

	//free root
	free(list);

}


void AdjListResetMarksAndResults(AdjNodeP *list) {

	AdjNodeP currentN = *list;
	AdjEdgeLP currentE = NULL;

	currentN = *list;

	while(currentN != NULL) {
		currentN->marked = false;
		currentN->result = -1;
		currentN->predecessor = 0;

		currentE = currentN->edges;
		while(currentE != NULL) {
			AdjEdgeP currentEdge = currentE->edge;
			currentEdge->marked = false;
			currentE = currentE->next;
		}
		currentN = currentN->next;
	}


}



void addEdgeToNode(AdjNodeP node, AdjEdgeP edge) {

	if(node->edges == NULL) {
		node->edges = AdjEdgeLAlloc(edge);
		return;
	}

	AdjEdgeLP currentE = node->edges;
	while(currentE->next != NULL) {
		currentE = currentE->next;
	}
	currentE->next = AdjEdgeLAlloc(edge);
	return;
}

void AdjEdgeAdd(AdjNodeP *list, char first, char second, int weight) {
	AdjEdgeP newAdjEdge = AdjEdgeAlloc(first, second, weight);


	AdjNodeP toN = *list;

	while(toN != NULL && toN->label != second) {
		toN = toN->next;
	}

	if(toN == NULL) {
		printf("Unknown node label %c\n", second);
		return;
	}

	newAdjEdge->second_node = toN;

	AdjNodeP fromN = *list;

	while(fromN != NULL && fromN->label != first) {
		fromN = fromN->next;
	}

	if(fromN == NULL) {
		printf("Unknown node label %c\n", first);
		return;
	}

	newAdjEdge->first_node = fromN;

	addEdgeToNode(fromN, newAdjEdge);
	addEdgeToNode(toN, newAdjEdge);

}



AdjNodeP otherAdjNode(AdjNodeP node, AdjEdgeP edge) {

	if(edge->first == node->label) {
		return edge->second_node;
	}
	else {
		return edge->first_node;
	}
}


//-1 if edge doesn't exist
int AdjEdgeWeight(AdjNodeP *list, char from, char to) {

	int result = -1;

	AdjNodeP currentN = *list;
	while(currentN != NULL && currentN->label != from) {
		currentN = currentN->next;
	}
	if(currentN == NULL) {
		printf("Unknown node label %c\n", from);
		return result;
	}

	if(currentN->edges == NULL) {
		return result;
	}

	AdjEdgeLP currentE = currentN->edges;
	while(currentE != NULL && otherAdjNode(currentN, currentE->edge)->label != to) {
		currentE = currentE->next;
	}
	if(currentE != NULL) {
		result = currentE->edge->weight;
	}

	return result;
}

void AdjListPrintGraphviz(AdjNodeP *list, bool directed) {

	if(directed) {
		printf("digraph {\n");
	}
	else {
		printf("graph {\n");
	}

	AdjNodeP currentN = *list;
	AdjEdgeLP currentE = NULL;

	while(currentN != NULL) {
		printf("\t%c [%slabel=\"%c", currentN->label, currentN->marked ? "style=bold, color=blue, " : "", currentN->label);
		if(currentN->result >= 0) {
			printf(":%d", currentN->result);
		}
		printf("\"]\n", currentN->result);

		currentN = currentN->next;
	}

	currentN = *list;

	while(currentN != NULL) {
		currentE = currentN->edges;
		while(currentE != NULL) {
			AdjEdgeP currentEdge = currentE->edge;
			//avoid duplicate edges in Graphviz
			if(currentEdge->first == currentN->label || directed) {
				printf("\t%c %s %c[%slabel=\"%d\",weight=\"%d\"];\n", currentEdge->first, directed ? "->" : "--", currentEdge->second, currentEdge->marked ? "style=bold, color=blue, " : "", currentEdge->weight, currentEdge->weight);
			}
			currentE = currentE->next;
		}
		currentN = currentN->next;
	}
	printf("}\n");

}


AdjNodeP* AdjListFromFile(char *filename) {

	FILE *in = fopen(filename, "r");

	const int BUFFER_SIZE = 255;

	char string[BUFFER_SIZE + 1];

	//create nodes

	fgets(string, BUFFER_SIZE, in);
	//remove newline (works for both windows and unix)
	string[strcspn(string, "\r\n")] = 0;

	AdjNodeP* adjList = AdjListAlloc();

	AdjNodeP current = NULL;
	for(int i = 0; i < strlen(string);i++) {

		AdjNodeP adjNode = AdjNodeAlloc(string[i]);

		if(current == NULL) {
			*adjList = adjNode;
		}
		else {
			current->next = adjNode;
		}
		current = adjNode;
	}

	//create edges

	while (fgets(string, BUFFER_SIZE, in)) {

		//remove newline (works for both windows and unix)
		string[strcspn(string, "\r\n")] = 0;

		AdjEdgeAdd(adjList, string[0], string[1], atoi(&string[2]));

	}

	return adjList;
}


static const char graph_labels[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

AdjNodeP *generateTestAdjList(int nodeAmount) {
	//linit due to available labels
	int nodes = nodeAmount > 52 ? 52 : nodeAmount;

	//create random order of labels
	char orderedlabels[nodes];
	char randomlabels[nodes];
	int labelinds[nodes];

	for(int i = 0; i < nodes; i++) {
		labelinds[i] = i;
	}
	shuffle(labelinds, nodes);

	for(int i = 0; i < nodes; i++) {
		orderedlabels[i] = graph_labels[i];
	}

	for(int i = 0; i < nodes; i++) {
		randomlabels[i] = graph_labels[labelinds[i]];
	}

	//create nodes in ordered fashion
	AdjNodeP *list = AdjListAlloc();

	if(nodes == 0)
	{
		return list;
	}


	AdjNodeP current = AdjNodeAlloc(orderedlabels[0]);
	*list = current;

	for(int i = 1; i < nodes; i++) {
		AdjNodeP next = AdjNodeAlloc(orderedlabels[i]);
		current->next = next;
		current = next;
	}

	//create nodes - 1 edges with random list to make sure graph is connected
	for(int i = 1; i < nodes; i++) {
		int weight = rand() % 9 + 1;
		int to = rand() % i;

		AdjEdgeAdd(list, randomlabels[i], randomlabels[to], weight);
	}

	//create additional edges to make it more interesting
	for(int i = 0; i < nodes*4/7 ; i++) {
		//try for an edge that is not redundant
		for(int tries = 0; tries < nodes; tries++) {
			int weight = rand() % 9 + 1;
			char from = orderedlabels[rand() % nodes];
			char to = orderedlabels[rand() % nodes];
			if(from != to && AdjEdgeWeight(list, from, to) < 0) {
				AdjEdgeAdd(list, from, to, weight);
				break;
			}
		}
	}

	return list;
}



