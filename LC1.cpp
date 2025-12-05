#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
     vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            bool a = binary_search(nums.begin(), nums.end(), target - nums[i]);
            if (a == true)
            {
                int k = 0;
                for (int b : nums)
                {
                    cout << i << " " << k << endl;
                    if ((nums[i] + b) == target)
                    {
                        if (k != i)
                        {
                            int t_1 = nums[i];
                            int t_2 = nums[k];

                            int a_1 = 0;
                            int a_2 = 0;
                            for(int as:temp){
                                if(as==t_1){
                                    v.push_back(a_1);
                                    break;
                                }
                                a_1++;
                            }

                            for(int as:temp){
                                if(as==t_2 && a_1!=a_2){
                                    v.push_back(a_2);
                                    break;
                                }
                                a_2++;
                            }


                            return v;
                        }
                    }
                    k++;
                }
            }
        }
        return v;
    }
};

int main()
{

    Solution s;
    vector<int> v = {3,2,4};
    vector<int> a = s.twoSum(v, 6);
    for(int k:a){
        cout << k << endl;
    }

    return 0;
}