/*
 ============================================================================
 Aufgabe     : Labyrinth
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
#include "dhbwmaze.h"
#include "dhbwmazesolve.h"

int main(int argc, char *argv[]) {

	clock_t begin, end;

	begin = clock();

	if (argc != 2) {
		fprintf(stderr, "Usage: %s [<file>|<number for size of random maze>]\n",
				argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Argument=%s\n", argv[1]);
	int amount = atoi(argv[1]);
	printf("Amount=%d\n", amount);



	MazeP inputMaze;
	if (amount > 0) {
		inputMaze = generateMaze(amount);
	} else {
		inputMaze = MazeFromFile(argv[1]);
	}

	printf("\n\n\nOriginal maze\n\n");
	printMaze(inputMaze);


	if(calcMazeDistanceImplemented())
	{
		calcMazeDistance(inputMaze);
		printf("\n\n\nMaze distances\n\n");
		printMaze(inputMaze);
		cleanupMaze(inputMaze);
	}


	if(findMazePathImplemented())
	{
		findMazePath(inputMaze);
		printf("\n\n\nMaze path to goal\n\n");
		printMaze(inputMaze);
		cleanupMaze(inputMaze);
	}


	end = clock();

	free(inputMaze);

	exit(EXIT_SUCCESS);
}
