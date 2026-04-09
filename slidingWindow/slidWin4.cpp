//For each subarray of size K in array, find the index of the minimum element
//in that subarray.

//optimised to 0(n) from 0(nlogk) by the help of deques 
//the nlogk method is pretty simple inserting pairs in a priority queue and then printing the top value
// below method is using deque (optimised).

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }    
    deque<pair<int,int>>d;
    
    for(int i=0;i<k;i++){
        while(!d.empty() && d.back().first > v[i]){
            d.pop_back();
        }
        d.push_back({v[i],i});
    }
    cout<<d.front().second+1<<" ";

    for(int i=k;i<n;i++){

        if(!d.empty() && d.front().second < i-k+1){
            d.pop_front();
        }

        while(!d.empty() && d.back().first > v[i]){
            d.pop_back();
        }
        d.push_back({v[i],i});
        cout<<d.front().second+1<<" ";
    }
    cout<<endl;

    return 0;
}