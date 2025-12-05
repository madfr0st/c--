#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int size = s.size();
        deque<char> dq;
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '(')
            {
                dq.push_back(s[i]);
            }
            else if (s[i] == '{')
            {
                dq.push_back(s[i]);
            }
            else if (s[i] == '[')
            {
                dq.push_back(s[i]);
            }
            else if (s[i] == ')')
            {
                if (dq.back() != '(')
                {
                    return false;
                }
                dq.pop_back();
            }
            else if (s[i] == '}')
            {
                if (dq.back() != '{')
                {
                    return false;
                }
                dq.pop_back();
            }
            else if (s[i] == ']')
            {
                if (dq.back() != '[')
                {
                    return false;
                }
                dq.pop_back();
            }
        }
        return true;
    }
};

int main()
{

    string s = "()[]{}";
    Solution ss;
    cout << ss.isValid(s) << endl;

    return 0;
}