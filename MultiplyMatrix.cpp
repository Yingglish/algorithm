#include <iostream>
using namespace std;

/*
    求M[1:n]的最小计算量 
*/

int main()
{
    void MultiplyMatrix ( int*, int, int**, int** );
    void traceback ( int **, int, int );
    int n = 0;
    int *b = NULL;
    int **m = NULL;
    int **t = NULL;
    cout << "请输入连乘矩阵个数" << endl;
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
    cout << "请输入矩阵阶数下标长度为" << n + 1 << endl;
    for ( int p = 0; p < n + 1 ; p++ )
    {
        cout << "b[" << p << "]=";
        cin >> b[p];
    }
    MultiplyMatrix(b,n,m,t);
    //cout << t[1][1];
    cout << endl << "矩阵连乘最少次数为" << m[1][n] << endl;
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
    输入: n为连乘矩阵个数
*/

void MultiplyMatrix ( int* b, int n, int** m, int** t )
{
    for ( int i = 1 ; i <= n ; i++ ) //子链长度为1时连乘次数
    {
        m[i][i] = 0;
    }
    for ( int r = 2 ; r <= n ; r++ ) //r为子链的长度(子问题的规模)
    {
        for ( int i = 1 ; i <= n - r + 1 ; i++ ) //遍历矩阵连乘开始矩阵 子链前端点的范围 1 —— n-r+1
        {
            int j = i + r - 1; //确定矩阵连乘结束矩阵 子链的后端点
            m[i][j] = m[i][i] + m[i + 1][j] +  b[i - 1] * b[i] * b[j]; //最小数乘数的初始化,此时k为i
            t[i][j] = i ; //最佳断开位置为i
            for ( int k = i + 1 ; k < j; k++ )
            {
                // A[i:j] = A[i:k] * A[k + 1:j]
                int temp = m[i][k] + m[k + 1][j] + b[i - 1] * b[k] * b[j]; //将M[1:j]的最小数乘次数存入变量l中
                if ( temp < m[i][j] )
                {
                    m[i][j] = temp;
                    t[i][j] = k; /*将矩阵断开位置存入数组t中*/
                }
            }
        }
    }
}
/*构造最优解*/
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

