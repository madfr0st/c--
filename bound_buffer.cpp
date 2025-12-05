#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>


using namespace std;

class BoundBuffer{
private:
    mutex m;
    condition_variable cv;
    int size = 0;
    int head = 0;
    int tail = 0;
    int len = 0;
    vector<int> *v;
public:
    BoundBuffer(int size):size(size){
        v = new vector<int>(size);
    }

    bool have_space(){
        if(len<size){
            return true;
        }
        return false;
    }

    bool have_data(){
        if(len==0){
            return false;
        }
        return true;
    }

    bool push(int data){
        unique_lock<mutex> lv(m);
        cv.wait(lv, [this]() { return have_space(); });
        (*v)[tail] = data;
        //cout << "data pushed :" << to_string(data) << endl;
        tail++;
        tail%=size;
        len++;
        cv.notify_all();
        return true;
    }

    int pop(){
        unique_lock<mutex> lv(m);
        cv.wait(lv, [this]() { return have_data(); });
        int a = (*v)[head];
        //cout << "data poped :" << to_string(a) << endl;
        head++;
        head%=size;
        len--;
        cv.notify_all();
        return a;
    }
};



int main()
{
    mutex k_1;
    mutex k_2;
    atomic<int> count = 0;
    int produced = 0;
    int consumed = 0;


    vector<int> data(10);
    for(int i=0;i<10;i++){
        data[i] = i+1;
    }


    BoundBuffer *buff = new BoundBuffer(10);
    vector<thread> pt;
    vector<thread> ct;

    function<void(string,int)> prod = [&](string t_name,int i)->void{
        while(produced<10){
            //cout << "produced by: " << t_name << endl;
            buff->push(data[produced]*(i+1));
            produced++;
        }

    };

    function<void(string)> cons = [&](string t_name)-> void{
        while(count.load()<50){ 
            int a = buff->pop();
            //cout << "consumed by: " << t_name << endl;
            cout << "data consumed :" << to_string(a) << endl;
            count++;
        }
    };

    for(int i=0;i<5;i++){
        pt.emplace_back(prod, to_string(i),i);
    }

    for(int i=0;i<2;i++){
        ct.emplace_back(cons, to_string(i));
    }

    for(auto &t:pt){
        t.join();
    }
    
    for(auto &t:ct){
        t.join();
    }

    cout << "end" << endl;






    return 0;
}