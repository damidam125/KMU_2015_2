__author__ = '20123434 황정담'
from string import ascii_lowercase
from math import factorial

def getArr(result, alphalist, numAlpha, numNth):
    if alphalist == [] :
        print(result)
    else :
        splitter =factorial(numAlpha-1)
        cnt = 0
        while numNth>splitter:
            numNth-=splitter
            cnt+=1
        result += alphalist.pop(cnt)
        getArr(result, alphalist, numAlpha-1, numNth)

def main():
    with open('input.txt', 'r') as f:
        numcase = int(f.readline())
        for a in range(numcase):
            numAlpha, numNth = list(map(int, f.readline().split()))
            alphalist = list(ascii_lowercase[i] for i in range(numAlpha) )
            result = ''
            getArr(result, alphalist, numAlpha, numNth)

if __name__ == '__main__':
    main()