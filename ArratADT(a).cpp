#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Array {
	int A[10];
	int size;
	int length;

};
//DISPLAY FUNCTION OF AN ARRAY
//arr is used when we don't want to modify the array
void display(struct Array arr) {

	int i;
	cout << "\nelemnts are\n";
	for (i = 0; i < arr.length; i++)
		cout << arr.A[i] << " ";

}
//APPENDING AN ELEMENT IN AN ARRAY
//*arr is used when we want to modify the array
void append(struct Array* arr, int x) {
	if ((*arr).length < (*arr).size) {
		(*arr).A[(*arr).length++] = x;
	}
}
//INSERTING AN ELEMENT AN ARRAY
//*arr is used when we want to modify the array
void insert(struct Array* arr, int index, int x) {
	int i;
	if (index >= 0 && index <= (*arr).length) {
		for (i = (*arr).length; i > index; i--)
			(*arr).A[i] = (*arr).A[i - 1];
		(*arr).A[index] = x;
		(*arr).length++;
	}
}
//DELEATING AN ELEMENT IN AN ARRAY
//*arr is used when we want to modify the array
int Delete(struct Array* arr, int index) {

	int x = 0;
	int i;
	if (index >= 0 && index < (*arr).length) {
		x = (*arr).A[index];
		for (i = index; i < (*arr).length - 1; i++)
			(*arr).A[i] = (*arr).A[i + 1];
		(*arr).length++;
		return x;

	}


	return 0;
}

void swap1(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

}

//LINEAR SEARCH IN AN ARRAY
//*arr is used when we want to modify the array
int linearSearch(struct Array* arr, int key) {
	int i;
	for (i = 0; i < (*arr).length; i++) {
		if (key == (*arr).A[i]) {
			swap1(&arr->A[i], &arr->A[0]);
			return i;
		}
	}
	return -1;
}

//BINARY SEARCH IN AN ARRAY
//arr is used when we don't want to modify the array
int binaraySearch(struct Array arr, int key) {
	int l, mid, h;
	l = 0;
	h = arr.length - 1;
	while (l <= h) {
		mid = (l + h) / 2;
		if (key == arr.A[mid])
			return mid;
		else if (key < arr.A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}
//BINARY SEARCH IN AN ARRAY USING RECURSION
int RBinSearch(int a[], int l, int h, int key) {
	int mid;
	if (l <= h) {
		mid = (l + h) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			return RBinSearch(a, l, mid - 1, key);
		else
			return RBinSearch(a, mid + 1, h, key);
	}

	return -1;
}
//get function
//arr is used when we don't want to modify the array
int Get(struct  Array arr,int index)
{
	if (index >= 0 && index < arr.length)
		return arr.A[index];
	return 0;
}
//set function
//*arr is used when we want to modify the array
void Set(struct  Array *arr, int index,int x)
{
	if (index >= 0 && index < (*arr).length)
		(*arr).A[index] = x;
}
//maximum functin
//arr is used when we don't want to modify the array
int Max(struct Array arr) {
	int max = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++) {
		if (arr.A[i] > max)
			max = arr.A[i];
	}
	return max;

}
//minimum function
//arr is used when we don't want to modify the array
int Min(struct Array arr) {
	int min = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++) {
		if (arr.A[i] < min)
			min = arr.A[i];
	}
	return min;

}
//sum function
//arr is used when we don't want to modify the array
int Sum(struct Array arr) {
	int s = 0, i;
	for (i = 0; i < arr.length; i++)
		s += arr.A[i];
	return s;
}
//average function
//arr is used when we don't want to modify the array
float Avg(struct Array arr) {
	return (float) Sum(arr) / arr.length;
}

