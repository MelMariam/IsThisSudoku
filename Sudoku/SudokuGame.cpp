#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"
using namespace std;

int main()
{   
    int matrix[N][N];
    int mistakeCounter = 0;
    //int hintCounter = 3;

    cout << "--------------Sudoku--------------" << endl;
    
    generateSudoku(matrix);
   //cout << "Mistakes: " << mistakeCounter << "/3,  Hints: " << hintCounter << "/3\n";
    cout << "Mistakes: " << mistakeCounter << "/3\n";
    printGrid(matrix);
    cout << "Rules:\n";
    cout << "Enter row, column, and value (in that order) separated by spaces.\nEnter -1 to finish.\n" ;

    int row, col, value;
    while (!solved(matrix) && mistakeCounter < 3)
    {   
       
        cout << "Enter your move:\n";
        cin >> row;
        //EXIT
        if (row == -1)
        {
            cout << "okay, bye\n";
            exit(-1);
           
        }
        //USE HINT
        //else if (row == 0) {
        //    if (hintCounter > 0) {
        //        hintCounter--;

        //        //show hint
        //        int r = rand() % N;
        //        int c = rand() % N;

        //        if (matrix[r][c] != empty) {
        //            continue; // Skip non-empty cells
        //        }
        //        int correctNumber = 0;
        //        for (int num = 1; num <= N; num++) {
        //            if (rightChoice(matrix, r, c, num)) {
        //                correctNumber = num;
        //                break;
        //            }
        //        }
        //  
        //        cout << "Hint: The number at row " << r + 1 << ", column " << c + 1 << " is " << correctNumber << endl;
        //        matrix[r][c] = correctNumber; // Reveal the number in the empty cell as a hint
        //    }        
        //    else {
        //        cout << "No more hints to use.insert your answer:\n";
        //        continue;
        //    }
        //}
        //PLAY
        else
        cin >> col >> value;

        row--; // Adjust to 0-based indexing
        col--;
        //validate input
        if (row < 0 || row >= N || col < 0 || col >= N || value < 1 || value > 9)
        {
            cout << "Invalid move. Please try again." << endl;
            continue;
        }
        //check input
        if (!rightChoice(matrix, row, col, value))
        {
            cout << "M I S T A K E " << endl;
            mistakeCounter++;
            cout << 3 - mistakeCounter << " Chances left.\n";
            continue;
        }
        //update indexed place and Print edited grid
        matrix[row][col] = value;
        //cout << "Mistakes: " << mistakeCounter << "/3,  Hints: " << hintCounter << "/3\n";
        cout << "Mistakes: " << mistakeCounter << "/3\n";
        printGrid(matrix);
    }
    if (mistakeCounter ==3) {
        cout << "You lost ;(\n";
    }else
    cout << "YOU WON! THANKS FOR PLAYING!" << endl;

    return 0;
}


