#define _CRT_SECURE_NO_WARNINGS
#include "matrix_operation.h"

//행렬의 곱셈 계산 함수
void matrix_multiplication(int* A, int* B, int* AB, int row, int index, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int temp = 0; //행렬A,B의 곱셈을 임시로 저장하는 변수
            for (int k = 0; k < index; k++) {
                temp += (*((A + k) + (i * index))) * (*((B + j) + (k * col))); //행렬A,B의 곱셈 계산 후 temp에 임시로 저장
            }
            *((AB + i * row) + j) = temp; //행렬의 곱셈 결과를 행렬 AB에 대입
        }
    }
}

// 전치행렬에서 행과 열을 바꾸기 위한 함수
void swap(int* pa, int* pb) {
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

//행렬의 전치행렬을 구하는 함수
void matrix_transpostion(int* AB, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++) {
            if (j > i) 
                swap(&(*((AB + i * row) + j)), &(*((AB + j * row) + i))); //2차원 배열의 표기법을 2차원 포인터로 변환하는 방법은 *(*(행렬이름+행의크기)+열의크기))
        }
}

//대각합을 구하기 위한 함수
int matrix_trace(int* AB, int row) {
    int i;
    int sum = 0; //대각합을 저장하기 위한 변수
    for (i = 0; i < row; i++) {
        sum += *((AB + (i * (row - 1))) + (i * (row - 1))); //(row-1)을 곱한 이유 : AB[i][i]로 출력해본 결과, AB[0][0], AB[0][2], AB[1][1]만 출력되어 (row-1)을 곱해줌
    }
    return sum;
}

//행렬을 print하기 위한 함수
void matrix_print(int* m, int row, int col, FILE* outf) {
    for (int i = 0; i < row; i++) {
        fprintf(outf, "\t\t[ ");
        for (int j = 0; j < col; j++)
            fprintf(outf, "%4d ", *((m + i * col) + j)); //2차원 배열의 표기법을 2차원 포인터로 변환하는 방법은 *(*(행렬이름+행의크기)+열의크기))
        fprintf(outf, " ]\n");
    }
}

