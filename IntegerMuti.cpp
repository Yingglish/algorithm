#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int sign ( int n );
	int getNumberLength(int );
	int result ( int x, int y, int n );
	int X = 0, Y = 0;
	cout << "��������� X ,Y :" << endl;
	cin >> X >> Y;
	if ( result ( X, Y, getNumberLength(X) ) == X * Y )
	{
		cout << "�˻�Ϊ: " << result ( X, Y, getNumberLength(Y) ) << endl;
	}
	//cout << "�˻�Ϊ: " <<
	//result ( X, Y, 5 ) ;//<< endl;
	//cout << (X >> 1) << endl;
	system ( "pause" );
	return 0;
}

/*
  ��ȡ�������� +1 -1
*/
int sign ( int n )
{
	return n > 0 ? 1 : -1;
}
/*
  ��ȡ����λ��
*/
int getNumberLength(int x)
{
	int length = 0;
	while(x){
		x/=10;
		length ++;
	}
	return length;
}


/*
  ���η���nλ������X��Y�ĳ˻�
*/

int result ( int x, int y, int n )
{
	const int d = n;
	int SIGN = sign ( x ) * sign ( y ); //�õ����ų˻�
	int X = abs ( x ); // ȡ����ֵ
	int Y = abs ( y );


	if ( X == 0 || Y == 0 )
	{
		return 0;
	}
	else if ( n == 1 )
	{

		return SIGN * X * Y;
	}
	else
	{
		int x_left = X / ( int ) pow ( 10, n >> 1 ); //ȡx�����n/2λ
		// cout << x_left << endl;
		int x_right = X % ( int ) pow ( 10, n >> 1 ); //ȡx���ұ�n/2λ
		//cout <<"x_l =  "<< x_left << " " << x_right << endl;
		int y_left = Y / ( int ) pow ( 10,  n >> 1 );
		int y_right = Y % ( int ) pow ( 10, n >> 1 ); //ȡy���ұ�n/2λ

		//cout << "x_l-x_r= " << getNumberLength(y_right-y_left) << endl;
		int m1 = result ( x_left, y_left, getNumberLength(x_left) );
		//cout << endl << "m1 = " << m1 << endl;
		int m2 = result ( x_left + x_right, y_right + y_left,getNumberLength(x_left +x_right) );
		//cout << m2 << endl;;
		int m3 = result ( x_right, y_right, getNumberLength(abs(x_right)) );
		//cout << m3;
		if((d & 1) == 1)
		{
			//���λ��Ϊ����
			return SIGN * ( m1 * ( int ) pow ( 10, n - 1) + ( m2 - m1 -m3 ) * ( int ) pow ( 10, n >> 1 )  +m3 );
		}
		else
		{
			//���λ��Ϊż��
			return SIGN * ( m1 * ( int ) pow ( 10, n ) + ( m2 - m1 -m3 ) * ( int ) pow ( 10, n >> 1 ) +m3 );
		}
	}
}




