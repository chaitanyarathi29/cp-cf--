#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    string s;cin>>s;
    int logo=0;
    int lt=0,pt=m;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(pt>0){
                pt--;
            }else{
                if(lt>0){
                    lt--;
                }else{
                    logo++;
                }
            }
        }
        if(s[i]=='2'){
            if(lt>0){
                lt--;
            }else{
                logo++;
            }
        }
        if(s[i]=='0'){
            lt=logo;
            pt=m;
        }
    }
    cout<<logo<<endl;
    
    return 0;
}