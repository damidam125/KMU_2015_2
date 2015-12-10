__author__ = '20123434 황정담'

def hotel(lst):
    '''
    :param lst: lst = { height of hotel, #of rooms in each floor, guest# }
    :return: no return, but there's stdout of room# for guest
    method for assigning guest to closest room from main entrance
    '''
    H, W, N = int(lst[0]), int(lst[1]), int(lst[2])
    HH = N%H if N%H !=0 else H
    WW = int(N/H)+1 if N%H!=0 else int(N/H)
    print( str(HH)+str(WW).zfill(2) )

def main():
    with open('input.txt', 'r') as f:
        numcase = int(f.readline()) #number of case
        for a in range(0, numcase):
            hotel(f.readline().split())

if __name__ == '__main__':
    main()
