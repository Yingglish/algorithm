#include <iostream>
using namespace std; 

int main(int argc, char const *argv[])
{
    int n;
    cout << "请输入整数n :" << endl ;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for (int j = 0; j <= 2 - i; j++)//现打印空格
		{
			cout << " ";
		}
		for (int j = 0; j <= 2 * i; j++)
		{
			if(j==0||j==2*i)//在两端时打印数字
				cout << i+1;
			else
				cout << " ";
		}
		cout << endl;
    }
    for (int i = 0; i < n-1; i++)//菱形下半部分
	{
		for (int j = 0; j <= i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j <= n - 2 * i; j++)
		{
			if (j == 0 || j == n - 2 * i)
				cout << n - i - 1 ;
			else
				cout << " ";
		}
		cout << endl;
	}
    system("PAUSE");
    return 0;
}

