#include <stdio.h>
#include <stdlib.h>
/* Structure definition */
struct node {
int roll;
char name[30];
char course[30];
struct node *next;
};
/* Enqueue operation */
void enqueue(struct node **front, struct node **rear) {
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
newnode->next = NULL;
if (*rear == NULL) {
*front = *rear = newnode;
} else {
(*rear)->next = newnode;
*rear = newnode;
}
printf("Student enqueued into the queue\n");
}

/* Dequeue operation */
void dequeue(struct node **front, struct node **rear) {
if (*front == NULL) {
printf("Queue underflow\n");
return;
}
struct node *temp = *front;
printf("\nDequeued Student Details:\n");
printf("Roll No : %d\n", temp->roll);
printf("Name : %s\n", temp->name);
printf("Course : %s\n", temp->course);
*front = temp->next;
if (*front == NULL) {
*rear = NULL;
}
free(temp);
}
/* Display queue elements */
void display(struct node *front) {
if (front == NULL) {
printf("Queue is empty\n");
return;
}
printf("\nUniversity Database (Queue):\n");
while (front != NULL) {
printf("Roll No: %d | Name: %s | Course: %s\n",
front->roll, front->name, front->course);
front = front->next;
}
}
/* Main function */
int main() {
struct node *front = NULL;
struct node *rear = NULL;

int choice;
while (1) {
printf("\n1. Enqueue Student");
printf("\n2. Dequeue Student");
printf("\n3. Display Queue");
printf("\n4. Exit");
printf("\nEnter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: enqueue(&front, &rear);
break;
case 2: dequeue(&front, &rear);
break;
case 3: display(front);
break;
case 4: return 0;
default: printf("Invalid choice\n");
}
}
}
