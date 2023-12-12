#include <iostream>


void read_mas(int* mass, int n)
{
    for (int i = 0; i < n; ++i) {
        std::cin >> mass[i];
    }    
}

bool is_one(int* mass, int n)
{
    for (int i = 0; i < n; ++i)
    {

        int x = mass[i];

        while (x > 9)
        {
            x /= 10;
        }

        if (x == 1)
        {
            return true;
        }

        return false;
    }
}

void sort_mas(int* mass, int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (mass[i] > mass[j])
            {
                int tmp = mass[i];
                mass[i] = mass[j];
                mass[j] = tmp;
            }
}

void write_mas(int* mass, int n)
{
    for (int i = 0; i < n; ++i) {
        std::cout << mass[i] << std::endl;
    }
}


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
        exit(-1); // функция остановки. программа выведет -1.
    }

    int* mass = new int[n];

    int i = 0;

    read_mas(mass, n);

    bool flag = is_one(mass, n);   


    if (flag)
    {
        sort_mas(mass, n);
    }

    write_mas(mass, n);

    delete[] mass;
    
}