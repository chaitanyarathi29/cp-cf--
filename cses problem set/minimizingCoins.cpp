#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,s;
    cin>>n>>s;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }

    vector<int>dp(1e6+1,1e6+2);

    dp[0]=0;
    int coins=0;
    int sum=0;
    for(int i=0;i<v.size();i++){
        coins=1;sum=v[i];
        for(int j=0;j<v.size();j++){
            
        }

    }

    return 0;
}