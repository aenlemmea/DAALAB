#include <stdio.h>
#include <stdlib.h>

// Complexity: 
/*
Worst Case::
ratio is O(1)
comparator is O(1)
qsort in main is O(n log n)
fknapsack does a O(n) scan to calculate answer.
Hence in total: O(1) + O(1) + O(n log n) + O(n) = O(n log n)

*/

typedef struct {
	int weight, profit;
} item;

double ratio(item it) {
	return (double) (it.profit / it.weight);
}

int comparator(const void *a, const void *b) {
	item aa = *(item*) a;
	item bb = *(item*) b;
	return ( ratio(aa) < ratio(bb)) ?   1
		:  ( ratio(aa) > ratio(bb)) ? -1
		:  ( 0 );
}

double fknapsack(item things[], int items, int capacity) {
	double ans = 0.0d;
	int i;
	for (i = 0; i < items && capacity > 0; i += 1) {
		if (things[i].weight <= capacity) {
			ans += things[i].profit;
			capacity -= things[i].weight;
		} else {
			double parts = (double) capacity / things[i].weight;
			ans += (parts * things[i].profit);
			capacity = 0;
		}
	}
	return ans;
}

int main(void) {
	int items, i, weight, profit, capacity;
	
	printf("\nEnter the number of items: ");
	scanf("%d", &items);
	
	item things[items];
	printf("\nEnter the weights and profits of the items:\n");
	
	for(i = 0, weight = 0, profit = 0; i < items; i += 1){
		scanf("%d %d", &weight, &profit);
		item thing = { .weight = weight, .profit = profit};
		things[i] = thing;
	}
	
	printf("\nEnter the capacity: ");
	scanf("%d", &capacity);
	
	qsort(things, items, sizeof(item), comparator); //n log n 
	printf("%.4lf\n", fknapsack(things, items, capacity));
}
