# -*- coding:utf-8 -*-

__author__ = 'huanghf'

"""
传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。
传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。

示例 1：

输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
输出：15
解释：
船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
第 1 天：1, 2, 3, 4, 5
第 2 天：6, 7
第 3 天：8
第 4 天：9
第 5 天：10

请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。 
示例 2：

输入：weights = [3,2,2,4,1,4], D = 3
输出：6
解释：
船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
第 1 天：3, 2
第 2 天：2, 4
第 3 天：1, 4
示例 3：

输入：weights = [1,2,3,1,1], D = 4
输出：3
解释：
第 1 天：1
第 2 天：2
第 3 天：3
第 4 天：1, 1
"""


class Solution(object):
    def shipWithinDays(self, weights, D):
        """
        二分查找法
        答案一定是在max(weights) 和 sum(weights) 中间的
        因为左端点对应每天一条船，右端点对应只有一条超级大船。
        利用二分法，每一次循环模拟运货的过程，然后根据需要的天数与 输入 D 的关系来调整区间左右端点。
        :type weights: List[int]
        :type D: int
        :rtype: int
        """
        left = max(weights)
        right = sum(weights)
        while left<right:

            # 船的最大运输能力
            mid = (left+right)//2
            # ----以下为模拟运货过程----
            tmp = 0
            day = 1
            for weight in weights:
                tmp += weight
                # 装的货比船运输能力多 需要加一艘船运输
                if tmp > mid:
                    day += 1
                    tmp = weight

            # print(left,mid,right,day,D)
            # 所花时间比给定时间多 需要加大船的运输量 在右区间
            if day > D:
                left = mid + 1
            # 所花时间比给定时间少或相同 尽量在左区间找到更少的
            if day <= D:
                right = mid
        return left



weights = [3,2,2,4,1,4]
D = 3
s = Solution()
print(s.shipWithinDays(weights,D))