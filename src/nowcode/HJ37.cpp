/*
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？

本题有多组数据。

输入描述：
输入int型表示month

输出描述：
输出兔子总数int型

示例1
输入：
9
复制
输出：
34
*/

#include <iostream>
using namespace std;

int getCount(int n)
{
    if(n == 1 || n == 2) return 1;
    int i = 1, j = 1, k = 0;
    for(int idx = 3; idx <= n; idx++)
    {
        k = i + j;
        i = j;
        j = k;
    }
    return k;
}
int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        cout<<getCount(n)<<endl;
    }
    return 0;
}
int main2(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        int age1 = 1, age2 = 0, age0 = 0, total = 0;
        for(int i = 2; i < n; i++)
        {
            age2 += age1;
            age1 = age0;
            age0 = age2;
        }
        total = age2 + age1 + age0;
        cout<<total<<endl;
    }
    return 0;
}
