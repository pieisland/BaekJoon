'''
2019.03.28.Thur.
<피보나치 수>
'''

n=int(input())

d=[]
for i in range(100):
    d.append(0)

def fibonacci(num):
    if num==0:
        return 0
    elif num==1:
        return 1
    else:
        if d[num]!=0:
            return d[num]
        else:
            temp=fibonacci(num-1)+fibonacci(num-2)
            d[num]=temp
            return d[num]

print(fibonacci(n))
