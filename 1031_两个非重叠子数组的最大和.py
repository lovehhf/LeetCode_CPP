# -*- coding:utf-8 -*-

__author__ = 'huanghf'

"""
给出非负整数数组 A ，返回两个非重叠（连续）子数组中元素的最大和，子数组的长度分别为 L 和 M。（这里需要澄清的是，长为 L 的子数组可以出现在长为 M 的子数组之前或之后。）

从形式上看，返回最大的 V，而 V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) 并满足下列条件之一：

 

0 <= i < i + L - 1 < j < j + M - 1 < A.length, 或
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 

示例 1：

输入：A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
输出：20
解释：子数组的一种选择中，[9] 长度为 1，[6,5] 长度为 2。
示例 2：

输入：A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
输出：29
解释：子数组的一种选择中，[3,8,1] 长度为 3，[8,9] 长度为 2。
示例 3：

输入：A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
输出：31
解释：子数组的一种选择中，[5,6,0,9] 长度为 4，[0,3,8] 长度为 3。
 

提示：

L >= 1
M >= 1
L + M <= A.length <= 1000
0 <= A[i] <= 1000
"""


class Solution(object):
    def get_max_range_sum(self, A, L):
        """
        获取最大的子数组和
        :param A:
        :param L:
        :return:
        """
        n = len(A)
        if n < L:
            return 0
        if n == L:
            return sum(A)
        if L == 1:
            return max(A)

        # s = sum(A[:L])
        max_num = 0
        for i in range(n - L + 1):
            s = sum(A[i:i+L])
            if s > max_num:
                max_num = s
        return max_num

    def maxSumTwoNoOverlap(self, A, L, M):
        n = len(A)
        if L + M == n:
            return sum(A)
        max_sum = 0
        for i in range(0,n-L+1):
            sum_L = sum(A[i:i+L])
            # 从不重叠的区间找出最大值
            max_M = max(self.get_max_range_sum(A[:i], M), self.get_max_range_sum(A[i + L:], M))
            if sum_L + max_M > max_sum:
                max_sum = sum_L + max_M
        return max_sum

    # def check(self, a, b):
    #     """
    #     判断两个区间是否有重叠的函数,有重叠则返回True
    #     :param a:
    #     :return:
    #     """
    #     if (a[0] <= b[0] and b[0] <= a[1]) or (b[0] <= a[0] and a[0] <= b[1]):
    #         return True
    #     return False
    #
    # def maxSumTwoNoOverlap(self, A, L, M):
    #     """
    #     :type A: List[int]
    #     :type L: int
    #     :type M: int
    #     :rtype: int
    #     """
    #     n = len(A)
    #     if L+M==n:
    #         return sum(A)
    #     L_list = []
    #     M_list = []
    #     for i in range(n - L + 1):
    #         L_list.append([(i, i + L - 1), sum(A[i:i + L])])
    #     for i in range(n - M + 1):
    #         M_list.append([(i, i + M - 1), sum(A[i:i + M])])
    #     L_list.sort(key=lambda x: x[1], reverse=True)
    #     M_list.sort(key=lambda x: x[1], reverse=True)
    #
    #
    #     # 两个指针从左往右遍历找到L,M不重叠的
    #     # i, j = 0, 0
    #     # while self.check(L_list[i][0], M_list[j][0]):
    #     #     if L_list[i][1] + M_list[j+1][1] > L_list[i+1][1] + M_list[j][1]:
    #     #         j+=1
    #     #     else:
    #     #         i+=1
    #     print(L_list)
    #     print(M_list)
    #     # return L_list[i][1] + M_list[j][1]


A = [87,42,40,86,93,4,18,28,59,30,6,51,99,46,40,24,19,98,40,41]

L = 1
M = 10
# A = [419,782,330,870,77,808,957,719,501,913,781,947,976,175,846,213,994,151,69,873,130,185,557,181,601,324,302,72,145,118,192,518,29,982,879,678,190,497,950,994,955,772,943,899,885,701,766,894,446,717,323,328,602,434,71,226,918,635,968,870,954,118,274,51,718,101,327,311,896,669,359,724,115,506,639,62,251,1,934,594,965,370,305,89,3,469,713,941,710,328,26,168,22,571,611,376,538,347,458,31,737,907,485,696,973,719,735,193,148,863,352,960,447,511,926,48,986,995,411,218,417,784,862,295,544,717,544,583,23,27,419,698,485,263,295,973,591,329,31,575,51,709,556,174,215,246,681,303,842,649,71,457,762,126,175,789,655,667,119,164,712,468,738,570,991,699,849,765,876,895,773,574,642,754,716,418,831,426,592,19,402,637,76,71,820,966,663,758,790,231,624,462,234,987,158,337,523,122,22,415,854,503,67,691,803,562,265,138,804,786,685,695,849,915,734,275,224,734,904,836,759,166,268,231,666,764,486,935,450,677,922,912,409,517,860,796,40,833,451,344,606,247,2,463,664,382,535,716,221,95,644,339,996,101,293,904,305,22,36,874,873,521,968,802,457,553,612,517,270,535,773,347,17,264,39,407,81,643,363,548,603,592,376,184,373,475,466,81,957,405,382,392,269,266,517,854,808,10,657,25]
#
# L = 261
# M = 15
s = Solution()
print(s.maxSumTwoNoOverlap(A, L, M))
