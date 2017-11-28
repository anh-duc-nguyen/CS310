import random

def merge_sort(alist):
	if len(alist)>1:
		mid = len(alist)//2
		left = alist[:mid]
		right = alist[mid:]

        merge_sort(left)
        merge_sort(right)

        i=0
        j=0
        k=0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                alist[k]=left[i]
                i=i+1
            else:
                alist[k]=right[j]
                j=j+1
            k=k+1

        while i < len(left):
            alist[k]=left[i]
            i=i+1
            k=k+1

        while j < len(right):
            alist[k]=right[j]
            j=j+1
            k=k+1
    	print(alist)


def test():
	alist = []
	for i in range(10):
		alist.append(random.randint(1,100))

	print ('unsorted list is: ',alist)
	print ('sorting')
	alist = merge_sort(alist)
	print ('list after sorting: ', alist)

test()