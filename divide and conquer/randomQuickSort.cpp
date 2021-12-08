// 合并排序或快速排序（二选一）：排序问题设为对一组数值从小到大排序，采用合并排序或快速排序两种分治思路实现排序算法（有能力可考虑实现自然合并排序和随机化快速排序）。
// 实现要求：可以任意给定一组不同个数、不同数值的数据；输出排序后结果和排序时间。
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;

int list[1000];

int randomPartition(int list[],int low,int high){
    int pos=rand()%(high-low)+low;//随机生成位置
    int tmp=list[pos];
    list[pos]=list[low];
    list[low]=tmp;
    list[0]=list[low];//用子表的第一个记录作枢轴记录
    while(low<high){//从表的两端交替地向中间扫描
        while(low<high&&list[high]>=list[0]) --high;
        list[low]=list[high];//将比枢轴记录小的记录移到低端
        while(low<high&&list[low]<=list[0]) ++low;
        list[high]=list[low];//将比枢轴记录大的记录移到高端
    }
    list[low]=list[0];//枢轴记录到位
    return low;//返回枢轴位置
}

void rQsort(int list[],int low,int high){//随机化快速排序
    if(low<high){//长度大于1
        int pivotloc=randomPartition(list, low, high);
        //将list一分为二
        rQsort(list,low,pivotloc-1);
        //对第子表递归排序，pivotloc是枢轴位置
        rQsort(list,pivotloc+1,high);
        //对高子表递归排序
    }
}

void randomQuickSort(int n){//随机化快速排序
    srand((int)time(0));
    for(int i=1;i<=n;++i){
        list[i]=rand()%1000;
        cout<<list[i]<<' ';
    }//生成随机数据
    cout<<endl<<endl;
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    rQsort(list,1,n);//排序
    QueryPerformanceCounter(&t2);
    for(int i=1;i<=n;++i) cout<<list[i]<<' ';
    cout<<endl;
    cout<<"time="<<(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart<<'s'<<endl<<endl;
}

int main(){
    int n;
    while(cin>>n) randomQuickSort(n);
    return 0;
}