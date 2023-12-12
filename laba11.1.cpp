

#include <iostream>

void read_matrix(int** matrixA, int n, int m)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> matrixA[i][j];
}

int sum_str(int** matrixA, int n, int m)
{

    int min = INT_MAX;
    int str = -1;

    for (int i = 0; i < n; ++i)
    {
        int sum = 0;

        for (int j = 0; j < m; ++j)
            sum = sum + matrixA[i][j];

        if (min > sum)
        {
            min = sum;
            str = i;
        }
    }

    return str;
}

void write_matrix(int** matrixA, int n, int m)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrixA[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
}


int main()
{
    std::cout << "number 3. " << std::endl;
    std::cout << " " << std::endl;


    const int N_Max = 100;
    const int M_Max = 100;

    int n, m;

    std::cout << " vvedite kolvo" << std::endl;
    std::cin >> n >> m;

    if (n > N_Max || m > M_Max)
    {
        std::cout << "error" << std::endl;
        return -1;
    }

    int** matrixA = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matrixA[i] = new int[m];
    }

    read_matrix(matrixA, n, m);

    int str = sum_str(matrixA, n, m);

    for (int j = 0; j < m; ++j) {

        matrixA[str][j] = 0;
    }

    write_matrix(matrixA, n, m);

    delete[] matrixA[0];
    delete[] matrixA;

}

