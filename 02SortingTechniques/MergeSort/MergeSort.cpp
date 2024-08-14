#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> lArr, rArr;
    for (int i = l; i <= m; i++)
    {
        lArr.push_back(arr[i]);
    }
    for (int i = m + 1; i <= r; i++)
    {
        rArr.push_back(arr[i]);
    }
    int lp = 0, rp = 0, k = l;
    while (lp < lArr.size() && rp < rArr.size())
    {
        if (lArr[lp] <= rArr[rp])
        {
            arr[k++] = lArr[lp++];
        }
        else
        {
            arr[k++] = rArr[rp++];
        }
    }
    while (lp < lArr.size())
    {
        arr[k++] = lArr[lp++];
    }
    while (rp < rArr.size())
    {
        arr[k++] = rArr[rp++];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2; // prevents integer overflow
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    mergeSort(arr, 0, arr.size() - 1);
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}