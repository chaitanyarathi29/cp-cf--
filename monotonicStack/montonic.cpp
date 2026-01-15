#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int>v(n);
    vector<int>ans(n);
    for(auto&it:v){
        cin>>it;
    }
    stack<int>s;
    //NSL
    int i=0;
    while(i<n){
        if(!s.empty() && s.top()>=v[i]){
            while(s.top()>=v[i]){
               s.pop();
            }
        }
        if(!s.empty() && s.top()<v[i]){
            ans[i]=s.top();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        s.push(v[i]);
        i++;
    } //precompute O(n)

    for(auto&it:ans){
        cout<<it<<" ";
    }
    
    return 0;
}