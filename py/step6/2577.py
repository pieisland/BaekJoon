#coding:utf-8
'''
2019.03.21.Thur
<숫자의 개수>
'''
import sys

a=int(sys.stdin.readline())
b=int(sys.stdin.readline())
c=int(sys.stdin.readline())
num=a*b*c

li=[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
temp=str(num)

for i in range(len(temp)):
    n=int(temp[i])
    li[n]+=1

for i in range(len(li)):
    print(li[i])
