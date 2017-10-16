add_executable(shell-app demo.cpp Classifier.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(shell-app ${OpenCV_LIBS} ${Boost_LIBRARIES})
