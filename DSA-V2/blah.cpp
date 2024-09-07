#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int cnt=-1;
    int ans=0;
    for(int i=1;i<=n;i++){
        while(i!=0){
            int digit=i%10;
            if(digit>0){
                cnt+=1;
            }
            i/=10;
        }
        if(cnt!=0){
            continue;
        }else{
            ans++;
        }
    }
    cout<<ans;
return 0;
}