


#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    

    std::cout << "number 1. " << std::endl;

    const int N_MAX = 10000;

    int n;
    std::cout << "Введите количество чисел в последовательности" << std::endl;
    std::cin >> n;

    if (n > N_MAX) {
        std::cout << "error" << std::endl;
    }

    int mas[N_MAX];

    int i = 0;
    bool flag = false;

    for (i = 0; i < n; i++) {
        std::cin >> mas[i];
    }

    for (i = 0; i < n; i++)
    {

        int x = mas[i];

        while (x > 9)
        {
            x /= 10;
        }

        if (x == 1)
        {
            flag = true;
            break;
        }


    }


    if (flag)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (mas[i] > mas[j])
                {
                    int tmp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = tmp;
                }
    }


    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << std::endl;
    }


 


 
std::cout << "number 2. " << std::endl;
std::cout << " " << std::endl;


const int M_MAX = 1000;

int n;
std::cout << "Введите количество чисел в последовательности" << std::endl;
std::cin >> n;

if (n > M_MAX) {
    std::cout << "error" << std::endl;
}

int mas[M_MAX];
int first[M_MAX];
int sum[M_MAX];


for (int i = 0; i < n; i++) {
    std::cin >> mas[i];
}

for (int i = 0; i < n; i++)
{
    first[i] = mas[i];
    while (first[i] > 9) {
        first[i] /= 10;
    }

    sum[i] = 0;
    int tmp = mas[i];
    while (tmp > 0)
    {
        sum[i] += tmp % 10;
        tmp /= 10;
    }
}

for (int i=0; i<n; i++)
    for (int j=i+1; j<n; j++)
        if ((first[i]>first[j])||
            ((first[i] == first[j]) && (sum[i] > sum[j])) ||
                ((first[i] == first[j]) && (sum[i] == sum[j]) && mas[i] > mas[j]))
        {
            int o = first[i];
            first[i] = first[j];
            first[j] = o;
            int p = sum[i];
            sum[i] = sum[j];
            sum[j] = p;
            int y = mas[i];
            mas[i] = mas[j];
            mas[j] = y;
        }


for (int i = 0; i < n; i++) {
    std::cout << mas[i] << std::endl;
}




    std::cout << "number 3. " << std::endl;
    std::cout << " " << std::endl;


    const int N_Max = 100;
    const int M_Max = 100;

    int matrixA[N_Max][M_Max];
    int n, m;

    std::cout << " vvedite kolvo" << std::endl;
    std::cin >> n >> m;

    if (n > N_Max || m > M_Max)
    {
        std::cout << "error" << std::endl;
        return -1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrixA[i][j];

    int min = INT_MAX;
    int str = -1;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = 0; j < m; j++)
            sum = sum + matrixA[i][j];

        if (min > sum)
        {
            min = sum;
            str = i;
        }
    }


    for (int j = 0; j < m; j++) {

        matrixA[str][j] = 0;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrixA[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
}
