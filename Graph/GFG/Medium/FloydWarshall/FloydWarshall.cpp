// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
#include<bits/stdc++.h>
using namespace std;
void shortest_distance(vector<vector<int>> &matrix)
{
    // Code here
    for (int via = 0; via < matrix.size(); via++)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (i == via || j == via || matrix[i][via] == -1 || matrix[via][j] == -1)
                    continue;
                int viaDist = matrix[i][via] + matrix[via][j];
                if (matrix[i][j] == -1 || matrix[i][j] > viaDist)
                {
                    matrix[i][j] = viaDist;
                }
            }
        }
    }
}
int main(void) {
    
    return 0;
}