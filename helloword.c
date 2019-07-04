#include <windows.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>

int g_id = 0;
FILE* fp;
struct data
{
	size_t id;//学号
	char name[20]; //名字
	char className[20];//课程名字
	int score;//成绩
};

struct node
{
	struct data Data;
	struct node* pNext;
};
//代表链表的指针
struct node* pHead = NULL;

//创建链表的节点
struct node* createNode(struct data* d) {
	struct node* pNew = (struct node*)malloc(sizeof(struct node));
	strcpy_s(pNew->Data.className, 20, d->className);
	strcpy_s(pNew->Data.name, 20, d->name);
	pNew->Data.id = d->id;
	pNew->Data.score = d->score;
	pNew->pNext = NULL;
	return pNew;
}

void addNode(struct data* d) {
	struct node* pNew = createNode(d);
	struct node* pTemp = pHead;
	if (pHead == NULL) {
		pHead = pNew;
	}
	else {
		while (1) {
			if (pTemp->pNext == NULL)
				break;
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = pNew;
	}
}

void setData() {
	struct data d;
	printf("请输入学号：");
	scanf_s("%d", &d.id, sizeof(d.id));
	/*if (hasStu(d.id)) {
	printf("姓名%s",d.)
	}*/
	printf("请输入学生姓名：");
	scanf_s("%s", d.name, 20);
	printf("请输入学生课程名称：");
	scanf_s("%s", d.className, sizeof(d.className));
	printf("请输入学生成绩：");
	scanf_s("%d", &d.score, sizeof(d.score));
	while (1) {
		if (d.score > 100)
		{
			printf("成绩不能大于100，请重新输入：");
			scanf_s("%d", &d.score, sizeof(d.score));
			continue;
		}
		else if (d.score < 0) {
			printf("成绩不能小于0，请重新输入：");
			scanf_s("%d", &d.score, sizeof(d.score));
			continue;
		}break;
	}
	
	
	addNode(&d);
	printf("成功了");
}

void getAllStudent() {
	system("cls");
	struct node* pTemp = pHead;
	printf("学号\t姓名\t课程名\t成绩\n");
	while (pTemp) {
		printf("%d\t%s\t%s\t%d\n", pTemp->Data.id, pTemp->Data.name, pTemp->Data.className, pTemp->Data.score);
		pTemp = pTemp->pNext;
	}
	system("pause");
}

void init() {
	struct data d;
	int id = 0;
	errno_t err = fopen_s(&fp, "newer.txt", "r");
	if (err == 0) {
		int r;
		while (1)
		{
			id++;
			r = fread(&d, 1, sizeof(d), fp);
			if (r <= 0)break;
			addNode(&d);
		}
		fclose(fp);
		g_id = id;
	}
	else {
		printf("文件打开失败");
	}

}

void findByStu(char *stuName){
	system("cls");
	printf("学号\t姓名\t课程名\t成绩\n");
	struct node* pTemp = pHead;
	int i = 0;
	if (pTemp == NULL) {
		printf("当前文件中没有数据，无法查询\n");
		return;
	}
	while (pTemp) {
		if (strcmp(pTemp->Data.name,stuName)==0) {
			printf("%d\t%s\t%s\t%d\n", pTemp->Data.id, pTemp->Data.name, pTemp->Data.className, pTemp->Data.score);
			i++;
			pTemp = pTemp->pNext;
			continue;
		}
		else {
			pTemp = pTemp->pNext;
			continue;
		}
	}
	if (i == 0) {
		printf("找不到该学生\n");
		return;
	}
}
BOOL hasStu(int id) {
	struct node* pTemp = pHead;
	while (pTemp) {
		if (pTemp->Data.id == id) {
			return TRUE;
		}
		else {
			pTemp = pTemp->pNext;
			continue;
		}
		return FALSE;
	}
}
void findScoreByStuId(int id) {
	system("cls");
	struct node* pTemp = pHead;
	int i = 0;
	printf("学号\t姓名\t课程名\t成绩\n");
	if (pTemp == NULL) {
		printf("当前文件中没有数据，无法查询\n");
		return;
	}
	while (pTemp) {
		if (pTemp->Data.id==id ) {
			printf("%d\t%s\t%s\t%d\n", pTemp->Data.id, pTemp->Data.name, pTemp->Data.className, pTemp->Data.score);
			i++;
			pTemp = pTemp->pNext;
			continue;
		}
		else {
			pTemp = pTemp->pNext;
			continue;
		}
	}
	if (i == 0) {
		printf("找不到该学生\n");
		return;
	}
}

void findByClass(char *className) {
	struct node* pTemp = pHead;
	int i = 0;
	if (pTemp == NULL) {
		printf("当前文件中没有数据，无法查询");
		return;
	}
	while (pTemp) {
		if (strcmp(pTemp->Data.className, className) == 0) {
			printf("%d\t%s\t%s\t%d\n", pTemp->Data.id, pTemp->Data.name, pTemp->Data.className, pTemp->Data.score);
			i++;
			pTemp = pTemp->pNext;
			continue;
		}
		else {
			pTemp = pTemp->pNext;
			continue;
		}
	}
	if (i = 0) {
		printf("找不到该课程");
	}
}
//写入文件
void save() {

	errno_t err = fopen_s(&fp, "newer.txt", "w");
	struct node* pTemp = pHead;
	if (err == 0) {
		while (pTemp) {
			fwrite(&(pTemp->Data), 1, sizeof(struct data), fp);
			pTemp = pTemp->pNext;
		}
		fclose(fp);
		printf("保存成功");
	}
	else
	{
		printf("保存失败");
	}
	Sleep(3000);
}
void findStu() {
	int a;
	int id;
	char stuName[20];
	printf("请选择要查询的方式：\n1.按姓名查询\n2.按学号查询\n");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
		printf("请输入要查询的学生的姓名:\n");
		scanf_s("%s", stuName, 20);
		findByStu(stuName); break;
	case 2:
		printf("请输入要查询的学生的学号:\n");
		scanf_s("%d", &id);
		findByStuId(id);
		break;
	default:
		break;
	}
	system("pause");
}
void show() {
	system("cls");
	printf("*********学生成绩管理系统*********\n");
	printf("1-----添加学生信息-----\n");
	printf("2-----查询学生成绩-----\n");
	printf("3-----查看所有信息-----\n");
	printf("4-----删除学生信息-----\n");
	printf("5-----保存学生信息-----\n");
}
void main() {
	int n;
	init();
	
	while (1)
	{
		show();
		printf("请选择：");
		scanf_s("%d", &n);

		switch (n)
		{
		case 1:
			setData(); break;
		case 2:
			findStu(); break;
		case 3:
			getAllStudent(); break;
		case 5:
			save(); break;
		default:
			break;
		}
	}
}