#include <iostream>
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

    cout << "Вызван конструктор без параметра класса: List" << endl;
}

// конструктор с параметром
List::List(float number)
{
    NodeList *node = new NodeList(number); // создаем указатель на узел

    this->head = node; // устанавливаем указатель начала списка на созданный узел
    this->tail = node; // указатель на конец списка
    this->tail->next = nullptr; // следующий элемент

    cout << "Вызван конструктор с параметром класса: List" << endl;
}

// конструктор копирования
List::List(const List &L)
{
    NodeList *buf_head = L.head; // создем буферный указатель, чтобы проходить по элементам

    this->head = nullptr; // устанвливаем указатели в nullptr
    this->tail = nullptr; // устанвливаем указатели в nullptr

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
        delete [] buf_head; // удаляем предыдущий элемент
        buf_head = head;
    }

    cout << "Вызван деструктор класса: List" << endl;
}

// метод добавления
void List::Set()
{
    cout << "Введите число: ";
    float num; // переменная для ввода числа

    // проверка на ввод числа
    try
    {
        cin >> num; // ввод числа
    }
    catch(const std::exception& e) // если число некорректно
    {
        cout << "Число некорректно" << endl;
    }

    NodeList *node = new NodeList(num); // создаем новый узел со значением

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
}

// метод вывода на экран
void List::Get()
{
    NodeList *buf_head = this->head; // устанавливаем буферный указатель на начало списка

    cout << "Элементы списка:" << endl;

    while (buf_head != nullptr) // пока не конец списка
    {
        cout << buf_head->number << endl; // выводим элемент
        buf_head = buf_head->next; // двигаемся дальше
    }
}

// метод удаления
void List::Pop()
{
    cout << "Введите номер элемента, который вы хотите удалить: ";
    int id; // переменная для хранеения номер

    // попытка ввода
    try
    {
        cin >> id;

        if (id < 1) throw "Error"; // если номер < 1 - ошибка
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Номер введен неверно" << endl;
    }

    int id_count = 1; // переменная для нахождения элемента
    NodeList *buf_head = this->head; // устанавливаем указатель на начало очереди

    // ищем нужный элемент
    while (id_count < id-1)
    {
        id_count++; // увеличиваем счетчик
        buf_head = buf_head->next; // двигаемся на след. элемент
    }

    NodeList *delete_node = buf_head->next; // устанавливаем указатель на элемент, который надо удалить
    NodeList *buf_next = delete_node->next; // устанавливаем указатель на элемент, на который указывает удаляемый

    buf_head->next = buf_next; // предыдущий элемент указывает на элемент, на который указывал удаляемый
    delete [] delete_node; // удаляем нужный элемент
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
        cout << "В списке есть элементы" << endl;
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

    cout << "Вызван конструктор без параметра класса: Deque" << endl;
}

// конструктор с параметром
Deque::Deque(float number)
{
    NodeDeque *node = new NodeDeque(number); // создаем указатель на узел

    this->head = node; // устанавливаем указатель начала деки на созданный узел
    this->Ltail = node; // указатель на неачало деки
    this->Rtail = node; // указатель на конец деки

    cout << "Вызван конструктор с параметром класса: Deque" << endl;
}

// конструктор копирования
Deque::Deque(const Deque &D)
{
    NodeDeque *buf_head = D.head; // создем буферный указатель, чтобы проходить по элементам

    this->head = nullptr; // устанвливаем указатели в nullptr
    this->Ltail = nullptr; // устанвливаем указатели в nullptr
    this->Rtail = nullptr; // устанвливаем указатели в nullptr

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
        delete [] buf_head; // удаляем предыдущий элемент
    }

    cout << "Вызван деструктор класса: Deque" << endl;
}

