#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<long long>v(n,0);
    long long s=0;
    for(auto&it:v){
        cin>>it;   
    }
    sort(v.begin(),v.end());
    int median=0;
    if(n&1){
        median = v[n/2];
    }else{
        median = (v[(n/2)-1]+v[(n/2)])/2;
    }
    for(int i=0;i<n;i++){
        s += abs(median-v[i]);
    }
    cout<<s<<endl;

    return 0;

}