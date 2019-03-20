#coding:utf-8
'''
2019.03.20.Wed.
<열 개씩 끊어 출력하기>
'''
s=input()
for i in range(len(s)):
    if i!=0 and i%10==0:
        print("")
    print(s[i], end="")
