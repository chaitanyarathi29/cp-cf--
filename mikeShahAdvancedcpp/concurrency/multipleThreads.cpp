#include <iostream>
#include <thread>
#include <vector>
using namespace std;

int main(){

    auto lambda = [](int x){
        cout<<"Hello from thread!"<<this_thread::get_id()<<endl;
        cout<<"Argument passed in: "<<x<<endl;
    };

    vector<thread>threads;
    for(int i=0;i<10;i++){
        threads.push_back(thread(lambda,i));
        //threads[i].join();  if i join each thread on each loop this will become synchronous that is thread creates then joins then other thread initialises and then joins this does not lead to parallelism
    }
    
    for(int i=0;i<10;i++){
        threads[i].join();
    }//this will create 10 threads instantly and execution will be 10x

    cout<<"hello from main thread"<<endl;
    return 0;
}

//jthreads are new threads introduced in c++20 that joins by themselves i dont have to worry about joining so we can use that as well