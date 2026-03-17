#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

void mergeSort(vector<ll>&v, ll start, ll end,ll& cnt){
    if(start>=end){
        return;
    }
    ll si=start;ll ei=start+((end-start)/2);
    mergeSort(v,start,ei,cnt);
    mergeSort(v,ei+1,end,cnt);

    ll i=si;ll j=ei+1;
    vector<ll>temp(end-start+1,0);
    ll idx=0;
    while(i<=ei && j<=end){
        if(v[i]>v[j]){
            temp[idx]=v[j];
            cnt+=(ei-i+1);
            j++;
        }else{
            temp[idx]=v[i];
            i++;
        }
        idx++;
    }
    while(i<=ei){
        temp[idx]=v[i];i++;idx++;
    }
    while(j<=end){
        temp[idx]=v[j];j++;idx++;
    }
    for(ll i=start;i<=end;i++){
        v[i]=temp[i-start];
    }
    return;
}

int main(){

    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        ll cnt=0;
        mergeSort(v,0,n-1,cnt);
        cout<<cnt<<endl;
    }
    
    return 0;
}
