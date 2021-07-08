#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    vector<string> v;
    string s;
    while(getline(cin, s))
    {
        s += " ";
        string tmp;
        for(int i = 0; i < s.size();i++)
        {
            char c = s[i];
            if(((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z')))
            {
                tmp += c;
            }
            else
            {
                if(tmp.size())
                {
                    v.push_back(tmp);
                    tmp = "";
                }
            }
        }
    }
    for(int i = v.size(); i>0; i--)
    {
        cout<<v[i-1]<<" ";
    }
    cout<<endl;
    return 0;
}