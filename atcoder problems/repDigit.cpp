#include <iostream>
using namespace std;

int main(){

    int n;cin>>n;
    bool flag=false;
    for(int i=1;i<10;i++){
        if(n%i==0 && n/i==111){
            flag=true;
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