#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

template <class T>
void display(vector<T> &v) {
    for(auto it : v) {
        cout << it << " ";
    }
    cout << endl;
}

bool iseven(int n) {
    return n % 2 == 0;
}

bool comparator(pair<int, int> p1, pair<int, int> p2) {
    // assuming p1 lies before p2
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false; //swap them
    if(p1.first >= p2.second) return true;
    return false;
}

int main() {
    vector<int> v1{2, 4, 1, 0, 9, 4};
    // display(v1);

    //-----------------------------------------------------------------------------------
    // MODIFYING FUNCTIONS :
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    /*
    # sort() - It generally takes two parameters, the first one being the point of the array/vector
            from where the sorting needs to begin and the second parameter being the length up to
            which we want the array/vector to get sorted. The third parameter is optional and can
            be used in cases such as if we want to sort the elements lexicographically.

    */

    sort(v1.begin() + 1, v1.begin() + 5);
    // display(v1);

    // sorting in descending order
    sort(v1.begin(), v1.end(), greater<int>());
    // display(v1);

    /*
    Best Case – O(N log N)
    Average Case – O(N log N)
    Worst-Case – O(N log N)
    */

    // sorting in our 'own way'
    // sort(v1.begin(), v1.end(), comparator) // nothing but a boolean comparator
    // eg - sorting an array of pairs in order of increasing 2nd element and if the 2nd element is same then sort it according to the decreasing order of the first element
    vector<pair<int, int>> vp;
    vp.push_back({1, 2});
    vp.push_back({3, 1});
    vp.push_back({4, 5});
    vp.push_back({2, 2});
    vp.push_back({4, 2});

    sort(vp.begin(), vp.end(), comparator);
    cout << "Comparator :\n";
    for(auto i: vp) {
        cout << i.first << ", " << i.second << endl; 
    }

    //-----------------------------------------------------------------------------------

    // #__builtin_popcount() - return number of set bits(1s) in the binary equivalent of the number
    // 7 -> 3, 6 -> 2
    cout << "10->" << __builtin_popcount(10)<< endl;

    // if the number if long long then the function will change to __builtin_popcountll()

    //-----------------------------------------------------------------------------------
    // # reverse() - It reverses the order of the elements in the range [first, last) of any container.
    // display(v1);
    reverse(v1.begin() + 1, v1.begin() + 5);
    // display(v1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # copy() - copy a range of elements, overwrites previous elements from specified position
    vector<int> v2{1, 2, 3, 5, 6, 8, 10};
    // display(v1);
    // display(v2);
    // copy(from vector's start, from vector's end, to vector's start)
    copy(v2.begin() + 1, v2.begin() + 4, v1.begin() + 1);
    // display(v1);
    // display(v2);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # copy_if() - this function copies according to the result of a “condition“. This
    //          is provided with the help of a 4th argument, a function returning a
    //              boolean value.

    vector<int> v3(v2.size());
    copy_if(v2.begin(), v2.end(), v3.begin(), iseven);
    // display(v3);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # replace() - Assigns new_value to all the elements in the range [first, last) that compare to old_value.
    // display(v3);
    replace(v3.begin(), v3.end(), 0, 99);
    // display(v3);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # replace_if() - Assigns new_value to all the elements in range [first, last) for which pred returns true.
    // display(v3);
    replace_if(v3.begin(), v3.end(), iseven, -99);
    // display(v3);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # fill() - The ‘fill’ function assigns the value ‘val’ to all the elements in the
    //      range [begin, end), where ‘begin’ is the initial position and ‘end’ is the last position.
    // display(v3);
    fill(v3.begin() + 2, v3.begin() + 5, 100);
    // display(v3);

    //-----------------------------------------------------------------------------------
    // # remove() - It removes value from range. Transforms the range [first,last) into a range
    //                  with all the elements that compare equal to val removed and returns an 
    //                          iterator to the new end of that range.
    // display(v3);
    auto newend = remove(v3.begin(), v3.end(), 100);
    // for (auto it = v3.begin(); it != newend; it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // #*max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
    // NOTE : The '*' is important
    // display(v1);
    // cout << *max_element(v1.begin(), v1.end());
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // #*min_element (...);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // #accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation
    //                                  of vector elements return 0;
    // NOTE : Present in the 'numeric' library
    // display(v1);
    // cout << accumulate(v1.begin(), v1.end(), 0);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // find(first_iterator, last_iterator, x) – Returns an iterator to the first occurrence of x
    //  in vector and points to last address of vector ((name_of_vector).end())
    //                     if element is not present in vector.

    // display(v1);
    auto it1 = find(v1.begin(), v1.end(), 5);
    auto it2 = find(v1.begin(), v1.end(), 9);
    // display(v1);
    // if(it1 != v1.end()) {
    //     cout << *it1 << " Found" << endl;
    // } else {
    //     cout << 5 << " Not Found" << endl;
    // }
    // if (it2 != v1.end()) {
    //     cout << *it1 << " Found" << endl;
    // } else {
    //     cout << 9 << " Not Found" << endl;
    // }
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # binary_search(first_iterator, last_iterator, x) – Tests whether x exists in sorted 
    //                              vector or not.
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to
    // the first element in the range [first,last) which has a value not less than ‘x’. ">="
    // display(v1);
    // cout << *lower_bound(v1.begin(), v1.end(), 0) << endl;
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the
    // first element in the range [first,last) which has a value greater than ‘x’.
    // display(v1);
    // cout << *upper_bound(v1.begin(), v1.end(), 0) << endl;
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // #next_permutation(first_iterator, last_iterator) – This modified the vector to its next 
    //                                      permutation.
    // vector<int> vp{1, 2, 3};
    // for (int i = 1; i <= 6; i++) {
    //     display(vp);
    //     next_permutation(vp.begin(), vp.end());
    // }
    string s = "231"; // 231, 312, 321
    // HENCE TO GET ALL PERMUTATIONS YOU CAN START FROM SORTED 
    do {
        cout<< s << endl;
    }while(next_permutation(s.begin(), s.end()));
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # prev_permutation(first_iterator, last_iterator) – This modified the vector to its
    //                                      previous permutation.
    // vector<int> vp{1, 2, 3};
    // for (int i = 1; i <= 6; i++) {
    //     display(vp);
    //     prev_permutation(vp.begin(), vp.end());
    // }
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # distance(first_iterator,desired_position) – It returns the distance of desired
    // position from the first iterator. This function is very useful while finding the index.
    // display(v1); 
    // int dist = distance(v1.begin(), min_element(v1.begin(), v1.end()));
    // cout << "Distance between 1st to Minimum Element :" << dist << endl;
    //-----------------------------------------------------------------------------------
}