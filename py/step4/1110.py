#coding:utf-8
'''
2019.03.20.Wed.
<더하기 사이클>
'''
import sys

n=int(sys.stdin.readline())

temp=n
cnt=0
while(1):
    cnt+=1
    #10의 자리 수
    n1=temp//10
    #1의 자리 수
    n2=temp%10
    #두 값을 더한 값
    n3=n1+n2
    #의 오른쪽 값
    n4=(n1+n2)%10
    #결과
    num=n2*10+n4
    
    if num==n:
        break
    else:
        temp=num

print(cnt)
