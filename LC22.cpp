#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int t)
    {

        int size = nums.size();
        int l = 0;
        int r = size - 1;
        int at = -1;
        if(t<nums[0] && t>nums[size-1]){
            return -1;
        }

        while (l < r)
        {

            int mid = (l + r) / 2;
            cout << l << " " << mid << " " << r << endl;

            int ll = nums[l];
            int rr = nums[r];
            int mm = nums[mid];

            if (ll <= mm && ll <= t && mm >= t)
            {
                r = mid;
            }
            else if (ll >= mm && t >= ll)
            {
                r = mid;
            }

            if (rr > mm && mm < t && rr > t)
            {
                l = mid + 1;
            }
            else if (rr <= mm && t <= rr)
            {
                l = mid + 1;
            }
            int target = t;

            if (nums[l] == target)
            {
                at = l;
                break;
            }
            if (nums[r] == target)
            {
                at = r;
                break;
            }
            if (nums[mid] == target)
            {
                at = mid;
                break;
            }
            if (l >= r)
            {
                break;
            }
        }

        return at;
    }
};

int main()
{
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};

    Solution s;
    cout << s.search(v, 3) << endl;

    return 0;
}