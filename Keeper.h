#ifndef KEEPER_H
#define KEEPER_H

class Keeper
{
private:
    Keeper *array;

public:
// создание конструкторов и деструктора
    Keeper();
    Keeper(int size);
    Keeper(const Keeper &K);
    ~Keeper();

// основные методы
    void Set(); // добавить элемент
    void Get(); // получить элемент
    void Delete(); // удалить элемент
    void Save(); // сохранить данные в файл
    void Load(); // загрузить данные из файла
};

#endif
