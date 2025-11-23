#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int max)
    {

        vector<vector<string>> vec;
        int count = 0;
        for (string s : words)
        {
            if (count + s.size() <= max && count != 0)
            {
                count += s.size() + 1;
                vec.back().push_back(s);
            }
            else
            {
                count = s.size();
                vector<string> temp;
                temp.push_back(s);
                vec.push_back(temp);
            }
        }

        cout << " test " << endl;

        vector<string> ans;
        for (int oo=0;oo<vec.size()-1;oo++)
        {
            auto &v = vec[oo];
            count = 0;
            for (auto &s : v)
            {
                count += s.size();
            }
            int space = max - count;

            if (v.size() == 1)
            {
                for (int i = v.front().size(); i <= max; i++)
                {
                    v[0] += " ";
                }
                ans.push_back(v[0]);
            }
            else
            {
                int each = space / (v.size() - 1);
                int rem = space % (v.size() - 1);
                string t;
                for (int i = 0; i < v.size(); i++)
                {
                    t += v[i];
                    if (i != v.size() - 1)
                    {
                        for (int k = 0; k < each; k++)
                        {
                            t += " ";
                        }
                        if (rem > 0)
                        {
                            t += " ";
                            rem--;
                        }
                    }
                }
                ans.push_back(t);
            }
        }

        string l = "";
        count = 0;
        for(int k=0;k<vec.back().size();k++){
            l+=vec.back()[k];
            l+=" ";
        }

        for(int i=l.size();i<max;i++){
            l+=" ";
        }

        ans.push_back(l);

        return ans;
    }
};

int main()
{

    vector<string> v_1 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};

    vector<string> v_2 = {"What","must","be","acknowledgment","shall","be"};

    int m_1 = 20;
    int m_2 = 16;

    Solution s;
    vector<string> ans = s.fullJustify(v_2, m_2);
    for (string &s : ans)
    {
        cout << s << endl;
    }

    return 0;
}