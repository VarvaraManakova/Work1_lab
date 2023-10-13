#include <iostream>
#include <fstream>
#include <string>
#include "Base.h"

using namespace std;

// Класс NodeList
// конструктор класса NodeList
NodeList::NodeList(float number)
{
    this->number = number; // устанавливаем значение
    this->next = nullptr; // устанавливаем указатель в nullptr

    cout << "Вызван конструктор класс: Node" << endl;
}

// Класс List
// конструктор без параметра класса List
List::List()
{
    this->head = nullptr; // устанавливаем указатель в пустоту, так как нет значения
    this->tail = nullptr; // устанавливаем указатель в пустоту, так как нет значения
    this->countEl = 0;

    cout << "Вызван конструктор без параметра класса: List" << endl;
}

// конструктор с параметром
List::List(float number)
{
    NodeList *node = new NodeList(number); // создаем указатель на узел

    this->head = node; // устанавливаем указатель начала списка на созданный узел
    this->tail = node; // указатель на конец списка
    this->tail->next = nullptr; // следующий элемент
    this->countEl = 1;

    cout << "Вызван конструктор с параметром класса: List" << endl;
}

// конструктор копирования
List::List(const List &L)
{
    NodeList *buf_head = L.head; // создем буферный указатель, чтобы проходить по элементам

    this->head = nullptr; // устанвливаем указатели в nullptr
    this->tail = nullptr; // устанвливаем указатели в nullptr
    this->countEl = L.countEl;

    // проходимся по всем элементам
    while (buf_head != nullptr)
    {
        NodeList *node = new NodeList(buf_head->number); // создаем новый элемент

        if (tail != nullptr) // если уже есть хотя бы 1 элемент
        {
            this->tail->next = node; // текущий указатель на следующий элемент указывает на новый элемент
        }

        if (this->head == nullptr) // если нет элементов
        {
            head = node; // указатель указывает на текущий узел
        }

        this->tail = node; // устанавливаем указатель на конец на текущий узел

        buf_head = buf_head->next; // двигаемся дальше
    }

    cout << "Вызван конструктор копирования класса: List" << endl;
}

// деструктор
List::~List()
{
    NodeList *buf_head = head; // создаем буферный указатель, чтобы удалить данные

    // удаляем все элементы
    while (this->head != nullptr)
    {
        head = head->next; // двигаем головной указатель на следующий элемент
        delete buf_head; // удаляем предыдущий элемент
        buf_head = head;
    }

    cout << "Вызван деструктор класса: List" << endl;
}

// метод добавления
void List::Set()
{
    cout << "Введите число: ";
    string num; // переменная для ввода числа

    // проверка на ввод числа
    try
    {
        cin >> num; // ввод числа
        for (int i = 0; i < num.length(); i++)
        {
            if ((num[i] >= 'A' and num[i] <= 'Z') or(num[i] >= 'a' and num[i] <= 'a'))
            {
                throw "Error";
            }
        }
    }
    catch(const std::exception& e) // если число некорректно
    {
        cout << "Число некорректно" << endl;
        exit(1);
    }
    catch(const char*mssg) // если число некорректно
    {
        cout << "Число некорректно" << endl;
        exit(1);
    }

    NodeList *node = new NodeList(stof(num)); // создаем новый узел со значением

    // если элемент есть в списке
   if (this->tail != nullptr)
    {
        this->tail->next = node; // устанавливаем указатель на следующий элемент на созданный узел
    }

    // если элементов нет в списке
    if (this->head == nullptr)
    {
        this->head = node; // указатель на начало устанавливаем на текущую node
    }

    this->tail = node; // двигаем указатель на конец на новый добавленный элемент
    this->countEl++;
}

// метод вывода на экран
void List::Get()
{
    NodeList *buf_head = this->head; // устанавливаем буферный указатель на начало списка

    cout << "\nЭлементы списка:" << endl;

    while (buf_head != nullptr) // пока не конец списка
    {
        cout << buf_head->number << endl; // выводим элемент
        buf_head = buf_head->next; // двигаемся дальше
    }
}

