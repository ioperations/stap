#!/usr/bin/env make
ccred=$(shell echo "\033[0;31m")
ccgreen=$(shell echo "\033[0;32m")
ccyellow=$(shell echo "\033[0;33m")
ccwhite=$(shell echo "\033[0;37m")
# $(error ${ccred} error message ${ccwhite})
# $(info ${ccyellow} info message ${ccwhite})


# $(error ${ccred} error message ${ccwhite})
# $(info ${ccred} info message ${ccwhite})
CXX=g++

default: generate_clyout_file
	@-echo "ok"

main:main.cc 
	${CXX} main.cc -o main  -g

main.debug:main 
	objcopy --only-keep-debug main main.debug
	objcopy --strip-debug main
	strip main
	objcopy --add-gnu-debuglink=main.debug main


show_debug_info:main
	readelf --string-dump=.gnu_debuglink main

generate_clyout_file:main.debug 
	clayout -i main.debug -o struct Dummy

clean:
	@-rm -rf main  *.o a.out main.debug struct.h struct.c
