
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

using namespace std;

void forward_node0(
  float v0[64],
  float v1[64][10],
  float v2[10],
  float v3[10]
) {	// L16
  #pragma HLS inline
  #pragma HLS array_partition variable=v0 cyclic factor=2 dim=1

  float v4[10];	// L17
  #pragma HLS resource variable=v4 core=ram_t2p_bram

  for (int v5 = 0; v5 < 8; v5 += 1) {	// L18
    for (int v6 = 0; v6 < 2; v6 += 1) {	// L19
      for (int v7 = 0; v7 < 8; v7 += 1) {	// L20
        for (int v8 = 0; v8 < 5; v8 += 1) {	// L21
          #pragma HLS pipeline II=1
          float v9 = v0[(v7 + (v5 * 8))];	// L22
          float v10 = v1[(v7 + (v5 * 8))][(v8 + (v6 * 5))];	// L23
          float v11 = v4[(v8 + (v6 * 5))];	// L24
          float v12 = v9 * v10;	// L25
          float v13 = v11 + v12;	// L26
          v4[(v8 + (v6 * 5))] = v13;	// L27
          float v14 = v2[(v8 + (v6 * 5))];	// L28
          float v15 = v13 + v14;	// L29
          if ((((-v7) + (v5 * -8)) + 63) == 0) {	// L30
            v3[(v8 + (v6 * 5))] = v15;	// L31
          }
        }
      }
    }
  }
}

void forward_node2(
  float v16[8][8],
  float v17[128],
  float v18[64],
  float v19[64],
  float v20[64],
  int v21,
  int v22
) {	// L39
  #pragma HLS inline
  #pragma HLS array_partition variable=v16 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v17 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v18 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v19 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v20 cyclic factor=2 dim=1

  for (int v23 = 0; v23 < 8; v23 += 1) {	// L41
    for (int v24 = 0; v24 < 8; v24 += 2) {	// L42
      #pragma HLS pipeline II=1
      float v25 = v17[(v23 + (v21 * 8))];	// L43
      float v26 = v16[v23][v24];	// L44
      float v27 = v20[(v24 + (v22 * 8))];	// L45
      float v28 = v25 * v26;	// L46
      float v29 = v27 + v28;	// L47
      v20[(v24 + (v22 * 8))] = v29;	// L48
      float v30 = v18[(v24 + (v22 * 8))];	// L49
      float v31 = v29 + v30;	// L50
      bool v32 = v31 > (float)0.000000;	// L51
      float v33 = v32 ? v31 : (float)0.000000;	// L52
      if ((((-v23) + (v21 * -8)) + 127) == 0) {	// L53
        v19[(v24 + (v22 * 8))] = v33;	// L54
      }
      float v34 = v16[v23][(v24 + 1)];	// L56
      float v35 = v20[((v24 + (v22 * 8)) + 1)];	// L57
      float v36 = v25 * v34;	// L58
      float v37 = v35 + v36;	// L59
      v20[((v24 + (v22 * 8)) + 1)] = v37;	// L60
      float v38 = v18[((v24 + (v22 * 8)) + 1)];	// L61
      float v39 = v37 + v38;	// L62
      bool v40 = v39 > (float)0.000000;	// L63
      float v41 = v40 ? v39 : (float)0.000000;	// L64
      if ((((-v23) + (v21 * -8)) + 127) == 0) {	// L65
        v19[((v24 + (v22 * 8)) + 1)] = v41;	// L66
      }
    }
  }
}

void forward_node3(
  float v42[128][64],
  float v43[8][8],
  int v44,
  int v45
) {	// L72
  #pragma HLS inline
  #pragma HLS array_partition variable=v43 cyclic factor=2 dim=2

  for (int v46 = 0; v46 < 8; v46 += 1) {	// L73
    for (int v47 = 0; v47 < 8; v47 += 2) {	// L74
      #pragma HLS pipeline II=1
      float v48 = v42[(v46 + (v44 * 8))][(v47 + (v45 * 8))];	// L75
      v43[v46][v47] = v48;	// L76
      float v49 = v42[(v46 + (v44 * 8))][((v47 + (v45 * 8)) + 1)];	// L77
      v43[v46][(v47 + 1)] = v49;	// L78
    }
  }
}

void forward_node1(
  float v50[64],
  float v51[128][64],
  float v52[128],
  float v53[64]
) {	// L83
  #pragma HLS array_partition variable=v50 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v52 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v53 cyclic factor=2 dim=1

  float v54[64];	// L84
  #pragma HLS array_partition variable=v54 cyclic factor=2 dim=1
  #pragma HLS resource variable=v54 core=ram_2p_lutram

  for (int v55 = 0; v55 < 128; v55 += 1) {	// L85
    #pragma HLS dataflow
    int v56 = (v55 % 8);	// L86
    int v57 = (v55 / 8);	// L87
    float v58[8][8];	// L88
    #pragma HLS array_partition variable=v58 cyclic factor=2 dim=2
    #pragma HLS resource variable=v58 core=ram_2p_lutram

    forward_node3(v51, v58, v57, v56);	// L89
    forward_node2(v58, v52, v50, v53, v54, v57, v56);	// L90
  }
}

void forward_node5(
  float v59[8][8],
  float v60[128],
  float v61[256],
  float v62[128],
  float v63[128],
  int v64,
  int v65
) {	// L94
  #pragma HLS inline
  #pragma HLS array_partition variable=v59 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v60 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v61 cyclic factor=4 dim=1

  #pragma HLS array_partition variable=v62 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v63 cyclic factor=2 dim=1

  for (int v66 = 0; v66 < 8; v66 += 1) {	// L96
    for (int v67 = 0; v67 < 8; v67 += 2) {	// L97
      #pragma HLS pipeline II=1
      float v68 = v61[(v66 + (v64 * 8))];	// L98
      float v69 = v59[v66][v67];	// L99
      float v70 = v62[(v67 + (v65 * 8))];	// L100
      float v71 = v68 * v69;	// L101
      float v72 = v70 + v71;	// L102
      v62[(v67 + (v65 * 8))] = v72;	// L103
      float v73 = v60[(v67 + (v65 * 8))];	// L104
      float v74 = v72 + v73;	// L105
      bool v75 = v74 > (float)0.000000;	// L106
      float v76 = v75 ? v74 : (float)0.000000;	// L107
      if ((((-v66) + (v64 * -8)) + 255) == 0) {	// L108
        v63[(v67 + (v65 * 8))] = v76;	// L109
      }
      float v77 = v59[v66][(v67 + 1)];	// L111
      float v78 = v62[((v67 + (v65 * 8)) + 1)];	// L112
      float v79 = v68 * v77;	// L113
      float v80 = v78 + v79;	// L114
      v62[((v67 + (v65 * 8)) + 1)] = v80;	// L115
      float v81 = v60[((v67 + (v65 * 8)) + 1)];	// L116
      float v82 = v80 + v81;	// L117
      bool v83 = v82 > (float)0.000000;	// L118
      float v84 = v83 ? v82 : (float)0.000000;	// L119
      if ((((-v66) + (v64 * -8)) + 255) == 0) {	// L120
        v63[((v67 + (v65 * 8)) + 1)] = v84;	// L121
      }
    }
  }
}

