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

default: libcount.so main
	@-echo "ok"

libcount.so: count.c count.h 
	${CXX} -fPIC -c count.c  
	${CXX} -shared -fPIC -o libcount.so *.o

main:main.cc 
	${CXX} main.cc -o main -ldl

clean:
	@-rm -rf main libcount.so *.o a.out
