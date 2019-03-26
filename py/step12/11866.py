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

while(len(result)<n):
    cnt+=1
    if cnt>n:
        cnt=1
    if cnt%m==0:
        if li[cnt]==-1:
            cnt-=1
            continue
        li[cnt]=-1
        result.append(li[cnt])
        print(li[cnt])

#헷갈림;;
