

#include <iostream>
#include <fstream>
#define N 3000

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream file("input.txt");

    char buff[100];

    for (int i = 0; i < 100; i++)
        buff[i] = 0;

    char words[N][100];

    int k = 0;

    while (!file.eof())
    {
        for (int i = 0; i < 100; i++)
        {
            words[k][i] = buff[i];
            k++;
        }

        for (int i = 0; i < 10; i++)
        {
            buff[i] = 0;
        }
    }


    // сделать массив количества каждой буквы в слове
    // найти пять наиболее часто встречающихся
    // найти слова, где таких букв минимум 4

}

