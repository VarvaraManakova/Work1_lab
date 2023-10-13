#include <iostream>
#include <fstream>
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

    string choice; // переменная для выбора

    // попытка ввести пользователем выбор
    try
    {
        cin >> choice; // ввод
        for (int i = 0; i < choice.length(); i++)
        {
            if ((choice[i] >= 'A' and choice[i] <= 'Z') or(choice[i] >= 'a' and choice[i] <= 'a'))
            {
                throw "Error";
            }
        }
        if (stoi(choice) < 0 or stoi(choice) > 3) throw "Error";
    }
    catch(const std::exception& e) // если ввел другие символы
    {
        cout << "Ввод некорректный - есть лишние символы" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Выбор неверный" << endl;
        exit(1);
    }

    // если выбрал список
    if (choice == "1")
    {
        BaseQueue *ptr_list = new List(); // создаем новый объект

        cout << "Введите кол-во элементов, которые вы хотите ввести: ";
        string count; // число элементов для ввода

        try
        {
            cin >> count; // ввод
            for (int i = 0; i < count.length(); i++)
            {
                if ((count[i] >= 'A' and count[i] <= 'Z') or(count[i] >= 'a' and count[i] <= 'a'))
                {
                    throw "Error";
                }
            }
            if (stoi(count) < 0) throw "Error";
        }
        catch(const std::exception& e) // если ввел другие символы
        {
            cout << "Ввод некорректный - есть лишние символы" << endl;
            exit(1);
        }
        catch(const char*mssg)
        {
            cout << "Кол-во не может быть отрицательным" << endl;
            exit(1);
        }

        // вод count элементов
        for (int i = 0; i < stoi(count); i++)
        {
            ptr_list->Set();
        }

        array[countElement++] = ptr_list; // добавление в массив
    }

    // если выбрал деку
    else if (choice == "2")
    {
        BaseQueue *ptr_deque = new Deque(); // создаем новый объект

        cout << "Введите кол-во элементов, которые вы хотите ввести: ";
        string count; // число элементов для ввода

        try
        {
            cin >> count; // ввод
            for (int i = 0; i < count.length(); i++)
            {
                if ((count[i] >= 'A' and count[i] <= 'Z') or(count[i] >= 'a' and count[i] <= 'a'))
                {
                    throw "Error";
                }
            }
            if (stoi(count) < 0) throw "Error";
        }
        catch(const std::exception& e) // если ввел другие символы
        {
            cout << "Ввод некорректный - есть лишние символы" << endl;
            exit(1);
        }
        catch(const char*mssg)
        {
            cout << "Кол-во не может быть отрицательным" << endl;
            exit(1);
        }

        // вод count элементов
        for (int i = 0; i < stoi(count); i++)
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
        string count; // число элементов для ввода

        try
        {
            cin >> count; // ввод
            for (int i = 0; i < count.length(); i++)
            {
                if ((count[i] >= 'A' and count[i] <= 'Z') or(count[i] >= 'a' and count[i] <= 'a'))
                {
                    throw "Error";
                }
            }
            if (stoi(count) < 0) throw "Error";
        }
        catch(const std::exception& e) // если ввел другие символы
        {
            cout << "Ввод некорректный - есть лишние символы" << endl;
            exit(1);
        }
        catch(const char*mssg)
        {
            cout << "Кол-во не может быть отрицательным" << endl;
            exit(1);
        }

        // вод count элементов
        for (int i = 0; i < stoi(count); i++)
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
    cout << "Введите номер, который вы хотите удалить: ";
    string id; // переменная для номер

    // попытка ввести пользователем выбор
    try
    {
        cin >> id; // ввод
        for (int i = 0; i < id.length(); i++)
        {
            if ((id[i] >= 'A' and id[i] <= 'Z') or(id[i] >= 'a' and id[i] <= 'a'))
            {
                throw "Error";
            }
        }
        if (stoi(id) < 0 or stoi(id) > countElement - 1) throw "Error";
    }
    catch(const std::exception& e) // если ввел другие символы
    {
        cout << "Ввод некорректный - есть лишние символы" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Выбор неверный" << endl;
        exit(1);
    }

    *this-= stoi(id);
}

