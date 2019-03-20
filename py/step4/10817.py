#coding:utf-8
import sys

'''
2019.03.20.Wed.
<세 수>
근데 그냥 파이썬에 있는 소트 쓰면 되는 거 아니냐
'''

a, b, c=map(int, sys.stdin.readline().split())
li=[]
li.append(a)
li.append(b)
li.append(c)
li.sort()
print(li[1])

