#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[l]; // taking first element as pivot
    int i = l;
    int j = r;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= r - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= l + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}
int main(void)
{
    vector<int> arr = {1, 4, 5, 2, 3, 7, 8, 4, 0};
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    quickSort(arr, 0, arr.size() - 1);
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}