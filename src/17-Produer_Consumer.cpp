#include<iostream>
#include<thread>
#include<mutex>
#include<algorithm>
#include<future>
#include<deque>

using namespace std;
using namespace std::chrono;

std::mutex mu;
std::condition_variable cond;
deque<int> buffer;
const unsigned int maxBufferSize = 50;

void producer(int val){
    while (val)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker,[]{return buffer.size()<maxBufferSize;});
        buffer.push_back(val);
        cout << "Produced: " << val << endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }
    
}

void consumer(){
    while (true)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker,[]{return buffer.size()>0;});
        int val = buffer.back(); 
        buffer.pop_back();
        cout << "Consumed: " << val << endl;
        locker.unlock();
        cond.notify_one();
    }    
}

int main(){
    thread t1(producer,100);
    thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}