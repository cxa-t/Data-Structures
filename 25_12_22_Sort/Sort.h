#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

void Swap(int* pa, int* pb);
void AdjustDown(int* a, int n, int parent);
int getMidi(int* a, int left, int right);
int PartSort2(int* a, int left, int right);
int PartSort3(int* a, int left, int right);
int singleTripSort(int* a, int left, int right);

void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n); 
void QuickSort(int* a, int left, int right); 
void BubbleSort(int* a, int n);
void HeapSort(int* a, int n);
void QuickSortNonR(int* a, int left, int right);

void MergeSort(int* a, int n);


void CountSort(int* a, int n);