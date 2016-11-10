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
		//pivot�� ���Ƶ� ���������� ������ �迭������ �Ѿ�� ���� ����
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		//ã�Ҵ�
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			//�̰��߿��ϴ�
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