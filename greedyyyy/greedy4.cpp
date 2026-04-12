//Given an array, reorder the array so that sum of a[i]*i is maximized

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
    for(int i=0;i<n;i++){
        sum += v[i]*i;
    }

    cout<<sum<<endl;
}