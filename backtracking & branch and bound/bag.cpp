// 0-1背包问题：给定n个物品和一个背包。第i个物品的重量是Wi，其价值为Vi，背包的容量为C，Wi、Vi和C均为整数。应如何选择装入背包的物品，使得装入的物品重量在不超过C的前提，总价值最大？物品只能全部装入或不装。
// 实现要求：输入任意n个物品的价值和重量，输出物品的装包方案（可输出装入背包的物品号）。
// 提示：价值限界函数：当前扩展节点背包价值+剩余物品价值是否大于已找到可行解中的最高价值
#include<iostream>
using namespace std;

int w[50],v[50],best[50],tmp[50],maxv,tmpv,tmpw,amt,C;
string num[50];

int bound(int n){//当前扩展节点背包价值+剩余物品价值
    int lmv=tmpv;
    while(n<amt) lmv+=v[n++];
    return lmv;
}

void BT(int n){
    if(n>amt-1){//到了叶子节点
        if(tmpv>maxv){//记录
            maxv=tmpv;
            for(int i=0;i<amt;++i) best[i]=tmp[i];
        }
        return;
    }
    if(tmpw+w[n]<=C){//装入当前物品，搜索左子树
        tmpw+=w[n];
        tmpv+=v[n];
        tmp[n]=1;
        BT(n+1);
        tmpw-=w[n];//回溯
        tmpv-=v[n];
        tmp[n]=0;
    }
    if(bound(n+1)>maxv) BT(n+1);//装不下当前物品，搜索右子树
}

int main(){
    cin>>amt>>C;
    for(int i=0;i<amt;++i) cin>>num[i]>>w[i]>>v[i];
    BT(0);
    cout<<endl<<"max:"<<maxv<<endl<<"bags:";
    int first=0;
    for(int i=0;i<amt;++i){//输出装包方案
        if(best[i]){
            if(!first){
                cout<<num[i];
                ++first;
            }else cout<<','<<num[i];
        }
        if(i==amt-1) cout<<endl;
    }
    return 0;
}
