#include <iostream>
#include <string>

/*
* http://www.crocus.co.kr/708 ÀÌºÐ ²¬ º¸°í ¹è¿ü´Ù.
*/

#define MAX 50

using namespace std;


string arr[MAX];

void backtracking(string s, const int cur, const int count, const int& K)
{
	if (count >= 6)
	{
		cout << s << endl;
		return;
	}

	for (int i = cur; i < K; i++)
		backtracking(s + arr[i] + " ", i + 1, count + 1, K);
}

int main()
{
	while (true)
	{
		int k = 0;
		cin >> k;
		if (k == 0)
			break;

		for (int i = 0; i < k; i++)
			cin >> arr[i];

		backtracking("", 0, 0, k);
		cout << endl;
	}

	return 0;
} 