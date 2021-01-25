#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("##############\n");
	printf("####1.start###\n");
	printf("####0.exit####\n");
	printf("##############\n");
}
void game()
{
	char show[ROWS][COLS] = { 0 };
	char real[ROWS][COLS] = { 0 };
	Initial(show, ROWS, COLS, '*');
	Initial(real, ROWS, COLS, '0');
	set_mine(real, ROW, COL);
	/*display(real, ROW, COL);*/
	display(show, ROW, COL);
	find_mine(real, show, ROW, COL);
}
int main()
{
	int n = 0;
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			printf("退出成功。\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误，请重试。\n");
			break;
		}
	}while (n);
	return 0;
}