#coding:utf-8

"""
2019.03.12.Tue.
<거스름돈>
그리디 알고리즘 사용
"""

def main():
    n=input()
    n=1000-int(n)
    result=0

    a=[500, 100, 50, 10, 5, 1]

    for i in range(0, len(a)):
        result+=int(n/a[i])
        n=n%a[i]
        
        if n==0: break

    print(result)

if __name__=="__main__":
    main()
