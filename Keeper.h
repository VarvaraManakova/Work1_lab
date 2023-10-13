#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"

class Keeper
{
private:
    BaseQueue **array; // массив для хранения объектов
    int size; // размер массива
    int countElement; // кол-во элементов в массиве

public:
// создание конструкторов и деструктора
    Keeper(); // конструктор без параметра
    Keeper(int size); // конструктор с параметром
    Keeper(const Keeper &K); // конструктор копирования
    ~Keeper(); // деструктор

// основные методы
    void Set(); // добавить элемент
    void Get(); // получить элемент
    void Pop(); // удалить элемент
    Keeper&operator-=(int element); // перегрузка оператора -=
    void PopElement(); // удаление значения из типов данных
    void Change(); // изменить данные
    void isEmpty(); // узнать данные
    void Save(); // сохранить данные в файл
    void Load(); // загрузить данные из файла
};

#endif
