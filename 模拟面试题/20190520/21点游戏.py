# -*- coding:utf-8 -*-

__author__ = 'huanghf'

"""
爱丽丝参与一个大致基于纸牌游戏 “21点” 规则的游戏，描述如下：

爱丽丝以 0 分开始，并在她的得分少于 K 分时抽取数字。 抽取时，她**从 [1, W] 的范围中随机获得一个整数作为分数进行累计**，其中 W 是整数。
**每次抽取都是独立的，其结果具有相同的概率。**

当爱丽丝**获得不少于 K 分时，她就停止抽取数字**。 爱丽丝的**分数不超过 N 的概率是多少**？

示例 1：

输入：N = 10, K = 1, W = 10
输出：1.00000
说明：爱丽丝得到一张卡，然后停止。
示例 2：

输入：N = 6, K = 1, W = 10
输出：0.60000
说明：爱丽丝得到一张卡，然后停止。
在 W = 10 的 6 种可能下，她的得分不超过 N = 6 分。
示例 3：

输入：N = 21, K = 17, W = 10
输出：0.73278
提示：

0 <= K <= N <= 10000
1 <= W <= 10000
如果答案与正确答案的误差不超过 10^-5，则该答案将被视为正确答案通过。
此问题的判断限制时间已经减少。

[1,2,3,4,5,6,7,8,9,10]
抽1次: 0
抽2次: 5/10*10 (8,9 8,10 9,8 9,10 10,10)
抽3次: 
。。。

7~16再抽一次有可能停止
8:1
9:


"""


class Solution(object):
    def new21Game(self, N, K, W):
        """
        :type N: int
        :type K: int
        :type W: int
        :rtype: float
        """


N, K, W = 21, 17, 10
s = Solution()
print(s.new21Game(N, K, W))
