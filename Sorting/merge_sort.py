import random


def merge_Sort(alist):
    if len(alist) > 2:
        mid = len(alist)//2
        left = alist[:mid]
        right = alist[mid:]
        sortedL = merge_Sort(left)  
        sortedR = merge_Sort(right)
        if sortedL[0] < sortedR[-1]:
            return left+right
        else: return right +left
    else:
        return sorted(alist)


def test():
	alist = []
	for i in range(10):
		alist.append(random.randint(1,100))

	print ('unsorted list is: ',alist)
	print ('sorting')
	alist = merge_Sort(alist)
	print ('list after sorting: ', alist)

test()