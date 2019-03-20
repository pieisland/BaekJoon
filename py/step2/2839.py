#coding:utf-8
'''
2019.03.20.Wed.
<Sugar Delivering>
단순하게 생각했더만... 아니었다.
조금 더 생각해봐야 할 듯.

핵심은 최대한 5로 나눈 뒤에
나머지가 3으로 떨어지는가를 알아보는 것
떨어지지 않으면 5의 개수를 줄여가며 확인
'''

n=int(input())
five=n//5
n%=5
three=0

while(five>=0):
    if n%3==0:
        three=n//3
        n%=3
        break
    five-=1
    n+=5

if n!=0:
    print(-1)
else:
    print(five+three)
