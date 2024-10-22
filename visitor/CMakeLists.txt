# Designate the executable(s)
add_executable(test_shape_visitor
    test_shape_visitor.cpp
)

target_compile_features(test_shape_visitor PRIVATE cxx_std_20)

add_executable(test_shape_visitor_variant
    test_shape_visitor_variant.cpp
)

target_compile_features(test_shape_visitor_variant PRIVATE cxx_std_20)


target_include_directories(test_shape_visitor 
    PRIVATE 
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
target_include_directories(test_shape_visitor_variant 
    PRIVATE 
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)