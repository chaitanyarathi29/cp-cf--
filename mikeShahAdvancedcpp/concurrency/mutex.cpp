#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex gLock; //mutex or binary semaphore
static int shared_value=0;

//now if i dont apply locks here race condition will occur so i should apply them

void shared_value_increment(){
    gLock.lock();
    shared_value++;
    shared_value++;
    shared_value++;
    //critical section
    gLock.unlock();
}
// this helps me increment the value of sharedvalue only by a thread at a time...
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