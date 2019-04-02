# -*- coding:utf-8 -*-

__author__ = 'huanghf'

"""
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
"""


# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    def merge(self, intervals):
        if not intervals:
            return []
        intervals = sorted(intervals,key=lambda x:(x.start,x.end))
        i = 0
        while i<len(intervals)-1:
            while i+1<len(intervals) and intervals[i].end>=intervals[i+1].start:
                intervals[i].end=max(intervals[i].end,intervals[i+1].end)
                intervals.pop(i+1)
            i+=1
        return intervals

s = Solution()
l = [[1,3],[2,6],[8,10],[15,18]]
intervals = []
for i in l:
    intervals.append(Interval(i[0],i[1]))

print(s.merge(intervals))