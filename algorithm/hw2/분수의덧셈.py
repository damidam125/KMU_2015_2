__author__ = 'dami'

'''
문제 설명_
두 분수를 더해 기약분수로 나타내는 프로그램. (단, 재귀적으로 작성)
한 번의 test case에 4개의 정수 a,b,c,d가 주어진다.
처음의 두 정수는 분수 a/b 를 나타내고, 그 다음의 두 정수는 분수 c/d 를 나타냄

알고리즘_
두 분수의 분모를 통일 시켜 더한 후,(서로 분모가 다른 경우는 분모와 분자를 상대 분모만큼 곱한 뒤 더함)
유클리드호제법을 이용해 분모와 분자의 최대공약수가 1이 될때까지 분모와 분자를 최대공약수로 나눠준다.(이 과정에서 재귀적 알고리즘 이용)
'''

def gcd(a, b):
    '''
    유클리트호제법을 이용해 최대공약수를 구하는 함수. (재귀적)
    :param a: 분자
    :param b: 분모
    :return: 최대공약수를 구할 때 까지 자신을 호출, 최대공약수를 구한 경우->값을 return
    '''
    return a if b==0 else gcd(b, a%b)

def main():
    with open('input.txt', 'r') as f:
        numcase = int(f.readline())
        for a in range(0, numcase):
            a,b,c,d = list(map(int, f.readline().split())) #각 testcase마다 4개의 정수를 입력받음
            result = [ a+c, b ] if b==d else [a*d+c*b, b*d] #분수를 더함 (서로 분모가 다른 경우는 분모와 분자를 상대 분모만큼 곱한 뒤 더함)

            #최대공약수가 1이 될 때 까지(즉, 분모와 분자의 공약수가 1뿐일 때 까지) 분모와 분자를 최대공약수로 나눠줌
            div = gcd(result[0],result[1])
            while( div!= 1 ):
                result = [ elem/div for elem in result ]
                div = gcd(result[0],result[1])

            print('%d %d' %(result[0], result[1]) )


if __name__ == '__main__':
    main()