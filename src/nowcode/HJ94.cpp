#include <iostream>
#include <string>
#include <vector>
#include <map> 
using namespace std;
int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        vector<string> names(n);
        vector<int> counts(n);
        for(int i = 0; i < n; i++)
        {
            cin>>names[i];
        }
        int votes;
        cin>>votes;
        map<string, int> m;
        string vname;
        for(int i = 0; i < votes; i++)
        {
            cin>>vname;
            m[vname]++;
        }
        int count = 0;
        for(int i = 0; i < names.size();i++)
        {
            cout<<names[i]<<" : "<<m[names[i]]<<endl;;
            count += m[names[i]];
        }
        cout<<"Invalid : "<<(votes - count)<<endl;
    }
    return 0;
}