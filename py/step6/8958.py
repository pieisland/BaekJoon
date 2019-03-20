#coding:utf-8
'''
2019.03.21.Thur
<OX>
'''

import sys

n=int(sys.stdin.readline())
li=[]
for i in range(n):
    re=sys.stdin.readline()
    num=0
    sum=0
    for i in range(len(re)):
        if re[i]=="O":
            num+=1
            sum+=num
        else:
            num=0
    li.append(sum)

for i in range(n):
    print(li[i])

