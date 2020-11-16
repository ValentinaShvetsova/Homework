#pragma once

// This structure consists of key, value and height of node
struct Node;

//This structure consists of nodes
struct Tree;

//This function check emptiness of tree
bool isEmpty(struct Tree* tree);

//This function ctreates tree
struct Tree* createTree();

//This function add value in the tree
void addValue(struct Tree* tree, int key, char* value);

//This function gets value by key 
char* getValue(struct Tree* tree, int key);

//This function check whether tree contains value by key
bool contain(struct Tree* tree, int key);