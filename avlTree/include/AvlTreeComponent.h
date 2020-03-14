#ifndef _AVLTREEINTERFACE_H_
#define _AVLTREEINTERFACE_H_ 

typedef struct AvlNode {
	void *data;
	struct AvlNode *leftChild;
	struct AvlNode *rightChild;
	int hight;
}AvlNode;

typedef struct AvlTree {
	AvlNode *root;
	int count;
} AvlTree;

#define Max(x,y) ((x) > (y) ? (x) : (y))

AvlNode *Find(AvlNode *root, void *data);
AvlNode *Delete(AvlNode *root, void *data, int *count);
AvlNode* Insert(AvlNode *root, void *data, int *count);
void FreeAvlNode(AvlNode *root);

#endif