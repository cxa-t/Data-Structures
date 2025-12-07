#pragma once

#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<time.h>

//类型的声明
#define POS_X 16
#define POS_Y 5

#define WALL L'□'
#define BODY L'●'
#define HEAD L'¤'
#define FOOD L'★'

//蛇行进的方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//蛇的状态
//正常、撞墙、撞自己、esc退出
enum GAME_STATUS
{
	OK,             //正常
	KILL_BY_WALL,   //撞墙
	KILL_BY_SELF,   //撞到自己
	END_NORMAL      //正常退出
};

//蛇身节点类型
typedef struct SnakeNode
{
	//坐标
	int x;
	int y;
	//下一个节点指针
	struct SnakeNode* next;
}SnakeNode,* pSnakeNode;//声明蛇头指针

//贪吃蛇
typedef struct Snake
{
	pSnakeNode _pSnake;            //指向蛇头的指针
	pSnakeNode _pFood;             //指食物节点的指针
	enum DIRECTION _dir;           //蛇的方向
	enum GAME_STATUS _status;      //游戏状态
	int _food_weight;              //一个食物的分数
	int _score;                    //游戏总分数
	int _sleep_time;               //休息时间，时间越短速度越快，时间越长速度越快
}Snake,* pSnake;

//函数的声明
//游戏初始化
void GameStart(pSnake ps);
//欢迎界面的打印
void WelcomeToGame();
//创建地图
void CreateMap();
//初始化蛇身
void InitSnake(pSnake ps);
//创建食物
void CreateFood(pSnake ps);

//游戏开始
void GameRun(pSnake ps);

//蛇移动逻辑
void SnakeMove(pSnake ps);

//下个坐标是否是食物
int NextIsFood(pSnakeNode pn, pSnake ps);

//是食物就吃掉食物
void EatFood(pSnakeNode pn, pSnake ps);

//不是食物
void NoFood(pSnakeNode pn, pSnake ps);

//检测蛇是否撞墙
void KillByWall(pSnake ps);

//检测蛇是否撞到自己
void KillBySelf(pSnake ps);

//游戏善后的工作
void GameEnd(pSnake ps);