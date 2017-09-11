#include "stdafx.h"
#include "generator.h"
#include<stdlib.h>
#define ms(a,b) memset(a,b,sizeof(b))


generator::generator()
{
}


generator::~generator()
{
}

void generator::Init(int n) {
	this->n = n;
	ms(Row, false);
	ms(Col, false);
	ms(Palace, false);
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if ((i - 1) / 3 == 0 && (j - 1) / 3 == 0) {
				getPalace[i][j] = 1;
			}
			else if ((i - 1) / 3 == 0 && (j - 1) / 3 == 1) {
				getPalace[i][j] = 2;
			}
			else if ((i - 1) / 3 == 0 && (j - 1) / 3 == 2) {
				getPalace[i][j] = 3;
			}
			else if ((i - 1) / 3 == 1 && (j - 1) / 3 == 0) {
				getPalace[i][j] = 4;
			}
			else if ((i - 1) / 3 == 1 && (j - 1) / 3 == 1) {
				getPalace[i][j] = 5;
			}
			else if ((i - 1) / 3 == 1 && (j - 1) / 3 == 2) {
				getPalace[i][j] = 6;
			}
			else if ((i - 1) / 3 == 2 && (j - 1) / 3 == 0) {
				getPalace[i][j] = 7;
			}
			else if ((i - 1) / 3 == 2 && (j - 1) / 3 == 1) {
				getPalace[i][j] = 8;
			}
			else if ((i - 1) / 3 == 2 && (j - 1) / 3 == 2) {
				getPalace[i][j] = 9;
			}
		}
	}
	dfs(1, 1);
}

void generator::Print() {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			ioscout << sudoku[i][j] << " ";
		}
		ioscout << endl;
	}
	ioscout << endl;
}

bool generator::CheckRowCol(int row, int col) {
	//  行比较 
	if (Row[row][sudoku[row][col]] == true) return false;

	//  列比较 
	if (Col[col][sudoku[row][col]] == true) return false;

	//  宫比较 
	if (Palace[getPalace[row][col]][sudoku[row][col]] == true) return false;

	return true;
}


void generator::dfs(int row, int col) {
	if (row == 9 && col == 9) {
		++cnt;
		//ioscout << "No." << cnt << " output :" << endl;
		Print();
		if (cnt == n) {
			exit(0);
		}
		return;
	}

	if (row == 1 && col == 1) {
		sudoku[1][1] = (2 + 8) % 9 + 1;
		Row[1][sudoku[1][1]] = true;
		Col[1][sudoku[1][1]] = true;
		Palace[1][sudoku[1][1]] = true;
	}
	++col;
	if (col > 9) {
		++row;
		col = 1;
	}
	for (int i = 1; i<10; i++) {
		sudoku[row][col] = i;
		if (!CheckRowCol(row, col)) continue;
		Row[row][sudoku[row][col]] = true;
		Col[col][sudoku[row][col]] = true;
		Palace[getPalace[row][col]][sudoku[row][col]] = true;
		dfs(row, col);
		Row[row][sudoku[row][col]] = false;
		Col[col][sudoku[row][col]] = false;
		Palace[getPalace[row][col]][sudoku[row][col]] = false;
	}
	sudoku[row][col] = 0;

	return;
}
