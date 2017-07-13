cmake_minimum_required(VERSION 2.8)

project(lep)

FILE(GLOB_RECURSE LUAFiles "Scripts/*.lua")
add_custom_target(Scripts SOURCES ${LUAFiles})

FILE(GLOB_RECURSE ShaderFiles "Shaders/*.shader")
add_custom_target(Shaders SOURCES ${ShaderFiles})

include_directories(Source)

set (SHORT_PATH_INCL "${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs/Leadwerks/Include")
include_directories(${SHORT_PATH_INCL})

include_directories("${SHORT_PATH_INCL}/Libraries/")
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
include_directories("${SHORT_PATH_INCL}/Libraries/openssl/include")
include_directories("${SHORT_PATH_INCL}/Libraries/libogg/include")

include_directories("${SHORT_PATH_INCL}/Libraries/NewtonDynamics/packages/thirdParty/timeTracker")

include_directories("${SHORT_PATH_INCL}/")
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

add_definitions(-D_GLIBCXX_USE_CX11_ABI=0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=0 -std=c++11 -D_STATICLIB -msse3 -fexceptions -DPLATFORM_LINUX -Dunix -D__STEAM__")

link_directories("${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs/Leadwerks/Library/Linux/Debug")

add_executable (lep Source/main.cpp)

target_link_libraries(lep
m
"${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs/Leadwerks/Library/Linux/Debug/Leadwerks.a"
dl
openal
GL
GLU
"${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs/Leadwerks/Library/Linux/libsteam_api.so"
X11
Xrender
Xext
Xft
pthread
curl)

ELSE (WIN32)

add_compile_options(-std:c++latest)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DPSAPI_VERSION=1 /D__STEAM__ /D_CUSTOM_JOINTS_STATIC_LIB")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DFT2_BUILD_LIBRARY /DLEADWERKS_3_1 /DDG_DISABLE_ASSERT")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DWINDOWS /DWIN32 /DOS_WINDOWS /DOPENGL /DPLATFORM_WINDOWS")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_WIN_32_VER /D_NEWTON_USE_LIB /DPTW32_STATIC_LIB /DPTW32_BUILD")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_NEWTON_STATIC_LIB /D_LIB /DDG_USE_NORMAL_PRIORITY_THREAD")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DGLEW_STATIC /D_STATICLIB /D \"SLB_LIBRARY\" /MP")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /DDEBUG /D_DEBUG")
set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:MSVCRT.lib /NODEFAULTLIB:MSVCRTD.lib")

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
libcryptoMT.lib
libsslMT.lib
Rpcrt4.lib
crypt32.lib
libcurl.lib
Msimg32.lib
newton_d.lib
dContainers_d.lib
dCustomJoints_d.lib)

ENDIF (UNIX)

set(CMAKE_BUILD_TYPE Debug)
