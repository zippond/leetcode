/*
描述
假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？

最后的误差判断是小数点6位



输入描述：
输入起始高度，int型

输出描述：
分别输出第5次落地时，共经过多少米第5次反弹多高

示例1
输入：
1
复制
输出：
2.875
0.03125

*/

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        double sum = n, height = n;
        for(int i = 0; i < 4; i++)
        {
            sum += height;
            height = height/2.0;
        }
        cout<<sum<<endl<<height/2<<endl;
    }
    return 0;
}
