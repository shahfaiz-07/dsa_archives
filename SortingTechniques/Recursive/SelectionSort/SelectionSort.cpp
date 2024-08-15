#include <bits/stdc++.h>
using namespace std;

int findSmallest(vector<int> &arr, int start, int smallestIndex)
{
    if (start == arr.size())
    {
        return smallestIndex;
    }
    smallestIndex = arr[smallestIndex] < arr[start] ? smallestIndex : start;
    return findSmallest(arr, start + 1, smallestIndex);
}
void selectionSort(vector<int> &arr, int index)
{
    if (index == arr.size())
    {
        return;
    }
    int s = findSmallest(arr, index, index);
    if (s != index)
    {
        swap(arr[s], arr[index]);
    }
    selectionSort(arr, index + 1);
}
int main(void)
{
    vector<int> arr = {7, 4, 2, 7, 2, 1, 5, 3};
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    selectionSort(arr, 0);
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}