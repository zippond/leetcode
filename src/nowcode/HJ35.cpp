#include <iostream>
#include <vector>

using namespace std;

/*
    蛇形矩阵。
    对角线填法。
    下标 和 s(i+j) 从0 到 n-1;
    j = 从0到s;
    i = 从s到0;
*/
int main(int argc, char ** argv)
{
    int n;
    while(cin>>n)
    {
        vector<vector<int>> v(n, vector<int>(n));
        int var = 1;
        for(int s = 0; s < n; s++)
        {
            for(int i = 0; i <= s; i++)
            {
                v[s-i][i] = var;
                var++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < (n - i); j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}