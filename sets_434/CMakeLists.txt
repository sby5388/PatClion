#浙大版《数据结构（第2版）》题目集
cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_STANDARD 99)
#设置当前的路径
set(MY_PATH ${CMAKE_CURRENT_LIST_DIR})
if (false)
    add_executable(xt1_8.c ${MY_PATH}/xt1_8.c)
    add_executable(xt1_9.c ${MY_PATH}/xt1_9.c)
    add_executable(xt2_4.c ${MY_PATH}/xt2_4.c)
    add_executable(xt2_5.c ${MY_PATH}/xt2_5.c)
    add_executable(xt2_6.c ${MY_PATH}/xt2_6.c)
    add_executable(xt2_7.c ${MY_PATH}/xt2_7.c)
endif ()


add_executable(xt2_2.c ${MY_PATH}/xt2_2.c)

add_executable(xt2_8.c ${MY_PATH}/xt2_8.c)
add_executable(xt2_2_1.c ${MY_PATH}/xt2_2_1.c)
add_executable(sl1_1.c ${MY_PATH}/sl1_1.c)
add_executable(xt3_3.c ${MY_PATH}/xt3_3.c)
add_executable(xt3_5.c ${MY_PATH}/xt3_5.c)

add_executable(xt2_3.c ${MY_PATH}/xt2_3.c)