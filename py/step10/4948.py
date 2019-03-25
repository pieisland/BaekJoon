'''
2019.03.25.Mon.
<베르트랑 공준>
'''
import math

def isPrime(n):
    if n==1:
        return -1

    n2=int(math.sqrt(n))
    for i in range(2, n2+1):
        if n%i==0:
            return -1
    return 0

def main():
    nums=[]

    result=[]
    
    while(1):
        n=int(input())
        if n==0:
            break
        nums.append(n)

    for i in range(len(nums)):
        cnt=0
        for j in range(nums[i]+1, nums[i]*2+1):
            if isPrime(j)!=-1:
                cnt+=1
        result.append(cnt)

    for i in range(len(result)):
        print(result[i])

main()