// метод удаления
void List::Pop()
{
    if (countEl == 0)
    {
        cout << "\n СПИСОК ПУСТ" << endl;
    }

    else
    {
        NodeList *buf_head = head;
        head = buf_head->next;
        delete buf_head;
        countEl--;
    }
}

// проверка на пустоту списка
void List::isEmpty()
{
    if (this->head == nullptr)
    {
        cout << "Список пустой" << endl;
    }

    else
    {
        cout << "В списке есть элементы в кол-ве: " << countEl << endl;
    }
}

//  Класс NodeDeque
// конструктор класса NodeDeque
NodeDeque::NodeDeque(float number)
{
    this->number = number;
    this->previous = nullptr;

    cout << "Вызван конструктор класса: NodeDeque" << endl;
}

// Класс Deque
// конструктор без параметра
Deque::Deque()
{
    this->head = nullptr; // устанавливаем указатель в пустоту, так как нет значения
    this->Ltail = nullptr; // устанавливаем указатель в пустоту, так как нет значения
    this->Rtail = nullptr; // устанавливаем указатель в пустоту, так как нет значения
    this->countEl = 0;

    cout << "Вызван конструктор без параметра класса: Deque" << endl;
}

// конструктор с параметром
Deque::Deque(float number)
{
    NodeDeque *node = new NodeDeque(number); // создаем указатель на узел

    this->head = node; // устанавливаем указатель начала деки на созданный узел
    this->Ltail = node; // указатель на неачало деки
    this->Rtail = node; // указатель на конец деки
    this->countEl = 1;

    cout << "Вызван конструктор с параметром класса: Deque" << endl;
}

// конструктор копирования
Deque::Deque(const Deque &D)
{
    NodeDeque *buf_head = D.head; // создем буферный указатель, чтобы проходить по элементам

    this->head = nullptr; // устанвливаем указатели в nullptr
    this->Ltail = nullptr; // устанвливаем указатели в nullptr
    this->Rtail = nullptr; // устанвливаем указатели в nullptr
    this->countEl = D.countEl;

    // проходимся по всем элементам
    while (buf_head != nullptr)
    {
        NodeDeque *node = new NodeDeque(buf_head->number); // создаем новый элемент

        if (Rtail != nullptr) // если уже есть хотя бы 1 элемент
        {
            this->Rtail->previous = node; // текущий указатель на следующий элемент указывает на новый элемент
        }

        if (this->head == nullptr) // если нет элементов
        {
            this->head = node; // указатель указывает на текущий узел
        }

        this->Rtail = node; // устанавливаем указатель на конец на текущий узел

        buf_head = buf_head->previous; // двигаемся дальше
    }

    cout << "Вызван конструктор копирования класса: Deque" << endl;
}

// деструктор
Deque::~Deque()
{
    // удаляем все элементы
    while (this->head != nullptr)
    {
        NodeDeque*buf_head = head; // создаем буферный указатель, чтобы удалить данные
        head = head->previous; // двигаем головной указатель на следующий элемент
        delete buf_head; // удаляем предыдущий элемент
    }

    cout << "Вызван деструктор класса: Deque" << endl;
}

// метод добавления элементов
void Deque::Set()
{
    cout << "Введите число: ";
    string num; // переменная для ввода числа

    // проверка на ввод числа
    try
    {
        cin >> num; // ввод числа
        for (int i = 0; i < num.length(); i++)
        {
            if ((num[i] >= 'A' and num[i] <= 'Z') or(num[i] >= 'a' and num[i] <= 'a'))
            {
                throw "Error";
            }
        }
    }
    catch(const std::exception& e) // если число некорректно
    {
        cout << "Число некорректно" << endl;
        exit(1);
    }
    catch(const char**mssg) // если число некорректно
    {
        cout << "Число некорректно" << endl;
        exit(1);
    }

    cout << "Куда добавить элемент?" << endl;
    cout << "Введите + если в начало \n"
        << "Введите - если в конец" << endl;

    string symbol; // переменная для ввода выбора
    try
    {
        cin >> symbol; // ввод
        if (symbol != "+" and symbol != "-") throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Ошибка ввода" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Выбор не верный" << endl;
        exit(1);
    }

    // добавление в конец деки
    if (symbol == "-")
    {
        NodeDeque *node = new NodeDeque(stof(num)); // создаем новый узел со значением

        // если элемент есть в списке
        if (this->Rtail != nullptr)
            {
                this->Rtail->previous = node; // устанавливаем указатель на следующий элемент на созданный узел
            }

        // если элементов нет в списке
        if (this->head == nullptr)
        {
            this->head = node; // указатель на начало устанавливаем на текущую node
        }

        this->Rtail = node; // двигаем указатель на конец на новый добавленный элемент
    }

    // если добавление в начало
    else
    {
        NodeDeque *node = new NodeDeque(stof(num)); // создаем новый узел со значением

        // если указатель на начало указывает на элемент
        if (Ltail != nullptr)
        {
            this->Ltail = node; // указатель на начало устанавливаем на новый элемент
            this->Ltail->previous = head; // новый начальный элемент будет указывать на прошлый начальный
        }

        // если еще нет элементов
        if (head == nullptr)
        {
            this->Rtail = node; // указатель на конец на новый элемент
            this->Ltail = node; // указатель на начало на новый элемент
        }

        this->head = node; // сдвигаем голову на новый начальный элемент
    }
    this->countEl++;
}

