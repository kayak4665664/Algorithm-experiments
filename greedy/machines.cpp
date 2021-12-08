// 多机调度问题要求给出一种作业调度方案，使所给的n个作业（每个作业给定其所需的执行时间且每个作业不可分解为更小作业分别执行）在尽可能短的时间内由m台机器加工处理完成。
// 上机要求：输入为n个作业的执行所需时间和机器数量（均为整数），输出为每个作业的分配方案（即作业分配到哪个机器的哪个时间段，每个机器从初始时间0开始）
#include<iostream>
using namespace std;

int work[50][4],machine[50];
string wn[50];

int main(){
    int n,m,maxt=0;
    cin>>n>>m;
    for(int i=0;i<n;++i){//输入作业编号和所需时间
        cin>>wn[i]>>work[i][0];
        if(work[i][0]>maxt) maxt=work[i][0];
    }
    if(n<=m){//作业数量不超过机器数量
        cout<<endl<<"min time:"<<maxt<<endl;
        cout<<"可以为每个作业分配一台机器"<<endl;
    }else{//作业数量超过了机器数量
        for(int i=0;i<n;++i){//将作业按照所需时间从大到小排序
            for(int j=i+1;j<n;++j){
                if(work[j][0]>work[i][0]){
                    int tmp=work[j][0];
                    work[j][0]=work[i][0];
                    work[i][0]=tmp;
                    string str=wn[j];
                    wn[j]=wn[i];
                    wn[i]=str;
                }
            }
        }
        for(int i=0;i<n;++i){
            int c,min=60000;
            for(int j=0;j<m;++j){//选择最早空闲的机器
                if(!machine[j]){
                    c=j;
                    break;
                }
                if(machine[j]<min){
                    min=machine[j];
                    c=j;
                }
            }
            work[i][1]=c;
            work[i][2]=machine[c];
            machine[c]+=work[i][0];
            work[i][3]=machine[c];
            if(machine[c]>maxt) maxt=machine[c];//记录最大时间
        }
        cout<<endl<<"min time:"<<maxt<<endl;
        for(int i=0;i<n;++i){//输出方案
            cout<<wn[i]<<" machine:m"<<work[i][1]<<" begin:"<<work[i][2]<<" end:"<<work[i][3]<<endl;
        }
    }
    return 0;
}