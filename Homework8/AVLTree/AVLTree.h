#pragma once

// This structure consists of nodes
struct Tree;

// This function creates tree
struct Tree* createTree();

// This function adds value in the tree
void addValue(struct Tree* tree, char* key, char* value);

// This function gets value by key 
char* getValue(struct Tree* tree, char* key);

// This function checks whether tree contains value by key
bool contains(struct Tree* tree, char* key);

// This function deletes value from tree
void deleteValue(struct Tree* tree, char* key);

//This function deletes Tree
void deleteTree(struct Tree* tree);

// This function gets root value
char* getRootValue(struct Tree* tree);