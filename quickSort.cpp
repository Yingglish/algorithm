#include <iostream>
using namespace std;

int main()
{
	int quickSort ( int*, int, int );
	int n;
	cout << "������Ҫ����ԭʼ����:\n";
	cin >> n;
	int *arr = new int[n];
	for ( int i = 0 ; i < n ; i++ )
	{
		cout << "�������" << i + 1 << "��Ԫ��" << endl;
		cin >> arr[i];
	}
	quickSort ( arr, 1, n - 1 );
	cout << "�����\n";
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
	temp = a[low]; //��׼��
	i = low;
	j = high;
	while ( i != j )
	{
		//���ҿ�ʼ���ұȻ�׼��С�ĵ�һ����
		while ( i < j && a[j] >= temp )
			j--;
		while ( i < j && a[i] <= temp )
			i++;
		if ( i < j )
			swap ( a[i], a[j] );
	}
	swap ( a[low], a[i] ); //��׼����λ
	quickSort ( a, low, i - 1 );
	quickSort ( a, i + 1, high );
}
