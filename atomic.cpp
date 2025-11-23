#include <bits/stdc++.h>

using namespace std;

atomic<bool> x, y;
atomic<int> z;

void set_x()
{
    x.store(true, memory_order_seq_cst);
}

void set_y()
{
    y.store(true, memory_order_seq_cst);
}

void check_x_then_y()
{
    while (!x.load(memory_order_seq_cst))
    {
    };

    if (y.load(memory_order_seq_cst))
    {
        z++;
    }
}

void check_y_then_x()
{
    while (!y.load(memory_order_seq_cst))
    {
    };

    if (x.load(memory_order_seq_cst))
    {
        z++;
    }
}

int main()
{

    x = false;
    y = false;
    z = 0;

    thread t_1(set_x);

    thread t_2(set_y);
    thread t_3(check_x_then_y);
    thread t_4(check_y_then_x);

    t_1.join();
    t_2.join();
    t_3.join();
    t_4.join();

    assert(z != 0);

    return 0;
}