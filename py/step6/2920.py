'''
2019.03.21.Thur.
<music scale>
'''
import sys

li=sys.stdin.readline().split()

n1=0
n2=0

for i in range(len(li)):
    if i+1==int(li[i]):
        n1+=1
    elif len(li)-i==int(li[i]):
        n2+=1

if n1==len(li):
    print("ascending")
elif n2==len(li):
    print("descending")
else:
    print("mixed")
