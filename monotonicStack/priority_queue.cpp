#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//custom comparator
//in case of pq -> if true then second is given priority
//in case of vector -> if true first is given priority
struct custom_compare{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        //on the basis of first -> min pq
        //on the basis of second -> max pq
        if(a.first==b.first){
            return (a.second < b.second);
        }
        return (a.first > b.first);
    }
};

int main(){

    priority_queue<pair<int,int>,vector<pair<int,int>>,custom_compare>pq;
    pq.push({3,2});
    pq.push({2,1});
    pq.push({3,4});
    pq.push({6,3});
    
    return 0;
}