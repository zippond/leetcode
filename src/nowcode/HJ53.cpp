#include <iostream>
#include <vector>
using namespace std;

int getYH(int n)
{
    vector<vector<int>> dp(n, vector<int>(2 * n + 1));
    dp[0][n] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < (2 * n); j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
            if (i == (n - 1))
            {
                /*
                for(int i1 = 0; i1 < n; i1++)
                {
                    for(int j1 = 0; j1< (2*n+1); j1++)
                    {
                        cout<<dp[i1][j1]<<" ";
                    }
                    cout<<endl;
                }
                */
                
                if (!(dp[i][j] % 2))
                {
                    return j;
                }
            }
        }
    }
    return -1;
}
int main(int argc, char **argv)
{
    int n;
    while (cin >> n)
    {
        cout << getYH(n) << endl;
    }
    return 0;
}