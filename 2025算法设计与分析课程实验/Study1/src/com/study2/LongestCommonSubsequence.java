package com.study2;

public class LongestCommonSubsequence {
    public static int longestCommonSubsequence(char[] x, char[] y) {
        int m = x.length;
        int n = y.length;
        int[][] dp = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (x[i] == y[j]) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                } else {
                    if (i == 0) {
                        dp[i][j] = j > 0? dp[i][j - 1] : 0;
                    } else if (j == 0) {
                        dp[i][j] = i > 0? dp[i - 1][j] : 0;
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    public static void main(String[] args) {
        char[] x = {' ', 'A', 'B', 'C', 'B', 'D', 'A', 'B'};
        char[] y = {' ', 'B', 'D', 'C', 'A', 'B', 'A'};

        int lcsLength = longestCommonSubsequence(x, y);
        System.out.println("最长公共子序列的长度为：" + lcsLength);
    }
}