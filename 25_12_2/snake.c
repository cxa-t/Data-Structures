#define _CRT_SECURE_NO_WARNINGS 1

#include"snake.h"

void SetPos(short x, short y)
{
	//拿到标准输出设备句柄
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//定义光标位置
	COORD pos = { x,y };
	//设置光标位置
	SetConsoleCursorPosition(houtput, pos);
}

void WelcomeToGame()
{
	SetPos(38, 14);//注意 第一个坐标是列，不是行
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(70, 26);//按任意键继续信息的位置
	system("pause");
	system("cls");//清理屏幕

	SetPos(43, 11);
	wprintf(L"按键指南\n");
	SetPos(40, 12);
	wprintf(L"↑ ：向上移动\n");
	SetPos(40, 13);
	wprintf(L"↓ ：向下移动\n");
	SetPos(40, 14);
	wprintf(L"← ：向左移动\n");
	SetPos(40, 15);
	wprintf(L"→ ：向右移动\n");
	SetPos(40, 16);
	wprintf(L"W  ：加速\n");
	SetPos(40, 17);
	wprintf(L"S  ：减速\n");
	SetPos(38, 18);
	wprintf(L"Tips：加速得分更高\n");

	SetPos(70, 26);//按任意键继续信息的位置
	system("pause");
	system("cls");//清理屏幕
}

void CreateMap()
{
	//上 58列 宽字符占2字节
	for (int i = 0; i < 29; i++)
		wprintf(L"%lc", WALL);
	
	//下 58列 宽字符占2字节
	SetPos(0, 29);
	for (int i = 0; i < 29; i++)
		wprintf(L"%lc", WALL);

	//左
	for (int i = 1; i < 29; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}

	//右
	for (int i = 1; i < 29; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}

void InitSnake(pSnake ps)
{
	pSnakeNode cur = NULL;

	for (int i = 0; i <= 3; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		//创建失败
		if (cur == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		//node串起来
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		
		//头插法
		if (ps->_pSnake == NULL)
		{
			ps->_pSnake = cur;
		}
		else
		{
			//始终往蛇头插入
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}

	//打印蛇
	cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	ps->_dir = RIGHT;//默认向右
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;//毫秒
	ps->_status = OK;

}

void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;
	//食物坐标
	//x 2的倍数 2-54
	//y 2的倍数 1-28
again:
	do
	{
		//食物坐标不能出内场范围
		x = rand() % 53 + 2;
		y = rand() % 28 + 1;
	} while (x%2!=0);
	//x和y不能和蛇身蛇头坐标一样
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}

	//创建食物节点
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;

	SetPos(pFood->x, pFood->y);
	wprintf(L"%lc", FOOD);

	ps->_pFood = pFood;

}

void GameStart(pSnake ps)
{
	//0.先设置窗口大小，后光标隐藏
	system("mode con cols=100 lines=33");
	system("title 贪吃蛇");
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info = { 0 };
	GetConsoleCursorInfo(houtput, &cursor_info);  //获取控制台光标信息
	cursor_info.bVisible = false;                 //隐藏控制台光标
	SetConsoleCursorInfo(houtput, &cursor_info);  //设置控制台光标状态
	//1.欢迎界面 功能介绍
	WelcomeToGame();
	//2.绘制地图
	CreateMap();
	//3.创建蛇
	InitSnake(ps);
	//4.创建食物
	CreateFood(ps);
}

void PrintHelpInfo()
{
	SetPos(70, 10);
	wprintf(L"  不能穿墙\n");
	SetPos(70, 11);
	wprintf(L"不能咬到自己\n");
	SetPos(70, 12);
	wprintf(L"按ESC退出游戏\n");
	SetPos(70, 13);
	wprintf(L"按空格暂停游戏\n");

	SetPos(73, 15);
	wprintf(L"按键指南\n");
	SetPos(70, 16);
	wprintf(L"↑ ：向上移动\n");
	SetPos(70, 17);
	wprintf(L"↓ ：向下移动\n");
	SetPos(70, 18);
	wprintf(L"← ：向左移动\n");
	SetPos(70, 19);
	wprintf(L"→ ：向右移动\n");
	SetPos(70, 20);
	wprintf(L"W  ：加速\n");
	SetPos(70, 21);
	wprintf(L"S  ：减速\n");
	SetPos(68, 22);
	wprintf(L"Tips：加速得分更高\n");

	//SetPos(70, 28);//按任意键继续信息的位置
	//getchar();
}

#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)

void Pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
			break;
	}
}

int NextIsFood(pSnakeNode pn, pSnake ps)
{
	return ((ps->_pFood->x == pn->x) && (ps->_pFood->y == pn->y));
}

void EatFood(pSnakeNode pn, pSnake ps)
{
	//头插法
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;

	//释放下一个位置的节点
	free(pn);
	pn = NULL;

	pSnakeNode cur = ps->_pSnake;
	//打印蛇
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;

	//重新创建食物
	CreateFood(ps);
}

void NoFood(pSnakeNode pn, pSnake ps)
{
	//头插法
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;

	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next != NULL)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	//把最后一个结点打印成空格
	SetPos(cur->next->x, cur->next->y);
	printf("  ");

	//释放最后一个结点
	free(cur->next);

	//把倒数第二个节点的地址置为NULL
	cur->next = NULL;
}

void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 || ps->_pSnake->y == 0 || ps->_pSnake->y == 28)
	{
		ps->_status = KILL_BY_WALL;
	}
}

void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
		{
			ps->_status = KILL_BY_SELF;
			break;
		}
		cur = cur->next;
	}
}

void SnakeMove(pSnake ps)
{
	//创建一个结点，表示蛇即将到的下一个节点
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}
	//这里需要修改 保持头结点不变 ，然后更新位置 接着打印
	switch (ps->_dir)
	{
	case UP:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}
	//下一位置是不是食物
	if (NextIsFood(pNextNode, ps))
	{
		//是食物
		EatFood(pNextNode, ps);
	}
	else
	{
		//不是食物
		NoFood(pNextNode, ps);
	}

	//检测蛇是否撞墙
	KillByWall(ps);
	//检测蛇是否撞到自己
	KillBySelf(ps);
}

void GameRun(pSnake ps)
{
	//打印帮助信息
	PrintHelpInfo();
	do
	{
		//打印总分数和食物分值
		SetPos(70, 7);
		printf("当前总分数：%2d\n",ps->_score);
		SetPos(70, 8);
		printf("当前食物分数：%2d\n", ps->_food_weight);

		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
		{
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//正常退出游戏
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			//暂停
			Pause();
		}
		else if (KEY_PRESS(0x57))
		{
			//加速
			if (ps->_sleep_time > 80)
			{
				ps->_food_weight += 2;
				ps->_sleep_time -= 30;
			}
		}
		else if (KEY_PRESS(0x53))
		{
			//减速
			if (ps->_food_weight > 2)
			{
				ps->_food_weight -= 2;
				ps->_sleep_time += 30;
			}
		}
		//蛇走一步
		SnakeMove(ps);
		Sleep(ps->_sleep_time);

	} while (ps->_status==OK);
}

void GameEnd(pSnake ps)
{
	SetPos(30, 14);
	switch (ps->_status)
	{
	case END_NORMAL:
		wprintf(L"主动结束游戏\n");
		break;
	case KILL_BY_WALL:
		wprintf(L"撞到墙上，游戏结束\n");
		break;
	case KILL_BY_SELF:
		wprintf(L"撞到了自己，游戏结束\n");
		break;
	}
	
	//释放蛇身的链表
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}
