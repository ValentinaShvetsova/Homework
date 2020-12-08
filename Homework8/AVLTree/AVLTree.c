#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include "AVLTree.h"

struct Node {
	char* key;
	char* value;
	int height;
	struct Node* parent;
	struct Node* leftChild;
	struct Node* rightChild;
};

struct Tree {
	struct Node* root;
};

bool isEmpty(struct Tree* tree) {
	return tree->root == NULL;
}

bool isLeaf(struct Node* node) {
	return node->leftChild == NULL && node->rightChild == NULL;
}

struct Tree* createTree() {
	struct Tree* newTree = calloc(1, sizeof(struct Tree));
	return newTree;
}

int getHeight(struct Node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return node->height;
	}
}

int heightDifference(struct Node* node) {
	return getHeight(node->rightChild) - getHeight(node->leftChild);
}

void heightUpdate(struct Node* node) {
	int leftHeight = 0;
	int rightHeight = 0;
	if (node->leftChild != NULL) {
		leftHeight = node->leftChild->height;
	}
	
	if (node->rightChild != NULL) {
		rightHeight = node->rightChild->height;
	}
	
	if (leftHeight > rightHeight) {
		node->height = leftHeight + 1;
	}
	else {
		node->height = rightHeight + 1;
	}
}

struct Node* leftRotation(struct Node* root) {
	struct Node* baseOfRotation = root->rightChild;
	baseOfRotation->parent = root->parent;
	if (baseOfRotation->leftChild != NULL) {
		baseOfRotation->leftChild->parent = root;
	}
	baseOfRotation->leftChild = root;
	root->parent = baseOfRotation;
	root->rightChild = NULL;
	heightUpdate(root);
	heightUpdate(baseOfRotation);
	return baseOfRotation;
}

struct Node* rightRotation(struct Node* root) {
	struct Node* baseOfRotation = calloc(1, sizeof(struct Node));
	baseOfRotation = root->leftChild;
	baseOfRotation->parent = root->parent;
	if (baseOfRotation->rightChild != NULL) {
		baseOfRotation->rightChild->parent = root;
	}
	baseOfRotation->rightChild = root;
	root->parent = baseOfRotation;
	root->leftChild = NULL;
	heightUpdate(root);
	heightUpdate(baseOfRotation);
	return baseOfRotation;
}

struct Node* balance(struct Node* node) {
	if (node == NULL) {
		return node;
	}
	heightUpdate(node);
	if (heightDifference(node) == 2) {
		if (heightDifference(node->rightChild) < 0) {
			node->rightChild = rightRotation(node->rightChild);
		}
		return leftRotation(node);
	}
	if (heightDifference(node) == -2) {
		if (heightDifference(node->leftChild) > 0) {
			node->leftChild = leftRotation(node->leftChild);
		}
		return rightRotation(node);
	}
	return node;
}

void insert(struct Node* node, char* key, char* value) {
	if (strcmp(key, node->key) == 0) {
		node->value = value;
		return;
	}
	if (strcmp(key, node->key) < 0) {
		if (node->leftChild == NULL) {
			struct Node* newNode = calloc(1, sizeof(struct Node));
			newNode->key = key;
			newNode->value = value;
			newNode->height = 1;
			node->leftChild = newNode;
			newNode->parent = node;
			return;
		}
		insert(node->leftChild, key, value);
		node->leftChild = balance(node->leftChild);
	}
	if (strcmp(key, node->key) > 0) {
		if (node->rightChild == NULL) {
			struct Node* newNode = calloc(1, sizeof(struct Node));
			newNode->key = key;
			newNode->value = value;
			newNode->height = 1;
			node->rightChild = newNode;
			newNode->parent = node;
			return;
		}
		insert(node->rightChild, key, value);
		node->rightChild = balance(node->rightChild);
	}
}

void addValue(struct Tree* tree, char* key, char* value) {
	char* newValue = calloc(1, sizeof(char));
	if (newValue == NULL) {
		return;
	}
	strcpy(newValue, value);
	char* newKey = calloc(1, sizeof(char));
	if (newKey == NULL) {
		return;
	}
	strcpy(newKey, key);
	if (isEmpty(tree)) {
		struct Node* root = calloc(1, sizeof(struct Node));
		root->key = newKey;
		root->value = newValue;
		root->height = 1;
		root->leftChild = NULL;
		root->rightChild = NULL;
		root->parent = NULL;
		tree->root = root;
		return;
	}
	insert(tree->root, newKey, newValue);
	tree->root = balance(tree->root);
}

