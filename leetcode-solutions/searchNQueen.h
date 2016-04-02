#pragma once

#include "common.h"

//   The n - queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
//   
//   
//   
//   Given an integer n, return all distinct solutions to the n - queens puzzle.
//   
//   Each solution contains a distinct board configuration of the n - queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//   
//   For example,
//   There exist two distinct solutions to the 4 - queens puzzle :
//   
//   [
//   	[".Q..",  // Solution 1
//   	"...Q",
//   	"Q...",
//   	"..Q."],
//   
//   	["..Q.",  // Solution 2
//   	"Q...",
//   	"...Q",
//   	".Q.."]
//   ]

struct line
{
	int numLine;
	int pos;
};

vector<vector<string> > solveNQueens(int n)
{
	std::vector<std::vector<std::string>> result;
	std::stack<line> lineStack;
	std::vector<line> board(n);
	std::vector<int> possible(n);

	for (int i = 0; i < n; ++i)
	{
		lineStack.push(line{ 0, i });
	}

	while (!lineStack.empty())
	{
		line current = lineStack.top();
		lineStack.pop();

		board[current.numLine] = current;

		if (current.numLine == n - 1)
		{
			std::vector<string> solution(n);
			for (int i = 0; i < n; ++i)
			{
				line l = board[i];
				solution[i] = string(l.pos, '.') + 'Q' + string(n - l.pos - 1, '.');
			}
			result.push_back(solution);
		}
		else
		{
			std::vector<int> possible(n, 1);

			for (int i = 0; i < current.numLine + 1; ++i)
			{
				line l = board[i];
				possible[l.pos] = 0;
				int left = l.pos - (current.numLine + 1 - i);
				int right = l.pos + (current.numLine + 1 - i);
				if (left >= 0)
					possible[l.pos - (current.numLine + 1 - i)] = 0;
				if (right < n)
					possible[l.pos + (current.numLine + 1 - i)] = 0;
			}

			for (int i = 0; i < n; ++i)
			{
				if (possible[i] == 1)
				{
					lineStack.push(line{ current.numLine + 1,i });
				}
			}
		}
	}
	return result;
}