#ifndef BASE_H
#define BASE_H

#include <string>
using namespace std;

// ОСНОВНОЙ КЛАСС
class BaseQueue
{
private:
    BaseQueue *next;
    BaseQueue *previous;
    BaseQueue *head;

public:
// создание конструкторов и деструктора
    BaseQueue(); // конструктор по умолчанию
    BaseQueue(BaseQueue *ptr); // конструктор с параметром
    BaseQueue(const BaseQueue &B); // конструктор копирования
    ~BaseQueue(); // деструктор

// основные методы
    void Set(int number); // добавить элемент
    void Get(); // получить элемент
    void Delete(int choice); // удалить элемент
    void Change(int choice); // изменить данные

};

class List:public BaseQueue
{
private:
    List *next; // следущий элемент
    List *previous; // предыдущий элемент
    List *head; // текущий элемент
    float number; // число

public:
// создание конструкторов и деструктора
    List(); // конструктор по умолчанию
    List(float number); // конструктор с параметром
    List(const List &L); // конструктор копирования
    ~List(); // деструктор

// основные методы
    void Set(float number); // добавить число
    void Get(); // получить число
    void Pop(); // удалить число
    int Size(); // узнать размер
};

class SoundBoard:public BaseQueue
{
private:
    SoundBoard *next; // следущий элемент
    SoundBoard *previous; // предыдущий элемент
    SoundBoard *head; // текущий элемент
    SoundBoard *back_head; // конечный элемент
    float number; // число

public:
// создание конструкторов и деструктора
    SoundBoard(); // конструктор по умолчанию
    SoundBoard(float number); // конструктор с параметром
    SoundBoard(const SoundBoard &S); // конструктор копирования
    ~SoundBoard(); // деструктор

// основные методы
    void SetHead(float number); // добавить число в начало
    void SetBack(float number); // добавить число в конец
    void Get(); // получить число
    void PopHead(); // удалить число с начала
    void PopBack(); // удалить число с конца
    int Size(); // узнать размер
};

class Stack:public BaseQueue
{
    private:
    SoundBoard *previous; // предыдущий элемент
    SoundBoard *head; // текущий элемент
    float number; // число

public:
// создание конструкторов и деструктора
    Stack(); // конструктор по умолчанию
    Stack(float number); // конструктор с параметром
    Stack(const Stack &S); // конструктор копирования
    ~Stack(); // деструктор

// основные методы
    void Set(float number); // добавить число
    void Get(); // получить число
    void Pop(); // удалить число
    int Size(); // узнать размер
};

#endif
