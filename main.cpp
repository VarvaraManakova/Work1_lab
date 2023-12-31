#include <iostream>
#include "Keeper.h"
#include "Base.h"

using namespace std;

int main()
{
    Keeper keeper;
    while (1)
    {
        string choice; // переменная выбора

        cout << "\n\nВыберите, что вы хотите сделать:\n";
        cout << "1 - Добавить элемент\n"
             << "2 - Получить элементы\n"
             << "3 - Удалить элемент\n"
             << "4 - Удалить элемент элемента\n"
             << "5 - Добавить элемент в элемент\n"
             << "6 - Проверить на пустоту\n"
             << "7 - Загрузить данные из файла\n"
             << "8 - Загрузить данные в файл" << endl;

        try
        {
            cin >> choice;
            if (choice != "8" and choice != "7" and choice != "6" and choice != "5" and choice != "4" and choice != "3" and
                choice != "2" and choice != "1") throw "Error";
        }
        catch(const std::exception& e)
        {
            cout << "Неверный ввод" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Неверный выбор" << endl;
            break;
        }

        if (choice == "1")
        {
            keeper.Set();
        }

        else if (choice == "2")
        {
            keeper.Get();
        }

        else if (choice == "3")
        {
            keeper.Pop();
        }

        else if (choice == "4")
        {
            keeper.PopElement();
        }

        else if (choice == "5")
        {
            keeper.Change();
        }

        else if (choice == "6")
        {
            keeper.isEmpty();
        }

        else if (choice == "7")
        {
            keeper.Load();
        }

        else
        {
            keeper.Save();
        }
    }
}
