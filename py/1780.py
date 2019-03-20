#coding:utf-8

"""
2019.03.14.Thur
<종이의 개수>
분할정복 문제.
"""
a=[]
res=[0, 0, 0]

def dnq(n, r, c):
    if n==1:
        res[a[r][c]+1]+=1

    else:
        num=a[r][c]
        b=True
        for i in range(r, r+n):
            for j in range(c, c+n):
                if num!=a[i][j]:
                    b=False
                
        if b==False:
            dnq(n//3, r, c)
            dnq(n//3, r, c+n//3)
            dnq(n//3, r, c+(n*2)//3)
            dnq(n//3, r+n//3, c)
            dnq(n//3, r+n//3, c+n//3)
            dnq(n//3, r+n//3, c+(n*2)//3)
            dnq(n//3, r+(n*2)//3, c)
            dnq(n//3, r+(n*2)//3, c+n//3)
            dnq(n//3, r+(n*2)//3, c+(n*2)//3)
        else:
            res[num+1]+=1
    
def main():
    n=int(input())
    
    for i in range(n):
        a.append(input()) 
        a[i]=a[i].replace(" ", "")

    for i in range(n):
        temp=a[i]
        a[i]=[]
        j=0
        while(j<len(temp)):
            if temp[j]=="-":
                a[i].append(-int(temp[j+1]))
                j+=2
            else:
                a[i].append(int(temp[j]))
                j+=1
    dnq(n, 0, 0)
    
    print(res[0])
    print(res[1])
    print(res[2])

if __name__=="__main__":
    main()
