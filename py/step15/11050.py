'''
2019.03.28.Thur.
<이항계수>
'''

a, b=map(int, input().split())

num=1

def fac(n):
    if n==0:
        return(1)
    result=n*fac(n-1)
    return result

for i in range(b):
    num=num*(a-i)

answer=int(num/fac(b))
print(answer)


