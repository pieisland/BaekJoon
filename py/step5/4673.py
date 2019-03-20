#coding:utf-8
'''
2019.03.20.Wed.
<셀프 넘버>
'''
NUM=10000

li=[0]
for i in range(1, NUM+1):
    li.append(i)

def selfNum(num):
    
    sNum=str(num)
    numLen=len(sNum)
    result=num
    temp=num

    for i in range(numLen-1):
        p=numLen-1-i
        result+=temp//pow(10, p)
        temp%=pow(10,p)
    
    result+=temp
    
    
    if result>NUM:
        return
    else:
        if li[result]==0: return
        li[result]=0
        selfNum(result)

def main():
    for i in range(1, NUM+1):
        selfNum(i)

    for i in range(1, len(li)):
        if li[i]==0:
            continue
        print(li[i])

main()
