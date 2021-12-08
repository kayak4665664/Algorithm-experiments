// 0-1背包问题：给定n个物品和一个背包。第i个物品的重量是Wi，其价值为Vi，背包的容量为C，Wi、Vi和C均为整数。应如何选择装入背包的物品，使得装入的物品重量在不超过C的前提，总价值最大？物品只能全部装入或不装。
// 上机要求：输入任意n个物品的价值和重量，输出物品的装包方案（可输出装入背包的物品号）。
#include<iostream>
#include<algorithm>
using namespace std;

int v[50],w[50],bag[60][60];
string num[50];

int main(){
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;++i) cin>>num[i]>>w[i]>>v[i];//输入编号，重量，价值
    for(int i=1;i<=n;++i){
        for(int j=1;j<=c;++j){
            if(j<w[i-1]) bag[i][j]=bag[i-1][j];//此时装不下
            else bag[i][j]=max(bag[i-1][j],bag[i-1][j-w[i-1]]+v[i-1]);//此时可以装下，在装或不装中选出价值最大的
        }
    }
    cout<<endl<<"max="<<bag[n][c]<<endl;
    cout<<"bags=";
    int tmp=bag[n][c],i=n,j=c;
    while(tmp){//输出方案
        if(bag[i-1][j]==bag[i][j]) --i;
        else{
            cout<<num[i-1];
            tmp-=v[i-1];
            if(tmp) cout<<',';
            else cout<<endl;
            --i;
            j-=w[i-1];
        }
    }
    return 0;
}