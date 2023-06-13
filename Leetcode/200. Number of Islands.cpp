#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*******************************************************************************************************************************
 * First Attempt - Mark island land based on nearby "1" 
 ********************************************************************************************************************************/
class Attemp1 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0, real = 0;
        int mat[grid.size()][grid[0].size()];
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                mat[i][j] = 0;
            }
        }
        unordered_map<int, unordered_map<int, bool>> huh;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '0') continue;
                if (mat[i][j] == 0)
                {
                    bool new_check = true;
                    count++; real++;
                    mat[i][j] = count;
                    // Right
                    if (j < grid[i].size() - 1 && grid[i][j + 1] == '1')
                    {
                        if (mat[i][j + 1] == 0)
                        {
                            mat[i][j + 1] = count;
                        }
                        else
                        {
                            count--; real--; new_check = false;
                            mat[i][j] = mat[i][j + 1];
                        }
                    }
                    // Under
                    if (i < grid.size() - 1 && grid[i + 1][j] == '1')
                    {
                        mat[i + 1][j] = count;
                    }
                    if (new_check)
                    {
                        unordered_map<int, bool> bruh;
                        huh.insert(make_pair(count, bruh));
                    }
                }
                else if (mat[i][j] != 0)
                {
                    // Right
                    if (j < grid[i].size() - 1 && grid[i][j + 1] == '1')
                    {
                        if (mat[i][j + 1] == 0)
                        {
                            mat[i][j + 1] = mat[i][j];
                        }
                        else if (mat[i][j + 1] != mat[i][j])
                        {
                            if (huh.at(mat[i][j]).find(mat[i][j + 1]) == huh.at(mat[i][j]).end() &&
                                huh.at(mat[i][j + 1]).find(mat[i][j]) == huh.at(mat[i][j + 1]).end())
                            {
                                huh.at(mat[i][j]).insert(huh.at(mat[i][j + 1]).begin(), huh.at(mat[i][j + 1]).end());
                                huh.at(mat[i][j + 1]).insert(huh.at(mat[i][j]).begin(), huh.at(mat[i][j]).end());
                                huh.at(mat[i][j]).insert(make_pair(mat[i][j + 1], false));
                                huh.at(mat[i][j + 1]).insert(make_pair(mat[i][j], false));
                                real--;
                            }
                        }
                    }
                    // Under
                    if (i < grid.size() - 1 && grid[i + 1][j] == '1')
                    {
                        mat[i + 1][j] = mat[i][j];
                    }
                }
            }
        }
        return real;
    }
};

/*******************************************************************************************************************************
 * Second Attempt - BFS or DFS to "clear" the island to "0"
 ********************************************************************************************************************************/
class Attempt2
{
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    // BFS to find and replace island with '0'
                    queue<pair<int, int>> pq;
                    pq.push(make_pair(i, j));
                    while(!pq.empty())
                    {
                        pair<int, int> curr = pq.front(); pq.pop();
                        grid[curr.first][curr.second] = '0';
                        if (curr.first  > 0                  && grid[curr.first - 1][curr.second] == '1') pq.push(make_pair(curr.first - 1, curr.second));
                        if (curr.first  < grid.size() - 1    && grid[curr.first + 1][curr.second] == '1') pq.push(make_pair(curr.first + 1, curr.second));
                        if (curr.second > 0                  && grid[curr.first][curr.second - 1] == '1') pq.push(make_pair(curr.first, curr.second - 1));
                        if (curr.second < grid[i].size() - 1 && grid[curr.first][curr.second + 1] == '1') pq.push(make_pair(curr.first, curr.second + 1));
                    }
                }
            }
        }
        return count;
    }
};


int main()
{
    vector<vector<char>> grid ={{'0','1','1','1','1','0','0','1','0','1','1','1','1','1','1','0','0','1','1','0'},
                                {'0','0','0','0','0','0','1','0','1','0','1','0','0','1','1','0','0','0','1','0'},
                                {'0','1','0','1','0','1','0','1','0','0','1','1','1','0','0','0','0','0','0','1'},
                                {'1','0','0','1','1','1','1','1','0','1','0','0','0','0','1','0','1','0','1','0'},
                                {'0','1','0','0','0','0','1','0','0','0','0','1','0','0','1','0','1','1','1','0'},
                                {'0','0','0','0','0','0','0','1','0','1','1','0','0','1','1','0','0','1','0','1'},
                                {'0','0','1','1','1','1','0','1','1','1','1','0','0','0','1','0','1','0','1','1'},
                                {'1','1','1','1','0','0','1','0','1','0','0','0','0','0','0','1','1','1','0','1'},
                                {'1','0','0','0','1','1','0','0','1','0','1','1','0','0','0','1','0','0','0','0'},
                                {'1','0','0','1','0','1','0','1','0','0','1','1','1','0','0','0','0','0','1','0'},
                                {'0','0','0','1','0','0','1','0','0','0','0','0','0','1','0','1','0','0','1','1'},
                                {'0','1','0','0','1','1','1','0','1','1','1','0','0','0','1','0','1','0','0','0'},
                                {'1','1','1','0','1','1','0','1','0','1','0','1','1','0','0','0','1','0','0','0'},
                                {'0','1','1','0','1','0','0','1','1','0','1','1','0','1','1','0','1','1','0','0'},
                                {'0','1','1','0','0','1','0','0','0','1','0','1','0','0','0','0','0','0','1','1'},
                                {'0','0','1','0','0','0','1','1','0','1','1','1','1','0','1','0','1','0','1','0'},
                                {'1','0','0','0','1','0','1','0','1','0','0','0','0','1','1','0','0','0','0','0'},
                                {'1','0','0','1','1','0','0','1','1','0','0','0','1','0','0','0','1','1','1','0'},
                                {'0','1','0','1','1','0','0','0','1','1','0','0','1','1','1','0','0','1','1','0'},
                                {'0','0','1','0','1','0','0','0','0','0','0','0','0','1','0','1','0','0','1','0'}}
    Attemp1 a;
    cout << a.numIslands(grid);
}