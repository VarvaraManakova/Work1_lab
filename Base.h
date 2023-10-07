#ifndef BASE_H
#define BASE_H

#include <string>
using namespace std;

// ОСНОВНОЙ КЛАСС
class BaseQueue
{
public:
// // создание конструкторов и деструктора
//     BaseQueue(); // конструктор по умолчанию
//     BaseQueue(BaseQueue *ptr); // конструктор с параметром
//     BaseQueue(const BaseQueue &B); // конструктор копирования
//     ~BaseQueue(); // деструктор

// основные методы
    virtual void Set() = 0; // добавить элемент
    virtual void Get() = 0; // получить элемент
    virtual void Pop() = 0; // удалить элемент
    virtual void isEmpty() = 0; // проверить на пустоту

};

class NodeList; // узел для листа

class List:public BaseQueue
{
private:
    NodeList *head; // указатель на начало списка
    NodeList *tail; // указатель, чтобы бегать по списку

public:
// создание конструкторов и деструктора
    List(); // конструктор по умолчанию
    List(float number); // конструктор с параметром
    List(const List &L); // конструктор копирования
    ~List(); // деструктор

// основные методы
    void Set() override; // добавить число
    void Get() override; // получить список
    void Pop() override; // удалить число
    void isEmpty() override; // узнать размер
};

class NodeList:public List
{
public:
    float number; // число
    NodeList *next; // указатель на следующий объект

    NodeList(float number); // конструктор с параметром
};

class NodeDeque; // узел для деки

class Deque:public BaseQueue
{
private:
    NodeDeque *head; // указатель на голову
    NodeDeque *Ltail; // указатель на начало
    NodeDeque *Rtail; // указатель на конец

public:
// создание конструкторов и деструктора
    Deque(); // конструктор по умолчанию
    Deque(float number); // конструктор с параметром
    Deque(const Deque &D); // конструктор копирования
    ~Deque(); // деструктор

// основные методы
    void Set() override; // добавить число
    void Get() override; // получить деку
    void Pop() override; // удалить число
    void isEmpty() override; // узнать размер
};

class NodeDeque:public Deque
{
public:
    NodeDeque *previous; // указатель на предыдущий элемент
    float number; // переменная для хранения числа

    NodeDeque(float number);
};

class NodeStack; // класс узла Stack

class Stack:public BaseQueue
{
private:
    NodeStack *head; // указатель на начало стека
    NodeStack *tail; // указатель на конец стека
    int count_elements;

public:
// создание конструкторов и деструктора
    Stack(); // конструктор по умолчанию
    Stack(float number); // конструктор с параметром
    Stack(const Stack &S); // конструктор копирования
    ~Stack(); // деструктор

// основные методы
    void Set() override; // добавить число
    void Get() override; // получить стек
    void Pop() override; // удалить число
    void isEmpty() override; // узнать размер
};

class NodeStack:public Stack
{
public:
    NodeStack *previous; // указатель на предыдущий элемент стека
    float number; // значение числа

    NodeStack(float number); // конструктор с параметром
};

#endif
