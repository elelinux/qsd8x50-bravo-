/* drivers/video/msm/mdp_csc_table.h
 *
 * Copyright (C) 2007 QUALCOMM Incorporated
 * Copyright (C) 2007 Google Incorporated
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

static struct {
	uint32_t reg;
	uint32_t val;
} csc_matrix_config_table[] = {
	/* RGB -> YUV primary forward matrix (set1). */
	{ MDP_CSC_PFMVn(0), 0x83 },
	{ MDP_CSC_PFMVn(1), 0x102 },
	{ MDP_CSC_PFMVn(2), 0x32 },
	{ MDP_CSC_PFMVn(3), 0xffffffb5 },
	{ MDP_CSC_PFMVn(4), 0xffffff6c },
	{ MDP_CSC_PFMVn(5), 0xe1 },
	{ MDP_CSC_PFMVn(6), 0xe1 },
	{ MDP_CSC_PFMVn(7), 0xffffff45 },
	{ MDP_CSC_PFMVn(8), 0xffffffdc },

	/* YUV -> RGB primary reverse matrix (set2) */
	{ MDP_CSC_PRMVn(0), 0x254 },
	{ MDP_CSC_PRMVn(1), 0x0 },
	{ MDP_CSC_PRMVn(2), 0x331 },
	{ MDP_CSC_PRMVn(3), 0x254 },
	{ MDP_CSC_PRMVn(4), 0xffffff38 },
	{ MDP_CSC_PRMVn(5), 0xfffffe61 },
	{ MDP_CSC_PRMVn(6), 0x254 },
	{ MDP_CSC_PRMVn(7), 0x409 },
	{ MDP_CSC_PRMVn(8), 0x0 },

/*#ifndef CONFIG_FB_MSM_MDP31
	 For MDP 2.2/3.0 

	 primary limit vector 
	{ MDP_CSC_PLVn(0), 0x10 },
	{ MDP_CSC_PLVn(1), 0xeb },
	{ MDP_CSC_PLVn(2), 0x10 },
	{ MDP_CSC_PLVn(3), 0xf0 },

	 primary bias vector 
	{ MDP_CSC_PBVn(0), 0x10 },
	{ MDP_CSC_PBVn(1), 0x80 },
	{ MDP_CSC_PBVn(2), 0x80 },

#else  CONFIG_MSM_MDP31 */

	/* limit vectors configuration */
	/* rgb -> yuv (set1) pre-limit vector */
	{ MDP_PPP_CSC_PRE_LV1n(0), 0x10 },
	{ MDP_PPP_CSC_PRE_LV1n(1), 0xeb },
	{ MDP_PPP_CSC_PRE_LV1n(2), 0x10 },
	{ MDP_PPP_CSC_PRE_LV1n(3), 0xf0 },
	{ MDP_PPP_CSC_PRE_LV1n(4), 0x10 },
	{ MDP_PPP_CSC_PRE_LV1n(5), 0xf0 },

	/* rgb -> yuv (set1) post-limit vector */
	{ MDP_PPP_CSC_POST_LV1n(0), 0x0 },
	{ MDP_PPP_CSC_POST_LV1n(1), 0xff },
	{ MDP_PPP_CSC_POST_LV1n(2), 0x0 },
	{ MDP_PPP_CSC_POST_LV1n(3), 0xff },
	{ MDP_PPP_CSC_POST_LV1n(4), 0x0 },
	{ MDP_PPP_CSC_POST_LV1n(5), 0xff },

	/* yuv -> rgb (set2) pre-limit vector */
	{ MDP_PPP_CSC_PRE_LV2n(0), 0x0 },
	{ MDP_PPP_CSC_PRE_LV2n(1), 0xff },
	{ MDP_PPP_CSC_PRE_LV2n(2), 0x0 },
	{ MDP_PPP_CSC_PRE_LV2n(3), 0xff },
	{ MDP_PPP_CSC_PRE_LV2n(4), 0x0 },
	{ MDP_PPP_CSC_PRE_LV2n(5), 0xff },

	/* yuv -> rgb (set2) post-limit vector */
	{ MDP_PPP_CSC_POST_LV2n(0), 0x10 },
	{ MDP_PPP_CSC_POST_LV2n(1), 0xeb },
	{ MDP_PPP_CSC_POST_LV2n(2), 0x10 },
	{ MDP_PPP_CSC_POST_LV2n(3), 0xf0 },
	{ MDP_PPP_CSC_POST_LV2n(4), 0x10 },
	{ MDP_PPP_CSC_POST_LV2n(5), 0xf0 },

	/* bias vectors configuration */

	/* XXX: why is set2 used for rgb->yuv, but set1 */
	/* used for yuv -> rgb??!? Seems to be the reverse of the
	 * other vectors. */

	/* RGB -> YUV pre-bias vector... */
	{ MDP_PPP_CSC_PRE_BV2n(0), 0 },
	{ MDP_PPP_CSC_PRE_BV2n(1), 0 },
	{ MDP_PPP_CSC_PRE_BV2n(2), 0 },

	/* RGB -> YUV post-bias vector */
	{ MDP_PPP_CSC_POST_BV2n(0), 0x10 },
	{ MDP_PPP_CSC_POST_BV2n(1), 0x80 },
	{ MDP_PPP_CSC_POST_BV2n(2), 0x80 },

	/* YUV -> RGB pre-bias vector... */
	{ MDP_PPP_CSC_PRE_BV1n(0), 0x1f0 },
	{ MDP_PPP_CSC_PRE_BV1n(1), 0x180 },
	{ MDP_PPP_CSC_PRE_BV1n(2), 0x180 },

	/* YUV -> RGB post-bias vector */
	{ MDP_PPP_CSC_POST_BV1n(0), 0 },
	{ MDP_PPP_CSC_POST_BV1n(1), 0 },
	{ MDP_PPP_CSC_POST_BV1n(2), 0 },

	/* luma filter coefficients */
	{ MDP_PPP_DEINT_COEFFn(0), 0x3e0 },
	{ MDP_PPP_DEINT_COEFFn(1), 0x360 },
	{ MDP_PPP_DEINT_COEFFn(2), 0x120 },
	{ MDP_PPP_DEINT_COEFFn(3), 0x140 },
