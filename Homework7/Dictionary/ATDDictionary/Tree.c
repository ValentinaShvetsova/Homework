#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Tree.h"

struct Node {
	int key;
	char* value;
	struct Node *parent;
	struct Node* leftChild;
	struct Node* rightChild;
};

struct Tree
{
	struct Node* root;
};

struct Tree* createTree() {
	struct Tree* newTree = calloc(1, sizeof(struct Tree));
	return newTree;
}

bool isEmpty(struct Tree* tree) {
	return tree->root == NULL;
}

void insert(int key, char* value, struct Node* node) {
	if (key == node->key) {
		node->value = value;
		return;
	}
	if (key < node->key) {
		if (node->leftChild == NULL) {
			struct Node* newNode = calloc(1, sizeof(struct Node));
			newNode->key = key;
			newNode->value = value;
			newNode->parent = node;
			node->leftChild = newNode;
			return;
		}
		insert(key, value, node->leftChild);
	}
	if (key > node->key) {
		if (node->rightChild == NULL) {
			struct Node* newNode = calloc(1, sizeof(struct Node));
			newNode->key = key;
			newNode->value = value;
			newNode->parent = node;
			node->rightChild = newNode;
			return;
		}
		insert(key, value, node->rightChild);
	}
}

void addValue(int key, char* value, struct Tree* tree) {
	if (isEmpty(tree)) {
		struct Node* newNode = calloc(1, sizeof(struct Node));
		newNode->key = key;
		newNode->value = value;
		return;
	}
	insert(key, value, tree->root);
}

char* get(struct Node* node, int key) {
	if (node == NULL) {
		return NULL;
	}
	if (node->key == key) {
		return node->value;
	}else if (node->key > key) {
		return get(node->leftChild, key);
	}
	else {
		return get(node->rightChild, key);
	}
}

char* getValue(struct Tree* tree, int key) {
	return get(tree->root, key);
}

bool findKey(struct Node* node, int key) {
	if (node == NULL) {
		return false;
	}
	if (node->key == key) {
		return true;
	}
	else if (key < node->key) {
		return findKey(node->leftChild, key);
	}
	else {
		return findKey(node->rightChild, key);
	}
}

bool contains(struct Tree* tree, int key) {
	return findKey(tree->root, key);
}

struct Node* findTheNearestLesserElement(struct Node* node) {
	struct Node* mostNearest = node->leftChild;
	while (mostNearest->rightChild != NULL) {
		mostNearest = mostNearest->rightChild;
	}
	return mostNearest;
}

void deleteNode(struct Node* node, int key) {
	if (node == NULL) {
		return;
	}
	if (key == node->key) {
		
		if (node->leftChild != NULL && node->rightChild != NULL) {
			struct Node* helpingNode = findTheNearestLesserElement(node);
			node->key = helpingNode->key;
			node->value = helpingNode->value;
			deleteNode(helpingNode, helpingNode->key);
			return;
		}
		else if (node->rightChild == NULL) {
			if (node->leftChild != NULL) {
				node->leftChild->parent = node->parent;
			}
			if (key < node->parent->key) {
				node->parent->leftChild = node->leftChild;
			}
			else {
				node->parent->rightChild = node->leftChild;
			}
		}
		else if (node->leftChild == NULL) {
			if (node->rightChild != NULL) {
				node->rightChild->parent = node->parent;
			}
			if (key < node->parent->key) {
				node->parent->leftChild = node->rightChild;
			}
			else {
				node->parent->rightChild = node->rightChild;
			}
		}
		else {
			if (key < node->parent->key) {
				node->parent->leftChild = NULL;
			}
			else {
				node->parent->rightChild = NULL;
			}
			free(node->key);
			free(node->value);
			free(node->parent);
		}
	}
	else if (key < node->key) {
		deleteNode(node->leftChild, key);
	}
	else {
		deleteNode(node->rightChild, key);
	}
}

void deleteRoot(struct Tree* tree)
{
	if (tree->root->rightChild != NULL && tree->root->leftChild != NULL)
	{
		struct Node* helpNode = findTheNearestLesserElement(tree->root);
		tree->root->key = helpNode->key;
		tree->root->value = helpNode->value;
		deleteNode(helpNode, helpNode->key);
		return;
	}

	struct Node* newRoot = NULL;
	if (tree->root->rightChild == NULL)
	{
		newRoot = tree->root->leftChild;
	}
	else
	{
		newRoot = tree->root->rightChild;
	}
	if (newRoot != NULL)
	{
		newRoot->parent = NULL;
	}
	free(tree->root->value);
	free(tree->root->key);
	free(tree->root);
	tree->root = newRoot;
}

void deleteValue(struct Tree* tree, int key)
{
	if (isEmpty(tree))
	{
		return;
	}

	if (tree->root->key == key)
	{
		deleteRoot(tree);
		return;
	}
	deleteNode(tree->root, key);
}

void deleteChildren(struct Node* node) {
	if (node == NULL) {
		return;
	}
	deleteChildren(node->leftChild);
	deleteChildren(node->rightChild);
	free(node->key);
	free(node->value);
	free(node);
}

void deleteTree(struct Tree* tree)
{
	deleteChildren(tree->root);
}