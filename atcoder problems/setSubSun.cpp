#include <iostream>
using namespace std;

int main(){

    long long cnt=0;
    long long n,k;
    cin>>n>>k;
    long long sum=0;
    while(sum<k){
        sum+=(n+cnt);
        cnt++;
    }
    if(cnt>0){
        cout<<cnt-1<<endl;
    }else{
        cout<<cnt<<endl;    
    }
    
    return 0;
}