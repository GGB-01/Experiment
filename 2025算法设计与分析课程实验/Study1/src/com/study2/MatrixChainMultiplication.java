package com.study2;

public class MatrixChainMultiplication {
    public static int recurMatrixChain(int i, int j, int[][] s, int[] p) {
        if (i == j) {
            return 0;
        }
        int u = recurMatrixChain(i, i, s, p) + recurMatrixChain(i + 1, j, s, p) + p[i - 1] * p[i] * p[j];
        s[i][j] = i;

        for (int k = i + 1; k < j; k++) {
            int t = recurMatrixChain(i, k, s, p) + recurMatrixChain(k + 1, j, s, p) + p[i - 1] * p[k] * p[j];
            if (t < u) {
                u = t;
                s[i][j] = k;
            }
        }
        return u;
    }

    public static void traceback(int i, int j, int[][] s) {
        if (i == j) {
            return;
        }
        traceback(i, s[i][j], s);
        traceback(s[i][j] + 1, j, s);
        System.out.println("Multiply A" + i + "," + s[i][j] + " and A" + (s[i][j] + 1) + "," + j);
    }

    public static void main(String[] args) {
        int[] p = {30, 35, 15, 5, 10, 20, 25};
        int[][] s = new int[p.length][p.length];

        int minComputation = recurMatrixChain(1, p.length - 1, s, p);
        System.out.println("矩阵的最少计算次数为：" + minComputation);
        System.out.println("矩阵最优计算次序为：");
        traceback(1, p.length - 1, s);
    }
}