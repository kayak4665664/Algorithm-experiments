// 矩阵连乘：给定n个矩阵{A1,A2,…,An}，其中Ai与Ai-1是可相乘的。确定一个计算次序，使计算矩阵连乘积A1A2…An所需计算量最少。
// 上机要求：输入为一个记录n个矩阵的行数和列数的数组，如{X1,X2,X3,…,Xn,Xn+1},其中X1和X2为A1矩阵的行数和列数，X2和X3为A2矩阵的行数和列数，Xn和Xn+1为An矩阵的行数和列数。输出为计算量最小的矩阵连乘加括号方式，如((A1A2)(A3(A4A5)))
#include<iostream>
using namespace std;

long long m[10][10],mat[10][2],com[10][10],data[12][2],data1[10][10];

int mc(int i,int j){
    long long u,t;
    if(m[i][j]>0) return m[i][j];//如果已经求解过了，直接返回
    if(i==j) return 0;//直接返回
    com[i][j]=i;
    u=mc(i+1,j)+mat[i][0]*mat[i][1]*mat[j][1];//初值
    for(int k=i+1;k<j;++k){//计算每一种可能
        t=mc(i,k)+mc(k+1,j)+mat[i][0]*mat[k][1]*mat[j][1];
        if(t<u){//如果现在的比初值更小
            u=t;
            com[i][j]=k;//记录当前的最小值
        }
    }
    m[i][j]=u;//记录最小值
    return u;
}

void Data(int i,int j){
    if(i+1==j) return;
    if(data1[i][j]) return;
    ++data[i][0];
    ++data[j][1];
    ++data1[i][j];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>mat[i][0]>>mat[i][1];//依次输入行标和列标
    cout<<"The least:"<<mc(0,n-1)<<endl;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            Data(i,com[i][j]+1);
            Data(com[i][j]+1,j+1);
        }
    }
    for(int i=0;i<=n;++i){//输出计算量最小的矩阵连乘加括号方式
        if(data[i][1]){
            for(int j=0;j<data[i][1];++j) cout<<')';
        }
        if(data[i][0]){
            for(int j=0;j<data[i][0];++j) cout<<'(';
        }
        if(i!=n) cout<<'A'<<i;
    }
    cout<<endl;
    return 0;
}