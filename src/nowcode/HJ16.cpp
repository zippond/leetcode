#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char **argv)
{
    int N, m;
    cin>>N>>m;
    N /= 10;
    vector<vector<int>> price(61, vector<int>(3, 0)), pmw(61, vector<int>(3, 0));
    int v, p, q;
    for(int i = 1; i <= m; i++) // 从1开始 
    {
        cin>>v>>p>>q;
        v /= 10;
        if(!q)
        {
            price[i][0] = v;
            pmw[i][0] = v*p;
        }
        else
        {
            if(price[q][1])
            {
                price[q][2] = v;
                pmw[q][2] = v*p;
            }
            else
            {
                price[q][1] = v;
                pmw[q][1] = v*p;
            }
        }
    }

    vector<vector<int>> dp(m+1, vector<int>(N+1));
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            // dp[i][j] 情况：
            // 0. 不取物品 i : dp[i-1][j]
            // 1. 取物品 i: dp[i - 1][j-price[i]] + pmw[i][0];
            // 2. 取物品 i 及附件1
            // 3. 取物品 i 及附件2
            // 4. 取物品 i 及附件1，2
            int pi = price[i][0], pi1 = price[i][1], pi2 = price[i][2];
            int pmwi = pmw[i][0], pmwi1 = pmw[i][1], pmwi2 = pmw[i][2];
            if(j >= pi)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-pi] + pmwi); // 取与不取i, 设定当前dp[i][j]值
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }

            if(j >= (pi + pi1)) // 在之前条件下，进一步判断
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-pi - pi1] + pmwi + pmwi1);
            }
            if(j >= (pi + pi2)) // 在之前条件下，进一步判断
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j - pi - pi2] + pmwi + pmwi2);
            }
            if(j >= (pi + pi1 + pi2))
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j - pi - pi1 - pi2] + pmwi + pmwi1 + pmwi2);
            }
        }
        
    }
    cout<<dp[m][N]*10<<endl;
    return 0;
}