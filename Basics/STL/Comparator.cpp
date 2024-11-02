#include<bits/stdc++.h>
using namespace std;

class info {
    public:
    int num1, num2, num3;
    info(int n1, int n2, int n3): num1(n1), num2(n2), num3(n3) {}
};

class compare {
    public:
    bool operator()(info *a, info *b) {
        return a->num1 > b->num1;
    }
};
int main(void) {
    priority_queue<info*, vector<info*>, compare> pq; // using custom comparator to create min heap
    return 0;
}