#include <iostream>
#include "Sorts.h"
#include "Search.h"
#include "e_d_list.hpp"

using namespace std;
using namespace eds;

int main()
{
	int arr[9] = { 1,5,2,5,3,45,4,5,64 };
	//shellSort(arr, 9, true);
	printArray(arr, 9);
	cout << endl;
	cout << binarySearchTreeSearch(arr, 9, 45);
}
