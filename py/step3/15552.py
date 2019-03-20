#coding:utf-8
'''
2019.03.20.Wed.
<빠른 A+B>
'''
import sys

n=int(sys.stdin.readline())

for i in range(n):
    li = sys.stdin.readline().split()
    print(int(li[0])+int(li[1]))

'''
그냥
a, b=map(int, sys.stdin.readline().split())
해도 되는 거다.
sys.stdin.readline()만 기억하면 될 듯
'''
