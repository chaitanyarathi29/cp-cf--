#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    vector<bool>fac(1e5+1,0);
    for(int i=0;i<n;i++){
        int num=v[i];
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                fac[i]=1;
                while(num%i==0){
                    num/=i;
                }
            }
        }
        if(num>1){
            fac[num]=1;
        }
    }
    for(int i=2;i<=m;i++){
        if(fac[i]){
            int j=i;
            while(j<=m){
                fac[j]=1;
                j+=i;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(!fac[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=m;i++){
        if(!fac[i]){
            cout<<i<<endl;
        }
    }

    return 0;
}
