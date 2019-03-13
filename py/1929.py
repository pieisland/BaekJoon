#coding:utf-8

"""
2019.03.13.Wed
<소수 구하기>
마찬가지로 에라토스 테네스의 체.
최대 숫자가 크기 때문에 반드시 사용해야 함
"""

def main():
    #숫자를 받아온다
    n=input().split()
    m=int(n[1])

    #소수일 경우 0으로 채울 배열
    a=[]
    for i in range(0, m+1):
        a.append(i)
    a[1]=0

    #소수 판별
    for i in range(2, m+1):
        j=i+i
        while(j<m+1):
            a[j]=0
            j+=i
    
    #소수가 아니면 출력
    for i in range(int(n[0]), m+1):
        if a[i]!=0:
            print(i)

#인덱스가 헷갈리는 게 문제..

if __name__=="__main__":
    main()

