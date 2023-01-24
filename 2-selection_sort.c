#include "sort.h"

/**
 * selection_sort - sorts an array on integers using the
 *	selection sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	for (i = 0; i < size; i++)
	{
		min = i;

		for (j = i; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min == i)
			continue;
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
