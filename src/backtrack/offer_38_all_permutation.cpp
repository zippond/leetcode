class Solution {
public:
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
    vector<string> permutation(string s) {
        string path;
        sort(s.begin(), s.end());
        v.resize(s.size());
        dfs(s, 0, s.size(), path);
        return r;
    }
};