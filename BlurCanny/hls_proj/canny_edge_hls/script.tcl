############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hls_proj_canny_edge
set_top canny_edge_top
add_files canny_edge.cpp
open_solution "solution1" -flow_target vivado
set_part {xczu9eg-ffvb1156-2-e}
create_clock -period 5 -name default
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
