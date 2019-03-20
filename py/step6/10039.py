'''
2019.03.21.Thur.
<Average Score>
'''

sum=0
for i in range(5):
    n=int(input())
    if n<40:
        n=40
    sum+=n
print(sum//5)
