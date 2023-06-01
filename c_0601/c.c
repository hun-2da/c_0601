#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}
// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}
ListNode* first_delete(ListNode* head) {
	ListNode* remove;
	remove = head->link;
	head->link = remove->link;

	free(remove);
	return head;
}
ListNode* last_delete(ListNode* head) {
	ListNode* remove = head->link;
	ListNode* p=NULL;

	while (1) {
		if (remove == head) break;
		else p = remove;
		remove = remove->link;
	}if (p == NULL) head= NULL;
	else {
		p->link = head->link;
		head = p;
	}
	free(remove);
	return head;
}

int main(void)
{
	ListNode* head = NULL;
	int number;

	while (1) {
		printf("메뉴\n 1)처음 삽입\n 2)끝 삽입\n 3)처음 삭제\n 4)끝 삭제\n 5)종료\n :");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			printf("처음 삽입될 숫자를 입력해 주십시오 :");
			scanf_s("%d", &number);
			head = insert_first(head, number);
			print_list(head);
			break;
		case 2:
			printf("마지막에 삽입될 숫자를 입력해 주십시오 :");
			scanf_s("%d", &number);
			head = insert_last(head, number);
			print_list(head);
			break;
		case 3:
			printf("처음 노드를 삭제합니다.");
			head = first_delete(head);
			print_list(head);
			break;
		case 4:
			printf("마지막 노드를 삭제합니다.");
			head = last_delete(head);
			print_list(head);
			break;
		
		case 5: printf("종료됩니다. "); return;
		}
	}
	print_list(head);
	return 0;
}
