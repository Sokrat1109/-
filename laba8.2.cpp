

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

    int kol = 0;   // количество букв в слове

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; words[i][j]!=0; j++)
        {
            // найти первое нулевое значение, пройтись по всей строке
            
            kol++;     // количество букв в слове
            // начинаем нумерацию с нуля
            // количество букв хранить в переменной
            // цикл должен быть до середины слова
            // сравниваем нулевой и последний, первый и предпоследний и тд
            // последний - количество букв минус один
            // прибавить единичку в левый, убавить из правого
            // если все элементы равны, то сделаем флажок 
            // как только нашли слово палиндром, делаем брейк

        }

        int m = 0;    //счетчик
        int n = kol;    //изменяемое количество букв
        bool flag = false;

        while (n > 0)   
        {
            for (int j = 0; j < kol; j++)
            {
                if (words[i][j] == words[i][n - 1])   // сравнение первой и последней буквы
                    m++;     // счетчик +1
                n--;     // последнюю букву убираем. первая убирается самим циклом
            }
            
            if (m == (kol /= 2))   // если счетчик = половине количества бувк
            {
                flag = true;
            }
        }
        
        if (flag)
            break;

    }



}
