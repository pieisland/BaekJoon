#coding:utf-8
'''
2019.03.20.Wed.
<x보다 작은 수>
'''

import sys

n, x=map(int, sys.stdin.readline().split())
li=[]

li=sys.stdin.readline().split()

#for i in range(n):
#    li[i]=temp=int(sys.stdin.readline())
#    li.append(temp)

for i in range(n):
    if x>int(li[i]):
        print(int(li[i]), end=" ")

