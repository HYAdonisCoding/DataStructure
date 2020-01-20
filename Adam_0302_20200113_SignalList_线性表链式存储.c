#include <stdio.h>
// #include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
/*线性表的顺序存储结构*/
#define MAXSIZE 20 		/*存储空间初始分配量*/
typedef int ElemType; 	/*ElemType类型根据实际情况而定，这里假设为int*/
typedef struct 
{
	ElemType data[MAXSIZE];	/*数组存储数据元素，最大值为MAXSIZE*/
	int length;				/*线性表当前长度*/
}SqList;
/*获取元素操作*/

typedef int Status;

/*线性表的单链表存储结构*/
typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;

typedef struct Node *LinkList; /*定义LinkList*/

/* 获取元素 
初始条件：顺序线性表L已经存在，1<=i<=ListLengh(L)
操作结果：用e返回L中第i个数据元素的值*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p; /*声明一指针p*/
	p=L->next;/*让p指向链表L的第一个节点*/
	j=1;/*j为计数器*/
	while (p && j<i)/*p不为空且计数器j还没有等于i时，循环继续*/
	{
		p=p->next;
		++j;
	}
	if (!p || j>i) {	/* 第i个节点不存在 */
		return ERROR;
	}
	*e=p->data;	/*获取第i个节点的数据*/
	return OK;
}

/* 插入元素 
初始条件：顺序线性表L已经存在，1<=i<=ListLengh(L)
操作结果：在L中第i个结点位置之前插入新的数据元素e，L的长度加1*/
Status ListInsert(LinkList *L, int i, ElemType e) {
	int j;
	LinkList p,s;
	p=*L;
	j=1;
	while (p && j<i) /*寻找第i-1个结点*/
	{
		p=p->next;
		++j;
	}
	if (!p || j>i) {/* 第i个结点不存在 */
		return ERROR;
	}
	s=(LinkList)malloc(sizeof(Node));/*生成新结点*/
	s->data=e;
	s->next=p->next;/*将p的后继结点赋值给s的后继*/
	p->next=s;/*将s赋值给p的后继*/
	return OK;
}

/* 删除元素 
初始条件：顺序线性表L已经存在，1<=i<=ListLengh(L)
操作结果：删除L中第i个结点,并用e返回其值，L的长度减1*/
Status ListDelete(LinkList *L, int i, ElemType *e) {
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j<i) /*遍历寻找第i-1个结点*/
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j>i) {/* 第i个结点不存在 */
		return ERROR;
	}
	q = p->next;
	p->next = q->next;/*将q的后继赋值给p的后继*/
	*e = q->data;/*将q节点中的数据给e*/
	free(q);
	return OK;
}


/*单链表的整表创建
随机产生n个元素的值,建立表头结点的单链表线性表L(头插法)*/
void CreateListHead(LinkList *L, int n) {
	LinkList p;
	int i;
	srand(time(0));	/*初始化随机种子*/
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;/*先建立一个带头结点的单链表*/
	for (i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(Node));/*生成新结点*/
		p->data = rand()%100+1;/*随机生成100以内的数字*/
		p->next = (*L)->next;
		(*L)->next = p; /*插入到表头*/
	}
}

/*单链表的整表创建
随机产生n个元素的值,建立表头结点的单链表线性表L(尾插法)*/
void CreateListTail(LinkList *L, int n) {
	LinkList p, r;
	int i;
	srand(time(0));	/*初始化随机种子*/
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;/*r为指向尾部的结点*/
	for (i = 0; i < n; ++i)
	{
		p = (Node *)malloc(sizeof(Node));/*生成新结点*/
		p->data = rand()%100+1;/*随机生成100以内的数字*/
		r->next = p;/*将表尾终端节点的指针指向新结点*/
		r = p; /*将当前的新结点定义为表尾终端结点*/
	}
	r->next = NULL;/*表示当前链表结束*/
}


/* 单链表的整表删除
初始条件:顺序线性表L已经存在,
操作结果:将L重置为空表*/
Status ClearList(LinkList *L) {
	LinkList p, q;
	p = (*L)->next;	/*p指向第一个结点*/
	while(p)		/*没到尾结点*/
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;/*头结点指针域为空*/
	return OK;
}


int main(int argc, char const *argv[])
{
	printf("hello\n");
	LinkList L;
	CreateListHead(&L, 10);
	if (ClearList(&L)) {/* 重置 */
		printf("重置成功\n");
	
	}
	CreateListTail(&L, 20);
	ElemType e;
	if (ListDelete(&L, 10, &e)) {
		 printf("删除 %d 成功 \n", e); 
	}
	if (ListInsert(&L, 2, e)) { 
		 printf("插入元素 %d 成功 \n", e); 
	}
	return 0;
}
