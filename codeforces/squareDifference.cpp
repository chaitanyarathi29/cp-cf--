#include <iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        if(a==b+1){
            long long num = a+b;
            int cnt=0;
            for(long long i=2;i*i<=num;i++){
                if(num%i==0){
                    while(num%i==0){
                        cnt++;
                        num/=i;
                    }
                }
            }
            if(num>1){
                cnt++;
            }
            if(cnt==1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}