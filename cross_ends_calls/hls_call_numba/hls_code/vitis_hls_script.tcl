# Vitis_HLS_Script.tcl
set project_name hls_proj_vec_add
set top_function vec_add

open_project -reset $project_name
set_top $top_function
add_files vec_add.cpp

open_solution "solution1" -flow_target vivado
set_part {xcu280-fsvh2892-2L-e}
create_clock -period 5 -name default

#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog

close_project

# open_project hls_proj_vec_add
# set_top vec_add
# add_files vec_add.cpp
# open_solution "solution1" -flow_target vivado
# set_part {xcu280-fsvh2892-2L-e}
# create_clock -period 5 -name default
# #csim_design
# csynth_design
# #cosim_design
# export_design -format ip_catalog
