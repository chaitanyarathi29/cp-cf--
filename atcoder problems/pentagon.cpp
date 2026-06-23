#include <iostream>
using namespace std;

int main(){

    char s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;

    int len1 = abs(s2-s1);
    int len2 = abs(t2-t1);

    if((len1==1 || len1==4) && (len2==1 || len2==4)){
        cout<<"Yes"<<endl;
    }else{
        if((len1==2 || len1==3) && (len2==2 || len2==3)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}