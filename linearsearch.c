#include <stdio.h>

/*
int linearsearchrec(int *a, int items, int key) {
	return (items < 0 || a[items] == key) ? items : linearsearchrec(a, items - 1, key);	
}
*/


// T(n) = T(n - 1) + 1
// T(1) = 1
// Best case O(1), average case O(1), worst case is o(n)
int linearsearchrec(int *a, int items, int key) {
	if (items < 0) return -1;
	
	if (a[items] == key) return items;
	
	return linearsearchrec(a, items - 1, key);
}

// Best Case O(1), Average Case is Sum(k/n) for k = 1 to n hence O(n), worst case is O(n)
int linearsearch(int *a, int items, int key) {
	int i;
	for(i = 0; i < items; i += 1){
		if (a[i] == key) return i;
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
	
	printf("\nITERATIVE: %s", (linearsearch(a, items, key) != -1 ? "Found item" : "Not found"));
	printf("\nRECURSIVE: %s", (linearsearchrec(a, items, key) != -1 ? "Found item" : "Not found"));
}
