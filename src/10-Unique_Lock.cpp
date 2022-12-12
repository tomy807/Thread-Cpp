#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m1;
int buffer =0;

void task(const char* threadNumber,int loopFor){
    std::unique_lock<mutex> lock(m1);
    for(int i=0;i<loopFor;i++){
        buffer++;
        cout << threadNumber << buffer << endl;
    }
}

int main(){
    thread t1(task,"T1: ",10);
    thread t2(task,"T2: ",10);
    t1.join();
    t2.join();
    return 0;
}