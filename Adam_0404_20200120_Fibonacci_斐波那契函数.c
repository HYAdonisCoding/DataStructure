#include <stdio.h>

int Fbi(int i)/* 斐波那契递归函数 */
{
    if (i < 2)
    {
        return i == 0 ? 0 : 1;
    }
    return Fbi(i -1) + Fbi(i - 2);
}

int main() {
    int a[40];
    printf("迭代显示斐波那契数列:\n");
    a[0] = 0;
    a[1] = 1;
    printf("%d ", a[0]);
    printf("%d ", a[1]);
    for (int i = 2; i < 40; i++)
    {
        a[i] = a[i-1] + a[i-2];
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("递归显示费斐波那契数列:\n");
    for (int i = 0; i < 40; i++)
    {
        printf("%d", Fbi(i));
    }
    return 0;
}