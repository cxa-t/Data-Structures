#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HDataType;

typedef struct Heap
{
	HDataType* a;
	int size;
	int capacity;
}HP;

void HPInit(HP* php);
void HPDestroy(HP* php);

void HPPush(HP* php,HDataType x);
void HPPop(HP* php);

HDataType HPTop(HP* php);
bool HPEmpty(HP* php);


