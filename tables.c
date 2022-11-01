#define ORDER 4

#define RANDOM_LENGTH 1024

//gadget_x就是输入的x^
unsigned int gadget_x[ORDER] = {0x4632,0xE97A};
unsigned int gadget_y[ORDER] = {0x2354, 0xAF23};
//gadget_z存放结果
unsigned int gadget_z[ORDER]={0};
unsigned int gadget_x_dot[ORDER]={0};
unsigned int gadget_y_dot[ORDER]={0};

unsigned int gadget_online_x[1]={0xbd7c};
unsigned int gadget_online_y[1]={0xDA0F};
unsigned int gadget_online_z[1]={0};

unsigned int gadget_online_x_dot[1]={0};
unsigned int gadget_online_y_dot[1]={0};


unsigned int matrixRx[ORDER][ORDER]={{0x1245,0x3445},{0x2666,0x2355}};
unsigned int matrixRy[ORDER][ORDER]= {{0x1675,0x1999},{0x9734,0x3563}};
unsigned int matrixR[ORDER][ORDER] = {{0x8563,0x8289},{0x9384,0x923D}};
unsigned int alpha[ORDER]={0xFFFF,0xFFFF};
unsigned int t_first[1];
unsigned int t_second[1];
unsigned int r[ORDER];

//xtest的3各share异或起来是0x1264
unsigned int sbxtest[ORDER]={0};
//ytest的3各share异或起来是0xA6BD

unsigned int sbytest[ORDER]={0};

//xtest and ytest = 0x224
unsigned int sbttest[ORDER]={0};
unsigned int sband0txtest[ORDER]={0};
unsigned int sband0tytest[ORDER]={0};
unsigned int sband0tttest[ORDER]={0};

unsigned int online_sbxtest[1]={0x772D};
unsigned int online_sbytest[1]={0x65A9};
unsigned int online_sbttest[1]={0};
unsigned int test_random_table[1] = {0}; 
unsigned int random_table[RANDOM_LENGTH]={63312, 36836, 35604, 49307, 20637, 26178, 45314, 37202, 5420, 33957, 5398, 6371, 24992, 56394, 47675, 59440, 20463, 3070, 10435, 34748, 26719, 8279, 6730, 63209, 14599, 33486, 52421, 31587, 44571, 17128, 62514, 55684, 3137, 62752, 37430, 46186, 20428, 27254, 49725, 58643, 16752, 30783, 48410, 41553, 741, 54360, 32789, 30621, 58038, 14492, 52870, 28521, 7150, 55770, 64830, 4533, 20130, 38216, 36253, 39198, 14689, 7451, 45298, 55837, 58346, 18865, 1065, 35025, 16811, 41215, 26544, 60375, 55969, 18728, 4472, 34593, 63750, 34964, 46480, 1159, 41889, 29018, 16841, 24420, 39787, 29247, 9824, 59262, 12623, 33523, 36633, 50715, 35868, 8274, 18832, 37216};
unsigned int AES_bitslice_const_address[] = {0x55555555, 0xAAAAAAAA,0x33333333,0xCCCCCCCC,0x0F0F0F0F,0xF0F0F0F0};

//密钥暂时先存在round_key的前4个里面
unsigned int round_key[44]={0x04030201,0x08070605,0x0C0B0A09,0x010F0E0D};

unsigned int bitsliced_round_key[88];
unsigned int sbx0[ORDER]={0x51e9};
unsigned int sbx1[ORDER]={0x2086};
unsigned int sbx2[ORDER]={0xc363};
unsigned int sbx3[ORDER]={0x80b9};
unsigned int sbx4[ORDER]={0x3aa6};
unsigned int sbx5[ORDER]={0xae2b};
unsigned int sbx6[ORDER]={0x9645};
unsigned int sbx7[ORDER]={0x50fa};





unsigned int sby0[ORDER]={0};
unsigned int sby1[ORDER]={0};
unsigned int sby2[ORDER]={0};
unsigned int sby3[ORDER]={0};
unsigned int sby4[ORDER]={0};
unsigned int sby5[ORDER]={0};
unsigned int sby6[ORDER]={0};
unsigned int sby7[ORDER]={0};
unsigned int sby8[ORDER]={0};
unsigned int sby9[ORDER]={0};
unsigned int sby10[ORDER]={0};
unsigned int sby11[ORDER]={0};
unsigned int sby12[ORDER]={0};
unsigned int sby13[ORDER]={0};
unsigned int sby14[ORDER]={0};
unsigned int sby15[ORDER]={0};
unsigned int sby16[ORDER]={0};
unsigned int sby17[ORDER]={0};
unsigned int sby18[ORDER]={0};
unsigned int sby19[ORDER]={0};
unsigned int sby20[ORDER]={0};
unsigned int sby21[ORDER]={0};

unsigned int sbt0[ORDER]={0};
unsigned int sbt1[ORDER]={0};
unsigned int sbt2[ORDER]={0};
unsigned int sbt3[ORDER]={0};
unsigned int sbt4[ORDER]={0};
unsigned int sbt5[ORDER]={0};
unsigned int sbt6[ORDER]={0};
unsigned int sbt7[ORDER]={0};
unsigned int sbt8[ORDER]={0};
unsigned int sbt9[ORDER]={0};
unsigned int sbt10[ORDER]={0};
unsigned int sbt11[ORDER]={0};
unsigned int sbt12[ORDER]={0};
unsigned int sbt13[ORDER]={0};
unsigned int sbt14[ORDER]={0};
unsigned int sbt15[ORDER]={0};
unsigned int sbt16[ORDER]={0};
unsigned int sbt17[ORDER]={0};
unsigned int sbt18[ORDER]={0};
unsigned int sbt19[ORDER]={0};
unsigned int sbt20[ORDER]={0};
unsigned int sbt21[ORDER]={0};
unsigned int sbt22[ORDER]={0};
unsigned int sbt23[ORDER]={0};
unsigned int sbt24[ORDER]={0};
unsigned int sbt25[ORDER]={0};
unsigned int sbt26[ORDER]={0};
unsigned int sbt27[ORDER]={0};
unsigned int sbt28[ORDER]={0};
unsigned int sbt29[ORDER]={0};
unsigned int sbt30[ORDER]={0};
unsigned int sbt31[ORDER]={0};
unsigned int sbt32[ORDER]={0};
unsigned int sbt33[ORDER]={0};
unsigned int sbt34[ORDER]={0};
unsigned int sbt35[ORDER]={0};
unsigned int sbt36[ORDER]={0};
unsigned int sbt37[ORDER]={0};
unsigned int sbt38[ORDER]={0};
unsigned int sbt39[ORDER]={0};
unsigned int sbt40[ORDER]={0};
unsigned int sbt41[ORDER]={0};
unsigned int sbt42[ORDER]={0};
unsigned int sbt43[ORDER]={0};
unsigned int sbt44[ORDER]={0};
unsigned int sbt45[ORDER]={0};
unsigned int sbt46[ORDER]={0};
unsigned int sbt47[ORDER]={0};
unsigned int sbt48[ORDER]={0};
unsigned int sbt49[ORDER]={0};
unsigned int sbt50[ORDER]={0};
unsigned int sbt51[ORDER]={0};
unsigned int sbt52[ORDER]={0};
unsigned int sbt53[ORDER]={0};
unsigned int sbt54[ORDER]={0};
unsigned int sbt55[ORDER]={0};
unsigned int sbt56[ORDER]={0};
unsigned int sbt57[ORDER]={0};
unsigned int sbt58[ORDER]={0};
unsigned int sbt59[ORDER]={0};
unsigned int sbt60[ORDER]={0};
unsigned int sbt61[ORDER]={0};
unsigned int sbt62[ORDER]={0};
unsigned int sbt63[ORDER]={0};
unsigned int sbt64[ORDER]={0};
unsigned int sbt65[ORDER]={0};
unsigned int sbt66[ORDER]={0};
unsigned int sbt67[ORDER]={0};

