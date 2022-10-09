cmake_minimum_required(VERSION 3.15)
project(metal-cpp-cmake LANGUAGES CXX)

include(GNUInstallDirs)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/metal-cpp>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(
  ${PROJECT_NAME} INTERFACE "-framework Foundation" "-framework Quartz"
                            "-framework Metal")

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-config)
install(
  EXPORT ${PROJECT_NAME}-config
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/metal-cpp/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING
  PATTERN "*.hpp")
