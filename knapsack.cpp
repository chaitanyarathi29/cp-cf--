#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>>ans;
void knapsackFn(int i, vector<pair<int,int>>&p, vector<pair<int,int>>temp){
    if(i>=p.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(p[i]);
    knapsackFn(i+1,p,temp);
    temp.pop_back();
    knapsackFn(i+1,p,temp);
}
int main(){

    int n,w;
    cin>>n>>w;
    vector<pair<int,int>>p(n);
    for(auto&it:p){
        cin>>it.first>>it.second;
    }
    vector<pair<int,int>>temp;
    knapsackFn(0,p,temp);

    int max=0;
    for(int i=0;i<ans.size();i++){
        int total=0;int sum=0;
        for(int j=0;j<ans[i].size();j++){
            total+=ans[i][j].first;
            sum+=ans[i][j].second;
        }
        if(total<=w){
            if(max<sum){
                max=sum;
            }
        }
    }
    cout<<max<<endl;
    return 0;
}