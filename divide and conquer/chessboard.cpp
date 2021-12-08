// 棋盘覆盖：在一个2^k * 2^k个方格组成的棋盘中,恰有一方格残缺, 残缺方格的位置有2^2k种。故对任何k≥0,残缺棋盘有2^2k种. 要求用4种L型骨牌覆盖残缺棋盘上的所有方格，且任何2个L型骨牌不得重叠覆盖。求L型骨牌的覆盖方案。
// 实现要求：可以设定棋盘的方格行数和残缺方格的位置（棋盘行号和列号）；要求输出棋盘覆盖结果参见课件PPT。（棋盘以二维数组存储，每个方格对应一个数组元素通过赋相应数值表示覆盖结果，特殊方格对应的数组元素以数值1表示，每次用L型骨牌覆盖方格通过对应数组元素赋以相同数值表示，按照分治法的L型骨牌覆盖次序，对应数组元素的赋值从2开始递增）
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int board[32][32], cnt;

void place(int tr, int tc) {
    for (int i = tr; i < tr + 2; ++i) {
        for (int j = tc; j < tc + 2; ++j) {
            if (!board[i][j]) board[i][j] = cnt;
        }
    }
    ++cnt;
}//放置骨牌

void place(int tr, int tc, int r, int c) {
    for (int i = tr; i < tr + 2; ++i) {
        for (int j = tc; j < tc + 2; ++j) {
            if (!board[i][j] && (i != r || j != c)) board[i][j] = cnt;
        }
    }
    ++cnt;
}//放置骨牌

void chessBoard(int tr, int tc, int dr, int dc, int size) {
    if (size == 2) {//直接放置骨牌
        place(tr, tc);
        return;
    }
    size /= 2;
    int rpos = tr + size, cpos = tc + size;
    int flag;
    if (dr < rpos && dc < cpos) {
        //如果特殊方格在左上子棋盘中
        flag = 2;
        place(rpos - 1, cpos - 1, rpos - 1, cpos - 1);
        //在棋盘中心放置骨牌
        chessBoard(tr, tc, dr, dc, size);
        //递归进入左上子棋盘
    }
    if (dr < rpos && dc >= cpos) {
        //如果特殊方格在右上子棋盘中
        flag = 1;
        place(rpos - 1, cpos - 1, rpos - 1, cpos);
        //在棋盘中心放置骨牌
        chessBoard(tr, cpos, dr, dc, size);
        //递归进入右上子棋盘
    }
    if (dr >= rpos && dc < cpos) {
        //如果特殊方格在左下子棋盘中
        flag = 3;
        place(rpos - 1, cpos - 1, rpos, cpos - 1);
        //在棋盘中心放置骨牌
        chessBoard(rpos, tc, dr, dc, size);
        //递归进入左下子棋盘
    }
    if (dr >=rpos && dc >= cpos) {
        //如果特殊方格在右下子棋盘中
        flag = 4;
        place(rpos - 1, cpos - 1, rpos, cpos);
        //在棋盘中心放置骨牌
        chessBoard(rpos, cpos, dr, dc, size);
        //递归进入右下子棋盘
    }
    if (flag != 2) chessBoard(tr, tc, rpos - 1, cpos - 1, size);//特殊方格不在左上子棋盘，递归进入左上子棋盘
    if (flag != 1) chessBoard(tr, cpos, rpos - 1, cpos, size);//特殊方格不在右上子棋盘，递归进入右上子棋盘
    if (flag != 3) chessBoard(rpos, tc, rpos, cpos - 1, size);//特殊方格不在左下子棋盘，递归进入左下子棋盘
    if (flag != 4) chessBoard(rpos, cpos, rpos, cpos, size);//特殊方格不在右下子棋盘，递归进入右下子棋盘
}

int main() {
    int size, dr, dc;
    while (cin >> size >> dr >> dc) {
        cnt = 2;
        memset(board, 0, sizeof(board));
        board[dr][dc] = 1;
        chessBoard(0, 0, dr, dc, size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << setiosflags(ios::left) << setw(3) << board[i][j];
                if (j == size - 1) cout << endl;
                else cout << ' ';
            }
        }
        cout << endl << endl;
    }
    return 0;
}
