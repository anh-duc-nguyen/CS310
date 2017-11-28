import random

def insertion_sort(alist):
	LEN = len(alist)
	for i in range(LEN):
		key = alist[i]
		j = i - 1
		while j > 0 and alist[j] > key:
			alist[j+1] = alist[j]
			j -= 1
		alist[j+1] = key
	return alist 

def test():
	alist =[]
	for i in range(30):
		alist.append(random.randint(1,100))
	print ('unsorted list is: ',alist)
	print ('sorting')
	alist = insertion_sort(alist)
	print ('list after sorting: ', alist)

test()