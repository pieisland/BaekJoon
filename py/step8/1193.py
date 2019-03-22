'''
2019.03.22.Fri
<대분수>
'''

def main(): 
    n=int(input())
    i=1
    sum=0
    b=True
    while(1):
        sum=(i*(i+1))//2
        if sum>=n:
            k=0
            while(1):
                if sum-k==n:
                    if i%2==0:
                        print("%d/%d"%(i-k, k+1))
                    else:
                        print("%d/%d"%(k+1, i-k))
                    return
                k+=1
        i+=1

main()
