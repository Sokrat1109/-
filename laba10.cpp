#include <iostream>
#include <vector>

int main()
{    
    std::vector <int>vector1 = { 1, 2, 3, 4, 5 };

    std::cout << vector1.size() << std::endl; // 1 2 3 4 5    //вывод   5
    vector1.resize(3);
    std::cout << vector1.size() << std::endl;  // 1 2 3     // вывод   3

    vector1.push_back(6);  // 1 2 3 6
    std::cout << vector1.size() << std::endl;   // вывод 4

    vector1.pop_back();  // 1 2 3
    std::cout << vector1.size() << std::endl;  // вывод 3

    vector1.shrink_to_fit();  // подгоняем размер памяти под размер массива, удаляя пустые резервные ячейки

    std::cout << vector1.size() << "   " << vector1.capacity() << std::endl;  // капасити - это резерв памяти    // вывод 3  3
    vector1.push_back(8);  // 1 2 3 8
    std::cout << vector1.size() << "   " << vector1.capacity() << std::endl;  // а сайз это размер вектора    // вывод  3  6
    // тут почему-то выводит 4  4, хотя предыдущее значение капасити 3, и он должен увеличивается *2 от этого значения, если я превышаю его

    vector1.reserve(8);  // делает резерв 8 вместо 6       // тут почему-то выводит 8881
    std::cout << vector1.capacity();

    vector1.clear();  // полностью очищает вектор
    std::cout << vector1.capacity();

    for (int i = 1; i <= 10; i++)   // забиваем значения от 1 до 10
        vector1.push_back(i);
    for (size_t i = 0; i<vector1.size(); i++)  // вывод
        std::cout << vector1[i] << ' ';
    std::cout << std::endl;

    vector1.erase(vector1.begin(), vector1.begin() + 3);  // удалить первые три элемента
    for (size_t i = 0; i < vector1.size(); i++)  // вывод
        std::cout << vector1[i] << ' ';
    std::cout << std::endl;

    std::vector <int>::iterator it;
    it = vector1.begin();

    for (size_t i = 0; i < vector1.size(); i++)  // вывод
        std::cout << vector1[i] << ' ';
    std::cout << std::endl;

    vector1.insert(it, 4);  // первый элемент будет 4, все остальные сдвигаются

    for (size_t i = 0; i < vector1.size(); i++)  // вывод
        std::cout << vector1[i] << ' ';
    std::cout << std::endl;

    // std::cout << vector1[45] << std::endl; // напечатается что-то непонятное, тк 45го элемента нет
    std::cout << vector1.at(0) << ' ';
    // std::cout << vector1.at(45);  // произойдет ошибка

}
