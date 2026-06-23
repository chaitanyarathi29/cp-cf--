#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex gLock;
static int shared_value=0;

void shared_value_increment(){
    lock_guard<mutex>lockGuard(gLock);
    //gLock.lock(); if i lock the thread and the thread gets an exception it will not 
    //unlock the lock and deadlock will occur;
    try{
        shared_value++;
        throw("dangerous...abort");
    }catch(error_code){
        cout<<"handle exceptiomn";
        return;
    }
    //gLock.unlock()
}

int main(){
    
    vector<thread>threads;
    for(int i=0;i<1000;i++){
        threads.push_back(thread(shared_value_increment,i));
    }

    for(int i=0;i<1000;i++){
        threads[i].join();
    }
    cout<<shared_value<<endl;
    return 0;
}