unsigned int sbs0[ORDER]={0};;
unsigned int sbs1[ORDER]={0};;
unsigned int sbs2[ORDER]={0};
unsigned int sbs3[ORDER]={0};
unsigned int sbs4[ORDER]={0};
unsigned int sbs5[ORDER]={0};
unsigned int sbs6[ORDER]={0};
unsigned int sbs7[ORDER]={0};


unsigned int sbz0[ORDER]={0};
unsigned int sbz1[ORDER]={0};
unsigned int sbz2[ORDER]={0};
unsigned int sbz3[ORDER]={0};
unsigned int sbz4[ORDER]={0};
unsigned int sbz5[ORDER]={0};
unsigned int sbz6[ORDER]={0};
unsigned int sbz8[ORDER]={0};
unsigned int sbz7[ORDER]={0};
unsigned int sbz9[ORDER]={0};
unsigned int sbz10[ORDER]={0};
unsigned int sbz11[ORDER]={0};
unsigned int sbz12[ORDER]={0};
unsigned int sbz13[ORDER]={0};
unsigned int sbz14[ORDER]={0};
unsigned int sbz15[ORDER]={0};
unsigned int sbz16[ORDER]={0};
unsigned int sbz17[ORDER]={0};

unsigned int sband1ty12[ORDER];
unsigned int sband1ty15[ORDER];
unsigned int sband1tr[ORDER];
unsigned int sband2ty3[ORDER];
unsigned int sband2ty6[ORDER];
unsigned int sband2tr[ORDER];
unsigned int sband3ty4[ORDER];
unsigned int sband3tx7[ORDER];
unsigned int sband3tr[ORDER];
unsigned int sband4ty13[ORDER];
unsigned int sband4ty16[ORDER];
unsigned int sband4tr[ORDER];
unsigned int sband5ty5[ORDER];
unsigned int sband5ty1[ORDER];
unsigned int sband5tr[ORDER];
unsigned int sband6ty2[ORDER];
unsigned int sband6ty7[ORDER];
unsigned int sband6tr[ORDER];
unsigned int sband7ty9[ORDER];
unsigned int sband7ty11[ORDER];
unsigned int sband7tr[ORDER];
unsigned int sband8ty14[ORDER];
unsigned int sband8ty17[ORDER];
unsigned int sband8tr[ORDER];
unsigned int sband9ty8[ORDER];
unsigned int sband9ty10[ORDER];
unsigned int sband9tr[ORDER];
unsigned int sband10tt21[ORDER];
unsigned int sband10tt23[ORDER];
unsigned int sband10tr[ORDER];
unsigned int sband11tt25[ORDER];
unsigned int sband11tt27[ORDER];
unsigned int sband11tr[ORDER];
unsigned int sband12tt31[ORDER];
unsigned int sband12tt30[ORDER];
unsigned int sband12tr[ORDER];
unsigned int sband13tt29[ORDER];
unsigned int sband13ty2[ORDER];
unsigned int sband13tr[ORDER];
unsigned int sband14tt24[ORDER];
unsigned int sband14tt35[ORDER];
unsigned int sband14tr[ORDER];
unsigned int sband15tt29[ORDER];
unsigned int sband15tt38[ORDER];
unsigned int sband15tr[ORDER];
unsigned int sband16tt29[ORDER];
unsigned int sband16ty7[ORDER];
unsigned int sband16tr[ORDER];
unsigned int sband17tt44[ORDER];
unsigned int sband17ty15[ORDER];
unsigned int sband17tr[ORDER];
unsigned int sband18tt37[ORDER];
unsigned int sband18ty6[ORDER];
unsigned int sband18tr[ORDER];
unsigned int sband19tt33[ORDER];
unsigned int sband19tx7[ORDER];
unsigned int sband19tr[ORDER];
unsigned int sband20tt43[ORDER];
unsigned int sband20ty16[ORDER];
unsigned int sband20tr[ORDER];
unsigned int sband21tt40[ORDER];
unsigned int sband21ty1[ORDER];
unsigned int sband21tr[ORDER];
unsigned int sband22tt42[ORDER];
unsigned int sband22ty11[ORDER];
unsigned int sband22tr[ORDER];
unsigned int sband23tt45[ORDER];
unsigned int sband23ty17[ORDER];
unsigned int sband23tr[ORDER];
unsigned int sband24tt41[ORDER];
unsigned int sband24ty10[ORDER];
unsigned int sband24tr[ORDER];
unsigned int sband25tt44[ORDER];
unsigned int sband25ty12[ORDER];
unsigned int sband25tr[ORDER];
unsigned int sband26tt37[ORDER];
unsigned int sband26ty3[ORDER];
unsigned int sband26tr[ORDER];
unsigned int sband27tt33[ORDER];
unsigned int sband27ty4[ORDER];
unsigned int sband27tr[ORDER];
unsigned int sband28tt43[ORDER];
unsigned int sband28ty13[ORDER];
unsigned int sband28tr[ORDER];
unsigned int sband29tt40[ORDER];
unsigned int sband29ty5[ORDER];
unsigned int sband29tr[ORDER];
unsigned int sband30tt42[ORDER];
unsigned int sband30ty9[ORDER];
unsigned int sband30tr[ORDER];
unsigned int sband31tt45[ORDER];
unsigned int sband31ty14[ORDER];
unsigned int sband31tr[ORDER];
unsigned int sband32tt41[ORDER];
unsigned int sband32ty8[ORDER];
unsigned int sband32tr[ORDER];

