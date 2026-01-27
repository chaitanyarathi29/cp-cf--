#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    vector<bool>v(1e6+1,true);
    v[0]=0;v[1]=0;
    for(int i=2;i*i<=1e6;i++){
        if(v[i]){
            for(int j=i*i;j<=1e6;j+=i){
                v[j]=false;
            }
        }
    }

    while(t--){
        int d;cin>>d;
        int ans=1;
        int temp=1+d;
        for(int i=temp;i<=1e6;i++){
            if(v[i]){
                ans*=i;
                temp=i;
                break;
            }
        }
        temp+=d;
        for(int i=temp;i<=1e6;i++){
            if(v[i]){
                ans*=i;
                temp=i;
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}