#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Tasks
{

public:
    unsigned id{};
    std::string name{};
    bool isComplited = false;

    Tasks(unsigned a_id, std::string a_name, bool a_complited) : id(a_id), name(a_name), isComplited(a_complited) {}

    void print()
    {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Задача №" << id << std::endl;
        std::cout << name << std::endl;
        std::cout << (isComplited == true ? "Сделанна" : "Не сделанна") << std::endl;
    };
};

enum class Text
{
    hello,
    menu,
    interface,
    addTask,
    inputTask,
    inputId,
    deleteTask,
    fixTask,
    notId,
    notTask,
    notFound
};

std::string get_message(Text msg)
{
    switch (msg)
    {
    case Text::hello:
        return "Это todo list.";
    case Text::menu:
        return "Добавить задачу - 1\nУдалить - 2\nИзменить задачу - 3\nВесь список задач - 4\nВыйти - 5.";
    case Text::interface:
        return "-----------------------------";
    case Text::addTask:
        return "Задача добавлена";
    case Text::inputTask:
        return "Напишите название задачи";
    case Text::inputId:
        return "Выберите id задачи";
    case Text::deleteTask:
        return "Задача удалена";
    case Text::notId:
        return "id не найден";
    case Text::notTask:
        return "Задача не найдена";
    case Text::fixTask:
        return "Напишите новое название задачи";
    case Text::notFound:
        return "Такой команды нет";
    }
    return "";
};

int main()
{
    bool run = true;
    std::string task_name;
    std::vector<Tasks> tasks;
    std::cout << get_message(Text::hello) << std::endl;
    std::ofstream file("todo.txt", std::ios_base::out);
    bool found = false;
    while (run)
    {
        std::cout << get_message(Text::interface) << std::endl;
        std::cout << get_message(Text::menu) << std::endl;
        std::cout << get_message(Text::interface) << std::endl;

        std::string response;
        std::cin >> response;
        int response_int = std::stoi(response);
        switch (response_int)
        {
        case 1:
        {
            std::cout << get_message(Text::inputTask) << std::endl;
            std::cin >> task_name;
            Tasks newTasks(tasks.size() + 1, task_name, false);
            tasks.push_back(newTasks);
            std::cout << get_message(Text::addTask) << std::endl;
            break;
        }
        case 2:
        {
            if (!tasks.empty())
            {
                std::string edit_id;
                std::cout << get_message(Text::inputId) << std::endl;
                std::cin >> edit_id;

                for (int i = 0; i < tasks.size(); i++)
                {
                    if (tasks[i].id == std::stoi(edit_id))
                    {
                        tasks.erase(tasks.begin() + i);
                        std::cout << get_message(Text::deleteTask) << std::endl;
                        found = true;
                        break;
                    }
                    else
                    {
                        std::cout << get_message(Text::notId) << std::endl;
                        !found
                    }
                }
            }
            else
            {
                std::cout << get_message(Text::notTask) << std::endl;
            }
            break;
        }
        case 3:
        {
            std::string rename;
            std::string edit_id;
            std::cout << get_message(Text::inputId) << std::endl;
            std::cin >> edit_id;
            std::cout << get_message(Text::fixTask) << std::endl;
            std::cin >> rename;
            for (int i = 0; i < tasks.size(); i++)
            {
                if (tasks[i].id == std::stoi(edit_id))
                {
                    tasks[i].name = rename;
                }
            };
            break;
        }
        case 4:
        {
            // std::ifstream file("todo.tsx");
            // if (file.is_open())
            // {
            //     char temp[1000];
            //     file.getline(temp, 1000);
            //     std::cout << temp << std::endl;
            // }
            // file.close();
            for (auto task : tasks)
            {
                task.print();
            }
            break;
        }

        case 5:
        {
            if (file.is_open())
            {
                for (auto task : tasks)
                {
                    file << task.id << ";" << task.name << ";" << (task.isComplited ? 1 : 0) << std::endl;
                }
                file.close();
            }
            run = false;
            break;
        }

        default:
            std::cout << get_message(Text::notFound) << std::endl;
            break;
        };
    }
}