unsigned int online_sbx0[1]={0x9ba8};
unsigned int online_sbx1[1]={0x433b};
unsigned int online_sbx2[1]={0xdef0};
unsigned int online_sbx3[1]={0x576c};
unsigned int online_sbx4[1]={0xa234};
unsigned int online_sbx5[1]={0x1597};
unsigned int online_sbx6[1]={0x7dc4};
unsigned int online_sbx7[1]={0x25ab};


unsigned int online_sby0[1]={0};
unsigned int online_sby1[1]={0};
unsigned int online_sby2[1]={0};
unsigned int online_sby3[1]={0};
unsigned int online_sby4[1]={0};
unsigned int online_sby5[1]={0};
unsigned int online_sby6[1]={0};
unsigned int online_sby7[1]={0};
unsigned int online_sby8[1]={0};
unsigned int online_sby9[1]={0};
unsigned int online_sby10[1]={0};
unsigned int online_sby11[1]={0};
unsigned int online_sby12[1]={0};
unsigned int online_sby13[1]={0};
unsigned int online_sby14[1]={0};
unsigned int online_sby15[1]={0};
unsigned int online_sby16[1]={0};
unsigned int online_sby17[1]={0};
unsigned int online_sby18[1]={0};
unsigned int online_sby19[1]={0};
unsigned int online_sby20[1]={0};
unsigned int online_sby21[1]={0};

unsigned int online_sbt0[1]={0};
unsigned int online_sbt1[1]={0};
unsigned int online_sbt2[1]={0};
unsigned int online_sbt3[1]={0};
unsigned int online_sbt4[1]={0};
unsigned int online_sbt5[1]={0};
unsigned int online_sbt6[1]={0};
unsigned int online_sbt7[1]={0};
unsigned int online_sbt8[1]={0};
unsigned int online_sbt9[1]={0};
unsigned int online_sbt10[1]={0};
unsigned int online_sbt11[1]={0};
unsigned int online_sbt12[1]={0};
unsigned int online_sbt13[1]={0};
unsigned int online_sbt14[1]={0};
unsigned int online_sbt15[1]={0};
unsigned int online_sbt16[1]={0};
unsigned int online_sbt17[1]={0};
unsigned int online_sbt18[1]={0};
unsigned int online_sbt19[1]={0};
unsigned int online_sbt20[1]={0};
unsigned int online_sbt21[1]={0};
unsigned int online_sbt22[1]={0};
unsigned int online_sbt23[1]={0};
unsigned int online_sbt24[1]={0};
unsigned int online_sbt25[1]={0};
unsigned int online_sbt26[1]={0};
unsigned int online_sbt27[1]={0};
unsigned int online_sbt28[1]={0};
unsigned int online_sbt29[1]={0};
unsigned int online_sbt30[1]={0};
unsigned int online_sbt31[1]={0};
unsigned int online_sbt32[1]={0};
unsigned int online_sbt33[1]={0};
unsigned int online_sbt34[1]={0};
unsigned int online_sbt35[1]={0};
unsigned int online_sbt36[1]={0};
unsigned int online_sbt37[1]={0};
unsigned int online_sbt38[1]={0};
unsigned int online_sbt39[1]={0};
unsigned int online_sbt40[1]={0};
unsigned int online_sbt41[1]={0};
unsigned int online_sbt42[1]={0};
unsigned int online_sbt43[1]={0};
unsigned int online_sbt44[1]={0};
unsigned int online_sbt45[1]={0};
unsigned int online_sbt46[1]={0};
unsigned int online_sbt47[1]={0};
unsigned int online_sbt48[1]={0};
unsigned int online_sbt49[1]={0};
unsigned int online_sbt50[1]={0};
unsigned int online_sbt51[1]={0};
unsigned int online_sbt52[1]={0};
unsigned int online_sbt53[1]={0};
unsigned int online_sbt54[1]={0};
unsigned int online_sbt55[1]={0};
unsigned int online_sbt56[1]={0};
unsigned int online_sbt57[1]={0};
unsigned int online_sbt58[1]={0};
unsigned int online_sbt59[1]={0};
unsigned int online_sbt60[1]={0};
unsigned int online_sbt61[1]={0};
unsigned int online_sbt62[1]={0};
unsigned int online_sbt63[1]={0};
unsigned int online_sbt64[1]={0};
unsigned int online_sbt65[1]={0};
unsigned int online_sbt66[1]={0};
unsigned int online_sbt67[1]={0};

unsigned int online_sbs0[1]={0};
unsigned int online_sbs1[1]={0};
unsigned int online_sbs2[1]={0};
unsigned int online_sbs3[1]={0};
unsigned int online_sbs4[1]={0};
unsigned int online_sbs5[1]={0};
unsigned int online_sbs6[1]={0};
unsigned int online_sbs7[1]={0};
unsigned int online_sbs8[1]={0};

unsigned int online_sbz0[1]={0};
unsigned int online_sbz1[1]={0};
unsigned int online_sbz2[1]={0};
unsigned int online_sbz3[1]={0};
unsigned int online_sbz4[1]={0};
unsigned int online_sbz5[1]={0};
unsigned int online_sbz6[1]={0};
unsigned int online_sbz8[1]={0};
unsigned int online_sbz7[1]={0};
unsigned int online_sbz9[1]={0};
unsigned int online_sbz10[1]={0};
unsigned int online_sbz11[1]={0};
unsigned int online_sbz12[1]={0};
unsigned int online_sbz13[1]={0};
unsigned int online_sbz14[1]={0};
unsigned int online_sbz15[1]={0};
unsigned int online_sbz16[1]={0};
unsigned int online_sbz17[1]={0};






unsigned int after_mixcolumn0[ORDER];
unsigned int after_mixcolumn1[ORDER];
unsigned int after_mixcolumn2[ORDER];
unsigned int after_mixcolumn3[ORDER];
unsigned int after_mixcolumn4[ORDER];
unsigned int after_mixcolumn5[ORDER];
unsigned int after_mixcolumn6[ORDER];
unsigned int after_mixcolumn7[ORDER];


