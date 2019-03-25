'''
2019.03.25.Mon.
<Prime>
'''
import math

def isPrime(num):
    if num==1:
        return -1

    n2=int(math.sqrt(num))

    for i in range(2, n2+1):
        if num%i==0:
            return -1

    return num

#maybe.. time complexity is high :(
def main():
    n=int(input())
    m=int(input())
    
    sum=0
    li=[]
    
    for i in range(n, m+1):
        a=isPrime(i)
        if a!=-1:
            sum+=i
            li.append(i)

    if len(li)==0:
        print(-1)
    else:
        print(sum)
        print(li[0])

if __name__=="__main__":
    main()
    
