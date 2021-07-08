#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        vector<int> v;
        int var;
        for(int i = 0; i < n; i++)
        {
            cin>>var;
            v.push_back(var);
        }
        int msteps = 0;
        vector<int> dp(n);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(v[j] < v[i])
                {
                    dp[i] = max(dp[j]+1, dp[i]);
                    msteps = max(dp[i], msteps);
                }
            }
        }
        cout<<msteps + 1<<endl;
    }
    return 0;
}