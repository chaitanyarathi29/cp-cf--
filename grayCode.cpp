#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    int n;cin>>n;
    vector<string>v = { "0", "1" };
    for(int i=2;i<=n; i++){
        int end=v.size()-1;
        while(end>=0){
            v.push_back(v[end]);
            end--;
        }
        int cnt=pow(2,i);
        for(int j=1;j<=cnt;j++){
            if(j<=(cnt/2)) v[j-1]="0"+v[j-1];
            else v[j-1]="1"+v[j-1];
        }
    }
    for(auto it:v)cout<<it<<endl;
    return 0;
}