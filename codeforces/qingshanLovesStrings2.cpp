#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        deque<char>d;
        int cnt1=0;int cnt0=0;
        for(auto&it:s){
            if(it=='1'){
                cnt1++;
            }else{
                cnt0++;
            }
            d.push_front(it);
        }
        if(cnt1!=cnt0 || (s.size()&1)){
            cout<<-1<<endl;
            continue;
        }
        vector<int>ans;
            char f=d.front();
            char b=d.back();
            int cnt=0;
            int temp=0;
            while(!d.empty()){
                f=d.front();
                b=d.back();
                if(f!=b){
                    d.pop_back();
                    d.pop_front();
                    temp++;
                }else{
                    if(f=='1'){
                        ans.push_back(0+temp);
                        d.push_back('1');
                        d.push_back('0');
                        cnt++;
                    }else{
                        ans.push_back(n-temp);
                        d.push_front('0');
                        d.push_front('1');
                        cnt++;
                    }
                    n+=2;
                }   
            }
            cout<<cnt<<endl;
            for(auto&it:ans){
                cout<<it<<" ";
            }
            cout<<endl;
    }

    return 0;
}