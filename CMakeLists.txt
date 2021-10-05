cmake_minimum_required(VERSION 3.10)

# set the project name
project(Application VERSION 1.0) 

include_directories(Activity ActivityAdapters ActivityParameters Callback_HeightWeight)

set(SOURCES Activity/Activity.c ActivityAdapters/Activity_Adapter_Hunting.c ActivityAdapters/Activity_Adapter_Math.c 
        ActivityAdapters/Activity_Adapter_Reading.c ActivityParameters/ActivityMathArg.c Callback_HeightWeight/Callback_HeightSapiens.c
        HomoAbstract.c HomoHabilis.c HomoSapiens.c main.c)

add_executable(Application ${SOURCES})