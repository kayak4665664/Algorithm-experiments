// 汉诺塔：有三个基座A,B,C,最初A上有n个大小不等的圆盘，且大盘在下、小盘在上。要求把圆盘从A移到B，移动过程中可以借助C，但每次只能移动一个盘，并且3个基座上的圆盘都保持大盘在下，小盘在上。求给定n个圆盘的移动方案。
// 实现要求：可以设定圆盘数n的值；要求打印输出每一步的移动过程，如把x号圆盘从“？”基座移动到“？”基座。圆盘按最初A基座上从上到下顺序从1到n编号。
#include<iostream>
using namespace std;

void hanoi(int n,char a,char b,char c){
    if(n==1){//当n=1时，只需要移动一个盘子到目标基座
        cout<<n<<':'<<a<<"->"<<c<<endl;
        return;
    }
    hanoi(n-1,a,c,b);
    //把前n-1个盘子看成一个整体，从a移动到b
    cout<<n<<':'<<a<<"->"<<c<<endl;
    //把第n个盘子从a移动到c
    hanoi(n-1,b,a,c);
    //把前n-1个盘子看成一个整体，从b移动到c
}

int main(){
    int n;
    while(cin>>n){hanoi(n,'A','B','C');}
    return 0;
}
