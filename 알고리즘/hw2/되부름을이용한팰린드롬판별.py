__author__ = '20123434 황정담'

'''
문제 설명_
주어진 영어단어가 회문인지를 판별하는 프로그램.(재귀적으로 작성)

알고리즘_
영어단어(msg)의 (첫글자와 끝글자)에서 부터 점점 인덱스를 좁혀나가는 방식.
1. 인덱스의 대소를 비교해서 대소관계가 바뀌거나 같아지면 True
2. 인덱스의 값들이 다르면 return false, 같으면 함수호출(재귀)

n! = 1 if n==0 else n*(n-1)!
'''

def palindrome(msg, idx1, idx2):
    if idx1>=idx2 :
        return 1
    return 0 if msg[idx1]!=msg[idx2] else palindrome(msg, idx1+1, idx2-1)

def main():
    with open('input.txt', 'r') as f:
        numcase = int(f.readline())
        for a in range(0, numcase):
            msg = f.readline();
            print(palindrome(msg, 0, len(msg)-2)) #3번째 인자가 len(msg)-2인 이유는 개행문자('\n') 때문.


if __name__ == '__main__':
    main()