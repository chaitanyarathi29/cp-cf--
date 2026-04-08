//Find the subarray of size K which has the maximum sum and all distinct
//elements.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

    int n,k;cin>>n>>k;
    vector<int>v(n,0);
    map<int,int>mp;
    for(auto&it:v){
        cin>>it;
    }
    int max=-1;int sum=0;
    for(int i=0;i<k;i++){
        mp[v[i]]++;
        if(mp[v[i]]==1) sum+=v[i];
    }
    max=sum;
    for(int i=k;i<n;i++){
        mp[v[i-k]]--;
        if(mp[v[i-k]]==0){
            sum-=v[i-k];
            mp.erase(v[i-k]);
        } 
        if(mp[v[i]]==0){
            sum+=v[i];
        }
        mp[v[i]]++;
        if(max<sum) max=sum;
    }
    cout<<max<<endl;

    return 0;
}