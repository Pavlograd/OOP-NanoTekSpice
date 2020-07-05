/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parsing
*/

#include "Parsing.hpp"

std::string process(std::string const &s)
{
    std::string::size_type pos = s.find('#');
    if (pos != std::string::npos)
        return s.substr(0, pos);
    else
        return s;
}

void checkNames(nts::Component *component, std::string name)
{
    if (component->componentExist(name))
    {
        std::cerr << "This component already exists." << std::endl;
        exit(84);
    }
}

void checkNbrElement(std::string line)
{
    std::string tmp;
    std::istringstream ss(line);
    int c = 0;

    while (ss.good())
    {
        ss >> tmp;
        c++;
    }
    if (c != 2)
    {
        std::cerr << "Error too much arguments in this line :" << line << std::endl;
        exit(84);
    }
}

void tryAddComponent(std::string category, std::string tmp, nts::Component *component, int *nb_inputs)
{
    if (category.compare("input") == 0)
    {
        component->addComponent("Input", "Undefined", tmp);
        (*nb_inputs)++;
    }
    else if (category.compare("output") == 0)
        component->addComponent("Output", "0", tmp);
    else if (category.compare("clock") == 0)
    {
        component->addComponent("Clock", "Undefined", tmp);
        (*nb_inputs)++;
    }
    else if (category.compare("true") == 0)
        component->addComponent("True", "1", tmp);
    else if (category.compare("false") == 0)
        component->addComponent("False", "0", tmp);
    else if (category.compare("4001") == 0)
        component->addComponent("4001", "1", tmp);
    else if (category.compare("4008") == 0)
        component->addComponent("4008", "1", tmp);
    else if (category.compare("4011") == 0)
        component->addComponent("4011", "1", tmp);
    else if (category.compare("4013") == 0)
        component->addComponent("4013", "1", tmp);
    else if (category.compare("4017") == 0)
        component->addComponent("4017", "1", tmp);
    else if (category.compare("4030") == 0)
        component->addComponent("4030", "1", tmp);
    else if (category.compare("4040") == 0)
        component->addComponent("4040", "1", tmp);
    else if (category.compare("4071") == 0)
        component->addComponent("4071", "1", tmp);
    else if (category.compare("4081") == 0)
        component->addComponent("4081", "1", tmp);
    else if (category.compare("4069") == 0)
        component->addComponent("4069", "1", tmp);
    else if (category.compare("4514") == 0)
        component->addComponent("4514", "1", tmp);
    else {
        std::cerr << "This Component type is undefined: " << category << std::endl;
        exit(84);
    }
}

void tryAddLinks(std::string category, std::string tmp, nts::Component *component)
{
    std::istringstream sTmp(tmp);
    std::istringstream sCategory(category);
    std::string tmp1 = "";
    std::string tmp2 = "";
    std::string category1 = "";
    std::string category2 = "";
    int link1 = -1;
    int link2 = -1;

    sTmp >> tmp1;
    sTmp >> tmp2;
    sCategory >> category1;
    sCategory >> category2;
    if (tmp1.compare("") == 0 || tmp2.compare("") == 0 || category1.compare("") == 0 || category2.compare("") == 0)
    {
        std::cerr << "One arguments is missing to create a link" << std::endl;
        exit(84);
    }
    link1 = stoi(tmp2);
    link2 = stoi(category2);
    if (link1 <= 0 || link2 <= 0)
    {
        std::cerr << "Incorrect link number" << std::endl;
        exit(84);
    }
    component->createLink(category1, tmp1, link2, link1);
}

void checkErrorLinks(std::string tmp, std::string category)
{
    size_t n = std::count(tmp.begin(), tmp.end(), ':');

    if (n != 1)
    {
        std::cerr << "You have to set a link for " << tmp << "." << std::endl;
        exit(84);
    }
    n = std::count(category.begin(), category.end(), ':');
    if (n != 1)
    {
        std::cerr << "You have to set a link for " << category << "." << std::endl;
        exit(84);
    }
}

void setAllInputsValues(int argc, char **argv, nts::Component *component)
{
    std::string name = "";
    std::string value = "";

    for (int i = 2; i < argc; i++)
    {
        name = "";
        value = "";
        std::string line = argv[i];
        size_t n = std::count(line.begin(), line.end(), '=');

        if (n != 1)
        {
            std::cerr << "Wrong format declaration variable: " << line << std::endl;
            exit(84);
        }
        std::replace(line.begin(), line.end(), '=', ' ');
        checkNbrElement(line);
        std::istringstream ss(line);
        ss >> name;
        ss >> value;
        component->changeValue(name, value);
    }
}

void parsingFile(int argc, char **argv, nts::Component *component)
{
    std::ifstream file(argv[1]);
    std::string line = "";
    std::string tmp = "";
    std::string category = "";
    int chipsets = 0;
    int links = 0;
    int nb_inputs = 0;
    (void)component;

    if (argc < 2)
        exit(84);
    for (int i = 0; std::getline(file, line); i++)
    {
        line = process(line);
        if (!line.empty())
        {
            int check = 0;
            if (line.compare(".chipsets:") == 0)
            {
                if (chipsets != 0)
                    exit(84);
                chipsets++;
                check = 1;
            }
            if (line.compare(".links:") == 0)
            {
                if (links != 0)
                    exit(84);
                links++;
                check = 1;
            }
            if (check == 0)
            {
                if (chipsets == 1 && links == 0)
                {
                    checkNbrElement(line);
                    std::istringstream ss(line);
                    ss >> category;
                    ss >> tmp;
                    checkNames(component, tmp);
                    tryAddComponent(category, tmp, component, &nb_inputs);
                }
                else if (links == 1 && chipsets == 1)
                {
                    checkNbrElement(line);
                    std::istringstream ss(line);
                    ss >> tmp;
                    ss >> category;
                    std::replace(tmp.begin(), tmp.end(), ':', ' ');
                    std::replace(category.begin(), category.end(), ':', ' ');
                    tryAddLinks(category, tmp, component);
                }
                else
                    exit(84);
            }
        }
    }
    if ((argc - 2 - nb_inputs) != 0)
    {
        std::cerr << "All inputs won't be set. You need to declare their values with the arguments." << std::endl;
        exit(84);
    }
    setAllInputsValues(argc, argv, component);
}