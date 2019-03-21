#coding:utf-8
'''
2019.03.21.Thur.
<Word Studying>
'''

s=input()
sLen=len(s)

alpha=[]
for i in range(26):
    alpha.append(0)

for i in range(sLen):
    val=ord(s[i])
    #소문자라면 대문자로 바꿔주기
    if val>96:
        val-=32
    alpha[val-65]+=1

m=max(alpha)
idx=alpha.index(m)
cnt=0
for i in range(len(alpha)):
    if i==idx:
        continue
    if alpha[i]==m:
        cnt+=1
if cnt!=0:
    print("?")
else:
    print(chr(idx+65))
