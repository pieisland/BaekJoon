'''
2019.03.27.Wed.
<덱>
'''

n=int(input())
li=[]
for i in range(n):
    a=input().split()

    if a[0]=="push_front":
        li.insert(0, int(a[1]))
    elif a[0]=="push_back":
        li.append(int(a[1]))
    elif a[0]=="pop_front":
        if len(li)==0:
            print(-1)
        else:
            print(li.pop(0))
    elif a[0]=="pop_back":
        if len(li)==0:
            print(-1)
        else:
            print(li.pop())
    elif a[0]=="size":
        print(len(li))
    elif a[0]=="empty":
        if len(li)==0:
            print(1)
        else:
            print(0)
    elif a[0]=="front":
        if len(li)==0:
            print(-1)
        else:
            print(li[0])
    else:
        if len(li)==0:
            print(-1)
        else:
            print(li[-1])

