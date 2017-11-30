import random
def merge(A,l,m,r):
    n1 = m - l +1
    n2 = r - m
    L = A[l:n1]
    R = A[n2:r]
    
    i = 0
    j = 0
    k = 1
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            A[k] = L[i]
            i+=1
        else:
            A[k] = R[j]
            j+=1
        k +=1
    while i<n1:
        A[k] = L[i]
        i += 1 
        k += 1
    while j<n2:
        A[k] = R[j]
        j+=1
        k+=1
def Merge(A,l,m,r):
    L = A[l:m]
    R = A[m:]


def merge_sort(A,l,r):
    if l<r:
        m = (l+r-1)//2
        merge_sort(A,l,m)
        merge_sort(A,m+1,r)
        merge(A,l,m,r)




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
	merge_sort(alist,0,len(alist)-1)
	print ('list after sorting: ', alist)

test()