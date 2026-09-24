#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//扫雷
	FIND(mine, show, ROW, COL);

}
void meun()
{
	printf("**************扫雷************\n");
	printf("**********1.play  0.exit******\n");
	printf("******************************\n");
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;

	do
	{
		meun();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			// play game
			game();
			break;
		case 0:
			// exit
			break;
		default:
			printf("无效选择，请重新输入！\n");
		}
	}
	while (input);
}
int main()
{
	test();
	return 0;
}