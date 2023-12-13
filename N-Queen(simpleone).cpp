#include <iostream>
using namespace std;
bool isSafe(int board[][10], int row, int col, int n)
 {

    // Check if there is a queen in the same column

    for (int i = 0; i < row; i++) 
	{

        if (board[i][col] == 1) 
		{

            return false;

        }

    }


    // Check if there is a queen in the upper left diagonal

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	 {

        if (board[i][j] == 1)
		 {

            return false;

        }

    }


    // Check if there is a queen in the upper right diagonal

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
	 {

        if (board[i][j] == 1)
		 {

            return false;

        }

    }


    return true;

}


bool solveNQueen(int board[][10], int row, int n)
 {

    if (row == n)
	 {

        // Print the board configuration

        for (int i = 0; i < n; i++)
		 {

            for (int j = 0; j < n; j++)
			 {
			 	if(board[i][j])
			 	{
//                cout << board[i][j] << " ";
                  cout<<"Q"<<" ";
                }
                else
                {
                	cout<<"*"<<" ";
				}

            }

            cout << endl;

        }

        cout << endl;

        return true;

    }


    bool res = false;

    for (int col = 0; col < n; col++)
	 {

        if (isSafe(board, row, col, n))
		 {

            board[row][col] = 1;

            res = solveNQueen(board, row + 1, n) || res;

            board[row][col] = 0;

        }

    }

    return res;

}


int main() {

    int n;

    cout << "Enter the number of queens: ";

    cin >> n;

    int board[10][10] = {0};

    bool solutionExists = solveNQueen(board, 0, n);


    if (!solutionExists) {

        cout << "No solution exists for the given number of queens." << endl;

    }


    return 0;

}


