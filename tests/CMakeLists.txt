package_add_test (voltlbx_test
                  test_cubic_spline.cpp
                  test_hyp_integral.cpp
                  test_linear_filter.cpp
                  test_optim.cpp
                  test_roots.cpp
                  test_utils.cpp				  
                  test_add.cpp)
target_compile_features(voltlbx_test PRIVATE cxx_std_17)
target_link_libraries (voltlbx_test VolTlbx)
