#coding:utf-8
'''
2019.03.20.Wed.
<2007>
'''
cal=[0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
day=["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
x, y=map(int, input().split())
days=0
for i in range(x):
    days+=cal[i]
days+=y
idx=days%7

print(day[idx])

