#include<iostream>
#include<vector>

using namespace std;

void quicksort(vector<int>& arr, const int left, const int right);
int partition(vector<int>& arr, const int left, const int right, const int pivot);

vector<int> arr;
int N = 0;

int main()
{
	scanf("%d", &N);
	arr.resize(N + 1);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	quicksort(arr, 0, N - 1);

	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	return 0;
}

void quicksort(vector<int>& arr, const int left, const int right)
{	
	if (right <= left)
		return;

	const int pivot = (right + left) / 2;
	const int new_pivot = partition(arr, left, right, pivot);

	quicksort(arr, left, new_pivot - 1);
	quicksort(arr, new_pivot + 1, right);
}

int partition(vector<int>& arr, const int left, const int right, const int pivot)
{
	int pivot_value = arr[pivot];
	swap(arr[pivot], arr[right]);

	int idx = left;
	for (int i = left; i <= right - 1; i++)
	{
		if (arr[i] <= pivot_value)
		{
			swap(arr[idx], arr[i]);
			idx++;
		}
	}
	
	swap(arr[idx], arr[right]);
	
	return idx;
}