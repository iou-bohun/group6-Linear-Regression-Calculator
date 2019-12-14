#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5

int count=0,array[MAX];

struct Node {
	int data;
	struct Node *next;
}*head = NULL;

void push(int value){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   array[count] = value;
   if(head == NULL)
      newNode->next = NULL;
   else
      newNode->next = head;
   head = newNode;
}

void pop(){
	struct Node *temp = head;
	printf ("\nThe Popped element is %d.  After Popping: ",temp->data);
	head = temp->next;
	free(temp);
}

void display () {
	printf ("The histogram is: \n\n");
	int x,y;
	if (head == NULL){
		printf("Empty!\n\n\n");
	}
	else{
		struct Node *temp = head;int i=0;
    	while(temp != NULL){
    		printf("%d) ",i+1);
			printf(" %d: ",array[i]);
			for(x=1;x<=array[i];x++){
				printf(" * ");
			}
			i++;
			printf("\n");
			temp = temp->next;
    	}
	}

    system("pause");
    system("cls");
}

void main(){
	printf("\n\n\t*********************************\n\t");
	printf("     made by Mark & Bo Hun\n\n\t");
	printf("  WELCOME TO HISTOGRAM PROGRAM!\n\n\t");
	printf(" This program is made to display");
	printf("\n\t    frequency of data to see a");
	printf("\n\t      trend within the data!\n\t \n\t*********************************\n\n");
	system("pause");
	system("cls");
	int item;
	int ch;
	int top = -1;
	do {
		do {
			printf ("\nMAIN MENU");
			printf ("\n1.PUSH (Insert) in the Stack");
			printf ("\n2.POP  (Delete) from the Stack");
			printf ("\n3.Display (See the Histogram)");
			printf ("\n4.Exit (End the Execution)");
			printf ("\nEnter Your Choice: ");
			scanf  ("%d", &ch);
			if (ch<1 || ch>4)
				       printf ("\nInvalid Choice, Please try again");
		}
		while (ch<1 || ch>4);
		switch (ch) {
			case 1:
			if (count == (MAX)){
				printf ("\nThe Stack is Full! Please pop a data first.\n\n");
				system("pause");
				system("cls");
			}
			else{
			    printf ("\nEnter the Element to be pushed : ");
			    scanf  ("%d", &item);
			    push (item);
				printf ("\nAfter Pushing, ");
				display ();
				count++;
			}
			break;
			//
			case 2:
					
			if (head==NULL){
				printf ("Stack underflow on Pop!\n");
			} else  
				pop ();
				display();
				count--;
			break;
			//
			case 3:
				display();break;
			default:
					printf ("\nEND OF EXECUTION");
		}
	}
	while (ch != 4);
	getch();
}
