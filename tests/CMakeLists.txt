add_executable(test_logging
  TestMain.cpp
)

target_include_directories(test_logging PRIVATE ../)
target_link_libraries(test_logging logging)