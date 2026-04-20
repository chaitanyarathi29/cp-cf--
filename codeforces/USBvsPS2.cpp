#include <iostream>
#include <vector>
#include <queue>

using ll=long long;
using namespace std;

int main(){

    int a,b,c;
    cin>>a>>b>>c;

    int n;cin>>n;
    priority_queue<ll,vector<ll>,greater<ll>>usb;
    priority_queue<ll,vector<ll>,greater<ll>>ps2;
    
    for(int i=0;i<n;i++){
        int temp;string s;
        cin>>temp>>s;
        if(s=="USB"){
            usb.push(temp);
        }else{
            ps2.push(temp);
        }
    }

    ll cnt=0,total=0;

    while(!usb.empty() && a>0){
        total+=usb.top();
        usb.pop();
        a--;cnt++;
    }

    while(!ps2.empty() && b>0){
        total+=ps2.top();
        ps2.pop();
        b--;cnt++;
    }

    while((!usb.empty() || !ps2.empty()) && c>0){
        if(!usb.empty() && !ps2.empty()){
            if(usb.top() < ps2.top()){
                total+=usb.top();
                usb.pop();
            }else{
                total+=ps2.top();
                ps2.pop();
            }
            c--;cnt++;
            continue;
        }        
        if(usb.empty()){
            total+=ps2.top();
            ps2.pop();c--;cnt++;continue;
        }
        if(ps2.empty()){
            total+=usb.top();
            usb.pop();c--;cnt++;continue;
        }
    }
    cout<<cnt<<" "<<total<<endl;

    return 0;
}