#include <iostream>
#include <string>
#include <vector>

class Tasks
{
public:
    unsigned item{};
    std::string name{};
    bool isCompited = false;

    Tasks(unsigned a_item, std::string a_name, bool a_compited) : item(a_item), name(a_name), isCompited(a_compited) {}

    void print()
    {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Задача №" << item << std::endl;
        std::cout << name << std::endl;
        std::cout << (isCompited == true ? "Сделанна" : "Не сделанна") << std::endl;
    };
};

void hello_fn()
{
    std::cout << "Это todo list." << std::endl;
}

void setting_fn()
{
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Если хотите добавить задачу нажмите 1\nЕсли хотите удалить нажмите 2\nЕсли хотите исправить задачу нажмите 3\nЕсли хотите увидеть весь список задач нажмите 4\nЕсли хотите выйти нажмите 5. " << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

void compited_fn()
{
    std::cout << "Задача добавлена" << std::endl;
}

int main()
{
    bool run = true;
    std::string task_name;
    std::vector<Tasks> tasks;
    hello_fn();
    while (run)
    {
        setting_fn();

        std::string response;
        std::cin >> response;
        int response_int = std::stoi(response);
        switch (response_int)
        {
        case 1:
        {
            std::cout << "Напишите название задачи" << std::endl;
            std::cin >> task_name;
            Tasks newTasks(tasks.size() + 1, task_name, false);
            tasks.push_back(newTasks);
            compited_fn();
            break;
        }
        case 2:
        {
            if (!tasks.empty())
            {

                tasks.pop_back();
                std::cout << "Задача удалена" << std::endl;
            }
            else
            {
                std::cout << "Задача не найдена" << std::endl;
            }
            break;
        }
        case 3:
        {
            std::cout << "Разработка" << std::endl;
            break;
        }
        case 4:
        {
            for (auto task : tasks)
            {
                task.print();
            }
            break;
        }

        case 5:
        {
            run = false;
            break;
        }

        default:
            std::cout << "Такой команды нет" << std::endl;
            break;
        };
    }
}
