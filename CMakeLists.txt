cmake_minimum_required(VERSION 2.8)

project(lep)


include_directories(Source)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
set (SHORT_PATH_INCL "${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs/Leadwerks/Include")
include_directories(${SHORT_PATH_INCL})

include_directories("${SHORT_PATH_INCL}/Libraries/lua-5.1.4")
include_directories("${SHORT_PATH_INCL}/Libraries/enet-1.3.1/include")
include_directories("${SHORT_PATH_INCL}/Libraries/freetype-2.4.7/include")
include_directories("${SHORT_PATH_INCL}/Libraries/zlib-1.2.5/contrib/minizip")
include_directories("${SHORT_PATH_INCL}/Libraries/zlib-1.2.5")
include_directories("${SHORT_PATH_INCL}/Libraries/LuaJIT/src")
include_directories("${SHORT_PATH_INCL}/Libraries/tolua++-1.0.93/include")
include_directories("${SHORT_PATH_INCL}/Libraries/freetype-2.4.7/include")
include_directories("${SHORT_PATH_INCL}/Libraries/OpenAL/include")
include_directories("${SHORT_PATH_INCL}/Libraries/glew-1.6.0/include")
include_directories("${SHORT_PATH_INCL}/Libraries/steamworks/public/steam")
include_directories("${SHORT_PATH_INCL}/Libraries/glslang")
        
include_directories("${SHORT_PATH_INCL}/Libraries/VHACD/src/VHACD_Lib/inc")
include_directories("${SHORT_PATH_INCL}/Libraries/NewtonDynamics/packages/dCustomJoints")
include_directories("${SHORT_PATH_INCL}/Libraries/NewtonDynamics/packages/dNewton")
include_directories("${SHORT_PATH_INCL}/Libraries/NewtonDynamics/packages/dContainers")
include_directories("${SHORT_PATH_INCL}/Libraries/NewtonDynamics/packages/dMath")
include_directories("${SHORT_PATH_INCL}/Libraries/RecastNavigation/Recast/Include")
include_directories("${SHORT_PATH_INCL}/Libraries/RecastNavigation/DebugUtils/Include")
include_directories("${SHORT_PATH_INCL}/Libraries/RecastNavigation/Detour/Include")
include_directories("${SHORT_PATH_INCL}/Libraries/RecastNavigation/DetourCrowd/Include")
include_directories("${SHORT_PATH_INCL}/Libraries/RecastNavigation/Detour/Include")
include_directories("${SHORT_PATH_INCL}/Libraries/RecastNavigation/DetourTileCache/Include")
include_directories("${SHORT_PATH_INCL}/Libraries/NewtonDynamics/coreLibrary_300/source/newton")

include_directories("${SHORT_PATH_INCL}/Classes")
include_directories("${SHORT_PATH_INCL}/Classes/Drivers/Graphics")
include_directories("${SHORT_PATH_INCL}/Classes/Drivers/Network")
include_directories("${SHORT_PATH_INCL}/Classes/Drivers/Physics")
include_directories("${SHORT_PATH_INCL}/Classes/Drivers/Sound")
include_directories("${SHORT_PATH_INCL}/Classes/Entities")
include_directories("${SHORT_PATH_INCL}/Classes/Entities/Light")
include_directories("${SHORT_PATH_INCL}/Classes/Entities/Primitives")
include_directories("${SHORT_PATH_INCL}/Classes/GUI")
include_directories("${SHORT_PATH_INCL}/Classes/Math")

IF(UNIX)

set(CMAKE_CXX_FLAGS "-std=c++11 -D_STATICLIB -msse3 -fexceptions -DPLATFORM_LINUX -Dunix -D__STEAM__")

link_directories("${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs/Leadwerks/Library/Linux/")

add_executable (lep Source/main.cpp Source/App.cpp)

target_link_libraries(lep
m
"${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs/Leadwerks/Library/Linux/Debug/Leadwerks.a"
dl
openal
GL
GLU
libsteam_api.so
X11
pthread)

ELSE (WIN32)

set(CMAKE_CXX_FLAGS "/D PSAPI_VERSION=1 /D __STEAM__ /D _CUSTOM_JOINTS_STATIC_LIB /D FT2_BUILD_LIBRARY /D LEADWERKS_3_1 /D DG_DISABLE_ASSERT /D WINDOWS /D WIN32 /D OS_WINDOWS /D OPENGL /D PLATFORM_WINDOWS /D _WIN_32_VER /D _NEWTON_USE_LIB /D PTW32_STATIC_LIB /D PTW32_BUILD /D _NEWTON_STATIC_LIB /D _LIB /D DG_USE_NORMAL_PRIORITY_THREAD /D GLEW_STATIC /D DEBUG /D _DEBUG /D CMAKE_INTDIR=Debug /D _MBCS /errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /Oy- /MTd /EHsc /nologo")

link_directories("${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs/Leadwerks/Library/Windows/x86/")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs/Leadwerks/Library/Windows/x86/Debug/")

add_executable (lep Source/main.cpp Source/App.cpp)

target_link_libraries(lep
lua51.lib
steam_api.lib
ws2_32.lib
Glu32.lib
libovrd.lib
OpenGL32.lib
winmm.lib
Psapi.lib
OpenAL32.lib
Leadwerks.lib
)

ENDIF (UNIX)

set(CMAKE_BUILD_TYPE Debug)
