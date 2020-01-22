#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 
typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

/* 循环队列的顺序存储结构 */
typedef struct
{
    QElemType data[MAXSIZE];
    int front;/* 头指针 */
    int rear;/* 尾指针 */
}SqQueue;

Status visit(QElemType c)
{
    printf("%d ", c);
    return OK;
}

/*  初始化一个空队列 */
Status InitQueue(SqQueue *q)
{
    q->front = 0;
    q->rear = 0;
    return OK;
}

/* 将q清为空队列 */
Status ClearQueue(SqQueue *q)
{
    q->front = q->rear = 0;
    return OK;
}

/* 若队列为空队列,则返回TRUE, 否则返回FALSE */
Status QueueEmpty(SqQueue q)
{
    if (q.front == q.rear) {
        /* 队列为空的标志 */
        return TRUE;
    } else {
        return FALSE;
    }
}

/* 返回q的元素个数,也就是队列当前的长度 */
int QueueLength(SqQueue q)
{
    return (q.rear - q.front + MAXSIZE)%MAXSIZE;
}

/* 若队列不空,则用哦返回q的队头元素,并返回OK,否则返回ERROR */
Status GetHead(SqQueue q, QElemType *e)
{
    if (q.front == q.rear)
    {
        return ERROR;
    }
    *e = q.data[q.front];
    return OK;
}

/* 若队列未满,则插入元素e为新的队尾元素 */
Status EnQueue(SqQueue *q, QElemType e)
{
    if ((q->rear+1)%MAXSIZE == q->front)
    {
        /* 队列满的判断 */
        return ERROR;
    }
    q->data[q->rear] = e;/* 将元素e赋值给队尾 */
    q->rear = (q->rear+1)%MAXSIZE;/* rear指针向后移动一位置,若到最后则转到数组头部 */
    return OK;
}

/* 若队列不空,则删除q中队头元素,用e返回其值 */
Status DeQueue(SqQueue *q, QElemType *e)
{
    if (q->front == q->rear)
    {
        /* 队列空的判断 */
        return ERROR;
    }
    *e = q->data[q->front];/* 将队头元素赋值给e */
    q->front = (q->front+1)%MAXSIZE;/* font指针指向后移一位,若到最后则转到数组头部 */
    return OK;
}

/* 从队头到队尾依次对队列q中每个元素输出 */
Status QueueTraverse(SqQueue q)
{
    int i = q.front;
    while ((i+q.front) != q.rear)
    {
        visit(q.data[i]);
        i = (i+1)%MAXSIZE;
    }
    printf("打印完毕\n");
    return OK;
}

int main() {
    Status j;
    int i = 0, l;
    QElemType d;
    SqQueue q;
    InitQueue(&q);
    printf("初始化队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(q));

    printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ",MAXSIZE-1);
    do
    {
        // scanf("%d", &d);
        d = i+100;
        if (d == -1)
        {
            break;
        }
        i++;
        EnQueue(&q, d);
    } while (i < MAXSIZE-1);
    printf("队列长度为: %d\n",QueueLength(q));
	printf("现在队列空否？%u(1:空 0:否)\n",QueueEmpty(q));
	printf("连续%d次由队头删除元素,队尾插入元素:\n",MAXSIZE);

    for ( l = 0; l <= MAXSIZE; l++)
    {
        DeQueue(&q, &d);
        printf("删除的元素是%d的, 插入的元素:%d\n", d, l+1000);
        d = 1+ 1000;
        EnQueue(&q, d);
    }
    l = QueueLength(q);

    printf("现在队列中的元素为:\n");
    QueueTraverse(q);
    printf("共向队尾插入了%d个元素\n", i+MAXSIZE);
    if (l-1>0)  
    {
        printf("现在由队头删除%d个元素:\n", l-2);
    }
    while (QueueLength(q)>2)
    {
        DeQueue(&q, &d);
        printf("删除的元素值为%d\n", d);
    }

    j = GetHead(q, &d);
    if (j)
    {
        printf("现在队头元素为: %d\n", d);
    }
    ClearQueue(&q);
    printf("清空队列后,队列空否?%u(1:空 0:否)\n", QueueEmpty(q));
    
    return 0;
}