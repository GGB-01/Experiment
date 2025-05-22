#include <iostream>
#include <string>
using namespace std;

// 计算最长公共子序列的长度并记录状态
void longestCommonSubsequence(const string& X, const string& Y, int m, int n) {
    // 动态规划表，dp[i][j]表示X的前i个字符和Y的前j个字符的最长公共子序列长度
    int dp[m + 1][n + 1];
    // 方向数组，用于回溯构造最长公共子序列
    int dir[m + 1][n + 1]; 

    // 初始化dp数组第一行和第一列
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    // 动态规划填充dp数组
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dir[i][j] = 1;  // 表示斜上方（匹配）
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                dir[i][j] = 2;  // 表示上方
            } else {
                dp[i][j] = dp[i][j - 1];
                dir[i][j] = 3;  // 表示左方
            }
        }
    }

    // 回溯构造最长公共子序列
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (dir[i][j] == 1) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (dir[i][j] == 2) {
            i--;
        } else {
            j--;
        }
    }

    cout << "最长公共子序列长度为: " << dp[m][n] << endl;
    cout << "最长公共子序列为: " << lcs << endl;
}

int main() {
    string X = "BCDAB";
    string Y = "ABCBB";
    int m = X.size();
    int n = Y.size();

    longestCommonSubsequence(X, Y, m, n);

    return 0;
}