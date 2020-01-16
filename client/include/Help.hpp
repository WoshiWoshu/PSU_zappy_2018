/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Help
*/

#ifndef HELP_HPP_
#define HELP_HPP_

class Help {
public:
  Help();
  ~Help();
  static void usage();
  static bool checkParams(int, const char **);

private:
};

#endif /* !HELP_HPP_ */
