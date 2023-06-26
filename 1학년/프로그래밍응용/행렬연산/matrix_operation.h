#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define L 3 
#define M 5
#define N 3

//함수 원형//
void matrix_multiplication(int* A, int* B, int* AB, int row, int index, int col); //행렬의 곱 함수 원형
void matrix_transpostion(int* AB, int row, int col); // 전치행렬 함수 원형
void swap(int* pa, int* pb); //전치행렬 구할 때 쓰는 swap함수 원형
int matrix_trace(int* AB, int row); // 대각합 함수 원형
void matrix_print(int* m, int row, int col, FILE* outf); // 행렬 print 함수 원형

