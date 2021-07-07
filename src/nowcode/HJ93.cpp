/*
    数组分组
    https://www.nowcoder.com/practice/9af744a3517440508dbeb297020aca86?tpId=37&tags=&title=&difficulty=0&judgeStatus=0&rp=1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool group(vector<int>& v)
{
    int sumall = 0, sum5 = 0, sum3 = 0, sumrest = 0;
    vector<int> others;
    for(int i = 0; i < v.size(); i++)
    {
        sumall += v[i];
        if((v[i] % 5) == 0)
        {
            sum5 += v[i];
        }
        else if((v[i] % 3) == 0)
        {
            sum3 += v[i];
        }
        else
        {
            others.push_back(v[i]);
        }
    }

    sumrest = sumall - sum5 - sum3;
    //cout<<"all:"<<sumall<<"sum5:"<<sum5<<"sum3:"<<sum3<<endl;

    int diff = (sum5 > sum3)?(sum5 - sum3):(sum3 - sum5);
    vector<int> sums({0});

    if(!others.size())
    {
        return diff == 0;
    }
    for(int i = 0; i < others.size();i++)
    {
        int csize = sums.size();
        for(int j = 0; j < csize;j++)
        {
            
            int cur_sum = sums[j] + others[i];
            int sum2 = sumrest - cur_sum;
            //cout<<"rest:"<<sumrest<<"cur:"<<cur_sum<<"sum2"<<sum2<<endl;
            if((sum2 - cur_sum) == diff) return true;
            if((cur_sum - sum2) == diff) return true;
            if(find(sums.begin(), sums.end(), cur_sum) == sums.end())
            {
                sums.push_back(cur_sum);
            }
        }
    }
    return false;
}
int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        cout<<(group(v)?"true":"false")<<endl;
    }
    return 0;
}