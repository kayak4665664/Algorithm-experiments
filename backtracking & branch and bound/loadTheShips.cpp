// 2艘船的最优装载问题：n个集装箱装到2艘载重量分别为c1,c2的货轮,其中集装箱i的重量为wi且(w1+w2+...+wn)<=C1+C2问题要求找到一个合理的装载方案可将这n个货箱装上这2艘轮船。
// 提示：若上述装载问题有解, 采用如下策略可得一个装载方案:(1)将第一艘轮船尽可能装满（等价于一个特殊的0-1背包问题）; (2)将剩余的集装箱装到第二艘船上。
// 实现要求：输入第一艘船载重量，待装载货物数量及各货物重量；输出各货物在第一艘船的装载方案（是否装船）以及最优装载重量。
#include<iostream>
using namespace std;

int w[50],best[50],tmp[50],maxw,tmpw,amt,C;
string num[50];

int bound(int n){//当前扩展节点集装箱重量+剩余集装箱重量
    int lmw=tmpw;
    while(n<amt) lmw+=w[n++];
    return lmw;
}

void BT(int n){
    if(n>amt-1){//到了叶子节点
        if(tmpw>maxw){//记录
            maxw=tmpw;
            for(int i=0;i<amt;++i) best[i]=tmp[i];
        }
        return;
    }
    if(tmpw+w[n]<=C){//装载当前集装箱，搜索左子树
        tmpw+=w[n];
        tmp[n]=1;
        BT(n+1);
        tmpw-=w[n];//回溯
        tmp[n]=0;
    }
    if(bound(n+1)>maxw) BT(n+1);//装不下当前集装箱，搜索右子树
}

int main(){
    cin>>amt>>C;
    for(int i=0;i<amt;++i) cin>>num[i]>>w[i];
    BT(0);
    cout<<endl<<"max:"<<maxw<<endl;
    int first=0;
    cout<<"ship0:";
    for(int i=0;i<amt;++i){//输出装载方案
        if(best[i]){
            if(!first){
                cout<<num[i];
                ++first;
            }else cout<<','<<num[i];
        }
        if(i==amt-1) cout<<endl;
    }
    cout<<"ship1:";
    first=0;
    for(int i=0;i<amt;++i){//输出装载方案
        if(!best[i]){
            if(!first){
                cout<<num[i];
                ++first;
            }else cout<<','<<num[i];
        }
        if(i==amt-1) cout<<endl;
    }
    return 0;
}
