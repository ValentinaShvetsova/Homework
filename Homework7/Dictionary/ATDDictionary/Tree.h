#pragma once

struct Tree;

//This function create Tree
struct Tree* createTree();

//This function check whether the tree is empty
bool isEmpty(struct Tree* tree);

//This function insert value
void insert(int key, char* value, struct Node* node);

//This function add value
void addValue(int key, char* value, struct Tree* tree);

//This function gets value
char* get(struct Node* node, int key);

//This function gets value
char* getValue(struct Tree* tree, int key);

//This function check whether the key is in the tree or not
bool findKey(struct Node* node, int key);

//This function check whether the element is in the tree or not
bool contains(struct Tree* tree, int key);

//This function find the largest node in the left subtree
struct Node* findTheNearestLesserElement(struct Node* node);

//This function delete node
void deleteNode(struct Node* node, int key);

//This function delete root
void deleteRoot(struct Tree* tree);

//This function delete value
void deleteValue(struct Tree* tree, int key);

//This function delete all children
void deleteChildren(struct Node* node);

//This function delete tree
void deleteTree(struct Tree* tree);
