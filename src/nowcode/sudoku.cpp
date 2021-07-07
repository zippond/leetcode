#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isValid(vector<vector<int>>& tmp, int cell, int num, int n, int cubrow, int cubcol)
{
    int row = cell/n;
    int col = cell%n;
    for(int i = 0; i < n; i++)
    {
        if(tmp[row][i] == num)
        {
            if(i != col)
            {
                cout<<"failed row"<<endl;
                return false;
            }
        }
        if(tmp[i][col] == num)
        {
            if(i != row )
            {
                cout<<"failed col"<<endl;
                return false;
            }
        }
    }

    int row_head = row/cubrow*cubrow;
    int col_head = col/cubcol*cubcol;

    for(int i = row_head; i < (row_head + cubrow);i++ )
    {
        for(int j = col_head; j< (col_head + cubcol);j++)
        {
            if(tmp[i][j] == num)
            {
                if(!((i == row)&&(j == col)))
                {
                    cout<<"failed rec"<<endl;
                    return false;
                }
            }
        }
    }
    return true;
}
void resolve(vector<vector<vector<int>>>& result, vector<vector<int>>& tmp,
             int cell, int n, int cubrow, int cubcol)
{
    if(cell == n*n ) // 最后一个格子已填完
    {
        result.push_back(tmp);
        return;
    }
    if(!tmp[cell/n][cell%n])
    {
        cout<<"Cell "<<cell<<" is needed"<<endl;
        for(int i = 1; i <=n; i++)
        {
            if(isValid(tmp, cell, i, n, cubrow, cubcol))
            {
                cout<<"Cell "<<cell<<" "<<i <<" is OK"<<endl;
                tmp[cell/n][cell%n] = i;
                resolve(result, tmp, cell+1, n, cubrow, cubcol);
                tmp[cell/n][cell%n] = 0;
            }
            else
            {
                cout<<"Cell "<<cell<<" "<<i <<" is Failed"<<endl;
            }
        }
    }
    else //重点！！！
    {
        resolve(result, tmp, cell+1, n, cubrow, cubcol);
    }
}

int main(int argc, char ** argv)
{
    int n, cubrow, cubcol;
    while(cin>>n>>cubrow>>cubcol)
    {
        vector<vector<int>> nums(n,vector<int>(n));
        for(int i = 0; i < n;i++)
        {
            for(int j = 0; j < n;j++)
            {
                cin>>nums[i][j];
            }
        }
        vector<vector<vector<int>>> result;
        resolve(result, nums, 0, n, cubrow, cubcol);
        for(int i = 0; i < result.size();i++)
        {
            cout<<"Result "<<i<<endl;
            for(int j = 0; j < result[i].size();j++)
            {
                for(int k = 0; k < result[i][j].size();k++)
                {
                    cout<<result[i][j][k]<<" ";
                }
                cout<<endl;
            }
        }
        cout<<"ABC"<<endl;

    }
    return 0;
}
