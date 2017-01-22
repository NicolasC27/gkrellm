##
## Makefile for yuu in /home/gerard_v/test/cpp_gkrellm
## 
## Made by valentin gerard
## Login   <gerard_v@epitech.net>
## 
## Started on  Sun Jan 22 09:29:19 2017 valentin gerard
## Last update Sun Jan 22 09:46:48 2017 valentin gerard
##

SUBDIRS = NCurses TekMonitor

all:COMPILES

COMPILES: $(SUBDIRS)
	cp TekMonitor/TekMonitor ./tekmonitor
	cp NCurses/gkrellm ./

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: $(SUBDIRS)
