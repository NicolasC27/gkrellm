//
// Ncurses.cpp for Displayncurses.cpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/srcs/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:07:23 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:07:24 2017 Nicolas Chevalier
//

#include "../../../includes/display/ncurses/Ncurses.hpp"

Ncurses::Ncurses()
{
  initscr();
  start_color();
  for(int i  = 0; i < COLORS && i < COLOR_PAIRS; i++)
    init_pair(i, COLOR_BLACK, i);
  cbreak();
  halfdelay(2);
  noecho();
  keypad(stdscr, true);
  curs_set(0);
  timeout(0);
}

void Ncurses::setWattron(WINDOW *win, int a)
{
  wattron(win, a);
}

void Ncurses::setWattroff(WINDOW *win, int b)
{
  wattroff(win, b);
}

void Ncurses::setWaddch(WINDOW *win, char c)
{
  waddch(win, c);
}

void Ncurses::setWprintw(WINDOW *win, const char *str)
{
  wprintw(win, str);
}

void Ncurses::setWrefresh(WINDOW *win)
{
  wrefresh(win);
}

void Ncurses::setEndwin()
{
  endwin();
}

void Ncurses::setWmove(WINDOW *win, int i, int a)
{
    wmove(win, i, a);
}

void Ncurses::setWclear(WINDOW *win)
{
    wclear(win);
}

void Ncurses::setBox(WINDOW *win, int i, int a)
{

    box(win, i, a);
}
