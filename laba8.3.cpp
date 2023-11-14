

#include <iostream>
#include <fstream>
#define N 3000
#define SYMBS 33

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream file("input.txt");
    std::ofstream file_out("output.txt");

    char buff = '0';

    char words[N];

    for (int i = 0; i < N; i++)
        words[i] = 0;

    int k = 0;// количество символов в строке

    while (!file.eof())
    {
        file.get(words[k]);      // считываем все символы как есть со знаками
        k++;           
    }
    k--;  // после выполнения цикла к тоже прибавится, и будет показывать на 1 больше чем нужно, поэтому к--

    for (int i = 0; i < k; i++)
        std::cout << words[i];

    char alph[SYMBS] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и', 'й',
                        'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у',
                        'Ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' };

    int alph_count[SYMBS];
    for (int i = 0; i < SYMBS; i++)
    {
        alph_count[i] = 0;
    }

    for (int i = 0; i < k; i++)
    {
       

        if ((words[i] >= 'А' && words[i] <= 'Я'))
        {
            alph_count[words[i] + 32 + 32]++; // А = -64, а= -32, тогда чтобы сделать 0, надо +32 +32
        }
        if ((words[i] >= 'а' && words[i] <= 'я'))
        {
            alph_count[words[i] + 32]++;
        }
    }

    for (int i = 0; i<SYMBS-1; i++)
        for (int j = i+1; j < SYMBS; j++)
        {
            if (alph_count[i] < alph_count[j])
            {
                char tmp = alph[i];
                alph[i] = alph[j];
                alph[j] = tmp;

                int tmpp = alph_count[i];
                alph_count[i] = alph_count[j];
                alph_count[j] = tmpp;
            }
        }

    char most_5[5] = { alph[0], alph[1], alph[2], alph[3], alph[4] };
    int most_5_count[5] = {0, 0, 0, 0, 0};
   
    int start = -1;   
    int finish = -1;
    int counter = 0;

    int i = 0;
    while (i < k)
    {
        if ((start == -1) && ((words[i] >= 'А' && words[i] <= 'Я') || (words[i] >= 'а' && words[i] <= 'я')))
            start = i;

        if((start != -1) && !((words[i] >= 'А' && words[i] <= 'Я') || (words[i] >= 'а' && words[i] <= 'я')))
            finish = i;  // следующий после последнего

        if (start == -1 && finish == -1)
            file_out << words[i];

        if (start != -1 && finish != -1)
        {
            std::cout << start << ' ' << finish << '\n';

            for (int n = start; n < finish; n++)  // по всему слову
            {
                for (int m = 0; m < 5; m++) // по самым популярным
                {
                    if (words[n] == most_5[m] || words[n] + 32 == most_5[m])
                    {
                        most_5_count[m]++;
                        counter++;  // количество популярных символов в слове
                    }
                }
            }

            if (counter >= 4)
            {
                for (int n = start; n < finish; n++)
                {
                    for (int m = 0; m < 5; m++)
                    {
                        if (words[n] == most_5[m])   // делаем буквы заглавными
                            words[n] -= 32;
                    }
                }
            }

            for (int n = start; n < finish; n++)  // проходимся по слову
            {
                file_out << words[n];
            }
            
            if (counter >= 4) {
                file_out << '(';
                for (int m = 0; m < 5; m++)
                {
                    if (most_5_count[m] != 0)
                    {
                        file_out << most_5[m] << ' ';
                    }
                }
                file_out << ')';
            }
            file_out << words[finish];  //символ, следующий после слова


            i = finish;  // чтобы сразу идти по следующему слову
            start = -1;
            finish = -1;
            counter = 0;
            for (int m = 0; m < 5; m++)
            {
                most_5_count[m] = 0;
            }
        }
        i++;
    }
    
    for (int i = 0; i < 5; i++)
        std::cout << most_5[i] << std::endl;

    for (int i = 0; i < k; i++)
        std::cout << words[i];

}
