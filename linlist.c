#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Student node structure */
struct student {
int rollnumber;
char name[50];
char course[50];
struct student *next;
};
/* Linked list structure */
struct studentList {
struct student *head;
struct student *tail;
int count;
};
/* Create a new node */
struct student* createNode(int rollnumber, char name[], char course[]) {
struct student *t = (struct student*)malloc(sizeof(struct student));
t->rollnumber = rollnumber;
strcpy(t->name, name);
strcpy(t->course, course);
t->next = NULL;

return t;
}
/* Insert at beginning */
void insertAtBegin(struct studentList *l, int rollnumber, char name[], char course[]) {
struct student *t = createNode(rollnumber, name, course);
if (l->count == 0) {
l->head = l->tail = t;
} else {
t->next = l->head;
l->head = t;
}
l->count++;
}
/* Insert at end */
void insertAtEnd(struct studentList *l, int rollnumber, char name[], char course[]) {
struct student *t = createNode(rollnumber, name, course);
if (l->count == 0) {
l->head = l->tail = t;
} else {
l->tail->next = t;
l->tail = t;
}
l->count++;
}
/* Print student list */
void printList(struct studentList *l) {
struct student *current = l->head;
if (current == NULL) {
printf("No student records found.\n");
return;
}
printf("\nStudent Records:\n");
while (current != NULL) {
printf("Roll No: %d, Name: %s, Course: %s\n",

current->rollnumber,
current->name,
current->course);
current = current->next;
}
printf("NULL\n");
}
/* Delete at beginning */
void deleteAtBegin(struct studentList *l) {
if (l->count == 0)
return;
struct student *temp = l->head;
l->head = l->head->next;
if (l->head == NULL)
l->tail = NULL;
free(temp);
l->count--;
}
/* Delete at end */
void deleteAtEnd(struct studentList *l) {
if (l->count == 0)
return;
if (l->count == 1) {
free(l->head);
l->head = l->tail = NULL;
} else {
struct student *temp = l->head;
while (temp->next != l->tail)
temp = temp->next;
free(l->tail);
temp->next = NULL;
l->tail = temp;
}
l->count--; }

/* Menu */
void menu() {
printf("\n--- Student Enrollment System ---\n");
printf("1. Insert at Beginning\n");
printf("2. Insert at End\n");
printf("3. Display Students\n");
printf("4. Delete from Beginning\n");
printf("5. Delete from End\n");
printf("6. Exit\n");
printf("Enter your choice: ");
}
/* Main function */
int main() {
struct studentList myList = { NULL, NULL, 0 };
int choice, rollnumber;
char name[50], course[50];
while (1) {
menu();
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter Roll Number, Name, Course: ");
scanf("%d %s %s", &rollnumber, name, course);
insertAtBegin(&myList, rollnumber, name, course);
break;
case 2:
printf("Enter Roll Number, Name, Course: ");
scanf("%d %s %s", &rollnumber, name, course);
insertAtEnd(&myList, rollnumber, name, course);
break;
case 3:
printList(&myList);
break;
case 4:

deleteAtBegin(&myList);
break;
case 5:
deleteAtEnd(&myList);
break;
case 6:
printf("Exiting...\n");
return 0;
default:
printf("Invalid choice!\n");
}
}
}
