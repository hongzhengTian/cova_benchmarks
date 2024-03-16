# Vivado_Script.tcl
# 设置项目名和输出目录
set project_name vivado_proj_vec_add
set output_dir ./output

# 创建新项目
create_project $project_name $output_dir -part xcu280-fsvh2892-2L-e -force
set_property board_part xilinx.com:u280:part0:1.0 [current_project]

# 导入Vitis HLS生成的IP
read_ip [glob $output_dir/$project_name/vec_add/solution1/impl/ip/*.xci]

# 添加设计源
# 如果有其他Verilog/VHDL源文件，也在这里添加
add_files -fileset sim_1 [glob ./src/*.v]

# 设置时钟约束
create_clock -period 5 -name clk [get_ports clk]

# 启动综合和实现
launch_runs synth_1 -jobs 8
wait_on_run synth_1

launch_runs impl_1 -to_step write_bitstream -jobs 8
wait_on_run impl_1

# 导出比特流和报告
export_design -format ip_catalog

# 关闭项目
close_project
