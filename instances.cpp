#include "instances.h"
#include<ctime>
#include <stdlib.h>
void instances::initiate(int n) {

	// If the array wasn't already initialized
	if (!initialize) {
		// Set initialize to true;
		initialize = true;
	}
	else {
		// Deallocate the previous array
		delete[] arr;
	}

	// Create new array with n elements.
	length = n;
	arr = new int[length];
	for (int i = 0; i < length; i++) {
		*(arr + i) = i;
	}
}

//decresing and increasing uses the same algorithm as insertion sort
void instances::increasing() {
	int j, temp;

	// Loop through the array until length is reached.
	for (int i = 0; i < length; i++) {
		// Set the the current i to be checked.
		j = i;
		// Swap the element backwards until it is greater than the element before it.
		while (j > 0 && *(arr + j) < *(arr + j - 1)) {
			temp = *(arr + j);
			*(arr + j) = *(arr + j - 1);
			*(arr + j - 1) = temp;
			j -= 1;
		}

	}
}

void instances::decreasing() {
	int j, temp;
	for (int i = 0; i < length; i++) {

		// Set the current to be checked element.
		j = i;

		// Swap the element backwards until it is less than the element before it.
		while (j > 0 && *(arr + j) > * (arr + j - 1)) {
			temp = *(arr + j);
			*(arr + j) = *(arr + j - 1);
			*(arr + j - 1) = temp;
			j -= 1;
		}
	}
}

//algorithm for creating random array. rand is in cstdlib library.
void instances::random() {
	// seed rand with starting value.
	srand(time(0));
	int r, temp;
	for (int i = 0; i < length; i++) {
		// Get a random position.
		r = rand() % length;
		// Temp current element.
		temp = *(arr + i);
		// Give current element the value from random position.
		*(arr + i) = *(arr + r);
		// Give the random element the current value.
		*(arr + r) = temp;
	}
}

//returns private data
int* instances::getArray()
{
	return arr;
}

int instances::getLength() const
{
	return length;
}
