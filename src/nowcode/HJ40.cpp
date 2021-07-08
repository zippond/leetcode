/*
描述
输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。

本题包含多组输入。


输入描述：
输入一行字符串，可以有空格

输出描述：
统计其中英文字符，空格字符，数字字符，其他字符的个数

示例1
输入：
1qazxsw23 edcvfr45tgbn hy67uj m,ki89ol.\\/;p0-=\\][
复制
输出：
26
3
10
12

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void count(const string& s, int &cs, int &ss, int &ds, int &other)
{
    cs = 0;
    ss = 0;
    ds = 0;
    other = 0;
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if( c == ' ')
        {
            ss++;
        }
        else if ((c >= '0') && (c <= '9'))
        {
            ds++;
        }
        else if(((c>='a')&&(c<= 'z'))||((c>='A'))&&(c <= 'Z'))
        {
            cs++;
        }
        else
        {
            other++;
        }
    }
}
int main(int argc, char **argv)
{
    string input;
    while(getline(cin, input))
    {
        int chars, spaces, digits, other;
        count(input, chars, spaces, digits, other);
        cout<<chars<<endl<<spaces<<endl<<digits<<endl<<other<<endl;
    }

    return 0;
}