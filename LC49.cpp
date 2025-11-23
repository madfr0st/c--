#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;

        for (string& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            if (m.find(key) == m.end())
            {
                vector<string> temp;
                temp.push_back(s);
                m[key] = temp;
            }
            else{
                m[key].push_back(s);
            }
        }

        for (auto it:m ){
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main()
{

    vector<string> strs;

    strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution solution;
    auto vec = solution.groupAnagrams(strs);

    for (auto v : vec)
    {
        for (auto a : v)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
