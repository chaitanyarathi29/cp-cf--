#include <iostream>
#include <vector>
#define ll long long; 
using namespace std;
long long const mod = 1e9+7;
long long expo(long long a, long long b){
    long long res=1;
    while(b){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
long long mul_mod(long long a, long long b){
    a=a%mod;b=b%mod;
    return (((a*b)%mod));
}
long long sub_mod(long long a, long long b){
    a=a%mod;b=b%mod;
    return ((a-b+mod)%mod);
}
long long div_mod(long long a,long long b){
    return (mul_mod(a,expo(b,mod-2))%mod);
}

int main(){

    int n;cin>>n;
    vector<long long>prime(n),power(n);
    for(int i=0;i<n;i++){
        cin>>prime[i]>>power[i];
    }

    long long ans1=1;
    for(int i=0;i<n;i++){
        ans1=mul_mod(ans1,(power[i]+1))%mod;
    }
    long long ans2=1;
    for(int i=0;i<n;i++){
        long long num = (expo(prime[i],power[i]+1)%mod-1+mod)%mod;
        long long deno = prime[i]-1;
        long long temp = div_mod(num,deno);
        ans2 = mul_mod(ans2,temp); 
    }
    long long pro=1;long long num=1;
    for(int i=0;i<n;i++){
        pro = expo(pro,(power[i]+1))%mod;
        long long temp = ((power[i]*(power[i]+1))/2);
        long long base = expo(prime[i],temp)%mod;
        long long val = expo(base,num)%mod;
        pro*=val;
        pro%=mod;
        num*=(power[i]+1);
        num%=(mod-1);
    }
    
    cout<<ans1<<" "<<ans2<<" "<<pro<<endl;

    return 0;
}