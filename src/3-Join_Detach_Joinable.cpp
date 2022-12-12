#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void run(int count){
    while(count-->0){
        cout << count << "CPP" << endl;
    }
    // std::this_thread::sleep_for(chrono::seconds(5));
    cout << "thread finished" << endl;
}

int main(){
    std::thread t1(run,10);
    cout << "main()" << endl;
    // t1.join();

    if(t1.joinable()){
        t1.join();
        t1.detach();
    }
    t1.detach();
    cout << "main() after" << endl;
    // std::this_thread::sleep_for(chrono::seconds(5));

    return 0;
}