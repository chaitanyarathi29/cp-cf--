#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;cin>>n;
    char x;cin>>x;
    vector<string>inp(n);

    for(auto&it:inp){
        cin>>it;
    }

    int col=x-'A';
    bool flag=false;
    for(int i=0;i<n;i++){
        if(inp[i][col]=='o'){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}