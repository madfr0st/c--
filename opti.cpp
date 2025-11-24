#include <bits/stdc++.h>

using namespace std;


int main(){

    bitset<32> bits;
    bits[0] = true;
    cout << bits[0] << endl;
    cout << sizeof(bits) << endl;


    deque<int> dq;
    dq.push_front(1);

    cout << dq[0] << endl;
    cout << dq[1] << endl;

    //cout << dq.at(1) << endl;
    



    return 0;
}