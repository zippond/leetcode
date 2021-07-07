#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    int n1;
    while(cin>>n1)
    {
        set<int> s;
        int var;
        for(int i = 0; i < n1; i++)
        {
            cin>>var;
            s.insert(var);
        }
        int n2;
        cin>>n2;
        for(int i = 0; i < n2; i++)
        {
            cin>>var;
            s.insert(var);
        }
        for(auto se: s)
        {
            cout<<se;
        }
        cout<<endl;
    }
}