unsigned int after_shiftrows0[ORDER];
unsigned int after_shiftrows1[ORDER];
unsigned int after_shiftrows2[ORDER];
unsigned int after_shiftrows3[ORDER];
unsigned int after_shiftrows4[ORDER];
unsigned int after_shiftrows5[ORDER];
unsigned int after_shiftrows6[ORDER];
unsigned int after_shiftrows7[ORDER];


unsigned int online_after_shiftrows0[1];
unsigned int online_after_shiftrows1[1];
unsigned int online_after_shiftrows2[1];
unsigned int online_after_shiftrows3[1];
unsigned int online_after_shiftrows4[1];
unsigned int online_after_shiftrows5[1];
unsigned int online_after_shiftrows6[1];
unsigned int online_after_shiftrows7[1];

unsigned int online_after_mixcolumn0[1];
unsigned int online_after_mixcolumn1[1];
unsigned int online_after_mixcolumn2[1];
unsigned int online_after_mixcolumn3[1];
unsigned int online_after_mixcolumn4[1];
unsigned int online_after_mixcolumn5[1];
unsigned int online_after_mixcolumn6[1];
unsigned int online_after_mixcolumn7[1];

//↓PRESENT部分

unsigned int PRESENT_sbx0[ORDER]={15465};
unsigned int PRESENT_sbx1[ORDER]={1345};
unsigned int PRESENT_sbx2[ORDER]={12484};
unsigned int PRESENT_sbx3[ORDER]={12315};

unsigned int PRESENT_sby0[ORDER]={0};
unsigned int PRESENT_sby1[ORDER]={0};
unsigned int PRESENT_sby2[ORDER]={0};
unsigned int PRESENT_sby3[ORDER]={0};

unsigned int PRESENT_sbt1[ORDER]={0};
unsigned int PRESENT_sbt2[ORDER]={0};
unsigned int PRESENT_sbt3[ORDER]={0};
unsigned int PRESENT_sbt4[ORDER]={0};
unsigned int PRESENT_sbt5[ORDER]={0};
unsigned int PRESENT_sbt6[ORDER]={0};
unsigned int PRESENT_sbt7[ORDER]={0};
unsigned int PRESENT_sbt8[ORDER]={0};
unsigned int PRESENT_sbt9[ORDER]={0};


unsigned int PRESENT_sband1tx1[ORDER];
unsigned int PRESENT_sband1tt1[ORDER];
unsigned int PRESENT_sband1tr[ORDER];
unsigned int PRESENT_sband2tt1[ORDER];
unsigned int PRESENT_sband2tt3[ORDER];
unsigned int PRESENT_sband2tr[ORDER];
unsigned int PRESENT_sband3tx3[ORDER];
unsigned int PRESENT_sband3tt5[ORDER];
unsigned int PRESENT_sband3tr[ORDER];
unsigned int PRESENT_sband4tt7[ORDER];
unsigned int PRESENT_sband4tt6[ORDER];
unsigned int PRESENT_sband4tr[ORDER];

unsigned int PRESENT_online_sbx0[1]={4551};
unsigned int PRESENT_online_sbx1[1]={23878};
unsigned int PRESENT_online_sbx2[1]={1879};
unsigned int PRESENT_online_sbx3[1]={911};

unsigned int PRESENT_online_sby0[1]={0};
unsigned int PRESENT_online_sby1[1]={0};
unsigned int PRESENT_online_sby2[1]={0};
unsigned int PRESENT_online_sby3[1]={0};


unsigned int PRESENT_online_sbt1[1]={0};
unsigned int PRESENT_online_sbt2[1]={0};
unsigned int PRESENT_online_sbt3[1]={0};
unsigned int PRESENT_online_sbt4[1]={0};
unsigned int PRESENT_online_sbt5[1]={0};
unsigned int PRESENT_online_sbt6[1]={0};
unsigned int PRESENT_online_sbt7[1]={0};
unsigned int PRESENT_online_sbt8[1]={0};
unsigned int PRESENT_online_sbt9[1]={0};


unsigned int PRESENT_after_linear0[ORDER];
unsigned int PRESENT_after_linear1[ORDER];
unsigned int PRESENT_after_linear2[ORDER];
unsigned int PRESENT_after_linear3[ORDER];

unsigned int PRESENT_online_after_linear0[1];
unsigned int PRESENT_online_after_linear1[1];
unsigned int PRESENT_online_after_linear2[1];
unsigned int PRESENT_online_after_linear3[1];

//↑PRESENT部分
//↓SKINNY部分
//沿用上面的表述，输出用y表示
//中间变量用m表示

// x0 = 1
// x1 = 1
// x2 = 0
// x3 = 1
// def sboxfunc(x0,x1,x2,x3):
//     m0 = (x0 | x1) ^ 0b1
//     m1 = (x1 | x2) ^ 0b1
//     y0 = m0 ^ x3
//     m2 = (x2 | y0) ^ 0b1
//     y1 = x0 ^ m1
//     m3 =  (y0 | y1) ^ 0b1
//     y2 = x1 ^ m2
//     y3 = x2 ^ m3
//     return y0,y1,y2,y3

unsigned int SKINNY_key0[ORDER]={0};
unsigned int SKINNY_key1[ORDER]={0};
unsigned int SKINNY_key2[ORDER]={0};
unsigned int SKINNY_key3[ORDER]={0};

unsigned int SKINNY_sbx0[ORDER]={36441};
unsigned int SKINNY_sbx1[ORDER]={8945};
unsigned int SKINNY_sbx2[ORDER]={39735};
unsigned int SKINNY_sbx3[ORDER]={315};

unsigned int SKINNY_sby0[ORDER]={0};
unsigned int SKINNY_sby1[ORDER]={0};
unsigned int SKINNY_sby2[ORDER]={0};
unsigned int SKINNY_sby3[ORDER]={0};

unsigned int SKINNY_sbm0[ORDER]={0};
unsigned int SKINNY_sbm1[ORDER]={0};
unsigned int SKINNY_sbm2[ORDER]={0};
unsigned int SKINNY_sbm3[ORDER]={0};

