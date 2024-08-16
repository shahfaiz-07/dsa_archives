// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include<bits/stdc++.h>
using namespace std;
void travel(vector<vector<int>> &mat, int i, int j, vector<string> &paths, string path)
{
    if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] == 0)
    {
        return;
    }
    if (i == mat.size() - 1 && j == mat[0].size() - 1)
    {
        paths.push_back(path);
        return;
    }
    mat[i][j] = 0; // mark visited
    // down
    travel(mat, i + 1, j, paths, path + "D");
    // up
    travel(mat, i - 1, j, paths, path + "U");
    // left
    travel(mat, i, j - 1, paths, path + "L");
    // right
    travel(mat, i, j + 1, paths, path + "R");
    mat[i][j] = 1; // unmark
}

vector<string> findPath(vector<vector<int>> &mat)
{
    // Your code goes here
    vector<string> paths;
    travel(mat, 0, 0, paths, "");
    return paths;
}
int main(void) {
    vector<vector<int>> mat = { {1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1} };
    vector<string> paths = findPath(mat); 
    for(string ele: paths) {
        cout << ele << " ";
    }
    return 0;
}