'''
2019.03.21.Thur.
<dial>
'''

s=input()
sum=0
for i in range(len(s)):
    n=ord(s[i])

    if n>86:
        sum+=10
    elif n>83:
        sum+=9
    elif n>79:
        sum+=8
    elif n>76:
        sum+=7
    elif n>73:
        sum+=6
    elif n>70:
        sum+=5
    elif n>67:
        sum+=4
    else:
        sum+=3

print(sum)
