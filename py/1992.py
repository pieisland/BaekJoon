#coding:utf-8

"""
2019.03.14.Thur
<쿼드 트리>
분할정복 문제.
"""
a=[]

def dnq(n, i, j):
    if n==1:
        return a[i][j]
    
def main():
    n=int(input())
    
    for i in range(n):
        a.append(input()) 
    print(a[1])
    
    for i in range(n):
        temp=a[i]
        a[i]=[]
        for j in range(n):
            a[i].append(int(temp[j]))

    dnq(n, 0, 0)

if __name__=="__main__":
    main()
