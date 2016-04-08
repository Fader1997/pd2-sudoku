#include "Sudoku.h"

using namespace std;

void Sudoku::giveQuestion(){
	int problem[9][9] = {{0, 0, 0, 3, 0, 0, 0, 0, 2},
			             {0, 0, 4, 0, 0, 0, 0, 0, 9},
						 {0, 0, 0, 0, 5, 1, 0, 4, 0},
						 {0, 4, 0, 3, 2, 0, 0, 9, 0},
						 {0, 0, 2, 1, 0, 8, 3, 0, 0},	
		   				 {0, 5, 0, 0, 4, 6, 0, 1, 0},
	                     {0, 3, 0, 5, 6, 0, 0, 0, 0},
						 {5, 0, 0, 0, 0, 0, 4, 0, 0},
		                 {2, 0, 0, 0, 9, 0, 0, 0, 0}};
	
	print(problem);
}

void Sudoku::readIn(){
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> input[i][j];
		}
	}

}


bool Sudoku::SolveSudoku(int input[9][9]){
	
	int row, col;

	if (!FindUnassignedLocation(input, row, col))
		return true;

	for (int Num = 1; Num <= 9; Num++)
	{
		if (isSafe(input, row, col, Num))
		{
			input[row][col] = Num;
						    
			if (SolveSudoku(input))
				return true;

			input[row][col] = UNASSIGNED;
		}
	}
	return false;
}

bool Sudoku::SolveSudoku_fromback(int check_input[9][9])
{
		int row,col;
		
		if(!FindUnassignedLocation(check_input,row,col))
			return true;
							
		for(int Num = 9; Num >= 1; Num--)
		{								
			if(isSafe(check_input, row, col, Num))
			{													
				check_input[row][col] = Num;
																						
				if(SolveSudoku_fromback(check_input))
					return true;
																																		
				check_input[row][col] = UNASSIGNED;
				
			}
		}
		return false;
}

bool Sudoku::FindUnassignedLocation(int input[9][9], int &row, int &col){
	  for (row = 0; row < 9; row++)
		  for (col = 0; col < 9; col++)
		    	if (input[row][col] == UNASSIGNED)
			       return true;
	  return false;
}

bool Sudoku::UsedInRow(int input[9][9], int row, int Num){
	for (int col = 0; col < 9; col++)
		if (input[row][col] == Num)
			return true;

	return false;

}
bool Sudoku::UsedInCol(int input[9][9], int col, int Num){
	for (int row = 0; row < 9; row++)
		if (input[row][col] == Num)
			return true;
	return false;

}
bool Sudoku::UsedInBox(int input[9][9], int boxStartRow, int boxStartCol, int Num){
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (input[row+boxStartRow][col+boxStartCol] == Num)
				return true;
	return false;
}

bool Sudoku::isSafe(int input[9][9], int row, int col, int Num){
	 return !UsedInRow(input, row, Num) &&
		  	!UsedInCol(input, col, Num) &&
		   	!UsedInBox(input, row - row % 3 , col - col % 3, Num);
}



bool Sudoku::Check_Row(int input[9][9]){
		
		int markRow[9] = {0,0,0,0,0,0,0,0,0};
		for(int i = 0;i < 9;i++)
		{	
			for(int Num = 1; Num <= 9; Num++)
			{
				if(input[0][i] == Num)
					markRow[Num-1]++;
				if(input[1][i] == Num)
					markRow[Num-1]++;
				if(input[2][i] == Num)
					markRow[Num-1]++;
				if(input[3][i] == Num)
					markRow[Num-1]++;	
				if(input[4][i] == Num)
					markRow[Num-1]++;
				if(input[5][i] == Num)
					markRow[Num-1]++;
				if(input[6][i] == Num)
					markRow[Num-1]++;
				if(input[7][i] == Num)
					markRow[Num-1]++;
				if(input[8][i] == Num)
					markRow[Num-1]++;
			}
			for(int i = 0; i < 9; i++)
			{
				if(markRow[i] > 1)
					return true;
				else
					markRow[i] = 0;
			}

		}
		return false;
}

bool Sudoku::Check_Col(int input[9][9]){
	
	int markCol[9] = {0,0,0,0,0,0,0,0,0};
	for(int i = 0; i < 9; i++)
	{	
		for(int Num = 1; Num <= 9; Num++)
		{
			if(input[i][0] == Num)
				markCol[Num-1]++;
			if(input[i][1] == Num)
				markCol[Num-1]++;
			if(input[i][2] == Num)
				markCol[Num-1]++;
			if(input[i][3] == Num)
				markCol[Num-1]++;	
			if(input[i][4] == Num)
				markCol[Num-1]++;
			if(input[i][5] == Num)
				markCol[Num-1]++;
			if(input[i][6] == Num)
				markCol[Num-1]++;
			if(input[i][7] == Num)
				markCol[Num-1]++;
			if(input[i][8] == Num)
				markCol[Num-1]++;
		}
		for(int i = 0; i < 9; i++)
		{
			if(markCol[i] > 1)
				return true;
			else
				markCol[i] = 0;
		}
	}
	return false;
}

