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
	char Dish[25];
}*head = NULL;

void pushDirty(){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = "Dirty";
   if(head == NULL)
      newNode->next = NULL;
   else
      newNode->next = head;
   head = newNode;
}

void pushClean(int value){
	int y=0;
	for(y=1;y<=value;y++){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = "Clean";
   if(head == NULL)
      newNode->next = NULL;
   else
      newNode->next = head;
   head = newNode;
}
}

void pop(){
	struct Node *temp = head;
	printf ("\nAfter Popping: ",temp->data);
	head = temp->next;
	free(temp);
}

void popAll(int value){
	int y=0;
	for(y=1;y<=value;y++){
		struct Node *temp = head;
		head = temp->next;
		free(temp);
	}
printf("All dishes are cleaned! ");
}

void display () {
	printf ("The current dishwasher contain is: \n\n");
	int x,y;
	if (head == NULL){
		printf("Empty!\n\n\n");
	}
	else{
		struct Node *temp = head;int i=0;
    	while(temp != NULL){
    		printf("%d) ",i+1);
			printf(" %s%d ",temp->data,i+1);
			/*for(x=1;x<=temp->data;x++){
				printf(" * ");
			}*/
			i++;
			printf("\n");
			temp = temp->next;
    	}
	}

    system("pause");
    system("cls");
}

void main(){
	printf("\n\n\t*********************************************\n\t");
	printf("     made by Mark & Bo Hun\n\n\t");
	printf("  WELCOME TO DISHWASHER PROGRAM!\n\n\t");
	printf(" This program is made to add dirty dishes");
	printf("\n\t    and to detect if the contain is full");
	printf("\n\t      and to clean dishes!\n\t \n\t********************************************\n\n");
	system("pause");
	system("cls");
	int item;
	int ch;
	int top = -1;
	do {
		do {
			system("cls");
			printf ("\nDISHWASHER MAIN MENU");
			printf ("\n1.Add a dish");
			printf ("\n2.Remove a dish");
			printf ("\n3.Clean all dishes");
			printf ("\n4.Display");
			printf ("\n5.Exit (End the Execution)");
			printf ("\nEnter Your Choice: ");
			scanf  ("%d", &ch);
			if (ch<1 || ch>5)
				       printf ("\nInvalid Choice, Please try again");
		}
		while (ch<1 || ch>5);
		switch (ch) {
			case 1:
			if (count == (MAX)){
				printf ("\nThe Stack is Full! Please pop a data first.\n\n");
				system("pause");
				system("cls");
			}
			else{
			    printf("Adding a dish...\n");
			    pushDirty();
			    system("pause");
			    system("cls");
			    printf("Dish added!");
				printf ("\nAfter Pushing, ");
				display ();
				count++;
			}
			break;
			//
			case 2:
					
			if (head==NULL){
				printf ("\nDishwasher is empty! Please add a dish first!\n\n");
				system("pause");
			} else{  
				pop ();
				display();
				count--;}
			break;
			//
			case 3:
				popAll(count);
				pushClean(count);
			case 4:
				display();break;
			default:
					printf ("\nEND OF EXECUTION");
		}
	}
	while (ch != 5);
	getch();
}