//reversing the elemnts in an array
//*arr is used when we want to modify the array
void Reverse(struct Array* arr) {
	int* B, i, j;
	B = (int*)malloc(arr->length * sizeof(int));
	for (i = (*arr).length - 1, j = 0; i >= 0; i--, j++)
		B[j] = (*arr).A[i];
	for (i = 0; i < (*arr).length;i++)
		(*arr).A[i] = B[i];
}
//reversing the elements in an array logic 2
//*arr is used when we want to modify the array
void Reverse2(struct Array* arr) {
	int i, j;
	for (i = 0, j = (*arr).length - 1; i < j; i++, j--) {
		swap1(&(*arr).A[i], &(*arr).A[j]);
	}
}
//rotating the elements of an array
//*arr is used when we want to modify the array
void leftRotate(struct Array* arr) {
	int i,j;
	j = (*arr).A[0];
	for (i = 0; i < (*arr).length; i++) {
		(*arr).A[i] = (*arr).A[i + 1];
	}
	cout << j;
	
}
//inserting an element in a sorted array
//*arr is used when we want to modify the array
void insertSort(struct Array* arr,int x) {
	int i = (*arr).length - 1;
	if ((*arr).length == (*arr).size) {
		return;
	}
	while (i>=0 && arr->A[i] > x) {
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = x;
	arr->length++;
}
//arr is used when we don't want to modify the array
int isSort(struct Array arr) {

	int i;
	for (i = 0; i < arr.length; i++) {
		if (arr.A[i] > arr.A[i + 1]) 
			return 0;
	}
	return 1;

}
//rearranging the elemnts in an array
void reArrange(struct Array *arr) {
	int i, j;
	i = 0;
	j = arr->length-1;
	while (i < j) {
		while (arr->A[i] < 0)i++;
		while (arr->A[i] > 0)j--;
		if (i < j)swap1(&arr->A[i], &arr->A[j]);
	}
	
}
//merging of 2 arrays
struct Array* merger(struct Array* arr1, struct Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));//creating array in heap

	while (i < arr1->length && j < arr2->length) {
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr1->A[j++];
	}
	for(;i<arr1->length;i++)//i is starting from where ever it is
		arr3->A[k++] = arr1->A[i];
	for (; j < arr2->length; j++)//j is starting from where ever it is
		arr3->A[k++] = arr1->A[j];
	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;
	return arr3;
}

//union operation on an array
struct Array* Union(struct Array* arr1, struct Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));//creating array in heap

	while (i < arr1->length && j < arr2->length) {
		if (arr1->A[i] < arr2->A[j])       // check if a1[i] < a2[j]
			arr3->A[k++] = arr1->A[i++];
		else if(arr2->A[j]<arr1->A[i])
			arr3->A[k++] = arr1->A[j++];
		else {
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	for (; i < arr1->length; i++)//i is starting from where ever it is
		arr3->A[k++] = arr1->A[i];
	for (; j < arr2->length; j++)//j is starting from where ever it is
		arr3->A[k++] = arr1->A[j];
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

//function for intersection on a set of arrays
struct Array* Intersection(struct Array* arr1, struct Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));//creating array in heap

	while (i < arr1->length && j < arr2->length) {
		if (arr1->A[i] < arr2->A[j])       // check if a1[i] < a2[j] then i++
			i++;
		else if (arr2->A[j] < arr1->A[i]) // check if a1[i] > a2[j] then j++
			j++;
		else if (arr1->A[i] == arr2->A[j]) {  // check if a1[i] = a2[j] then copy the elements
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

//function for difference on a set of array
struct Array* Difference(struct Array* arr1, struct Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));//creating array in heap

	while (i < arr1->length && j < arr2->length) {
		if (arr1->A[i] < arr2->A[j])       // check if a1[i] < a2[j]
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else {
			i++;
			j++;
		}
	}
	for (; i < arr1->length; i++)//i is starting from where ever it is and copy elements from array 1 
		arr3->A[k++] = arr1->A[i];
	
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

int main() {
	//struct Array arr = {{1,-2,3,-4,-5,8},10,6};
	struct Array arr1 = {{2,6,10,15,25},10,5};
	struct Array arr2 = {{3,6,7,15,20},10,5};
	struct Array *arr3;
	arr3 = Difference(&arr1, &arr2);
	display(*arr3);
	return 0;
}