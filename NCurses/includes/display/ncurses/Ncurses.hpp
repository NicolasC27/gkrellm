//
// Ncurses.hpp for Ncurses.hpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/includes/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:05:54 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:05:54 2017 Nicolas Chevalier
//
#ifndef CPP_GKRELLM_NCURSES_HPP
#define CPP_GKRELLM_NCURSES_HPP

#include <ncurses.h>

class Ncurses
{
 public:
  Ncurses();

  void setBox(WINDOW *win, int i, int a);

  void setWmove(WINDOW *win, int i, int a);

  void setWprintw(WINDOW *win, const char *str);

  void setWattron(WINDOW *win, int a);

  void setWattroff(WINDOW *win, int b);

  void setWaddch(WINDOW *win, char c);

  void setWrefresh(WINDOW *win);

  void setEndwin();

  void setWclear(WINDOW *win);
};


#endif //CPP_GKRELLM_NCURSES_HPP
