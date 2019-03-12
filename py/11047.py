#coding:utf-8

"""
2019.03.12.Tue.
동전 0
이것도 그리디 알고리즘
"""
#파이썬에서 인풋을 여러 개 받으려면 그냥 앞에 인수를 몇 개 써주면 됨
#근데 알고보니 뒤에 .split()이거를 붙여줘야되네요.
def main():
    n, k=input().split()
    n=int(n)
    k=int(k)
    
    result=0

    a=[]
    for i in range(0, n):
        a.append(int(input()))

    for i in range(0, n):
        j = n-1-i
        result+=int(k/a[j])
        k=k%a[j]

        if k==0: break
        
    print(result)

if __name__=="__main__":
    main()

