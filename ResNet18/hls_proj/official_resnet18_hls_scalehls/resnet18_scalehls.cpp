
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
#include <math.h>
#include <stdint.h>
#include <string.h>

using namespace std;

void forward_node1(
  float v0[8],
  float v1[1000],
  int v2
) {	// L56
  #pragma HLS inline
  #pragma HLS resource variable=v0 core=ram_t2p_bram

  for (int v3 = 0; v3 < 8; v3 += 1) {	// L57
    #pragma HLS pipeline II=1
    float v4 = v0[v3];	// L58
    v1[(v3 + (v2 * 8))] = v4;	// L59
  }
}

void forward_node2(
  float v5[512],
  float v6[8][8],
  float v7[1000],
  float v8[1000],
  float v9[8],
  int v10,
  int v11
) {	// L63
  #pragma HLS inline
  #pragma HLS resource variable=v5 core=ram_t2p_bram

  #pragma HLS resource variable=v6 core=ram_t2p_bram

  #pragma HLS resource variable=v7 core=ram_t2p_bram

  #pragma HLS resource variable=v8 core=ram_t2p_bram

  #pragma HLS resource variable=v9 core=ram_t2p_bram

  for (int v12 = 0; v12 < 8; v12 += 1) {	// L64
    for (int v13 = 0; v13 < 8; v13 += 1) {	// L65
      #pragma HLS pipeline II=1
      float v14 = v5[(v12 + (v10 * 8))];	// L66
      float v15 = v6[v12][v13];	// L67
      float v16 = v8[(v13 + (v11 * 8))];	// L68
      float v17 = v14 * v15;	// L69
      float v18 = v16 + v17;	// L70
      v8[(v13 + (v11 * 8))] = v18;	// L71
      float v19 = v7[(v13 + (v11 * 8))];	// L72
      float v20 = v18 + v19;	// L73
      if ((((-v12) + (v10 * -8)) + 511) == 0) {	// L74
        v9[v13] = v20;	// L75
      }
    }
  }
}

void forward_node3(
  float v21[512][1000],
  float v22[8][8],
  int v23,
  int v24
) {	// L81
  #pragma HLS inline
  #pragma HLS resource variable=v22 core=ram_t2p_bram

  for (int v25 = 0; v25 < 8; v25 += 1) {	// L82
    for (int v26 = 0; v26 < 8; v26 += 1) {	// L83
      #pragma HLS pipeline II=1
      float v27 = v21[(v25 + (v23 * 8))][(v26 + (v24 * 8))];	// L84
      v22[v25][v26] = v27;	// L85
    }
  }
}

void forward_node0(
  float v28[512][1000],
  float v29[512],
  float v30[1000],
  float v31[1000]
) {	// L90
  #pragma HLS resource variable=v29 core=ram_t2p_bram

  #pragma HLS resource variable=v30 core=ram_t2p_bram

  float v32[1000];	// L91
  #pragma HLS resource variable=v32 core=ram_t2p_bram

  for (int v33 = 0; v33 < 8000; v33 += 1) {	// L92
    #pragma HLS dataflow
    int v34 = (v33 % 125);	// L93
    int v35 = (v33 / 125);	// L94
    float v36[8];	// L95
    #pragma HLS resource variable=v36 core=ram_t2p_bram

    float v37[8][8];	// L96
    #pragma HLS resource variable=v37 core=ram_t2p_bram

    forward_node3(v28, v37, v35, v34);	// L97
    forward_node2(v29, v37, v30, v32, v36, v35, v34);	// L98
    forward_node1(v36, v31, v34);	// L99
  }
}

void forward_node5(
  float v38[8],
  float v39[512],
  int v40,
  int v41,
  int v42
) {	// L103
  #pragma HLS inline
  #pragma HLS resource variable=v38 core=ram_t2p_bram

  #pragma HLS resource variable=v39 core=ram_t2p_bram

  for (int v43 = 0; v43 < 8; v43 += 1) {	// L105
    #pragma HLS pipeline II=1
    float v44 = v38[v43];	// L106
    float v45 = v39[(v43 + (v40 * 8))];	// L107
    float v46 = v45 + v44;	// L108
    float v47 = v46 / (float)49.000000;	// L109
    float v48 = (((-v41) + 6) == 0 && ((-v42) + 6) == 0) ? v47 : v46;	// L110
    v39[(v43 + (v40 * 8))] = v48;	// L111
  }
}

void forward_node6(
  float v49[512][7][7],
  float v50[8],
  int v51,
  int v52,
  int v53
) {	// L115
  #pragma HLS inline
  #pragma HLS resource variable=v50 core=ram_t2p_bram

  for (int v54 = 0; v54 < 8; v54 += 1) {	// L116
    #pragma HLS pipeline II=1
    float v55 = v49[(v54 + (v53 * 8))][v51][v52];	// L117
    v50[v54] = v55;	// L118
  }
}

void forward_node4(
  float v56[512][7][7],
  float v57[512]
) {	// L122
  #pragma HLS resource variable=v57 core=ram_t2p_bram

  for (int v58 = 0; v58 < 3136; v58 += 1) {	// L123
    #pragma HLS dataflow
    int v59 = (v58 % 64);	// L124
    int v60 = ((v58 / 64) % 7);	// L125
    int v61 = ((v58 / 64) / 7);	// L126
    float v62[8];	// L127
    #pragma HLS resource variable=v62 core=ram_t2p_bram

    forward_node6(v56, v62, v61, v60, v59);	// L128
    forward_node5(v62, v57, v59, v61, v60);	// L129
  }
}

void forward_node8(
  float v63[8],
  float v64[512][7][7],
  int v65,
  int v66,
  int v67
) {	// L133
  #pragma HLS inline
  #pragma HLS resource variable=v63 core=ram_t2p_bram

  for (int v68 = 0; v68 < 8; v68 += 1) {	// L134
    #pragma HLS pipeline II=1
    float v69 = v63[v68];	// L135
    v64[(v68 + (v67 * 8))][v65][v66] = v69;	// L136
  }
}

void forward_node9(
  float v70[8],
  float v71[512],
  float v72[512],
  float v73[8],
  float v74[512],
  float v75[512],
  float v76[8],
  int v77
) {	// L140
  #pragma HLS inline
  #pragma HLS resource variable=v70 core=ram_t2p_bram

  #pragma HLS resource variable=v71 core=ram_t2p_bram

  #pragma HLS resource variable=v72 core=ram_t2p_bram

  #pragma HLS resource variable=v73 core=ram_t2p_bram

  #pragma HLS resource variable=v74 core=ram_t2p_bram

  #pragma HLS resource variable=v75 core=ram_t2p_bram

  #pragma HLS resource variable=v76 core=ram_t2p_bram

  for (int v78 = 0; v78 < 8; v78 += 1) {	// L143
    #pragma HLS pipeline II=1
    float v79 = v70[v78];	// L144
    float v80 = v74[(v78 + (v77 * 8))];	// L145
    float v81 = v71[(v78 + (v77 * 8))];	// L146
    float v82 = v75[(v78 + (v77 * 8))];	// L147
    float v83 = v72[(v78 + (v77 * 8))];	// L148
    float v84 = v73[v78];	// L149
    float v85 = (double)0.000010;	// L150
    float v86 = v83 + v85;	// L151
    float v87 = 1.0 / sqrt(v86);	// L152
    float v88 = v79 - v82;	// L153
    float v89 = v88 * v87;	// L154
    float v90 = v89 * v80;	// L155
    float v91 = v90 + v81;	// L156
    float v92 = v91 + v84;	// L157
    bool v93 = v92 > (float)0.000000;	// L158
    float v94 = v93 ? v92 : (float)0.000000;	// L159
    v76[v78] = v94;	// L160
  }
}

void forward_node10(
  float v95[512][7][7],
  float v96[8],
  int v97,
  int v98,
  int v99
) {	// L164
  #pragma HLS inline
  #pragma HLS resource variable=v96 core=ram_t2p_bram

  for (int v100 = 0; v100 < 8; v100 += 1) {	// L165
    #pragma HLS pipeline II=1
    float v101 = v95[(v100 + (v99 * 8))][v97][v98];	// L166
    v96[v100] = v101;	// L167
  }
}

void forward_node11(
  float v102[512][7][7],
  float v103[8],
  int v104,
  int v105,
  int v106
) {	// L171
  #pragma HLS inline
  #pragma HLS resource variable=v103 core=ram_t2p_bram

  for (int v107 = 0; v107 < 8; v107 += 1) {	// L172
    #pragma HLS pipeline II=1
    float v108 = v102[(v107 + (v106 * 8))][v104][v105];	// L173
    v103[v107] = v108;	// L174
  }
}

void forward_node7(
  float v109[512],
  float v110[512],
  float v111[512],
  float v112[512][7][7],
  float v113[512],
  float v114[512][7][7],
  float v115[512][7][7]
) {	// L178
  #pragma HLS resource variable=v109 core=ram_t2p_bram

  #pragma HLS resource variable=v110 core=ram_t2p_bram

  #pragma HLS resource variable=v111 core=ram_t2p_bram

  #pragma HLS resource variable=v113 core=ram_t2p_bram

  for (int v116 = 0; v116 < 3136; v116 += 1) {	// L179
    #pragma HLS dataflow
    int v117 = (v116 % 7);	// L180
    int v118 = ((v116 / 7) % 7);	// L181
    int v119 = ((v116 / 7) / 7);	// L182
    float v120[8];	// L183
    #pragma HLS resource variable=v120 core=ram_t2p_bram

    float v121[8];	// L184
    #pragma HLS resource variable=v121 core=ram_t2p_bram

    float v122[8];	// L185
    #pragma HLS resource variable=v122 core=ram_t2p_bram

    forward_node11(v112, v122, v118, v117, v119);	// L186
    forward_node10(v114, v121, v118, v117, v119);	// L187
    forward_node9(v122, v110, v113, v121, v109, v111, v120, v119);	// L188
    forward_node8(v120, v115, v118, v117, v119);	// L189
  }
}

void forward_node13(
  float v123[8],
  float v124[512][7][7],
  int v125,
  int v126,
  int v127
) {	// L193
  #pragma HLS inline
  #pragma HLS array_partition variable=v123 cyclic factor=2 dim=1
  #pragma HLS resource variable=v123 core=ram_t2p_bram

  #pragma HLS array_partition variable=v124 cyclic factor=2 dim=1

  for (int v128 = 0; v128 < 8; v128 += 2) {	// L194
    #pragma HLS pipeline II=1
    float v129 = v123[v128];	// L195
    v124[(v128 + (v127 * 8))][v125][v126] = v129;	// L196
    float v130 = v123[(v128 + 1)];	// L197
    v124[((v128 + (v127 * 8)) + 1)][v125][v126] = v130;	// L198
  }
}

void forward_node14(
  float v131[8],
  float v132[8][8],
  float v133[8],
  float v134[8]
) {	// L202
  #pragma HLS inline
  #pragma HLS array_partition variable=v131 cyclic factor=2 dim=1
  #pragma HLS resource variable=v131 core=ram_t2p_bram

  #pragma HLS array_partition variable=v132 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v132 cyclic factor=2 dim=2
  #pragma HLS resource variable=v132 core=ram_t2p_bram

  #pragma HLS array_partition variable=v133 cyclic factor=2 dim=1
  #pragma HLS resource variable=v133 core=ram_t2p_bram

  #pragma HLS array_partition variable=v134 cyclic factor=2 dim=1
  #pragma HLS resource variable=v134 core=ram_t2p_bram

  for (int v135 = 0; v135 < 8; v135 += 2) {	// L203
    for (int v136 = 0; v136 < 8; v136 += 2) {	// L204
      #pragma HLS pipeline II=1
      float v137 = v131[v135];	// L205
      float v138 = v132[v136][v135];	// L206
      float v139 = v133[v136];	// L207
      float v140 = v134[v136];	// L208
      float v141 = (v135 == 0) ? v139 : v140;	// L209
      float v142 = v137 * v138;	// L210
      float v143 = v141 + v142;	// L211
      float v144 = v132[(v136 + 1)][v135];	// L212
      float v145 = v133[(v136 + 1)];	// L213
      float v146 = v134[(v136 + 1)];	// L214
      float v147 = (v135 == 0) ? v145 : v146;	// L215
      float v148 = v137 * v144;	// L216
      float v149 = v147 + v148;	// L217
      int v150 = (v135 + 1);	// L218
      float v151 = v131[(v135 + 1)];	// L219
      float v152 = v132[v136][(v135 + 1)];	// L220
      float v153 = (v150 == 0) ? v139 : v143;	// L221
      float v154 = v151 * v152;	// L222
      float v155 = v153 + v154;	// L223
      v134[v136] = v155;	// L224
      float v156 = v132[(v136 + 1)][(v135 + 1)];	// L225
      float v157 = (v150 == 0) ? v145 : v149;	// L226
      float v158 = v151 * v156;	// L227
      float v159 = v157 + v158;	// L228
      v134[(v136 + 1)] = v159;	// L229
    }
  }
}

void forward_node15(
  float v160[512][7][7],
  float v161[8],
  int v162,
  int v163,
  int v164
) {	// L234
  #pragma HLS inline
  #pragma HLS array_partition variable=v160 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v161 cyclic factor=2 dim=1
  #pragma HLS resource variable=v161 core=ram_t2p_bram

  for (int v165 = 0; v165 < 8; v165 += 2) {	// L235
    #pragma HLS pipeline II=1
    float v166 = v160[(v165 + (v164 * 8))][v162][v163];	// L236
    v161[v165] = v166;	// L237
    float v167 = v160[((v165 + (v164 * 8)) + 1)][v162][v163];	// L238
    v161[(v165 + 1)] = v167;	// L239
  }
}

void forward_node16(
  float v168[512][512][3][3],
  float v169[8][8],
  int v170,
  int v171,
  int v172,
  int v173
) {	// L243
  #pragma HLS inline
  #pragma HLS array_partition variable=v168 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v168 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v169 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v169 cyclic factor=2 dim=2
  #pragma HLS resource variable=v169 core=ram_t2p_bram

  for (int v174 = 0; v174 < 8; v174 += 2) {	// L244
    for (int v175 = 0; v175 < 8; v175 += 2) {	// L245
      #pragma HLS pipeline II=1
      float v176 = v168[(v174 + (v172 * 8))][(v175 + (v173 * 8))][v170][v171];	// L246
      v169[v174][v175] = v176;	// L247
      float v177 = v168[(v174 + (v172 * 8))][((v175 + (v173 * 8)) + 1)][v170][v171];	// L248
      v169[v174][(v175 + 1)] = v177;	// L249
      float v178 = v168[((v174 + (v172 * 8)) + 1)][(v175 + (v173 * 8))][v170][v171];	// L250
      v169[(v174 + 1)][v175] = v178;	// L251
      float v179 = v168[((v174 + (v172 * 8)) + 1)][((v175 + (v173 * 8)) + 1)][v170][v171];	// L252
      v169[(v174 + 1)][(v175 + 1)] = v179;	// L253
    }
  }
}

void forward_node17(
  float v180[512][7][7],
  float v181[8],
  int v182,
  int v183,
  int v184,
  int v185,
  int v186
) {	// L258
  #pragma HLS inline
  #pragma HLS array_partition variable=v180 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v181 cyclic factor=2 dim=1
  #pragma HLS resource variable=v181 core=ram_t2p_bram

  for (int v187 = 0; v187 < 8; v187 += 2) {	// L259
    #pragma HLS pipeline II=1
    float v188 = v180[(v187 + (v182 * 8))][((v183 + v184) - 1)][((v185 + v186) - 1)];	// L260
    v181[v187] = v188;	// L261
    float v189 = v180[((v187 + (v182 * 8)) + 1)][((v183 + v184) - 1)][((v185 + v186) - 1)];	// L262
    v181[(v187 + 1)] = v189;	// L263
  }
}

void forward_node12(
  float v190[512][7][7],
  float v191[512][512][3][3],
  float v192[512][7][7],
  float v193[512][7][7]
) {	// L267
  #pragma HLS array_partition variable=v190 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v191 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v191 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v192 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v193 cyclic factor=2 dim=1

  for (int v194 = 0; v194 < 1806336; v194 += 1) {	// L268
    #pragma HLS dataflow
    int v195 = (v194 % 7);	// L269
    int v196 = ((v194 / 7) % 7);	// L270
    int v197 = (((v194 / 7) / 7) % 64);	// L271
    int v198 = ((((v194 / 7) / 7) / 64) % 3);	// L272
    int v199 = (((((v194 / 7) / 7) / 64) / 3) % 3);	// L273
    int v200 = (((((v194 / 7) / 7) / 64) / 3) / 3);	// L274
    float v201[8];	// L275
    #pragma HLS array_partition variable=v201 cyclic factor=2 dim=1
    #pragma HLS resource variable=v201 core=ram_t2p_bram

    float v202[8][8];	// L276
    #pragma HLS array_partition variable=v202 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v202 cyclic factor=2 dim=2
    #pragma HLS resource variable=v202 core=ram_t2p_bram

    float v203[8];	// L277
    #pragma HLS array_partition variable=v203 cyclic factor=2 dim=1
    #pragma HLS resource variable=v203 core=ram_t2p_bram

    forward_node17(v190, v203, v200, v196, v199, v195, v198);	// L278
    forward_node16(v191, v202, v199, v198, v197, v200);	// L279
    forward_node15(v192, v201, v196, v195, v197);	// L280
    float v204[8];	// L281
    #pragma HLS array_partition variable=v204 cyclic factor=2 dim=1
    #pragma HLS resource variable=v204 core=ram_t2p_bram

    forward_node14(v203, v202, v201, v204);	// L282
    forward_node13(v204, v193, v196, v195, v197);	// L283
  }
}

void forward_node19(
  float v205[8],
  float v206[512][7][7],
  int v207,
  int v208,
  int v209
) {	// L287
  #pragma HLS inline
  #pragma HLS resource variable=v205 core=ram_t2p_bram

  for (int v210 = 0; v210 < 8; v210 += 1) {	// L288
    #pragma HLS pipeline II=1
    float v211 = v205[v210];	// L289
    v206[(v210 + (v209 * 8))][v207][v208] = v211;	// L290
  }
}

void forward_node20(
  float v212[512],
  float v213[512],
  float v214[512],
  float v215[512],
  float v216[8],
  float v217[8],
  int v218
) {	// L294
  #pragma HLS inline
  #pragma HLS resource variable=v212 core=ram_t2p_bram

  #pragma HLS resource variable=v213 core=ram_t2p_bram

  #pragma HLS resource variable=v214 core=ram_t2p_bram

  #pragma HLS resource variable=v215 core=ram_t2p_bram

  #pragma HLS resource variable=v216 core=ram_t2p_bram

  #pragma HLS resource variable=v217 core=ram_t2p_bram

  for (int v219 = 0; v219 < 8; v219 += 1) {	// L297
    #pragma HLS pipeline II=1
    float v220 = v216[v219];	// L298
    float v221 = v213[(v219 + (v218 * 8))];	// L299
    float v222 = v215[(v219 + (v218 * 8))];	// L300
    float v223 = v214[(v219 + (v218 * 8))];	// L301
    float v224 = v212[(v219 + (v218 * 8))];	// L302
    float v225 = (double)0.000010;	// L303
    float v226 = v224 + v225;	// L304
    float v227 = 1.0 / sqrt(v226);	// L305
    float v228 = v220 - v223;	// L306
    float v229 = v228 * v227;	// L307
    float v230 = v229 * v221;	// L308
    float v231 = v230 + v222;	// L309
    bool v232 = v231 > (float)0.000000;	// L310
    float v233 = v232 ? v231 : (float)0.000000;	// L311
    v217[v219] = v233;	// L312
  }
}

void forward_node21(
  float v234[512][7][7],
  float v235[8],
  int v236,
  int v237,
  int v238
) {	// L316
  #pragma HLS inline
  #pragma HLS resource variable=v235 core=ram_t2p_bram

  for (int v239 = 0; v239 < 8; v239 += 1) {	// L317
    #pragma HLS pipeline II=1
    float v240 = v234[(v239 + (v238 * 8))][v236][v237];	// L318
    v235[v239] = v240;	// L319
  }
}

void forward_node18(
  float v241[512],
  float v242[512][7][7],
  float v243[512],
  float v244[512],
  float v245[512],
  float v246[512][7][7]
) {	// L323
  #pragma HLS resource variable=v241 core=ram_t2p_bram

  #pragma HLS resource variable=v243 core=ram_t2p_bram

  #pragma HLS resource variable=v244 core=ram_t2p_bram

  #pragma HLS resource variable=v245 core=ram_t2p_bram

  for (int v247 = 0; v247 < 3136; v247 += 1) {	// L324
    #pragma HLS dataflow
    int v248 = (v247 % 7);	// L325
    int v249 = ((v247 / 7) % 7);	// L326
    int v250 = ((v247 / 7) / 7);	// L327
    float v251[8];	// L328
    #pragma HLS resource variable=v251 core=ram_t2p_bram

    float v252[8];	// L329
    #pragma HLS resource variable=v252 core=ram_t2p_bram

    forward_node21(v242, v252, v249, v248, v250);	// L330
    forward_node20(v245, v244, v243, v241, v252, v251, v250);	// L331
    forward_node19(v251, v246, v249, v248, v250);	// L332
  }
}

void forward_node23(
  float v253[8],
  float v254[512][7][7],
  int v255,
  int v256,
  int v257
) {	// L336
  #pragma HLS inline
  #pragma HLS array_partition variable=v253 cyclic factor=2 dim=1
  #pragma HLS resource variable=v253 core=ram_t2p_bram

  #pragma HLS array_partition variable=v254 cyclic factor=2 dim=1

  for (int v258 = 0; v258 < 8; v258 += 2) {	// L337
    #pragma HLS pipeline II=1
    float v259 = v253[v258];	// L338
    v254[(v258 + (v257 * 8))][v255][v256] = v259;	// L339
    float v260 = v253[(v258 + 1)];	// L340
    v254[((v258 + (v257 * 8)) + 1)][v255][v256] = v260;	// L341
  }
}

void forward_node24(
  float v261[8],
  float v262[8],
  float v263[8][8],
  float v264[8],
  float v265[8],
  int v266,
  int v267,
  int v268
) {	// L345
  #pragma HLS inline
  #pragma HLS array_partition variable=v261 cyclic factor=2 dim=1
  #pragma HLS resource variable=v261 core=ram_t2p_bram

  #pragma HLS array_partition variable=v262 cyclic factor=2 dim=1
  #pragma HLS resource variable=v262 core=ram_t2p_bram

  #pragma HLS array_partition variable=v263 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v263 cyclic factor=2 dim=2
  #pragma HLS resource variable=v263 core=ram_t2p_bram

  #pragma HLS array_partition variable=v264 cyclic factor=2 dim=1
  #pragma HLS resource variable=v264 core=ram_t2p_bram

  #pragma HLS array_partition variable=v265 cyclic factor=2 dim=1
  #pragma HLS resource variable=v265 core=ram_t2p_bram

  for (int v269 = 0; v269 < 8; v269 += 2) {	// L346
    for (int v270 = 0; v270 < 8; v270 += 2) {	// L347
      #pragma HLS pipeline II=1
      float v271 = v261[v270];	// L348
      float v272 = v264[v270];	// L349
      float v273 = v265[v270];	// L350
      float v274 = (v269 == 0) ? v272 : v273;	// L351
      float v275 = ((v269 + (v268 * 8)) == 0 && v266 == 0 && v267 == 0) ? v271 : v274;	// L352
      float v276 = v262[v269];	// L353
      float v277 = v263[v270][v269];	// L354
      float v278 = v276 * v277;	// L355
      float v279 = v275 + v278;	// L356
      float v280 = v261[(v270 + 1)];	// L357
      float v281 = v264[(v270 + 1)];	// L358
      float v282 = v265[(v270 + 1)];	// L359
      float v283 = (v269 == 0) ? v281 : v282;	// L360
      float v284 = ((v269 + (v268 * 8)) == 0 && v266 == 0 && v267 == 0) ? v280 : v283;	// L361
      float v285 = v263[(v270 + 1)][v269];	// L362
      float v286 = v276 * v285;	// L363
      float v287 = v284 + v286;	// L364
      int v288 = (v269 + 1);	// L365
      float v289 = (v288 == 0) ? v272 : v279;	// L366
      float v290 = ((v288 + (v268 * 8)) == 0 && v266 == 0 && v267 == 0) ? v271 : v289;	// L367
      float v291 = v262[(v269 + 1)];	// L368
      float v292 = v263[v270][(v269 + 1)];	// L369
      float v293 = v291 * v292;	// L370
      float v294 = v290 + v293;	// L371
      v265[v270] = v294;	// L372
      float v295 = (v288 == 0) ? v281 : v287;	// L373
      float v296 = ((v288 + (v268 * 8)) == 0 && v266 == 0 && v267 == 0) ? v280 : v295;	// L374
      float v297 = v263[(v270 + 1)][(v269 + 1)];	// L375
      float v298 = v291 * v297;	// L376
      float v299 = v296 + v298;	// L377
      v265[(v270 + 1)] = v299;	// L378
    }
  }
}

void forward_node25(
  float v300[512][512][3][3],
  float v301[8][8],
  int v302,
  int v303,
  int v304,
  int v305
) {	// L383
  #pragma HLS inline
  #pragma HLS array_partition variable=v300 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v300 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v301 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v301 cyclic factor=2 dim=2
  #pragma HLS resource variable=v301 core=ram_t2p_bram

  for (int v306 = 0; v306 < 8; v306 += 2) {	// L384
    for (int v307 = 0; v307 < 8; v307 += 2) {	// L385
      #pragma HLS pipeline II=1
      float v308 = v300[(v306 + (v304 * 8))][(v307 + (v305 * 8))][v302][v303];	// L386
      v301[v306][v307] = v308;	// L387
      float v309 = v300[(v306 + (v304 * 8))][((v307 + (v305 * 8)) + 1)][v302][v303];	// L388
      v301[v306][(v307 + 1)] = v309;	// L389
      float v310 = v300[((v306 + (v304 * 8)) + 1)][(v307 + (v305 * 8))][v302][v303];	// L390
      v301[(v306 + 1)][v307] = v310;	// L391
      float v311 = v300[((v306 + (v304 * 8)) + 1)][((v307 + (v305 * 8)) + 1)][v302][v303];	// L392
      v301[(v306 + 1)][(v307 + 1)] = v311;	// L393
    }
  }
}

void forward_node26(
  float v312[512][7][7],
  float v313[8],
  int v314,
  int v315,
  int v316,
  int v317,
  int v318
) {	// L398
  #pragma HLS inline
  #pragma HLS array_partition variable=v312 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v313 cyclic factor=2 dim=1
  #pragma HLS resource variable=v313 core=ram_t2p_bram

  for (int v319 = 0; v319 < 8; v319 += 2) {	// L399
    #pragma HLS pipeline II=1
    float v320 = v312[(v319 + (v314 * 8))][((v315 + v316) - 1)][((v317 + v318) - 1)];	// L400
    v313[v319] = v320;	// L401
    float v321 = v312[((v319 + (v314 * 8)) + 1)][((v315 + v316) - 1)][((v317 + v318) - 1)];	// L402
    v313[(v319 + 1)] = v321;	// L403
  }
}

void forward_node27(
  float v322[512][7][7],
  float v323[8],
  int v324,
  int v325,
  int v326
) {	// L407
  #pragma HLS inline
  #pragma HLS array_partition variable=v322 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v323 cyclic factor=2 dim=1
  #pragma HLS resource variable=v323 core=ram_t2p_bram

  for (int v327 = 0; v327 < 8; v327 += 2) {	// L408
    #pragma HLS pipeline II=1
    float v328 = v322[(v327 + (v326 * 8))][v324][v325];	// L409
    v323[v327] = v328;	// L410
    float v329 = v322[((v327 + (v326 * 8)) + 1)][v324][v325];	// L411
    v323[(v327 + 1)] = v329;	// L412
  }
}

void forward_node28(
  float v330[512][7][7],
  float v331[8],
  int v332,
  int v333,
  int v334
) {	// L416
  #pragma HLS inline
  #pragma HLS array_partition variable=v330 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v331 cyclic factor=2 dim=1
  #pragma HLS resource variable=v331 core=ram_t2p_bram

  for (int v335 = 0; v335 < 8; v335 += 2) {	// L417
    #pragma HLS pipeline II=1
    float v336 = v330[(v335 + (v334 * 8))][v332][v333];	// L418
    v331[v335] = v336;	// L419
    float v337 = v330[((v335 + (v334 * 8)) + 1)][v332][v333];	// L420
    v331[(v335 + 1)] = v337;	// L421
  }
}

void forward_node22(
  float v338[512][7][7],
  float v339[512][7][7],
  float v340[512][512][3][3],
  float v341[512][7][7],
  float v342[512][7][7]
) {	// L425
  #pragma HLS array_partition variable=v338 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v339 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v340 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v340 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v341 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v342 cyclic factor=2 dim=1

  for (int v343 = 0; v343 < 1806336; v343 += 1) {	// L426
    #pragma HLS dataflow
    int v344 = (v343 % 7);	// L427
    int v345 = ((v343 / 7) % 7);	// L428
    int v346 = (((v343 / 7) / 7) % 64);	// L429
    int v347 = ((((v343 / 7) / 7) / 64) % 3);	// L430
    int v348 = (((((v343 / 7) / 7) / 64) / 3) % 3);	// L431
    int v349 = (((((v343 / 7) / 7) / 64) / 3) / 3);	// L432
    float v350[8][8];	// L433
    #pragma HLS array_partition variable=v350 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v350 cyclic factor=2 dim=2
    #pragma HLS resource variable=v350 core=ram_t2p_bram

    float v351[8];	// L434
    #pragma HLS array_partition variable=v351 cyclic factor=2 dim=1
    #pragma HLS resource variable=v351 core=ram_t2p_bram

    float v352[8];	// L435
    #pragma HLS array_partition variable=v352 cyclic factor=2 dim=1
    #pragma HLS resource variable=v352 core=ram_t2p_bram

    float v353[8];	// L436
    #pragma HLS array_partition variable=v353 cyclic factor=2 dim=1
    #pragma HLS resource variable=v353 core=ram_t2p_bram

    forward_node28(v338, v353, v345, v344, v346);	// L437
    forward_node27(v341, v352, v345, v344, v346);	// L438
    forward_node26(v339, v351, v349, v345, v348, v344, v347);	// L439
    forward_node25(v340, v350, v348, v347, v346, v349);	// L440
    float v354[8];	// L441
    #pragma HLS array_partition variable=v354 cyclic factor=2 dim=1
    #pragma HLS resource variable=v354 core=ram_t2p_bram

    forward_node24(v353, v351, v350, v352, v354, v348, v347, v349);	// L442
    forward_node23(v354, v342, v345, v344, v346);	// L443
  }
}

void forward_node30(
  float v355[8],
  float v356[512][7][7],
  int v357,
  int v358,
  int v359
) {	// L447
  #pragma HLS inline
  #pragma HLS resource variable=v355 core=ram_t2p_bram

  for (int v360 = 0; v360 < 8; v360 += 1) {	// L448
    #pragma HLS pipeline II=1
    float v361 = v355[v360];	// L449
    v356[(v360 + (v359 * 8))][v357][v358] = v361;	// L450
  }
}

void forward_node31(
  float v362[8],
  float v363[8],
  float v364[512],
  float v365[512],
  float v366[512],
  float v367[512],
  float v368[512],
  float v369[512],
  float v370[512],
  float v371[8],
  int v372
) {	// L454
  #pragma HLS inline
  #pragma HLS resource variable=v362 core=ram_t2p_bram

  #pragma HLS resource variable=v363 core=ram_t2p_bram

  #pragma HLS resource variable=v364 core=ram_t2p_bram

  #pragma HLS resource variable=v365 core=ram_t2p_bram

  #pragma HLS resource variable=v366 core=ram_t2p_bram

  #pragma HLS resource variable=v367 core=ram_t2p_bram

  #pragma HLS resource variable=v368 core=ram_t2p_bram

  #pragma HLS resource variable=v369 core=ram_t2p_bram

  #pragma HLS resource variable=v370 core=ram_t2p_bram

  #pragma HLS resource variable=v371 core=ram_t2p_bram

  for (int v373 = 0; v373 < 8; v373 += 1) {	// L457
    #pragma HLS pipeline II=1
    float v374 = v362[v373];	// L458
    float v375 = v366[(v373 + (v372 * 8))];	// L459
    float v376 = v368[(v373 + (v372 * 8))];	// L460
    float v377 = v367[(v373 + (v372 * 8))];	// L461
    float v378 = v370[(v373 + (v372 * 8))];	// L462
    float v379 = v363[v373];	// L463
    float v380 = v364[(v373 + (v372 * 8))];	// L464
    float v381 = v369[(v373 + (v372 * 8))];	// L465
    float v382 = v365[(v373 + (v372 * 8))];	// L466
    float v383 = (double)0.000010;	// L467
    float v384 = v382 + v383;	// L468
    float v385 = 1.0 / sqrt(v384);	// L469
    float v386 = v379 - v381;	// L470
    float v387 = v386 * v385;	// L471
    float v388 = v387 * v380;	// L472
    float v389 = v388 + v376;	// L473
    float v390 = v378 + v383;	// L474
    float v391 = 1.0 / sqrt(v390);	// L475
    float v392 = v374 - v377;	// L476
    float v393 = v392 * v391;	// L477
    float v394 = v393 * v375;	// L478
    float v395 = v394 + v376;	// L479
    float v396 = v395 + v389;	// L480
    bool v397 = v396 > (float)0.000000;	// L481
    float v398 = v397 ? v396 : (float)0.000000;	// L482
    v371[v373] = v398;	// L483
  }
}

void forward_node32(
  float v399[512][7][7],
  float v400[8],
  int v401,
  int v402,
  int v403
) {	// L487
  #pragma HLS inline
  #pragma HLS resource variable=v400 core=ram_t2p_bram

  for (int v404 = 0; v404 < 8; v404 += 1) {	// L488
    #pragma HLS pipeline II=1
    float v405 = v399[(v404 + (v403 * 8))][v401][v402];	// L489
    v400[v404] = v405;	// L490
  }
}

void forward_node33(
  float v406[512][7][7],
  float v407[8],
  int v408,
  int v409,
  int v410
) {	// L494
  #pragma HLS inline
  #pragma HLS resource variable=v407 core=ram_t2p_bram

  for (int v411 = 0; v411 < 8; v411 += 1) {	// L495
    #pragma HLS pipeline II=1
    float v412 = v406[(v411 + (v410 * 8))][v408][v409];	// L496
    v407[v411] = v412;	// L497
  }
}

void forward_node29(
  float v413[512],
  float v414[512],
  float v415[512],
  float v416[512],
  float v417[512][7][7],
  float v418[512],
  float v419[512][7][7],
  float v420[512],
  float v421[512],
  float v422[512][7][7]
) {	// L501
  #pragma HLS resource variable=v413 core=ram_t2p_bram

  #pragma HLS resource variable=v414 core=ram_t2p_bram

  #pragma HLS resource variable=v415 core=ram_t2p_bram

  #pragma HLS resource variable=v416 core=ram_t2p_bram

  #pragma HLS resource variable=v418 core=ram_t2p_bram

  #pragma HLS resource variable=v420 core=ram_t2p_bram

  #pragma HLS resource variable=v421 core=ram_t2p_bram

  for (int v423 = 0; v423 < 3136; v423 += 1) {	// L502
    #pragma HLS dataflow
    int v424 = (v423 % 7);	// L503
    int v425 = ((v423 / 7) % 7);	// L504
    int v426 = ((v423 / 7) / 7);	// L505
    float v427[8];	// L506
    #pragma HLS resource variable=v427 core=ram_t2p_bram

    float v428[8];	// L507
    #pragma HLS resource variable=v428 core=ram_t2p_bram

    float v429[8];	// L508
    #pragma HLS resource variable=v429 core=ram_t2p_bram

    forward_node33(v417, v429, v425, v424, v426);	// L509
    forward_node32(v419, v428, v425, v424, v426);	// L510
    forward_node31(v429, v428, v413, v414, v415, v416, v420, v421, v418, v427, v426);	// L511
    forward_node30(v427, v422, v425, v424, v426);	// L512
  }
}

void forward_node35(
  float v430[8],
  float v431[512][7][7],
  int v432,
  int v433,
  int v434
) {	// L516
  #pragma HLS inline
  #pragma HLS resource variable=v430 core=ram_t2p_bram

  for (int v435 = 0; v435 < 8; v435 += 1) {	// L517
    #pragma HLS pipeline II=1
    float v436 = v430[v435];	// L518
    v431[(v435 + (v434 * 8))][v432][v433] = v436;	// L519
  }
}

void forward_node36(
  float v437[8],
  float v438[8],
  float v439[8][8],
  float v440[8],
  float v441[8],
  int v442
) {	// L523
  #pragma HLS inline
  #pragma HLS resource variable=v437 core=ram_t2p_bram

  #pragma HLS resource variable=v438 core=ram_t2p_bram

  #pragma HLS resource variable=v439 core=ram_t2p_bram

  #pragma HLS resource variable=v440 core=ram_t2p_bram

  #pragma HLS resource variable=v441 core=ram_t2p_bram

  for (int v443 = 0; v443 < 8; v443 += 1) {	// L524
    for (int v444 = 0; v444 < 8; v444 += 1) {	// L525
      #pragma HLS pipeline II=1
      float v445 = v437[v444];	// L526
      float v446 = v440[v444];	// L527
      float v447 = v441[v444];	// L528
      float v448 = (v443 == 0) ? v446 : v447;	// L529
      float v449 = ((v443 + (v442 * 8)) == 0) ? v445 : v448;	// L530
      float v450 = v438[v443];	// L531
      float v451 = v439[v444][v443];	// L532
      float v452 = v450 * v451;	// L533
      float v453 = v449 + v452;	// L534
      v441[v444] = v453;	// L535
    }
  }
}

void forward_node37(
  float v454[512][256],
  float v455[8][8],
  int v456,
  int v457
) {	// L540
  #pragma HLS inline
  #pragma HLS resource variable=v455 core=ram_t2p_bram

  for (int v458 = 0; v458 < 8; v458 += 1) {	// L541
    for (int v459 = 0; v459 < 8; v459 += 1) {	// L542
      #pragma HLS pipeline II=1
      float v460 = v454[(v458 + (v456 * 8))][(v459 + (v457 * 8))];	// L543
      v455[v458][v459] = v460;	// L544
    }
  }
}

void forward_node38(
  float v461[256][14][14],
  float v462[8],
  int v463,
  int v464,
  int v465
) {	// L549
  #pragma HLS inline
  #pragma HLS resource variable=v462 core=ram_t2p_bram

  for (int v466 = 0; v466 < 8; v466 += 1) {	// L550
    #pragma HLS pipeline II=1
    float v467 = v461[(v466 + (v463 * 8))][(v464 * 2)][(v465 * 2)];	// L551
    v462[v466] = v467;	// L552
  }
}

void forward_node39(
  float v468[512][7][7],
  float v469[8],
  int v470,
  int v471,
  int v472
) {	// L556
  #pragma HLS inline
  #pragma HLS resource variable=v469 core=ram_t2p_bram

  for (int v473 = 0; v473 < 8; v473 += 1) {	// L557
    #pragma HLS pipeline II=1
    float v474 = v468[(v473 + (v472 * 8))][v470][v471];	// L558
    v469[v473] = v474;	// L559
  }
}

void forward_node40(
  float v475[512][7][7],
  float v476[8],
  int v477,
  int v478,
  int v479
) {	// L563
  #pragma HLS inline
  #pragma HLS resource variable=v476 core=ram_t2p_bram

  for (int v480 = 0; v480 < 8; v480 += 1) {	// L564
    #pragma HLS pipeline II=1
    float v481 = v475[(v480 + (v479 * 8))][v477][v478];	// L565
    v476[v480] = v481;	// L566
  }
}

void forward_node34(
  float v482[512][256],
  float v483[256][14][14],
  float v484[512][7][7],
  float v485[512][7][7],
  float v486[512][7][7]
) {	// L570
  for (int v487 = 0; v487 < 100352; v487 += 1) {	// L571
    #pragma HLS dataflow
    int v488 = (v487 % 7);	// L572
    int v489 = ((v487 / 7) % 7);	// L573
    int v490 = (((v487 / 7) / 7) % 64);	// L574
    int v491 = (((v487 / 7) / 7) / 64);	// L575
    float v492[8][8];	// L576
    #pragma HLS resource variable=v492 core=ram_t2p_bram

    float v493[8];	// L577
    #pragma HLS resource variable=v493 core=ram_t2p_bram

    float v494[8];	// L578
    #pragma HLS resource variable=v494 core=ram_t2p_bram

    float v495[8];	// L579
    #pragma HLS resource variable=v495 core=ram_t2p_bram

    forward_node40(v484, v495, v489, v488, v490);	// L580
    forward_node39(v485, v494, v489, v488, v490);	// L581
    forward_node38(v483, v493, v491, v489, v488);	// L582
    forward_node37(v482, v492, v490, v491);	// L583
    float v496[8];	// L584
    #pragma HLS resource variable=v496 core=ram_t2p_bram

    forward_node36(v495, v493, v492, v494, v496, v491);	// L585
    forward_node35(v496, v486, v489, v488, v490);	// L586
  }
}

void forward_node42(
  float v497[8],
  float v498[512][7][7],
  int v499,
  int v500,
  int v501
) {	// L590
  #pragma HLS inline
  #pragma HLS array_partition variable=v497 cyclic factor=2 dim=1
  #pragma HLS resource variable=v497 core=ram_t2p_bram

  #pragma HLS array_partition variable=v498 cyclic factor=2 dim=1

  for (int v502 = 0; v502 < 8; v502 += 2) {	// L591
    #pragma HLS pipeline II=1
    float v503 = v497[v502];	// L592
    v498[(v502 + (v501 * 8))][v499][v500] = v503;	// L593
    float v504 = v497[(v502 + 1)];	// L594
    v498[((v502 + (v501 * 8)) + 1)][v499][v500] = v504;	// L595
  }
}

void forward_node43(
  float v505[8],
  float v506[8],
  float v507[8][8],
  float v508[8],
  float v509[8],
  int v510,
  int v511,
  int v512
) {	// L599
  #pragma HLS inline
  #pragma HLS array_partition variable=v505 cyclic factor=2 dim=1
  #pragma HLS resource variable=v505 core=ram_t2p_bram

  #pragma HLS array_partition variable=v506 cyclic factor=2 dim=1
  #pragma HLS resource variable=v506 core=ram_t2p_bram

  #pragma HLS array_partition variable=v507 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v507 cyclic factor=2 dim=2
  #pragma HLS resource variable=v507 core=ram_t2p_bram

  #pragma HLS array_partition variable=v508 cyclic factor=2 dim=1
  #pragma HLS resource variable=v508 core=ram_t2p_bram

  #pragma HLS array_partition variable=v509 cyclic factor=2 dim=1
  #pragma HLS resource variable=v509 core=ram_t2p_bram

  for (int v513 = 0; v513 < 8; v513 += 2) {	// L600
    for (int v514 = 0; v514 < 8; v514 += 2) {	// L601
      #pragma HLS pipeline II=1
      float v515 = v505[v514];	// L602
      float v516 = v508[v514];	// L603
      float v517 = v509[v514];	// L604
      float v518 = (v513 == 0) ? v516 : v517;	// L605
      float v519 = ((v513 + (v512 * 8)) == 0 && v510 == 0 && v511 == 0) ? v515 : v518;	// L606
      float v520 = v506[v513];	// L607
      float v521 = v507[v514][v513];	// L608
      float v522 = v520 * v521;	// L609
      float v523 = v519 + v522;	// L610
      float v524 = v505[(v514 + 1)];	// L611
      float v525 = v508[(v514 + 1)];	// L612
      float v526 = v509[(v514 + 1)];	// L613
      float v527 = (v513 == 0) ? v525 : v526;	// L614
      float v528 = ((v513 + (v512 * 8)) == 0 && v510 == 0 && v511 == 0) ? v524 : v527;	// L615
      float v529 = v507[(v514 + 1)][v513];	// L616
      float v530 = v520 * v529;	// L617
      float v531 = v528 + v530;	// L618
      int v532 = (v513 + 1);	// L619
      float v533 = (v532 == 0) ? v516 : v523;	// L620
      float v534 = ((v532 + (v512 * 8)) == 0 && v510 == 0 && v511 == 0) ? v515 : v533;	// L621
      float v535 = v506[(v513 + 1)];	// L622
      float v536 = v507[v514][(v513 + 1)];	// L623
      float v537 = v535 * v536;	// L624
      float v538 = v534 + v537;	// L625
      v509[v514] = v538;	// L626
      float v539 = (v532 == 0) ? v525 : v531;	// L627
      float v540 = ((v532 + (v512 * 8)) == 0 && v510 == 0 && v511 == 0) ? v524 : v539;	// L628
      float v541 = v507[(v514 + 1)][(v513 + 1)];	// L629
      float v542 = v535 * v541;	// L630
      float v543 = v540 + v542;	// L631
      v509[(v514 + 1)] = v543;	// L632
    }
  }
}

void forward_node44(
  float v544[512][512][3][3],
  float v545[8][8],
  int v546,
  int v547,
  int v548,
  int v549
) {	// L637
  #pragma HLS inline
  #pragma HLS array_partition variable=v544 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v544 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v545 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v545 cyclic factor=2 dim=2
  #pragma HLS resource variable=v545 core=ram_t2p_bram

  for (int v550 = 0; v550 < 8; v550 += 2) {	// L638
    for (int v551 = 0; v551 < 8; v551 += 2) {	// L639
      #pragma HLS pipeline II=1
      float v552 = v544[(v550 + (v548 * 8))][(v551 + (v549 * 8))][v546][v547];	// L640
      v545[v550][v551] = v552;	// L641
      float v553 = v544[(v550 + (v548 * 8))][((v551 + (v549 * 8)) + 1)][v546][v547];	// L642
      v545[v550][(v551 + 1)] = v553;	// L643
      float v554 = v544[((v550 + (v548 * 8)) + 1)][(v551 + (v549 * 8))][v546][v547];	// L644
      v545[(v550 + 1)][v551] = v554;	// L645
      float v555 = v544[((v550 + (v548 * 8)) + 1)][((v551 + (v549 * 8)) + 1)][v546][v547];	// L646
      v545[(v550 + 1)][(v551 + 1)] = v555;	// L647
    }
  }
}

void forward_node45(
  float v556[512][7][7],
  float v557[8],
  int v558,
  int v559,
  int v560,
  int v561,
  int v562
) {	// L652
  #pragma HLS inline
  #pragma HLS array_partition variable=v556 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v557 cyclic factor=2 dim=1
  #pragma HLS resource variable=v557 core=ram_t2p_bram

  for (int v563 = 0; v563 < 8; v563 += 2) {	// L653
    #pragma HLS pipeline II=1
    float v564 = v556[(v563 + (v558 * 8))][((v559 + v560) - 1)][((v561 + v562) - 1)];	// L654
    v557[v563] = v564;	// L655
    float v565 = v556[((v563 + (v558 * 8)) + 1)][((v559 + v560) - 1)][((v561 + v562) - 1)];	// L656
    v557[(v563 + 1)] = v565;	// L657
  }
}

void forward_node46(
  float v566[512][7][7],
  float v567[8],
  int v568,
  int v569,
  int v570
) {	// L661
  #pragma HLS inline
  #pragma HLS array_partition variable=v566 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v567 cyclic factor=2 dim=1
  #pragma HLS resource variable=v567 core=ram_t2p_bram

  for (int v571 = 0; v571 < 8; v571 += 2) {	// L662
    #pragma HLS pipeline II=1
    float v572 = v566[(v571 + (v570 * 8))][v568][v569];	// L663
    v567[v571] = v572;	// L664
    float v573 = v566[((v571 + (v570 * 8)) + 1)][v568][v569];	// L665
    v567[(v571 + 1)] = v573;	// L666
  }
}

void forward_node47(
  float v574[512][7][7],
  float v575[8],
  int v576,
  int v577,
  int v578
) {	// L670
  #pragma HLS inline
  #pragma HLS array_partition variable=v574 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v575 cyclic factor=2 dim=1
  #pragma HLS resource variable=v575 core=ram_t2p_bram

  for (int v579 = 0; v579 < 8; v579 += 2) {	// L671
    #pragma HLS pipeline II=1
    float v580 = v574[(v579 + (v578 * 8))][v576][v577];	// L672
    v575[v579] = v580;	// L673
    float v581 = v574[((v579 + (v578 * 8)) + 1)][v576][v577];	// L674
    v575[(v579 + 1)] = v581;	// L675
  }
}

void forward_node41(
  float v582[512][512][3][3],
  float v583[512][7][7],
  float v584[512][7][7],
  float v585[512][7][7],
  float v586[512][7][7]
) {	// L679
  #pragma HLS array_partition variable=v582 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v582 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v583 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v584 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v585 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v586 cyclic factor=2 dim=1

  for (int v587 = 0; v587 < 1806336; v587 += 1) {	// L680
    #pragma HLS dataflow
    int v588 = (v587 % 7);	// L681
    int v589 = ((v587 / 7) % 7);	// L682
    int v590 = (((v587 / 7) / 7) % 64);	// L683
    int v591 = ((((v587 / 7) / 7) / 64) % 3);	// L684
    int v592 = (((((v587 / 7) / 7) / 64) / 3) % 3);	// L685
    int v593 = (((((v587 / 7) / 7) / 64) / 3) / 3);	// L686
    float v594[8][8];	// L687
    #pragma HLS array_partition variable=v594 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v594 cyclic factor=2 dim=2
    #pragma HLS resource variable=v594 core=ram_t2p_bram

    float v595[8];	// L688
    #pragma HLS array_partition variable=v595 cyclic factor=2 dim=1
    #pragma HLS resource variable=v595 core=ram_t2p_bram

    float v596[8];	// L689
    #pragma HLS array_partition variable=v596 cyclic factor=2 dim=1
    #pragma HLS resource variable=v596 core=ram_t2p_bram

    float v597[8];	// L690
    #pragma HLS array_partition variable=v597 cyclic factor=2 dim=1
    #pragma HLS resource variable=v597 core=ram_t2p_bram

    forward_node47(v583, v597, v589, v588, v590);	// L691
    forward_node46(v585, v596, v589, v588, v590);	// L692
    forward_node45(v584, v595, v593, v589, v592, v588, v591);	// L693
    forward_node44(v582, v594, v592, v591, v590, v593);	// L694
    float v598[8];	// L695
    #pragma HLS array_partition variable=v598 cyclic factor=2 dim=1
    #pragma HLS resource variable=v598 core=ram_t2p_bram

    forward_node43(v597, v595, v594, v596, v598, v592, v591, v593);	// L696
    forward_node42(v598, v586, v589, v588, v590);	// L697
  }
}

void forward_node49(
  float v599[8],
  float v600[512][7][7],
  int v601,
  int v602,
  int v603
) {	// L701
  #pragma HLS inline
  #pragma HLS resource variable=v599 core=ram_t2p_bram

  for (int v604 = 0; v604 < 8; v604 += 1) {	// L702
    #pragma HLS pipeline II=1
    float v605 = v599[v604];	// L703
    v600[(v604 + (v603 * 8))][v601][v602] = v605;	// L704
  }
}

void forward_node50(
  float v606[8],
  float v607[512],
  float v608[512],
  float v609[512],
  float v610[512],
  float v611[8],
  int v612
) {	// L708
  #pragma HLS inline
  #pragma HLS resource variable=v606 core=ram_t2p_bram

  #pragma HLS resource variable=v607 core=ram_t2p_bram

  #pragma HLS resource variable=v608 core=ram_t2p_bram

  #pragma HLS resource variable=v609 core=ram_t2p_bram

  #pragma HLS resource variable=v610 core=ram_t2p_bram

  #pragma HLS resource variable=v611 core=ram_t2p_bram

  for (int v613 = 0; v613 < 8; v613 += 1) {	// L711
    #pragma HLS pipeline II=1
    float v614 = v606[v613];	// L712
    float v615 = v608[(v613 + (v612 * 8))];	// L713
    float v616 = v610[(v613 + (v612 * 8))];	// L714
    float v617 = v607[(v613 + (v612 * 8))];	// L715
    float v618 = v609[(v613 + (v612 * 8))];	// L716
    float v619 = (double)0.000010;	// L717
    float v620 = v618 + v619;	// L718
    float v621 = 1.0 / sqrt(v620);	// L719
    float v622 = v614 - v617;	// L720
    float v623 = v622 * v621;	// L721
    float v624 = v623 * v615;	// L722
    float v625 = v624 + v616;	// L723
    bool v626 = v625 > (float)0.000000;	// L724
    float v627 = v626 ? v625 : (float)0.000000;	// L725
    v611[v613] = v627;	// L726
  }
}

void forward_node51(
  float v628[512][7][7],
  float v629[8],
  int v630,
  int v631,
  int v632
) {	// L730
  #pragma HLS inline
  #pragma HLS resource variable=v629 core=ram_t2p_bram

  for (int v633 = 0; v633 < 8; v633 += 1) {	// L731
    #pragma HLS pipeline II=1
    float v634 = v628[(v633 + (v632 * 8))][v630][v631];	// L732
    v629[v633] = v634;	// L733
  }
}

void forward_node48(
  float v635[512],
  float v636[512],
  float v637[512],
  float v638[512],
  float v639[512][7][7],
  float v640[512][7][7]
) {	// L737
  #pragma HLS resource variable=v635 core=ram_t2p_bram

  #pragma HLS resource variable=v636 core=ram_t2p_bram

  #pragma HLS resource variable=v637 core=ram_t2p_bram

  #pragma HLS resource variable=v638 core=ram_t2p_bram

  for (int v641 = 0; v641 < 3136; v641 += 1) {	// L738
    #pragma HLS dataflow
    int v642 = (v641 % 7);	// L739
    int v643 = ((v641 / 7) % 7);	// L740
    int v644 = ((v641 / 7) / 7);	// L741
    float v645[8];	// L742
    #pragma HLS resource variable=v645 core=ram_t2p_bram

    float v646[8];	// L743
    #pragma HLS resource variable=v646 core=ram_t2p_bram

    forward_node51(v639, v646, v643, v642, v644);	// L744
    forward_node50(v646, v635, v637, v636, v638, v645, v644);	// L745
    forward_node49(v645, v640, v643, v642, v644);	// L746
  }
}

void forward_node53(
  float v647[8],
  float v648[512][7][7],
  int v649,
  int v650,
  int v651
) {	// L750
  #pragma HLS inline
  #pragma HLS resource variable=v647 core=ram_t2p_bram

  for (int v652 = 0; v652 < 8; v652 += 1) {	// L751
    #pragma HLS pipeline II=1
    float v653 = v647[v652];	// L752
    v648[(v652 + (v651 * 8))][v649][v650] = v653;	// L753
  }
}

void forward_node54(
  float v654[8],
  float v655[8],
  float v656[8][8],
  float v657[8],
  float v658[8],
  int v659,
  int v660,
  int v661
) {	// L757
  #pragma HLS inline
  #pragma HLS resource variable=v654 core=ram_t2p_bram

  #pragma HLS resource variable=v655 core=ram_t2p_bram

  #pragma HLS resource variable=v656 core=ram_t2p_bram

  #pragma HLS resource variable=v657 core=ram_t2p_bram

  #pragma HLS resource variable=v658 core=ram_t2p_bram

  for (int v662 = 0; v662 < 8; v662 += 1) {	// L758
    for (int v663 = 0; v663 < 8; v663 += 1) {	// L759
      #pragma HLS pipeline II=1
      float v664 = v654[v663];	// L760
      float v665 = v657[v663];	// L761
      float v666 = v658[v663];	// L762
      float v667 = (v662 == 0) ? v665 : v666;	// L763
      float v668 = ((v662 + (v661 * 8)) == 0 && v659 == 0 && v660 == 0) ? v664 : v667;	// L764
      float v669 = v655[v662];	// L765
      float v670 = v656[v663][v662];	// L766
      float v671 = v669 * v670;	// L767
      float v672 = v668 + v671;	// L768
      v658[v663] = v672;	// L769
    }
  }
}

void forward_node55(
  float v673[512][256][3][3],
  float v674[8][8],
  int v675,
  int v676,
  int v677,
  int v678
) {	// L774
  #pragma HLS inline
  #pragma HLS resource variable=v674 core=ram_t2p_bram

  for (int v679 = 0; v679 < 8; v679 += 1) {	// L775
    for (int v680 = 0; v680 < 8; v680 += 1) {	// L776
      #pragma HLS pipeline II=1
      float v681 = v673[(v679 + (v677 * 8))][(v680 + (v678 * 8))][v675][v676];	// L777
      v674[v679][v680] = v681;	// L778
    }
  }
}

void forward_node56(
  float v682[256][14][14],
  float v683[8],
  int v684,
  int v685,
  int v686,
  int v687,
  int v688
) {	// L783
  #pragma HLS inline
  #pragma HLS resource variable=v683 core=ram_t2p_bram

  for (int v689 = 0; v689 < 8; v689 += 1) {	// L784
    #pragma HLS pipeline II=1
    float v690 = v682[(v689 + (v684 * 8))][(((v685 * 2) + v686) - 1)][(((v687 * 2) + v688) - 1)];	// L785
    v683[v689] = v690;	// L786
  }
}

void forward_node57(
  float v691[512][7][7],
  float v692[8],
  int v693,
  int v694,
  int v695
) {	// L790
  #pragma HLS inline
  #pragma HLS resource variable=v692 core=ram_t2p_bram

  for (int v696 = 0; v696 < 8; v696 += 1) {	// L791
    #pragma HLS pipeline II=1
    float v697 = v691[(v696 + (v695 * 8))][v693][v694];	// L792
    v692[v696] = v697;	// L793
  }
}

void forward_node58(
  float v698[512][7][7],
  float v699[8],
  int v700,
  int v701,
  int v702
) {	// L797
  #pragma HLS inline
  #pragma HLS resource variable=v699 core=ram_t2p_bram

  for (int v703 = 0; v703 < 8; v703 += 1) {	// L798
    #pragma HLS pipeline II=1
    float v704 = v698[(v703 + (v702 * 8))][v700][v701];	// L799
    v699[v703] = v704;	// L800
  }
}

void forward_node52(
  float v705[512][256][3][3],
  float v706[256][14][14],
  float v707[512][7][7],
  float v708[512][7][7],
  float v709[512][7][7]
) {	// L804
  for (int v710 = 0; v710 < 903168; v710 += 1) {	// L805
    #pragma HLS dataflow
    int v711 = (v710 % 7);	// L806
    int v712 = ((v710 / 7) % 7);	// L807
    int v713 = (((v710 / 7) / 7) % 64);	// L808
    int v714 = ((((v710 / 7) / 7) / 64) % 3);	// L809
    int v715 = (((((v710 / 7) / 7) / 64) / 3) % 3);	// L810
    int v716 = (((((v710 / 7) / 7) / 64) / 3) / 3);	// L811
    float v717[8][8];	// L812
    #pragma HLS resource variable=v717 core=ram_t2p_bram

    float v718[8];	// L813
    #pragma HLS resource variable=v718 core=ram_t2p_bram

    float v719[8];	// L814
    #pragma HLS resource variable=v719 core=ram_t2p_bram

    float v720[8];	// L815
    #pragma HLS resource variable=v720 core=ram_t2p_bram

    forward_node58(v707, v720, v712, v711, v713);	// L816
    forward_node57(v708, v719, v712, v711, v713);	// L817
    forward_node56(v706, v718, v716, v712, v715, v711, v714);	// L818
    forward_node55(v705, v717, v715, v714, v713, v716);	// L819
    float v721[8];	// L820
    #pragma HLS resource variable=v721 core=ram_t2p_bram

    forward_node54(v720, v718, v717, v719, v721, v715, v714, v716);	// L821
    forward_node53(v721, v709, v712, v711, v713);	// L822
  }
}

void forward_node60(
  float v722[8][7][7],
  float v723[256][14][14],
  int v724,
  int v725,
  int v726
) {	// L826
  #pragma HLS inline
  #pragma HLS resource variable=v722 core=ram_t2p_bram

  for (int v727 = 0; v727 < 8; v727 += 1) {	// L827
    for (int v728 = 0; v728 < 7; v728 += 1) {	// L828
      for (int v729 = 0; v729 < 7; v729 += 1) {	// L829
        #pragma HLS pipeline II=1
        float v730 = v722[v727][v728][v729];	// L830
        v723[(v727 + (v724 * 8))][(v728 + (v725 * 7))][(v729 + (v726 * 7))] = v730;	// L831
      }
    }
  }
}

void forward_node61(
  float v731[256],
  float v732[8][7][7],
  float v733[256],
  float v734[256],
  float v735[8][7][7],
  float v736[256],
  float v737[8][7][7],
  int v738
) {	// L837
  #pragma HLS inline
  #pragma HLS resource variable=v731 core=ram_t2p_bram

  #pragma HLS resource variable=v732 core=ram_t2p_bram

  #pragma HLS resource variable=v733 core=ram_t2p_bram

  #pragma HLS resource variable=v734 core=ram_t2p_bram

  #pragma HLS resource variable=v735 core=ram_t2p_bram

  #pragma HLS resource variable=v736 core=ram_t2p_bram

  #pragma HLS resource variable=v737 core=ram_t2p_bram

  for (int v739 = 0; v739 < 8; v739 += 1) {	// L840
    for (int v740 = 0; v740 < 7; v740 += 1) {	// L841
      for (int v741 = 0; v741 < 7; v741 += 1) {	// L842
        #pragma HLS pipeline II=1
        float v742 = v735[v739][v740][v741];	// L843
        float v743 = v736[(v739 + (v738 * 8))];	// L844
        float v744 = v734[(v739 + (v738 * 8))];	// L845
        float v745 = v731[(v739 + (v738 * 8))];	// L846
        float v746 = v733[(v739 + (v738 * 8))];	// L847
        float v747 = v732[v739][v740][v741];	// L848
        float v748 = (double)0.000010;	// L849
        float v749 = v746 + v748;	// L850
        float v750 = 1.0 / sqrt(v749);	// L851
        float v751 = v742 - v745;	// L852
        float v752 = v751 * v750;	// L853
        float v753 = v752 * v743;	// L854
        float v754 = v753 + v744;	// L855
        float v755 = v754 + v747;	// L856
        bool v756 = v755 > (float)0.000000;	// L857
        float v757 = v756 ? v755 : (float)0.000000;	// L858
        v737[v739][v740][v741] = v757;	// L859
      }
    }
  }
}

void forward_node62(
  float v758[256][14][14],
  float v759[8][7][7],
  int v760,
  int v761,
  int v762
) {	// L865
  #pragma HLS inline
  #pragma HLS resource variable=v759 core=ram_t2p_bram

  for (int v763 = 0; v763 < 8; v763 += 1) {	// L866
    for (int v764 = 0; v764 < 7; v764 += 1) {	// L867
      for (int v765 = 0; v765 < 7; v765 += 1) {	// L868
        #pragma HLS pipeline II=1
        float v766 = v758[(v763 + (v760 * 8))][(v764 + (v761 * 7))][(v765 + (v762 * 7))];	// L869
        v759[v763][v764][v765] = v766;	// L870
      }
    }
  }
}

void forward_node63(
  float v767[256][14][14],
  float v768[8][7][7],
  int v769,
  int v770,
  int v771
) {	// L876
  #pragma HLS inline
  #pragma HLS resource variable=v768 core=ram_t2p_bram

  for (int v772 = 0; v772 < 8; v772 += 1) {	// L877
    for (int v773 = 0; v773 < 7; v773 += 1) {	// L878
      for (int v774 = 0; v774 < 7; v774 += 1) {	// L879
        #pragma HLS pipeline II=1
        float v775 = v767[(v772 + (v769 * 8))][(v773 + (v770 * 7))][(v774 + (v771 * 7))];	// L880
        v768[v772][v773][v774] = v775;	// L881
      }
    }
  }
}

void forward_node59(
  float v776[256][14][14],
  float v777[256][14][14],
  float v778[256],
  float v779[256],
  float v780[256],
  float v781[256],
  float v782[256][14][14]
) {	// L887
  #pragma HLS resource variable=v778 core=ram_t2p_bram

  #pragma HLS resource variable=v779 core=ram_t2p_bram

  #pragma HLS resource variable=v780 core=ram_t2p_bram

  #pragma HLS resource variable=v781 core=ram_t2p_bram

  for (int v783 = 0; v783 < 128; v783 += 1) {	// L888
    #pragma HLS dataflow
    int v784 = (v783 % 2);	// L889
    int v785 = ((v783 / 2) % 2);	// L890
    int v786 = ((v783 / 2) / 2);	// L891
    float v787[8][7][7];	// L892
    #pragma HLS resource variable=v787 core=ram_t2p_bram

    float v788[8][7][7];	// L893
    #pragma HLS resource variable=v788 core=ram_t2p_bram

    float v789[8][7][7];	// L894
    #pragma HLS resource variable=v789 core=ram_t2p_bram

    forward_node63(v776, v789, v786, v785, v784);	// L895
    forward_node62(v777, v788, v786, v785, v784);	// L896
    forward_node61(v781, v788, v780, v779, v789, v778, v787, v786);	// L897
    forward_node60(v787, v782, v786, v785, v784);	// L898
  }
}

void forward_node65(
  float v790[8][7][7],
  float v791[256][14][14],
  int v792,
  int v793,
  int v794
) {	// L902
  #pragma HLS inline
  #pragma HLS array_partition variable=v790 cyclic factor=2 dim=1
  #pragma HLS resource variable=v790 core=ram_t2p_bram

  #pragma HLS array_partition variable=v791 cyclic factor=2 dim=1

  for (int v795 = 0; v795 < 8; v795 += 2) {	// L903
    for (int v796 = 0; v796 < 7; v796 += 1) {	// L904
      for (int v797 = 0; v797 < 7; v797 += 1) {	// L905
        #pragma HLS pipeline II=1
        float v798 = v790[v795][v796][v797];	// L906
        v791[(v795 + (v792 * 8))][(v796 + (v793 * 7))][(v797 + (v794 * 7))] = v798;	// L907
        float v799 = v790[(v795 + 1)][v796][v797];	// L908
        v791[((v795 + (v792 * 8)) + 1)][(v796 + (v793 * 7))][(v797 + (v794 * 7))] = v799;	// L909
      }
    }
  }
}

void forward_node66(
  float v800[8][7][7],
  float v801[8][8],
  float v802[8][7][7],
  float v803[8][7][7]
) {	// L915
  #pragma HLS inline
  #pragma HLS array_partition variable=v800 cyclic factor=2 dim=1
  #pragma HLS resource variable=v800 core=ram_t2p_bram

  #pragma HLS array_partition variable=v801 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v801 cyclic factor=2 dim=2
  #pragma HLS resource variable=v801 core=ram_t2p_bram

  #pragma HLS array_partition variable=v802 cyclic factor=2 dim=1
  #pragma HLS resource variable=v802 core=ram_t2p_bram

  #pragma HLS array_partition variable=v803 cyclic factor=2 dim=1
  #pragma HLS resource variable=v803 core=ram_t2p_bram

  for (int v804 = 0; v804 < 8; v804 += 2) {	// L916
    for (int v805 = 0; v805 < 8; v805 += 2) {	// L917
      for (int v806 = 0; v806 < 7; v806 += 1) {	// L918
        for (int v807 = 0; v807 < 7; v807 += 1) {	// L919
          #pragma HLS pipeline II=1
          float v808 = v800[v804][v806][v807];	// L920
          float v809 = v801[v805][v804];	// L921
          float v810 = v802[v805][v806][v807];	// L922
          float v811 = v803[v805][v806][v807];	// L923
          float v812 = (v804 == 0) ? v810 : v811;	// L924
          float v813 = v808 * v809;	// L925
          float v814 = v812 + v813;	// L926
          float v815 = v801[(v805 + 1)][v804];	// L927
          float v816 = v802[(v805 + 1)][v806][v807];	// L928
          float v817 = v803[(v805 + 1)][v806][v807];	// L929
          float v818 = (v804 == 0) ? v816 : v817;	// L930
          float v819 = v808 * v815;	// L931
          float v820 = v818 + v819;	// L932
          int v821 = (v804 + 1);	// L933
          float v822 = v800[(v804 + 1)][v806][v807];	// L934
          float v823 = v801[v805][(v804 + 1)];	// L935
          float v824 = (v821 == 0) ? v810 : v814;	// L936
          float v825 = v822 * v823;	// L937
          float v826 = v824 + v825;	// L938
          v803[v805][v806][v807] = v826;	// L939
          float v827 = v801[(v805 + 1)][(v804 + 1)];	// L940
          float v828 = (v821 == 0) ? v816 : v820;	// L941
          float v829 = v822 * v827;	// L942
          float v830 = v828 + v829;	// L943
          v803[(v805 + 1)][v806][v807] = v830;	// L944
        }
      }
    }
  }
}

void forward_node67(
  float v831[256][14][14],
  float v832[8][7][7],
  int v833,
  int v834,
  int v835
) {	// L951
  #pragma HLS inline
  #pragma HLS array_partition variable=v831 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v832 cyclic factor=2 dim=1
  #pragma HLS resource variable=v832 core=ram_t2p_bram

  for (int v836 = 0; v836 < 8; v836 += 2) {	// L952
    for (int v837 = 0; v837 < 7; v837 += 1) {	// L953
      for (int v838 = 0; v838 < 7; v838 += 1) {	// L954
        #pragma HLS pipeline II=1
        float v839 = v831[(v836 + (v833 * 8))][(v837 + (v834 * 7))][(v838 + (v835 * 7))];	// L955
        v832[v836][v837][v838] = v839;	// L956
        float v840 = v831[((v836 + (v833 * 8)) + 1)][(v837 + (v834 * 7))][(v838 + (v835 * 7))];	// L957
        v832[(v836 + 1)][v837][v838] = v840;	// L958
      }
    }
  }
}

void forward_node68(
  float v841[256][256][3][3],
  float v842[8][8],
  int v843,
  int v844,
  int v845,
  int v846
) {	// L964
  #pragma HLS inline
  #pragma HLS array_partition variable=v841 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v841 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v842 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v842 cyclic factor=2 dim=2
  #pragma HLS resource variable=v842 core=ram_t2p_bram

  for (int v847 = 0; v847 < 8; v847 += 2) {	// L965
    for (int v848 = 0; v848 < 8; v848 += 2) {	// L966
      #pragma HLS pipeline II=1
      float v849 = v841[(v847 + (v845 * 8))][(v848 + (v846 * 8))][v843][v844];	// L967
      v842[v847][v848] = v849;	// L968
      float v850 = v841[(v847 + (v845 * 8))][((v848 + (v846 * 8)) + 1)][v843][v844];	// L969
      v842[v847][(v848 + 1)] = v850;	// L970
      float v851 = v841[((v847 + (v845 * 8)) + 1)][(v848 + (v846 * 8))][v843][v844];	// L971
      v842[(v847 + 1)][v848] = v851;	// L972
      float v852 = v841[((v847 + (v845 * 8)) + 1)][((v848 + (v846 * 8)) + 1)][v843][v844];	// L973
      v842[(v847 + 1)][(v848 + 1)] = v852;	// L974
    }
  }
}

void forward_node69(
  float v853[256][14][14],
  float v854[8][7][7],
  int v855,
  int v856,
  int v857,
  int v858,
  int v859
) {	// L979
  #pragma HLS inline
  #pragma HLS array_partition variable=v853 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v854 cyclic factor=2 dim=1
  #pragma HLS resource variable=v854 core=ram_t2p_bram

  for (int v860 = 0; v860 < 8; v860 += 2) {	// L980
    for (int v861 = 0; v861 < 7; v861 += 1) {	// L981
      for (int v862 = 0; v862 < 7; v862 += 1) {	// L982
        #pragma HLS pipeline II=1
        float v863 = v853[(v860 + (v855 * 8))][(((v861 + v856) + (v857 * 7)) - 1)][(((v862 + v858) + (v859 * 7)) - 1)];	// L983
        v854[v860][v861][v862] = v863;	// L984
        float v864 = v853[((v860 + (v855 * 8)) + 1)][(((v861 + v856) + (v857 * 7)) - 1)][(((v862 + v858) + (v859 * 7)) - 1)];	// L985
        v854[(v860 + 1)][v861][v862] = v864;	// L986
      }
    }
  }
}

void forward_node64(
  float v865[256][256][3][3],
  float v866[256][14][14],
  float v867[256][14][14],
  float v868[256][14][14]
) {	// L992
  #pragma HLS array_partition variable=v865 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v865 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v866 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v867 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v868 cyclic factor=2 dim=1

  for (int v869 = 0; v869 < 36864; v869 += 1) {	// L993
    #pragma HLS dataflow
    int v870 = (v869 % 2);	// L994
    int v871 = ((v869 / 2) % 2);	// L995
    int v872 = (((v869 / 2) / 2) % 32);	// L996
    int v873 = ((((v869 / 2) / 2) / 32) % 3);	// L997
    int v874 = (((((v869 / 2) / 2) / 32) / 3) % 3);	// L998
    int v875 = (((((v869 / 2) / 2) / 32) / 3) / 3);	// L999
    float v876[8][7][7];	// L1000
    #pragma HLS array_partition variable=v876 cyclic factor=2 dim=1
    #pragma HLS resource variable=v876 core=ram_t2p_bram

    float v877[8][8];	// L1001
    #pragma HLS array_partition variable=v877 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v877 cyclic factor=2 dim=2
    #pragma HLS resource variable=v877 core=ram_t2p_bram

    float v878[8][7][7];	// L1002
    #pragma HLS array_partition variable=v878 cyclic factor=2 dim=1
    #pragma HLS resource variable=v878 core=ram_t2p_bram

    forward_node69(v866, v878, v875, v874, v871, v873, v870);	// L1003
    forward_node68(v865, v877, v874, v873, v872, v875);	// L1004
    forward_node67(v867, v876, v872, v871, v870);	// L1005
    float v879[8][7][7];	// L1006
    #pragma HLS array_partition variable=v879 cyclic factor=2 dim=1
    #pragma HLS resource variable=v879 core=ram_t2p_bram

    forward_node66(v878, v877, v876, v879);	// L1007
    forward_node65(v879, v868, v872, v871, v870);	// L1008
  }
}

void forward_node71(
  float v880[8][7][7],
  float v881[256][14][14],
  int v882,
  int v883,
  int v884
) {	// L1012
  #pragma HLS inline
  #pragma HLS resource variable=v880 core=ram_t2p_bram

  for (int v885 = 0; v885 < 8; v885 += 1) {	// L1013
    for (int v886 = 0; v886 < 7; v886 += 1) {	// L1014
      for (int v887 = 0; v887 < 7; v887 += 1) {	// L1015
        #pragma HLS pipeline II=1
        float v888 = v880[v885][v886][v887];	// L1016
        v881[(v885 + (v882 * 8))][(v886 + (v883 * 7))][(v887 + (v884 * 7))] = v888;	// L1017
      }
    }
  }
}

void forward_node72(
  float v889[8][7][7],
  float v890[256],
  float v891[256],
  float v892[256],
  float v893[256],
  float v894[8][7][7],
  int v895
) {	// L1023
  #pragma HLS inline
  #pragma HLS resource variable=v889 core=ram_t2p_bram

  #pragma HLS resource variable=v890 core=ram_t2p_bram

  #pragma HLS resource variable=v891 core=ram_t2p_bram

  #pragma HLS resource variable=v892 core=ram_t2p_bram

  #pragma HLS resource variable=v893 core=ram_t2p_bram

  #pragma HLS resource variable=v894 core=ram_t2p_bram

  for (int v896 = 0; v896 < 8; v896 += 1) {	// L1026
    for (int v897 = 0; v897 < 7; v897 += 1) {	// L1027
      for (int v898 = 0; v898 < 7; v898 += 1) {	// L1028
        #pragma HLS pipeline II=1
        float v899 = v889[v896][v897][v898];	// L1029
        float v900 = v893[(v896 + (v895 * 8))];	// L1030
        float v901 = v890[(v896 + (v895 * 8))];	// L1031
        float v902 = v892[(v896 + (v895 * 8))];	// L1032
        float v903 = v891[(v896 + (v895 * 8))];	// L1033
        float v904 = (double)0.000010;	// L1034
        float v905 = v903 + v904;	// L1035
        float v906 = 1.0 / sqrt(v905);	// L1036
        float v907 = v899 - v902;	// L1037
        float v908 = v907 * v906;	// L1038
        float v909 = v908 * v900;	// L1039
        float v910 = v909 + v901;	// L1040
        bool v911 = v910 > (float)0.000000;	// L1041
        float v912 = v911 ? v910 : (float)0.000000;	// L1042
        v894[v896][v897][v898] = v912;	// L1043
      }
    }
  }
}

void forward_node73(
  float v913[256][14][14],
  float v914[8][7][7],
  int v915,
  int v916,
  int v917
) {	// L1049
  #pragma HLS inline
  #pragma HLS resource variable=v914 core=ram_t2p_bram

  for (int v918 = 0; v918 < 8; v918 += 1) {	// L1050
    for (int v919 = 0; v919 < 7; v919 += 1) {	// L1051
      for (int v920 = 0; v920 < 7; v920 += 1) {	// L1052
        #pragma HLS pipeline II=1
        float v921 = v913[(v918 + (v915 * 8))][(v919 + (v916 * 7))][(v920 + (v917 * 7))];	// L1053
        v914[v918][v919][v920] = v921;	// L1054
      }
    }
  }
}

void forward_node70(
  float v922[256],
  float v923[256],
  float v924[256],
  float v925[256],
  float v926[256][14][14],
  float v927[256][14][14]
) {	// L1060
  #pragma HLS resource variable=v922 core=ram_t2p_bram

  #pragma HLS resource variable=v923 core=ram_t2p_bram

  #pragma HLS resource variable=v924 core=ram_t2p_bram

  #pragma HLS resource variable=v925 core=ram_t2p_bram

  for (int v928 = 0; v928 < 128; v928 += 1) {	// L1061
    #pragma HLS dataflow
    int v929 = (v928 % 2);	// L1062
    int v930 = ((v928 / 2) % 2);	// L1063
    int v931 = ((v928 / 2) / 2);	// L1064
    float v932[8][7][7];	// L1065
    #pragma HLS resource variable=v932 core=ram_t2p_bram

    float v933[8][7][7];	// L1066
    #pragma HLS resource variable=v933 core=ram_t2p_bram

    forward_node73(v926, v933, v931, v930, v929);	// L1067
    forward_node72(v933, v924, v923, v925, v922, v932, v931);	// L1068
    forward_node71(v932, v927, v931, v930, v929);	// L1069
  }
}

void forward_node75(
  float v934[8][7][7],
  float v935[256][14][14],
  int v936,
  int v937,
  int v938
) {	// L1073
  #pragma HLS inline
  #pragma HLS array_partition variable=v934 cyclic factor=2 dim=1
  #pragma HLS resource variable=v934 core=ram_t2p_bram

  #pragma HLS array_partition variable=v935 cyclic factor=2 dim=1

  for (int v939 = 0; v939 < 8; v939 += 2) {	// L1074
    for (int v940 = 0; v940 < 7; v940 += 1) {	// L1075
      for (int v941 = 0; v941 < 7; v941 += 1) {	// L1076
        #pragma HLS pipeline II=1
        float v942 = v934[v939][v940][v941];	// L1077
        v935[(v939 + (v936 * 8))][(v940 + (v937 * 7))][(v941 + (v938 * 7))] = v942;	// L1078
        float v943 = v934[(v939 + 1)][v940][v941];	// L1079
        v935[((v939 + (v936 * 8)) + 1)][(v940 + (v937 * 7))][(v941 + (v938 * 7))] = v943;	// L1080
      }
    }
  }
}

void forward_node76(
  float v944[8][7][7],
  float v945[8][7][7],
  float v946[8][8],
  float v947[8][7][7],
  float v948[8][7][7],
  int v949,
  int v950,
  int v951
) {	// L1086
  #pragma HLS inline
  #pragma HLS array_partition variable=v944 cyclic factor=2 dim=1
  #pragma HLS resource variable=v944 core=ram_t2p_bram

  #pragma HLS array_partition variable=v945 cyclic factor=2 dim=1
  #pragma HLS resource variable=v945 core=ram_t2p_bram

  #pragma HLS array_partition variable=v946 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v946 cyclic factor=2 dim=2
  #pragma HLS resource variable=v946 core=ram_t2p_bram

  #pragma HLS array_partition variable=v947 cyclic factor=2 dim=1
  #pragma HLS resource variable=v947 core=ram_t2p_bram

  #pragma HLS array_partition variable=v948 cyclic factor=2 dim=1
  #pragma HLS resource variable=v948 core=ram_t2p_bram

  for (int v952 = 0; v952 < 8; v952 += 2) {	// L1087
    for (int v953 = 0; v953 < 8; v953 += 2) {	// L1088
      for (int v954 = 0; v954 < 7; v954 += 1) {	// L1089
        for (int v955 = 0; v955 < 7; v955 += 1) {	// L1090
          #pragma HLS pipeline II=1
          float v956 = v944[v953][v954][v955];	// L1091
          float v957 = v947[v953][v954][v955];	// L1092
          float v958 = v948[v953][v954][v955];	// L1093
          float v959 = (v952 == 0) ? v957 : v958;	// L1094
          float v960 = ((v952 + (v950 * 8)) == 0 && v951 == 0 && v949 == 0) ? v956 : v959;	// L1095
          float v961 = v945[v952][v954][v955];	// L1096
          float v962 = v946[v953][v952];	// L1097
          float v963 = v961 * v962;	// L1098
          float v964 = v960 + v963;	// L1099
          float v965 = v944[(v953 + 1)][v954][v955];	// L1100
          float v966 = v947[(v953 + 1)][v954][v955];	// L1101
          float v967 = v948[(v953 + 1)][v954][v955];	// L1102
          float v968 = (v952 == 0) ? v966 : v967;	// L1103
          float v969 = ((v952 + (v950 * 8)) == 0 && v951 == 0 && v949 == 0) ? v965 : v968;	// L1104
          float v970 = v946[(v953 + 1)][v952];	// L1105
          float v971 = v961 * v970;	// L1106
          float v972 = v969 + v971;	// L1107
          int v973 = (v952 + 1);	// L1108
          float v974 = (v973 == 0) ? v957 : v964;	// L1109
          float v975 = ((v973 + (v950 * 8)) == 0 && v951 == 0 && v949 == 0) ? v956 : v974;	// L1110
          float v976 = v945[(v952 + 1)][v954][v955];	// L1111
          float v977 = v946[v953][(v952 + 1)];	// L1112
          float v978 = v976 * v977;	// L1113
          float v979 = v975 + v978;	// L1114
          v948[v953][v954][v955] = v979;	// L1115
          float v980 = (v973 == 0) ? v966 : v972;	// L1116
          float v981 = ((v973 + (v950 * 8)) == 0 && v951 == 0 && v949 == 0) ? v965 : v980;	// L1117
          float v982 = v946[(v953 + 1)][(v952 + 1)];	// L1118
          float v983 = v976 * v982;	// L1119
          float v984 = v981 + v983;	// L1120
          v948[(v953 + 1)][v954][v955] = v984;	// L1121
        }
      }
    }
  }
}

void forward_node77(
  float v985[256][256][3][3],
  float v986[8][8],
  int v987,
  int v988,
  int v989,
  int v990
) {	// L1128
  #pragma HLS inline
  #pragma HLS array_partition variable=v985 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v985 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v986 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v986 cyclic factor=2 dim=2
  #pragma HLS resource variable=v986 core=ram_t2p_bram

  for (int v991 = 0; v991 < 8; v991 += 2) {	// L1129
    for (int v992 = 0; v992 < 8; v992 += 2) {	// L1130
      #pragma HLS pipeline II=1
      float v993 = v985[(v991 + (v989 * 8))][(v992 + (v990 * 8))][v987][v988];	// L1131
      v986[v991][v992] = v993;	// L1132
      float v994 = v985[(v991 + (v989 * 8))][((v992 + (v990 * 8)) + 1)][v987][v988];	// L1133
      v986[v991][(v992 + 1)] = v994;	// L1134
      float v995 = v985[((v991 + (v989 * 8)) + 1)][(v992 + (v990 * 8))][v987][v988];	// L1135
      v986[(v991 + 1)][v992] = v995;	// L1136
      float v996 = v985[((v991 + (v989 * 8)) + 1)][((v992 + (v990 * 8)) + 1)][v987][v988];	// L1137
      v986[(v991 + 1)][(v992 + 1)] = v996;	// L1138
    }
  }
}

void forward_node78(
  float v997[256][14][14],
  float v998[8][7][7],
  int v999,
  int v1000,
  int v1001,
  int v1002,
  int v1003
) {	// L1143
  #pragma HLS inline
  #pragma HLS array_partition variable=v997 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v998 cyclic factor=2 dim=1
  #pragma HLS resource variable=v998 core=ram_t2p_bram

  for (int v1004 = 0; v1004 < 8; v1004 += 2) {	// L1144
    for (int v1005 = 0; v1005 < 7; v1005 += 1) {	// L1145
      for (int v1006 = 0; v1006 < 7; v1006 += 1) {	// L1146
        #pragma HLS pipeline II=1
        float v1007 = v997[(v1004 + (v999 * 8))][(((v1005 + v1000) + (v1001 * 7)) - 1)][(((v1006 + v1002) + (v1003 * 7)) - 1)];	// L1147
        v998[v1004][v1005][v1006] = v1007;	// L1148
        float v1008 = v997[((v1004 + (v999 * 8)) + 1)][(((v1005 + v1000) + (v1001 * 7)) - 1)][(((v1006 + v1002) + (v1003 * 7)) - 1)];	// L1149
        v998[(v1004 + 1)][v1005][v1006] = v1008;	// L1150
      }
    }
  }
}

void forward_node79(
  float v1009[256][14][14],
  float v1010[8][7][7],
  int v1011,
  int v1012,
  int v1013
) {	// L1156
  #pragma HLS inline
  #pragma HLS array_partition variable=v1009 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1010 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1010 core=ram_t2p_bram

  for (int v1014 = 0; v1014 < 8; v1014 += 2) {	// L1157
    for (int v1015 = 0; v1015 < 7; v1015 += 1) {	// L1158
      for (int v1016 = 0; v1016 < 7; v1016 += 1) {	// L1159
        #pragma HLS pipeline II=1
        float v1017 = v1009[(v1014 + (v1011 * 8))][(v1015 + (v1012 * 7))][(v1016 + (v1013 * 7))];	// L1160
        v1010[v1014][v1015][v1016] = v1017;	// L1161
        float v1018 = v1009[((v1014 + (v1011 * 8)) + 1)][(v1015 + (v1012 * 7))][(v1016 + (v1013 * 7))];	// L1162
        v1010[(v1014 + 1)][v1015][v1016] = v1018;	// L1163
      }
    }
  }
}

void forward_node80(
  float v1019[256][14][14],
  float v1020[8][7][7],
  int v1021,
  int v1022,
  int v1023
) {	// L1169
  #pragma HLS inline
  #pragma HLS array_partition variable=v1019 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1020 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1020 core=ram_t2p_bram

  for (int v1024 = 0; v1024 < 8; v1024 += 2) {	// L1170
    for (int v1025 = 0; v1025 < 7; v1025 += 1) {	// L1171
      for (int v1026 = 0; v1026 < 7; v1026 += 1) {	// L1172
        #pragma HLS pipeline II=1
        float v1027 = v1019[(v1024 + (v1021 * 8))][(v1025 + (v1022 * 7))][(v1026 + (v1023 * 7))];	// L1173
        v1020[v1024][v1025][v1026] = v1027;	// L1174
        float v1028 = v1019[((v1024 + (v1021 * 8)) + 1)][(v1025 + (v1022 * 7))][(v1026 + (v1023 * 7))];	// L1175
        v1020[(v1024 + 1)][v1025][v1026] = v1028;	// L1176
      }
    }
  }
}

void forward_node74(
  float v1029[256][14][14],
  float v1030[256][14][14],
  float v1031[256][256][3][3],
  float v1032[256][14][14],
  float v1033[256][14][14]
) {	// L1182
  #pragma HLS array_partition variable=v1029 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1030 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1031 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1031 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v1032 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1033 cyclic factor=2 dim=1

  for (int v1034 = 0; v1034 < 36864; v1034 += 1) {	// L1183
    #pragma HLS dataflow
    int v1035 = (v1034 % 2);	// L1184
    int v1036 = ((v1034 / 2) % 2);	// L1185
    int v1037 = (((v1034 / 2) / 2) % 32);	// L1186
    int v1038 = ((((v1034 / 2) / 2) / 32) % 3);	// L1187
    int v1039 = (((((v1034 / 2) / 2) / 32) / 3) % 3);	// L1188
    int v1040 = (((((v1034 / 2) / 2) / 32) / 3) / 3);	// L1189
    float v1041[8][8];	// L1190
    #pragma HLS array_partition variable=v1041 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v1041 cyclic factor=2 dim=2
    #pragma HLS resource variable=v1041 core=ram_t2p_bram

    float v1042[8][7][7];	// L1191
    #pragma HLS array_partition variable=v1042 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1042 core=ram_t2p_bram

    float v1043[8][7][7];	// L1192
    #pragma HLS array_partition variable=v1043 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1043 core=ram_t2p_bram

    float v1044[8][7][7];	// L1193
    #pragma HLS array_partition variable=v1044 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1044 core=ram_t2p_bram

    forward_node80(v1029, v1044, v1037, v1036, v1035);	// L1194
    forward_node79(v1032, v1043, v1037, v1036, v1035);	// L1195
    forward_node78(v1030, v1042, v1040, v1039, v1036, v1038, v1035);	// L1196
    forward_node77(v1031, v1041, v1039, v1038, v1037, v1040);	// L1197
    float v1045[8][7][7];	// L1198
    #pragma HLS array_partition variable=v1045 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1045 core=ram_t2p_bram

    forward_node76(v1044, v1042, v1041, v1043, v1045, v1038, v1040, v1039);	// L1199
    forward_node75(v1045, v1033, v1037, v1036, v1035);	// L1200
  }
}

void forward_node82(
  float v1046[8][7][7],
  float v1047[256][14][14],
  int v1048,
  int v1049,
  int v1050
) {	// L1204
  #pragma HLS inline
  #pragma HLS resource variable=v1046 core=ram_t2p_bram

  for (int v1051 = 0; v1051 < 8; v1051 += 1) {	// L1205
    for (int v1052 = 0; v1052 < 7; v1052 += 1) {	// L1206
      for (int v1053 = 0; v1053 < 7; v1053 += 1) {	// L1207
        #pragma HLS pipeline II=1
        float v1054 = v1046[v1051][v1052][v1053];	// L1208
        v1047[(v1051 + (v1048 * 8))][(v1052 + (v1049 * 7))][(v1053 + (v1050 * 7))] = v1054;	// L1209
      }
    }
  }
}

void forward_node83(
  float v1055[256],
  float v1056[256],
  float v1057[256],
  float v1058[256],
  float v1059[256],
  float v1060[256],
  float v1061[256],
  float v1062[8][7][7],
  float v1063[8][7][7],
  float v1064[8][7][7],
  int v1065
) {	// L1215
  #pragma HLS inline
  #pragma HLS resource variable=v1055 core=ram_t2p_bram

  #pragma HLS resource variable=v1056 core=ram_t2p_bram

  #pragma HLS resource variable=v1057 core=ram_t2p_bram

  #pragma HLS resource variable=v1058 core=ram_t2p_bram

  #pragma HLS resource variable=v1059 core=ram_t2p_bram

  #pragma HLS resource variable=v1060 core=ram_t2p_bram

  #pragma HLS resource variable=v1061 core=ram_t2p_bram

  #pragma HLS resource variable=v1062 core=ram_t2p_bram

  #pragma HLS resource variable=v1063 core=ram_t2p_bram

  #pragma HLS resource variable=v1064 core=ram_t2p_bram

  for (int v1066 = 0; v1066 < 8; v1066 += 1) {	// L1218
    for (int v1067 = 0; v1067 < 7; v1067 += 1) {	// L1219
      for (int v1068 = 0; v1068 < 7; v1068 += 1) {	// L1220
        #pragma HLS pipeline II=1
        float v1069 = v1063[v1066][v1067][v1068];	// L1221
        float v1070 = v1056[(v1066 + (v1065 * 8))];	// L1222
        float v1071 = v1058[(v1066 + (v1065 * 8))];	// L1223
        float v1072 = v1055[(v1066 + (v1065 * 8))];	// L1224
        float v1073 = v1057[(v1066 + (v1065 * 8))];	// L1225
        float v1074 = v1062[v1066][v1067][v1068];	// L1226
        float v1075 = v1060[(v1066 + (v1065 * 8))];	// L1227
        float v1076 = v1061[(v1066 + (v1065 * 8))];	// L1228
        float v1077 = v1059[(v1066 + (v1065 * 8))];	// L1229
        float v1078 = (double)0.000010;	// L1230
        float v1079 = v1077 + v1078;	// L1231
        float v1080 = 1.0 / sqrt(v1079);	// L1232
        float v1081 = v1074 - v1076;	// L1233
        float v1082 = v1081 * v1080;	// L1234
        float v1083 = v1082 * v1075;	// L1235
        float v1084 = v1083 + v1071;	// L1236
        float v1085 = v1073 + v1078;	// L1237
        float v1086 = 1.0 / sqrt(v1085);	// L1238
        float v1087 = v1069 - v1072;	// L1239
        float v1088 = v1087 * v1086;	// L1240
        float v1089 = v1088 * v1070;	// L1241
        float v1090 = v1089 + v1071;	// L1242
        float v1091 = v1090 + v1084;	// L1243
        bool v1092 = v1091 > (float)0.000000;	// L1244
        float v1093 = v1092 ? v1091 : (float)0.000000;	// L1245
        v1064[v1066][v1067][v1068] = v1093;	// L1246
      }
    }
  }
}

void forward_node84(
  float v1094[256][14][14],
  float v1095[8][7][7],
  int v1096,
  int v1097,
  int v1098
) {	// L1252
  #pragma HLS inline
  #pragma HLS resource variable=v1095 core=ram_t2p_bram

  for (int v1099 = 0; v1099 < 8; v1099 += 1) {	// L1253
    for (int v1100 = 0; v1100 < 7; v1100 += 1) {	// L1254
      for (int v1101 = 0; v1101 < 7; v1101 += 1) {	// L1255
        #pragma HLS pipeline II=1
        float v1102 = v1094[(v1099 + (v1096 * 8))][(v1100 + (v1097 * 7))][(v1101 + (v1098 * 7))];	// L1256
        v1095[v1099][v1100][v1101] = v1102;	// L1257
      }
    }
  }
}

void forward_node85(
  float v1103[256][14][14],
  float v1104[8][7][7],
  int v1105,
  int v1106,
  int v1107
) {	// L1263
  #pragma HLS inline
  #pragma HLS resource variable=v1104 core=ram_t2p_bram

  for (int v1108 = 0; v1108 < 8; v1108 += 1) {	// L1264
    for (int v1109 = 0; v1109 < 7; v1109 += 1) {	// L1265
      for (int v1110 = 0; v1110 < 7; v1110 += 1) {	// L1266
        #pragma HLS pipeline II=1
        float v1111 = v1103[(v1108 + (v1105 * 8))][(v1109 + (v1106 * 7))][(v1110 + (v1107 * 7))];	// L1267
        v1104[v1108][v1109][v1110] = v1111;	// L1268
      }
    }
  }
}

void forward_node81(
  float v1112[256],
  float v1113[256][14][14],
  float v1114[256][14][14],
  float v1115[256],
  float v1116[256],
  float v1117[256],
  float v1118[256],
  float v1119[256],
  float v1120[256],
  float v1121[256][14][14]
) {	// L1274
  #pragma HLS resource variable=v1112 core=ram_t2p_bram

  #pragma HLS resource variable=v1115 core=ram_t2p_bram

  #pragma HLS resource variable=v1116 core=ram_t2p_bram

  #pragma HLS resource variable=v1117 core=ram_t2p_bram

  #pragma HLS resource variable=v1118 core=ram_t2p_bram

  #pragma HLS resource variable=v1119 core=ram_t2p_bram

  #pragma HLS resource variable=v1120 core=ram_t2p_bram

  for (int v1122 = 0; v1122 < 128; v1122 += 1) {	// L1275
    #pragma HLS dataflow
    int v1123 = (v1122 % 2);	// L1276
    int v1124 = ((v1122 / 2) % 2);	// L1277
    int v1125 = ((v1122 / 2) / 2);	// L1278
    float v1126[8][7][7];	// L1279
    #pragma HLS resource variable=v1126 core=ram_t2p_bram

    float v1127[8][7][7];	// L1280
    #pragma HLS resource variable=v1127 core=ram_t2p_bram

    float v1128[8][7][7];	// L1281
    #pragma HLS resource variable=v1128 core=ram_t2p_bram

    forward_node85(v1113, v1128, v1125, v1124, v1123);	// L1282
    forward_node84(v1114, v1127, v1125, v1124, v1123);	// L1283
    forward_node83(v1116, v1117, v1119, v1118, v1120, v1115, v1112, v1127, v1128, v1126, v1125);	// L1284
    forward_node82(v1126, v1121, v1125, v1124, v1123);	// L1285
  }
}

void forward_node87(
  float v1129[8][7][7],
  float v1130[256][14][14],
  int v1131,
  int v1132,
  int v1133
) {	// L1289
  #pragma HLS inline
  #pragma HLS resource variable=v1129 core=ram_t2p_bram

  for (int v1134 = 0; v1134 < 8; v1134 += 1) {	// L1290
    for (int v1135 = 0; v1135 < 7; v1135 += 1) {	// L1291
      for (int v1136 = 0; v1136 < 7; v1136 += 1) {	// L1292
        #pragma HLS pipeline II=1
        float v1137 = v1129[v1134][v1135][v1136];	// L1293
        v1130[(v1134 + (v1131 * 8))][(v1135 + (v1132 * 7))][(v1136 + (v1133 * 7))] = v1137;	// L1294
      }
    }
  }
}

void forward_node88(
  float v1138[8][7][7],
  float v1139[8][7][7],
  float v1140[8][8],
  float v1141[8][7][7],
  float v1142[8][7][7],
  int v1143
) {	// L1300
  #pragma HLS inline
  #pragma HLS resource variable=v1138 core=ram_t2p_bram

  #pragma HLS resource variable=v1139 core=ram_t2p_bram

  #pragma HLS resource variable=v1140 core=ram_t2p_bram

  #pragma HLS resource variable=v1141 core=ram_t2p_bram

  #pragma HLS resource variable=v1142 core=ram_t2p_bram

  for (int v1144 = 0; v1144 < 8; v1144 += 1) {	// L1301
    for (int v1145 = 0; v1145 < 8; v1145 += 1) {	// L1302
      for (int v1146 = 0; v1146 < 7; v1146 += 1) {	// L1303
        for (int v1147 = 0; v1147 < 7; v1147 += 1) {	// L1304
          #pragma HLS pipeline II=1
          float v1148 = v1138[v1145][v1146][v1147];	// L1305
          float v1149 = v1141[v1145][v1146][v1147];	// L1306
          float v1150 = v1142[v1145][v1146][v1147];	// L1307
          float v1151 = (v1144 == 0) ? v1149 : v1150;	// L1308
          float v1152 = ((v1144 + (v1143 * 8)) == 0) ? v1148 : v1151;	// L1309
          float v1153 = v1139[v1144][v1146][v1147];	// L1310
          float v1154 = v1140[v1145][v1144];	// L1311
          float v1155 = v1153 * v1154;	// L1312
          float v1156 = v1152 + v1155;	// L1313
          v1142[v1145][v1146][v1147] = v1156;	// L1314
        }
      }
    }
  }
}

void forward_node89(
  float v1157[256][128],
  float v1158[8][8],
  int v1159,
  int v1160
) {	// L1321
  #pragma HLS inline
  #pragma HLS resource variable=v1158 core=ram_t2p_bram

  for (int v1161 = 0; v1161 < 8; v1161 += 1) {	// L1322
    for (int v1162 = 0; v1162 < 8; v1162 += 1) {	// L1323
      #pragma HLS pipeline II=1
      float v1163 = v1157[(v1161 + (v1159 * 8))][(v1162 + (v1160 * 8))];	// L1324
      v1158[v1161][v1162] = v1163;	// L1325
    }
  }
}

void forward_node90(
  float v1164[128][28][28],
  float v1165[8][7][7],
  int v1166,
  int v1167,
  int v1168
) {	// L1330
  #pragma HLS inline
  #pragma HLS resource variable=v1165 core=ram_t2p_bram

  for (int v1169 = 0; v1169 < 8; v1169 += 1) {	// L1331
    for (int v1170 = 0; v1170 < 7; v1170 += 1) {	// L1332
      for (int v1171 = 0; v1171 < 7; v1171 += 1) {	// L1333
        #pragma HLS pipeline II=1
        float v1172 = v1164[(v1169 + (v1166 * 8))][((v1170 * 2) + (v1167 * 14))][((v1171 * 2) + (v1168 * 14))];	// L1334
        v1165[v1169][v1170][v1171] = v1172;	// L1335
      }
    }
  }
}

void forward_node91(
  float v1173[256][14][14],
  float v1174[8][7][7],
  int v1175,
  int v1176,
  int v1177
) {	// L1341
  #pragma HLS inline
  #pragma HLS resource variable=v1174 core=ram_t2p_bram

  for (int v1178 = 0; v1178 < 8; v1178 += 1) {	// L1342
    for (int v1179 = 0; v1179 < 7; v1179 += 1) {	// L1343
      for (int v1180 = 0; v1180 < 7; v1180 += 1) {	// L1344
        #pragma HLS pipeline II=1
        float v1181 = v1173[(v1178 + (v1175 * 8))][(v1179 + (v1176 * 7))][(v1180 + (v1177 * 7))];	// L1345
        v1174[v1178][v1179][v1180] = v1181;	// L1346
      }
    }
  }
}

void forward_node92(
  float v1182[256][14][14],
  float v1183[8][7][7],
  int v1184,
  int v1185,
  int v1186
) {	// L1352
  #pragma HLS inline
  #pragma HLS resource variable=v1183 core=ram_t2p_bram

  for (int v1187 = 0; v1187 < 8; v1187 += 1) {	// L1353
    for (int v1188 = 0; v1188 < 7; v1188 += 1) {	// L1354
      for (int v1189 = 0; v1189 < 7; v1189 += 1) {	// L1355
        #pragma HLS pipeline II=1
        float v1190 = v1182[(v1187 + (v1184 * 8))][(v1188 + (v1185 * 7))][(v1189 + (v1186 * 7))];	// L1356
        v1183[v1187][v1188][v1189] = v1190;	// L1357
      }
    }
  }
}

void forward_node86(
  float v1191[256][14][14],
  float v1192[256][128],
  float v1193[128][28][28],
  float v1194[256][14][14],
  float v1195[256][14][14]
) {	// L1363
  for (int v1196 = 0; v1196 < 2048; v1196 += 1) {	// L1364
    #pragma HLS dataflow
    int v1197 = (v1196 % 2);	// L1365
    int v1198 = ((v1196 / 2) % 2);	// L1366
    int v1199 = (((v1196 / 2) / 2) % 32);	// L1367
    int v1200 = (((v1196 / 2) / 2) / 32);	// L1368
    float v1201[8][8];	// L1369
    #pragma HLS resource variable=v1201 core=ram_t2p_bram

    float v1202[8][7][7];	// L1370
    #pragma HLS resource variable=v1202 core=ram_t2p_bram

    float v1203[8][7][7];	// L1371
    #pragma HLS resource variable=v1203 core=ram_t2p_bram

    float v1204[8][7][7];	// L1372
    #pragma HLS resource variable=v1204 core=ram_t2p_bram

    forward_node92(v1191, v1204, v1199, v1198, v1197);	// L1373
    forward_node91(v1194, v1203, v1199, v1198, v1197);	// L1374
    forward_node90(v1193, v1202, v1200, v1198, v1197);	// L1375
    forward_node89(v1192, v1201, v1199, v1200);	// L1376
    float v1205[8][7][7];	// L1377
    #pragma HLS resource variable=v1205 core=ram_t2p_bram

    forward_node88(v1204, v1202, v1201, v1203, v1205, v1200);	// L1378
    forward_node87(v1205, v1195, v1199, v1198, v1197);	// L1379
  }
}

void forward_node94(
  float v1206[8][7][7],
  float v1207[256][14][14],
  int v1208,
  int v1209,
  int v1210
) {	// L1383
  #pragma HLS inline
  #pragma HLS array_partition variable=v1206 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1206 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1207 cyclic factor=2 dim=1

  for (int v1211 = 0; v1211 < 8; v1211 += 2) {	// L1384
    for (int v1212 = 0; v1212 < 7; v1212 += 1) {	// L1385
      for (int v1213 = 0; v1213 < 7; v1213 += 1) {	// L1386
        #pragma HLS pipeline II=1
        float v1214 = v1206[v1211][v1212][v1213];	// L1387
        v1207[(v1211 + (v1208 * 8))][(v1212 + (v1209 * 7))][(v1213 + (v1210 * 7))] = v1214;	// L1388
        float v1215 = v1206[(v1211 + 1)][v1212][v1213];	// L1389
        v1207[((v1211 + (v1208 * 8)) + 1)][(v1212 + (v1209 * 7))][(v1213 + (v1210 * 7))] = v1215;	// L1390
      }
    }
  }
}

void forward_node95(
  float v1216[8][7][7],
  float v1217[8][8],
  float v1218[8][7][7],
  float v1219[8][7][7],
  float v1220[8][7][7],
  int v1221,
  int v1222,
  int v1223
) {	// L1396
  #pragma HLS inline
  #pragma HLS array_partition variable=v1216 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1216 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1217 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1217 cyclic factor=2 dim=2
  #pragma HLS resource variable=v1217 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1218 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1218 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1219 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1219 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1220 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1220 core=ram_t2p_bram

  for (int v1224 = 0; v1224 < 8; v1224 += 2) {	// L1397
    for (int v1225 = 0; v1225 < 8; v1225 += 2) {	// L1398
      for (int v1226 = 0; v1226 < 7; v1226 += 1) {	// L1399
        for (int v1227 = 0; v1227 < 7; v1227 += 1) {	// L1400
          #pragma HLS pipeline II=1
          float v1228 = v1216[v1225][v1226][v1227];	// L1401
          float v1229 = v1219[v1225][v1226][v1227];	// L1402
          float v1230 = v1220[v1225][v1226][v1227];	// L1403
          float v1231 = (v1224 == 0) ? v1229 : v1230;	// L1404
          float v1232 = ((v1224 + (v1222 * 8)) == 0 && v1221 == 0 && v1223 == 0) ? v1228 : v1231;	// L1405
          float v1233 = v1218[v1224][v1226][v1227];	// L1406
          float v1234 = v1217[v1225][v1224];	// L1407
          float v1235 = v1233 * v1234;	// L1408
          float v1236 = v1232 + v1235;	// L1409
          float v1237 = v1216[(v1225 + 1)][v1226][v1227];	// L1410
          float v1238 = v1219[(v1225 + 1)][v1226][v1227];	// L1411
          float v1239 = v1220[(v1225 + 1)][v1226][v1227];	// L1412
          float v1240 = (v1224 == 0) ? v1238 : v1239;	// L1413
          float v1241 = ((v1224 + (v1222 * 8)) == 0 && v1221 == 0 && v1223 == 0) ? v1237 : v1240;	// L1414
          float v1242 = v1217[(v1225 + 1)][v1224];	// L1415
          float v1243 = v1233 * v1242;	// L1416
          float v1244 = v1241 + v1243;	// L1417
          int v1245 = (v1224 + 1);	// L1418
          float v1246 = (v1245 == 0) ? v1229 : v1236;	// L1419
          float v1247 = ((v1245 + (v1222 * 8)) == 0 && v1221 == 0 && v1223 == 0) ? v1228 : v1246;	// L1420
          float v1248 = v1218[(v1224 + 1)][v1226][v1227];	// L1421
          float v1249 = v1217[v1225][(v1224 + 1)];	// L1422
          float v1250 = v1248 * v1249;	// L1423
          float v1251 = v1247 + v1250;	// L1424
          v1220[v1225][v1226][v1227] = v1251;	// L1425
          float v1252 = (v1245 == 0) ? v1238 : v1244;	// L1426
          float v1253 = ((v1245 + (v1222 * 8)) == 0 && v1221 == 0 && v1223 == 0) ? v1237 : v1252;	// L1427
          float v1254 = v1217[(v1225 + 1)][(v1224 + 1)];	// L1428
          float v1255 = v1248 * v1254;	// L1429
          float v1256 = v1253 + v1255;	// L1430
          v1220[(v1225 + 1)][v1226][v1227] = v1256;	// L1431
        }
      }
    }
  }
}

void forward_node96(
  float v1257[256][256][3][3],
  float v1258[8][8],
  int v1259,
  int v1260,
  int v1261,
  int v1262
) {	// L1438
  #pragma HLS inline
  #pragma HLS array_partition variable=v1257 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1257 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v1258 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1258 cyclic factor=2 dim=2
  #pragma HLS resource variable=v1258 core=ram_t2p_bram

  for (int v1263 = 0; v1263 < 8; v1263 += 2) {	// L1439
    for (int v1264 = 0; v1264 < 8; v1264 += 2) {	// L1440
      #pragma HLS pipeline II=1
      float v1265 = v1257[(v1263 + (v1261 * 8))][(v1264 + (v1262 * 8))][v1259][v1260];	// L1441
      v1258[v1263][v1264] = v1265;	// L1442
      float v1266 = v1257[(v1263 + (v1261 * 8))][((v1264 + (v1262 * 8)) + 1)][v1259][v1260];	// L1443
      v1258[v1263][(v1264 + 1)] = v1266;	// L1444
      float v1267 = v1257[((v1263 + (v1261 * 8)) + 1)][(v1264 + (v1262 * 8))][v1259][v1260];	// L1445
      v1258[(v1263 + 1)][v1264] = v1267;	// L1446
      float v1268 = v1257[((v1263 + (v1261 * 8)) + 1)][((v1264 + (v1262 * 8)) + 1)][v1259][v1260];	// L1447
      v1258[(v1263 + 1)][(v1264 + 1)] = v1268;	// L1448
    }
  }
}

void forward_node97(
  float v1269[256][14][14],
  float v1270[8][7][7],
  int v1271,
  int v1272,
  int v1273,
  int v1274,
  int v1275
) {	// L1453
  #pragma HLS inline
  #pragma HLS array_partition variable=v1269 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1270 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1270 core=ram_t2p_bram

  for (int v1276 = 0; v1276 < 8; v1276 += 2) {	// L1454
    for (int v1277 = 0; v1277 < 7; v1277 += 1) {	// L1455
      for (int v1278 = 0; v1278 < 7; v1278 += 1) {	// L1456
        #pragma HLS pipeline II=1
        float v1279 = v1269[(v1276 + (v1271 * 8))][(((v1277 + v1272) + (v1273 * 7)) - 1)][(((v1278 + v1274) + (v1275 * 7)) - 1)];	// L1457
        v1270[v1276][v1277][v1278] = v1279;	// L1458
        float v1280 = v1269[((v1276 + (v1271 * 8)) + 1)][(((v1277 + v1272) + (v1273 * 7)) - 1)][(((v1278 + v1274) + (v1275 * 7)) - 1)];	// L1459
        v1270[(v1276 + 1)][v1277][v1278] = v1280;	// L1460
      }
    }
  }
}

void forward_node98(
  float v1281[256][14][14],
  float v1282[8][7][7],
  int v1283,
  int v1284,
  int v1285
) {	// L1466
  #pragma HLS inline
  #pragma HLS array_partition variable=v1281 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1282 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1282 core=ram_t2p_bram

  for (int v1286 = 0; v1286 < 8; v1286 += 2) {	// L1467
    for (int v1287 = 0; v1287 < 7; v1287 += 1) {	// L1468
      for (int v1288 = 0; v1288 < 7; v1288 += 1) {	// L1469
        #pragma HLS pipeline II=1
        float v1289 = v1281[(v1286 + (v1283 * 8))][(v1287 + (v1284 * 7))][(v1288 + (v1285 * 7))];	// L1470
        v1282[v1286][v1287][v1288] = v1289;	// L1471
        float v1290 = v1281[((v1286 + (v1283 * 8)) + 1)][(v1287 + (v1284 * 7))][(v1288 + (v1285 * 7))];	// L1472
        v1282[(v1286 + 1)][v1287][v1288] = v1290;	// L1473
      }
    }
  }
}

void forward_node99(
  float v1291[256][14][14],
  float v1292[8][7][7],
  int v1293,
  int v1294,
  int v1295
) {	// L1479
  #pragma HLS inline
  #pragma HLS array_partition variable=v1291 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1292 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1292 core=ram_t2p_bram

  for (int v1296 = 0; v1296 < 8; v1296 += 2) {	// L1480
    for (int v1297 = 0; v1297 < 7; v1297 += 1) {	// L1481
      for (int v1298 = 0; v1298 < 7; v1298 += 1) {	// L1482
        #pragma HLS pipeline II=1
        float v1299 = v1291[(v1296 + (v1293 * 8))][(v1297 + (v1294 * 7))][(v1298 + (v1295 * 7))];	// L1483
        v1292[v1296][v1297][v1298] = v1299;	// L1484
        float v1300 = v1291[((v1296 + (v1293 * 8)) + 1)][(v1297 + (v1294 * 7))][(v1298 + (v1295 * 7))];	// L1485
        v1292[(v1296 + 1)][v1297][v1298] = v1300;	// L1486
      }
    }
  }
}

void forward_node93(
  float v1301[256][14][14],
  float v1302[256][14][14],
  float v1303[256][256][3][3],
  float v1304[256][14][14],
  float v1305[256][14][14]
) {	// L1492
  #pragma HLS array_partition variable=v1301 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1302 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1303 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1303 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v1304 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1305 cyclic factor=2 dim=1

  for (int v1306 = 0; v1306 < 36864; v1306 += 1) {	// L1493
    #pragma HLS dataflow
    int v1307 = (v1306 % 2);	// L1494
    int v1308 = ((v1306 / 2) % 2);	// L1495
    int v1309 = (((v1306 / 2) / 2) % 32);	// L1496
    int v1310 = ((((v1306 / 2) / 2) / 32) % 3);	// L1497
    int v1311 = (((((v1306 / 2) / 2) / 32) / 3) % 3);	// L1498
    int v1312 = (((((v1306 / 2) / 2) / 32) / 3) / 3);	// L1499
    float v1313[8][8];	// L1500
    #pragma HLS array_partition variable=v1313 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v1313 cyclic factor=2 dim=2
    #pragma HLS resource variable=v1313 core=ram_t2p_bram

    float v1314[8][7][7];	// L1501
    #pragma HLS array_partition variable=v1314 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1314 core=ram_t2p_bram

    float v1315[8][7][7];	// L1502
    #pragma HLS array_partition variable=v1315 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1315 core=ram_t2p_bram

    float v1316[8][7][7];	// L1503
    #pragma HLS array_partition variable=v1316 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1316 core=ram_t2p_bram

    forward_node99(v1301, v1316, v1309, v1308, v1307);	// L1504
    forward_node98(v1304, v1315, v1309, v1308, v1307);	// L1505
    forward_node97(v1302, v1314, v1312, v1311, v1308, v1310, v1307);	// L1506
    forward_node96(v1303, v1313, v1311, v1310, v1309, v1312);	// L1507
    float v1317[8][7][7];	// L1508
    #pragma HLS array_partition variable=v1317 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1317 core=ram_t2p_bram

    forward_node95(v1316, v1313, v1314, v1315, v1317, v1311, v1312, v1310);	// L1509
    forward_node94(v1317, v1305, v1309, v1308, v1307);	// L1510
  }
}

void forward_node101(
  float v1318[8][7][7],
  float v1319[256][14][14],
  int v1320,
  int v1321,
  int v1322
) {	// L1514
  #pragma HLS inline
  #pragma HLS resource variable=v1318 core=ram_t2p_bram

  for (int v1323 = 0; v1323 < 8; v1323 += 1) {	// L1515
    for (int v1324 = 0; v1324 < 7; v1324 += 1) {	// L1516
      for (int v1325 = 0; v1325 < 7; v1325 += 1) {	// L1517
        #pragma HLS pipeline II=1
        float v1326 = v1318[v1323][v1324][v1325];	// L1518
        v1319[(v1323 + (v1320 * 8))][(v1324 + (v1321 * 7))][(v1325 + (v1322 * 7))] = v1326;	// L1519
      }
    }
  }
}

void forward_node102(
  float v1327[8][7][7],
  float v1328[256],
  float v1329[256],
  float v1330[256],
  float v1331[256],
  float v1332[8][7][7],
  int v1333
) {	// L1525
  #pragma HLS inline
  #pragma HLS resource variable=v1327 core=ram_t2p_bram

  #pragma HLS resource variable=v1328 core=ram_t2p_bram

  #pragma HLS resource variable=v1329 core=ram_t2p_bram

  #pragma HLS resource variable=v1330 core=ram_t2p_bram

  #pragma HLS resource variable=v1331 core=ram_t2p_bram

  #pragma HLS resource variable=v1332 core=ram_t2p_bram

  for (int v1334 = 0; v1334 < 8; v1334 += 1) {	// L1528
    for (int v1335 = 0; v1335 < 7; v1335 += 1) {	// L1529
      for (int v1336 = 0; v1336 < 7; v1336 += 1) {	// L1530
        #pragma HLS pipeline II=1
        float v1337 = v1327[v1334][v1335][v1336];	// L1531
        float v1338 = v1328[(v1334 + (v1333 * 8))];	// L1532
        float v1339 = v1331[(v1334 + (v1333 * 8))];	// L1533
        float v1340 = v1330[(v1334 + (v1333 * 8))];	// L1534
        float v1341 = v1329[(v1334 + (v1333 * 8))];	// L1535
        float v1342 = (double)0.000010;	// L1536
        float v1343 = v1341 + v1342;	// L1537
        float v1344 = 1.0 / sqrt(v1343);	// L1538
        float v1345 = v1337 - v1340;	// L1539
        float v1346 = v1345 * v1344;	// L1540
        float v1347 = v1346 * v1338;	// L1541
        float v1348 = v1347 + v1339;	// L1542
        bool v1349 = v1348 > (float)0.000000;	// L1543
        float v1350 = v1349 ? v1348 : (float)0.000000;	// L1544
        v1332[v1334][v1335][v1336] = v1350;	// L1545
      }
    }
  }
}

void forward_node103(
  float v1351[256][14][14],
  float v1352[8][7][7],
  int v1353,
  int v1354,
  int v1355
) {	// L1551
  #pragma HLS inline
  #pragma HLS resource variable=v1352 core=ram_t2p_bram

  for (int v1356 = 0; v1356 < 8; v1356 += 1) {	// L1552
    for (int v1357 = 0; v1357 < 7; v1357 += 1) {	// L1553
      for (int v1358 = 0; v1358 < 7; v1358 += 1) {	// L1554
        #pragma HLS pipeline II=1
        float v1359 = v1351[(v1356 + (v1353 * 8))][(v1357 + (v1354 * 7))][(v1358 + (v1355 * 7))];	// L1555
        v1352[v1356][v1357][v1358] = v1359;	// L1556
      }
    }
  }
}

void forward_node100(
  float v1360[256],
  float v1361[256],
  float v1362[256][14][14],
  float v1363[256],
  float v1364[256],
  float v1365[256][14][14]
) {	// L1562
  #pragma HLS resource variable=v1360 core=ram_t2p_bram

  #pragma HLS resource variable=v1361 core=ram_t2p_bram

  #pragma HLS resource variable=v1363 core=ram_t2p_bram

  #pragma HLS resource variable=v1364 core=ram_t2p_bram

  for (int v1366 = 0; v1366 < 128; v1366 += 1) {	// L1563
    #pragma HLS dataflow
    int v1367 = (v1366 % 2);	// L1564
    int v1368 = ((v1366 / 2) % 2);	// L1565
    int v1369 = ((v1366 / 2) / 2);	// L1566
    float v1370[8][7][7];	// L1567
    #pragma HLS resource variable=v1370 core=ram_t2p_bram

    float v1371[8][7][7];	// L1568
    #pragma HLS resource variable=v1371 core=ram_t2p_bram

    forward_node103(v1362, v1371, v1369, v1368, v1367);	// L1569
    forward_node102(v1371, v1360, v1361, v1364, v1363, v1370, v1369);	// L1570
    forward_node101(v1370, v1365, v1369, v1368, v1367);	// L1571
  }
}

void forward_node105(
  float v1372[8][7][7],
  float v1373[256][14][14],
  int v1374,
  int v1375,
  int v1376
) {	// L1575
  #pragma HLS inline
  #pragma HLS resource variable=v1372 core=ram_t2p_bram

  for (int v1377 = 0; v1377 < 8; v1377 += 1) {	// L1576
    for (int v1378 = 0; v1378 < 7; v1378 += 1) {	// L1577
      for (int v1379 = 0; v1379 < 7; v1379 += 1) {	// L1578
        #pragma HLS pipeline II=1
        float v1380 = v1372[v1377][v1378][v1379];	// L1579
        v1373[(v1377 + (v1374 * 8))][(v1378 + (v1375 * 7))][(v1379 + (v1376 * 7))] = v1380;	// L1580
      }
    }
  }
}

void forward_node106(
  float v1381[8][8],
  float v1382[8][7][7],
  float v1383[8][7][7],
  float v1384[8][7][7],
  float v1385[8][7][7],
  int v1386,
  int v1387,
  int v1388
) {	// L1586
  #pragma HLS inline
  #pragma HLS resource variable=v1381 core=ram_t2p_bram

  #pragma HLS resource variable=v1382 core=ram_t2p_bram

  #pragma HLS resource variable=v1383 core=ram_t2p_bram

  #pragma HLS resource variable=v1384 core=ram_t2p_bram

  #pragma HLS resource variable=v1385 core=ram_t2p_bram

  for (int v1389 = 0; v1389 < 8; v1389 += 1) {	// L1587
    for (int v1390 = 0; v1390 < 8; v1390 += 1) {	// L1588
      for (int v1391 = 0; v1391 < 7; v1391 += 1) {	// L1589
        for (int v1392 = 0; v1392 < 7; v1392 += 1) {	// L1590
          #pragma HLS pipeline II=1
          float v1393 = v1383[v1390][v1391][v1392];	// L1591
          float v1394 = v1384[v1390][v1391][v1392];	// L1592
          float v1395 = v1385[v1390][v1391][v1392];	// L1593
          float v1396 = (v1389 == 0) ? v1394 : v1395;	// L1594
          float v1397 = ((v1389 + (v1386 * 8)) == 0 && v1387 == 0 && v1388 == 0) ? v1393 : v1396;	// L1595
          float v1398 = v1382[v1389][v1391][v1392];	// L1596
          float v1399 = v1381[v1390][v1389];	// L1597
          float v1400 = v1398 * v1399;	// L1598
          float v1401 = v1397 + v1400;	// L1599
          v1385[v1390][v1391][v1392] = v1401;	// L1600
        }
      }
    }
  }
}

void forward_node107(
  float v1402[256][128][3][3],
  float v1403[8][8],
  int v1404,
  int v1405,
  int v1406,
  int v1407
) {	// L1607
  #pragma HLS inline
  #pragma HLS resource variable=v1403 core=ram_t2p_bram

  for (int v1408 = 0; v1408 < 8; v1408 += 1) {	// L1608
    for (int v1409 = 0; v1409 < 8; v1409 += 1) {	// L1609
      #pragma HLS pipeline II=1
      float v1410 = v1402[(v1408 + (v1406 * 8))][(v1409 + (v1407 * 8))][v1404][v1405];	// L1610
      v1403[v1408][v1409] = v1410;	// L1611
    }
  }
}

void forward_node108(
  float v1411[128][28][28],
  float v1412[8][7][7],
  int v1413,
  int v1414,
  int v1415,
  int v1416,
  int v1417
) {	// L1616
  #pragma HLS inline
  #pragma HLS resource variable=v1412 core=ram_t2p_bram

  for (int v1418 = 0; v1418 < 8; v1418 += 1) {	// L1617
    for (int v1419 = 0; v1419 < 7; v1419 += 1) {	// L1618
      for (int v1420 = 0; v1420 < 7; v1420 += 1) {	// L1619
        #pragma HLS pipeline II=1
        float v1421 = v1411[(v1418 + (v1413 * 8))][((((v1419 * 2) + v1414) + (v1415 * 14)) - 1)][((((v1420 * 2) + v1416) + (v1417 * 14)) - 1)];	// L1620
        v1412[v1418][v1419][v1420] = v1421;	// L1621
      }
    }
  }
}

void forward_node109(
  float v1422[256][14][14],
  float v1423[8][7][7],
  int v1424,
  int v1425,
  int v1426
) {	// L1627
  #pragma HLS inline
  #pragma HLS resource variable=v1423 core=ram_t2p_bram

  for (int v1427 = 0; v1427 < 8; v1427 += 1) {	// L1628
    for (int v1428 = 0; v1428 < 7; v1428 += 1) {	// L1629
      for (int v1429 = 0; v1429 < 7; v1429 += 1) {	// L1630
        #pragma HLS pipeline II=1
        float v1430 = v1422[(v1427 + (v1424 * 8))][(v1428 + (v1425 * 7))][(v1429 + (v1426 * 7))];	// L1631
        v1423[v1427][v1428][v1429] = v1430;	// L1632
      }
    }
  }
}

void forward_node110(
  float v1431[256][14][14],
  float v1432[8][7][7],
  int v1433,
  int v1434,
  int v1435
) {	// L1638
  #pragma HLS inline
  #pragma HLS resource variable=v1432 core=ram_t2p_bram

  for (int v1436 = 0; v1436 < 8; v1436 += 1) {	// L1639
    for (int v1437 = 0; v1437 < 7; v1437 += 1) {	// L1640
      for (int v1438 = 0; v1438 < 7; v1438 += 1) {	// L1641
        #pragma HLS pipeline II=1
        float v1439 = v1431[(v1436 + (v1433 * 8))][(v1437 + (v1434 * 7))][(v1438 + (v1435 * 7))];	// L1642
        v1432[v1436][v1437][v1438] = v1439;	// L1643
      }
    }
  }
}

void forward_node104(
  float v1440[256][14][14],
  float v1441[256][128][3][3],
  float v1442[128][28][28],
  float v1443[256][14][14],
  float v1444[256][14][14]
) {	// L1649
  for (int v1445 = 0; v1445 < 18432; v1445 += 1) {	// L1650
    #pragma HLS dataflow
    int v1446 = (v1445 % 2);	// L1651
    int v1447 = ((v1445 / 2) % 2);	// L1652
    int v1448 = (((v1445 / 2) / 2) % 32);	// L1653
    int v1449 = ((((v1445 / 2) / 2) / 32) % 3);	// L1654
    int v1450 = (((((v1445 / 2) / 2) / 32) / 3) % 3);	// L1655
    int v1451 = (((((v1445 / 2) / 2) / 32) / 3) / 3);	// L1656
    float v1452[8][8];	// L1657
    #pragma HLS resource variable=v1452 core=ram_t2p_bram

    float v1453[8][7][7];	// L1658
    #pragma HLS resource variable=v1453 core=ram_t2p_bram

    float v1454[8][7][7];	// L1659
    #pragma HLS resource variable=v1454 core=ram_t2p_bram

    float v1455[8][7][7];	// L1660
    #pragma HLS resource variable=v1455 core=ram_t2p_bram

    forward_node110(v1440, v1455, v1448, v1447, v1446);	// L1661
    forward_node109(v1443, v1454, v1448, v1447, v1446);	// L1662
    forward_node108(v1442, v1453, v1451, v1450, v1447, v1449, v1446);	// L1663
    forward_node107(v1441, v1452, v1450, v1449, v1448, v1451);	// L1664
    float v1456[8][7][7];	// L1665
    #pragma HLS resource variable=v1456 core=ram_t2p_bram

    forward_node106(v1452, v1453, v1455, v1454, v1456, v1451, v1450, v1449);	// L1666
    forward_node105(v1456, v1444, v1448, v1447, v1446);	// L1667
  }
}

void forward_node112(
  float v1457[8][7][7],
  float v1458[128][28][28],
  int v1459,
  int v1460,
  int v1461
) {	// L1671
  #pragma HLS inline
  #pragma HLS resource variable=v1457 core=ram_t2p_bram

  for (int v1462 = 0; v1462 < 8; v1462 += 1) {	// L1672
    for (int v1463 = 0; v1463 < 7; v1463 += 1) {	// L1673
      for (int v1464 = 0; v1464 < 7; v1464 += 1) {	// L1674
        #pragma HLS pipeline II=1
        float v1465 = v1457[v1462][v1463][v1464];	// L1675
        v1458[(v1462 + (v1459 * 8))][(v1463 + (v1460 * 7))][(v1464 + (v1461 * 7))] = v1465;	// L1676
      }
    }
  }
}

void forward_node113(
  float v1466[128],
  float v1467[128],
  float v1468[128],
  float v1469[128],
  float v1470[8][7][7],
  float v1471[8][7][7],
  float v1472[8][7][7],
  int v1473
) {	// L1682
  #pragma HLS inline
  #pragma HLS resource variable=v1466 core=ram_t2p_bram

  #pragma HLS resource variable=v1467 core=ram_t2p_bram

  #pragma HLS resource variable=v1468 core=ram_t2p_bram

  #pragma HLS resource variable=v1469 core=ram_t2p_bram

  #pragma HLS resource variable=v1470 core=ram_t2p_bram

  #pragma HLS resource variable=v1471 core=ram_t2p_bram

  #pragma HLS resource variable=v1472 core=ram_t2p_bram

  for (int v1474 = 0; v1474 < 8; v1474 += 1) {	// L1685
    for (int v1475 = 0; v1475 < 7; v1475 += 1) {	// L1686
      for (int v1476 = 0; v1476 < 7; v1476 += 1) {	// L1687
        #pragma HLS pipeline II=1
        float v1477 = v1471[v1474][v1475][v1476];	// L1688
        float v1478 = v1469[(v1474 + (v1473 * 8))];	// L1689
        float v1479 = v1467[(v1474 + (v1473 * 8))];	// L1690
        float v1480 = v1468[(v1474 + (v1473 * 8))];	// L1691
        float v1481 = v1466[(v1474 + (v1473 * 8))];	// L1692
        float v1482 = v1470[v1474][v1475][v1476];	// L1693
        float v1483 = (double)0.000010;	// L1694
        float v1484 = v1481 + v1483;	// L1695
        float v1485 = 1.0 / sqrt(v1484);	// L1696
        float v1486 = v1477 - v1480;	// L1697
        float v1487 = v1486 * v1485;	// L1698
        float v1488 = v1487 * v1478;	// L1699
        float v1489 = v1488 + v1479;	// L1700
        float v1490 = v1489 + v1482;	// L1701
        bool v1491 = v1490 > (float)0.000000;	// L1702
        float v1492 = v1491 ? v1490 : (float)0.000000;	// L1703
        v1472[v1474][v1475][v1476] = v1492;	// L1704
      }
    }
  }
}

void forward_node114(
  float v1493[128][28][28],
  float v1494[8][7][7],
  int v1495,
  int v1496,
  int v1497
) {	// L1710
  #pragma HLS inline
  #pragma HLS resource variable=v1494 core=ram_t2p_bram

  for (int v1498 = 0; v1498 < 8; v1498 += 1) {	// L1711
    for (int v1499 = 0; v1499 < 7; v1499 += 1) {	// L1712
      for (int v1500 = 0; v1500 < 7; v1500 += 1) {	// L1713
        #pragma HLS pipeline II=1
        float v1501 = v1493[(v1498 + (v1495 * 8))][(v1499 + (v1496 * 7))][(v1500 + (v1497 * 7))];	// L1714
        v1494[v1498][v1499][v1500] = v1501;	// L1715
      }
    }
  }
}

void forward_node115(
  float v1502[128][28][28],
  float v1503[8][7][7],
  int v1504,
  int v1505,
  int v1506
) {	// L1721
  #pragma HLS inline
  #pragma HLS resource variable=v1503 core=ram_t2p_bram

  for (int v1507 = 0; v1507 < 8; v1507 += 1) {	// L1722
    for (int v1508 = 0; v1508 < 7; v1508 += 1) {	// L1723
      for (int v1509 = 0; v1509 < 7; v1509 += 1) {	// L1724
        #pragma HLS pipeline II=1
        float v1510 = v1502[(v1507 + (v1504 * 8))][(v1508 + (v1505 * 7))][(v1509 + (v1506 * 7))];	// L1725
        v1503[v1507][v1508][v1509] = v1510;	// L1726
      }
    }
  }
}

void forward_node111(
  float v1511[128][28][28],
  float v1512[128],
  float v1513[128],
  float v1514[128],
  float v1515[128],
  float v1516[128][28][28],
  float v1517[128][28][28]
) {	// L1732
  #pragma HLS resource variable=v1512 core=ram_t2p_bram

  #pragma HLS resource variable=v1513 core=ram_t2p_bram

  #pragma HLS resource variable=v1514 core=ram_t2p_bram

  #pragma HLS resource variable=v1515 core=ram_t2p_bram

  for (int v1518 = 0; v1518 < 256; v1518 += 1) {	// L1733
    #pragma HLS dataflow
    int v1519 = (v1518 % 4);	// L1734
    int v1520 = ((v1518 / 4) % 4);	// L1735
    int v1521 = ((v1518 / 4) / 4);	// L1736
    float v1522[8][7][7];	// L1737
    #pragma HLS resource variable=v1522 core=ram_t2p_bram

    float v1523[8][7][7];	// L1738
    #pragma HLS resource variable=v1523 core=ram_t2p_bram

    float v1524[8][7][7];	// L1739
    #pragma HLS resource variable=v1524 core=ram_t2p_bram

    forward_node115(v1516, v1524, v1521, v1520, v1519);	// L1740
    forward_node114(v1511, v1523, v1521, v1520, v1519);	// L1741
    forward_node113(v1515, v1513, v1514, v1512, v1523, v1524, v1522, v1521);	// L1742
    forward_node112(v1522, v1517, v1521, v1520, v1519);	// L1743
  }
}

void forward_node117(
  float v1525[8][7][7],
  float v1526[128][28][28],
  int v1527,
  int v1528,
  int v1529
) {	// L1747
  #pragma HLS inline
  #pragma HLS array_partition variable=v1525 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1525 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1526 cyclic factor=2 dim=1

  for (int v1530 = 0; v1530 < 8; v1530 += 2) {	// L1748
    for (int v1531 = 0; v1531 < 7; v1531 += 1) {	// L1749
      for (int v1532 = 0; v1532 < 7; v1532 += 1) {	// L1750
        #pragma HLS pipeline II=1
        float v1533 = v1525[v1530][v1531][v1532];	// L1751
        v1526[(v1530 + (v1527 * 8))][(v1531 + (v1528 * 7))][(v1532 + (v1529 * 7))] = v1533;	// L1752
        float v1534 = v1525[(v1530 + 1)][v1531][v1532];	// L1753
        v1526[((v1530 + (v1527 * 8)) + 1)][(v1531 + (v1528 * 7))][(v1532 + (v1529 * 7))] = v1534;	// L1754
      }
    }
  }
}

void forward_node118(
  float v1535[8][7][7],
  float v1536[8][8],
  float v1537[8][7][7],
  float v1538[8][7][7]
) {	// L1760
  #pragma HLS inline
  #pragma HLS array_partition variable=v1535 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1535 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1536 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1536 cyclic factor=2 dim=2
  #pragma HLS resource variable=v1536 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1537 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1537 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1538 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1538 core=ram_t2p_bram

  for (int v1539 = 0; v1539 < 8; v1539 += 2) {	// L1761
    for (int v1540 = 0; v1540 < 8; v1540 += 2) {	// L1762
      for (int v1541 = 0; v1541 < 7; v1541 += 1) {	// L1763
        for (int v1542 = 0; v1542 < 7; v1542 += 1) {	// L1764
          #pragma HLS pipeline II=1
          float v1543 = v1535[v1539][v1541][v1542];	// L1765
          float v1544 = v1536[v1540][v1539];	// L1766
          float v1545 = v1537[v1540][v1541][v1542];	// L1767
          float v1546 = v1538[v1540][v1541][v1542];	// L1768
          float v1547 = (v1539 == 0) ? v1545 : v1546;	// L1769
          float v1548 = v1543 * v1544;	// L1770
          float v1549 = v1547 + v1548;	// L1771
          float v1550 = v1536[(v1540 + 1)][v1539];	// L1772
          float v1551 = v1537[(v1540 + 1)][v1541][v1542];	// L1773
          float v1552 = v1538[(v1540 + 1)][v1541][v1542];	// L1774
          float v1553 = (v1539 == 0) ? v1551 : v1552;	// L1775
          float v1554 = v1543 * v1550;	// L1776
          float v1555 = v1553 + v1554;	// L1777
          int v1556 = (v1539 + 1);	// L1778
          float v1557 = v1535[(v1539 + 1)][v1541][v1542];	// L1779
          float v1558 = v1536[v1540][(v1539 + 1)];	// L1780
          float v1559 = (v1556 == 0) ? v1545 : v1549;	// L1781
          float v1560 = v1557 * v1558;	// L1782
          float v1561 = v1559 + v1560;	// L1783
          v1538[v1540][v1541][v1542] = v1561;	// L1784
          float v1562 = v1536[(v1540 + 1)][(v1539 + 1)];	// L1785
          float v1563 = (v1556 == 0) ? v1551 : v1555;	// L1786
          float v1564 = v1557 * v1562;	// L1787
          float v1565 = v1563 + v1564;	// L1788
          v1538[(v1540 + 1)][v1541][v1542] = v1565;	// L1789
        }
      }
    }
  }
}

void forward_node119(
  float v1566[128][28][28],
  float v1567[8][7][7],
  int v1568,
  int v1569,
  int v1570
) {	// L1796
  #pragma HLS inline
  #pragma HLS array_partition variable=v1566 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1567 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1567 core=ram_t2p_bram

  for (int v1571 = 0; v1571 < 8; v1571 += 2) {	// L1797
    for (int v1572 = 0; v1572 < 7; v1572 += 1) {	// L1798
      for (int v1573 = 0; v1573 < 7; v1573 += 1) {	// L1799
        #pragma HLS pipeline II=1
        float v1574 = v1566[(v1571 + (v1568 * 8))][(v1572 + (v1569 * 7))][(v1573 + (v1570 * 7))];	// L1800
        v1567[v1571][v1572][v1573] = v1574;	// L1801
        float v1575 = v1566[((v1571 + (v1568 * 8)) + 1)][(v1572 + (v1569 * 7))][(v1573 + (v1570 * 7))];	// L1802
        v1567[(v1571 + 1)][v1572][v1573] = v1575;	// L1803
      }
    }
  }
}

void forward_node120(
  float v1576[128][128][3][3],
  float v1577[8][8],
  int v1578,
  int v1579,
  int v1580,
  int v1581
) {	// L1809
  #pragma HLS inline
  #pragma HLS array_partition variable=v1576 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1576 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v1577 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1577 cyclic factor=2 dim=2
  #pragma HLS resource variable=v1577 core=ram_t2p_bram

  for (int v1582 = 0; v1582 < 8; v1582 += 2) {	// L1810
    for (int v1583 = 0; v1583 < 8; v1583 += 2) {	// L1811
      #pragma HLS pipeline II=1
      float v1584 = v1576[(v1582 + (v1580 * 8))][(v1583 + (v1581 * 8))][v1578][v1579];	// L1812
      v1577[v1582][v1583] = v1584;	// L1813
      float v1585 = v1576[(v1582 + (v1580 * 8))][((v1583 + (v1581 * 8)) + 1)][v1578][v1579];	// L1814
      v1577[v1582][(v1583 + 1)] = v1585;	// L1815
      float v1586 = v1576[((v1582 + (v1580 * 8)) + 1)][(v1583 + (v1581 * 8))][v1578][v1579];	// L1816
      v1577[(v1582 + 1)][v1583] = v1586;	// L1817
      float v1587 = v1576[((v1582 + (v1580 * 8)) + 1)][((v1583 + (v1581 * 8)) + 1)][v1578][v1579];	// L1818
      v1577[(v1582 + 1)][(v1583 + 1)] = v1587;	// L1819
    }
  }
}

void forward_node121(
  float v1588[128][28][28],
  float v1589[8][7][7],
  int v1590,
  int v1591,
  int v1592,
  int v1593,
  int v1594
) {	// L1824
  #pragma HLS inline
  #pragma HLS array_partition variable=v1588 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1589 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1589 core=ram_t2p_bram

  for (int v1595 = 0; v1595 < 8; v1595 += 2) {	// L1825
    for (int v1596 = 0; v1596 < 7; v1596 += 1) {	// L1826
      for (int v1597 = 0; v1597 < 7; v1597 += 1) {	// L1827
        #pragma HLS pipeline II=1
        float v1598 = v1588[(v1595 + (v1590 * 8))][(((v1596 + v1591) + (v1592 * 7)) - 1)][(((v1597 + v1593) + (v1594 * 7)) - 1)];	// L1828
        v1589[v1595][v1596][v1597] = v1598;	// L1829
        float v1599 = v1588[((v1595 + (v1590 * 8)) + 1)][(((v1596 + v1591) + (v1592 * 7)) - 1)][(((v1597 + v1593) + (v1594 * 7)) - 1)];	// L1830
        v1589[(v1595 + 1)][v1596][v1597] = v1599;	// L1831
      }
    }
  }
}

void forward_node116(
  float v1600[128][28][28],
  float v1601[128][128][3][3],
  float v1602[128][28][28],
  float v1603[128][28][28]
) {	// L1837
  #pragma HLS array_partition variable=v1600 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1601 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1601 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v1602 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1603 cyclic factor=2 dim=1

  for (int v1604 = 0; v1604 < 36864; v1604 += 1) {	// L1838
    #pragma HLS dataflow
    int v1605 = (v1604 % 4);	// L1839
    int v1606 = ((v1604 / 4) % 4);	// L1840
    int v1607 = (((v1604 / 4) / 4) % 16);	// L1841
    int v1608 = ((((v1604 / 4) / 4) / 16) % 3);	// L1842
    int v1609 = (((((v1604 / 4) / 4) / 16) / 3) % 3);	// L1843
    int v1610 = (((((v1604 / 4) / 4) / 16) / 3) / 3);	// L1844
    float v1611[8][7][7];	// L1845
    #pragma HLS array_partition variable=v1611 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1611 core=ram_t2p_bram

    float v1612[8][8];	// L1846
    #pragma HLS array_partition variable=v1612 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v1612 cyclic factor=2 dim=2
    #pragma HLS resource variable=v1612 core=ram_t2p_bram

    float v1613[8][7][7];	// L1847
    #pragma HLS array_partition variable=v1613 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1613 core=ram_t2p_bram

    forward_node121(v1600, v1613, v1610, v1609, v1606, v1608, v1605);	// L1848
    forward_node120(v1601, v1612, v1609, v1608, v1607, v1610);	// L1849
    forward_node119(v1602, v1611, v1607, v1606, v1605);	// L1850
    float v1614[8][7][7];	// L1851
    #pragma HLS array_partition variable=v1614 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1614 core=ram_t2p_bram

    forward_node118(v1613, v1612, v1611, v1614);	// L1852
    forward_node117(v1614, v1603, v1607, v1606, v1605);	// L1853
  }
}

void forward_node123(
  float v1615[8][7][7],
  float v1616[128][28][28],
  int v1617,
  int v1618,
  int v1619
) {	// L1857
  #pragma HLS inline
  #pragma HLS resource variable=v1615 core=ram_t2p_bram

  for (int v1620 = 0; v1620 < 8; v1620 += 1) {	// L1858
    for (int v1621 = 0; v1621 < 7; v1621 += 1) {	// L1859
      for (int v1622 = 0; v1622 < 7; v1622 += 1) {	// L1860
        #pragma HLS pipeline II=1
        float v1623 = v1615[v1620][v1621][v1622];	// L1861
        v1616[(v1620 + (v1617 * 8))][(v1621 + (v1618 * 7))][(v1622 + (v1619 * 7))] = v1623;	// L1862
      }
    }
  }
}

void forward_node124(
  float v1624[8][7][7],
  float v1625[128],
  float v1626[128],
  float v1627[128],
  float v1628[128],
  float v1629[8][7][7],
  int v1630
) {	// L1868
  #pragma HLS inline
  #pragma HLS resource variable=v1624 core=ram_t2p_bram

  #pragma HLS resource variable=v1625 core=ram_t2p_bram

  #pragma HLS resource variable=v1626 core=ram_t2p_bram

  #pragma HLS resource variable=v1627 core=ram_t2p_bram

  #pragma HLS resource variable=v1628 core=ram_t2p_bram

  #pragma HLS resource variable=v1629 core=ram_t2p_bram

  for (int v1631 = 0; v1631 < 8; v1631 += 1) {	// L1871
    for (int v1632 = 0; v1632 < 7; v1632 += 1) {	// L1872
      for (int v1633 = 0; v1633 < 7; v1633 += 1) {	// L1873
        #pragma HLS pipeline II=1
        float v1634 = v1624[v1631][v1632][v1633];	// L1874
        float v1635 = v1627[(v1631 + (v1630 * 8))];	// L1875
        float v1636 = v1628[(v1631 + (v1630 * 8))];	// L1876
        float v1637 = v1625[(v1631 + (v1630 * 8))];	// L1877
        float v1638 = v1626[(v1631 + (v1630 * 8))];	// L1878
        float v1639 = (double)0.000010;	// L1879
        float v1640 = v1638 + v1639;	// L1880
        float v1641 = 1.0 / sqrt(v1640);	// L1881
        float v1642 = v1634 - v1637;	// L1882
        float v1643 = v1642 * v1641;	// L1883
        float v1644 = v1643 * v1635;	// L1884
        float v1645 = v1644 + v1636;	// L1885
        bool v1646 = v1645 > (float)0.000000;	// L1886
        float v1647 = v1646 ? v1645 : (float)0.000000;	// L1887
        v1629[v1631][v1632][v1633] = v1647;	// L1888
      }
    }
  }
}

void forward_node125(
  float v1648[128][28][28],
  float v1649[8][7][7],
  int v1650,
  int v1651,
  int v1652
) {	// L1894
  #pragma HLS inline
  #pragma HLS resource variable=v1649 core=ram_t2p_bram

  for (int v1653 = 0; v1653 < 8; v1653 += 1) {	// L1895
    for (int v1654 = 0; v1654 < 7; v1654 += 1) {	// L1896
      for (int v1655 = 0; v1655 < 7; v1655 += 1) {	// L1897
        #pragma HLS pipeline II=1
        float v1656 = v1648[(v1653 + (v1650 * 8))][(v1654 + (v1651 * 7))][(v1655 + (v1652 * 7))];	// L1898
        v1649[v1653][v1654][v1655] = v1656;	// L1899
      }
    }
  }
}

void forward_node122(
  float v1657[128],
  float v1658[128],
  float v1659[128][28][28],
  float v1660[128],
  float v1661[128],
  float v1662[128][28][28]
) {	// L1905
  #pragma HLS resource variable=v1657 core=ram_t2p_bram

  #pragma HLS resource variable=v1658 core=ram_t2p_bram

  #pragma HLS resource variable=v1660 core=ram_t2p_bram

  #pragma HLS resource variable=v1661 core=ram_t2p_bram

  for (int v1663 = 0; v1663 < 256; v1663 += 1) {	// L1906
    #pragma HLS dataflow
    int v1664 = (v1663 % 4);	// L1907
    int v1665 = ((v1663 / 4) % 4);	// L1908
    int v1666 = ((v1663 / 4) / 4);	// L1909
    float v1667[8][7][7];	// L1910
    #pragma HLS resource variable=v1667 core=ram_t2p_bram

    float v1668[8][7][7];	// L1911
    #pragma HLS resource variable=v1668 core=ram_t2p_bram

    forward_node125(v1659, v1668, v1666, v1665, v1664);	// L1912
    forward_node124(v1668, v1660, v1661, v1657, v1658, v1667, v1666);	// L1913
    forward_node123(v1667, v1662, v1666, v1665, v1664);	// L1914
  }
}

void forward_node127(
  float v1669[8][7][7],
  float v1670[128][28][28],
  int v1671,
  int v1672,
  int v1673
) {	// L1918
  #pragma HLS inline
  #pragma HLS array_partition variable=v1669 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1669 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1670 cyclic factor=2 dim=1

  for (int v1674 = 0; v1674 < 8; v1674 += 2) {	// L1919
    for (int v1675 = 0; v1675 < 7; v1675 += 1) {	// L1920
      for (int v1676 = 0; v1676 < 7; v1676 += 1) {	// L1921
        #pragma HLS pipeline II=1
        float v1677 = v1669[v1674][v1675][v1676];	// L1922
        v1670[(v1674 + (v1671 * 8))][(v1675 + (v1672 * 7))][(v1676 + (v1673 * 7))] = v1677;	// L1923
        float v1678 = v1669[(v1674 + 1)][v1675][v1676];	// L1924
        v1670[((v1674 + (v1671 * 8)) + 1)][(v1675 + (v1672 * 7))][(v1676 + (v1673 * 7))] = v1678;	// L1925
      }
    }
  }
}

void forward_node128(
  float v1679[8][7][7],
  float v1680[8][8],
  float v1681[8][7][7],
  float v1682[8][7][7],
  float v1683[8][7][7],
  int v1684,
  int v1685,
  int v1686
) {	// L1931
  #pragma HLS inline
  #pragma HLS array_partition variable=v1679 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1679 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1680 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1680 cyclic factor=2 dim=2
  #pragma HLS resource variable=v1680 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1681 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1681 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1682 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1682 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1683 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1683 core=ram_t2p_bram

  for (int v1687 = 0; v1687 < 8; v1687 += 2) {	// L1932
    for (int v1688 = 0; v1688 < 8; v1688 += 2) {	// L1933
      for (int v1689 = 0; v1689 < 7; v1689 += 1) {	// L1934
        for (int v1690 = 0; v1690 < 7; v1690 += 1) {	// L1935
          #pragma HLS pipeline II=1
          float v1691 = v1681[v1688][v1689][v1690];	// L1936
          float v1692 = v1682[v1688][v1689][v1690];	// L1937
          float v1693 = v1683[v1688][v1689][v1690];	// L1938
          float v1694 = (v1687 == 0) ? v1692 : v1693;	// L1939
          float v1695 = ((v1687 + (v1686 * 8)) == 0 && v1684 == 0 && v1685 == 0) ? v1691 : v1694;	// L1940
          float v1696 = v1679[v1687][v1689][v1690];	// L1941
          float v1697 = v1680[v1688][v1687];	// L1942
          float v1698 = v1696 * v1697;	// L1943
          float v1699 = v1695 + v1698;	// L1944
          float v1700 = v1681[(v1688 + 1)][v1689][v1690];	// L1945
          float v1701 = v1682[(v1688 + 1)][v1689][v1690];	// L1946
          float v1702 = v1683[(v1688 + 1)][v1689][v1690];	// L1947
          float v1703 = (v1687 == 0) ? v1701 : v1702;	// L1948
          float v1704 = ((v1687 + (v1686 * 8)) == 0 && v1684 == 0 && v1685 == 0) ? v1700 : v1703;	// L1949
          float v1705 = v1680[(v1688 + 1)][v1687];	// L1950
          float v1706 = v1696 * v1705;	// L1951
          float v1707 = v1704 + v1706;	// L1952
          int v1708 = (v1687 + 1);	// L1953
          float v1709 = (v1708 == 0) ? v1692 : v1699;	// L1954
          float v1710 = ((v1708 + (v1686 * 8)) == 0 && v1684 == 0 && v1685 == 0) ? v1691 : v1709;	// L1955
          float v1711 = v1679[(v1687 + 1)][v1689][v1690];	// L1956
          float v1712 = v1680[v1688][(v1687 + 1)];	// L1957
          float v1713 = v1711 * v1712;	// L1958
          float v1714 = v1710 + v1713;	// L1959
          v1683[v1688][v1689][v1690] = v1714;	// L1960
          float v1715 = (v1708 == 0) ? v1701 : v1707;	// L1961
          float v1716 = ((v1708 + (v1686 * 8)) == 0 && v1684 == 0 && v1685 == 0) ? v1700 : v1715;	// L1962
          float v1717 = v1680[(v1688 + 1)][(v1687 + 1)];	// L1963
          float v1718 = v1711 * v1717;	// L1964
          float v1719 = v1716 + v1718;	// L1965
          v1683[(v1688 + 1)][v1689][v1690] = v1719;	// L1966
        }
      }
    }
  }
}

void forward_node129(
  float v1720[128][128][3][3],
  float v1721[8][8],
  int v1722,
  int v1723,
  int v1724,
  int v1725
) {	// L1973
  #pragma HLS inline
  #pragma HLS array_partition variable=v1720 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1720 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v1721 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1721 cyclic factor=2 dim=2
  #pragma HLS resource variable=v1721 core=ram_t2p_bram

  for (int v1726 = 0; v1726 < 8; v1726 += 2) {	// L1974
    for (int v1727 = 0; v1727 < 8; v1727 += 2) {	// L1975
      #pragma HLS pipeline II=1
      float v1728 = v1720[(v1726 + (v1724 * 8))][(v1727 + (v1725 * 8))][v1722][v1723];	// L1976
      v1721[v1726][v1727] = v1728;	// L1977
      float v1729 = v1720[(v1726 + (v1724 * 8))][((v1727 + (v1725 * 8)) + 1)][v1722][v1723];	// L1978
      v1721[v1726][(v1727 + 1)] = v1729;	// L1979
      float v1730 = v1720[((v1726 + (v1724 * 8)) + 1)][(v1727 + (v1725 * 8))][v1722][v1723];	// L1980
      v1721[(v1726 + 1)][v1727] = v1730;	// L1981
      float v1731 = v1720[((v1726 + (v1724 * 8)) + 1)][((v1727 + (v1725 * 8)) + 1)][v1722][v1723];	// L1982
      v1721[(v1726 + 1)][(v1727 + 1)] = v1731;	// L1983
    }
  }
}

void forward_node130(
  float v1732[128][28][28],
  float v1733[8][7][7],
  int v1734,
  int v1735,
  int v1736,
  int v1737,
  int v1738
) {	// L1988
  #pragma HLS inline
  #pragma HLS array_partition variable=v1732 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1733 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1733 core=ram_t2p_bram

  for (int v1739 = 0; v1739 < 8; v1739 += 2) {	// L1989
    for (int v1740 = 0; v1740 < 7; v1740 += 1) {	// L1990
      for (int v1741 = 0; v1741 < 7; v1741 += 1) {	// L1991
        #pragma HLS pipeline II=1
        float v1742 = v1732[(v1739 + (v1734 * 8))][(((v1740 + v1735) + (v1736 * 7)) - 1)][(((v1741 + v1737) + (v1738 * 7)) - 1)];	// L1992
        v1733[v1739][v1740][v1741] = v1742;	// L1993
        float v1743 = v1732[((v1739 + (v1734 * 8)) + 1)][(((v1740 + v1735) + (v1736 * 7)) - 1)][(((v1741 + v1737) + (v1738 * 7)) - 1)];	// L1994
        v1733[(v1739 + 1)][v1740][v1741] = v1743;	// L1995
      }
    }
  }
}

void forward_node131(
  float v1744[128][28][28],
  float v1745[8][7][7],
  int v1746,
  int v1747,
  int v1748
) {	// L2001
  #pragma HLS inline
  #pragma HLS array_partition variable=v1744 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1745 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1745 core=ram_t2p_bram

  for (int v1749 = 0; v1749 < 8; v1749 += 2) {	// L2002
    for (int v1750 = 0; v1750 < 7; v1750 += 1) {	// L2003
      for (int v1751 = 0; v1751 < 7; v1751 += 1) {	// L2004
        #pragma HLS pipeline II=1
        float v1752 = v1744[(v1749 + (v1746 * 8))][(v1750 + (v1747 * 7))][(v1751 + (v1748 * 7))];	// L2005
        v1745[v1749][v1750][v1751] = v1752;	// L2006
        float v1753 = v1744[((v1749 + (v1746 * 8)) + 1)][(v1750 + (v1747 * 7))][(v1751 + (v1748 * 7))];	// L2007
        v1745[(v1749 + 1)][v1750][v1751] = v1753;	// L2008
      }
    }
  }
}

void forward_node132(
  float v1754[128][28][28],
  float v1755[8][7][7],
  int v1756,
  int v1757,
  int v1758
) {	// L2014
  #pragma HLS inline
  #pragma HLS array_partition variable=v1754 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1755 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1755 core=ram_t2p_bram

  for (int v1759 = 0; v1759 < 8; v1759 += 2) {	// L2015
    for (int v1760 = 0; v1760 < 7; v1760 += 1) {	// L2016
      for (int v1761 = 0; v1761 < 7; v1761 += 1) {	// L2017
        #pragma HLS pipeline II=1
        float v1762 = v1754[(v1759 + (v1756 * 8))][(v1760 + (v1757 * 7))][(v1761 + (v1758 * 7))];	// L2018
        v1755[v1759][v1760][v1761] = v1762;	// L2019
        float v1763 = v1754[((v1759 + (v1756 * 8)) + 1)][(v1760 + (v1757 * 7))][(v1761 + (v1758 * 7))];	// L2020
        v1755[(v1759 + 1)][v1760][v1761] = v1763;	// L2021
      }
    }
  }
}

void forward_node126(
  float v1764[128][28][28],
  float v1765[128][128][3][3],
  float v1766[128][28][28],
  float v1767[128][28][28],
  float v1768[128][28][28]
) {	// L2027
  #pragma HLS array_partition variable=v1764 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1765 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1765 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v1766 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1767 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v1768 cyclic factor=2 dim=1

  for (int v1769 = 0; v1769 < 36864; v1769 += 1) {	// L2028
    #pragma HLS dataflow
    int v1770 = (v1769 % 4);	// L2029
    int v1771 = ((v1769 / 4) % 4);	// L2030
    int v1772 = (((v1769 / 4) / 4) % 16);	// L2031
    int v1773 = ((((v1769 / 4) / 4) / 16) % 3);	// L2032
    int v1774 = (((((v1769 / 4) / 4) / 16) / 3) % 3);	// L2033
    int v1775 = (((((v1769 / 4) / 4) / 16) / 3) / 3);	// L2034
    float v1776[8][8];	// L2035
    #pragma HLS array_partition variable=v1776 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v1776 cyclic factor=2 dim=2
    #pragma HLS resource variable=v1776 core=ram_t2p_bram

    float v1777[8][7][7];	// L2036
    #pragma HLS array_partition variable=v1777 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1777 core=ram_t2p_bram

    float v1778[8][7][7];	// L2037
    #pragma HLS array_partition variable=v1778 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1778 core=ram_t2p_bram

    float v1779[8][7][7];	// L2038
    #pragma HLS array_partition variable=v1779 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1779 core=ram_t2p_bram

    forward_node132(v1766, v1779, v1772, v1771, v1770);	// L2039
    forward_node131(v1767, v1778, v1772, v1771, v1770);	// L2040
    forward_node130(v1764, v1777, v1775, v1774, v1771, v1773, v1770);	// L2041
    forward_node129(v1765, v1776, v1774, v1773, v1772, v1775);	// L2042
    float v1780[8][7][7];	// L2043
    #pragma HLS array_partition variable=v1780 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1780 core=ram_t2p_bram

    forward_node128(v1777, v1776, v1779, v1778, v1780, v1774, v1773, v1775);	// L2044
    forward_node127(v1780, v1768, v1772, v1771, v1770);	// L2045
  }
}

void forward_node134(
  float v1781[8][7][7],
  float v1782[128][28][28],
  int v1783,
  int v1784,
  int v1785
) {	// L2049
  #pragma HLS inline
  #pragma HLS resource variable=v1781 core=ram_t2p_bram

  for (int v1786 = 0; v1786 < 8; v1786 += 1) {	// L2050
    for (int v1787 = 0; v1787 < 7; v1787 += 1) {	// L2051
      for (int v1788 = 0; v1788 < 7; v1788 += 1) {	// L2052
        #pragma HLS pipeline II=1
        float v1789 = v1781[v1786][v1787][v1788];	// L2053
        v1782[(v1786 + (v1783 * 8))][(v1787 + (v1784 * 7))][(v1788 + (v1785 * 7))] = v1789;	// L2054
      }
    }
  }
}

void forward_node135(
  float v1790[128],
  float v1791[8][7][7],
  float v1792[128],
  float v1793[128],
  float v1794[8][7][7],
  float v1795[128],
  float v1796[128],
  float v1797[128],
  float v1798[128],
  float v1799[8][7][7],
  int v1800
) {	// L2060
  #pragma HLS inline
  #pragma HLS resource variable=v1790 core=ram_t2p_bram

  #pragma HLS resource variable=v1791 core=ram_t2p_bram

  #pragma HLS resource variable=v1792 core=ram_t2p_bram

  #pragma HLS resource variable=v1793 core=ram_t2p_bram

  #pragma HLS resource variable=v1794 core=ram_t2p_bram

  #pragma HLS resource variable=v1795 core=ram_t2p_bram

  #pragma HLS resource variable=v1796 core=ram_t2p_bram

  #pragma HLS resource variable=v1797 core=ram_t2p_bram

  #pragma HLS resource variable=v1798 core=ram_t2p_bram

  #pragma HLS resource variable=v1799 core=ram_t2p_bram

  for (int v1801 = 0; v1801 < 8; v1801 += 1) {	// L2063
    for (int v1802 = 0; v1802 < 7; v1802 += 1) {	// L2064
      for (int v1803 = 0; v1803 < 7; v1803 += 1) {	// L2065
        #pragma HLS pipeline II=1
        float v1804 = v1794[v1801][v1802][v1803];	// L2066
        float v1805 = v1797[(v1801 + (v1800 * 8))];	// L2067
        float v1806 = v1793[(v1801 + (v1800 * 8))];	// L2068
        float v1807 = v1798[(v1801 + (v1800 * 8))];	// L2069
        float v1808 = v1796[(v1801 + (v1800 * 8))];	// L2070
        float v1809 = v1791[v1801][v1802][v1803];	// L2071
        float v1810 = v1790[(v1801 + (v1800 * 8))];	// L2072
        float v1811 = v1795[(v1801 + (v1800 * 8))];	// L2073
        float v1812 = v1792[(v1801 + (v1800 * 8))];	// L2074
        float v1813 = (double)0.000010;	// L2075
        float v1814 = v1812 + v1813;	// L2076
        float v1815 = 1.0 / sqrt(v1814);	// L2077
        float v1816 = v1809 - v1811;	// L2078
        float v1817 = v1816 * v1815;	// L2079
        float v1818 = v1817 * v1810;	// L2080
        float v1819 = v1818 + v1806;	// L2081
        float v1820 = v1808 + v1813;	// L2082
        float v1821 = 1.0 / sqrt(v1820);	// L2083
        float v1822 = v1804 - v1807;	// L2084
        float v1823 = v1822 * v1821;	// L2085
        float v1824 = v1823 * v1805;	// L2086
        float v1825 = v1824 + v1806;	// L2087
        float v1826 = v1825 + v1819;	// L2088
        bool v1827 = v1826 > (float)0.000000;	// L2089
        float v1828 = v1827 ? v1826 : (float)0.000000;	// L2090
        v1799[v1801][v1802][v1803] = v1828;	// L2091
      }
    }
  }
}

void forward_node136(
  float v1829[128][28][28],
  float v1830[8][7][7],
  int v1831,
  int v1832,
  int v1833
) {	// L2097
  #pragma HLS inline
  #pragma HLS resource variable=v1830 core=ram_t2p_bram

  for (int v1834 = 0; v1834 < 8; v1834 += 1) {	// L2098
    for (int v1835 = 0; v1835 < 7; v1835 += 1) {	// L2099
      for (int v1836 = 0; v1836 < 7; v1836 += 1) {	// L2100
        #pragma HLS pipeline II=1
        float v1837 = v1829[(v1834 + (v1831 * 8))][(v1835 + (v1832 * 7))][(v1836 + (v1833 * 7))];	// L2101
        v1830[v1834][v1835][v1836] = v1837;	// L2102
      }
    }
  }
}

void forward_node137(
  float v1838[128][28][28],
  float v1839[8][7][7],
  int v1840,
  int v1841,
  int v1842
) {	// L2108
  #pragma HLS inline
  #pragma HLS resource variable=v1839 core=ram_t2p_bram

  for (int v1843 = 0; v1843 < 8; v1843 += 1) {	// L2109
    for (int v1844 = 0; v1844 < 7; v1844 += 1) {	// L2110
      for (int v1845 = 0; v1845 < 7; v1845 += 1) {	// L2111
        #pragma HLS pipeline II=1
        float v1846 = v1838[(v1843 + (v1840 * 8))][(v1844 + (v1841 * 7))][(v1845 + (v1842 * 7))];	// L2112
        v1839[v1843][v1844][v1845] = v1846;	// L2113
      }
    }
  }
}

void forward_node133(
  float v1847[128],
  float v1848[128],
  float v1849[128][28][28],
  float v1850[128],
  float v1851[128][28][28],
  float v1852[128],
  float v1853[128],
  float v1854[128],
  float v1855[128],
  float v1856[128][28][28]
) {	// L2119
  #pragma HLS resource variable=v1847 core=ram_t2p_bram

  #pragma HLS resource variable=v1848 core=ram_t2p_bram

  #pragma HLS resource variable=v1850 core=ram_t2p_bram

  #pragma HLS resource variable=v1852 core=ram_t2p_bram

  #pragma HLS resource variable=v1853 core=ram_t2p_bram

  #pragma HLS resource variable=v1854 core=ram_t2p_bram

  #pragma HLS resource variable=v1855 core=ram_t2p_bram

  for (int v1857 = 0; v1857 < 256; v1857 += 1) {	// L2120
    #pragma HLS dataflow
    int v1858 = (v1857 % 4);	// L2121
    int v1859 = ((v1857 / 4) % 4);	// L2122
    int v1860 = ((v1857 / 4) / 4);	// L2123
    float v1861[8][7][7];	// L2124
    #pragma HLS resource variable=v1861 core=ram_t2p_bram

    float v1862[8][7][7];	// L2125
    #pragma HLS resource variable=v1862 core=ram_t2p_bram

    float v1863[8][7][7];	// L2126
    #pragma HLS resource variable=v1863 core=ram_t2p_bram

    forward_node137(v1849, v1863, v1860, v1859, v1858);	// L2127
    forward_node136(v1851, v1862, v1860, v1859, v1858);	// L2128
    forward_node135(v1852, v1862, v1853, v1855, v1863, v1854, v1850, v1847, v1848, v1861, v1860);	// L2129
    forward_node134(v1861, v1856, v1860, v1859, v1858);	// L2130
  }
}

void forward_node139(
  float v1864[8][7][7],
  float v1865[128][28][28],
  int v1866,
  int v1867,
  int v1868
) {	// L2134
  #pragma HLS inline
  #pragma HLS resource variable=v1864 core=ram_t2p_bram

  for (int v1869 = 0; v1869 < 8; v1869 += 1) {	// L2135
    for (int v1870 = 0; v1870 < 7; v1870 += 1) {	// L2136
      for (int v1871 = 0; v1871 < 7; v1871 += 1) {	// L2137
        #pragma HLS pipeline II=1
        float v1872 = v1864[v1869][v1870][v1871];	// L2138
        v1865[(v1869 + (v1866 * 8))][(v1870 + (v1867 * 7))][(v1871 + (v1868 * 7))] = v1872;	// L2139
      }
    }
  }
}

void forward_node140(
  float v1873[8][7][7],
  float v1874[8][7][7],
  float v1875[8][8],
  float v1876[8][7][7],
  float v1877[8][7][7],
  int v1878
) {	// L2145
  #pragma HLS inline
  #pragma HLS resource variable=v1873 core=ram_t2p_bram

  #pragma HLS resource variable=v1874 core=ram_t2p_bram

  #pragma HLS resource variable=v1875 core=ram_t2p_bram

  #pragma HLS resource variable=v1876 core=ram_t2p_bram

  #pragma HLS resource variable=v1877 core=ram_t2p_bram

  for (int v1879 = 0; v1879 < 8; v1879 += 1) {	// L2146
    for (int v1880 = 0; v1880 < 8; v1880 += 1) {	// L2147
      for (int v1881 = 0; v1881 < 7; v1881 += 1) {	// L2148
        for (int v1882 = 0; v1882 < 7; v1882 += 1) {	// L2149
          #pragma HLS pipeline II=1
          float v1883 = v1873[v1880][v1881][v1882];	// L2150
          float v1884 = v1876[v1880][v1881][v1882];	// L2151
          float v1885 = v1877[v1880][v1881][v1882];	// L2152
          float v1886 = (v1879 == 0) ? v1884 : v1885;	// L2153
          float v1887 = ((v1879 + (v1878 * 8)) == 0) ? v1883 : v1886;	// L2154
          float v1888 = v1874[v1879][v1881][v1882];	// L2155
          float v1889 = v1875[v1880][v1879];	// L2156
          float v1890 = v1888 * v1889;	// L2157
          float v1891 = v1887 + v1890;	// L2158
          v1877[v1880][v1881][v1882] = v1891;	// L2159
        }
      }
    }
  }
}

void forward_node141(
  float v1892[128][64],
  float v1893[8][8],
  int v1894,
  int v1895
) {	// L2166
  #pragma HLS inline
  #pragma HLS resource variable=v1893 core=ram_t2p_bram

  for (int v1896 = 0; v1896 < 8; v1896 += 1) {	// L2167
    for (int v1897 = 0; v1897 < 8; v1897 += 1) {	// L2168
      #pragma HLS pipeline II=1
      float v1898 = v1892[(v1896 + (v1894 * 8))][(v1897 + (v1895 * 8))];	// L2169
      v1893[v1896][v1897] = v1898;	// L2170
    }
  }
}

void forward_node142(
  float v1899[64][56][56],
  float v1900[8][7][7],
  int v1901,
  int v1902,
  int v1903
) {	// L2175
  #pragma HLS inline
  #pragma HLS resource variable=v1900 core=ram_t2p_bram

  for (int v1904 = 0; v1904 < 8; v1904 += 1) {	// L2176
    for (int v1905 = 0; v1905 < 7; v1905 += 1) {	// L2177
      for (int v1906 = 0; v1906 < 7; v1906 += 1) {	// L2178
        #pragma HLS pipeline II=1
        float v1907 = v1899[(v1904 + (v1901 * 8))][((v1905 * 2) + (v1902 * 14))][((v1906 * 2) + (v1903 * 14))];	// L2179
        v1900[v1904][v1905][v1906] = v1907;	// L2180
      }
    }
  }
}

void forward_node143(
  float v1908[128][28][28],
  float v1909[8][7][7],
  int v1910,
  int v1911,
  int v1912
) {	// L2186
  #pragma HLS inline
  #pragma HLS resource variable=v1909 core=ram_t2p_bram

  for (int v1913 = 0; v1913 < 8; v1913 += 1) {	// L2187
    for (int v1914 = 0; v1914 < 7; v1914 += 1) {	// L2188
      for (int v1915 = 0; v1915 < 7; v1915 += 1) {	// L2189
        #pragma HLS pipeline II=1
        float v1916 = v1908[(v1913 + (v1910 * 8))][(v1914 + (v1911 * 7))][(v1915 + (v1912 * 7))];	// L2190
        v1909[v1913][v1914][v1915] = v1916;	// L2191
      }
    }
  }
}

void forward_node144(
  float v1917[128][28][28],
  float v1918[8][7][7],
  int v1919,
  int v1920,
  int v1921
) {	// L2197
  #pragma HLS inline
  #pragma HLS resource variable=v1918 core=ram_t2p_bram

  for (int v1922 = 0; v1922 < 8; v1922 += 1) {	// L2198
    for (int v1923 = 0; v1923 < 7; v1923 += 1) {	// L2199
      for (int v1924 = 0; v1924 < 7; v1924 += 1) {	// L2200
        #pragma HLS pipeline II=1
        float v1925 = v1917[(v1922 + (v1919 * 8))][(v1923 + (v1920 * 7))][(v1924 + (v1921 * 7))];	// L2201
        v1918[v1922][v1923][v1924] = v1925;	// L2202
      }
    }
  }
}

void forward_node138(
  float v1926[64][56][56],
  float v1927[128][28][28],
  float v1928[128][64],
  float v1929[128][28][28],
  float v1930[128][28][28]
) {	// L2208
  for (int v1931 = 0; v1931 < 2048; v1931 += 1) {	// L2209
    #pragma HLS dataflow
    int v1932 = (v1931 % 4);	// L2210
    int v1933 = ((v1931 / 4) % 4);	// L2211
    int v1934 = (((v1931 / 4) / 4) % 16);	// L2212
    int v1935 = (((v1931 / 4) / 4) / 16);	// L2213
    float v1936[8][8];	// L2214
    #pragma HLS resource variable=v1936 core=ram_t2p_bram

    float v1937[8][7][7];	// L2215
    #pragma HLS resource variable=v1937 core=ram_t2p_bram

    float v1938[8][7][7];	// L2216
    #pragma HLS resource variable=v1938 core=ram_t2p_bram

    float v1939[8][7][7];	// L2217
    #pragma HLS resource variable=v1939 core=ram_t2p_bram

    forward_node144(v1927, v1939, v1934, v1933, v1932);	// L2218
    forward_node143(v1929, v1938, v1934, v1933, v1932);	// L2219
    forward_node142(v1926, v1937, v1935, v1933, v1932);	// L2220
    forward_node141(v1928, v1936, v1934, v1935);	// L2221
    float v1940[8][7][7];	// L2222
    #pragma HLS resource variable=v1940 core=ram_t2p_bram

    forward_node140(v1939, v1937, v1936, v1938, v1940, v1935);	// L2223
    forward_node139(v1940, v1930, v1934, v1933, v1932);	// L2224
  }
}

void forward_node146(
  float v1941[8][7][7],
  float v1942[128][28][28],
  int v1943,
  int v1944,
  int v1945
) {	// L2228
  #pragma HLS inline
  #pragma HLS array_partition variable=v1941 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1941 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1942 cyclic factor=2 dim=1

  for (int v1946 = 0; v1946 < 8; v1946 += 2) {	// L2229
    for (int v1947 = 0; v1947 < 7; v1947 += 1) {	// L2230
      for (int v1948 = 0; v1948 < 7; v1948 += 1) {	// L2231
        #pragma HLS pipeline II=1
        float v1949 = v1941[v1946][v1947][v1948];	// L2232
        v1942[(v1946 + (v1943 * 8))][(v1947 + (v1944 * 7))][(v1948 + (v1945 * 7))] = v1949;	// L2233
        float v1950 = v1941[(v1946 + 1)][v1947][v1948];	// L2234
        v1942[((v1946 + (v1943 * 8)) + 1)][(v1947 + (v1944 * 7))][(v1948 + (v1945 * 7))] = v1950;	// L2235
      }
    }
  }
}

void forward_node147(
  float v1951[8][8],
  float v1952[8][7][7],
  float v1953[8][7][7],
  float v1954[8][7][7],
  float v1955[8][7][7],
  int v1956,
  int v1957,
  int v1958
) {	// L2241
  #pragma HLS inline
  #pragma HLS array_partition variable=v1951 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1951 cyclic factor=2 dim=2
  #pragma HLS resource variable=v1951 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1952 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1952 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1953 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1953 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1954 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1954 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1955 cyclic factor=2 dim=1
  #pragma HLS resource variable=v1955 core=ram_t2p_bram

  for (int v1959 = 0; v1959 < 8; v1959 += 2) {	// L2242
    for (int v1960 = 0; v1960 < 8; v1960 += 2) {	// L2243
      for (int v1961 = 0; v1961 < 7; v1961 += 1) {	// L2244
        for (int v1962 = 0; v1962 < 7; v1962 += 1) {	// L2245
          #pragma HLS pipeline II=1
          float v1963 = v1952[v1960][v1961][v1962];	// L2246
          float v1964 = v1954[v1960][v1961][v1962];	// L2247
          float v1965 = v1955[v1960][v1961][v1962];	// L2248
          float v1966 = (v1959 == 0) ? v1964 : v1965;	// L2249
          float v1967 = ((v1959 + (v1957 * 8)) == 0 && v1958 == 0 && v1956 == 0) ? v1963 : v1966;	// L2250
          float v1968 = v1953[v1959][v1961][v1962];	// L2251
          float v1969 = v1951[v1960][v1959];	// L2252
          float v1970 = v1968 * v1969;	// L2253
          float v1971 = v1967 + v1970;	// L2254
          float v1972 = v1952[(v1960 + 1)][v1961][v1962];	// L2255
          float v1973 = v1954[(v1960 + 1)][v1961][v1962];	// L2256
          float v1974 = v1955[(v1960 + 1)][v1961][v1962];	// L2257
          float v1975 = (v1959 == 0) ? v1973 : v1974;	// L2258
          float v1976 = ((v1959 + (v1957 * 8)) == 0 && v1958 == 0 && v1956 == 0) ? v1972 : v1975;	// L2259
          float v1977 = v1951[(v1960 + 1)][v1959];	// L2260
          float v1978 = v1968 * v1977;	// L2261
          float v1979 = v1976 + v1978;	// L2262
          int v1980 = (v1959 + 1);	// L2263
          float v1981 = (v1980 == 0) ? v1964 : v1971;	// L2264
          float v1982 = ((v1980 + (v1957 * 8)) == 0 && v1958 == 0 && v1956 == 0) ? v1963 : v1981;	// L2265
          float v1983 = v1953[(v1959 + 1)][v1961][v1962];	// L2266
          float v1984 = v1951[v1960][(v1959 + 1)];	// L2267
          float v1985 = v1983 * v1984;	// L2268
          float v1986 = v1982 + v1985;	// L2269
          v1955[v1960][v1961][v1962] = v1986;	// L2270
          float v1987 = (v1980 == 0) ? v1973 : v1979;	// L2271
          float v1988 = ((v1980 + (v1957 * 8)) == 0 && v1958 == 0 && v1956 == 0) ? v1972 : v1987;	// L2272
          float v1989 = v1951[(v1960 + 1)][(v1959 + 1)];	// L2273
          float v1990 = v1983 * v1989;	// L2274
          float v1991 = v1988 + v1990;	// L2275
          v1955[(v1960 + 1)][v1961][v1962] = v1991;	// L2276
        }
      }
    }
  }
}

void forward_node148(
  float v1992[128][128][3][3],
  float v1993[8][8],
  int v1994,
  int v1995,
  int v1996,
  int v1997
) {	// L2283
  #pragma HLS inline
  #pragma HLS array_partition variable=v1992 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1992 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v1993 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1993 cyclic factor=2 dim=2
  #pragma HLS resource variable=v1993 core=ram_t2p_bram

  for (int v1998 = 0; v1998 < 8; v1998 += 2) {	// L2284
    for (int v1999 = 0; v1999 < 8; v1999 += 2) {	// L2285
      #pragma HLS pipeline II=1
      float v2000 = v1992[(v1998 + (v1996 * 8))][(v1999 + (v1997 * 8))][v1994][v1995];	// L2286
      v1993[v1998][v1999] = v2000;	// L2287
      float v2001 = v1992[(v1998 + (v1996 * 8))][((v1999 + (v1997 * 8)) + 1)][v1994][v1995];	// L2288
      v1993[v1998][(v1999 + 1)] = v2001;	// L2289
      float v2002 = v1992[((v1998 + (v1996 * 8)) + 1)][(v1999 + (v1997 * 8))][v1994][v1995];	// L2290
      v1993[(v1998 + 1)][v1999] = v2002;	// L2291
      float v2003 = v1992[((v1998 + (v1996 * 8)) + 1)][((v1999 + (v1997 * 8)) + 1)][v1994][v1995];	// L2292
      v1993[(v1998 + 1)][(v1999 + 1)] = v2003;	// L2293
    }
  }
}

void forward_node149(
  float v2004[128][28][28],
  float v2005[8][7][7],
  int v2006,
  int v2007,
  int v2008,
  int v2009,
  int v2010
) {	// L2298
  #pragma HLS inline
  #pragma HLS array_partition variable=v2004 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v2005 cyclic factor=2 dim=1
  #pragma HLS resource variable=v2005 core=ram_t2p_bram

  for (int v2011 = 0; v2011 < 8; v2011 += 2) {	// L2299
    for (int v2012 = 0; v2012 < 7; v2012 += 1) {	// L2300
      for (int v2013 = 0; v2013 < 7; v2013 += 1) {	// L2301
        #pragma HLS pipeline II=1
        float v2014 = v2004[(v2011 + (v2006 * 8))][(((v2012 + v2007) + (v2008 * 7)) - 1)][(((v2013 + v2009) + (v2010 * 7)) - 1)];	// L2302
        v2005[v2011][v2012][v2013] = v2014;	// L2303
        float v2015 = v2004[((v2011 + (v2006 * 8)) + 1)][(((v2012 + v2007) + (v2008 * 7)) - 1)][(((v2013 + v2009) + (v2010 * 7)) - 1)];	// L2304
        v2005[(v2011 + 1)][v2012][v2013] = v2015;	// L2305
      }
    }
  }
}

void forward_node150(
  float v2016[128][28][28],
  float v2017[8][7][7],
  int v2018,
  int v2019,
  int v2020
) {	// L2311
  #pragma HLS inline
  #pragma HLS array_partition variable=v2016 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v2017 cyclic factor=2 dim=1
  #pragma HLS resource variable=v2017 core=ram_t2p_bram

  for (int v2021 = 0; v2021 < 8; v2021 += 2) {	// L2312
    for (int v2022 = 0; v2022 < 7; v2022 += 1) {	// L2313
      for (int v2023 = 0; v2023 < 7; v2023 += 1) {	// L2314
        #pragma HLS pipeline II=1
        float v2024 = v2016[(v2021 + (v2018 * 8))][(v2022 + (v2019 * 7))][(v2023 + (v2020 * 7))];	// L2315
        v2017[v2021][v2022][v2023] = v2024;	// L2316
        float v2025 = v2016[((v2021 + (v2018 * 8)) + 1)][(v2022 + (v2019 * 7))][(v2023 + (v2020 * 7))];	// L2317
        v2017[(v2021 + 1)][v2022][v2023] = v2025;	// L2318
      }
    }
  }
}

void forward_node151(
  float v2026[128][28][28],
  float v2027[8][7][7],
  int v2028,
  int v2029,
  int v2030
) {	// L2324
  #pragma HLS inline
  #pragma HLS array_partition variable=v2026 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v2027 cyclic factor=2 dim=1
  #pragma HLS resource variable=v2027 core=ram_t2p_bram

  for (int v2031 = 0; v2031 < 8; v2031 += 2) {	// L2325
    for (int v2032 = 0; v2032 < 7; v2032 += 1) {	// L2326
      for (int v2033 = 0; v2033 < 7; v2033 += 1) {	// L2327
        #pragma HLS pipeline II=1
        float v2034 = v2026[(v2031 + (v2028 * 8))][(v2032 + (v2029 * 7))][(v2033 + (v2030 * 7))];	// L2328
        v2027[v2031][v2032][v2033] = v2034;	// L2329
        float v2035 = v2026[((v2031 + (v2028 * 8)) + 1)][(v2032 + (v2029 * 7))][(v2033 + (v2030 * 7))];	// L2330
        v2027[(v2031 + 1)][v2032][v2033] = v2035;	// L2331
      }
    }
  }
}

void forward_node145(
  float v2036[128][128][3][3],
  float v2037[128][28][28],
  float v2038[128][28][28],
  float v2039[128][28][28],
  float v2040[128][28][28]
) {	// L2337
  #pragma HLS array_partition variable=v2036 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v2036 cyclic factor=2 dim=2

  #pragma HLS array_partition variable=v2037 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v2038 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v2039 cyclic factor=2 dim=1

  #pragma HLS array_partition variable=v2040 cyclic factor=2 dim=1

  for (int v2041 = 0; v2041 < 36864; v2041 += 1) {	// L2338
    #pragma HLS dataflow
    int v2042 = (v2041 % 4);	// L2339
    int v2043 = ((v2041 / 4) % 4);	// L2340
    int v2044 = (((v2041 / 4) / 4) % 16);	// L2341
    int v2045 = ((((v2041 / 4) / 4) / 16) % 3);	// L2342
    int v2046 = (((((v2041 / 4) / 4) / 16) / 3) % 3);	// L2343
    int v2047 = (((((v2041 / 4) / 4) / 16) / 3) / 3);	// L2344
    float v2048[8][8];	// L2345
    #pragma HLS array_partition variable=v2048 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v2048 cyclic factor=2 dim=2
    #pragma HLS resource variable=v2048 core=ram_t2p_bram

    float v2049[8][7][7];	// L2346
    #pragma HLS array_partition variable=v2049 cyclic factor=2 dim=1
    #pragma HLS resource variable=v2049 core=ram_t2p_bram

    float v2050[8][7][7];	// L2347
    #pragma HLS array_partition variable=v2050 cyclic factor=2 dim=1
    #pragma HLS resource variable=v2050 core=ram_t2p_bram

    float v2051[8][7][7];	// L2348
    #pragma HLS array_partition variable=v2051 cyclic factor=2 dim=1
    #pragma HLS resource variable=v2051 core=ram_t2p_bram

    forward_node151(v2038, v2051, v2044, v2043, v2042);	// L2349
    forward_node150(v2039, v2050, v2044, v2043, v2042);	// L2350
    forward_node149(v2037, v2049, v2047, v2046, v2043, v2045, v2042);	// L2351
    forward_node148(v2036, v2048, v2046, v2045, v2044, v2047);	// L2352
    float v2052[8][7][7];	// L2353
    #pragma HLS array_partition variable=v2052 cyclic factor=2 dim=1
    #pragma HLS resource variable=v2052 core=ram_t2p_bram

    forward_node147(v2048, v2051, v2049, v2050, v2052, v2045, v2047, v2046);	// L2354
    forward_node146(v2052, v2040, v2044, v2043, v2042);	// L2355
  }
}

void forward_node153(
  float v2053[8][7][7],
  float v2054[128][28][28],
  int v2055,
  int v2056,
  int v2057
) {	// L2359
  #pragma HLS inline
  #pragma HLS resource variable=v2053 core=ram_t2p_bram

  for (int v2058 = 0; v2058 < 8; v2058 += 1) {	// L2360
    for (int v2059 = 0; v2059 < 7; v2059 += 1) {	// L2361
      for (int v2060 = 0; v2060 < 7; v2060 += 1) {	// L2362
        #pragma HLS pipeline II=1
        float v2061 = v2053[v2058][v2059][v2060];	// L2363
        v2054[(v2058 + (v2055 * 8))][(v2059 + (v2056 * 7))][(v2060 + (v2057 * 7))] = v2061;	// L2364
      }
    }
  }
}

void forward_node154(
  float v2062[128],
  float v2063[128],
  float v2064[128],
  float v2065[8][7][7],
  float v2066[128],
  float v2067[8][7][7],
  int v2068
) {	// L2370
  #pragma HLS inline
  #pragma HLS resource variable=v2062 core=ram_t2p_bram

  #pragma HLS resource variable=v2063 core=ram_t2p_bram

  #pragma HLS resource variable=v2064 core=ram_t2p_bram

  #pragma HLS resource variable=v2065 core=ram_t2p_bram

  #pragma HLS resource variable=v2066 core=ram_t2p_bram

  #pragma HLS resource variable=v2067 core=ram_t2p_bram

  for (int v2069 = 0; v2069 < 8; v2069 += 1) {	// L2373
    for (int v2070 = 0; v2070 < 7; v2070 += 1) {	// L2374
      for (int v2071 = 0; v2071 < 7; v2071 += 1) {	// L2375
        #pragma HLS pipeline II=1
        float v2072 = v2065[v2069][v2070][v2071];	// L2376
        float v2073 = v2066[(v2069 + (v2068 * 8))];	// L2377
        float v2074 = v2062[(v2069 + (v2068 * 8))];	// L2378
        float v2075 = v2064[(v2069 + (v2068 * 8))];	// L2379
        float v2076 = v2063[(v2069 + (v2068 * 8))];	// L2380
        float v2077 = (double)0.000010;	// L2381
        float v2078 = v2076 + v2077;	// L2382
        float v2079 = 1.0 / sqrt(v2078);	// L2383
        float v2080 = v2072 - v2075;	// L2384
        float v2081 = v2080 * v2079;	// L2385
        float v2082 = v2081 * v2073;	// L2386
        float v2083 = v2082 + v2074;	// L2387
        bool v2084 = v2083 > (float)0.000000;	// L2388
        float v2085 = v2084 ? v2083 : (float)0.000000;	// L2389
        v2067[v2069][v2070][v2071] = v2085;	// L2390
      }
    }
  }
}

void forward_node155(
  float v2086[128][28][28],
  float v2087[8][7][7],
  int v2088,
  int v2089,
  int v2090
) {	// L2396
  #pragma HLS inline
  #pragma HLS resource variable=v2087 core=ram_t2p_bram

  for (int v2091 = 0; v2091 < 8; v2091 += 1) {	// L2397
    for (int v2092 = 0; v2092 < 7; v2092 += 1) {	// L2398
      for (int v2093 = 0; v2093 < 7; v2093 += 1) {	// L2399
        #pragma HLS pipeline II=1
        float v2094 = v2086[(v2091 + (v2088 * 8))][(v2092 + (v2089 * 7))][(v2093 + (v2090 * 7))];	// L2400
        v2087[v2091][v2092][v2093] = v2094;	// L2401
      }
    }
  }
}

void forward_node152(
  float v2095[128],
  float v2096[128][28][28],
  float v2097[128],
  float v2098[128],
  float v2099[128],
  float v2100[128][28][28]
) {	// L2407
  #pragma HLS resource variable=v2095 core=ram_t2p_bram

  #pragma HLS resource variable=v2097 core=ram_t2p_bram

  #pragma HLS resource variable=v2098 core=ram_t2p_bram

  #pragma HLS resource variable=v2099 core=ram_t2p_bram

  for (int v2101 = 0; v2101 < 256; v2101 += 1) {	// L2408
    #pragma HLS dataflow
    int v2102 = (v2101 % 4);	// L2409
    int v2103 = ((v2101 / 4) % 4);	// L2410
    int v2104 = ((v2101 / 4) / 4);	// L2411
    float v2105[8][7][7];	// L2412
    #pragma HLS resource variable=v2105 core=ram_t2p_bram

    float v2106[8][7][7];	// L2413
    #pragma HLS resource variable=v2106 core=ram_t2p_bram

    forward_node155(v2096, v2106, v2104, v2103, v2102);	// L2414
    forward_node154(v2098, v2097, v2099, v2106, v2095, v2105, v2104);	// L2415
    forward_node153(v2105, v2100, v2104, v2103, v2102);	// L2416
  }
}

void forward_node157(
  float v2107[8][7][7],
  float v2108[128][28][28],
  int v2109,
  int v2110,
  int v2111
) {	// L2420
  #pragma HLS inline
  #pragma HLS resource variable=v2107 core=ram_t2p_bram

  for (int v2112 = 0; v2112 < 8; v2112 += 1) {	// L2421
    for (int v2113 = 0; v2113 < 7; v2113 += 1) {	// L2422
      for (int v2114 = 0; v2114 < 7; v2114 += 1) {	// L2423
        #pragma HLS pipeline II=1
        float v2115 = v2107[v2112][v2113][v2114];	// L2424
        v2108[(v2112 + (v2109 * 8))][(v2113 + (v2110 * 7))][(v2114 + (v2111 * 7))] = v2115;	// L2425
      }
    }
  }
}

void forward_node158(
  float v2116[8][8],
  float v2117[8][7][7],
  float v2118[8][7][7],
  float v2119[8][7][7],
  float v2120[8][7][7],
  int v2121,
  int v2122,
  int v2123
) {	// L2431
  #pragma HLS inline
  #pragma HLS resource variable=v2116 core=ram_t2p_bram

  #pragma HLS resource variable=v2117 core=ram_t2p_bram

  #pragma HLS resource variable=v2118 core=ram_t2p_bram

  #pragma HLS resource variable=v2119 core=ram_t2p_bram

  #pragma HLS resource variable=v2120 core=ram_t2p_bram

  for (int v2124 = 0; v2124 < 8; v2124 += 1) {	// L2432
    for (int v2125 = 0; v2125 < 8; v2125 += 1) {	// L2433
      for (int v2126 = 0; v2126 < 7; v2126 += 1) {	// L2434
        for (int v2127 = 0; v2127 < 7; v2127 += 1) {	// L2435
          #pragma HLS pipeline II=1
          float v2128 = v2117[v2125][v2126][v2127];	// L2436
          float v2129 = v2119[v2125][v2126][v2127];	// L2437
          float v2130 = v2120[v2125][v2126][v2127];	// L2438
          float v2131 = (v2124 == 0) ? v2129 : v2130;	// L2439
          float v2132 = ((v2124 + (v2123 * 8)) == 0 && v2122 == 0 && v2121 == 0) ? v2128 : v2131;	// L2440
          float v2133 = v2118[v2124][v2126][v2127];	// L2441
          float v2134 = v2116[v2125][v2124];	// L2442
          float v2135 = v2133 * v2134;	// L2443
          float v2136 = v2132 + v2135;	// L2444
          v2120[v2125][v2126][v2127] = v2136;	// L2445
        }
      }
    }
  }
}

void forward_node159(
  float v2137[128][64][3][3],
  float v2138[8][8],
  int v2139,
  int v2140,
  int v2141,
  int v2142
) {	// L2452
  #pragma HLS inline
  #pragma HLS resource variable=v2138 core=ram_t2p_bram

  for (int v2143 = 0; v2143 < 8; v2143 += 1) {	// L2453
    for (int v2144 = 0; v2144 < 8; v2144 += 1) {	// L2454
      #pragma HLS pipeline II=1
      float v2145 = v2137[(v2143 + (v2141 * 8))][(v2144 + (v2142 * 8))][v2139][v2140];	// L2455
      v2138[v2143][v2144] = v2145;	// L2456
    }
  }
}

void forward_node160(
  float v2146[64][56][56],
  float v2147[8][7][7],
  int v2148,
  int v2149,
  int v2150,
  int v2151,
  int v2152
) {	// L2461
  #pragma HLS inline
  #pragma HLS resource variable=v2147 core=ram_t2p_bram

  for (int v2153 = 0; v2153 < 8; v2153 += 1) {	// L2462
    for (int v2154 = 0; v2154 < 7; v2154 += 1) {	// L2463
      for (int v2155 = 0; v2155 < 7; v2155 += 1) {	// L2464
        #pragma HLS pipeline II=1
        float v2156 = v2146[(v2153 + (v2148 * 8))][((((v2154 * 2) + v2149) + (v2150 * 14)) - 1)][((((v2155 * 2) + v2151) + (v2152 * 14)) - 1)];	// L2465
        v2147[v2153][v2154][v2155] = v2156;	// L2466
      }
    }
  }
}

void forward_node161(
  float v2157[128][28][28],
  float v2158[8][7][7],
  int v2159,
  int v2160,
  int v2161
) {	// L2472
  #pragma HLS inline
  #pragma HLS resource variable=v2158 core=ram_t2p_bram

  for (int v2162 = 0; v2162 < 8; v2162 += 1) {	// L2473
    for (int v2163 = 0; v2163 < 7; v2163 += 1) {	// L2474
      for (int v2164 = 0; v2164 < 7; v2164 += 1) {	// L2475
        #pragma HLS pipeline II=1
        float v2165 = v2157[(v2162 + (v2159 * 8))][(v2163 + (v2160 * 7))][(v2164 + (v2161 * 7))];	// L2476
        v2158[v2162][v2163][v2164] = v2165;	// L2477
      }
    }
  }
}

void forward_node162(
  float v2166[128][28][28],
  float v2167[8][7][7],
  int v2168,
  int v2169,
  int v2170
) {	// L2483
  #pragma HLS inline
  #pragma HLS resource variable=v2167 core=ram_t2p_bram

  for (int v2171 = 0; v2171 < 8; v2171 += 1) {	// L2484
    for (int v2172 = 0; v2172 < 7; v2172 += 1) {	// L2485
      for (int v2173 = 0; v2173 < 7; v2173 += 1) {	// L2486
        #pragma HLS pipeline II=1
        float v2174 = v2166[(v2171 + (v2168 * 8))][(v2172 + (v2169 * 7))][(v2173 + (v2170 * 7))];	// L2487
        v2167[v2171][v2172][v2173] = v2174;	// L2488
      }
    }
  }
}

void forward_node156(
  float v2175[128][64][3][3],
  float v2176[64][56][56],
  float v2177[128][28][28],
  float v2178[128][28][28],
  float v2179[128][28][28]
) {	// L2494
  for (int v2180 = 0; v2180 < 18432; v2180 += 1) {	// L2495
    #pragma HLS dataflow
    int v2181 = (v2180 % 4);	// L2496
    int v2182 = ((v2180 / 4) % 4);	// L2497
    int v2183 = (((v2180 / 4) / 4) % 16);	// L2498
    int v2184 = ((((v2180 / 4) / 4) / 16) % 3);	// L2499
    int v2185 = (((((v2180 / 4) / 4) / 16) / 3) % 3);	// L2500
    int v2186 = (((((v2180 / 4) / 4) / 16) / 3) / 3);	// L2501
    float v2187[8][8];	// L2502
    #pragma HLS resource variable=v2187 core=ram_t2p_bram

    float v2188[8][7][7];	// L2503
    #pragma HLS resource variable=v2188 core=ram_t2p_bram

    float v2189[8][7][7];	// L2504
    #pragma HLS resource variable=v2189 core=ram_t2p_bram

    float v2190[8][7][7];	// L2505
    #pragma HLS resource variable=v2190 core=ram_t2p_bram

    forward_node162(v2177, v2190, v2183, v2182, v2181);	// L2506
    forward_node161(v2178, v2189, v2183, v2182, v2181);	// L2507
    forward_node160(v2176, v2188, v2186, v2185, v2182, v2184, v2181);	// L2508
    forward_node159(v2175, v2187, v2185, v2184, v2183, v2186);	// L2509
    float v2191[8][7][7];	// L2510
    #pragma HLS resource variable=v2191 core=ram_t2p_bram

    forward_node158(v2187, v2190, v2188, v2189, v2191, v2184, v2185, v2186);	// L2511
    forward_node157(v2191, v2179, v2183, v2182, v2181);	// L2512
  }
}

void forward_node164(
  float v2192[8][8][8],
  float v2193[64][56][56],
  int v2194,
  int v2195,
  int v2196
) {	// L2516
  #pragma HLS inline
  #pragma HLS resource variable=v2192 core=ram_t2p_bram

  for (int v2197 = 0; v2197 < 8; v2197 += 1) {	// L2517
    for (int v2198 = 0; v2198 < 8; v2198 += 1) {	// L2518
      for (int v2199 = 0; v2199 < 8; v2199 += 1) {	// L2519
        #pragma HLS pipeline II=1
        float v2200 = v2192[v2197][v2198][v2199];	// L2520
        v2193[(v2197 + (v2194 * 8))][(v2198 + (v2195 * 8))][(v2199 + (v2196 * 8))] = v2200;	// L2521
      }
    }
  }
}

void forward_node165(
  float v2201[64],
  float v2202[64],
  float v2203[64],
  float v2204[8][8][8],
  float v2205[8][8][8],
  float v2206[64],
  float v2207[8][8][8],
  int v2208
) {	// L2527
  #pragma HLS inline
  #pragma HLS resource variable=v2201 core=ram_t2p_bram

  #pragma HLS resource variable=v2202 core=ram_t2p_bram

  #pragma HLS resource variable=v2203 core=ram_t2p_bram

  #pragma HLS resource variable=v2204 core=ram_t2p_bram

  #pragma HLS resource variable=v2205 core=ram_t2p_bram

  #pragma HLS resource variable=v2206 core=ram_t2p_bram

  #pragma HLS resource variable=v2207 core=ram_t2p_bram

  for (int v2209 = 0; v2209 < 8; v2209 += 1) {	// L2530
    for (int v2210 = 0; v2210 < 8; v2210 += 1) {	// L2531
      for (int v2211 = 0; v2211 < 8; v2211 += 1) {	// L2532
        #pragma HLS pipeline II=1
        float v2212 = v2205[v2209][v2210][v2211];	// L2533
        float v2213 = v2206[(v2209 + (v2208 * 8))];	// L2534
        float v2214 = v2202[(v2209 + (v2208 * 8))];	// L2535
        float v2215 = v2201[(v2209 + (v2208 * 8))];	// L2536
        float v2216 = v2203[(v2209 + (v2208 * 8))];	// L2537
        float v2217 = v2204[v2209][v2210][v2211];	// L2538
        float v2218 = (double)0.000010;	// L2539
        float v2219 = v2216 + v2218;	// L2540
        float v2220 = 1.0 / sqrt(v2219);	// L2541
        float v2221 = v2212 - v2215;	// L2542
        float v2222 = v2221 * v2220;	// L2543
        float v2223 = v2222 * v2213;	// L2544
        float v2224 = v2223 + v2214;	// L2545
        float v2225 = v2224 + v2217;	// L2546
        bool v2226 = v2225 > (float)0.000000;	// L2547
        float v2227 = v2226 ? v2225 : (float)0.000000;	// L2548
        v2207[v2209][v2210][v2211] = v2227;	// L2549
      }
    }
  }
}

void forward_node166(
  float v2228[64][56][56],
  float v2229[8][8][8],
  int v2230,
  int v2231,
  int v2232
) {	// L2555
  #pragma HLS inline
  #pragma HLS resource variable=v2229 core=ram_t2p_bram

  for (int v2233 = 0; v2233 < 8; v2233 += 1) {	// L2556
    for (int v2234 = 0; v2234 < 8; v2234 += 1) {	// L2557
      for (int v2235 = 0; v2235 < 8; v2235 += 1) {	// L2558
        #pragma HLS pipeline II=1
        float v2236 = v2228[(v2233 + (v2230 * 8))][(v2234 + (v2231 * 8))][(v2235 + (v2232 * 8))];	// L2559
        v2229[v2233][v2234][v2235] = v2236;	// L2560
      }
    }
  }
}

void forward_node167(
  float v2237[64][56][56],
  float v2238[8][8][8],
  int v2239,
  int v2240,
  int v2241
) {	// L2566
  #pragma HLS inline
  #pragma HLS resource variable=v2238 core=ram_t2p_bram

  for (int v2242 = 0; v2242 < 8; v2242 += 1) {	// L2567
    for (int v2243 = 0; v2243 < 8; v2243 += 1) {	// L2568
      for (int v2244 = 0; v2244 < 8; v2244 += 1) {	// L2569
        #pragma HLS pipeline II=1
        float v2245 = v2237[(v2242 + (v2239 * 8))][(v2243 + (v2240 * 8))][(v2244 + (v2241 * 8))];	// L2570
        v2238[v2242][v2243][v2244] = v2245;	// L2571
      }
    }
  }
}

void forward_node163(
  float v2246[64],
  float v2247[64][56][56],
  float v2248[64],
  float v2249[64],
  float v2250[64],
  float v2251[64][56][56],
  float v2252[64][56][56]
) {	// L2577
  #pragma HLS resource variable=v2246 core=ram_t2p_bram

  #pragma HLS resource variable=v2248 core=ram_t2p_bram

  #pragma HLS resource variable=v2249 core=ram_t2p_bram

  #pragma HLS resource variable=v2250 core=ram_t2p_bram

  for (int v2253 = 0; v2253 < 392; v2253 += 1) {	// L2578
    #pragma HLS dataflow
    int v2254 = (v2253 % 7);	// L2579
    int v2255 = ((v2253 / 7) % 7);	// L2580
    int v2256 = ((v2253 / 7) / 7);	// L2581
    float v2257[8][8][8];	// L2582
    #pragma HLS resource variable=v2257 core=ram_t2p_bram

    float v2258[8][8][8];	// L2583
    #pragma HLS resource variable=v2258 core=ram_t2p_bram

    float v2259[8][8][8];	// L2584
    #pragma HLS resource variable=v2259 core=ram_t2p_bram

    forward_node167(v2251, v2259, v2256, v2255, v2254);	// L2585
    forward_node166(v2247, v2258, v2256, v2255, v2254);	// L2586
    forward_node165(v2246, v2249, v2250, v2258, v2259, v2248, v2257, v2256);	// L2587
    forward_node164(v2257, v2252, v2256, v2255, v2254);	// L2588
  }
}

void forward_node169(
  float v2260[8][8][8],
  float v2261[64][56][56],
  int v2262,
  int v2263,
  int v2264
) {	// L2592
  #pragma HLS inline
  #pragma HLS array_partition variable=v2260 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2260 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2260 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2261 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2261 cyclic factor=2 dim=3

  for (int v2265 = 0; v2265 < 8; v2265 += 1) {	// L2593
    for (int v2266 = 0; v2266 < 8; v2266 += 2) {	// L2594
      for (int v2267 = 0; v2267 < 8; v2267 += 2) {	// L2595
        #pragma HLS pipeline II=1
        float v2268 = v2260[v2265][v2266][v2267];	// L2596
        v2261[(v2265 + (v2262 * 8))][(v2266 + (v2263 * 8))][(v2267 + (v2264 * 8))] = v2268;	// L2597
        float v2269 = v2260[v2265][v2266][(v2267 + 1)];	// L2598
        v2261[(v2265 + (v2262 * 8))][(v2266 + (v2263 * 8))][((v2267 + (v2264 * 8)) + 1)] = v2269;	// L2599
        float v2270 = v2260[v2265][(v2266 + 1)][v2267];	// L2600
        v2261[(v2265 + (v2262 * 8))][((v2266 + (v2263 * 8)) + 1)][(v2267 + (v2264 * 8))] = v2270;	// L2601
        float v2271 = v2260[v2265][(v2266 + 1)][(v2267 + 1)];	// L2602
        v2261[(v2265 + (v2262 * 8))][((v2266 + (v2263 * 8)) + 1)][((v2267 + (v2264 * 8)) + 1)] = v2271;	// L2603
      }
    }
  }
}

void forward_node170(
  float v2272[8][8][8],
  float v2273[8][8],
  float v2274[8][8][8],
  float v2275[8][8][8]
) {	// L2609
  #pragma HLS inline
  #pragma HLS array_partition variable=v2272 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2272 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2272 core=ram_t2p_bram

  #pragma HLS resource variable=v2273 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2274 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2274 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2274 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2275 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2275 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2275 core=ram_t2p_bram

  for (int v2276 = 0; v2276 < 8; v2276 += 1) {	// L2610
    for (int v2277 = 0; v2277 < 8; v2277 += 1) {	// L2611
      for (int v2278 = 0; v2278 < 8; v2278 += 2) {	// L2612
        for (int v2279 = 0; v2279 < 8; v2279 += 2) {	// L2613
          #pragma HLS pipeline II=1
          float v2280 = v2272[v2276][v2278][v2279];	// L2614
          float v2281 = v2273[v2277][v2276];	// L2615
          float v2282 = v2274[v2277][v2278][v2279];	// L2616
          float v2283 = v2275[v2277][v2278][v2279];	// L2617
          float v2284 = (v2276 == 0) ? v2282 : v2283;	// L2618
          float v2285 = v2280 * v2281;	// L2619
          float v2286 = v2284 + v2285;	// L2620
          v2275[v2277][v2278][v2279] = v2286;	// L2621
          float v2287 = v2272[v2276][v2278][(v2279 + 1)];	// L2622
          float v2288 = v2274[v2277][v2278][(v2279 + 1)];	// L2623
          float v2289 = v2275[v2277][v2278][(v2279 + 1)];	// L2624
          float v2290 = (v2276 == 0) ? v2288 : v2289;	// L2625
          float v2291 = v2287 * v2281;	// L2626
          float v2292 = v2290 + v2291;	// L2627
          v2275[v2277][v2278][(v2279 + 1)] = v2292;	// L2628
          float v2293 = v2272[v2276][(v2278 + 1)][v2279];	// L2629
          float v2294 = v2274[v2277][(v2278 + 1)][v2279];	// L2630
          float v2295 = v2275[v2277][(v2278 + 1)][v2279];	// L2631
          float v2296 = (v2276 == 0) ? v2294 : v2295;	// L2632
          float v2297 = v2293 * v2281;	// L2633
          float v2298 = v2296 + v2297;	// L2634
          v2275[v2277][(v2278 + 1)][v2279] = v2298;	// L2635
          float v2299 = v2272[v2276][(v2278 + 1)][(v2279 + 1)];	// L2636
          float v2300 = v2274[v2277][(v2278 + 1)][(v2279 + 1)];	// L2637
          float v2301 = v2275[v2277][(v2278 + 1)][(v2279 + 1)];	// L2638
          float v2302 = (v2276 == 0) ? v2300 : v2301;	// L2639
          float v2303 = v2299 * v2281;	// L2640
          float v2304 = v2302 + v2303;	// L2641
          v2275[v2277][(v2278 + 1)][(v2279 + 1)] = v2304;	// L2642
        }
      }
    }
  }
}

void forward_node171(
  float v2305[64][56][56],
  float v2306[8][8][8],
  int v2307,
  int v2308,
  int v2309
) {	// L2649
  #pragma HLS inline
  #pragma HLS array_partition variable=v2305 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2305 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2306 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2306 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2306 core=ram_t2p_bram

  for (int v2310 = 0; v2310 < 8; v2310 += 1) {	// L2650
    for (int v2311 = 0; v2311 < 8; v2311 += 2) {	// L2651
      for (int v2312 = 0; v2312 < 8; v2312 += 2) {	// L2652
        #pragma HLS pipeline II=1
        float v2313 = v2305[(v2310 + (v2307 * 8))][(v2311 + (v2308 * 8))][(v2312 + (v2309 * 8))];	// L2653
        v2306[v2310][v2311][v2312] = v2313;	// L2654
        float v2314 = v2305[(v2310 + (v2307 * 8))][(v2311 + (v2308 * 8))][((v2312 + (v2309 * 8)) + 1)];	// L2655
        v2306[v2310][v2311][(v2312 + 1)] = v2314;	// L2656
        float v2315 = v2305[(v2310 + (v2307 * 8))][((v2311 + (v2308 * 8)) + 1)][(v2312 + (v2309 * 8))];	// L2657
        v2306[v2310][(v2311 + 1)][v2312] = v2315;	// L2658
        float v2316 = v2305[(v2310 + (v2307 * 8))][((v2311 + (v2308 * 8)) + 1)][((v2312 + (v2309 * 8)) + 1)];	// L2659
        v2306[v2310][(v2311 + 1)][(v2312 + 1)] = v2316;	// L2660
      }
    }
  }
}

void forward_node172(
  float v2317[64][64][3][3],
  float v2318[8][8],
  int v2319,
  int v2320,
  int v2321,
  int v2322
) {	// L2666
  #pragma HLS inline
  #pragma HLS resource variable=v2318 core=ram_t2p_bram

  for (int v2323 = 0; v2323 < 8; v2323 += 1) {	// L2667
    for (int v2324 = 0; v2324 < 8; v2324 += 1) {	// L2668
      #pragma HLS pipeline II=1
      float v2325 = v2317[(v2323 + (v2321 * 8))][(v2324 + (v2322 * 8))][v2319][v2320];	// L2669
      v2318[v2323][v2324] = v2325;	// L2670
    }
  }
}

void forward_node173(
  float v2326[64][56][56],
  float v2327[8][8][8],
  int v2328,
  int v2329,
  int v2330,
  int v2331,
  int v2332
) {	// L2675
  #pragma HLS inline
  #pragma HLS array_partition variable=v2326 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2326 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2327 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2327 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2327 core=ram_t2p_bram

  for (int v2333 = 0; v2333 < 8; v2333 += 1) {	// L2676
    for (int v2334 = 0; v2334 < 8; v2334 += 2) {	// L2677
      for (int v2335 = 0; v2335 < 8; v2335 += 2) {	// L2678
        #pragma HLS pipeline II=1
        float v2336 = v2326[(v2333 + (v2328 * 8))][(((v2334 + v2329) + (v2330 * 8)) - 1)][(((v2335 + v2331) + (v2332 * 8)) - 1)];	// L2679
        v2327[v2333][v2334][v2335] = v2336;	// L2680
        float v2337 = v2326[(v2333 + (v2328 * 8))][(((v2334 + v2329) + (v2330 * 8)) - 1)][((v2335 + v2331) + (v2332 * 8))];	// L2681
        v2327[v2333][v2334][(v2335 + 1)] = v2337;	// L2682
        float v2338 = v2326[(v2333 + (v2328 * 8))][((v2334 + v2329) + (v2330 * 8))][(((v2335 + v2331) + (v2332 * 8)) - 1)];	// L2683
        v2327[v2333][(v2334 + 1)][v2335] = v2338;	// L2684
        float v2339 = v2326[(v2333 + (v2328 * 8))][((v2334 + v2329) + (v2330 * 8))][((v2335 + v2331) + (v2332 * 8))];	// L2685
        v2327[v2333][(v2334 + 1)][(v2335 + 1)] = v2339;	// L2686
      }
    }
  }
}

void forward_node168(
  float v2340[64][56][56],
  float v2341[64][64][3][3],
  float v2342[64][56][56],
  float v2343[64][56][56]
) {	// L2692
  #pragma HLS array_partition variable=v2340 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2340 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2342 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2342 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2343 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2343 cyclic factor=2 dim=3

  for (int v2344 = 0; v2344 < 28224; v2344 += 1) {	// L2693
    #pragma HLS dataflow
    int v2345 = (v2344 % 7);	// L2694
    int v2346 = ((v2344 / 7) % 7);	// L2695
    int v2347 = (((v2344 / 7) / 7) % 8);	// L2696
    int v2348 = ((((v2344 / 7) / 7) / 8) % 3);	// L2697
    int v2349 = (((((v2344 / 7) / 7) / 8) / 3) % 3);	// L2698
    int v2350 = (((((v2344 / 7) / 7) / 8) / 3) / 3);	// L2699
    float v2351[8][8][8];	// L2700
    #pragma HLS array_partition variable=v2351 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2351 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2351 core=ram_t2p_bram

    float v2352[8][8];	// L2701
    #pragma HLS resource variable=v2352 core=ram_t2p_bram

    float v2353[8][8][8];	// L2702
    #pragma HLS array_partition variable=v2353 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2353 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2353 core=ram_t2p_bram

    forward_node173(v2340, v2353, v2350, v2349, v2346, v2348, v2345);	// L2703
    forward_node172(v2341, v2352, v2349, v2348, v2347, v2350);	// L2704
    forward_node171(v2342, v2351, v2347, v2346, v2345);	// L2705
    float v2354[8][8][8];	// L2706
    #pragma HLS array_partition variable=v2354 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2354 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2354 core=ram_t2p_bram

    forward_node170(v2353, v2352, v2351, v2354);	// L2707
    forward_node169(v2354, v2343, v2347, v2346, v2345);	// L2708
  }
}

void forward_node175(
  float v2355[8][8][8],
  float v2356[64][56][56],
  int v2357,
  int v2358,
  int v2359
) {	// L2712
  #pragma HLS inline
  #pragma HLS resource variable=v2355 core=ram_t2p_bram

  for (int v2360 = 0; v2360 < 8; v2360 += 1) {	// L2713
    for (int v2361 = 0; v2361 < 8; v2361 += 1) {	// L2714
      for (int v2362 = 0; v2362 < 8; v2362 += 1) {	// L2715
        #pragma HLS pipeline II=1
        float v2363 = v2355[v2360][v2361][v2362];	// L2716
        v2356[(v2360 + (v2357 * 8))][(v2361 + (v2358 * 8))][(v2362 + (v2359 * 8))] = v2363;	// L2717
      }
    }
  }
}

void forward_node176(
  float v2364[64],
  float v2365[64],
  float v2366[64],
  float v2367[8][8][8],
  float v2368[64],
  float v2369[8][8][8],
  int v2370
) {	// L2723
  #pragma HLS inline
  #pragma HLS resource variable=v2364 core=ram_t2p_bram

  #pragma HLS resource variable=v2365 core=ram_t2p_bram

  #pragma HLS resource variable=v2366 core=ram_t2p_bram

  #pragma HLS resource variable=v2367 core=ram_t2p_bram

  #pragma HLS resource variable=v2368 core=ram_t2p_bram

  #pragma HLS resource variable=v2369 core=ram_t2p_bram

  for (int v2371 = 0; v2371 < 8; v2371 += 1) {	// L2726
    for (int v2372 = 0; v2372 < 8; v2372 += 1) {	// L2727
      for (int v2373 = 0; v2373 < 8; v2373 += 1) {	// L2728
        #pragma HLS pipeline II=1
        float v2374 = v2367[v2371][v2372][v2373];	// L2729
        float v2375 = v2365[(v2371 + (v2370 * 8))];	// L2730
        float v2376 = v2364[(v2371 + (v2370 * 8))];	// L2731
        float v2377 = v2366[(v2371 + (v2370 * 8))];	// L2732
        float v2378 = v2368[(v2371 + (v2370 * 8))];	// L2733
        float v2379 = (double)0.000010;	// L2734
        float v2380 = v2378 + v2379;	// L2735
        float v2381 = 1.0 / sqrt(v2380);	// L2736
        float v2382 = v2374 - v2377;	// L2737
        float v2383 = v2382 * v2381;	// L2738
        float v2384 = v2383 * v2375;	// L2739
        float v2385 = v2384 + v2376;	// L2740
        bool v2386 = v2385 > (float)0.000000;	// L2741
        float v2387 = v2386 ? v2385 : (float)0.000000;	// L2742
        v2369[v2371][v2372][v2373] = v2387;	// L2743
      }
    }
  }
}

void forward_node177(
  float v2388[64][56][56],
  float v2389[8][8][8],
  int v2390,
  int v2391,
  int v2392
) {	// L2749
  #pragma HLS inline
  #pragma HLS resource variable=v2389 core=ram_t2p_bram

  for (int v2393 = 0; v2393 < 8; v2393 += 1) {	// L2750
    for (int v2394 = 0; v2394 < 8; v2394 += 1) {	// L2751
      for (int v2395 = 0; v2395 < 8; v2395 += 1) {	// L2752
        #pragma HLS pipeline II=1
        float v2396 = v2388[(v2393 + (v2390 * 8))][(v2394 + (v2391 * 8))][(v2395 + (v2392 * 8))];	// L2753
        v2389[v2393][v2394][v2395] = v2396;	// L2754
      }
    }
  }
}

void forward_node174(
  float v2397[64],
  float v2398[64],
  float v2399[64],
  float v2400[64][56][56],
  float v2401[64],
  float v2402[64][56][56]
) {	// L2760
  #pragma HLS resource variable=v2397 core=ram_t2p_bram

  #pragma HLS resource variable=v2398 core=ram_t2p_bram

  #pragma HLS resource variable=v2399 core=ram_t2p_bram

  #pragma HLS resource variable=v2401 core=ram_t2p_bram

  for (int v2403 = 0; v2403 < 392; v2403 += 1) {	// L2761
    #pragma HLS dataflow
    int v2404 = (v2403 % 7);	// L2762
    int v2405 = ((v2403 / 7) % 7);	// L2763
    int v2406 = ((v2403 / 7) / 7);	// L2764
    float v2407[8][8][8];	// L2765
    #pragma HLS resource variable=v2407 core=ram_t2p_bram

    float v2408[8][8][8];	// L2766
    #pragma HLS resource variable=v2408 core=ram_t2p_bram

    forward_node177(v2400, v2408, v2406, v2405, v2404);	// L2767
    forward_node176(v2401, v2399, v2398, v2408, v2397, v2407, v2406);	// L2768
    forward_node175(v2407, v2402, v2406, v2405, v2404);	// L2769
  }
}

void forward_node179(
  float v2409[8][8][8],
  float v2410[64][56][56],
  int v2411,
  int v2412,
  int v2413
) {	// L2773
  #pragma HLS inline
  #pragma HLS array_partition variable=v2409 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2409 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2409 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2410 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2410 cyclic factor=2 dim=3

  for (int v2414 = 0; v2414 < 8; v2414 += 1) {	// L2774
    for (int v2415 = 0; v2415 < 8; v2415 += 2) {	// L2775
      for (int v2416 = 0; v2416 < 8; v2416 += 2) {	// L2776
        #pragma HLS pipeline II=1
        float v2417 = v2409[v2414][v2415][v2416];	// L2777
        v2410[(v2414 + (v2411 * 8))][(v2415 + (v2412 * 8))][(v2416 + (v2413 * 8))] = v2417;	// L2778
        float v2418 = v2409[v2414][v2415][(v2416 + 1)];	// L2779
        v2410[(v2414 + (v2411 * 8))][(v2415 + (v2412 * 8))][((v2416 + (v2413 * 8)) + 1)] = v2418;	// L2780
        float v2419 = v2409[v2414][(v2415 + 1)][v2416];	// L2781
        v2410[(v2414 + (v2411 * 8))][((v2415 + (v2412 * 8)) + 1)][(v2416 + (v2413 * 8))] = v2419;	// L2782
        float v2420 = v2409[v2414][(v2415 + 1)][(v2416 + 1)];	// L2783
        v2410[(v2414 + (v2411 * 8))][((v2415 + (v2412 * 8)) + 1)][((v2416 + (v2413 * 8)) + 1)] = v2420;	// L2784
      }
    }
  }
}

void forward_node180(
  float v2421[8][8][8],
  float v2422[8][8],
  float v2423[8][8][8],
  float v2424[8][8][8],
  float v2425[8][8][8],
  int v2426,
  int v2427,
  int v2428
) {	// L2790
  #pragma HLS inline
  #pragma HLS array_partition variable=v2421 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2421 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2421 core=ram_t2p_bram

  #pragma HLS resource variable=v2422 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2423 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2423 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2423 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2424 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2424 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2424 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2425 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2425 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2425 core=ram_t2p_bram

  for (int v2429 = 0; v2429 < 8; v2429 += 1) {	// L2791
    for (int v2430 = 0; v2430 < 8; v2430 += 1) {	// L2792
      for (int v2431 = 0; v2431 < 8; v2431 += 2) {	// L2793
        for (int v2432 = 0; v2432 < 8; v2432 += 2) {	// L2794
          #pragma HLS pipeline II=1
          float v2433 = v2421[v2430][v2431][v2432];	// L2795
          float v2434 = v2424[v2430][v2431][v2432];	// L2796
          float v2435 = v2425[v2430][v2431][v2432];	// L2797
          float v2436 = (v2429 == 0) ? v2434 : v2435;	// L2798
          float v2437 = ((v2429 + (v2428 * 8)) == 0 && v2426 == 0 && v2427 == 0) ? v2433 : v2436;	// L2799
          float v2438 = v2423[v2429][v2431][v2432];	// L2800
          float v2439 = v2422[v2430][v2429];	// L2801
          float v2440 = v2438 * v2439;	// L2802
          float v2441 = v2437 + v2440;	// L2803
          v2425[v2430][v2431][v2432] = v2441;	// L2804
          float v2442 = v2421[v2430][v2431][(v2432 + 1)];	// L2805
          float v2443 = v2424[v2430][v2431][(v2432 + 1)];	// L2806
          float v2444 = v2425[v2430][v2431][(v2432 + 1)];	// L2807
          float v2445 = (v2429 == 0) ? v2443 : v2444;	// L2808
          float v2446 = ((v2429 + (v2428 * 8)) == 0 && v2426 == 0 && v2427 == 0) ? v2442 : v2445;	// L2809
          float v2447 = v2423[v2429][v2431][(v2432 + 1)];	// L2810
          float v2448 = v2447 * v2439;	// L2811
          float v2449 = v2446 + v2448;	// L2812
          v2425[v2430][v2431][(v2432 + 1)] = v2449;	// L2813
          float v2450 = v2421[v2430][(v2431 + 1)][v2432];	// L2814
          float v2451 = v2424[v2430][(v2431 + 1)][v2432];	// L2815
          float v2452 = v2425[v2430][(v2431 + 1)][v2432];	// L2816
          float v2453 = (v2429 == 0) ? v2451 : v2452;	// L2817
          float v2454 = ((v2429 + (v2428 * 8)) == 0 && v2426 == 0 && v2427 == 0) ? v2450 : v2453;	// L2818
          float v2455 = v2423[v2429][(v2431 + 1)][v2432];	// L2819
          float v2456 = v2455 * v2439;	// L2820
          float v2457 = v2454 + v2456;	// L2821
          v2425[v2430][(v2431 + 1)][v2432] = v2457;	// L2822
          float v2458 = v2421[v2430][(v2431 + 1)][(v2432 + 1)];	// L2823
          float v2459 = v2424[v2430][(v2431 + 1)][(v2432 + 1)];	// L2824
          float v2460 = v2425[v2430][(v2431 + 1)][(v2432 + 1)];	// L2825
          float v2461 = (v2429 == 0) ? v2459 : v2460;	// L2826
          float v2462 = ((v2429 + (v2428 * 8)) == 0 && v2426 == 0 && v2427 == 0) ? v2458 : v2461;	// L2827
          float v2463 = v2423[v2429][(v2431 + 1)][(v2432 + 1)];	// L2828
          float v2464 = v2463 * v2439;	// L2829
          float v2465 = v2462 + v2464;	// L2830
          v2425[v2430][(v2431 + 1)][(v2432 + 1)] = v2465;	// L2831
        }
      }
    }
  }
}

void forward_node181(
  float v2466[64][64][3][3],
  float v2467[8][8],
  int v2468,
  int v2469,
  int v2470,
  int v2471
) {	// L2838
  #pragma HLS inline
  #pragma HLS resource variable=v2467 core=ram_t2p_bram

  for (int v2472 = 0; v2472 < 8; v2472 += 1) {	// L2839
    for (int v2473 = 0; v2473 < 8; v2473 += 1) {	// L2840
      #pragma HLS pipeline II=1
      float v2474 = v2466[(v2472 + (v2470 * 8))][(v2473 + (v2471 * 8))][v2468][v2469];	// L2841
      v2467[v2472][v2473] = v2474;	// L2842
    }
  }
}

void forward_node182(
  float v2475[64][56][56],
  float v2476[8][8][8],
  int v2477,
  int v2478,
  int v2479,
  int v2480,
  int v2481
) {	// L2847
  #pragma HLS inline
  #pragma HLS array_partition variable=v2475 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2475 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2476 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2476 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2476 core=ram_t2p_bram

  for (int v2482 = 0; v2482 < 8; v2482 += 1) {	// L2848
    for (int v2483 = 0; v2483 < 8; v2483 += 2) {	// L2849
      for (int v2484 = 0; v2484 < 8; v2484 += 2) {	// L2850
        #pragma HLS pipeline II=1
        float v2485 = v2475[(v2482 + (v2477 * 8))][(((v2483 + v2478) + (v2479 * 8)) - 1)][(((v2484 + v2480) + (v2481 * 8)) - 1)];	// L2851
        v2476[v2482][v2483][v2484] = v2485;	// L2852
        float v2486 = v2475[(v2482 + (v2477 * 8))][(((v2483 + v2478) + (v2479 * 8)) - 1)][((v2484 + v2480) + (v2481 * 8))];	// L2853
        v2476[v2482][v2483][(v2484 + 1)] = v2486;	// L2854
        float v2487 = v2475[(v2482 + (v2477 * 8))][((v2483 + v2478) + (v2479 * 8))][(((v2484 + v2480) + (v2481 * 8)) - 1)];	// L2855
        v2476[v2482][(v2483 + 1)][v2484] = v2487;	// L2856
        float v2488 = v2475[(v2482 + (v2477 * 8))][((v2483 + v2478) + (v2479 * 8))][((v2484 + v2480) + (v2481 * 8))];	// L2857
        v2476[v2482][(v2483 + 1)][(v2484 + 1)] = v2488;	// L2858
      }
    }
  }
}

void forward_node183(
  float v2489[64][56][56],
  float v2490[8][8][8],
  int v2491,
  int v2492,
  int v2493
) {	// L2864
  #pragma HLS inline
  #pragma HLS array_partition variable=v2489 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2489 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2490 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2490 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2490 core=ram_t2p_bram

  for (int v2494 = 0; v2494 < 8; v2494 += 1) {	// L2865
    for (int v2495 = 0; v2495 < 8; v2495 += 2) {	// L2866
      for (int v2496 = 0; v2496 < 8; v2496 += 2) {	// L2867
        #pragma HLS pipeline II=1
        float v2497 = v2489[(v2494 + (v2491 * 8))][(v2495 + (v2492 * 8))][(v2496 + (v2493 * 8))];	// L2868
        v2490[v2494][v2495][v2496] = v2497;	// L2869
        float v2498 = v2489[(v2494 + (v2491 * 8))][(v2495 + (v2492 * 8))][((v2496 + (v2493 * 8)) + 1)];	// L2870
        v2490[v2494][v2495][(v2496 + 1)] = v2498;	// L2871
        float v2499 = v2489[(v2494 + (v2491 * 8))][((v2495 + (v2492 * 8)) + 1)][(v2496 + (v2493 * 8))];	// L2872
        v2490[v2494][(v2495 + 1)][v2496] = v2499;	// L2873
        float v2500 = v2489[(v2494 + (v2491 * 8))][((v2495 + (v2492 * 8)) + 1)][((v2496 + (v2493 * 8)) + 1)];	// L2874
        v2490[v2494][(v2495 + 1)][(v2496 + 1)] = v2500;	// L2875
      }
    }
  }
}

void forward_node184(
  float v2501[64][56][56],
  float v2502[8][8][8],
  int v2503,
  int v2504,
  int v2505
) {	// L2881
  #pragma HLS inline
  #pragma HLS array_partition variable=v2501 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2501 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2502 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2502 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2502 core=ram_t2p_bram

  for (int v2506 = 0; v2506 < 8; v2506 += 1) {	// L2882
    for (int v2507 = 0; v2507 < 8; v2507 += 2) {	// L2883
      for (int v2508 = 0; v2508 < 8; v2508 += 2) {	// L2884
        #pragma HLS pipeline II=1
        float v2509 = v2501[(v2506 + (v2503 * 8))][(v2507 + (v2504 * 8))][(v2508 + (v2505 * 8))];	// L2885
        v2502[v2506][v2507][v2508] = v2509;	// L2886
        float v2510 = v2501[(v2506 + (v2503 * 8))][(v2507 + (v2504 * 8))][((v2508 + (v2505 * 8)) + 1)];	// L2887
        v2502[v2506][v2507][(v2508 + 1)] = v2510;	// L2888
        float v2511 = v2501[(v2506 + (v2503 * 8))][((v2507 + (v2504 * 8)) + 1)][(v2508 + (v2505 * 8))];	// L2889
        v2502[v2506][(v2507 + 1)][v2508] = v2511;	// L2890
        float v2512 = v2501[(v2506 + (v2503 * 8))][((v2507 + (v2504 * 8)) + 1)][((v2508 + (v2505 * 8)) + 1)];	// L2891
        v2502[v2506][(v2507 + 1)][(v2508 + 1)] = v2512;	// L2892
      }
    }
  }
}

void forward_node178(
  float v2513[64][56][56],
  float v2514[64][64][3][3],
  float v2515[64][56][56],
  float v2516[64][56][56],
  float v2517[64][56][56]
) {	// L2898
  #pragma HLS array_partition variable=v2513 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2513 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2515 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2515 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2516 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2516 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2517 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2517 cyclic factor=2 dim=3

  for (int v2518 = 0; v2518 < 28224; v2518 += 1) {	// L2899
    #pragma HLS dataflow
    int v2519 = (v2518 % 7);	// L2900
    int v2520 = ((v2518 / 7) % 7);	// L2901
    int v2521 = (((v2518 / 7) / 7) % 8);	// L2902
    int v2522 = ((((v2518 / 7) / 7) / 8) % 3);	// L2903
    int v2523 = (((((v2518 / 7) / 7) / 8) / 3) % 3);	// L2904
    int v2524 = (((((v2518 / 7) / 7) / 8) / 3) / 3);	// L2905
    float v2525[8][8];	// L2906
    #pragma HLS resource variable=v2525 core=ram_t2p_bram

    float v2526[8][8][8];	// L2907
    #pragma HLS array_partition variable=v2526 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2526 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2526 core=ram_t2p_bram

    float v2527[8][8][8];	// L2908
    #pragma HLS array_partition variable=v2527 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2527 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2527 core=ram_t2p_bram

    float v2528[8][8][8];	// L2909
    #pragma HLS array_partition variable=v2528 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2528 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2528 core=ram_t2p_bram

    forward_node184(v2515, v2528, v2521, v2520, v2519);	// L2910
    forward_node183(v2516, v2527, v2521, v2520, v2519);	// L2911
    forward_node182(v2513, v2526, v2524, v2523, v2520, v2522, v2519);	// L2912
    forward_node181(v2514, v2525, v2523, v2522, v2521, v2524);	// L2913
    float v2529[8][8][8];	// L2914
    #pragma HLS array_partition variable=v2529 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2529 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2529 core=ram_t2p_bram

    forward_node180(v2528, v2525, v2526, v2527, v2529, v2523, v2522, v2524);	// L2915
    forward_node179(v2529, v2517, v2521, v2520, v2519);	// L2916
  }
}

void forward_node186(
  float v2530[8][8][8],
  float v2531[64][56][56],
  int v2532,
  int v2533,
  int v2534
) {	// L2920
  #pragma HLS inline
  #pragma HLS resource variable=v2530 core=ram_t2p_bram

  for (int v2535 = 0; v2535 < 8; v2535 += 1) {	// L2921
    for (int v2536 = 0; v2536 < 8; v2536 += 1) {	// L2922
      for (int v2537 = 0; v2537 < 8; v2537 += 1) {	// L2923
        #pragma HLS pipeline II=1
        float v2538 = v2530[v2535][v2536][v2537];	// L2924
        v2531[(v2535 + (v2532 * 8))][(v2536 + (v2533 * 8))][(v2537 + (v2534 * 8))] = v2538;	// L2925
      }
    }
  }
}

void forward_node187(
  float v2539[8][8][8],
  float v2540[64],
  float v2541[64],
  float v2542[64],
  float v2543[64],
  float v2544[8][8][8],
  float v2545[8][8][8],
  int v2546
) {	// L2931
  #pragma HLS inline
  #pragma HLS resource variable=v2539 core=ram_t2p_bram

  #pragma HLS resource variable=v2540 core=ram_t2p_bram

  #pragma HLS resource variable=v2541 core=ram_t2p_bram

  #pragma HLS resource variable=v2542 core=ram_t2p_bram

  #pragma HLS resource variable=v2543 core=ram_t2p_bram

  #pragma HLS resource variable=v2544 core=ram_t2p_bram

  #pragma HLS resource variable=v2545 core=ram_t2p_bram

  for (int v2547 = 0; v2547 < 8; v2547 += 1) {	// L2934
    for (int v2548 = 0; v2548 < 8; v2548 += 1) {	// L2935
      for (int v2549 = 0; v2549 < 8; v2549 += 1) {	// L2936
        #pragma HLS pipeline II=1
        float v2550 = v2539[v2547][v2548][v2549];	// L2937
        float v2551 = v2543[(v2547 + (v2546 * 8))];	// L2938
        float v2552 = v2540[(v2547 + (v2546 * 8))];	// L2939
        float v2553 = v2542[(v2547 + (v2546 * 8))];	// L2940
        float v2554 = v2541[(v2547 + (v2546 * 8))];	// L2941
        float v2555 = v2544[v2547][v2548][v2549];	// L2942
        float v2556 = (double)0.000010;	// L2943
        float v2557 = v2554 + v2556;	// L2944
        float v2558 = 1.0 / sqrt(v2557);	// L2945
        float v2559 = v2550 - v2553;	// L2946
        float v2560 = v2559 * v2558;	// L2947
        float v2561 = v2560 * v2551;	// L2948
        float v2562 = v2561 + v2552;	// L2949
        float v2563 = v2562 + v2555;	// L2950
        bool v2564 = v2563 > (float)0.000000;	// L2951
        float v2565 = v2564 ? v2563 : (float)0.000000;	// L2952
        v2545[v2547][v2548][v2549] = v2565;	// L2953
      }
    }
  }
}

void forward_node188(
  float v2566[64][56][56],
  float v2567[8][8][8],
  int v2568,
  int v2569,
  int v2570
) {	// L2959
  #pragma HLS inline
  #pragma HLS resource variable=v2567 core=ram_t2p_bram

  for (int v2571 = 0; v2571 < 8; v2571 += 1) {	// L2960
    for (int v2572 = 0; v2572 < 8; v2572 += 1) {	// L2961
      for (int v2573 = 0; v2573 < 8; v2573 += 1) {	// L2962
        #pragma HLS pipeline II=1
        float v2574 = v2566[(v2571 + (v2568 * 8))][(v2572 + (v2569 * 8))][(v2573 + (v2570 * 8))];	// L2963
        v2567[v2571][v2572][v2573] = v2574;	// L2964
      }
    }
  }
}

void forward_node189(
  float v2575[64][56][56],
  float v2576[8][8][8],
  int v2577,
  int v2578,
  int v2579
) {	// L2970
  #pragma HLS inline
  #pragma HLS resource variable=v2576 core=ram_t2p_bram

  for (int v2580 = 0; v2580 < 8; v2580 += 1) {	// L2971
    for (int v2581 = 0; v2581 < 8; v2581 += 1) {	// L2972
      for (int v2582 = 0; v2582 < 8; v2582 += 1) {	// L2973
        #pragma HLS pipeline II=1
        float v2583 = v2575[(v2580 + (v2577 * 8))][(v2581 + (v2578 * 8))][(v2582 + (v2579 * 8))];	// L2974
        v2576[v2580][v2581][v2582] = v2583;	// L2975
      }
    }
  }
}

void forward_node185(
  float v2584[64][56][56],
  float v2585[64],
  float v2586[64],
  float v2587[64][56][56],
  float v2588[64],
  float v2589[64],
  float v2590[64][56][56]
) {	// L2981
  #pragma HLS resource variable=v2585 core=ram_t2p_bram

  #pragma HLS resource variable=v2586 core=ram_t2p_bram

  #pragma HLS resource variable=v2588 core=ram_t2p_bram

  #pragma HLS resource variable=v2589 core=ram_t2p_bram

  for (int v2591 = 0; v2591 < 392; v2591 += 1) {	// L2982
    #pragma HLS dataflow
    int v2592 = (v2591 % 7);	// L2983
    int v2593 = ((v2591 / 7) % 7);	// L2984
    int v2594 = ((v2591 / 7) / 7);	// L2985
    float v2595[8][8][8];	// L2986
    #pragma HLS resource variable=v2595 core=ram_t2p_bram

    float v2596[8][8][8];	// L2987
    #pragma HLS resource variable=v2596 core=ram_t2p_bram

    float v2597[8][8][8];	// L2988
    #pragma HLS resource variable=v2597 core=ram_t2p_bram

    forward_node189(v2587, v2597, v2594, v2593, v2592);	// L2989
    forward_node188(v2584, v2596, v2594, v2593, v2592);	// L2990
    forward_node187(v2597, v2586, v2588, v2585, v2589, v2596, v2595, v2594);	// L2991
    forward_node186(v2595, v2590, v2594, v2593, v2592);	// L2992
  }
}

void forward_node191(
  float v2598[8][8][8],
  float v2599[64][56][56],
  int v2600,
  int v2601,
  int v2602
) {	// L2996
  #pragma HLS inline
  #pragma HLS array_partition variable=v2598 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2598 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2598 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2599 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2599 cyclic factor=2 dim=3

  for (int v2603 = 0; v2603 < 8; v2603 += 1) {	// L2997
    for (int v2604 = 0; v2604 < 8; v2604 += 2) {	// L2998
      for (int v2605 = 0; v2605 < 8; v2605 += 2) {	// L2999
        #pragma HLS pipeline II=1
        float v2606 = v2598[v2603][v2604][v2605];	// L3000
        v2599[(v2603 + (v2600 * 8))][(v2604 + (v2601 * 8))][(v2605 + (v2602 * 8))] = v2606;	// L3001
        float v2607 = v2598[v2603][v2604][(v2605 + 1)];	// L3002
        v2599[(v2603 + (v2600 * 8))][(v2604 + (v2601 * 8))][((v2605 + (v2602 * 8)) + 1)] = v2607;	// L3003
        float v2608 = v2598[v2603][(v2604 + 1)][v2605];	// L3004
        v2599[(v2603 + (v2600 * 8))][((v2604 + (v2601 * 8)) + 1)][(v2605 + (v2602 * 8))] = v2608;	// L3005
        float v2609 = v2598[v2603][(v2604 + 1)][(v2605 + 1)];	// L3006
        v2599[(v2603 + (v2600 * 8))][((v2604 + (v2601 * 8)) + 1)][((v2605 + (v2602 * 8)) + 1)] = v2609;	// L3007
      }
    }
  }
}

void forward_node192(
  float v2610[8][8][8],
  float v2611[8][8][8],
  float v2612[8][8],
  float v2613[8][8][8],
  float v2614[8][8][8],
  int v2615,
  int v2616,
  int v2617
) {	// L3013
  #pragma HLS inline
  #pragma HLS array_partition variable=v2610 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2610 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2610 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2611 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2611 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2611 core=ram_t2p_bram

  #pragma HLS resource variable=v2612 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2613 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2613 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2613 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2614 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2614 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2614 core=ram_t2p_bram

  for (int v2618 = 0; v2618 < 8; v2618 += 1) {	// L3014
    for (int v2619 = 0; v2619 < 8; v2619 += 1) {	// L3015
      for (int v2620 = 0; v2620 < 8; v2620 += 2) {	// L3016
        for (int v2621 = 0; v2621 < 8; v2621 += 2) {	// L3017
          #pragma HLS pipeline II=1
          float v2622 = v2611[v2619][v2620][v2621];	// L3018
          float v2623 = v2613[v2619][v2620][v2621];	// L3019
          float v2624 = v2614[v2619][v2620][v2621];	// L3020
          float v2625 = (v2618 == 0) ? v2623 : v2624;	// L3021
          float v2626 = ((v2618 + (v2617 * 8)) == 0 && v2615 == 0 && v2616 == 0) ? v2622 : v2625;	// L3022
          float v2627 = v2610[v2618][v2620][v2621];	// L3023
          float v2628 = v2612[v2619][v2618];	// L3024
          float v2629 = v2627 * v2628;	// L3025
          float v2630 = v2626 + v2629;	// L3026
          v2614[v2619][v2620][v2621] = v2630;	// L3027
          float v2631 = v2611[v2619][v2620][(v2621 + 1)];	// L3028
          float v2632 = v2613[v2619][v2620][(v2621 + 1)];	// L3029
          float v2633 = v2614[v2619][v2620][(v2621 + 1)];	// L3030
          float v2634 = (v2618 == 0) ? v2632 : v2633;	// L3031
          float v2635 = ((v2618 + (v2617 * 8)) == 0 && v2615 == 0 && v2616 == 0) ? v2631 : v2634;	// L3032
          float v2636 = v2610[v2618][v2620][(v2621 + 1)];	// L3033
          float v2637 = v2636 * v2628;	// L3034
          float v2638 = v2635 + v2637;	// L3035
          v2614[v2619][v2620][(v2621 + 1)] = v2638;	// L3036
          float v2639 = v2611[v2619][(v2620 + 1)][v2621];	// L3037
          float v2640 = v2613[v2619][(v2620 + 1)][v2621];	// L3038
          float v2641 = v2614[v2619][(v2620 + 1)][v2621];	// L3039
          float v2642 = (v2618 == 0) ? v2640 : v2641;	// L3040
          float v2643 = ((v2618 + (v2617 * 8)) == 0 && v2615 == 0 && v2616 == 0) ? v2639 : v2642;	// L3041
          float v2644 = v2610[v2618][(v2620 + 1)][v2621];	// L3042
          float v2645 = v2644 * v2628;	// L3043
          float v2646 = v2643 + v2645;	// L3044
          v2614[v2619][(v2620 + 1)][v2621] = v2646;	// L3045
          float v2647 = v2611[v2619][(v2620 + 1)][(v2621 + 1)];	// L3046
          float v2648 = v2613[v2619][(v2620 + 1)][(v2621 + 1)];	// L3047
          float v2649 = v2614[v2619][(v2620 + 1)][(v2621 + 1)];	// L3048
          float v2650 = (v2618 == 0) ? v2648 : v2649;	// L3049
          float v2651 = ((v2618 + (v2617 * 8)) == 0 && v2615 == 0 && v2616 == 0) ? v2647 : v2650;	// L3050
          float v2652 = v2610[v2618][(v2620 + 1)][(v2621 + 1)];	// L3051
          float v2653 = v2652 * v2628;	// L3052
          float v2654 = v2651 + v2653;	// L3053
          v2614[v2619][(v2620 + 1)][(v2621 + 1)] = v2654;	// L3054
        }
      }
    }
  }
}

void forward_node193(
  float v2655[64][64][3][3],
  float v2656[8][8],
  int v2657,
  int v2658,
  int v2659,
  int v2660
) {	// L3061
  #pragma HLS inline
  #pragma HLS resource variable=v2656 core=ram_t2p_bram

  for (int v2661 = 0; v2661 < 8; v2661 += 1) {	// L3062
    for (int v2662 = 0; v2662 < 8; v2662 += 1) {	// L3063
      #pragma HLS pipeline II=1
      float v2663 = v2655[(v2661 + (v2659 * 8))][(v2662 + (v2660 * 8))][v2657][v2658];	// L3064
      v2656[v2661][v2662] = v2663;	// L3065
    }
  }
}

void forward_node194(
  float v2664[64][56][56],
  float v2665[8][8][8],
  int v2666,
  int v2667,
  int v2668,
  int v2669,
  int v2670
) {	// L3070
  #pragma HLS inline
  #pragma HLS array_partition variable=v2664 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2664 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2665 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2665 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2665 core=ram_t2p_bram

  for (int v2671 = 0; v2671 < 8; v2671 += 1) {	// L3071
    for (int v2672 = 0; v2672 < 8; v2672 += 2) {	// L3072
      for (int v2673 = 0; v2673 < 8; v2673 += 2) {	// L3073
        #pragma HLS pipeline II=1
        float v2674 = v2664[(v2671 + (v2666 * 8))][(((v2672 + v2667) + (v2668 * 8)) - 1)][(((v2673 + v2669) + (v2670 * 8)) - 1)];	// L3074
        v2665[v2671][v2672][v2673] = v2674;	// L3075
        float v2675 = v2664[(v2671 + (v2666 * 8))][(((v2672 + v2667) + (v2668 * 8)) - 1)][((v2673 + v2669) + (v2670 * 8))];	// L3076
        v2665[v2671][v2672][(v2673 + 1)] = v2675;	// L3077
        float v2676 = v2664[(v2671 + (v2666 * 8))][((v2672 + v2667) + (v2668 * 8))][(((v2673 + v2669) + (v2670 * 8)) - 1)];	// L3078
        v2665[v2671][(v2672 + 1)][v2673] = v2676;	// L3079
        float v2677 = v2664[(v2671 + (v2666 * 8))][((v2672 + v2667) + (v2668 * 8))][((v2673 + v2669) + (v2670 * 8))];	// L3080
        v2665[v2671][(v2672 + 1)][(v2673 + 1)] = v2677;	// L3081
      }
    }
  }
}

void forward_node195(
  float v2678[64][56][56],
  float v2679[8][8][8],
  int v2680,
  int v2681,
  int v2682
) {	// L3087
  #pragma HLS inline
  #pragma HLS array_partition variable=v2678 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2678 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2679 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2679 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2679 core=ram_t2p_bram

  for (int v2683 = 0; v2683 < 8; v2683 += 1) {	// L3088
    for (int v2684 = 0; v2684 < 8; v2684 += 2) {	// L3089
      for (int v2685 = 0; v2685 < 8; v2685 += 2) {	// L3090
        #pragma HLS pipeline II=1
        float v2686 = v2678[(v2683 + (v2680 * 8))][(v2684 + (v2681 * 8))][(v2685 + (v2682 * 8))];	// L3091
        v2679[v2683][v2684][v2685] = v2686;	// L3092
        float v2687 = v2678[(v2683 + (v2680 * 8))][(v2684 + (v2681 * 8))][((v2685 + (v2682 * 8)) + 1)];	// L3093
        v2679[v2683][v2684][(v2685 + 1)] = v2687;	// L3094
        float v2688 = v2678[(v2683 + (v2680 * 8))][((v2684 + (v2681 * 8)) + 1)][(v2685 + (v2682 * 8))];	// L3095
        v2679[v2683][(v2684 + 1)][v2685] = v2688;	// L3096
        float v2689 = v2678[(v2683 + (v2680 * 8))][((v2684 + (v2681 * 8)) + 1)][((v2685 + (v2682 * 8)) + 1)];	// L3097
        v2679[v2683][(v2684 + 1)][(v2685 + 1)] = v2689;	// L3098
      }
    }
  }
}

void forward_node196(
  float v2690[64][56][56],
  float v2691[8][8][8],
  int v2692,
  int v2693,
  int v2694
) {	// L3104
  #pragma HLS inline
  #pragma HLS array_partition variable=v2690 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2690 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2691 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2691 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2691 core=ram_t2p_bram

  for (int v2695 = 0; v2695 < 8; v2695 += 1) {	// L3105
    for (int v2696 = 0; v2696 < 8; v2696 += 2) {	// L3106
      for (int v2697 = 0; v2697 < 8; v2697 += 2) {	// L3107
        #pragma HLS pipeline II=1
        float v2698 = v2690[(v2695 + (v2692 * 8))][(v2696 + (v2693 * 8))][(v2697 + (v2694 * 8))];	// L3108
        v2691[v2695][v2696][v2697] = v2698;	// L3109
        float v2699 = v2690[(v2695 + (v2692 * 8))][(v2696 + (v2693 * 8))][((v2697 + (v2694 * 8)) + 1)];	// L3110
        v2691[v2695][v2696][(v2697 + 1)] = v2699;	// L3111
        float v2700 = v2690[(v2695 + (v2692 * 8))][((v2696 + (v2693 * 8)) + 1)][(v2697 + (v2694 * 8))];	// L3112
        v2691[v2695][(v2696 + 1)][v2697] = v2700;	// L3113
        float v2701 = v2690[(v2695 + (v2692 * 8))][((v2696 + (v2693 * 8)) + 1)][((v2697 + (v2694 * 8)) + 1)];	// L3114
        v2691[v2695][(v2696 + 1)][(v2697 + 1)] = v2701;	// L3115
      }
    }
  }
}

void forward_node190(
  float v2702[64][56][56],
  float v2703[64][64][3][3],
  float v2704[64][56][56],
  float v2705[64][56][56],
  float v2706[64][56][56]
) {	// L3121
  #pragma HLS array_partition variable=v2702 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2702 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2704 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2704 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2705 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2705 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2706 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2706 cyclic factor=2 dim=3

  for (int v2707 = 0; v2707 < 28224; v2707 += 1) {	// L3122
    #pragma HLS dataflow
    int v2708 = (v2707 % 7);	// L3123
    int v2709 = ((v2707 / 7) % 7);	// L3124
    int v2710 = (((v2707 / 7) / 7) % 8);	// L3125
    int v2711 = ((((v2707 / 7) / 7) / 8) % 3);	// L3126
    int v2712 = (((((v2707 / 7) / 7) / 8) / 3) % 3);	// L3127
    int v2713 = (((((v2707 / 7) / 7) / 8) / 3) / 3);	// L3128
    float v2714[8][8];	// L3129
    #pragma HLS resource variable=v2714 core=ram_t2p_bram

    float v2715[8][8][8];	// L3130
    #pragma HLS array_partition variable=v2715 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2715 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2715 core=ram_t2p_bram

    float v2716[8][8][8];	// L3131
    #pragma HLS array_partition variable=v2716 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2716 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2716 core=ram_t2p_bram

    float v2717[8][8][8];	// L3132
    #pragma HLS array_partition variable=v2717 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2717 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2717 core=ram_t2p_bram

    forward_node196(v2704, v2717, v2710, v2709, v2708);	// L3133
    forward_node195(v2705, v2716, v2710, v2709, v2708);	// L3134
    forward_node194(v2702, v2715, v2713, v2712, v2709, v2711, v2708);	// L3135
    forward_node193(v2703, v2714, v2712, v2711, v2710, v2713);	// L3136
    float v2718[8][8][8];	// L3137
    #pragma HLS array_partition variable=v2718 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2718 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2718 core=ram_t2p_bram

    forward_node192(v2715, v2717, v2714, v2716, v2718, v2712, v2711, v2713);	// L3138
    forward_node191(v2718, v2706, v2710, v2709, v2708);	// L3139
  }
}

void forward_node198(
  float v2719[8][8][8],
  float v2720[64][56][56],
  int v2721,
  int v2722,
  int v2723
) {	// L3143
  #pragma HLS inline
  #pragma HLS resource variable=v2719 core=ram_t2p_bram

  for (int v2724 = 0; v2724 < 8; v2724 += 1) {	// L3144
    for (int v2725 = 0; v2725 < 8; v2725 += 1) {	// L3145
      for (int v2726 = 0; v2726 < 8; v2726 += 1) {	// L3146
        #pragma HLS pipeline II=1
        float v2727 = v2719[v2724][v2725][v2726];	// L3147
        v2720[(v2724 + (v2721 * 8))][(v2725 + (v2722 * 8))][(v2726 + (v2723 * 8))] = v2727;	// L3148
      }
    }
  }
}

void forward_node199(
  float v2728[64],
  float v2729[64],
  float v2730[64],
  float v2731[64],
  float v2732[8][8][8],
  float v2733[8][8][8],
  int v2734
) {	// L3154
  #pragma HLS inline
  #pragma HLS resource variable=v2728 core=ram_t2p_bram

  #pragma HLS resource variable=v2729 core=ram_t2p_bram

  #pragma HLS resource variable=v2730 core=ram_t2p_bram

  #pragma HLS resource variable=v2731 core=ram_t2p_bram

  #pragma HLS resource variable=v2732 core=ram_t2p_bram

  #pragma HLS resource variable=v2733 core=ram_t2p_bram

  for (int v2735 = 0; v2735 < 8; v2735 += 1) {	// L3157
    for (int v2736 = 0; v2736 < 8; v2736 += 1) {	// L3158
      for (int v2737 = 0; v2737 < 8; v2737 += 1) {	// L3159
        #pragma HLS pipeline II=1
        float v2738 = v2732[v2735][v2736][v2737];	// L3160
        float v2739 = v2731[(v2735 + (v2734 * 8))];	// L3161
        float v2740 = v2730[(v2735 + (v2734 * 8))];	// L3162
        float v2741 = v2728[(v2735 + (v2734 * 8))];	// L3163
        float v2742 = v2729[(v2735 + (v2734 * 8))];	// L3164
        float v2743 = (double)0.000010;	// L3165
        float v2744 = v2742 + v2743;	// L3166
        float v2745 = 1.0 / sqrt(v2744);	// L3167
        float v2746 = v2738 - v2741;	// L3168
        float v2747 = v2746 * v2745;	// L3169
        float v2748 = v2747 * v2739;	// L3170
        float v2749 = v2748 + v2740;	// L3171
        bool v2750 = v2749 > (float)0.000000;	// L3172
        float v2751 = v2750 ? v2749 : (float)0.000000;	// L3173
        v2733[v2735][v2736][v2737] = v2751;	// L3174
      }
    }
  }
}

void forward_node200(
  float v2752[64][56][56],
  float v2753[8][8][8],
  int v2754,
  int v2755,
  int v2756
) {	// L3180
  #pragma HLS inline
  #pragma HLS resource variable=v2753 core=ram_t2p_bram

  for (int v2757 = 0; v2757 < 8; v2757 += 1) {	// L3181
    for (int v2758 = 0; v2758 < 8; v2758 += 1) {	// L3182
      for (int v2759 = 0; v2759 < 8; v2759 += 1) {	// L3183
        #pragma HLS pipeline II=1
        float v2760 = v2752[(v2757 + (v2754 * 8))][(v2758 + (v2755 * 8))][(v2759 + (v2756 * 8))];	// L3184
        v2753[v2757][v2758][v2759] = v2760;	// L3185
      }
    }
  }
}

void forward_node197(
  float v2761[64],
  float v2762[64],
  float v2763[64],
  float v2764[64],
  float v2765[64][56][56],
  float v2766[64][56][56]
) {	// L3191
  #pragma HLS resource variable=v2761 core=ram_t2p_bram

  #pragma HLS resource variable=v2762 core=ram_t2p_bram

  #pragma HLS resource variable=v2763 core=ram_t2p_bram

  #pragma HLS resource variable=v2764 core=ram_t2p_bram

  for (int v2767 = 0; v2767 < 392; v2767 += 1) {	// L3192
    #pragma HLS dataflow
    int v2768 = (v2767 % 7);	// L3193
    int v2769 = ((v2767 / 7) % 7);	// L3194
    int v2770 = ((v2767 / 7) / 7);	// L3195
    float v2771[8][8][8];	// L3196
    #pragma HLS resource variable=v2771 core=ram_t2p_bram

    float v2772[8][8][8];	// L3197
    #pragma HLS resource variable=v2772 core=ram_t2p_bram

    forward_node200(v2765, v2772, v2770, v2769, v2768);	// L3198
    forward_node199(v2761, v2762, v2763, v2764, v2772, v2771, v2770);	// L3199
    forward_node198(v2771, v2766, v2770, v2769, v2768);	// L3200
  }
}

void forward_node202(
  float v2773[8][8][8],
  float v2774[64][56][56],
  int v2775,
  int v2776,
  int v2777
) {	// L3204
  #pragma HLS inline
  #pragma HLS array_partition variable=v2773 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2773 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2773 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2774 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2774 cyclic factor=2 dim=3

  for (int v2778 = 0; v2778 < 8; v2778 += 1) {	// L3205
    for (int v2779 = 0; v2779 < 8; v2779 += 2) {	// L3206
      for (int v2780 = 0; v2780 < 8; v2780 += 2) {	// L3207
        #pragma HLS pipeline II=1
        float v2781 = v2773[v2778][v2779][v2780];	// L3208
        v2774[(v2778 + (v2775 * 8))][(v2779 + (v2776 * 8))][(v2780 + (v2777 * 8))] = v2781;	// L3209
        float v2782 = v2773[v2778][v2779][(v2780 + 1)];	// L3210
        v2774[(v2778 + (v2775 * 8))][(v2779 + (v2776 * 8))][((v2780 + (v2777 * 8)) + 1)] = v2782;	// L3211
        float v2783 = v2773[v2778][(v2779 + 1)][v2780];	// L3212
        v2774[(v2778 + (v2775 * 8))][((v2779 + (v2776 * 8)) + 1)][(v2780 + (v2777 * 8))] = v2783;	// L3213
        float v2784 = v2773[v2778][(v2779 + 1)][(v2780 + 1)];	// L3214
        v2774[(v2778 + (v2775 * 8))][((v2779 + (v2776 * 8)) + 1)][((v2780 + (v2777 * 8)) + 1)] = v2784;	// L3215
      }
    }
  }
}

void forward_node203(
  float v2785[8][8][8],
  float v2786[8][8],
  float v2787[8][8][8],
  float v2788[8][8][8],
  float v2789[8][8][8],
  int v2790,
  int v2791,
  int v2792
) {	// L3221
  #pragma HLS inline
  #pragma HLS array_partition variable=v2785 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2785 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2785 core=ram_t2p_bram

  #pragma HLS resource variable=v2786 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2787 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2787 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2787 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2788 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2788 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2788 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2789 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2789 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2789 core=ram_t2p_bram

  for (int v2793 = 0; v2793 < 8; v2793 += 1) {	// L3222
    for (int v2794 = 0; v2794 < 8; v2794 += 1) {	// L3223
      for (int v2795 = 0; v2795 < 8; v2795 += 2) {	// L3224
        for (int v2796 = 0; v2796 < 8; v2796 += 2) {	// L3225
          #pragma HLS pipeline II=1
          float v2797 = v2785[v2794][v2795][v2796];	// L3226
          float v2798 = v2788[v2794][v2795][v2796];	// L3227
          float v2799 = v2789[v2794][v2795][v2796];	// L3228
          float v2800 = (v2793 == 0) ? v2798 : v2799;	// L3229
          float v2801 = ((v2793 + (v2792 * 8)) == 0 && v2791 == 0 && v2790 == 0) ? v2797 : v2800;	// L3230
          float v2802 = v2787[v2793][v2795][v2796];	// L3231
          float v2803 = v2786[v2794][v2793];	// L3232
          float v2804 = v2802 * v2803;	// L3233
          float v2805 = v2801 + v2804;	// L3234
          v2789[v2794][v2795][v2796] = v2805;	// L3235
          float v2806 = v2785[v2794][v2795][(v2796 + 1)];	// L3236
          float v2807 = v2788[v2794][v2795][(v2796 + 1)];	// L3237
          float v2808 = v2789[v2794][v2795][(v2796 + 1)];	// L3238
          float v2809 = (v2793 == 0) ? v2807 : v2808;	// L3239
          float v2810 = ((v2793 + (v2792 * 8)) == 0 && v2791 == 0 && v2790 == 0) ? v2806 : v2809;	// L3240
          float v2811 = v2787[v2793][v2795][(v2796 + 1)];	// L3241
          float v2812 = v2811 * v2803;	// L3242
          float v2813 = v2810 + v2812;	// L3243
          v2789[v2794][v2795][(v2796 + 1)] = v2813;	// L3244
          float v2814 = v2785[v2794][(v2795 + 1)][v2796];	// L3245
          float v2815 = v2788[v2794][(v2795 + 1)][v2796];	// L3246
          float v2816 = v2789[v2794][(v2795 + 1)][v2796];	// L3247
          float v2817 = (v2793 == 0) ? v2815 : v2816;	// L3248
          float v2818 = ((v2793 + (v2792 * 8)) == 0 && v2791 == 0 && v2790 == 0) ? v2814 : v2817;	// L3249
          float v2819 = v2787[v2793][(v2795 + 1)][v2796];	// L3250
          float v2820 = v2819 * v2803;	// L3251
          float v2821 = v2818 + v2820;	// L3252
          v2789[v2794][(v2795 + 1)][v2796] = v2821;	// L3253
          float v2822 = v2785[v2794][(v2795 + 1)][(v2796 + 1)];	// L3254
          float v2823 = v2788[v2794][(v2795 + 1)][(v2796 + 1)];	// L3255
          float v2824 = v2789[v2794][(v2795 + 1)][(v2796 + 1)];	// L3256
          float v2825 = (v2793 == 0) ? v2823 : v2824;	// L3257
          float v2826 = ((v2793 + (v2792 * 8)) == 0 && v2791 == 0 && v2790 == 0) ? v2822 : v2825;	// L3258
          float v2827 = v2787[v2793][(v2795 + 1)][(v2796 + 1)];	// L3259
          float v2828 = v2827 * v2803;	// L3260
          float v2829 = v2826 + v2828;	// L3261
          v2789[v2794][(v2795 + 1)][(v2796 + 1)] = v2829;	// L3262
        }
      }
    }
  }
}

void forward_node204(
  float v2830[64][64][3][3],
  float v2831[8][8],
  int v2832,
  int v2833,
  int v2834,
  int v2835
) {	// L3269
  #pragma HLS inline
  #pragma HLS resource variable=v2831 core=ram_t2p_bram

  for (int v2836 = 0; v2836 < 8; v2836 += 1) {	// L3270
    for (int v2837 = 0; v2837 < 8; v2837 += 1) {	// L3271
      #pragma HLS pipeline II=1
      float v2838 = v2830[(v2836 + (v2834 * 8))][(v2837 + (v2835 * 8))][v2832][v2833];	// L3272
      v2831[v2836][v2837] = v2838;	// L3273
    }
  }
}

void forward_node205(
  float v2839[64][56][56],
  float v2840[8][8][8],
  int v2841,
  int v2842,
  int v2843,
  int v2844,
  int v2845
) {	// L3278
  #pragma HLS inline
  #pragma HLS array_partition variable=v2839 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2839 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2840 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2840 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2840 core=ram_t2p_bram

  for (int v2846 = 0; v2846 < 8; v2846 += 1) {	// L3279
    for (int v2847 = 0; v2847 < 8; v2847 += 2) {	// L3280
      for (int v2848 = 0; v2848 < 8; v2848 += 2) {	// L3281
        #pragma HLS pipeline II=1
        float v2849 = v2839[(v2846 + (v2841 * 8))][(((v2847 + v2842) + (v2843 * 8)) - 1)][(((v2848 + v2844) + (v2845 * 8)) - 1)];	// L3282
        v2840[v2846][v2847][v2848] = v2849;	// L3283
        float v2850 = v2839[(v2846 + (v2841 * 8))][(((v2847 + v2842) + (v2843 * 8)) - 1)][((v2848 + v2844) + (v2845 * 8))];	// L3284
        v2840[v2846][v2847][(v2848 + 1)] = v2850;	// L3285
        float v2851 = v2839[(v2846 + (v2841 * 8))][((v2847 + v2842) + (v2843 * 8))][(((v2848 + v2844) + (v2845 * 8)) - 1)];	// L3286
        v2840[v2846][(v2847 + 1)][v2848] = v2851;	// L3287
        float v2852 = v2839[(v2846 + (v2841 * 8))][((v2847 + v2842) + (v2843 * 8))][((v2848 + v2844) + (v2845 * 8))];	// L3288
        v2840[v2846][(v2847 + 1)][(v2848 + 1)] = v2852;	// L3289
      }
    }
  }
}

void forward_node206(
  float v2853[64][56][56],
  float v2854[8][8][8],
  int v2855,
  int v2856,
  int v2857
) {	// L3295
  #pragma HLS inline
  #pragma HLS array_partition variable=v2853 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2853 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2854 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2854 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2854 core=ram_t2p_bram

  for (int v2858 = 0; v2858 < 8; v2858 += 1) {	// L3296
    for (int v2859 = 0; v2859 < 8; v2859 += 2) {	// L3297
      for (int v2860 = 0; v2860 < 8; v2860 += 2) {	// L3298
        #pragma HLS pipeline II=1
        float v2861 = v2853[(v2858 + (v2855 * 8))][(v2859 + (v2856 * 8))][(v2860 + (v2857 * 8))];	// L3299
        v2854[v2858][v2859][v2860] = v2861;	// L3300
        float v2862 = v2853[(v2858 + (v2855 * 8))][(v2859 + (v2856 * 8))][((v2860 + (v2857 * 8)) + 1)];	// L3301
        v2854[v2858][v2859][(v2860 + 1)] = v2862;	// L3302
        float v2863 = v2853[(v2858 + (v2855 * 8))][((v2859 + (v2856 * 8)) + 1)][(v2860 + (v2857 * 8))];	// L3303
        v2854[v2858][(v2859 + 1)][v2860] = v2863;	// L3304
        float v2864 = v2853[(v2858 + (v2855 * 8))][((v2859 + (v2856 * 8)) + 1)][((v2860 + (v2857 * 8)) + 1)];	// L3305
        v2854[v2858][(v2859 + 1)][(v2860 + 1)] = v2864;	// L3306
      }
    }
  }
}

void forward_node207(
  float v2865[64][56][56],
  float v2866[8][8][8],
  int v2867,
  int v2868,
  int v2869
) {	// L3312
  #pragma HLS inline
  #pragma HLS array_partition variable=v2865 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2865 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2866 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2866 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2866 core=ram_t2p_bram

  for (int v2870 = 0; v2870 < 8; v2870 += 1) {	// L3313
    for (int v2871 = 0; v2871 < 8; v2871 += 2) {	// L3314
      for (int v2872 = 0; v2872 < 8; v2872 += 2) {	// L3315
        #pragma HLS pipeline II=1
        float v2873 = v2865[(v2870 + (v2867 * 8))][(v2871 + (v2868 * 8))][(v2872 + (v2869 * 8))];	// L3316
        v2866[v2870][v2871][v2872] = v2873;	// L3317
        float v2874 = v2865[(v2870 + (v2867 * 8))][(v2871 + (v2868 * 8))][((v2872 + (v2869 * 8)) + 1)];	// L3318
        v2866[v2870][v2871][(v2872 + 1)] = v2874;	// L3319
        float v2875 = v2865[(v2870 + (v2867 * 8))][((v2871 + (v2868 * 8)) + 1)][(v2872 + (v2869 * 8))];	// L3320
        v2866[v2870][(v2871 + 1)][v2872] = v2875;	// L3321
        float v2876 = v2865[(v2870 + (v2867 * 8))][((v2871 + (v2868 * 8)) + 1)][((v2872 + (v2869 * 8)) + 1)];	// L3322
        v2866[v2870][(v2871 + 1)][(v2872 + 1)] = v2876;	// L3323
      }
    }
  }
}

void forward_node201(
  float v2877[64][64][3][3],
  float v2878[64][56][56],
  float v2879[64][56][56],
  float v2880[64][56][56],
  float v2881[64][56][56]
) {	// L3329
  #pragma HLS array_partition variable=v2878 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2878 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2879 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2879 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2880 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2880 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2881 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2881 cyclic factor=2 dim=3

  for (int v2882 = 0; v2882 < 28224; v2882 += 1) {	// L3330
    #pragma HLS dataflow
    int v2883 = (v2882 % 7);	// L3331
    int v2884 = ((v2882 / 7) % 7);	// L3332
    int v2885 = (((v2882 / 7) / 7) % 8);	// L3333
    int v2886 = ((((v2882 / 7) / 7) / 8) % 3);	// L3334
    int v2887 = (((((v2882 / 7) / 7) / 8) / 3) % 3);	// L3335
    int v2888 = (((((v2882 / 7) / 7) / 8) / 3) / 3);	// L3336
    float v2889[8][8];	// L3337
    #pragma HLS resource variable=v2889 core=ram_t2p_bram

    float v2890[8][8][8];	// L3338
    #pragma HLS array_partition variable=v2890 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2890 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2890 core=ram_t2p_bram

    float v2891[8][8][8];	// L3339
    #pragma HLS array_partition variable=v2891 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2891 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2891 core=ram_t2p_bram

    float v2892[8][8][8];	// L3340
    #pragma HLS array_partition variable=v2892 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2892 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2892 core=ram_t2p_bram

    forward_node207(v2879, v2892, v2885, v2884, v2883);	// L3341
    forward_node206(v2880, v2891, v2885, v2884, v2883);	// L3342
    forward_node205(v2878, v2890, v2888, v2887, v2884, v2886, v2883);	// L3343
    forward_node204(v2877, v2889, v2887, v2886, v2885, v2888);	// L3344
    float v2893[8][8][8];	// L3345
    #pragma HLS array_partition variable=v2893 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2893 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2893 core=ram_t2p_bram

    forward_node203(v2892, v2889, v2890, v2891, v2893, v2886, v2887, v2888);	// L3346
    forward_node202(v2893, v2881, v2885, v2884, v2883);	// L3347
  }
}

void forward_node209(
  float v2894[8][8][8],
  float v2895[64][56][56],
  int v2896,
  int v2897,
  int v2898
) {	// L3351
  #pragma HLS inline
  #pragma HLS resource variable=v2894 core=ram_t2p_bram

  for (int v2899 = 0; v2899 < 8; v2899 += 1) {	// L3352
    for (int v2900 = 0; v2900 < 8; v2900 += 1) {	// L3353
      for (int v2901 = 0; v2901 < 8; v2901 += 1) {	// L3354
        #pragma HLS pipeline II=1
        float v2902 = v2894[v2899][v2900][v2901];	// L3355
        v2895[(v2899 + (v2896 * 8))][(v2900 + (v2897 * 8))][(v2901 + (v2898 * 8))] = v2902;	// L3356
      }
    }
  }
}

void forward_node210(
  float v2903[8][8][8],
  float v2904[8][8][8],
  float v2905[8][8][8]
) {	// L3362
  #pragma HLS inline
  #pragma HLS resource variable=v2903 core=ram_t2p_bram

  #pragma HLS resource variable=v2904 core=ram_t2p_bram

  #pragma HLS resource variable=v2905 core=ram_t2p_bram

  for (int v2906 = 0; v2906 < 8; v2906 += 1) {	// L3363
    for (int v2907 = 0; v2907 < 8; v2907 += 1) {	// L3364
      for (int v2908 = 0; v2908 < 8; v2908 += 1) {	// L3365
        #pragma HLS pipeline II=1
        float v2909 = v2903[v2906][v2907][v2908];	// L3366
        float v2910 = v2904[v2906][v2907][v2908];	// L3367
        float v2911 = max(v2910, v2909);	// L3368
        v2905[v2906][v2907][v2908] = v2911;	// L3369
      }
    }
  }
}

void forward_node211(
  float v2912[64][56][56],
  float v2913[8][8][8],
  int v2914,
  int v2915,
  int v2916
) {	// L3375
  #pragma HLS inline
  #pragma HLS resource variable=v2913 core=ram_t2p_bram

  for (int v2917 = 0; v2917 < 8; v2917 += 1) {	// L3376
    for (int v2918 = 0; v2918 < 8; v2918 += 1) {	// L3377
      for (int v2919 = 0; v2919 < 8; v2919 += 1) {	// L3378
        #pragma HLS pipeline II=1
        float v2920 = v2912[(v2917 + (v2914 * 8))][(v2918 + (v2915 * 8))][(v2919 + (v2916 * 8))];	// L3379
        v2913[v2917][v2918][v2919] = v2920;	// L3380
      }
    }
  }
}

void forward_node212(
  float v2921[64][112][112],
  float v2922[8][8][8],
  int v2923,
  int v2924,
  int v2925,
  int v2926,
  int v2927
) {	// L3386
  #pragma HLS inline
  #pragma HLS resource variable=v2922 core=ram_t2p_bram

  for (int v2928 = 0; v2928 < 8; v2928 += 1) {	// L3387
    for (int v2929 = 0; v2929 < 8; v2929 += 1) {	// L3388
      for (int v2930 = 0; v2930 < 8; v2930 += 1) {	// L3389
        #pragma HLS pipeline II=1
        float v2931 = v2921[(v2928 + (v2923 * 8))][((((v2929 * 2) + v2924) + (v2925 * 16)) - 1)][((((v2930 * 2) + v2926) + (v2927 * 16)) - 1)];	// L3390
        v2922[v2928][v2929][v2930] = v2931;	// L3391
      }
    }
  }
}

void forward_node208(
  float v2932[64][112][112],
  float v2933[64][56][56],
  float v2934[64][56][56]
) {	// L3397
  for (int v2935 = 0; v2935 < 3528; v2935 += 1) {	// L3398
    #pragma HLS dataflow
    int v2936 = (v2935 % 7);	// L3399
    int v2937 = ((v2935 / 7) % 7);	// L3400
    int v2938 = (((v2935 / 7) / 7) % 8);	// L3401
    int v2939 = ((((v2935 / 7) / 7) / 8) % 3);	// L3402
    int v2940 = ((((v2935 / 7) / 7) / 8) / 3);	// L3403
    float v2941[8][8][8];	// L3404
    #pragma HLS resource variable=v2941 core=ram_t2p_bram

    float v2942[8][8][8];	// L3405
    #pragma HLS resource variable=v2942 core=ram_t2p_bram

    forward_node212(v2932, v2942, v2938, v2940, v2937, v2939, v2936);	// L3406
    forward_node211(v2933, v2941, v2938, v2937, v2936);	// L3407
    float v2943[8][8][8];	// L3408
    #pragma HLS resource variable=v2943 core=ram_t2p_bram

    forward_node210(v2942, v2941, v2943);	// L3409
    forward_node209(v2943, v2934, v2938, v2937, v2936);	// L3410
  }
}

void forward_node214(
  float v2944[8][8][8],
  float v2945[64][112][112],
  int v2946,
  int v2947,
  int v2948
) {	// L3414
  #pragma HLS inline
  #pragma HLS resource variable=v2944 core=ram_t2p_bram

  for (int v2949 = 0; v2949 < 8; v2949 += 1) {	// L3415
    for (int v2950 = 0; v2950 < 8; v2950 += 1) {	// L3416
      for (int v2951 = 0; v2951 < 8; v2951 += 1) {	// L3417
        #pragma HLS pipeline II=1
        float v2952 = v2944[v2949][v2950][v2951];	// L3418
        v2945[(v2949 + (v2946 * 8))][(v2950 + (v2947 * 8))][(v2951 + (v2948 * 8))] = v2952;	// L3419
      }
    }
  }
}

void forward_node215(
  float v2953[64],
  float v2954[8][8][8],
  float v2955[64],
  float v2956[64],
  float v2957[64],
  float v2958[8][8][8],
  int v2959
) {	// L3425
  #pragma HLS inline
  #pragma HLS resource variable=v2953 core=ram_t2p_bram

  #pragma HLS resource variable=v2954 core=ram_t2p_bram

  #pragma HLS resource variable=v2955 core=ram_t2p_bram

  #pragma HLS resource variable=v2956 core=ram_t2p_bram

  #pragma HLS resource variable=v2957 core=ram_t2p_bram

  #pragma HLS resource variable=v2958 core=ram_t2p_bram

  for (int v2960 = 0; v2960 < 8; v2960 += 1) {	// L3428
    for (int v2961 = 0; v2961 < 8; v2961 += 1) {	// L3429
      for (int v2962 = 0; v2962 < 8; v2962 += 1) {	// L3430
        #pragma HLS pipeline II=1
        float v2963 = v2954[v2960][v2961][v2962];	// L3431
        float v2964 = v2956[(v2960 + (v2959 * 8))];	// L3432
        float v2965 = v2955[(v2960 + (v2959 * 8))];	// L3433
        float v2966 = v2957[(v2960 + (v2959 * 8))];	// L3434
        float v2967 = v2953[(v2960 + (v2959 * 8))];	// L3435
        float v2968 = (double)0.000010;	// L3436
        float v2969 = v2967 + v2968;	// L3437
        float v2970 = 1.0 / sqrt(v2969);	// L3438
        float v2971 = v2963 - v2966;	// L3439
        float v2972 = v2971 * v2970;	// L3440
        float v2973 = v2972 * v2964;	// L3441
        float v2974 = v2973 + v2965;	// L3442
        bool v2975 = v2974 > (float)0.000000;	// L3443
        float v2976 = v2975 ? v2974 : (float)0.000000;	// L3444
        v2958[v2960][v2961][v2962] = v2976;	// L3445
      }
    }
  }
}

void forward_node216(
  float v2977[64][112][112],
  float v2978[8][8][8],
  int v2979,
  int v2980,
  int v2981
) {	// L3451
  #pragma HLS inline
  #pragma HLS resource variable=v2978 core=ram_t2p_bram

  for (int v2982 = 0; v2982 < 8; v2982 += 1) {	// L3452
    for (int v2983 = 0; v2983 < 8; v2983 += 1) {	// L3453
      for (int v2984 = 0; v2984 < 8; v2984 += 1) {	// L3454
        #pragma HLS pipeline II=1
        float v2985 = v2977[(v2982 + (v2979 * 8))][(v2983 + (v2980 * 8))][(v2984 + (v2981 * 8))];	// L3455
        v2978[v2982][v2983][v2984] = v2985;	// L3456
      }
    }
  }
}

void forward_node213(
  float v2986[64][112][112],
  float v2987[64],
  float v2988[64],
  float v2989[64],
  float v2990[64],
  float v2991[64][112][112]
) {	// L3462
  #pragma HLS resource variable=v2987 core=ram_t2p_bram

  #pragma HLS resource variable=v2988 core=ram_t2p_bram

  #pragma HLS resource variable=v2989 core=ram_t2p_bram

  #pragma HLS resource variable=v2990 core=ram_t2p_bram

  for (int v2992 = 0; v2992 < 1568; v2992 += 1) {	// L3463
    #pragma HLS dataflow
    int v2993 = (v2992 % 14);	// L3464
    int v2994 = ((v2992 / 14) % 14);	// L3465
    int v2995 = ((v2992 / 14) / 14);	// L3466
    float v2996[8][8][8];	// L3467
    #pragma HLS resource variable=v2996 core=ram_t2p_bram

    float v2997[8][8][8];	// L3468
    #pragma HLS resource variable=v2997 core=ram_t2p_bram

    forward_node216(v2986, v2997, v2995, v2994, v2993);	// L3469
    forward_node215(v2989, v2997, v2990, v2988, v2987, v2996, v2995);	// L3470
    forward_node214(v2996, v2991, v2995, v2994, v2993);	// L3471
  }
}

void forward_node218(
  float v2998[8][8][8],
  float v2999[64][112][112],
  int v3000,
  int v3001,
  int v3002
) {	// L3475
  #pragma HLS inline
  #pragma HLS array_partition variable=v2998 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2998 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2998 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2999 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2999 cyclic factor=2 dim=3

  for (int v3003 = 0; v3003 < 8; v3003 += 1) {	// L3476
    for (int v3004 = 0; v3004 < 8; v3004 += 2) {	// L3477
      for (int v3005 = 0; v3005 < 8; v3005 += 2) {	// L3478
        #pragma HLS pipeline II=1
        float v3006 = v2998[v3003][v3004][v3005];	// L3479
        v2999[(v3003 + (v3000 * 8))][(v3004 + (v3001 * 8))][(v3005 + (v3002 * 8))] = v3006;	// L3480
        float v3007 = v2998[v3003][v3004][(v3005 + 1)];	// L3481
        v2999[(v3003 + (v3000 * 8))][(v3004 + (v3001 * 8))][((v3005 + (v3002 * 8)) + 1)] = v3007;	// L3482
        float v3008 = v2998[v3003][(v3004 + 1)][v3005];	// L3483
        v2999[(v3003 + (v3000 * 8))][((v3004 + (v3001 * 8)) + 1)][(v3005 + (v3002 * 8))] = v3008;	// L3484
        float v3009 = v2998[v3003][(v3004 + 1)][(v3005 + 1)];	// L3485
        v2999[(v3003 + (v3000 * 8))][((v3004 + (v3001 * 8)) + 1)][((v3005 + (v3002 * 8)) + 1)] = v3009;	// L3486
      }
    }
  }
}

void forward_node219(
  float v3010[8][8],
  float v3011[8],
  float v3012[8][8][8],
  float v3013[8][8][8]
) {	// L3492
  #pragma HLS inline
  #pragma HLS array_partition variable=v3010 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3010 cyclic factor=2 dim=2
  #pragma HLS resource variable=v3010 core=ram_t2p_bram

  #pragma HLS resource variable=v3011 core=ram_t2p_bram

  #pragma HLS array_partition variable=v3012 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3012 cyclic factor=2 dim=3
  #pragma HLS resource variable=v3012 core=ram_t2p_bram

  #pragma HLS array_partition variable=v3013 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3013 cyclic factor=2 dim=3
  #pragma HLS resource variable=v3013 core=ram_t2p_bram

  for (int v3014 = 0; v3014 < 8; v3014 += 1) {	// L3493
    for (int v3015 = 0; v3015 < 8; v3015 += 2) {	// L3494
      for (int v3016 = 0; v3016 < 8; v3016 += 2) {	// L3495
        #pragma HLS pipeline II=1
        float v3017 = v3010[v3015][v3016];	// L3496
        float v3018 = v3011[v3014];	// L3497
        float v3019 = v3012[v3014][v3015][v3016];	// L3498
        float v3020 = v3017 * v3018;	// L3499
        float v3021 = v3019 + v3020;	// L3500
        v3013[v3014][v3015][v3016] = v3021;	// L3501
        float v3022 = v3010[v3015][(v3016 + 1)];	// L3502
        float v3023 = v3012[v3014][v3015][(v3016 + 1)];	// L3503
        float v3024 = v3022 * v3018;	// L3504
        float v3025 = v3023 + v3024;	// L3505
        v3013[v3014][v3015][(v3016 + 1)] = v3025;	// L3506
        float v3026 = v3010[(v3015 + 1)][v3016];	// L3507
        float v3027 = v3012[v3014][(v3015 + 1)][v3016];	// L3508
        float v3028 = v3026 * v3018;	// L3509
        float v3029 = v3027 + v3028;	// L3510
        v3013[v3014][(v3015 + 1)][v3016] = v3029;	// L3511
        float v3030 = v3010[(v3015 + 1)][(v3016 + 1)];	// L3512
        float v3031 = v3012[v3014][(v3015 + 1)][(v3016 + 1)];	// L3513
        float v3032 = v3030 * v3018;	// L3514
        float v3033 = v3031 + v3032;	// L3515
        v3013[v3014][(v3015 + 1)][(v3016 + 1)] = v3033;	// L3516
      }
    }
  }
}

void forward_node220(
  float v3034[64][112][112],
  float v3035[8][8][8],
  int v3036,
  int v3037,
  int v3038
) {	// L3522
  #pragma HLS inline
  #pragma HLS array_partition variable=v3034 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3034 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v3035 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3035 cyclic factor=2 dim=3
  #pragma HLS resource variable=v3035 core=ram_t2p_bram

  for (int v3039 = 0; v3039 < 8; v3039 += 1) {	// L3523
    for (int v3040 = 0; v3040 < 8; v3040 += 2) {	// L3524
      for (int v3041 = 0; v3041 < 8; v3041 += 2) {	// L3525
        #pragma HLS pipeline II=1
        float v3042 = v3034[(v3039 + (v3036 * 8))][(v3040 + (v3037 * 8))][(v3041 + (v3038 * 8))];	// L3526
        v3035[v3039][v3040][v3041] = v3042;	// L3527
        float v3043 = v3034[(v3039 + (v3036 * 8))][(v3040 + (v3037 * 8))][((v3041 + (v3038 * 8)) + 1)];	// L3528
        v3035[v3039][v3040][(v3041 + 1)] = v3043;	// L3529
        float v3044 = v3034[(v3039 + (v3036 * 8))][((v3040 + (v3037 * 8)) + 1)][(v3041 + (v3038 * 8))];	// L3530
        v3035[v3039][(v3040 + 1)][v3041] = v3044;	// L3531
        float v3045 = v3034[(v3039 + (v3036 * 8))][((v3040 + (v3037 * 8)) + 1)][((v3041 + (v3038 * 8)) + 1)];	// L3532
        v3035[v3039][(v3040 + 1)][(v3041 + 1)] = v3045;	// L3533
      }
    }
  }
}

void forward_node221(
  float v3046[64][3][7][7],
  float v3047[8],
  int v3048,
  int v3049,
  int v3050,
  int v3051
) {	// L3539
  #pragma HLS inline
  #pragma HLS resource variable=v3047 core=ram_t2p_bram

  for (int v3052 = 0; v3052 < 8; v3052 += 1) {	// L3540
    #pragma HLS pipeline II=1
    float v3053 = v3046[(v3052 + (v3051 * 8))][v3048][v3049][v3050];	// L3541
    v3047[v3052] = v3053;	// L3542
  }
}

void forward_node222(
  float v3054[3][224][224],
  float v3055[8][8],
  int v3056,
  int v3057,
  int v3058,
  int v3059,
  int v3060
) {	// L3546
  #pragma HLS inline
  #pragma HLS array_partition variable=v3054 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v3054 cyclic factor=4 dim=3

  #pragma HLS array_partition variable=v3055 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3055 cyclic factor=2 dim=2
  #pragma HLS resource variable=v3055 core=ram_t2p_bram

  for (int v3061 = 0; v3061 < 8; v3061 += 2) {	// L3547
    for (int v3062 = 0; v3062 < 8; v3062 += 2) {	// L3548
      #pragma HLS pipeline II=1
      float v3063 = v3054[v3056][((((v3061 * 2) + v3057) + (v3058 * 16)) - 3)][((((v3062 * 2) + v3059) + (v3060 * 16)) - 3)];	// L3549
      v3055[v3061][v3062] = v3063;	// L3550
      float v3064 = v3054[v3056][((((v3061 * 2) + v3057) + (v3058 * 16)) - 3)][((((v3062 * 2) + v3059) + (v3060 * 16)) - 1)];	// L3551
      v3055[v3061][(v3062 + 1)] = v3064;	// L3552
      float v3065 = v3054[v3056][((((v3061 * 2) + v3057) + (v3058 * 16)) - 1)][((((v3062 * 2) + v3059) + (v3060 * 16)) - 3)];	// L3553
      v3055[(v3061 + 1)][v3062] = v3065;	// L3554
      float v3066 = v3054[v3056][((((v3061 * 2) + v3057) + (v3058 * 16)) - 1)][((((v3062 * 2) + v3059) + (v3060 * 16)) - 1)];	// L3555
      v3055[(v3061 + 1)][(v3062 + 1)] = v3066;	// L3556
    }
  }
}

void forward_node217(
  float v3067[64][3][7][7],
  float v3068[3][224][224],
  float v3069[64][112][112],
  float v3070[64][112][112]
) {	// L3561
  #pragma HLS array_partition variable=v3068 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v3068 cyclic factor=4 dim=3

  #pragma HLS array_partition variable=v3069 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3069 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v3070 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3070 cyclic factor=2 dim=3

  for (int v3071 = 0; v3071 < 230496; v3071 += 1) {	// L3562
    #pragma HLS dataflow
    int v3072 = (v3071 % 14);	// L3563
    int v3073 = ((v3071 / 14) % 14);	// L3564
    int v3074 = (((v3071 / 14) / 14) % 8);	// L3565
    int v3075 = ((((v3071 / 14) / 14) / 8) % 7);	// L3566
    int v3076 = (((((v3071 / 14) / 14) / 8) / 7) % 7);	// L3567
    int v3077 = (((((v3071 / 14) / 14) / 8) / 7) / 7);	// L3568
    float v3078[8][8][8];	// L3569
    #pragma HLS array_partition variable=v3078 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v3078 cyclic factor=2 dim=3
    #pragma HLS resource variable=v3078 core=ram_t2p_bram

    float v3079[8];	// L3570
    #pragma HLS resource variable=v3079 core=ram_t2p_bram

    float v3080[8][8];	// L3571
    #pragma HLS array_partition variable=v3080 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v3080 cyclic factor=2 dim=2
    #pragma HLS resource variable=v3080 core=ram_t2p_bram

    forward_node222(v3068, v3080, v3077, v3076, v3073, v3075, v3072);	// L3572
    forward_node221(v3067, v3079, v3077, v3076, v3075, v3074);	// L3573
    forward_node220(v3069, v3078, v3074, v3073, v3072);	// L3574
    float v3081[8][8][8];	// L3575
    #pragma HLS array_partition variable=v3081 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v3081 cyclic factor=2 dim=3
    #pragma HLS resource variable=v3081 core=ram_t2p_bram

    forward_node219(v3080, v3079, v3078, v3081);	// L3576
    forward_node218(v3081, v3070, v3074, v3073, v3072);	// L3577
  }
}

/// This is top function.
void forward(
  float v3082[3][224][224],
  float v3083[1000],
  float v3084[64][3][7][7],
  float v3085[64][64][3][3],
  float v3086[64][64][3][3],
  float v3087[64][64][3][3],
  float v3088[64][64][3][3],
  float v3089[128][64][3][3],
  float v3090[128][128][3][3],
  float v3091[128][64],
  float v3092[128][128][3][3],
  float v3093[128][128][3][3],
  float v3094[256][128][3][3],
  float v3095[256][256][3][3],
  float v3096[256][128],
  float v3097[256][256][3][3],
  float v3098[256][256][3][3],
  float v3099[512][256][3][3],
  float v3100[512][512][3][3],
  float v3101[512][256],
  float v3102[512][512][3][3],
  float v3103[512][512][3][3],
  float v3104[512][1000],
  float v3105[64][112][112],
  float v3106[64][112][112],
  float v3107[64][112][112],
  float v3108[64][112][112],
  float v3109[64][112][112],
  float v3110[64][56][56],
  float v3111[64][56][56],
  float v3112[64][56][56],
  float v3113[64][56][56],
  float v3114[64][56][56],
  float v3115[64][56][56],
  float v3116[64][56][56],
  float v3117[64][56][56],
  float v3118[64][56][56],
  float v3119[64][56][56],
  float v3120[64][56][56],
  float v3121[64][56][56],
  float v3122[64][56][56],
  float v3123[64][56][56],
  float v3124[64][56][56],
  float v3125[64][56][56],
  float v3126[64][56][56],
  float v3127[64][56][56],
  float v3128[64][56][56],
  float v3129[64][56][56],
  float v3130[64][56][56],
  float v3131[64][56][56],
  float v3132[64][56][56],
  float v3133[64][56][56],
  float v3134[64][56][56],
  float v3135[64][56][56],
  float v3136[64][56][56],
  float v3137[64][56][56],
  float v3138[64][56][56],
  float v3139[128][28][28],
  float v3140[128][28][28],
  float v3141[128][28][28],
  float v3142[128][28][28],
  float v3143[128][28][28],
  float v3144[128][28][28],
  float v3145[128][28][28],
  float v3146[128][28][28],
  float v3147[128][28][28],
  float v3148[128][28][28],
  float v3149[128][28][28],
  float v3150[128][28][28],
  float v3151[128][28][28],
  float v3152[128][28][28],
  float v3153[128][28][28],
  float v3154[128][28][28],
  float v3155[128][28][28],
  float v3156[128][28][28],
  float v3157[128][28][28],
  float v3158[128][28][28],
  float v3159[128][28][28],
  float v3160[128][28][28],
  float v3161[128][28][28],
  float v3162[128][28][28],
  float v3163[128][28][28],
  float v3164[128][28][28],
  float v3165[128][28][28],
  float v3166[128][28][28],
  float v3167[128][28][28],
  float v3168[256][14][14],
  float v3169[256][14][14],
  float v3170[256][14][14],
  float v3171[256][14][14],
  float v3172[256][14][14],
  float v3173[256][14][14],
  float v3174[256][14][14],
  float v3175[256][14][14],
  float v3176[256][14][14],
  float v3177[256][14][14],
  float v3178[256][14][14],
  float v3179[256][14][14],
  float v3180[256][14][14],
  float v3181[256][14][14],
  float v3182[256][14][14],
  float v3183[256][14][14],
  float v3184[256][14][14],
  float v3185[256][14][14],
  float v3186[256][14][14],
  float v3187[256][14][14],
  float v3188[256][14][14],
  float v3189[256][14][14],
  float v3190[256][14][14],
  float v3191[256][14][14],
  float v3192[256][14][14],
  float v3193[256][14][14],
  float v3194[256][14][14],
  float v3195[256][14][14],
  float v3196[256][14][14],
  float v3197[512][7][7],
  float v3198[512][7][7],
  float v3199[512][7][7],
  float v3200[512][7][7],
  float v3201[512][7][7],
  float v3202[512][7][7],
  float v3203[512][7][7],
  float v3204[512][7][7],
  float v3205[512][7][7],
  float v3206[512][7][7],
  float v3207[512][7][7],
  float v3208[512][7][7],
  float v3209[512][7][7],
  float v3210[512][7][7],
  float v3211[512][7][7],
  float v3212[512][7][7],
  float v3213[512][7][7],
  float v3214[512][7][7],
  float v3215[512][7][7],
  float v3216[512][7][7],
  float v3217[512][7][7],
  float v3218[512][7][7],
  float v3219[512][7][7],
  float v3220[512][7][7],
  float v3221[512][7][7],
  float v3222[512][7][7],
  float v3223[512][7][7],
  float v3224[512][7][7]
) {	// L3581
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface ap_memory port=v3224
  #pragma HLS stable variable=v3224

  #pragma HLS interface ap_memory port=v3223
  #pragma HLS stable variable=v3223

  #pragma HLS interface ap_memory port=v3222
  #pragma HLS stable variable=v3222
  #pragma HLS array_partition variable=v3222 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3221
  #pragma HLS stable variable=v3221

  #pragma HLS interface ap_memory port=v3220
  #pragma HLS stable variable=v3220

  #pragma HLS interface ap_memory port=v3219
  #pragma HLS stable variable=v3219
  #pragma HLS array_partition variable=v3219 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3218
  #pragma HLS stable variable=v3218
  #pragma HLS array_partition variable=v3218 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3217
  #pragma HLS stable variable=v3217

  #pragma HLS interface ap_memory port=v3216
  #pragma HLS stable variable=v3216
  #pragma HLS array_partition variable=v3216 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3215
  #pragma HLS stable variable=v3215

  #pragma HLS interface ap_memory port=v3214
  #pragma HLS stable variable=v3214

  #pragma HLS interface ap_memory port=v3213
  #pragma HLS stable variable=v3213

  #pragma HLS interface ap_memory port=v3212
  #pragma HLS stable variable=v3212

  #pragma HLS interface ap_memory port=v3211
  #pragma HLS stable variable=v3211

  #pragma HLS interface ap_memory port=v3210
  #pragma HLS stable variable=v3210
  #pragma HLS array_partition variable=v3210 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3209
  #pragma HLS stable variable=v3209
  #pragma HLS array_partition variable=v3209 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3208
  #pragma HLS stable variable=v3208
  #pragma HLS array_partition variable=v3208 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3207
  #pragma HLS stable variable=v3207

  #pragma HLS interface ap_memory port=v3206
  #pragma HLS stable variable=v3206

  #pragma HLS interface ap_memory port=v3205
  #pragma HLS stable variable=v3205

  #pragma HLS interface ap_memory port=v3204
  #pragma HLS stable variable=v3204

  #pragma HLS interface ap_memory port=v3203
  #pragma HLS stable variable=v3203

  #pragma HLS interface ap_memory port=v3202
  #pragma HLS stable variable=v3202
  #pragma HLS array_partition variable=v3202 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3201
  #pragma HLS stable variable=v3201
  #pragma HLS array_partition variable=v3201 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3200
  #pragma HLS stable variable=v3200
  #pragma HLS array_partition variable=v3200 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3199
  #pragma HLS stable variable=v3199

  #pragma HLS interface ap_memory port=v3198
  #pragma HLS stable variable=v3198
  #pragma HLS array_partition variable=v3198 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3197
  #pragma HLS stable variable=v3197

  #pragma HLS interface ap_memory port=v3196
  #pragma HLS stable variable=v3196

  #pragma HLS interface ap_memory port=v3195
  #pragma HLS stable variable=v3195

  #pragma HLS interface ap_memory port=v3194
  #pragma HLS stable variable=v3194

  #pragma HLS interface ap_memory port=v3193
  #pragma HLS stable variable=v3193
  #pragma HLS array_partition variable=v3193 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3192
  #pragma HLS stable variable=v3192

  #pragma HLS interface ap_memory port=v3191
  #pragma HLS stable variable=v3191

  #pragma HLS interface ap_memory port=v3190
  #pragma HLS stable variable=v3190
  #pragma HLS array_partition variable=v3190 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3189
  #pragma HLS stable variable=v3189
  #pragma HLS array_partition variable=v3189 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3188
  #pragma HLS stable variable=v3188

  #pragma HLS interface ap_memory port=v3187
  #pragma HLS stable variable=v3187
  #pragma HLS array_partition variable=v3187 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3186
  #pragma HLS stable variable=v3186

  #pragma HLS interface ap_memory port=v3185
  #pragma HLS stable variable=v3185

  #pragma HLS interface ap_memory port=v3184
  #pragma HLS stable variable=v3184

  #pragma HLS interface ap_memory port=v3183
  #pragma HLS stable variable=v3183

  #pragma HLS interface ap_memory port=v3182
  #pragma HLS stable variable=v3182

  #pragma HLS interface ap_memory port=v3181
  #pragma HLS stable variable=v3181
  #pragma HLS array_partition variable=v3181 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3180
  #pragma HLS stable variable=v3180
  #pragma HLS array_partition variable=v3180 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3179
  #pragma HLS stable variable=v3179
  #pragma HLS array_partition variable=v3179 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3178
  #pragma HLS stable variable=v3178

  #pragma HLS interface ap_memory port=v3177
  #pragma HLS stable variable=v3177

  #pragma HLS interface ap_memory port=v3176
  #pragma HLS stable variable=v3176

  #pragma HLS interface ap_memory port=v3175
  #pragma HLS stable variable=v3175

  #pragma HLS interface ap_memory port=v3174
  #pragma HLS stable variable=v3174

  #pragma HLS interface ap_memory port=v3173
  #pragma HLS stable variable=v3173
  #pragma HLS array_partition variable=v3173 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3172
  #pragma HLS stable variable=v3172
  #pragma HLS array_partition variable=v3172 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3171
  #pragma HLS stable variable=v3171
  #pragma HLS array_partition variable=v3171 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3170
  #pragma HLS stable variable=v3170

  #pragma HLS interface ap_memory port=v3169
  #pragma HLS stable variable=v3169
  #pragma HLS array_partition variable=v3169 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3168
  #pragma HLS stable variable=v3168

  #pragma HLS interface ap_memory port=v3167
  #pragma HLS stable variable=v3167

  #pragma HLS interface ap_memory port=v3166
  #pragma HLS stable variable=v3166

  #pragma HLS interface ap_memory port=v3165
  #pragma HLS stable variable=v3165

  #pragma HLS interface ap_memory port=v3164
  #pragma HLS stable variable=v3164
  #pragma HLS array_partition variable=v3164 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3163
  #pragma HLS stable variable=v3163

  #pragma HLS interface ap_memory port=v3162
  #pragma HLS stable variable=v3162

  #pragma HLS interface ap_memory port=v3161
  #pragma HLS stable variable=v3161
  #pragma HLS array_partition variable=v3161 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3160
  #pragma HLS stable variable=v3160
  #pragma HLS array_partition variable=v3160 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3159
  #pragma HLS stable variable=v3159

  #pragma HLS interface ap_memory port=v3158
  #pragma HLS stable variable=v3158
  #pragma HLS array_partition variable=v3158 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3157
  #pragma HLS stable variable=v3157

  #pragma HLS interface ap_memory port=v3156
  #pragma HLS stable variable=v3156

  #pragma HLS interface ap_memory port=v3155
  #pragma HLS stable variable=v3155

  #pragma HLS interface ap_memory port=v3154
  #pragma HLS stable variable=v3154

  #pragma HLS interface ap_memory port=v3153
  #pragma HLS stable variable=v3153

  #pragma HLS interface ap_memory port=v3152
  #pragma HLS stable variable=v3152
  #pragma HLS array_partition variable=v3152 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3151
  #pragma HLS stable variable=v3151
  #pragma HLS array_partition variable=v3151 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3150
  #pragma HLS stable variable=v3150
  #pragma HLS array_partition variable=v3150 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3149
  #pragma HLS stable variable=v3149

  #pragma HLS interface ap_memory port=v3148
  #pragma HLS stable variable=v3148

  #pragma HLS interface ap_memory port=v3147
  #pragma HLS stable variable=v3147

  #pragma HLS interface ap_memory port=v3146
  #pragma HLS stable variable=v3146

  #pragma HLS interface ap_memory port=v3145
  #pragma HLS stable variable=v3145

  #pragma HLS interface ap_memory port=v3144
  #pragma HLS stable variable=v3144
  #pragma HLS array_partition variable=v3144 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3143
  #pragma HLS stable variable=v3143
  #pragma HLS array_partition variable=v3143 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3142
  #pragma HLS stable variable=v3142
  #pragma HLS array_partition variable=v3142 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3141
  #pragma HLS stable variable=v3141

  #pragma HLS interface ap_memory port=v3140
  #pragma HLS stable variable=v3140
  #pragma HLS array_partition variable=v3140 cyclic factor=2 dim=1


  #pragma HLS interface ap_memory port=v3139
  #pragma HLS stable variable=v3139

  #pragma HLS interface ap_memory port=v3138
  #pragma HLS stable variable=v3138

  #pragma HLS interface ap_memory port=v3137
  #pragma HLS stable variable=v3137

  #pragma HLS interface ap_memory port=v3136
  #pragma HLS stable variable=v3136

  #pragma HLS interface ap_memory port=v3135
  #pragma HLS stable variable=v3135
  #pragma HLS array_partition variable=v3135 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3135 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3134
  #pragma HLS stable variable=v3134

  #pragma HLS interface ap_memory port=v3133
  #pragma HLS stable variable=v3133

  #pragma HLS interface ap_memory port=v3132
  #pragma HLS stable variable=v3132
  #pragma HLS array_partition variable=v3132 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3132 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3131
  #pragma HLS stable variable=v3131
  #pragma HLS array_partition variable=v3131 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3131 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3130
  #pragma HLS stable variable=v3130

  #pragma HLS interface ap_memory port=v3129
  #pragma HLS stable variable=v3129
  #pragma HLS array_partition variable=v3129 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3129 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3128
  #pragma HLS stable variable=v3128

  #pragma HLS interface ap_memory port=v3127
  #pragma HLS stable variable=v3127

  #pragma HLS interface ap_memory port=v3126
  #pragma HLS stable variable=v3126
  #pragma HLS array_partition variable=v3126 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3126 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3125
  #pragma HLS stable variable=v3125
  #pragma HLS array_partition variable=v3125 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3125 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3124
  #pragma HLS stable variable=v3124
  #pragma HLS array_partition variable=v3124 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3124 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3123
  #pragma HLS stable variable=v3123

  #pragma HLS interface ap_memory port=v3122
  #pragma HLS stable variable=v3122

  #pragma HLS interface ap_memory port=v3121
  #pragma HLS stable variable=v3121
  #pragma HLS array_partition variable=v3121 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3121 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3120
  #pragma HLS stable variable=v3120
  #pragma HLS array_partition variable=v3120 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3120 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3119
  #pragma HLS stable variable=v3119

  #pragma HLS interface ap_memory port=v3118
  #pragma HLS stable variable=v3118
  #pragma HLS array_partition variable=v3118 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3118 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3117
  #pragma HLS stable variable=v3117
  #pragma HLS array_partition variable=v3117 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3117 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3116
  #pragma HLS stable variable=v3116
  #pragma HLS array_partition variable=v3116 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3116 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3115
  #pragma HLS stable variable=v3115
  #pragma HLS array_partition variable=v3115 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3115 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3114
  #pragma HLS stable variable=v3114
  #pragma HLS array_partition variable=v3114 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3114 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3113
  #pragma HLS stable variable=v3113

  #pragma HLS interface ap_memory port=v3112
  #pragma HLS stable variable=v3112
  #pragma HLS array_partition variable=v3112 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3112 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3111
  #pragma HLS stable variable=v3111

  #pragma HLS interface ap_memory port=v3110
  #pragma HLS stable variable=v3110

  #pragma HLS interface ap_memory port=v3109
  #pragma HLS stable variable=v3109

  #pragma HLS interface ap_memory port=v3108
  #pragma HLS stable variable=v3108

  #pragma HLS interface ap_memory port=v3107
  #pragma HLS stable variable=v3107

  #pragma HLS interface ap_memory port=v3106
  #pragma HLS stable variable=v3106
  #pragma HLS array_partition variable=v3106 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3106 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3105
  #pragma HLS stable variable=v3105
  #pragma HLS array_partition variable=v3105 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3105 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3104
  #pragma HLS stable variable=v3104

  #pragma HLS interface ap_memory port=v3103
  #pragma HLS stable variable=v3103
  #pragma HLS array_partition variable=v3103 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3103 cyclic factor=2 dim=2


  #pragma HLS interface ap_memory port=v3102
  #pragma HLS stable variable=v3102
  #pragma HLS array_partition variable=v3102 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3102 cyclic factor=2 dim=2


  #pragma HLS interface ap_memory port=v3101
  #pragma HLS stable variable=v3101

  #pragma HLS interface ap_memory port=v3100
  #pragma HLS stable variable=v3100
  #pragma HLS array_partition variable=v3100 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3100 cyclic factor=2 dim=2


  #pragma HLS interface ap_memory port=v3099
  #pragma HLS stable variable=v3099

  #pragma HLS interface ap_memory port=v3098
  #pragma HLS stable variable=v3098
  #pragma HLS array_partition variable=v3098 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3098 cyclic factor=2 dim=2


  #pragma HLS interface ap_memory port=v3097
  #pragma HLS stable variable=v3097
  #pragma HLS array_partition variable=v3097 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3097 cyclic factor=2 dim=2


  #pragma HLS interface ap_memory port=v3096
  #pragma HLS stable variable=v3096

  #pragma HLS interface ap_memory port=v3095
  #pragma HLS stable variable=v3095
  #pragma HLS array_partition variable=v3095 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3095 cyclic factor=2 dim=2


  #pragma HLS interface ap_memory port=v3094
  #pragma HLS stable variable=v3094

  #pragma HLS interface ap_memory port=v3093
  #pragma HLS stable variable=v3093
  #pragma HLS array_partition variable=v3093 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3093 cyclic factor=2 dim=2


  #pragma HLS interface ap_memory port=v3092
  #pragma HLS stable variable=v3092
  #pragma HLS array_partition variable=v3092 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3092 cyclic factor=2 dim=2


  #pragma HLS interface ap_memory port=v3091
  #pragma HLS stable variable=v3091

  #pragma HLS interface ap_memory port=v3090
  #pragma HLS stable variable=v3090
  #pragma HLS array_partition variable=v3090 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3090 cyclic factor=2 dim=2


  #pragma HLS interface ap_memory port=v3089
  #pragma HLS stable variable=v3089

  #pragma HLS interface ap_memory port=v3088
  #pragma HLS stable variable=v3088

  #pragma HLS interface ap_memory port=v3087
  #pragma HLS stable variable=v3087

  #pragma HLS interface ap_memory port=v3086
  #pragma HLS stable variable=v3086

  #pragma HLS interface ap_memory port=v3085
  #pragma HLS stable variable=v3085

  #pragma HLS interface ap_memory port=v3084
  #pragma HLS stable variable=v3084

  #pragma HLS interface ap_memory port=v3083
  #pragma HLS stable variable=v3083

  #pragma HLS interface ap_memory port=v3082
  #pragma HLS stable variable=v3082
  #pragma HLS array_partition variable=v3082 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v3082 cyclic factor=4 dim=3


  float v3368[64] = {(float)1.016945, (float)3.716743, (float)0.000000, (float)3.282543, (float)0.000000, (float)0.658227, (float)4.370062, (float)0.000000, (float)0.915523, (float)0.000000, (float)4.125586, (float)2.743992, (float)2.839091, (float)0.000000, (float)11.072271, (float)0.500746, (float)2.231282, (float)4.825707, (float)2.698614, (float)9.369955, (float)3.733917, (float)5.484296, (float)5.712669, (float)0.445445, (float)0.436275, (float)7.156336, (float)13.717909, (float)5.251175, (float)6.817375, (float)1.672358, (float)1.653430, (float)1.232460, (float)4.907629, (float)3.073051, (float)4.238386, (float)4.993635, (float)0.000000, (float)1.521162, (float)0.000000, (float)0.351344, (float)0.170247, (float)1.420545, (float)1.908483, (float)2.151240, (float)2.660849, (float)4.844434, (float)1.929712, (float)1.499944, (float)0.000000, (float)1.530640, (float)0.365027, (float)2.937554, (float)5.466412, (float)0.707925, (float)3.331507, (float)0.771803, (float)2.406784, (float)6.521367, (float)4.126250, (float)1.050635, (float)2.953032, (float)11.365622, (float)4.769047, (float)1.655878};	// L3868
  #pragma HLS resource variable=v3368 core=ram_t2p_bram

  float v3369[64] = {(float)0.002768, (float)-0.025769, (float)0.000000, (float)-0.084605, (float)0.000000, (float)0.000497, (float)-0.022408, (float)-0.000000, (float)-0.004824, (float)0.000000, (float)0.039582, (float)0.031994, (float)-0.037490, (float)-0.000001, (float)0.006600, (float)0.004378, (float)0.064797, (float)0.111760, (float)0.036002, (float)-0.075075, (float)-0.038240, (float)0.084358, (float)-0.052287, (float)-0.011799, (float)0.001302, (float)0.032172, (float)-0.017784, (float)-0.091009, (float)0.113187, (float)-0.041632, (float)0.008730, (float)0.029693, (float)-0.070502, (float)-0.003485, (float)0.109771, (float)-0.001734, (float)-0.000000, (float)0.029330, (float)-0.000000, (float)0.006732, (float)-0.003710, (float)0.016028, (float)-0.027883, (float)0.026593, (float)0.028475, (float)-0.127347, (float)0.044617, (float)0.026329, (float)0.000000, (float)-0.017045, (float)-0.003562, (float)-0.045841, (float)0.063876, (float)0.015220, (float)-0.038511, (float)-0.016428, (float)-0.016569, (float)0.056057, (float)-0.080306, (float)-0.002665, (float)-0.041718, (float)0.126113, (float)-0.049237, (float)-0.013261};	// L3869
  #pragma HLS resource variable=v3369 core=ram_t2p_bram

  float v3370[64] = {(float)0.230717, (float)0.253822, (float)-0.000001, (float)-0.664389, (float)-0.000000, (float)0.161522, (float)0.454504, (float)-0.000000, (float)0.300514, (float)-0.000008, (float)0.349418, (float)0.311481, (float)-0.249530, (float)-0.000035, (float)0.107726, (float)0.218971, (float)0.381413, (float)-0.529882, (float)-0.628644, (float)0.571398, (float)0.299847, (float)0.584304, (float)0.482022, (float)0.328526, (float)0.196717, (float)0.194962, (float)0.152145, (float)0.085522, (float)0.513143, (float)0.015237, (float)0.166442, (float)0.332394, (float)0.249211, (float)0.443367, (float)-0.280169, (float)-0.020385, (float)-0.000000, (float)0.321341, (float)-0.000000, (float)0.237767, (float)0.232908, (float)0.315275, (float)0.427762, (float)0.293128, (float)0.263794, (float)0.675976, (float)0.429100, (float)0.345663, (float)-0.000000, (float)0.247294, (float)0.303161, (float)0.615773, (float)0.398349, (float)0.332067, (float)-0.412188, (float)0.378069, (float)0.178953, (float)0.257478, (float)-0.449080, (float)0.213059, (float)0.569339, (float)0.572743, (float)-0.402383, (float)0.234064};	// L3870
  #pragma HLS resource variable=v3370 core=ram_t2p_bram

  float v3371[64] = {(float)0.234873, (float)0.266258, (float)-0.000000, (float)0.518700, (float)0.000000, (float)0.222385, (float)0.422887, (float)0.000000, (float)0.250932, (float)0.000002, (float)0.316872, (float)0.250492, (float)0.378926, (float)0.000011, (float)0.275264, (float)0.236741, (float)0.242022, (float)0.395315, (float)0.469346, (float)0.290896, (float)0.272684, (float)0.278028, (float)0.290692, (float)0.206927, (float)0.258990, (float)0.278711, (float)0.291150, (float)0.316014, (float)0.388891, (float)0.304112, (float)0.267757, (float)0.210925, (float)0.287084, (float)0.332426, (float)0.426728, (float)0.373261, (float)0.000000, (float)0.190678, (float)0.000000, (float)0.223030, (float)0.179079, (float)0.248601, (float)0.273995, (float)0.259229, (float)0.294202, (float)0.299236, (float)0.223689, (float)0.262799, (float)0.000000, (float)0.266098, (float)0.220890, (float)0.284286, (float)0.330723, (float)0.226810, (float)0.365381, (float)0.212299, (float)0.239653, (float)0.249496, (float)0.525831, (float)0.248248, (float)0.295653, (float)0.258777, (float)0.483256, (float)0.266704};	// L3871
  #pragma HLS resource variable=v3371 core=ram_t2p_bram

  float v3372[64] = {(float)0.435055, (float)0.204354, (float)0.234371, (float)0.555869, (float)0.962581, (float)0.348372, (float)0.087091, (float)0.685126, (float)0.471447, (float)1.264185, (float)0.151851, (float)0.672974, (float)0.242971, (float)0.557664, (float)0.870111, (float)0.241860, (float)0.205246, (float)0.814858, (float)0.304025, (float)0.261729, (float)0.805968, (float)0.800655, (float)1.558104, (float)0.240397, (float)0.444483, (float)0.676497, (float)0.556174, (float)0.937784, (float)0.258369, (float)0.317293, (float)0.096178, (float)0.411816, (float)0.519685, (float)0.976714, (float)1.270331, (float)0.890841, (float)0.360924, (float)0.222713, (float)1.158769, (float)1.596519, (float)0.406011, (float)0.255919, (float)0.176324, (float)0.279655, (float)0.375710, (float)0.128194, (float)1.827967, (float)0.314452, (float)0.741928, (float)0.212855, (float)0.812225, (float)0.466000, (float)0.406509, (float)0.491435, (float)0.481395, (float)0.169688, (float)0.400027, (float)0.386658, (float)0.149924, (float)0.413703, (float)0.067106, (float)0.830320, (float)0.243440, (float)0.344939};	// L3872
  #pragma HLS resource variable=v3372 core=ram_t2p_bram

  float v3373[64] = {(float)-0.433190, (float)-0.175695, (float)0.030747, (float)-0.705807, (float)-1.636446, (float)-0.798920, (float)-0.067817, (float)-0.195550, (float)-1.126039, (float)-0.957785, (float)0.003038, (float)-1.826511, (float)-0.039339, (float)-0.867986, (float)-1.106184, (float)-0.635920, (float)-0.987194, (float)-0.577787, (float)-1.334917, (float)-0.340781, (float)-1.198194, (float)-1.605752, (float)-2.170181, (float)-0.881360, (float)-0.817468, (float)-0.695106, (float)0.654208, (float)-1.642239, (float)0.281131, (float)0.316297, (float)-0.412330, (float)-1.402285, (float)-1.504384, (float)-2.503079, (float)-2.158050, (float)-1.364501, (float)-0.857909, (float)-0.220596, (float)-2.554775, (float)-2.269485, (float)-0.160925, (float)-0.855172, (float)0.528861, (float)1.349205, (float)-0.938154, (float)-0.335566, (float)-2.916777, (float)-1.596725, (float)-1.887467, (float)-1.616621, (float)-1.944322, (float)-2.019488, (float)-0.967085, (float)-1.388074, (float)-1.883634, (float)0.186852, (float)-1.348731, (float)-0.459333, (float)-0.454171, (float)-0.903211, (float)-0.076797, (float)-1.771877, (float)1.248418, (float)-0.913858};	// L3873
  #pragma HLS resource variable=v3373 core=ram_t2p_bram

  float v3374[64] = {(float)0.165661, (float)0.241959, (float)0.177965, (float)-0.043138, (float)-0.205331, (float)0.159751, (float)0.292936, (float)0.091178, (float)0.111647, (float)0.088373, (float)0.110414, (float)-0.203524, (float)0.153929, (float)0.085720, (float)-0.109398, (float)0.065450, (float)0.076595, (float)-0.206687, (float)-0.021186, (float)0.139637, (float)0.040125, (float)-0.282750, (float)-0.325706, (float)-0.003466, (float)-0.437301, (float)-0.124845, (float)0.128243, (float)-0.087393, (float)0.119922, (float)-0.082930, (float)-0.531535, (float)-0.078031, (float)-0.387627, (float)-0.054656, (float)-0.181555, (float)-0.188850, (float)0.132012, (float)0.003135, (float)-0.269714, (float)-0.298390, (float)0.139352, (float)0.259657, (float)0.137245, (float)0.005264, (float)0.013150, (float)0.329456, (float)-0.271507, (float)-0.018674, (float)-0.246698, (float)0.157942, (float)0.016460, (float)-0.089049, (float)-0.190278, (float)-0.078674, (float)0.170013, (float)-0.483183, (float)0.061921, (float)-0.067710, (float)0.312465, (float)-0.506396, (float)0.313813, (float)-0.261735, (float)-0.154493, (float)0.006281};	// L3874
  #pragma HLS resource variable=v3374 core=ram_t2p_bram

  float v3375[64] = {(float)0.309043, (float)0.214711, (float)0.236577, (float)0.425931, (float)0.513686, (float)0.218109, (float)0.220441, (float)0.229953, (float)0.264006, (float)0.269451, (float)0.213778, (float)0.460191, (float)0.266088, (float)0.231898, (float)0.390032, (float)0.238855, (float)0.266045, (float)0.363448, (float)0.347413, (float)0.247701, (float)0.328453, (float)0.534935, (float)0.644020, (float)0.227494, (float)0.448181, (float)0.307817, (float)0.260412, (float)0.465068, (float)0.217946, (float)0.285815, (float)0.342562, (float)0.441997, (float)0.444977, (float)0.450019, (float)0.551551, (float)0.509207, (float)0.256445, (float)0.263419, (float)0.566351, (float)0.640956, (float)0.222757, (float)0.198602, (float)0.245954, (float)0.224201, (float)0.214311, (float)0.198216, (float)0.636766, (float)0.310555, (float)0.504928, (float)0.240275, (float)0.306494, (float)0.375986, (float)0.379381, (float)0.428064, (float)0.299082, (float)0.332632, (float)0.259647, (float)0.334533, (float)0.200566, (float)0.435056, (float)0.168260, (float)0.514938, (float)0.262883, (float)0.325370};	// L3875
  #pragma HLS resource variable=v3375 core=ram_t2p_bram

  float v3376[64] = {(float)0.112977, (float)0.041237, (float)0.033545, (float)0.128228, (float)0.208378, (float)0.030685, (float)0.060566, (float)0.073705, (float)0.031310, (float)0.040856, (float)0.137575, (float)0.039873, (float)0.043669, (float)0.028224, (float)0.158828, (float)0.028779, (float)0.083656, (float)0.079875, (float)0.017730, (float)0.183914, (float)0.088387, (float)0.305412, (float)0.151206, (float)0.039352, (float)0.037352, (float)0.096941, (float)0.171872, (float)0.061037, (float)0.060672, (float)0.156014, (float)0.044767, (float)0.123553, (float)0.046391, (float)0.100531, (float)0.049753, (float)0.048147, (float)0.045006, (float)0.122899, (float)0.062314, (float)0.038063, (float)0.022906, (float)0.122661, (float)0.165624, (float)0.104651, (float)0.131607, (float)0.183358, (float)0.062244, (float)0.127234, (float)0.192906, (float)0.041888, (float)0.026284, (float)0.262289, (float)0.071197, (float)0.144237, (float)0.093709, (float)0.098259, (float)0.116282, (float)0.151095, (float)0.100875, (float)0.034225, (float)0.185439, (float)0.069805, (float)0.063052, (float)0.034959};	// L3876
  #pragma HLS resource variable=v3376 core=ram_t2p_bram

  float v3377[64] = {(float)0.167667, (float)0.005160, (float)0.786813, (float)0.166958, (float)0.477449, (float)-0.036223, (float)-0.057831, (float)0.002011, (float)-0.342021, (float)0.067421, (float)-0.097042, (float)-0.099979, (float)-0.065909, (float)-0.038458, (float)-0.070890, (float)-0.221758, (float)-0.134342, (float)0.119792, (float)-0.060160, (float)0.000618, (float)0.086362, (float)-0.146616, (float)0.035369, (float)-0.153914, (float)-0.041574, (float)-0.431713, (float)0.032966, (float)-0.079720, (float)-0.586836, (float)-0.246140, (float)-0.150488, (float)-0.401244, (float)-0.218739, (float)-0.635121, (float)0.069792, (float)0.141156, (float)0.275380, (float)-0.564455, (float)-0.111346, (float)-0.241368, (float)-0.131315, (float)-0.021504, (float)0.126393, (float)-0.168429, (float)0.169258, (float)-0.468406, (float)-0.690758, (float)0.204412, (float)0.001475, (float)-0.054254, (float)-0.148674, (float)0.126161, (float)-0.114532, (float)-0.159674, (float)0.122987, (float)-0.160528, (float)-0.225617, (float)-0.099545, (float)-0.162096, (float)0.322956, (float)-0.005539, (float)0.109110, (float)0.078114, (float)0.012128};	// L3877
  #pragma HLS resource variable=v3377 core=ram_t2p_bram

  float v3378[64] = {(float)0.227523, (float)0.008675, (float)-0.067346, (float)-0.068779, (float)0.359775, (float)-0.201667, (float)-0.000048, (float)0.023735, (float)0.395493, (float)0.037079, (float)0.006879, (float)0.275777, (float)-0.070272, (float)-0.239702, (float)-0.081753, (float)-0.094132, (float)-0.145436, (float)0.037301, (float)-0.361739, (float)-0.395614, (float)-0.407890, (float)0.003556, (float)-0.278780, (float)-0.035299, (float)-0.070281, (float)0.210055, (float)-0.004636, (float)-0.196648, (float)-0.280661, (float)-0.016540, (float)0.264518, (float)-0.089359, (float)-0.210460, (float)-0.130261, (float)0.172147, (float)0.053403, (float)-0.222954, (float)-0.048033, (float)0.245716, (float)0.209495, (float)0.162200, (float)0.113698, (float)0.114566, (float)-0.148701, (float)-0.032150, (float)-0.305488, (float)0.491247, (float)0.108730, (float)0.012779, (float)0.100442, (float)0.415533, (float)-0.014710, (float)0.023922, (float)0.099812, (float)-0.172731, (float)0.100782, (float)-0.145636, (float)-0.227354, (float)0.136365, (float)0.201266, (float)-0.057430, (float)0.235302, (float)-0.112987, (float)0.309331};	// L3878
  #pragma HLS resource variable=v3378 core=ram_t2p_bram

  float v3379[64] = {(float)0.249624, (float)0.219779, (float)0.275616, (float)0.607289, (float)0.265406, (float)0.294219, (float)0.113630, (float)0.442462, (float)0.286828, (float)0.297393, (float)0.250593, (float)0.410340, (float)0.485451, (float)0.338272, (float)0.466963, (float)0.177248, (float)0.217085, (float)0.502508, (float)0.226337, (float)0.366660, (float)0.486735, (float)0.458631, (float)0.465238, (float)0.219968, (float)0.151047, (float)0.276148, (float)0.381326, (float)0.280345, (float)0.238178, (float)0.395336, (float)0.303210, (float)0.316327, (float)0.202471, (float)0.232277, (float)0.200276, (float)0.166101, (float)0.468973, (float)0.347641, (float)0.341383, (float)0.227361, (float)0.248534, (float)0.235556, (float)0.272629, (float)0.465665, (float)0.342945, (float)0.246468, (float)0.467435, (float)0.281193, (float)0.624087, (float)0.415187, (float)0.340282, (float)0.421777, (float)0.115192, (float)0.298459, (float)0.580225, (float)0.279544, (float)0.470572, (float)0.451711, (float)0.430281, (float)0.274865, (float)0.342688, (float)0.113665, (float)0.506885, (float)0.437001};	// L3879
  #pragma HLS resource variable=v3379 core=ram_t2p_bram

  float v3380[64] = {(float)0.711093, (float)0.554310, (float)0.614262, (float)0.514770, (float)0.284033, (float)0.492356, (float)0.353583, (float)0.393900, (float)0.251109, (float)0.485877, (float)0.180289, (float)0.746771, (float)0.422531, (float)0.368559, (float)0.171940, (float)0.277702, (float)0.367602, (float)0.231068, (float)0.351484, (float)0.491670, (float)0.139254, (float)0.173218, (float)0.624763, (float)0.303798, (float)0.159914, (float)0.524640, (float)0.240992, (float)0.509616, (float)0.525103, (float)0.536898, (float)0.179995, (float)1.062263, (float)0.400559, (float)0.205999, (float)0.519441, (float)0.498068, (float)0.425001, (float)0.261632, (float)0.825168, (float)0.499086, (float)0.328967, (float)0.364203, (float)0.271639, (float)0.652044, (float)0.449248, (float)0.275283, (float)0.337728, (float)0.316726, (float)0.382971, (float)0.462435, (float)0.409776, (float)0.556643, (float)0.504820, (float)0.474730, (float)0.682017, (float)0.438720, (float)0.350608, (float)0.299549, (float)0.559473, (float)0.685530, (float)0.526043, (float)0.647788, (float)0.495957, (float)0.544854};	// L3880
  #pragma HLS resource variable=v3380 core=ram_t2p_bram

  float v3381[64] = {(float)-0.653447, (float)0.924024, (float)-1.340310, (float)-0.739529, (float)-0.583001, (float)-1.671664, (float)-0.337623, (float)0.191265, (float)-0.456502, (float)-0.787722, (float)-0.375650, (float)-0.229459, (float)-1.700279, (float)-0.613499, (float)0.542234, (float)-0.107217, (float)-0.231535, (float)-0.377473, (float)-1.802572, (float)-0.720974, (float)-0.028771, (float)-1.258514, (float)-1.814399, (float)0.050433, (float)-0.073926, (float)-1.550640, (float)-1.509207, (float)-1.062313, (float)0.170608, (float)0.152729, (float)0.398340, (float)-2.906515, (float)-0.906957, (float)-0.298274, (float)-1.840399, (float)-2.395594, (float)0.224111, (float)-0.075966, (float)-0.952490, (float)-1.463211, (float)0.765657, (float)-0.383212, (float)0.859049, (float)-1.321067, (float)-1.259886, (float)-0.121953, (float)-0.222972, (float)0.507102, (float)1.026229, (float)-0.596883, (float)-0.010449, (float)-1.401284, (float)-0.426694, (float)-0.997893, (float)-1.945835, (float)0.199095, (float)-0.884107, (float)-0.830212, (float)-0.307628, (float)-2.075870, (float)-1.264517, (float)0.267899, (float)0.434910, (float)-1.256771};	// L3881
  #pragma HLS resource variable=v3381 core=ram_t2p_bram

  float v3382[64] = {(float)-0.099726, (float)-0.475517, (float)-0.047361, (float)-0.269804, (float)-0.083441, (float)-0.007201, (float)0.047423, (float)0.102155, (float)-0.016982, (float)-0.147148, (float)0.230658, (float)0.144664, (float)-0.177520, (float)0.027268, (float)0.155878, (float)-0.183632, (float)0.123778, (float)-0.152205, (float)0.055447, (float)-0.288112, (float)-0.260619, (float)0.231643, (float)-0.324240, (float)-0.021868, (float)-0.264468, (float)0.057604, (float)-0.246467, (float)0.048148, (float)-0.352958, (float)0.094998, (float)-0.186222, (float)-0.170697, (float)-0.016055, (float)-0.260413, (float)-0.314487, (float)-0.108275, (float)0.065943, (float)-0.142717, (float)-0.056989, (float)-0.007582, (float)-0.300593, (float)-0.074393, (float)-0.068269, (float)-0.110389, (float)0.025262, (float)0.048921, (float)-0.251537, (float)0.115038, (float)-0.378323, (float)0.084590, (float)-0.036842, (float)0.143884, (float)-0.046804, (float)-0.308721, (float)-0.024006, (float)0.139675, (float)-0.090794, (float)-0.179469, (float)-0.112889, (float)-0.079252, (float)-0.149069, (float)0.059446, (float)-0.443326, (float)-0.013775};	// L3882
  #pragma HLS resource variable=v3382 core=ram_t2p_bram

  float v3383[64] = {(float)0.391013, (float)0.437474, (float)0.374570, (float)0.398993, (float)0.340426, (float)0.350275, (float)0.261832, (float)0.270686, (float)0.286510, (float)0.430750, (float)0.189464, (float)0.304125, (float)0.383696, (float)0.294356, (float)0.210527, (float)0.330406, (float)0.294271, (float)0.288749, (float)0.205988, (float)0.462650, (float)0.233496, (float)0.183100, (float)0.448870, (float)0.282973, (float)0.338903, (float)0.299658, (float)0.350253, (float)0.273501, (float)0.390755, (float)0.281686, (float)0.263607, (float)0.446234, (float)0.328157, (float)0.377594, (float)0.447084, (float)0.387753, (float)0.251591, (float)0.317194, (float)0.366085, (float)0.316589, (float)0.381759, (float)0.312835, (float)0.227367, (float)0.362716, (float)0.290218, (float)0.238076, (float)0.298752, (float)0.246872, (float)0.383969, (float)0.288621, (float)0.319681, (float)0.287939, (float)0.321752, (float)0.455860, (float)0.350026, (float)0.241983, (float)0.339564, (float)0.351888, (float)0.383881, (float)0.380568, (float)0.403935, (float)0.282568, (float)0.459434, (float)0.334185};	// L3883
  #pragma HLS resource variable=v3383 core=ram_t2p_bram

  float v3384[64] = {(float)0.048466, (float)0.103448, (float)0.066338, (float)0.045807, (float)0.114688, (float)0.053403, (float)0.065437, (float)0.046703, (float)0.044204, (float)0.081993, (float)0.033204, (float)0.040009, (float)0.037901, (float)0.084874, (float)0.040922, (float)0.028237, (float)0.082061, (float)0.069935, (float)0.032657, (float)0.049693, (float)0.050617, (float)0.105976, (float)0.092145, (float)0.030009, (float)0.016958, (float)0.038313, (float)0.035837, (float)0.038259, (float)0.074534, (float)0.057908, (float)0.038953, (float)0.050435, (float)0.049378, (float)0.061704, (float)0.045755, (float)0.034700, (float)0.052544, (float)0.057536, (float)0.047484, (float)0.035390, (float)0.065802, (float)0.033570, (float)0.043730, (float)0.073445, (float)0.057415, (float)0.059629, (float)0.045175, (float)0.040343, (float)0.078903, (float)0.055075, (float)0.032795, (float)0.077450, (float)0.072167, (float)0.039030, (float)0.050137, (float)0.039366, (float)0.045432, (float)0.045014, (float)0.089896, (float)0.029663, (float)0.052693, (float)0.018401, (float)0.052560, (float)0.033971};	// L3884
  #pragma HLS resource variable=v3384 core=ram_t2p_bram

  float v3385[64] = {(float)-0.055500, (float)-0.203719, (float)0.768174, (float)-0.065923, (float)0.474583, (float)-0.046248, (float)-0.089630, (float)0.040515, (float)-0.244641, (float)-0.307899, (float)0.241824, (float)-0.013522, (float)-0.013889, (float)-0.571560, (float)0.163069, (float)-0.123432, (float)-0.060682, (float)-0.068160, (float)0.032566, (float)0.024542, (float)-0.100840, (float)0.064618, (float)0.002764, (float)-0.010114, (float)-0.014506, (float)0.037742, (float)-0.084166, (float)0.018299, (float)-0.505570, (float)-0.052911, (float)-0.057266, (float)-0.121150, (float)-0.357840, (float)-0.247204, (float)-0.340336, (float)0.057016, (float)-0.251170, (float)-0.265774, (float)-0.121009, (float)-0.036924, (float)-0.099599, (float)0.283819, (float)0.147756, (float)-0.110480, (float)-0.459736, (float)-0.186662, (float)-0.285773, (float)0.123724, (float)-0.129131, (float)-0.238919, (float)0.020293, (float)0.108089, (float)-0.230991, (float)-0.084760, (float)-0.031626, (float)0.254551, (float)0.059674, (float)-0.172892, (float)-0.018973, (float)0.189760, (float)0.082253, (float)0.037962, (float)-0.042936, (float)0.139213};	// L3885
  #pragma HLS resource variable=v3385 core=ram_t2p_bram

  float v3386[64] = {(float)-0.177790, (float)-0.128705, (float)0.034879, (float)-0.145190, (float)0.186434, (float)-0.141275, (float)-0.420148, (float)-0.133402, (float)0.218276, (float)-0.191190, (float)0.031088, (float)-0.023462, (float)-0.172444, (float)-0.027425, (float)-0.029478, (float)-0.103149, (float)0.004718, (float)0.082794, (float)-0.152129, (float)0.018295, (float)-0.241826, (float)-0.083148, (float)-0.049059, (float)-0.068803, (float)-0.255967, (float)0.138053, (float)-0.016455, (float)0.209190, (float)-0.002823, (float)-0.026474, (float)-0.022462, (float)0.028627, (float)-0.106532, (float)-0.369825, (float)0.286155, (float)-0.103624, (float)0.308034, (float)-0.089430, (float)0.277215, (float)0.113614, (float)-0.315686, (float)0.042269, (float)0.056672, (float)0.236950, (float)-0.072728, (float)0.046475, (float)-0.053608, (float)0.130854, (float)0.028206, (float)-0.137072, (float)0.146362, (float)-0.071663, (float)-0.323746, (float)-0.158278, (float)-0.042404, (float)-0.127791, (float)-0.170256, (float)0.041290, (float)0.089118, (float)0.077040, (float)-0.072964, (float)0.068284, (float)-0.039060, (float)0.047603};	// L3886
  #pragma HLS resource variable=v3386 core=ram_t2p_bram

  float v3387[64] = {(float)0.255970, (float)0.568951, (float)0.404206, (float)0.512989, (float)0.217755, (float)0.494048, (float)0.331485, (float)0.551048, (float)0.435429, (float)0.529137, (float)0.208072, (float)0.473497, (float)0.594470, (float)0.564473, (float)0.276135, (float)0.257107, (float)0.485284, (float)0.624026, (float)0.436954, (float)0.230790, (float)0.497025, (float)0.315717, (float)0.570591, (float)0.216200, (float)0.193186, (float)0.144774, (float)0.221751, (float)0.238884, (float)0.587139, (float)0.350060, (float)0.410852, (float)0.319929, (float)0.580758, (float)0.328075, (float)0.272313, (float)0.197146, (float)0.613904, (float)0.407504, (float)0.630373, (float)0.387390, (float)0.760535, (float)0.211071, (float)0.307139, (float)0.460326, (float)0.309855, (float)0.191446, (float)0.443134, (float)0.253684, (float)0.574516, (float)0.645867, (float)0.391356, (float)0.308978, (float)0.678156, (float)0.193749, (float)0.581427, (float)0.256959, (float)0.351401, (float)0.212430, (float)0.579397, (float)0.341530, (float)0.205068, (float)0.071525, (float)0.408986, (float)0.441568};	// L3887
  #pragma HLS resource variable=v3387 core=ram_t2p_bram

  float v3388[128] = {(float)0.593310, (float)0.522483, (float)0.958677, (float)1.298441, (float)0.695402, (float)0.549521, (float)0.712340, (float)0.739628, (float)0.400142, (float)0.592862, (float)0.487997, (float)0.653224, (float)0.590060, (float)0.578593, (float)0.503144, (float)0.698397, (float)0.669882, (float)0.361280, (float)0.625812, (float)0.522611, (float)0.630567, (float)0.690843, (float)0.439007, (float)0.795547, (float)0.850360, (float)0.889134, (float)0.496305, (float)0.766487, (float)0.902729, (float)0.611070, (float)0.463242, (float)0.460936, (float)0.805312, (float)0.462128, (float)0.543827, (float)0.640072, (float)0.620282, (float)0.613264, (float)0.607044, (float)0.655792, (float)0.531518, (float)0.268372, (float)0.144623, (float)0.565144, (float)0.778362, (float)0.697679, (float)0.437897, (float)0.624566, (float)0.774904, (float)0.730056, (float)0.509908, (float)0.629786, (float)0.560832, (float)0.779375, (float)0.685117, (float)0.625684, (float)1.032232, (float)0.742745, (float)0.932032, (float)0.365862, (float)0.749193, (float)0.531596, (float)0.642129, (float)1.224698, (float)0.655463, (float)0.780651, (float)0.712956, (float)0.572756, (float)0.484813, (float)0.618051, (float)0.642812, (float)0.503305, (float)0.604441, (float)0.686455, (float)0.646250, (float)0.618148, (float)0.587760, (float)0.670910, (float)0.821051, (float)0.581310, (float)0.661186, (float)0.600928, (float)0.699439, (float)0.548678, (float)0.352786, (float)0.486316, (float)0.788625, (float)0.611432, (float)0.385830, (float)0.669801, (float)0.450744, (float)0.775131, (float)0.501571, (float)0.592511, (float)1.119311, (float)0.703092, (float)0.584707, (float)0.439465, (float)0.634338, (float)0.548005, (float)0.662297, (float)0.709441, (float)0.590768, (float)0.871853, (float)1.121974, (float)0.703923, (float)0.628972, (float)0.496351, (float)0.713743, (float)0.673382, (float)0.428245, (float)0.712878, (float)0.594225, (float)0.796172, (float)0.630016, (float)0.988299, (float)0.634330, (float)0.772596, (float)0.698150, (float)0.692563, (float)0.669203, (float)0.720668, (float)0.451586, (float)0.680505, (float)0.526193, (float)0.474407, (float)0.713929, (float)0.614371};	// L3888
  #pragma HLS resource variable=v3388 core=ram_t2p_bram

  float v3389[128] = {(float)0.150200, (float)0.300916, (float)-0.147537, (float)-0.120987, (float)-0.570131, (float)-0.752484, (float)0.023193, (float)-0.119149, (float)-0.520287, (float)-0.034415, (float)0.152679, (float)-0.800944, (float)-0.213324, (float)-0.195601, (float)-0.450303, (float)-0.263243, (float)0.083857, (float)-1.361400, (float)0.351981, (float)0.043538, (float)-0.512436, (float)-0.448886, (float)0.367435, (float)-0.786505, (float)-0.006069, (float)-0.550220, (float)-0.262887, (float)-0.069671, (float)-0.389200, (float)0.859612, (float)-0.026084, (float)0.019395, (float)-1.482228, (float)0.207719, (float)0.074051, (float)-0.537047, (float)0.634842, (float)0.006638, (float)-0.615627, (float)-0.637323, (float)-0.264894, (float)0.302085, (float)-0.614048, (float)-0.862524, (float)-1.168787, (float)-0.269116, (float)-0.756879, (float)-0.710371, (float)-0.560104, (float)-0.380309, (float)-0.642373, (float)-0.565310, (float)-0.394290, (float)-0.853161, (float)-0.881654, (float)-0.544433, (float)-0.236447, (float)-0.257178, (float)-0.013056, (float)-1.125633, (float)0.237203, (float)-0.226454, (float)-0.168215, (float)-0.745038, (float)-0.863955, (float)0.211796, (float)0.191799, (float)0.505848, (float)0.075484, (float)-0.697482, (float)-0.751843, (float)0.579945, (float)-0.293336, (float)-0.007108, (float)-0.625584, (float)-0.261605, (float)-0.673278, (float)-1.137500, (float)0.119250, (float)-0.498732, (float)-0.646061, (float)-0.057618, (float)0.036118, (float)0.002640, (float)-1.188415, (float)0.290132, (float)-0.797850, (float)-0.288818, (float)0.710557, (float)-0.671836, (float)-0.391351, (float)0.372045, (float)-0.492660, (float)-0.523825, (float)-0.016232, (float)-0.507445, (float)-0.326729, (float)-1.231871, (float)-0.192739, (float)-0.127261, (float)0.323021, (float)-0.015556, (float)-0.131741, (float)-0.609888, (float)-0.017879, (float)-0.300286, (float)-0.124729, (float)0.145174, (float)-0.493696, (float)-0.485238, (float)-0.335667, (float)-0.326114, (float)-0.377579, (float)-0.369098, (float)-0.645815, (float)-0.332252, (float)-0.042399, (float)-0.255116, (float)-0.655701, (float)-0.291660, (float)0.534487, (float)-0.428588, (float)0.158519, (float)-0.354673, (float)-0.126226, (float)-1.052125, (float)-0.249047, (float)-0.291654};	// L3889
  #pragma HLS resource variable=v3389 core=ram_t2p_bram

  float v3390[128] = {(float)-0.058919, (float)-0.168562, (float)-0.020559, (float)0.002724, (float)-0.095516, (float)-0.104846, (float)0.034862, (float)-0.088465, (float)-0.205294, (float)-0.176443, (float)-0.122366, (float)-0.036381, (float)-0.078540, (float)0.208818, (float)-0.040302, (float)-0.182007, (float)-0.107612, (float)0.298905, (float)-0.056967, (float)0.206444, (float)-0.092137, (float)-0.137563, (float)-0.130374, (float)-0.119292, (float)-0.100569, (float)-0.038038, (float)-0.110811, (float)-0.047660, (float)-0.108695, (float)0.158133, (float)-0.112305, (float)-0.158445, (float)0.097579, (float)-0.043000, (float)-0.134921, (float)-0.118917, (float)-0.098579, (float)-0.047895, (float)-0.083688, (float)-0.072037, (float)-0.083597, (float)-0.244234, (float)-0.337563, (float)-0.212384, (float)-0.069257, (float)-0.065093, (float)0.497870, (float)-0.081146, (float)-0.102116, (float)-0.078765, (float)-0.180223, (float)-0.101133, (float)-0.109032, (float)-0.061716, (float)-0.085599, (float)-0.049520, (float)-0.036976, (float)0.002258, (float)-0.050784, (float)-0.242987, (float)0.000918, (float)-0.152533, (float)-0.096342, (float)-0.051610, (float)-0.047299, (float)0.088366, (float)-0.102754, (float)-0.090700, (float)-0.108634, (float)-0.037853, (float)-0.103024, (float)-0.160907, (float)-0.090269, (float)-0.089757, (float)-0.128227, (float)-0.083011, (float)-0.018634, (float)-0.023180, (float)-0.004535, (float)-0.213116, (float)-0.143089, (float)-0.139070, (float)-0.130341, (float)-0.056792, (float)-0.186188, (float)-0.120910, (float)-0.033967, (float)-0.118150, (float)0.229818, (float)-0.208474, (float)-0.133540, (float)0.141824, (float)-0.089086, (float)-0.127267, (float)0.010721, (float)-0.102923, (float)-0.102543, (float)0.156240, (float)-0.093673, (float)-0.065726, (float)-0.124505, (float)-0.045139, (float)-0.070736, (float)-0.044729, (float)0.071477, (float)-0.048389, (float)-0.031163, (float)-0.043704, (float)-0.092708, (float)-0.146466, (float)-0.115128, (float)-0.018331, (float)-0.192681, (float)0.249057, (float)0.029965, (float)-0.130989, (float)-0.046823, (float)-0.085139, (float)-0.042109, (float)-0.041294, (float)-0.045703, (float)-0.143300, (float)-0.098112, (float)-0.104567, (float)-0.131521, (float)-0.124859, (float)-0.098192, (float)-0.096066};	// L3890
  #pragma HLS resource variable=v3390 core=ram_t2p_bram

  float v3391[128] = {(float)0.324834, (float)0.361286, (float)0.296001, (float)0.291272, (float)0.340724, (float)0.343486, (float)0.304928, (float)0.330825, (float)0.344703, (float)0.386029, (float)0.319625, (float)0.262200, (float)0.299442, (float)0.218919, (float)0.239658, (float)0.374363, (float)0.355502, (float)0.194782, (float)0.334943, (float)0.215932, (float)0.334950, (float)0.345426, (float)0.309408, (float)0.376880, (float)0.354555, (float)0.326677, (float)0.317772, (float)0.327223, (float)0.383199, (float)0.258517, (float)0.297278, (float)0.348103, (float)0.282671, (float)0.299546, (float)0.345139, (float)0.347087, (float)0.344019, (float)0.334352, (float)0.321053, (float)0.318047, (float)0.293964, (float)0.335297, (float)0.325333, (float)0.373341, (float)0.319777, (float)0.298675, (float)0.162031, (float)0.326202, (float)0.327120, (float)0.340962, (float)0.369312, (float)0.332041, (float)0.335704, (float)0.295134, (float)0.311533, (float)0.318515, (float)0.313850, (float)0.263277, (float)0.308895, (float)0.360143, (float)0.273400, (float)0.343340, (float)0.333502, (float)0.328786, (float)0.270554, (float)0.287885, (float)0.331762, (float)0.330961, (float)0.317023, (float)0.297651, (float)0.329960, (float)0.321629, (float)0.320513, (float)0.323057, (float)0.348127, (float)0.313005, (float)0.282608, (float)0.285637, (float)0.327924, (float)0.366598, (float)0.328828, (float)0.357500, (float)0.337720, (float)0.290390, (float)0.327274, (float)0.321442, (float)0.333242, (float)0.345229, (float)0.184188, (float)0.391577, (float)0.333745, (float)0.232547, (float)0.328524, (float)0.335796, (float)0.288527, (float)0.314884, (float)0.328837, (float)0.223603, (float)0.315898, (float)0.299266, (float)0.340252, (float)0.321951, (float)0.317072, (float)0.295022, (float)0.284672, (float)0.322377, (float)0.311865, (float)0.261327, (float)0.337353, (float)0.333315, (float)0.333005, (float)0.295903, (float)0.408659, (float)0.219163, (float)0.298173, (float)0.400610, (float)0.308063, (float)0.317075, (float)0.286153, (float)0.295179, (float)0.306962, (float)0.358301, (float)0.323218, (float)0.334503, (float)0.345349, (float)0.304311, (float)0.332711, (float)0.333740};	// L3891
  #pragma HLS resource variable=v3391 core=ram_t2p_bram

  float v3392[128] = {(float)0.048081, (float)0.057063, (float)0.061899, (float)0.031855, (float)0.089576, (float)0.053762, (float)0.060583, (float)0.102586, (float)0.044504, (float)0.104475, (float)0.047660, (float)0.075112, (float)0.031222, (float)0.050009, (float)0.045284, (float)0.051051, (float)0.084579, (float)0.079215, (float)0.199471, (float)0.059025, (float)0.055521, (float)0.087712, (float)0.054514, (float)0.082450, (float)0.051070, (float)0.104590, (float)0.060172, (float)0.046650, (float)0.057548, (float)0.066726, (float)0.097311, (float)0.092991, (float)0.060063, (float)0.070214, (float)0.069294, (float)0.034683, (float)0.105912, (float)0.040416, (float)0.044948, (float)0.240390, (float)0.199556, (float)0.184995, (float)0.033682, (float)0.049144, (float)0.032698, (float)0.097604, (float)0.039781, (float)0.099897, (float)0.087856, (float)0.075277, (float)0.036786, (float)0.063870, (float)0.115870, (float)0.048717, (float)0.128205, (float)0.061422, (float)0.054136, (float)0.033325, (float)0.090838, (float)0.072602, (float)0.048982, (float)0.075107, (float)0.064598, (float)0.069368, (float)0.144685, (float)0.111054, (float)0.186836, (float)0.064836, (float)0.063890, (float)0.053752, (float)0.063663, (float)0.058872, (float)0.064292, (float)0.106626, (float)0.136297, (float)0.084543, (float)0.067032, (float)0.100692, (float)0.036063, (float)0.074072, (float)0.043717, (float)0.077617, (float)0.072114, (float)0.068459, (float)0.061152, (float)0.060784, (float)0.068841, (float)0.106674, (float)0.060960, (float)0.079729, (float)0.038548, (float)0.057476, (float)0.051169, (float)0.067163, (float)0.022885, (float)0.089759, (float)0.072918, (float)0.044839, (float)0.037924, (float)0.243955, (float)0.076868, (float)0.087841, (float)0.052205, (float)0.054060, (float)0.022537, (float)0.074135, (float)0.130297, (float)0.057613, (float)0.083563, (float)0.049879, (float)0.052438, (float)0.163570, (float)0.087086, (float)0.057702, (float)0.049753, (float)0.111324, (float)0.067851, (float)0.068260, (float)0.046537, (float)0.050457, (float)0.179244, (float)0.084195, (float)0.041398, (float)0.097146, (float)0.046994, (float)0.057527, (float)0.049032, (float)0.045477};	// L3892
  #pragma HLS resource variable=v3392 core=ram_t2p_bram

  float v3393[128] = {(float)-0.453216, (float)-0.152422, (float)-0.377120, (float)-0.071292, (float)-0.287784, (float)-0.153411, (float)-0.544283, (float)-0.187820, (float)-0.295625, (float)-0.036512, (float)-0.033632, (float)-0.147503, (float)0.006782, (float)-0.137726, (float)-0.141708, (float)-0.370328, (float)-0.464431, (float)-0.124823, (float)0.476732, (float)0.038502, (float)-0.325714, (float)-0.153851, (float)-0.318125, (float)-0.103727, (float)0.063922, (float)-0.206649, (float)-0.160771, (float)0.055680, (float)0.125203, (float)-0.381157, (float)-0.230118, (float)-0.125565, (float)-0.284221, (float)-0.094927, (float)-0.362862, (float)-0.101347, (float)0.317283, (float)-0.126387, (float)-0.166025, (float)-0.144379, (float)-0.947483, (float)-1.099162, (float)-0.012528, (float)-0.068993, (float)0.149744, (float)-0.328442, (float)0.088629, (float)-0.346599, (float)-0.263027, (float)-0.158299, (float)-0.309201, (float)-0.036766, (float)-0.016934, (float)-0.343533, (float)-0.374221, (float)-0.248840, (float)-0.107837, (float)-0.306945, (float)-0.101044, (float)0.165530, (float)-0.420061, (float)-0.270237, (float)-0.134241, (float)-0.049494, (float)-0.464282, (float)-0.227078, (float)-0.453005, (float)-0.036464, (float)-0.453056, (float)-0.048457, (float)0.040308, (float)-0.079835, (float)-0.088525, (float)-0.139873, (float)-0.525539, (float)0.025445, (float)-0.121041, (float)-0.268475, (float)-0.144709, (float)-0.111433, (float)-0.578161, (float)-0.344528, (float)-0.009802, (float)-0.850283, (float)-0.038048, (float)-0.244956, (float)-0.070458, (float)-0.116732, (float)-0.194630, (float)-0.376894, (float)-0.509102, (float)0.235545, (float)-0.179103, (float)-0.246469, (float)-0.203475, (float)-0.355957, (float)0.010045, (float)-0.206067, (float)-0.040713, (float)-0.623080, (float)-0.043063, (float)-0.287439, (float)-0.362729, (float)-0.148554, (float)-0.027103, (float)-0.371420, (float)0.131329, (float)-0.182683, (float)-0.229369, (float)-0.066050, (float)-0.043142, (float)-0.959691, (float)0.084918, (float)-0.085548, (float)-0.328571, (float)-0.955873, (float)-0.164016, (float)-0.074490, (float)0.103987, (float)-0.380771, (float)-0.466441, (float)0.082288, (float)-0.214799, (float)-0.336690, (float)-0.077530, (float)-0.167701, (float)-0.066847, (float)-0.101599};	// L3893
  #pragma HLS resource variable=v3393 core=ram_t2p_bram

  float v3394[128] = {(float)0.024560, (float)0.059340, (float)0.134748, (float)-0.108948, (float)-0.046953, (float)-0.135904, (float)-0.054964, (float)0.050946, (float)-0.061328, (float)0.091555, (float)0.003117, (float)-0.027439, (float)-0.053891, (float)0.017680, (float)0.043196, (float)0.007427, (float)0.054773, (float)-0.032124, (float)-0.022354, (float)0.014151, (float)-0.215038, (float)-0.115954, (float)0.048597, (float)-0.114138, (float)0.106568, (float)0.035475, (float)0.013958, (float)0.017726, (float)0.078118, (float)0.133057, (float)0.013866, (float)0.044721, (float)0.106299, (float)0.052816, (float)-0.053854, (float)-0.115995, (float)0.105490, (float)-0.159093, (float)0.009957, (float)0.119660, (float)0.017048, (float)0.092924, (float)-0.067453, (float)0.098745, (float)0.103357, (float)0.050093, (float)0.029731, (float)0.028066, (float)-0.007469, (float)-0.057654, (float)-0.014447, (float)-0.164012, (float)0.125463, (float)0.081694, (float)0.063531, (float)0.093611, (float)0.021275, (float)0.048635, (float)-0.117394, (float)0.023740, (float)-0.217731, (float)0.009857, (float)-0.188289, (float)0.046725, (float)-0.082868, (float)0.058492, (float)-0.030578, (float)0.050947, (float)0.054060, (float)-0.167106, (float)0.011538, (float)-0.030242, (float)-0.139324, (float)0.011474, (float)0.042843, (float)0.118872, (float)-0.128894, (float)0.047884, (float)0.047402, (float)-0.062519, (float)0.000927, (float)-0.014440, (float)0.090924, (float)0.134192, (float)-0.033815, (float)0.056014, (float)0.084818, (float)-0.046690, (float)0.022831, (float)-0.009708, (float)0.136016, (float)-0.262473, (float)0.008751, (float)-0.055258, (float)0.038344, (float)-0.072012, (float)0.090656, (float)0.161242, (float)-0.107569, (float)0.101078, (float)-0.051920, (float)0.083777, (float)-0.070380, (float)-0.080635, (float)-0.024310, (float)0.053303, (float)0.127705, (float)0.140336, (float)-0.059300, (float)-0.063885, (float)-0.076590, (float)-0.116262, (float)0.066147, (float)-0.164424, (float)0.042161, (float)-0.278612, (float)-0.100634, (float)-0.069588, (float)-0.076140, (float)0.037116, (float)-0.024699, (float)0.091587, (float)-0.019960, (float)-0.017605, (float)0.029791, (float)-0.037279, (float)0.046599, (float)-0.137054};	// L3894
  #pragma HLS resource variable=v3394 core=ram_t2p_bram

  float v3395[128] = {(float)0.145360, (float)0.327034, (float)0.311272, (float)0.253844, (float)0.408611, (float)0.393735, (float)0.440020, (float)0.310809, (float)0.340602, (float)0.216793, (float)0.217005, (float)0.385689, (float)0.197057, (float)0.269211, (float)0.166347, (float)0.245394, (float)0.323222, (float)0.368608, (float)0.389336, (float)0.326424, (float)0.387510, (float)0.470665, (float)0.195832, (float)0.471701, (float)0.167291, (float)0.393835, (float)0.304437, (float)0.192885, (float)0.217518, (float)0.211891, (float)0.422997, (float)0.368287, (float)0.245454, (float)0.222887, (float)0.337012, (float)0.322865, (float)0.268833, (float)0.355672, (float)0.258055, (float)0.403077, (float)0.449247, (float)0.364234, (float)0.259931, (float)0.188145, (float)0.135859, (float)0.295791, (float)0.191273, (float)0.306459, (float)0.398054, (float)0.410152, (float)0.187375, (float)0.451574, (float)0.334031, (float)0.162764, (float)0.359933, (float)0.162416, (float)0.288619, (float)0.135804, (float)0.449146, (float)0.269389, (float)0.482328, (float)0.339347, (float)0.476410, (float)0.315497, (float)0.600514, (float)0.465356, (float)0.526438, (float)0.299068, (float)0.299173, (float)0.462067, (float)0.261355, (float)0.424686, (float)0.466248, (float)0.424928, (float)0.334506, (float)0.265505, (float)0.404762, (float)0.360481, (float)0.178225, (float)0.383255, (float)0.282325, (float)0.384305, (float)0.330699, (float)0.215093, (float)0.331719, (float)0.145785, (float)0.277083, (float)0.491718, (float)0.319917, (float)0.422169, (float)0.155856, (float)0.488359, (float)0.326664, (float)0.343999, (float)0.160794, (float)0.485517, (float)0.267712, (float)0.161554, (float)0.322052, (float)0.424293, (float)0.366113, (float)0.189262, (float)0.339991, (float)0.364810, (float)0.177854, (float)0.354371, (float)0.285221, (float)0.243696, (float)0.447201, (float)0.301112, (float)0.399651, (float)0.617299, (float)0.279388, (float)0.486732, (float)0.150205, (float)0.602134, (float)0.360387, (float)0.469642, (float)0.371103, (float)0.238830, (float)0.534697, (float)0.150882, (float)0.321347, (float)0.439417, (float)0.322947, (float)0.432900, (float)0.148859, (float)0.370201};	// L3895
  #pragma HLS resource variable=v3395 core=ram_t2p_bram

  float v3396[128] = {(float)0.195075, (float)0.015126, (float)0.024686, (float)0.069140, (float)0.066477, (float)0.038569, (float)0.029205, (float)0.187348, (float)0.047591, (float)0.085917, (float)0.106478, (float)0.091648, (float)0.123286, (float)0.059453, (float)0.122047, (float)0.087753, (float)0.062034, (float)0.083518, (float)0.119766, (float)0.026393, (float)0.141712, (float)0.015137, (float)0.080786, (float)0.022324, (float)0.122655, (float)0.009270, (float)0.109414, (float)0.105676, (float)0.119017, (float)0.148300, (float)0.076409, (float)0.018531, (float)0.064178, (float)0.211846, (float)0.124331, (float)0.055484, (float)0.042722, (float)0.055615, (float)0.112607, (float)0.095887, (float)0.094294, (float)0.113487, (float)0.066087, (float)0.070395, (float)0.122939, (float)0.140619, (float)0.085870, (float)0.067176, (float)0.013766, (float)0.105736, (float)0.111352, (float)0.058925, (float)0.026861, (float)0.096942, (float)0.048945, (float)0.128996, (float)0.076791, (float)0.093506, (float)0.021500, (float)0.129628, (float)0.012155, (float)0.059132, (float)0.058341, (float)0.021649, (float)0.013461, (float)0.010597, (float)0.034173, (float)0.019851, (float)0.056583, (float)0.016790, (float)0.064006, (float)0.053730, (float)0.032178, (float)0.031792, (float)0.058448, (float)0.036133, (float)0.015466, (float)0.015941, (float)0.094866, (float)0.096540, (float)0.092703, (float)0.033148, (float)0.024034, (float)0.112144, (float)0.069260, (float)0.217726, (float)0.025089, (float)0.064994, (float)0.034509, (float)0.035683, (float)0.153443, (float)0.056833, (float)0.036974, (float)0.044199, (float)0.075228, (float)0.041296, (float)0.025106, (float)0.058206, (float)0.037025, (float)0.119014, (float)0.099326, (float)0.264434, (float)0.053664, (float)0.049540, (float)0.112233, (float)0.063765, (float)0.030242, (float)0.037588, (float)0.018721, (float)0.063380, (float)0.030748, (float)0.037784, (float)0.179270, (float)0.023952, (float)0.201506, (float)0.033747, (float)0.144427, (float)0.036813, (float)0.016456, (float)0.070980, (float)0.013318, (float)0.263823, (float)0.028834, (float)0.005705, (float)0.046202, (float)0.029074, (float)0.119795, (float)0.045042};	// L3896
  #pragma HLS resource variable=v3396 core=ram_t2p_bram

  float v3397[128] = {(float)-0.211283, (float)0.135911, (float)0.003872, (float)0.088622, (float)-0.054593, (float)-0.271570, (float)0.252057, (float)-0.203466, (float)0.030309, (float)-0.146448, (float)-0.263998, (float)-0.443631, (float)-0.381481, (float)-0.146328, (float)0.057290, (float)-0.211984, (float)-0.066480, (float)0.243781, (float)0.083157, (float)0.003994, (float)-0.213596, (float)-0.175505, (float)-0.720057, (float)-0.223341, (float)0.104656, (float)0.146672, (float)-0.316539, (float)-0.200965, (float)0.256891, (float)-0.814085, (float)-0.086720, (float)-0.087481, (float)-0.979392, (float)-0.219662, (float)-0.056762, (float)-0.384841, (float)0.257944, (float)0.173454, (float)-0.052807, (float)0.327628, (float)-0.438050, (float)0.189461, (float)-0.131566, (float)-0.310094, (float)-0.286190, (float)-0.016661, (float)-0.221619, (float)-0.193017, (float)0.045372, (float)-0.304901, (float)0.186341, (float)-0.546061, (float)0.046079, (float)0.189910, (float)-0.035324, (float)-0.241548, (float)0.081305, (float)0.478797, (float)0.051930, (float)0.043841, (float)0.137906, (float)-0.403564, (float)-0.123150, (float)0.055124, (float)-0.066305, (float)0.169912, (float)-0.309545, (float)-0.108016, (float)-0.143140, (float)0.233852, (float)-0.289316, (float)0.351272, (float)0.189279, (float)-0.078873, (float)-0.588245, (float)-0.136508, (float)-0.291918, (float)0.286934, (float)0.308479, (float)-0.109600, (float)0.390506, (float)-0.262971, (float)-0.214997, (float)-0.196612, (float)-0.257918, (float)-0.090391, (float)0.050640, (float)-0.027527, (float)0.406672, (float)0.096961, (float)-0.397573, (float)0.217634, (float)0.258483, (float)0.107776, (float)-0.260712, (float)-0.112592, (float)-0.200102, (float)-0.439961, (float)-0.118115, (float)0.216810, (float)-0.129016, (float)-0.143399, (float)0.249810, (float)-0.281125, (float)-0.276826, (float)-0.520892, (float)0.178535, (float)0.116071, (float)-0.180557, (float)-0.144778, (float)-0.070399, (float)-0.359138, (float)-0.458136, (float)-0.111657, (float)-0.191608, (float)0.726131, (float)-0.238154, (float)0.012629, (float)0.074889, (float)-0.009665, (float)0.047987, (float)0.993994, (float)0.063368, (float)0.062898, (float)-0.795395, (float)-0.161197, (float)1.303984, (float)-0.287946};	// L3897
  #pragma HLS resource variable=v3397 core=ram_t2p_bram

  float v3398[128] = {(float)0.333437, (float)0.058141, (float)0.071451, (float)0.344152, (float)0.175646, (float)0.150940, (float)0.156753, (float)0.309979, (float)0.192735, (float)0.151586, (float)0.304443, (float)0.223826, (float)0.370650, (float)0.173883, (float)0.305100, (float)0.261006, (float)0.157454, (float)0.201529, (float)0.293294, (float)0.100969, (float)0.587052, (float)0.067581, (float)0.249943, (float)0.092899, (float)0.244333, (float)0.049473, (float)0.244866, (float)0.275016, (float)0.307121, (float)0.302456, (float)0.181769, (float)0.068811, (float)0.222305, (float)0.376576, (float)0.466122, (float)0.328428, (float)0.103522, (float)0.339995, (float)0.232495, (float)0.151386, (float)0.175311, (float)0.226932, (float)0.260599, (float)0.183070, (float)0.289391, (float)0.258995, (float)0.220830, (float)0.139903, (float)0.064348, (float)0.283322, (float)0.345072, (float)0.201662, (float)0.069578, (float)0.272249, (float)0.112749, (float)0.291654, (float)0.235779, (float)0.270338, (float)0.091056, (float)0.259050, (float)0.130156, (float)0.226135, (float)0.196738, (float)0.053907, (float)0.069651, (float)0.052445, (float)0.105012, (float)0.086111, (float)0.117261, (float)0.095746, (float)0.186192, (float)0.164236, (float)0.133584, (float)0.106451, (float)0.131232, (float)0.088791, (float)0.079264, (float)0.047525, (float)0.304888, (float)0.232467, (float)0.290756, (float)0.129200, (float)0.077844, (float)0.226314, (float)0.237911, (float)0.340521, (float)0.091429, (float)0.193598, (float)0.122301, (float)0.139977, (float)0.295250, (float)0.236044, (float)0.168133, (float)0.133842, (float)0.266574, (float)0.149506, (float)0.076098, (float)0.167363, (float)0.178391, (float)0.171979, (float)0.231797, (float)0.375289, (float)0.210302, (float)0.192155, (float)0.400192, (float)0.171847, (float)0.059252, (float)0.074192, (float)0.068560, (float)0.193075, (float)0.138588, (float)0.111138, (float)0.305451, (float)0.120503, (float)0.344339, (float)0.163305, (float)0.367280, (float)0.153379, (float)0.074206, (float)0.208761, (float)0.039418, (float)0.259399, (float)0.138467, (float)-0.005076, (float)0.190468, (float)0.127526, (float)0.307100, (float)0.168179};	// L3898
  #pragma HLS resource variable=v3398 core=ram_t2p_bram

  float v3399[128] = {(float)0.265984, (float)0.142226, (float)0.240406, (float)0.429715, (float)0.130597, (float)0.333568, (float)0.193908, (float)0.159962, (float)0.216622, (float)0.406987, (float)0.102928, (float)0.344171, (float)0.202139, (float)0.158985, (float)0.222596, (float)0.184193, (float)0.273120, (float)0.226213, (float)0.217797, (float)0.153600, (float)0.172152, (float)0.203482, (float)0.339101, (float)0.157192, (float)0.227613, (float)0.273962, (float)0.154285, (float)0.130658, (float)0.164928, (float)0.257095, (float)0.143062, (float)0.234942, (float)0.176451, (float)0.117135, (float)0.340118, (float)0.165663, (float)0.130661, (float)0.316855, (float)0.197333, (float)0.150357, (float)0.318104, (float)0.252881, (float)0.298031, (float)0.246102, (float)0.285730, (float)0.281353, (float)0.188892, (float)0.112508, (float)0.207923, (float)0.213070, (float)0.215777, (float)0.337231, (float)0.279137, (float)0.285221, (float)0.510197, (float)0.180843, (float)0.253995, (float)0.387584, (float)0.204832, (float)0.171647, (float)0.277470, (float)0.238497, (float)0.199155, (float)0.332500, (float)0.183191, (float)0.124644, (float)0.185207, (float)0.208308, (float)0.317851, (float)0.307654, (float)0.184214, (float)0.184476, (float)0.168399, (float)0.244728, (float)0.299013, (float)0.241209, (float)0.337016, (float)0.197437, (float)0.167910, (float)0.245905, (float)0.166989, (float)0.176372, (float)0.225831, (float)0.374315, (float)0.146398, (float)0.170609, (float)0.292521, (float)0.259431, (float)0.212312, (float)0.219105, (float)0.228057, (float)0.180866, (float)0.127798, (float)0.257516, (float)0.338658, (float)0.175510, (float)0.308295, (float)0.139915, (float)0.219728, (float)0.159400, (float)0.131078, (float)0.224978, (float)0.342173, (float)0.239100, (float)0.123958, (float)0.206810, (float)0.278398, (float)0.179967, (float)0.313302, (float)0.116730, (float)0.306559, (float)0.100834, (float)0.172883, (float)0.304478, (float)0.218748, (float)0.286205, (float)0.236073, (float)0.156040, (float)0.127094, (float)0.246670, (float)0.220105, (float)0.142332, (float)0.153068, (float)0.299454, (float)0.206944, (float)0.212649, (float)0.136926, (float)0.156573};	// L3899
  #pragma HLS resource variable=v3399 core=ram_t2p_bram

  float v3400[128] = {(float)-0.359329, (float)-0.477234, (float)0.232878, (float)-0.713911, (float)-0.671253, (float)-0.555205, (float)-0.455632, (float)-0.650177, (float)-0.208170, (float)-0.401110, (float)-0.394219, (float)-0.296979, (float)-0.162634, (float)-0.437940, (float)-0.333381, (float)-0.616314, (float)-0.298241, (float)-0.519042, (float)0.167560, (float)-0.183182, (float)-0.207992, (float)-0.529586, (float)-0.424530, (float)-0.175528, (float)-0.855614, (float)-0.306702, (float)-0.456019, (float)-0.164220, (float)-0.505888, (float)-0.452942, (float)-0.453194, (float)-0.725371, (float)0.603657, (float)-0.250895, (float)-0.019907, (float)-0.467233, (float)-0.590104, (float)-0.419542, (float)-0.327237, (float)0.565780, (float)-0.343822, (float)-0.599216, (float)-0.268328, (float)-0.459065, (float)-0.346020, (float)-0.166886, (float)-0.327144, (float)0.035087, (float)-0.417475, (float)-0.398392, (float)-0.411848, (float)-0.361882, (float)-0.131267, (float)-0.275814, (float)-0.719622, (float)-0.540127, (float)-1.173857, (float)-0.049651, (float)-0.135809, (float)-0.613852, (float)-0.514309, (float)-0.301727, (float)-0.046470, (float)-0.397720, (float)-0.025143, (float)0.382112, (float)-0.507901, (float)-0.279453, (float)-0.190372, (float)0.399343, (float)-0.441783, (float)-0.181321, (float)-0.612221, (float)-0.313241, (float)-0.065635, (float)-0.445764, (float)0.089382, (float)-0.375939, (float)0.043963, (float)-0.397213, (float)-0.286045, (float)0.087717, (float)-0.082471, (float)-0.762022, (float)-0.026026, (float)-0.386070, (float)-0.112798, (float)-0.412884, (float)-0.288291, (float)1.105405, (float)-0.389190, (float)-0.039337, (float)-0.139370, (float)-0.167832, (float)0.182516, (float)-0.437861, (float)-0.252168, (float)-0.111858, (float)-0.509824, (float)-0.032774, (float)-0.287390, (float)-0.380895, (float)-0.192937, (float)-0.335496, (float)-0.386343, (float)-0.161692, (float)-0.228914, (float)0.166474, (float)-0.687425, (float)-0.170472, (float)-0.521633, (float)-0.331493, (float)-0.667820, (float)0.534173, (float)0.143320, (float)-0.555769, (float)-0.427653, (float)-0.323982, (float)-0.214243, (float)0.021606, (float)-0.437899, (float)-0.848646, (float)-0.767517, (float)-0.451166, (float)0.278764, (float)-0.969427, (float)-1.169143, (float)0.019830};	// L3900
  #pragma HLS resource variable=v3400 core=ram_t2p_bram

  float v3401[128] = {(float)-0.173491, (float)-0.233710, (float)-0.338329, (float)-0.080570, (float)-0.192011, (float)-0.062054, (float)-0.188519, (float)-0.283036, (float)-0.168034, (float)-0.179567, (float)-0.264540, (float)-0.198254, (float)-0.118316, (float)-0.243189, (float)-0.170644, (float)-0.308978, (float)-0.266079, (float)-0.403989, (float)-0.194935, (float)-0.139227, (float)-0.244917, (float)-0.124167, (float)-0.201219, (float)-0.190123, (float)-0.101361, (float)-0.346804, (float)-0.224452, (float)-0.327163, (float)-0.305659, (float)-0.328909, (float)-0.153208, (float)-0.196746, (float)-0.066690, (float)-0.328066, (float)-0.141847, (float)-0.152700, (float)-0.098708, (float)-0.324310, (float)-0.225153, (float)-0.346165, (float)-0.228392, (float)-0.226256, (float)-0.180956, (float)-0.156392, (float)-0.172998, (float)-0.150661, (float)-0.291292, (float)-0.164308, (float)-0.199820, (float)-0.153210, (float)-0.221071, (float)-0.224671, (float)-0.091338, (float)-0.156250, (float)-0.245263, (float)-0.485364, (float)-0.442787, (float)-0.102146, (float)-0.161508, (float)-0.212533, (float)-0.223903, (float)-0.195173, (float)-0.044655, (float)-0.173257, (float)-0.117751, (float)-0.477455, (float)-0.211025, (float)-0.230468, (float)-0.179492, (float)-0.158220, (float)-0.200780, (float)-0.204053, (float)-0.197439, (float)-0.274988, (float)-0.039521, (float)-0.216061, (float)-0.278604, (float)-0.262572, (float)-0.099668, (float)-0.295324, (float)-0.143103, (float)-0.144757, (float)-0.189352, (float)-0.128346, (float)-0.180698, (float)-0.114418, (float)-0.130784, (float)-0.415391, (float)-0.232355, (float)-0.137638, (float)-0.115441, (float)-0.209871, (float)-0.096623, (float)-0.166871, (float)-0.383489, (float)-0.254503, (float)-0.160312, (float)-0.190372, (float)-0.241955, (float)-0.165757, (float)-0.113350, (float)-0.149788, (float)-0.121281, (float)-0.231825, (float)-0.201705, (float)-0.382692, (float)-0.149086, (float)-0.117410, (float)-0.126119, (float)-0.203114, (float)-0.183187, (float)-0.227419, (float)-0.128094, (float)-0.255662, (float)-0.140035, (float)-0.072347, (float)-0.221194, (float)-0.148563, (float)-0.291366, (float)-0.111600, (float)-0.219389, (float)-0.489799, (float)-0.369349, (float)-0.143669, (float)-0.123228, (float)-0.372334, (float)-0.679388, (float)-0.153556};	// L3901
  #pragma HLS resource variable=v3401 core=ram_t2p_bram

  float v3402[128] = {(float)0.332279, (float)0.290789, (float)0.324604, (float)0.343499, (float)0.301133, (float)0.305367, (float)0.304133, (float)0.353912, (float)0.286192, (float)0.360089, (float)0.297030, (float)0.338131, (float)0.256527, (float)0.327597, (float)0.303041, (float)0.408485, (float)0.351930, (float)0.421810, (float)0.305489, (float)0.255109, (float)0.342549, (float)0.321531, (float)0.336599, (float)0.270019, (float)0.284925, (float)0.395363, (float)0.316580, (float)0.328618, (float)0.351512, (float)0.395284, (float)0.276768, (float)0.362486, (float)0.198786, (float)0.271687, (float)0.335525, (float)0.279714, (float)0.250960, (float)0.383155, (float)0.326616, (float)0.326292, (float)0.368095, (float)0.340069, (float)0.365079, (float)0.339102, (float)0.307109, (float)0.323148, (float)0.369146, (float)0.241042, (float)0.353627, (float)0.318859, (float)0.323815, (float)0.361054, (float)0.308593, (float)0.330886, (float)0.388617, (float)0.436192, (float)0.454995, (float)0.296215, (float)0.307095, (float)0.338550, (float)0.331689, (float)0.322825, (float)0.239334, (float)0.314733, (float)0.273822, (float)0.321808, (float)0.319823, (float)0.341149, (float)0.361058, (float)0.283285, (float)0.303515, (float)0.318290, (float)0.314626, (float)0.389027, (float)0.260684, (float)0.347912, (float)0.323576, (float)0.370897, (float)0.259174, (float)0.374153, (float)0.255528, (float)0.296578, (float)0.350519, (float)0.316516, (float)0.280768, (float)0.266033, (float)0.281745, (float)0.479532, (float)0.337221, (float)0.272313, (float)0.295520, (float)0.322453, (float)0.247034, (float)0.316046, (float)0.351453, (float)0.313138, (float)0.337206, (float)0.283730, (float)0.354032, (float)0.289689, (float)0.249013, (float)0.301909, (float)0.311431, (float)0.351002, (float)0.302211, (float)0.361745, (float)0.285898, (float)0.283114, (float)0.324345, (float)0.276870, (float)0.331425, (float)0.239431, (float)0.293249, (float)0.278819, (float)0.268619, (float)0.319401, (float)0.354174, (float)0.268255, (float)0.295470, (float)0.292432, (float)0.353813, (float)0.425614, (float)0.360298, (float)0.301261, (float)0.276316, (float)0.435417, (float)0.399058, (float)0.269375};	// L3902
  #pragma HLS resource variable=v3402 core=ram_t2p_bram

  float v3403[128] = {(float)0.018228, (float)0.021225, (float)0.028612, (float)0.020886, (float)0.029474, (float)0.047744, (float)0.035290, (float)0.028429, (float)0.028470, (float)0.045069, (float)0.029840, (float)0.019491, (float)0.017088, (float)0.029840, (float)0.028539, (float)0.028518, (float)0.020139, (float)0.022774, (float)0.032135, (float)0.033348, (float)0.017759, (float)0.047420, (float)0.030149, (float)0.041645, (float)0.037812, (float)0.046252, (float)0.029589, (float)0.016504, (float)0.026924, (float)0.030834, (float)0.036263, (float)0.045937, (float)0.031620, (float)0.026538, (float)0.022904, (float)0.058237, (float)0.056463, (float)0.040456, (float)0.026616, (float)0.032348, (float)0.033927, (float)0.084368, (float)0.024933, (float)0.017348, (float)0.022366, (float)0.021032, (float)0.019272, (float)0.015102, (float)0.056145, (float)0.039999, (float)0.018257, (float)0.040509, (float)0.032031, (float)0.022098, (float)0.033824, (float)0.022704, (float)0.025319, (float)0.018465, (float)0.068178, (float)0.026885, (float)0.072726, (float)0.021805, (float)0.049063, (float)0.026663, (float)0.023015, (float)0.013440, (float)0.047817, (float)0.058346, (float)0.033150, (float)0.047472, (float)0.018629, (float)0.033559, (float)0.045253, (float)0.031564, (float)0.036324, (float)0.034589, (float)0.047584, (float)0.032355, (float)0.017391, (float)0.035121, (float)0.018529, (float)0.053177, (float)0.013671, (float)0.030469, (float)0.037829, (float)0.016996, (float)0.041624, (float)0.031600, (float)0.032903, (float)0.016922, (float)0.032056, (float)0.043576, (float)0.035142, (float)0.024761, (float)0.016919, (float)0.038553, (float)0.036356, (float)0.017814, (float)0.062490, (float)0.040622, (float)0.025852, (float)0.022963, (float)0.027265, (float)0.029650, (float)0.020724, (float)0.044788, (float)0.057808, (float)0.020073, (float)0.039706, (float)0.058224, (float)0.043781, (float)0.036008, (float)0.026018, (float)0.035214, (float)0.019792, (float)0.032273, (float)0.049339, (float)0.016944, (float)0.062593, (float)0.029896, (float)0.025511, (float)0.015677, (float)0.036686, (float)0.015467, (float)0.031936, (float)0.028402, (float)0.028767, (float)0.044939};	// L3903
  #pragma HLS resource variable=v3403 core=ram_t2p_bram

  float v3404[128] = {(float)-0.030282, (float)0.032654, (float)0.024031, (float)-0.076254, (float)-0.158904, (float)-0.080364, (float)-0.179721, (float)-0.070087, (float)-0.157296, (float)0.113432, (float)-0.080524, (float)-0.023368, (float)-0.075576, (float)-0.183264, (float)0.038381, (float)0.079149, (float)-0.059366, (float)-0.021708, (float)0.028777, (float)-0.102287, (float)-0.069791, (float)-0.048403, (float)0.123386, (float)-0.124158, (float)0.058383, (float)-0.104519, (float)-0.008196, (float)-0.053568, (float)0.012729, (float)0.026888, (float)-0.178475, (float)-0.051413, (float)-0.050308, (float)0.017321, (float)0.016230, (float)-0.253243, (float)-0.281744, (float)-0.238800, (float)-0.064062, (float)0.013646, (float)0.139668, (float)-0.282715, (float)0.076684, (float)-0.032818, (float)-0.007989, (float)-0.005788, (float)-0.132186, (float)-0.026603, (float)-0.399491, (float)-0.082451, (float)-0.106088, (float)-0.055577, (float)-0.055737, (float)0.055247, (float)-0.125942, (float)-0.007705, (float)-0.101706, (float)-0.053206, (float)-0.157038, (float)0.067522, (float)-0.557878, (float)0.052287, (float)-0.110857, (float)0.009559, (float)0.010253, (float)-0.096847, (float)-0.009989, (float)-0.263148, (float)-0.101345, (float)-0.015615, (float)-0.054351, (float)-0.143559, (float)-0.074740, (float)-0.060869, (float)-0.071018, (float)-0.117134, (float)0.020510, (float)0.037233, (float)-0.016161, (float)-0.024520, (float)0.168410, (float)-0.286805, (float)0.055828, (float)0.040196, (float)-0.136006, (float)-0.052269, (float)-0.054720, (float)-0.110828, (float)-0.248952, (float)-0.025246, (float)0.078344, (float)-0.192699, (float)-0.142652, (float)-0.112169, (float)-0.059888, (float)-0.088440, (float)-0.019096, (float)0.001496, (float)-0.552184, (float)0.004240, (float)0.030461, (float)0.024223, (float)-0.124602, (float)-0.154293, (float)0.004527, (float)-0.180832, (float)-0.222397, (float)0.090906, (float)0.032938, (float)0.545644, (float)-0.022998, (float)0.062755, (float)0.046356, (float)-0.087351, (float)-0.029993, (float)0.110824, (float)-0.049152, (float)-0.033058, (float)-0.247085, (float)-0.035225, (float)0.051587, (float)0.070940, (float)-0.240892, (float)-0.065018, (float)-0.168374, (float)-0.056477, (float)-0.130560, (float)-0.062673};	// L3904
  #pragma HLS resource variable=v3404 core=ram_t2p_bram

  float v3405[128] = {(float)-0.140328, (float)-0.088945, (float)-0.414691, (float)-0.226405, (float)-0.073735, (float)-0.353450, (float)-0.337907, (float)-0.075212, (float)-0.179123, (float)0.044826, (float)-0.284193, (float)-0.176455, (float)-0.159067, (float)-0.067545, (float)-0.154270, (float)-0.106100, (float)-0.233439, (float)-0.098128, (float)-0.090774, (float)-0.056665, (float)-0.190828, (float)-0.205473, (float)-0.270418, (float)-0.188264, (float)-0.356957, (float)-0.112524, (float)-0.163161, (float)-0.021077, (float)-0.168745, (float)-0.212433, (float)-0.171320, (float)-0.087193, (float)-0.219359, (float)-0.188759, (float)-0.295415, (float)-0.457019, (float)-0.022601, (float)-0.052663, (float)0.040554, (float)-0.060934, (float)-0.045578, (float)-0.117637, (float)-0.014481, (float)0.031818, (float)-0.204581, (float)-0.095336, (float)-0.049646, (float)-0.105117, (float)-0.079309, (float)-0.193274, (float)-0.146744, (float)-0.321475, (float)-0.325699, (float)-0.228701, (float)-0.035580, (float)-0.186885, (float)-0.193175, (float)-0.077068, (float)0.276766, (float)-0.065632, (float)-0.089503, (float)-0.254808, (float)-0.236533, (float)0.002141, (float)-0.098652, (float)-0.317785, (float)0.161271, (float)0.000558, (float)-0.234711, (float)-0.414953, (float)-0.131037, (float)-0.314176, (float)-0.258199, (float)-0.539954, (float)0.077238, (float)-0.254571, (float)-0.445436, (float)-0.026179, (float)-0.093667, (float)-0.220115, (float)-0.204358, (float)-0.015544, (float)-0.089319, (float)-0.216655, (float)0.111158, (float)-0.061883, (float)-0.121699, (float)-0.159310, (float)-0.131706, (float)-0.171691, (float)-0.372923, (float)-0.335352, (float)-0.341418, (float)0.035783, (float)-0.206719, (float)-0.108735, (float)0.014148, (float)-0.033818, (float)-0.212884, (float)-0.112212, (float)-0.162665, (float)-0.199955, (float)0.090774, (float)-0.004113, (float)-0.131348, (float)-0.294189, (float)0.016028, (float)-0.106472, (float)-0.128883, (float)-0.169939, (float)-0.172128, (float)-0.180889, (float)-0.229467, (float)-0.361108, (float)-0.174603, (float)-0.353952, (float)-0.155432, (float)-0.270855, (float)-0.260711, (float)0.008433, (float)-0.031063, (float)-0.002231, (float)-0.083139, (float)0.038031, (float)-0.489251, (float)-0.274916, (float)0.124518, (float)-0.127154};	// L3905
  #pragma HLS resource variable=v3405 core=ram_t2p_bram

  float v3406[128] = {(float)0.119389, (float)0.162451, (float)0.308392, (float)0.293060, (float)0.295737, (float)0.526303, (float)0.403845, (float)0.202352, (float)0.340056, (float)0.198215, (float)0.255910, (float)0.231121, (float)0.163044, (float)0.289084, (float)0.224845, (float)0.231051, (float)0.241681, (float)0.218689, (float)0.192158, (float)0.310324, (float)0.201460, (float)0.480243, (float)0.248132, (float)0.389808, (float)0.320391, (float)0.403485, (float)0.261744, (float)0.155120, (float)0.225615, (float)0.211736, (float)0.270751, (float)0.353666, (float)0.250458, (float)0.184278, (float)0.246481, (float)0.650101, (float)0.389760, (float)0.428938, (float)0.179944, (float)0.160353, (float)0.177524, (float)0.359953, (float)0.269352, (float)0.128253, (float)0.166169, (float)0.171629, (float)0.183674, (float)0.171020, (float)0.417839, (float)0.324853, (float)0.175895, (float)0.471709, (float)0.411493, (float)0.199489, (float)0.202503, (float)0.149152, (float)0.286027, (float)0.107250, (float)0.364880, (float)0.190612, (float)0.536862, (float)0.240043, (float)0.441093, (float)0.170234, (float)0.199319, (float)0.204474, (float)0.197212, (float)0.404137, (float)0.303404, (float)0.616775, (float)0.228446, (float)0.322839, (float)0.454725, (float)0.436961, (float)0.157013, (float)0.405716, (float)0.579129, (float)0.233751, (float)0.158552, (float)0.313032, (float)0.220113, (float)0.319544, (float)0.116600, (float)0.251712, (float)0.218374, (float)0.098906, (float)0.311623, (float)0.261283, (float)0.327686, (float)0.177789, (float)0.271778, (float)0.417423, (float)0.513997, (float)0.213603, (float)0.190534, (float)0.289775, (float)0.247165, (float)0.134083, (float)0.621224, (float)0.181041, (float)0.239355, (float)0.141709, (float)0.175946, (float)0.282684, (float)0.198707, (float)0.377475, (float)0.374890, (float)0.127358, (float)0.365601, (float)0.430489, (float)0.421177, (float)0.267256, (float)0.201616, (float)0.509774, (float)0.144946, (float)0.440837, (float)0.358322, (float)0.250295, (float)0.568202, (float)0.251753, (float)0.139241, (float)0.061661, (float)0.340573, (float)0.131263, (float)0.458603, (float)0.291374, (float)0.132604, (float)0.391477};	// L3906
  #pragma HLS resource variable=v3406 core=ram_t2p_bram

  float v3407[256] = {(float)0.250864, (float)0.298932, (float)0.281011, (float)0.261564, (float)0.303803, (float)0.361369, (float)0.174898, (float)0.261464, (float)0.231546, (float)0.259326, (float)0.319929, (float)0.203902, (float)0.393703, (float)0.281866, (float)0.692774, (float)0.166908, (float)0.197141, (float)0.234712, (float)0.179814, (float)0.258408, (float)0.204510, (float)0.224671, (float)0.257510, (float)0.189613, (float)0.224339, (float)0.329013, (float)0.226237, (float)0.162855, (float)0.174987, (float)0.216183, (float)0.268586, (float)0.198980, (float)0.302773, (float)0.247399, (float)0.630018, (float)0.274692, (float)0.234032, (float)0.218395, (float)0.347572, (float)0.196595, (float)0.173869, (float)0.201052, (float)0.188224, (float)0.191662, (float)0.234873, (float)0.179596, (float)0.201768, (float)0.195002, (float)0.218602, (float)0.259526, (float)0.152205, (float)0.208831, (float)0.138049, (float)0.525828, (float)0.165894, (float)0.328321, (float)0.193083, (float)0.234705, (float)0.144876, (float)0.261347, (float)0.272002, (float)0.185486, (float)0.246871, (float)0.233705, (float)0.252473, (float)0.148685, (float)0.174042, (float)0.210088, (float)0.350658, (float)0.166817, (float)0.285117, (float)0.187431, (float)0.172494, (float)0.261913, (float)0.190267, (float)0.277414, (float)0.187483, (float)0.258448, (float)0.163465, (float)0.269258, (float)0.170919, (float)0.709311, (float)0.226438, (float)0.243884, (float)0.271709, (float)0.201970, (float)0.242027, (float)0.197879, (float)0.324886, (float)0.232497, (float)0.217436, (float)0.239979, (float)0.220082, (float)0.191406, (float)0.231140, (float)0.472309, (float)0.274862, (float)0.203280, (float)0.437263, (float)0.212425, (float)0.195578, (float)0.157026, (float)0.249678, (float)0.272318, (float)0.192829, (float)0.272554, (float)0.194160, (float)0.286151, (float)0.273076, (float)0.234804, (float)0.325900, (float)0.307940, (float)0.279887, (float)0.186518, (float)0.241578, (float)0.226162, (float)0.350172, (float)0.216920, (float)0.237095, (float)0.174961, (float)0.282227, (float)0.198301, (float)0.397905, (float)0.237978, (float)0.179769, (float)0.266089, (float)0.163974, (float)0.426010, (float)0.203198, (float)0.176351, (float)0.180248, (float)0.282140, (float)0.478301, (float)0.189528, (float)0.336067, (float)0.200891, (float)0.154111, (float)0.202102, (float)0.236516, (float)0.352982, (float)0.183315, (float)0.613094, (float)0.183968, (float)0.277182, (float)0.273462, (float)0.179923, (float)0.400513, (float)0.214398, (float)0.267736, (float)0.266503, (float)0.421295, (float)0.237306, (float)0.240770, (float)0.257516, (float)0.389262, (float)0.172283, (float)0.317349, (float)0.201366, (float)0.509833, (float)0.225395, (float)0.210268, (float)0.315547, (float)0.306514, (float)0.181416, (float)0.251151, (float)0.166545, (float)0.207832, (float)0.235228, (float)0.216052, (float)0.167390, (float)0.430228, (float)0.304516, (float)0.351816, (float)0.162007, (float)0.223414, (float)0.202807, (float)0.152331, (float)0.331499, (float)0.208631, (float)0.300535, (float)0.276002, (float)0.198756, (float)0.168350, (float)0.211100, (float)0.307697, (float)0.280259, (float)0.304477, (float)0.177278, (float)0.179699, (float)0.147033, (float)0.212199, (float)0.214709, (float)0.168834, (float)0.191250, (float)0.206656, (float)0.244358, (float)0.260919, (float)0.275039, (float)0.259668, (float)0.237292, (float)0.221625, (float)0.398130, (float)0.774624, (float)0.201475, (float)0.173361, (float)0.363690, (float)0.174825, (float)0.249547, (float)0.245724, (float)0.155897, (float)0.274097, (float)0.376527, (float)0.276687, (float)0.284072, (float)0.255299, (float)0.158174, (float)0.332825, (float)0.199572, (float)0.228403, (float)0.272024, (float)0.251950, (float)0.272385, (float)0.193060, (float)0.292428, (float)0.262938, (float)0.375961, (float)0.220595, (float)0.261611, (float)0.190731, (float)0.282084, (float)0.275237, (float)0.230336, (float)0.272964, (float)0.233962, (float)0.223458, (float)0.146601, (float)0.286886, (float)0.276269, (float)0.282303, (float)0.184287, (float)0.180444, (float)0.224428, (float)0.184037, (float)0.144650, (float)0.212632, (float)0.179212, (float)0.254628, (float)0.166118, (float)0.188118, (float)0.166739, (float)0.237100, (float)0.252300, (float)0.226000, (float)0.272757, (float)0.202812, (float)0.480202};	// L3907
  #pragma HLS resource variable=v3407 core=ram_t2p_bram

  float v3408[256] = {(float)-0.125285, (float)-0.226214, (float)-0.486030, (float)-0.145832, (float)-0.631118, (float)0.007284, (float)-0.059700, (float)0.003752, (float)-0.136321, (float)-0.221260, (float)-0.384376, (float)-0.578263, (float)-1.271543, (float)-0.454579, (float)-1.409158, (float)-0.486397, (float)0.288440, (float)-0.782657, (float)0.305954, (float)-0.354159, (float)-0.571101, (float)-0.799809, (float)0.088768, (float)-0.143884, (float)-0.686732, (float)-0.858843, (float)-0.544732, (float)0.298266, (float)-0.191937, (float)0.134417, (float)-0.638721, (float)-0.471627, (float)0.613940, (float)-0.006469, (float)0.009157, (float)-0.754339, (float)-0.366568, (float)-0.147949, (float)-0.726295, (float)-0.306396, (float)-0.300255, (float)-0.488007, (float)-0.368779, (float)-0.329479, (float)-0.146555, (float)-0.668113, (float)-0.121652, (float)-0.566083, (float)-0.754172, (float)-0.497712, (float)-0.198177, (float)-0.748014, (float)0.293547, (float)-0.503929, (float)-0.415239, (float)-0.184573, (float)-0.065346, (float)-0.361654, (float)0.097863, (float)-0.098897, (float)-0.874720, (float)-0.686600, (float)-0.285040, (float)-0.180705, (float)-0.756375, (float)0.489559, (float)-0.471906, (float)-0.325071, (float)0.236078, (float)-0.282303, (float)-0.545358, (float)-0.570296, (float)-0.391414, (float)-0.745949, (float)-0.312741, (float)0.498307, (float)-0.429021, (float)0.050147, (float)-0.146516, (float)-0.606047, (float)0.313227, (float)-0.374327, (float)-0.582572, (float)-0.384315, (float)-0.107641, (float)-0.565698, (float)-0.310177, (float)0.317944, (float)-0.778714, (float)-0.032611, (float)-0.472261, (float)-0.566884, (float)-0.014164, (float)-0.597379, (float)-0.317522, (float)-0.936114, (float)-0.183842, (float)0.132857, (float)-1.032077, (float)-0.059062, (float)-0.459894, (float)-0.509421, (float)0.207018, (float)-0.052015, (float)0.150766, (float)-0.861900, (float)-0.087798, (float)-0.813155, (float)-0.385866, (float)-0.229938, (float)-0.609966, (float)-0.224648, (float)-0.346424, (float)-0.951537, (float)0.085479, (float)0.310099, (float)-0.472149, (float)-0.415532, (float)0.007986, (float)-0.173154, (float)-0.650107, (float)-0.620344, (float)-0.137175, (float)-0.152218, (float)-0.286989, (float)-0.494054, (float)0.096648, (float)0.507254, (float)-0.251031, (float)-0.303242, (float)-0.314956, (float)-0.573268, (float)-0.054476, (float)-0.344083, (float)-0.764426, (float)-0.232119, (float)-0.773845, (float)-0.174531, (float)0.242331, (float)-0.335081, (float)-0.129590, (float)-0.512466, (float)-0.110073, (float)-0.876779, (float)-0.286019, (float)-0.355995, (float)-0.124355, (float)-0.299707, (float)-0.157739, (float)-0.316033, (float)-0.174813, (float)0.589301, (float)0.125172, (float)-0.280216, (float)-0.051413, (float)-0.660500, (float)-0.198867, (float)-0.106192, (float)-0.084415, (float)-0.672405, (float)-0.000834, (float)-0.260551, (float)-0.382815, (float)-0.167397, (float)-1.455198, (float)-0.445208, (float)-0.215850, (float)-0.587816, (float)-0.417873, (float)-0.621527, (float)0.173720, (float)-0.588677, (float)-0.572029, (float)0.074681, (float)-0.600545, (float)-0.346055, (float)-0.325968, (float)-0.357741, (float)-0.093304, (float)-0.358804, (float)-0.393470, (float)-0.955065, (float)-0.914292, (float)-0.276236, (float)-0.365220, (float)-0.170353, (float)-0.267629, (float)-0.229179, (float)-0.380049, (float)-0.492739, (float)-0.217846, (float)-0.361399, (float)-0.127377, (float)-0.520279, (float)-0.543694, (float)0.020979, (float)-0.635725, (float)-0.592680, (float)-0.161099, (float)-0.101500, (float)-0.406663, (float)-0.421175, (float)-0.267119, (float)-0.327238, (float)-0.499771, (float)0.010453, (float)-0.397699, (float)-0.461170, (float)-0.067067, (float)0.152801, (float)-0.192739, (float)-0.401757, (float)-0.581724, (float)-0.338345, (float)-0.507856, (float)-0.606219, (float)-0.209398, (float)0.034390, (float)0.004939, (float)-0.007406, (float)-0.843081, (float)-0.882384, (float)-0.354944, (float)-0.209500, (float)-0.493705, (float)-0.290731, (float)-0.441446, (float)-0.489615, (float)0.083633, (float)-0.977952, (float)-0.472126, (float)-0.147393, (float)-0.318508, (float)-0.243628, (float)-0.179690, (float)-0.042850, (float)-0.297155, (float)-0.429911, (float)-0.312470, (float)-0.369892, (float)-0.489870, (float)-0.097868, (float)-0.780393, (float)-0.392426, (float)0.084980, (float)-0.503046, (float)-0.675454, (float)-0.250641, (float)-0.435426, (float)-0.244056, (float)0.019346, (float)-0.344223, (float)-0.675849, (float)-0.448382, (float)-0.162842, (float)-0.680128};	// L3908
  #pragma HLS resource variable=v3408 core=ram_t2p_bram

  float v3409[256] = {(float)-0.091541, (float)0.018898, (float)-0.123456, (float)-0.061327, (float)-0.100263, (float)-0.130591, (float)-0.147267, (float)-0.107884, (float)-0.243784, (float)-0.111251, (float)0.136086, (float)-0.147696, (float)0.038740, (float)-0.090681, (float)0.035250, (float)-0.185141, (float)-0.131863, (float)-0.174566, (float)-0.081508, (float)-0.100397, (float)-0.339357, (float)-0.171201, (float)-0.080694, (float)-0.122756, (float)-0.226348, (float)-0.150313, (float)-0.231352, (float)-0.232732, (float)-0.085389, (float)-0.080152, (float)-0.071633, (float)-0.083903, (float)-0.059168, (float)0.035758, (float)-0.032176, (float)-0.219693, (float)0.002686, (float)-0.147120, (float)-0.026404, (float)-0.188586, (float)-0.241665, (float)-0.149379, (float)-0.190439, (float)-0.108913, (float)-0.265685, (float)-0.136225, (float)-0.048705, (float)-0.134040, (float)-0.092953, (float)-0.006406, (float)-0.172137, (float)-0.147599, (float)-0.171439, (float)0.033604, (float)-0.101091, (float)-0.176112, (float)-0.118361, (float)-0.048236, (float)-0.325970, (float)-0.155533, (float)-0.016897, (float)-0.237285, (float)-0.101522, (float)-0.105098, (float)-0.273812, (float)-0.191719, (float)-0.050346, (float)-0.109822, (float)0.148440, (float)-0.228247, (float)-0.069973, (float)-0.142682, (float)-0.141699, (float)-0.309599, (float)-0.204279, (float)0.026869, (float)-0.077861, (float)-0.084224, (float)-0.046442, (float)-0.142941, (float)-0.391699, (float)0.025708, (float)-0.177874, (float)-0.099331, (float)-0.050711, (float)-0.222194, (float)-0.095079, (float)-0.086135, (float)-0.074276, (float)-0.166584, (float)-0.205380, (float)-0.178156, (float)-0.115048, (float)-0.252517, (float)-0.069416, (float)-0.053633, (float)-0.049875, (float)-0.031105, (float)0.121213, (float)-0.098814, (float)-0.157045, (float)-0.309300, (float)-0.079659, (float)-0.099416, (float)-0.177447, (float)-0.050523, (float)0.076561, (float)-0.047986, (float)-0.127789, (float)-0.065052, (float)-0.173716, (float)0.030266, (float)-0.133399, (float)-0.243512, (float)-0.074562, (float)-0.036471, (float)-0.184350, (float)-0.088707, (float)-0.192414, (float)-0.111002, (float)-0.145788, (float)-0.089511, (float)-0.095593, (float)-0.204198, (float)-0.133813, (float)-0.063686, (float)-0.069926, (float)-0.165650, (float)-0.152099, (float)-0.131711, (float)-0.082572, (float)-0.247043, (float)-0.117428, (float)-0.147476, (float)-0.084031, (float)-0.068137, (float)-0.178943, (float)0.028840, (float)-0.036173, (float)-0.300523, (float)-0.144107, (float)-0.081247, (float)-0.049173, (float)-0.065680, (float)-0.124873, (float)-0.110424, (float)0.018734, (float)-0.135130, (float)-0.194434, (float)-0.090873, (float)0.206699, (float)-0.108119, (float)-0.249868, (float)-0.099919, (float)0.050711, (float)-0.189901, (float)-0.036945, (float)-0.143244, (float)0.127873, (float)-0.178175, (float)-0.117233, (float)-0.009903, (float)0.078477, (float)-0.068088, (float)-0.036492, (float)-0.159562, (float)-0.160586, (float)-0.092235, (float)-0.177350, (float)-0.178807, (float)0.030627, (float)-0.110060, (float)-0.135469, (float)-0.224402, (float)-0.085992, (float)-0.123241, (float)-0.092661, (float)-0.166617, (float)-0.139341, (float)-0.089812, (float)-0.061381, (float)-0.173992, (float)-0.250278, (float)-0.059253, (float)-0.127184, (float)-0.142201, (float)-0.074251, (float)-0.220762, (float)-0.220682, (float)-0.274205, (float)-0.130161, (float)-0.091641, (float)-0.169643, (float)-0.248070, (float)-0.152374, (float)0.041031, (float)-0.107683, (float)0.040801, (float)-0.191516, (float)-0.069653, (float)-0.104922, (float)-0.011046, (float)-0.325680, (float)-0.133634, (float)-0.102107, (float)0.012819, (float)-0.271689, (float)-0.124546, (float)0.028783, (float)-0.102536, (float)-0.240512, (float)-0.147584, (float)0.100827, (float)-0.021987, (float)-0.098267, (float)-0.441696, (float)-0.077403, (float)-0.320662, (float)-0.027250, (float)-0.072613, (float)-0.060763, (float)-0.043001, (float)-0.087174, (float)-0.128030, (float)-0.160845, (float)-0.152924, (float)-0.174502, (float)-0.170176, (float)-0.048594, (float)-0.145877, (float)-0.055220, (float)-0.080786, (float)-0.026370, (float)-0.095169, (float)-0.112555, (float)-0.045169, (float)-0.083661, (float)-0.033070, (float)0.012683, (float)-0.086466, (float)-0.144631, (float)-0.073167, (float)-0.215994, (float)-0.095242, (float)-0.129684, (float)-0.200768, (float)-0.213469, (float)-0.220437, (float)-0.238096, (float)-0.178692, (float)-0.138572, (float)-0.190089, (float)-0.098096, (float)-0.085015, (float)-0.076103, (float)-0.058645};	// L3909
  #pragma HLS resource variable=v3409 core=ram_t2p_bram

  float v3410[256] = {(float)0.285559, (float)0.242513, (float)0.303185, (float)0.316843, (float)0.301112, (float)0.347454, (float)0.307561, (float)0.310476, (float)0.364599, (float)0.325492, (float)0.219472, (float)0.316731, (float)0.267433, (float)0.310377, (float)0.302567, (float)0.344343, (float)0.291547, (float)0.337878, (float)0.288732, (float)0.299638, (float)0.358818, (float)0.316421, (float)0.288209, (float)0.291741, (float)0.349248, (float)0.374901, (float)0.358705, (float)0.316626, (float)0.275555, (float)0.297773, (float)0.336378, (float)0.289266, (float)0.310645, (float)0.250589, (float)0.346038, (float)0.362116, (float)0.257021, (float)0.369536, (float)0.293526, (float)0.328555, (float)0.324343, (float)0.318817, (float)0.309339, (float)0.331369, (float)0.354980, (float)0.297806, (float)0.273727, (float)0.302276, (float)0.317948, (float)0.283143, (float)0.306462, (float)0.338974, (float)0.305294, (float)0.309905, (float)0.301651, (float)0.347185, (float)0.303356, (float)0.293453, (float)0.335237, (float)0.367627, (float)0.316286, (float)0.340372, (float)0.307773, (float)0.281928, (float)0.379397, (float)0.308284, (float)0.277796, (float)0.336334, (float)0.228444, (float)0.325858, (float)0.279001, (float)0.307226, (float)0.297520, (float)0.384725, (float)0.337204, (float)0.225265, (float)0.282748, (float)0.373716, (float)0.279589, (float)0.348498, (float)0.387878, (float)0.328783, (float)0.334035, (float)0.333461, (float)0.275599, (float)0.350031, (float)0.289668, (float)0.279846, (float)0.290734, (float)0.321974, (float)0.382362, (float)0.352245, (float)0.327819, (float)0.368933, (float)0.314718, (float)0.360019, (float)0.312293, (float)0.251859, (float)0.235510, (float)0.321113, (float)0.320316, (float)0.334461, (float)0.276752, (float)0.334053, (float)0.315254, (float)0.317547, (float)0.222378, (float)0.295571, (float)0.320610, (float)0.265781, (float)0.366241, (float)0.271525, (float)0.365474, (float)0.342714, (float)0.281972, (float)0.275396, (float)0.466927, (float)0.309017, (float)0.346771, (float)0.314426, (float)0.321970, (float)0.276543, (float)0.330110, (float)0.321858, (float)0.315216, (float)0.281280, (float)0.249709, (float)0.351405, (float)0.326416, (float)0.301382, (float)0.273426, (float)0.352193, (float)0.383082, (float)0.302775, (float)0.294032, (float)0.282470, (float)0.309919, (float)0.237338, (float)0.270537, (float)0.418871, (float)0.298495, (float)0.384072, (float)0.275390, (float)0.309113, (float)0.316944, (float)0.282377, (float)0.274919, (float)0.349322, (float)0.401850, (float)0.310825, (float)0.217624, (float)0.282134, (float)0.319884, (float)0.335810, (float)0.246835, (float)0.333235, (float)0.287557, (float)0.296442, (float)0.238542, (float)0.345085, (float)0.308119, (float)0.276033, (float)0.253318, (float)0.257576, (float)0.309189, (float)0.294967, (float)0.308874, (float)0.311262, (float)0.347532, (float)0.317155, (float)0.247428, (float)0.337070, (float)0.345042, (float)0.318918, (float)0.314958, (float)0.300786, (float)0.269426, (float)0.373029, (float)0.323512, (float)0.298830, (float)0.281176, (float)0.324457, (float)0.363002, (float)0.284270, (float)0.353284, (float)0.345131, (float)0.324354, (float)0.352450, (float)0.311796, (float)0.342882, (float)0.321482, (float)0.274752, (float)0.328727, (float)0.365552, (float)0.290056, (float)0.252260, (float)0.328359, (float)0.252313, (float)0.342566, (float)0.285146, (float)0.291776, (float)0.249690, (float)0.515868, (float)0.302605, (float)0.274273, (float)0.237944, (float)0.352385, (float)0.339384, (float)0.226397, (float)0.265234, (float)0.375858, (float)0.377673, (float)0.245921, (float)0.304622, (float)0.306692, (float)0.377470, (float)0.297616, (float)0.355231, (float)0.269597, (float)0.264911, (float)0.287163, (float)0.298522, (float)0.286704, (float)0.367557, (float)0.349431, (float)0.382281, (float)0.324598, (float)0.356710, (float)0.266202, (float)0.335733, (float)0.293518, (float)0.298707, (float)0.266426, (float)0.301895, (float)0.317489, (float)0.243584, (float)0.327437, (float)0.276378, (float)0.246619, (float)0.287555, (float)0.305970, (float)0.315744, (float)0.332885, (float)0.298386, (float)0.296086, (float)0.330902, (float)0.372892, (float)0.323777, (float)0.349068, (float)0.334237, (float)0.303659, (float)0.357816, (float)0.284855, (float)0.282661, (float)0.280880, (float)0.324879};	// L3910
  #pragma HLS resource variable=v3410 core=ram_t2p_bram

  float v3411[256] = {(float)0.107920, (float)0.113119, (float)0.092402, (float)0.071782, (float)0.097940, (float)0.161556, (float)0.067759, (float)0.095264, (float)0.156841, (float)0.148867, (float)0.148639, (float)0.118751, (float)0.103737, (float)0.327870, (float)0.074858, (float)0.097990, (float)0.084549, (float)0.063650, (float)0.081342, (float)0.100630, (float)0.073185, (float)0.064171, (float)0.193288, (float)0.082385, (float)0.059233, (float)0.148861, (float)0.073801, (float)0.089610, (float)0.255869, (float)0.151682, (float)0.068495, (float)0.104463, (float)0.116415, (float)0.118472, (float)0.089943, (float)0.102400, (float)0.069438, (float)0.161354, (float)0.085833, (float)0.078180, (float)0.062971, (float)0.131437, (float)0.108712, (float)0.101784, (float)0.070927, (float)0.097307, (float)0.063811, (float)0.079515, (float)0.091107, (float)0.077233, (float)0.080560, (float)0.098582, (float)0.130434, (float)0.164583, (float)0.100621, (float)0.123261, (float)0.070296, (float)0.103307, (float)0.129595, (float)0.237423, (float)0.090776, (float)0.129562, (float)0.067803, (float)0.133029, (float)0.206679, (float)0.085977, (float)0.120746, (float)0.157335, (float)0.165559, (float)0.077627, (float)0.166565, (float)0.188749, (float)0.116823, (float)0.114407, (float)0.046436, (float)0.113001, (float)0.056545, (float)0.065159, (float)0.103074, (float)0.109842, (float)0.076094, (float)0.101361, (float)0.062740, (float)0.062418, (float)0.098488, (float)0.131857, (float)0.063869, (float)0.088104, (float)0.064605, (float)0.198904, (float)0.201842, (float)0.068886, (float)0.062178, (float)0.123867, (float)0.100861, (float)0.193545, (float)0.075647, (float)0.175286, (float)0.142215, (float)0.152461, (float)0.073533, (float)0.103727, (float)0.077450, (float)0.073334, (float)0.134000, (float)0.067998, (float)0.186661, (float)0.064853, (float)0.088539, (float)0.127883, (float)0.196692, (float)0.116001, (float)0.161062, (float)0.078586, (float)0.069576, (float)0.104028, (float)0.139981, (float)0.095898, (float)0.099353, (float)0.063146, (float)0.044682, (float)0.159987, (float)0.062740, (float)0.100733, (float)0.231643, (float)0.107364, (float)0.069490, (float)0.052605, (float)0.117870, (float)0.221723, (float)0.078380, (float)0.096814, (float)0.090653, (float)0.067003, (float)0.075803, (float)0.082118, (float)0.157966, (float)0.111124, (float)0.092853, (float)0.087567, (float)0.096227, (float)0.058785, (float)0.075936, (float)0.093882, (float)0.077693, (float)0.119861, (float)0.067781, (float)0.143152, (float)0.087430, (float)0.066882, (float)0.088135, (float)0.101346, (float)0.130327, (float)0.087776, (float)0.113767, (float)0.080938, (float)0.094607, (float)0.094033, (float)0.146219, (float)0.161455, (float)0.084281, (float)0.120982, (float)0.092326, (float)0.044513, (float)0.096573, (float)0.102368, (float)0.063741, (float)0.070668, (float)0.074185, (float)0.139571, (float)0.049915, (float)0.117890, (float)0.068812, (float)0.048670, (float)0.087817, (float)0.086432, (float)0.079138, (float)0.172189, (float)0.099577, (float)0.125177, (float)0.055568, (float)0.076120, (float)0.072859, (float)0.120526, (float)0.054969, (float)0.108001, (float)0.132347, (float)0.227916, (float)0.052727, (float)0.067079, (float)0.095510, (float)0.112687, (float)0.129030, (float)0.087197, (float)0.092644, (float)0.079046, (float)0.058910, (float)0.132045, (float)0.060425, (float)0.070423, (float)0.090503, (float)0.054910, (float)0.162270, (float)0.062874, (float)0.067185, (float)0.064026, (float)0.080040, (float)0.127539, (float)0.131902, (float)0.074259, (float)0.138094, (float)0.065906, (float)0.132874, (float)0.196173, (float)0.073843, (float)0.141605, (float)0.163910, (float)0.096622, (float)0.099170, (float)0.078575, (float)0.076646, (float)0.090674, (float)0.075964, (float)0.100050, (float)0.135052, (float)0.060326, (float)0.060349, (float)0.076702, (float)0.067060, (float)0.133114, (float)0.119993, (float)0.077948, (float)0.083209, (float)0.061850, (float)0.120612, (float)0.098630, (float)0.074216, (float)0.096020, (float)0.067579, (float)0.090194, (float)0.119490, (float)0.041490, (float)0.092642, (float)0.119073, (float)0.105536, (float)0.133169, (float)0.086161, (float)0.086509, (float)0.064966, (float)0.079783, (float)0.066094, (float)0.101048, (float)0.103775, (float)0.100503, (float)0.094500, (float)0.061120};	// L3911
  #pragma HLS resource variable=v3411 core=ram_t2p_bram

  float v3412[256] = {(float)-0.189777, (float)-0.482186, (float)-0.008805, (float)0.006411, (float)-0.340083, (float)-0.104136, (float)-0.162624, (float)-0.225853, (float)-0.111947, (float)-0.325409, (float)-0.025436, (float)-0.235121, (float)-0.079023, (float)-0.330589, (float)-0.095579, (float)-0.041512, (float)-0.320712, (float)-0.003675, (float)-0.182978, (float)-0.129528, (float)-0.206938, (float)-0.263178, (float)-0.135148, (float)-0.129547, (float)-0.252728, (float)-0.010400, (float)-0.087520, (float)-0.337514, (float)-0.500123, (float)-0.119882, (float)-0.198902, (float)-0.296375, (float)-0.192366, (float)-0.290422, (float)-0.009084, (float)-0.010365, (float)0.073766, (float)-0.176034, (float)0.044212, (float)-0.223174, (float)0.037583, (float)-0.123472, (float)-0.006477, (float)-0.252415, (float)-0.012039, (float)0.055478, (float)0.153278, (float)-0.142060, (float)-0.116012, (float)-0.089306, (float)-0.154690, (float)-0.161466, (float)0.020772, (float)-0.349643, (float)-0.147741, (float)-0.615463, (float)-0.136424, (float)-0.040550, (float)-0.324642, (float)-0.169717, (float)0.169392, (float)-0.066222, (float)-0.207621, (float)-0.396942, (float)-0.293588, (float)0.107962, (float)-0.279773, (float)-0.085886, (float)-0.071285, (float)-0.351994, (float)-0.064169, (float)-0.199326, (float)0.020171, (float)-0.380757, (float)-0.083251, (float)-0.132135, (float)-0.300852, (float)-0.179991, (float)0.082419, (float)-0.053208, (float)0.153810, (float)0.177749, (float)0.183670, (float)-0.197191, (float)-0.008271, (float)-0.213453, (float)-0.388144, (float)-0.168575, (float)-0.114889, (float)0.205505, (float)-0.205391, (float)-0.134499, (float)-0.157910, (float)-0.180125, (float)-0.213260, (float)-0.294034, (float)-0.208740, (float)-0.041945, (float)-0.215760, (float)-0.045287, (float)-0.293506, (float)-0.157409, (float)0.031047, (float)0.015392, (float)-0.101318, (float)0.040111, (float)-0.407119, (float)-0.285228, (float)-0.295356, (float)-0.226055, (float)-0.108272, (float)0.135866, (float)-0.618958, (float)-0.195708, (float)-0.201768, (float)-0.018107, (float)-0.315698, (float)-0.097366, (float)-0.218778, (float)0.010469, (float)-0.068638, (float)-0.293657, (float)-0.316823, (float)-0.174534, (float)0.028630, (float)-0.172140, (float)-0.204302, (float)-0.211421, (float)-0.203194, (float)-0.216986, (float)0.045944, (float)0.211036, (float)-0.100892, (float)-0.056037, (float)0.150099, (float)-0.171299, (float)0.017118, (float)-0.202913, (float)-0.217480, (float)0.083633, (float)-0.021473, (float)-0.342348, (float)-0.144981, (float)0.163231, (float)-0.167945, (float)-0.167225, (float)-0.163446, (float)-0.361114, (float)-0.066378, (float)-0.301459, (float)-0.119178, (float)0.019238, (float)-0.141982, (float)-0.285228, (float)-0.303883, (float)-0.089706, (float)-0.065887, (float)-0.024002, (float)-0.221210, (float)0.030599, (float)-0.008324, (float)-0.377250, (float)-0.258354, (float)0.002954, (float)-0.098139, (float)-0.260227, (float)-0.121153, (float)-0.209369, (float)-0.139802, (float)-0.179488, (float)-0.146744, (float)0.010215, (float)-0.139606, (float)-0.273151, (float)-0.142677, (float)-0.113589, (float)-0.166838, (float)-0.334615, (float)-0.310770, (float)-0.046880, (float)-0.073305, (float)-0.382769, (float)-0.108244, (float)-0.085387, (float)-0.156431, (float)-0.170715, (float)-0.139600, (float)0.037278, (float)0.278705, (float)-0.241466, (float)-0.119594, (float)-0.145318, (float)-0.264213, (float)-0.101207, (float)0.047012, (float)-0.113262, (float)0.159313, (float)-0.056641, (float)-0.186790, (float)-0.236183, (float)0.092192, (float)0.165713, (float)0.156039, (float)-0.199838, (float)-0.193852, (float)0.115413, (float)0.053682, (float)-0.219226, (float)-0.099676, (float)-0.233159, (float)-0.149759, (float)0.031655, (float)0.079305, (float)-0.217689, (float)-0.265366, (float)-0.227793, (float)-0.041873, (float)0.014206, (float)-0.211142, (float)-0.022370, (float)0.095297, (float)-0.162817, (float)0.098129, (float)-0.122034, (float)-0.035969, (float)-0.388423, (float)0.114713, (float)0.006867, (float)-0.282127, (float)-0.605982, (float)-0.224330, (float)0.017712, (float)-0.073646, (float)-0.137202, (float)-0.043635, (float)0.161579, (float)-0.190647, (float)-0.277439, (float)0.113585, (float)0.189117, (float)0.061008, (float)0.016080, (float)-0.104557, (float)-0.082977, (float)0.007892, (float)-0.096327, (float)-0.195615, (float)-0.144547, (float)-0.159137, (float)0.061161, (float)-0.255179, (float)0.008187, (float)0.197982, (float)-0.228035, (float)-0.116328, (float)-0.164370};	// L3912
  #pragma HLS resource variable=v3412 core=ram_t2p_bram

  float v3413[256] = {(float)-0.026385, (float)0.099545, (float)-0.006836, (float)-0.087678, (float)0.007832, (float)0.040653, (float)-0.030738, (float)0.005956, (float)0.001694, (float)0.047769, (float)0.063004, (float)0.035760, (float)-0.050405, (float)0.021372, (float)-0.009033, (float)-0.033702, (float)-0.045529, (float)-0.192383, (float)-0.067608, (float)0.077464, (float)-0.033957, (float)-0.079947, (float)0.131379, (float)-0.127304, (float)-0.062825, (float)-0.005497, (float)-0.091520, (float)-0.175702, (float)-0.008296, (float)-0.094468, (float)0.002491, (float)-0.031894, (float)-0.015755, (float)0.143725, (float)-0.003477, (float)0.010756, (float)-0.051074, (float)0.035848, (float)0.087819, (float)-0.045240, (float)-0.045785, (float)0.014690, (float)0.068685, (float)0.016806, (float)-0.047715, (float)0.056814, (float)0.045985, (float)-0.050668, (float)0.005891, (float)-0.103352, (float)0.010281, (float)-0.105204, (float)-0.016557, (float)-0.019213, (float)-0.034522, (float)0.020138, (float)-0.136205, (float)0.039602, (float)-0.008828, (float)-0.010837, (float)-0.029803, (float)0.072119, (float)-0.066893, (float)-0.009429, (float)-0.030956, (float)-0.026700, (float)-0.141836, (float)0.119003, (float)0.066929, (float)-0.213746, (float)0.042720, (float)0.047782, (float)0.033905, (float)0.000139, (float)-0.148223, (float)-0.023684, (float)-0.074337, (float)-0.068427, (float)-0.020076, (float)0.014697, (float)-0.039620, (float)0.019393, (float)-0.069640, (float)-0.055779, (float)0.007966, (float)0.023639, (float)-0.257815, (float)0.006356, (float)-0.100405, (float)0.028047, (float)0.015223, (float)-0.048413, (float)-0.153553, (float)0.104931, (float)0.049892, (float)0.065689, (float)-0.054139, (float)0.007726, (float)0.094090, (float)-0.019978, (float)-0.235610, (float)-0.062284, (float)0.033363, (float)0.110169, (float)0.076999, (float)-0.032478, (float)0.048089, (float)-0.149947, (float)-0.165030, (float)0.123038, (float)0.071157, (float)0.058895, (float)-0.048155, (float)-0.097220, (float)-0.186036, (float)0.085326, (float)-0.051602, (float)-0.307986, (float)-0.060410, (float)-0.077131, (float)-0.272820, (float)0.028950, (float)-0.132805, (float)0.017264, (float)-0.039184, (float)0.054153, (float)-0.037219, (float)-0.152829, (float)-0.176634, (float)0.083937, (float)0.069329, (float)-0.082645, (float)0.111784, (float)-0.050772, (float)-0.044772, (float)-0.037455, (float)0.030361, (float)-0.378243, (float)0.014857, (float)0.006824, (float)-0.052090, (float)-0.295015, (float)0.089860, (float)0.029646, (float)0.019930, (float)-0.083483, (float)-0.096416, (float)-0.023830, (float)0.034911, (float)-0.266257, (float)-0.161844, (float)0.073552, (float)0.027568, (float)-0.110867, (float)-0.010322, (float)-0.097499, (float)0.013995, (float)0.010802, (float)0.078444, (float)0.013057, (float)-0.039476, (float)0.024805, (float)-0.077445, (float)-0.028419, (float)0.010412, (float)-0.042330, (float)-0.166340, (float)-0.094908, (float)-0.034328, (float)0.045544, (float)-0.300010, (float)-0.006938, (float)0.014103, (float)-0.261548, (float)-0.073598, (float)-0.106273, (float)-0.010544, (float)-0.071160, (float)-0.103388, (float)-0.029787, (float)-0.142769, (float)-0.051710, (float)-0.057126, (float)-0.054392, (float)-0.042260, (float)-0.008512, (float)0.015887, (float)-0.065358, (float)-0.061346, (float)-0.145019, (float)0.039939, (float)0.081640, (float)-0.007760, (float)-0.034062, (float)0.031969, (float)-0.044756, (float)-0.070306, (float)0.102130, (float)-0.179928, (float)-0.211733, (float)-0.059797, (float)-0.115961, (float)0.039271, (float)-0.045443, (float)-0.184456, (float)-0.108476, (float)0.055781, (float)-0.063649, (float)0.016825, (float)0.000166, (float)0.079866, (float)-0.067240, (float)0.079827, (float)-0.003991, (float)-0.190164, (float)0.020026, (float)0.073181, (float)0.103234, (float)-0.026431, (float)0.023963, (float)-0.044247, (float)0.022896, (float)0.023444, (float)-0.023481, (float)0.010516, (float)-0.214937, (float)-0.128099, (float)-0.018338, (float)-0.000602, (float)-0.051624, (float)0.056575, (float)-0.054297, (float)0.014146, (float)-0.049852, (float)0.067255, (float)0.051713, (float)-0.004027, (float)0.035057, (float)0.082781, (float)0.010034, (float)0.059230, (float)-0.204295, (float)-0.076169, (float)0.041432, (float)0.077517, (float)0.076005, (float)-0.159186, (float)-0.083613, (float)-0.166251, (float)0.002297, (float)-0.068489, (float)0.038119, (float)-0.098731, (float)-0.020290, (float)0.015394, (float)-0.105481};	// L3913
  #pragma HLS resource variable=v3413 core=ram_t2p_bram

  float v3414[256] = {(float)0.321214, (float)0.212399, (float)0.266072, (float)0.359449, (float)0.278469, (float)0.258197, (float)0.310780, (float)0.309614, (float)0.334833, (float)0.299212, (float)0.254539, (float)0.245751, (float)0.313275, (float)0.415883, (float)0.299702, (float)0.306994, (float)0.313544, (float)0.441772, (float)0.374276, (float)0.257042, (float)0.294294, (float)0.307829, (float)0.273839, (float)0.394832, (float)0.292831, (float)0.357222, (float)0.343523, (float)0.537935, (float)0.424347, (float)0.390766, (float)0.274456, (float)0.279759, (float)0.321719, (float)0.195593, (float)0.275126, (float)0.318720, (float)0.350660, (float)0.275078, (float)0.191919, (float)0.330734, (float)0.285038, (float)0.303757, (float)0.217935, (float)0.265186, (float)0.294413, (float)0.213770, (float)0.218425, (float)0.294765, (float)0.326244, (float)0.375874, (float)0.255724, (float)0.379644, (float)0.294955, (float)0.338577, (float)0.324264, (float)0.307028, (float)0.333070, (float)0.230194, (float)0.303576, (float)0.337655, (float)0.292232, (float)0.220439, (float)0.326703, (float)0.319780, (float)0.402345, (float)0.298687, (float)0.486047, (float)0.285416, (float)0.271637, (float)0.434131, (float)0.283433, (float)0.229564, (float)0.250730, (float)0.311966, (float)0.367275, (float)0.324437, (float)0.338049, (float)0.327208, (float)0.286757, (float)0.287673, (float)0.320995, (float)0.233216, (float)0.337860, (float)0.276670, (float)0.294190, (float)0.267243, (float)0.440110, (float)0.290800, (float)0.377056, (float)0.278862, (float)0.305619, (float)0.327566, (float)0.387124, (float)0.245329, (float)0.255872, (float)0.278296, (float)0.316762, (float)0.340972, (float)0.231816, (float)0.357684, (float)0.503631, (float)0.355690, (float)0.247532, (float)0.185207, (float)0.227332, (float)0.360157, (float)0.291895, (float)0.392827, (float)0.442318, (float)0.205229, (float)0.252430, (float)0.218886, (float)0.411338, (float)0.361080, (float)0.428416, (float)0.233330, (float)0.350439, (float)0.700149, (float)0.375362, (float)0.287419, (float)0.370221, (float)0.317366, (float)0.363957, (float)0.288891, (float)0.415500, (float)0.247910, (float)0.289849, (float)0.373996, (float)0.492593, (float)0.280807, (float)0.238791, (float)0.347282, (float)0.186811, (float)0.283673, (float)0.308996, (float)0.361434, (float)0.279743, (float)0.687078, (float)0.285402, (float)0.293681, (float)0.312809, (float)0.486253, (float)0.219283, (float)0.287136, (float)0.255449, (float)0.417536, (float)0.304438, (float)0.322992, (float)0.334262, (float)0.494713, (float)0.392355, (float)0.226389, (float)0.265720, (float)0.419290, (float)0.348321, (float)0.355126, (float)0.287663, (float)0.255942, (float)0.245868, (float)0.277469, (float)0.384195, (float)0.294926, (float)0.350955, (float)0.192600, (float)0.310130, (float)0.341671, (float)0.393080, (float)0.391781, (float)0.323868, (float)0.285095, (float)0.458256, (float)0.266863, (float)0.266303, (float)0.443338, (float)0.322125, (float)0.365481, (float)0.333581, (float)0.439321, (float)0.396961, (float)0.372661, (float)0.352343, (float)0.358557, (float)0.328611, (float)0.418138, (float)0.295527, (float)0.304995, (float)0.298793, (float)0.432011, (float)0.230884, (float)0.382633, (float)0.227008, (float)0.222812, (float)0.320580, (float)0.327314, (float)0.262748, (float)0.308742, (float)0.292022, (float)0.232836, (float)0.414381, (float)0.407486, (float)0.326447, (float)0.358304, (float)0.301402, (float)0.315049, (float)0.443821, (float)0.404212, (float)0.202751, (float)0.385498, (float)0.256986, (float)0.236064, (float)0.234269, (float)0.331237, (float)0.230322, (float)0.374439, (float)0.472747, (float)0.360084, (float)0.275426, (float)0.198746, (float)0.302701, (float)0.342689, (float)0.299445, (float)0.253305, (float)0.263879, (float)0.345958, (float)0.384709, (float)0.436817, (float)0.378559, (float)0.312291, (float)0.259140, (float)0.397851, (float)0.257663, (float)0.313072, (float)0.293382, (float)0.302671, (float)0.294207, (float)0.226591, (float)0.280574, (float)0.297662, (float)0.185842, (float)0.278839, (float)0.250415, (float)0.394814, (float)0.349607, (float)0.242925, (float)0.215502, (float)0.268320, (float)0.409995, (float)0.349523, (float)0.424278, (float)0.262704, (float)0.332853, (float)0.284865, (float)0.392416, (float)0.372755, (float)0.265513, (float)0.333785};	// L3914
  #pragma HLS resource variable=v3414 core=ram_t2p_bram

  float v3415[256] = {(float)0.013212, (float)0.013382, (float)0.006095, (float)0.023173, (float)0.010613, (float)0.013040, (float)0.018071, (float)0.022225, (float)0.005863, (float)0.008064, (float)0.009384, (float)0.020050, (float)0.013193, (float)0.043016, (float)0.016614, (float)0.008651, (float)0.016540, (float)0.025693, (float)0.008004, (float)0.005019, (float)0.027886, (float)0.003852, (float)0.007347, (float)0.015154, (float)0.021317, (float)0.029001, (float)0.021060, (float)0.006044, (float)0.011943, (float)0.013458, (float)0.013165, (float)0.024103, (float)0.010533, (float)0.017815, (float)0.014061, (float)0.021802, (float)0.009886, (float)0.011141, (float)0.012210, (float)0.013257, (float)0.018708, (float)0.016071, (float)0.014969, (float)0.012958, (float)0.011608, (float)0.009993, (float)0.006997, (float)0.025080, (float)0.010482, (float)0.014110, (float)0.018211, (float)0.023854, (float)0.024584, (float)0.020267, (float)0.019324, (float)0.016686, (float)0.023925, (float)0.013504, (float)0.019314, (float)0.024688, (float)0.022756, (float)0.013571, (float)0.014856, (float)0.024605, (float)0.027555, (float)0.028775, (float)0.008696, (float)0.006599, (float)0.010593, (float)0.010700, (float)0.009298, (float)0.019956, (float)0.022161, (float)0.022084, (float)0.016220, (float)0.011626, (float)0.015926, (float)0.007989, (float)0.010761, (float)0.012732, (float)0.020618, (float)0.014437, (float)0.015537, (float)0.018481, (float)0.020876, (float)0.009675, (float)0.004506, (float)0.014136, (float)0.008490, (float)0.012861, (float)0.012262, (float)0.034415, (float)0.014798, (float)0.005757, (float)0.008053, (float)0.008657, (float)0.012911, (float)0.023058, (float)0.014168, (float)0.009986, (float)0.011963, (float)0.015742, (float)0.020729, (float)0.009315, (float)0.011655, (float)0.011168, (float)0.011475, (float)0.016534, (float)0.017462, (float)0.009781, (float)0.017381, (float)0.010939, (float)0.011043, (float)0.013494, (float)0.007770, (float)0.005724, (float)0.018667, (float)0.010200, (float)0.011307, (float)0.008269, (float)0.009879, (float)0.011117, (float)0.014385, (float)0.023246, (float)0.025138, (float)0.009115, (float)0.010578, (float)0.007320, (float)0.016562, (float)0.014827, (float)0.005685, (float)0.034491, (float)0.019896, (float)0.020521, (float)0.009075, (float)0.012675, (float)0.010924, (float)0.026108, (float)0.010890, (float)0.006949, (float)0.022735, (float)0.007547, (float)0.016364, (float)0.010205, (float)0.007436, (float)0.013534, (float)0.015288, (float)0.025751, (float)0.007504, (float)0.009168, (float)0.023543, (float)0.007190, (float)0.008317, (float)0.012518, (float)0.014798, (float)0.011023, (float)0.015361, (float)0.004985, (float)0.006109, (float)0.009817, (float)0.013473, (float)0.016659, (float)0.028802, (float)0.003228, (float)0.015283, (float)0.013065, (float)0.019141, (float)0.010007, (float)0.020190, (float)0.014825, (float)0.011234, (float)0.006844, (float)0.014365, (float)0.009743, (float)0.021293, (float)0.015214, (float)0.013259, (float)0.006814, (float)0.012939, (float)0.006188, (float)0.006421, (float)0.007311, (float)0.022736, (float)0.008418, (float)0.019729, (float)0.010084, (float)0.019774, (float)0.022133, (float)0.007438, (float)0.011675, (float)0.026822, (float)0.006403, (float)0.008460, (float)0.012970, (float)0.011952, (float)0.009338, (float)0.011365, (float)0.016780, (float)0.008185, (float)0.010743, (float)0.016519, (float)0.020700, (float)0.009490, (float)0.019632, (float)0.013310, (float)0.011290, (float)0.005067, (float)0.015383, (float)0.011103, (float)0.028381, (float)0.011821, (float)0.011883, (float)0.015355, (float)0.021017, (float)0.011177, (float)0.010712, (float)0.007522, (float)0.014946, (float)0.012895, (float)0.005904, (float)0.004068, (float)0.020167, (float)0.015424, (float)0.010638, (float)0.003425, (float)0.011384, (float)0.030723, (float)0.007040, (float)0.030110, (float)0.018263, (float)0.006956, (float)0.005911, (float)0.008097, (float)0.018654, (float)0.006678, (float)0.018846, (float)0.013750, (float)0.006798, (float)0.008424, (float)0.015255, (float)0.014950, (float)0.013587, (float)0.020014, (float)0.015513, (float)0.009465, (float)0.005946, (float)0.023052, (float)0.018731, (float)0.009167, (float)0.009334, (float)0.014370, (float)0.011357, (float)0.011465, (float)0.010277, (float)0.010530, (float)0.017208};	// L3915
  #pragma HLS resource variable=v3415 core=ram_t2p_bram

  float v3416[256] = {(float)-0.107749, (float)-0.122918, (float)-0.068057, (float)-0.192978, (float)-0.057083, (float)-0.022351, (float)-0.033751, (float)-0.243701, (float)-0.044682, (float)0.045172, (float)0.000794, (float)0.060614, (float)-0.068606, (float)-0.041073, (float)0.043546, (float)-0.087261, (float)-0.215666, (float)-0.159296, (float)-0.015692, (float)-0.069784, (float)-0.179629, (float)-0.020418, (float)0.044308, (float)-0.157338, (float)-0.040731, (float)-0.183036, (float)0.017990, (float)-0.089484, (float)-0.043369, (float)-0.203314, (float)-0.017081, (float)0.144224, (float)-0.079689, (float)-0.184836, (float)-0.020056, (float)-0.043827, (float)-0.143498, (float)-0.015720, (float)0.062979, (float)-0.022316, (float)-0.146989, (float)-0.083330, (float)-0.156791, (float)0.018029, (float)0.008319, (float)0.112518, (float)-0.093601, (float)0.064658, (float)-0.135173, (float)-0.137200, (float)0.136350, (float)-0.103056, (float)-0.167458, (float)-0.206970, (float)-0.007766, (float)-0.017808, (float)0.112277, (float)-0.087588, (float)-0.187685, (float)0.024718, (float)-0.254787, (float)-0.141303, (float)-0.091591, (float)-0.161294, (float)0.008704, (float)-0.204462, (float)-0.042047, (float)-0.076329, (float)-0.052223, (float)-0.002868, (float)-0.042433, (float)0.154109, (float)0.066410, (float)-0.073272, (float)-0.093508, (float)-0.022622, (float)-0.179698, (float)0.012897, (float)0.046525, (float)-0.100765, (float)-0.065238, (float)0.008820, (float)-0.012005, (float)0.057574, (float)-0.057091, (float)-0.066670, (float)-0.022753, (float)-0.088033, (float)-0.019220, (float)0.091500, (float)0.021224, (float)-0.286575, (float)-0.185104, (float)0.063062, (float)-0.032503, (float)0.010583, (float)-0.016274, (float)-0.137474, (float)-0.020840, (float)0.039972, (float)0.038194, (float)-0.158154, (float)-0.024230, (float)-0.010428, (float)-0.025313, (float)-0.007089, (float)-0.082242, (float)-0.002871, (float)0.016810, (float)-0.132763, (float)-0.063943, (float)0.083179, (float)-0.066588, (float)-0.008000, (float)-0.045917, (float)0.045017, (float)-0.101334, (float)-0.062952, (float)-0.062940, (float)-0.136139, (float)-0.050002, (float)-0.048774, (float)0.109049, (float)-0.069991, (float)-0.080147, (float)-0.103026, (float)-0.027757, (float)-0.124223, (float)-0.058502, (float)-0.026336, (float)-0.037121, (float)-0.067826, (float)-0.168335, (float)0.012244, (float)0.038192, (float)-0.007231, (float)-0.042381, (float)-0.086380, (float)-0.005778, (float)0.096943, (float)-0.223213, (float)0.025069, (float)-0.029840, (float)-0.012575, (float)0.053059, (float)-0.200877, (float)-0.221157, (float)-0.002151, (float)0.039617, (float)-0.002853, (float)-0.137680, (float)0.022641, (float)0.019518, (float)-0.174737, (float)0.061876, (float)-0.153826, (float)-0.089588, (float)0.075784, (float)-0.046126, (float)0.001137, (float)-0.078707, (float)-0.087727, (float)-0.220280, (float)-0.043143, (float)0.074256, (float)-0.128912, (float)-0.096022, (float)-0.084083, (float)0.058107, (float)-0.105853, (float)-0.151327, (float)-0.083388, (float)0.035651, (float)-0.091718, (float)0.064076, (float)0.059519, (float)-0.120998, (float)-0.027586, (float)0.037621, (float)-0.009965, (float)-0.137036, (float)-0.096201, (float)-0.281392, (float)-0.103302, (float)-0.043732, (float)-0.033824, (float)-0.059146, (float)-0.069079, (float)-0.088350, (float)-0.048529, (float)0.074784, (float)-0.037809, (float)-0.047766, (float)0.018923, (float)-0.054648, (float)-0.014481, (float)0.033152, (float)-0.059256, (float)0.022501, (float)-0.137368, (float)-0.118120, (float)0.055905, (float)0.022248, (float)-0.002063, (float)-0.095352, (float)-0.041699, (float)0.079884, (float)-0.144740, (float)-0.029650, (float)-0.095548, (float)0.059774, (float)0.073225, (float)-0.007424, (float)0.040194, (float)-0.022209, (float)0.074660, (float)0.011220, (float)0.126989, (float)-0.027397, (float)-0.005367, (float)0.014878, (float)-0.026290, (float)-0.037304, (float)-0.097051, (float)0.074925, (float)-0.137720, (float)-0.187705, (float)-0.063754, (float)-0.148719, (float)-0.009851, (float)-0.027509, (float)0.001119, (float)-0.040400, (float)0.055569, (float)-0.111979, (float)-0.167270, (float)0.040156, (float)-0.179521, (float)0.067644, (float)0.022024, (float)-0.081266, (float)0.091851, (float)-0.040204, (float)0.019240, (float)0.003338, (float)-0.021979, (float)-0.167338, (float)-0.108656, (float)-0.102467, (float)0.047615, (float)-0.137436, (float)0.005816, (float)-0.077233, (float)-0.044517, (float)0.014401, (float)-0.114851};	// L3916
  #pragma HLS resource variable=v3416 core=ram_t2p_bram

  float v3417[256] = {(float)0.067355, (float)0.051428, (float)0.038453, (float)0.169151, (float)0.060444, (float)0.045957, (float)0.120948, (float)0.111015, (float)0.041795, (float)0.038695, (float)0.044169, (float)0.070729, (float)0.078953, (float)0.109442, (float)0.095900, (float)0.054391, (float)0.103244, (float)0.218981, (float)0.045899, (float)0.037226, (float)0.140985, (float)0.058720, (float)0.036016, (float)0.095475, (float)0.165730, (float)0.102427, (float)0.141727, (float)0.058008, (float)0.053617, (float)0.071556, (float)0.086484, (float)0.111046, (float)0.051134, (float)0.051456, (float)0.080900, (float)0.115377, (float)0.077653, (float)0.044903, (float)0.048958, (float)0.105569, (float)0.145745, (float)0.074394, (float)0.053026, (float)0.059951, (float)0.102562, (float)0.048563, (float)0.040838, (float)0.131216, (float)0.063901, (float)0.106154, (float)0.091546, (float)0.147588, (float)0.090042, (float)0.074165, (float)0.106905, (float)0.077630, (float)0.142333, (float)0.049509, (float)0.097357, (float)0.066064, (float)0.129222, (float)0.054811, (float)0.114466, (float)0.094952, (float)0.092081, (float)0.157894, (float)0.049587, (float)0.023633, (float)0.039756, (float)0.093460, (float)0.029148, (float)0.065285, (float)0.088538, (float)0.118976, (float)0.169175, (float)0.069161, (float)0.131626, (float)0.060590, (float)0.048040, (float)0.065360, (float)0.108199, (float)0.062440, (float)0.110316, (float)0.110551, (float)0.107625, (float)0.040008, (float)0.072288, (float)0.094698, (float)0.066159, (float)0.046392, (float)0.044422, (float)0.172738, (float)0.092065, (float)0.034482, (float)0.045051, (float)0.037437, (float)0.094050, (float)0.081760, (float)0.039662, (float)0.045171, (float)0.098512, (float)0.109502, (float)0.107201, (float)0.050593, (float)0.044436, (float)0.075476, (float)0.042001, (float)0.104616, (float)0.117208, (float)0.044654, (float)0.045942, (float)0.040864, (float)0.053858, (float)0.103637, (float)0.074125, (float)0.031065, (float)0.108586, (float)0.174579, (float)0.077694, (float)0.068938, (float)0.109982, (float)0.048908, (float)0.104767, (float)0.109747, (float)0.102549, (float)0.044844, (float)0.067470, (float)0.070740, (float)0.136368, (float)0.043839, (float)0.034581, (float)0.176885, (float)0.066684, (float)0.115469, (float)0.062781, (float)0.087277, (float)0.040644, (float)0.289002, (float)0.070327, (float)0.042766, (float)0.117316, (float)0.104901, (float)0.061137, (float)0.046914, (float)0.040005, (float)0.074382, (float)0.100340, (float)0.101244, (float)0.059949, (float)0.107826, (float)0.151178, (float)0.032168, (float)0.042972, (float)0.097673, (float)0.095145, (float)0.083779, (float)0.095803, (float)0.044831, (float)0.026261, (float)0.042486, (float)0.115426, (float)0.077075, (float)0.178146, (float)0.029957, (float)0.069904, (float)0.072415, (float)0.159989, (float)0.089302, (float)0.113046, (float)0.053426, (float)0.135893, (float)0.037503, (float)0.080887, (float)0.114542, (float)0.123203, (float)0.094226, (float)0.088033, (float)0.034649, (float)0.099603, (float)0.046072, (float)0.069359, (float)0.063005, (float)0.158955, (float)0.050894, (float)0.125435, (float)0.059031, (float)0.074401, (float)0.108354, (float)0.051442, (float)0.093101, (float)0.084757, (float)0.024004, (float)0.027874, (float)0.099328, (float)0.061239, (float)0.059906, (float)0.109542, (float)0.050842, (float)0.065824, (float)0.116200, (float)0.083273, (float)0.165128, (float)0.050494, (float)0.123114, (float)0.122795, (float)0.103773, (float)0.036941, (float)0.075630, (float)0.041531, (float)0.119168, (float)0.029214, (float)0.083852, (float)0.057698, (float)0.095098, (float)0.094377, (float)0.030888, (float)0.039030, (float)0.060384, (float)0.067196, (float)0.050130, (float)0.038252, (float)0.094625, (float)0.095757, (float)0.050099, (float)0.024288, (float)0.107435, (float)0.190828, (float)0.069329, (float)0.137637, (float)0.115080, (float)0.032938, (float)0.064666, (float)0.061636, (float)0.110599, (float)0.035808, (float)0.072129, (float)0.085061, (float)0.037549, (float)0.036827, (float)0.094678, (float)0.046447, (float)0.166622, (float)0.104944, (float)0.075518, (float)0.039807, (float)0.024882, (float)0.152823, (float)0.116652, (float)0.088585, (float)0.054029, (float)0.072570, (float)0.073581, (float)0.079700, (float)0.085395, (float)0.060856, (float)0.126276};	// L3917
  #pragma HLS resource variable=v3417 core=ram_t2p_bram

  float v3418[256] = {(float)0.202093, (float)0.264854, (float)0.081632, (float)0.114109, (float)0.127637, (float)0.123027, (float)0.178034, (float)0.139318, (float)0.123479, (float)0.117826, (float)0.128063, (float)0.150515, (float)0.105954, (float)0.095384, (float)0.114740, (float)0.126009, (float)0.083070, (float)0.221375, (float)0.145195, (float)0.125999, (float)0.120253, (float)0.150707, (float)0.106624, (float)0.303817, (float)0.144419, (float)0.126642, (float)0.196604, (float)0.114546, (float)0.137646, (float)0.099110, (float)0.122224, (float)0.134298, (float)0.106592, (float)0.114780, (float)0.194646, (float)0.158945, (float)0.171481, (float)0.158772, (float)0.157699, (float)0.099467, (float)0.103577, (float)0.130468, (float)0.154715, (float)0.162316, (float)0.143723, (float)0.162410, (float)0.085646, (float)0.218325, (float)0.133880, (float)0.080743, (float)0.152815, (float)0.127717, (float)0.141331, (float)0.119961, (float)0.256691, (float)0.120201, (float)0.152304, (float)0.151313, (float)0.100176, (float)0.145286, (float)0.161952, (float)0.126973, (float)0.117854, (float)0.100444, (float)0.203356, (float)0.157843, (float)0.178462, (float)0.118063, (float)0.067406, (float)0.246021, (float)0.125107, (float)0.114425, (float)0.167035, (float)0.145993, (float)0.162544, (float)0.120343, (float)0.169716, (float)0.106482, (float)0.141526, (float)0.169446, (float)0.090944, (float)0.113330, (float)0.156861, (float)0.087992, (float)0.133309, (float)0.171133, (float)0.242056, (float)0.118814, (float)0.088181, (float)0.108375, (float)0.137294, (float)0.288606, (float)0.173576, (float)0.173963, (float)0.151192, (float)0.108596, (float)0.121099, (float)0.152290, (float)0.145297, (float)0.173510, (float)0.151500, (float)0.134832, (float)0.244512, (float)0.143301, (float)0.142233, (float)0.152000, (float)0.098458, (float)0.129181, (float)0.137196, (float)0.222825, (float)0.126548, (float)0.153776, (float)0.160038, (float)0.112089, (float)0.192169, (float)0.119511, (float)0.110010, (float)0.115071, (float)0.143141, (float)0.125817, (float)0.141578, (float)0.104924, (float)0.183995, (float)0.115784, (float)0.111114, (float)0.218703, (float)0.119288, (float)0.154097, (float)0.107354, (float)0.135008, (float)0.138471, (float)0.099032, (float)0.141793, (float)0.183737, (float)0.166731, (float)0.171192, (float)0.156719, (float)0.154214, (float)0.150069, (float)0.158486, (float)0.142163, (float)0.152685, (float)0.117883, (float)0.188203, (float)0.185572, (float)0.154950, (float)0.179835, (float)0.287934, (float)0.115603, (float)0.174893, (float)0.129729, (float)0.152180, (float)0.130814, (float)0.212340, (float)0.157937, (float)0.093668, (float)0.131023, (float)0.205168, (float)0.151040, (float)0.154166, (float)0.141620, (float)0.120317, (float)0.137218, (float)0.197992, (float)0.135204, (float)0.206488, (float)0.138541, (float)0.135778, (float)0.169633, (float)0.281613, (float)0.105841, (float)0.088596, (float)0.112328, (float)0.226925, (float)0.111682, (float)0.107955, (float)0.202922, (float)0.102599, (float)0.114998, (float)0.145168, (float)0.118048, (float)0.169048, (float)0.207947, (float)0.113291, (float)0.193266, (float)0.145378, (float)0.087229, (float)0.100246, (float)0.110129, (float)0.175703, (float)0.196709, (float)0.090690, (float)0.117549, (float)0.150821, (float)0.134801, (float)0.120340, (float)0.141347, (float)0.218888, (float)0.102995, (float)0.138703, (float)0.166914, (float)0.108992, (float)0.163189, (float)0.087485, (float)0.134905, (float)0.107441, (float)0.283900, (float)0.162788, (float)0.187195, (float)0.153806, (float)0.097348, (float)0.183113, (float)0.211954, (float)0.171563, (float)0.088992, (float)0.186927, (float)0.087747, (float)0.129961, (float)0.279172, (float)0.156529, (float)0.160495, (float)0.142747, (float)0.136645, (float)0.144106, (float)0.107992, (float)0.116587, (float)0.128579, (float)0.249071, (float)0.124998, (float)0.146923, (float)0.138747, (float)0.116422, (float)0.125475, (float)0.099127, (float)0.094169, (float)0.154936, (float)0.284385, (float)0.123462, (float)0.173281, (float)0.182766, (float)0.089063, (float)0.110368, (float)0.128625, (float)0.149508, (float)0.124881, (float)0.462863, (float)0.137999, (float)0.101497, (float)0.106382, (float)0.161172, (float)0.214756, (float)0.144181, (float)0.171417, (float)0.160055, (float)0.257159, (float)0.187855};	// L3918
  #pragma HLS resource variable=v3418 core=ram_t2p_bram

  float v3419[256] = {(float)-0.102453, (float)-0.259171, (float)-0.096546, (float)-0.340652, (float)-0.709656, (float)-0.603112, (float)-0.214115, (float)-0.903070, (float)-0.403511, (float)-0.640743, (float)-0.249654, (float)-0.358281, (float)-0.456530, (float)-0.649031, (float)-0.517009, (float)-0.134873, (float)-0.485002, (float)-0.473931, (float)-0.315326, (float)-0.820895, (float)-0.422487, (float)-0.620579, (float)-0.455907, (float)-0.336757, (float)-0.479224, (float)-0.145781, (float)-0.274776, (float)-0.398024, (float)-0.713027, (float)-0.839437, (float)-0.273773, (float)-0.268421, (float)-0.755879, (float)-0.121173, (float)-0.438951, (float)-0.697070, (float)-0.503360, (float)-0.566661, (float)-0.088093, (float)-0.530825, (float)-1.077885, (float)-0.465694, (float)-0.101642, (float)-0.325129, (float)0.538409, (float)-0.757289, (float)-0.471778, (float)-0.347490, (float)-0.719843, (float)0.047820, (float)-0.138734, (float)-0.877976, (float)-0.405742, (float)-0.115066, (float)0.099245, (float)-0.388754, (float)-1.001531, (float)-0.386642, (float)-0.326697, (float)-0.732440, (float)0.090762, (float)-0.275990, (float)-0.275940, (float)-0.189190, (float)-0.503649, (float)-0.740645, (float)-0.531369, (float)-0.480375, (float)-0.606323, (float)-0.002653, (float)-0.918494, (float)-0.244357, (float)-1.184874, (float)-0.538959, (float)0.082583, (float)-0.517662, (float)-0.281385, (float)-0.946679, (float)-0.394639, (float)-0.220216, (float)-0.932489, (float)-0.220535, (float)-0.563211, (float)-0.316468, (float)-0.347139, (float)-0.569394, (float)-0.510860, (float)-0.589007, (float)-0.783802, (float)-0.002263, (float)-0.239585, (float)-0.167228, (float)-0.841089, (float)-0.730738, (float)-0.726148, (float)-0.934870, (float)-0.371630, (float)-0.356172, (float)-0.513671, (float)0.019965, (float)-0.168304, (float)-0.563289, (float)-0.785985, (float)0.099101, (float)-0.419311, (float)-0.207190, (float)0.357886, (float)-0.410227, (float)-0.366750, (float)-0.404898, (float)-0.900548, (float)-0.277691, (float)-0.272548, (float)0.394123, (float)-0.507511, (float)-0.452994, (float)-0.147831, (float)-0.022060, (float)-0.857384, (float)-0.310359, (float)-0.345442, (float)-0.642811, (float)-0.270896, (float)-0.856503, (float)-0.625989, (float)0.038911, (float)-0.225354, (float)-0.060526, (float)-0.598401, (float)-0.364272, (float)-0.348462, (float)0.025581, (float)-0.649912, (float)-0.305280, (float)-0.239829, (float)-0.398209, (float)-0.721522, (float)-0.653706, (float)0.076822, (float)-0.455411, (float)-0.536163, (float)-0.102057, (float)-0.646412, (float)-0.265759, (float)-0.498525, (float)-0.431918, (float)-0.385519, (float)-0.394294, (float)-0.591754, (float)-0.233525, (float)-0.677230, (float)-0.516218, (float)0.380602, (float)-0.389636, (float)-0.729214, (float)-0.220693, (float)-0.168720, (float)-0.662275, (float)0.284971, (float)0.172585, (float)-0.197409, (float)-0.558643, (float)-0.252358, (float)0.177279, (float)-0.609615, (float)-0.228053, (float)-0.469064, (float)-0.813329, (float)0.009186, (float)-0.491989, (float)-0.176777, (float)0.128825, (float)-0.069292, (float)-0.839732, (float)0.261292, (float)-0.218767, (float)-0.319037, (float)-0.486760, (float)-0.660932, (float)-0.767496, (float)-0.793261, (float)-0.934205, (float)-0.069119, (float)-0.661614, (float)-0.370487, (float)-0.453789, (float)-0.927919, (float)0.332377, (float)-0.495022, (float)0.266945, (float)-0.813905, (float)-0.790910, (float)-0.789206, (float)-0.467173, (float)-0.591689, (float)-0.546259, (float)-0.289580, (float)-0.022648, (float)-0.272203, (float)-0.374683, (float)0.120206, (float)-0.033795, (float)0.189072, (float)-0.243509, (float)-0.022650, (float)-0.764620, (float)-0.401645, (float)-0.311593, (float)1.539555, (float)-0.137344, (float)-0.753158, (float)-0.610004, (float)-0.243898, (float)-0.531916, (float)-0.660311, (float)-0.319874, (float)-0.847142, (float)-0.048371, (float)0.082996, (float)-0.458410, (float)-0.388908, (float)-0.816281, (float)-0.332179, (float)-0.667026, (float)-0.774422, (float)-0.700965, (float)0.212783, (float)-0.562379, (float)-1.035953, (float)-0.309841, (float)0.699997, (float)-0.358035, (float)-0.348437, (float)-0.516148, (float)-0.216690, (float)-0.890328, (float)-0.340157, (float)-0.403715, (float)-0.550114, (float)-0.419702, (float)-0.528954, (float)-0.497380, (float)0.008297, (float)-0.016590, (float)-0.860652, (float)-0.558072, (float)-0.516058, (float)-0.366773, (float)-0.736309, (float)-0.365438, (float)-0.278847, (float)-0.389011, (float)-0.152117, (float)-0.332711, (float)-0.790260, (float)-0.253097};	// L3919
  #pragma HLS resource variable=v3419 core=ram_t2p_bram

  float v3420[256] = {(float)-0.133214, (float)-0.064444, (float)-0.323875, (float)-0.239039, (float)-0.326220, (float)-0.179559, (float)-0.208659, (float)-0.320836, (float)-0.187442, (float)-0.298805, (float)-0.209937, (float)-0.228288, (float)-0.214078, (float)-0.245966, (float)-0.276796, (float)-0.135078, (float)-0.249833, (float)-0.239290, (float)-0.122324, (float)-0.459029, (float)-0.217210, (float)-0.121966, (float)-0.210134, (float)-0.177912, (float)-0.242619, (float)-0.154622, (float)-0.154925, (float)-0.371626, (float)-0.281672, (float)-0.388609, (float)-0.154490, (float)-0.068677, (float)-0.341201, (float)-0.226082, (float)-0.196129, (float)-0.224238, (float)-0.298387, (float)-0.138098, (float)-0.225115, (float)-0.165752, (float)-0.453374, (float)-0.322573, (float)-0.097736, (float)-0.134867, (float)-0.261947, (float)-0.142808, (float)-0.396050, (float)-0.163345, (float)-0.210092, (float)-0.116093, (float)-0.144819, (float)-0.550154, (float)-0.217875, (float)-0.124579, (float)0.050221, (float)-0.190218, (float)-0.104652, (float)-0.099972, (float)-0.141065, (float)-0.312444, (float)-0.219041, (float)-0.306164, (float)-0.124671, (float)-0.155663, (float)-0.297321, (float)-0.382461, (float)-0.195100, (float)-0.138092, (float)-0.576052, (float)-0.387944, (float)-0.280753, (float)-0.254198, (float)-0.347019, (float)-0.246020, (float)-0.109053, (float)-0.056168, (float)-0.183284, (float)-0.495630, (float)-0.305902, (float)-0.098782, (float)-0.225456, (float)-0.195824, (float)-0.132007, (float)-0.173788, (float)-0.228728, (float)-0.192558, (float)-0.092404, (float)-0.342682, (float)-0.548922, (float)-0.243081, (float)-0.193513, (float)-0.164142, (float)-0.250291, (float)-0.327355, (float)-0.400776, (float)-0.282362, (float)-0.269382, (float)-0.193880, (float)-0.241272, (float)-0.030905, (float)-0.088015, (float)-0.342131, (float)-0.310449, (float)-0.110157, (float)-0.153949, (float)-0.123325, (float)-0.178033, (float)-0.271506, (float)-0.200460, (float)-0.184582, (float)-0.284287, (float)-0.111685, (float)-0.181633, (float)-0.211910, (float)-0.330439, (float)-0.226671, (float)-0.141322, (float)-0.337637, (float)-0.267428, (float)-0.252407, (float)-0.255380, (float)-0.473517, (float)-0.234194, (float)-0.213038, (float)-0.328168, (float)-0.196613, (float)-0.106321, (float)-0.261463, (float)-0.423371, (float)-0.137416, (float)-0.081062, (float)-0.306943, (float)-0.153817, (float)-0.145295, (float)-0.161228, (float)-0.163069, (float)-0.375850, (float)-0.260815, (float)-0.238250, (float)-0.249911, (float)-0.148469, (float)-0.148726, (float)-0.432819, (float)-0.137658, (float)-0.278101, (float)-0.225946, (float)-0.207203, (float)-0.416503, (float)-0.358211, (float)-0.138224, (float)-0.359833, (float)-0.267221, (float)-0.208982, (float)-0.017715, (float)-0.127906, (float)-0.281210, (float)-0.362077, (float)0.047602, (float)-0.223232, (float)-0.127153, (float)-0.323714, (float)-0.300843, (float)-0.111896, (float)-0.083946, (float)-0.242635, (float)-0.200009, (float)-0.187291, (float)-0.468492, (float)-0.199976, (float)-0.346223, (float)-0.070560, (float)-0.197347, (float)-0.354795, (float)-0.197491, (float)-0.353741, (float)-0.354628, (float)-0.143281, (float)-0.205225, (float)-0.272155, (float)-0.152756, (float)-0.279767, (float)-0.194508, (float)-0.247417, (float)-0.491016, (float)0.132207, (float)-0.237834, (float)-0.516559, (float)-0.395906, (float)-0.235377, (float)-0.126617, (float)-0.080985, (float)-0.413208, (float)-0.557567, (float)-0.223787, (float)-0.156350, (float)-0.395036, (float)-0.328337, (float)-0.084629, (float)-0.310310, (float)-0.312971, (float)-0.149776, (float)-0.139644, (float)-0.097234, (float)-0.161957, (float)-0.163142, (float)-0.636406, (float)-0.135030, (float)-0.234509, (float)-0.104853, (float)-0.162499, (float)-0.287795, (float)-0.245024, (float)-0.146850, (float)-0.203473, (float)-0.535771, (float)-0.168296, (float)-0.552396, (float)-0.251135, (float)-0.122984, (float)-0.230478, (float)-0.192514, (float)-0.375949, (float)-0.101441, (float)-0.169663, (float)-0.400249, (float)-0.297984, (float)-0.303460, (float)-0.156281, (float)-0.465962, (float)-0.115537, (float)-0.166486, (float)-0.338201, (float)-0.293534, (float)-0.312157, (float)-0.301493, (float)-0.326061, (float)-0.254199, (float)-0.203715, (float)-0.095477, (float)-0.206962, (float)-0.437046, (float)-0.205060, (float)-0.420465, (float)-0.312456, (float)-0.484535, (float)-0.352765, (float)-0.262413, (float)-0.289421, (float)-0.397609, (float)-0.210660, (float)-0.179051, (float)-0.107529, (float)-0.121296, (float)-0.302165, (float)0.051579, (float)-0.192754};	// L3920
  #pragma HLS resource variable=v3420 core=ram_t2p_bram

  float v3421[256] = {(float)0.248004, (float)0.197221, (float)0.227915, (float)0.270937, (float)0.329617, (float)0.263992, (float)0.271038, (float)0.347507, (float)0.238823, (float)0.290421, (float)0.276932, (float)0.304482, (float)0.226830, (float)0.263404, (float)0.299885, (float)0.239654, (float)0.272437, (float)0.272277, (float)0.213278, (float)0.380557, (float)0.276681, (float)0.240271, (float)0.240643, (float)0.291698, (float)0.267530, (float)0.230546, (float)0.239432, (float)0.312264, (float)0.298412, (float)0.335303, (float)0.223426, (float)0.191874, (float)0.316781, (float)0.262574, (float)0.290077, (float)0.291755, (float)0.345481, (float)0.256062, (float)0.243417, (float)0.229806, (float)0.331795, (float)0.348086, (float)0.203156, (float)0.247785, (float)0.247750, (float)0.248303, (float)0.325223, (float)0.256749, (float)0.268470, (float)0.197736, (float)0.254135, (float)0.407943, (float)0.248038, (float)0.207616, (float)0.227621, (float)0.268264, (float)0.209837, (float)0.205637, (float)0.201043, (float)0.356013, (float)0.238443, (float)0.328386, (float)0.195169, (float)0.244480, (float)0.284825, (float)0.374165, (float)0.274620, (float)0.211680, (float)0.385899, (float)0.478451, (float)0.300522, (float)0.284849, (float)0.376245, (float)0.290297, (float)0.212571, (float)0.177562, (float)0.277798, (float)0.387786, (float)0.312289, (float)0.197362, (float)0.267901, (float)0.229997, (float)0.247368, (float)0.231969, (float)0.263528, (float)0.281929, (float)0.229565, (float)0.319441, (float)0.381395, (float)0.250263, (float)0.226861, (float)0.267645, (float)0.343139, (float)0.379892, (float)0.378657, (float)0.296827, (float)0.302131, (float)0.257482, (float)0.300692, (float)0.193874, (float)0.194984, (float)0.321728, (float)0.362303, (float)0.217116, (float)0.248580, (float)0.226643, (float)0.213327, (float)0.285148, (float)0.271466, (float)0.271985, (float)0.310700, (float)0.217368, (float)0.267532, (float)0.238684, (float)0.343367, (float)0.276101, (float)0.208426, (float)0.297540, (float)0.317776, (float)0.281832, (float)0.285849, (float)0.349836, (float)0.267530, (float)0.263775, (float)0.315932, (float)0.287927, (float)0.187316, (float)0.298574, (float)0.358417, (float)0.256991, (float)0.181488, (float)0.275838, (float)0.263985, (float)0.248594, (float)0.256725, (float)0.225200, (float)0.341978, (float)0.290998, (float)0.289778, (float)0.290217, (float)0.240370, (float)0.238109, (float)0.363321, (float)0.269005, (float)0.380985, (float)0.294719, (float)0.274345, (float)0.464418, (float)0.313274, (float)0.244387, (float)0.347697, (float)0.300125, (float)0.197695, (float)0.230124, (float)0.251274, (float)0.266026, (float)0.327121, (float)0.162206, (float)0.227351, (float)0.222519, (float)0.359638, (float)0.321504, (float)0.199726, (float)0.221497, (float)0.270638, (float)0.283085, (float)0.262063, (float)0.370977, (float)0.272955, (float)0.290309, (float)0.189265, (float)0.213956, (float)0.245996, (float)0.314081, (float)0.242442, (float)0.369932, (float)0.236427, (float)0.242000, (float)0.294799, (float)0.249748, (float)0.275993, (float)0.268643, (float)0.289536, (float)0.385712, (float)0.139844, (float)0.283177, (float)0.336180, (float)0.252237, (float)0.282348, (float)0.238055, (float)0.231099, (float)0.327437, (float)0.407818, (float)0.264824, (float)0.252499, (float)0.338782, (float)0.325136, (float)0.241992, (float)0.285595, (float)0.360523, (float)0.260303, (float)0.229410, (float)0.248266, (float)0.217122, (float)0.235323, (float)0.411717, (float)0.258756, (float)0.288844, (float)0.197249, (float)0.240768, (float)0.275538, (float)0.303093, (float)0.245712, (float)0.274405, (float)0.356421, (float)0.254601, (float)0.367256, (float)0.288264, (float)0.258973, (float)0.302077, (float)0.288963, (float)0.350464, (float)0.209174, (float)0.295303, (float)0.322194, (float)0.292542, (float)0.257395, (float)0.301156, (float)0.389332, (float)0.221066, (float)0.222639, (float)0.325820, (float)0.320490, (float)0.297501, (float)0.232316, (float)0.332266, (float)0.281247, (float)0.270204, (float)0.229953, (float)0.284602, (float)0.331768, (float)0.229250, (float)0.349766, (float)0.262185, (float)0.358054, (float)0.400306, (float)0.292357, (float)0.304933, (float)0.347845, (float)0.284454, (float)0.274175, (float)0.201888, (float)0.246647, (float)0.298755, (float)0.204366, (float)0.269054};	// L3921
  #pragma HLS resource variable=v3421 core=ram_t2p_bram

  float v3422[256] = {(float)0.018530, (float)0.026394, (float)0.012856, (float)0.012689, (float)0.014751, (float)0.015978, (float)0.012460, (float)0.018145, (float)0.019383, (float)0.011628, (float)0.007526, (float)0.011219, (float)0.034934, (float)0.017682, (float)0.020756, (float)0.025356, (float)0.023623, (float)0.019827, (float)0.022904, (float)0.034381, (float)0.019890, (float)0.053809, (float)0.031563, (float)0.019644, (float)0.012794, (float)0.019174, (float)0.019996, (float)0.028697, (float)0.018158, (float)0.027271, (float)0.011315, (float)0.011837, (float)0.021068, (float)0.008485, (float)0.016900, (float)0.015894, (float)0.012585, (float)0.015643, (float)0.009987, (float)0.008934, (float)0.018547, (float)0.015648, (float)0.008220, (float)0.013122, (float)0.011694, (float)0.010160, (float)0.010536, (float)0.024400, (float)0.013983, (float)0.016112, (float)0.011215, (float)0.016260, (float)0.029490, (float)0.035517, (float)0.014957, (float)0.020074, (float)0.017436, (float)0.011895, (float)0.020108, (float)0.035077, (float)0.018778, (float)0.012123, (float)0.013372, (float)0.023718, (float)0.024176, (float)0.017590, (float)0.028278, (float)0.014679, (float)0.010504, (float)0.016922, (float)0.024693, (float)0.018485, (float)0.010362, (float)0.016711, (float)0.013731, (float)0.022465, (float)0.011501, (float)0.024804, (float)0.012025, (float)0.012570, (float)0.021939, (float)0.016975, (float)0.017424, (float)0.021701, (float)0.017643, (float)0.019817, (float)0.023719, (float)0.012252, (float)0.027208, (float)0.060497, (float)0.011410, (float)0.012758, (float)0.019986, (float)0.019867, (float)0.022465, (float)0.019493, (float)0.016528, (float)0.023030, (float)0.018762, (float)0.020904, (float)0.021493, (float)0.024125, (float)0.012632, (float)0.014381, (float)0.012692, (float)0.009812, (float)0.016465, (float)0.016313, (float)0.040332, (float)0.015335, (float)0.014138, (float)0.005016, (float)0.033883, (float)0.015893, (float)0.022616, (float)0.012452, (float)0.017113, (float)0.045386, (float)0.016545, (float)0.031452, (float)0.041772, (float)0.022630, (float)0.024911, (float)0.016146, (float)0.019939, (float)0.010476, (float)0.027228, (float)0.014376, (float)0.027456, (float)0.011228, (float)0.009946, (float)0.009961, (float)0.020141, (float)0.018478, (float)0.009278, (float)0.020743, (float)0.008191, (float)0.028920, (float)0.015118, (float)0.013835, (float)0.016313, (float)0.021079, (float)0.012747, (float)0.013377, (float)0.040637, (float)0.025386, (float)0.021835, (float)0.015742, (float)0.008617, (float)0.018719, (float)0.034042, (float)0.009114, (float)0.006896, (float)0.021932, (float)0.020435, (float)0.033022, (float)0.020678, (float)0.012721, (float)0.040421, (float)0.014042, (float)0.014963, (float)0.016277, (float)0.047124, (float)0.053335, (float)0.014413, (float)0.016945, (float)0.024771, (float)0.022726, (float)0.016246, (float)0.039784, (float)0.025942, (float)0.006863, (float)0.016802, (float)0.020793, (float)0.018885, (float)0.023745, (float)0.015412, (float)0.022586, (float)0.018481, (float)0.020519, (float)0.029992, (float)0.050411, (float)0.018868, (float)0.017426, (float)0.014016, (float)0.018388, (float)0.023564, (float)0.040373, (float)0.069144, (float)0.027295, (float)0.020721, (float)0.016795, (float)0.023665, (float)0.018622, (float)0.014306, (float)0.011317, (float)0.042427, (float)0.014678, (float)0.021902, (float)0.043384, (float)0.044179, (float)0.011020, (float)0.017952, (float)0.014674, (float)0.015806, (float)0.025305, (float)0.023667, (float)0.021030, (float)0.011405, (float)0.019686, (float)0.011575, (float)0.013539, (float)0.009093, (float)0.020994, (float)0.023689, (float)0.025597, (float)0.033564, (float)0.016578, (float)0.015100, (float)0.013169, (float)0.029548, (float)0.026140, (float)0.016542, (float)0.013860, (float)0.011822, (float)0.020687, (float)0.018049, (float)0.009810, (float)0.016161, (float)0.039758, (float)0.011737, (float)0.032446, (float)0.013650, (float)0.022535, (float)0.017262, (float)0.012099, (float)0.009317, (float)0.011607, (float)0.011387, (float)0.019526, (float)0.014283, (float)0.010255, (float)0.020608, (float)0.011115, (float)0.016965, (float)0.013392, (float)0.022404, (float)0.021118, (float)0.039554, (float)0.007481, (float)0.024169, (float)0.012689, (float)0.036180, (float)0.016522, (float)0.018249, (float)0.016171};	// L3922
  #pragma HLS resource variable=v3422 core=ram_t2p_bram

  float v3423[256] = {(float)-0.082312, (float)-0.033227, (float)-0.026646, (float)-0.013217, (float)-0.063828, (float)-0.104692, (float)-0.067094, (float)-0.053039, (float)0.062327, (float)-0.000111, (float)-0.012984, (float)0.017784, (float)-0.049284, (float)-0.065327, (float)-0.098474, (float)0.211247, (float)-0.092193, (float)-0.113936, (float)-0.187878, (float)-0.082167, (float)-0.058521, (float)-0.559937, (float)-0.051197, (float)-0.198668, (float)-0.071481, (float)-0.066465, (float)-0.168375, (float)-0.103121, (float)0.105447, (float)-0.230613, (float)-0.033933, (float)-0.080676, (float)-0.003466, (float)0.047170, (float)-0.078841, (float)-0.126503, (float)-0.061497, (float)0.064309, (float)0.027830, (float)0.003133, (float)-0.076740, (float)-0.095088, (float)0.000138, (float)-0.047186, (float)-0.030897, (float)-0.046435, (float)-0.063253, (float)-0.081402, (float)-0.070531, (float)-0.067097, (float)-0.079232, (float)-0.177784, (float)0.055108, (float)0.411084, (float)0.001561, (float)-0.079884, (float)-0.069195, (float)-0.049812, (float)0.003836, (float)0.002520, (float)0.035645, (float)-0.025757, (float)-0.122488, (float)-0.046376, (float)-0.121627, (float)-0.064273, (float)-0.138339, (float)-0.023200, (float)-0.018081, (float)-0.147026, (float)0.048809, (float)-0.055714, (float)-0.034797, (float)-0.056561, (float)-0.065104, (float)-0.104747, (float)-0.052624, (float)-0.185086, (float)-0.106039, (float)0.026538, (float)0.071723, (float)-0.019967, (float)-0.112256, (float)-0.200571, (float)-0.103172, (float)0.004091, (float)-0.224197, (float)-0.127268, (float)-0.088721, (float)0.108202, (float)-0.058866, (float)-0.083435, (float)-0.104600, (float)0.023022, (float)-0.088489, (float)0.033548, (float)-0.110725, (float)-0.009239, (float)-0.045979, (float)-0.136995, (float)-0.202196, (float)0.046265, (float)-0.019667, (float)-0.011913, (float)-0.060050, (float)-0.075059, (float)-0.072690, (float)-0.091073, (float)-0.092056, (float)-0.058019, (float)-0.036355, (float)-0.044718, (float)-0.170913, (float)-0.136799, (float)-0.147614, (float)-0.147590, (float)-0.112343, (float)-0.230801, (float)-0.090601, (float)-0.259308, (float)-0.208255, (float)-0.063401, (float)-0.268006, (float)-0.161228, (float)-0.100256, (float)-0.131830, (float)-0.090434, (float)-0.096675, (float)-0.197284, (float)0.053544, (float)-0.027836, (float)-0.074435, (float)-0.056267, (float)-0.059114, (float)-0.024094, (float)-0.151039, (float)0.002181, (float)-0.188863, (float)-0.128863, (float)-0.019607, (float)-0.072803, (float)-0.184000, (float)-0.060926, (float)-0.020046, (float)-0.403146, (float)-0.073355, (float)-0.095973, (float)-0.086466, (float)-0.068302, (float)-0.168954, (float)-0.098700, (float)0.012385, (float)-0.044298, (float)-0.193734, (float)-0.132867, (float)-0.120692, (float)-0.142336, (float)0.104760, (float)-0.085365, (float)0.063847, (float)-0.057782, (float)-0.086523, (float)0.033596, (float)-0.387682, (float)-0.057414, (float)-0.075301, (float)-0.207186, (float)-0.182655, (float)-0.123786, (float)-0.220588, (float)-0.164540, (float)-0.029335, (float)-0.130926, (float)-0.158500, (float)-0.043881, (float)-0.138688, (float)-0.061651, (float)-0.019781, (float)-0.122039, (float)-0.076332, (float)-0.356170, (float)0.341274, (float)-0.065834, (float)-0.126368, (float)-0.175434, (float)0.041658, (float)-0.036161, (float)-0.128932, (float)-0.270402, (float)-0.214051, (float)0.019383, (float)0.013128, (float)-0.009500, (float)-0.060263, (float)-0.034165, (float)-0.079913, (float)-0.317163, (float)-0.034097, (float)-0.169743, (float)-0.122081, (float)-0.309284, (float)-0.122529, (float)-0.028297, (float)-0.151813, (float)-0.093257, (float)-0.283448, (float)-0.003030, (float)-0.035894, (float)0.003011, (float)-0.046019, (float)-0.085464, (float)-0.038165, (float)-0.017352, (float)-0.082586, (float)-0.150925, (float)-0.176884, (float)-0.150072, (float)0.001534, (float)-0.087669, (float)-0.033261, (float)-0.254497, (float)-0.012980, (float)-0.046881, (float)-0.088381, (float)-0.089857, (float)-0.191141, (float)-0.131301, (float)-0.035002, (float)-0.114926, (float)-0.188881, (float)-0.040911, (float)-0.381905, (float)-0.089706, (float)-0.170198, (float)-0.154573, (float)0.030685, (float)-0.040941, (float)-0.036983, (float)-0.069053, (float)-0.042029, (float)0.053512, (float)-0.131176, (float)-0.119942, (float)-0.057783, (float)-0.054637, (float)-0.123350, (float)-0.116191, (float)-0.123229, (float)-0.252074, (float)-0.041003, (float)-0.105637, (float)-0.052183, (float)-0.241468, (float)-0.094696, (float)-0.156377, (float)-0.122982};	// L3923
  #pragma HLS resource variable=v3423 core=ram_t2p_bram

  float v3424[256] = {(float)-0.016245, (float)-0.203263, (float)0.029385, (float)-0.169664, (float)-0.183951, (float)-0.030897, (float)-0.203861, (float)-0.142588, (float)-0.044317, (float)-0.088597, (float)-0.064677, (float)-0.096849, (float)-0.037978, (float)-0.207329, (float)-0.306056, (float)0.144284, (float)-0.307884, (float)-0.123179, (float)-0.162712, (float)-0.098041, (float)-0.247118, (float)-0.283653, (float)-0.120123, (float)-0.289314, (float)-0.230311, (float)-0.356210, (float)-0.082497, (float)-0.348327, (float)0.070732, (float)-0.132077, (float)-0.107421, (float)-0.145144, (float)0.023506, (float)0.022505, (float)-0.188479, (float)-0.250710, (float)-0.246110, (float)0.063148, (float)-0.002294, (float)-0.120950, (float)-0.258070, (float)-0.164026, (float)-0.017193, (float)-0.114291, (float)-0.209634, (float)-0.015776, (float)0.012847, (float)-0.133163, (float)-0.313940, (float)-0.229356, (float)-0.152731, (float)-0.350311, (float)0.208646, (float)0.078491, (float)-0.159745, (float)-0.198988, (float)0.034600, (float)0.038818, (float)-0.126883, (float)0.101943, (float)0.098149, (float)-0.038957, (float)-0.253741, (float)-0.135554, (float)-0.179615, (float)-0.242240, (float)-0.451653, (float)-0.312450, (float)-0.017678, (float)-0.261494, (float)-0.156722, (float)0.021168, (float)-0.075348, (float)-0.142621, (float)-0.278794, (float)0.006175, (float)-0.189471, (float)-0.232739, (float)-0.129768, (float)-0.120019, (float)-0.191670, (float)-0.098714, (float)-0.191551, (float)-0.166586, (float)-0.272923, (float)0.128678, (float)-0.462026, (float)-0.225932, (float)-0.227040, (float)0.193910, (float)0.023026, (float)-0.330260, (float)-0.320158, (float)-0.129240, (float)-0.071557, (float)0.004831, (float)-0.257935, (float)-0.011567, (float)-0.055650, (float)-0.122925, (float)-0.480394, (float)-0.235115, (float)-0.136698, (float)-0.057786, (float)-0.053713, (float)-0.274276, (float)-0.082687, (float)-0.192167, (float)-0.348090, (float)-0.035842, (float)-0.109360, (float)0.013808, (float)-0.188810, (float)-0.259163, (float)-0.329339, (float)-0.082037, (float)-0.183938, (float)-0.163550, (float)-0.316315, (float)-0.024608, (float)-0.166662, (float)-0.165285, (float)-0.307553, (float)-0.222890, (float)-0.183395, (float)-0.053620, (float)-0.062063, (float)-0.175165, (float)-0.524255, (float)-0.193342, (float)-0.111859, (float)-0.228255, (float)-0.043679, (float)-0.177694, (float)-0.130007, (float)-0.251926, (float)-0.045575, (float)-0.630507, (float)-0.136383, (float)-0.213837, (float)0.040575, (float)-0.528653, (float)-0.201392, (float)-0.144229, (float)-0.192954, (float)-0.303300, (float)0.103006, (float)-0.149919, (float)-0.229681, (float)-0.530064, (float)-0.254274, (float)-0.041712, (float)0.042858, (float)-0.321792, (float)-0.161135, (float)-0.256175, (float)-0.118742, (float)-0.100078, (float)0.022491, (float)0.099644, (float)-0.213848, (float)-0.201887, (float)0.080756, (float)-0.012101, (float)-0.236381, (float)-0.324670, (float)-0.148193, (float)-0.484607, (float)-0.344871, (float)-0.136469, (float)-0.666387, (float)0.041802, (float)-0.280741, (float)-0.096090, (float)-0.237802, (float)-0.183354, (float)-0.189028, (float)-0.037668, (float)-0.305603, (float)-0.184272, (float)-0.135655, (float)-0.303846, (float)-0.267961, (float)-0.414308, (float)-0.263275, (float)-0.174954, (float)-0.185577, (float)-0.240538, (float)-0.108238, (float)-0.225023, (float)-0.126790, (float)-0.109350, (float)0.059438, (float)-0.141892, (float)-0.117792, (float)-0.160157, (float)-0.032850, (float)-0.019429, (float)-0.198540, (float)0.046975, (float)-0.188651, (float)-0.277640, (float)-0.093020, (float)-0.409246, (float)-0.337848, (float)-0.725179, (float)0.026007, (float)-0.182911, (float)0.056122, (float)-0.222686, (float)-0.002551, (float)-0.321779, (float)-0.009302, (float)-0.284284, (float)-0.512142, (float)-0.233748, (float)-0.083571, (float)-0.081786, (float)-0.129600, (float)-0.209036, (float)0.016879, (float)-0.189866, (float)-0.189163, (float)-0.307490, (float)-0.310809, (float)-0.298639, (float)-0.471174, (float)-0.182340, (float)-0.189275, (float)-0.313145, (float)-0.087605, (float)-0.116606, (float)-0.299515, (float)-0.083107, (float)-0.342664, (float)-0.077193, (float)-0.145986, (float)-0.161113, (float)0.020350, (float)-0.062725, (float)-0.060997, (float)-0.257375, (float)-0.138255, (float)0.046971, (float)-0.030197, (float)-0.163756, (float)-0.332289, (float)-0.174150, (float)-0.630677, (float)-0.077151, (float)-0.212325, (float)-0.155853, (float)-0.045911, (float)-0.241584, (float)-0.014343, (float)-0.207857};	// L3924
  #pragma HLS resource variable=v3424 core=ram_t2p_bram

  float v3425[256] = {(float)0.197083, (float)0.177063, (float)0.130256, (float)0.199495, (float)0.183903, (float)0.093385, (float)0.233283, (float)0.223625, (float)0.165396, (float)0.127999, (float)0.084225, (float)0.108512, (float)0.316751, (float)0.203194, (float)0.324606, (float)0.218361, (float)0.320812, (float)0.282439, (float)0.340799, (float)0.333867, (float)0.330713, (float)0.557144, (float)0.282054, (float)0.308072, (float)0.211382, (float)0.297131, (float)0.236138, (float)0.549991, (float)0.122082, (float)0.338117, (float)0.152827, (float)0.154387, (float)0.198245, (float)0.058198, (float)0.181202, (float)0.248904, (float)0.195430, (float)0.070545, (float)0.091757, (float)0.132818, (float)0.261582, (float)0.201262, (float)0.072013, (float)0.157323, (float)0.191896, (float)0.081277, (float)0.116971, (float)0.250426, (float)0.286264, (float)0.303238, (float)0.147590, (float)0.369600, (float)0.186970, (float)0.209749, (float)0.190654, (float)0.236384, (float)0.164152, (float)0.107897, (float)0.253063, (float)0.170326, (float)0.126562, (float)0.081425, (float)0.240692, (float)0.260912, (float)0.270503, (float)0.212843, (float)0.500701, (float)0.237510, (float)0.080245, (float)0.289631, (float)0.177601, (float)0.088677, (float)0.109387, (float)0.183369, (float)0.281203, (float)0.197087, (float)0.202083, (float)0.344269, (float)0.141080, (float)0.136165, (float)0.267635, (float)0.161836, (float)0.272281, (float)0.272662, (float)0.252797, (float)0.098169, (float)0.470705, (float)0.223911, (float)0.364941, (float)0.198725, (float)0.081468, (float)0.254280, (float)0.332248, (float)0.156143, (float)0.233612, (float)0.129416, (float)0.257032, (float)0.169978, (float)0.137449, (float)0.221491, (float)0.501533, (float)0.313217, (float)0.148703, (float)0.117356, (float)0.091607, (float)0.213016, (float)0.139292, (float)0.305655, (float)0.563450, (float)0.101800, (float)0.099411, (float)0.049198, (float)0.442658, (float)0.314225, (float)0.400163, (float)0.133425, (float)0.217355, (float)0.552157, (float)0.280600, (float)0.278423, (float)0.433314, (float)0.260157, (float)0.378775, (float)0.182663, (float)0.266373, (float)0.107714, (float)0.300150, (float)0.242794, (float)0.513047, (float)0.082872, (float)0.125387, (float)0.199579, (float)0.145117, (float)0.225259, (float)0.146747, (float)0.371155, (float)0.079381, (float)0.542518, (float)0.205773, (float)0.210267, (float)0.128751, (float)0.499309, (float)0.181521, (float)0.184518, (float)0.415396, (float)0.381719, (float)0.205408, (float)0.220500, (float)0.147142, (float)0.496439, (float)0.420158, (float)0.080098, (float)0.062257, (float)0.353560, (float)0.276026, (float)0.383971, (float)0.163176, (float)0.140242, (float)0.267423, (float)0.084425, (float)0.230524, (float)0.225906, (float)0.214586, (float)0.418085, (float)0.282106, (float)0.292584, (float)0.341571, (float)0.464038, (float)0.302510, (float)0.373204, (float)0.587109, (float)0.061605, (float)0.279668, (float)0.304214, (float)0.217345, (float)0.354958, (float)0.209598, (float)0.244930, (float)0.342777, (float)0.286756, (float)0.354334, (float)0.466692, (float)0.322005, (float)0.380490, (float)0.263234, (float)0.215985, (float)0.192379, (float)0.407367, (float)0.496558, (float)0.362302, (float)0.166981, (float)0.132087, (float)0.237372, (float)0.211823, (float)0.152241, (float)0.166782, (float)0.383586, (float)0.098273, (float)0.372934, (float)0.394324, (float)0.435339, (float)0.226984, (float)0.150788, (float)0.313302, (float)0.384988, (float)0.577444, (float)0.189226, (float)0.282158, (float)0.090682, (float)0.236430, (float)0.096440, (float)0.235968, (float)0.069868, (float)0.293818, (float)0.510049, (float)0.334802, (float)0.233938, (float)0.114513, (float)0.215459, (float)0.226613, (float)0.282874, (float)0.234118, (float)0.189083, (float)0.290554, (float)0.268075, (float)0.387578, (float)0.391480, (float)0.184427, (float)0.188864, (float)0.440469, (float)0.140498, (float)0.346018, (float)0.272350, (float)0.256695, (float)0.278544, (float)0.114821, (float)0.160654, (float)0.175425, (float)0.088254, (float)0.164943, (float)0.126761, (float)0.235614, (float)0.281092, (float)0.076576, (float)0.142417, (float)0.168344, (float)0.397862, (float)0.268495, (float)0.638344, (float)0.108743, (float)0.318036, (float)0.176041, (float)0.363429, (float)0.261512, (float)0.199873, (float)0.254116};	// L3925
  #pragma HLS resource variable=v3425 core=ram_t2p_bram

  float v3426[512] = {(float)0.102969, (float)0.099928, (float)0.127914, (float)0.099059, (float)0.100430, (float)0.121449, (float)0.162097, (float)0.100043, (float)0.159959, (float)0.122664, (float)0.105262, (float)0.142098, (float)0.102029, (float)0.132221, (float)0.100326, (float)0.106438, (float)0.136585, (float)0.124613, (float)0.130006, (float)0.198400, (float)0.116320, (float)0.149600, (float)0.162998, (float)0.126596, (float)0.106612, (float)0.121217, (float)0.106790, (float)0.112300, (float)0.161500, (float)0.165558, (float)0.130312, (float)0.143827, (float)0.114844, (float)0.123655, (float)0.116569, (float)0.115679, (float)0.192961, (float)0.104196, (float)0.090405, (float)0.095586, (float)0.106340, (float)0.084078, (float)0.116300, (float)0.134858, (float)0.117626, (float)0.164849, (float)0.111461, (float)0.122224, (float)0.126947, (float)0.188003, (float)0.109027, (float)0.127952, (float)0.121110, (float)0.144697, (float)0.085655, (float)0.120671, (float)0.112938, (float)0.120395, (float)0.130486, (float)0.117947, (float)0.116683, (float)0.245552, (float)0.202163, (float)0.097515, (float)0.126310, (float)0.104477, (float)0.208212, (float)0.083050, (float)0.103759, (float)0.123070, (float)0.112443, (float)0.110532, (float)0.146693, (float)0.133561, (float)0.128758, (float)0.110741, (float)0.136630, (float)0.181454, (float)0.128223, (float)0.130604, (float)0.119954, (float)0.105619, (float)0.118920, (float)0.120361, (float)0.111300, (float)0.098627, (float)0.103261, (float)0.122012, (float)0.117761, (float)0.149702, (float)0.111549, (float)0.113045, (float)0.120670, (float)0.137210, (float)0.098998, (float)0.146081, (float)0.098501, (float)0.118389, (float)0.150684, (float)0.128408, (float)0.108534, (float)0.140632, (float)0.175394, (float)0.109470, (float)0.097672, (float)0.094074, (float)0.179887, (float)0.107252, (float)0.079623, (float)0.115265, (float)0.118862, (float)0.145173, (float)0.109861, (float)0.136122, (float)0.259220, (float)0.080983, (float)0.109804, (float)0.157304, (float)0.127159, (float)0.183668, (float)0.136026, (float)0.095853, (float)0.140319, (float)0.130310, (float)0.134171, (float)0.096452, (float)0.128541, (float)0.221489, (float)0.124658, (float)0.118763, (float)0.120368, (float)0.116297, (float)0.100566, (float)0.171091, (float)0.103555, (float)0.121105, (float)0.136119, (float)0.119264, (float)0.097030, (float)0.110434, (float)0.133113, (float)0.124958, (float)0.116818, (float)0.088458, (float)0.116332, (float)0.089325, (float)0.168050, (float)0.093430, (float)0.124383, (float)0.118799, (float)0.163994, (float)0.108056, (float)0.131044, (float)0.123868, (float)0.126921, (float)0.097171, (float)0.121111, (float)0.104287, (float)0.229385, (float)0.120757, (float)0.101777, (float)0.114841, (float)0.147212, (float)0.097454, (float)0.130895, (float)0.131667, (float)0.191380, (float)0.108085, (float)0.149058, (float)0.113174, (float)0.099293, (float)0.116667, (float)0.147313, (float)0.120351, (float)0.101188, (float)0.120051, (float)0.106186, (float)0.119047, (float)0.133610, (float)0.120395, (float)0.141070, (float)0.181610, (float)0.113411, (float)0.111433, (float)0.173537, (float)0.177542, (float)0.121546, (float)0.138897, (float)0.098290, (float)0.139586, (float)0.120764, (float)0.106274, (float)0.113612, (float)0.124812, (float)0.263905, (float)0.148459, (float)0.107708, (float)0.106114, (float)0.155084, (float)0.172677, (float)0.125083, (float)0.136005, (float)0.121585, (float)0.152622, (float)0.110289, (float)0.104515, (float)0.085658, (float)0.110004, (float)0.119019, (float)0.125474, (float)0.158541, (float)0.126997, (float)0.132823, (float)0.125616, (float)0.107881, (float)0.128350, (float)0.071472, (float)0.116252, (float)0.137530, (float)0.082056, (float)0.146145, (float)0.121004, (float)0.122692, (float)0.114094, (float)0.107170, (float)0.149235, (float)0.120269, (float)0.208620, (float)0.113120, (float)0.074732, (float)0.138501, (float)0.149575, (float)0.128722, (float)0.099209, (float)0.133543, (float)0.151521, (float)0.186073, (float)0.113070, (float)0.164859, (float)0.093683, (float)0.136206, (float)0.095898, (float)0.087026, (float)0.118172, (float)0.144881, (float)0.157680, (float)0.125008, (float)0.129811, (float)0.125173, (float)0.101626, (float)0.178735, (float)0.113597, (float)0.120398, (float)0.112605, (float)0.129529, (float)0.137083, (float)0.113586, (float)0.146883, (float)0.160778, (float)0.099425, (float)0.234304, (float)0.139662, (float)0.114545, (float)0.133579, (float)0.142977, (float)0.112115, (float)0.138883, (float)0.163318, (float)0.105025, (float)0.153779, (float)0.109543, (float)0.113140, (float)0.100522, (float)0.141127, (float)0.113207, (float)0.102092, (float)0.139891, (float)0.104518, (float)0.122020, (float)0.130258, (float)0.154121, (float)0.142526, (float)0.121724, (float)0.094121, (float)0.230927, (float)0.099665, (float)0.092804, (float)0.126329, (float)0.125531, (float)0.088600, (float)0.124690, (float)0.129280, (float)0.107645, (float)0.141442, (float)0.093475, (float)0.137658, (float)0.166226, (float)0.145095, (float)0.105080, (float)0.111591, (float)0.132086, (float)0.189528, (float)0.136962, (float)0.134989, (float)0.128502, (float)0.095144, (float)0.184310, (float)0.213431, (float)0.153420, (float)0.175178, (float)0.172102, (float)0.098957, (float)0.151034, (float)0.105176, (float)0.136074, (float)0.146286, (float)0.160968, (float)0.159597, (float)0.115675, (float)0.088342, (float)0.112243, (float)0.118787, (float)0.118149, (float)0.135604, (float)0.130526, (float)0.107419, (float)0.109284, (float)0.118020, (float)0.096058, (float)0.221776, (float)0.137604, (float)0.115087, (float)0.137037, (float)0.129592, (float)0.100529, (float)0.091615, (float)0.112613, (float)0.092674, (float)0.143197, (float)0.097747, (float)0.123528, (float)0.142610, (float)0.138156, (float)0.138650, (float)0.117726, (float)0.131527, (float)0.128811, (float)0.119234, (float)0.137690, (float)0.136844, (float)0.146846, (float)0.108803, (float)0.131052, (float)0.121582, (float)0.107816, (float)0.123804, (float)0.137003, (float)0.105249, (float)0.188565, (float)0.169428, (float)0.132624, (float)0.131426, (float)0.108044, (float)0.109634, (float)0.121790, (float)0.172380, (float)0.130916, (float)0.095925, (float)0.140335, (float)0.123459, (float)0.095284, (float)0.156764, (float)0.151655, (float)0.119709, (float)0.245863, (float)0.125804, (float)0.096682, (float)0.093338, (float)0.062390, (float)0.131068, (float)0.090356, (float)0.129776, (float)0.114087, (float)0.110646, (float)0.107882, (float)0.111276, (float)0.123109, (float)0.141226, (float)0.116038, (float)0.156117, (float)0.267777, (float)0.161008, (float)0.117126, (float)0.198059, (float)0.123219, (float)0.120907, (float)0.102412, (float)0.102818, (float)0.136985, (float)0.079203, (float)0.124966, (float)0.140690, (float)0.142933, (float)0.125776, (float)0.113467, (float)0.114388, (float)0.118252, (float)0.111282, (float)0.190332, (float)0.106768, (float)0.136849, (float)0.118526, (float)0.113189, (float)0.118171, (float)0.105632, (float)0.092010, (float)0.104149, (float)0.152369, (float)0.152479, (float)0.135482, (float)0.233237, (float)0.143558, (float)0.149689, (float)0.196908, (float)0.162862, (float)0.168064, (float)0.112899, (float)0.138323, (float)0.148283, (float)0.118987, (float)0.135336, (float)0.118192, (float)0.120108, (float)0.100727, (float)0.114601, (float)0.177554, (float)0.111874, (float)0.109587, (float)0.111309, (float)0.158084, (float)0.098303, (float)0.124443, (float)0.145842, (float)0.113721, (float)0.137052, (float)0.180867, (float)0.213040, (float)0.137236, (float)0.093852, (float)0.104700, (float)0.131116, (float)0.191763, (float)0.123431, (float)0.093901, (float)0.121040, (float)0.138561, (float)0.090314, (float)0.117834, (float)0.160101, (float)0.157086, (float)0.146179, (float)0.153154, (float)0.296101, (float)0.097116, (float)0.138284, (float)0.116281, (float)0.093932, (float)0.117921, (float)0.106596, (float)0.147237, (float)0.130546, (float)0.143004, (float)0.119795, (float)0.130636, (float)0.182460, (float)0.133858, (float)0.104615, (float)0.070947, (float)0.158399, (float)0.100164, (float)0.149495, (float)0.160381, (float)0.142217, (float)0.114640, (float)0.090272, (float)0.089960, (float)0.122854, (float)0.156734, (float)0.126246, (float)0.116253, (float)0.150747, (float)0.102566, (float)0.122289, (float)0.140423, (float)0.136450, (float)0.118191, (float)0.092278, (float)0.118940, (float)0.109218, (float)0.106868, (float)0.123438, (float)0.233763, (float)0.122934, (float)0.111006, (float)0.098920, (float)0.113283, (float)0.093151, (float)0.158288, (float)0.123618, (float)0.139493, (float)0.110941, (float)0.105699};	// L3926
  #pragma HLS resource variable=v3426 core=ram_t2p_bram

  float v3427[512] = {(float)-0.112399, (float)-0.116439, (float)-0.129277, (float)-0.418715, (float)-0.384113, (float)-0.407468, (float)-0.531776, (float)-0.182379, (float)-0.757418, (float)-0.839405, (float)-0.191102, (float)-0.269664, (float)-0.438940, (float)-0.266877, (float)-0.433000, (float)-0.476784, (float)-0.496500, (float)-0.473768, (float)-0.141513, (float)-0.424507, (float)-0.328492, (float)-0.526421, (float)-0.812645, (float)-0.401106, (float)-0.314249, (float)-0.458406, (float)-0.166297, (float)-0.485648, (float)-0.343087, (float)-0.518310, (float)-0.432761, (float)-0.672563, (float)-0.433207, (float)-0.405020, (float)-0.183107, (float)-0.453480, (float)-1.013503, (float)-0.009113, (float)-0.477304, (float)-0.384145, (float)-0.501301, (float)-0.742657, (float)-0.499172, (float)-0.586968, (float)-0.360770, (float)-0.475071, (float)-0.608605, (float)-0.376767, (float)-0.692520, (float)-1.217636, (float)-0.516137, (float)-0.412293, (float)-0.321387, (float)-0.153690, (float)-0.332965, (float)-0.330429, (float)-0.437467, (float)-0.581860, (float)-0.476988, (float)-0.594429, (float)-0.250872, (float)0.262500, (float)0.104237, (float)-0.336077, (float)-0.432966, (float)-0.400236, (float)-0.367752, (float)-0.366686, (float)-0.219613, (float)-0.646535, (float)-0.588735, (float)-0.385367, (float)-0.330557, (float)-0.378576, (float)-0.231806, (float)-0.097445, (float)-1.031814, (float)-0.880079, (float)-0.327233, (float)-0.494126, (float)-0.603831, (float)-0.408300, (float)-0.125906, (float)-0.115601, (float)-0.178602, (float)-0.555274, (float)-0.710459, (float)-0.266660, (float)-0.167976, (float)-0.007352, (float)-0.246322, (float)-0.336113, (float)0.157182, (float)-0.601864, (float)-0.468605, (float)-0.357834, (float)-0.581191, (float)-0.211286, (float)-0.359057, (float)-0.529334, (float)-0.772094, (float)-0.584602, (float)-0.112900, (float)-0.413537, (float)-0.496495, (float)-0.675932, (float)-0.407701, (float)-0.489354, (float)-0.332871, (float)-0.368918, (float)-0.013880, (float)-0.110656, (float)-0.328942, (float)0.049362, (float)-0.104944, (float)0.032464, (float)-0.214452, (float)-0.058529, (float)-0.365958, (float)-0.295750, (float)-0.087778, (float)-0.647347, (float)-0.895826, (float)-0.520704, (float)-0.475582, (float)-0.335130, (float)-0.542062, (float)0.092361, (float)-0.920866, (float)0.061003, (float)0.073713, (float)-0.368023, (float)-0.701119, (float)-0.591840, (float)-0.508094, (float)-0.459119, (float)-0.515429, (float)-0.318958, (float)-0.623240, (float)-0.551153, (float)-0.481386, (float)-0.430723, (float)-0.291835, (float)-0.212256, (float)-0.218935, (float)-0.402839, (float)-0.156959, (float)-0.109874, (float)-0.391399, (float)-0.388566, (float)-0.150173, (float)-0.452671, (float)-0.167128, (float)-0.202127, (float)-0.532084, (float)-0.264351, (float)-0.520682, (float)-0.553412, (float)-0.551886, (float)-0.306945, (float)-0.232572, (float)-0.570877, (float)-0.616357, (float)-0.011549, (float)-0.664122, (float)-0.572931, (float)-0.274999, (float)-0.572013, (float)-0.768450, (float)-0.436126, (float)-0.352616, (float)-0.042565, (float)-0.134978, (float)-0.883548, (float)-0.321707, (float)-0.170556, (float)-0.428356, (float)-0.449698, (float)-0.726382, (float)-0.958914, (float)-0.343854, (float)-0.679991, (float)-0.451969, (float)-0.545850, (float)-0.299316, (float)-0.485377, (float)-0.141496, (float)-0.028968, (float)-0.272937, (float)-0.166597, (float)-0.234621, (float)-0.539686, (float)-0.472434, (float)-0.560607, (float)-0.564710, (float)-0.361384, (float)-0.515817, (float)-0.272838, (float)-0.043191, (float)-0.942049, (float)-0.528378, (float)-0.623554, (float)-0.383542, (float)-0.682523, (float)-0.534687, (float)-0.412121, (float)-0.265564, (float)-0.576051, (float)-0.337885, (float)-0.767888, (float)-0.833459, (float)-0.563115, (float)-0.371247, (float)-0.016989, (float)-0.509873, (float)-0.519588, (float)-0.261680, (float)-0.563200, (float)-0.631046, (float)-0.524374, (float)-0.219218, (float)-0.424097, (float)-0.213002, (float)-0.276040, (float)-0.177244, (float)-0.571938, (float)-0.403344, (float)-0.787354, (float)-0.322614, (float)-0.267134, (float)-0.342526, (float)-0.710991, (float)-0.442178, (float)-0.131834, (float)-0.384127, (float)-0.405017, (float)-0.510206, (float)-0.486478, (float)-0.541453, (float)-0.479047, (float)-0.486675, (float)-0.248170, (float)-0.534675, (float)0.137316, (float)-0.928146, (float)-0.379055, (float)-0.039265, (float)-0.650038, (float)-0.068735, (float)-0.255033, (float)-0.783301, (float)-0.190591, (float)0.069200, (float)-0.520266, (float)0.110204, (float)-0.469053, (float)-0.216485, (float)-0.405797, (float)-0.525246, (float)-0.548900, (float)-0.224316, (float)-0.891227, (float)-0.575327, (float)-0.378748, (float)-0.466015, (float)-0.416706, (float)-0.794753, (float)-0.221377, (float)0.216941, (float)-0.323023, (float)-0.571629, (float)-0.452323, (float)-0.223508, (float)-0.535418, (float)-0.618674, (float)-0.640286, (float)-0.577882, (float)-0.697379, (float)-0.453077, (float)-0.455918, (float)-0.674158, (float)-0.865837, (float)-0.641282, (float)-0.309825, (float)0.412202, (float)-0.481322, (float)-0.526779, (float)0.134130, (float)-0.112282, (float)-0.386807, (float)-0.668274, (float)-0.402017, (float)-0.470466, (float)-0.526314, (float)-0.491210, (float)-0.434492, (float)0.067518, (float)-0.731700, (float)-0.346691, (float)-0.475672, (float)-0.484478, (float)-0.166603, (float)-0.554598, (float)-0.287519, (float)-0.557369, (float)-0.292941, (float)-0.917794, (float)0.093173, (float)-0.347311, (float)-0.265892, (float)-0.870023, (float)-0.414276, (float)-0.669144, (float)-0.389632, (float)-0.399296, (float)-0.358292, (float)-0.964411, (float)-0.541634, (float)-0.311702, (float)0.178528, (float)-0.497123, (float)-0.843553, (float)-0.628203, (float)-0.511303, (float)-0.099860, (float)-0.383422, (float)-0.433000, (float)-0.408400, (float)-0.426940, (float)-0.566965, (float)-0.559916, (float)0.200167, (float)-0.358192, (float)-0.762071, (float)-0.425684, (float)-0.474864, (float)-0.267235, (float)-0.444904, (float)-0.463114, (float)-0.505526, (float)-0.321621, (float)-0.542648, (float)-0.261515, (float)-0.569461, (float)-0.298140, (float)-0.844004, (float)-0.623715, (float)-0.664250, (float)-0.469105, (float)-0.932553, (float)-0.612922, (float)0.098774, (float)-0.838134, (float)-0.273548, (float)-0.229909, (float)-0.588052, (float)-0.210117, (float)-0.051954, (float)-0.821773, (float)-0.846684, (float)-0.161722, (float)-0.224413, (float)-0.436564, (float)-0.120466, (float)-0.575075, (float)-0.679570, (float)-0.405034, (float)-0.067879, (float)-0.840527, (float)-0.454655, (float)-0.170813, (float)-0.048041, (float)-0.158716, (float)-0.373385, (float)-0.889646, (float)0.082504, (float)-0.759268, (float)-0.459439, (float)-0.267621, (float)-0.114515, (float)-0.302276, (float)-0.245612, (float)-0.364465, (float)-0.354500, (float)-0.824092, (float)-0.173027, (float)-0.257509, (float)-0.010339, (float)-0.393497, (float)-0.703393, (float)-0.291880, (float)-0.279310, (float)-0.396569, (float)-0.712801, (float)-0.521117, (float)-0.718786, (float)-0.407343, (float)-0.281441, (float)-0.229254, (float)-0.452871, (float)-0.677881, (float)-0.093355, (float)-0.327243, (float)-0.363757, (float)-0.204797, (float)-0.272021, (float)-0.368346, (float)-0.333415, (float)-0.640944, (float)-0.280670, (float)-0.424596, (float)-0.068290, (float)-0.343726, (float)-0.146595, (float)-0.625573, (float)-0.431924, (float)-0.185842, (float)-0.181652, (float)-0.767884, (float)-0.335338, (float)-0.958843, (float)-0.195242, (float)-0.200604, (float)-0.128025, (float)-0.404694, (float)-0.223926, (float)-0.624653, (float)-0.342209, (float)-0.559487, (float)-0.702609, (float)0.035447, (float)-0.581416, (float)-0.738228, (float)-0.390357, (float)-0.340927, (float)-0.863017, (float)-0.345280, (float)-0.156938, (float)-0.671733, (float)-0.521623, (float)-0.232921, (float)-0.356420, (float)-0.758426, (float)-0.012366, (float)-0.539764, (float)-0.770848, (float)-0.335878, (float)-0.290856, (float)-0.313259, (float)-0.339998, (float)-0.562364, (float)-0.549299, (float)-0.463665, (float)-0.402154, (float)-0.357964, (float)-0.332480, (float)-0.338387, (float)-0.227683, (float)-0.269677, (float)-0.290673, (float)-0.216382, (float)-0.248912, (float)-0.057300, (float)-0.373486, (float)-0.399569, (float)-0.345078, (float)-0.464810, (float)-0.714298, (float)-0.206166, (float)-0.251282, (float)-0.446420, (float)-0.262376, (float)-0.161453, (float)-0.309853, (float)-0.747986, (float)-0.775115, (float)-0.338349, (float)-0.287491, (float)-0.597623, (float)-0.375151, (float)-0.944747, (float)0.977841, (float)-0.525900, (float)-0.011899, (float)-0.312199, (float)-0.380173, (float)-0.769012, (float)-0.353425, (float)-0.326794, (float)-0.388225, (float)-0.487052, (float)-0.440380, (float)-0.677326, (float)-0.491474, (float)-0.489073, (float)-0.331316, (float)-0.649739, (float)-0.530273, (float)-0.619254, (float)-0.806289, (float)-0.435616, (float)-0.046601, (float)-0.677238, (float)-0.735951, (float)-0.638833, (float)-0.419857, (float)-0.457520, (float)-0.577571, (float)-0.564816, (float)-0.250951, (float)-0.275274, (float)-0.486037};	// L3927
  #pragma HLS resource variable=v3427 core=ram_t2p_bram

  float v3428[512] = {(float)-0.198635, (float)-0.159280, (float)-0.205440, (float)-0.159751, (float)-0.126783, (float)-0.322602, (float)-0.159702, (float)-0.347721, (float)-0.249661, (float)-0.273007, (float)-0.231932, (float)-0.028604, (float)-0.189897, (float)-0.281265, (float)-0.173262, (float)-0.241200, (float)-0.371220, (float)-0.274710, (float)-0.205253, (float)-0.258500, (float)-0.153542, (float)-0.274793, (float)-0.324058, (float)-0.252472, (float)-0.190612, (float)-0.225170, (float)-0.343567, (float)-0.220154, (float)-0.166400, (float)-0.271596, (float)-0.191981, (float)-0.339946, (float)-0.202635, (float)-0.297159, (float)-0.261564, (float)-0.223832, (float)-0.248628, (float)-0.260583, (float)-0.089288, (float)-0.357226, (float)-0.128296, (float)-0.258322, (float)-0.244954, (float)-0.152284, (float)-0.316499, (float)-0.144499, (float)-0.252168, (float)-0.196256, (float)-0.179368, (float)-0.107088, (float)-0.166188, (float)-0.205255, (float)-0.252968, (float)-0.144727, (float)-0.251718, (float)-0.206196, (float)-0.281670, (float)-0.337613, (float)-0.138244, (float)-0.238891, (float)-0.255711, (float)-0.015554, (float)-0.216885, (float)-0.176316, (float)-0.148643, (float)-0.212185, (float)-0.200180, (float)-0.071553, (float)-0.208908, (float)-0.357989, (float)-0.258831, (float)-0.359925, (float)-0.152776, (float)-0.210741, (float)-0.292484, (float)-0.185539, (float)-0.397034, (float)-0.125722, (float)-0.257364, (float)-0.241233, (float)-0.086334, (float)-0.306480, (float)-0.270061, (float)-0.337952, (float)-0.248466, (float)-0.193549, (float)-0.298651, (float)-0.227864, (float)-0.359965, (float)-0.276432, (float)-0.248049, (float)-0.120810, (float)-0.337792, (float)-0.266138, (float)-0.167728, (float)-0.247002, (float)-0.215158, (float)-0.259118, (float)-0.193646, (float)-0.154288, (float)-0.411724, (float)-0.156958, (float)-0.237157, (float)-0.299713, (float)-0.212358, (float)-0.203400, (float)-0.184828, (float)-0.306988, (float)-0.343761, (float)-0.183858, (float)-0.193655, (float)-0.091612, (float)-0.233758, (float)-0.355788, (float)-0.196726, (float)-0.330299, (float)-0.139834, (float)-0.217654, (float)-0.166528, (float)-0.185734, (float)-0.311453, (float)-0.104899, (float)-0.422929, (float)-0.240815, (float)-0.132040, (float)-0.163091, (float)-0.337840, (float)-0.330003, (float)-0.318321, (float)-0.226779, (float)-0.278663, (float)-0.194961, (float)-0.194987, (float)-0.146256, (float)-0.243719, (float)-0.229727, (float)-0.128243, (float)-0.216404, (float)-0.117926, (float)-0.243669, (float)-0.261094, (float)-0.265609, (float)-0.194772, (float)-0.120835, (float)-0.166772, (float)-0.135053, (float)-0.271304, (float)-0.056007, (float)-0.224252, (float)-0.131812, (float)-0.235599, (float)-0.272038, (float)-0.205063, (float)-0.173640, (float)-0.289066, (float)-0.262726, (float)-0.335823, (float)-0.177874, (float)-0.230911, (float)-0.147696, (float)-0.268536, (float)-0.188245, (float)-0.262892, (float)-0.198329, (float)-0.352163, (float)-0.190481, (float)-0.277790, (float)-0.339548, (float)-0.289472, (float)-0.224038, (float)-0.114972, (float)-0.246249, (float)-0.242611, (float)-0.258111, (float)-0.313325, (float)-0.231534, (float)-0.227076, (float)-0.207734, (float)-0.210885, (float)-0.137085, (float)-0.132296, (float)-0.252940, (float)-0.171612, (float)-0.253187, (float)-0.227680, (float)-0.208407, (float)-0.180303, (float)-0.186834, (float)-0.240367, (float)-0.216608, (float)-0.219689, (float)-0.287034, (float)-0.306171, (float)-0.150719, (float)-0.105436, (float)-0.219935, (float)-0.241527, (float)-0.331005, (float)-0.269987, (float)-0.156821, (float)-0.144899, (float)-0.261037, (float)-0.182827, (float)-0.264791, (float)-0.313404, (float)-0.293743, (float)-0.268707, (float)-0.211493, (float)-0.216372, (float)-0.452181, (float)-0.299851, (float)-0.303153, (float)-0.229169, (float)-0.309911, (float)-0.264202, (float)-0.269489, (float)-0.144062, (float)-0.167143, (float)-0.156979, (float)-0.141488, (float)-0.222238, (float)-0.173627, (float)-0.148146, (float)-0.257285, (float)-0.206039, (float)-0.170317, (float)-0.235997, (float)-0.176952, (float)-0.213227, (float)-0.201556, (float)-0.300095, (float)-0.151790, (float)-0.208563, (float)-0.280471, (float)-0.269795, (float)-0.229193, (float)-0.129287, (float)-0.251390, (float)-0.260037, (float)-0.245432, (float)-0.174379, (float)-0.102882, (float)-0.167894, (float)-0.235278, (float)-0.200725, (float)-0.336331, (float)-0.164050, (float)-0.242959, (float)-0.169863, (float)-0.169697, (float)-0.183738, (float)-0.162455, (float)-0.241503, (float)-0.268742, (float)-0.230482, (float)-0.202916, (float)-0.220905, (float)-0.224020, (float)-0.267481, (float)-0.323331, (float)0.146213, (float)-0.477669, (float)-0.237640, (float)-0.148853, (float)-0.146244, (float)-0.305496, (float)-0.223361, (float)-0.169727, (float)-0.195171, (float)-0.213050, (float)-0.233987, (float)-0.203905, (float)-0.305400, (float)-0.259589, (float)-0.347015, (float)-0.217554, (float)-0.270612, (float)-0.289733, (float)-0.172889, (float)-0.230001, (float)-0.106558, (float)-0.355581, (float)-0.291246, (float)-0.177713, (float)-0.200747, (float)-0.169918, (float)-0.300875, (float)-0.304572, (float)-0.169294, (float)-0.260249, (float)-0.205322, (float)-0.180969, (float)-0.180788, (float)-0.172978, (float)-0.375723, (float)-0.180822, (float)-0.180544, (float)-0.189487, (float)-0.264252, (float)-0.207542, (float)-0.236463, (float)-0.197528, (float)-0.306371, (float)-0.198389, (float)-0.181054, (float)-0.367628, (float)-0.119818, (float)-0.148455, (float)-0.176971, (float)-0.078079, (float)-0.205227, (float)-0.136028, (float)-0.141746, (float)-0.169058, (float)-0.239485, (float)-0.178486, (float)-0.174669, (float)-0.248379, (float)-0.271685, (float)-0.309555, (float)-0.146468, (float)-0.223885, (float)-0.258417, (float)-0.357162, (float)-0.231054, (float)-0.287848, (float)-0.384136, (float)-0.347452, (float)-0.389585, (float)-0.189110, (float)-0.286117, (float)-0.243095, (float)-0.283685, (float)-0.436487, (float)-0.335263, (float)-0.180239, (float)-0.197564, (float)-0.152912, (float)-0.197830, (float)-0.253538, (float)-0.195395, (float)-0.266740, (float)-0.281316, (float)-0.248707, (float)-0.307038, (float)-0.233905, (float)-0.221150, (float)-0.192464, (float)-0.222371, (float)-0.417830, (float)-0.315056, (float)-0.266301, (float)-0.358100, (float)-0.193531, (float)-0.238467, (float)-0.242361, (float)-0.185004, (float)-0.226484, (float)-0.180310, (float)-0.077689, (float)-0.149226, (float)-0.336118, (float)-0.413346, (float)-0.312267, (float)-0.274504, (float)-0.124697, (float)-0.310247, (float)0.004149, (float)-0.198112, (float)-0.330072, (float)-0.204688, (float)-0.105279, (float)-0.165321, (float)-0.163434, (float)-0.111551, (float)-0.231402, (float)-0.319092, (float)-0.181831, (float)-0.265720, (float)-0.221983, (float)-0.102949, (float)-0.199872, (float)-0.270191, (float)-0.213872, (float)-0.225551, (float)-0.265250, (float)-0.162972, (float)-0.332166, (float)-0.161663, (float)-0.344593, (float)0.028774, (float)-0.245563, (float)-0.317107, (float)-0.357985, (float)-0.285660, (float)-0.251980, (float)-0.203063, (float)-0.152176, (float)-0.220265, (float)-0.348986, (float)-0.168507, (float)-0.142427, (float)-0.160224, (float)-0.155327, (float)-0.305684, (float)-0.241994, (float)-0.353634, (float)-0.055081, (float)-0.098713, (float)-0.227165, (float)-0.261876, (float)-0.203461, (float)-0.090587, (float)-0.197606, (float)-0.303963, (float)-0.273170, (float)-0.316085, (float)-0.210227, (float)-0.338416, (float)-0.173969, (float)-0.147459, (float)-0.184161, (float)-0.182304, (float)-0.115078, (float)-0.218291, (float)-0.200986, (float)-0.265908, (float)-0.220454, (float)-0.256738, (float)-0.163324, (float)-0.221288, (float)-0.265817, (float)-0.293830, (float)-0.106918, (float)-0.252185, (float)-0.110302, (float)-0.221646, (float)-0.224405, (float)-0.290811, (float)-0.217623, (float)-0.360512, (float)-0.237444, (float)-0.239137, (float)-0.225083, (float)-0.225597, (float)-0.133864, (float)-0.197039, (float)-0.296969, (float)-0.220620, (float)-0.205085, (float)-0.222900, (float)-0.360189, (float)-0.292274, (float)-0.249828, (float)-0.146556, (float)-0.097893, (float)-0.168627, (float)-0.215751, (float)-0.288114, (float)-0.300222, (float)-0.276004, (float)-0.249589, (float)-0.353595, (float)-0.286838, (float)-0.325114, (float)-0.184698, (float)-0.306160, (float)-0.386136, (float)-0.264980, (float)-0.133942, (float)-0.184593, (float)-0.163013, (float)-0.062955, (float)-0.171709, (float)-0.141548, (float)-0.190569, (float)-0.461079, (float)-0.139061, (float)-0.191997, (float)-0.136922, (float)-0.164662, (float)-0.005524, (float)-0.259823, (float)-0.265267, (float)-0.231897, (float)-0.178000, (float)-0.191288, (float)-0.205495, (float)-0.189086, (float)-0.262499, (float)-0.163345, (float)-0.249750, (float)-0.169640, (float)-0.190729, (float)-0.243125, (float)-0.182511, (float)-0.260706, (float)-0.194282, (float)-0.236066, (float)-0.058098, (float)-0.275778, (float)-0.259300, (float)-0.146562, (float)-0.358905, (float)-0.043869, (float)-0.344004, (float)-0.108874, (float)-0.421938, (float)-0.150348, (float)-0.279242, (float)-0.303465, (float)-0.115635};	// L3928
  #pragma HLS resource variable=v3428 core=ram_t2p_bram

  float v3429[512] = {(float)0.242738, (float)0.223229, (float)0.251088, (float)0.228825, (float)0.207412, (float)0.290541, (float)0.248232, (float)0.310215, (float)0.274875, (float)0.289230, (float)0.244753, (float)0.175929, (float)0.242616, (float)0.277998, (float)0.231506, (float)0.263106, (float)0.338313, (float)0.278466, (float)0.253569, (float)0.298945, (float)0.233532, (float)0.281249, (float)0.348573, (float)0.277822, (float)0.228034, (float)0.254681, (float)0.303198, (float)0.246762, (float)0.251219, (float)0.297292, (float)0.257664, (float)0.319988, (float)0.238466, (float)0.271371, (float)0.253153, (float)0.262516, (float)0.334373, (float)0.262634, (float)0.183769, (float)0.283901, (float)0.218676, (float)0.266551, (float)0.285818, (float)0.247110, (float)0.291457, (float)0.233155, (float)0.263742, (float)0.269146, (float)0.243248, (float)0.238433, (float)0.235601, (float)0.252514, (float)0.256354, (float)0.245073, (float)0.252895, (float)0.252250, (float)0.279956, (float)0.316502, (float)0.233972, (float)0.263354, (float)0.256883, (float)0.194176, (float)0.262103, (float)0.220502, (float)0.230072, (float)0.232253, (float)0.281094, (float)0.189740, (float)0.227982, (float)0.347183, (float)0.271688, (float)0.319123, (float)0.243989, (float)0.271895, (float)0.278139, (float)0.226162, (float)0.344388, (float)0.264784, (float)0.272536, (float)0.285112, (float)0.203887, (float)0.293511, (float)0.274228, (float)0.277399, (float)0.265362, (float)0.243014, (float)0.272139, (float)0.270834, (float)0.308537, (float)0.289527, (float)0.259586, (float)0.214701, (float)0.311861, (float)0.344944, (float)0.226181, (float)0.281367, (float)0.232603, (float)0.271219, (float)0.263690, (float)0.232319, (float)0.333319, (float)0.271424, (float)0.299137, (float)0.274671, (float)0.251543, (float)0.239413, (float)0.270857, (float)0.283572, (float)0.286577, (float)0.240797, (float)0.256005, (float)0.204830, (float)0.239414, (float)0.281327, (float)0.326718, (float)0.276053, (float)0.212269, (float)0.271543, (float)0.254019, (float)0.277094, (float)0.320890, (float)0.190511, (float)0.398912, (float)0.267578, (float)0.235663, (float)0.216938, (float)0.321555, (float)0.359597, (float)0.283838, (float)0.264836, (float)0.270211, (float)0.246857, (float)0.244201, (float)0.255279, (float)0.259854, (float)0.269251, (float)0.239868, (float)0.269991, (float)0.206276, (float)0.271124, (float)0.283362, (float)0.278073, (float)0.252874, (float)0.201308, (float)0.234309, (float)0.208181, (float)0.306341, (float)0.163521, (float)0.267299, (float)0.219724, (float)0.278701, (float)0.272365, (float)0.274440, (float)0.228724, (float)0.296922, (float)0.266241, (float)0.298229, (float)0.239561, (float)0.303906, (float)0.231925, (float)0.277275, (float)0.266073, (float)0.289807, (float)0.248948, (float)0.305993, (float)0.261240, (float)0.293731, (float)0.304544, (float)0.299858, (float)0.258004, (float)0.209265, (float)0.271366, (float)0.299270, (float)0.267889, (float)0.296296, (float)0.275384, (float)0.257953, (float)0.256569, (float)0.263375, (float)0.232545, (float)0.244152, (float)0.293402, (float)0.239776, (float)0.263149, (float)0.285050, (float)0.286958, (float)0.223889, (float)0.240993, (float)0.267589, (float)0.268111, (float)0.263831, (float)0.273174, (float)0.281168, (float)0.220254, (float)0.266969, (float)0.276436, (float)0.254976, (float)0.316048, (float)0.288816, (float)0.261468, (float)0.217815, (float)0.248495, (float)0.241365, (float)0.279753, (float)0.287232, (float)0.276727, (float)0.255150, (float)0.242932, (float)0.245879, (float)0.328794, (float)0.302417, (float)0.291177, (float)0.262525, (float)0.301930, (float)0.264317, (float)0.272079, (float)0.210763, (float)0.236752, (float)0.226902, (float)0.198820, (float)0.283030, (float)0.256911, (float)0.234938, (float)0.275530, (float)0.244206, (float)0.271696, (float)0.274690, (float)0.278527, (float)0.251553, (float)0.222659, (float)0.278269, (float)0.246469, (float)0.265156, (float)0.264124, (float)0.296017, (float)0.267127, (float)0.267868, (float)0.253713, (float)0.284713, (float)0.250700, (float)0.252451, (float)0.202384, (float)0.231072, (float)0.261772, (float)0.276418, (float)0.303103, (float)0.245168, (float)0.271560, (float)0.227330, (float)0.229452, (float)0.261116, (float)0.232895, (float)0.268972, (float)0.275259, (float)0.273658, (float)0.259012, (float)0.242071, (float)0.268511, (float)0.339180, (float)0.307252, (float)0.137076, (float)0.365011, (float)0.298036, (float)0.245969, (float)0.248711, (float)0.291247, (float)0.270354, (float)0.255993, (float)0.221280, (float)0.256874, (float)0.266119, (float)0.236722, (float)0.274177, (float)0.284701, (float)0.305502, (float)0.267062, (float)0.281862, (float)0.279052, (float)0.240121, (float)0.254914, (float)0.221047, (float)0.350725, (float)0.285211, (float)0.216223, (float)0.282136, (float)0.236936, (float)0.290523, (float)0.282647, (float)0.230002, (float)0.274461, (float)0.243744, (float)0.252203, (float)0.248898, (float)0.239529, (float)0.285060, (float)0.288684, (float)0.262105, (float)0.250022, (float)0.268917, (float)0.242713, (float)0.300962, (float)0.306657, (float)0.286106, (float)0.238744, (float)0.246162, (float)0.285928, (float)0.255025, (float)0.263029, (float)0.244164, (float)0.214544, (float)0.289764, (float)0.228232, (float)0.232676, (float)0.224215, (float)0.273758, (float)0.248482, (float)0.237869, (float)0.305787, (float)0.279779, (float)0.276106, (float)0.225152, (float)0.286625, (float)0.266006, (float)0.325035, (float)0.261215, (float)0.276718, (float)0.320541, (float)0.293245, (float)0.318326, (float)0.293882, (float)0.310258, (float)0.255299, (float)0.298073, (float)0.366746, (float)0.308639, (float)0.225385, (float)0.235182, (float)0.234786, (float)0.255469, (float)0.259705, (float)0.236874, (float)0.301747, (float)0.277597, (float)0.272827, (float)0.317445, (float)0.278549, (float)0.272122, (float)0.263707, (float)0.270200, (float)0.363315, (float)0.286896, (float)0.267537, (float)0.340459, (float)0.258697, (float)0.273187, (float)0.274671, (float)0.282137, (float)0.275032, (float)0.262962, (float)0.201825, (float)0.235759, (float)0.303436, (float)0.315534, (float)0.301280, (float)0.277486, (float)0.251089, (float)0.294482, (float)0.160482, (float)0.282515, (float)0.296418, (float)0.219357, (float)0.206085, (float)0.233200, (float)0.234764, (float)0.266315, (float)0.254269, (float)0.292666, (float)0.221489, (float)0.252101, (float)0.282715, (float)0.199326, (float)0.245316, (float)0.259724, (float)0.265365, (float)0.275675, (float)0.264962, (float)0.244407, (float)0.294905, (float)0.230785, (float)0.307080, (float)0.190391, (float)0.302415, (float)0.278632, (float)0.365939, (float)0.296625, (float)0.274562, (float)0.244938, (float)0.220149, (float)0.256353, (float)0.285268, (float)0.239166, (float)0.245727, (float)0.246669, (float)0.237418, (float)0.266365, (float)0.245967, (float)0.318188, (float)0.179343, (float)0.237876, (float)0.259582, (float)0.284720, (float)0.245217, (float)0.197415, (float)0.238787, (float)0.294851, (float)0.287885, (float)0.278605, (float)0.276464, (float)0.329610, (float)0.253012, (float)0.268977, (float)0.254731, (float)0.233338, (float)0.234827, (float)0.268967, (float)0.271771, (float)0.267890, (float)0.251561, (float)0.271041, (float)0.236629, (float)0.260149, (float)0.276431, (float)0.287993, (float)0.200767, (float)0.263671, (float)0.226324, (float)0.251057, (float)0.260447, (float)0.280525, (float)0.298889, (float)0.296537, (float)0.259692, (float)0.276733, (float)0.255258, (float)0.295895, (float)0.251213, (float)0.292514, (float)0.300836, (float)0.242281, (float)0.239387, (float)0.270826, (float)0.370442, (float)0.287928, (float)0.253228, (float)0.224844, (float)0.202289, (float)0.227922, (float)0.236583, (float)0.308202, (float)0.297956, (float)0.290909, (float)0.277748, (float)0.429307, (float)0.265800, (float)0.294045, (float)0.241794, (float)0.281646, (float)0.324692, (float)0.264662, (float)0.221609, (float)0.275780, (float)0.242125, (float)0.207775, (float)0.233235, (float)0.227066, (float)0.261117, (float)0.365041, (float)0.201653, (float)0.259769, (float)0.215959, (float)0.264116, (float)0.140771, (float)0.266422, (float)0.250156, (float)0.255299, (float)0.222699, (float)0.241697, (float)0.269631, (float)0.238818, (float)0.283297, (float)0.233322, (float)0.266676, (float)0.222427, (float)0.269119, (float)0.270981, (float)0.245862, (float)0.267364, (float)0.242962, (float)0.259345, (float)0.185116, (float)0.295006, (float)0.366398, (float)0.221177, (float)0.302595, (float)0.184028, (float)0.344339, (float)0.213992, (float)0.371655, (float)0.236002, (float)0.308054, (float)0.263847, (float)0.223318};	// L3929
  #pragma HLS resource variable=v3429 core=ram_t2p_bram

  float v3430[512] = {(float)0.024833, (float)0.033080, (float)0.020296, (float)0.015249, (float)0.020692, (float)0.018305, (float)0.020471, (float)0.028226, (float)0.030079, (float)0.024272, (float)0.027239, (float)0.021119, (float)0.016120, (float)0.048926, (float)0.015775, (float)0.019033, (float)0.020561, (float)0.035445, (float)0.022633, (float)0.014559, (float)0.021948, (float)0.026594, (float)0.025071, (float)0.015912, (float)0.019282, (float)0.021082, (float)0.019509, (float)0.019900, (float)0.016651, (float)0.018938, (float)0.021580, (float)0.025958, (float)0.020472, (float)0.021154, (float)0.016775, (float)0.014313, (float)0.028038, (float)0.020398, (float)0.023671, (float)0.013760, (float)0.019427, (float)0.021632, (float)0.023166, (float)0.013648, (float)0.025834, (float)0.020891, (float)0.019066, (float)0.034593, (float)0.021960, (float)0.022518, (float)0.020690, (float)0.013641, (float)0.016057, (float)0.019966, (float)0.020539, (float)0.017946, (float)0.017566, (float)0.019128, (float)0.022047, (float)0.029701, (float)0.017670, (float)0.019960, (float)0.029041, (float)0.023745, (float)0.023840, (float)0.020386, (float)0.025736, (float)0.017321, (float)0.016626, (float)0.018936, (float)0.036740, (float)0.023555, (float)0.017346, (float)0.029061, (float)0.017480, (float)0.020982, (float)0.016436, (float)0.017391, (float)0.022283, (float)0.019045, (float)0.015922, (float)0.026576, (float)0.018965, (float)0.024633, (float)0.022448, (float)0.023271, (float)0.026828, (float)0.015013, (float)0.034970, (float)0.027197, (float)0.024104, (float)0.024977, (float)0.018593, (float)0.018319, (float)0.023605, (float)0.029364, (float)0.020061, (float)0.021858, (float)0.022766, (float)0.020778, (float)0.037099, (float)0.027477, (float)0.024862, (float)0.017150, (float)0.016191, (float)0.015232, (float)0.030046, (float)0.026621, (float)0.018450, (float)0.029335, (float)0.017999, (float)0.025333, (float)0.018225, (float)0.026072, (float)0.023344, (float)0.019952, (float)0.027224, (float)0.039102, (float)0.017148, (float)0.018970, (float)0.026572, (float)0.023887, (float)0.025440, (float)0.019029, (float)0.018488, (float)0.019150, (float)0.022768, (float)0.021362, (float)0.015905, (float)0.020834, (float)0.020401, (float)0.025575, (float)0.022002, (float)0.012720, (float)0.015156, (float)0.017273, (float)0.024564, (float)0.020573, (float)0.019230, (float)0.017903, (float)0.021950, (float)0.019275, (float)0.019678, (float)0.020337, (float)0.020774, (float)0.023042, (float)0.022799, (float)0.017380, (float)0.025705, (float)0.020541, (float)0.030618, (float)0.020408, (float)0.018540, (float)0.025696, (float)0.014412, (float)0.022202, (float)0.018074, (float)0.032491, (float)0.023889, (float)0.017946, (float)0.019074, (float)0.022918, (float)0.018890, (float)0.029527, (float)0.021006, (float)0.025455, (float)0.023745, (float)0.020723, (float)0.020327, (float)0.020734, (float)0.020228, (float)0.019176, (float)0.017930, (float)0.022085, (float)0.017270, (float)0.023272, (float)0.022734, (float)0.018007, (float)0.037277, (float)0.020109, (float)0.025690, (float)0.023128, (float)0.027003, (float)0.024481, (float)0.020348, (float)0.029298, (float)0.019656, (float)0.020298, (float)0.032104, (float)0.017097, (float)0.020729, (float)0.016681, (float)0.029341, (float)0.013314, (float)0.022363, (float)0.015633, (float)0.018116, (float)0.030468, (float)0.020086, (float)0.021300, (float)0.028081, (float)0.017087, (float)0.034536, (float)0.021716, (float)0.024298, (float)0.016968, (float)0.021991, (float)0.014881, (float)0.019965, (float)0.016619, (float)0.024966, (float)0.023971, (float)0.019127, (float)0.023055, (float)0.020037, (float)0.024586, (float)0.024219, (float)0.019185, (float)0.023733, (float)0.024952, (float)0.021067, (float)0.016952, (float)0.022617, (float)0.016901, (float)0.025003, (float)0.018883, (float)0.019898, (float)0.020216, (float)0.020317, (float)0.024188, (float)0.019648, (float)0.018298, (float)0.018622, (float)0.067734, (float)0.018365, (float)0.014915, (float)0.023664, (float)0.082619, (float)0.025052, (float)0.040331, (float)0.018407, (float)0.032252, (float)0.033313, (float)0.016555, (float)0.020685, (float)0.026944, (float)0.015494, (float)0.018364, (float)0.018372, (float)0.034329, (float)0.038219, (float)0.016332, (float)0.015061, (float)0.015214, (float)0.020056, (float)0.033673, (float)0.021137, (float)0.027841, (float)0.019850, (float)0.021473, (float)0.023712, (float)0.025655, (float)0.022647, (float)0.016206, (float)0.016700, (float)0.024116, (float)0.016932, (float)0.025522, (float)0.016277, (float)0.029663, (float)0.037830, (float)0.018506, (float)0.017631, (float)0.028417, (float)0.029806, (float)0.021214, (float)0.021561, (float)0.021888, (float)0.021089, (float)0.024743, (float)0.023409, (float)0.019061, (float)0.017674, (float)0.027206, (float)0.034606, (float)0.016863, (float)0.018932, (float)0.024011, (float)0.022686, (float)0.017131, (float)0.022803, (float)0.017171, (float)0.019732, (float)0.017178, (float)0.019143, (float)0.014510, (float)0.032377, (float)0.022500, (float)0.018290, (float)0.021394, (float)0.030828, (float)0.021373, (float)0.020031, (float)0.023608, (float)0.028301, (float)0.018092, (float)0.023573, (float)0.019300, (float)0.018900, (float)0.019180, (float)0.022582, (float)0.031516, (float)0.026300, (float)0.016959, (float)0.020105, (float)0.019393, (float)0.041140, (float)0.015049, (float)0.033769, (float)0.052802, (float)0.028814, (float)0.019997, (float)0.020849, (float)0.020606, (float)0.021785, (float)0.013761, (float)0.021078, (float)0.015782, (float)0.018571, (float)0.025762, (float)0.037403, (float)0.032722, (float)0.021694, (float)0.017374, (float)0.018202, (float)0.019531, (float)0.052114, (float)0.015209, (float)0.018567, (float)0.022269, (float)0.020769, (float)0.065523, (float)0.016649, (float)0.036942, (float)0.020398, (float)0.016697, (float)0.022643, (float)0.023169, (float)0.025668, (float)0.046674, (float)0.018211, (float)0.021373, (float)0.020317, (float)0.018884, (float)0.018498, (float)0.016197, (float)0.024375, (float)0.016976, (float)0.018281, (float)0.014417, (float)0.028025, (float)0.020342, (float)0.026802, (float)0.018525, (float)0.023066, (float)0.015621, (float)0.023369, (float)0.020752, (float)0.025609, (float)0.018787, (float)0.030633, (float)0.024343, (float)0.090075, (float)0.022312, (float)0.021592, (float)0.016924, (float)0.020200, (float)0.017122, (float)0.022771, (float)0.015618, (float)0.029398, (float)0.019049, (float)0.027112, (float)0.017003, (float)0.016870, (float)0.021307, (float)0.016659, (float)0.015115, (float)0.022211, (float)0.020252, (float)0.018544, (float)0.014517, (float)0.013800, (float)0.029232, (float)0.016665, (float)0.019171, (float)0.016493, (float)0.019881, (float)0.020807, (float)0.020759, (float)0.012931, (float)0.020713, (float)0.017423, (float)0.030200, (float)0.027102, (float)0.025999, (float)0.015614, (float)0.018196, (float)0.020943, (float)0.021923, (float)0.024057, (float)0.018049, (float)0.015076, (float)0.025803, (float)0.018316, (float)0.018238, (float)0.016072, (float)0.018363, (float)0.028800, (float)0.016225, (float)0.022379, (float)0.019086, (float)0.020058, (float)0.015964, (float)0.030622, (float)0.018056, (float)0.020481, (float)0.026230, (float)0.025718, (float)0.024484, (float)0.048848, (float)0.020584, (float)0.017286, (float)0.023303, (float)0.020452, (float)0.025861, (float)0.021619, (float)0.017750, (float)0.017517, (float)0.022799, (float)0.037831, (float)0.019328, (float)0.030274, (float)0.018237, (float)0.019539, (float)0.019688, (float)0.028542, (float)0.021648, (float)0.017796, (float)0.014165, (float)0.020635, (float)0.015512, (float)0.024537, (float)0.018025, (float)0.017956, (float)0.021426, (float)0.023666, (float)0.025232, (float)0.017208, (float)0.014933, (float)0.029103, (float)0.023218, (float)0.017705, (float)0.020426, (float)0.015930, (float)0.023843, (float)0.024137, (float)0.015038, (float)0.024345, (float)0.019328, (float)0.025741, (float)0.019144, (float)0.024423, (float)0.015700, (float)0.023361, (float)0.018594, (float)0.017644, (float)0.022995, (float)0.018335, (float)0.039936, (float)0.016851, (float)0.031330, (float)0.018009, (float)0.020876, (float)0.028069, (float)0.024640, (float)0.019396, (float)0.015216, (float)0.013678, (float)0.021538, (float)0.015096, (float)0.016284, (float)0.019524, (float)0.018641, (float)0.020955, (float)0.020575, (float)0.014833, (float)0.019324, (float)0.019538, (float)0.018318, (float)0.019908, (float)0.020339, (float)0.021765, (float)0.022689, (float)0.020712, (float)0.023893, (float)0.018392, (float)0.017216, (float)0.017257, (float)0.026570, (float)0.015864, (float)0.017469};	// L3930
  #pragma HLS resource variable=v3430 core=ram_t2p_bram

  float v3431[512] = {(float)-0.232302, (float)-0.200935, (float)-0.122972, (float)-0.110189, (float)-0.094452, (float)-0.107273, (float)-0.135740, (float)-0.195383, (float)-0.182557, (float)-0.189005, (float)-0.143205, (float)-0.166712, (float)-0.108637, (float)-0.121344, (float)-0.161362, (float)-0.110852, (float)-0.179412, (float)-0.185288, (float)-0.142104, (float)-0.154869, (float)-0.132217, (float)-0.187041, (float)-0.172972, (float)-0.104222, (float)-0.154669, (float)-0.167919, (float)-0.184609, (float)-0.156798, (float)-0.134012, (float)-0.078551, (float)-0.166365, (float)-0.148140, (float)-0.153803, (float)-0.147544, (float)-0.147552, (float)-0.140890, (float)-0.240223, (float)-0.070726, (float)-0.051521, (float)-0.105176, (float)-0.153536, (float)-0.251397, (float)-0.196279, (float)-0.131828, (float)-0.138942, (float)-0.172649, (float)-0.206854, (float)-0.179420, (float)-0.070911, (float)-0.185128, (float)-0.133683, (float)-0.098252, (float)-0.146256, (float)-0.168510, (float)-0.135466, (float)-0.160325, (float)-0.100751, (float)-0.178750, (float)-0.217991, (float)-0.145966, (float)-0.194805, (float)-0.134796, (float)-0.201972, (float)-0.197083, (float)-0.187969, (float)-0.091100, (float)-0.177819, (float)-0.194519, (float)-0.079001, (float)-0.213767, (float)-0.108032, (float)-0.186328, (float)-0.148694, (float)-0.181970, (float)-0.108989, (float)-0.155602, (float)-0.183434, (float)-0.132527, (float)-0.190307, (float)-0.128660, (float)-0.141448, (float)-0.097824, (float)-0.096139, (float)-0.106179, (float)-0.162803, (float)-0.154933, (float)-0.193116, (float)-0.107990, (float)-0.167286, (float)0.015974, (float)-0.106103, (float)-0.082035, (float)-0.173040, (float)-0.149805, (float)-0.145115, (float)-0.153323, (float)-0.062149, (float)-0.144531, (float)-0.091818, (float)-0.184441, (float)-0.200063, (float)-0.195992, (float)-0.281586, (float)-0.105019, (float)-0.082714, (float)-0.096708, (float)-0.190664, (float)-0.204479, (float)-0.142458, (float)-0.172193, (float)-0.185631, (float)-0.148087, (float)-0.050002, (float)-0.196371, (float)-0.252936, (float)-0.130516, (float)-0.183256, (float)-0.100996, (float)-0.167824, (float)-0.090414, (float)-0.142094, (float)-0.182888, (float)-0.148279, (float)-0.160357, (float)-0.204362, (float)-0.246992, (float)-0.257437, (float)0.041143, (float)-0.104581, (float)-0.098690, (float)-0.155744, (float)-0.156297, (float)-0.119009, (float)-0.053658, (float)-0.100444, (float)-0.128948, (float)-0.147222, (float)-0.117688, (float)-0.100082, (float)-0.169749, (float)-0.118216, (float)-0.107779, (float)-0.098160, (float)-0.084792, (float)-0.115911, (float)-0.212963, (float)-0.183578, (float)-0.131023, (float)-0.129830, (float)-0.106809, (float)-0.166528, (float)-0.180043, (float)-0.190757, (float)-0.189426, (float)-0.179287, (float)-0.124778, (float)-0.158351, (float)-0.012211, (float)-0.110524, (float)-0.055824, (float)-0.128081, (float)-0.090005, (float)-0.107691, (float)-0.036224, (float)-0.180773, (float)-0.168387, (float)-0.189743, (float)-0.134360, (float)-0.143946, (float)-0.105097, (float)-0.187517, (float)-0.176032, (float)-0.060163, (float)-0.180108, (float)-0.149665, (float)-0.092921, (float)-0.168158, (float)-0.112420, (float)-0.233518, (float)-0.139173, (float)-0.158372, (float)-0.148938, (float)-0.083121, (float)-0.116465, (float)-0.111749, (float)-0.148483, (float)-0.225528, (float)-0.094978, (float)-0.320784, (float)-0.157886, (float)-0.256821, (float)-0.096258, (float)-0.153973, (float)-0.099777, (float)-0.136168, (float)-0.213496, (float)-0.203732, (float)-0.135704, (float)-0.121270, (float)-0.110177, (float)-0.194392, (float)-0.184633, (float)-0.145726, (float)-0.119995, (float)-0.151465, (float)-0.124048, (float)-0.150740, (float)-0.145879, (float)-0.183828, (float)-0.013828, (float)-0.159438, (float)-0.189359, (float)-0.191632, (float)-0.097181, (float)-0.190013, (float)-0.062310, (float)-0.102058, (float)-0.099895, (float)-0.235442, (float)-0.205990, (float)-0.158682, (float)-0.096543, (float)-0.044021, (float)-0.145041, (float)-0.243312, (float)-0.136630, (float)-0.143473, (float)-0.123434, (float)-0.099576, (float)-0.185544, (float)-0.125909, (float)-0.171286, (float)-0.207148, (float)0.367456, (float)-0.183047, (float)-0.082496, (float)-0.159248, (float)0.476678, (float)-0.177632, (float)-0.284210, (float)-0.173548, (float)-0.258689, (float)-0.091807, (float)-0.070211, (float)-0.191668, (float)-0.231592, (float)-0.142491, (float)-0.200931, (float)-0.162459, (float)-0.050567, (float)-0.174687, (float)-0.163821, (float)-0.084131, (float)-0.054895, (float)-0.151551, (float)-0.235959, (float)-0.117191, (float)-0.109222, (float)-0.003786, (float)-0.167928, (float)-0.122046, (float)-0.064560, (float)-0.178259, (float)-0.151505, (float)-0.051187, (float)-0.091795, (float)-0.081585, (float)-0.142072, (float)-0.135937, (float)0.008303, (float)-0.248446, (float)-0.188448, (float)-0.073592, (float)-0.113894, (float)-0.221322, (float)-0.177965, (float)-0.192910, (float)-0.170259, (float)-0.133447, (float)-0.209552, (float)-0.185318, (float)-0.116583, (float)-0.143818, (float)-0.188078, (float)0.143649, (float)-0.068612, (float)-0.142092, (float)-0.133502, (float)-0.152447, (float)-0.232189, (float)-0.240584, (float)-0.087056, (float)-0.139663, (float)-0.148048, (float)-0.151175, (float)-0.126180, (float)-0.124397, (float)-0.117284, (float)-0.129118, (float)-0.132612, (float)-0.111337, (float)-0.207984, (float)-0.132911, (float)-0.149755, (float)-0.146943, (float)-0.171493, (float)-0.108968, (float)-0.138324, (float)-0.047026, (float)-0.145403, (float)-0.173710, (float)-0.244259, (float)-0.130177, (float)-0.082999, (float)-0.107842, (float)-0.133776, (float)-0.145120, (float)-0.127843, (float)-0.194736, (float)-0.087655, (float)-0.128759, (float)-0.115108, (float)-0.180912, (float)-0.106765, (float)-0.179656, (float)-0.159873, (float)-0.141131, (float)-0.210445, (float)-0.118925, (float)-0.154765, (float)-0.176910, (float)-0.215166, (float)-0.254884, (float)-0.197702, (float)-0.138451, (float)-0.233902, (float)-0.248123, (float)-0.097799, (float)-0.097889, (float)-0.069748, (float)-0.125725, (float)-0.092703, (float)-0.122435, (float)-0.198584, (float)-0.157050, (float)-0.184530, (float)-0.194364, (float)-0.140669, (float)-0.131509, (float)-0.165687, (float)-0.182292, (float)-0.197263, (float)-0.130963, (float)-0.154184, (float)-0.128043, (float)-0.057010, (float)-0.153762, (float)-0.115227, (float)-0.149621, (float)-0.047698, (float)-0.151506, (float)-0.112096, (float)-0.166724, (float)-0.165059, (float)-0.041460, (float)-0.129915, (float)-0.168775, (float)-0.114300, (float)-0.056381, (float)-0.079186, (float)-0.214027, (float)-0.153466, (float)-0.308662, (float)-0.192660, (float)-0.116826, (float)-0.170450, (float)-0.136237, (float)-0.153795, (float)-0.080354, (float)-0.152580, (float)-0.112461, (float)-0.143779, (float)-0.056540, (float)-0.091854, (float)-0.142999, (float)-0.117261, (float)-0.221513, (float)-0.162438, (float)-0.227675, (float)-0.116485, (float)-0.181648, (float)-0.089875, (float)-0.053628, (float)-0.144332, (float)-0.153889, (float)-0.122333, (float)-0.139570, (float)-0.189093, (float)-0.150242, (float)-0.152174, (float)-0.107524, (float)-0.081042, (float)-0.127600, (float)-0.221178, (float)-0.074705, (float)-0.131271, (float)-0.148800, (float)-0.183152, (float)-0.100470, (float)-0.168825, (float)-0.208740, (float)-0.205517, (float)-0.056272, (float)-0.181550, (float)-0.079208, (float)-0.138109, (float)-0.092590, (float)-0.113554, (float)-0.219974, (float)-0.102614, (float)-0.194732, (float)-0.089157, (float)-0.171075, (float)-0.066090, (float)-0.198945, (float)-0.124851, (float)-0.179668, (float)-0.207942, (float)-0.175541, (float)-0.091204, (float)-0.312171, (float)-0.127823, (float)-0.137409, (float)-0.212180, (float)-0.103986, (float)-0.110434, (float)-0.202333, (float)-0.135847, (float)-0.143726, (float)-0.137832, (float)-0.153456, (float)-0.170911, (float)-0.245988, (float)-0.119525, (float)-0.122377, (float)-0.148505, (float)-0.205045, (float)-0.166311, (float)-0.121796, (float)-0.108426, (float)-0.084329, (float)-0.154539, (float)-0.162437, (float)-0.040206, (float)-0.094774, (float)-0.123349, (float)-0.124742, (float)-0.094856, (float)-0.189039, (float)-0.140897, (float)-0.195749, (float)-0.152068, (float)-0.179119, (float)-0.177113, (float)-0.079887, (float)-0.151514, (float)-0.239003, (float)-0.097860, (float)-0.137393, (float)-0.172780, (float)-0.089316, (float)-0.217160, (float)-0.152696, (float)-0.172826, (float)-0.113589, (float)-0.132474, (float)-0.220271, (float)-0.128512, (float)-0.180011, (float)-0.235956, (float)-0.147804, (float)-0.085998, (float)-0.136019, (float)-0.136589, (float)-0.195817, (float)-0.115021, (float)-0.182575, (float)-0.231534, (float)-0.128786, (float)-0.219198, (float)-0.094386, (float)-0.164513, (float)-0.198852, (float)-0.167741, (float)-0.195079, (float)-0.183487, (float)-0.051837, (float)-0.091640, (float)-0.156358, (float)-0.152678, (float)-0.183448, (float)-0.142401, (float)-0.048417, (float)-0.079919, (float)-0.092998, (float)-0.093650, (float)-0.110507, (float)-0.159363, (float)-0.145434, (float)-0.245941, (float)-0.075525, (float)-0.210594};	// L3931
  #pragma HLS resource variable=v3431 core=ram_t2p_bram

  float v3432[512] = {(float)-0.175876, (float)-0.215647, (float)-0.204695, (float)-0.169495, (float)-0.162827, (float)-0.147338, (float)-0.215763, (float)-0.290474, (float)-0.111154, (float)-0.219632, (float)-0.102010, (float)-0.154852, (float)-0.198917, (float)-0.044533, (float)-0.150829, (float)-0.191982, (float)-0.211422, (float)-0.165469, (float)-0.185385, (float)-0.173255, (float)-0.128850, (float)-0.237593, (float)-0.196459, (float)-0.196512, (float)-0.177603, (float)-0.177378, (float)-0.175981, (float)-0.154552, (float)-0.164812, (float)-0.259943, (float)-0.175183, (float)-0.249797, (float)-0.174085, (float)-0.240969, (float)-0.249838, (float)-0.293822, (float)-0.149622, (float)-0.157821, (float)-0.180007, (float)-0.185098, (float)-0.151621, (float)-0.134493, (float)-0.274576, (float)-0.124816, (float)-0.224551, (float)-0.253069, (float)-0.239821, (float)-0.185870, (float)-0.173906, (float)-0.239322, (float)-0.121415, (float)-0.180345, (float)-0.272923, (float)-0.261738, (float)-0.185536, (float)-0.231590, (float)-0.233326, (float)-0.186008, (float)-0.209718, (float)-0.069156, (float)-0.191230, (float)-0.207791, (float)-0.108394, (float)-0.280989, (float)-0.130290, (float)-0.165388, (float)-0.211865, (float)-0.364110, (float)-0.295110, (float)-0.238412, (float)-0.163155, (float)-0.189230, (float)-0.179195, (float)-0.203113, (float)-0.176996, (float)-0.273815, (float)-0.332410, (float)-0.172504, (float)-0.179256, (float)-0.263844, (float)-0.220675, (float)-0.160910, (float)-0.153418, (float)-0.141382, (float)-0.299210, (float)-0.144963, (float)-0.183827, (float)-0.177888, (float)-0.142214, (float)-0.219838, (float)-0.190025, (float)-0.158025, (float)-0.166649, (float)-0.248980, (float)-0.156913, (float)-0.171848, (float)-0.166000, (float)-0.197152, (float)-0.228674, (float)-0.236629, (float)-0.222967, (float)-0.154267, (float)-0.203035, (float)-0.143148, (float)-0.136256, (float)-0.201488, (float)-0.180418, (float)-0.209272, (float)-0.296443, (float)-0.198436, (float)-0.268257, (float)-0.221554, (float)-0.214695, (float)-0.340379, (float)-0.266834, (float)-0.189038, (float)-0.173252, (float)-0.222553, (float)-0.177227, (float)-0.169795, (float)-0.109547, (float)-0.218040, (float)-0.115450, (float)-0.165376, (float)-0.190963, (float)-0.353537, (float)-0.311177, (float)-0.216132, (float)-0.149594, (float)-0.166691, (float)-0.284863, (float)-0.220685, (float)-0.152887, (float)-0.180719, (float)-0.211753, (float)-0.186857, (float)-0.137562, (float)-0.177034, (float)-0.186086, (float)-0.196906, (float)-0.174074, (float)-0.301054, (float)-0.078720, (float)-0.201734, (float)-0.194675, (float)-0.224661, (float)-0.245879, (float)-0.105768, (float)-0.140073, (float)-0.121287, (float)-0.119868, (float)-0.175956, (float)-0.215642, (float)-0.330730, (float)-0.351507, (float)-0.236602, (float)-0.118475, (float)-0.215456, (float)-0.175091, (float)-0.189247, (float)-0.336501, (float)-0.159756, (float)-0.255446, (float)0.064416, (float)-0.285613, (float)-0.119795, (float)-0.158325, (float)-0.229696, (float)-0.335175, (float)-0.198683, (float)-0.268627, (float)-0.163159, (float)-0.246141, (float)-0.290042, (float)-0.242833, (float)-0.144908, (float)-0.190023, (float)-0.214939, (float)-0.154125, (float)-0.291725, (float)-0.250379, (float)-0.221277, (float)-0.046265, (float)-0.154741, (float)-0.151054, (float)-0.152670, (float)-0.173487, (float)-0.193143, (float)-0.198664, (float)-0.223877, (float)-0.208557, (float)-0.268808, (float)-0.184503, (float)-0.179723, (float)-0.183276, (float)-0.388039, (float)-0.153910, (float)-0.155262, (float)-0.156722, (float)-0.223757, (float)-0.151111, (float)-0.253952, (float)-0.284909, (float)-0.182560, (float)-0.268691, (float)-0.232789, (float)-0.210797, (float)-0.240983, (float)-0.102194, (float)-0.150658, (float)-0.197840, (float)-0.173376, (float)-0.228219, (float)-0.098492, (float)-0.184693, (float)-0.176974, (float)-0.157557, (float)-0.193729, (float)-0.164283, (float)-0.282202, (float)-0.186557, (float)-0.275359, (float)-0.226644, (float)-0.216856, (float)-0.135228, (float)-0.219364, (float)-0.105988, (float)-0.213885, (float)-0.132169, (float)-0.188947, (float)-0.213028, (float)-0.191251, (float)-0.236402, (float)-0.140232, (float)-0.222844, (float)-0.235422, (float)-0.163198, (float)-0.190452, (float)-0.142823, (float)-0.117746, (float)-0.241885, (float)-0.273342, (float)-0.296315, (float)-0.159994, (float)-0.355825, (float)-0.367269, (float)-0.220057, (float)-0.150526, (float)-0.208420, (float)-0.086982, (float)-0.205152, (float)-0.206952, (float)-0.198606, (float)-0.229943, (float)-0.074515, (float)-0.176496, (float)-0.141153, (float)-0.218021, (float)-0.144980, (float)-0.142644, (float)-0.145244, (float)-0.291583, (float)-0.087099, (float)-0.135855, (float)-0.200296, (float)-0.112490, (float)-0.258800, (float)-0.198756, (float)-0.202807, (float)-0.244341, (float)-0.086370, (float)-0.341515, (float)-0.257930, (float)-0.234285, (float)-0.355215, (float)-0.185889, (float)-0.115276, (float)-0.173172, (float)-0.177991, (float)-0.190923, (float)-0.201802, (float)-0.188640, (float)-0.275075, (float)-0.150079, (float)0.116527, (float)-0.189073, (float)-0.184478, (float)-0.203674, (float)-0.033936, (float)-0.346352, (float)-0.195640, (float)-0.196203, (float)-0.153652, (float)-0.190249, (float)-0.143065, (float)-0.302204, (float)-0.177953, (float)-0.197052, (float)-0.211816, (float)-0.095247, (float)-0.171144, (float)-0.240855, (float)-0.218429, (float)-0.211422, (float)-0.204203, (float)-0.056632, (float)-0.069972, (float)-0.208111, (float)-0.187201, (float)-0.207923, (float)-0.153953, (float)-0.226569, (float)-0.198087, (float)-0.167854, (float)-0.202200, (float)-0.201038, (float)-0.105144, (float)-0.170481, (float)-0.213924, (float)0.039596, (float)-0.107683, (float)-0.274493, (float)-0.269041, (float)-0.260268, (float)-0.281934, (float)-0.191735, (float)-0.194046, (float)-0.294365, (float)-0.182235, (float)-0.290273, (float)-0.106416, (float)-0.207573, (float)-0.264753, (float)-0.303198, (float)-0.287798, (float)-0.157870, (float)-0.007106, (float)-0.214186, (float)-0.202193, (float)-0.151610, (float)-0.112344, (float)0.024550, (float)-0.097783, (float)-0.138225, (float)-0.179958, (float)-0.321398, (float)-0.217892, (float)-0.136859, (float)-0.079968, (float)0.011651, (float)-0.183850, (float)-0.192576, (float)-0.161397, (float)-0.276863, (float)-0.190925, (float)-0.210108, (float)-0.230516, (float)-0.205480, (float)-0.201685, (float)-0.274145, (float)-0.100519, (float)-0.315171, (float)-0.112055, (float)-0.170047, (float)-0.136427, (float)-0.215665, (float)-0.267289, (float)-0.158427, (float)-0.199738, (float)-0.174545, (float)-0.188593, (float)-0.230733, (float)-0.202356, (float)-0.337601, (float)-0.226602, (float)-0.235517, (float)-0.213326, (float)-0.234617, (float)-0.241234, (float)-0.235827, (float)-0.126483, (float)-0.234063, (float)-0.188728, (float)-0.164635, (float)-0.141678, (float)-0.188190, (float)-0.107585, (float)-0.304830, (float)-0.116209, (float)-0.165138, (float)-0.204584, (float)-0.183345, (float)-0.310223, (float)-0.177752, (float)-0.157479, (float)-0.267603, (float)-0.177651, (float)-0.156919, (float)-0.174050, (float)-0.189249, (float)-0.302800, (float)-0.145666, (float)-0.217923, (float)-0.222581, (float)-0.160946, (float)-0.142348, (float)-0.268311, (float)-0.292008, (float)-0.173983, (float)-0.207916, (float)-0.194009, (float)-0.267895, (float)-0.197272, (float)-0.195115, (float)-0.166471, (float)-0.228643, (float)-0.190261, (float)-0.266719, (float)-0.401001, (float)-0.255011, (float)-0.181693, (float)-0.202540, (float)-0.158920, (float)-0.247610, (float)-0.057332, (float)-0.220320, (float)-0.208377, (float)-0.158687, (float)-0.121199, (float)-0.179473, (float)-0.344943, (float)-0.166220, (float)-0.252310, (float)-0.243506, (float)-0.287777, (float)-0.279724, (float)-0.189737, (float)-0.211347, (float)-0.194293, (float)-0.205022, (float)-0.169366, (float)-0.224268, (float)-0.298661, (float)-0.132767, (float)-0.142799, (float)-0.239909, (float)-0.159280, (float)-0.199854, (float)-0.322538, (float)-0.185953, (float)-0.176311, (float)-0.269071, (float)-0.209719, (float)-0.239560, (float)-0.113970, (float)-0.189716, (float)-0.186976, (float)-0.182853, (float)-0.261500, (float)-0.207342, (float)-0.185801, (float)-0.059755, (float)-0.191480, (float)-0.218287, (float)-0.208783, (float)-0.174156, (float)-0.271491, (float)-0.199923, (float)-0.211675, (float)-0.249233, (float)-0.171727, (float)-0.156605, (float)-0.166925, (float)-0.301463, (float)-0.168512, (float)-0.243372, (float)-0.229652, (float)-0.194695, (float)-0.286040, (float)-0.328765, (float)-0.219691, (float)-0.186197, (float)-0.175520, (float)-0.098674, (float)-0.175625, (float)-0.130352, (float)-0.155537, (float)-0.167934, (float)-0.222239, (float)-0.281887, (float)-0.265243, (float)-0.094651, (float)-0.241226, (float)-0.273117, (float)-0.257160, (float)-0.260431, (float)-0.293425, (float)-0.246995, (float)-0.181964, (float)-0.274007, (float)-0.133587, (float)-0.169813, (float)-0.191901, (float)-0.179560, (float)-0.232497, (float)-0.135247, (float)-0.107717, (float)-0.218356, (float)-0.153940, (float)-0.201536, (float)-0.324302, (float)-0.171332};	// L3932
  #pragma HLS resource variable=v3432 core=ram_t2p_bram

  float v3433[512] = {(float)0.447423, (float)0.513753, (float)0.433517, (float)0.342105, (float)0.385544, (float)0.349521, (float)0.374139, (float)0.583643, (float)0.432735, (float)0.504286, (float)0.461772, (float)0.386647, (float)0.349811, (float)0.479783, (float)0.331033, (float)0.391315, (float)0.388016, (float)0.522505, (float)0.397472, (float)0.329229, (float)0.415106, (float)0.445845, (float)0.397002, (float)0.361367, (float)0.391385, (float)0.463290, (float)0.346294, (float)0.364381, (float)0.327155, (float)0.458416, (float)0.428011, (float)0.453801, (float)0.403021, (float)0.467282, (float)0.420868, (float)0.398738, (float)0.423288, (float)0.387562, (float)0.421188, (float)0.345988, (float)0.352240, (float)0.374380, (float)0.455002, (float)0.288776, (float)0.459012, (float)0.481650, (float)0.444968, (float)0.511018, (float)0.405238, (float)0.424651, (float)0.355792, (float)0.307477, (float)0.446194, (float)0.472367, (float)0.425337, (float)0.388401, (float)0.449249, (float)0.372737, (float)0.463020, (float)0.398490, (float)0.351244, (float)0.366537, (float)0.386002, (float)0.508161, (float)0.402154, (float)0.345836, (float)0.480451, (float)0.539029, (float)0.422332, (float)0.427524, (float)0.458986, (float)0.473648, (float)0.367295, (float)0.540533, (float)0.324312, (float)0.517760, (float)0.474331, (float)0.350593, (float)0.375866, (float)0.432766, (float)0.386732, (float)0.459052, (float)0.384294, (float)0.498163, (float)0.528848, (float)0.394591, (float)0.458918, (float)0.319701, (float)0.467630, (float)0.480615, (float)0.430807, (float)0.423547, (float)0.328379, (float)0.387704, (float)0.414036, (float)0.446909, (float)0.404150, (float)0.440666, (float)0.435647, (float)0.512019, (float)0.505891, (float)0.462759, (float)0.458519, (float)0.331097, (float)0.342400, (float)0.414994, (float)0.517032, (float)0.459319, (float)0.522786, (float)0.425166, (float)0.421423, (float)0.499517, (float)0.409826, (float)0.537956, (float)0.487378, (float)0.371902, (float)0.464947, (float)0.431961, (float)0.327671, (float)0.374342, (float)0.436016, (float)0.483832, (float)0.439920, (float)0.376324, (float)0.414979, (float)0.514663, (float)0.501180, (float)0.438183, (float)0.365483, (float)0.403676, (float)0.449763, (float)0.471993, (float)0.391360, (float)0.323746, (float)0.320835, (float)0.322407, (float)0.429084, (float)0.400934, (float)0.394691, (float)0.377877, (float)0.434894, (float)0.412024, (float)0.327408, (float)0.433427, (float)0.373986, (float)0.418887, (float)0.428752, (float)0.307146, (float)0.426034, (float)0.341015, (float)0.437495, (float)0.440691, (float)0.374963, (float)0.585253, (float)0.451794, (float)0.504526, (float)0.300518, (float)0.496813, (float)0.415490, (float)0.375511, (float)0.551371, (float)0.414643, (float)0.467706, (float)0.140422, (float)0.500085, (float)0.419293, (float)0.424561, (float)0.445150, (float)0.510906, (float)0.448834, (float)0.457372, (float)0.389648, (float)0.414464, (float)0.449722, (float)0.424525, (float)0.397052, (float)0.395712, (float)0.407184, (float)0.530484, (float)0.498646, (float)0.373323, (float)0.427978, (float)0.346914, (float)0.417807, (float)0.376607, (float)0.402921, (float)0.381379, (float)0.449335, (float)0.513231, (float)0.407952, (float)0.415510, (float)0.363528, (float)0.439108, (float)0.348868, (float)0.422753, (float)0.483326, (float)0.349387, (float)0.440606, (float)0.379494, (float)0.429752, (float)0.491020, (float)0.387832, (float)0.629899, (float)0.432214, (float)0.543615, (float)0.414014, (float)0.431155, (float)0.316055, (float)0.361197, (float)0.359734, (float)0.428121, (float)0.450592, (float)0.429420, (float)0.364638, (float)0.411044, (float)0.403845, (float)0.409787, (float)0.390064, (float)0.392834, (float)0.542146, (float)0.362942, (float)0.407754, (float)0.458593, (float)0.421713, (float)0.395339, (float)0.399698, (float)0.383811, (float)0.437370, (float)0.357607, (float)0.421712, (float)0.412836, (float)0.390364, (float)0.413677, (float)0.514531, (float)0.403890, (float)0.357687, (float)0.442909, (float)0.563922, (float)0.384760, (float)0.610368, (float)0.448247, (float)0.620309, (float)0.533568, (float)0.347986, (float)0.540067, (float)0.604419, (float)0.407654, (float)0.346940, (float)0.428102, (float)0.463130, (float)0.594779, (float)0.347913, (float)0.368877, (float)0.365834, (float)0.319143, (float)0.549162, (float)0.340987, (float)0.538595, (float)0.404143, (float)0.337258, (float)0.418550, (float)0.518712, (float)0.393328, (float)0.318837, (float)0.350157, (float)0.373564, (float)0.423783, (float)0.475212, (float)0.332150, (float)0.507801, (float)0.431669, (float)0.531826, (float)0.441295, (float)0.550951, (float)0.564777, (float)0.412977, (float)0.401727, (float)0.430363, (float)0.407656, (float)0.428488, (float)0.436032, (float)0.374929, (float)0.426109, (float)0.390548, (float)0.303016, (float)0.341231, (float)0.376848, (float)0.450699, (float)0.312710, (float)0.459211, (float)0.429770, (float)0.393613, (float)0.310594, (float)0.386927, (float)0.359374, (float)0.404642, (float)0.472214, (float)0.437271, (float)0.390158, (float)0.351535, (float)0.444846, (float)0.429893, (float)0.434711, (float)0.469288, (float)0.480729, (float)0.254855, (float)0.417091, (float)0.438670, (float)0.415612, (float)0.397638, (float)0.409194, (float)0.495279, (float)0.482386, (float)0.346782, (float)0.438214, (float)0.417869, (float)0.466848, (float)0.329928, (float)0.598589, (float)0.494855, (float)0.416673, (float)0.499622, (float)0.452813, (float)0.454967, (float)0.494491, (float)0.341493, (float)0.465827, (float)0.435634, (float)0.397566, (float)0.543874, (float)0.464332, (float)0.512203, (float)0.466884, (float)0.446294, (float)0.480985, (float)0.349167, (float)0.396135, (float)0.359268, (float)0.405338, (float)0.387780, (float)0.395922, (float)0.500108, (float)0.280756, (float)0.547004, (float)0.444839, (float)0.489365, (float)0.462131, (float)0.341664, (float)0.348471, (float)0.506004, (float)0.363714, (float)0.377388, (float)0.324810, (float)0.451971, (float)0.393600, (float)0.340334, (float)0.465975, (float)0.411420, (float)0.364251, (float)0.419598, (float)0.390338, (float)0.512833, (float)0.422064, (float)0.411518, (float)0.424044, (float)0.361026, (float)0.499868, (float)0.367244, (float)0.472069, (float)0.425155, (float)0.559005, (float)0.469406, (float)0.732236, (float)0.584926, (float)0.474911, (float)0.442566, (float)0.393422, (float)0.390910, (float)0.457596, (float)0.363646, (float)0.414579, (float)0.412940, (float)0.508076, (float)0.368089, (float)0.365219, (float)0.425403, (float)0.294505, (float)0.414201, (float)0.314530, (float)0.430416, (float)0.425217, (float)0.349332, (float)0.425694, (float)0.513318, (float)0.326145, (float)0.436697, (float)0.363685, (float)0.371230, (float)0.418293, (float)0.377237, (float)0.441756, (float)0.423116, (float)0.413291, (float)0.473100, (float)0.495479, (float)0.404575, (float)0.407886, (float)0.471905, (float)0.387505, (float)0.467329, (float)0.412886, (float)0.456864, (float)0.353010, (float)0.479327, (float)0.384407, (float)0.378485, (float)0.334253, (float)0.435122, (float)0.651192, (float)0.429510, (float)0.412192, (float)0.378755, (float)0.369234, (float)0.434277, (float)0.421420, (float)0.387330, (float)0.456627, (float)0.445587, (float)0.410690, (float)0.459617, (float)0.708211, (float)0.445249, (float)0.351457, (float)0.478452, (float)0.421713, (float)0.575569, (float)0.431215, (float)0.404691, (float)0.404316, (float)0.476442, (float)0.548901, (float)0.442972, (float)0.555885, (float)0.374430, (float)0.395060, (float)0.437607, (float)0.475181, (float)0.434038, (float)0.439896, (float)0.358578, (float)0.416113, (float)0.392985, (float)0.459856, (float)0.435436, (float)0.344785, (float)0.464944, (float)0.444204, (float)0.427477, (float)0.388138, (float)0.324681, (float)0.490854, (float)0.342600, (float)0.398876, (float)0.432001, (float)0.336283, (float)0.399056, (float)0.473241, (float)0.351376, (float)0.473625, (float)0.424391, (float)0.460255, (float)0.329753, (float)0.435716, (float)0.435347, (float)0.374213, (float)0.419065, (float)0.387980, (float)0.421212, (float)0.452733, (float)0.721327, (float)0.396854, (float)0.521703, (float)0.378590, (float)0.351187, (float)0.531838, (float)0.413776, (float)0.324344, (float)0.324375, (float)0.365248, (float)0.477405, (float)0.399674, (float)0.280039, (float)0.456171, (float)0.446301, (float)0.481626, (float)0.428990, (float)0.439948, (float)0.463270, (float)0.357526, (float)0.477375, (float)0.310451, (float)0.435638, (float)0.379660, (float)0.430352, (float)0.426148, (float)0.373965, (float)0.336998, (float)0.391676, (float)0.363721, (float)0.434727, (float)0.523475, (float)0.384540};	// L3933
  #pragma HLS resource variable=v3433 core=ram_t2p_bram

  float v3434[512] = {(float)0.014797, (float)0.037974, (float)0.024287, (float)0.033282, (float)0.009573, (float)0.012175, (float)0.032409, (float)0.023881, (float)0.021434, (float)0.012457, (float)0.007617, (float)0.014534, (float)0.025956, (float)0.008145, (float)0.016107, (float)0.016402, (float)0.032195, (float)0.034207, (float)0.021148, (float)0.021447, (float)0.013177, (float)0.034486, (float)0.035753, (float)0.023377, (float)0.017639, (float)0.004832, (float)0.028323, (float)0.019312, (float)0.027409, (float)0.017613, (float)0.022178, (float)0.042271, (float)0.016393, (float)0.015593, (float)0.018405, (float)0.021813, (float)0.017244, (float)0.022655, (float)0.034637, (float)0.017027, (float)0.018760, (float)0.026324, (float)0.028153, (float)0.027661, (float)0.023234, (float)0.010893, (float)0.019429, (float)0.047713, (float)0.014600, (float)0.020709, (float)0.014191, (float)0.027877, (float)0.011790, (float)0.018164, (float)0.021013, (float)0.033222, (float)0.022192, (float)0.023825, (float)0.023330, (float)0.009719, (float)0.020101, (float)0.035948, (float)0.010746, (float)0.019807, (float)0.014409, (float)0.025751, (float)0.020639, (float)0.008093, (float)0.024897, (float)0.016369, (float)0.024380, (float)0.015503, (float)0.015689, (float)0.004939, (float)0.024048, (float)0.012735, (float)0.023085, (float)0.026694, (float)0.022144, (float)0.019275, (float)0.021960, (float)0.019823, (float)0.015991, (float)0.012718, (float)0.016494, (float)0.011768, (float)0.016908, (float)0.024666, (float)0.022209, (float)0.017352, (float)0.016695, (float)0.020054, (float)0.024338, (float)0.027665, (float)0.017877, (float)0.017486, (float)0.037940, (float)0.015464, (float)0.020674, (float)0.012233, (float)0.033432, (float)0.015017, (float)0.013682, (float)0.028803, (float)0.028052, (float)0.031367, (float)0.013165, (float)0.026028, (float)0.011627, (float)0.047816, (float)0.019174, (float)0.011349, (float)0.018531, (float)0.044545, (float)0.019873, (float)0.028756, (float)0.008903, (float)0.052529, (float)0.030137, (float)0.017425, (float)0.013181, (float)0.013588, (float)0.003196, (float)0.016511, (float)0.010533, (float)0.017726, (float)0.015709, (float)0.008342, (float)0.028195, (float)0.013471, (float)0.027743, (float)0.012433, (float)0.013966, (float)0.020415, (float)0.030947, (float)0.029389, (float)0.006835, (float)0.017954, (float)0.012979, (float)0.022241, (float)0.017859, (float)0.029926, (float)0.018215, (float)0.011935, (float)0.023874, (float)0.024038, (float)0.024009, (float)0.037302, (float)0.009383, (float)0.026433, (float)0.011903, (float)0.008586, (float)0.029513, (float)0.018345, (float)0.012961, (float)0.016569, (float)0.026276, (float)0.025337, (float)0.015654, (float)0.021501, (float)0.022197, (float)0.023241, (float)0.019577, (float)0.067689, (float)0.024607, (float)0.004769, (float)0.024836, (float)0.016700, (float)0.019427, (float)0.023107, (float)0.017138, (float)0.018203, (float)0.018894, (float)0.024965, (float)0.021896, (float)0.025463, (float)0.036071, (float)0.015943, (float)0.018717, (float)0.006850, (float)0.041029, (float)0.023362, (float)0.019808, (float)0.012859, (float)0.032598, (float)0.030832, (float)0.024954, (float)0.012277, (float)0.017085, (float)0.015440, (float)0.023446, (float)0.029087, (float)0.059264, (float)0.024963, (float)0.012804, (float)0.020356, (float)0.022088, (float)0.032317, (float)0.040116, (float)0.009682, (float)0.010246, (float)0.022698, (float)0.031086, (float)0.017329, (float)0.027773, (float)0.022563, (float)0.012499, (float)0.028079, (float)0.021120, (float)0.023154, (float)0.017160, (float)0.011038, (float)0.010535, (float)0.018923, (float)0.013009, (float)0.014156, (float)0.027678, (float)0.024117, (float)0.021302, (float)0.014714, (float)0.036207, (float)0.028543, (float)0.016743, (float)0.018916, (float)0.026885, (float)0.010043, (float)0.012075, (float)0.014134, (float)0.033789, (float)0.020699, (float)0.010101, (float)0.018902, (float)0.015572, (float)0.049192, (float)0.016134, (float)0.028751, (float)0.009142, (float)0.042635, (float)0.026588, (float)0.004665, (float)0.009972, (float)0.005729, (float)0.049139, (float)0.024250, (float)0.016319, (float)0.014276, (float)0.014179, (float)0.024507, (float)0.012122, (float)0.020003, (float)0.024153, (float)0.027940, (float)0.025884, (float)0.020835, (float)0.012927, (float)0.024182, (float)0.034140, (float)0.021667, (float)0.007899, (float)0.029858, (float)0.013404, (float)0.021888, (float)0.005248, (float)0.024414, (float)0.033217, (float)0.017424, (float)0.017588, (float)0.022876, (float)0.025777, (float)0.036217, (float)0.011590, (float)0.015665, (float)0.016886, (float)0.024274, (float)0.033398, (float)0.016618, (float)0.019122, (float)0.017813, (float)0.015589, (float)0.017732, (float)0.017904, (float)0.019168, (float)0.016683, (float)0.033678, (float)0.004529, (float)0.015886, (float)0.018173, (float)0.022744, (float)0.007121, (float)0.012488, (float)0.023408, (float)0.031028, (float)0.027164, (float)0.015513, (float)0.017717, (float)0.016643, (float)0.029922, (float)0.022554, (float)0.017378, (float)0.014135, (float)0.046231, (float)0.023767, (float)0.013142, (float)0.024729, (float)0.023066, (float)0.023765, (float)0.003310, (float)0.020579, (float)0.012455, (float)0.016946, (float)0.029351, (float)0.019246, (float)0.024107, (float)0.027394, (float)0.011762, (float)0.011401, (float)0.017944, (float)0.023090, (float)0.027987, (float)0.004324, (float)0.012802, (float)0.010422, (float)0.027148, (float)0.030546, (float)0.014914, (float)0.022719, (float)0.007397, (float)0.016942, (float)0.010857, (float)0.014844, (float)0.016265, (float)0.028345, (float)0.019868, (float)0.015381, (float)0.016695, (float)0.021697, (float)0.009911, (float)0.018018, (float)0.016002, (float)0.010949, (float)0.005767, (float)0.005036, (float)0.026319, (float)0.030716, (float)0.009113, (float)0.010563, (float)0.016398, (float)0.030490, (float)0.013609, (float)0.006690, (float)0.019067, (float)0.017289, (float)0.025994, (float)0.015580, (float)0.021489, (float)0.026740, (float)0.025944, (float)0.023086, (float)0.030448, (float)0.017901, (float)0.016307, (float)0.018869, (float)0.008179, (float)0.012594, (float)0.028673, (float)0.027379, (float)0.012914, (float)0.042257, (float)0.044290, (float)0.004725, (float)0.017098, (float)0.010509, (float)0.034835, (float)0.010232, (float)0.010880, (float)0.009897, (float)0.024268, (float)0.031363, (float)0.028433, (float)0.023923, (float)0.018523, (float)0.022239, (float)0.027958, (float)0.021271, (float)0.018237, (float)0.016664, (float)0.028019, (float)0.021324, (float)0.028550, (float)0.017067, (float)0.018597, (float)0.015267, (float)0.019043, (float)0.010217, (float)0.027563, (float)0.028792, (float)0.020045, (float)0.018991, (float)0.011335, (float)0.022008, (float)0.021896, (float)0.019881, (float)0.012837, (float)0.022065, (float)0.043280, (float)0.018434, (float)0.019879, (float)0.012119, (float)0.019007, (float)0.009195, (float)0.022533, (float)0.009538, (float)0.029914, (float)0.011779, (float)0.010417, (float)0.025136, (float)0.024045, (float)0.014470, (float)0.020585, (float)0.020260, (float)0.013212, (float)0.017874, (float)0.016841, (float)0.018557, (float)0.007608, (float)0.026879, (float)0.016277, (float)0.013738, (float)0.005450, (float)0.012819, (float)0.036177, (float)0.008542, (float)0.030353, (float)0.011260, (float)0.038203, (float)0.019922, (float)0.016696, (float)0.020955, (float)0.016163, (float)0.009182, (float)0.010645, (float)0.016338, (float)0.021920, (float)0.022267, (float)0.014893, (float)0.023184, (float)0.014378, (float)0.013713, (float)0.018360, (float)0.020984, (float)0.024619, (float)0.023726, (float)0.022280, (float)0.018140, (float)0.020319, (float)0.003983, (float)0.019480, (float)0.027284, (float)0.028425, (float)0.023305, (float)0.028359, (float)0.006877, (float)0.012102, (float)0.011683, (float)0.038713, (float)0.016494, (float)0.020911, (float)0.019379, (float)0.014409, (float)0.015669, (float)0.009922, (float)0.030646, (float)0.014635, (float)0.014432, (float)0.040783, (float)0.017921, (float)0.018565, (float)0.014059, (float)0.020364, (float)0.024347, (float)0.021271, (float)0.016969, (float)0.016637, (float)0.011990, (float)0.031063, (float)0.005982, (float)0.027176, (float)0.025192, (float)0.025004, (float)0.010163, (float)0.023461, (float)0.029223, (float)0.010756, (float)0.017914, (float)0.009306, (float)0.025531, (float)0.016042, (float)0.012558, (float)0.018730, (float)0.013725, (float)0.030774, (float)0.011870, (float)0.037628, (float)0.017584, (float)0.017254, (float)0.026002, (float)0.018345, (float)0.018618, (float)0.013726, (float)0.034435, (float)0.014385, (float)0.011154};	// L3934
  #pragma HLS resource variable=v3434 core=ram_t2p_bram

  float v3435[512] = {(float)-0.102286, (float)-0.130249, (float)0.016886, (float)0.053927, (float)0.053070, (float)-0.065007, (float)-0.168092, (float)-0.096206, (float)0.060128, (float)-0.089756, (float)-0.075971, (float)-0.011981, (float)0.048014, (float)-0.086672, (float)-0.041463, (float)-0.088698, (float)-0.037827, (float)-0.237557, (float)-0.096518, (float)-0.043417, (float)0.030305, (float)-0.238074, (float)-0.006524, (float)-0.070019, (float)0.060617, (float)0.025746, (float)-0.169070, (float)-0.120655, (float)-0.155018, (float)-0.092696, (float)-0.001185, (float)-0.096202, (float)-0.092171, (float)-0.178946, (float)0.014559, (float)-0.049803, (float)0.027617, (float)-0.169230, (float)0.025903, (float)0.037747, (float)-0.029229, (float)0.014037, (float)-0.063783, (float)-0.083131, (float)0.104908, (float)-0.055399, (float)-0.055074, (float)0.133189, (float)0.077474, (float)-0.186081, (float)-0.081155, (float)-0.208298, (float)-0.024397, (float)-0.029691, (float)-0.059322, (float)0.124287, (float)-0.047476, (float)-0.001440, (float)-0.006886, (float)-0.100196, (float)-0.104021, (float)-0.083676, (float)0.000882, (float)0.025870, (float)-0.048999, (float)-0.063094, (float)0.019339, (float)-0.037542, (float)-0.048652, (float)-0.080320, (float)-0.112343, (float)-0.153831, (float)-0.103056, (float)-0.085757, (float)-0.070625, (float)-0.072476, (float)-0.090262, (float)0.007539, (float)-0.085022, (float)-0.028707, (float)0.000811, (float)0.024941, (float)-0.106755, (float)-0.123709, (float)-0.127055, (float)0.093040, (float)-0.029539, (float)-0.084636, (float)-0.056157, (float)-0.121008, (float)0.010295, (float)-0.111767, (float)-0.040748, (float)-0.010973, (float)-0.051184, (float)-0.132640, (float)0.045407, (float)-0.107193, (float)-0.101830, (float)-0.169869, (float)-0.033820, (float)-0.095022, (float)-0.189678, (float)0.062315, (float)-0.021020, (float)0.093181, (float)-0.098590, (float)0.082313, (float)-0.091109, (float)0.071120, (float)-0.110610, (float)0.017561, (float)-0.016362, (float)-0.247180, (float)-0.118508, (float)-0.047748, (float)-0.065117, (float)0.177139, (float)0.014971, (float)-0.044933, (float)-0.153648, (float)0.085648, (float)0.021406, (float)-0.077496, (float)-0.011504, (float)-0.018905, (float)0.053105, (float)-0.085857, (float)-0.038039, (float)0.072169, (float)-0.027858, (float)0.024390, (float)-0.067953, (float)-0.043382, (float)-0.034377, (float)-0.161844, (float)-0.022166, (float)-0.049201, (float)0.043180, (float)-0.154618, (float)-0.109031, (float)-0.135244, (float)-0.127626, (float)0.043546, (float)0.017695, (float)-0.065638, (float)-0.061107, (float)0.202461, (float)-0.013972, (float)-0.124579, (float)0.008559, (float)-0.018228, (float)0.031176, (float)-0.148220, (float)-0.186647, (float)-0.005104, (float)-0.081573, (float)-0.181948, (float)-0.097725, (float)-0.037767, (float)0.000181, (float)-0.038663, (float)-0.063522, (float)0.146074, (float)-0.128204, (float)-0.074300, (float)0.030985, (float)-0.122840, (float)-0.042529, (float)0.025415, (float)-0.092340, (float)0.000491, (float)-0.016613, (float)-0.135662, (float)-0.062528, (float)0.006009, (float)0.037423, (float)-0.000798, (float)-0.133080, (float)-0.041386, (float)-0.202340, (float)-0.016247, (float)-0.196248, (float)-0.072525, (float)0.020790, (float)-0.058455, (float)-0.113474, (float)-0.136087, (float)-0.106708, (float)-0.171915, (float)0.014489, (float)-0.039008, (float)0.042632, (float)-0.119871, (float)0.081119, (float)-0.099114, (float)-0.177936, (float)-0.084463, (float)0.001022, (float)-0.008251, (float)0.007777, (float)-0.098570, (float)-0.094069, (float)0.069623, (float)-0.110015, (float)-0.114589, (float)0.017814, (float)-0.171108, (float)-0.014443, (float)-0.028208, (float)0.048741, (float)-0.051265, (float)-0.096291, (float)0.038626, (float)-0.103671, (float)0.012829, (float)-0.049016, (float)-0.029189, (float)-0.055315, (float)-0.140197, (float)0.002234, (float)-0.079135, (float)-0.017436, (float)0.010842, (float)-0.006639, (float)0.025010, (float)0.002807, (float)-0.014991, (float)-0.117217, (float)0.033509, (float)0.003361, (float)-0.100465, (float)-0.173487, (float)-0.113841, (float)-0.080396, (float)-0.032859, (float)-0.028635, (float)-0.213338, (float)-0.015135, (float)-0.087584, (float)0.014559, (float)-0.027689, (float)-0.142149, (float)0.027245, (float)0.034968, (float)-0.148343, (float)-0.130571, (float)-0.059593, (float)-0.136536, (float)-0.100315, (float)-0.008331, (float)-0.090577, (float)-0.101207, (float)-0.142599, (float)0.043190, (float)-0.078463, (float)-0.046141, (float)0.015669, (float)0.014962, (float)-0.128983, (float)0.068532, (float)-0.147780, (float)-0.125880, (float)-0.057315, (float)0.099854, (float)-0.023377, (float)-0.134027, (float)0.017321, (float)0.167296, (float)0.069254, (float)0.006963, (float)0.020260, (float)-0.050786, (float)-0.139708, (float)-0.129200, (float)-0.033092, (float)0.008835, (float)0.120834, (float)-0.180802, (float)-0.014881, (float)-0.130247, (float)0.032282, (float)-0.098632, (float)-0.062034, (float)0.078147, (float)0.080889, (float)-0.091807, (float)-0.045004, (float)-0.124604, (float)-0.048472, (float)-0.075580, (float)0.069195, (float)-0.038243, (float)-0.006287, (float)-0.047689, (float)-0.060283, (float)-0.048453, (float)-0.035499, (float)-0.102493, (float)-0.063373, (float)0.151472, (float)-0.132043, (float)-0.071426, (float)0.040202, (float)-0.034154, (float)-0.008526, (float)0.001868, (float)-0.029316, (float)-0.152261, (float)-0.033686, (float)-0.048225, (float)-0.097569, (float)-0.040431, (float)-0.091853, (float)-0.000275, (float)0.022159, (float)-0.055239, (float)-0.068588, (float)0.031948, (float)0.150193, (float)-0.117370, (float)-0.129927, (float)0.018276, (float)-0.015077, (float)-0.146365, (float)-0.084167, (float)-0.030010, (float)-0.073432, (float)-0.053854, (float)-0.128083, (float)0.040759, (float)-0.089652, (float)-0.140781, (float)0.057215, (float)0.028043, (float)-0.009149, (float)-0.103762, (float)-0.024293, (float)-0.084685, (float)-0.022411, (float)-0.002665, (float)-0.115365, (float)-0.046597, (float)0.030503, (float)-0.105998, (float)-0.009157, (float)-0.074790, (float)0.000416, (float)-0.088800, (float)-0.142314, (float)-0.039687, (float)-0.164266, (float)-0.045068, (float)0.033121, (float)0.000795, (float)-0.154220, (float)0.099867, (float)-0.004623, (float)-0.057053, (float)-0.084284, (float)0.054957, (float)-0.181353, (float)-0.138678, (float)-0.033480, (float)0.047180, (float)-0.032470, (float)-0.003394, (float)-0.021033, (float)0.039258, (float)0.009295, (float)-0.018768, (float)-0.097337, (float)0.518637, (float)0.018138, (float)-0.040453, (float)-0.057851, (float)-0.014343, (float)-0.026796, (float)-0.042246, (float)0.004108, (float)-0.077753, (float)-0.048641, (float)0.035890, (float)-0.156307, (float)-0.082575, (float)-0.148550, (float)-0.098730, (float)-0.002838, (float)-0.024290, (float)-0.065538, (float)0.007586, (float)-0.139745, (float)-0.104217, (float)-0.082347, (float)-0.055217, (float)0.007889, (float)-0.047024, (float)0.065973, (float)-0.106290, (float)-0.057187, (float)-0.055214, (float)-0.080113, (float)-0.089246, (float)0.028202, (float)0.123264, (float)-0.205945, (float)-0.020338, (float)-0.024089, (float)0.082836, (float)0.004376, (float)-0.031189, (float)-0.171535, (float)0.046388, (float)-0.071442, (float)0.032068, (float)-0.096685, (float)-0.066919, (float)-0.034415, (float)-0.076992, (float)0.056344, (float)-0.146839, (float)-0.069553, (float)-0.007231, (float)-0.024979, (float)-0.043237, (float)-0.062540, (float)-0.002472, (float)0.008895, (float)-0.082210, (float)-0.124440, (float)0.070838, (float)0.016016, (float)-0.134764, (float)-0.062674, (float)-0.105392, (float)0.142106, (float)-0.008648, (float)-0.076716, (float)-0.125101, (float)-0.054731, (float)-0.131304, (float)-0.023042, (float)0.015469, (float)-0.048935, (float)-0.001273, (float)0.045024, (float)0.033201, (float)-0.046740, (float)-0.105459, (float)0.048534, (float)-0.112343, (float)-0.077349, (float)0.006614, (float)-0.037838, (float)-0.017476, (float)-0.031532, (float)0.045498, (float)-0.178286, (float)-0.030906, (float)-0.087056, (float)-0.073235, (float)-0.033448, (float)-0.021015, (float)0.086905, (float)-0.056695, (float)0.047351, (float)-0.197582, (float)-0.091191, (float)-0.123400, (float)-0.057476, (float)-0.064887, (float)-0.092378, (float)-0.011430, (float)-0.075702, (float)-0.111605, (float)-0.029059, (float)-0.049385, (float)-0.032027, (float)-0.191926, (float)-0.064090, (float)-0.022608, (float)-0.168679, (float)0.005069, (float)-0.127235, (float)0.092186, (float)-0.086097, (float)-0.060362, (float)-0.111019, (float)-0.000974, (float)-0.026893, (float)-0.126493, (float)0.080552, (float)-0.088567, (float)0.001659, (float)-0.018472, (float)-0.013239, (float)-0.089863, (float)-0.102586, (float)-0.092393, (float)-0.059868, (float)-0.024012, (float)-0.005873, (float)0.080796, (float)-0.040349, (float)-0.112878, (float)0.087438, (float)-0.008288, (float)-0.194065, (float)-0.147339, (float)-0.034333, (float)-0.019008, (float)-0.006106};	// L3935
  #pragma HLS resource variable=v3435 core=ram_t2p_bram

  float v3436[512] = {(float)0.169410, (float)0.336753, (float)0.299325, (float)0.374526, (float)0.151277, (float)0.178057, (float)0.316733, (float)0.394715, (float)0.185845, (float)0.206849, (float)0.109002, (float)0.204206, (float)0.295515, (float)0.076483, (float)0.202319, (float)0.248717, (float)0.329550, (float)0.334914, (float)0.253230, (float)0.273901, (float)0.166143, (float)0.343162, (float)0.342436, (float)0.296871, (float)0.222597, (float)0.099329, (float)0.332798, (float)0.234925, (float)0.289414, (float)0.229609, (float)0.271884, (float)0.394487, (float)0.199041, (float)0.256375, (float)0.255654, (float)0.354066, (float)0.184846, (float)0.251309, (float)0.310109, (float)0.278173, (float)0.210884, (float)0.244075, (float)0.328250, (float)0.324777, (float)0.249868, (float)0.187333, (float)0.264297, (float)0.394897, (float)0.196152, (float)0.258667, (float)0.170828, (float)0.338123, (float)0.223777, (float)0.249751, (float)0.278729, (float)0.378271, (float)0.344459, (float)0.268094, (float)0.295598, (float)0.114583, (float)0.268843, (float)0.347863, (float)0.129532, (float)0.284261, (float)0.155215, (float)0.302551, (float)0.273831, (float)0.189133, (float)0.356764, (float)0.230155, (float)0.219877, (float)0.207006, (float)0.211938, (float)0.097067, (float)0.248231, (float)0.226383, (float)0.355506, (float)0.311291, (float)0.238566, (float)0.265447, (float)0.297534, (float)0.266616, (float)0.218011, (float)0.145094, (float)0.245951, (float)0.173432, (float)0.235794, (float)0.289079, (float)0.209118, (float)0.197142, (float)0.218470, (float)0.200752, (float)0.246056, (float)0.372634, (float)0.202765, (float)0.199320, (float)0.365248, (float)0.225819, (float)0.260566, (float)0.190004, (float)0.276370, (float)0.201080, (float)0.197336, (float)0.295795, (float)0.322198, (float)0.411696, (float)0.147543, (float)0.267399, (float)0.192815, (float)0.361520, (float)0.277430, (float)0.214287, (float)0.268830, (float)0.428604, (float)0.256000, (float)0.277671, (float)0.133946, (float)0.510279, (float)0.323768, (float)0.241690, (float)0.152944, (float)0.184349, (float)0.057901, (float)0.228790, (float)0.179726, (float)0.280332, (float)0.227906, (float)0.157900, (float)0.319630, (float)0.184173, (float)0.337821, (float)0.168833, (float)0.165389, (float)0.304870, (float)0.353342, (float)0.294815, (float)0.114033, (float)0.250263, (float)0.189174, (float)0.264696, (float)0.240506, (float)0.388007, (float)0.193253, (float)0.191754, (float)0.251126, (float)0.290069, (float)0.315123, (float)0.325163, (float)0.129560, (float)0.249134, (float)0.141738, (float)0.129532, (float)0.306188, (float)0.283580, (float)0.348328, (float)0.230613, (float)0.274099, (float)0.269971, (float)0.187296, (float)0.243142, (float)0.352592, (float)0.354630, (float)0.272095, (float)0.270821, (float)0.306536, (float)0.083244, (float)0.296813, (float)0.228561, (float)0.327553, (float)0.269526, (float)0.245220, (float)0.244357, (float)0.285695, (float)0.336548, (float)0.278372, (float)0.293323, (float)0.339739, (float)0.223145, (float)0.233046, (float)0.148591, (float)0.384555, (float)0.310379, (float)0.172444, (float)0.172428, (float)0.346584, (float)0.297812, (float)0.258155, (float)0.187930, (float)0.241948, (float)0.224921, (float)0.272043, (float)0.373508, (float)0.425912, (float)0.375369, (float)0.173145, (float)0.369828, (float)0.234918, (float)0.269450, (float)0.314805, (float)0.165768, (float)0.118073, (float)0.299416, (float)0.401808, (float)0.212650, (float)0.386431, (float)0.295480, (float)0.184785, (float)0.368620, (float)0.197224, (float)0.326541, (float)0.231940, (float)0.167550, (float)0.175588, (float)0.236656, (float)0.213911, (float)0.197388, (float)0.256083, (float)0.261869, (float)0.217013, (float)0.228423, (float)0.348622, (float)0.450006, (float)0.256276, (float)0.255950, (float)0.281415, (float)0.179733, (float)0.173643, (float)0.201252, (float)0.341085, (float)0.224510, (float)0.138465, (float)0.228378, (float)0.222973, (float)0.256646, (float)0.230147, (float)0.363866, (float)0.137964, (float)0.238139, (float)0.259003, (float)0.083023, (float)0.186304, (float)0.126698, (float)0.450099, (float)0.274064, (float)0.259042, (float)0.278164, (float)0.224772, (float)0.271820, (float)0.194872, (float)0.181473, (float)0.296870, (float)0.316810, (float)0.338941, (float)0.279011, (float)0.159396, (float)0.275177, (float)0.294745, (float)0.290891, (float)0.141803, (float)0.333568, (float)0.195306, (float)0.264556, (float)0.087880, (float)0.255316, (float)0.333496, (float)0.194341, (float)0.277656, (float)0.238551, (float)0.367640, (float)0.304152, (float)0.123388, (float)0.261541, (float)0.254774, (float)0.322369, (float)0.346163, (float)0.209001, (float)0.214224, (float)0.205431, (float)0.211544, (float)0.215323, (float)0.216290, (float)0.250868, (float)0.242926, (float)0.332636, (float)-0.052733, (float)0.224385, (float)0.231899, (float)0.267421, (float)0.110341, (float)0.231996, (float)0.282224, (float)0.323417, (float)0.281837, (float)0.209333, (float)0.226130, (float)0.290010, (float)0.312654, (float)0.345589, (float)0.259207, (float)0.167721, (float)0.392362, (float)0.269410, (float)0.199733, (float)0.297266, (float)0.332400, (float)0.226979, (float)0.065588, (float)0.296431, (float)0.194763, (float)0.238322, (float)0.302117, (float)0.251032, (float)0.311681, (float)0.318538, (float)0.172093, (float)0.186731, (float)0.166460, (float)0.285118, (float)0.351171, (float)-0.048625, (float)0.155843, (float)0.221314, (float)0.328078, (float)0.386052, (float)0.237469, (float)0.305702, (float)0.117849, (float)0.268051, (float)0.192117, (float)0.221083, (float)0.167906, (float)0.287741, (float)0.249482, (float)0.245134, (float)0.267811, (float)0.239291, (float)0.098827, (float)0.277783, (float)0.246465, (float)0.174705, (float)0.100487, (float)0.050196, (float)0.280930, (float)0.281007, (float)0.171598, (float)0.211425, (float)0.221346, (float)0.281698, (float)0.150649, (float)0.076939, (float)0.238055, (float)0.241127, (float)0.294181, (float)0.254267, (float)0.255613, (float)0.345135, (float)0.294828, (float)0.303989, (float)0.320355, (float)0.275740, (float)0.165689, (float)0.294141, (float)0.130094, (float)0.185425, (float)0.286594, (float)0.319824, (float)0.212748, (float)0.360818, (float)0.344050, (float)0.095413, (float)0.258644, (float)0.170935, (float)0.200692, (float)0.196744, (float)0.197181, (float)0.194237, (float)0.320139, (float)0.348373, (float)0.343676, (float)0.315266, (float)0.202015, (float)0.325148, (float)0.322675, (float)0.303804, (float)0.263383, (float)0.236389, (float)0.249160, (float)0.307993, (float)0.259140, (float)0.239066, (float)0.271980, (float)0.260091, (float)0.321008, (float)0.181837, (float)0.352627, (float)0.357930, (float)0.286101, (float)0.252634, (float)0.164206, (float)0.289713, (float)0.399584, (float)0.265095, (float)0.203076, (float)0.250223, (float)0.369446, (float)0.208519, (float)0.280384, (float)0.223330, (float)0.230855, (float)0.160899, (float)0.236905, (float)0.211641, (float)0.354886, (float)0.163478, (float)0.164160, (float)0.307243, (float)0.307705, (float)0.215194, (float)0.282122, (float)0.285682, (float)0.170101, (float)0.230474, (float)0.213436, (float)0.318922, (float)0.106063, (float)0.262806, (float)0.260816, (float)0.174854, (float)0.082007, (float)0.181492, (float)0.356583, (float)0.120368, (float)0.315855, (float)0.159469, (float)0.378953, (float)0.327226, (float)0.208611, (float)0.309562, (float)0.225279, (float)0.145632, (float)0.134626, (float)0.230364, (float)0.291274, (float)0.272654, (float)0.202684, (float)0.268785, (float)0.195801, (float)0.227745, (float)0.303641, (float)0.324994, (float)0.300008, (float)0.332829, (float)0.241726, (float)0.266489, (float)0.247341, (float)0.091259, (float)0.250275, (float)0.254326, (float)0.371028, (float)0.332103, (float)0.369274, (float)0.109943, (float)0.170144, (float)0.175816, (float)0.388793, (float)0.220611, (float)0.276613, (float)0.281295, (float)0.175525, (float)0.261646, (float)0.154389, (float)0.251868, (float)0.194534, (float)0.245232, (float)0.340547, (float)0.244606, (float)0.242613, (float)0.182212, (float)0.300236, (float)0.303656, (float)0.311811, (float)0.241362, (float)0.232588, (float)0.130263, (float)0.308066, (float)0.097932, (float)0.277647, (float)0.291823, (float)0.384778, (float)0.178882, (float)0.362211, (float)0.300467, (float)0.192286, (float)0.267236, (float)0.166335, (float)0.299789, (float)0.271044, (float)0.204033, (float)0.256543, (float)0.228943, (float)0.255155, (float)0.212116, (float)0.353151, (float)0.229290, (float)0.250965, (float)0.308534, (float)0.236787, (float)0.299957, (float)0.211089, (float)0.345572, (float)0.342168, (float)0.157556};	// L3936
  #pragma HLS resource variable=v3436 core=ram_t2p_bram

  float v3437[512] = {(float)0.157272, (float)0.121494, (float)0.110890, (float)0.138332, (float)0.154231, (float)0.119160, (float)0.137997, (float)0.156451, (float)0.103958, (float)0.122691, (float)0.121031, (float)0.108789, (float)0.150741, (float)0.122900, (float)0.118188, (float)0.103053, (float)0.123558, (float)0.141964, (float)0.272493, (float)0.113742, (float)0.128986, (float)0.119658, (float)0.120304, (float)0.120511, (float)0.133857, (float)0.146808, (float)0.091806, (float)0.142326, (float)0.128061, (float)0.105257, (float)0.140615, (float)0.143751, (float)0.169360, (float)0.159124, (float)0.121500, (float)0.126739, (float)0.149052, (float)0.154392, (float)0.151626, (float)0.120618, (float)0.140859, (float)0.148686, (float)0.133982, (float)0.121194, (float)0.169162, (float)0.135213, (float)0.119971, (float)0.134204, (float)0.113415, (float)0.125448, (float)0.121302, (float)0.179269, (float)0.132751, (float)0.129523, (float)0.158171, (float)0.149059, (float)0.118247, (float)0.142966, (float)0.120525, (float)0.128163, (float)0.137333, (float)0.103394, (float)0.120583, (float)0.087091, (float)0.084795, (float)0.133024, (float)0.200593, (float)0.126079, (float)0.123615, (float)0.103434, (float)0.126255, (float)0.135451, (float)0.141095, (float)0.122359, (float)0.136957, (float)0.159438, (float)0.132475, (float)0.121734, (float)0.141482, (float)0.133773, (float)0.161217, (float)0.126054, (float)0.138424, (float)0.148697, (float)0.136529, (float)0.115158, (float)0.111243, (float)0.210655, (float)0.150067, (float)0.149925, (float)0.146573, (float)0.124652, (float)0.130291, (float)0.179599, (float)0.139915, (float)0.138198, (float)0.126833, (float)0.144613, (float)0.119749, (float)0.181381, (float)0.135587, (float)0.155462, (float)0.119060, (float)0.151802, (float)0.148132, (float)0.167735, (float)0.166350, (float)0.137500, (float)0.130187, (float)0.157453, (float)0.104428, (float)0.148859, (float)0.132261, (float)0.165668, (float)0.136275, (float)0.164993, (float)0.138821, (float)0.157225, (float)0.109712, (float)0.153218, (float)0.111765, (float)0.158229, (float)0.123995, (float)0.137109, (float)0.147888, (float)0.144130, (float)0.120230, (float)0.107165, (float)0.124514, (float)0.144111, (float)0.170445, (float)0.105546, (float)0.172847, (float)0.152914, (float)0.116989, (float)0.107541, (float)0.131471, (float)0.138915, (float)0.105366, (float)0.139452, (float)0.145897, (float)0.113597, (float)0.132929, (float)0.135730, (float)0.153182, (float)0.120458, (float)0.130249, (float)0.106744, (float)0.168344, (float)0.129868, (float)0.185800, (float)0.121044, (float)0.135292, (float)0.128703, (float)0.135367, (float)0.124730, (float)0.132676, (float)0.145161, (float)0.128291, (float)0.138383, (float)0.147979, (float)0.138992, (float)0.125923, (float)0.123036, (float)0.161289, (float)0.156189, (float)0.129665, (float)0.144354, (float)0.121738, (float)0.148620, (float)0.125385, (float)0.137104, (float)0.177627, (float)0.125947, (float)0.126593, (float)0.143159, (float)0.114476, (float)0.112578, (float)0.151409, (float)0.162312, (float)0.112443, (float)0.140079, (float)0.129008, (float)0.109462, (float)0.129889, (float)0.143210, (float)0.153370, (float)0.138683, (float)0.141045, (float)0.099450, (float)0.138254, (float)0.138848, (float)0.109361, (float)0.141240, (float)0.145026, (float)0.134450, (float)0.180661, (float)0.166874, (float)0.179685, (float)0.144648, (float)0.124261, (float)0.150043, (float)0.196581, (float)0.142786, (float)0.117790, (float)0.132922, (float)0.123891, (float)0.148714, (float)0.144703, (float)0.123294, (float)0.122973, (float)0.142068, (float)0.138037, (float)0.126073, (float)0.104146, (float)0.136178, (float)0.125905, (float)0.197598, (float)0.111434, (float)0.117451, (float)0.091696, (float)0.118450, (float)0.130511, (float)0.141301, (float)0.146123, (float)0.131051, (float)0.197174, (float)0.135347, (float)0.106754, (float)0.134551, (float)0.184436, (float)0.134739, (float)0.128100, (float)0.132872, (float)0.115101, (float)0.136478, (float)0.155266, (float)0.157809, (float)0.109249, (float)0.153827, (float)0.143292, (float)0.161629, (float)0.156723, (float)0.119411, (float)0.120206, (float)0.109810, (float)0.120180, (float)0.111734, (float)0.128541, (float)0.174715, (float)0.141909, (float)0.125527, (float)0.180091, (float)0.136425, (float)0.138315, (float)0.141775, (float)0.139527, (float)0.164408, (float)0.185390, (float)0.191718, (float)0.147939, (float)0.127644, (float)0.131170, (float)0.126823, (float)0.106023, (float)0.137908, (float)0.116774, (float)0.126028, (float)0.112418, (float)0.156467, (float)0.120242, (float)0.209883, (float)0.133611, (float)0.131967, (float)0.152136, (float)0.153782, (float)0.159980, (float)0.119557, (float)0.140178, (float)0.116429, (float)0.140495, (float)0.102665, (float)0.124602, (float)0.113414, (float)0.112752, (float)0.123284, (float)0.162008, (float)0.192566, (float)0.176427, (float)0.125148, (float)0.107817, (float)0.188905, (float)0.120710, (float)0.118803, (float)0.113520, (float)0.118226, (float)0.127486, (float)0.130172, (float)0.122628, (float)0.132900, (float)0.251585, (float)0.138885, (float)0.133268, (float)0.192137, (float)0.115032, (float)0.157397, (float)0.136418, (float)0.134507, (float)0.135265, (float)0.143946, (float)0.130495, (float)0.136269, (float)0.255849, (float)0.127721, (float)0.161987, (float)0.140434, (float)0.145994, (float)0.143567, (float)0.217126, (float)0.120137, (float)0.137316, (float)0.130616, (float)0.131082, (float)0.130820, (float)0.128702, (float)0.116088, (float)0.216788, (float)0.148036, (float)0.109485, (float)0.144219, (float)0.102065, (float)0.114707, (float)0.149040, (float)0.164266, (float)0.119442, (float)0.105308, (float)0.120292, (float)0.104201, (float)0.104647, (float)0.157188, (float)0.119718, (float)0.141703, (float)0.129102, (float)0.143758, (float)0.152957, (float)0.142382, (float)0.147007, (float)0.117802, (float)0.134479, (float)0.116054, (float)0.118435, (float)0.113276, (float)0.114869, (float)0.133755, (float)0.157416, (float)0.173171, (float)0.122215, (float)0.131741, (float)0.165122, (float)0.159154, (float)0.125511, (float)0.171438, (float)0.138623, (float)0.127446, (float)0.170997, (float)0.160217, (float)0.142664, (float)0.119088, (float)0.142298, (float)0.124406, (float)0.124245, (float)0.134550, (float)0.122764, (float)0.157830, (float)0.138354, (float)0.187025, (float)0.114211, (float)0.169193, (float)0.132511, (float)0.141570, (float)0.149899, (float)0.125941, (float)0.120167, (float)0.124617, (float)0.174438, (float)0.161133, (float)0.127741, (float)0.122790, (float)0.127565, (float)0.110531, (float)0.170789, (float)0.136660, (float)0.122042, (float)0.117236, (float)0.132416, (float)0.118440, (float)0.249330, (float)0.140252, (float)0.126854, (float)0.125446, (float)0.158869, (float)0.122826, (float)0.154812, (float)0.162049, (float)0.126960, (float)0.121890, (float)0.121928, (float)0.144863, (float)0.113283, (float)0.180020, (float)0.195894, (float)0.132988, (float)0.131381, (float)0.106672, (float)0.120703, (float)0.108573, (float)0.142950, (float)0.111283, (float)0.137490, (float)0.165181, (float)0.129301, (float)0.126071, (float)0.151297, (float)0.126862, (float)0.133357, (float)0.121345, (float)0.111666, (float)0.136574, (float)0.139949, (float)0.130967, (float)0.145197, (float)0.147552, (float)0.133029, (float)0.117296, (float)0.150844, (float)0.138939, (float)0.123110, (float)0.138138, (float)0.165599, (float)0.111851, (float)0.138641, (float)0.112593, (float)0.137264, (float)0.112204, (float)0.123050, (float)0.095599, (float)0.140241, (float)0.156471, (float)0.140808, (float)0.120633, (float)0.139597, (float)0.123611, (float)0.162952, (float)0.135291, (float)0.130257, (float)0.208375, (float)0.124216, (float)0.112209, (float)0.131368, (float)0.132996, (float)0.139019, (float)0.169519, (float)0.134225, (float)0.160857, (float)0.167455, (float)0.144514, (float)0.142181, (float)0.156618, (float)0.162929, (float)0.168533, (float)0.133698, (float)0.129143, (float)0.131512, (float)0.164832, (float)0.118704, (float)0.131188, (float)0.134356, (float)0.158196, (float)0.108468, (float)0.114835, (float)0.134079, (float)0.175744, (float)0.139813, (float)0.116924, (float)0.136767, (float)0.197171, (float)0.113234, (float)0.129328, (float)0.135916, (float)0.115879, (float)0.120353, (float)0.114077, (float)0.151214, (float)0.157829, (float)0.148324, (float)0.109571, (float)0.136292, (float)0.153027, (float)0.141014, (float)0.181838, (float)0.121173, (float)0.130402, (float)0.141520, (float)0.120097, (float)0.156104, (float)0.114908, (float)0.125043, (float)0.112289, (float)0.116106, (float)0.146591, (float)0.141853, (float)0.171405};	// L3937
  #pragma HLS resource variable=v3437 core=ram_t2p_bram

  float v3438[512] = {(float)-0.616304, (float)-0.710955, (float)-0.454402, (float)-0.614255, (float)-0.787494, (float)-0.528893, (float)-0.621433, (float)-0.582421, (float)-0.406652, (float)-0.525627, (float)-0.512498, (float)-0.533722, (float)-0.565790, (float)-0.684483, (float)-0.514649, (float)-0.632307, (float)-0.539150, (float)-0.683786, (float)-0.657745, (float)-0.471635, (float)-0.524932, (float)-0.405884, (float)-0.602798, (float)-0.524639, (float)-0.891306, (float)-0.652838, (float)-0.504806, (float)-0.500840, (float)-0.506658, (float)-0.597285, (float)-0.552446, (float)-0.638255, (float)-0.678162, (float)-0.726262, (float)-0.572461, (float)-0.645593, (float)-0.713844, (float)-0.614577, (float)-0.534616, (float)-0.517699, (float)-0.459262, (float)-0.661813, (float)-0.511263, (float)-0.581029, (float)-0.624362, (float)-0.553085, (float)-0.556308, (float)-0.548126, (float)-0.608908, (float)-0.462584, (float)-0.731059, (float)-0.663177, (float)-0.631639, (float)-0.738078, (float)-0.613689, (float)-0.623704, (float)-0.496449, (float)-0.448909, (float)-0.642752, (float)-0.596825, (float)-0.553037, (float)-0.382175, (float)-0.610950, (float)-0.453029, (float)-0.467932, (float)-0.522124, (float)-0.635563, (float)-0.486059, (float)-0.777206, (float)-0.509635, (float)-0.578227, (float)-0.705387, (float)-0.666734, (float)-0.624430, (float)-0.729190, (float)-0.731116, (float)-0.655683, (float)-0.687150, (float)-0.676692, (float)-0.556686, (float)-0.605893, (float)-0.667994, (float)-0.716171, (float)-0.610517, (float)-0.577846, (float)-0.650139, (float)-0.624793, (float)-1.075139, (float)-0.676370, (float)-0.727725, (float)-0.583836, (float)-0.517192, (float)-0.657830, (float)-0.676537, (float)-0.782756, (float)-0.521314, (float)-0.585204, (float)-0.605134, (float)-0.617385, (float)-0.649530, (float)-0.712327, (float)-0.693985, (float)-0.553193, (float)-0.659540, (float)-0.540599, (float)-0.793111, (float)-0.571818, (float)-0.584746, (float)-0.613227, (float)-0.693451, (float)-0.686847, (float)-0.669434, (float)-0.532752, (float)-0.643606, (float)-0.681984, (float)1.094305, (float)-0.721794, (float)-0.552714, (float)-0.636416, (float)-0.703609, (float)-0.495384, (float)-0.724163, (float)-0.597713, (float)-0.491831, (float)-0.612987, (float)-0.566158, (float)-0.560591, (float)-0.521596, (float)-0.622898, (float)-0.663222, (float)-0.687799, (float)-0.528395, (float)-0.676746, (float)-0.687652, (float)-0.490881, (float)-0.564638, (float)-0.531156, (float)-0.594634, (float)-0.476138, (float)-0.478973, (float)-0.437675, (float)-0.507542, (float)-0.775500, (float)-0.630304, (float)-0.713768, (float)-0.635128, (float)-0.486655, (float)-0.694944, (float)-0.584056, (float)-0.531543, (float)-0.774950, (float)-0.414342, (float)-0.627546, (float)-0.736624, (float)-0.433248, (float)-0.526515, (float)-0.559585, (float)-0.705374, (float)-0.570816, (float)-0.682786, (float)-0.568887, (float)-0.637050, (float)-0.688830, (float)-0.657953, (float)-0.704505, (float)-0.588115, (float)-0.566433, (float)-0.726806, (float)-0.453258, (float)-0.589214, (float)-0.375950, (float)-0.560585, (float)-0.419610, (float)-0.622340, (float)-0.585825, (float)-0.623298, (float)-0.559863, (float)-0.612563, (float)-0.609163, (float)-0.580848, (float)-0.601551, (float)-0.678778, (float)-0.625062, (float)-0.595292, (float)-0.611051, (float)-0.553896, (float)-0.673447, (float)-0.727241, (float)-0.609655, (float)-0.531932, (float)-0.615366, (float)-0.661623, (float)-0.525051, (float)-0.720417, (float)-0.514133, (float)-0.532666, (float)0.423257, (float)-0.552948, (float)-0.524175, (float)-0.659346, (float)-0.451149, (float)-0.634925, (float)-0.345611, (float)-0.663090, (float)-0.591956, (float)-0.597252, (float)-0.621118, (float)-0.711954, (float)-0.631364, (float)-0.503959, (float)-0.651598, (float)-0.654962, (float)-0.714219, (float)-0.580766, (float)-0.678856, (float)-0.620104, (float)-0.406141, (float)-0.592477, (float)-0.555808, (float)-0.557123, (float)-0.488908, (float)-0.536469, (float)-0.581187, (float)-0.434032, (float)-0.651491, (float)-0.765928, (float)-0.725813, (float)-0.600297, (float)-0.548644, (float)-0.573570, (float)-0.673882, (float)-0.791803, (float)-0.703981, (float)-0.729587, (float)-0.540516, (float)-0.765787, (float)-0.797869, (float)-0.434029, (float)-0.495118, (float)-0.607839, (float)-0.594747, (float)-0.499707, (float)-0.627690, (float)-0.779225, (float)-0.564906, (float)-0.536798, (float)-0.548710, (float)-0.448432, (float)-0.582722, (float)-0.659951, (float)-0.621732, (float)-0.481428, (float)-0.535148, (float)-0.716983, (float)-0.616804, (float)-0.511115, (float)-0.524308, (float)-0.533465, (float)-0.580659, (float)-0.554720, (float)-0.650323, (float)-0.458660, (float)-0.520870, (float)-0.606180, (float)-0.617250, (float)-0.551609, (float)-0.600615, (float)-0.623892, (float)-0.547826, (float)-0.416296, (float)-0.400634, (float)-0.652903, (float)-0.629601, (float)-0.628480, (float)-0.695389, (float)-0.696171, (float)-0.619967, (float)-0.610122, (float)-0.740638, (float)-0.554527, (float)-0.611820, (float)-0.456072, (float)-0.701886, (float)-0.492771, (float)-0.674054, (float)-0.535626, (float)-0.508433, (float)-0.576041, (float)-0.781385, (float)-0.606688, (float)-0.564861, (float)-0.706667, (float)-0.524017, (float)-0.546131, (float)-0.611009, (float)-0.493108, (float)-0.583555, (float)-0.562198, (float)-0.645880, (float)-0.630781, (float)-0.902502, (float)-0.785391, (float)-0.565273, (float)-0.729284, (float)-0.592601, (float)-0.559185, (float)-0.744047, (float)-0.748236, (float)-0.666430, (float)-0.704776, (float)-0.743941, (float)-0.587821, (float)-0.802787, (float)-0.619217, (float)-0.461556, (float)-0.585491, (float)-0.674150, (float)-0.788763, (float)-0.665089, (float)-0.368269, (float)-0.613433, (float)-0.484249, (float)-0.368227, (float)-0.653625, (float)-0.763135, (float)-0.609199, (float)-0.483914, (float)-0.650656, (float)-0.390514, (float)-0.686241, (float)-0.440122, (float)-0.652524, (float)-0.565567, (float)-0.671697, (float)-0.742093, (float)-0.722871, (float)-0.467401, (float)-0.575119, (float)-0.551060, (float)-0.558588, (float)-0.555832, (float)-0.495576, (float)-0.740304, (float)-0.685487, (float)-0.348640, (float)-0.653714, (float)-0.484410, (float)-0.634893, (float)-0.559822, (float)-0.594751, (float)-0.481156, (float)-0.533360, (float)-0.597617, (float)-0.626149, (float)-0.677230, (float)-0.751566, (float)-0.549316, (float)-0.351552, (float)-0.500901, (float)-0.687211, (float)-0.596026, (float)-0.701455, (float)-0.701849, (float)-0.616725, (float)-0.646680, (float)-0.662618, (float)-0.628021, (float)-0.568340, (float)-0.437611, (float)-0.575540, (float)-0.433710, (float)-0.723970, (float)-0.643754, (float)-0.746185, (float)-0.583211, (float)-0.434603, (float)-0.483143, (float)-0.708712, (float)-0.629189, (float)-0.574825, (float)-0.645158, (float)-0.625728, (float)-0.539591, (float)-0.618591, (float)-0.635195, (float)-0.804003, (float)-0.686286, (float)-0.509029, (float)-0.578320, (float)-0.463522, (float)-0.662571, (float)-0.605672, (float)-0.545510, (float)-0.690327, (float)-0.425566, (float)-0.628013, (float)-0.600466, (float)-0.625441, (float)-0.656136, (float)-0.631090, (float)0.069986, (float)-0.538626, (float)-0.630297, (float)-0.612624, (float)-0.562514, (float)-0.717746, (float)-0.714968, (float)-0.443519, (float)-0.503402, (float)-0.460118, (float)-0.713433, (float)-0.604455, (float)-0.617452, (float)-0.131146, (float)-0.460610, (float)-0.527855, (float)-0.470304, (float)-0.617029, (float)-0.539948, (float)-0.653345, (float)-0.489337, (float)-0.605371, (float)-0.582756, (float)-0.432120, (float)-0.558990, (float)-0.612080, (float)-0.432217, (float)-0.565227, (float)-0.555233, (float)-0.552695, (float)-0.701409, (float)-0.830658, (float)-0.723646, (float)-0.580912, (float)-0.588886, (float)-0.308734, (float)-0.508060, (float)-0.625120, (float)-0.505165, (float)-0.597686, (float)-0.482370, (float)-0.581055, (float)-0.569211, (float)-0.551578, (float)-0.736489, (float)-0.549753, (float)-0.632732, (float)-0.506880, (float)-0.737591, (float)-0.609342, (float)-0.448911, (float)-0.414976, (float)-0.824387, (float)-0.646708, (float)-0.652089, (float)-0.790253, (float)-0.550589, (float)-0.592843, (float)-0.561587, (float)-0.524387, (float)-0.768650, (float)-0.446418, (float)-0.575646, (float)-0.663503, (float)-0.833324, (float)-0.584874, (float)-0.649196, (float)-0.674701, (float)-0.591840, (float)-0.700442, (float)-0.570885, (float)-0.678234, (float)-0.567685, (float)-0.527412, (float)-0.603221, (float)-0.732851, (float)-0.763933, (float)-0.714234, (float)-0.543401, (float)-0.595375, (float)-0.366722, (float)-0.835745, (float)-0.595797, (float)-0.552825, (float)-0.704469, (float)-0.730476, (float)-0.583419, (float)-0.688803, (float)-0.629495, (float)-0.467073, (float)-0.495003, (float)-0.388563, (float)-0.705246, (float)-0.742846, (float)-0.439654, (float)-0.619706, (float)-0.604399, (float)-0.721261, (float)-0.772576, (float)-0.570528, (float)-0.534292, (float)-0.605621, (float)-0.505945, (float)-0.718137, (float)-0.681156, (float)-0.640036, (float)-0.627977, (float)-0.675497, (float)-0.664535, (float)-0.670920, (float)-0.678671, (float)-0.770007};	// L3938
  #pragma HLS resource variable=v3438 core=ram_t2p_bram

  float v3439[512] = {(float)-0.166778, (float)-0.301884, (float)-0.218710, (float)-0.291665, (float)-0.197052, (float)-0.232542, (float)-0.186879, (float)-0.185719, (float)-0.247446, (float)-0.162930, (float)-0.244761, (float)-0.250772, (float)-0.189473, (float)-0.265120, (float)-0.325032, (float)-0.381098, (float)-0.295301, (float)-0.496279, (float)-0.029429, (float)-0.272426, (float)-0.200655, (float)-0.222042, (float)-0.294523, (float)-0.257905, (float)-0.515237, (float)-0.199378, (float)-0.501575, (float)-0.273609, (float)-0.452842, (float)-0.396767, (float)-0.228079, (float)-0.177167, (float)-0.129269, (float)-0.265454, (float)-0.325217, (float)-0.323211, (float)-0.333732, (float)-0.190141, (float)-0.069213, (float)-0.219598, (float)-0.213196, (float)-0.256509, (float)-0.164644, (float)-0.156687, (float)-0.208673, (float)-0.217784, (float)-0.248026, (float)-0.276723, (float)-0.307089, (float)-0.198761, (float)-0.198528, (float)-0.023470, (float)-0.245765, (float)-0.415635, (float)-0.165957, (float)-0.192324, (float)-0.332811, (float)-0.148053, (float)-0.304728, (float)-0.227722, (float)-0.318194, (float)-0.274427, (float)-0.164250, (float)-0.336509, (float)-0.405015, (float)-0.208197, (float)-0.062082, (float)-0.267069, (float)-0.280936, (float)-0.218496, (float)-0.214800, (float)-0.446515, (float)-0.337594, (float)-0.321295, (float)-0.292084, (float)-0.199835, (float)-0.336912, (float)-0.209215, (float)-0.283081, (float)-0.289337, (float)-0.171927, (float)-0.218890, (float)-0.401572, (float)-0.248410, (float)-0.207006, (float)-0.384924, (float)-0.375318, (float)-0.587427, (float)-0.163706, (float)-0.174781, (float)-0.221691, (float)-0.506717, (float)-0.249581, (float)-0.211673, (float)-0.429063, (float)-0.194439, (float)-0.308921, (float)-0.262051, (float)-0.409624, (float)-0.060217, (float)-0.200947, (float)-0.131576, (float)-0.333645, (float)-0.262714, (float)-0.232000, (float)-0.090958, (float)-0.156032, (float)-0.288905, (float)-0.328569, (float)-0.162802, (float)-0.512772, (float)-0.203649, (float)-0.172572, (float)-0.184377, (float)-0.228476, (float)-0.192538, (float)-0.343170, (float)-0.092912, (float)-0.313844, (float)-0.191236, (float)-0.192553, (float)-0.034224, (float)-0.326845, (float)-0.169908, (float)-0.082844, (float)-0.241710, (float)-0.206921, (float)-0.386983, (float)-0.220995, (float)-0.286666, (float)-0.052590, (float)-0.309189, (float)-0.065540, (float)-0.259427, (float)-0.216036, (float)-0.506234, (float)-0.290463, (float)-0.212464, (float)-0.312382, (float)-0.212780, (float)-0.194570, (float)-0.251969, (float)-0.547520, (float)-0.232130, (float)-0.335038, (float)-0.347271, (float)-0.215781, (float)-0.360343, (float)-0.075889, (float)-0.147226, (float)-0.032748, (float)-0.140364, (float)-0.312821, (float)-0.306322, (float)-0.112002, (float)-0.266357, (float)-0.269969, (float)-0.311171, (float)-0.151908, (float)-0.384272, (float)-0.064518, (float)-0.237345, (float)-0.422661, (float)-0.254578, (float)-0.161118, (float)-0.234975, (float)-0.152435, (float)-0.349375, (float)-0.345312, (float)-0.208057, (float)-0.091781, (float)-0.202487, (float)-0.124616, (float)-0.253308, (float)-0.276754, (float)-0.315624, (float)-0.253035, (float)-0.395692, (float)-0.098060, (float)-0.125728, (float)-0.369679, (float)-0.233297, (float)-0.366438, (float)-0.282851, (float)-0.432020, (float)-0.083630, (float)-0.158317, (float)-0.239466, (float)-0.181846, (float)-0.440792, (float)-0.237558, (float)-0.445011, (float)-0.323199, (float)-0.278685, (float)-0.185759, (float)-0.213734, (float)0.048095, (float)-0.105792, (float)-0.109336, (float)-0.203505, (float)-0.049555, (float)-0.211673, (float)-0.159833, (float)-0.238937, (float)-0.282979, (float)-0.287788, (float)-0.340562, (float)-0.255988, (float)-0.446779, (float)-0.244449, (float)-0.249191, (float)-0.222163, (float)-0.279186, (float)-0.300518, (float)-0.418048, (float)-0.256758, (float)-0.187175, (float)-0.026989, (float)-0.264514, (float)-0.187262, (float)-0.302245, (float)-0.340033, (float)-0.180271, (float)-0.180987, (float)-0.207890, (float)-0.477471, (float)-0.204706, (float)-0.187821, (float)-0.450425, (float)-0.251550, (float)-0.165694, (float)-0.276547, (float)-0.232948, (float)-0.244570, (float)-0.295637, (float)-0.416283, (float)-0.281643, (float)-0.157050, (float)-0.219938, (float)-0.212529, (float)-0.168377, (float)0.035650, (float)-0.091396, (float)-0.448422, (float)-0.353491, (float)-0.221241, (float)-0.254963, (float)-0.250917, (float)-0.270208, (float)-0.059870, (float)-0.350520, (float)-0.292434, (float)-0.236047, (float)-0.233904, (float)-0.125887, (float)-0.259706, (float)-0.226746, (float)-0.197800, (float)-0.137064, (float)-0.012892, (float)-0.117458, (float)-0.252714, (float)-0.309939, (float)-0.323135, (float)-0.346767, (float)-0.355307, (float)-0.353698, (float)-0.331463, (float)-0.371257, (float)-0.109127, (float)-0.095854, (float)-0.025802, (float)-0.275570, (float)-0.280846, (float)-0.201234, (float)-0.281223, (float)-0.199129, (float)-0.394824, (float)-0.225674, (float)-0.246888, (float)-0.421136, (float)-0.210989, (float)-0.466971, (float)-0.306896, (float)-0.354851, (float)-0.233702, (float)-0.061225, (float)-0.132124, (float)-0.296824, (float)-0.187037, (float)-0.231554, (float)-0.068646, (float)-0.311342, (float)-0.289526, (float)-0.314944, (float)-0.268616, (float)-0.208079, (float)-0.209587, (float)-0.301078, (float)-0.181040, (float)-0.022727, (float)-0.387303, (float)-0.266473, (float)-0.022525, (float)-0.297290, (float)-0.097272, (float)-0.297961, (float)-0.321932, (float)-0.292626, (float)-0.319557, (float)-0.433212, (float)-0.198044, (float)-0.211702, (float)-0.230248, (float)-0.098036, (float)-0.234449, (float)-0.215439, (float)-0.292083, (float)-0.035002, (float)-0.336064, (float)-0.261990, (float)-0.218833, (float)-0.156628, (float)-0.179497, (float)-0.272610, (float)-0.410262, (float)0.041331, (float)-0.150667, (float)-0.255214, (float)-0.313730, (float)-0.246626, (float)-0.296126, (float)-0.093810, (float)-0.148112, (float)-0.212855, (float)-0.547962, (float)-0.291468, (float)-0.280187, (float)-0.507714, (float)-0.130599, (float)-0.186227, (float)-0.239996, (float)-0.436204, (float)-0.301735, (float)-0.163260, (float)-0.344721, (float)-0.104740, (float)-0.284646, (float)-0.124401, (float)-0.303603, (float)-0.240359, (float)-0.233264, (float)-0.249393, (float)-0.186588, (float)-0.329376, (float)-0.167748, (float)-0.254014, (float)-0.129459, (float)-0.051167, (float)-0.196646, (float)-0.280118, (float)-0.170163, (float)-0.187942, (float)-0.184979, (float)-0.327354, (float)-0.036948, (float)-0.297911, (float)-0.261205, (float)-0.188904, (float)-0.327026, (float)-0.137659, (float)-0.278723, (float)-0.220099, (float)-0.241671, (float)-0.283364, (float)-0.055538, (float)-0.253775, (float)-0.103968, (float)-0.266035, (float)-0.164432, (float)-0.172312, (float)-0.267215, (float)-0.279710, (float)-0.421407, (float)-0.037770, (float)-0.238588, (float)-0.349763, (float)-0.243517, (float)-0.434770, (float)-0.255393, (float)-0.171896, (float)-0.283597, (float)-0.331604, (float)-0.278738, (float)-0.287927, (float)-0.263989, (float)-0.055961, (float)-0.178914, (float)-0.419529, (float)-0.215160, (float)0.056671, (float)-0.235948, (float)-0.224888, (float)-0.091073, (float)-0.264409, (float)-0.387462, (float)-0.331677, (float)-0.141506, (float)-0.342510, (float)-0.001966, (float)-0.194066, (float)-0.282105, (float)-0.280897, (float)-0.096453, (float)-0.184142, (float)-0.297108, (float)-0.017309, (float)-0.304341, (float)-0.301250, (float)-0.172939, (float)-0.187185, (float)-0.268301, (float)-0.203277, (float)-0.305852, (float)-0.293887, (float)-0.216347, (float)-0.188940, (float)-0.258145, (float)-0.229595, (float)-0.206601, (float)-0.346224, (float)-0.429798, (float)-0.260050, (float)-0.309454, (float)-0.179973, (float)-0.011597, (float)-0.212382, (float)-0.255211, (float)-0.052268, (float)-0.221629, (float)-0.260463, (float)-0.213373, (float)-0.286738, (float)-0.255577, (float)-0.227501, (float)-0.343706, (float)-0.169841, (float)-0.155950, (float)-0.411996, (float)-0.206748, (float)-0.115915, (float)-0.240838, (float)-0.309345, (float)-0.262110, (float)-0.259264, (float)-0.013475, (float)-0.309890, (float)-0.217898, (float)-0.276555, (float)-0.240024, (float)-0.393405, (float)0.007223, (float)-0.298154, (float)-0.092989, (float)-0.216617, (float)-0.163475, (float)-0.182670, (float)-0.230832, (float)-0.252491, (float)-0.099116, (float)-0.232465, (float)-0.293801, (float)-0.247992, (float)-0.093388, (float)-0.191098, (float)-0.377190, (float)-0.336867, (float)-0.160648, (float)-0.275220, (float)-0.300454, (float)-0.137182, (float)-0.299033, (float)-0.215551, (float)-0.262224, (float)-0.316047, (float)-0.134242, (float)-0.290303, (float)-0.386548, (float)-0.291577, (float)-0.324283, (float)-0.205084, (float)-0.265611, (float)-0.235949, (float)-0.150819, (float)-0.106305, (float)-0.359518, (float)-0.231204, (float)-0.304596, (float)-0.417826, (float)-0.027616, (float)-0.220362, (float)-0.242648, (float)-0.161557, (float)-0.478941, (float)-0.171309, (float)-0.280208, (float)-0.230503, (float)-0.432674, (float)-0.241290, (float)-0.186202, (float)-0.148583, (float)-0.150677};	// L3939
  #pragma HLS resource variable=v3439 core=ram_t2p_bram

  float v3440[512] = {(float)0.258653, (float)0.307254, (float)0.259460, (float)0.322322, (float)0.266240, (float)0.265176, (float)0.257515, (float)0.266003, (float)0.276571, (float)0.241378, (float)0.304453, (float)0.285334, (float)0.282124, (float)0.287992, (float)0.309360, (float)0.344413, (float)0.315457, (float)0.412925, (float)0.210974, (float)0.290261, (float)0.249561, (float)0.260129, (float)0.296687, (float)0.303279, (float)0.415180, (float)0.271899, (float)0.366112, (float)0.325054, (float)0.389843, (float)0.334617, (float)0.275327, (float)0.271204, (float)0.241399, (float)0.335072, (float)0.339427, (float)0.316734, (float)0.336015, (float)0.266617, (float)0.210885, (float)0.270491, (float)0.258746, (float)0.307003, (float)0.271974, (float)0.231582, (float)0.288480, (float)0.288359, (float)0.295524, (float)0.305746, (float)0.304270, (float)0.259641, (float)0.267296, (float)0.192930, (float)0.313607, (float)0.359308, (float)0.262186, (float)0.293081, (float)0.329468, (float)0.251390, (float)0.320831, (float)0.279846, (float)0.325917, (float)0.293923, (float)0.238955, (float)0.310520, (float)0.347136, (float)0.281158, (float)0.214759, (float)0.299651, (float)0.306111, (float)0.273967, (float)0.279072, (float)0.379026, (float)0.359156, (float)0.324715, (float)0.299542, (float)0.273507, (float)0.335615, (float)0.270266, (float)0.325483, (float)0.312741, (float)0.278306, (float)0.270219, (float)0.390034, (float)0.294182, (float)0.289862, (float)0.346078, (float)0.343229, (float)0.468488, (float)0.263406, (float)0.255341, (float)0.301866, (float)0.396060, (float)0.274202, (float)0.299477, (float)0.385829, (float)0.278531, (float)0.321156, (float)0.310891, (float)0.364163, (float)0.219310, (float)0.264327, (float)0.233275, (float)0.315063, (float)0.310163, (float)0.293578, (float)0.237394, (float)0.241894, (float)0.297588, (float)0.333537, (float)0.261866, (float)0.398381, (float)0.272133, (float)0.271832, (float)0.267829, (float)0.275722, (float)0.244483, (float)0.350807, (float)0.217371, (float)0.330944, (float)0.265293, (float)0.256439, (float)0.174837, (float)0.317694, (float)0.275073, (float)0.206674, (float)0.290497, (float)0.276154, (float)0.332903, (float)0.273802, (float)0.322444, (float)0.219853, (float)0.299732, (float)0.220557, (float)0.321267, (float)0.276035, (float)0.392709, (float)0.317351, (float)0.269806, (float)0.298773, (float)0.260953, (float)0.255023, (float)0.278819, (float)0.444529, (float)0.286156, (float)0.360626, (float)0.327896, (float)0.286877, (float)0.329384, (float)0.224351, (float)0.233813, (float)0.175445, (float)0.231830, (float)0.318585, (float)0.332225, (float)0.225506, (float)0.304087, (float)0.283712, (float)0.327611, (float)0.239207, (float)0.366756, (float)0.197145, (float)0.294643, (float)0.361256, (float)0.273633, (float)0.255369, (float)0.286021, (float)0.251089, (float)0.348963, (float)0.325344, (float)0.293427, (float)0.202669, (float)0.258012, (float)0.220020, (float)0.308927, (float)0.307405, (float)0.333202, (float)0.294267, (float)0.337549, (float)0.233025, (float)0.261063, (float)0.338264, (float)0.283743, (float)0.354584, (float)0.309302, (float)0.379091, (float)0.219729, (float)0.264785, (float)0.282971, (float)0.258664, (float)0.358847, (float)0.283009, (float)0.397142, (float)0.319417, (float)0.306608, (float)0.275414, (float)0.264732, (float)0.096991, (float)0.218234, (float)0.233432, (float)0.262442, (float)0.182925, (float)0.293257, (float)0.274660, (float)0.300114, (float)0.299629, (float)0.310712, (float)0.325552, (float)0.293957, (float)0.390091, (float)0.279043, (float)0.303045, (float)0.283846, (float)0.301035, (float)0.304372, (float)0.347879, (float)0.308721, (float)0.261120, (float)0.195816, (float)0.294136, (float)0.255841, (float)0.288934, (float)0.314836, (float)0.251640, (float)0.266390, (float)0.286150, (float)0.393963, (float)0.293256, (float)0.278149, (float)0.379642, (float)0.302151, (float)0.258293, (float)0.302115, (float)0.278377, (float)0.296740, (float)0.299419, (float)0.385593, (float)0.327699, (float)0.258716, (float)0.253909, (float)0.282389, (float)0.263356, (float)0.148927, (float)0.220537, (float)0.392898, (float)0.340055, (float)0.271699, (float)0.278920, (float)0.291713, (float)0.317740, (float)0.199225, (float)0.368365, (float)0.311954, (float)0.320131, (float)0.281020, (float)0.230217, (float)0.277928, (float)0.286487, (float)0.285787, (float)0.271287, (float)0.160112, (float)0.249581, (float)0.289524, (float)0.315395, (float)0.344278, (float)0.328518, (float)0.344432, (float)0.325108, (float)0.323501, (float)0.337509, (float)0.228236, (float)0.212838, (float)0.179536, (float)0.307721, (float)0.300513, (float)0.277469, (float)0.305415, (float)0.291415, (float)0.353504, (float)0.287099, (float)0.266912, (float)0.396121, (float)0.267444, (float)0.389827, (float)0.318337, (float)0.324219, (float)0.278895, (float)0.191084, (float)0.256855, (float)0.342734, (float)0.246424, (float)0.277846, (float)0.209767, (float)0.301859, (float)0.314531, (float)0.327072, (float)0.291418, (float)0.261850, (float)0.264285, (float)0.303916, (float)0.252017, (float)0.209921, (float)0.364308, (float)0.291455, (float)0.195748, (float)0.328570, (float)0.235546, (float)0.320984, (float)0.298192, (float)0.338831, (float)0.344965, (float)0.371618, (float)0.289784, (float)0.284586, (float)0.280502, (float)0.221948, (float)0.290975, (float)0.268068, (float)0.316252, (float)0.196427, (float)0.317611, (float)0.309220, (float)0.270613, (float)0.250465, (float)0.250810, (float)0.316617, (float)0.358251, (float)0.156263, (float)0.260824, (float)0.289224, (float)0.340060, (float)0.289098, (float)0.312587, (float)0.217215, (float)0.245887, (float)0.265121, (float)0.405211, (float)0.298572, (float)0.302591, (float)0.377266, (float)0.226189, (float)0.267520, (float)0.289994, (float)0.375936, (float)0.320086, (float)0.256677, (float)0.344324, (float)0.234774, (float)0.305689, (float)0.234677, (float)0.327660, (float)0.293774, (float)0.274554, (float)0.280529, (float)0.242139, (float)0.359016, (float)0.262216, (float)0.277316, (float)0.239642, (float)0.213411, (float)0.272716, (float)0.298438, (float)0.274433, (float)0.259093, (float)0.262776, (float)0.356810, (float)0.200910, (float)0.321951, (float)0.286774, (float)0.256133, (float)0.311339, (float)0.213783, (float)0.313627, (float)0.274466, (float)0.304581, (float)0.304164, (float)0.197231, (float)0.281454, (float)0.254222, (float)0.298339, (float)0.261308, (float)0.266769, (float)0.314248, (float)0.293041, (float)0.379950, (float)0.196589, (float)0.294770, (float)0.336325, (float)0.271314, (float)0.362477, (float)0.290850, (float)0.269547, (float)0.311078, (float)0.324165, (float)0.300873, (float)0.323066, (float)0.305076, (float)0.201172, (float)0.271588, (float)0.369198, (float)0.269375, (float)0.148108, (float)0.285847, (float)0.281887, (float)0.239137, (float)0.286653, (float)0.346642, (float)0.343100, (float)0.236494, (float)0.335651, (float)0.168539, (float)0.292454, (float)0.309248, (float)0.312699, (float)0.188345, (float)0.256073, (float)0.308609, (float)0.173237, (float)0.298885, (float)0.323458, (float)0.269283, (float)0.263033, (float)0.291337, (float)0.278647, (float)0.312437, (float)0.309797, (float)0.269525, (float)0.240332, (float)0.290607, (float)0.278380, (float)0.265381, (float)0.348534, (float)0.393850, (float)0.303310, (float)0.314508, (float)0.262222, (float)0.153991, (float)0.278961, (float)0.296657, (float)0.195435, (float)0.263214, (float)0.295734, (float)0.258132, (float)0.323063, (float)0.279482, (float)0.285947, (float)0.313898, (float)0.248818, (float)0.240414, (float)0.371402, (float)0.264856, (float)0.226700, (float)0.287824, (float)0.346230, (float)0.306279, (float)0.317971, (float)0.172571, (float)0.315303, (float)0.262468, (float)0.301976, (float)0.299645, (float)0.363247, (float)0.154106, (float)0.319185, (float)0.219963, (float)0.289393, (float)0.262160, (float)0.253383, (float)0.293457, (float)0.320769, (float)0.223056, (float)0.274329, (float)0.302337, (float)0.282941, (float)0.239436, (float)0.250616, (float)0.351159, (float)0.336579, (float)0.266591, (float)0.293011, (float)0.304928, (float)0.232099, (float)0.339687, (float)0.272655, (float)0.289975, (float)0.314638, (float)0.268182, (float)0.309351, (float)0.371775, (float)0.338693, (float)0.320203, (float)0.242282, (float)0.274548, (float)0.296551, (float)0.250019, (float)0.232927, (float)0.341928, (float)0.292804, (float)0.353586, (float)0.373931, (float)0.193541, (float)0.267000, (float)0.284598, (float)0.258259, (float)0.378281, (float)0.282597, (float)0.292868, (float)0.272787, (float)0.364453, (float)0.277048, (float)0.275636, (float)0.252264, (float)0.249964};	// L3940
  #pragma HLS resource variable=v3440 core=ram_t2p_bram

  float v3441[512] = {(float)0.012607, (float)0.012795, (float)0.012836, (float)0.013783, (float)0.012441, (float)0.013147, (float)0.014444, (float)0.016157, (float)0.012308, (float)0.011641, (float)0.011995, (float)0.011215, (float)0.012360, (float)0.010052, (float)0.012017, (float)0.013942, (float)0.013127, (float)0.018412, (float)0.012599, (float)0.010842, (float)0.012449, (float)0.013412, (float)0.013765, (float)0.013621, (float)0.012877, (float)0.012920, (float)0.012716, (float)0.012023, (float)0.014954, (float)0.012628, (float)0.012342, (float)0.012743, (float)0.012353, (float)0.011137, (float)0.012544, (float)0.012324, (float)0.014762, (float)0.012765, (float)0.011890, (float)0.010633, (float)0.012721, (float)0.010859, (float)0.012173, (float)0.012396, (float)0.013669, (float)0.012910, (float)0.012683, (float)0.020786, (float)0.012164, (float)0.011582, (float)0.012351, (float)0.013041, (float)0.010677, (float)0.015028, (float)0.011270, (float)0.012414, (float)0.015545, (float)0.014291, (float)0.013015, (float)0.011886, (float)0.011764, (float)0.017043, (float)0.011810, (float)0.014155, (float)0.011373, (float)0.012751, (float)0.010263, (float)0.013853, (float)0.015373, (float)0.012052, (float)0.013857, (float)0.011107, (float)0.011257, (float)0.013424, (float)0.011654, (float)0.013275, (float)0.012267, (float)0.011632, (float)0.011624, (float)0.011821, (float)0.011366, (float)0.014051, (float)0.011627, (float)0.015670, (float)0.010272, (float)0.012229, (float)0.013182, (float)0.011980, (float)0.011770, (float)0.011470, (float)0.009519, (float)0.013395, (float)0.012046, (float)0.013805, (float)0.011765, (float)0.012712, (float)0.011828, (float)0.011465, (float)0.012209, (float)0.011313, (float)0.012856, (float)0.012779, (float)0.012912, (float)0.012170, (float)0.011401, (float)0.011912, (float)0.014428, (float)0.014182, (float)0.013258, (float)0.015467, (float)0.011182, (float)0.011008, (float)0.011993, (float)0.013008, (float)0.013681, (float)0.013370, (float)0.011496, (float)0.016639, (float)0.011855, (float)0.012463, (float)0.012111, (float)0.013034, (float)0.012276, (float)0.009981, (float)0.012321, (float)0.011815, (float)0.012773, (float)0.011727, (float)0.011281, (float)0.013318, (float)0.014112, (float)0.012649, (float)0.010986, (float)0.012151, (float)0.015177, (float)0.013746, (float)0.012133, (float)0.013573, (float)0.012481, (float)0.013561, (float)0.010291, (float)0.012488, (float)0.011282, (float)0.012459, (float)0.013162, (float)0.013991, (float)0.012794, (float)0.015236, (float)0.011475, (float)0.014152, (float)0.011746, (float)0.011560, (float)0.014177, (float)0.011815, (float)0.010985, (float)0.014292, (float)0.013252, (float)0.013664, (float)0.012592, (float)0.011000, (float)0.012848, (float)0.020357, (float)0.012684, (float)0.030875, (float)0.016966, (float)0.013806, (float)0.010805, (float)0.011598, (float)0.012627, (float)0.012273, (float)0.012620, (float)0.011659, (float)0.012492, (float)0.012681, (float)0.012751, (float)0.010844, (float)0.014885, (float)0.013681, (float)0.012171, (float)0.011670, (float)0.013635, (float)0.011769, (float)0.018156, (float)0.011138, (float)0.012628, (float)0.015029, (float)0.015616, (float)0.013909, (float)0.011480, (float)0.011303, (float)0.012139, (float)0.011750, (float)0.015876, (float)0.013656, (float)0.010394, (float)0.012946, (float)0.012624, (float)0.011957, (float)0.013235, (float)0.011265, (float)0.011500, (float)0.012635, (float)0.015489, (float)0.009593, (float)0.014590, (float)0.014663, (float)0.013447, (float)0.012776, (float)0.012686, (float)0.012837, (float)0.010899, (float)0.010744, (float)0.011642, (float)0.011800, (float)0.014411, (float)0.012817, (float)0.011857, (float)0.011787, (float)0.010723, (float)0.014497, (float)0.013106, (float)0.013415, (float)0.013301, (float)0.012676, (float)0.011392, (float)0.012345, (float)0.012399, (float)0.012312, (float)0.013118, (float)0.011824, (float)0.012197, (float)0.012423, (float)0.012812, (float)0.013887, (float)0.011381, (float)0.011887, (float)0.010703, (float)0.015483, (float)0.012125, (float)0.012822, (float)0.011870, (float)0.012034, (float)0.017866, (float)0.010217, (float)0.012893, (float)0.014659, (float)0.012393, (float)0.011389, (float)0.011972, (float)0.012732, (float)0.013072, (float)0.012994, (float)0.012904, (float)0.012871, (float)0.011562, (float)0.014855, (float)0.012064, (float)0.014229, (float)0.012749, (float)0.015885, (float)0.013019, (float)0.012125, (float)0.012583, (float)0.011958, (float)0.013250, (float)0.010867, (float)0.013941, (float)0.010751, (float)0.012574, (float)0.012344, (float)0.010800, (float)0.011533, (float)0.013274, (float)0.011349, (float)0.014498, (float)0.012250, (float)0.012234, (float)0.009903, (float)0.011828, (float)0.012083, (float)0.015951, (float)0.010767, (float)0.011830, (float)0.013225, (float)0.011655, (float)0.011856, (float)0.012551, (float)0.011889, (float)0.012027, (float)0.013007, (float)0.011249, (float)0.012834, (float)0.013066, (float)0.014390, (float)0.013390, (float)0.011616, (float)0.013649, (float)0.013628, (float)0.012689, (float)0.009673, (float)0.013976, (float)0.012583, (float)0.011835, (float)0.012000, (float)0.014709, (float)0.013959, (float)0.012518, (float)0.013496, (float)0.012184, (float)0.014348, (float)0.012852, (float)0.012958, (float)0.013992, (float)0.011663, (float)0.010442, (float)0.011392, (float)0.013530, (float)0.012199, (float)0.013925, (float)0.012103, (float)0.010940, (float)0.012331, (float)0.014481, (float)0.012432, (float)0.011955, (float)0.011361, (float)0.013141, (float)0.013357, (float)0.010638, (float)0.011367, (float)0.011926, (float)0.015863, (float)0.013304, (float)0.012212, (float)0.013405, (float)0.011748, (float)0.010780, (float)0.011570, (float)0.013548, (float)0.013191, (float)0.011238, (float)0.011355, (float)0.011769, (float)0.014076, (float)0.010655, (float)0.011557, (float)0.012413, (float)0.011456, (float)0.011505, (float)0.012523, (float)0.011101, (float)0.011558, (float)0.011428, (float)0.010822, (float)0.011301, (float)0.011807, (float)0.012160, (float)0.012464, (float)0.011496, (float)0.012547, (float)0.014902, (float)0.014602, (float)0.012770, (float)0.012263, (float)0.014406, (float)0.012328, (float)0.011850, (float)0.012651, (float)0.013965, (float)0.014678, (float)0.012244, (float)0.012105, (float)0.012584, (float)0.011940, (float)0.010827, (float)0.013151, (float)0.011509, (float)0.011410, (float)0.013750, (float)0.012897, (float)0.014835, (float)0.012276, (float)0.011962, (float)0.012476, (float)0.013449, (float)0.013318, (float)0.012557, (float)0.016294, (float)0.012615, (float)0.011391, (float)0.010025, (float)0.013623, (float)0.012699, (float)0.011068, (float)0.013502, (float)0.012616, (float)0.011090, (float)0.012450, (float)0.013262, (float)0.012724, (float)0.016779, (float)0.013447, (float)0.011733, (float)0.012772, (float)0.013858, (float)0.012996, (float)0.013405, (float)0.012329, (float)0.012411, (float)0.012495, (float)0.013410, (float)0.011526, (float)0.011101, (float)0.011719, (float)0.012455, (float)0.013591, (float)0.010963, (float)0.012343, (float)0.011039, (float)0.012518, (float)0.011693, (float)0.011699, (float)0.013526, (float)0.012257, (float)0.012567, (float)0.014976, (float)0.012528, (float)0.013554, (float)0.011318, (float)0.012526, (float)0.012288, (float)0.013581, (float)0.011964, (float)0.012445, (float)0.014404, (float)0.016388, (float)0.012757, (float)0.012317, (float)0.011435, (float)0.011726, (float)0.013039, (float)0.012119, (float)0.013858, (float)0.011201, (float)0.012956, (float)0.012951, (float)0.012869, (float)0.012629, (float)0.016022, (float)0.011351, (float)0.011411, (float)0.014286, (float)0.012237, (float)0.012991, (float)0.012031, (float)0.011916, (float)0.010642, (float)0.013661, (float)0.013933, (float)0.012715, (float)0.014832, (float)0.011984, (float)0.012630, (float)0.011473, (float)0.013745, (float)0.011393, (float)0.011939, (float)0.013160, (float)0.013901, (float)0.012581, (float)0.011313, (float)0.010755, (float)0.011584, (float)0.012514, (float)0.012153, (float)0.013047, (float)0.011249, (float)0.011903, (float)0.012367, (float)0.011338, (float)0.012559, (float)0.011869, (float)0.012105, (float)0.010223, (float)0.015068, (float)0.013862, (float)0.010991, (float)0.012486, (float)0.012651, (float)0.010860, (float)0.013252, (float)0.015014, (float)0.012576, (float)0.012565, (float)0.012202, (float)0.014279, (float)0.010337, (float)0.013899, (float)0.013158, (float)0.012282, (float)0.014694, (float)0.010891, (float)0.014762, (float)0.010859, (float)0.010720, (float)0.011243, (float)0.015002, (float)0.012772, (float)0.011317, (float)0.012571, (float)0.016188, (float)0.013516};	// L3941
  #pragma HLS resource variable=v3441 core=ram_t2p_bram

  float v3442[512] = {(float)-0.013953, (float)-0.050031, (float)-0.043323, (float)-0.015914, (float)-0.046112, (float)-0.023473, (float)-0.025429, (float)-0.033783, (float)0.051665, (float)-0.035325, (float)-0.037555, (float)-0.013353, (float)-0.034012, (float)-0.002871, (float)-0.043814, (float)-0.026424, (float)-0.030987, (float)-0.091183, (float)0.015193, (float)-0.039889, (float)0.003516, (float)-0.063124, (float)-0.028069, (float)-0.038168, (float)-0.005747, (float)-0.019639, (float)-0.020180, (float)-0.041006, (float)-0.037068, (float)-0.049702, (float)-0.020847, (float)-0.035155, (float)-0.022799, (float)-0.035089, (float)-0.025835, (float)-0.026871, (float)-0.033089, (float)-0.053280, (float)-0.029554, (float)-0.027207, (float)-0.079410, (float)-0.038662, (float)-0.070901, (float)-0.004792, (float)-0.040081, (float)-0.044518, (float)-0.009688, (float)0.039220, (float)-0.041579, (float)-0.035060, (float)-0.027755, (float)-0.007651, (float)-0.044367, (float)-0.026813, (float)-0.012360, (float)-0.035112, (float)-0.031672, (float)-0.024467, (float)-0.060395, (float)-0.046648, (float)-0.053290, (float)-0.028216, (float)-0.054557, (float)-0.054704, (float)-0.028591, (float)-0.050634, (float)0.000627, (float)-0.051950, (float)-0.051578, (float)-0.036758, (float)-0.030772, (float)-0.039569, (float)-0.019722, (float)-0.043900, (float)-0.044507, (float)-0.053416, (float)-0.043945, (float)-0.023374, (float)-0.051497, (float)-0.044268, (float)-0.039613, (float)0.007135, (float)-0.031644, (float)0.034458, (float)-0.038945, (float)-0.038628, (float)-0.029412, (float)-0.036697, (float)-0.033454, (float)-0.003520, (float)-0.023919, (float)-0.015737, (float)-0.018832, (float)-0.036160, (float)-0.030676, (float)-0.035423, (float)-0.036338, (float)-0.060085, (float)-0.024744, (float)-0.010668, (float)-0.064177, (float)-0.049577, (float)-0.052484, (float)-0.054054, (float)-0.005603, (float)-0.011281, (float)-0.052175, (float)-0.042486, (float)-0.028311, (float)-0.036422, (float)-0.005653, (float)-0.028168, (float)-0.029531, (float)-0.037204, (float)-0.067556, (float)-0.031953, (float)-0.045689, (float)0.045595, (float)-0.030731, (float)-0.023350, (float)-0.032033, (float)-0.015946, (float)-0.043791, (float)0.004781, (float)0.000364, (float)-0.031503, (float)-0.023126, (float)-0.037362, (float)-0.046890, (float)-0.027394, (float)-0.056134, (float)-0.049824, (float)-0.043524, (float)-0.027824, (float)-0.070928, (float)-0.060755, (float)-0.050579, (float)-0.028704, (float)-0.026274, (float)-0.033160, (float)-0.008618, (float)-0.039907, (float)-0.035256, (float)-0.086042, (float)-0.026312, (float)-0.032020, (float)-0.014972, (float)-0.011586, (float)-0.038802, (float)-0.067321, (float)-0.045730, (float)-0.013368, (float)-0.029202, (float)-0.015672, (float)-0.055057, (float)-0.047705, (float)-0.026542, (float)-0.013914, (float)-0.019433, (float)-0.036511, (float)-0.051134, (float)-0.043920, (float)-0.033364, (float)0.041027, (float)-0.032706, (float)-0.000820, (float)-0.019290, (float)-0.047500, (float)-0.044132, (float)-0.038169, (float)-0.024048, (float)-0.041317, (float)-0.020381, (float)-0.039825, (float)-0.043505, (float)-0.013664, (float)-0.030153, (float)-0.032162, (float)-0.051351, (float)-0.043963, (float)-0.001310, (float)-0.020620, (float)-0.041151, (float)-0.074645, (float)-0.013569, (float)-0.042029, (float)-0.036559, (float)-0.055496, (float)-0.024927, (float)-0.043322, (float)-0.025386, (float)-0.005925, (float)0.009121, (float)-0.046321, (float)-0.049662, (float)-0.013392, (float)-0.049198, (float)-0.022978, (float)-0.013565, (float)-0.044778, (float)-0.041518, (float)-0.053186, (float)-0.062418, (float)-0.033953, (float)-0.018224, (float)-0.047834, (float)-0.025541, (float)-0.016724, (float)-0.066561, (float)-0.055189, (float)-0.029102, (float)0.001744, (float)-0.028708, (float)-0.047356, (float)-0.039403, (float)-0.052492, (float)-0.048850, (float)-0.033341, (float)-0.027483, (float)-0.061212, (float)-0.045193, (float)-0.035821, (float)0.008330, (float)-0.017342, (float)0.001103, (float)-0.062373, (float)-0.024603, (float)-0.072638, (float)0.021412, (float)-0.075782, (float)-0.032325, (float)-0.024850, (float)-0.022635, (float)-0.008499, (float)-0.024250, (float)0.006696, (float)-0.016815, (float)-0.057800, (float)-0.040070, (float)-0.025381, (float)-0.026095, (float)-0.036127, (float)-0.041404, (float)-0.047404, (float)-0.001727, (float)-0.058207, (float)-0.062922, (float)-0.041185, (float)-0.027714, (float)-0.026942, (float)-0.019350, (float)-0.002645, (float)-0.046726, (float)-0.044284, (float)-0.021652, (float)-0.048506, (float)-0.040399, (float)-0.035572, (float)-0.046054, (float)-0.031532, (float)-0.032670, (float)-0.043606, (float)-0.053407, (float)-0.029613, (float)-0.065983, (float)-0.036677, (float)-0.015673, (float)-0.041916, (float)0.007200, (float)-0.026574, (float)-0.029427, (float)-0.046752, (float)-0.016942, (float)-0.017730, (float)-0.031830, (float)-0.020861, (float)-0.042271, (float)-0.037406, (float)-0.038363, (float)-0.043299, (float)0.007099, (float)-0.016024, (float)-0.011558, (float)-0.013649, (float)-0.019286, (float)-0.005381, (float)-0.038080, (float)-0.040525, (float)-0.037919, (float)-0.038805, (float)-0.075134, (float)-0.013963, (float)0.002917, (float)-0.018857, (float)-0.018787, (float)-0.018889, (float)-0.039999, (float)-0.047723, (float)-0.015847, (float)-0.038556, (float)-0.003824, (float)-0.041886, (float)-0.022822, (float)-0.027051, (float)-0.012578, (float)-0.012243, (float)-0.010389, (float)-0.030908, (float)-0.049441, (float)-0.057127, (float)-0.043721, (float)-0.029496, (float)-0.028846, (float)-0.034347, (float)-0.033969, (float)-0.018485, (float)-0.020259, (float)-0.006510, (float)-0.032701, (float)-0.012320, (float)-0.042393, (float)-0.044799, (float)-0.025397, (float)-0.037255, (float)-0.030126, (float)-0.033043, (float)0.011193, (float)-0.034983, (float)-0.031577, (float)-0.036480, (float)-0.010290, (float)0.028495, (float)-0.036363, (float)-0.004754, (float)-0.057458, (float)-0.017357, (float)-0.009672, (float)-0.026240, (float)-0.032853, (float)-0.001027, (float)-0.056348, (float)-0.019716, (float)-0.063584, (float)0.011124, (float)-0.029937, (float)-0.025287, (float)-0.039320, (float)0.002933, (float)-0.048010, (float)-0.031270, (float)-0.035449, (float)-0.029562, (float)-0.017369, (float)-0.050306, (float)-0.045947, (float)-0.017834, (float)-0.006932, (float)-0.003274, (float)-0.048955, (float)-0.035086, (float)-0.024075, (float)-0.021984, (float)-0.007037, (float)-0.037546, (float)-0.031797, (float)-0.024134, (float)-0.033352, (float)-0.032565, (float)-0.016909, (float)-0.022290, (float)-0.039201, (float)-0.010906, (float)-0.056042, (float)-0.048766, (float)-0.030840, (float)-0.034916, (float)-0.038825, (float)-0.043324, (float)-0.056847, (float)0.010243, (float)-0.046514, (float)-0.010452, (float)-0.002154, (float)-0.044856, (float)-0.036066, (float)-0.017105, (float)-0.005236, (float)-0.028570, (float)-0.050284, (float)-0.065926, (float)-0.016846, (float)-0.031785, (float)-0.062677, (float)-0.055734, (float)-0.035885, (float)-0.014798, (float)-0.043455, (float)-0.013114, (float)-0.035012, (float)-0.021125, (float)-0.073286, (float)-0.041934, (float)-0.017432, (float)-0.035229, (float)0.035735, (float)-0.030858, (float)-0.041892, (float)-0.035874, (float)0.001710, (float)-0.018882, (float)-0.032570, (float)-0.068433, (float)-0.002356, (float)-0.045632, (float)0.001103, (float)-0.079181, (float)-0.015563, (float)-0.022546, (float)-0.019013, (float)-0.047557, (float)-0.015476, (float)-0.045174, (float)-0.025230, (float)-0.031111, (float)-0.017632, (float)-0.011193, (float)-0.016986, (float)-0.063783, (float)-0.025520, (float)0.009365, (float)-0.024927, (float)-0.052760, (float)-0.062665, (float)-0.024147, (float)-0.054109, (float)-0.064714, (float)-0.019359, (float)-0.014110, (float)-0.045960, (float)-0.042290, (float)-0.029651, (float)-0.011331, (float)-0.049568, (float)-0.045198, (float)-0.046655, (float)-0.039152, (float)-0.072373, (float)-0.028233, (float)-0.033341, (float)0.000050, (float)-0.024896, (float)-0.004391, (float)-0.057027, (float)-0.016781, (float)-0.041684, (float)-0.043151, (float)-0.011696, (float)-0.032351, (float)-0.009796, (float)-0.010248, (float)-0.031722, (float)-0.031369, (float)-0.043368, (float)-0.041376, (float)-0.017700, (float)-0.065839, (float)-0.044930, (float)-0.030312, (float)-0.049151, (float)-0.034421, (float)-0.029603, (float)-0.027210, (float)-0.021330, (float)-0.036309, (float)-0.023335, (float)-0.040678, (float)-0.012841, (float)-0.030524, (float)-0.061549, (float)-0.046466, (float)-0.062686, (float)-0.036889, (float)-0.039056, (float)-0.034740, (float)-0.006074, (float)-0.019422, (float)-0.042960, (float)-0.037847, (float)-0.077137, (float)-0.029199, (float)-0.054336, (float)-0.025864, (float)-0.032088, (float)-0.050267, (float)-0.026562, (float)-0.019347, (float)-0.012865, (float)-0.037129, (float)-0.033561, (float)-0.056942, (float)-0.023849, (float)-0.007705, (float)-0.058456, (float)0.000136, (float)-0.066229, (float)-0.029168, (float)-0.003950, (float)-0.052685, (float)-0.019541, (float)-0.058807, (float)-0.045790, (float)-0.030423};	// L3942
  #pragma HLS resource variable=v3442 core=ram_t2p_bram

  float v3443[512] = {(float)0.237053, (float)0.343314, (float)0.327930, (float)0.464220, (float)0.223302, (float)0.236983, (float)0.217579, (float)0.379259, (float)0.313998, (float)0.280349, (float)0.243354, (float)0.211605, (float)0.247772, (float)0.243528, (float)0.229751, (float)0.317221, (float)0.272502, (float)0.651092, (float)0.292538, (float)0.228129, (float)0.227865, (float)0.425408, (float)0.234154, (float)0.332787, (float)0.263182, (float)0.217551, (float)0.317980, (float)0.389284, (float)0.138651, (float)0.227351, (float)0.337893, (float)0.076736, (float)0.225347, (float)0.250441, (float)0.198979, (float)0.195098, (float)0.256563, (float)0.325269, (float)0.279655, (float)0.314925, (float)0.237289, (float)0.253293, (float)0.195599, (float)0.323569, (float)0.209272, (float)0.233284, (float)0.230018, (float)0.501893, (float)0.282992, (float)0.188529, (float)0.326359, (float)0.272219, (float)0.236874, (float)0.242986, (float)0.362477, (float)0.216480, (float)0.470004, (float)0.304696, (float)0.367542, (float)0.264145, (float)0.197909, (float)0.266441, (float)0.344828, (float)0.200494, (float)0.245039, (float)0.435114, (float)0.268898, (float)0.163205, (float)0.308723, (float)0.120929, (float)0.215303, (float)0.159195, (float)0.296048, (float)0.142256, (float)0.295127, (float)0.270614, (float)0.200694, (float)0.293873, (float)0.220994, (float)0.224312, (float)0.246470, (float)0.391002, (float)0.459865, (float)0.541699, (float)0.214747, (float)0.346871, (float)0.270255, (float)0.222941, (float)0.364451, (float)0.264704, (float)0.242119, (float)0.249187, (float)0.166577, (float)0.276258, (float)0.256001, (float)0.215109, (float)0.336350, (float)0.276745, (float)0.251579, (float)0.298841, (float)0.262212, (float)0.349904, (float)0.300138, (float)0.390748, (float)0.318424, (float)0.223267, (float)0.264882, (float)0.210972, (float)0.203422, (float)0.275224, (float)0.231400, (float)0.347985, (float)0.223767, (float)0.289213, (float)0.199100, (float)0.292305, (float)0.325925, (float)0.072217, (float)0.303866, (float)0.304128, (float)0.380301, (float)0.256797, (float)0.238229, (float)0.305689, (float)0.265156, (float)0.153213, (float)0.210964, (float)0.256739, (float)0.314824, (float)0.274623, (float)0.183315, (float)0.195023, (float)0.111641, (float)0.227948, (float)0.370550, (float)0.247727, (float)0.199956, (float)0.306049, (float)0.254773, (float)0.246758, (float)0.302787, (float)0.192077, (float)0.295212, (float)0.198045, (float)0.213546, (float)0.158295, (float)0.158563, (float)0.394441, (float)0.235171, (float)0.394657, (float)0.273975, (float)0.286094, (float)0.185610, (float)0.270156, (float)0.298583, (float)0.172837, (float)0.265767, (float)0.269627, (float)0.202776, (float)0.183818, (float)0.317562, (float)0.624552, (float)0.263150, (float)0.385471, (float)0.207381, (float)0.231713, (float)0.417059, (float)0.204437, (float)0.292574, (float)0.350612, (float)0.230526, (float)0.240012, (float)0.141978, (float)0.109323, (float)0.275665, (float)0.325277, (float)0.233393, (float)0.164955, (float)0.402629, (float)0.206574, (float)0.178993, (float)0.303239, (float)0.565806, (float)0.324606, (float)0.383396, (float)0.325397, (float)0.177192, (float)0.290861, (float)0.235024, (float)0.251875, (float)0.196810, (float)0.200341, (float)0.321280, (float)0.480220, (float)0.254314, (float)0.257771, (float)0.328014, (float)0.226978, (float)0.304444, (float)0.227312, (float)0.244713, (float)0.252721, (float)0.413645, (float)0.258828, (float)0.358865, (float)0.268754, (float)0.211535, (float)0.202235, (float)0.318619, (float)0.374031, (float)0.178458, (float)0.207424, (float)0.234567, (float)0.356628, (float)0.262261, (float)0.262033, (float)0.287963, (float)0.146182, (float)0.189597, (float)0.277728, (float)0.185201, (float)0.323953, (float)0.274835, (float)0.216381, (float)0.306597, (float)0.184479, (float)0.399247, (float)0.169518, (float)0.441088, (float)0.281237, (float)0.273039, (float)0.278381, (float)0.186113, (float)0.358933, (float)0.193435, (float)0.332022, (float)0.334961, (float)0.265495, (float)0.273984, (float)0.318533, (float)0.263286, (float)0.245843, (float)0.200339, (float)0.280912, (float)0.304941, (float)0.205005, (float)0.290431, (float)0.238096, (float)0.327801, (float)0.348381, (float)0.429329, (float)0.242223, (float)0.285886, (float)0.186399, (float)0.295433, (float)0.563375, (float)0.208059, (float)0.374326, (float)0.290192, (float)0.382046, (float)0.306874, (float)0.210070, (float)0.275039, (float)0.287817, (float)0.187039, (float)0.301513, (float)0.166114, (float)0.299785, (float)0.310108, (float)0.252193, (float)0.241927, (float)0.175803, (float)0.268132, (float)0.281191, (float)0.149509, (float)0.286774, (float)0.315678, (float)0.258718, (float)0.243671, (float)0.146721, (float)0.541647, (float)0.248959, (float)0.283121, (float)0.278269, (float)0.161389, (float)0.196283, (float)0.203411, (float)0.236409, (float)0.252743, (float)0.157319, (float)0.318354, (float)0.284144, (float)0.161263, (float)0.148857, (float)0.285006, (float)0.162499, (float)0.327670, (float)0.493568, (float)0.277950, (float)0.317778, (float)0.174265, (float)0.215775, (float)0.222169, (float)0.282063, (float)0.426734, (float)0.271349, (float)0.177836, (float)0.306651, (float)0.227027, (float)0.177218, (float)0.389682, (float)0.292299, (float)0.484342, (float)0.234477, (float)0.232725, (float)0.274010, (float)0.269951, (float)0.280366, (float)0.403522, (float)0.150091, (float)0.332921, (float)0.328650, (float)0.280335, (float)0.230856, (float)0.173835, (float)0.326979, (float)0.309747, (float)0.180763, (float)0.238421, (float)0.210695, (float)0.324003, (float)0.334594, (float)0.223584, (float)0.206111, (float)0.268665, (float)0.235953, (float)0.333787, (float)0.269394, (float)0.320256, (float)0.289484, (float)0.188421, (float)0.149104, (float)0.395704, (float)0.516672, (float)0.340672, (float)0.185363, (float)0.181559, (float)0.262563, (float)0.185529, (float)0.221933, (float)0.148225, (float)0.258442, (float)0.245774, (float)0.261618, (float)0.239616, (float)0.240172, (float)0.242331, (float)0.346345, (float)0.273092, (float)0.152377, (float)0.251441, (float)0.276048, (float)0.173379, (float)0.271490, (float)0.405222, (float)0.225249, (float)0.367610, (float)0.307018, (float)0.312668, (float)0.183613, (float)0.432988, (float)0.220315, (float)0.207333, (float)0.280325, (float)0.298398, (float)0.219112, (float)0.327168, (float)0.226721, (float)0.274924, (float)0.305604, (float)0.456600, (float)0.296181, (float)0.352823, (float)0.323551, (float)0.422030, (float)0.271530, (float)0.225554, (float)0.290283, (float)0.182879, (float)0.399409, (float)0.282009, (float)0.247102, (float)0.164738, (float)0.365430, (float)0.450432, (float)0.268513, (float)0.299158, (float)0.282500, (float)0.243481, (float)0.221242, (float)0.430044, (float)0.434159, (float)0.198785, (float)0.286281, (float)0.339768, (float)0.244437, (float)0.290467, (float)0.255927, (float)0.258624, (float)0.170158, (float)0.190607, (float)0.253623, (float)0.297827, (float)0.249819, (float)0.377678, (float)0.225250, (float)0.247197, (float)0.224260, (float)0.173196, (float)0.219388, (float)0.209061, (float)0.282015, (float)0.289757, (float)0.288662, (float)0.329191, (float)0.164362, (float)0.296229, (float)0.327889, (float)0.253544, (float)0.279541, (float)0.223803, (float)0.260670, (float)0.193694, (float)0.267951, (float)0.241841, (float)0.519329, (float)0.250175, (float)0.314686, (float)0.216584, (float)0.231314, (float)0.202680, (float)0.187981, (float)0.218013, (float)0.382618, (float)0.387100, (float)0.235753, (float)0.355567, (float)0.227164, (float)0.327212, (float)0.344226, (float)0.315383, (float)0.199268, (float)0.313538, (float)0.225408, (float)0.304828, (float)0.265832, (float)0.333724, (float)0.267948, (float)0.267009, (float)0.236316, (float)0.434741, (float)0.193061, (float)0.199529, (float)0.207250, (float)0.320201, (float)0.266679, (float)0.230467, (float)0.238302, (float)0.224635, (float)0.256233, (float)0.283666, (float)0.404571, (float)0.278617, (float)0.224333, (float)0.159102, (float)0.192333, (float)0.189382, (float)0.249551, (float)0.114005, (float)0.312817, (float)0.319656, (float)0.353033, (float)0.299884, (float)0.211529, (float)0.471820, (float)0.297907, (float)0.347207, (float)0.288995, (float)0.473978, (float)0.223012, (float)0.362989, (float)0.401476, (float)0.244623, (float)0.189659, (float)0.146001, (float)0.187443, (float)0.273355, (float)0.236632, (float)0.300086, (float)0.235897, (float)0.268770, (float)0.325564, (float)0.274938, (float)0.284832, (float)0.229917, (float)0.300114, (float)0.481755, (float)0.307368, (float)0.316406, (float)0.311434, (float)0.354851, (float)0.285893};	// L3943
  #pragma HLS resource variable=v3443 core=ram_t2p_bram

  float v3444[512] = {(float)1.841924, (float)1.830665, (float)1.765044, (float)1.828764, (float)1.950485, (float)1.802649, (float)1.953560, (float)2.278975, (float)1.766216, (float)1.890236, (float)1.776848, (float)1.774939, (float)1.905522, (float)1.732813, (float)1.876214, (float)1.821127, (float)1.796656, (float)2.342822, (float)1.798536, (float)1.727121, (float)1.791495, (float)1.951208, (float)1.892834, (float)1.901748, (float)1.878427, (float)1.980947, (float)1.856939, (float)1.783045, (float)1.891100, (float)1.885943, (float)1.776434, (float)1.983203, (float)1.838904, (float)1.761562, (float)1.872803, (float)1.875332, (float)1.900778, (float)1.820872, (float)1.703864, (float)1.737742, (float)1.778557, (float)1.694390, (float)1.782871, (float)1.781527, (float)1.759392, (float)1.842761, (float)1.923818, (float)2.087056, (float)1.898015, (float)1.841299, (float)1.847065, (float)1.858356, (float)1.764045, (float)1.845287, (float)1.760567, (float)1.950370, (float)1.961970, (float)1.875451, (float)1.942396, (float)1.873090, (float)1.867402, (float)1.942193, (float)1.874984, (float)1.920790, (float)1.746413, (float)1.855831, (float)1.653877, (float)2.066049, (float)2.029759, (float)1.917397, (float)1.897197, (float)1.758860, (float)1.755070, (float)1.955983, (float)1.790851, (float)1.797098, (float)1.785074, (float)1.773338, (float)1.806138, (float)1.794901, (float)1.816864, (float)1.808875, (float)1.864094, (float)2.154163, (float)1.773894, (float)1.791333, (float)1.802216, (float)1.715502, (float)1.767918, (float)1.770429, (float)1.626641, (float)1.864492, (float)1.907619, (float)1.857551, (float)1.692416, (float)1.802023, (float)1.709990, (float)1.771347, (float)1.857234, (float)1.710326, (float)2.066400, (float)1.905368, (float)1.942188, (float)1.807759, (float)1.741196, (float)1.606143, (float)1.910464, (float)1.894665, (float)1.795414, (float)1.898920, (float)1.823906, (float)1.761872, (float)1.795084, (float)1.814886, (float)1.853915, (float)1.850158, (float)1.709521, (float)2.183057, (float)1.859896, (float)1.825197, (float)1.819331, (float)1.846032, (float)1.796820, (float)1.622874, (float)1.844986, (float)1.829045, (float)1.870638, (float)1.929316, (float)1.688099, (float)1.972520, (float)1.898131, (float)1.892510, (float)1.885120, (float)1.844526, (float)1.976428, (float)2.067389, (float)1.838374, (float)1.841449, (float)1.876244, (float)1.793084, (float)1.713145, (float)1.964417, (float)1.785416, (float)1.936923, (float)1.897213, (float)1.893970, (float)1.870030, (float)1.796662, (float)1.877477, (float)1.940897, (float)1.739148, (float)1.794372, (float)1.967792, (float)1.767767, (float)1.685112, (float)1.941390, (float)1.966295, (float)1.988168, (float)1.791470, (float)1.814119, (float)1.832476, (float)2.120046, (float)1.925580, (float)2.359169, (float)2.030399, (float)1.959444, (float)1.733415, (float)1.904849, (float)1.822145, (float)1.781100, (float)1.908426, (float)1.805347, (float)1.917101, (float)1.964422, (float)1.825584, (float)1.643215, (float)1.917314, (float)1.909381, (float)1.992280, (float)1.796252, (float)1.907689, (float)1.761856, (float)2.172372, (float)1.793135, (float)1.756431, (float)1.888935, (float)1.983240, (float)1.913613, (float)1.803543, (float)1.841859, (float)1.827797, (float)1.805722, (float)1.906258, (float)1.864566, (float)1.784804, (float)1.823047, (float)1.798623, (float)1.709148, (float)1.772385, (float)1.793932, (float)1.761125, (float)1.932543, (float)2.016203, (float)1.729540, (float)2.019571, (float)1.887599, (float)1.832458, (float)1.822480, (float)1.786975, (float)1.916026, (float)1.719693, (float)1.716987, (float)1.913316, (float)1.776954, (float)1.994338, (float)1.838863, (float)1.806998, (float)1.851589, (float)1.785702, (float)1.964764, (float)1.955314, (float)1.923161, (float)1.808591, (float)1.811360, (float)1.714114, (float)1.805774, (float)1.853172, (float)1.925512, (float)1.768152, (float)1.831435, (float)1.849486, (float)1.829582, (float)1.827823, (float)1.881891, (float)1.769794, (float)1.783835, (float)1.780722, (float)1.997370, (float)1.699350, (float)1.948276, (float)1.779277, (float)1.802874, (float)2.221012, (float)1.645528, (float)1.835702, (float)2.170646, (float)1.920386, (float)1.741420, (float)1.780923, (float)1.864751, (float)1.914509, (float)1.884929, (float)1.834563, (float)1.936827, (float)1.816905, (float)2.230180, (float)1.826201, (float)2.065090, (float)1.988802, (float)1.816873, (float)1.846174, (float)1.968134, (float)1.808323, (float)1.859548, (float)1.853903, (float)1.769876, (float)1.900066, (float)1.728547, (float)1.755268, (float)1.892441, (float)1.782869, (float)1.942767, (float)1.872420, (float)1.722780, (float)2.054824, (float)1.773247, (float)1.856061, (float)1.769877, (float)1.926942, (float)1.817067, (float)2.407539, (float)1.725657, (float)1.781858, (float)1.724360, (float)1.852108, (float)1.830183, (float)1.879742, (float)1.761717, (float)1.965020, (float)1.980732, (float)1.710236, (float)1.748623, (float)1.835038, (float)1.991866, (float)1.850481, (float)1.899953, (float)1.826905, (float)1.978724, (float)1.763464, (float)1.607073, (float)1.799797, (float)1.954521, (float)1.734773, (float)1.713990, (float)1.885145, (float)1.798079, (float)1.910030, (float)1.831536, (float)1.786438, (float)1.916499, (float)1.883893, (float)1.901720, (float)1.933395, (float)1.740484, (float)1.766093, (float)1.801504, (float)1.998720, (float)1.762174, (float)1.910710, (float)1.844371, (float)1.712762, (float)1.872555, (float)1.852910, (float)1.926968, (float)1.876938, (float)1.726095, (float)1.839320, (float)1.907536, (float)1.795327, (float)1.824615, (float)1.760533, (float)2.047018, (float)1.922079, (float)1.920474, (float)1.890972, (float)1.766609, (float)1.680096, (float)1.830830, (float)1.884494, (float)1.833918, (float)1.823766, (float)1.761641, (float)1.611358, (float)1.841055, (float)1.743720, (float)1.842344, (float)1.953971, (float)1.746498, (float)1.774127, (float)1.874641, (float)1.885600, (float)1.773955, (float)1.760335, (float)1.768241, (float)1.839620, (float)1.686926, (float)1.808025, (float)1.883639, (float)1.828299, (float)1.834092, (float)1.852179, (float)1.974879, (float)1.870677, (float)1.771900, (float)1.899318, (float)1.810824, (float)1.847982, (float)1.826671, (float)1.873141, (float)1.957556, (float)1.834722, (float)1.950949, (float)1.964092, (float)1.799669, (float)1.765217, (float)1.925279, (float)1.712602, (float)1.755079, (float)1.942656, (float)1.855907, (float)1.916284, (float)1.768074, (float)1.780292, (float)1.850017, (float)1.853547, (float)1.886460, (float)1.759878, (float)2.069206, (float)1.802135, (float)1.707732, (float)1.889028, (float)1.945721, (float)1.851559, (float)1.788223, (float)1.835623, (float)1.847209, (float)1.670773, (float)1.743474, (float)1.908001, (float)1.965260, (float)2.040064, (float)1.893518, (float)1.844987, (float)1.753582, (float)1.773277, (float)1.813463, (float)1.853431, (float)1.936762, (float)1.734786, (float)1.873797, (float)1.963245, (float)1.903311, (float)1.742212, (float)1.784246, (float)1.851613, (float)2.021755, (float)1.704387, (float)1.879297, (float)1.865480, (float)1.851599, (float)1.800211, (float)1.868684, (float)1.846039, (float)1.758945, (float)1.817399, (float)1.982992, (float)1.903378, (float)2.122153, (float)1.846037, (float)1.920870, (float)1.889303, (float)1.942176, (float)1.848934, (float)1.839560, (float)1.995323, (float)2.086452, (float)1.825274, (float)1.769959, (float)1.803460, (float)1.753474, (float)1.892261, (float)1.862024, (float)1.862720, (float)1.726408, (float)1.814006, (float)1.961330, (float)1.881199, (float)1.872904, (float)2.005015, (float)1.709180, (float)1.772615, (float)1.940960, (float)1.838086, (float)1.836619, (float)1.727632, (float)1.879583, (float)1.754793, (float)1.953583, (float)1.806152, (float)1.888337, (float)2.027816, (float)1.877468, (float)1.944567, (float)1.867612, (float)1.842294, (float)1.779833, (float)1.940318, (float)1.837511, (float)2.047343, (float)1.950710, (float)1.833741, (float)1.818419, (float)1.779133, (float)1.899275, (float)1.878100, (float)1.869083, (float)1.849270, (float)1.762251, (float)1.945750, (float)1.756408, (float)1.744830, (float)1.863340, (float)1.686286, (float)1.806160, (float)1.870201, (float)2.004785, (float)1.850444, (float)1.896378, (float)1.948875, (float)1.826359, (float)1.901902, (float)1.819593, (float)1.971231, (float)1.896917, (float)1.865206, (float)1.870860, (float)1.698377, (float)1.867712, (float)1.884631, (float)1.925568, (float)1.861968, (float)1.636646, (float)1.843373, (float)1.750554, (float)1.843847, (float)1.578803, (float)1.931623, (float)1.953484, (float)1.787848, (float)1.735447, (float)2.091964, (float)1.945583};	// L3944
  #pragma HLS resource variable=v3444 core=ram_t2p_bram

  float v3445[1000] = {(float)-0.002634, (float)0.003000, (float)0.000656, (float)-0.026909, (float)0.006364, (float)0.013260, (float)-0.011178, (float)0.020639, (float)-0.003637, (float)-0.012325, (float)-0.012629, (float)-0.007206, (float)-0.019321, (float)-0.024960, (float)-0.011885, (float)-0.008326, (float)-0.009575, (float)-0.016658, (float)0.009180, (float)-0.015354, (float)0.007136, (float)0.030737, (float)0.013239, (float)-0.007753, (float)0.004745, (float)0.011175, (float)0.015949, (float)-0.016712, (float)-0.001013, (float)-0.003717, (float)0.006527, (float)-0.012041, (float)0.009043, (float)-0.000833, (float)0.008865, (float)-0.026307, (float)-0.014588, (float)0.002943, (float)0.002972, (float)-0.019125, (float)-0.004792, (float)0.013828, (float)0.009880, (float)-0.018417, (float)0.019734, (float)0.001694, (float)0.012420, (float)-0.005584, (float)-0.010612, (float)0.000398, (float)0.004273, (float)-0.013298, (float)0.020661, (float)0.016963, (float)0.002795, (float)0.000742, (float)0.013168, (float)0.003221, (float)0.010458, (float)0.016511, (float)0.000917, (float)0.003939, (float)-0.005653, (float)0.019372, (float)0.007524, (float)0.013437, (float)-0.013185, (float)-0.010026, (float)0.007192, (float)-0.002317, (float)-0.018895, (float)0.012519, (float)0.001958, (float)0.007384, (float)-0.009666, (float)0.020189, (float)0.007665, (float)0.018529, (float)0.015710, (float)0.018582, (float)-0.006931, (float)0.017090, (float)0.009127, (float)-0.038876, (float)-0.024116, (float)-0.006872, (float)-0.011648, (float)0.007882, (float)0.001805, (float)0.028480, (float)-0.019379, (float)-0.016295, (float)0.010468, (float)-0.013027, (float)-0.008421, (float)-0.029210, (float)-0.002486, (float)-0.008714, (float)-0.016397, (float)-0.009305, (float)-0.015931, (float)-0.026346, (float)-0.001109, (float)0.022589, (float)0.002139, (float)-0.023212, (float)-0.014085, (float)-0.005622, (float)-0.020090, (float)-0.030284, (float)-0.049574, (float)0.023283, (float)0.014954, (float)-0.007750, (float)-0.003948, (float)-0.037629, (float)-0.024220, (float)-0.010194, (float)-0.007704, (float)-0.004131, (float)-0.002955, (float)-0.006217, (float)-0.012076, (float)-0.007017, (float)-0.003895, (float)-0.016953, (float)-0.024585, (float)0.005535, (float)-0.008337, (float)-0.007076, (float)-0.024023, (float)-0.006369, (float)0.000734, (float)0.005288, (float)-0.022181, (float)-0.026972, (float)-0.017990, (float)-0.016393, (float)0.002148, (float)-0.016122, (float)-0.016112, (float)0.006593, (float)-0.020045, (float)0.006415, (float)-0.012601, (float)-0.007624, (float)0.011411, (float)-0.045084, (float)-0.009202, (float)-0.015563, (float)-0.013590, (float)-0.001437, (float)-0.019466, (float)0.020737, (float)-0.010476, (float)0.006323, (float)0.008323, (float)-0.010791, (float)-0.018903, (float)0.005862, (float)-0.002019, (float)0.032436, (float)0.040581, (float)-0.000041, (float)0.010886, (float)-0.016544, (float)-0.000534, (float)-0.022903, (float)0.004629, (float)-0.004840, (float)0.010187, (float)0.017954, (float)0.004821, (float)0.006183, (float)0.014419, (float)-0.012094, (float)-0.008746, (float)0.001949, (float)0.014685, (float)0.012464, (float)0.007052, (float)-0.004178, (float)0.012048, (float)-0.020199, (float)0.009914, (float)0.013978, (float)-0.001032, (float)0.005739, (float)0.001402, (float)0.000601, (float)-0.000558, (float)0.024424, (float)0.023076, (float)-0.014610, (float)0.011185, (float)0.034608, (float)0.016944, (float)0.004330, (float)-0.025606, (float)0.012279, (float)-0.025810, (float)0.008536, (float)0.020437, (float)0.022557, (float)0.022966, (float)0.008842, (float)-0.013894, (float)0.003872, (float)-0.009305, (float)0.023220, (float)-0.014949, (float)0.006926, (float)0.005007, (float)-0.017302, (float)0.001036, (float)-0.010223, (float)-0.009695, (float)0.034534, (float)0.006134, (float)0.011582, (float)-0.020529, (float)-0.021956, (float)0.005311, (float)0.034101, (float)-0.005808, (float)0.029406, (float)-0.008795, (float)-0.005250, (float)-0.019088, (float)0.030350, (float)0.018445, (float)-0.021225, (float)0.018432, (float)0.013832, (float)0.017848, (float)-0.004476, (float)0.035858, (float)0.021762, (float)0.010880, (float)0.040255, (float)-0.002005, (float)-0.003035, (float)0.009329, (float)-0.016304, (float)0.000963, (float)0.018673, (float)-0.016567, (float)0.014964, (float)-0.003721, (float)-0.007673, (float)-0.000008, (float)0.003973, (float)-0.009598, (float)-0.016833, (float)0.000059, (float)-0.006413, (float)0.008298, (float)0.004821, (float)-0.001147, (float)0.004887, (float)0.017349, (float)0.003922, (float)-0.007808, (float)0.016051, (float)0.009880, (float)-0.010144, (float)0.020912, (float)-0.006320, (float)-0.023139, (float)0.001165, (float)0.022468, (float)-0.006695, (float)0.018311, (float)0.014623, (float)-0.011654, (float)-0.014306, (float)0.012974, (float)-0.009687, (float)-0.006235, (float)0.013180, (float)0.006754, (float)0.046418, (float)-0.027962, (float)-0.015111, (float)0.028716, (float)0.009199, (float)-0.005371, (float)-0.006036, (float)-0.007214, (float)-0.009242, (float)0.001854, (float)-0.003108, (float)-0.008400, (float)-0.016766, (float)0.004094, (float)0.006243, (float)-0.001247, (float)-0.012919, (float)0.003582, (float)0.011006, (float)-0.013282, (float)0.002640, (float)0.008995, (float)0.006542, (float)-0.012031, (float)0.017149, (float)0.017949, (float)-0.010581, (float)-0.026962, (float)-0.013564, (float)-0.009717, (float)-0.002118, (float)0.035370, (float)0.018392, (float)0.026676, (float)-0.001059, (float)-0.003395, (float)-0.004884, (float)0.013427, (float)-0.013948, (float)-0.019559, (float)-0.023295, (float)-0.037834, (float)-0.014637, (float)-0.021323, (float)-0.030952, (float)-0.030822, (float)0.001944, (float)0.002864, (float)-0.021198, (float)0.010448, (float)-0.011316, (float)-0.004261, (float)0.022647, (float)-0.012867, (float)-0.011018, (float)0.012336, (float)-0.020057, (float)-0.021837, (float)-0.006807, (float)-0.010488, (float)-0.026298, (float)-0.009958, (float)-0.012966, (float)-0.002483, (float)-0.007094, (float)0.017997, (float)-0.006426, (float)0.007907, (float)-0.012287, (float)0.009818, (float)0.002667, (float)-0.021524, (float)0.002751, (float)-0.009207, (float)-0.017541, (float)-0.001710, (float)-0.014588, (float)0.004425, (float)0.034405, (float)0.012725, (float)0.030885, (float)0.001309, (float)-0.000070, (float)-0.002317, (float)-0.003799, (float)-0.011148, (float)0.017210, (float)-0.006757, (float)-0.000137, (float)-0.008917, (float)-0.016281, (float)-0.004492, (float)0.011332, (float)-0.001591, (float)-0.008819, (float)-0.004940, (float)0.004573, (float)-0.010949, (float)0.012890, (float)-0.006659, (float)-0.002561, (float)0.002796, (float)0.011225, (float)-0.022055, (float)-0.003927, (float)-0.006647, (float)-0.018840, (float)-0.021687, (float)-0.000741, (float)-0.027281, (float)0.005045, (float)-0.020709, (float)-0.034103, (float)-0.022374, (float)-0.016656, (float)-0.027916, (float)-0.009898, (float)0.005525, (float)0.016013, (float)-0.014895, (float)0.003509, (float)0.009000, (float)-0.008398, (float)-0.037479, (float)0.020727, (float)-0.005880, (float)0.009177, (float)-0.020297, (float)-0.007315, (float)-0.001697, (float)-0.001403, (float)0.003223, (float)0.029212, (float)0.012487, (float)-0.020100, (float)0.021170, (float)-0.025300, (float)0.031815, (float)-0.001064, (float)-0.010449, (float)-0.023419, (float)0.014564, (float)0.021245, (float)0.016530, (float)-0.003244, (float)-0.020437, (float)-0.036982, (float)-0.008721, (float)0.005457, (float)0.001105, (float)0.002201, (float)0.002951, (float)-0.000060, (float)0.000558, (float)-0.003691, (float)0.005376, (float)-0.024765, (float)0.009273, (float)0.009608, (float)0.009165, (float)0.009088, (float)0.007484, (float)-0.011946, (float)0.021395, (float)0.027922, (float)0.014692, (float)-0.002496, (float)0.028887, (float)0.013422, (float)0.001717, (float)0.002502, (float)-0.021253, (float)-0.000824, (float)0.004218, (float)0.008598, (float)0.018735, (float)0.008562, (float)-0.008826, (float)0.017462, (float)-0.013693, (float)0.002196, (float)0.010772, (float)0.002869, (float)0.031032, (float)0.008546, (float)-0.014198, (float)-0.002247, (float)0.018740, (float)-0.012905, (float)0.040370, (float)-0.000775, (float)0.001867, (float)0.007279, (float)-0.026508, (float)-0.017609, (float)-0.024142, (float)0.002958, (float)-0.015917, (float)0.001627, (float)0.011132, (float)0.014574, (float)-0.008192, (float)-0.007658, (float)-0.018452, (float)-0.009042, (float)0.004088, (float)0.044482, (float)-0.023664, (float)-0.005255, (float)-0.019529, (float)0.003286, (float)0.005467, (float)-0.004956, (float)0.007680, (float)-0.003303, (float)-0.002625, (float)-0.011094, (float)0.023922, (float)0.018079, (float)-0.018135, (float)0.005220, (float)-0.013559, (float)0.019448, (float)0.010981, (float)0.026869, (float)-0.006680, (float)-0.000894, (float)-0.003492, (float)-0.019667, (float)-0.018511, (float)-0.000763, (float)-0.016382, (float)-0.015862, (float)-0.013717, (float)0.017528, (float)-0.001142, (float)-0.006335, (float)-0.011118, (float)0.013159, (float)-0.023464, (float)0.000280, (float)-0.000363, (float)0.023797, (float)-0.002735, (float)-0.022223, (float)0.013415, (float)0.010443, (float)-0.023512, (float)0.016832, (float)0.004370, (float)-0.013243, (float)-0.002861, (float)0.005421, (float)0.001992, (float)-0.000687, (float)-0.000391, (float)0.017806, (float)0.018391, (float)0.028473, (float)-0.033835, (float)-0.010778, (float)-0.012371, (float)-0.001911, (float)-0.001638, (float)0.017288, (float)-0.003981, (float)-0.015167, (float)-0.010781, (float)0.005381, (float)-0.000339, (float)0.000339, (float)-0.010162, (float)-0.004027, (float)-0.003475, (float)0.004236, (float)-0.001468, (float)0.013207, (float)0.007558, (float)0.000194, (float)0.003005, (float)0.008628, (float)-0.011193, (float)0.038466, (float)-0.026220, (float)-0.020251, (float)-0.006387, (float)0.021906, (float)-0.007340, (float)0.005275, (float)-0.011709, (float)0.008401, (float)0.002853, (float)-0.004722, (float)0.023118, (float)-0.007604, (float)0.002814, (float)-0.011701, (float)-0.004412, (float)0.011846, (float)-0.001763, (float)-0.012260, (float)-0.002121, (float)0.012072, (float)0.006752, (float)-0.000191, (float)-0.025105, (float)0.012693, (float)0.016062, (float)0.008126, (float)0.001386, (float)0.003009, (float)-0.014111, (float)0.019784, (float)-0.000923, (float)-0.018428, (float)0.007806, (float)0.015319, (float)-0.012768, (float)-0.009017, (float)0.018031, (float)0.024853, (float)0.017788, (float)0.008864, (float)-0.009442, (float)-0.001365, (float)0.012932, (float)0.009013, (float)0.016655, (float)-0.005432, (float)0.027480, (float)-0.031781, (float)-0.013331, (float)0.005579, (float)-0.013278, (float)-0.019219, (float)-0.013307, (float)0.004239, (float)0.030246, (float)-0.008199, (float)0.008301, (float)0.018993, (float)0.010643, (float)0.031324, (float)0.019283, (float)0.003364, (float)0.019669, (float)0.002267, (float)-0.019630, (float)0.020147, (float)-0.011433, (float)-0.007607, (float)0.015071, (float)-0.003040, (float)-0.009343, (float)-0.004166, (float)0.002297, (float)-0.005099, (float)-0.014499, (float)-0.027673, (float)-0.038721, (float)0.005425, (float)0.013504, (float)-0.001281, (float)0.037465, (float)0.001515, (float)0.024035, (float)-0.020557, (float)0.009841, (float)0.010352, (float)0.038597, (float)-0.011905, (float)-0.021718, (float)0.008378, (float)0.014691, (float)0.022631, (float)-0.003763, (float)0.015570, (float)-0.009399, (float)0.005354, (float)0.019584, (float)-0.011156, (float)0.015190, (float)0.005462, (float)0.022995, (float)0.029260, (float)-0.001524, (float)0.006601, (float)-0.031939, (float)-0.010486, (float)-0.004462, (float)0.031853, (float)0.013736, (float)0.013561, (float)0.007091, (float)-0.016753, (float)-0.025470, (float)0.019752, (float)0.026715, (float)-0.004686, (float)0.017682, (float)0.032496, (float)0.014553, (float)0.026101, (float)0.011341, (float)-0.002227, (float)0.035237, (float)-0.011892, (float)-0.018683, (float)-0.005525, (float)-0.007073, (float)-0.005267, (float)0.007595, (float)-0.018465, (float)-0.016897, (float)0.010127, (float)0.013006, (float)-0.001825, (float)0.000667, (float)-0.011207, (float)0.013563, (float)-0.018153, (float)-0.026487, (float)0.006065, (float)0.039711, (float)-0.014285, (float)0.018001, (float)-0.014039, (float)-0.018762, (float)-0.011778, (float)-0.016449, (float)0.009042, (float)-0.007273, (float)0.017517, (float)-0.000730, (float)0.010212, (float)0.023785, (float)0.008129, (float)0.008026, (float)0.011922, (float)0.006242, (float)-0.024625, (float)0.029461, (float)-0.014183, (float)-0.018672, (float)-0.014057, (float)0.007987, (float)-0.021081, (float)-0.027560, (float)-0.003569, (float)0.001599, (float)0.009472, (float)0.018272, (float)-0.002374, (float)0.001184, (float)-0.000577, (float)0.008782, (float)0.002780, (float)0.000680, (float)0.015877, (float)-0.007036, (float)0.002549, (float)-0.017925, (float)0.008491, (float)0.004338, (float)0.024508, (float)0.003669, (float)0.010252, (float)-0.013396, (float)0.000457, (float)0.010313, (float)0.015229, (float)0.039907, (float)-0.008081, (float)0.013760, (float)-0.006586, (float)0.006607, (float)-0.031480, (float)0.024665, (float)0.003437, (float)0.020973, (float)0.019384, (float)-0.020880, (float)0.007147, (float)0.010406, (float)0.000022, (float)-0.019182, (float)0.006314, (float)-0.000169, (float)0.008866, (float)-0.004767, (float)-0.014493, (float)0.003218, (float)0.007335, (float)0.020694, (float)-0.000500, (float)0.018820, (float)0.039147, (float)-0.027095, (float)-0.018293, (float)-0.019868, (float)-0.009405, (float)0.004155, (float)0.005384, (float)-0.004666, (float)-0.013019, (float)-0.024452, (float)-0.008923, (float)-0.014603, (float)0.002553, (float)-0.030766, (float)0.011169, (float)-0.006811, (float)-0.007597, (float)-0.009319, (float)0.001492, (float)-0.002343, (float)0.000444, (float)-0.010810, (float)0.008850, (float)-0.021022, (float)-0.008038, (float)-0.010818, (float)-0.006482, (float)-0.002068, (float)0.022326, (float)-0.019234, (float)0.004084, (float)0.000772, (float)0.001723, (float)-0.017454, (float)-0.013190, (float)-0.007411, (float)-0.001755, (float)0.001293, (float)-0.006703, (float)-0.007059, (float)0.006275, (float)-0.018068, (float)-0.009486, (float)-0.020856, (float)0.008960, (float)0.021294, (float)0.017025, (float)0.021015, (float)0.008823, (float)-0.009828, (float)-0.022293, (float)0.024295, (float)-0.011174, (float)-0.007575, (float)0.006118, (float)-0.020653, (float)-0.016264, (float)0.026457, (float)-0.014782, (float)0.018654, (float)0.025488, (float)0.024106, (float)0.004789, (float)0.023329, (float)0.000358, (float)0.025154, (float)0.017094, (float)0.017803, (float)0.024687, (float)0.009008, (float)0.002361, (float)0.026088, (float)-0.014110, (float)-0.000542, (float)0.000895, (float)0.021150, (float)0.004848, (float)-0.030503, (float)-0.007503, (float)-0.033718, (float)-0.028913, (float)0.015691, (float)0.006205, (float)-0.010853, (float)0.019524, (float)-0.016188, (float)0.008989, (float)0.009189, (float)-0.002859, (float)-0.010911, (float)0.010848, (float)0.048784, (float)-0.001969, (float)0.026843, (float)-0.004872, (float)0.013489, (float)-0.014523, (float)-0.027585, (float)0.006123, (float)0.004817, (float)0.002157, (float)-0.037561, (float)0.030775, (float)0.019977, (float)0.018480, (float)0.003037, (float)0.009382, (float)0.000452, (float)0.061650, (float)-0.008642, (float)-0.026913, (float)0.006353, (float)0.007799, (float)0.013180, (float)-0.001667, (float)0.020865, (float)0.009948, (float)0.008814, (float)0.014841, (float)0.003321, (float)0.003634, (float)0.028740, (float)-0.022120, (float)-0.007157, (float)0.010352, (float)0.016433, (float)0.011683, (float)-0.005806, (float)-0.000693, (float)0.026578, (float)0.008797, (float)-0.031689, (float)0.018949, (float)-0.008586, (float)0.034228, (float)-0.015237, (float)-0.005971, (float)0.001107, (float)-0.018394, (float)-0.019246, (float)-0.036361, (float)0.003984, (float)0.041237, (float)0.013816, (float)-0.007330, (float)0.003883, (float)0.002437, (float)-0.021625, (float)-0.014523, (float)-0.000163, (float)0.000626, (float)-0.016798, (float)0.023083, (float)0.009711, (float)-0.008221, (float)0.001160, (float)-0.020983, (float)-0.006654, (float)-0.014097, (float)0.003407, (float)-0.007758, (float)-0.014738, (float)-0.021343, (float)0.005412, (float)0.003975, (float)-0.004619, (float)-0.015462, (float)-0.007623, (float)0.012211, (float)-0.004845, (float)-0.008876, (float)-0.010275, (float)0.007348, (float)-0.006035, (float)0.002366, (float)0.021053, (float)-0.008569, (float)-0.011630, (float)-0.027332, (float)-0.020648, (float)0.004495, (float)-0.018649, (float)-0.011564, (float)0.000459, (float)-0.006183, (float)-0.024435, (float)-0.007119, (float)-0.014394, (float)-0.002354, (float)0.021556, (float)0.022924, (float)-0.013725, (float)0.007779, (float)-0.008551, (float)0.024221, (float)0.003819, (float)0.000709, (float)0.016114, (float)0.025932, (float)0.018108, (float)0.029306, (float)0.001677, (float)-0.003017, (float)0.032015, (float)-0.014034, (float)0.027365, (float)-0.018858, (float)0.002583, (float)0.013498, (float)-0.013502, (float)-0.014940, (float)-0.010904, (float)0.018642, (float)0.004259, (float)-0.016742, (float)-0.012638, (float)-0.045468, (float)-0.005082, (float)-0.025093, (float)0.006785, (float)-0.017868, (float)-0.000782, (float)-0.006345};	// L3945
  #pragma HLS resource variable=v3445 core=ram_t2p_bram

  forward_node217(v3084, v3082, v3106, v3105);	// L3946
  forward_node213(v3107, v3369, v3371, v3368, v3370, v3108);	// L3947
  forward_node208(v3109, v3111, v3110);	// L3948
  forward_node201(v3085, v3112, v3114, v3121, v3120);	// L3949
  forward_node197(v3373, v3372, v3374, v3375, v3122, v3123);	// L3950
  forward_node190(v3124, v3086, v3115, v3126, v3125);	// L3951
  forward_node185(v3113, v3377, v3378, v3127, v3376, v3379, v3128);	// L3952
  forward_node178(v3129, v3087, v3116, v3132, v3131);	// L3953
  forward_node174(v3380, v3381, v3383, v3133, v3382, v3134);	// L3954
  forward_node168(v3135, v3088, v3118, v3117);	// L3955
  forward_node163(v3385, v3130, v3387, v3386, v3384, v3119, v3136);	// L3956
  forward_node156(v3089, v3137, v3139, v3147, v3146);	// L3957
  forward_node152(v3391, v3148, v3388, v3390, v3389, v3149);	// L3958
  forward_node145(v3090, v3150, v3140, v3152, v3151);	// L3959
  forward_node138(v3138, v3141, v3091, v3155, v3154);	// L3960
  forward_node133(v3395, v3393, v3153, v3392, v3156, v3398, v3396, v3397, v3394, v3157);	// L3961
  forward_node126(v3158, v3092, v3142, v3161, v3160);	// L3962
  forward_node122(v3402, v3401, v3162, v3400, v3399, v3163);	// L3963
  forward_node116(v3164, v3093, v3144, v3143);	// L3964
  forward_node111(v3159, v3406, v3405, v3404, v3403, v3145, v3165);	// L3965
  forward_node104(v3168, v3094, v3166, v3176, v3175);	// L3966
  forward_node100(v3410, v3407, v3177, v3409, v3408, v3178);	// L3967
  forward_node93(v3169, v3179, v3095, v3181, v3180);	// L3968
  forward_node86(v3170, v3096, v3167, v3184, v3183);	// L3969
  forward_node81(v3416, v3182, v3185, v3417, v3412, v3414, v3413, v3411, v3415, v3186);	// L3970
  forward_node74(v3171, v3187, v3097, v3190, v3189);	// L3971
  forward_node70(v3421, v3418, v3420, v3419, v3191, v3192);	// L3972
  forward_node64(v3098, v3193, v3173, v3172);	// L3973
  forward_node59(v3174, v3188, v3425, v3424, v3422, v3423, v3194);	// L3974
  forward_node52(v3099, v3195, v3197, v3205, v3204);	// L3975
  forward_node48(v3427, v3426, v3429, v3428, v3206, v3207);	// L3976
  forward_node41(v3100, v3198, v3208, v3210, v3209);	// L3977
  forward_node34(v3101, v3196, v3199, v3213, v3212);	// L3978
  forward_node29(v3436, v3434, v3433, v3431, v3211, v3430, v3214, v3432, v3435, v3215);	// L3979
  forward_node22(v3200, v3216, v3102, v3219, v3218);	// L3980
  forward_node18(v3439, v3220, v3438, v3440, v3437, v3221);	// L3981
  forward_node12(v3222, v3103, v3202, v3201);	// L3982
  forward_node7(v3444, v3443, v3442, v3203, v3441, v3217, v3223);	// L3983
  float v3446[512];	// L3984
  #pragma HLS resource variable=v3446 core=ram_t2p_bram

  forward_node4(v3224, v3446);	// L3985
  forward_node0(v3104, v3446, v3445, v3083);	// L3986
}

