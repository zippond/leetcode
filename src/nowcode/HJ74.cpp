/*
    参数解析
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getCmds(string s)
{
    s += " "; // 辅助空格
    bool in_quote = false;
    vector<string> ret;
    string tmp;
    for(int i = 0; i < s.size();i++)
    {
        char c = s[i];
        if( c == '"')
        {
            if(in_quote)
            {
                in_quote = false;
            }
            else
            {
                in_quote = true;
            }
            continue;
        }
        else if(c == ' ')
        {
            if(in_quote)
            {
                tmp += c;
            }
            else
            {
                if(tmp.size())
                {
                    ret.push_back(tmp);
                    tmp = "";
                }
            }
        }
        else
        {
            tmp += c;
        }
    }
    return ret;
}
int main(int argc, char **argv)
{
    string input;
    while(getline(cin, input))
    {
        vector<string> cmd = getCmds(input);
        cout<<cmd.size()<<endl;
        for(auto s: cmd)
        {
            cout<<s<<endl;
        }
    }
    return 0;
}