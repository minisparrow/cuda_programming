    # CMakeLists.txt to build hellocuda.cu
cmake_minimum_required(VERSION 2.8)
find_package(CUDA QUIET REQUIRED)
find_package(OpenCV REQUIRED)
# collect source files
file( GLOB  hdr *.hpp *.h )
file( GLOB  cu  *.cu)
SET (HW1_files reference_main.cpp reference_calc.cpp HW1.cpp)

CUDA_ADD_EXECUTABLE(HW1 ${HW1_files} ${hdr} ${cu})
