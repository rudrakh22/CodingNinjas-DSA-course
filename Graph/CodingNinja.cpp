#include <iostream>
#include <vector>
using namespace std;
bool validPoint(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}
bool dfs(vector<vector<char>> &board, vector<vector<bool>> &used, string &s, int x, int y, int wordIndex, int n, int m)
{
    if (wordIndex == 11)
    {
        return true;
    }
    used[x][y] = true;
    bool found = false;
    int matrix[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < 8; i++)
    {
        int newX = x + matrix[i][0];
        int newY = y + matrix[i][1];
        if (validPoint(newX, newY, n, m) && board[newX][newY] == s[wordIndex] && !used[newX][newY])
        {
            found = dfs(board, used, s, newX, newY, wordIndex + 1, n, m);
            if (found)
            {
                return found;
            }
        }
    }
    used[x][y] = false;
    return found;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
    string s = "CODINGNINJA";
    bool foundPath = false;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[0] == board[i][j])
            {
                foundPath = dfs(board, visited, s, i, j, 1, n, m);
                if (foundPath)
                    return foundPath;
            }
        }
    }
    return foundPath;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}