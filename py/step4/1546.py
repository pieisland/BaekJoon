#coding:utf-8
'''
2019.03.20.Wed.
<평균>
'''
import sys

n=int(sys.stdin.readline())
li=sys.stdin.readline().split()
for i in range(n):
    li[i]=int(li[i])
li.sort()
max=int(li[-1])
sum=0

for i in range(n):
    num=int(li[i])/max*100
    sum+=num

print(sum/n)
