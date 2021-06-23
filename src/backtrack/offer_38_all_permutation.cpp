class Solution {
public:
    void swap(string& s, int x, int y)
    {
        char t = s[x];
        s[x] = s[y];
        s[y] = t;
    }
    void reverse(string& s, int start, int end)
    {
        while(start < end)
        {
            swap(s, start, end);
            start++;
            end--;
        }
    }
    bool next_permutation(string& s)
    {
        for(int i = s.size()-2; i >= 0; i--)
        {
            if(s[i] < s[i + 1])
            {
                for(int j = s.size()-1; j > i; j--)
                {
                    if(s[j] > s[i])
                    {
                        swap(s, i, j);
                        break;
                    }
                }
                reverse(s, i + 1, s.size()-1);
                return true;
            }
        }
        return false;
    }
    vector<string> permutation(string s) {
        vector<string> result;
        sort(s.begin(), s.end());
        result.push_back(s);
        while(next_permutation(s))
        {
            result.push_back(s);
        }
        return result;
    }
    vector<string> r;
    vector<bool> v;
    void dfs(string s, int i, int n, string &path)
    {
        if(i == n)
        {
            r.push_back(path);
            return;
        }
        for(int j = 0; j < s.size(); j++)
        {
            // 如果访问过;
            // 或者这是相同的字符(j>0)&&(s[j] == s[j-1])&&(!v[j])
            if(v[j])
            {
                continue;
            }
            if((j>0)&&(s[j] == s[j-1])&&!v[j-1])
            {
                continue;
            }
            path.push_back(s[j]);
            v[j] = true;
            dfs(s, i+1, n, path);
            path.pop_back();
            v[j] = false;
        }
    }
    vector<string> permutation2(string s) {
        string path;
        sort(s.begin(), s.end());
        v.resize(s.size());
        dfs(s, 0, s.size(), path);
        return r;
    }
};