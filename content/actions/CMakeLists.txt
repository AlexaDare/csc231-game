add_library(actions
        attack.cpp
        closedoor.cpp
        move.cpp
        opendoor.cpp
        rest.cpp
        wander.cpp
)

target_include_directories(actions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(actions PUBLIC engine events)
