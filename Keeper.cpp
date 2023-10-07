#include <iostream>
#include "Keeper.h"
#include "Base.h"

// конструктор без параметра
Keeper::Keeper()
{
    this->array = new BaseQueue*[1]; // создаем массив на 1 элемент
    this->size = 1; // размер = 1
    this->countElement = 0; // кол-во элементов

    cout << "Вызван конструктор класса: Keeper" << endl;
}

// конструктор с параметром
Keeper::Keeper(int size)
{
    this->array = new BaseQueue*[size]; // создаем массив на size элементов
    this->size = size; // размер = size
    this->countElement = 0; // кол-во = 0

    cout << "Вызван конструктор с параметром класса: Keeper" << endl;
}

// конструктор копирования
Keeper::Keeper(const Keeper &K)
{
    this->size = K.size; // приравниваем значения размера массива
    this->countElement = K.countElement; // приравниваем кол-во элементов
    this->array = new BaseQueue*[this->size]; // выделяем память под size элементов

    // перебираем все элементы массива
    for (int count = 0; count < this->countElement; count++)
    {
        this->array[count] = K.array[count]; // копируем объекты
    }

    cout << "Вызван конструктор копирования класса: Keeper" << endl;
}

// деструктор
Keeper::~Keeper()
{
    // перебираем все элементы
    for (int count = 0; count < countElement; count++)
    {
        delete [] this->array[count]; // удаляем элементы
    }

    delete [] array; // высвобождаем память из под массива
}

// метод для добавления элементов
void Keeper::Set()
{
    cout << "Выберете, что вы хотите добавить:" << endl;
    cout << "---------------------------------\n"
         << "|        1 - Список             |\n"
         << "|        2 - Дека               |\n"
         << "|        3 - Стек               |\n"
         << "---------------------------------" << endl;

    int choice; // переменная для выбора

    // попытка ввести пользователем выбор
    try
    {
        cin >> choice; // ввод
        if (choice > 3 or choice < 1) throw "Error"; // если пользователь ввел не то число бросаем ошибку
    }
    catch(const std::exception& e) // если ввел другие символы
    {
        cout << "Ввод некорректный - есть лишние символы" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Выбор неверный" << endl;
    }

    // если выбрал список
    if (choice == 1)
    {
        BaseQueue *ptr_list = new List(); // создаем новый объект

        cout << "Введите кол-во элементов, которые вы хотите ввести: ";
        int count; // число элементов для ввода

        try
        {
            cin >> count; // ввод
            if (count < 0) throw "Error";
        }
        catch(const std::exception& e) // если ввел другие символы
        {
            cout << "Ввод некорректный - есть лишние символы" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Кол-во не может быть отрицательным" << endl;
        }

        // вод count элементов
        for (int i = 0; i < count; i++)
        {
            ptr_list->Set();
        }

        array[countElement++] = ptr_list; // добавление в массив
    }

    // если выбрал деку
    else if (choice == 2)
    {
        BaseQueue *ptr_deque = new Deque(); // создаем новый объект

        cout << "Введите кол-во элементов, которые вы хотите ввести: ";
        int count; // число элементов для ввода

        try
        {
            cin >> count; // ввод
            if (count < 0) throw "Error";
        }
        catch(const std::exception& e) // если ввел другие символы
        {
            cout << "Ввод некорректный - есть лишние символы" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Кол-во не может быть отрицательным" << endl;
        }

        // вод count элементов
        for (int i = 0; i < count; i++)
        {
            ptr_deque->Set();
        }

        array[countElement++] = ptr_deque; // добавление в массив
    }

    // если выбрал стек
    else
    {
        BaseQueue *ptr_stack = new Stack(); // создаем новый объект

        cout << "Введите кол-во элементов, которые вы хотите ввести: ";
        int count; // число элементов для ввода

        try
        {
            cin >> count; // ввод
            if (count < 0) throw "Error";
        }
        catch(const std::exception& e) // если ввел другие символы
        {
            cout << "Ввод некорректный - есть лишние символы" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Кол-во не может быть отрицательным" << endl;
        }

        // вод count элементов
        for (int i = 0; i < count; i++)
        {
            ptr_stack->Set();
        }

        array[countElement++] = ptr_stack; // добавление в массив
    }
}

// метод вывода элементов
void Keeper::Get()
{
    // вывод каждого элемента
    for (int i = 0; i < countElement; i++)
    {
        array[i]->Get();
    }
}

// метод удаления данных
void Keeper::Pop()
{
    cout << "Введите номер элемента, который вы хотите удалить: ";
    int id; // переменная для номер

    // попытка ввести пользователем выбор
    try
    {
        cin >> id; // ввод
        if (id < 0 or id > countElement) throw "Error"; // если пользователь ввел не то число бросаем ошибку
    }
    catch(const std::exception& e) // если ввел другие символы
    {
        cout << "Ввод некорректный - есть лишние символы" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Выбор неверный" << endl;
    }

    array[id]->Pop();
}

// метод редактиврования данных
void Keeper::Change()
{
    cout << "Введите номер элемента, в который вы хотите добавить элементы: ";
    int id; // переменная для номер

    // попытка ввести пользователем выбор
    try
    {
        cin >> id; // ввод
        if (id < 0 or id > countElement) throw "Error"; // если пользователь ввел не то число бросаем ошибку
    }
    catch(const std::exception& e) // если ввел другие символы
    {
        cout << "Ввод некорректный - есть лишние символы" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Выбор неверный" << endl;
    }

    cout << "Введите кол-во элементов, которые вы хотите ввести: ";
    int count; // число элементов для ввода

    try
    {
        cin >> count; // ввод
        if (count < 0) throw "Error";
    }
    catch(const std::exception& e) // если ввел другие символы
    {
        cout << "Ввод некорректный - есть лишние символы" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Кол-во не может быть отрицательным" << endl;
    }

    // вод count элементов
    for (int i = 0; i < count; i++)
    {
        array[id]->Set();
    }
}

// метод проверки на пустоту
void Keeper::isEmpty()
{
    for (int i = 0; i < countElement; i++)
    {
        array[i]->isEmpty();
    }
}

// метод сохранения в файл
void Keeper::Save()
{
    cout << "SAVE" << endl;
}

// метод загрузки из файла
void Keeper::Load()
{
    cout << "LOAD" << endl;
}
