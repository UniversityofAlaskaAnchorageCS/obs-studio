project(simple-edit)

if(APPLE)
	find_library(COCOA Cocoa)
	include_directories(${COCOA})
endif()

if(UNIX)
	find_package(X11 REQUIRED)
	link_libraries(${X11_LIBRARIES})
	include_directories(${X11_INCLUDE_DIR})
endif()

set(simple-edit_HEADERS
	${simple-edit_HEADERS}
	simple-edit.h
	)
set(simple-edit_SOURCES
	${simple-edit_SOURCES}
	simple-edit.cpp
	simple-edit-module.c
	)
#set(advanced-scene-switcher_UI
#	${advanced-scene-switcher_UI}
#	forms/advanced-scene-switcher.ui
#	)

#if(WIN32)
#	set(advanced-scene-switcher_PLATFORM_SOURCES
#		advanced-scene-switcher-win.cpp)

#elseif(APPLE)
#	set(advanced-scene-switcher_PLATFORM_SOURCES
#		advanced-scene-switcher-osx.mm)
#	set_source_files_properties(advanced-scene-switcher-osx.mm
#		PROPERTIES COMPILE_FLAGS "-fobjc-arc")

#	set(advanced-scene-switcher_PLATFORM_LIBS
#		${COCOA})
#else()
#	set(advanced-scene-switcher_PLATFORM_SOURCES
#		advanced-scene-switcher-nix.cpp)
#	set(advanced-scene-switcher_PLATFORM_LIBS
#		Xss)
#endif()

#qt5_wrap_ui(advanced-scene-switcher_UI_HEADERS
#	${advanced-scene-switcher_UI}
#	${advanced-scene-switcher_PLATFORM_UI})

add_library(simple-edit MODULE
	${simple-edit_HEADERS}
	${simple-edit_SOURCES}
	#${advanced-scene-switcher_UI_HEADERS}
	#${advanced-scene-switcher_PLATFORM_SOURCES}
	#${advanced-scene-switcher_PLATFORM_HEADERS}
	)
target_link_libraries(simple-edit
	#${advanced-scene-switcher_PLATFORM_LIBS}
	obs-frontend-api
	Qt5::Widgets
	libobs)

install_obs_plugin(simple-edit data)
