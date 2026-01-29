#include <iostream>
#include <vector>
using namespace std;

long long const MOD = 1e9+7;
int main(){

    int n;cin>>n;
    vector<int>dp(n+1,0);
    
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(j<=i){
                dp[i] = (dp[i] + dp[i-j])%MOD;
            }
        }
    }

    cout<<dp[n]<<endl;

    return 0;
}

    // dp[n]=1;
    // for(int i=n;i>=0;i--){
    //     for(int j=1;j<=6;j++){
    //         if(i+j<=n){
    //             dp[i] = dp[i] + dp[i+j];
    //         }
    //     }
    // }

    // cout<<dp[0]<<endl;