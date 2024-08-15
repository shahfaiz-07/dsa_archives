#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        bool swapped = false; // check for already sorted array
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!swapped)
        {
            break;
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
    bubbleSort(arr);
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}