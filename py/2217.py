#coding:utf-8

"""
2019.03.12.Tue.
로프.
마찬가지로 그리디 알고리즘.
그리디 알고리즘은.. 정렬부터 먼저 해야되는 것 같군.
"""

def main():
    n=int(input())
    
    a=[]
    for i in range(0, n):
        temp=int(input())
        a.append(temp)
    
    a.sort()
    max=0
    for i in range(0, n):
        if(max<a[i]*(n-i)):
            max=a[i]*(n-i)
    print(max)
    
if __name__=="__main__":
    main()
