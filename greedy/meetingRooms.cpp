// 在充分数量的会议室安排n个活动（所有活动都得可分配到会议室，每个活动有一个起始时间和一个结束时间），并希望尽量少占用会议室，写算法求使用最少会议室的数量。
// 上机要求：输入为n个活动的起始和结束时间，输出为最少会议室数量。
// 提示：该问题即求n个活动的时间区间的最大重叠数
#include<iostream>
using namespace std;

int act[50][3],amt;
string num[50],room[50];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>num[i]>>act[i][0]>>act[i][1];//输入编号，起始时间，结束时间
    int fflag=0;
    while(!fflag){//当还有活动没有分配会议室时
        int flag=0,tmp;
        for(int i=0;i<n;++i){
            if(!act[i][2]){//当前活动没有分配会议室
                if(!flag){//选择结束时间最早的活动
                    room[amt]=""+num[i]+' ';
                    tmp=act[i][1];
                    act[i][2]=1;
                    ++flag;
                    continue;
                }
                if(act[i][0]>=tmp){//当前活动与本会议室已选活动不冲突且结束时间最早
                    room[amt]+=num[i]+' ';
                    tmp=act[i][1];
                    act[i][2]=1;
                }
            }
        }
        if(!flag) ++fflag;
        ++amt;
    }
    cout<<endl<<"min rome:"<<amt-1<<endl;//输出分配方案
    for(int i=0;i<amt-1;++i) cout<<"room"<<i<<':'<<room[i]<<endl;
    return 0;
}