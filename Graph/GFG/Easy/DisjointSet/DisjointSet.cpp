// https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1
#include<bits/stdc++.h>
using namespace std;
// FOR GFG
int find(int A[], int X)
{
    if (A[X] == X)
        return X;
    return A[X] = find(A, A[X]);
}
void unionSet(int A[], int X, int Z)
{
    int upX = find(A, A[X]), upZ = find(A, A[Z]);
    if (upX != upZ)
        A[upX] = upZ;
}

// General Class
class DisjointSet {
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int x, int y) {
        int upX = findParent(x), upY = findParent(y);
        if(upX == upY) return; // same component
        if(rank[upX] < rank[upY]) {
            parent[upX] = upY;
        }
        else if (rank[upX] > rank[upY]) {
            parent[upY] = upX;
        } else {
            parent[upY] = upX;
            rank[upX]++;
        }
    }

    void unionBySize(int x, int y) {
        int upX = findParent(x), upY = findParent(y);
        if (upX == upY)
            return; // same component
        if(size[upX] < size[upY]) {
            parent[upX] = upY;
            size[upY] += size[upX];
        } else {
            parent[upY] = upX;
            size[upX] += size[upY];
        }
    }
};
int main(void) {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    int up3 = ds.findParent(3), up7 = ds.findParent(7);
    if(up3 == up7) {
        cout << "Same\n";
    } else {
        cout << "Different\n";
    }
    ds.unionBySize(3, 7);
    up3 = ds.findParent(3); up7 = ds.findParent(7);
    if (up3 == up7)
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Different\n";
    }
    return 0;
}