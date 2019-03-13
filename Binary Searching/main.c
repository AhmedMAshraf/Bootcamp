/*
 * main.c
 *
 *  Created on: Feb 11, 2019
 *      Author: AVE-LAP-062
 */


#include <stdio.h>
#include "Bubble_Sort.h"
#include "Binary_Search.h"

int main(){

	int arr[ARR_SIZE] = {1, 55, 10, 23, 6, 12, 44, 2, 0, 15, 43, 7};
	int index ;
	index = Linear_search_algo(arr, ARR_SIZE, 7);
	if(index == -1 ){
		printf("Target not found in the array\n");
	}
	else{
		printf("Target is found in the array at index %d\n", index);
	}
	Bubble_sort_algo(arr,ARR_SIZE);
	index = Binary_search_algo(arr,ARR_SIZE, 55);
	if(index == -1 ){
		printf("Target not found in the array\n");
	}
	else{
		printf("Target is found in the array at index %d\n", index);
	}
}
