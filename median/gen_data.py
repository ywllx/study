#!/usr/bin/env python

import sys
import argparse
import random

def generate_data(mini, median, maxi, number, seed=None):
    less_num = number/2
    greater_num = number/2

    less_range = median - mini
    greater_range = maxi - median
    
    # decide the number of median to emit ???
    expect_freq_values_less = float(less_num) / less_range
    expect_freq_values_greater = float(greater_num) / greater_range
    average_freq = int((expect_freq_values_less + expect_freq_values_greater) / 2)
    median_num = average_freq/3*3
    if median_num == 0:
        median_num = 1
    total = less_num + greater_num + median_num

    # spread the medians eventy through the set ???
    min_num_between_medians = total / median_num
    last_median = 0

    while(total > 0):
        a = random.randint(0, 2)
        if a == 0:
            if less_num > 0:
                value = random.randint(0, less_range-1) + mini
                less_num -= 1
                print value
        elif a == 1:
            if greater_num > 0:
                value = random.randint(1, greater_range) + median
                greater_num -= 1
                print value
        else:
            if median_num > 0 and last_median > min_num_between_medians:
                median_num -= 1
                last_median = 0
                print median

        total = less_num + greater_num + median_num
        last_median += 1

    
parser = argparse.ArgumentParser(description='Generete the test data')
parser.add_argument('-l', dest='mini', type=int, required=True, 
                    help='the mini value')
parser.add_argument('-m', dest='median',type=int,  required=True, 
                    help='the median value')
parser.add_argument('-g', dest='maxi', type=int,  required=True, 
                    help='the mixi value')
parser.add_argument('-n', dest='num', type=int, required=True, 
                    help='the number of test data')
parser.add_argument('-s', dest='seed', type=int, default=None, 
                    help='the seed of rand')
args = parser.parse_args()

generate_data(args.mini, args.median, args.maxi, args.num, args.seed)
