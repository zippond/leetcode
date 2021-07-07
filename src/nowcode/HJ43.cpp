/*
    迷宫问题
*/

#include <iostream>
#include <vector>
using namespace std;

int m, n;

void find(vector<vector<int>>& maze, vector<vector<int>>& best_path, vector<vector<int>>& tmp_path, int x, int y)
{
    /* 当前 maze[x][y] 不可能为1 */
    maze[x][y] = 1;
    tmp_path.push_back({x, y});
    if(( x == (m-1)) && (y == (n - 1))) // 到达终点
    {
        if((best_path.empty())||(tmp_path.size() < best_path.size()))
        {
            best_path = tmp_path;
        }
        /* 可以退出 */
        maze[x][y] = 0;
        tmp_path.pop_back();
        return;
        
    }

    /* 否则，找下一步 */
    if((x < (m - 1)) && (maze[x+1][y] == 0)) // 向右
    {
        find(maze, best_path, tmp_path, x+1, y);
    }
    if((x > 0) && (maze[x - 1][y] == 0)) // 向左
    {
        find(maze, best_path, tmp_path, x - 1, y);
    }
    if(( y > 0 ) && (maze[x][y - 1] == 0)) // 向上
    {
        find(maze, best_path, tmp_path, x, y - 1);
    }
    if((y < (n - 1)) && (maze[x][y + 1] == 0)) // 向下
    {
        find(maze, best_path, tmp_path, x, y + 1);
    }

    /* 撤销当前操作 */
    maze[x][y] = 0;
    tmp_path.pop_back();
}
int main(int argc, char **argv)
{
    while(cin>>m>>n)
    {
        vector<vector<int>> maze(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>maze[i][j];
            }
        }
        vector<vector<int>> best_path, tmp_path;
        find(maze, best_path, tmp_path, 0, 0);
        for(int i = 0; i < best_path.size(); i++)
        {
            cout<<"("<<best_path[i][0]<<","<<best_path[i][1]<<")"<<endl;
        }
    }
}