//Find the max sum of the subarray from the given array

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    int sum=0;
    int max=-1;
    for(int i=0;i<n;i++){
        sum += v[i];
        if(max<sum){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout<<max<<endl;
    
    return 0;
}