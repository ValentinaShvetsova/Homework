#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"
#include "MergeSort.h"

struct List* mergeSort(struct List* list, int sortType) {
	const int length = listLength(list);
	if (length <= 1) {
		return list;
	}

	struct List* leftList = createList();
	transferElements(list, leftList, length / 2);
	struct List* rightList = createList();
	transferElements(list, rightList, length - length / 2);
	deleteList(list);

	leftList = mergeSort(leftList, sortType);
	rightList = mergeSort(rightList, sortType);
	return merge(leftList, rightList, sortType);
}

void transferElements(struct List* list1, struct List* list2, int length) {
	for (int i = 0; i < length; ++i) {
		addEntry(list2, returnNameFromHead(list1), returnPhoneFromHead(list1));
		deleteHead(list1);
	}
}

struct List* merge(struct List* list1, struct List* list2, int sortType) {
	struct List* newList = createList();
	while (listLength(list1) != 0 && listLength(list2) != 0) {
		int comparison = 0;
		if (sortType == 1) {
			comparison = strcmp(returnNameFromHead(list1), returnNameFromHead(list2));
		}
		else {
			comparison = strcmp(returnPhoneFromHead(list1), returnPhoneFromHead(list2));
		}
		
		if (comparison < 0) {
			transferElements(list1, newList, 1);
		}
		else {
			transferElements(list2, newList, 1);
		}
	}

	if (listLength(list2) == 0) {
		transferElements(list1, newList, listLength(list1));
	}
	else {
		transferElements(list2, newList, listLength(list2));
	}
	deleteList(list1);
	deleteList(list2);
	return newList;
}