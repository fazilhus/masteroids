#--------------------------------------------------------------------------
# spacegame_client project
#--------------------------------------------------------------------------

PROJECT(spacegame_client)
FILE(GLOB project_headers code/*.h)
FILE(GLOB project_sources code/*.cc)

SET(files_project ${project_headers} ${project_sources})
SOURCE_GROUP("spacegame_client" FILES ${files_project})

ADD_EXECUTABLE(spacegame_client ${files_project})
TARGET_LINK_LIBRARIES(spacegame_client core render)
ADD_DEPENDENCIES(spacegame_client core render)

IF(MSVC)
    set_property(TARGET spacegame_client PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
ENDIF()