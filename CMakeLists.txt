cmake_minimum_required(VERSION 3.2)
project(Orderbook)

set(CMAKE_CXX_STANDARD 14)

find_package( Threads )

add_subdirectory(opt)

file(GLOB ORDERBOOK_SRC "src/*.cpp" "src/impl/*.cpp")
add_executable(orderbook ${ORDERBOOK_SRC})
target_link_libraries(orderbook ${CMAKE_THREAD_LIBS_INIT} ${CPR_LIBRARIES} )
include_directories(${Orderbook_SOURCE_DIR}/inc ${CPR_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS} ${SPIMPL_INCLUDE_DIRS})