// метод вывода деки
void Deque::Get()
{
    NodeDeque *buf_head = this->head; // устанавливаем буферный указатель на начало списка

    cout << "\nЭлементы деки:" << endl;

    while (buf_head != nullptr) // пока не конец списка
    {
        cout << buf_head->number << endl; // выводим элемент
        buf_head = buf_head->previous; // двигаемся дальше
    }
}

// удаление элементов
void Deque::Pop()
{
    cout << "Откуда удалить элемент?" << endl;
    cout << "Введите + если из начала \n"
        << "Введите - если из конца" << endl;

    string symbol; // переменная для ввода выбора
    try
    {
        cin >> symbol; // ввод
        if (symbol != "+" and symbol != "-") throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Ошибка ввода" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Выбор не верный" << endl;
        exit(1);
    }

    // если из начала
    if (symbol == "+")
    {
        NodeDeque *buf_head = head; // создаем буферный указатель на начало

        head = buf_head->previous; // перемещаем на следущий элемент указатель на голову
        Ltail = buf_head->previous; // перемещаем на следующий элемент указатель на начало

        delete buf_head; // удаляем
    }

    // если из конца
    else
    {
        if (Rtail == nullptr)  cout << "\nДека пуста" << endl; // если нет элементов
        else
        {
            NodeDeque *buf_tail = head; // создаем буферный указатель начала

            while (buf_tail != Rtail) // идем до конца - 1
            {
                if (buf_tail->previous != Rtail) buf_tail = buf_tail->previous; // находим предпоследний элемент
                else break;
            }

            NodeDeque *buf_delete = Rtail; // создаем буфер на конец
            Rtail = buf_tail; // перемещаем указатель назад
            Rtail->previous = nullptr; // устанавливаем указатель на след в nullptr
            delete buf_delete; // удаляем старый элемент
        }
    }
    this->countEl--;
}

// проверка на пустоту списка
void Deque::isEmpty()
{
    if (this->head == nullptr)
    {
        cout << "Дека пустая" << endl;
    }

    else
    {
        cout << "В деке есть элементы в кол-ве: " << this->countEl << endl;
    }
}

// Класс NodeStack
// конструктор
NodeStack::NodeStack(float number)
{
    this->previous = nullptr; // указатель на предыдущий элемент в nullptr
    this->number = number; // присваиваем значение

    cout << "Вызван конструктор класса: NodeStack" << endl;
}

// Класс Stack
// конструктор по умолчанию
Stack::Stack()
{
    this->head = nullptr; // указатель на начало в nullptr
    this->tail = nullptr; // указатель на конец в nullptr
    this-> count_elements = 0; // кол-во элементов

    cout << "Вызван конструктор по умолчанию класса: Stack" << endl;
}

