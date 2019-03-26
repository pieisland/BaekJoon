'''
2019.03.26.Tue.
<괄호>
'''

n=int(input())
li=[]
for i in range(n):
    li.append(input())

s=[]
b=0
for i in range(len(li)):
    s=[]
    b=0
    for j in range(len(li[i])):
        if li[i][j]=="(":
            s.append(i)
        elif li[i][j]==")":
            if len(s)==0:
                b=-1
                continue
            s.pop()
    if b==-1:
        print("NO")
    elif len(s)==0:
        print("YES")
    else:
        print("NO")

