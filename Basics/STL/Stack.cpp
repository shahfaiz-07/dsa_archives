#include<iostream>
#include<stack>
using namespace std;
//#NOTE - Cannot acess elements from the middle using [] operator or at() function
int main() {
    //-----------------------------------------------------------------------------------
    // DEFINING
    //-----------------------------------------------------------------------------------
    stack<int> stk1;

    //-----------------------------------------------------------------------------------
    // FUNCTIONS
    //-----------------------------------------------------------------------------------

    //# push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
    stk1.push(2);
    stk1.push(3);
    stk1.push(4);
    stk1.push(5);

    //# pop() – Deletes the most recent entered element of the stack – Time Complexity : O(1)
    stk1.pop();

    //# top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
    cout << stk1.top() << endl;

    // # size() – Returns the size of the stack – Time Complexity : O(1)
    cout << stk1.size() << endl;

    // #empty() – Returns whether the stack is empty – Time Complexity : O(1)
    cout << stk1.empty() << endl;

    stk1.pop();
    stk1.pop();
    stk1.pop();

    cout << stk1.empty() << endl;
    return 0;
}