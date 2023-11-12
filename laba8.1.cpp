// laba8.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#define N 2000
#define N_WORDS 3000    // количество столбцов
#define SYMBS 33     // количество русских букв по алфавиту

int main()
{
    setlocale(LC_ALL,"Russian");

    std::ifstream fin("rtr.txt");  // открываем файл

    char buff[100];
    for (int i = 0; i < 100; i++)    // удаляем мусор из созданного массива
        buff[i] = 0;

    char words[N_WORDS][100];  // массив для сохранения слов

    char max_symb_in_word[N_WORDS];  // наиболее частый символ 
    int count_mas_symb[N_WORDS];  // количество наиболее частого символа

    int count_of_words = 0;   // количество слов
    int k = 0;

    for (int i = 0; i < N_WORDS; i++) {   // удаляем мусор из двух массивов
        max_symb_in_word[i] = 0;
        count_mas_symb[i] = 0;
    }


    while (!fin.eof()) // пока файл не пустой
    {
        fin >> buff; // считываем слово до пробела
        count_of_words++;  // количество слов увеличивается на 1

        for (int i = 0; i < 100; i++)
            words[k][i] = buff[i];  // запоминаем слово
        k++;

        for (int i = 0; i < 100; i++)  // очищаем буфер, чтобы записать новое слово
            buff[i] = 0;
    }

    int symbs[SYMBS];    // массив с количеством повторов у каждой буквы, размер 33 символа

    for (int i = 0; i < SYMBS; i++)   // очищаем массив
        symbs[i] = 0;


    for (int i = 0; i < count_of_words; i++)    // пока И меньше количества слов
    {
        for (int j = 0; j < 100; j++)              //   j  меньше максимального размера слова
        {
            if (words[i][j] >= 'А' && words[i][j] <= 'Я')     // меняем регистр
                words[i][j] += 'а' - 'А';                // делаем все буквы строчными
        }
    }

    // 0 1 2 3 4 5 ......... 32
    // А Б В Г Д Е ......... Я
    // а = -32
    // б = -31
    // и тд
    // 
    //0 0 0 0 0 0
    //2 0 0 1 0 0

    int max_symb = 0;  // самый часто встречающийся символ
     
    for (int i = 0; i < count_of_words; i++)     // пока меньше количества слов  // проходим по каждому слову
    {
        for (int j = 0; j < 100; j++)   //пока меньше 100 (максимальная длина одного слова)  // проходим по каждой букве
        {
            if (words[i][j] >= 'а' && words[i][j] <= 'я') {    // если буква в дипазоне от а до я строчных
                symbs[(int)words[i][j] + 32]++;    //  то к ее соответствующему нолику (количеству таких букв) мы прибавляем 1
            }                     // мы взяли букву и принудительно дали ей тип инт, затем прибавили 32, чтобы привести ее к диапазону от 0 до 32 (т.е. 33 символа)
        }

        for (int m = 0; m < SYMBS; m++)  // обрабатываем таблицу с количеством каждого символа в слове
        {
            if (symbs[m] > max_symb)    // ищем максимальное количество повторений одной буквы
            {
                max_symb = symbs[m];   // записываем эту букву
                max_symb_in_word[i] = m - 32;    // записываем саму букву         // номер буквы в таблице, переводим обратно в -32 для чара
                count_mas_symb[i] = max_symb;   // записываем количество повторений этой буквы

            }
        }
        for (int i = 0; i < SYMBS; i++)   // очищаем массив повторов для следующего слова
            symbs[i] = 0;

        max_symb = 0;

    }

    int stock[N_WORDS];   // запасной массив
    for (int i=0; i<N_WORDS; i++)   // очищаем его
        
        stock[i] = 0;
        

        int tmp = 0;
    for (int i = 0; i < count_of_words - 1; i++)    // отвечает за номер строки
    {
        for (int j = i + 1; j < count_of_words; j++) {       // отвечает за следующий элемент
            if (count_mas_symb[i] < count_mas_symb[j]) {
                tmp = max_symb_in_word[i];             // меняем саму букву
                max_symb_in_word[i] = max_symb_in_word[j];
                max_symb_in_word[j] = tmp;

                tmp = count_mas_symb[i];             // меняем количество повторов этой буквы
                count_mas_symb[i] = count_mas_symb[j];
                count_mas_symb[j] = tmp;

                for (int k = 0; k < 100; k++) {
                    stock[i] = words[i][k];           // меняем само слово
                    words[i][k] = words[j][k];
                    words[j][k] = stock[i];
                }
            }
        }           // в итоге вопрос, почему мы вообще записываем каждое слово как двухмерный массив
    }


    for (int i = 0; i < count_of_words; i++) {         // вывод
        for (int j = 0; j < 100; j++)
            std::cout << words[i][j];               // слово по букве
        std::cout << std::endl << max_symb_in_word[i] << count_mas_symb[i] << std::endl;           // частая буква + количество повторений
    }

   
    
    fin.close();
}

