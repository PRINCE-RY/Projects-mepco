#include <stdio.h>
#include <stdlib.h>
/* Structure definition */
struct node {
int roll;

char name[30];
char course[30];
struct node *next;
};
/* Push operation */
void push(struct node **top) {
struct node *newnode = (struct node *)malloc(sizeof(struct node));
if (newnode == NULL) {
printf("Memory allocation failed\n");
return;
}
printf("\nEnter Roll Number: ");
scanf("%d", &newnode->roll);
printf("Enter Name: ");
scanf("%s", newnode->name);
printf("Enter Course: ");
scanf("%s", newnode->course);
newnode->next = *top;
*top = newnode;
printf("Student pushed onto the stack\n");
}
/* Pop operation */
void pop(struct node **top) {
if (*top == NULL) {
printf("Stack underflow\n");
return;
}
struct node *temp = *top;
printf("\nPopped Student Details:\n");
printf("Roll No : %d\n", temp->roll);
printf("Name : %s\n", temp->name);
printf("Course : %s\n", temp->course);
*top = temp->next;
free(temp);

}
/* Display stack elements */
void display(struct node *top) {
if (top == NULL) {
printf("Stack is empty\n");
return;
}
printf("\nUniversity Database (Stack):\n");
while (top != NULL) {
printf("Roll No: %d | Name: %s | Course: %s\n",
top->roll, top->name, top->course);
top = top->next;
}
}
/* Main function */
int main() {
struct node *top = NULL;
int choice;
while (1) {
printf("\n1. Push Student");
printf("\n2. Pop Student");
printf("\n3. Display Stack");
printf("\n4. Exit");
printf("\nEnter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: push(&top);
break;
case 2: pop(&top);
break;
case 3: display(top);
break;
case 4: return 0;
default: printf("Invalid choice\n"); } } }
