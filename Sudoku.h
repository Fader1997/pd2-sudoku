#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define UNASSIGNED 0

using namespace std;

class Sudoku {
	public:
		void print(int prtanyArr[9][9]);
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		bool FindUnassignedLocation(int input[9][9], int &row, int &col);
		bool isSafe(int input[9][9], int row, int col, int Num);
		bool SolveSudoku(int input[9][9]);
		bool SolveSudoku_fromback(int input[9][9]);
		bool UsedInRow(int input[9][9], int row, int Num);
		bool UsedInCol(int input[9][9], int col, int Num);
		bool UsedInBox(int input[9][9], int boxStartRow, int boxStartCol, int Num);
		bool Check_Row(int input[9][9]);
		bool Check_Col(int input[9][9]);
		bool CanOrNot(int input[9][9]);
		
	
		int input[9][9], temp[9][9], check_input[9][9];
		int mark[9][9], markRow[9], markCol[9];
};
