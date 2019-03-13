#coding:utf-8

"""
2019.03.13.Wed.
<잃어버린 괄호>
그리디 알고리즘.
마이너스가 처음 나온 순간부터 그 뒤의 숫자들은 빼는 식으로 계산.
"""

def main():
    a=input()

    #플러스와 마이너스가 언제 나왔는지 인덱스를 기억
    #숫자를 분리해내기 위함임.
    plus=[]
    minus=[]

    idx=[]
    for i in range(0, len(a)):
        if a[i]=="+":
            plus.append(i)
            idx.append(0)
        elif a[i]=="-":
            minus.append(i)
            idx.append(1)
            #사실 하나만 찾아도 됨

    #마이너스가 한 번도 나오지 않은 경우를 고려해 mi에 큰 값을 넣어줌
    mi=100
    for i in range(0, len(idx)):
        if idx[i]==1:
            mi=i
            break

    #print(mi)

    #숫자집합
    number=[]

    tmp=""
    for i in range(0, len(a)):
        if i in plus:
            number.append(int(tmp))
            tmp=""
        elif i in minus:
            number.append(int(tmp))
            tmp=""
        else:
            tmp=tmp+a[i]

    #마지막으로 찾은 숫자도 넣어주고..
    number.append(int(tmp))

    #print(number)

    result=0
    for i in range(0, len(number)):
        if i>mi:
            result-=number[i]
        else:
            result+=number[i]

    print(result)
    
if __name__=="__main__":
    main()
