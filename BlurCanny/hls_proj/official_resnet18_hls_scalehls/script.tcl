############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hls_proj_official_resnet18
set_top forward
add_files resnet18_scalehls.cpp
open_solution "solution1" -flow_target vivado
set_part {xck26-sfvc784-2LV-C}
create_clock -period 5 -name default
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
