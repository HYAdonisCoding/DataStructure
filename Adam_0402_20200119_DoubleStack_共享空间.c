#include <stdlib.h>
#include <stdio.h>

#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20/* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType;/* SElemType根据实际情况而定,这里假设为int */

/* 两栈共享空间结构 */
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;/* 栈1栈顶指针 */
    int top2;/* 栈2栈顶指针 */
}SqDoubleStack;

Status visit(SElemType c)
{
    printf("-%d-", c);
    return c;
}

/* 构造一个空栈S */
Status InitStack(SqDoubleStack *S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqDoubleStack *S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

/* 若栈S为空栈则返回TRUE,否则返回FALSE */
Status StackEmpty(SqDoubleStack S)
{
    if (S.top1 == -1 && S.top2 == MAXSIZE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* 返回S的元素个数,即栈的长度 */
int StackLength(SqDoubleStack S)
{
    return (S.top1 + 1) + (MAXSIZE-S.top2);
}

/* 插入元素e为新的栈顶元素 */
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if (S->top1+1 == S->top2)   /* 栈已满,不能再push新元素了 */
    {
        return ERROR;
    }
    if (stackNumber == 1)/* 栈1有元素进栈 */
    {
        S->data[++S->top1] = e;/* 若是栈1则先top1+1后给数组元素赋值 */
    }
    else if (stackNumber == 2)/* 栈2有元素进栈 */
    {
        S->data[--S->top2] = e;/* 若是栈2则先top2-1后给数组元素赋值 */
    }
    else
    {
        return ERROR;
    }
    return OK;
}

/* 若栈不空,则删除S的栈顶元素, 用e返回其值, 并返回OK;否则返回ERROR */
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{

    if (stackNumber == 1)/* 栈1 */
    {
        if (S->top1 == -1)
        {
            return ERROR;/* 说明栈1已经是空栈,溢出 */
        }
        
        *e = S->data[S->top1--];/* 将栈1的栈顶元素出栈 */
    }
    else if (stackNumber == 2)/* 栈2有元素进栈 */
    {
        if (S->top2 == MAXSIZE)
        {
            return ERROR;/* 说明栈2已经是空栈,溢出 */
        }
        
        *e = S->data[S->top2++];/* 将栈2的栈顶元素出栈 */
    }
    else
    {
        return ERROR;
    }
    return OK;
}

Status StackTraverse(SqDoubleStack S)
{
    int i = 0;
    while (i <= S.top1)
    {
        visit(S.data[i++]);
    }
    i = S.top2;
    while (i < MAXSIZE)
    {
        visit(S.data[i++]);
    }
    printf("\n打印完毕\n");
    return OK;
}

int main() {
    int i, e;
    SqDoubleStack s;
    if (InitStack(&s) == OK)
    {
        for (i = 1; i <= 5; i++)
        {
            Push(&s, i, 1);
        }
        for (i = MAXSIZE; i >= MAXSIZE-2; i--)
        {
            Push(&s, i, 2);
        }
    }
    printf("栈中元素依次为:");
    StackTraverse(s);
    printf("当前栈中元素有: %d 个\n", StackLength(s));

    Pop(&s, &e, 2);
    printf("弹出的2栈顶元素 e = %d\n", e);
    // Pop(&s, &e, 1);
    // printf("弹出的1栈顶元素 e = %d\n", e);
    printf("栈空否: %d(1:空 0:否)\n", StackEmpty(s));
    printf("栈中元素依次为:");
    StackTraverse(s);
    printf("当前栈中元素有：%d \n",StackLength(s));

    for (int i = 0; i < MAXSIZE-3; i++)
    {
        Push(&s, i, 1);
    }
    printf("栈中元素依次为:");
    StackTraverse(s);

    printf("栈满否: %d(1:否 0: 满)\n", Push(&s, 100, 1));
    printf("栈满否：%d(1:否 0:满)\n",Push(&s,100,2));
    printf("栈中元素依次为:");
    StackTraverse(s);

    ClearStack(&s);
    printf("清空栈后,栈空否: %d(1:空 0:否)\n", StackEmpty(s));
    return 0;
}
