'''
2019.03.26.Tue.
<조세퍼스 순열>
'''

n, m=map(int, input().split())
li=[-1]
for i in range(1, n+1):
    li.append(i)
result=[]
cnt=0
i=0
while(len(result)<n):
    i+=1
    if i>n: i=1
    if li[i]!=-1:
        cnt+=1
        if cnt%m==0:
            result.append(li[i])
            li[i]=-1
            cnt=0
for i in range(n):
    if i==0:
        print("<%d, "%result[i], end="")
    elif i==n-1:
        print("%d>"%result[i])
    else:
        print("%d, "%result[i], end="")

