#define _CRT_SECURE_NO_WARNINGS
#include "matrix_operation.h"
  
int main(void)
{
	int A[L][M] = { 0 }, B[M][N] = { 0 }, AB[L][N] = { 0 }; //행렬 A, 행렬 B, 행렬A와 행렬B의 곱 행렬AB 선언
	int i = 0, j = 0; 

	FILE * inFa = NULL; //a.txt
	FILE * inFb = NULL; //b.xt
	FILE * outF = NULL; //result.txt

	inFa = fopen("a.txt", "r"); 
	inFb = fopen("b.txt", "r");

	//파일을 불러오지 못했을 때
	if(inFa == NULL) {
		printf("a.txt 파일을 불러오지 못했습니다.");
		exit(1);
	}
	if (inFb == NULL) {
		printf("b.txt 파일을 불러오지 못했습니다.");
		exit(1);
	}

	// 행렬 A 불러오기
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) 
			fscanf(inFa, "%d", &A[i][j]);
	}

	// 행렬 B 불러오기	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(inFb, "%d", &B[i][j]);
		}
	}

	//result.txt 생성
	outF = fopen("result.txt", "w");
	//result.txt가 생성되지 않을 때
	if (outF == NULL) {
		fprintf(stderr, "result.txt 파일을 열 수 없습니다.");
		exit(1);
	}

	//result.txt에 작성하기
	fprintf(outF, "프로그래밍응용 학기말 과제 : 기말고사 대체 (학번 : 2020301006, 이름 : 김가은)\n\n");

	//행렬 A 출력
	fprintf(outF, "행렬 A와 행렬 B는 다음과 같습니다.\n\n");
	fprintf(outF, "	행렬 A : \n");
	matrix_print(*A, L, M, outF);
	fprintf(outF, "\n\n");

	//행렬 B 출력
	fprintf(outF, "	행렬 B : \n");
	matrix_print(*B, M, N, outF);
	fprintf(outF, "\n\n");

	//행렬의 곱셈 출력
	matrix_multiplication(*A, *B, *AB, L, M, N);
	fprintf(outF, "\n");
	fprintf(outF, "(2) 행렬 A와 행렬 B의 곱 AB는 다음과 같습니다.\n\n");
	matrix_print(*AB, L, N, outF);
	fprintf(outF, "\n\n");

	//전치행렬 출력
	fprintf(outF, "(3) 행렬 AB의 전치행렬은 다음과 같습니다. \n\n");
	matrix_transpostion(*AB, L, N);
	matrix_print(*AB, L, N, outF);
	fprintf(outF, "\n\n");

	//대각합 출력
	fprintf(outF, "(4) 행렬 AB의 대각합은 tr(AB) = %d 입니다. \n\n", matrix_trace(*AB, L));

	//파일 닫고, 결과를 콘솔창에 출력
	fclose(inFa);
	fclose(inFb);
	fclose(outF);
	printf("실행결과 : 프로젝트 폴더의 result.txt 로 출력되었습니다.\n");
	return 0;
}
