'''
2019.03.25.Mon.
<Stack>
'''

n=int(input())
li=[]
for i in range(n):
    tmp=input().split()
    if tmp[0]=="push":
        li.append(int(tmp[1]))
    elif tmp[0]=="pop":
        if len(li)==0:
            print(-1)
        else:
            print(li[-1])
            li.pop()
    elif tmp[0]=="size":
        print(len(li))
    elif tmp[0]=="empty":
        if len(li)==0:
            print(1)
        else:
            print(0)
    elif tmp[0]=="top":
        if len(li)==0:
            print(-1)
        else:
            print(li[-1])
    else:
        break

