#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

ll const num = 1e7;

int main(){

    vector<bool>isPrime(num,1);
    isPrime[0]=0;isPrime[1]=0;
    vector<int>v;
    for(int i=2;i*i<num;i++){
        if(isPrime[i]){
            for(int j=i*i;j<num;j+=i){
                isPrime[j]=0;
            }
        }
    }
    for(int i=2;i<num;i++){
        if(isPrime[i]){
            v.push_back(i);
        }
    }
    int t;cin>>t;
    while(t--){

        ll n;cin>>n;
        ll q=0;
        int p=0;
        cout<<endl;
        for(auto&it:v){
            if(n%it==0){
                ll x = n/it;
                if(x%it==0){
                    p=it;
                    q=x/it;break;
                }else{
                    q=it;
                    p=sqrt(n/it);
                }
            }
        }
        cout<<p<<" "<<q<<endl;
    }
    
    return 0;
}