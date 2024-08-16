// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
#include <bits/stdc++.h>
using namespace std;
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> uni;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            if (uni.size() == 0 || uni[uni.size() - 1] != arr1[i])
                uni.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i] == arr2[j])
        {
            if (uni.size() == 0 || uni[uni.size() - 1] != arr1[i])
                uni.push_back(arr1[i]);
            i++;
            j++;
        }
        else
        {
            if (uni.size() == 0 || uni[uni.size() - 1] != arr2[j])
                uni.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n)
    {
        if (uni.size() == 0 || uni[uni.size() - 1] != arr1[i])
            uni.push_back(arr1[i]);
        i++;
    }
    while (j < m)
    {
        if (uni.size() == 0 || uni[uni.size() - 1] != arr2[j])
            uni.push_back(arr2[j]);
        j++;
    }
    return uni;
}
int main(void)
{
    int arr1[] = {-5, -4, -1, 1, 7};
    int arr2[] = {-3, 0, 1, 8};
    vector<int> uni = findUnion(arr1, arr2, 5, 4);
    for(int i: uni) {
        cout << i << " ";
    }
    return 0;
}