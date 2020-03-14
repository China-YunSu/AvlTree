#include <stdio.h>

#include "./include/AvlTree.h"
#include "./include/boolean.h"
#include "./include/showError.h"
#include "./include/userType.h"

void Print(AvlTree *avlTree) {
	Item *container = NULL;
	int i = 0;
	int count = GetAvlNodeCount(avlTree);
	container = ToArray(avlTree);

	for (; i < count; i++) {
		printf("��%d��ѧ��������:""%s\n", i + 1,container[i].name);
		printf("��%d��ѧ����ѧ��:""%s\n", i + 1,container[i].id);
		printf("��%d��ѧ������ѧ�ɼ�:""%d\n", i + 1,container[i].math);
	}
	free(container);
}

int main(int argc, char const *argv[])
{
	AvlTree *avlTree = NULL;
	Item student[3] = {0};
	int i = 0;
	
	InitAvlTree(&avlTree);
	for (i = 0; i < 3; i++) {
		printf("�������%d��ѧ��������:", i + 1 );
		scanf("%s", student[i].name);
		printf("�������%d��ѧ����ѧ��:", i + 1 );
		scanf("%s", student[i].id);
		printf("�������%d��ѧ������ѧ�ɼ�:", i + 1 );
		scanf("%d", &student[i].math);
		Append(avlTree, student[i]);
	}
	Print(avlTree);

	DestoryAvlTree(&avlTree);
	
	return 0;
}