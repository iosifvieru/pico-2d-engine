# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PICO_SDK_FETCH_FROM_GIT ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico-game-engine C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(pico-game-engine 
        main.cpp

        Engine/Drivers/DisplayDriver/ST7735.cpp
        Engine/Drivers/InputDriver/Keyboard.cpp

        Engine/Canvas/BufferedCanvas.cpp
        
        Engine/Engine.cpp
        Engine/Entity/Entity.cpp
        Engine/Random.cpp

        Engine/Systems/MovementSystem.cpp
        Engine/Systems/RenderSystem.cpp
        Engine/Systems/CollisionSystem.cpp
        Engine/Systems/CameraSystem.cpp
        Engine/Systems/PhysicsSystem.cpp
        Engine/Systems/MenuSystem.cpp
        Engine/TextureManager.cpp

        Menu/Menu.cpp

        Games/pong/Pong.cpp
        Games/pong/Globals.cpp
        Games/pong/Systems/BallSystem.cpp
        Games/pong/Systems/EnemySystem.cpp
        Games/pong/Systems/GameLogic.cpp
        Games/pong/Systems/PlayerSystem.cpp
        Games/pong/Systems/UISystem.cpp

        Games/platformer_game/Systems/EnemySystem.cpp
        Games/platformer_game/Systems/LifetimeSystem.cpp
        Games/platformer_game/Systems/PlayerSystem.cpp
        Games/platformer_game/Assets.cpp
        Games/platformer_game/Player.cpp
        Games/platformer_game/Enemy.cpp
        )

pico_set_program_name(pico-game-engine "pico-game-engine")
pico_set_program_version(pico-game-engine "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(pico-game-engine 0)
pico_enable_stdio_usb(pico-game-engine 1)

# Add the standard library to the build
target_link_libraries(pico-game-engine
        pico_stdlib
        hardware_spi
        pico_multicore
        )

# Add the standard include files to the build
target_include_directories(pico-game-engine PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(pico-game-engine)
