'''
2019.03.21.Thur.
<Finding Alphabet>
'''
li=[]
for i in range(26):
    li.append(-1)

s=input()
for i in range(len(s)):
    if li[ord(s[i])-97]!=-1:
        continue
    li[ord(s[i])-97]=i

for i in range(len(li)):
    print(li[i], end=" ")
