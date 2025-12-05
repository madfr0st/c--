#include <iostream>
#include <random>
#include <unordered_map>

using namespace std;

int random()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);
    return dist(gen);
}

class Solution
{
public:
    void calc(vector<int> &given, unordered_map<int, int> &map, int at, int max)
    {
        for (int i = 1; i <= 6; i++)
        {
            int new_at = at + i;
            if (new_at > max)
            {
                new_at = max;
            }

            if (given[new_at - 1] != -1)
            {
                new_at = given[new_at - 1];
            }

            if (map[new_at] > (map[at] + 1))
            {
                map[new_at] = map[at] + 1;
                if (new_at == max)
                {
                    return;
                }
                else
                {
                    calc(given, map, new_at, max);
                }
            }
            else
            {
                continue;
            }
        }
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        vector<int> v;
        int size = board.size();
        unordered_map<int, int> map;

        for (int i = 0; i <= size * size; i++)
        {
            map[i] = INT_MAX;
        }
        map[1] = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            if (i % 2 == 1)
            {
                for (int j = 0; j < size; j++)
                {
                    v.emplace_back(board[i][j]);
                }
            }
            else
            {
                for (int j = size - 1; j >= 0; j--)
                {
                    v.emplace_back(board[i][j]);
                }
            }
        }

        calc(v, map, 1, size * size);

        for (int a : v)
        {
            cout << a << " ";
        }

        auto a = map.begin();
        while (a != map.end())
        {
            cout << (*a).first << " " << (*a).second << endl;
            a++;
        }
        cout << size * size << " " << map[size * size] << endl;
        if (map[size * size] == INT_MAX)
        {
            return -1;
        }
        return map[size * size];
    }
};

int main()
{

    vector<vector<int>> given =
        {{-1, -1, -1, -1, -1, -1},
         {-1, -1, -1, -1, -1, -1},
         {-1, -1, -1, -1, -1, -1},
         {-1, 35, -1, -1, 13, -1},
         {-1, -1, -1, -1, -1, -1},
         {-1, 15, -1, -1, -1, -1}};

    Solution sol;
    sol.snakesAndLadders(given);

    return 0;
}
