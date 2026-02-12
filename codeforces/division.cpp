#include <iostream>
#include <vector>
using namespace std;

long long expo(long long a, long long b){
    long long res = 1;
    while(b){
        if(b&1){
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}

int main(){

    int t;cin>>t;
    while(t--){
        vector<long long>prime;
        long long p,q;
        cin>>p>>q;
        long long nq=q;
        if(p%q!=0 || p<q){
            cout<<p<<endl;
        }else{
            for(int i=2;i*i<=nq;i++){
                if(nq%i==0){
                    prime.push_back(i);
                    while(nq%i==0){
                        nq/=i;
                    }
                }
            }
            if(nq>1){
                prime.push_back(nq);
            }
            long long max=-1;
            long long nq=q;
            long long np=p;
            for(auto&pr:prime){
                int a=0,b=0;
                long long nq=q;
                long long np=p;
                while(np%pr==0){
                    np/=pr;
                    a++;
                }
                while(nq%pr==0){
                    nq/=pr;
                    b++;
                }
                int pow = a-b+1;
                long long num = p/expo(pr,pow);
                if(max<num){
                    max=num;
                }                
            }
            cout<<max<<endl;
        }
    }
    
    return 0;
}
