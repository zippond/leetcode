class Solution
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