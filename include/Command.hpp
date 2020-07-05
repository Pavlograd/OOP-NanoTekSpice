/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Command
*/

#ifndef __COMMAND_HPP__
# define __COMMAND_HPP__

int readData(std::istream &in, std::string *command);
int check_command(std::string command, nts::Component* component);

#endif /* !COMMAND_HPP_ */
