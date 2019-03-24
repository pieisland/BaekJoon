'''
2019.03.24.Sun.
<sort inside>
'''
n=input()
li=[]
for i in range(len(n)):
    li.append(int(n[i]))

li.sort()

for i in range(len(li)):
    print(li[len(li)-1-i], end="")


