#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int k,g,m;
    cin>>k>>g>>m;
    int glass=0,mug=0;
    while(k--){
        if(glass==g){
            glass=0;continue;
        }
        if(mug==0){
            mug=m;continue;
        }
        if(mug>g){
            mug-=(g-glass);
            glass=g;
        }else{
            glass=mug;
            mug=0;
        }
    }
    cout<<glass<<" "<<mug;
    
    return 0;
}