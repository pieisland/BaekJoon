'''
2019.03.21.Thur.
<Sansoo>
'''
n1, n2=map(int, input().split())

tmp=[n1, n2]

for i in range(2):
    a=tmp[i]//100
    tmp[i]%=100
    b=tmp[i]//10
    tmp[i]%=10
    c=tmp[i]

    n=c*100+b*10+a
    tmp[i]=n

print(max(tmp))
