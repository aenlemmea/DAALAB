#include <stdio.h>

// T(n) = T(n/2) + c_2. T(1) = c_1
// Best Case: O(1), Average Case:O(log n), Worst Case: O(log(n))
int binarysearchrec(int *a, int left, int right, int key) {
	int mid = 0;
	if (right < left) return -1;
	mid = left + ((right - left) / 2);
	
	if (right >= left) {
		if (key == a[mid]) return mid;
		else if (key < a[mid]) return binarysearchrec(a, left, mid - 1, key);
		else return binarysearchrec(a, mid + 1, right, key);
	}
}

// Worst case: Key is either in left or right so O(log n) since no. of comparisons.
// Best Case: O(1)
// Average Case: https://www.knowledgehut.com/blog/programming/time-complexity-of-binary-search
int binarysearch(int *a, int left, int right, int key) {
	int mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		
		if (key < a[mid]) right = mid - 1;
		else if (key > a[mid]) left = mid + 1;
		else return mid;
	}
	return -1;
}

int main() {
	int items, i, key;
	int a[101];
	printf("\nEnter the number of items: ");
	scanf("%d", &items);
	
	printf("\nEnter the items: ");
	for(i= 0; i < items; i += 1){
		scanf("%d", &a[i]);
	}
	
	printf("\nEnter the key to find: ");
	scanf("%d", &key);
	
	printf("\nITERATIVE: %s", (binarysearch(a, 0, items, key) != -1 ? "Found item" : "Not found"));
	printf("\nRECURSIVE: %s", (binarysearchrec(a, 0, items, key) != -1 ? "Found item" : "Not found"));
}
