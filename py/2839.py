#coding:utf-8
'''
2019.03.20.Wed.
<Sugar Delivering>
단순하게 생각했더만... 아니었다.
조금 더 생각해봐야 할 듯.
11을 5+3*2로 되는데. 이걸 어떻게 할까?
5를 한 번만 나눠야 하는 문제가 있음...
근데 이런 문제 풀었던 것 같은데
그 때는 이런 거 별로 안 따졌던 걸로 기억하는데...;;
'''

a=int(input())
temp1=a
temp2=a

num1=0
num2=0

num1+=temp1//5
temp1=temp1%5
num1+=temp1//3
temp1=temp1%3

num2+=temp2//3
temp2=temp2%3
num2+=temp2//5
temp2=temp2%5

if temp1==0 or temp2==0:
    if temp1==0 and temp2==0:
        print(num1)
    elif temp1==0:
        print(num1)
    else: print(num2)
else:
    print(-1)
