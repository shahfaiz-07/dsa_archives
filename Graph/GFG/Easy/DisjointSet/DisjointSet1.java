

public class DisjointSet1 {
    // FOR GFG
    int find(int A[], int X) {
        //add code here.
        if (A[X] == X) {
            return X;
        }
        A[X] = find(A, A[X]);
        return A[X];
    }

    void unionSet(int A[], int X, int Z) {
        //add code here.
        int upX = find(A, A[X]), upZ = find(A, A[Z]);
        if (upX != upZ) {
            A[upX] = upZ;
        }
    }

    public static void main(String[] args) {
        DisjointSet ds = new DisjointSet(7);
        ds.unionBySize(1, 2);
        ds.unionBySize(2, 3);
        ds.unionBySize(4, 5);
        ds.unionBySize(6, 7);
        int up3 = ds.findParent(3), up7 = ds.findParent(7);
        if (up3 == up7) {
            System.out.println("Same");
        } else {
            System.out.println("Different");
        }
        ds.unionBySize(3, 7);
        up3 = ds.findParent(3);
        up7 = ds.findParent(7);
        if (up3 == up7) {
            System.out.println("Same");
        } else {
            System.out.println("Different");
        }
    }
}
// General Class
class DisjointSet {
    int parent[], rank[], size[];
    DisjointSet(int n) {
        parent = new int[n + 1];
        rank = new int[n + 1];
        size = new int[n + 1];
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int X) {
        if(parent[X] == X) {
            return X;
        }
        parent[X] = findParent(parent[X]);
        return parent[X];
    }
    void unionByRank(int X, int Y) {
        int upX = findParent(X), upY = findParent(Y);
        if(upX == upY) return;
        if(rank[upX] < rank[upY]) {
            parent[upX] = upY;
        } else if(rank[upX] > rank[upY]) {
            parent[upY] = upX;
        } else {
            parent[upY] = upX;
            rank[upY]++;
        }
    }
    void unionBySize(int X, int Y) {
        int upX = findParent(X), upY = findParent(Y);
        if (upX == upY)
            return;
        if(size[upX] < size[upY]) {
            parent[upX] = upY;
            size[upY] += size[upX];
        } else {
            parent[upY] = upX;
            size[upX] += size[upY];
        }
    }
}
