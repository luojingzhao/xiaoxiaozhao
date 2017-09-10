// SudokuTest1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "generator.h"



int main(int argc, char* argv[]) {
	if (strcmp(argv[1], "-c") != 0) {
		printf("error data");
	}
	else {
		generator *temp = new generator();
		char* str = argv[2];
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if (str[i] < '0' || str[i] > '9') {
				printf("the n is wrong");
				return 0;
			}
		}
		int res = 0, tmp = 1;
		for (int i = len - 1; i >= 0; i--) {
			res += (str[i] - '0')*tmp;
			tmp *= 10;
		}
		int n = res;
		temp->ioscout.open("sudoku.txt");
		temp->Init(n);
		temp->ioscout.close();
	}
	return 0;
}

