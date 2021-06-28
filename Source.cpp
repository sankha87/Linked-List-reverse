#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include "Source.h"
struct node
{
	int data;
	struct node *next;
};
void printList(struct node *head_ref)
{
	while (head_ref->next)
	{
		printf(" %d ", head_ref->data);
		head_ref = head_ref->next;
	}
}
void reverse(struct node *head_ref)
{
	struct node *prev, *curr, *next1, *ptr;
	
	prev = head_ref;
	curr = prev->next;
	next1 = curr->next;
	while (next1->next != NULL)
		next1 = next1->next;
	while (next1->next != curr)
	{
		ptr = head_ref;
		while (ptr->next != next1)
			ptr = ptr->next;
		printf(" %d ", ptr->data);
		next1 = ptr;
	}

}
node* reverseLink(struct node *head_ref)
{
	struct node *prev=NULL, *curr=head_ref, *next1=NULL;
	while (curr->next != NULL)
	{
		next1 = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next1;
	}
	head_ref = prev;
	return head_ref;
}
void main()
{
	int val=0;
	struct node *head, *temp, *temp2;
	head = (struct node *)malloc(sizeof(struct node));
	temp = head;
	temp2 = head;
	printf("enter values , -1 to terminate : \n");
	while (val != -1)
	{
		scanf_s("%d", &val);
		if (val != -1)
		{
			temp->data = val;
			temp->next = (struct node *)malloc(sizeof(struct node));
			temp = temp->next;
		}
	}
	temp->next = NULL;
	printf("\nLinkedList : \n");
	printList(head);
	printf("\nReverse of the LinkedList : \n");
	reverse(head);
	printf("\n LinkedList : \n");
	printList(head);
	printf("\n LinkedList : \n");
	head = reverseLink(head);
	printList(head);
	_getch();
}