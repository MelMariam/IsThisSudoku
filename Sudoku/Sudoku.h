#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define empty 0
const int N = 9;

bool rightChoice(int matrix[N][N], int row, int col, int num);
bool InRow(int matrix[N][N], int prow, int number);
bool InCol(int matrix[N][N], int pcol, int number);
bool InBox(int matrix[N][N], int boxBeginRow, int boxBeginCol, int number);
void printGrid(int matrix[N][N]);
void generateSudoku(int matrix[N][N]);
bool solved(int matrix[N][N]);