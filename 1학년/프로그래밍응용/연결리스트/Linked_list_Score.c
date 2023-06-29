#define _CRT_SECURE_NO_WARNINGS
#include "Linked_list_Score.h"

void main() {
	// 링크드 리스트의 첫 노드의 주소를 갖고 있을 head 선언
	STUDENT* list_head = (STUDENT*)malloc(sizeof(STUDENT));
	list_head->next = NULL; // head의 next를 NULL로 초기화


	//연결리스트 만들기
	Make_Linked_List(list_head);
	//연결리스트 출력
	Print_List(list_head);
	//학생수 계산 후 출력
	Check_Student(list_head);
	//최고점인 학생 출력
	Check_Maxscore(list_head);

	//실행결과를 콘솔창에 출력
	printf("\n\n실행결과 출력은 result.txt파일에 출력되었습니다.\n");

}
