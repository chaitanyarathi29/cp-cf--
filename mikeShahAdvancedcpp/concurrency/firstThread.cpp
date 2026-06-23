#include <iostream>
#include <thread>
using namespace std;

void test(int x){
    cout<<" Hello from thread"<<endl;
    cout<< "Argument passed in: "<<x<<endl;
}

int main(){

    auto lambda=[](int x){
        cout<<" Hello from thread"<<endl;
        cout<< "Argument passed in: "<<x<<endl;
    };
    //can use a inline function instead also

    thread myThread(&test, 100);
    myThread.join();

    cout<< "hello from my main thread"<<endl;
    
    return 0;
}

//have to join the test thread to main thread otherwise core dumped error will come whcih means that
// the main thread had returned 0 while the other thread was still executing