#include <iostream>
#include <vector>

using namespace std;

int Partition(int arr[], int left, int right, int pivot)
{
	int p = arr[pivot];
	std::swap(arr[pivot], arr[right]);
	int stidx = left;
	for (int i = left; i < right; i++)
	{
		if (arr[i] > p)
			continue;

		std::swap(arr[stidx], arr[i]);;
		stidx++;
	}
	std::swap(arr[right], arr[stidx]);
	return stidx;
}

void QuickSort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int pivot = Partition(arr, left, right, left);
	QuickSort(arr, left, pivot - 1);
	QuickSort(arr, pivot + 1, right);
}

bool IsExist(int arr[], int start, int end, int f)
{
	int p = (start + end) * 0.5;
	if (arr[p] == f)
		return true;
	if (end - start < 1)
		return false;

	return (f < arr[p]) ? IsExist(arr, start, p, f) : IsExist(arr, p + 1, end, f);
}

int main() 
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	QuickSort(&v[0], 0, v.size() - 1);
	
	int m;
	scanf("%d", &m);
	vector<int> res(m);
	for (int i = 0; i < m; i++)
		scanf("%d", &res[i]);
	
	for (int i=0; i<res.size(); i++)
		printf("%d\n", IsExist(&v[0], 0, v.size() - 1, res[i]));
	return 0;
}