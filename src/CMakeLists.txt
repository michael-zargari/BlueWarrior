file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} "../include/Window.h" "../include/assets/Macro.h" "Window.cpp" "../include/Game.h" "Game.cpp" "../include/assets/StateMachine.h" "../include/State.h" "assets/StateMachine.cpp" "../include/assets/GameResources.h" "assets/GameResources.cpp" "../include/MainMenuState.h" "MainMenuState.cpp")
target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
