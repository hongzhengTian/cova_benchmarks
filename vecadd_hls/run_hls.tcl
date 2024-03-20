 
open_project -reset pl_vecadd_alveo_u280_hls
set_top pl_vecadd
add_files pl_vecadd.cpp  -cflags "-std=c++0x"

open_solution -reset "solution1"
set_part {xcu280-fsvh2892-2L-e}
create_clock -period 200.0MHz

config_sdx -optimization_level none -target xocc
config_export -vivado_optimization_level 0 -vivado_phys_opt none
config_compile -name_max_length 256 -pipeline_loops 64
config_schedule -enable_dsp_full_reg

# csim_design

csynth_design
export_design -format xo -version "1.0" -output /home/hongzhet/myProjects/cova_benchmarks/cross_ends_calls/python_runtime/hls_code/pl_vecadd_alveo_u280.xo

exit