void forward_node6(
  float v85[256][128],
  float v86[8][8],
  int v87,
  int v88
) {	// L127
  #pragma HLS inline
  #pragma HLS array_partition variable=v86 cyclic factor=2 dim=2

  for (int v89 = 0; v89 < 8; v89 += 1) {	// L128
    for (int v90 = 0; v90 < 8; v90 += 2) {	// L129
      #pragma HLS pipeline II=1
      float v91 = v85[(v89 + (v87 * 8))][(v90 + (v88 * 8))];	// L130
      v86[v89][v90] = v91;	// L131
      float v92 = v85[(v89 + (v87 * 8))][((v90 + (v88 * 8)) + 1)];	// L132
      v86[v89][(v90 + 1)] = v92;	// L133
    }
  }
}

void forward_node4(
  float v93[128],
  float v94[256][128],
  float v95[256],
  float v96[128]
) {	// L138
  #pragma HLS array_partition variable=v93 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v95 cyclic factor=4 dim=1

  #pragma HLS array_partition variable=v96 cyclic factor=2 dim=1

  float v97[128];	// L139
  #pragma HLS array_partition variable=v97 cyclic factor=2 dim=1
  #pragma HLS resource variable=v97 core=ram_2p_lutram

  for (int v98 = 0; v98 < 512; v98 += 1) {	// L140
    #pragma HLS dataflow
    int v99 = (v98 % 16);	// L141
    int v100 = (v98 / 16);	// L142
    float v101[8][8];	// L143
    #pragma HLS array_partition variable=v101 cyclic factor=2 dim=2
    #pragma HLS resource variable=v101 core=ram_2p_lutram

    forward_node6(v94, v101, v100, v99);	// L144
    forward_node5(v101, v93, v95, v97, v96, v100, v99);	// L145
  }
}

void forward_node8(
  float v102[8][8],
  float v103[256],
  float v104[512],
  float v105[256],
  float v106[256],
  int v107,
  int v108
) {	// L149
  #pragma HLS inline
  #pragma HLS array_partition variable=v102 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v102 cyclic factor=4 dim=2

  #pragma HLS array_partition variable=v103 cyclic factor=4 dim=1

  #pragma HLS array_partition variable=v104 cyclic factor=8 dim=1

  #pragma HLS array_partition variable=v105 cyclic factor=4 dim=1

  #pragma HLS array_partition variable=v106 cyclic factor=4 dim=1

  for (int v109 = 0; v109 < 8; v109 += 1) {	// L151
    for (int v110 = 0; v110 < 8; v110 += 4) {	// L152
      #pragma HLS pipeline II=1
      float v111 = v104[(v109 + (v107 * 8))];	// L153
      float v112 = v102[v109][v110];	// L154
      float v113 = v105[(v110 + (v108 * 8))];	// L155
      float v114 = v111 * v112;	// L156
      float v115 = v113 + v114;	// L157
      v105[(v110 + (v108 * 8))] = v115;	// L158
      float v116 = v103[(v110 + (v108 * 8))];	// L159
      float v117 = v115 + v116;	// L160
      bool v118 = v117 > (float)0.000000;	// L161
      float v119 = v118 ? v117 : (float)0.000000;	// L162
      if ((((-v109) + (v107 * -8)) + 511) == 0) {	// L163
        v106[(v110 + (v108 * 8))] = v119;	// L164
      }
      float v120 = v102[v109][(v110 + 1)];	// L166
      float v121 = v105[((v110 + (v108 * 8)) + 1)];	// L167
      float v122 = v111 * v120;	// L168
      float v123 = v121 + v122;	// L169
      v105[((v110 + (v108 * 8)) + 1)] = v123;	// L170
      float v124 = v103[((v110 + (v108 * 8)) + 1)];	// L171
      float v125 = v123 + v124;	// L172
      bool v126 = v125 > (float)0.000000;	// L173
      float v127 = v126 ? v125 : (float)0.000000;	// L174
      if ((((-v109) + (v107 * -8)) + 511) == 0) {	// L175
        v106[((v110 + (v108 * 8)) + 1)] = v127;	// L176
      }
      float v128 = v102[v109][(v110 + 2)];	// L178
      float v129 = v105[((v110 + (v108 * 8)) + 2)];	// L179
      float v130 = v111 * v128;	// L180
      float v131 = v129 + v130;	// L181
      v105[((v110 + (v108 * 8)) + 2)] = v131;	// L182
      float v132 = v103[((v110 + (v108 * 8)) + 2)];	// L183
      float v133 = v131 + v132;	// L184
      bool v134 = v133 > (float)0.000000;	// L185
      float v135 = v134 ? v133 : (float)0.000000;	// L186
      if ((((-v109) + (v107 * -8)) + 511) == 0) {	// L187
        v106[((v110 + (v108 * 8)) + 2)] = v135;	// L188
      }
      float v136 = v102[v109][(v110 + 3)];	// L190
      float v137 = v105[((v110 + (v108 * 8)) + 3)];	// L191
      float v138 = v111 * v136;	// L192
      float v139 = v137 + v138;	// L193
      v105[((v110 + (v108 * 8)) + 3)] = v139;	// L194
      float v140 = v103[((v110 + (v108 * 8)) + 3)];	// L195
      float v141 = v139 + v140;	// L196
      bool v142 = v141 > (float)0.000000;	// L197
      float v143 = v142 ? v141 : (float)0.000000;	// L198
      if ((((-v109) + (v107 * -8)) + 511) == 0) {	// L199
        v106[((v110 + (v108 * 8)) + 3)] = v143;	// L200
      }
    }
  }
}

void forward_node9(
  float v144[512][256],
  float v145[8][8],
  int v146,
  int v147
) {	// L206
  #pragma HLS inline
  #pragma HLS array_partition variable=v145 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v145 cyclic factor=4 dim=2

  for (int v148 = 0; v148 < 8; v148 += 2) {	// L207
    for (int v149 = 0; v149 < 8; v149 += 2) {	// L208
      #pragma HLS pipeline II=1
      float v150 = v144[(v148 + (v146 * 8))][(v149 + (v147 * 8))];	// L209
      v145[v148][v149] = v150;	// L210
      float v151 = v144[(v148 + (v146 * 8))][((v149 + (v147 * 8)) + 1)];	// L211
      v145[v148][(v149 + 1)] = v151;	// L212
      float v152 = v144[((v148 + (v146 * 8)) + 1)][(v149 + (v147 * 8))];	// L213
      v145[(v148 + 1)][v149] = v152;	// L214
      float v153 = v144[((v148 + (v146 * 8)) + 1)][((v149 + (v147 * 8)) + 1)];	// L215
      v145[(v148 + 1)][(v149 + 1)] = v153;	// L216
    }
  }
}

void forward_node7(
  float v154[512][256],
  float v155[256],
  float v156[512],
  float v157[256]
) {	// L221
  #pragma HLS array_partition variable=v155 cyclic factor=4 dim=1

  #pragma HLS array_partition variable=v156 cyclic factor=8 dim=1

  #pragma HLS array_partition variable=v157 cyclic factor=4 dim=1

  float v158[256];	// L222
  #pragma HLS array_partition variable=v158 cyclic factor=4 dim=1
  #pragma HLS resource variable=v158 core=ram_2p_lutram

  for (int v159 = 0; v159 < 2048; v159 += 1) {	// L223
    #pragma HLS dataflow
    int v160 = (v159 % 32);	// L224
    int v161 = (v159 / 32);	// L225
    float v162[8][8];	// L226
    #pragma HLS array_partition variable=v162 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v162 cyclic factor=4 dim=2
    #pragma HLS resource variable=v162 core=ram_2p_lutram

    forward_node9(v154, v162, v161, v160);	// L227
    forward_node8(v162, v155, v156, v158, v157, v161, v160);	// L228
  }
}

