#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int mini=100000007;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    double l=0;double h=1e8;
    for(int i=0;i<150;i++){
        double mid=l+(h-l)/2;
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(long long)v[i]/mid;
        }
        if(cnt>=k){
            l=mid;
        }else{
            h=mid;
        }
    }
    cout<<setprecision(8)<<fixed<<h<<endl;

    return 0;
}