char* get(struct Node* node, char* key) {
	if (node == NULL) {
		return NULL;
	}

	if (strcmp(node->key, key) == 0) {
		char* value = calloc(1, sizeof(char));
		strcpy(value, node->value);
		return value;
	}
	if (strcmp(key, node->key) < 0) {
		return get(node->leftChild, key);
	}
	else {
		return get(node->rightChild, key);
	}
}

char* getValue(struct Tree* tree, char* key) {
	return get(tree->root, key);
}

bool find(struct Node* node, char* key) {
	if (node == NULL) {
		return false;
	}
	if (strcmp(node->key, key) == 0) {
		return true;
	}
	else if (strcmp(node->key, key) < 0) {
		return find(node->rightChild, key);
	}
	else {
		return find(node->leftChild, key);
	}
}

bool contain(struct Tree* tree, char* key) {
	return find(tree->root, key);
}

struct Node* closestToMiddle(struct Node* node) {
	struct Node* mostRightOnTheLeft = calloc(1, sizeof(struct Node));
	mostRightOnTheLeft = node->leftChild;
	int leftPath = 1;
	while (mostRightOnTheLeft->rightChild != NULL) {
		mostRightOnTheLeft = mostRightOnTheLeft->rightChild;
		leftPath++;
	}
	struct Node* mostLeftOnTheRight = calloc(1, sizeof(struct Node));
	mostLeftOnTheRight = node->rightChild;
	int rightPath = 1;
	while (mostLeftOnTheRight->leftChild != NULL) {
		mostLeftOnTheRight = mostLeftOnTheRight->leftChild;
		rightPath++;
	}
	if (leftPath >= rightPath) {
		return mostRightOnTheLeft;
	}
	else {
		return mostLeftOnTheRight;
	}
}

void copyData(struct Node* to, struct Node* from) {
	char* newValue = calloc(1, sizeof(char));
	if (newValue == NULL) {
		return;
	}
	strcpy(newValue, from->value);
	char* newKey = calloc(1, sizeof(char));
	if (newKey == NULL) {
		return;
	}
	strcpy(newKey, from->key);
	to->value = newValue;
	to->key = newKey;
}

void deleteNode(struct Node* node, char* key) {
	if (node == NULL) {
		return;
	}
	if (strcmp(node->key, key) == 0) {
		if (node->leftChild != NULL && node->rightChild != NULL) {
			struct Node* helpingNode = closestToMiddle(node);
			copyData(node, helpingNode);
			deleteNode(helpingNode, helpingNode->key);
			return;
		} 
		if (node->leftChild == NULL) {
			if (node->rightChild != NULL) {
				node->rightChild->parent = node->parent;
				node->parent->leftChild = node->rightChild;
			}
		}
		else if (node->rightChild == NULL) {
			if (node->leftChild != NULL) {
				node->leftChild->parent = node->parent;
				node->parent->rightChild = node->leftChild;
			}
		}
		struct Node* help = node->parent;
		free(node->key);
		free(node->value);
		free(node);
		help = balance(help);

		return;
	}
	else if (strcmp(key, node->key) < 0) {
		deleteNode(node->leftChild, key);
	}
	else {
		deleteNode(node->rightChild, key);
	}

	if (node->parent != NULL) {
		if (node->key < node->parent->key) {
			node->parent->leftChild = balance(node);
		}
		else { 
			node->parent->rightChild = balance(node); 
		}
	}
}

void deleteRoot(struct Tree* tree) {
	if (tree->root->leftChild != NULL && tree->root->rightChild != NULL) {
		struct Node* helpingNode = closestToMiddle(tree->root);
		copyData(tree->root, helpingNode);
		deleteNode(helpingNode, helpingNode->key);
		tree->root = balance(tree->root);
		return;
	}
	struct Node* newRoot = calloc(1, sizeof(struct Node));
	if (tree->root->leftChild == NULL) {
		newRoot = tree->root->rightChild;
	}
	else {
		newRoot = tree->root->leftChild;
	}
	if (newRoot != NULL) {
		newRoot->parent = NULL;
	}
	free(tree->root->key);
	free(tree->root->value);
	free(tree->root);
	tree->root = balance(newRoot);
	return;
}

void deleteValue(struct Tree* tree, char* key) {
	if (isEmpty(tree)) {
		return;
	}
	if (strcmp(tree->root->key, key) == 0) {
		deleteRoot(tree);
		return;
	} 
	deleteNode(tree->root, key);
	tree->root = balance(tree->root);
}

void deleteChildren(struct Node* node) {
	if (node == NULL) {
		return;
	}
	deleteChildren(node->leftChild);
	deleteChildren(node->rightChild);
	free(node->key);
	free(node->value);
	free(node->height);
	free(node);
}

void deleteTree(struct Tree* tree)
{
	deleteChildren(tree->root);
}