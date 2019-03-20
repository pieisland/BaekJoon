#coding:utf-8
'''
2019.03.20.Wed.
<별 찍기2>
'''

n=int(input())
for i in range(n):
    print(" "*(n-1-i), end="")
    print("*"*(i+1))
