############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project project_3
add_files hls/tut3A/matrix_mult.cpp
add_files hls/tut3A/matrix_mult.h
add_files -tb hls/tut3A/matrix_mult_test.cpp
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 5 -name default
#source "./project_3/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
