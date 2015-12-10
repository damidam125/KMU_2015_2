__author__ = 'dami'
'''
문제 설명_
양의 정수 n이 주어진 경우 맥카시 함수를 계산하는 프로그램(재귀적으로 구할 것)

알고리즘_
양의 정수 n에 대하여 맥카시함수M(n)은
n>100인 경우 : n-10
n<100인 경우 : M(M(n+11))
'''

def McCarthy(n):
    return n-10 if n>100 else McCarthy( McCarthy(n+11) )

def main():
    with open('input.txt', 'r') as f:
        numcase, lst = int(f.readline()), []
        for a in range(0, numcase):
            print(McCarthy(int(f.readline())))


if __name__ == '__main__':
    main()