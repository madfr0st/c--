#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:


    RandomizedSet() {
        map = new unordered_map<int,int>();
    }

    bool insert(int val) {
        (*this->map)[val] = 1;
        return true;
    }

    bool remove(int val) {
        if (this->map->find(val) == this->map->end()) {
           // cout << "in" << endl;
            return false;
        }
        (*this->map).erase(val);
        //cout << "in" << endl;
        return true;
    }

    int getRandom() {
        for(auto a: (*this->map)){
            return a.first;
        }

    }

private:
    unordered_map<int,int>* map;
};


int main(){
    RandomizedSet sol;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    sol.insert(6);
     sol.insert(1);
     cout << sol.remove(1) << endl;
    cout << sol.getRandom() << endl;

    cout << sol.remove(1) << endl;
    return 0;
}


