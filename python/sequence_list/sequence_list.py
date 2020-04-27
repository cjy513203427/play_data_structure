# -*- encoding: utf-8 -*-
'''
@File    :   sequence_list.py
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/2/17 17:00   Jonas           sequence list
'''

import numpy as np

MAXSIZE = 20

class SqList(object):
    def __init__(self):
        self.data = np.zeros(MAXSIZE)
        self.length = 0

    def visit(self, element):
        print(element,end="")
        return True

    # init sequence list
    def InitList(self):
        self.length = 0
        return True

    # judge if list empty is
    def ListEmpty(self):
        if self.length == 0:
            return True
        else:
            return False

    # clear sequence list
    def ClearList(self):
        self.length = 0
        return True

    # return list length
    def ListLength(self):
        return self.length

    # Condition:0≤i≤ListLength
    # according to index return element
    def GetElem(self, i):
        if self.length == 0 or i < 0 or i > (self.length - 1):
            return False
        et = self.data[i]
        return et

    # Condition:ListLength>0
    # according to element return element's index
    def locateElem(self, et):
        i = 0
        if self.length == 0:
            return False
        for d in self.data:
            if d == et:
                break
        if i >= self.length:
            return False
        return i

    # Condition:!=MAXSIZE; 0≤i≤ListLength
    # insert element in position i
    def ListInsert(self, i, et):
        if self.length == MAXSIZE:
            return False
        if i < 0 or i > self.length:
            return False
        # not final position
        if i < self.length:
            for k in range(self.length, i, -1):
                self.data[k] = self.data[k-1]
        self.data[i] = et
        self.length += 1
        return True

    # Condition:ListLength!=0; 0≤i≤ListLength
    # delete element according to index
    # return deleted element
    def ListDelete(self, i):
        if self.length == 0:
            return False
        if i < 0 or i > self.length - 1:
            return False
        et = self.data[i]
        # not final position
        if i < self.length - 1:
            for k in range(i, self.length - 1, 1):
                self.data[k] = self.data[k + 1]
        self.length -= 1
        return et

    def ListTraverse(self):
        for d in self.data:
            self.visit(d)
        return True


if __name__ == '__main__':
    sl = SqList()
    sl.InitList()
    print("after Initialization:sl.length=", sl.length)
    for j in range(0,6,1):
        sl.ListInsert(0, j)
    print("after we insert from 0 to 5:sl.data=")
    sl.ListTraverse()
    print("\nsl.length=",sl.length);
