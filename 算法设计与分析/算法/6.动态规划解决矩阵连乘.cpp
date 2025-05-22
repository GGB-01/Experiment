#include <iostream>
#include <climits>
using namespace std;

// 矩阵数量
const int N = 4;
// 矩阵维度数组，p[i]表示第i个矩阵的行数，p[i + 1]表示第i个矩阵的列数
int p[N + 1] = {5, 10, 6, 15, 8};
// 动态规划表，m[i][j]表示计算矩阵链M[i]...M[j]所需的最少乘法次数
int m[N + 1][N + 1];
// 记录最优分割点，s[i][j]表示在计算矩阵链M[i]...M[j]时的最优分割位置
int s[N + 1][N + 1];

// 计算矩阵链乘法的最少乘法次数并记录最优分割点
void matrixChainOrder() {
    // 初始化对角线元素，单个矩阵乘法次数为0
    for (int i = 1; i <= N; i++) {
        m[i][i] = 0;
    }

    // 考虑不同长度的矩阵链
    for (int l = 2; l <= N; l++) {
        for (int i = 1; i <= N - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            // 枚举分割点k
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// 打印最优括号化形式
void printOptimalParens(int i, int j) {
    if (i == j) {
        cout << "M" << i;
    } else {
        cout << "(";
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    matrixChainOrder();

    cout << "最少乘法次数: " << m[1][N] << endl;
    cout << "最优括号化形式: ";
    printOptimalParens(1, N);
    cout << endl;

    return 0;
}