// def sboxfunc(x0,x1,x2,x3):
//     m0 = (x0 | x1) ^ 0xFFFF
//     m1 = (x1 | x2) ^ 0xFFFF
//     y0 = m0 ^ x3
//     m2 = (x2 | y0) ^ 0xFFFF
//     y1 = x0 ^ m1
//     m3 =  (y0 | y1) ^ 0xFFFF
//     y2 = x1 ^ m2
//     y3 = x2 ^ m3
//     return y0,y1,y2,y3
unsigned int SKINNY_sband1tx0[ORDER];
unsigned int SKINNY_sband1tx1[ORDER];
unsigned int SKINNY_sband1tr[ORDER];
unsigned int SKINNY_sband2tx1[ORDER];
unsigned int SKINNY_sband2tx2[ORDER];
unsigned int SKINNY_sband2tr[ORDER];
unsigned int SKINNY_sband3tx2[ORDER];
unsigned int SKINNY_sband3ty0[ORDER];
unsigned int SKINNY_sband3tr[ORDER];
unsigned int SKINNY_sband4ty0[ORDER];
unsigned int SKINNY_sband4ty1[ORDER];
unsigned int SKINNY_sband4tr[ORDER];

unsigned int SKINNY_online_key0[1]={0};
unsigned int SKINNY_online_key1[1]={0};
unsigned int SKINNY_online_key2[1]={0};
unsigned int SKINNY_online_key3[1]={0};

unsigned int SKINNY_online_sbx0[1]={4551};
unsigned int SKINNY_online_sbx1[1]={23878};
unsigned int SKINNY_online_sbx2[1]={1879};
unsigned int SKINNY_online_sbx3[1]={911};

unsigned int SKINNY_online_sbm0[1]={0};
unsigned int SKINNY_online_sbm1[1]={0};
unsigned int SKINNY_online_sbm2[1]={0};
unsigned int SKINNY_online_sbm3[1]={0};


unsigned int SKINNY_online_sby0[1]={0};
unsigned int SKINNY_online_sby1[1]={0};
unsigned int SKINNY_online_sby2[1]={0};
unsigned int SKINNY_online_sby3[1]={0};

unsigned int SKINNY_online_sbt1[1]={0};
unsigned int SKINNY_online_sbt2[1]={0};
unsigned int SKINNY_online_sbt3[1]={0};
unsigned int SKINNY_online_sbt4[1]={0};
unsigned int SKINNY_online_sbt5[1]={0};
unsigned int SKINNY_online_sbt6[1]={0};
unsigned int SKINNY_online_sbt7[1]={0};
unsigned int SKINNY_online_sbt8[1]={0};
unsigned int SKINNY_online_sbt9[1]={0};


unsigned int SKINNY_after_linear0[ORDER];
unsigned int SKINNY_after_linear1[ORDER];
unsigned int SKINNY_after_linear2[ORDER];
unsigned int SKINNY_after_linear3[ORDER];

unsigned int SKINNY_online_after_linear0[1];
unsigned int SKINNY_online_after_linear1[1];
unsigned int SKINNY_online_after_linear2[1];
unsigned int SKINNY_online_after_linear3[1];

//round在论文中是从1开始数的，这里从0开始数

unsigned char SKINNY_ART_constants_array[62] = {0x01,0x03,0x07,0x0F,0x1F,0x3E,0x3D,0x3B,0x37,0x2F,0x1E,0x3C,0x39,0x33,0x27,0x0E,0x1D,0x3A,0x35,0x2B,0x16,0x2C,0x18,0x30,0x21,0x02,0x05,0x0B,0x17,0x2E,0x1C,0x38,0x31,0x23,0x06,0x0D,0x1B,0x36,0x2D,0x1A,0x34,0x29,0x12,0x24,0x08,0x11,0x22,0x04,0x09,0x13,0x26,0x0C,0x19,0x32,0x25,0x0A,0x15,0x2A,0x14,0x28,0x10,0x20};

unsigned int SKINNY_after_shiftrows_sby0[ORDER];
unsigned int SKINNY_after_shiftrows_sby1[ORDER];
unsigned int SKINNY_after_shiftrows_sby2[ORDER];
unsigned int SKINNY_after_shiftrows_sby3[ORDER];
	
	
unsigned int SKINNY_online_after_shiftrows_sby0[1];
unsigned int SKINNY_online_after_shiftrows_sby1[1];
unsigned int SKINNY_online_after_shiftrows_sby2[1];
unsigned int SKINNY_online_after_shiftrows_sby3[1];
	
	
unsigned int SKINNY_after_mixcolumns_sby0[ORDER];
unsigned int SKINNY_after_mixcolumns_sby1[ORDER];
unsigned int SKINNY_after_mixcolumns_sby2[ORDER];
unsigned int SKINNY_after_mixcolumns_sby3[ORDER];
	
	
unsigned int SKINNY_online_after_mixcolumns_sby0[1];
unsigned int SKINNY_online_after_mixcolumns_sby1[1];
unsigned int SKINNY_online_after_mixcolumns_sby2[1];
unsigned int SKINNY_online_after_mixcolumns_sby3[1];
//↑skinny部分



extern unsigned int gadget_x[ORDER];
extern unsigned int gadget_y[ORDER];
extern unsigned int gadget_z[ORDER];
extern unsigned int gadget_x_dot[ORDER];
extern unsigned int gadget_y_dot[ORDER];

extern unsigned int gadget_online_x[1];
extern unsigned int gadget_online_y[1];
extern unsigned int gadget_online_z[1];
extern unsigned int gadget_online_x_dot[1];
extern unsigned int gadget_online_y_dot[1];


extern unsigned int matrixRx[ORDER][ORDER];
extern unsigned int matrixRy[ORDER][ORDER];
extern unsigned int matrixR[ORDER][ORDER];

extern unsigned int alpha[ORDER];
extern unsigned int t_first[1];
extern unsigned int t_second[1];
extern unsigned int r[ORDER];



extern unsigned int test_random_table[1];
extern unsigned int sbx0[ORDER];
extern unsigned int sbx1[ORDER];
extern unsigned int sbx2[ORDER];
extern unsigned int sbx3[ORDER];
extern unsigned int sbx4[ORDER];
extern unsigned int sbx5[ORDER];
extern unsigned int sbx6[ORDER];
extern unsigned int sbx7[ORDER];

extern unsigned int sby0[ORDER];
extern unsigned int sby1[ORDER];
extern unsigned int sby2[ORDER];
extern unsigned int sby3[ORDER];
extern unsigned int sby4[ORDER];
extern unsigned int sby5[ORDER];
extern unsigned int sby6[ORDER];
extern unsigned int sby7[ORDER];
extern unsigned int sby8[ORDER];
extern unsigned int sby9[ORDER];
extern unsigned int sby10[ORDER];
extern unsigned int sby11[ORDER];
extern unsigned int sby12[ORDER];
extern unsigned int sby13[ORDER];
extern unsigned int sby14[ORDER];
extern unsigned int sby15[ORDER];
extern unsigned int sby16[ORDER];
extern unsigned int sby17[ORDER];
extern unsigned int sby18[ORDER];
extern unsigned int sby19[ORDER];
extern unsigned int sby20[ORDER];
extern unsigned int sby21[ORDER];

