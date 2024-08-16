// https://www.geeksforgeeks.org/problems/find-length-of-loop/1
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
int countNodesinLoop(struct Node *head)
{
    // Code here
    if (!head)
    {
        return 0;
    }
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            int count = 0;
            do
            {
                fast = fast->next;
                count++;
            } while (fast != slow);
            return count;
        }
    }
    return 0;
}
int main(void) {
    
    return 0;
}