# Designate the executable(s)
add_executable(test_shapes 
    test_shapes.cpp
)

target_compile_features(test_shapes PRIVATE cxx_std_20)

# Given my current folder structure, I need to provide where the include files are for the target
target_include_directories(test_shapes 
    PRIVATE 
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)