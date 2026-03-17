#include <iostream>
using namespace std;

int main(){

    int h,w,q;
    cin>>h>>w>>q;
    while(q--){
        int i,x;
        cin>>i>>x;
        if(i==1){
            cout<<w*x<<endl;
            h-=x;
        }else{
            cout<<h*x<<endl;
            w-=x;
        }
    }
    
    return 0;
}