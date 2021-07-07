#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getlongest(string &s, int x, int y)
{
    while((x > -1)&&(y<s.size())&&(s[x] == s[y]))
    {
        x--;
        y++;
    }
    return y - x - 1;
}
int longest(string &s1)
{
    int mlen = 0;
    for(int i = 0; i < s1.size();i++)
    {
        mlen = max(getlongest(s1, i, i), mlen);
        mlen = max(getlongest(s1, i, i+1), mlen);
    }
    return mlen;
}
int main(int argc, char **argv)
{
    string input;
    while(getline(cin, input))
    {
        cout<<longest(input)<<endl;
    }
    return 0;
}