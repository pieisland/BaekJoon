#coding:utf-8

'''
2019.03.20.Thur.
<그대로 출력하기>
아. try, except문을 쓰는 것과
EOFError라는 것을 알게됐다.

eof는 end of file을 의미하며
갑자기 파일의 끝이 올 것을 예상하지 못했을 때 발생하는 에러라고 함.
'''

while(1):
    try:
        print(input())
    except EOFError:
        break
    
    #a=input)
    #if a.startswith(" "):
    #    break
    #else:
    #    print(a)
