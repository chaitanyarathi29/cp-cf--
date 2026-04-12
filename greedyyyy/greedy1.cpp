//Given an array, find a subset of K elements with maximum sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    vector<int>v(n,0);
    for(auto&iy:v){
        cin>>iy;
    }
    
    sort(v.begin(),v.end());

    int sum=0;
    for(int i=n-1;i>n-k-1;i--){
        sum+=v[i];
    }
    cout<<sum<<endl;
    return 0;
}