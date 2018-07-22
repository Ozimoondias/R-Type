if (UNIX)
	cmake_minimum_required(VERSION 3.9)
elseif (WIN32)
	cmake_minimum_required(VERSION 3.5.1)
endif()

project(cpp_rtype)

include_directories(include)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCES
        src/main.cpp
        src/CoreManager.cpp
        src/EntityManager.cpp
        src/GraphicsManager.cpp
        src/NetworkManager.cpp
        src/StateManager.cpp
        src/GameState.cpp
        src/MenuState.cpp
        src/IntroState.cpp
        src/Entity.cpp
        src/Shot.cpp
        src/Player.cpp
        src/Enemy.cpp
        src/OverState.cpp
        src/Map.cpp
        src/PauseState.cpp
        src/Button.cpp
        src/SelectState.cpp
        src/Boss.cpp
        src/BossState.cpp
        src/MeteorState.cpp
        src/Bonus.cpp
        src/Sound.cpp)

add_executable(cpp_rtype ${SOURCES})

find_package(SFML 2 COMPONENTS system window graphics network audio REQUIRED)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(cpp_rtype ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} Threads::Threads)
endif()
