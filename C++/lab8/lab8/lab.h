#pragma once
#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int n);
void radixsort(int arr[], int n);
void countSort(int arr[], int n, int exp);
int getMax(int arr[], int n);

//int maxRazr(int number);
//void sortRazr(int** count, int* p, int razr, int size);
//int valueRazr(int number, int razr);

void sortArray(int* p, int* count, int size, int min);

void printSortArray(int* count, int max, int min);

void getData();