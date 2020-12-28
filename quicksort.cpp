//Kevin Le
//12/5/2020


#include <iostream>


using namespace std;


void quick(int[], int p, int r);
int partition(int[], int p, int r);
void print(int[], int);

int count = 0;

int main() {
	int a[] = {1, 10, 2, 5, 8, 9, 7, 6};
	int size = sizeof(a) / sizeof(int);
	print(a, size);
	quick(a, 0, size - 1);	//NOT size: since the last valid index is size-1
	print(a, size);

	return 0;
}


//time complexity: O(N lgN) < O(N * N)
void quick(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quick(a, p, q - 1);
		quick(a, q + 1, r);
	}
} 



//para a: array
//para p: low index
//para r: high index

//partition() will put smaller elements on the left,
//put larger elements on the right
//put the pivot elements to the correct spot

int partition(int a[], int p, int r) {
	int x = a[r];					//make a copy of the rightmost element in the range ==> x
	int i = p - 1;					//define index i, initialized to (lower bound - 1)
	for (int j = p; j < r; ++j) {	//range: [lower bound, higher bound)
		if (a[j] <= x) {			//if the running ele is less or equal to x
		++i;						//increase index i
		swap(a[i], a[j]);			//swap a[i] and a[j] 
		}
	}
	swap(a[i + 1], a[r]);			//swap the rightmost element to the partition point
	return i + 1;					//i + 1 will be the partition point, element on it is already sorted
}


void print(int a[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}