//#endif
};

static struct {
	uint32_t reg;
	uint32_t val;
} csc_color_lut[] = {
	{ 0x40800, 0x0 },
	{ 0x40804, 0x151515 },
	{ 0x40808, 0x1d1d1d },
	{ 0x4080c, 0x232323 },
	{ 0x40810, 0x272727 },
	{ 0x40814, 0x2b2b2b },
	{ 0x40818, 0x2f2f2f },
	{ 0x4081c, 0x333333 },
	{ 0x40820, 0x363636 },
	{ 0x40824, 0x393939 },
	{ 0x40828, 0x3b3b3b },
	{ 0x4082c, 0x3e3e3e },
	{ 0x40830, 0x404040 },
	{ 0x40834, 0x434343 },
	{ 0x40838, 0x454545 },
	{ 0x4083c, 0x474747 },
	{ 0x40840, 0x494949 },
	{ 0x40844, 0x4b4b4b },
	{ 0x40848, 0x4d4d4d },
	{ 0x4084c, 0x4f4f4f },
	{ 0x40850, 0x515151 },
	{ 0x40854, 0x535353 },
	{ 0x40858, 0x555555 },
	{ 0x4085c, 0x565656 },
	{ 0x40860, 0x585858 },
	{ 0x40864, 0x5a5a5a },
	{ 0x40868, 0x5b5b5b },
	{ 0x4086c, 0x5d5d5d },
	{ 0x40870, 0x5e5e5e },
	{ 0x40874, 0x606060 },
	{ 0x40878, 0x616161 },
	{ 0x4087c, 0x636363 },
	{ 0x40880, 0x646464 },
	{ 0x40884, 0x666666 },
	{ 0x40888, 0x676767 },
	{ 0x4088c, 0x686868 },
	{ 0x40890, 0x6a6a6a },
	{ 0x40894, 0x6b6b6b },
	{ 0x40898, 0x6c6c6c },
	{ 0x4089c, 0x6e6e6e },
	{ 0x408a0, 0x6f6f6f },
	{ 0x408a4, 0x707070 },
	{ 0x408a8, 0x717171 },
	{ 0x408ac, 0x727272 },
	{ 0x408b0, 0x747474 },
	{ 0x408b4, 0x757575 },
	{ 0x408b8, 0x767676 },
	{ 0x408bc, 0x777777 },
	{ 0x408c0, 0x787878 },
	{ 0x408c4, 0x797979 },
	{ 0x408c8, 0x7a7a7a },
	{ 0x408cc, 0x7c7c7c },
	{ 0x408d0, 0x7d7d7d },
	{ 0x408d4, 0x7e7e7e },
	{ 0x408d8, 0x7f7f7f },
	{ 0x408dc, 0x808080 },
	{ 0x408e0, 0x818181 },
	{ 0x408e4, 0x828282 },
	{ 0x408e8, 0x838383 },
	{ 0x408ec, 0x848484 },
	{ 0x408f0, 0x858585 },
	{ 0x408f4, 0x868686 },
	{ 0x408f8, 0x878787 },
	{ 0x408fc, 0x888888 },
	{ 0x40900, 0x898989 },
	{ 0x40904, 0x8a8a8a },
	{ 0x40908, 0x8b8b8b },
	{ 0x4090c, 0x8c8c8c },
	{ 0x40910, 0x8d8d8d },
	{ 0x40914, 0x8e8e8e },
	{ 0x40918, 0x8f8f8f },
	{ 0x4091c, 0x8f8f8f },
	{ 0x40920, 0x909090 },
	{ 0x40924, 0x919191 },
	{ 0x40928, 0x929292 },
	{ 0x4092c, 0x939393 },
	{ 0x40930, 0x949494 },
	{ 0x40934, 0x959595 },
	{ 0x40938, 0x969696 },
	{ 0x4093c, 0x969696 },
	{ 0x40940, 0x979797 },
	{ 0x40944, 0x989898 },
	{ 0x40948, 0x999999 },
	{ 0x4094c, 0x9a9a9a },
	{ 0x40950, 0x9b9b9b },
	{ 0x40954, 0x9c9c9c },
	{ 0x40958, 0x9c9c9c },
	{ 0x4095c, 0x9d9d9d },
	{ 0x40960, 0x9e9e9e },
	{ 0x40964, 0x9f9f9f },
	{ 0x40968, 0xa0a0a0 },
	{ 0x4096c, 0xa0a0a0 },
	{ 0x40970, 0xa1a1a1 },
	{ 0x40974, 0xa2a2a2 },
	{ 0x40978, 0xa3a3a3 },
	{ 0x4097c, 0xa4a4a4 },
	{ 0x40980, 0xa4a4a4 },
	{ 0x40984, 0xa5a5a5 },
	{ 0x40988, 0xa6a6a6 },
	{ 0x4098c, 0xa7a7a7 },
	{ 0x40990, 0xa7a7a7 },
	{ 0x40994, 0xa8a8a8 },
	{ 0x40998, 0xa9a9a9 },
	{ 0x4099c, 0xaaaaaa },
	{ 0x409a0, 0xaaaaaa },
	{ 0x409a4, 0xababab },
	{ 0x409a8, 0xacacac },
	{ 0x409ac, 0xadadad },
	{ 0x409b0, 0xadadad },
	{ 0x409b4, 0xaeaeae },
	{ 0x409b8, 0xafafaf },
	{ 0x409bc, 0xafafaf },
	{ 0x409c0, 0xb0b0b0 },
	{ 0x409c4, 0xb1b1b1 },
	{ 0x409c8, 0xb2b2b2 },
	{ 0x409cc, 0xb2b2b2 },
	{ 0x409d0, 0xb3b3b3 },
	{ 0x409d4, 0xb4b4b4 },
	{ 0x409d8, 0xb4b4b4 },
	{ 0x409dc, 0xb5b5b5 },
	{ 0x409e0, 0xb6b6b6 },
	{ 0x409e4, 0xb6b6b6 },
	{ 0x409e8, 0xb7b7b7 },
	{ 0x409ec, 0xb8b8b8 },
	{ 0x409f0, 0xb8b8b8 },
	{ 0x409f4, 0xb9b9b9 },
	{ 0x409f8, 0xbababa },
	{ 0x409fc, 0xbababa },
	{ 0x40a00, 0xbbbbbb },
	{ 0x40a04, 0xbcbcbc },
	{ 0x40a08, 0xbcbcbc },
	{ 0x40a0c, 0xbdbdbd },
	{ 0x40a10, 0xbebebe },
	{ 0x40a14, 0xbebebe },
	{ 0x40a18, 0xbfbfbf },
	{ 0x40a1c, 0xc0c0c0 },
	{ 0x40a20, 0xc0c0c0 },
	{ 0x40a24, 0xc1c1c1 },
	{ 0x40a28, 0xc1c1c1 },
	{ 0x40a2c, 0xc2c2c2 },
	{ 0x40a30, 0xc3c3c3 },
	{ 0x40a34, 0xc3c3c3 },
	{ 0x40a38, 0xc4c4c4 },
	{ 0x40a3c, 0xc5c5c5 },
	{ 0x40a40, 0xc5c5c5 },
	{ 0x40a44, 0xc6c6c6 },
	{ 0x40a48, 0xc6c6c6 },
	{ 0x40a4c, 0xc7c7c7 },
	{ 0x40a50, 0xc8c8c8 },
	{ 0x40a54, 0xc8c8c8 },
	{ 0x40a58, 0xc9c9c9 },
	{ 0x40a5c, 0xc9c9c9 },
	{ 0x40a60, 0xcacaca },
	{ 0x40a64, 0xcbcbcb },
	{ 0x40a68, 0xcbcbcb },
	{ 0x40a6c, 0xcccccc },
	{ 0x40a70, 0xcccccc },
	{ 0x40a74, 0xcdcdcd },
	{ 0x40a78, 0xcecece },
	{ 0x40a7c, 0xcecece },
	{ 0x40a80, 0xcfcfcf },
	{ 0x40a84, 0xcfcfcf },
	{ 0x40a88, 0xd0d0d0 },
	{ 0x40a8c, 0xd0d0d0 },
	{ 0x40a90, 0xd1d1d1 },
	{ 0x40a94, 0xd2d2d2 },
	{ 0x40a98, 0xd2d2d2 },
	{ 0x40a9c, 0xd3d3d3 },
	{ 0x40aa0, 0xd3d3d3 },
	{ 0x40aa4, 0xd4d4d4 },
	{ 0x40aa8, 0xd4d4d4 },
	{ 0x40aac, 0xd5d5d5 },
	{ 0x40ab0, 0xd6d6d6 },
	{ 0x40ab4, 0xd6d6d6 },
	{ 0x40ab8, 0xd7d7d7 },
	{ 0x40abc, 0xd7d7d7 },
	{ 0x40ac0, 0xd8d8d8 },
	{ 0x40ac4, 0xd8d8d8 },
	{ 0x40ac8, 0xd9d9d9 },
	{ 0x40acc, 0xd9d9d9 },
	{ 0x40ad0, 0xdadada },
	{ 0x40ad4, 0xdbdbdb },
	{ 0x40ad8, 0xdbdbdb },
	{ 0x40adc, 0xdcdcdc },
	{ 0x40ae0, 0xdcdcdc },
	{ 0x40ae4, 0xdddddd },
	{ 0x40ae8, 0xdddddd },
	{ 0x40aec, 0xdedede },
	{ 0x40af0, 0xdedede },
	{ 0x40af4, 0xdfdfdf },
	{ 0x40af8, 0xdfdfdf },
	{ 0x40afc, 0xe0e0e0 },
	{ 0x40b00, 0xe0e0e0 },
	{ 0x40b04, 0xe1e1e1 },
	{ 0x40b08, 0xe1e1e1 },
	{ 0x40b0c, 0xe2e2e2 },
	{ 0x40b10, 0xe3e3e3 },
	{ 0x40b14, 0xe3e3e3 },
	{ 0x40b18, 0xe4e4e4 },
	{ 0x40b1c, 0xe4e4e4 },
	{ 0x40b20, 0xe5e5e5 },
	{ 0x40b24, 0xe5e5e5 },
	{ 0x40b28, 0xe6e6e6 },
	{ 0x40b2c, 0xe6e6e6 },
	{ 0x40b30, 0xe7e7e7 },
	{ 0x40b34, 0xe7e7e7 },
	{ 0x40b38, 0xe8e8e8 },
	{ 0x40b3c, 0xe8e8e8 },
	{ 0x40b40, 0xe9e9e9 },
	{ 0x40b44, 0xe9e9e9 },
	{ 0x40b48, 0xeaeaea },
	{ 0x40b4c, 0xeaeaea },
	{ 0x40b50, 0xebebeb },
	{ 0x40b54, 0xebebeb },
	{ 0x40b58, 0xececec },
	{ 0x40b5c, 0xececec },
	{ 0x40b60, 0xededed },
	{ 0x40b64, 0xededed },
	{ 0x40b68, 0xeeeeee },
	{ 0x40b6c, 0xeeeeee },
	{ 0x40b70, 0xefefef },
	{ 0x40b74, 0xefefef },
	{ 0x40b78, 0xf0f0f0 },
	{ 0x40b7c, 0xf0f0f0 },
	{ 0x40b80, 0xf1f1f1 },
	{ 0x40b84, 0xf1f1f1 },
	{ 0x40b88, 0xf2f2f2 },
	{ 0x40b8c, 0xf2f2f2 },
	{ 0x40b90, 0xf2f2f2 },
	{ 0x40b94, 0xf3f3f3 },
	{ 0x40b98, 0xf3f3f3 },
	{ 0x40b9c, 0xf4f4f4 },
	{ 0x40ba0, 0xf4f4f4 },
	{ 0x40ba4, 0xf5f5f5 },
	{ 0x40ba8, 0xf5f5f5 },
	{ 0x40bac, 0xf6f6f6 },
	{ 0x40bb0, 0xf6f6f6 },
	{ 0x40bb4, 0xf7f7f7 },
	{ 0x40bb8, 0xf7f7f7 },
	{ 0x40bbc, 0xf8f8f8 },
	{ 0x40bc0, 0xf8f8f8 },
	{ 0x40bc4, 0xf9f9f9 },
	{ 0x40bc8, 0xf9f9f9 },
	{ 0x40bcc, 0xfafafa },
	{ 0x40bd0, 0xfafafa },
	{ 0x40bd4, 0xfafafa },
	{ 0x40bd8, 0xfbfbfb },
	{ 0x40bdc, 0xfbfbfb },
	{ 0x40be0, 0xfcfcfc },
	{ 0x40be4, 0xfcfcfc },
	{ 0x40be8, 0xfdfdfd },
	{ 0x40bec, 0xfdfdfd },
	{ 0x40bf0, 0xfefefe },
	{ 0x40bf4, 0xfefefe },
	{ 0x40bf8, 0xffffff },
	{ 0x40bfc, 0xffffff },
	{ 0x40c00, 0x0 },
	{ 0x40c04, 0x0 },
	{ 0x40c08, 0x0 },
	{ 0x40c0c, 0x0 },
	{ 0x40c10, 0x0 },
	{ 0x40c14, 0x0 },
	{ 0x40c18, 0x0 },
	{ 0x40c1c, 0x0 },
	{ 0x40c20, 0x0 },
	{ 0x40c24, 0x0 },
	{ 0x40c28, 0x0 },
	{ 0x40c2c, 0x0 },
	{ 0x40c30, 0x0 },
	{ 0x40c34, 0x0 },
	{ 0x40c38, 0x0 },
	{ 0x40c3c, 0x0 },
	{ 0x40c40, 0x10101 },
	{ 0x40c44, 0x10101 },
	{ 0x40c48, 0x10101 },
	{ 0x40c4c, 0x10101 },
	{ 0x40c50, 0x10101 },
	{ 0x40c54, 0x10101 },
	{ 0x40c58, 0x10101 },
	{ 0x40c5c, 0x10101 },
	{ 0x40c60, 0x10101 },
	{ 0x40c64, 0x10101 },
	{ 0x40c68, 0x20202 },
	{ 0x40c6c, 0x20202 },
	{ 0x40c70, 0x20202 },
	{ 0x40c74, 0x20202 },
	{ 0x40c78, 0x20202 },
	{ 0x40c7c, 0x20202 },
	{ 0x40c80, 0x30303 },
	{ 0x40c84, 0x30303 },
	{ 0x40c88, 0x30303 },
	{ 0x40c8c, 0x30303 },
	{ 0x40c90, 0x30303 },
	{ 0x40c94, 0x40404 },
	{ 0x40c98, 0x40404 },
	{ 0x40c9c, 0x40404 },
	{ 0x40ca0, 0x40404 },
	{ 0x40ca4, 0x40404 },
	{ 0x40ca8, 0x50505 },
	{ 0x40cac, 0x50505 },
	{ 0x40cb0, 0x50505 },
	{ 0x40cb4, 0x50505 },
	{ 0x40cb8, 0x60606 },
	{ 0x40cbc, 0x60606 },
	{ 0x40cc0, 0x60606 },
	{ 0x40cc4, 0x70707 },
	{ 0x40cc8, 0x70707 },
	{ 0x40ccc, 0x70707 },
	{ 0x40cd0, 0x70707 },
	{ 0x40cd4, 0x80808 },
	{ 0x40cd8, 0x80808 },
	{ 0x40cdc, 0x80808 },
	{ 0x40ce0, 0x90909 },
	{ 0x40ce4, 0x90909 },
	{ 0x40ce8, 0xa0a0a },
	{ 0x40cec, 0xa0a0a },
	{ 0x40cf0, 0xa0a0a },
	{ 0x40cf4, 0xb0b0b },
	{ 0x40cf8, 0xb0b0b },
	{ 0x40cfc, 0xb0b0b },
	{ 0x40d00, 0xc0c0c },
	{ 0x40d04, 0xc0c0c },
	{ 0x40d08, 0xd0d0d },
	{ 0x40d0c, 0xd0d0d },
	{ 0x40d10, 0xe0e0e },
	{ 0x40d14, 0xe0e0e },
	{ 0x40d18, 0xe0e0e },
	{ 0x40d1c, 0xf0f0f },
	{ 0x40d20, 0xf0f0f },
	{ 0x40d24, 0x101010 },
	{ 0x40d28, 0x101010 },
	{ 0x40d2c, 0x111111 },
	{ 0x40d30, 0x111111 },
	{ 0x40d34, 0x121212 },
	{ 0x40d38, 0x121212 },
	{ 0x40d3c, 0x131313 },
	{ 0x40d40, 0x131313 },
	{ 0x40d44, 0x141414 },
	{ 0x40d48, 0x151515 },
	{ 0x40d4c, 0x151515 },
	{ 0x40d50, 0x161616 },
	{ 0x40d54, 0x161616 },
	{ 0x40d58, 0x171717 },
	{ 0x40d5c, 0x171717 },
	{ 0x40d60, 0x181818 },
	{ 0x40d64, 0x191919 },
	{ 0x40d68, 0x191919 },
	{ 0x40d6c, 0x1a1a1a },
	{ 0x40d70, 0x1b1b1b },
	{ 0x40d74, 0x1b1b1b },
	{ 0x40d78, 0x1c1c1c },
	{ 0x40d7c, 0x1c1c1c },
	{ 0x40d80, 0x1d1d1d },
	{ 0x40d84, 0x1e1e1e },
	{ 0x40d88, 0x1f1f1f },
	{ 0x40d8c, 0x1f1f1f },
	{ 0x40d90, 0x202020 },
	{ 0x40d94, 0x212121 },
	{ 0x40d98, 0x212121 },
	{ 0x40d9c, 0x222222 },
	{ 0x40da0, 0x232323 },
	{ 0x40da4, 0x242424 },
	{ 0x40da8, 0x242424 },
	{ 0x40dac, 0x252525 },
	{ 0x40db0, 0x262626 },
	{ 0x40db4, 0x272727 },
	{ 0x40db8, 0x272727 },
	{ 0x40dbc, 0x282828 },
	{ 0x40dc0, 0x292929 },
	{ 0x40dc4, 0x2a2a2a },
	{ 0x40dc8, 0x2b2b2b },
	{ 0x40dcc, 0x2c2c2c },
	{ 0x40dd0, 0x2c2c2c },
	{ 0x40dd4, 0x2d2d2d },
	{ 0x40dd8, 0x2e2e2e },
	{ 0x40ddc, 0x2f2f2f },
	{ 0x40de0, 0x303030 },
	{ 0x40de4, 0x313131 },
	{ 0x40de8, 0x323232 },
	{ 0x40dec, 0x333333 },
	{ 0x40df0, 0x333333 },
	{ 0x40df4, 0x343434 },
	{ 0x40df8, 0x353535 },
	{ 0x40dfc, 0x363636 },
	{ 0x40e00, 0x373737 },
	{ 0x40e04, 0x383838 },
	{ 0x40e08, 0x393939 },
	{ 0x40e0c, 0x3a3a3a },
	{ 0x40e10, 0x3b3b3b },
	{ 0x40e14, 0x3c3c3c },
	{ 0x40e18, 0x3d3d3d },
	{ 0x40e1c, 0x3e3e3e },
	{ 0x40e20, 0x3f3f3f },
	{ 0x40e24, 0x404040 },
	{ 0x40e28, 0x414141 },
	{ 0x40e2c, 0x424242 },
	{ 0x40e30, 0x434343 },
	{ 0x40e34, 0x444444 },
	{ 0x40e38, 0x464646 },
	{ 0x40e3c, 0x474747 },
	{ 0x40e40, 0x484848 },
	{ 0x40e44, 0x494949 },
	{ 0x40e48, 0x4a4a4a },
	{ 0x40e4c, 0x4b4b4b },
	{ 0x40e50, 0x4c4c4c },
	{ 0x40e54, 0x4d4d4d },
	{ 0x40e58, 0x4f4f4f },
	{ 0x40e5c, 0x505050 },
	{ 0x40e60, 0x515151 },
	{ 0x40e64, 0x525252 },
	{ 0x40e68, 0x535353 },
	{ 0x40e6c, 0x545454 },
	{ 0x40e70, 0x565656 },
	{ 0x40e74, 0x575757 },
	{ 0x40e78, 0x585858 },
	{ 0x40e7c, 0x595959 },
	{ 0x40e80, 0x5b5b5b },
	{ 0x40e84, 0x5c5c5c },
	{ 0x40e88, 0x5d5d5d },
	{ 0x40e8c, 0x5e5e5e },
	{ 0x40e90, 0x606060 },
	{ 0x40e94, 0x616161 },
	{ 0x40e98, 0x626262 },
	{ 0x40e9c, 0x646464 },
	{ 0x40ea0, 0x656565 },
	{ 0x40ea4, 0x666666 },
	{ 0x40ea8, 0x686868 },
	{ 0x40eac, 0x696969 },
	{ 0x40eb0, 0x6a6a6a },
	{ 0x40eb4, 0x6c6c6c },
	{ 0x40eb8, 0x6d6d6d },
	{ 0x40ebc, 0x6f6f6f },
	{ 0x40ec0, 0x707070 },
	{ 0x40ec4, 0x717171 },
	{ 0x40ec8, 0x737373 },
	{ 0x40ecc, 0x747474 },
	{ 0x40ed0, 0x767676 },
	{ 0x40ed4, 0x777777 },
	{ 0x40ed8, 0x797979 },
	{ 0x40edc, 0x7a7a7a },
	{ 0x40ee0, 0x7c7c7c },
	{ 0x40ee4, 0x7d7d7d },
	{ 0x40ee8, 0x7f7f7f },
	{ 0x40eec, 0x808080 },
	{ 0x40ef0, 0x828282 },
	{ 0x40ef4, 0x838383 },
	{ 0x40ef8, 0x858585 },
	{ 0x40efc, 0x868686 },
	{ 0x40f00, 0x888888 },
	{ 0x40f04, 0x898989 },
	{ 0x40f08, 0x8b8b8b },
	{ 0x40f0c, 0x8d8d8d },
	{ 0x40f10, 0x8e8e8e },
	{ 0x40f14, 0x909090 },
	{ 0x40f18, 0x919191 },
	{ 0x40f1c, 0x939393 },
	{ 0x40f20, 0x959595 },
	{ 0x40f24, 0x969696 },
	{ 0x40f28, 0x989898 },
	{ 0x40f2c, 0x9a9a9a },
	{ 0x40f30, 0x9b9b9b },
	{ 0x40f34, 0x9d9d9d },
	{ 0x40f38, 0x9f9f9f },
	{ 0x40f3c, 0xa1a1a1 },
	{ 0x40f40, 0xa2a2a2 },
	{ 0x40f44, 0xa4a4a4 },
	{ 0x40f48, 0xa6a6a6 },
	{ 0x40f4c, 0xa7a7a7 },
	{ 0x40f50, 0xa9a9a9 },
	{ 0x40f54, 0xababab },
	{ 0x40f58, 0xadadad },
	{ 0x40f5c, 0xafafaf },
	{ 0x40f60, 0xb0b0b0 },
	{ 0x40f64, 0xb2b2b2 },
	{ 0x40f68, 0xb4b4b4 },
	{ 0x40f6c, 0xb6b6b6 },
	{ 0x40f70, 0xb8b8b8 },
	{ 0x40f74, 0xbababa },
	{ 0x40f78, 0xbbbbbb },
	{ 0x40f7c, 0xbdbdbd },
	{ 0x40f80, 0xbfbfbf },
	{ 0x40f84, 0xc1c1c1 },
	{ 0x40f88, 0xc3c3c3 },
	{ 0x40f8c, 0xc5c5c5 },
	{ 0x40f90, 0xc7c7c7 },
	{ 0x40f94, 0xc9c9c9 },
	{ 0x40f98, 0xcbcbcb },
	{ 0x40f9c, 0xcdcdcd },
	{ 0x40fa0, 0xcfcfcf },
	{ 0x40fa4, 0xd1d1d1 },
	{ 0x40fa8, 0xd3d3d3 },
	{ 0x40fac, 0xd5d5d5 },
	{ 0x40fb0, 0xd7d7d7 },
	{ 0x40fb4, 0xd9d9d9 },
	{ 0x40fb8, 0xdbdbdb },
	{ 0x40fbc, 0xdddddd },
	{ 0x40fc0, 0xdfdfdf },
	{ 0x40fc4, 0xe1e1e1 },
	{ 0x40fc8, 0xe3e3e3 },
	{ 0x40fcc, 0xe5e5e5 },
	{ 0x40fd0, 0xe7e7e7 },
	{ 0x40fd4, 0xe9e9e9 },
	{ 0x40fd8, 0xebebeb },
	{ 0x40fdc, 0xeeeeee },
	{ 0x40fe0, 0xf0f0f0 },
	{ 0x40fe4, 0xf2f2f2 },
	{ 0x40fe8, 0xf4f4f4 },
	{ 0x40fec, 0xf6f6f6 },
	{ 0x40ff0, 0xf8f8f8 },
	{ 0x40ff4, 0xfbfbfb },
	{ 0x40ff8, 0xfdfdfd },
	{ 0x40ffc, 0xffffff },
};
