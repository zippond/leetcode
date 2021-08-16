class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idx[128] = {0};
        int head = 0, last_pos = 0, len = 0;
        for(int i = 0; i < s.size();i++)
        {
            last_pos = idx[s[i]- '\0'];
            if(last_pos > head) // 出现过
            {
                head = last_pos;
            }
            else
            {
                len = max(len, i - head + 1);
            }
            idx [s[i] - '\0'] = i+1;
        }
        return len;
    }
};