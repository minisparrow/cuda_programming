cmake_minimum_required(VERSION 2.8)
find_package(CUDA QUIET REQUIRED)
#=============================================
# Pass options to NVCC
set( CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; 
-g -G  -gencode arch=compute_50,code=sm_50
    -gencode arch=compute_60,code=sm_60
)
# Specify include directories
#=============================================

include_directories(
../common
)

#=============================================
# Specify library paths
#link_directories(
#) 

#=============================================
# For compilation ...
# Specify target & source files to compile it from
cuda_add_executable(
simpleDivergence
./simpleDivergence.cu
../common/common.h
)
#=============================================
# For linking ...
# Specify target & libraries to link it with
# target_link_libraries(
# )
#=============================================
