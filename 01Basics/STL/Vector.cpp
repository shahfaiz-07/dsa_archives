#include<iostream>
#include<vector>
/*
    RESIZABLE ARRAYS
    Random access – constant O(1)
    Insertion or removal of elements at the end – constant O(1)
    Insertion or removal of elements – linear in the distance to the end of the vector O(N)
    Knowing the size – constant O(1)
    Resizing the vector- Linear O(N)
*/
#include<algorithm>
using namespace std;

template <class T>
void display(vector<T> &v) {
    if(v.size() == 0) {
        cout << "Empty Vector!!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    //INITIALISING A VECTOR :

    vector<int> v1; // vector with size 0;
    vector<pair<int, int>> vp;
    vector<int> v2(3); // vector with size 3
    // display(v2); - all ements are 0
    vector<int> v3(3, 4); // vector of size 3 with all initialised to 4
    vector<int> v4(v3); //vector initialised using other vector
    vector<int> v5 = {2, 5, 1, 7, 9, 0, 8}; // initialisation by values
    // display(v4);

    //-----------------------------------------------------------------------------------
    // MODIFIERS :
    //-----------------------------------------------------------------------------------

    //# push_back() – It push the elements into a vector from the back
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(8);
    vp.push_back({2,3});
    //display(v1);

    //# emplace_back() - Similar to push_back but considered faster
    v1.emplace_back(23847);
    vp.emplace_back(4,5);
    // for(pair<int, int> i : vp) {
    //     cout<< "{" << i.first << ", " << i.second << "} "; 
    // }
    // cout << endl;
    // display(v1);

    //# pop_back() – It is used to pop or remove elements from a vector from the back.
    v1.pop_back();
    //display(v1);

    //# assign() – It assigns new value to the vector elements by replacing old ones, also
    //            changes the size of the vector if necessary
    v1.assign(2, 3); // assigning 2 3's
    //display(v1);
    //cout << v1.size() << endl;
    int arr[] = {1, 2, 3, 4};
    v1.assign(arr + 1, arr + 4); // assigns 3 elements from array 'arr'(copying elements)
    //first argument will be pointer to first element and 2nd to last elements to be assigned
    // display(v1);

    //# insert() – It inserts new elements before the element at the specified position
    //** requires iterator

    v1.insert(v1.begin() + 1, 9); // inserts 9 at 2nd position
    //display(v1);
    v1.insert(v1.begin() + 2, 3, 100); // insert 3 100 in 3rd position
    //display(v1);
    // vector<int>::iterator it2 = v5.begin();
    // v1.insert(it + 1, it2 + 2, it2 + 4); // inserting a range of elements from another vector
    // display(v1);

    // # erase() – It is used to remove elements from a container from the specified position or range.
    v5.clear(); // removes all elements and makes size = 0
    // display(v5);
    v1.erase(v1.begin() + 1); // removing 2nd element
    // display(v1);

    v1.erase(v1.begin() + 2, v1.begin() + 5); // removing elements from 3rd to 5th position
    // display(v1);

    // # find() returns an iterator to find an element in the vector from between the specified position
    // ** contained in algorithm library
    auto it = find(v1.begin(), v1.end(), 100);
    if(it != v1.end())
        v1.erase(it);
    // display(v1);

    // # at() - similar to operator []
    // cout << v1.at(0);
    // # swap() - This function is used to swap the contents of one vector with another vector of 
    //          same type and sizes of vectors may differ.return 0;

    vector<int> v6{2, 5, 1, 6, 8};
    vector<int> v7{6, 1, 7, 32, 12, 15};
    // display(v6);
    // display(v7);
    v6.swap(v7);
    // display(v6);
    // display(v7);

    //-----------------------------------------------------------------------------------
    // CAPACITY :
    //-----------------------------------------------------------------------------------

    // # size() – Returns the number of elements in the vector.
    cout << v6.size() << endl;

    // # max_size() – Returns the maximum number of elements that the vector can hold.
    cout << v6.max_size() << endl;

    // # capacity() – Returns the size of the storage space currently allocated to the 
    //                  vector expressed as number of elements.
    cout << v6.capacity() << endl;

    // # resize(n) – Resizes the container so that it contains ‘n’ elements.
    v6.resize(9);
    // cout << v6.size() << endl;
    // display(v6);
    v6.resize(4);
    // cout << v6.size() << endl;
    // display(v6);

    // # empty() – Returns whether the container is empty.
    cout << v6.empty() << endl;
    v7.clear();
    cout << v7.empty() << endl;

    //-----------------------------------------------------------------------------------
    // ELEMENT ACCESS :
    //-----------------------------------------------------------------------------------

    /// # at() - similar to operator []
    cout << v6.at(2) << endl;

    // # front() – Returns a reference to the first element in the vector
    cout << v6.front() << endl;

    // # back() – Returns a reference to the last element in the vector
    cout << v6.back() << endl;

    // # data() – Returns a direct pointer to the memory array used internally by the 
    //              vector to store its owned elements.

    int *pos = v6.data();
    cout << *(pos + 1) << endl;
    }