#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void Initial(char arr[ROWS][COLS], int row, int col, char ch)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ch;
		}
	}
}
void display(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
void set_mine(char arr[ROW][COL], int row, int col)
{
	int count = easy_count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}
int get_mine(char mine[ROW][COL], int x, int y)
{
	return mine[x - 1][y - 1] - '0' +
		mine[x - 1][y] - '0' +
		mine[x - 1][y + 1] - '0' +
		mine[x][y + 1] - '0' +
		mine[x + 1][y + 1] - '0' +
		mine[x + 1][y] - '0' +
		mine[x + 1][y - 1] - '0' +
		mine[x][y - 1] - '0';
}
void open_mine(char real_arr[ROW][COL], char show_arr[ROW][COL], int x, int y,int row,int col)
{
	if (show_arr[x][y] == '*')
	{
		show_arr[x][y] = get_mine(real_arr, x, y) + '0';
	}
	if (show_arr[x - 1][y - 1] == '*' && real_arr[x - 1][y - 1] != '1' && x > 1 && y > 1)
	{
		open_mine(real_arr, show_arr, x - 1, y - 1, row, col);
	}
	if (show_arr[x - 1][y] == '*' && real_arr[x - 1][y] != '1' && x > 1)
	{
		open_mine(real_arr, show_arr, x - 1, y, row, col);
	}
	if (show_arr[x - 1][y + 1] == '*'  && real_arr[x - 1][y + 1] != '1' && x > 1 && y + 1 <col)
	{
		open_mine(real_arr, show_arr, x - 1, y + 1, row, col);
	}
	if (show_arr[x][y - 1] == '*'  && real_arr[x][y - 1] != '1' && y > 1)
	{
		open_mine(real_arr, show_arr, x, y - 1, row, col);
	}
	if (show_arr[x][y + 1] == '*'  && real_arr[x][y + 1] != '1' && y + 1<col)
	{
		open_mine(real_arr, show_arr, x - 1, y - 1, row, col);
	}
	if (show_arr[x + 1][y + 1] == '*' && real_arr[x + 1][y + 1] != '1' && x + 1<row && y + 1<col)
	{
		open_mine(real_arr, show_arr, x - 1, y - 1, row, col);
	}
	if (show_arr[x + 1][y] == '*'  && real_arr[x + 1][y] != '1' && x + 1<row)
	{
		open_mine(real_arr, show_arr, x - 1, y - 1, row, col);
	}
	if (show_arr[x + 1][y - 1] == '*' && real_arr[x + 1][y - 1] != '1' && x + 1<row && y - 1>0)
	{
		open_mine(real_arr, show_arr, x - 1, y - 1, row, col);
	}
}
void find_mine(char real_arr[ROW][COL],char arr[ROW][COL], int row, int col)
{
	int count = row*col - easy_count;
	int x, y;
	while (count)
	{
		printf("请输入坐标。\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (real_arr[x][y] == '1')
			{
				printf("你被炸死了。\n");
				break; 
			}
			else if (real_arr[x][y] == '0')
			{
				count--;
				arr[x][y] = get_mine(real_arr, x, y)+'0';
				open_mine(real_arr, arr, x, y, row, col);
				display(arr, ROW, COL);
			}
		}
		else
			printf("坐标错误，请重试。\n");
	}
	if (!count)
		printf("游戏成功！\n");
}