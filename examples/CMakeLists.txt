# Designate the executable(s)
add_executable(test_shape_visitor
    test_shape_visitor.cpp
)
add_executable(test_shape_strategy
    test_shape_strategy.cpp
)
add_executable(test_pound_a_peg
    test_pound_a_peg.cpp
)
target_compile_features(test_shape_visitor PRIVATE cxx_std_20)
target_compile_features(test_shape_strategy PRIVATE cxx_std_20)
target_compile_features(test_pound_a_peg PRIVATE cxx_std_20)

# Given my current folder structure, I need to provide where the include files are for the target
target_include_directories(test_shape_visitor 
    PRIVATE 
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
target_include_directories(test_shape_strategy 
    PRIVATE 
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
target_include_directories(test_pound_a_peg
    PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(test_shape_strategy
  fmt::fmt
)