#define _CRT_SECURE_NO_WARNINGS
#include "Linked_list_Score.h"

void Make_Linked_List(STUDENT* head) {
	// data.txt 파일 오픈
	FILE* inf = fopen("data.txt", "r");
	if (inf == NULL) {
		printf("data.txt 파일을 불러오지 못했습니다.");
		exit(1);
	}

	// 링크드 리스트를 옮겨다닐 포인터 선언
	STUDENT* cursor = head;

	while (1) {
		// 링크드 리스트의 끝에 연결된 노드가 없을 때까지 이동
		while (cursor->next != NULL) {
			cursor = cursor->next;
		}

		// 새로운 노드 만들기
		STUDENT* new_node = (STUDENT*)malloc(sizeof(STUDENT));

		// 만약 data.txt파일에서 가져올 데이터가 있으면 노드를 채움
		if (fscanf(inf, "%s %s %d %d", new_node->idnum, new_node->name, &(new_node->sungjuk.mid), &(new_node->sungjuk.final)) != EOF)
			new_node->sungjuk.total = new_node->sungjuk.mid + new_node->sungjuk.final;
		// 만약 data.txt파일에 데이터가 없다면 while문 탈출
		else
			break;

		// 만들어진 노드의 주소를 이동 포인터의 next값에 저장
		cursor->next = new_node;
		new_node->next = NULL; // 새로 만든 노드의 next를 NULL로 초기화
	}

	if (inf != NULL)
		fclose(inf);
}

//연결리스트를 출력하는 모듈
void Print_List(STUDENT* head) {
	FILE* outf = fopen("result.txt", "w");
	if (outf == NULL) {
		printf("result.txt 파일을 불러오지 못했습니다.\n");
		exit(1);
	}
	STUDENT* ptr = head;

	fprintf(outf, "(1) 학생들의 성적 리스트 입니다.\n");
	fprintf(outf, "    ***************************************************\n");
	fprintf(outf, "            학번	이름     중간 기말  총점\n");
	fprintf(outf, "    ***************************************************\n");
	while (ptr->next != NULL) {
		ptr = ptr->next;
		fprintf(outf, "      %-13s %-10s %-5d %-5d %-5d\n", ptr->idnum, ptr->name, ptr->sungjuk.mid, ptr->sungjuk.final, ptr->sungjuk.total);
	}
	fprintf(outf, "    ***************************************************\n\n");

	if (outf != NULL)
		fclose(outf);
}

//학생 수를 계산하는 모듈
void Check_Student(STUDENT* head) {
	int cnt = 0;
	STUDENT* cursor = head;

	while (cursor->next != NULL) {
		cnt++;
		cursor = cursor->next;
	}


	FILE* outf = fopen("result.txt", "a");
	if (outf == NULL) {
		printf("result.txt 파일을 열지 못했습니다.");
		exit(1);
	}
	else
		fprintf(outf, "(2) 학생 수: 총 %d명 입니다.\n\n", cnt);

	if (outf != NULL)
		fclose(outf);
}

//최고점인 학생을 확인하고, 출력하는 모듈
void Check_Maxscore(STUDENT* head) {
	int max = 0;
	STUDENT* cursor = head;

	while (cursor->next != NULL) {
		if (cursor->sungjuk.total > max)
			max = cursor->sungjuk.total;
		cursor = cursor->next;
	}

	FILE* outf = fopen("result.txt", "a");
	if (outf == NULL) {
		printf("result.txt 파일을 열지 못했습니다.\n");
		exit(1);
	}
	else {
		cursor = head;

		while (cursor->next != NULL) {
			if (cursor->sungjuk.total == max) {
				fprintf(outf, "(3) 1등은 총점 %d점을 획득한 %s입니다.\n", max, cursor->name);
				break;
			}
			cursor = cursor->next;
		}
	}
	//파일 닫기
	if (outf != NULL)
		fclose(outf);
}
