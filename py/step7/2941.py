'''
2019.03.22.Fri.
<크로아티아 알파벳>
'''

s=input()
sLen=len(s)
cnt=0
i=0
while(i<sLen):
    if s[i]=="c" or s[i]=="s" or s[i]=="z":
        if i+1<sLen:
            if s[i+1]=="=" or s[i+1]=="-":
                cnt+=1
                i+=2
                continue
    elif s[i]=="d":
        if i+1<sLen:
            if s[i+1]=="=":
                cnt+=1
                i+=2
                continue
        if i+2<sLen:
            if s[i+1]=="z" and s[i+2]=="=":
                cnt+=1
                i+=3
                continue
    elif s[i]=="l" or s[i]=="n":
        if i+1<sLen:
            if s[i+1]=="j":
                cnt+=1
                i+=2
                continue
    else:
        cnt+=1
        i+=1
        continue
    cnt+=1
    i+=1

print(cnt)
    
