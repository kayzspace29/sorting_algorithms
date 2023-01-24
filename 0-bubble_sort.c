#include "sort.h"

/**
 * bubble_sort - sorts an array using the bubble sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int temp;
	int flag;

	if (!array)
		return;

	for (x = 0; x < size; x++)
	{

		flag = 0;
		for (y = 0; y < (size - x - 1); y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
			flag = 1;
		}
		if (!flag)
			break;
	}
}
