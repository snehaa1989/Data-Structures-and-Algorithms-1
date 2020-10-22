/* C++ program to implement Pigeonhole Sort */
#include <iostream> 
#include <vector>
using namespace std; 

/* Sorts the array using pigeonhole algorithm */
void pigeonholeSort(int arr[], int n) 
{ 
	// Find minimum and maximum values in arr[] 
	int Minimum = arr[0], Maximum = arr[0]; 
	for (int i = 1; i < n; i++) { 
		if (arr[i] < Minimum) 
			Minimum = arr[i]; 
		if (arr[i] > Maximum) 
			Maximum = arr[i]; 
	} 
	int range = Maximum - Minimum + 1; // Find range 

	// Create an array of vectors. Size of array 
	// range. Each vector represents a hole that 
	// is going to contain matching elements. 
	vector<int> holes[range]; 

	// Traverse through input array and put every 
	// element in its respective hole 
	for (int i = 0; i < n; i++) 
		holes[arr[i] - Minimum].push_back(arr[i]); 

	// Traverse through all holes one by one. For 
	// every hole, take its elements and put in 
	// array. 
	int index = 0; // index in sorted array 
	for (int i = 0; i < range; i++) { 
		vector<int>::iterator it; 
		for (it = holes[i].begin(); it != holes[i].end(); ++it) 
			arr[index++] = *it; 
	} 
} 

// Main
int main() 
{ 
	
	int n;
    cin>>n;//take input number of elements
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

	pigeonholeSort(arr, n); 

	
	for (int i = 0; i < n; i++) 
	{
         cout<<arr[i]<<" ";
     }

	return 0; 
} 
//INPUT:  5
//        4 1 2 3 5
//OUTPUT: 1 2 3 4 5