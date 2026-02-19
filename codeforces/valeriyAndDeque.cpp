#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
int main(){

    int n,q;
    cin>>n>>q;
    vector<int>a(n,0);
    deque<int>d;
    int max=-1;
    for(auto&it:a){
        cin>>it;
        d.push_back(it);
        if(max<it){
            max=it;
        }
    }
    vector<ll>qu(q,0);
    for(auto&it:qu){
        cin>>it;
    }
    vector<pair<int,int>>ans;
    int front = d.front();
    int cnt=0;
    while(front!=max){
        int first=d.front();
        d.pop_front();
        int second=d.front();
        d.pop_front();
        ans.push_back({first,second});
        if(first>second){
            d.push_front(first);
            d.push_back(second);
        }else{
            d.push_front(second);
            d.push_back(first);
        }
        front=d.front();
        cnt++;
    }
    
    vector<int>v;
    d.pop_front();
    while(!d.empty()){
        v.push_back(d.front());
        // cout<<d.front()<<" ";
        d.pop_front();
    }
    // cout<<endl;
    // for(auto&it:v){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<qu.size();i++){
        if(qu[i]<=cnt){
            cout<<ans[qu[i]-1].first<<" "<<ans[qu[i]-1].second<<endl;
        }else{
            ll rem = ((qu[i]-cnt-1)%v.size());
            cout<<max<<" "<<v[rem]<<endl;
        }
    }
    

    return 0;
}