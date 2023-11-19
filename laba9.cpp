#include <iostream>
#include <math.h>
#define N 1000
#define M 1000

/*bool stolb(int matrix[N][M])
{
    bool flag = false;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == matrix[i + 1][j])
            {
                k++;
            }
        }

        if (k = j)
        {
            flag = true;
        }
    }

}
*/

int matrix[N][M];

int main()
{
    setlocale(LC_ALL, "Russian");


    int n, m;

    std::cout << "введите количество строк и столбцов ";
    std::cin >> n >> m;

    std::cout << "введите элементы матрицы " << std::endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];

    std::cout << std::endl;

    // если в матрице есть 2 одинаковых столбца
    // если есть простое по модулю число
    // модуль элемента -> сумма модулей

    bool flag = false;  // есть ли два одинаковых столбца
    int k = 0;  // счетчик
    int d;  // вспомогательный счетчик

    for (int i = 0; i < n; i++)
    {
        for (d = 0; d < m; d++)
        {
            if (matrix[i][d] == matrix[i + 1][d])
            {
                k++;
            }
        }

        if (k = d)
        {
            flag = true;
        }
    }

    bool flag2 = false;  // проверка на простое число
    int s = 0;  // счетчик
    int y;  // вспомогательный счетчик

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (y = 2; y < matrix[i][j]; y++)  // sqrt(matrix[i][j])+1
            {
                if (abs(matrix[i][j]) % y != 0)
                    s++;
            }

            if (y == s)
                flag2 = true;
        }
    }

    int massive[N];

    if (flag == true && flag2 == true)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                massive[i] += abs(matrix[i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (massive[i] > massive[i + 1])
            {
                for (int j = 0; j < m; j++)
                {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[i + 1][j];
                    matrix[i + 1][j] = tmp;
                }
            }
        }
    }

    std::cout << "Ваша матрица : " << std::endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}



