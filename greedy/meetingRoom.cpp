// 在一个会议室安排n个活动（每个活动有一个起始时间和一个结束时间，同一时间会议室内只能安排一个活动），并希望尽量多安排活动，写算法求可安排最多活动的数量及安排方案。
// 上机要求：输入为n个活动的起始和结束时间，输出为可安排最多活动的数量及各活动是否排入会议室。
#include<iostream>
using namespace std;

int act[50][2];
string num[50];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>num[i]>>act[i][0]>>act[i][1];//输入编号，起始时间，结束时间
    int tmp=act[0][1],cnt=1;
    cout<<endl<<"activities:";
    int flag=0;
    for(int i=0;i<n;++i){
        if(!flag){//选择结束时间最早的活动
            cout<<num[i]<<' ';
            ++flag;
            continue;
        }
        if(act[i][0]>tmp){//当前活动与已选活动不冲突且结束时间最早
            cout<<num[i]<<' ';
            tmp=act[i][1];
            ++cnt;
        }
    }
    cout<<endl<<"sum:"<<cnt<<endl;
    return 0;
}