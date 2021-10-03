class Solution {
public:
    int count;
    int totalNQueens(int n) {
        count = 0;
        vector<vector<int>> path(n, vector<int>(n));
        find(path, n, 0);
        return count;
    }
    void find(vector<vector<int>>& tmp, int n, int row)
    {
        if(row == n)
        {
            count++;
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(valid(tmp, n, row, i))
            {
                tmp[row][i] = 1;
                find(tmp, n, row + 1);
                tmp[row][i] = 0;
            }
        }
    }
    bool valid(vector<vector<int>>& path, int n, int row, int col)
    {
        for(int i = 1;((row - i)>= 0)&&((col -i)>= 0);i++)
        {
            if(path[row-i][col-i]) return false;
        }
        for(int i = 1; ((row-i)>= 0)&&((col+i)<n); i++)
        {
            if(path[row-i][col+i]) return false;
        }
        for(int i = 0; i < row; i++)
        {
            if(path[i][col]) return false;
        }
        return true;
    }
};