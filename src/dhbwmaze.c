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
#include "dhbwmaze.h"

static const char charByIndex[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz(){}[]§$%&-+,;:*~";

MazeP MazePAlloc(int mazesize) {
	MazeP newMazeP = malloc(sizeof(Maze));
	newMazeP->size = mazesize;
	newMazeP->start.x = 1;
	newMazeP->start.y = 1;
	newMazeP->goal.x = mazesize - 2;
	newMazeP->goal.y = mazesize - 2;
	newMazeP->maze = calloc(mazesize, sizeof *(newMazeP->maze));

	for (int i=0; i<mazesize; i++){
		newMazeP->maze[i] = calloc(mazesize, (mazesize + 1) * sizeof(char));
		newMazeP->maze[i][mazesize] = '\0';
	}

	return newMazeP;
}


void MazePFree(MazeP maze) {
	free(maze->maze);
	free(maze);
}

MazeP generateMaze(int mazesize) {

	MazeP maze = MazePAlloc(mazesize);
	//draw border
	for(int i = 0; i < maze->size; i++) {
		setCellUnPassable(maze, (MazeCoords){.x=0,.y=i});
		setCellUnPassable(maze, (MazeCoords){.x=i,.y=0});
		setCellUnPassable(maze, (MazeCoords){.x=maze->size-1,.y=i});
		setCellUnPassable(maze, (MazeCoords){.x=i,.y=maze->size-1});
	}

	//draw grid #
	for(int i = 1; i < maze->size - 1; i++) {
		for(int j = 1; j < maze->size - 1; j++) {

			if(i%2==1 && j%2==1) {
				setCellPassable(maze, (MazeCoords){.x=i,.y=j});
			}
			else {
				setCellUnPassable(maze, (MazeCoords){.x=i,.y=j});
			}
		}
	}

	//randomized walk
	bool finished = false;
	char dirc[]= "udlr";
	char oppdirc[]= "durl";
	int dirX[]= {0,0,-1,1};
	int dirY[]= {-1,1,0,0};
	MazeCoords currentCoords = (MazeCoords){.x=1,.y=1};
	//jump out of bounds when finished
	setCellCharacter(maze, currentCoords, 'l');
	while(inMazeBounds(maze, currentCoords)) {


		//find possible directions
		int founddirs[4] = {-1,-1,-1,-1};
		int founddirscount = 0;
		for(int dir = 0; dir < 4; dir++) {
			MazeCoords neighborCoords = (MazeCoords){.x=currentCoords.x+dirX[dir]*2,.y=currentCoords.y+dirY[dir]*2};
			if(inMazeBounds(maze, neighborCoords) && isCellChar(maze, neighborCoords, ' ')) {
				founddirs[founddirscount]=dir;
				founddirscount++;
			}
		}
		if(founddirscount > 0) {
			//choose a random direction
			int dir = founddirs[rand() % founddirscount];
			//remove wall
			MazeCoords neighborCoords = (MazeCoords){.x=currentCoords.x+dirX[dir]*1,.y=currentCoords.y+dirY[dir]*1};
			setCellPassable(maze, neighborCoords);
			//jump to next cell
			currentCoords = (MazeCoords){.x=currentCoords.x+dirX[dir]*2,.y=currentCoords.y+dirY[dir]*2};
			//mark backjump direction
			setCellCharacter(maze, currentCoords, oppdirc[dir]);
		}
		else {
			//backtrack
			//get dir back
			char backdirc = getCellChar(maze, currentCoords);
			int dir;
			for (dir = 0; dir < 4; dir++) {
				if (backdirc == dirc[dir]) {
					break;

				}
			}
			//set current cell as _f_inished and track back
			setCellCharacter(maze, currentCoords, 'f');
			currentCoords = (MazeCoords ) {
							.x = currentCoords.x + dirX[dir] * 2, .y =
									currentCoords.y + dirY[dir] * 2 };
		}

	}

	//cleanup all inbetween characters
	for(int i = 1; i < maze->size - 1; i++) {
		for(int j = 1; j < maze->size - 1; j++) {

			if(isCellPassable(maze, (MazeCoords){.x=i,.y=j})) {
				setCellPassable(maze, (MazeCoords){.x=i,.y=j});
			}
		}
	}

	//border fix for even size
	if(maze->size % 2 == 0) {
		setCellPassable(maze, (MazeCoords){.x=maze->size-2,.y=maze->size-3});
		setCellPassable(maze, (MazeCoords){.x=maze->size-3,.y=maze->size-2});
		for(int i = 1; i < maze->size-3; i++) {
			if(rand() % 2) {
				setCellPassable(maze, (MazeCoords){.x=maze->size-2,.y=i});
			}
			if(rand() % 2) {
				setCellPassable(maze, (MazeCoords){.x=i,.y=maze->size-2});
			}
		}

	}

	setCellCharacter(maze, maze->start, '?');
	setCellCharacter(maze, maze->goal, '!');

	return maze;
}


MazeP MazeFromFile(char *filename) {

	FILE *in = fopen(filename, "r");

	const int BUFFER_SIZE = 255;

	char string[BUFFER_SIZE + 1];

	//create nodes

	fgets(string, BUFFER_SIZE, in);
	//remove newline (works for both windows and unix)
	string[strcspn(string, "\r\n")] = 0;

	int mazeSize = strlen(string);

	MazeP maze = MazePAlloc(mazeSize);
	for(int i = 0; i < strlen(string);i++) {
		setCellCharacter(maze, (MazeCoords){.x=i,.y=0}, string[i]);
		if(string[i] == '?') {
			maze->start = (MazeCoords){.x=i,.y=0};
		}
		else if(string[i] == '!') {
			maze->goal = (MazeCoords){.x=i,.y=0};
		}
	}


	//   ^__________^ YUM!
	int curry = 1;
	while (fgets(string, BUFFER_SIZE, in)) {

		//remove newline (works for both windows and unix)
		string[strcspn(string, "\r\n")] = 0;

		for(int i = 0; i < strlen(string);i++) {
			setCellCharacter(maze, (MazeCoords){.x=i,.y=curry}, string[i]);
			if(string[i] == '?') {
				maze->start = (MazeCoords){.x=i,.y=curry};
			}
			else if(string[i] == '!') {
				maze->goal = (MazeCoords){.x=i,.y=curry};
			}
		}
		curry++;
	}

	return maze;
}



void cleanupMaze(MazeP maze) {

	//cleanup all inbetween characters
	for(int i = 0; i < maze->size - 1; i++) {
		for(int j = 0; j < maze->size - 1; j++) {

			if(isCellPassable(maze, (MazeCoords){.x=i,.y=j})) {
				setCellPassable(maze, (MazeCoords){.x=i,.y=j});
			}
		}
	}
	setCellCharacter(maze, maze->start, '?');
	setCellCharacter(maze, maze->goal, '!');
}

bool inMazeBounds(MazeP maze, MazeCoords coords) {
	return coords.x >= 0 && coords.y >= 0 && coords.x < maze->size && coords.y < maze->size;
}
bool onMazeBorder(MazeP maze, MazeCoords coords) {
	return coords.x == 0 || coords.y == 0 || coords.x == maze->size - 1 || coords.y == maze->size -1;
}
bool isCellPassable(MazeP maze, MazeCoords coords) {
	return maze->maze[coords.y][coords.x] != '#';
}
bool isCellChar(MazeP maze, MazeCoords coords, char c) {
	return maze->maze[coords.y][coords.x] == c;
}

char getCellChar(MazeP maze, MazeCoords coords) {
	return maze->maze[coords.y][coords.x];
}

void setCellPassable(MazeP maze, MazeCoords coords) {
	setCellCharacter(maze, coords, ' ');
}
void setCellUnPassable(MazeP maze, MazeCoords coords) {
	setCellCharacter(maze, coords, '#');
}

void setCellCharacter(MazeP maze, MazeCoords coords, char c) {
	maze->maze[coords.y][coords.x] = c;
}
void setCellCharacterByIndex(MazeP maze, MazeCoords coords, int index) {
	setCellCharacter(maze, coords, charByIndex[index % strlen(charByIndex)]);
}

void printMaze(MazeP maze) {

	printf("\n");
	for(int i = 0; i < maze->size; i++) {
		printf("%s\n", maze->maze[i]);
	}
	printf("\n");
}
