#include <iostream>
#include <string>
#include <vector>
using namespace std;

string process(string s)
{
    s += 'a';
    vector<char> v(2*s.size(), '\0');
    for(int i = 0; i < s.size(); i++)
    {
        v[2*i+1] = s[i];
    }
    bool indigit = false;
    for(int i = 1; i < v.size(); i+=2)
    {
        if(isdigit(v[i]))
        {
            if(indigit)
            {
                //
            }
            else
            {
                v[i-1] = '*';
                indigit = true;
            }
        }
        else
        {
            if(indigit)
            {
                v[i-1] = '*';
                indigit = false;
            }
        }
    }
    string ret;
    for(int i = 0; i < v.size() - 1;i++)
    {
        if(v[i] != '\0')
            ret += v[i];
    }
    return ret;
}
int main(int argc, char **argv)
{
    string input;
    while(getline(cin, input))
    {
        cout<<process(input)<<endl;
    }
    return 0;
}