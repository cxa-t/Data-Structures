#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<windows.h>
#include <stdbool.h>
//int main()
//{
//	//设置控制台窗口大小
//	system("mode con cols=100 lines=30");
//	//设置控制台名称
//	system("title 贪吃蛇");
//
//
//	//设置控制台暂停 获取一个字符后继续
//	system("pause");
//	return 0;
//}

//int main()
//{
//	COORD pos = { 0,0 };
//	COORD pos = { 10,10 };
//
//	return 0;
//}

void set_pos(short x, short y)
{
	//拿到标准输出设备句柄
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//定义光标位置
	COORD pos = { x,y };
	//设置光标位置
	SetConsoleCursorPosition(houtput, pos);
}

//int main()
//{
//	//获取标准输出设备
//	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE); 
//	CONSOLE_CURSOR_INFO cursor_info = { 0 };
//
//	////光标信息
//	//GetConsoleCursorInfo(houtput, &cursor_info);
//	////printf("%d\n",cursor_info.dwSize);
//	////cursor_info.dwSize = 50;
//	//cursor_info.bVisible = false; //隐藏控制台光标
//	//SetConsoleCursorInfo(houtput, &cursor_info);//设置控制台光标状态
//
//	COORD pos = { 5,5 };
//	SetConsoleCursorPosition(houtput, pos);
//
//
//	getchar();
//	
//	////会打印一个任意按键继续，所以先注释掉，为了看光标位置
//	//system("pause");
//
//
//	return 0;
//}

//int main()
//{
//	////查看上键有没有被按过
//	//short ret = GetAsyncKeyState(0x36);
//	//if (ret & 0x1)
//	//{
//	//	printf("yes\n");
//	//}
//	//else
//	//{
//	//	printf("no\n");
//	//}
//
//	return 0;
//}

#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)

int main()
{
	while (1)
	{
		if (KEY_PRESS(0x30))
			printf("0\n");
		else if(KEY_PRESS(0x31))
			printf("1\n");
		else if (KEY_PRESS(0x32))
			printf("2\n");
		else if (KEY_PRESS(0x33))
			printf("3\n");
		else if (KEY_PRESS(0x34))
			printf("4\n");
		else if (KEY_PRESS(0x35))
			printf("5\n");
		else if (KEY_PRESS(0x36))
			printf("6\n");
		else if (KEY_PRESS(0x37))
			printf("7\n");
		else if (KEY_PRESS(0x38))
			printf("8\n");
		else if (KEY_PRESS(0x39))
			printf("9\n");
		else if (KEY_PRESS(0x26))
			printf("上\n");
		else if (KEY_PRESS(0x25))
			printf("左\n");
		else if (KEY_PRESS(0x27))
			printf("右\n");
		else if (KEY_PRESS(0x28))
			printf("下\n");
	}
	return 0;
}
