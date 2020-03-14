#include <stdio.h>

#include "./include/boolean.h"
#include "./include/AvlTreeComponent.h"
#include "./include/showError.h"

extern char *errorMess;

static AvlNode *FindMin(AvlNode *root);
static int Hight(AvlNode *root);
static AvlNode *SingleRotateWithLeft(AvlNode *root);
static AvlNode *SingleRotateWithRight(AvlNode *root);
static AvlNode *DoubleRotateWithLeft(AvlNode *root);
static AvlNode *DoubleRotateWithRight(AvlNode *root);
static AvlNode *RotateWithLeft(AvlNode *root, void *data);
static AvlNode *RotateWithRight(AvlNode *root, void *data);
static void TravelRoot(AvlNode *root, void *array, int i);

static int Hight(AvlNode *root) {
	if (NULL == root) {
		return 0;
	}

	return root->hight;
}

AvlNode *FindMin(AvlNode *root) {
	if (root != NULL) {
		while (root->leftChild != NULL) {
			root = root->leftChild;
		}
	}

	return root;
}

static AvlNode* SingleRotateWithLeft(AvlNode *root) {
	AvlNode *child = NULL;

	child = root->leftChild;
	root->leftChild = child->rightChild;
	child->rightChild = root; 

	root->hight = Max(Hight(root->leftChild),Hight(root->rightChild)) + 1;
	child->hight = Max(Hight(child->leftChild), root->hight) + 1;
	
	return child;
} 

static AvlNode* SingleRotateWithRight(AvlNode *root) {
	AvlNode *child = NULL;

	child = root->rightChild;
	root->rightChild = child->leftChild;
	child->leftChild = root;

	root->hight = Max(Hight(root->leftChild),Hight(root->rightChild)) + 1;
	child->hight = Max(Hight(child->rightChild), root->hight) + 1;

	return child;
}

static AvlNode* DoubleRotateWithLeft(AvlNode *root) {
	root->leftChild = SingleRotateWithRight(root->leftChild);

	return SingleRotateWithLeft(root);
}

static AvlNode* DoubleRotateWithRight(AvlNode *root) {
	root->rightChild = SingleRotateWithLeft(root->rightChild);

	return SingleRotateWithRight(root);
}

static AvlNode *RotateWithLeft(AvlNode *root, void *data) {
	if (Hight(root->leftChild) - Hight(root->rightChild) == 2) {
		if (IsToLeft(data, root->leftChild->data)) {
			root = SingleRotateWithLeft(root);
		}
		else {
			root = DoubleRotateWithLeft(root);
		}
	}

	return root;
}

static AvlNode *RotateWithRight(AvlNode *root, void *data) {
	if (Hight(root->rightChild) - Hight(root->leftChild) == 2) {
		if (IsToRight(data, root->rightChild->data)) {
			root = SingleRotateWithRight(root);
		}
		else {
			root = DoubleRotateWithRight(root);
		}
	}

	return root;

}

static AvlNode *CreatOneAvlNode(void *data) {
	AvlNode *root = NULL;
	root = (AvlNode *) malloc(sizeof(AvlNode));
	if (NULL == root) {
		errorMess = "Out of space!!!";
	}
	else {
		root->data = data;
		root->hight = 1;
		root->leftChild = root->rightChild = NULL;
	}
	return root;
}

AvlNode* Insert(AvlNode *root, void *data, int *count) {
	if (NULL == root) {
		root = CreatOneAvlNode(data);
		root == NULL ? 0 : ++(*count);
	} 
	else if (IsToLeft(data, root->data)) {
		root->leftChild = Insert(root->leftChild, data, count);
		root = RotateWithLeft(root, data);
	}
	else if (IsToRight(data, root->data)) {
		root->rightChild = Insert(root->rightChild, data, count);
		root = RotateWithRight(root, data);
	}
	root->hight = Max(Hight(root->leftChild),
						 Hight(root->rightChild)) + 1;
	return root;
}
AvlNode *Delete(AvlNode *root, void *data, int *count) {
	AvlNode *tmp = NULL;

	if (NULL == root) {
		printf("Not Found!");
	}
	else if (IsToLeft(data, root->data)) {
		root->leftChild = Delete(root->leftChild, data, count);
		root = RotateWithLeft(root, data);		
	}
	else if (IsToRight(data, root->data)) {
		root->rightChild = Delete(root->rightChild, data, count);
		root = RotateWithRight(root, data);
	}
	else if (root->leftChild && root->rightChild) {
		tmp = FindMin(root->rightChild);
		root->data = tmp->data;
		root->rightChild = Delete(root->rightChild, root->data, count);
		root = RotateWithRight(root, data);		
	} else {
		tmp = root;
		if (NULL == root->leftChild) {
			root = root->rightChild;
		}
		else if (NULL == root->rightChild) {
			root = root->leftChild;
		}	
	}

	if (NULL == tmp) {
		 --(*count);
		free(tmp->data);
		free(tmp);
	}

	return root;
}

void FreeAvlNode(AvlNode *root) {
	if (NULL == root) {
		return;
	}

	FreeAvlNode(root->leftChild);
	FreeAvlNode(root->rightChild);
	free(root->data);
	free(root);
}

AvlNode *Find(AvlNode *root, void *data) {
	AvlNode *gold = NULL;
	if (root == NULL) {
		errorMess = "Not Found!";	
	}
	else if (IsToLeft(data, root->data)) {
		gold = Find(root->leftChild, data);	
	}
	else if (IsToRight(data, root->data)) {
		gold = Find(root->rightChild, data);
	}
	else {
		gold = root;
	}

	return gold;
}
