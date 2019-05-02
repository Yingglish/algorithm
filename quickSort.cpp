#include <iostream>
using namespace std;

int main()
{
	int quickSort ( int*, int, int );
	int n;
	cout << "请输入要排序原始个数:\n";
	cin >> n;
	int *arr = new int[n];
	for ( int i = 0 ; i < n ; i++ )
	{
		cout << "请输入第" << i + 1 << "个元素" << endl;
		cin >> arr[i];
	}
	quickSort ( arr, 1, n - 1 );
	cout << "排序后\n";
	for ( int j = 0 ; j < n ; j++ )
	{
		cout << arr[j] << " ";
	}
	cout  << endl;
	delete[] arr;
	return 0;
}

void quickSort ( int *a, int low, int high )
{
	if ( low > high )
	{
		return;
	}
	int i = 0, j = 0, temp;
	temp = a[low]; //基准数
	i = low;
	j = high;
	while ( i != j )
	{
		//从右开始查找比基准数小的第一个数
		while ( i < j && a[j] >= temp )
			j--;
		while ( i < j && a[i] <= temp )
			i++;
		if ( i < j )
			swap ( a[i], a[j] );
	}
	swap ( a[low], a[i] ); //基准数归位
	quickSort ( a, low, i - 1 );
	quickSort ( a, i + 1, high );
}
