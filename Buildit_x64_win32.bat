SET COMP_OPTS=-g -O0 -Wall -fPIC
SET BASIC_PROG_LIBS=-lz

SET HEADIR=builds\head_x64_win32
SET OBJDIR=builds\obj_x64_win32
SET BINDIR=builds\bin_x64_win32

IF EXIST %HEADIR% RMDIR /S /Q %HEADIR%
IF EXIST %OBJDIR% RMDIR /S /Q %OBJDIR%
IF EXIST %BINDIR% RMDIR /S /Q %BINDIR%
MKDIR %HEADIR%
MKDIR %OBJDIR%
MKDIR %BINDIR%

IF EXIST doc RMDIR /S /Q doc
MKDIR doc

REM **************************************************************************
REM stable compilation

SET STABLE_OBJDIR=%OBJDIR%\stable
MKDIR %STABLE_OBJDIR%

g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_args.o stable\w_args.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_compress.o stable\w_compress.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_container.o stable\w_container.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_ermac.o stable\w_ermac.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_oshook_com.o stable\w_oshook_com.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_oshook_win32.o stable\w_oshook_win32.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_parse.o stable\w_parse.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_regex.o stable\w_regex.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_sort.o stable\w_sort.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_stat_data.o stable\w_stat_data.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_stat_randoms.o stable\w_stat_randoms.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_stat_table.o stable\w_stat_table.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_stat_util_com.o stable\w_stat_util_com.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_streams.o stable\w_streams.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_string_com.o stable\w_string_com.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_string_x64.o stable\w_string_x64.cpp
IF %errorlevel% NEQ 0 EXIT /b
g++ %COMP_OPTS% -Istable -c -o %STABLE_OBJDIR%\w_thread.o stable\w_thread.cpp
IF %errorlevel% NEQ 0 EXIT /b

ar rcs %BINDIR%\libwhodun.a %STABLE_OBJDIR%\*.o
IF %errorlevel% NEQ 0 EXIT /b




