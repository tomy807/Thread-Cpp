#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int count = 0;
std::mutex mtx;

void increase(){
    for(int i= 0;i<100000;++i){
        if(mtx.try_lock()){
            ++count;
            mtx.unlock();
        }
    }
}

int main(){
    std::thread t1(increase);
    std::thread t2(increase);

    t1.join();
    t2.join();
    cout << "Count: " << count << endl;
    return 0;
}