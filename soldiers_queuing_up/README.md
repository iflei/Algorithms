### 问题描述
有Ｎ个士兵(1≤Ｎ≤26)，编号依次为Ａ,Ｂ,Ｃ, …, Z，队列训练时，指挥官要把一些士兵从高到矮一次排成一行，但现在指挥官不能直接获得每个人的身高信息，只能获得“P1比P2高”这样的比较结果，如"Ａ>Ｂ"表示Ａ比Ｂ高。根据所得到的比较结果求出一种符合条件的排队方案。（注：比较结果中没有涉及的士兵不参加排队）
### 问题分析
首先用visit数组标记涉及的士兵，用dep二维数组表示士兵之间身高关系，in数组记录入度（也就是有几个人比他高），ans数组保存最终排序结果。

拓扑排序是核心算法。下面一步一步分析。

首先统计涉及的士兵人数n，把入度为0的士兵push进队列里（入度为0说明是某个序列中最高的）；

当队列不空时，队列首元素出队列，并且把涉及的士兵人数n--，然后把这个士兵加入到结果数组中（因为队列里的都是某个序列里最高的士兵，这些士兵的高低是没有比较的）；

举个例子，A>B B>D F>D，只能知道A和F 的入度为0，所以他们都会入队列，并且A排在前面。

然后遍历一遍所有士兵，当队首这个士兵比 i 士兵高，就把 i 的入度减 1，如果 i 入度为零了，就把 i 也入队列（说明已经没有谁比他高了）；

当队列为空了，说明所有士兵都排好序了。