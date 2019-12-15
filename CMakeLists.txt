# Add as a subdirectory SimpleRenderEngineProject using add_subdirectory
IF (NOT DEFINED all_libs)
    message( FATAL_ERROR "This CMakeLists.txt must be included using the command add_subdirectory(name)" )
ENDIF (NOT DEFINED all_libs)
# Ensure SimpleRenderEngineProject is up-to-date
IF (WIN32)
    IF (NOT DEFINED DLLFileList)
        message( FATAL_ERROR "The SimpleRenderEngineProject has been updated. Clone the project (https://github.com/mortennobel/SimpleRenderEngineProject) again the project again and start over." )
    ENDIF(NOT DEFINED DLLFileList)
ENDIF(WIN32)

file(GLOB pokeman
        "*.hpp"
        "*.h"
        "*.cpp"
        )

add_executable(Pokeman ${pokeman} WorldGenerator.cpp WorldGenerator.h Projectile.cpp Projectile.h Creature.h Creature.cpp SoundSource.cpp SoundSource.h)

target_link_libraries(Pokeman ${all_libs})

# copy files to dest
file(COPY assets sounds sprites DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
file(COPY assets sounds sprites DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
file(COPY assets sounds sprites DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


IF (WIN32)
    # Copy dll files to ${CMAKE_CURRENT_BINARY_DIR}/Debug
    file(COPY ${DLLFileList} DESTINATION Debug)
    file(COPY ${DLLFileList} DESTINATION Release)
    file(COPY ${DLLFileList} DESTINATION .)

    # Set working directory to ${CMAKE_CURRENT_BINARY_DIR}/Debug
    set_target_properties(Pokeman PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Debug)
ENDIF(WIN32)
