#include<iostream>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int l,a,b;
        cin>>l>>a>>b;
        int max=(a+b)%l;
        int c=(a+b)%l;
        while(c!=a){
            if(max<c){
                max=c;
            }
            c=(c+b)%l;
        }
        if(a>max){
            cout<<a<<endl;
        }else{
            cout<<max<<endl;   
        }
    }

    return 0;
}