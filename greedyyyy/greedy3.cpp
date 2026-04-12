//Given an array, find the minimum difference between 2 elements
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
    
    int mini=INT_MAX;
    for(int i=0;i<n-1;i++){
        mini = min(mini,v[i+1]-v[i]);
    }

    cout<<mini<<endl;
    
    return 0;
}