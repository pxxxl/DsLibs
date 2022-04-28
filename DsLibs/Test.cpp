#include <iostream>
#include "Sorts.h"
#include "e_d_list.hpp"

using namespace std;
using namespace eds;

int main()
{
	int arr[10] = { 1,5,2,5,3,45,4,5,5,64 };
	mergeSortDT(arr, 10, true);
	printArray(arr, 10);
}
