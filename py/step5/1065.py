#coding:utf-8
'''
2019.03.20.Wed.
<한수>
양의 정수 x의 자리수가 등차수열을 이루는 수를
한수라고 함
'''

import sys

n=int(sys.stdin.readline())
temp=n
cnt=0
while(temp>0):
    if temp//100!=0:#100이상 1000이하
        temp2=temp
        n1=temp2//100
        temp2%=100
        n2=temp2//10
        n3=temp2%10
        #print(temp, n1, n2, n3)
        if n2-n1==n3-n2:
            cnt+=1
    else:
        cnt+=1

    temp-=1

print(cnt)
