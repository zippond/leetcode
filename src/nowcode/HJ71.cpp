/*
描述
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，下同）
？：匹配1个字符

注意：匹配时不区分大小写。

输入：
通配符表达式；
一组字符串。
输出：

返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false

本题含有多组样例输入！
输入描述：
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串

输出描述：
返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false

示例1
输入：
te?t*.*
txt12.xls
复制
输出：
false
复制
示例2
输入：
z
zz
复制
输出：
false
复制
示例3
输入：
pq
pppq
复制
输出：
false
复制
示例4
输入：
**Z
0QZz
复制
输出：
true
复制
示例5
输入：
?*Bc*?
abcd
复制
输出：
true
复制
示例6
输入：
p*p*qp**pq*p**p***ppq
pppppppqppqqppqppppqqqppqppqpqqqppqpqpppqpppqpqqqpqqp
复制
输出：
false
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool ischar(char c)
{
    return ((c >= 'a')&&(c<='z')||(c >= '0')&&(c<='9')||(c >= 'A')&&(c<='Z'));
}
bool match(const string& p, const string& q)
{
    int plen = p.size(), qlen = q.size();
    vector<vector<bool>> dp(plen+1, vector<bool>(qlen+1)); 
    dp[0][0] = true; // 空配空

    // 全星配空    
    for(int i = 1; i <= plen; i++)
    {
        if(p[i-1] == '*')
        {
            dp[i][0] = dp[i-1][0];
        }
    }

    for(int i = 1; i <= plen; i++)
    {
        for(int j = 1; j <= qlen; j++)
        {
            char pc = tolower(p[i-1]), qc = tolower(q[j-1]);
            if(pc == '?')
            {
                if(ischar(qc))
                    dp[i][j] = dp[i-1][j-1];
            }
            else if(pc == '*')
            {
                if(ischar(qc))
                    dp[i][j] = dp[i-1][j]/* * 匹配 0 个 */  || dp[i-1][j-1] /* * 匹配 第一个(当前) */ ||dp[i][j-1] /* * 已经匹配到了之前的字符，继续匹配 */;
            }
            else if( pc == qc)
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[plen][qlen];
}

int main(int argc, char **argv)
{
    string p, q;
    while(getline(cin, p))
    {
        getline(cin, q);
        cout<<(match(p, q)?"true":"false")<<endl;
    }
    return 0;
}