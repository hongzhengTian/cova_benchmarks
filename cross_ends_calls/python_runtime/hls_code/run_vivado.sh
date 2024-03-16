mkdir -p pl_vecadd_alveo_u250_vivado
cd pl_vecadd_alveo_u250_vivado
v++ -t hw --platform xilinx_u250_gen3x16_xdma_4_1_202210_1 --link ../pl_vecadd_alveo_u250.xo -o ../pl_vecadd_alveo_u250.xclbin
cd ..