extern unsigned int sbt0[ORDER];
extern unsigned int sbt1[ORDER];
extern unsigned int sbt2[ORDER];
extern unsigned int sbt3[ORDER];
extern unsigned int sbt4[ORDER];
extern unsigned int sbt5[ORDER];
extern unsigned int sbt6[ORDER];
extern unsigned int sbt7[ORDER];
extern unsigned int sbt8[ORDER];
extern unsigned int sbt9[ORDER];
extern unsigned int sbt10[ORDER];
extern unsigned int sbt11[ORDER];
extern unsigned int sbt12[ORDER];
extern unsigned int sbt13[ORDER];
extern unsigned int sbt14[ORDER];
extern unsigned int sbt15[ORDER];
extern unsigned int sbt16[ORDER];
extern unsigned int sbt17[ORDER];
extern unsigned int sbt18[ORDER];
extern unsigned int sbt19[ORDER];
extern unsigned int sbt20[ORDER];
extern unsigned int sbt21[ORDER];
extern unsigned int sbt22[ORDER];
extern unsigned int sbt23[ORDER];
extern unsigned int sbt24[ORDER];
extern unsigned int sbt25[ORDER];
extern unsigned int sbt26[ORDER];
extern unsigned int sbt27[ORDER];
extern unsigned int sbt28[ORDER];
extern unsigned int sbt29[ORDER];
extern unsigned int sbt30[ORDER];
extern unsigned int sbt31[ORDER];
extern unsigned int sbt32[ORDER];
extern unsigned int sbt33[ORDER];
extern unsigned int sbt34[ORDER];
extern unsigned int sbt35[ORDER];
extern unsigned int sbt36[ORDER];
extern unsigned int sbt37[ORDER];
extern unsigned int sbt38[ORDER];
extern unsigned int sbt39[ORDER];
extern unsigned int sbt40[ORDER];
extern unsigned int sbt41[ORDER];
extern unsigned int sbt42[ORDER];
extern unsigned int sbt43[ORDER];
extern unsigned int sbt44[ORDER];
extern unsigned int sbt45[ORDER];
extern unsigned int sbt46[ORDER];
extern unsigned int sbt47[ORDER];
extern unsigned int sbt48[ORDER];
extern unsigned int sbt49[ORDER];
extern unsigned int sbt50[ORDER];
extern unsigned int sbt51[ORDER];
extern unsigned int sbt52[ORDER];
extern unsigned int sbt53[ORDER];
extern unsigned int sbt54[ORDER];
extern unsigned int sbt55[ORDER];
extern unsigned int sbt56[ORDER];
extern unsigned int sbt57[ORDER];
extern unsigned int sbt58[ORDER];
extern unsigned int sbt59[ORDER];
extern unsigned int sbt60[ORDER];
extern unsigned int sbt61[ORDER];
extern unsigned int sbt62[ORDER];
extern unsigned int sbt63[ORDER];
extern unsigned int sbt64[ORDER];
extern unsigned int sbt65[ORDER];
extern unsigned int sbt66[ORDER];
extern unsigned int sbt67[ORDER];

extern unsigned int sbs0[ORDER];
extern unsigned int sbs1[ORDER];
extern unsigned int sbs2[ORDER];
extern unsigned int sbs3[ORDER];
extern unsigned int sbs4[ORDER];
extern unsigned int sbs5[ORDER];
extern unsigned int sbs6[ORDER];
extern unsigned int sbs7[ORDER];
extern unsigned int sbs8[ORDER];

extern unsigned int sbz0[ORDER];
extern unsigned int sbz1[ORDER];
extern unsigned int sbz2[ORDER];
extern unsigned int sbz3[ORDER];
extern unsigned int sbz4[ORDER];
extern unsigned int sbz5[ORDER];
extern unsigned int sbz6[ORDER];
extern unsigned int sbz7[ORDER];
extern unsigned int sbz8[ORDER];
extern unsigned int sbz9[ORDER];
extern unsigned int sbz10[ORDER];
extern unsigned int sbz11[ORDER];
extern unsigned int sbz12[ORDER];
extern unsigned int sbz13[ORDER];
extern unsigned int sbz14[ORDER];
extern unsigned int sbz15[ORDER];
extern unsigned int sbz16[ORDER];
extern unsigned int sbz17[ORDER];

