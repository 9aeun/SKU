#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
	struct ListNode* llink;
	char name[10];
	float grade;
	struct ListNode* rlink; 
}listNode;

typedef struct
{
	struct listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h() {
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

listNode* createNode(char* x, float s) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->name, x);
	newNode->grade = s;
	newNode->llink = NULL;
	newNode->rlink = NULL;
	return newNode;
}


listNode* searchNode(linkedList_h* DL, char* x)
{
	listNode* temp;
	temp = DL->head;
	while (temp != NULL)
	{
		if (strcmp(temp->name, x) == 0)
			return temp;
		else
			temp = temp->rlink; // else 없어도 ok, llink는 사용 안 함
	}
	return NULL;
}

void insertNode(linkedList_h* DL, char* x, float s) {
	listNode* newNode;
	listNode* p;

	newNode = createNode(x, s);

	if (DL->head == NULL)
	{
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}

	else
	{
		p = DL->head;
		while (p->rlink != NULL)
		{
			p = p->rlink;
		}
		newNode->rlink = NULL;
		p->rlink = newNode;
		newNode->llink = p;
	}
	
}

void printList(linkedList_h* DL) {
	listNode* p;
	printf("학생 = (");

	p = DL->head;
	while (p != NULL)
	{
		printf("이름: %s 성적: %2.1f", p->name, p->grade);
		p = p->rlink;
		if (p != NULL)
			printf(", ");
	}
	printf(") \n");
}

void deleteNode(linkedList_h* DL, listNode* old)
{
	if (DL->head == NULL) return;
	if (old == NULL) return;
	else
	{
		if (old->llink == NULL)
		{
			DL->head = old->rlink;
			free(old);
		}

		else if (old->rlink == NULL)
		{
			old->llink->rlink = old->rlink;
			free(old);
		}

		else
		{
			old->llink->rlink = old->rlink;
			old->rlink->llink = old->llink;
			free(old);
		}
	}
}

linkedList_h* modifyNode(linkedList_h* DL, listNode* p, float s) // 노드의 요일을 수정한다.(어느 요일의 노드를 어떤 요일로 바꿀건지)
{
	if (!p)
		printf("수정하려는 학생이 리스트에 없습니다.");
	else
	{
		p->grade=s;
	}
	return DL;
}

int menu()
{
	int input;
	printf("\n(1) ~ (6)번 사이의 메뉴를 고르세요 : ");
	scanf("%d", &input);
	return input;
}


main(void)
{

	printf("===================\n");
	printf("(1) 학생 이름, 성적 삽입\n");
	printf("(2) 학생 이름 검색\n");
	printf("(3) 학생 삭제 \n");
	printf("(4) 학생 성적 수정 \n");
	printf("(5) 전체 출력\n");
	printf("(6) 끝냄\n");
	printf("===================\n");

	linkedList_h* DL;
	DL = createLinkedList_h();
	listNode* p;

	while (1)
	{

		char x[5];
		float s;

		int choice = menu();
		printf("\n");
		

		switch (choice) {
		case 1: 
			printf("삽입하고자 하는 학생의 이름과 성적을 입력하세요: ");
			scanf("%s %f", &x, &s);
			insertNode(DL,x,s);
			break;
			

		case 2: 
			printf("화면에서 검색하고자 하는 학생의 이름을 입력하세요: ");
			scanf("%s", &x);
			p = searchNode(DL, x);
			if (searchNode(DL, x))
				printf("이름: %s, 성적: %2.1f\n", p->name, p->grade);
			else
				printf("못찾았음\n");
			getchar();
			break;

		case 3:
			printf("\n화면에서 삭제하고 싶은 학생의 이름을 입력하세요 : ");
			scanf("%s", &x);
			p = searchNode(DL, x);
			if (p == NULL)
				printf("찾고자 하는 학생이 없습니다.\n");
			else
				deleteNode(DL, p);
			break;

		case 4:
			printf("성적을 고치고 싶은 학생의 이름과 성적을 입력하세요. : ");
			scanf("%s %f", &x, &s);
			p = searchNode(DL, x);
			modifyNode(DL, p, s);
			getchar();
			break;

		case 5:
			printf("전체를 출력합니다.\n");
			printList(DL);
			getchar();
			break;

		case 6:
			printf("실행을 끝냅니다.\n");
			return NULL;

		default:
			printf("(1) ~ (6) 사이의 숫자를 다시 입력하세요. \n");
			break;
			
			
		}
	}
	getchar();
}
