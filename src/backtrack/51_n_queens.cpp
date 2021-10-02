class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<int>> tmp(n, vector<int>(n, 0));
        int cur = 0;
        find(result, tmp, n, cur);
        return result;
    }
    vector<string> format(vector<vector<int>>& p)
    {
        vector<string> ret;
        
        for(int i = 0; i < p.size(); i++)
        {
            string t;
            
            for(int j = 0; j < p.size(); j++)
            {
                t.push_back(p[i][j]?'Q':'.');
            }
            ret.push_back(t);
        }
        return ret;
    }
    void find(vector<vector<string>> &r, vector<vector<int>> &path, int rows, int cur)
    {
        //cout<<"Cur "<<cur<<endl;
        if(cur == rows)
        {
            //cout<<"Find"<<endl;
            r.push_back(format(path));
            return;
        }
        for(int i = 0; i < rows ;i++)
        {
            
            if(valid(path, rows, cur, i))
            {
                path[cur][i] = 1;
                find(r, path, rows, cur+1);
                path[cur][i] = 0;
            }

            
        }
    }
    bool valid(vector<vector<int>>& tmp, int n, int currow, int col)
    {
        //cout<<"row:"<<currow<<":col:"<<col<<endl;
        // 左上，右上，上
        for(int i = 1; ((currow - i)>= 0)&&((col-i) >= 0);i++)
        {
            if(tmp[currow-i][col-i]) return false;
        }

        for(int i = 1; ((currow - i) >= 0)&&((col+i)< n); i++)
        {
            if(tmp[currow - i][col + i]) return false;
        }
        for(int i = 0; i < currow; i++)
        {
            if(tmp[i][col]) return false;
        }

        return true;
    }
};