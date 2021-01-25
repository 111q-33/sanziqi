#include<stdio.h>
#include<stdlib.h>
#define easy_count 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
void Initial(char arr[ROWS][COLS], int row, int col, char ch);
void set_mine(char arr[ROW][COL], int row, int col);
void find_mine(char real_arr[ROW][COL], char arr[ROW][COL], int row, int col);
void display(char arr[ROW][COL], int row, int col);