#coding:utf-8

"""
2019.03.13.Wed
<소수찾기>
에라토스테네스의 체를 사용해보자
"""

def main():
    n = int(input())

    a = input().split()
    
    b=[]
    for i in range(0, 1001):
        b.append(i)
    
    b[1]=0

    for i in range(2, 1001):
        j=i+i 
        while(j<1001):
            b[j]=0
            j+=i
    
    cnt=0
    for i in range(0, len(a)):
        idx = int(a[i])
        if b[idx]!=0:
            cnt+=1

    print(cnt)

if __name__=="__main__":
    main()
