#include<iostream>
#include<thread>
using namespace std;

// 1. Function Pointer

void fun(int x){
    while(x-->0){
        cout << x << endl;
    }
}

// int main(){
//     std::thread t1(fun,11);
//     t1.join();
//     return 0;
// }

// 2. Lamda Funtion-1

// int main(){
//     auto fun =[](int x){
//         while(x-->0){
//             cout << x << endl;
//         }
//     };
//     std::thread t(fun,10);
//     t.join();
//     return 0;
// }

// 3.Lamda Funtion-2

// int main(){
//     std::thread t([] (int x){
//         while(x-->0){
//             cout << x << endl;
//         }
//     },10);
//     t.join();
//     return 0;
// }

// 4. Functor(Function-Object)

// class Base{
//     public:
//         void operator () (int x){
//             while(x-->0){
//                 cout << x << endl;
//             }
//         }
// };
// int main(){
//     std::thread t((Base()),10);
//     t.join();
//     return 0;
// }

// 5. Non-static member Function
// class Base{
//     public:
//         void run(int x){
//             while(x-->0){
//                 cout << x << endl;
//             }
//         }
// };

// int main(){
//     Base b;
//     std::thread t(&Base::run,&b,10);
//     t.join();
//     return 0;
// }

// 6. Static member Function
class Base{
    public:
        static void run(int x){
            while(x-->0){
                cout << x << endl;
            }
        }
};
int main(){
    std::thread t(&Base::run,10);
    t.join();
    return 0;
}