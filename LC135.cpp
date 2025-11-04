#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define pb push_back

class Solution
{
public:
    int candy(vector<int> &ra)
    {

        vector<int> giv(ra.size(), 0);

        int ans = 0;
        int n = ra.size();
        if (n == 1)
        {
            return 1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({ra[i], i});
        }

        while (!pq.empty())
        {
            cout << pq.top().first << " : " << pq.top().second << endl;
            int a = pq.top().first;
            int b = pq.top().second;
            pq.pop();

            if (b == 0)
            {
                if (ra[0] > ra[1])
                {
                    giv[0] = giv[1] + 1;
                }
                else
                {
                    giv[0] = 1;
                }
            }
            else if (b == n - 1)
            {
                if (ra[b] > ra[b-1])
                {
                    giv[b] = giv[b-1] + 1;
                }
                else
                {
                    giv[b] = 1;
                }
            }
            else{
                if(ra[b-1] < ra[b] && ra[b]>ra[b+1]){
                    giv[b] = max(giv[b-1],giv[b+1])+1;

                }
                else if(ra[b-1]<ra[b]){
                    giv[b] = giv[b-1]+1;
                }
                else if(ra[b+1]<ra[b]){
                    giv[b] = giv[b+1]+1;
                }
                else{
                    giv[b] = 1;
                }
            }
        }

        for(int& a:giv){
            cout << a << " ";
                ans+=a;
        }
        cout << endl;

        // priority queue
        // pair
        // array formating

        return ans;
    }
};

int main()
{

    Solution sol;
    vector<int> v;
    // 1,3,2,2,1
    //[29,51,87,87,72,12]
    v.pb(29);
    v.pb(51);
    v.pb(87);
    v.pb(87);
    v.pb(72);

    vector<int> c;
    v.pb(12);
    c.pb(4);
    c.pb(5);
    c.pb(1);
    c.pb(2);

    cout << sol.candy(v) << endl;

    return 0;
}