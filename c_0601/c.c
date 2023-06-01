#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
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
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
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
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}
// ����Ʈ�� �׸� ���
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
		printf("�޴�\n 1)ó�� ����\n 2)�� ����\n 3)ó�� ����\n 4)�� ����\n 5)����\n :");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			printf("ó�� ���Ե� ���ڸ� �Է��� �ֽʽÿ� :");
			scanf_s("%d", &number);
			head = insert_first(head, number);
			print_list(head);
			break;
		case 2:
			printf("�������� ���Ե� ���ڸ� �Է��� �ֽʽÿ� :");
			scanf_s("%d", &number);
			head = insert_last(head, number);
			print_list(head);
			break;
		case 3:
			printf("ó�� ��带 �����մϴ�.");
			head = first_delete(head);
			print_list(head);
			break;
		case 4:
			printf("������ ��带 �����մϴ�.");
			head = last_delete(head);
			print_list(head);
			break;
		
		case 0: printf("����˴ϴ�. "); return;
		}
	}
	print_list(head);
	return 0;
}