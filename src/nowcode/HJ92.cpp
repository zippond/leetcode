#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isDigit(char c)
{
    return (c >= '0') && (c <= '9');
}
vector<string> getLongestDigitSeq(string &s)
{
    s += 'a';
    int maxlen = 0, curlen = 0;
    vector<string> ret;
    string tmp;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isDigit(c))
        {
            tmp += c;
        }
        else
        {
            int l = tmp.size();
            if (l)
            {
                if (l > maxlen)
                {
                    maxlen = l;
                    ret.clear();
                    ret.push_back(tmp);
                }
                else if (l == maxlen)
                {
                    ret.push_back(tmp);
                }
                else
                {
                    // do nothing
                }
            }

            tmp = "";
        }
    }
    return ret;
}
int main(int argc, char **argv)
{
    string input;
    while (getline(cin, input))
    {
        vector<string> v = getLongestDigitSeq(input);
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        if (v.size())
            cout <<","<< v[0].size() << endl;
        ;
    }
    return 0;
}