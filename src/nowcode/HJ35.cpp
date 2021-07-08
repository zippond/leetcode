#include <iostream>
#include <vector>

using namespace std;

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