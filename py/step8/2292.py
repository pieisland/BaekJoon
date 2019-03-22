'''
2019.03.22.Fri.
<Bee's home>
'''

n=int(input())

sum=1
i=1
while(1):
    sum=sum+6*(i-1)
    if n<=sum:
        print(i)
        break
    i+=1


