add_executable(test_logging
  TestMain.cpp
)

target_link_libraries(test_logging PRIVATE logging)