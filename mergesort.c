// @mycodeschool

#include<stdio.h>
#include<stdlib.h>

// All three cases O(n log n)
// T(n) = 2 T(n/2) + O(n) then master's theorem.

// lefCount = number of elements in L
// rightCount = number of elements in R. 
void merge(int * A, int * L, int leftCount, int * R, int rightCount) {
	int i, j, k;
	
	// i - to mark the index of left subarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0;
	j = 0;
	k = 0;
	
	while (i < leftCount && j < rightCount) {
		if (L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while (i < leftCount) A[k++] = L[i++];
	while (j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void mergesort(int *A, int n) {
	int mid, i, *L, *R;
	if (n < 2) return; // base condition. If the array has less than two element, do nothing. 
	
	mid = n / 2; // find the mid index. 
	
	L = (int * ) malloc(mid * sizeof(int));
	R = (int * ) malloc((n - mid) * sizeof(int));
	
	for (i = 0; i < mid; i++) L[i] = A[i]; // creating left subarray
	for (i = mid; i < n; i++) R[i - mid] = A[i]; // creating right subarray
	
	mergesort(L, mid); // sorting the left subarray
	mergesort(R, n - mid); // sorting the right subarray
	merge(A, L, mid, R, n - mid); // Merging L and R into A as sorted list.
	free(L);
	free(R);
}

int main() {
	
	int i, items;
	
	int a[101];
	printf("\nEnter the number of items: ");
	scanf("%d", & items);
	
	printf("\nEnter the items: ");
	for (i = 0; i < items; i += 1) {
		scanf("%d", & a[i]);
	}
	
	mergesort(a, items);
	
	for (i = 0; i < items; i++) printf("%d ", a[i]);
	return 0;
}
