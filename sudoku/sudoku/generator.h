#pragma once
class generator
{
public:
	ofstream ioscout;
	generator();
	~generator();
	void Print();
	int n;
	void Init(int n);

private:
	int sudoku[10][10];
	bool Row[10][10];
	bool Col[10][10];
	bool Palace[10][10];
	int getPalace[10][10];
	int cnt = 0;
	bool CheckRowCol(int row, int col);
	void dfs(int row, int col);
};

