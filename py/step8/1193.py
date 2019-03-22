'''
2019.03.22.Fri
<대분수>
'''

n=int(input())
i=1
sum=0
while(1):
    sum=(i*(i+1))//2
    if sum>=n:
        k=0
        while(1):
            if sum-k==n:
                print("%d/%d"%(k+1, i-k))
                break
            k+=1

