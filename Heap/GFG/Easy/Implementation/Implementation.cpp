// https://www.geeksforgeeks.org/problems/implementation-of-priority-queue-using-binary-heap/1
#include<bits/stdc++.h>
using namespace std;
int H[10009];
int s = -1;
int parent(int i)
{
    return (i - 1) / 2;
}
int leftChild(int i)
{
    return ((2 * i) + 1);
}
int rightChild(int i)
{
    return ((2 * i) + 2);
}
void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i])
    {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}
void shiftDown(int i)
{
    int maxIndex = i;
    int l = leftChild(i);

    if (l <= s && H[l] > H[maxIndex])
    {
        maxIndex = l;
    }
    int r = rightChild(i);

    if (r <= s && H[r] > H[maxIndex])
    {
        maxIndex = r;
    }
    if (i != maxIndex)
    {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}
void insert(int p)
{
    s = s + 1;
    H[s] = p;
    shiftUp(s);
}
// -------------------------------------------------------
class Solution
{
public:
    int extractMax()
    {
        // your code here
        int maxi = H[0];
        H[0] = H[s];
        s--;
        shiftDown(0);
        return maxi;
    }
};

// -------------------------------------------------------
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            insert(k);
        }

        Solution ob;

        cout << "Node with maximum priority : " << ob.extractMax() << "\n";
        cout << "Priority queue after "
             << "extracting maximum : ";
        int j = 0;
        while (j <= s)
        {
            cout << H[j] << " ";
            j++;
        }
        cout << "\n";

        cout << "~" << "\n";
    }
    return 0;
}