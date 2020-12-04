#浙大版《C语言程序设计（第3版）》题目集
cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD 99)
#设置当前的路径
set(MY_PATH ${CMAKE_CURRENT_LIST_DIR})
#add_executable(P5_1_1 ${CMAKE_CURRENT_SOURCE_DIR}/sets12/p5_1.c)
#add_executable(P5_1 ${CMAKE_CURRENT_LIST_DIR}/p5_1.c)

if (false)

    add_executable(P4_10.C ${MY_PATH}/p4_10.c)
    add_executable(P4_11.C ${MY_PATH}/p4_11.c)

endif ()
if (true)

    add_executable(P10_1.C ${MY_PATH}/p10_1.c)
    add_executable(P10_2.C ${MY_PATH}/p10_2.c)
    add_executable(P10_3.C ${MY_PATH}/p10_3.c)
    add_executable(P10_4.C ${MY_PATH}/p10_4.c)
    add_executable(P10_5.C ${MY_PATH}/p10_5.c)
    add_executable(P10_6.C ${MY_PATH}/p10_6.c)
    add_executable(P11_2.C ${MY_PATH}/p11_2.c)


endif ()
add_executable(temp ${MY_PATH}/temp.c)
add_executable(P4_11_1.C ${MY_PATH}/p4_11_1.c)
add_executable(P4_11_2.C ${MY_PATH}/p4_11_2.c)
add_executable(p11_7_2.c ${MY_PATH}/p11_7_2.c)
add_executable(p11_7.c ${MY_PATH}/p11_7.c)
add_executable(p10_7.c ${MY_PATH}/p10_7.c)
add_executable(p11_8.c ${MY_PATH}/p11_8.c)