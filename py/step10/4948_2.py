'''
2019.03.25.Mon.
<베르트랑 공준>
'''
import math

def main():
    nums=[]

    result=[]
    
    while(1):
        n=int(input())
        if n==0:
            break
        nums.append(n)

    mNum=max(nums)

    li=[]
    for i in range(mNum*2+1):
        li.append(i)
    li[1]=0

    for i in range(2, mNum*2+1):
        if li[i]==0:
            continue
        k=i+i
        while(k<mNum*2+1):
            li[k]=0
            k=k+i

    for i in range(len(nums)):
        cnt=0
        for j in range(nums[i]+1, nums[i]*2+1):
            if li[j]!=0:
                cnt+=1
        print(cnt)

main()
