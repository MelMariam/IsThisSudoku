#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"
using namespace std;
#define empty 0
#define N 9
bool rightChoice(int matrix[N][N], int prow, int pcol, int number)
{
    return !InRow(matrix, prow, number) && !InCol(matrix, pcol, number) &&
        !InBox(matrix, prow - prow % 3, pcol - pcol % 3, number);
}

bool InRow(int matrix[N][N], int prow, int number)
{
    for (int col = 0; col < N; col++)
    {
        if (matrix[prow][col] == number)
        {
            return true;
        }
    }
    return false;
}

bool InCol(int matrix[N][N], int pcol, int number)
{
    for (int row = 0; row < N; row++)
    {
        if (matrix[row][pcol] == number)
        {
            return true;
        }
    }
    return false;
}

bool InBox(int matrix[N][N], int boxBeginRow, int boxBeginCol, int number)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (matrix[row + boxBeginRow][col + boxBeginCol] == number)
            {
                return true;
            }
        }
    }
    return false;
}

void printGrid(int matrix[N][N]) {
    cout << "Current Puzzle:" << endl;
    for (int row = 0; row < N; row++) {
        if (row > 0 && row % 3 == 0) {
            cout << "------+-------+------" << endl; // Print horizontal line after every 3 rows
        }
        for (int col = 0; col < N; col++) {
            if (col > 0 && col % 3 == 0) {
                cout << "| "; // Print vertical separator after every 3 columns within each row
            }
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}
void generateSudoku(int matrix[N][N])
{
    srand(time(nullptr));

    // Generate a solved Sudoku puzzle
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            matrix[row][col] = (row * 3 + row / 3 + col) % N + 1;
        }
    }

    // Shuffle rows within each box
    for (int box = 0; box < N; box += 3)
    {
        int r1 = rand() % 3;
        int r2 = rand() % 3;

        for (int j = 0; j < N; j++)
        {
            swap(matrix[box + r1][j], matrix[box + r2][j]);
        }
    }

    // Shuffle columns within each box
    for (int box = 0; box < N; box += 3)
    {
        int c1 = rand() % 3;
        int c2 = rand() % 3;

        for (int j = 0; j < N; j++)
        {
            swap(matrix[j][box + c1], matrix[j][box + c2]);
        }
    }
    //I will comment this part so u won't be able to see the initial solved puzzle
    //if you want to see it just uncomment it
    /* cout << "Generated Solved Puzzle:" << endl;
    printGrid(grid);*/
    // hide some cells to create the puzzle
    int hidden = 30;  // You can adjust this value for difficulty
    while (hidden> 0)
    {
        int row = rand() % N;
        int col = rand() % N;
        if (matrix[row][col] != empty)
        {
            matrix[row][col] = empty;
            hidden--;
        }
    }
}
//check wether sudoku is solved or not
bool solved(int m[N][N])
{
    for (int r = 0; r< N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (m[r][c] == 0)
            {
                return false;
            }
        }
    }
    return true;
}