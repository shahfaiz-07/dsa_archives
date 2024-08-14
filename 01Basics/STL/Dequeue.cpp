#include<iostream>
#include<deque>
using namespace std;
/*
    The functions for deque are same as vector, with an addition of push and pop operations 
    for both front and back.
*/

template <class T>
void display(deque<T> dq) {
    for(int i : dq) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    //-----------------------------------------------------------------------------------
    // DEFINING
    //-----------------------------------------------------------------------------------
    deque<int> dq;

    //-----------------------------------------------------------------------------------
    // FUNCTIONS
    //-----------------------------------------------------------------------------------

    // # push_back() – It push the elements into a deque from the back
    dq.push_back(4);
    dq.push_back(24);
    // # push_front() – It push the elements into a deque from the front
    dq.push_front(99);
    dq.push_front(89);

    //display(dq);

    // # pop_back() – It is used to pop or remove elements from a deque from the back.
    dq.pop_back();

    //display(dq);

    // # pop_front() – It is used to pop or remove elements from a deque from the front.
    dq.pop_front();
    //display(dq);

    // # front() - reference the first element of the deque container
    cout << dq.front() << endl;

    // # back - reference the last element of the deque container
    cout << dq.back() << endl;

    // # assign() 
    int arr[] = {1, 2, 3, 4, 5};
    dq.assign(arr, arr + 5);
    // display(dq);

    //# insert() 
    //# clear()
    //# erase()
    //# empty()
    //# size()
    //# [] operator or at()
    //# begin() and end()

    return 0;
}