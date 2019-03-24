'''
2019.03.24.Sun.
<Room Number>
'''

nlist=input()

numCheck=[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
sn=0

for i in range(len(nlist)):
    if nlist[i]=="6" or nlist[i]=="9":
        sn+=1
    else:
        numCheck[int(nlist[i])]+=1

a=sn//2
b=sn%2
max=a+b

for i in range(len(numCheck)):
    if numCheck[i]>max:
        max=numCheck[i]

print(max)

