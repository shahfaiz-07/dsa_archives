#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int s = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[s])
            {
                s = j;
            }
        }
        if (s != i) // check if the current element is the smallest
        {
            // swap(arr[i], arr[s]);
            int t = arr[i];
            arr[i] = arr[s];
            arr[s] = t;
        }
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
    selectionSort(arr);
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}