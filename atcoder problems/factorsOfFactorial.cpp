#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll const N=1e9+7;
int main(){
 
    vector<bool> prime(1e3+1,1);
    for(int i=2;i*i<=1e3;i++){
        if(prime[i]){
            for(int j=i*i;j<=1e3;j+=i){
                prime[j]=0;
            }
        }
    }
    int n;cin>>n;
    vector<int>freq(1e3+1,0);
    for(int i=2;i<=1e3;i++){
        int cnt=0;
        int temp=n;
        while(temp>1 && prime[i]==1){
            cnt += temp/i;
            temp/=i;
        }
        freq[i]=cnt;
    }
    ll prod=1;
    for(int i=2;i<1e3+1;i++){
        if(freq[i]>0){
            prod*=(freq[i]+1);
            prod%=N;
        }
    }
    cout<<prod<<endl;

    return 0;
}