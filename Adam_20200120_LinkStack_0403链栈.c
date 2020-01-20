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
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
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
    return s.count;
}

/* 若栈不空,则用e返回s的栈顶元素,并返回OK;否则返回ERROR */
Status GetTop(LinkStack s, SElemType *e)
{
    if (s.top == NULL) {
        return ERROR;
    } else {
        *e = s.top->data;
        return OK;
    }
}

/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *s, SElemType e)
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = s->top;/* 把当前的栈顶元素赋值给新的结点的直接后继 */
    s->top = p;/* 将新的结点p夫妇只给栈顶指针 */
    s->count++;
    return OK;
}

/* 若栈不空,则删除s的栈顶元素,用e返回其值,并返回OK;否则返回OK */
Status Pop(LinkStack *s, SElemType *e)
{
    LinkStackPtr p;
    if (StackEmpty(*s))
    {
        return ERROR;
    }
    *e = s->top->data;
    p = s->top; /* 将栈顶结点赋值给p */
    s->top = s->top->next;/* 是的栈顶指针指向下移一位, 指向后一结点 */
    free(p);/* 释放结点p */
    s->count--;
    return OK;
}

Status StackTraverse(LinkStack s)
{
    printf("栈中元素依次为：");
    LinkStackPtr p;
    p = s.top;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("打印完毕\n");
    return OK;
}

int main() {
    int j, e;
    LinkStack s;
    if (InitStack(&s) == OK)
    {
        for (j = 0; j <= 10; j++)
        {
            Push(&s, j);
        }
    }
    StackTraverse(s);
    Pop(&s, &e);
    printf("弹出的栈定元素 e = %d\n", e);
    StackTraverse(s);
    printf("栈空否: %d(1:空 0:否)\n", StackEmpty(s));
    GetTop(s, &e);
    printf("栈顶元素 e = %d 栈的长度为%d\n", e, StackLength(s));
    ClearStack(&s);
    printf("清空栈后, 栈空否: %d(1:空 0:否)\n", StackEmpty(s));

    return 0;
}
