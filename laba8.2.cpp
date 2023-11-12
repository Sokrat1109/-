
#include <iostream>
#include <fstream>
#define N 3000
#define SYMBS 33

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream fin("text.txt");

    char buff[100];

    for (int i = 0; i < 100; i++)
        buff[i] = 0;

    char words[N][100];
    int k = 0;

    while (!fin.eof())      // read
    {
        fin >> buff;

        for (int i = 0; i < 100; i++)
        {
            words[k][i] = buff[i];
            k++;
        }

        for (int i = 0; i < 100; i++)
        {
            buff[i] = 0;
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (words[i][j] >= 'а' && words[i][j] <= 'я')     // меняем регистр
                words[i][j] -= 'а' - 'А';
        }
    }

        /*int symbs[N][100];

    for (int i = 0; i < SYMBS; i++)
        for (int j = 0; j < 100; j++)                     // очищаем массив
            symbs[i][j] = 0;
            */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            int tmp = strlen(words[i][j]);     // здесь узнать количество букв в слове
            // потом как-то перевернуть слово и сравнить его с изначальным
        }

    }
}

