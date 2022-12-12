#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m1,m2;

void task_a(){
    while(1){
        std::lock(m1,m2);
        std::cout << "task a\n";
        m1.unlock();
        m2.unlock();
    }
}

void task_b(){
    while(1){
        std::lock(m2,m1);
        std::cout << "task_b\n";
        m2.unlock();
        m1.unlock();
    }
}

int main(){
    std::thread t1(task_a);
    std::thread t2(task_b);

    t1.join();
    t2.join();
    return 0;
}