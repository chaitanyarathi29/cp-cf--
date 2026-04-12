//Given an array, find the maximum difference between 2 elements
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
    
    cout<<v[n-1]-v[0]<<endl;

    return 0;
}