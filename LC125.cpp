#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        string k = "";
        int size = s.size();
        bool ans = true;
        for(int i=0;i<size;i++){
            char a = s[i];
            a -='a';
            if(a>=0 && a<26){
                k+=s[i];
            }
            a+='a';
            a = a-'A';
             if(a>=0 && a<26){
                k+=s[i]-'A'+'a';
            }
        }

        for(char a:k){
            cout << a << " ";
        }
        cout << endl;
        size = k.size()/2;
        cout << size << endl;
        for(int i=0;i<size;i++){
            if(k[i]!=k[k.size()-1-i]){
                return false;
            }
        }


        return ans;
        
    }
};

int main(){

    string s = "0P";

    Solution sol;
    cout << sol.isPalindrome(s) << endl;


    return 0;
}

