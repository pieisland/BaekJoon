#coding:utf-8
'''
2019.03.20.Wed.
<나머지>
'''

a, b, c=map(int, input().split())
print((a+b)%c)
print(((a%c)+(b%c))%c)
print((a*b)%c)
print((a%c*b%c)%c)
