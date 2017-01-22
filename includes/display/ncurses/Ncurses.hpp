//
// Created by cheval_8 on 1/21/17.
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
