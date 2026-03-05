#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n,0);
        bool flag=0;
        int neg=-1000000001; 
        int max=-1;
        for(auto&it:v){
            cin>>it;
            if(it<0 && neg<it){
                flag=1;
                neg=it;
            }
            if(it>max){
                max=it;
            }
        }
        if(flag){
            cout<<neg<<endl;
            continue;
        }else{
            cout<<max<<endl;
        }
             
    }
    
    return 0;
}