bool Sudoku::CanOrNot(int input[9][9]){
	if(Check_Row(input))
		return false;
	if(Check_Col(input))
		return false;
	return true;
}

void Sudoku::solve(){

	if(!CanOrNot(input))
	{
		cout << "0" << endl;
		exit(1);
	}
	for(int i = 0;i < 9; i++)
		for(int j = 0; j < 9; j++)
			check_input[i][j] = input[i][j];


	if(SolveSudoku(input) && SolveSudoku_fromback(check_input))
	{
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				if(input[i][j] == check_input[i][j])
					mark[i][j] = 1;
				else
					mark[i][j] = 0;
			}
		}
	}
	else
	{
		cout << "0" << endl;
		exit(1);
	}

					
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(mark[i][j] == 0)
			{
				cout << "2" << endl;
				exit(1);
			}
		}
	}
						
	cout << "1" << endl;
	print(input);

}

void Sudoku::changeNum(int a, int b){
	
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			temp[i][j] = input[i][j];
			if (temp[i][j] == a)
				input[i][j] = b;
			if (temp[i][j] == b)
				input[i][j] = a;
		}
	}

}

void Sudoku::changeRow(int a, int b){
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			temp[i][j] = input[i][j];
		}
	}

	if ((a == 2 && b == 1) || (a == 1 && b == 2))	
	{	
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				input[i+3][j] = temp[i+6][j];
				input[i+6][j] = temp[i+3][j];
			}
		}
	}

	if ((a == 0 && b == 1) || (a == 1 && b == 0))
	{
		for (int i = 0; i < 3; i++)
		{	
			for (int j = 0; j < 9; j++)
			{
				input[i][j] = temp[i+3][j];
				input[i+3][j] = temp[i][j];
			}
		}
	}
				
	if ((a == 0 && b == 2) || (a == 2 && b == 0))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				input[i][j] = temp[i+6][j];
				input[i+6][j] = temp[i][j];
			}
		}        
	}

	/*cout << endl;
	
	for (int i = 0; i < 9; i++,cout << endl)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << input[i][j] << " ";
		}
	}*/
}

void Sudoku::changeCol(int a, int b){
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			temp[i][j] = input[i][j];
		}
	}

	if ((a == 2 && b == 1) || (a == 1 && b == 2))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				input[j][i+3] = temp[j][i+6];
				input[j][i+6] = temp[j][i+3];
			}
		}
	}
	 
	if ((a == 0 && b == 1) || (a == 1 && b == 0))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				input[j][i] = temp[j][i+3];
				input[j][i+3] = temp[j][i];
			}
		}
	}
	 
	if ((a == 0 && b == 2) || (a == 2 && b == 0))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				input[j][i] = temp[j][i+6];
				input[j][i+6] = temp[j][i];
			}
		}
	}

	/*cout << endl;
	
	for (int i = 0; i < 9; i++,cout << endl)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << input[i][j] << " ";
		}
	}*/
}

void Sudoku::rotate(int n){
	
	for (int time = 1; time <= n; time++)	
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				temp[i][j] = input[i][j];
			}
		}
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				input[j][8-i] = temp[i][j];
			}
		}
	}

	/*cout << endl;

	for (int i = 0; i < 9; i++,cout << endl)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << input[i][j] << " ";
		}
	}*/

}

void Sudoku::flip(int n){
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			temp[i][j] = input[i][j];
		}
	}

	if (n == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				input[i][j] = temp[8 - i][j];
			}
		}

		for (int i = 8; i > 4; i--)
		{
			for (int j = 0; j < 9; j++)
			{
				input[i][j] = temp[8 - i][j];
			}
		}
	}

	else if(n != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				input[j][i] = temp[j][8 - i];
			}
		}
		
		for (int i = 8; i > 4; i--)
		{
			for (int j = 0; j < 9; j++)
			{
				input[j][i] = temp[j][8 - i];
			}
		}
	}

	/*cout << endl;
	
	for (int i = 0; i < 9; i++,cout << endl)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << input[i][j] << " ";
		}
	}*/

}

void Sudoku::transform(){
	
	srand(time(NULL));
	changeNum(rand() % 9, rand() % 9);
	changeRow(rand() % 3, rand() % 3);
	changeCol(rand() % 3, rand() % 3);
	rotate(rand() % 101);
	flip(rand() % 2);

	print(input);
	/*for (int i = 0; i < 9; i++) 
	{
		cout << endl;
		for (int j = 0; j < 9; j++)
		{
			cout << input[i][j] << " ";
		}
	}	
	cout << endl;*/
}

void Sudoku::print(int prtanyArr[9][9])
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0 ;j < 9 ;j++)
		{
			cout << prtanyArr[i][j] << " ";
		}
		cout << endl;
	}
}

/*int main()
{

	Sudoku sudoku;
	sudoku.giveQuestion();
	sudoku.readIn();
	sudoku.changeNum(1, 2);
	sudoku.changeRow(1, 2);
	sudoku.changeCol(1, 2);
	sudoku.rotate(1);
	sudoku.flip(596);
	sudoku.transform();
	sudoku.solve();
	return 0;
}*/
