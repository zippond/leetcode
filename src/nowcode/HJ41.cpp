/*描述
现有一组砝码，重量互不相等，分别为m1,m2,m3…mn；
每种砝码对应的数量为x1,x2,x3...xn。现在要用这些砝码去称物体的重量(放在同一侧)，问能称出多少种不同的重量。


注：

称重重量包括0


输入描述：
输入包含多组测试数据。
对于每组测试数据：
第一行：n --- 砝码数(范围[1,10])
第二行：m1 m2 m3 ... mn --- 每个砝码的重量(范围[1,2000])
第三行：x1 x2 x3 .... xn --- 每个砝码的数量(范围[1,6])
输出描述：
利用给定的砝码可以称出的不同的重量数

示例1
输入：
2
1 2
2 1
复制
输出：
5
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        vector<int> famas(n), numbers(n);
        for(int i = 0; i < n; i++)
        {
            cin>>famas[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin>>numbers[i];
        }

        vector<int> all_weight;
        all_weight.push_back(0);
        for(int i = 0; i < n ;i++)
        {
            int size = all_weight.size();
            for(int j = 0; j < size; j++)
            {
                int cur_weight = all_weight[j];
                for(int k = 1; k <= numbers[i]; k++)
                {
                    int new_weight = cur_weight + famas[i]*k;
                    if(find(all_weight.begin(), all_weight.end(), new_weight) == all_weight.end())
                    {
                        all_weight.push_back(new_weight);
                    }
                }
            }
        }
        cout<<all_weight.size()<<endl;
    }
}