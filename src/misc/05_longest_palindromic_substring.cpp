/*

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
class Solution0
{
public:
    string longestPalindrome(string s)
    {
        string max_substr;
        for(int i = 0; i < s.size();i++)
        {
            string t = getLongestPalindromeStr(s, i, i);
            if(t.size() > max_substr.size())
            {
                max_substr = t;
            }

            t = getLongestPalindromeStr(s, i, i+1);
            if(t.size() > max_substr.size())
            {
                max_substr = t;
            }
        }
        return max_substr;
    }
    string getLongestPalindromeStr(const string& s, int l, int r)
    {
        // expand
        while((l>=0)&&(r<s.size())&&(s[l] == s[r]))
        {
            l--;
            r++;
        }
        return s.substr(l+1, r - l - 1);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        int max_len = 1;
        int start = 0;
        for(int L = 2; L <= n; L++)
        {
            if( max_len < (L-2)) break; // shortcut，return if no shorter palindrome
            for(int i = 0; i < n; i++)
            {
                int j = i + L - 1;
                if(j >= n) break;
                if(s[i] == s[j])
                {
                    if(L == 2)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if((dp[i][j])&&(L > max_len))
                    {
                        max_len = L;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
