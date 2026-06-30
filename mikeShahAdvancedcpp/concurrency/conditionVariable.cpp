#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

mutex gLock;
condition_variable gConditionVariable;

int main(){

    int result = 0;
    bool notified = false;

    thread reporter([&]{
        unique_lock<mutex> lock(gLock);  //good locks do not really have to care about unlocking
        if(!notified){
            gConditionVariable.wait(lock);
        }
        cout<<"Reporter result: "<<result<<endl;
    
    });
    
    thread worker([&]{
        unique_lock<mutex> lock(gLock);
        //doing our work
        result = 42+1+7; //some computation
        //work done 
        notified = true;
        this_thread::sleep_for(chrono::seconds(5));
        cout<<"Work completed"<<endl;
        gConditionVariable.notify_one();
    
    });

    reporter.join();
    worker.join();

    return 0;
}