extern unsigned int sband1ty12[ORDER];
extern unsigned int sband1ty15[ORDER];
extern unsigned int sband1tr[ORDER];
extern unsigned int sband2ty3[ORDER];
extern unsigned int sband2ty6[ORDER];
extern unsigned int sband2tr[ORDER];
extern unsigned int sband3ty4[ORDER];
extern unsigned int sband3tx7[ORDER];
extern unsigned int sband3tr[ORDER];
extern unsigned int sband4ty13[ORDER];
extern unsigned int sband4ty16[ORDER];
extern unsigned int sband4tr[ORDER];
extern unsigned int sband5ty5[ORDER];
extern unsigned int sband5ty1[ORDER];
extern unsigned int sband5tr[ORDER];
extern unsigned int sband6ty2[ORDER];
extern unsigned int sband6ty7[ORDER];
extern unsigned int sband6tr[ORDER];
extern unsigned int sband7ty9[ORDER];
extern unsigned int sband7ty11[ORDER];
extern unsigned int sband7tr[ORDER];
extern unsigned int sband8ty14[ORDER];
extern unsigned int sband8ty17[ORDER];
extern unsigned int sband8tr[ORDER];
extern unsigned int sband9ty8[ORDER];
extern unsigned int sband9ty10[ORDER];
extern unsigned int sband9tr[ORDER];
extern unsigned int sband10tt21[ORDER];
extern unsigned int sband10tt23[ORDER];
extern unsigned int sband10tr[ORDER];
extern unsigned int sband11tt25[ORDER];
extern unsigned int sband11tt27[ORDER];
extern unsigned int sband11tr[ORDER];
extern unsigned int sband12tt31[ORDER];
extern unsigned int sband12tt30[ORDER];
extern unsigned int sband12tr[ORDER];
extern unsigned int sband13tt29[ORDER];
extern unsigned int sband13ty2[ORDER];
extern unsigned int sband13tr[ORDER];
extern unsigned int sband14tt24[ORDER];
extern unsigned int sband14tt35[ORDER];
extern unsigned int sband14tr[ORDER];
extern unsigned int sband15tt29[ORDER];
extern unsigned int sband15tt38[ORDER];
extern unsigned int sband15tr[ORDER];
extern unsigned int sband16tt29[ORDER];
extern unsigned int sband16ty7[ORDER];
extern unsigned int sband16tr[ORDER];
extern unsigned int sband17tt44[ORDER];
extern unsigned int sband17ty15[ORDER];
extern unsigned int sband17tr[ORDER];
extern unsigned int sband18tt37[ORDER];
extern unsigned int sband18ty6[ORDER];
extern unsigned int sband18tr[ORDER];
extern unsigned int sband19tt33[ORDER];
extern unsigned int sband19tx7[ORDER];
extern unsigned int sband19tr[ORDER];
extern unsigned int sband20tt43[ORDER];
extern unsigned int sband20ty16[ORDER];
extern unsigned int sband20tr[ORDER];
extern unsigned int sband21tt40[ORDER];
extern unsigned int sband21ty1[ORDER];
extern unsigned int sband21tr[ORDER];
extern unsigned int sband22tt42[ORDER];
extern unsigned int sband22ty11[ORDER];
extern unsigned int sband22tr[ORDER];
extern unsigned int sband23tt45[ORDER];
extern unsigned int sband23ty17[ORDER];
extern unsigned int sband23tr[ORDER];
extern unsigned int sband24tt41[ORDER];
extern unsigned int sband24ty10[ORDER];
extern unsigned int sband24tr[ORDER];
extern unsigned int sband25tt44[ORDER];
extern unsigned int sband25ty12[ORDER];
extern unsigned int sband25tr[ORDER];
extern unsigned int sband26tt37[ORDER];
extern unsigned int sband26ty3[ORDER];
extern unsigned int sband26tr[ORDER];
extern unsigned int sband27tt33[ORDER];
extern unsigned int sband27ty4[ORDER];
extern unsigned int sband27tr[ORDER];
extern unsigned int sband28tt43[ORDER];
extern unsigned int sband28ty13[ORDER];
extern unsigned int sband28tr[ORDER];
extern unsigned int sband29tt40[ORDER];
extern unsigned int sband29ty5[ORDER];
extern unsigned int sband29tr[ORDER];
extern unsigned int sband30tt42[ORDER];
extern unsigned int sband30ty9[ORDER];
extern unsigned int sband30tr[ORDER];
extern unsigned int sband31tt45[ORDER];
extern unsigned int sband31ty14[ORDER];
extern unsigned int sband31tr[ORDER];
extern unsigned int sband32tt41[ORDER];
extern unsigned int sband32ty8[ORDER];
extern unsigned int sband32tr[ORDER];


extern unsigned int online_sbx0[1];
extern unsigned int online_sbx1[1];
extern unsigned int online_sbx2[1];
extern unsigned int online_sbx3[1];
extern unsigned int online_sbx4[1];
extern unsigned int online_sbx5[1];
extern unsigned int online_sbx7[1];
extern unsigned int online_sbx6[1];

 
extern unsigned int online_sby0[1];
extern unsigned int online_sby1[1];
extern unsigned int online_sby2[1];
extern unsigned int online_sby3[1];
extern unsigned int online_sby4[1];
extern unsigned int online_sby5[1];
extern unsigned int online_sby6[1];
extern unsigned int online_sby7[1];
extern unsigned int online_sby8[1];
extern unsigned int online_sby9[1];
extern unsigned int online_sby10[1];
extern unsigned int online_sby11[1];
extern unsigned int online_sby12[1];
extern unsigned int online_sby13[1];
extern unsigned int online_sby14[1];
extern unsigned int online_sby15[1];
extern unsigned int online_sby16[1];
extern unsigned int online_sby17[1];
extern unsigned int online_sby18[1];
extern unsigned int online_sby19[1];
extern unsigned int online_sby20[1];
extern unsigned int online_sby21[1];
 
extern unsigned int online_sbt0[1];
extern unsigned int online_sbt1[1];
extern unsigned int online_sbt2[1];
extern unsigned int online_sbt3[1];
extern unsigned int online_sbt4[1];
extern unsigned int online_sbt5[1];
extern unsigned int online_sbt6[1];
extern unsigned int online_sbt7[1];
extern unsigned int online_sbt8[1];
extern unsigned int online_sbt9[1];
extern unsigned int online_sbt10[1];
extern unsigned int online_sbt11[1];
extern unsigned int online_sbt12[1];
extern unsigned int online_sbt13[1];
extern unsigned int online_sbt14[1];
extern unsigned int online_sbt15[1];
extern unsigned int online_sbt16[1];
extern unsigned int online_sbt17[1];
extern unsigned int online_sbt18[1];
extern unsigned int online_sbt19[1];
extern unsigned int online_sbt20[1];
extern unsigned int online_sbt21[1];
extern unsigned int online_sbt22[1];
extern unsigned int online_sbt23[1];
extern unsigned int online_sbt24[1];
extern unsigned int online_sbt25[1];
extern unsigned int online_sbt26[1];
extern unsigned int online_sbt27[1];
extern unsigned int online_sbt28[1];
extern unsigned int online_sbt29[1];
extern unsigned int online_sbt30[1];
extern unsigned int online_sbt31[1];
extern unsigned int online_sbt32[1];
extern unsigned int online_sbt33[1];
extern unsigned int online_sbt34[1];
extern unsigned int online_sbt35[1];
extern unsigned int online_sbt36[1];
extern unsigned int online_sbt37[1];
extern unsigned int online_sbt38[1];
extern unsigned int online_sbt39[1];
extern unsigned int online_sbt40[1];
extern unsigned int online_sbt41[1];
extern unsigned int online_sbt42[1];
extern unsigned int online_sbt43[1];
extern unsigned int online_sbt44[1];
extern unsigned int online_sbt45[1];
extern unsigned int online_sbt46[1];
extern unsigned int online_sbt47[1];
extern unsigned int online_sbt48[1];
extern unsigned int online_sbt49[1];
extern unsigned int online_sbt50[1];
extern unsigned int online_sbt51[1];
extern unsigned int online_sbt52[1];
extern unsigned int online_sbt53[1];
extern unsigned int online_sbt54[1];
extern unsigned int online_sbt55[1];
extern unsigned int online_sbt56[1];
extern unsigned int online_sbt57[1];
extern unsigned int online_sbt58[1];
extern unsigned int online_sbt59[1];
extern unsigned int online_sbt60[1];
extern unsigned int online_sbt61[1];
extern unsigned int online_sbt62[1];
extern unsigned int online_sbt63[1];
extern unsigned int online_sbt64[1];
extern unsigned int online_sbt65[1];
extern unsigned int online_sbt66[1];
extern unsigned int online_sbt67[1];

