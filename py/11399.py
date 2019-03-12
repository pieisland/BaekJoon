#coding:utf-8

"""
2019.03.12.Tue.
ATM
마찬가지로 그리디 아록리즘.
정렬을 해야되는데, 파이썬 자체에서 정렬을 쉽게 하는 게있어서 그냥 그걸 사용함..
"""

def main():
    n=int(input())

    #이렇게 받으면 자동적으로 리스트가 되구나.
    a = input().split()
    
    #문자열로 저장되어 있으므로 int 값으로 변환
    for i in range(0, len(a)):
        a[i]=int(a[i])
    a.sort()

    result=0
    #복잡도가O(N^2). for 문을 두 번이나 돌 필요 없음.
    #for i in range(0, len(a)):
    #    temp=0
    #    for j in range(0, i+1):
    #        temp+=a[j]
    #    result+=temp
    
    temp=0
    for i in range(0, len(a)):
        temp+=a[i]
        result+=temp

    print(result)

if __name__=="__main__":
    main()
