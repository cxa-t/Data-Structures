#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

void test01()
{
	int ch = 0;
	do
	{
		system("cls");
		//创建贪吃蛇
		Snake snake = { 0 };
		//初始化游戏
		//1. 打印环境界面
		//2. 功能介绍
		//3. 绘制地图
		//4. 创建蛇
		//5. 创建食物
		//6. 设置游戏的相关信息
		GameStart(&snake);

		//运行游戏
		GameRun(&snake);
		//结束游戏 - 善后工作
		GameEnd(&snake);
		SetPos(20, 15);
		printf("再来一局吗?(Y/N):");
		ch = getchar();
		getchar();

	} while (ch == 'Y' || ch == 'y');
	SetPos(0, 29);
}

int main()
{
	//设置本地环境，也就是引入宽字符。
	setlocale(LC_ALL, "");
	//食物坐标随机
	srand((unsigned int)time(NULL));
	//测试游戏
	test01();

	return 0;
}