// конструктор с параметром
Stack::Stack(float number)
{
    NodeStack *node = new NodeStack(number); // создаем элемент
    NodeStack *buf_head = this->head; // создаем буфер на начало
    this-> count_elements = 1; // кол-во элементов

    // если уже есть элементы
    if (head != nullptr)
    {
        this->head = node; // двигаем начало на новый элемент
        this->head->previous = buf_head; // указатель нового элемента указывает на предыдущий
    }

    // если элементов нет
    else
    {
        this->head = node; // указываем на новый
        this->head->previous = nullptr; // предыдущий = nullptr
    }

    cout << "Вызван конструктор с параметром класса: Stack" << endl;
}

// конструктор копирования
Stack::Stack(const Stack &S)
{
    NodeStack *buf_haed = S.head; // создаем копию указателя на начало копируемого стека

    this->head = nullptr; // устанавливаем начало нового стека в nullptr
    this->tail = nullptr; // устанавливаем конец нового стека в nullptr
    this->count_elements = S.count_elements; // копируем кол-во элементов

    // перебираем все элементры
    while (buf_haed != nullptr)
    {
        NodeStack *node = new NodeStack(buf_haed->number); // создаем новый элемент

        // если еще элемента нет
        if (this->head == nullptr)
        {
            this->head = node; // устанавливаем голову на текущий элемент
        }

        // если элементы есть
        if (this->tail != nullptr)
        {
            this->tail->previous = node; // устанавливаем указатель на предыдущий элемент
        }

        this->tail = node; // двигаем указатель на конец конца
        buf_haed = buf_haed->previous; // двигаем указатель дальше
    }

    cout << "Вызван конструктор копирования класса: Stack" << endl;
}

// деструктор
Stack::~Stack()
{
    // перебираем все элементы
    while (head != nullptr)
    {
        NodeStack *buf_head = this->head; // создаем буферный указатель
        this->head = this->head->previous; // двигаем начало дальше
        delete buf_head; // удалаяем элементы
    }
}

// метод добавления элемента
void Stack::Set()
{
    cout << "Введите число: ";
    string num; // переменная для ввода числа

    // проверка на ввод числа
    try
    {
        cin >> num; // ввод числа
        for (int i = 0; i < num.length(); i++)
        {
            if ((num[i] >= 'A' and num[i] <= 'Z') or(num[i] >= 'a' and num[i] <= 'a'))
            {
                throw "Error";
            }
        }
    }
    catch(const std::exception& e) // если число некорректно
    {
        cout << "Число некорректно" << endl;
        exit(1);
    }
    catch(const char*mssg) // если число некорректно
    {
        cout << "Число некорректно" << endl;
        exit(1);
    }

    NodeStack *node = new NodeStack(stof(num)); // создаем элемент
    NodeStack *buf_head = this->head; // создаем буфер на начало

    // если уже есть элементы
    if (head != nullptr)
    {
        this->head = node; // двигаем начало на новый элемент
        this->head->previous = buf_head; // указатель нового элемента указывает на предыдущий
    }

    // если элементов нет
    else
    {
        this->head = node; // указываем на новый
        this->head->previous = nullptr; // предыдущий = nullptr
    }

    this->count_elements++;
}

// метод вывода стека
void Stack::Get()
{
    NodeStack *buf_node = this->head;

    cout << "\nЭлементы стека:" << endl;

    while (buf_node != nullptr)
    {
        cout << buf_node->number << endl;
        buf_node = buf_node->previous;
    }
}

// метод удаления элементов
void Stack::Pop()
{
    cout << "Введите кол-во элементов, которые вы хотите удалить: ";
    string count; // переменная для хранеения кол-ва

    // попытка ввода
    try
    {
        cin >> count;
        for (int i = 0; i < count.length(); i++)
        {
            if ((count[i] >= 'A' and count[i] <= 'Z') or(count[i] >= 'a' and count[i] <= 'a'))
            {
                throw "Error";
            }
        }
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Некорректный ввод" << endl;
        exit(1);
    }

    // если кол-во введено больше, приравниваем его к кол-ву элементов стека
    int count1 = 0; // буферный count
    if (stoi(count) > count_elements) count1 = count_elements;
    else count1 = stoi(count);

    int buf_count = 0; // буферный счетчик

    while (buf_count < count1)
    {
        NodeStack *buf_head = this->head; // создаем буферный указатель
        this->head = this->head->previous; // двигаем начало дальше
        delete buf_head; // удалаяем элементы
        buf_count++; // увеличиваем счетчик
    }
}

