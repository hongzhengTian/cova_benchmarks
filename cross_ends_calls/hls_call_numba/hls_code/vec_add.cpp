// This is a HLS C++ example to do vector addition
#include <hls_stream.h>
#include <ap_axi_sdata.h>

typedef ap_axiu<32,1,1,1> AXI_VAL;

void vec_add(
  hls::stream<AXI_VAL> &in_stream1, 
  hls::stream<AXI_VAL> &in_stream2, 
  hls::stream<AXI_VAL> &out_stream, 
  int length
) {
#pragma HLS INTERFACE axis port=in_stream1
#pragma HLS INTERFACE axis port=in_stream2
#pragma HLS INTERFACE axis port=out_stream
#pragma HLS INTERFACE s_axilite port=return bundle=control

  for (int i = 0; i < length; i++) {
    AXI_VAL in1 = in_stream1.read();
    AXI_VAL in2 = in_stream2.read();
    AXI_VAL out;
    out.data = in1.data + in2.data;
    out_stream.write(out);
  }
}
