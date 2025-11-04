#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define pb push_back

class Solution
{
public:
    string intToRoman(int num)
    {
        unordered_map<int, string> map;
        map[1] = "I";
        map[5] = "V";
        map[10] = "X";
        map[50] = "L";
        map[100] = "C";
        map[500] = "D";
        map[1000] = "M";

        int n = to_string(num).size();

        string ones = "";

        int mul = 1;

        for (int i = 0; i < n; i++)
        {

            int at = num % (mul * 10);

            num -= at;

            at /= mul;

            printf("at: %d, mul: %d, num: %d\n", at, mul, num);

            if (at >= 0 && at <= 3)
            {
                for (int j = 0; j < at; j++)
                {
                    ones = map[mul] + ones;
                }
            }
            else if (at == 4)
            {
                ones = map[mul] + map[mul * 5] + ones;
                
            }
            else if (at >= 5 && at <= 8)
            {
                
                for (int j = 0; j < at%5; j++)
                {
                    ones = map[1 * mul] + ones;
                    
                }
                ones = map[ 5 * mul]+ones;
            }
            else if (at == 9)
            {
                ones = map[mul] + map[mul * 10] + ones;
                
            }
            cout << ones << endl;

            mul *= 10;
        }

        return ones;
    }
};

int main()
{

    Solution sol;
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> c = {4, 2, 0, 3, 2, 5};

    cout << sol.intToRoman(1994) << endl;
    cout << sol.intToRoman(58) << endl;
    // cout << sol.intToRoman(c) << endl;
    return 0;
}