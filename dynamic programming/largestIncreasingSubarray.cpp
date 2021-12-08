// 最大增序子数组：找出长度为n的数组中最大的增序子数组。子数组中的数要求与原数组中的数的前后位置关系不变，且子数组中数的个数最多。（建议运用课程讲解的最长公共子序列方法来求解）
//    提示：可以在已有数组基础上通过从小到大排序构造一个新数组，对两个数组运用类似最长公共子序列的方法求解。
// 上机要求：输入为一个包含任意个数数字的数组，输出最长增序子数据组中包含的数字。
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

int data[150],data1[150],note[160][160][2],ans[150],cnt;

void lcs(int n){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(data[i-1]==data1[j-1]){//相等则取左上角数+1
                note[i][j][0]=note[i-1][j-1][0]+1;
                note[i][j][1]=1;//记录方向为左上
            }else if(note[i-1][j][0]>=note[i][j-1][0]){//取上面一行的数字
                note[i][j][0]=note[i-1][j][0];
                note[i][j][1]=2;//记录方向为上
            }else{
                note[i][j][0]=note[i][j-1][0];//取左边一列的数字
                note[i][j][1]=3;//记录方向为下
            }
        }
    }
}

int main(){
    srand((int)time(0));
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        data1[i]=data[i]=rand()%100;
        cout<<data[i]<<' ';
    }
    cout<<endl;
    sort(data1,data1+n);
    lcs(n);
    cnt=note[n][n][0];
    int tmp=cnt,i=n,j=n;
    while(tmp){
        if(note[i][j][1]==1){//向左上走
            ans[--tmp]=data1[j-1];
            --i;
            --j;
        }else if(note[i][j][1]==2) --i;//向上走
        else --j;//向左走
    }
    for(int i=0;i<cnt;++i){//输出结果
        cout<<ans[i];
        if(i==cnt-1) cout<<endl;
        else cout<<' ';
    }
    return 0;
}
