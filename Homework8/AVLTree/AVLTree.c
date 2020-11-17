#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include "AVLTree.h"

struct Node {
	int key;
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
	struct Tree* newTree = callloc(1, sizeof(struct Tree*));
	return newTree;
}

int getHeight(struct Node* node) {
	if (node == NULL) {
		return -1;
	}
	else {
		return node->height;
	}
}

int heightDifference(struct Node* node) {
	return getHeight(node->rightChild) - getHeight(node->leftChild);
}

void heightUpdate(struct Node* node) {
	int leftHeight = node->leftChild->height;
	int rightHeight = node->rightChild->height;
	if (leftHeight > rightHeight) {
		node->height = leftHeight + 1;
	}
	else {
		node->height = rightHeight + 1;
	}
}

struct Node* leftRotation(struct Node* root) {
	struct Node* baseOfRotation = calloc(1, sizeof(struct Node*));
	baseOfRotation = root->rightChild;
	baseOfRotation->parent = root->parent;
	if (baseOfRotation->leftChild != NULL) {
		baseOfRotation->leftChild->parent = root;
	}
	baseOfRotation->leftChild = root;
	root->parent = baseOfRotation;
	heightUpdate(root);
	heightUpdate(baseOfRotation);
	return baseOfRotation;
}

struct Node* rightRotation(struct Node* root) {
	struct Node* baseOfRotation = calloc(1, sizeof(struct Node*));
	baseOfRotation = root->leftChild;
	baseOfRotation->parent = root->parent;
	if (baseOfRotation->rightChild != NULL) {
		baseOfRotation->rightChild->parent = root;
	}
	baseOfRotation->rightChild = root;
	root->parent = baseOfRotation;
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

void addValue(struct Tree* tree, int key, char* value) {
	char* newValue = calloc(1, sizeof(char*));
	if (newValue == NULL) {
		return;
	}
	strcpy(newValue, value);
	if (isEmpty(tree)) {
		struct Node* root = calloc(1, sizeof(struct Node*));
		root->key = key;
		root->value = newValue;
		root->height = 0;
		tree->root = root;
	}
	insert(tree->root, key, newValue);
	tree->root = balance(tree->root);
}

void insert(struct Node* node, int key, char* value) {
	if (key == node->key) {
		node->value = value;
		return;
	}
	if (key < node->key) {
		if (node->leftChild == NULL) {
			struct Node* newNode = calloc(1, sizeof(struct Node*));
			newNode->key = key;
			newNode->value = value;
			newNode->height = 0;
			node->leftChild = newNode;
			return;
		}
		insert(node->leftChild, key, value);
		node->leftChild = balance(node->leftChild);
	}
	if (key > node->key) {
		if (node->rightChild == NULL) {
			struct Node* newNode = calloc(1, sizeof(struct Node*));
			newNode->key = key;
			newNode->value = value;
			newNode->height = 0;
			node->rightChild = newNode;
			return;
		}
		insert(node->rightChild, key, value);
		node->rightChild = balance(node->rightChild);
	}
}

char* get(struct Node* node, int key) {
	if (node == NULL) {
		return NULL;
	}

	if (node->key == key) {
		char* value = calloc(1, sizeof(char*));
		strcpy(value, node->value);
		return value;
	}
	if (key < node->key) {
		return get(node->leftChild, key);
	}
	else {
		return get(node->rightChild, key);
	}
}

char* getValue(struct Tree* tree, int key) {
	return get(tree->root, key);
}

bool find(struct Node* node, int key) {
	if (node == NULL) {
		return false;
	}
	if (node->key = key) {
		return true;
	}
	else if (node->key < key) {
		return find(node->rightChild, key);
	}
	else {
		return find(node->leftChild, key);
	}
}

bool contain(struct Tree* tree, int key) {
	return find(tree->root, key);
}

struct Node* closestToMiddle(struct Node* node) {
	struct Node* mostRightOnTheLeft = callloc(1, sizeof(struct Node*));
	mostRightOnTheLeft = node->leftChild;
	int leftPath = 1;
	while (mostRightOnTheLeft->rightChild != NULL) {
		mostRightOnTheLeft = mostRightOnTheLeft->rightChild;
		leftPath++;
	}
	struct Node* mostLeftOnTheRight = callloc(1, sizeof(struct Node*));
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
	char* newValue = calloc(1, sizeof(char*));
	strcpy(newValue, from->value);
	free(to->value);
	to->value = newValue;
	to->key = from->key;
}

void deleteNode(struct Node* node, int key) {
	if (node == NULL) {
		return;
	}
	if (node->key = key) {
		if (node->leftChild != NULL && node->rightChild != NULL) {
			struct Node* helpingNode = closestToMiddle(node);
			copyData(node, helpingNode);
			deleteNode(helpingNode, helpingNode->key);
			return;
		} 
		if (node->leftChild == NULL) {
			if (node->rightChild != NULL) {
				node->rightChild->parent = node->parent;
			}
			node->parent->rightChild = node->rightChild;
		}
		else if (node->rightChild == NULL) {
			if (node->leftChild != NULL) {
				node->leftChild->parent = node->parent;
			}
			node->parent->leftChild = node->leftChild;
		}
		struct Node* help = node->parent;
		free(node->value);
		free(node->key);
		free(node->height);
		free(node);
		help = balance(help);

		return;
	}
	else if (key < node->key) {
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
	struct Node* newRoot = calloc(1, sizeof(struct Node*));
	if (tree->root->leftChild == NULL) {
		newRoot = tree->root->rightChild;
	}
	else {
		newRoot = tree->root->leftChild;
	}
	if (newRoot != NULL) {
		newRoot->parent = NULL;
	}
	free(tree->root->height);
	free(tree->root->key);
	free(tree->root->value);
	free(tree->root);
	tree->root = balance(newRoot);
	return;
}

void deleteValue(struct Tree* tree, int key) {
	if (isEmpty(tree)) {
		return;
	}
	if (tree->root->key = key) {
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