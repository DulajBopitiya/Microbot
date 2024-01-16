#include <stdio.h>

#define ROWS 5
#define COLS 5

// Function to perform flood fill
void floodFill(int maze[ROWS][COLS], int row, int col, int targetColor, int replacementColor) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || maze[row][col] != targetColor) {
        return;
    }

    maze[row][col] = replacementColor;

    floodFill(maze, row + 1, col, targetColor, replacementColor);
    floodFill(maze, row - 1, col, targetColor, replacementColor);
    floodFill(maze, row, col + 1, targetColor, replacementColor);
    floodFill(maze, row, col - 1, targetColor, replacementColor);
}

// Function to print the maze
void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLS] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    printf("Original Maze:\n");
    printMaze(maze);

    int targetColor = maze[1][1];  // Target color to be replaced
    int replacementColor = 2;      // Color to replace with

    floodFill(maze, 1, 1, targetColor, replacementColor);

    printf("\nMaze after Flood Fill:\n");
    printMaze(maze);

    return 0;
}
