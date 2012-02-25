#!/usr/bin/env python
#-!-coding:utf8-!-

def swap(array, x, y):
    array[x],array[y] = array[y],array[x]

def partition(array, begin, end):
    pivo = array[begin]
    l = begin
    for i in xrange(begin + 1, end):
        if array[i] > pivo: continue
        l += 1
        swap(array, i, l)
    swap(array, begin, l)
    return l

def qsort(array, begin, end):
    if begin >= end: return
    mid = partition(array, begin, end)
    qsort(array, begin, mid)
    qsort(array, mid + 1, end)

def main():
    import random
    array = [random.randint(1, 1000000) for i in xrange(1000000)]
    qsort(array, 0, len(array))
    for i in xrange(1, len(array)):
        assert array[i-1] <= array[i]
    print 'ok'

if __name__ == '__main__':
    main()

