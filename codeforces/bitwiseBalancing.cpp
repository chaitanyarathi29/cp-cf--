#include <iostream>
#include <map>
using ll = long long;
using namespace std;

int main(){
    
    map<tuple<int,int,int>,int>mp;
    mp[{0,0,0}]=0;
    mp[{0,0,1}]=1;
    mp[{0,1,0}]=1;
    mp[{0,1,1}]=-1;
    mp[{1,0,0}]=-1;
    mp[{1,0,1}]=1;
    mp[{1,1,0}]=1;
    mp[{1,1,1}]=0;

    int t;cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>b>>c>>d;
        a=0;bool f=1;
        for(int i=0;i<61;i++){
            int bb=(b>>i)&1;
            int cb=(c>>i)&1;
            int db=(d>>i)&1;
            int ab = mp[{bb,cb,db}];
            if(ab==-1){
                f=0;break;
            } 
            a|=(1LL*ab<<i);
        }
        if(f){
            cout<<a<<endl;
        }else{
            cout<<-1<<endl;
        }

    }

    return 0;
}