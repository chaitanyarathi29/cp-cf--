#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){

    ll n,c;
    cin>>n>>c;
    ll itt = n;
    map<ll,int>mp;
    vector<ll>vec;
    vector<pair<pair<ll,ll>,ll>>ops;
    while(itt--){
        int left,right,val;
        cin>>left>>right>>val;
        if(!mp[left]){
            vec.push_back(left);
            mp[left]=1;
        }
        if(!mp[right+1]){
            vec.push_back(right+1);
            mp[right+1]=1;
        }
        ops.push_back({{left,right+1},val});
    }
    sort(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++){
        mp[vec[i]]=i;
    }
    vector<ll>ans(vec.size(),0);
    for(int i=0;i<ops.size();i++){
        ll left = ops[i].first.first;
        ll right = ops[i].first.second;
        ll val = ops[i].second;
        ans[mp[left]]+=val;
        ans[mp[right]]-=val;
    }

    for(int i=1;i<ans.size();i++){
        ans[i]+=ans[i-1];
    }
    ll answer=0;
    for(int i=1;i<vec.size();i++){
        ll diff = vec[i]-vec[i-1];
        answer+=diff* (min(ans[i-1], c));
    }

    cout<<answer;

    return 0;
}

//keep values of days that are going to incurr a change after repeating values and map them with the actual 1e9 value...
//day1  day2  day3  day4  day5  day6  day7  day8  day9
// 0      6     6    15     15    9     9     9     0
//query 2 5 6 and 4 8 9   

// see changes in  2,4,6,9  therefore Ai, Bi+1 indices changes of query therefore we will map it and then calculate the total value....
