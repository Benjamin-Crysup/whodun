
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

all : alllibs allexes alldoc alltests

alllibs : $(BINDIR)/libwhodun.a

allexes : $(BINDIR)/whodun

alltests : $(BINDIR)/testlibwhodun

alldoc : doc/html/index.html doc/whodun/main.html

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
$(STABLE_OBJDIR)/w_tests.o : stable/w_tests.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_tests.o stable/w_tests.cpp
$(STABLE_OBJDIR)/w_thread.o : stable/w_thread.cpp $(STABLE_HEADERS) | $(STABLE_OBJDIR)
	g++ $(COMP_OPTS) -Istable -c -o $(STABLE_OBJDIR)/w_thread.o stable/w_thread.cpp

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
			$(STABLE_OBJDIR)/w_tests.o \
			$(STABLE_OBJDIR)/w_thread.o \
			| $(BINDIR)
	ar rcs $(BINDIR)/libwhodun.a $(STABLE_OBJDIR)/*.o

STABLE_TEST_OBJDIR = $(OBJDIR)/stable_test

STABLE_TEST_HEADERS = stable_tests/tests.h

$(STABLE_TEST_OBJDIR) : 
	mkdir -p $(STABLE_TEST_OBJDIR)

$(STABLE_TEST_OBJDIR)/main.o : stable_tests/main.cpp $(STABLE_HEADERS) $(STABLE_TEST_HEADERS) | $(STABLE_TEST_OBJDIR)
	g++ $(COMP_OPTS) -Istable -Istable_tests -c -o $(STABLE_TEST_OBJDIR)/main.o stable_tests/main.cpp
$(STABLE_TEST_OBJDIR)/test_compress.o : stable_tests/test_compress.cpp $(STABLE_HEADERS) $(STABLE_TEST_HEADERS) | $(STABLE_TEST_OBJDIR)
	g++ $(COMP_OPTS) -Istable -Istable_tests -c -o $(STABLE_TEST_OBJDIR)/test_compress.o stable_tests/test_compress.cpp
$(STABLE_TEST_OBJDIR)/test_container.o : stable_tests/test_container.cpp $(STABLE_HEADERS) $(STABLE_TEST_HEADERS) | $(STABLE_TEST_OBJDIR)
	g++ $(COMP_OPTS) -Istable -Istable_tests -c -o $(STABLE_TEST_OBJDIR)/test_container.o stable_tests/test_container.cpp
$(STABLE_TEST_OBJDIR)/test_sort.o : stable_tests/test_sort.cpp $(STABLE_HEADERS) $(STABLE_TEST_HEADERS) | $(STABLE_TEST_OBJDIR)
	g++ $(COMP_OPTS) -Istable -Istable_tests -c -o $(STABLE_TEST_OBJDIR)/test_sort.o stable_tests/test_sort.cpp
$(STABLE_TEST_OBJDIR)/test_string.o : stable_tests/test_string.cpp $(STABLE_HEADERS) $(STABLE_TEST_HEADERS) | $(STABLE_TEST_OBJDIR)
	g++ $(COMP_OPTS) -Istable -Istable_tests -c -o $(STABLE_TEST_OBJDIR)/test_string.o stable_tests/test_string.cpp

$(BINDIR)/testlibwhodun : \
			$(STABLE_TEST_OBJDIR)/main.o \
			$(STABLE_TEST_OBJDIR)/test_compress.o \
			$(STABLE_TEST_OBJDIR)/test_container.o \
			$(STABLE_TEST_OBJDIR)/test_sort.o \
			$(STABLE_TEST_OBJDIR)/test_string.o \
			$(BINDIR)/libwhodun.a \
			| $(BINDIR)
	g++ $(COMP_OPTS) -o $(BINDIR)/testlibwhodun -L$(BINDIR) $(STABLE_TEST_OBJDIR)/*.o -lwhodun $(BASIC_PROG_LIBS)


# *******************************************************************
# programs
# *************************************
# whodun

PROG_WHODUN_OBJDIR = $(OBJDIR)/programs/whodun

PROG_WHODUN_HEADERS = programs/whodun/whodunmain_programs.h

$(PROG_WHODUN_OBJDIR) : 
	mkdir -p $(PROG_WHODUN_OBJDIR)

$(PROG_WHODUN_OBJDIR)/whodunmain.o : programs/whodun/whodunmain.cpp $(STABLE_HEADERS) $(UNSTABLE_HEADERS) $(PROG_WHODUN_HEADERS) | $(PROG_WHODUN_OBJDIR)
	g++ $(COMP_OPTS) -Istable -Iprograms/whodun -c -o $(PROG_WHODUN_OBJDIR)/whodunmain.o programs/whodun/whodunmain.cpp
$(PROG_WHODUN_OBJDIR)/whodun_main_d2t.o : programs/whodun/whodun_main_d2t.cpp $(STABLE_HEADERS) $(UNSTABLE_HEADERS) $(PROG_WHODUN_HEADERS) | $(PROG_WHODUN_OBJDIR)
	g++ $(COMP_OPTS) -Istable -Iprograms/whodun -c -o $(PROG_WHODUN_OBJDIR)/whodun_main_d2t.o programs/whodun/whodun_main_d2t.cpp
$(PROG_WHODUN_OBJDIR)/whodun_main_dconv.o : programs/whodun/whodun_main_dconv.cpp $(STABLE_HEADERS) $(UNSTABLE_HEADERS) $(PROG_WHODUN_HEADERS) | $(PROG_WHODUN_OBJDIR)
	g++ $(COMP_OPTS) -Istable -Iprograms/whodun -c -o $(PROG_WHODUN_OBJDIR)/whodun_main_dconv.o programs/whodun/whodun_main_dconv.cpp
$(PROG_WHODUN_OBJDIR)/whodun_main_t2d.o : programs/whodun/whodun_main_t2d.cpp $(STABLE_HEADERS) $(UNSTABLE_HEADERS) $(PROG_WHODUN_HEADERS) | $(PROG_WHODUN_OBJDIR)
	g++ $(COMP_OPTS) -Istable -Iprograms/whodun -c -o $(PROG_WHODUN_OBJDIR)/whodun_main_t2d.o programs/whodun/whodun_main_t2d.cpp
$(PROG_WHODUN_OBJDIR)/whodun_main_tconv.o : programs/whodun/whodun_main_tconv.cpp $(STABLE_HEADERS) $(UNSTABLE_HEADERS) $(PROG_WHODUN_HEADERS) | $(PROG_WHODUN_OBJDIR)
	g++ $(COMP_OPTS) -Istable -Iprograms/whodun -c -o $(PROG_WHODUN_OBJDIR)/whodun_main_tconv.o programs/whodun/whodun_main_tconv.cpp

#TODO

$(BINDIR)/whodun : \
			$(PROG_WHODUN_OBJDIR)/whodunmain.o \
			$(PROG_WHODUN_OBJDIR)/whodun_main_d2t.o \
			$(PROG_WHODUN_OBJDIR)/whodun_main_dconv.o \
			$(PROG_WHODUN_OBJDIR)/whodun_main_t2d.o \
			$(PROG_WHODUN_OBJDIR)/whodun_main_tconv.o \
			$(BINDIR)/libwhodun.a \
			| $(BINDIR)
	g++ $(COMP_OPTS) -o $(BINDIR)/whodun -L$(BINDIR) $(PROG_WHODUN_OBJDIR)/*.o -lwhodun $(BASIC_PROG_LIBS)


# *******************************************************************
# documentation

doc/html/index.html : $(STABLE_HEADERS)
	doxygen Doxyfile > /dev/null

doc/whodun/main.html : $(BINDIR)/whodun
	mkdir -p doc/whodun/
	python3 tools/ArgMang.py htmls --prog $(BINDIR)/whodun > doc/whodun/main.html
	python3 tools/ArgMang.py mans --prog $(BINDIR)/whodun --out ./doc/whodun/ --pref whodun



