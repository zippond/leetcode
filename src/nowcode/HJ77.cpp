/*
 火车进站
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool valid(stack<int> spre, vector<int>& v)
{
    stack<int> sout, sin;
    for(int i = v.size()-1; i >= 0; i--)
    {
        sout.push(v[i]);
    }
    while(sout.size())
    {
        int cur = sout.top();
        while (sin.empty() || (sin.top() != cur)) // 不相等，就從pre裏取
        {
            if(spre.size()) 
            {
                sin.push(spre.top());
                spre.pop();
            }
            else // 如果pre里没有，返回false
            {
                return false;
            }
        }
        // 此时 top == cur
        sout.pop();
        sin.pop();
    }
    return true;
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
        stack<int> spre;
        for(int i = n-1; i >= 0; i--)
        {
            spre.push(v[i]);
        }
        stack<int> sin;
        sort(v.begin(), v.end());
        do{
            if(valid(spre, v))
            {
                for(int i = 0; i < n; i++)
                {
                    cout<<v[i];
                    if( i != (n-1))
                    cout<<" ";
                }
                cout<<endl;
            }
        }
        while(next_permutation(v.begin(), v.end()));
    }
}