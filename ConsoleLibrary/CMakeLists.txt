add_library(CONSOLE_LIBRARY SHARED ConsoleDisplayer.cpp ConsoleDisplayer.h)
add_executable(CONSOLE_LIBRARY_TESTING Library_Testing.cpp)
set_target_properties(CONSOLE_LIBRARY PROPERTIES LINKER_LANGUAGE CXX)
# works?