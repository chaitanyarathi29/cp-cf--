#include <iostream>
using namespace std;

int main(){

    int n,k;cin>>n>>k;
    int cnt=1;
    int ans=0;
    while(cnt<n+1){
        int temp=cnt;
        int sum=0;
        while(temp){
            sum +=temp%10;
            temp/=10;
        }
        if(sum==k){
            ans++;
        }
        cnt++;
    }
    cout<<ans<<endl;
    
    return 0;
}