// перегрузка оператора -=
Keeper & Keeper::operator-=(int element)
{
    // сдвигаем все элементы
    for (int count = element; count < countElement-1; count++)
    {
        int buf_count = count + 1;
        array[count] = array[buf_count];
    }
    this->countElement--;
    return *this;
}

// удаление значения из типов данных
void Keeper::PopElement()
{
    cout << "Введите номер, из которого вы хотите удалить: ";
    string id; // переменная для номер

    // попытка ввести пользователем выбор
    try
    {
        cin >> id; // ввод
        for (int i = 0; i < id.length(); i++)
        {
            if ((id[i] >= 'A' and id[i] <= 'Z') or(id[i] >= 'a' and id[i] <= 'a'))
            {
                throw "Error";
            }
        }
        if (stoi(id) < 0 or stoi(id) > countElement - 1) throw "Error";
    }
    catch(const std::exception& e) // если ввел другие символы
    {
        cout << "Ввод некорректный - есть лишние символы" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Выбор неверный" << endl;
        exit(1);
    }

    array[stoi(id)]->Pop();
}

// метод редактиврования данных
void Keeper::Change()
{
    cout << "Введите номер элемента, в который вы хотите добавить элементы: ";
    string id; // переменная для номер

    // попытка ввести пользователем выбор
    try
    {
        cin >> id; // ввод
        for (int i = 0; i < id.length(); i++)
        {
            if ((id[i] >= 'A' and id[i] <= 'Z') or (id[i] >= 'a' and id[i] <= 'a'))
            {
                throw "Error";
            }
        }
        if (stoi(id) < 0 or stoi(id) > countElement - 1) throw "Error";
    }
    catch(const std::exception& e) // если ввел другие символы
    {
        cout << "Ввод некорректный - есть лишние символы" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Выбор неверный" << endl;
        exit(1);
    }

    cout << "Введите кол-во элементов, которые вы хотите ввести: ";
    string count; // число элементов для ввода

    try
    {
        cin >> count; // ввод
        for (int i = 0; i < id.length(); i++)
        {
            if ((id[i] >= 'A' and id[i] <= 'Z') or(id[i] >= 'a' and id[i] <= 'a'))
            {
                throw "Error";
            }
        }
        if (stoi(id) < 0) throw "Error";
    }
    catch(const std::exception& e) // если ввел другие символы
    {
        cout << "Ввод некорректный - есть лишние символы" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Кол-во не может быть отрицательным" << endl;
        exit(1);
    }

    // вод count элементов
    for (int i = 0; i < stoi(count); i++)
    {
        array[stoi(id)]->Set();
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
    // очищаем файлы
    ofstream loadS;
    loadS.open("stack.txt");

    ofstream loadD;
    loadD.open("deque.txt");

    ofstream loadL;
    loadL.open("list.txt");

    loadL << "";
    loadD << "";
    loadS << "";

    loadL.close();
    loadD.close();
    loadS.close();

    cout << "\nSAVE" << endl;

    for (int i = 0; i < countElement; i++)
    {
        array[i]->GetType();
    }
}

// метод загрузки из файла
void Keeper::Load()
{
    cout << "\nLOAD" << endl;

    ifstream loadL;
    ifstream loadD;
    ifstream loadS;
    loadL.open("list.txt");
    loadD.open("deque.txt");
    loadS.open("stack.txt");
    if (loadL.is_open() and loadD.is_open() and loadS.is_open())
    {
        string line; // строка, в которую будем считывать
        BaseQueue *ptr_list = new List(); // создаем новый объект
        BaseQueue *ptr_deque = new Deque(); // создаем новый объект
        BaseQueue *ptr_stack = new Stack(); // создаем новый объект

        while (getline(loadL, line)) ptr_list->SetL(stof(line));

        while (getline(loadD, line)) ptr_deque->SetL(stof(line));

        while (getline(loadS, line)) ptr_stack->SetL(stof(line));

        array[countElement++] = ptr_list; // добавление в массив
        array[countElement++] = ptr_deque; // добавление в массив
        array[countElement++] = ptr_stack; // добавление в массив
    }

    cout << "\nLOAD END" << endl;
    loadL.close();
    loadD.close();
    loadS.close();
}