void forward_node11(
  float v163[8][8],
  float v164[28][28],
  float v165[512],
  float v166[512],
  float v167[512],
  int v168,
  int v169
) {	// L232
  #pragma HLS inline
  #pragma HLS array_partition variable=v163 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v163 cyclic factor=8 dim=2

  #pragma HLS array_partition variable=v165 cyclic factor=8 dim=1

  #pragma HLS array_partition variable=v166 cyclic factor=8 dim=1

  #pragma HLS array_partition variable=v167 cyclic factor=8 dim=1

  for (int v170 = 0; v170 < 8; v170 += 1) {	// L234
    #pragma HLS pipeline II=1
    float v171 = v164[(((v170 + (v168 * 8)) % 784) / 28)][((v170 + (v168 * 8)) % 28)];	// L235
    float v172 = v163[v170][0];	// L236
    float v173 = v167[(v169 * 8)];	// L237
    float v174 = v171 * v172;	// L238
    float v175 = v173 + v174;	// L239
    v167[(v169 * 8)] = v175;	// L240
    float v176 = v165[(v169 * 8)];	// L241
    float v177 = v175 + v176;	// L242
    bool v178 = v177 > (float)0.000000;	// L243
    float v179 = v178 ? v177 : (float)0.000000;	// L244
    if ((((-v170) + (v168 * -8)) + 783) == 0) {	// L245
      v166[(v169 * 8)] = v179;	// L246
    }
    float v180 = v163[v170][1];	// L248
    float v181 = v167[((v169 * 8) + 1)];	// L249
    float v182 = v171 * v180;	// L250
    float v183 = v181 + v182;	// L251
    v167[((v169 * 8) + 1)] = v183;	// L252
    float v184 = v165[((v169 * 8) + 1)];	// L253
    float v185 = v183 + v184;	// L254
    bool v186 = v185 > (float)0.000000;	// L255
    float v187 = v186 ? v185 : (float)0.000000;	// L256
    if ((((-v170) + (v168 * -8)) + 783) == 0) {	// L257
      v166[((v169 * 8) + 1)] = v187;	// L258
    }
    float v188 = v163[v170][2];	// L260
    float v189 = v167[((v169 * 8) + 2)];	// L261
    float v190 = v171 * v188;	// L262
    float v191 = v189 + v190;	// L263
    v167[((v169 * 8) + 2)] = v191;	// L264
    float v192 = v165[((v169 * 8) + 2)];	// L265
    float v193 = v191 + v192;	// L266
    bool v194 = v193 > (float)0.000000;	// L267
    float v195 = v194 ? v193 : (float)0.000000;	// L268
    if ((((-v170) + (v168 * -8)) + 783) == 0) {	// L269
      v166[((v169 * 8) + 2)] = v195;	// L270
    }
    float v196 = v163[v170][3];	// L272
    float v197 = v167[((v169 * 8) + 3)];	// L273
    float v198 = v171 * v196;	// L274
    float v199 = v197 + v198;	// L275
    v167[((v169 * 8) + 3)] = v199;	// L276
    float v200 = v165[((v169 * 8) + 3)];	// L277
    float v201 = v199 + v200;	// L278
    bool v202 = v201 > (float)0.000000;	// L279
    float v203 = v202 ? v201 : (float)0.000000;	// L280
    if ((((-v170) + (v168 * -8)) + 783) == 0) {	// L281
      v166[((v169 * 8) + 3)] = v203;	// L282
    }
    float v204 = v163[v170][4];	// L284
    float v205 = v167[((v169 * 8) + 4)];	// L285
    float v206 = v171 * v204;	// L286
    float v207 = v205 + v206;	// L287
    v167[((v169 * 8) + 4)] = v207;	// L288
    float v208 = v165[((v169 * 8) + 4)];	// L289
    float v209 = v207 + v208;	// L290
    bool v210 = v209 > (float)0.000000;	// L291
    float v211 = v210 ? v209 : (float)0.000000;	// L292
    if ((((-v170) + (v168 * -8)) + 783) == 0) {	// L293
      v166[((v169 * 8) + 4)] = v211;	// L294
    }
    float v212 = v163[v170][5];	// L296
    float v213 = v167[((v169 * 8) + 5)];	// L297
    float v214 = v171 * v212;	// L298
    float v215 = v213 + v214;	// L299
    v167[((v169 * 8) + 5)] = v215;	// L300
    float v216 = v165[((v169 * 8) + 5)];	// L301
    float v217 = v215 + v216;	// L302
    bool v218 = v217 > (float)0.000000;	// L303
    float v219 = v218 ? v217 : (float)0.000000;	// L304
    if ((((-v170) + (v168 * -8)) + 783) == 0) {	// L305
      v166[((v169 * 8) + 5)] = v219;	// L306
    }
    float v220 = v163[v170][6];	// L308
    float v221 = v167[((v169 * 8) + 6)];	// L309
    float v222 = v171 * v220;	// L310
    float v223 = v221 + v222;	// L311
    v167[((v169 * 8) + 6)] = v223;	// L312
    float v224 = v165[((v169 * 8) + 6)];	// L313
    float v225 = v223 + v224;	// L314
    bool v226 = v225 > (float)0.000000;	// L315
    float v227 = v226 ? v225 : (float)0.000000;	// L316
    if ((((-v170) + (v168 * -8)) + 783) == 0) {	// L317
      v166[((v169 * 8) + 6)] = v227;	// L318
    }
    float v228 = v163[v170][7];	// L320
    float v229 = v167[((v169 * 8) + 7)];	// L321
    float v230 = v171 * v228;	// L322
    float v231 = v229 + v230;	// L323
    v167[((v169 * 8) + 7)] = v231;	// L324
    float v232 = v165[((v169 * 8) + 7)];	// L325
    float v233 = v231 + v232;	// L326
    bool v234 = v233 > (float)0.000000;	// L327
    float v235 = v234 ? v233 : (float)0.000000;	// L328
    if ((((-v170) + (v168 * -8)) + 783) == 0) {	// L329
      v166[((v169 * 8) + 7)] = v235;	// L330
    }
  }
}

void forward_node12(
  float v236[784][512],
  float v237[8][8],
  int v238,
  int v239
) {	// L335
  #pragma HLS inline
  #pragma HLS array_partition variable=v237 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v237 cyclic factor=8 dim=2

  for (int v240 = 0; v240 < 8; v240 += 2) {	// L336
    for (int v241 = 0; v241 < 8; v241 += 4) {	// L337
      #pragma HLS pipeline II=1
      float v242 = v236[(v240 + (v238 * 8))][(v241 + (v239 * 8))];	// L338
      v237[v240][v241] = v242;	// L339
      float v243 = v236[(v240 + (v238 * 8))][((v241 + (v239 * 8)) + 1)];	// L340
      v237[v240][(v241 + 1)] = v243;	// L341
      float v244 = v236[(v240 + (v238 * 8))][((v241 + (v239 * 8)) + 2)];	// L342
      v237[v240][(v241 + 2)] = v244;	// L343
      float v245 = v236[(v240 + (v238 * 8))][((v241 + (v239 * 8)) + 3)];	// L344
      v237[v240][(v241 + 3)] = v245;	// L345
      float v246 = v236[((v240 + (v238 * 8)) + 1)][(v241 + (v239 * 8))];	// L346
      v237[(v240 + 1)][v241] = v246;	// L347
      float v247 = v236[((v240 + (v238 * 8)) + 1)][((v241 + (v239 * 8)) + 1)];	// L348
      v237[(v240 + 1)][(v241 + 1)] = v247;	// L349
      float v248 = v236[((v240 + (v238 * 8)) + 1)][((v241 + (v239 * 8)) + 2)];	// L350
      v237[(v240 + 1)][(v241 + 2)] = v248;	// L351
      float v249 = v236[((v240 + (v238 * 8)) + 1)][((v241 + (v239 * 8)) + 3)];	// L352
      v237[(v240 + 1)][(v241 + 3)] = v249;	// L353
    }
  }
}

