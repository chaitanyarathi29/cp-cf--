#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=2;j*j<=v[i];j++){
                if(v[i]%j==0){
                    int cnt=0;
                    while(v[i]%j==0){
                        v[i]/=j;
                        cnt++;
                    }
                    mp[j]+=cnt;
                }
            }
            if(v[i]>1){
                mp[v[i]]++;
            }
        }
        bool flag=true;
        for(auto&it:mp){
            if(it.second%n!=0){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}