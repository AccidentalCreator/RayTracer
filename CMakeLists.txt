cmake_minimum_required(VERSION 2.6)
project(RAYTRACER)

if (MSVC)
	include_directories(
	src
	contrib/msvc-windows-x86/SDL2/include
    	contrib/msvc-windows-x86/GLM
)

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/GLM
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_executable(RayTracer
		src/RayTracer/Screen.h
		src/RayTracer/Ray.h
		src/RayTracer/Sphere.h
		src/RayTracer/Tracer.h
		src/RayTracer/Camera.h

		src/RayTracer/Screen.cpp
		src/RayTracer/Ray.cpp
		src/RayTracer/Sphere.cpp
		src/RayTracer/Tracer.cpp
		src/RayTracer/Camera.cpp

		src/RayTracer/main.cpp)

if(MSVC)
  target_link_libraries(RayTracer
    SDL2
  )
else()
  target_link_libraries(RayTracer
    SDL2
  )
endif()


if(MSVC)
  add_custom_command(TARGET RayTracer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:RayTracer>"
  )
endif()

target_link_libraries(RayTracer SDL2)