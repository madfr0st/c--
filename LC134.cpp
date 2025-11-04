#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


#define pb push_back


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g_sum = 0;
        int c_sum  = 0;
        int n = gas.size();
        int g_min = INT_MAX;
        int g_min_at = -1;
        int c_max_at = -1;
        int c_max = -1;

        for(int i=0;i<n;i++){
            gas.push_back(gas[0]);
            cost.push_back(cost[0]);
            g_sum += gas[i];
            c_sum += cost[i];
            c_max = max(c_max,cost[i]);
        }
        if(g_sum<c_sum){
            return -1;
        }

        int at = 0;
        int l_gas = 0;

        for(int i=0;i<2*n-1;i++){
            l_gas += gas[i];
            cout<< l_gas << endl;
            if(l_gas>=cost[i+1]){
                l_gas -=cost[i+1];
            }
            else{
                 cout<< "i : " << i << endl;
                l_gas = 0;
                at = i%n;
            }
        }

        return (at)%n;


    }
};

int main(){

    Solution sol;
    vector<int> v;
    v.pb(1);
    v.pb(2);
    v.pb(3);
    v.pb(4);
    v.pb(5);

    vector<int> c;
    c.pb(3);
    c.pb(4);
    c.pb(5);
    c.pb(1);
    c.pb(2);

    cout <<  sol.canCompleteCircuit(v,c) << endl;

    return 0;
}