#pragma once

struct Tree* tree;

// This function creates tree
struct Tree* createTree();

// This function checks whether the tree is empty or nor
bool isEmpty(struct Tree* tree);

// This function builds a tree with data from string
struct Tree* buildTree(char* string);

// This function calculates the expression in the tree
int calculate(struct Tree* tree);

// This function deletes tree
void deleteTree(struct Tree* tree);

