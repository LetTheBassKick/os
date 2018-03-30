/*
 *Linked list structure. Dunno if it works or not. Basically my first C program.
 *Assignment seems to imply that every data structure will be a linked list.
 *Wrote two separate logics for the job list and the page list. Jobs need to be in a priority linked list queue, not sure if we can just use the same logic for all structures.
 *Stuff might be missing from the structures. Feel free to fix whatever is in here right now.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct jobList {
	int size;
	int arrival;
	int duration;
	struct jobList* next;
}Job;


Job* newJob(int s, int d, int a) {
	Job* temp = (Job*)malloc(sizeof(Job));
	temp->size = s;
	temp->arrival = a;
	temp->duration = d;
	temp->next = NULL;
	return temp;
}

void pushJob(Job** head, int s, int d, int a) {
	Job* start = (*head);
	Job* temp = newJob(s, d, a);
	if ((*head)->arrival > a) {
		temp->next = *head;
		(*head) = temp;
	}
	else {
		while (start->next != NULL && start->next->arrival < a) {
			start = start->next;
		}
	}
	temp->next = start->next;
	start->next = temp;
}

void printJob(Job* head) {
	Job* current = head;
	while (current != NULL) {
		printf("%d\n", current->arrival);
		current = current->next;
	}
}


typedef struct pageList {
	int id;
	int data;
	struct pageList *next;
}*page;


page createPage(int d, int i){
	page temp; 
	temp = malloc(sizeof(page));
	temp->data = d;
	temp->id = i;
	temp->next = NULL;
	return temp;
}

void push(page head, int d, int i) {
	page current,temp;
	temp = createPage(d, i);
	if (head == NULL) {
		head = temp;
	}
	else {
		current = head;
		while (current->next != NULL) { //Maybe take the loop out. Pushing to the beginning didn't seem to work.
			current = current->next;
		}
		current->next = temp;
	}
}

void print(page head) {
	page current = head;
	while (current != NULL) {
		printf("%d\n", current->id);
		current = current->next;
	}
}

int main() {
	page one = createPage(5, 1); //Seems like a bit of a hassle to have to create something every time, dunno how to get around it though
	push(one, 5, 4);
	push(one, 3, 2);
	push(one, 2, 3);
	print(one);
	Job* head = newJob(5, 1, 1);
	pushJob(&head, 4, 6, 3);
	pushJob(&head, 5, 2, 2);
	printJob(head);
	return 0;
}
