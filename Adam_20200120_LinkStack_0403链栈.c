#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 链栈结构 */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct
{
    LinkStackPtr top;
    int count;
}LinkStack;

Status visit(SElemType c)
{
    printf("%d ", c);
    return OK;
}

/* 构造一个空栈 */
Status InitStack(LinkStack *s)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!s->top)
    {
        return ERROR;
    }
    s->top = NULL;
    s->count = 0;
    return OK;
}

/* 置为空栈 */
Status ClearStack(LinkStack *s)
{
    LinkStackPtr p, q;
    p = s->top;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    s->count = 0;
    return OK;
}

/* 若栈为空栈,则返回TRUE,否则返回FALSE */
Status StackEmpty(LinkStack s)
{
    if (s.count == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* 返回s的元素个数,即栈的长度 */
int StackLength(LinkStack s)
{
    if (s.count == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}