// проверка на пустоту стека
void Stack::isEmpty()
{
    if (this->head == nullptr)
    {
        cout << "Список пустой" << endl;
    }

    else
    {
        cout << "В списке есть элементы, в кол-ве: " << this->count_elements << endl;
    }
}

// методы загрузки из файла
void List::SetL(int number)
{
    NodeList *node = new NodeList(number); // создаем новый узел со значением

    // если элемент есть в списке
   if (this->tail != nullptr)
    {
        this->tail->next = node; // устанавливаем указатель на следующий элемент на созданный узел
    }

    // если элементов нет в списке
    if (this->head == nullptr)
    {
        this->head = node; // указатель на начало устанавливаем на текущую node
    }

    this->tail = node; // двигаем указатель на конец на новый добавленный элемент
    this->countEl++;
}

void Deque::SetL(int number)
{
    cout << "Куда добавить элемент?" << endl;
    cout << "Введите + если в начало \n"
        << "Введите - если в конец" << endl;

    string symbol; // переменная для ввода выбора
    try
    {
        cin >> symbol; // ввод
        if (symbol != "+" and symbol != "-") throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Ошибка ввода" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Выбор не верный" << endl;
        exit(1);
    }

    // добавление в конец деки
    if (symbol == "-")
    {
        NodeDeque *node = new NodeDeque(number); // создаем новый узел со значением

        // если элемент есть в списке
        if (this->Rtail != nullptr)
            {
                this->Rtail->previous = node; // устанавливаем указатель на следующий элемент на созданный узел
            }

        // если элементов нет в списке
        if (this->head == nullptr)
        {
            this->head = node; // указатель на начало устанавливаем на текущую node
        }

        this->Rtail = node; // двигаем указатель на конец на новый добавленный элемент
    }

    // если добавление в начало
    else
    {
        NodeDeque *node = new NodeDeque(number); // создаем новый узел со значением

        // если указатель на начало указывает на элемент
        if (Ltail != nullptr)
        {
            this->Ltail = node; // указатель на начало устанавливаем на новый элемент
            this->Ltail->previous = head; // новый начальный элемент будет указывать на прошлый начальный
        }

        // если еще нет элементов
        if (head == nullptr)
        {
            this->Rtail = node; // указатель на конец на новый элемент
            this->Ltail = node; // указатель на начало на новый элемент
        }

        this->head = node; // сдвигаем голову на новый начальный элемент
    }
    this->countEl++;
}

void Stack::SetL(int number)
{
    NodeStack *node = new NodeStack(number); // создаем элемент
    NodeStack *buf_head = this->head; // создаем буфер на начало

    // если уже есть элементы
    if (head != nullptr)
    {
        this->head = node; // двигаем начало на новый элемент
        this->head->previous = buf_head; // указатель нового элемента указывает на предыдущий
    }

    // если элементов нет
    else
    {
        this->head = node; // указываем на новый
        this->head->previous = nullptr; // предыдущий = nullptr
    }

    this->count_elements++;
}

// методы определения типа для записи в нужный файл
void List::GetType()
{
    ofstream loadL;
    loadL.open("list.txt", ios::app);

    NodeList *buf_head = this->head; // устанавливаем буферный указатель на начало списка

    while (buf_head != nullptr) // пока не конец списка
    {
        loadL << buf_head->number << endl; // выводим элемент
        buf_head = buf_head->next; // двигаемся дальше
    }

    loadL.close();
}
void Deque::GetType()
{
    ofstream loadD;
    loadD.open("deque.txt", ios::app);

    NodeDeque *buf_head = this->head; // устанавливаем буферный указатель на начало списка

    while (buf_head != nullptr) // пока не конец списка
    {
        loadD << buf_head->number << endl; // выводим элемент
        buf_head = buf_head->previous; // двигаемся дальше
    }

    loadD.close();
}
void Stack::GetType()
{
    ofstream loadS;
    loadS.open("stack.txt", ios::app);

    NodeStack *buf_node = this->head;

    while (buf_node != nullptr)
    {
        loadS << buf_node->number << endl;
        buf_node = buf_node->previous;
    }

    loadS.close();
}
