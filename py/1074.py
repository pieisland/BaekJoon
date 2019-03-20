#coding:utf-8

"""
2019.03.14.Thur
<Z>
분할정복 문제
어떻게 보면 코드가 길어서 그렇지
이해하고 나면 엄청 어려운 건 아닌 듯.

time over;;
"""

ans=0

num=[]

def divideAndConquer(n, r, c):
    global ans

    if n==2:
        if r==num[1] and c==num[2]:
            print(ans)
            return
        ans+=1
        if r==num[1] and c+1==num[2]:
            print(ans)
            return
        ans+=1
        if r+1==num[1] and c==num[2]:
            print(ans)
            return
        ans+=1
        if r+1==num[1] and c+1==num[2]:
            print(ans)
            return
        ans+=1

        return 
    
    divideAndConquer(n/2, r, c)
    divideAndConquer(n/2, r, c+n/2)
    divideAndConquer(n/2, r+n/2, c)
    divideAndConquer(n/2, r+n/2, c+n/2)

def main():
    a=input().split()

    for i in range(len(a)):
        num.append(int(a[i]))

    divideAndConquer(pow(2, num[0]), 0, 0)

if __name__=="__main__":
    main()
