

#include <iostream>
#include <vector>

int main()
{    
    std::vector <int>vector1 = { 1, 2, 3, 4, 5 };

    std::cout << vector1.size() << std::endl; // 1 2 3 4 5
    vector1.resize(3);
    std::cout << vector1.size() << std::endl;  // 1 2 3

    vector1.push_back(6);  // 1 2 3 6
    vector1.pop_back();  // 1 2 3

    std::cout << vector1.size() << "   " << vector1.capacity() << std::endl;  // капасити - это резерв памяти
    vector1.push_back(8);  // 1 2 3 8
    std::cout << vector1.size() << "   " << vector1.capacity() << std::endl;  // а сайз это размер вектора
    // вывод капасити = 6, тк изначально было 3 элемента

    vector1.reserve(4);  // делает резерв 4 вместо 6
    std::cout << vector1.capacity();

    std::cout << vector1.capacity();
    vector1.clear();  // полностью очищает вектор

    std::cout << vector1.capacity();
    vector1.shrink_to_fit();

    std::cout << vector1.capacity();

    for (int i = 1; i <= 10; i++)   // забиваем значения от 1 до 10
        vector1.push_back(i);
    for (size_t i = 0; vector1.size(); i++)  // вывод
        std::cout << vector1[i] << ' ';
    std::cout << std::endl;

    vector1.erase(vector1.begin(), vector1.begin() + 3);  // удалить первые три элемента
    for (size_t i = 0; vector1.size(); i++)  // вывод
        std::cout << vector1[i] << ' ';
    std::cout << std::endl;

    std::vector <int>::iterator it;
    it = vector1.begin();

    for (size_t i = 0; vector1.size(); i++)
        std::cout << vector1[i] << ' ';
    std::cout << std::endl;

    vector1.insert(it, 4);  // первый элемент будет 4, все остальные сдвигаются

    for (size_t i = 0; vector1.size(); i++)
        std::cout << vector1[i] << ' ';
    std::cout << std::endl;

    std::cout << vector1[45] << std::endl; // напечатается что-то непонятное, тк 45го элемента нет
    std::cout << vector1.at(0) << ' ';
    std::cout << vector1.at(45);  // произойдет ошибка

}
