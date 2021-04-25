#pragma once
#define SIZE 101

struct Tree;

// This function creates Tree
struct Tree* createTree();

// This function checks whether the tree is empty
bool isEmpty(struct Tree* tree);

// This function adds value
void addValue(int key, char* value, struct Tree* tree);

// This function gets value
char* getValue(struct Tree* tree, int key);

// This function checks whether the element is in the tree or not
bool contains(struct Tree* tree, int key);

// This function deletes root
void deleteRoot(struct Tree* tree);

// This function deletes value
void deleteValue(struct Tree* tree, int key);

// This function deletes tree
void deleteTree(struct Tree* tree);
