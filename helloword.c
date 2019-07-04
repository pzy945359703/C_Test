#include <windows.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>

int g_id = 0;
FILE* fp;
struct data
{
	size_t id;//ѧ��
	char name[20]; //����
	char className[20];//�γ�����
	int score;//�ɼ�
};

struct node
{
	struct data Data;
	struct node* pNext;
};
//���������ָ��
struct node* pHead = NULL;

//��������Ľڵ�
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
	printf("������ѧ�ţ�");
	scanf_s("%d", &d.id, sizeof(d.id));
	/*if (hasStu(d.id)) {
	printf("����%s",d.)
	}*/
	printf("������ѧ��������");
	scanf_s("%s", d.name, 20);
	printf("������ѧ���γ����ƣ�");
	scanf_s("%s", d.className, sizeof(d.className));
	printf("������ѧ���ɼ���");
	scanf_s("%d", &d.score, sizeof(d.score));
	while (1) {
		if (d.score > 100)
		{
			printf("�ɼ����ܴ���100�����������룺");
			scanf_s("%d", &d.score, sizeof(d.score));
			continue;
		}
		else if (d.score < 0) {
			printf("�ɼ�����С��0�����������룺");
			scanf_s("%d", &d.score, sizeof(d.score));
			continue;
		}break;
	}
	
	
	addNode(&d);
	printf("�ɹ���");
}

void getAllStudent() {
	system("cls");
	struct node* pTemp = pHead;
	printf("ѧ��\t����\t�γ���\t�ɼ�\n");
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
		printf("�ļ���ʧ��");
	}

}

void findByStu(char *stuName){
	system("cls");
	printf("ѧ��\t����\t�γ���\t�ɼ�\n");
	struct node* pTemp = pHead;
	int i = 0;
	if (pTemp == NULL) {
		printf("��ǰ�ļ���û�����ݣ��޷���ѯ\n");
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
		printf("�Ҳ�����ѧ��\n");
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
	printf("ѧ��\t����\t�γ���\t�ɼ�\n");
	if (pTemp == NULL) {
		printf("��ǰ�ļ���û�����ݣ��޷���ѯ\n");
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
		printf("�Ҳ�����ѧ��\n");
		return;
	}
}

void findByClass(char *className) {
	struct node* pTemp = pHead;
	int i = 0;
	if (pTemp == NULL) {
		printf("��ǰ�ļ���û�����ݣ��޷���ѯ");
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
		printf("�Ҳ����ÿγ�");
	}
}
//д���ļ�
void save() {

	errno_t err = fopen_s(&fp, "newer.txt", "w");
	struct node* pTemp = pHead;
	if (err == 0) {
		while (pTemp) {
			fwrite(&(pTemp->Data), 1, sizeof(struct data), fp);
			pTemp = pTemp->pNext;
		}
		fclose(fp);
		printf("����ɹ�");
	}
	else
	{
		printf("����ʧ��");
	}
	Sleep(3000);
}
void findStu() {
	int a;
	int id;
	char stuName[20];
	printf("��ѡ��Ҫ��ѯ�ķ�ʽ��\n1.��������ѯ\n2.��ѧ�Ų�ѯ\n");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
		printf("������Ҫ��ѯ��ѧ��������:\n");
		scanf_s("%s", stuName, 20);
		findByStu(stuName); break;
	case 2:
		printf("������Ҫ��ѯ��ѧ����ѧ��:\n");
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
	printf("*********ѧ���ɼ�����ϵͳ*********\n");
	printf("1-----���ѧ����Ϣ-----\n");
	printf("2-----��ѯѧ���ɼ�-----\n");
	printf("3-----�鿴������Ϣ-----\n");
	printf("4-----ɾ��ѧ����Ϣ-----\n");
	printf("5-----����ѧ����Ϣ-----\n");
}
void main() {
	int n;
	init();
	
	while (1)
	{
		show();
		printf("��ѡ��");
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