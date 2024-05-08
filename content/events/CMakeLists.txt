add_library(events
        animation.cpp
        die.cpp
        hit.cpp
        #raise.cpp
        sound.cpp
        steal.cpp
        swing.cpp
        thrust.cpp
        updatefov.cpp
)

target_include_directories(events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(events PUBLIC engine)
