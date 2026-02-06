#include <iostream>
#include <vector>
using namespace std;

vector<int>ans;
bool fnExp(int i, int cnt,vector<int>&v,int x){

    if(i==v.size()){
        return cnt==x;
    }
    bool addi = fnExp(i+1,cnt+v[i],v,x);
    bool subtra = fnExp(i+1,cnt-v[i],v,x);
    return addi || subtra;
}

int main(){

    int n,x;cin>>n>>x;
    vector<int>v(n,0);
    for(auto&it:v) cin>>it;
    bool ans = fnExp(1,v[0],v,x);

    if(ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;   
    }
    return 0;
}