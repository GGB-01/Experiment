package com.study2;
public class MaximumSubarraySum {
    public static int maxSubArraySum(int[] a) {
        int n = a.length;
        int maxEndingHere = a[0];
        int maxSoFar = a[0];

        for (int i = 1; i < n; i++) {
            maxEndingHere = Math.max(a[i], maxEndingHere + a[i]);
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }

    public static void main(String[] args) {
        int[] a = {-2, 11, -4, 13, -5, -2};

        int maxSum = maxSubArraySum(a);
        System.out.println("最大字段和为：" + maxSum);
    }
}