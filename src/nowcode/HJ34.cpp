#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getLongest(const string& s, int x, int y)
{
    while((x > -1)&&( y < s.size())&&(s[x] == s[y]))
    {
        x--;
        y++;
    }
    return y - x -1;
}
int getLongest(const string& s)
{
    int m = 0;
    int i = 0, j = 0;
    for(int i = 0; i < s.size(); i++)
    {
        m = max(getLongest(s, i, i), m); // 奇数对称
        m = max(getLongest(s, i, i+1), m); // 偶数对称
    }
    return m;
}
int main(int argc, char **argv)
{
    string input;
    while(getline(cin, input))
    {
        cout<<getLongest(input)<<endl;
    }
    return 0;
}