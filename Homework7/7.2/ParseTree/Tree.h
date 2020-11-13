#pragma once

struct Tree* tree;

//This function creates tree
struct Tree* createTree();

//This function check whether the tree is empty or nor
bool isEmpty(struct Tree* tree);

//This function build a tree with data from file
struct Tree* buildTree(char* string);

//This function calculates the expression in the tree
int calculate(struct Tree* tree);

//This function delete tree
void deleteTree(struct Tree* tree);

