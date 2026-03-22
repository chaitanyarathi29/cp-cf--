#include <iostream>
#include <vector>
#include <iomanip>
using ll = long long;
using namespace std;

int main(){

    int n;cin>>n;
    vector<ll>x(n,0);
    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>x[i]>>v[i];
    }
    double l=0;double h=2e9;
    for(int i=0;i<100;i++){
        double mid=l+(h-l)/2;
        double x1=x[0]-(mid*v[0]);double y1=x[0]+(mid*v[0]);
        bool f=1;
        for(int j=1;j<n;j++){
            double y2=x[j]+(mid*v[j]);
            double x2=x[j]-(mid*v[j]);
            double maxx=max(x1,x2);
            double miny=min(y1,y2);
            if(maxx>miny){
                f=0; break;
            }
            x1=maxx;y1=miny;
        }
        if(f){
            h=mid;
        }else{  
            l=mid;
        }
    }
    cout<<setprecision(7)<<fixed<<h<<endl;
    return 0;
}