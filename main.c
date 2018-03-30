/*
 *Linked list structure. Dunno if it works or not. Basically my first C program.
 *Assignment seems to imply that every data structure will be a linked list.
 *Wrote two separate logics for the job list and the page list. Jobs need to be in a priority linked list queue, not sure if we can just 
 *use the same logic for all structures.
 *Stuff might be missing from the structures. Feel free to fix whatever is in here right now.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct job {
	int size;
	int arrival;
	int duration;
	struct job* next;
} Job;

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
	temp->next = start->next;
	start->next = temp;
}

typedef struct pageList {
	int id;
	int data;
	struct pageList * next;
} Page;

void push(Page ** head, int data, int id) {
	Page * new_page;
	new_page = malloc(sizeof(page));
	new_page->data = data;
	new_page->id = id;
	new_page->next = *head;
	*head = new_page;
}

void print(Page * head) {
	Page * current = head;
	while (current != null) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

int main() {
	return 0;
}