extern unsigned int online_sbs0[1];;
extern unsigned int online_sbs1[1];;
extern unsigned int online_sbs2[1];
extern unsigned int online_sbs3[1];
extern unsigned int online_sbs4[1];
extern unsigned int online_sbs5[1];
extern unsigned int online_sbs6[1];
extern unsigned int online_sbs7[1];

extern unsigned int online_sbz0[1];
extern unsigned int online_sbz1[1];
extern unsigned int online_sbz2[1];
extern unsigned int online_sbz3[1];
extern unsigned int online_sbz4[1];
extern unsigned int online_sbz5[1];
extern unsigned int online_sbz6[1];
extern unsigned int online_sbz8[1];
extern unsigned int online_sbz7[1];
extern unsigned int online_sbz9[1];
extern unsigned int online_sbz10[1];
extern unsigned int online_sbz11[1];
extern unsigned int online_sbz12[1];
extern unsigned int online_sbz13[1];
extern unsigned int online_sbz14[1];
extern unsigned int online_sbz15[1];
extern unsigned int online_sbz16[1];
extern unsigned int online_sbz17[1];



extern unsigned int after_mixcolumn0[ORDER];
extern unsigned int after_mixcolumn1[ORDER];
extern unsigned int after_mixcolumn2[ORDER];
extern unsigned int after_mixcolumn3[ORDER];
extern unsigned int after_mixcolumn4[ORDER];
extern unsigned int after_mixcolumn5[ORDER];
extern unsigned int after_mixcolumn6[ORDER];
extern unsigned int after_mixcolumn7[ORDER];

extern unsigned int after_shiftrows0[ORDER];
extern unsigned int after_shiftrows1[ORDER];
extern unsigned int after_shiftrows2[ORDER];
extern unsigned int after_shiftrows3[ORDER];
extern unsigned int after_shiftrows4[ORDER];
extern unsigned int after_shiftrows5[ORDER];
extern unsigned int after_shiftrows6[ORDER];
extern unsigned int after_shiftrows7[ORDER];

extern unsigned int online_after_mixcolumn0[1];
extern unsigned int online_after_mixcolumn1[1];
extern unsigned int online_after_mixcolumn2[1];
extern unsigned int online_after_mixcolumn3[1];
extern unsigned int online_after_mixcolumn4[1];
extern unsigned int online_after_mixcolumn5[1];
extern unsigned int online_after_mixcolumn6[1];
extern unsigned int online_after_mixcolumn7[1];

extern unsigned int online_after_shiftrows0[1];
extern unsigned int online_after_shiftrows1[1];
extern unsigned int online_after_shiftrows2[1];
extern unsigned int online_after_shiftrows3[1];
extern unsigned int online_after_shiftrows4[1];
extern unsigned int online_after_shiftrows5[1];
extern unsigned int online_after_shiftrows6[1];
extern unsigned int online_after_shiftrows7[1];







extern unsigned int PRESENT_sbx0[ORDER];
extern unsigned int PRESENT_sbx1[ORDER];
extern unsigned int PRESENT_sbx2[ORDER];
extern unsigned int PRESENT_sbx3[ORDER];

extern unsigned int PRESENT_sby0[ORDER];
extern unsigned int PRESENT_sby1[ORDER];
extern unsigned int PRESENT_sby2[ORDER];
extern unsigned int PRESENT_sby3[ORDER];

extern unsigned int PRESENT_sbt1[ORDER];
extern unsigned int PRESENT_sbt2[ORDER];
extern unsigned int PRESENT_sbt3[ORDER];
extern unsigned int PRESENT_sbt4[ORDER];
extern unsigned int PRESENT_sbt5[ORDER];
extern unsigned int PRESENT_sbt6[ORDER];
extern unsigned int PRESENT_sbt7[ORDER];
extern unsigned int PRESENT_sbt8[ORDER];
extern unsigned int PRESENT_sbt9[ORDER];


extern unsigned int PRESENT_sband1tx1[ORDER];
extern unsigned int PRESENT_sband1tt1[ORDER];
extern unsigned int PRESENT_sband1tr[ORDER];
extern unsigned int PRESENT_sband2tt1[ORDER];
extern unsigned int PRESENT_sband2tt3[ORDER];
extern unsigned int PRESENT_sband2tr[ORDER];
extern unsigned int PRESENT_sband3tx3[ORDER];
extern unsigned int PRESENT_sband3tt5[ORDER];
extern unsigned int PRESENT_sband3tr[ORDER];
extern unsigned int PRESENT_sband4tt7[ORDER];
extern unsigned int PRESENT_sband4tt6[ORDER];
extern unsigned int PRESENT_sband4tr[ORDER];

extern unsigned int PRESENT_online_sbx0[1];
extern unsigned int PRESENT_online_sbx1[1];
extern unsigned int PRESENT_online_sbx2[1];
extern unsigned int PRESENT_online_sbx3[1];

extern unsigned int PRESENT_online_sby0[1];
extern unsigned int PRESENT_online_sby1[1];
extern unsigned int PRESENT_online_sby2[1];
extern unsigned int PRESENT_online_sby3[1];


extern unsigned int PRESENT_online_sbt1[1];
extern unsigned int PRESENT_online_sbt2[1];
extern unsigned int PRESENT_online_sbt3[1];
extern unsigned int PRESENT_online_sbt4[1];
extern unsigned int PRESENT_online_sbt5[1];
extern unsigned int PRESENT_online_sbt6[1];
extern unsigned int PRESENT_online_sbt7[1];
extern unsigned int PRESENT_online_sbt8[1];
extern unsigned int PRESENT_online_sbt9[1];


extern unsigned int PRESENT_after_linear0[ORDER];
extern unsigned int PRESENT_after_linear1[ORDER];
extern unsigned int PRESENT_after_linear2[ORDER];
extern unsigned int PRESENT_after_linear3[ORDER];

extern unsigned int PRESENT_online_after_linear0[1];
extern unsigned int PRESENT_online_after_linear1[1];
extern unsigned int PRESENT_online_after_linear2[1];
extern unsigned int PRESENT_online_after_linear3[1];

