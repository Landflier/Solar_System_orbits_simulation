cmake_minimum_required(VERSION 3.16)
project(Solar_System_rebased C)

set(CMAKE_C_STANDARD 99)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(lib)
target_link_directories(${PROJECT_NAME} PRIVATE lib/)

target_link_libraries(Vector_operations PUBLIC m) # Hamiltonian requires Vector_operations functionalites

target_link_libraries(Hamiltonian PUBLIC Vector_operations) # Hamiltonian requires Vector_operations functionalites

target_link_libraries(Runge_Kutta PUBLIC Hamiltonian Vector_operations) # Hamiltonian requires Vector_operations functionalites


target_link_libraries(NASA_data PUBLIC Hamiltonian Vector_operations)


target_link_libraries(${PROJECT_NAME} PUBLIC NASA_data Runge_Kutta  m)