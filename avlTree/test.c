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
		printf("第%d个学生的姓名:""%s\n", i + 1,container[i].name);
		printf("第%d个学生的学号:""%s\n", i + 1,container[i].id);
		printf("第%d个学生的数学成绩:""%d\n", i + 1,container[i].math);
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
		printf("请输入第%d个学生的姓名:", i + 1 );
		scanf("%s", student[i].name);
		printf("请输入第%d个学生的学号:", i + 1 );
		scanf("%s", student[i].id);
		printf("请输入第%d个学生的数学成绩:", i + 1 );
		scanf("%d", &student[i].math);
		Append(avlTree, student[i]);
	}
	Print(avlTree);

	DestoryAvlTree(&avlTree);
	
	return 0;
}