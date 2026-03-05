#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

bool helper(int x,int k,vector<int>&workload){
    int worker=1;
    int perwork=0;
    for(auto&work:workload){
        if(perwork+work<x){
            perwork+=work;
        }else{
            if(work>x){
                return false;
            }
            perwork=work;
            if(worker==k){
                return false;
            }
            worker++;
        }
    }
    return true;
}

int main(){

    int n,k;
    cin>>n>>k;
    vector<int>workload(n,0);
    for(auto&it:workload){
        cin>>it;
    }
    ll ans=1e9;
    ll lowerend=0;
    ll upperend=1e9;
    while(lowerend<=upperend){
        ll mid = lowerend + (upperend-lowerend)/2;
        if(helper(mid,k,workload)){
            ans = min(ans,mid);
            upperend = mid-1;
        }else{
            lowerend=mid+1;
        }
    }
    
    
    return 0;
}