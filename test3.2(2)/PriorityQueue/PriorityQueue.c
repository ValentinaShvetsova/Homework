#include "PriorityQueue.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

struct QueueElement
{
	int value;
	int priority;
	struct QueueElement* next;
};

struct PriorityQueue
{
	struct QueueElement* front;
};

struct PriorityQueue* createQueue() {
	struct PriorityQueue* newQueue = calloc(1, sizeof(struct PriorityQueue));
	return newQueue;
}

bool isEmpty(struct PriorityQueue* queue) {
	return queue->front == NULL;
}

void enqueue(struct PriorityQueue* queue, int value, int priority) {
	struct QueueElement* current = queue->front;
	struct QueueElement* previous = NULL;
	while (current != NULL && current->priority >= priority) {
		previous = current;
		current = current->next;
	}
	struct QueueElement* newQueueElement = calloc(1, sizeof(struct QueueElement));
	newQueueElement->value = value;
	newQueueElement->priority = priority;
	if (previous == NULL) {
		newQueueElement->next = current;
		queue->front = newQueueElement;
	}
	else {
		newQueueElement->next = current;
		previous->next = newQueueElement;
	}
}

int dequeue(struct PriorityQueue* queue) {
	if (isEmpty(queue)) {
		return -1;
	}
	struct QueueElement* first = queue->front;
	queue->front = queue->front->next;
	int firstValue = first->value;
	free(first);
	return firstValue;
}

void deleteQueue(struct PriorityQueue* queue) {
	while (!isEmpty(queue)) {
		struct QueueElement* temp = queue->front->next;
		free(queue->front);
		queue->front = temp;
	}
	free(queue);
}