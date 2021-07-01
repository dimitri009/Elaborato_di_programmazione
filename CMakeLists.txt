cmake_minimum_required(VERSION 3.17)
project(Elaborato_di_programmazione)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)
set(SOURCE_FILES chat.cpp chat.h messageNotifier.cpp messageNotifier.h message.cpp message.h unreadMessageNotification.cpp unreadMessageNotification.h user.cpp version.h)
add_executable(Elaborato_di_programmazione main.cpp )
add_library(core ${SOURCE_FILES})
target_link_libraries(Elaborato_di_programmazione core)