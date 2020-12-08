#pragma once

// This structure consists of nodes
struct Tree;

// This function ctreates tree
struct Tree* createTree();

// This function add value in the tree
void addValue(struct Tree* tree, char* key, char* value);

// This function gets value by key 
char* getValue(struct Tree* tree, char* key);

//This function check whether tree contains value by key
bool contain(struct Tree* tree, char* key);

// This function deletes value from tree
void deleteValue(struct Tree* tree, char* key);

//This function deletes Tree
void deleteTree(struct Tree* tree);