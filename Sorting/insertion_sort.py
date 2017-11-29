import random

def insertion_sort(alist):
	'''
	a really really bad sorting algorithm
	'''
	LEN = len(alist)
	for i in range(1,LEN):
		key = alist[i]
		j = i - 1
		while j >= 0 and alist[j] > key:
			alist[j+1] = alist[j]
			j -= 1
		alist[j+1] = key
	return alist 

def test():
	alist =[]
	for i in range(10):
		alist.append(random.randint(1,100))
	print ('unsorted list is: ',alist)
	print ('sorting')
	alist = insertion_sort(alist)
	print ('list after sorting: ', alist)

test()