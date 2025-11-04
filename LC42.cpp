#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define pb push_back

class Solution
{
public:
    int trap(vector<int> &height)
    {

        int l_max = 0;
        int r_max = 0;
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while (l < r)
        {
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

            if (height[l] < height[r])
            {
                if (height[l] < min(l_max, r_max))
                {
                    ans += min(l_max, r_max) - height[l];
                }
                l++;
            }
            else
            {
                if (height[r] < min(l_max, r_max))
                {
                    ans += min(l_max, r_max) - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};

int main()
{

    Solution sol;
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> c = {4,2,0,3,2,5};

    cout << sol.trap(v) << endl;
cout << sol.trap(c) << endl;
    return 0;
}