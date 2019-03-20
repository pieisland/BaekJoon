#coding:utf-8
'''
2019.03.20.Wed.
<평균은 넘겠지>
문제를 참 웃기게 내는구나..
소수점 특정 자리수까지 표현을 하고 싶으면
0.3f 이런 식으로 써야함을 알았다.
'''

import sys

n=int(sys.stdin.readline())
result=[]
for i in range(n):
    temp=sys.stdin.readline().split()
    sum=0
    for j in range(1, len(temp)):
        sum+=int(temp[j])
    avg=sum/int(temp[0])
    cnt=0
    for k in range(1, len(temp)):
        if int(temp[k])>avg:
            cnt+=1
    result.append(cnt/int(temp[0])*100)

for i in range(n):
    print("%0.3f%%" % result[i])
    
        
