
/*****************************题目描述

黑白棋，又叫翻转棋（Reversi）、苹果棋或奥赛罗棋（Othello）。棋盘共有8行8列共64格。
开局时，棋盘正中央的4格先置放黑白相隔的4枚棋子。双方轮流落子，只要落子和棋盘上任一枚己方的棋子
在一条线上（横、直、斜线皆可）夹着对方棋子，就能将对方的这些棋子转变为我己方（翻面即可）。
如果在任一位置落子都不能夹住对手的任一颗棋子，就要让对手下子。当双方皆不能下子时，游戏就结束，子多的一方胜。
现在给你一个8x8的棋局，以及下一步玩家的落子位置。请输出翻转好的新棋局。

输入描述 :
输入有多组数据，每组数据有两部分。

第一部分有8行，为8x8的棋局，其中“*”为黑子、“ + ”为白子、“.”为空位置。

第二个部分有一行，包含要落子的行号r（1≤r≤8）、列号c（1≤c≤8）、棋子e（“*”或“ + ”）。


输出描述 :
对应每组输入，根据黑白棋的规则，请输出落子后翻转的结果。

每组数据之后输出一个空行作为间隔。

输入例子 :
........
........
........
... + *...
...*+...
........
........
........
4 3 *
........
........
........
..***...
...*+...
........
........
........
3 3 +

输出例子:
........
........
........
..***...
...*+...
........
........
........

........
........
.. + .....
..* + *...
...*+...
........
........
........
*************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };

void PrintTheBoard(vector<string> &board)
{
	for (int i = 0; i < 8; ++i)
		cout << board[i] << endl;
	cout << endl;
}

void BlackAndWhiteChess(vector<string> &board, int curr_x, int curr_y, char ch)
{
	for (int i = 0; i < 8; ++i)
	{
		int next_x = curr_x + dx[i], next_y = curr_y + dy[i];
		while (next_x >= 0 && next_x < 8 && next_y >= 0 && next_y < 8)
		{
			if (ch == board[next_x][next_y])
			{
				for (int p = next_x - dx[i], q = next_y - dy[i];; p -= dx[i], q -= dy[i])
				{
					if (p == curr_x && q == curr_y)
						break;
					board[p][q] = ch;
				}
				break;
			}
			else if ('.' == board[next_x][next_y])
				break;
			next_x += dx[i], next_y += dy[i];
		}
	}
}

int main()
{
	char ch;
	vector<string> board(8, string(9, ' '));
	int curr_x, curr_y;
	while (cin >> board[0])
	{
		for (int i = 1; i < 8; ++i)
			cin >> board[i];
		cin >> curr_x >> curr_y >> ch;
		board[curr_x - 1][curr_y - 1] = ch;

		BlackAndWhiteChess(board, curr_x - 1, curr_y - 1, ch);

		PrintTheBoard(board);
	}
	return 0;
}
