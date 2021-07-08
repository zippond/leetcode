/*
    放苹果
    m 个苹果放到 n 个盘子里，有几种方法？
    注 5 1 1 和 1 5 1是同一种
*/

#include <iostream>
#include <vector>

using namespace std;

int calc(int m, int n)
{
    if(m <= 1) return 1;
    if(n == 1) return 1;
    if(m < n) return calc(m, m);
    return calc(m, n-1) + calc(m - n, n);
}

int calc2(int m, int n)
{
    vector<vector<int>> dp(m+1, vector<int>(n+1, 1));
    for(int i = 2; i <= m; i++)
    {
        for(int j = 2; j<=n; j++)
        {
            dp[i][j] = dp[i][j-1] + ((i < j)?0:dp[i-j][j]);
        }
    }
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];
}
int main(int argc, char **argv)
{
    int m, n;
    while(cin>>m>>n)
    {
        cout<<calc2(m, n)<<endl;
    }
    return 0;
}