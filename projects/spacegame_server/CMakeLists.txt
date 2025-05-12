#--------------------------------------------------------------------------
# spacegame_server project
#--------------------------------------------------------------------------

PROJECT(spacegame_server)
FILE(GLOB project_headers code/*.h)
FILE(GLOB project_sources code/*.cc)

SET(files_project ${project_headers} ${project_sources})
SOURCE_GROUP("spacegame_server" FILES ${files_project})

ADD_EXECUTABLE(spacegame_server ${files_project})
TARGET_LINK_LIBRARIES(spacegame_server core render)
ADD_DEPENDENCIES(spacegame_server core render)

IF(MSVC)
    set_property(TARGET spacegame_server PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
ENDIF()