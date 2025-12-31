#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin>>a>>b;
        int a1=a,b1=b;
        int cnt=0,cnt1=0;
        int i=1,twos=1;
        while(true) {
            if (i&1) {
                if(a<twos) break;
                a-=twos;
            } else {
                if(b<twos) break;
                b-=twos;
            }
            cnt++;twos *= 2;i++;
        }
        i=1;twos=1;
        while(true) {
            if(i&1) {
                if(b1<twos)break;
                b1-=twos;
            }else{
                if(a1<twos) break;
                a1-=twos;
            }
            cnt1++;twos*=2;i++;
        }

        cout << max(cnt,cnt1)<< endl;
    }
    return 0;
}
