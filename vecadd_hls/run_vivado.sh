mkdir -p pl_vecadd_alveo_u280_vivado
cd pl_vecadd_alveo_u280_vivado
v++ -t hw --platform xilinx_u280_gen3x16_xdma_1_202211_1 --link ../pl_vecadd_alveo_u280.xo -o ../pl_vecadd_alveo_u280.xclbin
cd ..