
# figure out what flavor of processor this is running on

uname_p := $(shell uname -p)
ifeq ($(uname_p),i386)
PROC_NAME = x86
else ifeq ($(uname_p),i686)
PROC_NAME = x86
else ifeq ($(uname_p),x86_64)
PROC_NAME = x64
else ifeq ($(uname_p),amd64)
PROC_NAME = x64
else
PROC_NAME = oth
endif

COMP_OPTS = -g -O0 -Wall -pthread
BASIC_PROG_LIBS = -ldl -lz
GPU_PROG_LIBS = -lvulkan
OBJDIR = builds/obj_$(PROC_NAME)_linux
BINDIR = builds/bin_$(PROC_NAME)_linux

# *******************************************************************
# super targets

all : alllibs alldoc

alllibs : $(BINDIR)/libwhodun.a

alldoc : doc/html/index.html

clean : 
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)
	rm -rf doc/*

$(BINDIR) : 
	mkdir -p $(BINDIR)

# *******************************************************************
# stable

STABLE_OBJDIR = $(OBJDIR)/stable

STABLE_HEADERS = stable/whodun_args.h stable/whodun_compress.h stable/whodun_container.h stable/whodun_ermac.h stable/whodun_math_constants.h stable/whodun_oshook.h stable/whodun_parse.h stable/whodun_regex.h stable/whodun_sort.h stable/whodun_stat_data.h stable/whodun_stat_randoms.h stable/whodun_stat_table.h stable/whodun_stat_util.h stable/whodun_streams.h stable/whodun_string.h stable/whodun_thread.h

$(STABLE_OBJDIR) : 
	mkdir -p $(STABLE_OBJDIR)

$(STABLE_OBJDIR)/w_args.o : stable/w_args.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_args.o stable/w_args.cpp
$(STABLE_OBJDIR)/w_compress.o : stable/w_compress.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_compress.o stable/w_compress.cpp
$(STABLE_OBJDIR)/w_container.o : stable/w_container.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_container.o stable/w_container.cpp
$(STABLE_OBJDIR)/w_ermac.o : stable/w_ermac.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_ermac.o stable/w_ermac.cpp
$(STABLE_OBJDIR)/w_oshook_com.o : stable/w_oshook_com.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_oshook_com.o stable/w_oshook_com.cpp
$(STABLE_OBJDIR)/w_oshook_linux.o : stable/w_oshook_linux.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_oshook_linux.o stable/w_oshook_linux.cpp
$(STABLE_OBJDIR)/w_parse.o : stable/w_parse.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_parse.o stable/w_parse.cpp
$(STABLE_OBJDIR)/w_regex.o : stable/w_regex.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_regex.o stable/w_regex.cpp
$(STABLE_OBJDIR)/w_sort.o : stable/w_sort.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_sort.o stable/w_sort.cpp
$(STABLE_OBJDIR)/w_stat_data.o : stable/w_stat_data.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_stat_data.o stable/w_stat_data.cpp
$(STABLE_OBJDIR)/w_stat_randoms.o : stable/w_stat_randoms.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_stat_randoms.o stable/w_stat_randoms.cpp
$(STABLE_OBJDIR)/w_stat_table.o : stable/w_stat_table.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_stat_table.o stable/w_stat_table.cpp
$(STABLE_OBJDIR)/w_stat_util_com.o : stable/w_stat_util_com.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_stat_util_com.o stable/w_stat_util_com.cpp
$(STABLE_OBJDIR)/w_streams.o : stable/w_streams.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_streams.o stable/w_streams.cpp
$(STABLE_OBJDIR)/w_string_com.o : stable/w_string_com.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_string_com.o stable/w_string_com.cpp
$(STABLE_OBJDIR)/w_string_$(PROC_NAME).o : stable/w_string_$(PROC_NAME).cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_string_$(PROC_NAME).o stable/w_string_$(PROC_NAME).cpp
$(STABLE_OBJDIR)/w_thread.o : stable/w_thread.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_thread.o stable/w_thread.cpp

#TODO

$(BINDIR)/libwhodun.a : \
			$(STABLE_OBJDIR)/w_args.o \
			$(STABLE_OBJDIR)/w_compress.o \
			$(STABLE_OBJDIR)/w_container.o \
			$(STABLE_OBJDIR)/w_ermac.o \
			$(STABLE_OBJDIR)/w_oshook_com.o $(STABLE_OBJDIR)/w_oshook_linux.o \
			$(STABLE_OBJDIR)/w_parse.o \
			$(STABLE_OBJDIR)/w_regex.o \
			$(STABLE_OBJDIR)/w_sort.o \
			$(STABLE_OBJDIR)/w_stat_data.o \
			$(STABLE_OBJDIR)/w_stat_randoms.o \
			$(STABLE_OBJDIR)/w_stat_table.o \
			$(STABLE_OBJDIR)/w_stat_util_com.o \
			$(STABLE_OBJDIR)/w_streams.o \
			$(STABLE_OBJDIR)/w_string_com.o $(STABLE_OBJDIR)/w_string_$(PROC_NAME).o \
			$(STABLE_OBJDIR)/w_thread.o \
			| $(BINDIR)
	ar rcs $(BINDIR)/libwhodun.a $(STABLE_OBJDIR)/*.o

# *******************************************************************
# documentation

doc/html/index.html : $(STABLE_HEADERS)
	doxygen Doxyfile > /dev/null


