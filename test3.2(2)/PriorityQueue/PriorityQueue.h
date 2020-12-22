#pragma once

// Queue with priorities
struct PriorityQueue;

// This function creates queue. It returnes pointer on queue
struct PriorityQueue* createQueue();

// This function adds value in queue. It takes pointer on queue, value and priority
void enqueue(struct PriorityQueue* queue, int value, int priority);

// This function gives value with top priority and deletes it from queue. It takes pointer on queue
int dequeue(struct PriorityQueue* queue);

// This function deletes queue. It takes pointer on queue
void deleteQueue(struct PriorityQueue* queue);