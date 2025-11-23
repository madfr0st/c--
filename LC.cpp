#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define pb push_back

template <typename T>
T add(T a, T b)
{
    return (a + b);
}

inline void print(string s)
{
    cout << s << endl;
}

#define SQUARE(X) (X * X)

int main()
{

    auto sum = [](int a) -> int
    {
        return SQUARE(a);
    };

    struct Delta{
        int first;
        int second;
    };

    Delta* arr = (Delta*) malloc(10*sizeof(Delta));

    for(int i=0;i<10;i++){
        arr[i].first = i+i;
        arr[i].second = 444+i;
        
    }


    for(Delta* a=arr;a<arr+10;a++){
        cout << a->first << " " << a->second << endl;
    }

    



  

    int a = 9;
    int b = a;
    int &c = a;
    printf("a: %d,b: %d, c: %d\n", a, b, &c);
    reinterpret_cast<int>(a);


      int ans = sum(a);

      cout << ans <<endl;

    return 0;
}