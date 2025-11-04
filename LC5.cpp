#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define pb push_back

class Solution
{
public:
    string longestPalindrome(string s)
    {

        if (s.size() == 0)
        {
            return 0;
        }

        int mx = 1;
        int n = s.size();
        int dp[n][n];
        fill(&dp[0][0], &dp[0][0] + n * n, 0);

        int ll = 0;
        int rr = 0;

        int k = 0;
        while (k < n)
        {
            dp[k][k] = 1;
            k++;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                cout << j - i << " " << j << endl;
                if (s[j - i] == s[j])
                {
                    if(i==1){
                        dp[j - i][j] = 2;
                    }
                    else if (dp[j - i - 1][j - 1] >= 1)
                    {
                        dp[j - i][j] = dp[j - i + 1][j - 1] + 2;
                    }
                }
                else
                {
                    dp[j - i][j] = 0;
                }
                mx = max(mx, dp[j - i][j]);
                if(mx == dp[j-i][j]){
                    ll = j-i;
                    rr = j;
                }
            }

            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    cout << dp[k][l] << " ";
                }
                cout << endl;
            }
        }
        cout << mx << endl;
        string ans = "";
        for(int i=ll;i<=rr;i++){
ans+=s[i];
        }
        return ans;
    }
};

int main()
{

    Solution sol;
    vector<int> v = {2, 3, 1, 2, 4, 3};
    vector<int> c = {4, 2, 0, 3, 2, 5};

    string s = "babadd";

    cout << sol.longestPalindrome(s) << endl;
    // cout << sol.lengthOfLongestSubstring(2, c) << endl;
    //  cout << sol.intToRoman(c) << endl;
    return 0;
}