//Find the subarray of size K which has the maximum sum in an array.

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    int max=-1;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=v[i];
    }
    max=sum;
    for(int i=k;i<n;i++){
        sum-=v[i-k];sum+=v[i];
        if(max<sum) max=sum;
    }
    cout<<max<<endl;

    return 0;
}