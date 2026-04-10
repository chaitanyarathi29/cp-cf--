// Find the number of subarrays with sum <= k.
// Find the number of subarrays with sum > k. (total se minus krdo)
// 10 5 2 7 1 9

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,k;cin>>n>>k;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    int l,r;l=r=0;
    int sum=0,ans=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        while(sum>k){
            sum-=v[l];l++;
        }
        ans+=(r-l+1);
        r++;
    }
    cout<<ans<<endl;

    return 0;
}