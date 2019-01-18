from __future__ import print_function
import sys

while True:
    try:
        A = list(map(int, input().split()))
        A = A[:-1]
        cur_max = A[0]
        cur_min = A[0]
        prev_max = A[0]
        prev_min = A[0]
        res = A[0]
        
        for i in range(1,len(A)):
            cur_max = max(prev_max*A[i] , max(prev_min*A[i] , A[i]))
            cur_min = min(prev_max*A[i] , min(prev_min*A[i] , A[i]))
            res = max(res , cur_max)
            prev_max = cur_max
            prev_min = cur_min
        print(res)
    except EOFError:
        break
