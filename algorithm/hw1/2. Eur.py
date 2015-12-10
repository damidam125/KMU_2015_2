__author__ = '20123434 황정담'

class Flags:
    """
    this class is used to set the flags, each of them represent :
    if N, the non-negative integer, can be represented as sum of exactly 1/2/3 triangle numbers
    then each flag is set 1. Otherwise 0
    """
    def __init__(self):
        self.f1=0
        self.f2=0
        self.f3=0

    def can_be_rep_3(self):
        '''
        :return: the number can be represented as sum of exactly 3 triangle numbers
        '''
        return self.f3


def getAllData(arr=[]):
    '''
    method to get flags for integer 0 to 1000.
    :param arr: is a list of the flags. arr[i] has the flags for i.
    :return:nothing

    1. get list which contains T0 to Tn (Tn<1000). list[n] = Tn
    2. initialize arr[0:1000]. use #1's list
        for all Tn, set arr[Tn].flag3 = 1, others are set 0 by default.
    3. set the all flags arr[0:1000].
        algorithm used : when integer (N, a, b) as (N>=2, a+b=N) then
        arr[N].flag(2) is 1 if ( arr[a].flag1 ==1 and arr[b].flag1 == 1 )
        arr[N].flag(3) is 1 if ( arr[a].flag1 ==1 and arr[b].flag1 == 2 )
         or ( arr[a].flag1 ==2 and arr[b].flag1 == 1 )
    '''

    #algorithm #1
    num, lst = 0, []
    while num*(num+1)-2000 < 0:
        lst.append( int(num*(num+1)/2) )
        num+=1

    #algorithm #2
    for a in range(1001):
        arr.append(Flags())
        arr[a].f1 = 1 if (a in lst) else 0
    arr[0].f1 = 0

    #algorithm #3
    for a in range(2,1001):
        possible = []  # variable to get list of tuples where integer a = tuple[0]+tuple[1]
        for idx in range(a-1,int((a-1)/2),-1):
            possible.append( (idx, a-idx) )
        for idx in possible:
            arr[a].f2 = arr[a].f2 or (arr[idx[0]].f1 and arr[idx[1]].f1)
            arr[a].f3 = arr[a].f3 or (arr[idx[0]].f1 and arr[idx[1]].f2) or \
                        (arr[idx[0]].f2 and arr[idx[1]].f1)

def main():
    with open('input.txt', 'r') as f:
        numcase = int(f.readline())
        arr = []
        getAllData(arr)
        for a in range(0, numcase):
            get = int(f.readline())
            print(arr[get].can_be_rep_3())



if __name__ == '__main__':
    main()