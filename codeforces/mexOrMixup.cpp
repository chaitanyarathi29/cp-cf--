#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;cin>>t;
    vector<int>vec(300002,0);
    int temp=0;
    for(int i=0;i<300002;i++){
        temp^=i;
        vec[i]=temp;
    }
    while(t--){
        int mex,xo;
        cin>>mex>>xo;
        if(vec[mex-1]==xo){
            cout<<mex<<endl;
        }else{
            if((vec[mex-1]^xo)==mex){
                cout<<mex+2<<endl;
            }else{
                cout<<mex+1<<endl;
            }
        }
    }
    return 0;
}