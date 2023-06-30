#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct SCORE {
	int mid;
	int final;
	int total;
};

struct STUDENT {
	char idnum[15];
	char name[15];
	struct SCORE sungjuk;
	struct STUDENT* next;
};

typedef struct STUDENT STUDENT; // struct STUDENT를 STUDENT 로 사용할 수 있게 형변환

// 함수 프로토타입
void Make_Linked_List(STUDENT* head); // 링크트 리스트 만드는 함수
void Print_List(STUDENT* head);       // 링크드 리스트 내용 출력 함수

void Check_Student(STUDENT* head);     // 링크드 리스트에 있는 학생수 체크하는 함수
void Check_Maxscore(STUDENT* head);	  // 링크드 리스트에 있는 가장 큰 최종 점수를 찾는 함수
