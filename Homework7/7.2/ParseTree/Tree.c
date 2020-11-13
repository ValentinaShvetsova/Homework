#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include "Tree.h"

struct Node {
	char operation;
	int operand;
	struct Node* leftChild;
	struct Node* rightChild;
};

struct Tree {
	struct Node* root;
};

struct Tree* createTree() {
	struct Tree* newTree = calloc(1, sizeof(struct Tree));
	return newTree;
}

bool isEmpty(struct Tree* tree) {
	return tree->root == NULL;
}

bool isLeaf(struct Node* node) {
	return node->leftChild == NULL && node->rightChild == NULL;
}

bool isOperation(struct Node* node) {
	return node->operation == '+' || node->operation == '-' || node->operation == '*' || node->operation == '/';
}

int numberBuilding(char *string, int **position) {
	int number = 0;
	while (string[**position] >= '0' && string[**position] <= '9')
	{
		number = number * 10 + (string[**position] - '0');
		**position += 1;
	}
	return number;
}

struct Node* newNode(char* string, int *position) {
	(*position) += 1;
	while (string[*position] == ' ' || string[*position] == '(' || string[*position] == ')') {
		(*position) += 1;
	}
	struct Node *node = calloc(1, sizeof(struct Node));
	if (node == NULL) {
		return NULL;
	}

	if (string[*position] == '+' || string[*position] == '-' || string[*position] == '*' || string[*position] == '/') {
		node->operation = string[*position];
		node->leftChild = newNode(string, position);
		node->rightChild = newNode(string, position);
	}
	else {
		node->operand = numberBuilding(string, &position);
	}
	return node;
}

struct Tree* buildTree(char *string) {
	int position = -1;
	struct Tree* tree = createTree();
	tree->root = newNode(string, &position);
	return tree;
}

int calculateSubtree(struct Node* node)
{
	if (isLeaf(node))
	{
		return node->operand;
	}
	const int operand1 = calculateSubtree(node->leftChild);
	const int operand2 = calculateSubtree(node->rightChild);
	const char operation = node->operation;
	if (operation == '+')
	{
		return operand1 + operand2;
	}
	if (operation == '-')
	{
		return operand1 - operand2;
	}
	if (operation == '*')
	{
		return operand1 * operand2;
	}
	else {
		return operand1 / operand2;
	}
}

int calculate(struct Tree* tree) {
	return calculateSubtree(tree->root);
}

void deleteChildren(struct Node* node) {
	if (node == NULL) {
		return;
	}
	deleteChildren(node->leftChild);
	deleteChildren(node->rightChild);

	free(node);
}

void deleteTree(struct Tree* tree)
{
	deleteChildren(tree->root);
}