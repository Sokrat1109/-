
#include <iostream>

int main()

{
    const int N_Max = 20000;
    int mas[N_Max];

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }

    for (int i = 0; i < n; i++)
    {
        bool flag7 = false;
        bool flag6 = false;

        int num = mas[i];

        while (num > 0)  // проверяем на наличие 6 и 7
        {
            int kek = num % 10;
            if (kek == 7)
            {
                flag7 = true;
            }
            if (kek == 6)
            {
                flag6 = true;
            }
            num /= 10;
        }

        if (flag7 == true && flag6 == false)   // исключаем если есть 7 и нет 6
        {
            for (int j = i; j < n; j++)           
            {
                mas[j] = mas[j + 1];                
            }
            n--;
            i--;
        }

    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        int num = mas[i];


        if (num != 1) {
            for (int j = 2; j < sqrt(num) + 1; j++)  // поиск простых чисел
            {
                if (num % j == 0)
                {
                    flag = false;
                }
            }
            if (flag == true)   // дублирование
            {
                n++;
                for (int k = n; k > i; k--)
                {
                    mas[k] = mas[k - 1];
                }
                i++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << mas[i] << " ";
}
