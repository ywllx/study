#!/usr/bin/env python

import sys

def maxi(arr):
    value = arr[0]
    for e in arr:
        if e > value:
            value = e
    return value


def mini(arr):
    value = arr[0]
    for e in arr:
        if e < value:
            value = e
    return value

def num_less(arr, element):
    n = 0
    for e in arr:
        if e < element:
            n = n + 1
    return n

def median(arr):
    print maxi(arr)
    print mini(arr)
    target_order = len(arr)/2

    n = 0 
    while True:
        n = n + 1
        max_value = maxi(arr)
        min_value = mini(arr)
        if max_value == min_value:
            print "n = %d" %n
            print max_value
            return
    
        pivot = arr[0]
        num = num_less(arr, pivot)
        if target_order == num:
            print "n = %d" %n
            print pivot
            return
        if target_order < num:
            temp_arr = filter(lambda x:x<pivot, arr)
            arr = temp_arr
        if target_order > num:
            del arr[0]
            temp_arr = filter(lambda x:x>=pivot, arr)
            target_order = target_order - num - 1
            arr = temp_arr
    

exarr = [int(value.strip()) for value in sys.stdin.readlines()]
median(exarr)
