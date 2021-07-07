#include <iostream>
#include <vector>
using namespace std;

int count(int n, int m)
{
    if(n == 1) return m+1;
    if(m == 1) return n+1;
    return count(n, m-1) + count(n-1, m);
}

int count2(int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n][m];

}
int main(int argc, char **argv)
{
    int m, n;
    while(cin>>n>>m)
    {
        cout<<count2(n, m)<<endl;
    }
    return 0;
}