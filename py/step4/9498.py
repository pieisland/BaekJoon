#coding:utf-8
import sys
'''
2019.03.20.Wed.
<시험 성적>
'''
n=int(sys.stdin.readline())

if n>=90:
    print("A")
elif n>=80:
    print("B")
elif n>=70:
    print("C")
elif n>=60:
    print("D")
else:
    print("F")

