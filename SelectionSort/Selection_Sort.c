/*********************************************************************************
 *
 *  Selection_Sort.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * As per explained algorithm, complete the below code to implement a fully
 * functional selection sort code
 *
 ********************************************************************************/
/* Haggag & Ashraf Team */
#include <stdio.h>
#include "Selection_Sort.h"


void selectionSort(int arr[], int arr_size)
{
	int i , j , temp ;
	for(i=0 ; i<arr_size ; i++)//ittiration loop
	{
		for(j=i+1 ; j<arr_size ; j++)
		{
			if(arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {64 ,64,25, 12, 22, 11,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
