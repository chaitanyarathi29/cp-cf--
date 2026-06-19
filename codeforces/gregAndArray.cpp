#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,m,k;
    cin>>n>>m>>k;

    vector<long long>vec(n,0);
    for(auto&it:vec){
        cin>>it;
    }

    vector<pair<pair<long ,long>,long>>op;
    int itt=m;
    while(itt--){
        int l,r,d;
        cin>>l>>r>>d;
        op.push_back({{l,r},d});
    }
    vector<long long>times(m+1,0);
    while(k--){
        int fir,sec;
        cin>>fir>>sec;
        times[fir-1]++;
        times[sec]--;
    }
    for(int i=1;i<m;i++){
        times[i]+=times[i-1];
    }
    vector<long long>ans(n,0);
    for(int i=0;i<m;i++){
        int left = op[i].first.first;
        int right = op[i].first.second;
        int val = op[i].second;
    
        long long value=(times[i]*val);
        ans[left-1]+=value;
        if(right>n-1) continue;
        ans[right]-=value;
    }

    for(int i=1;i<n;i++){
        ans[i]+=ans[i-1];
    }
    
    for(int i=0;i<n;i++){
        vec[i]+=ans[i];
    }

    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    
    return 0;
}