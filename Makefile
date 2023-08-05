#!/usr/bin/env make
ccred=$(shell echo "\033[0;31m")
ccgreen=$(shell echo "\033[0;32m")
ccyellow=$(shell echo "\033[0;33m")
ccwhite=$(shell echo "\033[0;37m")
# $(error ${ccred} error message ${ccwhite})
# $(info ${ccyellow} info message ${ccwhite})


#check if file exists
#ifneq ("$(wildcard  FILENAME)","")
##file exists; use space insted of tab here
#endif 

#use ${LINENO} to locate the error message location

srcs = $(wildcard *.cc)
target=$(patsubst %.cc, %, $(srcs))
asm_target=$(srcs:.cc=.s)


CXX ?= g++
CPPFLAGS += -g

default: $(target) rust bpftrace_cpp_string dlopen_t
	$(info ${ccgreen} ok ${ccwhite})

rust:rust.rs 
	rustc $< -o $@

bpftrace_cpp_string:
	make -C bpftrace_cpp_string

dlopen_t:
	make -C dlopen_t

%:%.cc
	${CXX} $< ${CPPFLAGS} -o $@

clean:
	-rm ${target} a.out rust
	make -C bpftrace_cpp_string clean 
	make -C dlopen_t clean 
