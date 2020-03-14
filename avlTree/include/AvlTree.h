#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include "userType.h"
#include "boolean.h"
#include "AvlTreeComponent.h"

boolean InitAvlTree(AvlTree **tree);
void DestoryAvlTree(AvlTree **tree);
Item Search(AvlTree *tree, Item item);
boolean Append(AvlTree *tree, Item item);
boolean Remove(AvlTree *tree, Item item);
char *StringSearch(AvlTree *tree, char *item);
boolean StringAppend(AvlTree *tree, char *item);
boolean StringRemove(AvlTree *tree, char *item);
int GetAvlNodeCount(AvlTree *tree);
Item* ToArray(AvlTree *tree);

#endif