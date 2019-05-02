#include <iostream>
using namespace std;

/*
    ��M[1:n]����С������ 
*/

int main()
{
    void MultiplyMatrix ( int*, int, int**, int** );
    void traceback ( int **, int, int );
    int n = 0;
    int *b = NULL;
    int **m = NULL;
    int **t = NULL;
    cout << "���������˾������" << endl;
    cin >> n;
    b = new int[n + 1];
    m = new int*[n + 1];
    t = new int*[n + 1];
    for ( int x = 0 ; x < n + 1 ; x++ )
    {
        m[x] = new int[n + 1];
        t[x] = new int[n + 1];
    }
    for ( int i = 0 ; i < n + 1 ; i++ )
    {
        for ( int j = 0 ; j < n + 1 ; j++ )
        {
            m[i][j] = 0;
            t[i][j] = 0;
        }

    }
    cout << "�������������±곤��Ϊ" << n + 1 << endl;
    for ( int p = 0; p < n + 1 ; p++ )
    {
        cout << "b[" << p << "]=";
        cin >> b[p];
    }
    MultiplyMatrix(b,n,m,t);
    //cout << t[1][1];
    cout << endl << "�����������ٴ���Ϊ" << m[1][n] << endl;
    traceback ( t, 1, n );
    cout << endl;
    for(int q = 0 ; q < n + 1 ; q++)
    {
        delete[] m[q];
        delete[] t[q];
    }
    return 0;
}

/*
    ����: nΪ���˾������
*/

void MultiplyMatrix ( int* b, int n, int** m, int** t )
{
    for ( int i = 1 ; i <= n ; i++ ) //��������Ϊ1ʱ���˴���
    {
        m[i][i] = 0;
    }
    for ( int r = 2 ; r <= n ; r++ ) //rΪ�����ĳ���(������Ĺ�ģ)
    {
        for ( int i = 1 ; i <= n - r + 1 ; i++ ) //�����������˿�ʼ���� ����ǰ�˵�ķ�Χ 1 ���� n-r+1
        {
            int j = i + r - 1; //ȷ���������˽������� �����ĺ�˵�
            m[i][j] = m[i][i] + m[i + 1][j] +  b[i - 1] * b[i] * b[j]; //��С�������ĳ�ʼ��,��ʱkΪi
            t[i][j] = i ; //��ѶϿ�λ��Ϊi
            for ( int k = i + 1 ; k < j; k++ )
            {
                // A[i:j] = A[i:k] * A[k + 1:j]
                int temp = m[i][k] + m[k + 1][j] + b[i - 1] * b[k] * b[j]; //��M[1:j]����С���˴����������l��
                if ( temp < m[i][j] )
                {
                    m[i][j] = temp;
                    t[i][j] = k; /*������Ͽ�λ�ô�������t��*/
                }
            }
        }
    }
}
/*�������Ž�*/
void traceback ( int **t, int i, int j )
{
    if ( i == j )
    {
        cout << "M" << i;
    }
    else
    {
        cout << "(";
        traceback ( t, i, t[i][j] );
        traceback ( t, t[i][j] + 1, j );
        cout << ")";
    }
}

