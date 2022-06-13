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


#ifndef DHBWMAZE_H_
#define DHBWMAZE_H_

static const char CELL_EMPTY = ' ';
static const char CELL_WALL = '#';
static const char CELL_START = '?';
static const char CELL_GOAL = '!';

typedef struct mazecoords {
	int x;
	int y;
} MazeCoords;

typedef struct maze {
	int size;
	MazeCoords start;
	MazeCoords goal;

	char **maze;

} Maze, *MazeP;

//Allocation methods
MazeP MazePAlloc(int mazesize);
void MazePFree(MazeP maze);

//Create mazes
MazeP generateMaze(int mazesize);
MazeP MazeFromFile(char *filename);

//Remove everything that's not #, restore ? and !
void cleanupMaze(MazeP maze);

//Checks if a pair of coordinates is within the limits of the maze
bool inMazeBounds(MazeP maze, MazeCoords coords);
//Checks if a pair of coordinates is on the outer border of the maze
bool onMazeBorder(MazeP maze, MazeCoords coords);
//Returns true if a cell can be passed (everything except #)
bool isCellPassable(MazeP maze, MazeCoords coords);

//Returns true if a cell contains the specified character
bool isCellChar(MazeP maze, MazeCoords coords, char c);

//Returns the character at the specified coordinates
char getCellChar(MazeP maze, MazeCoords coords);

//Change characters in cells
void setCellPassable(MazeP maze, MazeCoords coords);
void setCellUnPassable(MazeP maze, MazeCoords coords);
void setCellCharacter(MazeP maze, MazeCoords coords, char c);

//Sets a rising character by number (0-9A-Za-z ...)
//Warning: Characters may loop for large numbers
void setCellCharacterByIndex(MazeP maze, MazeCoords coords, int index);

//Output the maze to console
void printMaze(MazeP maze);

#endif /* DHBWMAZE_H_ */
