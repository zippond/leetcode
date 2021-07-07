/*
    最长公共子串
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestSubstr(const string &s1, const string& s2)
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    int mlen = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                mlen = max(mlen, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return mlen;
}
int main(int argc, char **argv)
{
    string s1, s2;
    while(getline(cin, s1))
    {
        getline(cin, s2);
        cout<<longestSubstr(s1, s2)<<endl;
    }
    return 0;
}