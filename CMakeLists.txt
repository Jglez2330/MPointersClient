cmake_minimum_required(VERSION 3.12)
project(MpointersClient)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(MpointersClient main.cpp Socket.cpp Socket.h MPointer.cpp MPointer.h ReferenceCounter.cpp ReferenceCounter.h json.hpp DoubleLInkedList.cpp DoubleLInkedList.h GarbageCollector.cpp GarbageCollector.h LInkedLIstGC.cpp LInkedLIstGC.h NodeGC.cpp NodeGC.h NodeLD.cpp NodeLD.h)