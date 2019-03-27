'''
2019.03.27.Wed.
<회전하는 큐>
'''

def move(li, n1, n2):
    if n1==0:
        for i in range(n2):
            num=li.pop(0)
            li.append(num)
    else:
        for i in range(n2):
            num=li.pop()
            li.insert(0, num)

a, b=map(int, input().split())
nums=[]
for i in range(a):
    nums.append(i+1)

find=input().split()

i=0
cnt=0
while(1):
    idx=nums.index(int(find[i]))
    if idx==0:
        nums.pop(0)
        i+=1
        if i==b:
            break
        continue
    if idx<=int(len(nums)/2):
        move(nums, 0, idx)
        #print(idx, "left")
        cnt+=idx
    else:
        move(nums, 1, len(nums)-idx)
        #print(idx, "right")
        cnt+=len(nums)-idx
    
print(cnt)
