#include <iostream>
#include <vector>

using namespace std;

void QuickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[right];

	/* partition */
	while (i <= j) {
		//pivot과 같아도 빠져나가기 때문에 배열범위를 넘어서는 일은 없다
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		//찾았다
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			//이게중요하다
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		QuickSort(arr, left, j);

	if (i < right)
		QuickSort(arr, i, right);
}

int main() 
{
	int n;
	vector<int> v;
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	QuickSort(&v[0], 0, v.size() -1);
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);

	return 0;
}