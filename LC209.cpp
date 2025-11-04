#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define pb push_back

class Solution
{
public:
    int minSubArrayLen(int tar, vector<int> &nums)
    {
        int l = 0, r = 1;
        if (nums.size() == 0)
        {
            return 0;
        }

        for(int a:nums){
            if(a==tar){
                return 1;
            }
        }

        int sum = nums[0];

        if (nums.size() == 1)
        {
            if (nums[0] == tar)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int mn = INT_MAX;

        while (l < r)
        {
            if (sum < tar && r < nums.size())
            {
                sum += nums[r];
                r++;
            }
            else if (sum >= tar)
            {
                 mn = min(mn, (r - l));
                sum -= nums[l];
                l++;
            }
            
            printf("sum: %d, l: %d, r: %d, mn: %d\n", sum, l, r, mn);
            if (r == nums.size())
            {
                break;
            }
        }
        while (l < nums.size())
        {

            if (sum >= tar)
            {
                mn = min(mn, (r - l));
                sum -= nums[l];
                l++;
            }
            else if(sum<tar)
            {
                break;
            }
            printf("sum: %d, l: %d, r: %d, mn: %d\n", sum, l, r, mn);
             
        }
        if(mn==INT_MAX){
            return 0;
        }

        return mn;
    }
};

int main()
{

    Solution sol;
    vector<int> v = {2, 3, 1, 2, 4, 3};
    vector<int> c = {4, 2, 0, 3, 2, 5};

    cout << sol.minSubArrayLen(15, v) << endl;
    cout << sol.minSubArrayLen(2, c) << endl;
    // cout << sol.intToRoman(c) << endl;
    return 0;
}