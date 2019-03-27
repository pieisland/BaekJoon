'''
2019.03.27.Wed.
<AC>
'''
import re

def reverse(li):
    temp=[]
    for i in range(len(li)):
        j=len(li)-1-i
        temp.append(li[j])
    #print(temp)
    li=temp
    return li

def delete(li):
    if len(li)==0:
        return -1
    else:
        li.pop(0)
    return 0

n=int(input())
for i in range(n):
    defs=input()
    num=int(input())
    tmp=input()#까다로운 부분..;; 숫자만 분리해야되는 거 아니냐.
    arr=re.findall("\d+", tmp)
    check=1
    for j in range(len(defs)):#명령의 수만큼 반복
        #print(defs[j])
        if defs[j]=="R":
            arr=reverse(arr)
            #print("revese")
            #print(arr)
        else:
            #print("delete..??")
            val=delete(arr)
            if val==-1:
                print("error")
                check=0
                break
            #print(arr)
    #print(arr)
    if check==0:
        continue
    for j in range(len(arr)):
        if j==0:
            print("[%d,"%int(arr[j]), end="")
        elif j==len(arr)-1:
            print("%d]"%int(arr[j]))
        else:
            print("%d,"%int(arr[j]), end="")

