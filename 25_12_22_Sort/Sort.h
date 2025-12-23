#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

void Swap(int* pa, int* pb);

void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n); 
void QuickSort(int* a, int left, int right);