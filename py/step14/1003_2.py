'''
2019.03.28.Thur.
<피보나치 함수>
'''

n=int(input())

a=[]
b=[]
for i in range(50):
    a.append(0)
    b.append(0)
a[0]=1
b[1]=1

for i in range(2,50):
    a[i]=a[i-1]+a[i-2]
    b[i]=b[i-1]+b[i-2]

def fibonacci(num):
    if num==0:
        return(print("1 0"))
    elif num==1:
        return(print("0 1"))
    else:
        return(print("%d %d"%(a[num], b[num])))

for i in range(n):
    an=int(input())
    fibonacci(an)
