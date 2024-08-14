#include<iostream>
#include<list>
#include<vector>
/*
* It is generally implemented using a *dynamic doubly linked* list with traversal in both directions.
* Faster insert and delete operation as compared to arrays and vectors.
* It provides only sequential access. Random Access to any middle element is not possible
* It is defined as a template so it is able to hold any data type.
* It operates as an unsorted list would, which implies that by default, 
    the list’s order is not preserved. However, there are techniques for sorting.
*/
#include<algorithm>
using namespace std;

template <class T>
void display(list<T> &l) {

    for (auto it : l) {
        cout << it << " ";
    }
    cout << endl;
}

bool isequal(int a, int b) {
    return a == b;
}

bool isodd(int r) {
    return (r % 2 == 1);
}

int main() {
    //-----------------------------------------------------------------------------------
    // INITIALIZE :
    //-----------------------------------------------------------------------------------
    list<int> l1{1,2,3,4,5};
    // display(l1);
    list<int> l2;
    list<int> l3(3);
    list<int> l4(l1);
    // display(l4);
    list<int> l5(3, 5); // 3 5s
    // display(l5);

    //-----------------------------------------------------------------------------------
    // USEFUL FUNCTIONS :
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # front() – Returns the value of the first element in the list.
    // cout << l1.front() << endl;
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # back() – Returns the value of the last element in the list.
    // cout << l1.back() << endl;
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # push_front() – Adds a new element ‘g’ at the beginning of the list.
    l1.push_front(99);
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # push_back() – Adds a new element ‘g’ at the end of the list.
    l1.push_back(88);
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # pop_front() – Removes the first element of the list, and reduces the size of the list by 1.
    l1.pop_front();
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # pop_back() – Removes the last element of the list, and reduces the size of the list by 1.
    l1.pop_back();
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # insert() – Inserts new elements in the list before the element at a specified position.
    //          takes 3 elements, position(iterator), number of elements to insert and value to insert.

    list<int> :: iterator it = l1.begin();
    // # advance()
    advance(it, 2); // advances it to 3rd position
    l1.insert(it, 5); // inserts 5 at 3rd position
    // display(l1);
    l1.insert(it, 3, 9); // inserts 3 9s at 4th position
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # size() – Returns the number of elements in the list.
    // cout << l1.size() << endl;
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    /*
    # begin() – begin() function returns an iterator pointing to the first element of the list.

    # end() – end() function returns an iterator pointing to the theoretical last
                    element which follows the last element.
    */

    // for (auto it1 = l1.begin(); it1 != l1.end(); advance(it1, 1)) {
    //     cout << *it1 << " ";
    // }
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    /*

     # rbegin()  - rbegin() returns a reverse iterator which points to the last
                element of the list.
     # rend()   - rend() returns a reverse iterator that points to the
                position before the beginning of the list.

    */

    // display(l1);
    // for (auto it1 = l1.rbegin(); it1 != l1.rend(); ++it1) {
    //     cout << *it1 << " ";
    // }
    

    /*
    rend begin                        rbegin end
           1    2   3   4   5   6   7   8
    */
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # empty() - Returns whether the list is empty(1) or not(0).

    // cout << l1.empty() << endl;
    // cout << l2.empty() << endl;
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # erase() - a built-in function in C++ STL which is used to delete elements from a list
    //      container. This function can be used to remove a single element or a range of
    //      elements from the specified list container

    // display(l1);
    l1.erase(find(l1.begin(), l1.end(), 9)); // erasing first occurence of 9
    // display(l1);

    list<int>::iterator it1 = l1.begin();
    list<int>::iterator it2 = l1.begin();
    advance(it1, 2);
    advance(it2, 5);
    // display(l1);
    l1.erase(it1, it2); // erasing 3rd to 5th element
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # assign() - Assigns new elements to the list by replacing current elements and resizing the list.

    vector<int> v1{2, 3, 1, 5, 6};
    l3.assign(v1.begin(), v1.end());
    // display(l3);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # remove() - Removes all the elements from the list, which are equal to a given element.

    l1.push_back(4);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(5);
    // display(l1);
    l1.remove(5);
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # remove_if() - Used to remove all the values from the list that correspond true to the
    // predicate or condition given as a parameter to the function.

    // display(l1);
    l1.remove_if(isodd);
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # reverse() - Reverses the list.

    l1.assign(v1.begin(), v1.end());
    // display(l1);
    l1.reverse();
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # sort()	- Sorts the list in increasing order.

    l1.sort();
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # unique() - Removes all duplicate consecutive elements from the list.

    l1.push_back(4);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(5);
    // display(l1);
    l1.unique();
    // display(l1);

    l1.sort();
    // display(l1);
    l1.unique();
    // display(l1);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # swap() - This function is used to swap the contents of one list with another list of
    //              the same type and size.

    // 1. It throws an error if the lists are not of the same type.
    // 2. It throws an error if the lists are not of the same size.
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # splice() - Used to transfer elements from one list to another.

    // display(l5);
    list<int>::iterator itl5 = l5.begin();
    advance(itl5, 2);
    list<int>::iterator it_l1_1 = l1.begin(), it_l1_2 = l1.begin();
    advance(it_l1_1, 1);
    advance(it_l1_2, 4);
    l5.splice(itl5, l1, it_l1_1, it_l1_2); // if only 1 iterator is passed from 2nd list, only that item is inserted
    // display(l5);

    // display(l1);
    // display(l5);
    // # appending list into another
    // l5.splice(l5.end(), l1, l1.begin(), l1.end());
    // display(l5);
    //-----------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------
    // # merge() - Merges two sorted lists into one.
    l1.sort();
    l5.sort();
    // display(l1);
    // display(l5);
    // l1.merge(l5); - no 2nd argument given so the list is merged and sorted in ascending order
    // display(l1);

    // l1.merge(l5, isequal);
    display(l1);
    //-----------------------------------------------------------------------------------
    return 0;
}