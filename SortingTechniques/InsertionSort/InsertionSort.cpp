#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i - 1, curr = arr[i];
        while (j >= 0 && curr < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
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
    insertionSort(arr);
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}