#include <iostream>
#include <vector>
using namespace std;

int main(){

    int h,w;
    cin>>h>>w;
    vector<vector<char>>vec(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>vec[i][j];
        }    
    }

    int sr,er,sc,ec;
    sr=0;er=h-1;
    sc=0;ec=w-1;
    bool flag=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(vec[i][j]=='#'){
                flag=1;
                break;
            }
        }   
        if(flag) break;
        sr++;
    }
    flag=0;
    for(int i=h-1;i>=0;i--){
        for(int j=0;j<w;j++){
            if(vec[i][j]=='#'){
                flag=1;
                break;
            }
        }    
        if(flag) break;
        er--;
    }
    flag=0;
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(vec[j][i]=='#'){
                flag=1;
                break;
            }
        }    
        if(flag) break;
        sc++;
    }
    flag=0;
    for(int i=w-1;i>=0;i--){
        for(int j=0;j<h;j++){
            if(vec[j][i]=='#'){
                flag=1;
                break;
            }
        } 
        if(flag) break;
        ec--;
    }
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            cout<<vec[i][j];
        }   
        cout<<endl;
    }

    return 0;
}