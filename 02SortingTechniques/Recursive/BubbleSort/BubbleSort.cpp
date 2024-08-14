#include<bits/stdc++.h>
using namespace std;
void swapElements(vector<int> &arr, int start, int index) {
    if(index == arr.size() - start - 1) {
        return;
    }
    if(arr[index] > arr[index + 1]) {
        swap(arr[index], arr[index + 1]);
    }
    swapElements(arr, start, index + 1);
}
void bubbleSort(vector<int> &arr, int index) {
    if(index == arr.size() - 1) {
        return;
    }
    swapElements(arr, index, 0);
    bubbleSort(arr, index + 1);
}
int main(void) {
    vector<int> arr = {1, 4, 5, 2, 3, 7, 8, 4, 0};
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    bubbleSort(arr, 0);
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}