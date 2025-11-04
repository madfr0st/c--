#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define pb push_back


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        set<char> ch;
        int ans = 0;
        int mx = 0;
        int l=0;
        int r = 1;

        if(s.size()==0){
            return 0;
        }

        if(s.size()==1){
            return 1;
        }
        if(s.size()==2){
            if(s[0]==s[1]){
                return 1;
            }
            return 2;
        }

        if(s[0]==s[1]){
            mx = 1;
            ch.emplace(s[0]);
            l=1;
        }
        else{
        ch.emplace(s[0]);
        ch.emplace(s[1]);
        mx = 2;
        r = 2;
        }

        while(r<s.size()){
            printf("r : %d, l : %d, mx : %d\n",r,l,mx);
            
            if(l==r){
                r++;
                if(r==s.size()){
                    break;
                }
            }
            if(ch.count(s[r])==0){
                ch.emplace(s[r]);
                mx = max(mx,r-l+1);
                r++;
                auto b = ch.begin();
                while(b!=ch.end()){
                    cout<<*b<< " ";
                    b++;
                }
                cout<<endl;
            }
            else{
                while(l<r){
                    if(s[l]==s[r]){
                        l++;
                       
                        mx = max(r-l+1,mx);
                         r++;
                        break;
                    }
                    else{
                        ch.erase(s[l]);
                        l++;
                    }
                    
                }
            }

        }

        return mx;
        
    }
};



int main()
{

    Solution sol;
    vector<int> v = {2, 3, 1, 2, 4, 3};
    vector<int> c = {4, 2, 0, 3, 2, 5};

    string s = "abcabcbb";

    cout << sol.lengthOfLongestSubstring(s) << endl;
    //cout << sol.lengthOfLongestSubstring(2, c) << endl;
    // cout << sol.intToRoman(c) << endl;
    return 0;
}