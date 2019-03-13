#coding:utf-8

"""
<30>
그리디 알고리즘이고, 정수론 기본 지식이 필요.
숫자를 조합해서 30의 배수를 만들 수 있는지를 묻는 문제.
정수론에서, 각 숫자 자릿수의 합이 n의 배수이면, 전체 숫자는 항상 n의 배수가 된다는 게 있음..
몰랐는데 그런게 있다고 한다.. ^>^

그래서 30의 배수가 되고 싶으면, 일단 각 각 숫자 자릿수의 합이 3의 배수인지를 찾고.
0이 포함이 되어 있는지를 찾아서
큰 순서대로 출력을 해주면 됨.
"""

def main():
    n=input()

    a=[]
    sum=0
    for i in range(0, len(n)):
        a.append(int(n[i]))
        sum+=a[i]

    if 0 in a:#0이 반드시 있어야 하고,
        if sum%3==0: #3으로 나누어진다면
            a.sort()
            num=""
            for i in range(0, len(a)):
                j=len(a)-1-i
                num+=str(a[j])
            print(int(num))
        else: print(-1)
    else:
        print(-1)

if __name__=="__main__":
    main()
