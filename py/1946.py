#coding:utf-8

"""
2019.03.13.Tue
<신입사원>
그리디.
어떤 문제가 주어졌을 때 이 문제를 풀기 위해서는 이런 게 필요하다는 걸 알 수 있다는 게
굉장히 부러움..;
ㅠㅠ
작은 순서대로 정렬이 되고
두 번째 비교할 것이 더 작은 값이 나올수록 선택이 되는...
"""

def main():
    n=int(input())
    result=[]
    while(n!=0):
        min=1000

        #몇 명의 신입사원?
        n2=int(input())

        #모든 신입사원들의 서류, 면접 순위를 저장할 리스트
        all=[]

        #몇 명의 신입사원들이 뽑힐 수 있는지?
        cnt=0

        #모든 신입사원들의 점수 기록
        for i in range(0, n2):
            a=input().split()
            all.append([int(a[0]), int(a[1])])
        #서류심사 순위대로 정렬됨
        all.sort()

        #면접심사 순위를 더 작은 값을 받을 때마다(두 심사 모두 지지 않았을 경우)
        #합격. 일단 서류심사 순위가 1순위인 사람은 무조건 합격인거고.
        for i in range(0, len(all)):
            if min > all[i][1]:
                min=all[i][1]
                cnt+=1
        result.append(cnt)

        n-=1

    for i in range(0, len(result)):
        print(result[i])

if __name__=="__main__":
    main()
