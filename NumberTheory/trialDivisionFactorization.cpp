#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int>v;
    for(int i=2;i*i<=n;i++){
        if(!(n%i)){
            if(i!=n/i){
                v.push_back(n/i);
            }
            v.push_back(i);
        }
    }
    for(auto&it:v){
        cout<<it<<" ";
    }

    return 0;
}