void forward_node10(
  float v250[512],
  float v251[784][512],
  float v252[28][28],
  float v253[512]
) {	// L358
  #pragma HLS array_partition variable=v250 cyclic factor=8 dim=1

  #pragma HLS array_partition variable=v253 cyclic factor=8 dim=1

  float v254[512];	// L359
  #pragma HLS array_partition variable=v254 cyclic factor=8 dim=1
  #pragma HLS resource variable=v254 core=ram_2p_lutram

  for (int v255 = 0; v255 < 6272; v255 += 1) {	// L360
    #pragma HLS dataflow
    int v256 = (v255 % 64);	// L361
    int v257 = (v255 / 64);	// L362
    float v258[8][8];	// L363
    #pragma HLS array_partition variable=v258 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v258 cyclic factor=8 dim=2
    #pragma HLS resource variable=v258 core=ram_2p_lutram

    forward_node12(v251, v258, v257, v256);	// L364
    forward_node11(v258, v252, v250, v253, v254, v257, v256);	// L365
  }
}

/// This is top function.
void forward(
  float v259[28][28],
  float v260[10],
  float v261[784][512],
  float v262[512][256],
  float v263[256][128],
  float v264[128][64]
) {	// L369
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS dataflow

  #pragma HLS interface m_axi offset=slave port=v264 bundle=axi_5

  #pragma HLS interface m_axi offset=slave port=v263 bundle=axi_4

  #pragma HLS interface m_axi offset=slave port=v262 bundle=axi_3

  #pragma HLS interface m_axi offset=slave port=v261 bundle=axi_2

  #pragma HLS interface bram storage_type=ram_t2p storage_impl=bram port=v260 bundle=axi_1

  #pragma HLS interface bram storage_type=ram_t2p storage_impl=bram port=v259 bundle=axi_0

  float v271[512] = {(float)0.004582, (float)-0.007698, (float)-0.002763, (float)0.025873, (float)-0.012661, (float)-0.000470, (float)0.025041, (float)-0.017044, (float)-0.022128, (float)-0.022345, (float)-0.027030, (float)0.015402, (float)-0.025259, (float)-0.023050, (float)0.026089, (float)0.034964, (float)-0.005767, (float)-0.011514, (float)0.032174, (float)0.028097, (float)0.004916, (float)-0.012107, (float)0.006354, (float)0.023497, (float)-0.013130, (float)0.016154, (float)-0.028381, (float)0.002840, (float)-0.022644, (float)0.032191, (float)-0.017333, (float)-0.018570, (float)0.014672, (float)-0.001246, (float)-0.021424, (float)-0.032394, (float)0.027825, (float)0.000970, (float)-0.013326, (float)-0.016509, (float)0.035632, (float)0.005675, (float)0.006289, (float)-0.003581, (float)-0.029069, (float)-0.031188, (float)-0.031182, (float)-0.022417, (float)-0.002035, (float)0.008091, (float)0.032901, (float)0.034959, (float)0.002164, (float)-0.014223, (float)0.018431, (float)-0.034929, (float)0.000613, (float)0.017186, (float)-0.020662, (float)0.002756, (float)-0.016128, (float)-0.007309, (float)0.009458, (float)-0.003465, (float)-0.016709, (float)0.001064, (float)0.028952, (float)-0.011557, (float)0.018674, (float)0.009357, (float)0.033731, (float)-0.030868, (float)-0.011977, (float)0.003760, (float)-0.030481, (float)-0.028924, (float)-0.012566, (float)0.023900, (float)-0.021779, (float)0.008321, (float)-0.005536, (float)-0.027038, (float)0.008413, (float)0.016572, (float)-0.031882, (float)-0.008084, (float)-0.025676, (float)0.036315, (float)-0.012950, (float)0.024750, (float)0.030555, (float)-0.028433, (float)-0.032449, (float)0.025830, (float)0.013140, (float)0.028142, (float)-0.030300, (float)-0.011079, (float)-0.005103, (float)0.032883, (float)-0.014207, (float)0.004248, (float)0.013480, (float)0.000429, (float)-0.000103, (float)0.035151, (float)-0.003268, (float)0.020937, (float)0.008108, (float)0.001777, (float)-0.016116, (float)-0.008159, (float)-0.034390, (float)0.034895, (float)-0.024932, (float)0.010738, (float)0.036037, (float)-0.023830, (float)-0.014114, (float)0.006812, (float)0.024504, (float)0.013608, (float)0.029553, (float)-0.026838, (float)-0.006977, (float)0.030702, (float)-0.023357, (float)0.009767, (float)0.032947, (float)0.005540, (float)-0.010562, (float)-0.004906, (float)-0.002879, (float)-0.017815, (float)0.029460, (float)0.030104, (float)0.034873, (float)0.032631, (float)-0.007888, (float)-0.007530, (float)0.007670, (float)0.007005, (float)-0.014534, (float)-0.010897, (float)-0.018809, (float)0.009740, (float)0.022662, (float)-0.032941, (float)0.023299, (float)-0.020362, (float)0.029789, (float)0.007604, (float)-0.023130, (float)-0.027501, (float)-0.009785, (float)-0.004210, (float)-0.006283, (float)-0.033090, (float)0.014613, (float)-0.025040, (float)0.014116, (float)-0.008976, (float)-0.022867, (float)-0.017093, (float)-0.006481, (float)0.012512, (float)-0.031400, (float)-0.036674, (float)-0.019132, (float)0.023058, (float)-0.027597, (float)0.005844, (float)0.025389, (float)-0.018669, (float)0.032513, (float)0.023603, (float)-0.021330, (float)0.019864, (float)0.034535, (float)0.034024, (float)-0.008722, (float)-0.009583, (float)-0.024508, (float)-0.004997, (float)0.008590, (float)0.031554, (float)0.034075, (float)-0.002908, (float)-0.034636, (float)-0.026605, (float)0.033471, (float)-0.004128, (float)0.006546, (float)0.023118, (float)0.019110, (float)0.005507, (float)0.015441, (float)-0.019094, (float)-0.025672, (float)-0.027632, (float)0.004731, (float)0.022299, (float)0.008224, (float)-0.034165, (float)0.018494, (float)0.030853, (float)-0.030002, (float)0.005845, (float)-0.015427, (float)0.008834, (float)0.023988, (float)-0.011245, (float)0.010680, (float)0.009318, (float)0.002083, (float)-0.021524, (float)0.030270, (float)0.003045, (float)0.014880, (float)-0.002487, (float)-0.034257, (float)-0.009091, (float)0.016238, (float)0.026484, (float)-0.006692, (float)0.008720, (float)0.026938, (float)0.034688, (float)-0.034733, (float)-0.027439, (float)0.035344, (float)-0.021108, (float)0.035122, (float)0.030809, (float)-0.005370, (float)0.012553, (float)0.026158, (float)0.038052, (float)-0.013897, (float)0.009931, (float)0.014280, (float)0.017744, (float)0.013508, (float)-0.030743, (float)-0.021031, (float)-0.010509, (float)-0.030991, (float)0.013231, (float)0.012191, (float)-0.024274, (float)-0.028481, (float)0.031547, (float)0.022330, (float)0.011675, (float)-0.010070, (float)-0.021913, (float)0.008116, (float)0.000134, (float)0.023187, (float)-0.029054, (float)0.031673, (float)-0.013302, (float)-0.027956, (float)-0.007277, (float)-0.001921, (float)-0.003352, (float)0.028511, (float)0.006952, (float)0.006781, (float)0.005629, (float)0.025477, (float)0.014581, (float)-0.000641, (float)0.023335, (float)0.013888, (float)0.014137, (float)0.017846, (float)-0.014265, (float)-0.031900, (float)0.028878, (float)0.035626, (float)0.024455, (float)0.015091, (float)0.024620, (float)0.011465, (float)-0.005992, (float)-0.030283, (float)-0.000763, (float)0.003997, (float)0.000570, (float)0.029648, (float)-0.007406, (float)0.003653, (float)0.031877, (float)-0.033693, (float)0.013565, (float)-0.006161, (float)-0.031470, (float)-0.001086, (float)-0.028035, (float)-0.017777, (float)-0.018619, (float)0.000297, (float)0.009630, (float)0.006106, (float)-0.023182, (float)0.024436, (float)0.018628, (float)0.027876, (float)-0.033257, (float)-0.001353, (float)-0.030169, (float)0.012590, (float)-0.019889, (float)0.022987, (float)0.008788, (float)-0.028935, (float)-0.021743, (float)0.029349, (float)0.001475, (float)0.011559, (float)-0.014452, (float)0.016132, (float)0.023247, (float)0.029419, (float)-0.006039, (float)-0.026586, (float)-0.018758, (float)-0.032157, (float)-0.008199, (float)0.023571, (float)-0.017416, (float)-0.031579, (float)0.035299, (float)-0.018127, (float)-0.016069, (float)-0.033532, (float)-0.029251, (float)-0.034470, (float)-0.032931, (float)-0.020421, (float)0.032329, (float)-0.021537, (float)-0.008108, (float)0.017854, (float)-0.030320, (float)-0.003609, (float)-0.029961, (float)0.006058, (float)0.000128, (float)0.014783, (float)-0.034626, (float)0.002139, (float)0.009254, (float)0.024295, (float)0.023359, (float)0.028985, (float)0.036546, (float)-0.017838, (float)0.003792, (float)-0.015606, (float)-0.024146, (float)0.021451, (float)0.025780, (float)0.012789, (float)0.019206, (float)0.023550, (float)0.017257, (float)0.023219, (float)-0.011015, (float)-0.032591, (float)-0.000643, (float)-0.017392, (float)-0.024575, (float)0.019111, (float)0.008441, (float)-0.014008, (float)0.034271, (float)-0.028637, (float)-0.007675, (float)0.005872, (float)0.004377, (float)-0.005313, (float)-0.006514, (float)-0.002832, (float)0.021572, (float)0.002154, (float)0.013891, (float)-0.004519, (float)0.009297, (float)0.013983, (float)0.023181, (float)0.023012, (float)0.028048, (float)0.026516, (float)0.011521, (float)-0.021416, (float)-0.025365, (float)-0.025089, (float)-0.013048, (float)-0.025673, (float)0.007242, (float)0.020668, (float)-0.007187, (float)-0.010313, (float)-0.000415, (float)0.011702, (float)-0.006398, (float)-0.003803, (float)-0.000011, (float)0.027384, (float)-0.010187, (float)-0.003406, (float)-0.027415, (float)0.005434, (float)0.008551, (float)-0.001519, (float)-0.008949, (float)0.006955, (float)0.008586, (float)-0.009764, (float)0.026599, (float)-0.023870, (float)0.002023, (float)-0.017533, (float)-0.013931, (float)0.034040, (float)-0.000421, (float)-0.018021, (float)-0.027323, (float)-0.008489, (float)-0.017383, (float)-0.003224, (float)0.007901, (float)0.025717, (float)-0.032809, (float)-0.003386, (float)0.034133, (float)0.021669, (float)0.028968, (float)0.033339, (float)-0.019648, (float)0.021067, (float)-0.027040, (float)-0.021325, (float)-0.011191, (float)0.015086, (float)-0.024348, (float)0.012935, (float)0.032483, (float)-0.005123, (float)0.029695, (float)-0.031749, (float)0.033233, (float)-0.009436, (float)0.014842, (float)0.025354, (float)0.012291, (float)0.022208, (float)0.029208, (float)0.016333, (float)-0.012798, (float)0.009555, (float)-0.007537, (float)-0.017857, (float)-0.013800, (float)-0.034741, (float)0.030903, (float)0.034852, (float)-0.027560, (float)0.027331, (float)0.028889, (float)0.003679, (float)-0.023112, (float)0.021069, (float)0.030465, (float)0.027185, (float)0.014027, (float)-0.027607, (float)0.007998, (float)0.006417, (float)0.007095, (float)-0.018950, (float)-0.012976, (float)-0.020142, (float)-0.002347, (float)0.024631, (float)0.024799, (float)0.034577, (float)0.019066, (float)0.020595, (float)-0.029089, (float)-0.032165, (float)-0.030430, (float)0.013359, (float)0.016003, (float)-0.006772, (float)0.020067, (float)-0.019250, (float)0.022215, (float)0.031967, (float)-0.027574, (float)0.001738, (float)-0.018042, (float)-0.004413, (float)0.003986, (float)0.001332, (float)0.005284, (float)-0.001264, (float)-0.012127, (float)0.022409, (float)0.022149};	// L382
  #pragma HLS array_partition variable=v271 cyclic factor=8 dim=1
  #pragma HLS resource variable=v271 core=ram_2p_lutram

  float v272[256] = {(float)-0.022629, (float)-0.021402, (float)0.025388, (float)0.035952, (float)0.016995, (float)0.019777, (float)-0.008517, (float)-0.000761, (float)-0.027349, (float)-0.019121, (float)0.023547, (float)-0.026929, (float)-0.000873, (float)-0.039948, (float)-0.035336, (float)0.037931, (float)0.042872, (float)-0.028444, (float)0.031807, (float)-0.029134, (float)-0.001806, (float)-0.032759, (float)0.023935, (float)0.005656, (float)0.015775, (float)0.007522, (float)0.034773, (float)0.028569, (float)-0.043976, (float)0.012770, (float)-0.040407, (float)0.044864, (float)0.001891, (float)-0.019187, (float)0.008878, (float)-0.013641, (float)-0.012622, (float)-0.027074, (float)0.014640, (float)0.037513, (float)-0.042433, (float)-0.007378, (float)0.028351, (float)0.023373, (float)-0.041632, (float)-0.045027, (float)-0.027553, (float)0.002183, (float)0.000795, (float)0.011177, (float)-0.033057, (float)0.008154, (float)0.007265, (float)-0.009837, (float)-0.037415, (float)-0.018727, (float)0.013411, (float)0.004109, (float)-0.014296, (float)0.042815, (float)0.024752, (float)0.021207, (float)-0.013650, (float)0.006501, (float)-0.012842, (float)0.037665, (float)0.041544, (float)0.038582, (float)-0.043514, (float)-0.015910, (float)-0.022622, (float)0.036408, (float)0.025763, (float)0.034014, (float)0.013620, (float)0.014578, (float)-0.008341, (float)0.027303, (float)0.011402, (float)0.022472, (float)-0.011715, (float)0.008842, (float)-0.016189, (float)0.030328, (float)-0.024717, (float)-0.005060, (float)0.024940, (float)-0.034978, (float)0.003700, (float)0.013879, (float)0.024865, (float)0.004373, (float)0.043471, (float)0.010778, (float)0.047809, (float)-0.029974, (float)-0.025508, (float)-0.024693, (float)-0.001657, (float)0.003306, (float)0.000320, (float)-0.043546, (float)0.046203, (float)0.034440, (float)0.041251, (float)0.001794, (float)0.006722, (float)0.042210, (float)-0.019459, (float)0.023744, (float)-0.028694, (float)-0.023673, (float)0.017767, (float)-0.027573, (float)-0.026426, (float)-0.021075, (float)-0.017014, (float)-0.008083, (float)-0.033545, (float)-0.034889, (float)0.035996, (float)0.030800, (float)-0.015008, (float)-0.018037, (float)-0.006920, (float)-0.018294, (float)0.019320, (float)-0.000178, (float)0.045752, (float)-0.019930, (float)-0.007518, (float)-0.013967, (float)0.027986, (float)-0.014006, (float)0.035033, (float)0.003607, (float)-0.011811, (float)-0.003993, (float)-0.015090, (float)0.035495, (float)-0.042677, (float)0.039689, (float)-0.003031, (float)-0.023988, (float)0.012293, (float)0.031122, (float)0.035907, (float)-0.023709, (float)0.008078, (float)-0.030632, (float)0.037079, (float)-0.013522, (float)0.012672, (float)0.040230, (float)-0.013599, (float)-0.007787, (float)0.010620, (float)0.015355, (float)-0.026991, (float)0.042849, (float)0.007050, (float)-0.026710, (float)-0.023238, (float)-0.010670, (float)0.026625, (float)0.035929, (float)-0.009901, (float)0.014591, (float)-0.030475, (float)0.011458, (float)-0.019932, (float)0.047231, (float)-0.033219, (float)-0.012796, (float)-0.029738, (float)0.020439, (float)-0.026938, (float)0.010662, (float)-0.029374, (float)-0.031894, (float)0.024971, (float)0.009766, (float)-0.006801, (float)-0.010636, (float)0.038826, (float)-0.010656, (float)0.032335, (float)0.027868, (float)0.001483, (float)-0.007019, (float)0.023109, (float)0.033876, (float)0.033285, (float)0.027787, (float)-0.026221, (float)-0.042157, (float)-0.004940, (float)0.041294, (float)-0.030386, (float)-0.001082, (float)0.022753, (float)-0.015224, (float)-0.003183, (float)0.011792, (float)0.017535, (float)0.013499, (float)-0.036770, (float)0.046600, (float)0.036435, (float)0.024006, (float)-0.010624, (float)-0.041885, (float)0.030375, (float)-0.010847, (float)0.016107, (float)0.004642, (float)0.004311, (float)0.003532, (float)-0.029102, (float)-0.024299, (float)-0.040737, (float)-0.010624, (float)-0.023938, (float)0.037086, (float)-0.008845, (float)-0.022881, (float)0.004771, (float)0.045411, (float)-0.035774, (float)-0.041766, (float)-0.017037, (float)-0.004794, (float)-0.029851, (float)0.013792, (float)-0.034669, (float)-0.016442, (float)0.003891, (float)-0.001948, (float)0.005768, (float)-0.037017, (float)-0.033114, (float)-0.021145, (float)0.029133, (float)0.022923, (float)-0.015659, (float)-0.016866, (float)-0.022250, (float)0.031115, (float)0.027845, (float)0.019365, (float)-0.025623, (float)0.033580, (float)0.044393, (float)-0.034773, (float)0.010953, (float)0.023118};	// L383
  #pragma HLS array_partition variable=v272 cyclic factor=4 dim=1
  #pragma HLS resource variable=v272 core=ram_2p_lutram

  float v273[128] = {(float)-0.043639, (float)0.004348, (float)0.044298, (float)-0.000856, (float)0.020359, (float)-0.063866, (float)0.000164, (float)0.049653, (float)-0.030394, (float)0.058873, (float)-0.048871, (float)-0.051707, (float)0.008698, (float)-0.061677, (float)-0.031370, (float)0.012889, (float)-0.027997, (float)0.047787, (float)0.059241, (float)-0.052803, (float)-0.005252, (float)-0.015415, (float)-0.019190, (float)0.014838, (float)-0.034421, (float)-0.015342, (float)0.017300, (float)-0.013314, (float)0.067965, (float)0.042292, (float)-0.044672, (float)0.024552, (float)-0.029089, (float)0.053610, (float)-0.007664, (float)0.000141, (float)0.007832, (float)0.009695, (float)0.018306, (float)-0.045055, (float)0.043529, (float)-0.024279, (float)0.015134, (float)-0.025492, (float)-0.025415, (float)-0.028073, (float)-0.009497, (float)-0.044938, (float)-0.021516, (float)-0.007159, (float)0.054672, (float)0.015835, (float)-0.061822, (float)0.069001, (float)-0.016806, (float)-0.044310, (float)0.060772, (float)0.060410, (float)0.022983, (float)0.059461, (float)-0.054550, (float)0.005220, (float)-0.040858, (float)-0.058015, (float)0.060291, (float)0.064306, (float)0.019023, (float)-0.042027, (float)0.011386, (float)-0.049338, (float)0.013654, (float)-0.003531, (float)-0.011400, (float)0.009516, (float)-0.031863, (float)0.007620, (float)-0.062886, (float)0.032245, (float)0.037255, (float)-0.052767, (float)-0.021558, (float)-0.035773, (float)-0.032216, (float)-0.047181, (float)0.021347, (float)0.060865, (float)0.030398, (float)0.001842, (float)0.029364, (float)-0.042015, (float)0.022690, (float)-0.040558, (float)0.002723, (float)0.056438, (float)0.029452, (float)0.045854, (float)0.014557, (float)-0.035279, (float)0.063022, (float)0.028641, (float)0.066244, (float)-0.046010, (float)0.057443, (float)0.013649, (float)0.055397, (float)0.057453, (float)-0.060015, (float)0.066068, (float)-0.006655, (float)0.014852, (float)0.009973, (float)0.062705, (float)-0.021591, (float)-0.021680, (float)0.057743, (float)-0.063525, (float)0.030972, (float)0.042783, (float)0.070859, (float)-0.035890, (float)0.016719, (float)0.033539, (float)0.026378, (float)0.031870, (float)0.054748, (float)-0.022700, (float)0.016006, (float)0.001197};	// L384
  #pragma HLS array_partition variable=v273 cyclic factor=2 dim=1
  #pragma HLS resource variable=v273 core=ram_2p_lutram

  float v274[64] = {(float)0.070070, (float)-0.018526, (float)-0.016878, (float)-0.032265, (float)-0.044199, (float)-0.049352, (float)0.070142, (float)0.017621, (float)-0.058272, (float)0.070949, (float)-0.057323, (float)0.070470, (float)0.113124, (float)0.096452, (float)-0.012923, (float)-0.029109, (float)-0.061242, (float)0.039802, (float)-0.077773, (float)0.105755, (float)0.102567, (float)-0.021639, (float)-0.088081, (float)0.083582, (float)0.033520, (float)0.115723, (float)0.101117, (float)0.080142, (float)-0.073019, (float)-0.074369, (float)0.087162, (float)0.080676, (float)-0.012306, (float)0.115469, (float)0.066489, (float)-0.070672, (float)-0.005709, (float)0.010401, (float)-0.060227, (float)-0.035394, (float)-0.009371, (float)0.026535, (float)0.124855, (float)-0.056761, (float)0.002799, (float)0.035932, (float)0.077916, (float)-0.058129, (float)-0.029174, (float)-0.076766, (float)-0.083014, (float)0.040504, (float)-0.073816, (float)0.095833, (float)-0.009010, (float)0.013385, (float)-0.034498, (float)0.043327, (float)-0.026855, (float)-0.003851, (float)-0.043590, (float)-0.047906, (float)0.098214, (float)0.037988};	// L385
  #pragma HLS array_partition variable=v274 cyclic factor=2 dim=1
  #pragma HLS resource variable=v274 core=ram_2p_lutram

  float v275[10] = {(float)-0.053619, (float)-0.041749, (float)-0.044107, (float)0.146601, (float)-0.024145, (float)0.091943, (float)-0.060371, (float)0.050150, (float)0.054833, (float)0.030319};	// L386
  #pragma HLS resource variable=v275 core=ram_t2p_bram

  float v276[64][10] = {(float)0.034616, (float)0.062773, (float)-0.142267, (float)0.029997, (float)-0.044752, (float)-0.058961, (float)0.049614, (float)0.066438, (float)0.005857, (float)0.028664, (float)0.109575, (float)-0.175401, (float)-0.003635, (float)0.164481, (float)0.097827, (float)0.029165, (float)0.197137, (float)0.109451, (float)-0.257669, (float)-0.201223, (float)-0.083808, (float)0.072737, (float)0.061915, (float)-0.080591, (float)-0.110000, (float)0.069702, (float)0.120681, (float)-0.036544, (float)0.095196, (float)0.088496, (float)0.114469, (float)0.008062, (float)0.100620, (float)-0.276089, (float)0.141467, (float)-0.047199, (float)-0.008614, (float)0.039663, (float)-0.099679, (float)-0.122449, (float)-0.053095, (float)-0.013864, (float)0.035605, (float)-0.047617, (float)0.082492, (float)-0.089326, (float)-0.029935, (float)0.014181, (float)-0.007124, (float)0.081058, (float)0.027816, (float)0.105738, (float)0.018234, (float)0.021011, (float)-0.052038, (float)-0.103746, (float)-0.088813, (float)0.077454, (float)0.065366, (float)-0.051778, (float)-0.211977, (float)0.283957, (float)0.162999, (float)0.019644, (float)-0.248803, (float)0.011580, (float)-0.110706, (float)0.032960, (float)0.079646, (float)-0.212377, (float)0.122528, (float)-0.117807, (float)-0.030294, (float)-0.231134, (float)0.088814, (float)-0.012095, (float)-0.001860, (float)-0.103128, (float)-0.135114, (float)-0.083044, (float)-0.129194, (float)-0.095472, (float)-0.192293, (float)0.040362, (float)0.107356, (float)-0.117889, (float)-0.072722, (float)0.185815, (float)0.017264, (float)0.253455, (float)0.021134, (float)0.099415, (float)0.109514, (float)-0.059808, (float)-0.052403, (float)0.020767, (float)-0.216336, (float)0.249660, (float)0.044312, (float)-0.024403, (float)0.069548, (float)-0.091619, (float)0.218551, (float)0.194804, (float)-0.271504, (float)-0.144895, (float)-0.143512, (float)-0.033022, (float)0.146018, (float)0.039176, (float)-0.039966, (float)-0.158129, (float)0.130807, (float)-0.056773, (float)-0.142904, (float)0.188081, (float)0.226625, (float)-0.166450, (float)0.101002, (float)-0.043824, (float)0.099803, (float)0.143178, (float)-0.117459, (float)-0.058731, (float)-0.228770, (float)0.263972, (float)-0.152848, (float)0.032277, (float)0.023146, (float)0.085247, (float)0.237480, (float)-0.235995, (float)-0.087504, (float)0.154539, (float)-0.001858, (float)0.003807, (float)0.229773, (float)-0.281975, (float)-0.009375, (float)0.083717, (float)-0.003694, (float)-0.098767, (float)-0.189034, (float)-0.197421, (float)0.075962, (float)0.180427, (float)-0.176941, (float)-0.170004, (float)-0.042641, (float)-0.036674, (float)-0.052745, (float)0.012124, (float)0.106393, (float)0.039062, (float)-0.106264, (float)-0.193184, (float)-0.044747, (float)0.250780, (float)0.015743, (float)0.098289, (float)0.006326, (float)-0.122569, (float)0.028838, (float)-0.093431, (float)0.064317, (float)-0.025531, (float)0.092168, (float)0.067841, (float)0.039034, (float)-0.097613, (float)-0.252031, (float)0.124015, (float)0.192299, (float)-0.114943, (float)0.142708, (float)-0.195783, (float)-0.244782, (float)0.255278, (float)0.101850, (float)-0.020497, (float)-0.119222, (float)0.108212, (float)0.020571, (float)0.103163, (float)0.030265, (float)0.052724, (float)-0.033942, (float)0.116654, (float)-0.097139, (float)-0.070706, (float)-0.006584, (float)-0.048109, (float)-0.169767, (float)0.269910, (float)-0.272994, (float)0.081883, (float)-0.332238, (float)0.229333, (float)-0.109143, (float)0.038270, (float)0.123677, (float)-0.178064, (float)0.296764, (float)0.154712, (float)-0.309480, (float)-0.121828, (float)-0.106920, (float)-0.088855, (float)0.029227, (float)-0.025470, (float)-0.114582, (float)-0.025255, (float)-0.088669, (float)-0.061602, (float)0.040086, (float)-0.076219, (float)-0.075990, (float)0.108036, (float)0.034306, (float)0.073863, (float)-0.021983, (float)0.067514, (float)-0.102966, (float)-0.041903, (float)-0.041277, (float)0.111647, (float)-0.066218, (float)-0.034069, (float)0.007811, (float)-0.149916, (float)0.321300, (float)-0.193047, (float)0.255965, (float)0.106456, (float)-0.184381, (float)-0.052002, (float)-0.029248, (float)0.077441, (float)-0.017581, (float)-0.165093, (float)-0.056850, (float)-0.115396, (float)0.073987, (float)-0.174148, (float)0.182964, (float)-0.001128, (float)0.047572, (float)-0.047565, (float)-0.002940, (float)0.222137, (float)0.287028, (float)-0.422192, (float)-0.086022, (float)-0.182797, (float)0.054121, (float)0.051241, (float)0.196548, (float)-0.099751, (float)0.191571, (float)-0.072771, (float)0.039551, (float)0.149890, (float)-0.175921, (float)0.082187, (float)0.173540, (float)0.067042, (float)-0.032559, (float)-0.164466, (float)0.181908, (float)0.199794, (float)-0.224628, (float)0.068084, (float)-0.016798, (float)-0.098375, (float)0.062304, (float)-0.252968, (float)0.159608, (float)0.119976, (float)0.000709, (float)0.186185, (float)-0.174171, (float)-0.042901, (float)0.004510, (float)-0.000896, (float)0.025352, (float)0.056449, (float)-0.186286, (float)-0.136780, (float)0.105029, (float)-0.054722, (float)-0.086225, (float)-0.112532, (float)-0.014712, (float)0.005622, (float)-0.124873, (float)-0.038471, (float)-0.122918, (float)0.006209, (float)0.035934, (float)-0.142004, (float)-0.190609, (float)0.219418, (float)-0.071464, (float)0.257383, (float)-0.246253, (float)0.108190, (float)-0.265925, (float)-0.039478, (float)-0.069907, (float)-0.021075, (float)-0.232986, (float)0.222419, (float)0.257119, (float)0.091202, (float)0.088956, (float)-0.080452, (float)0.232589, (float)-0.066533, (float)-0.178240, (float)-0.182722, (float)0.002190, (float)0.272854, (float)-0.114031, (float)-0.187337, (float)0.057469, (float)0.012568, (float)0.163112, (float)-0.097135, (float)0.084468, (float)-0.181394, (float)0.106137, (float)-0.276649, (float)-0.235528, (float)0.002045, (float)-0.088433, (float)0.267514, (float)-0.234980, (float)-0.209021, (float)0.198205, (float)0.160004, (float)0.024336, (float)-0.131316, (float)0.074616, (float)-0.029801, (float)0.191448, (float)-0.163286, (float)-0.194731, (float)0.335142, (float)-0.228894, (float)0.165900, (float)0.103748, (float)0.065818, (float)-0.151895, (float)0.057343, (float)-0.092943, (float)0.102064, (float)-0.119506, (float)-0.114991, (float)0.121704, (float)-0.026891, (float)-0.110144, (float)0.039136, (float)0.107413, (float)-0.156058, (float)-0.030436, (float)-0.188774, (float)0.062754, (float)0.242922, (float)-0.211116, (float)0.063038, (float)-0.035757, (float)0.201329, (float)-0.039361, (float)0.046467, (float)0.080585, (float)-0.102162, (float)0.069839, (float)0.056120, (float)0.010877, (float)-0.091542, (float)0.119195, (float)0.045326, (float)0.083753, (float)0.008948, (float)-0.062667, (float)0.028166, (float)-0.083855, (float)-0.087185, (float)0.097184, (float)0.079967, (float)0.067780, (float)-0.307593, (float)-0.083045, (float)-0.150425, (float)0.080987, (float)-0.068748, (float)0.043739, (float)0.066861, (float)0.075661, (float)0.114388, (float)-0.038922, (float)-0.015913, (float)0.104205, (float)0.172558, (float)-0.014731, (float)-0.093015, (float)-0.085693, (float)-0.064035, (float)-0.132852, (float)0.101917, (float)-0.273601, (float)0.238662, (float)0.091198, (float)0.061822, (float)-0.130680, (float)0.143913, (float)-0.006424, (float)-0.136329, (float)0.288206, (float)-0.186896, (float)-0.137030, (float)-0.003087, (float)-0.180563, (float)0.061415, (float)0.068064, (float)-0.005525, (float)0.117175, (float)0.066552, (float)-0.060925, (float)0.185323, (float)-0.003948, (float)0.115630, (float)-0.013277, (float)-0.003739, (float)0.001500, (float)0.015789, (float)0.024227, (float)-0.112727, (float)0.076943, (float)-0.084510, (float)-0.092328, (float)0.012946, (float)0.036836, (float)-0.083306, (float)0.001407, (float)-0.036809, (float)0.090287, (float)0.199347, (float)0.144644, (float)-0.025751, (float)-0.138779, (float)0.031780, (float)0.056086, (float)-0.150347, (float)0.401278, (float)0.135496, (float)0.263103, (float)-0.359057, (float)-0.102619, (float)0.035993, (float)-0.084821, (float)0.156459, (float)0.023808, (float)0.149092, (float)-0.087362, (float)0.210416, (float)-0.003674, (float)-0.234605, (float)0.170744, (float)-0.138068, (float)0.025612, (float)0.092272, (float)0.052811, (float)-0.036729, (float)0.051703, (float)0.095299, (float)-0.114976, (float)0.112670, (float)-0.045587, (float)-0.035535, (float)-0.146634, (float)-0.005772, (float)-0.097746, (float)0.000423, (float)0.310302, (float)0.164578, (float)-0.328961, (float)0.146790, (float)-0.225742, (float)0.224484, (float)0.074121, (float)-0.024935, (float)-0.095771, (float)0.104125, (float)0.112368, (float)0.003469, (float)-0.034886, (float)-0.051109, (float)0.053163, (float)-0.083099, (float)0.059062, (float)-0.030036, (float)-0.118318, (float)0.051646, (float)0.116344, (float)0.099749, (float)-0.091267, (float)-0.078891, (float)0.002421, (float)-0.123834, (float)0.326570, (float)-0.043280, (float)0.269639, (float)-0.225929, (float)-0.051761, (float)-0.145687, (float)-0.028039, (float)-0.101812, (float)0.013906, (float)-0.103034, (float)-0.173843, (float)0.008992, (float)-0.079489, (float)-0.040648, (float)0.050558, (float)-0.004734, (float)0.052319, (float)-0.103735, (float)0.195856, (float)0.051210, (float)-0.051450, (float)0.035946, (float)-0.066253, (float)0.196703, (float)0.155802, (float)-0.137004, (float)0.028548, (float)-0.123680, (float)0.091609, (float)0.079331, (float)0.011746, (float)-0.107693, (float)0.108865, (float)0.077655, (float)-0.207150, (float)0.073278, (float)0.020240, (float)0.157931, (float)-0.129638, (float)-0.048574, (float)0.052198, (float)-0.275981, (float)0.068998, (float)0.044036, (float)0.086927, (float)0.219881, (float)0.133123, (float)0.218707, (float)-0.245758, (float)-0.175746, (float)-0.057482, (float)-0.060157, (float)0.124828, (float)-0.089041, (float)0.101538, (float)-0.096325, (float)-0.100237, (float)0.028578, (float)-0.048124, (float)0.042781, (float)-0.085296, (float)0.045408, (float)0.157455, (float)-0.124760, (float)-0.145661, (float)-0.180853, (float)0.110894, (float)-0.197850, (float)-0.012352, (float)0.092448, (float)-0.214797, (float)0.048042, (float)-0.030808, (float)0.322878, (float)0.047639, (float)-0.058985, (float)-0.148818, (float)-0.019007, (float)-0.068285, (float)0.015810, (float)-0.209942, (float)0.153591, (float)0.189109, (float)-0.135086, (float)0.195314, (float)0.010056, (float)0.307087, (float)-0.090217, (float)-0.022305, (float)-0.220598, (float)-0.072384, (float)0.137850, (float)-0.128159, (float)-0.090431, (float)0.094558, (float)0.019403, (float)-0.028642, (float)0.152877, (float)0.126791, (float)0.194065, (float)0.075719, (float)-0.053784, (float)0.109822, (float)-0.071905, (float)0.093671, (float)0.009112, (float)-0.019277, (float)0.097296, (float)0.063163, (float)-0.080484, (float)-0.114438, (float)-0.162309, (float)-0.210280, (float)-0.005384, (float)-0.011327, (float)-0.014532, (float)-0.000621, (float)0.007262, (float)0.294517, (float)0.177961, (float)0.074762, (float)0.080061, (float)-0.128672, (float)0.223870, (float)-0.043409, (float)0.291120, (float)0.121765, (float)-0.077732, (float)-0.278728, (float)-0.281649};	// L387
  #pragma HLS resource variable=v276 core=ram_t2p_bram

  float v277[512];	// L388
  #pragma HLS array_partition variable=v277 cyclic factor=8 dim=1
  #pragma HLS resource variable=v277 core=ram_2p_lutram

  forward_node10(v271, v261, v259, v277);	// L389
  float v278[256];	// L390
  #pragma HLS array_partition variable=v278 cyclic factor=4 dim=1
  #pragma HLS resource variable=v278 core=ram_2p_lutram

  forward_node7(v262, v272, v277, v278);	// L391
  float v279[128];	// L392
  #pragma HLS array_partition variable=v279 cyclic factor=2 dim=1
  #pragma HLS resource variable=v279 core=ram_2p_lutram

  forward_node4(v273, v263, v278, v279);	// L393
  float v280[64];	// L394
  #pragma HLS array_partition variable=v280 cyclic factor=2 dim=1
  #pragma HLS resource variable=v280 core=ram_2p_lutram

  forward_node1(v274, v264, v279, v280);	// L395
  forward_node0(v280, v276, v275, v260);	// L396
}

