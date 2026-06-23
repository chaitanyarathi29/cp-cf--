#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long;

int countInv(vector<int>vec){

    int cnt=0;
    for(int i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++){
            if(vec[i]>vec[j]){
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){

    int h,w;
    cin>>h>>w;

    vector<vector<ll>>a(h,vector<ll>(w,0));
    vector<vector<ll>>b(h,vector<ll>(w,0));

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }   
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>b[i][j];
        }   
    }

    vector<int>row(h,0);
    vector<int>col(w,0);
    iota(row.begin(),row.end(),0);
    iota(col.begin(),col.end(),0);
    int ans=1e9;
    do{
        do{
            bool ok=true;
            for(int i=0;i<row.size();i++){
                for(int j=0;j<col.size();j++){
                    if(a[row[i]][col[j]] != b[i][j]){
                        ok=false;
                    }
                }   
            }

            if(ok){
                int mini = countInv(row) + countInv(col);
                ans = min(ans,mini);
            }

        }while(next_permutation(col.begin(),col.end()));

    }while(next_permutation(row.begin(),row.end()));

    if(ans==1e9){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }

    return 0;
}