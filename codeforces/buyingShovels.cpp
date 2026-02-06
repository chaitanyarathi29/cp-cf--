#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        if(n<=k){
            cout<<1<<endl;
        }else{
            vector<long long>factor;
            for(int i=2;i*i<=n;i++){
                if(n%i==0){
                    factor.push_back(i);
                    if(i!=n/i){
                        factor.push_back(n/i);
                    }
                }
            }
            sort(factor.begin(),factor.end());
            if(factor.size()==0){
                cout<<n<<endl;
                continue;
            }
            bool flag=0;
            for(int i=0;i<factor.size();i++){
                if((n/factor[i])<=k){
                    cout<<factor[i]<<endl;
                    flag=1;
                    break;
                }
            }
            if(!flag){
                cout<<n<<endl;
            }
        }
    }
    
    return 0;
}