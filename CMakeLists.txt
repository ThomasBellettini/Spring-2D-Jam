cmake_minimum_required(VERSION 3.21)
project(Jam_GardenBusiness)

set(CMAKE_CXX_STANDARD 14)

add_executable(Jam_GardenBusiness WIN32 src/GardenBuisness.cpp src/Game/GameManagement.cpp appicon.rc src/Plant/IPlant.hpp src/Plant/APlant.cpp src/Plant/APlant.hpp include/libs.hpp src/Plant/Plot.cpp src/Plant/Plot.hpp src/Player/Player.hpp src/Player/Player.cpp src/Player/Inventory.cpp src/Player/Inventory.hpp src/Map/Map.hpp src/Map/Map.cpp src/Npc/Npc.cpp src/Npc/Npc.hpp src/Utils/GardenText.cpp src/Utils/GardenText.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
set(CMAKE_EXE_LINKER_FLAGS "-static")

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(Jam_GardenBusiness sfml-system sfml-window sfml-graphics sfml-audio)
