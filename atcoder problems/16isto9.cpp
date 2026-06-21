#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int x,y;
    cin>>x>>y;

    vector<int>fac;
    int maxi=max(x,y);
    for(int i=2;i<=maxi;i++){
        if(x%i==0 && y%i==0){
            fac.push_back(i);
        }
    }

    for(int i=0;i<fac.size();i++){
        while(!(x%fac[i]) && !(y%fac[i])){
            x/=fac[i];
            y/=fac[i];
        }
    }

    if(x==16 && y==9){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;


}