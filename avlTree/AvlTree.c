#include <stdio.h>
#include <string.h>

#include "./include/userType.h"
#include "./include/boolean.h"
#include "./include/AvlTree.h"
#include "./include/AvlTreeComponent.h"
#include "./include/showError.h"

extern char *errorMess;

Item Search(AvlTree *tree, Item item) {
	Item null = {0};
	AvlNode *tmp = NULL; 
	if (NULL == tree) {
		return null;
	}

	if(NULL != (tmp = Find(tree->root, &item))) {
		return *(Item *) (tmp->data);
	}

	return null;
}

void DestoryAvlTree(AvlTree **tree) {
	if (NULL == tree || NULL == *tree) {
		return;
	}

	FreeAvlNode((*tree)->root);
	free(*tree);
	*tree = NULL;
}

boolean InitAvlTree(AvlTree **tree) {
	if (NULL == tree || *tree != NULL) {
		errorMess = "³õÊ¼»¯»¯Ê§°Ü£¡";
		return FALSE;
	}

	*tree = (AvlTree*) malloc(sizeof(AvlTree));
	if (NULL == tree) {
		errorMess = "Out of space£¡";
		return FALSE;
	}
	(*tree)->root = NULL;
	(*tree)->count = 0;

	return TRUE;
}

boolean Append(AvlTree *tree, Item item) {
	Item *data = NULL;
	if (NULL == tree) {
		errorMess = "error of append!";
		return FALSE;
	}
	data = (Item *) malloc(sizeof(Item));
	*data = item;

	tree->root = Insert(tree->root, data, &tree->count);

	return TRUE;
}

boolean Remove(AvlTree *tree, Item item) {
	if (NULL == tree) {
		errorMess = "error of Remove!";
		return FALSE;
	}
	
	tree->root = Delete(tree->root, &item, &tree->count);

	return TRUE;
}

boolean StringRemove(AvlTree *tree, char *item) {
	if (NULL == tree) {
		errorMess = "error of Remove!";
		return FALSE;
	}
	
	tree->root = Delete(tree->root, item, &tree->count);

	return TRUE;
}


boolean StringAppend(AvlTree *tree, char *item) {
	char *data = NULL;
	if (NULL == tree) {
		errorMess = "error of append!";
		return FALSE;
	}
	data = (char *) calloc(sizeof(char), strlen(item));
	data = item;

	tree->root = Insert(tree->root, data, &tree->count);

	return TRUE;
}

char *StringSearch(AvlTree *tree, char *item) {
	AvlNode *tmp = NULL;
	if (NULL == tree) {
		return 0;
	}

	if(NULL != (tmp = Find(tree->root, item))) {
		return (char *) (tmp->data);
	}

	return 0;
}

int GetAvlNodeCount(AvlTree *tree) {
	if (NULL == tree) {
		return 0;
	}

	return tree->count;
}

static void TravelRoot(AvlNode *root, Item *array, int *i) {
	if (root == NULL) {
		return;
	}

	TravelRoot(root->leftChild, array, i);
	TravelRoot(root->rightChild, array, i);
	array[(*i)++] = *(Item *)(root->data);
} 

Item* ToArray(AvlTree *tree) {
	Item *array = NULL;
	int i = 0;
	if (NULL == tree) {
		return NULL;
	}

	array = (Item *) calloc(sizeof(Item),tree->count);
	if (NULL != array) {
		TravelRoot(tree->root, array, &i);
	}

	return array;
}
