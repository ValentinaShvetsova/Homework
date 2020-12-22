#include <stdio.h>
#include "priorityQueue.h"
#include <stdbool.h>

bool tests() {
	struct PriorityQueue* queue = createQueue();
	enqueue(queue, 1, 2);
	enqueue(queue, 2, 1);
	enqueue(queue, 3, 4);
	enqueue(queue, 4, 3);
	enqueue(queue, 5, 4);

	if (dequeue(queue) != 3) {
		deleteQueue(queue);
		return false;
	}
	if (dequeue(queue) != 5) {
		deleteQueue(queue);
		return false;
	}
	if (dequeue(queue) != 4) {
		deleteQueue(queue);
		return false;
	}
	if (dequeue(queue) != 1) {
		deleteQueue(queue);
		return false;
	}
	if (dequeue(queue) != 2) {
		deleteQueue(queue);
		return false;
	}
	if (dequeue(queue) != -1) {
		deleteQueue(queue);
		return false;
	}

	deleteQueue(queue);
	return true;
}
int main() {
	if (!tests()) {
		printf("Testing error\n");
		return 1;
	}
	return 0;
}