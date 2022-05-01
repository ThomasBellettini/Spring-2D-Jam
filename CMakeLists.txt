cmake_minimum_required(VERSION 3.21)
project(Jam_GardenBusiness)

set(CMAKE_CXX_STANDARD 14)

add_executable(Jam_GardenBusiness WIN32 src/GardenBuisness.cpp src/Game/GameManagement.cpp appicon.rc src/Plant/IPlant.hpp src/Plant/APlant.cpp src/Plant/APlant.hpp include/libs.hpp src/Plant/Pot.cpp src/Plant/Pot.hpp src/Player/Player.hpp src/Player/Player.cpp src/Player/Inventory.cpp src/Player/Inventory.hpp src/Map/AMap.hpp src/Map/AMap.cpp src/Npc/Npc.cpp src/Npc/Npc.hpp src/Utils/GardenText.cpp src/Utils/GardenText.hpp src/Map/IMap.hpp src/Map/GardenMap.cpp src/Map/GardenMap.hpp src/Map/ChamberMap.cpp src/Map/ChamberMap.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
set(CMAKE_EXE_LINKER_FLAGS "-static")

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(Jam_GardenBusiness sfml-system sfml-window sfml-graphics sfml-audio)