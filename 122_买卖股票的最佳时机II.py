# -*- coding:utf-8 -*-

__author__ = 'huanghf'

"""
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
"""


def maxProfit(prices):
    n = len(prices)
    if n < 2:
        return 0
    s = 0
    for i in range(0, n - 1):
        m = prices[i + 1] - prices[i]
        if m > 0:
            s += m
    return s

    # if not prices:
    #     return 0
    # maxProfit = 0
    # n = len(prices)
    # i = 0
    # while i < n - 1:
    #     while i < n - 1 and prices[i] >= prices[i + 1]:
    #         i += 1
    #     valley = prices[i]
    #     while i < n - 1 and prices[i] <= prices[i + 1]:
    #         i += 1
    #     peak = prices[i]
    #     maxProfit += peak - valley
    # return maxProfit


print(maxProfit([7, 1, 5, 3, 6, 4]))
