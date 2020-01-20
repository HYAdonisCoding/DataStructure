#include <stdio.h>
// #include <malloc.h>
#include <stdlib.h>
#include <time.h>

/*静态链表*/

/*线性表的静态链表存储结构*/
#define MAXSIZE 1000 /*假设链表的最大长度是1000*/
typedef int ElemType; 	/*ElemType类型根据实际情况而定，这里假设为int*/
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct
{
	ElemType data;
	int cur;/*游标(Coursor), 为0时表示无指向*/
} Component, StaticLinkList[MAXSIZE];

/*将一维数组space中各分量链成一备用链表*/
/*将space[0].cur为头指针,"0"表示空指针*/
Status InitList(StaticLinkList space) 
{
	int i;
	for (i = 0; i < MAXSIZE-1; ++i)
	{
		space[i].cur = i+1;
	}
	space[MAXSIZE-1].cur = 0;
	return OK;
}

/*获取链表长度
初始条件:静态链表L已经存在.
操作结果:返回L中数据元素个数*/
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE-1].cur;
	while(i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}

/* 插入操作
若备用空间链表非空,则返回分配的结点下标,否则返回0*/
Status Malloc_SLL(StaticLinkList space) 
{
	int i = space[0].cur;/*当前数组第一个元素的cur存的值
	就是要返回的第一个备用空闲的下标*/
	if (space[0].cur) {/* 由于要拿出一个分量来使用了,所以我们就得把他的下一个分量用了做备用 */
		space[0].cur = space[i].cur;
	}
	return i;
}

/* 插入元素
在L中第i个元素之前插入新的数据元素e*/
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int j, k, l;
	k = MAXSIZE-1;
	if (i < 1 || i > ListLength(L) + 1) {/*  description */
		return ERROR;
	}
	j = Malloc_SLL(L);/*获得分量的下标*/
	if (j) {/*  description */
		L[j].data = e;/*将数据赋值给此分量的data*/
		for (l = 1; l <= i - 1; ++l)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;/*把第i个元素之前的cur赋值给新的元素cur*/
		L[k].cur = j;/*把新元素的下标赋值给第i个元素之前元素的cur*/
		return OK;
	}
	return ERROR;
}

/*释放元素
将下标为k的空闲结点回收到备用链表*/
void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;/*把第一个元素cur值赋给要删除的分量cur*/
	space[0].cur = k;/*把要删除的分量下标赋值给第一个元素的cur*/
}
/*删除元素
删除L中第i个数据元素e*/
Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i < 1 || i > ListLength(L)) {/*  description */
		return ERROR;
	}
	k = MAXSIZE-1;
	for (j = 0; j < i-1; ++j)
	{
		k = L[k].cur;
	}
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return OK;
}




int main(int argc, char const *argv[])
{
	printf("hello\n");
	return 0;
}
