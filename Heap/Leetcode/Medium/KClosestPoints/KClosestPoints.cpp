// https://leetcode.com/problems/k-closest-points-to-origin/
#include<bits/stdc++.h>
using namespace std;
// Through Manual Heap Creation - O(k) extra space
double magnitude(vector<int> &point)
{
    return sqrt(point[0] * point[0] + point[1] * point[1]);
}
int parent(int index) { return (index - 1) / 2; }
int leftChild(int index) { return 2 * index + 1; }
int rightChild(int index) { return 2 * index + 2; }

void insert(vector<vector<int>> &heap, vector<int> &val)
{
    heap.push_back(val);
    int index = heap.size() - 1;

    while (index > 0 && magnitude(heap[parent(index)]) < magnitude(heap[index]))
    {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}
void minHeapify(vector<vector<int>> &heap, int index)
{
    int largest = index;
    int lc = leftChild(index), rc = rightChild(index);
    if (lc < heap.size() && magnitude(heap[lc]) > magnitude(heap[largest]))
    {
        largest = lc;
    }
    if (rc < heap.size() && magnitude(heap[rc]) > magnitude(heap[largest]))
    {
        largest = rc;
    }
    if (index != largest)
    {
        swap(heap[index], heap[largest]);
        minHeapify(heap, largest);
    }
}
void remove(vector<vector<int>> &heap)
{
    if (heap.size() == 0)
        return;
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if (heap.size() > 0)
    {
        minHeapify(heap, 0);
    }
}
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> ans;
    for (int i = 0; i < k; i++)
    {
        insert(ans, points[i]);
    }

    for (int i = k; i < points.size(); i++)
    {
        if (magnitude(points[i]) < magnitude(ans[0]))
        {
            remove(ans);
            insert(ans, points[i]);
        }
    }

    return ans;
}

// USING STL priority_queue - O(2*k) extra space and also O(klog(k)) extra time for removing all elements from heap
class info
{
public:
    int x, y;
    info(int x1, int y1) : x(x1), y(y1) {}
};
double magnitude(int x, int y)
{
    return sqrt(x * x + y * y);
}
class compare
{
public:
    bool operator()(info *a, info *b)
    {
        return magnitude(a->x, a->y) < magnitude(b->x, b->y);
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<info *, vector<info *>, compare> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(new info(points[i][0], points[i][1]));
    }

    for (int i = k; i < points.size(); i++)
    {
        int x = points[i][0], y = points[i][1];
        if (magnitude(x, y) < magnitude(pq.top()->x, pq.top()->y))
        {
            pq.pop();
            pq.push(new info(x, y));
        }
    }
    vector<vector<int>> ans;
    while (!pq.empty())
    {
        ans.push_back({pq.top()->x, pq.top()->y});
        pq.pop();
    }
    return ans;
}
int main(void) {
    
    return 0;
}