// метод добавления элементов
void Deque::Set()
{
    cout << "Введите число: ";
    float num; // переменная для ввода числа

    // проверка на ввод числа
    try
    {
        cin >> num; // ввод числа
    }
    catch(const std::exception& e) // если число некорректно
    {
        cout << "Число некорректно" << endl;
    }

    cout << "Куда добавить элемент?" << endl;
    cout << "Введите + если в начало"
        << "Введите - если в конец" << endl;

    char symbol; // переменная для ввода выбора
    try
    {
        cin >> symbol; // ввод
        if (symbol != '+' or symbol != '-') throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Ошибка ввода" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Выбор не верный" << endl;
    }

    // добавление в конец деки
    if (symbol == '-')
    {
        NodeDeque *node = new NodeDeque(num); // создаем новый узел со значением

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
        NodeDeque *node = new NodeDeque(num); // создаем новый узел со значением

        // если указатель на начало указывает на элемент
        if (Ltail != nullptr)
        {
            this->Ltail = node; // указатель на начало устанавливаем на новый элемент
            this->Ltail->previous = head; // новый начальный элемент будет указывать на прошлый начальный
            this->head = node; // сдвигаем голову на новый начальный элемент
        }

        // если еще нет элементов
        if (head == nullptr)
        {
            this->head = node; // голова на новый элемент
            this->Rtail = node; // указатель на конец на новый элемент
            this->Ltail = node; // указатель на начало на новый элемент
        }
    }
}

// метод вывода деки
void Deque::Get()
{
    NodeDeque *buf_head = this->head; // устанавливаем буферный указатель на начало списка

    cout << "Элементы деки:" << endl;

    while (buf_head != nullptr) // пока не конец списка
    {
        cout << buf_head->number << endl; // выводим элемент
        buf_head = buf_head->previous; // двигаемся дальше
    }
}

// удаление элементов
void Deque::Pop()
{
    cout << "Введите номер элемента, который вы хотите удалить: ";
    int id; // переменная для хранеения номер

    // попытка ввода
    try
    {
        cin >> id;

        if (id < 1) throw "Error"; // если номер < 1 - ошибка
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Номер введен неверно" << endl;
    }

    cout << "Откуда удалить элемент?" << endl;
    cout << "Введите + если из начала"
        << "Введите - если из конца" << endl;

    char symbol; // переменная для ввода выбора
    try
    {
        cin >> symbol; // ввод
        if (symbol != '+' or symbol != '-') throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Ошибка ввода" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Выбор не верный" << endl;
    }

    // если из начала
    if (symbol == '+')
    {
        NodeDeque *buf_head = head; // создаем буферный указатель на начало

        head = buf_head->previous; // перемещаем на следущий элемент указатель на голову
        Ltail = buf_head->previous; // перемещаем на следующий элемент указатель на начало

        delete [] buf_head; // удаляем
    }

    // если из конца
    else
    {
        NodeDeque *buf_Rtail = head; // буферный указатель на начало

        // перебираем все элементы до конечного - 1
        while (buf_Rtail < Rtail)
        {
            // если текущий указатель на следующий элемент не указывает на конец, то двигаем указатель
            if (buf_Rtail->previous != Rtail)
            {
                buf_Rtail = buf_Rtail->previous;
            }
            //иначе прекращаем цикл
            else
            {
                break;
            }
        }

        delete [] Rtail;
        Rtail = buf_Rtail;
    }
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
        cout << "В деке есть элементы" << endl;
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
        delete [] buf_head; // удалаяем элементы
    }
}

// метод добавления элемента
void Stack::Set()
{
    cout << "Введите число: ";
    float num; // переменная для ввода числа

    // проверка на ввод числа
    try
    {
        cin >> num; // ввод числа
    }
    catch(const std::exception& e) // если число некорректно
    {
        cout << "Число некорректно" << endl;
    }

    NodeStack *node = new NodeStack(num); // создаем элемент
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

    cout << "Элементы стека:" << endl;

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
    int count; // переменная для хранеения кол-ва

    // попытка ввода
    try
    {
        cin >> count;
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }

    // если кол-во введено больше, приравниваем его к кол-ву элементов стека
    if (count > count_elements) count = count_elements;

    int buf_count = 0; // буферный счетчик

    while (buf_count < count)
    {
        NodeStack *buf_head = this->head; // создаем буферный указатель
        this->head = this->head->previous; // двигаем начало дальше
        delete [] buf_head; // удалаяем элементы
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
