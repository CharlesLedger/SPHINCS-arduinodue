/*
 * test_wotsp.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "test_wotsp.h"
#include "wotsp.h"
#include "utils.h"

static char const * test_wotsp_keygen(void)
{
	unsigned char * y = malloc((SPHINCS_BYTES*WOTS_L) * sizeof(unsigned char));
	mu_assert("Malloc returned NULL.", y != NULL);
	unsigned char * x = malloc((SPHINCS_BYTES*WOTS_L) * sizeof(unsigned char));
	mu_assert("Malloc returned NULL.", x != NULL);

	unsigned char const y_exp[SPHINCS_BYTES*WOTS_L] = {
		0xed, 0x1a, 0xc1, 0xb6, 0x24, 0x17, 0x4b, 0x14,
		0x53, 0x9c, 0xc1, 0xf3, 0x93, 0xea, 0xdd, 0xa4,
		0x14, 0x18, 0x1d, 0xbf, 0xc1, 0x61, 0xf5, 0x4a,
		0x1c, 0x14, 0xbb, 0x55, 0x59, 0x41, 0x5f, 0x08,

		0x2c, 0xe0, 0xfa, 0x94, 0xbc, 0xa8, 0xf0, 0x7f,
		0xc8, 0x44, 0xf6, 0x9d, 0x69, 0xa4, 0xa7, 0x9f,
		0x96, 0xa5, 0x2b, 0x94, 0x5c, 0x39, 0x60, 0x43,
		0x5d, 0x2d, 0x4b, 0x04, 0x80, 0xa7, 0x37, 0xe8,

		0xf6, 0x9d, 0xca, 0x08, 0x4f, 0x7d, 0xd7, 0xf1,
		0xa0, 0x18, 0x41, 0xfe, 0x14, 0x73, 0xee, 0x35,
		0x3a, 0xfd, 0x8b, 0x4d, 0x44, 0x1c, 0x7f, 0x6a,
		0x66, 0x77, 0x32, 0x4e, 0x29, 0x7e, 0x96, 0xfb,

		0x3b, 0x09, 0xd9, 0xf9, 0x6a, 0x1d, 0x69, 0xf4,
		0xd2, 0xb8, 0x2b, 0x78, 0x6f, 0x03, 0x54, 0x63,
		0x91, 0x1b, 0x9d, 0x1a, 0x9a, 0xfb, 0x1a, 0xa5,
		0x8d, 0xa8, 0x32, 0x53, 0xc3, 0x6b, 0x6a, 0xa2,


		0xa8, 0x6f, 0x8f, 0x58, 0x28, 0xdf, 0x86, 0x44,
		0x5d, 0xca, 0x98, 0xa8, 0x9e, 0x45, 0x35, 0xc0,
		0x47, 0x78, 0xb8, 0x9b, 0xef, 0xb5, 0x3b, 0x5b,
		0xba, 0xd3, 0x39, 0x55, 0x25, 0xf0, 0xe1, 0xd8,

		0x4d, 0xf9, 0xb8, 0xe3, 0x54, 0x1c, 0x8d, 0x42,
		0xb9, 0x46, 0xe6, 0x27, 0xc5, 0x6d, 0x51, 0xf8,
		0xe0, 0x85, 0x0a, 0x2c, 0x85, 0xcb, 0xe9, 0x79,
		0x29, 0x5c, 0x75, 0x4e, 0x3e, 0x9e, 0x0e, 0x42,

		0xbf, 0xda, 0x17, 0xc4, 0xe2, 0x45, 0x0b, 0xb3,
		0xd5, 0x97, 0x26, 0x1b, 0x07, 0xff, 0x3a, 0xb7,
		0xfc, 0x53, 0xd4, 0x14, 0xe0, 0xfb, 0x06, 0x82,
		0x00, 0xab, 0xa0, 0x16, 0xff, 0x0e, 0x40, 0x4a,

		0xa4, 0x5a, 0x4a, 0x49, 0x1d, 0x5d, 0x7f, 0x36,
		0x7f, 0x9d, 0x20, 0xc7, 0x29, 0x88, 0x88, 0xb8,
		0xda, 0xb1, 0xd7, 0x44, 0xee, 0x29, 0x0d, 0x24,
		0x49, 0x38, 0x50, 0x4a, 0xcf, 0xf3, 0x83, 0xa1,


		0xad, 0x9d, 0xad, 0x06, 0xf3, 0xaa, 0xb2, 0xa4,
		0xd9, 0xc5, 0x71, 0x03, 0xc4, 0x19, 0x80, 0x89,
		0xb5, 0x94, 0x35, 0xee, 0x4e, 0xbe, 0x38, 0x7d,
		0xee, 0x7c, 0x22, 0x06, 0x39, 0x95, 0xd5, 0x0e,

		0xb6, 0x9a, 0x87, 0xff, 0x53, 0x00, 0xf9, 0xfa,
		0x2b, 0x11, 0x94, 0x46, 0x53, 0x30, 0x2a, 0xd1,
		0xef, 0x33, 0x7e, 0x09, 0x2d, 0x50, 0x90, 0x0a,
		0x75, 0x6f, 0x3d, 0xc6, 0xb6, 0xd7, 0x90, 0xeb,

		0x0e, 0x2a, 0xe1, 0xf6, 0xa8, 0x28, 0x58, 0x58,
		0x0e, 0xd8, 0x5e, 0x72, 0xd5, 0xaf, 0x67, 0xba,
		0x7d, 0xe0, 0x72, 0x78, 0xc9, 0xa9, 0x6d, 0x1d,
		0xce, 0x89, 0x5b, 0x2b, 0x55, 0x53, 0x9c, 0x91,

		0xc8, 0x16, 0xaa, 0xbe, 0xef, 0xe8, 0x7e, 0x2e,
		0xe6, 0x79, 0x4f, 0x55, 0xca, 0xd6, 0xd3, 0x56,
		0x0a, 0xc1, 0x12, 0xed, 0xda, 0x09, 0x3b, 0xaf,
		0x38, 0xe0, 0x63, 0x7e, 0x57, 0x1d, 0x97, 0x3d,


		0xa9, 0x32, 0xa6, 0xbc, 0xe5, 0x5c, 0x41, 0x5b,
		0x61, 0x09, 0x5e, 0x29, 0xfc, 0xdf, 0x73, 0xc6,
		0xae, 0x7b, 0x2a, 0x3f, 0x03, 0x15, 0xd7, 0x94,
		0xdc, 0xb3, 0xc8, 0x01, 0x42, 0xc9, 0x83, 0x35,

		0xa7, 0x02, 0xe6, 0x3e, 0x38, 0xae, 0xbc, 0x77,
		0xd5, 0x6f, 0x25, 0xdc, 0xda, 0xea, 0x40, 0xb2,
		0xe7, 0x7d, 0x48, 0x26, 0x80, 0x86, 0xee, 0x89,
		0xee, 0xe2, 0xb2, 0xa5, 0x9d, 0x09, 0xe7, 0x3c,

		0x0d, 0xc1, 0x5e, 0x9d, 0x43, 0x86, 0x6f, 0xd5,
		0x15, 0x50, 0x24, 0xa2, 0x39, 0xc5, 0xbf, 0xa4,
		0x18, 0xa3, 0xd5, 0xd2, 0xda, 0xa2, 0x16, 0x45,
		0x77, 0x49, 0xbd, 0x62, 0x04, 0xa4, 0x21, 0x71,

		0x3c, 0x26, 0x3b, 0xe0, 0x25, 0x2c, 0xb5, 0xed,
		0x66, 0x83, 0x35, 0xd7, 0x1d, 0x80, 0xcc, 0xac,
		0xa2, 0xe8, 0x88, 0x59, 0x89, 0x10, 0x16, 0x6f,
		0x8c, 0xc3, 0x24, 0xfe, 0x24, 0x81, 0xf9, 0xa5,


		0x7c, 0xbb, 0x90, 0xb1, 0x0b, 0x70, 0x74, 0x6b,
		0x9c, 0xda, 0x2d, 0xc5, 0x32, 0x52, 0x3d, 0xff,
		0x02, 0x12, 0xf2, 0x3d, 0xd3, 0x12, 0x1d, 0xfe,
		0xad, 0xa3, 0xc1, 0x89, 0x90, 0x60, 0x53, 0xf0,

		0x79, 0x6c, 0xe0, 0x10, 0xa7, 0xb0, 0x69, 0xf1,
		0x06, 0x0e, 0x74, 0x4a, 0x8f, 0x73, 0xdc, 0x58,
		0x03, 0xa2, 0xc1, 0x47, 0x59, 0x53, 0xeb, 0xbe,
		0x3e, 0xf2, 0xa8, 0x4d, 0x3c, 0x62, 0xe8, 0xa8,

		0x6b, 0xd2, 0xda, 0x39, 0x5a, 0x27, 0x25, 0xdb,
		0x0b, 0xdd, 0xed, 0x7b, 0x17, 0xdc, 0xbe, 0x42,
		0x3c, 0x59, 0x6b, 0xbb, 0x0f, 0x1d, 0xa1, 0x06,
		0x7c, 0x87, 0x87, 0xe5, 0x8b, 0x10, 0x65, 0x13,

		0xaa, 0x40, 0x88, 0x85, 0x5c, 0x9a, 0x2d, 0xf7,
		0x14, 0x0e, 0x2a, 0x05, 0xf9, 0x76, 0xea, 0xdb,
		0x25, 0x8a, 0x4c, 0xb1, 0x71, 0xb3, 0xa5, 0x55,
		0x2a, 0xf6, 0xb3, 0x7a, 0xfa, 0x0d, 0x83, 0x81,


		0xea, 0x55, 0xa1, 0x8d, 0x8c, 0x2d, 0x65, 0xbf,
		0x10, 0x83, 0x2b, 0xec, 0x4d, 0xef, 0xaa, 0x81,
		0x9b, 0x20, 0x4f, 0xf5, 0x24, 0x90, 0xc6, 0xb6,
		0x96, 0x5d, 0x9f, 0x79, 0x8e, 0xdd, 0xef, 0xdc,

		0xfa, 0x77, 0x6a, 0x9a, 0x35, 0xfd, 0x9d, 0x97,
		0x93, 0x9a, 0xa8, 0x74, 0xb3, 0x6a, 0xcc, 0xb2,
		0xf5, 0x30, 0x83, 0xc9, 0x2a, 0x0c, 0x60, 0x04,
		0xb5, 0x6d, 0x21, 0x93, 0x56, 0x8b, 0x98, 0xbe,

		0xdc, 0x2f, 0xb9, 0xe2, 0x7b, 0xdb, 0x56, 0xc0,
		0x82, 0xe3, 0x7e, 0x21, 0x43, 0xcd, 0xa3, 0x1c,
		0xcb, 0x15, 0xf1, 0xfe, 0x42, 0x8a, 0xb2, 0x98,
		0x26, 0xf3, 0x41, 0x6c, 0x42, 0x62, 0x4c, 0x43,

		0x1f, 0xf7, 0x6f, 0xb6, 0xf1, 0x11, 0x9d, 0xee,
		0xff, 0x7d, 0x46, 0xd9, 0x60, 0x80, 0xbe, 0x13,
		0x9b, 0x94, 0x78, 0xee, 0x52, 0x6b, 0x31, 0xa3,
		0x77, 0x72, 0x1d, 0x28, 0x38, 0xed, 0xca, 0xc9,


		0x64, 0x33, 0xd0, 0x09, 0x3d, 0x3e, 0x2e, 0xce,
		0x72, 0xc3, 0x6a, 0x29, 0x2e, 0x87, 0x27, 0x62,
		0x53, 0x4e, 0x31, 0x87, 0xbb, 0xda, 0xdb, 0x04,
		0xc8, 0xeb, 0xfc, 0x90, 0x24, 0xd6, 0x5d, 0x06,

		0xd7, 0x7e, 0x61, 0x57, 0xdf, 0x72, 0x44, 0xce,
		0xfb, 0xa8, 0x38, 0xf5, 0xaf, 0xd3, 0x82, 0xf9,
		0x5a, 0xc5, 0xb9, 0xab, 0xb5, 0xbd, 0x7a, 0x54,
		0xa6, 0x97, 0xd7, 0x2c, 0xba, 0x7c, 0xe2, 0x30,

		0xe0, 0x73, 0x4e, 0x7e, 0x05, 0x2c, 0xf6, 0x41,
		0xec, 0x44, 0x1e, 0xae, 0x44, 0xe4, 0x67, 0xfd,
		0xe7, 0xf7, 0xa7, 0xa6, 0xe2, 0xfe, 0x3f, 0x58,
		0x34, 0x07, 0x38, 0xdc, 0x1f, 0x5e, 0xbd, 0x9f,

		0x7c, 0xa3, 0x60, 0xd5, 0x3f, 0xbe, 0x34, 0xd9,
		0xe0, 0x98, 0x37, 0x99, 0xb6, 0x20, 0xbf, 0xcb,
		0x2e, 0xa4, 0xa1, 0xbe, 0x48, 0xe5, 0xbe, 0x6e,
		0x41, 0x48, 0x4d, 0x40, 0x5c, 0x63, 0x7d, 0x5d,


		0x2e, 0x2b, 0x0e, 0x3f, 0x44, 0x05, 0x99, 0xcd,
		0xd8, 0xed, 0x84, 0x4c, 0x15, 0xfc, 0x7f, 0x2c,
		0x75, 0xcb, 0x00, 0x22, 0x67, 0x23, 0x87, 0xbb,
		0x35, 0x2e, 0x07, 0xe2, 0xa6, 0x3a, 0x6f, 0xf4,

		0x36, 0x78, 0x77, 0xa4, 0x77, 0xef, 0xd4, 0xf4,
		0xef, 0x2b, 0x5e, 0xb2, 0xe1, 0xc1, 0xac, 0x8b,
		0x97, 0x75, 0x14, 0x62, 0xb9, 0x58, 0x4e, 0xa3,
		0xf7, 0x53, 0xa0, 0x8b, 0x43, 0x3a, 0x07, 0x44,

		0x4a, 0xad, 0xd1, 0x59, 0x59, 0x02, 0x46, 0x3e,
		0x4c, 0x37, 0xf6, 0xe7, 0x59, 0x85, 0x48, 0xea,
		0xab, 0xbc, 0x1c, 0x1f, 0x57, 0xe1, 0x23, 0xba,
		0xf6, 0x70, 0xb5, 0xad, 0x95, 0xca, 0x5d, 0xa5,

		0x92, 0x31, 0x2d, 0xd8, 0x4d, 0x45, 0xd4, 0x07,
		0xf6, 0x6c, 0x92, 0x6d, 0x45, 0x6f, 0x1a, 0xac,
		0xb2, 0xc8, 0x33, 0x09, 0xc5, 0xd3, 0xe6, 0x45,
		0x7f, 0xa6, 0xb8, 0xa1, 0x67, 0x71, 0xce, 0x93,


		0xfa, 0xcf, 0xa0, 0x97, 0x56, 0xd4, 0x3f, 0x3f,
		0xf5, 0x92, 0x85, 0x32, 0xfd, 0x9a, 0x7c, 0x67,
		0xff, 0x41, 0xf8, 0x84, 0x72, 0x46, 0x95, 0xda,
		0xc3, 0x8a, 0x12, 0x0d, 0x7c, 0x56, 0xe4, 0x7f,

		0x01, 0xeb, 0xc3, 0xc0, 0x0d, 0xa7, 0x03, 0x73,
		0xc1, 0x63, 0x4f, 0x33, 0x1e, 0x43, 0xc7, 0x92,
		0x97, 0x27, 0xe0, 0x9b, 0x34, 0x33, 0x17, 0xd3,
		0xe3, 0x06, 0x6f, 0x72, 0x20, 0x0a, 0xb1, 0xcb,

		0x9c, 0xa4, 0x26, 0x10, 0x15, 0x1a, 0xcd, 0xfb,
		0x2b, 0x95, 0xed, 0x22, 0xca, 0x55, 0x3d, 0xb6,
		0x94, 0xc0, 0x00, 0x1a, 0x0a, 0xfd, 0xac, 0xd5,
		0xa2, 0x99, 0x9d, 0xd5, 0x7e, 0x7f, 0x58, 0xda,

		0xd1, 0xf6, 0x01, 0x61, 0x5c, 0x08, 0x5d, 0xb9,
		0xf9, 0x36, 0x06, 0x89, 0x1a, 0xca, 0x37, 0x5c,
		0x11, 0xcb, 0xea, 0x53, 0xd7, 0x7f, 0x34, 0x8c,
		0x78, 0xf0, 0xaf, 0xba, 0x5b, 0xb0, 0x42, 0xd8,


		0x4a, 0x89, 0x51, 0xe9, 0x2b, 0xa8, 0x3e, 0x4e,
		0xc3, 0x29, 0xed, 0x8e, 0x43, 0x62, 0x00, 0x13,
		0x72, 0x3c, 0xeb, 0x58, 0x6e, 0x5b, 0x86, 0xf9,
		0xff, 0x84, 0x1c, 0xc8, 0xd8, 0x35, 0x13, 0x56,

		0x28, 0x80, 0x0b, 0xaf, 0x9c, 0x32, 0xcb, 0x02,
		0x52, 0x51, 0x4f, 0x9c, 0x4c, 0x8d, 0xfc, 0xa5,
		0x53, 0xf8, 0xdf, 0x5e, 0x58, 0xac, 0x6a, 0xe9,
		0x9f, 0x40, 0x9f, 0x0f, 0xc5, 0xe6, 0x3b, 0x20,

		0x28, 0x32, 0x8f, 0x6e, 0xfe, 0x98, 0x7e, 0xf4,
		0x87, 0x8c, 0x97, 0xfd, 0x2e, 0x9b, 0x8a, 0x7a,
		0x6e, 0x8c, 0x04, 0xe1, 0x8a, 0xd3, 0xeb, 0xee,
		0x9d, 0xf9, 0xa9, 0x57, 0x2f, 0x60, 0x24, 0xed,

		0x63, 0x06, 0x8f, 0x90, 0x79, 0xef, 0x68, 0x3b,
		0x79, 0x6f, 0xac, 0xce, 0x7f, 0x91, 0xa0, 0x7f,
		0xab, 0xfb, 0x2f, 0xc0, 0xd5, 0x45, 0x07, 0x97,
		0xf2, 0xba, 0x52, 0x98, 0x3c, 0x4c, 0x92, 0x05,


		0x62, 0x74, 0xb2, 0xec, 0x05, 0x40, 0x70, 0xb9,
		0x90, 0x3e, 0xfa, 0xce, 0xca, 0x5a, 0xc7, 0x7b,
		0x3c, 0x0a, 0x28, 0x23, 0xcc, 0x96, 0x78, 0x0d,
		0x56, 0xa5, 0x16, 0xa6, 0x7e, 0x94, 0x90, 0x45,

		0xab, 0x3e, 0x5c, 0x28, 0xe9, 0x6c, 0x65, 0x77,
		0xf3, 0x4e, 0xe0, 0x9b, 0x75, 0x70, 0x40, 0xb5,
		0xf1, 0x16, 0x49, 0xd5, 0xb4, 0x3f, 0x48, 0xe6,
		0xb0, 0xdb, 0x52, 0x57, 0x62, 0x35, 0xce, 0xd0,

		0x34, 0x09, 0x6d, 0xbf, 0xfc, 0xf8, 0xce, 0x28,
		0x34, 0xdb, 0xe9, 0xe4, 0x78, 0xa6, 0xd8, 0x51,
		0x77, 0x4a, 0xf2, 0x52, 0xc0, 0x0d, 0x9b, 0xa7,
		0xd0, 0xf6, 0xa4, 0xe2, 0x4e, 0xeb, 0x2d, 0xad,

		0xf4, 0x1f, 0x55, 0xa9, 0xd3, 0x04, 0xe1, 0xb5,
		0x87, 0x15, 0xab, 0xac, 0xda, 0x41, 0x96, 0xfc,
		0xc7, 0x9b, 0x88, 0xe4, 0x09, 0x98, 0x40, 0xf0,
		0xe9, 0x49, 0xc6, 0xb5, 0x8f, 0x77, 0xcf, 0xe6,


		0xa0, 0x4b, 0x3d, 0xef, 0xba, 0x77, 0xd0, 0x56,
		0x41, 0x3e, 0xff, 0xaf, 0x93, 0x46, 0xcb, 0x5a,
		0xfd, 0xf2, 0x20, 0x80, 0x92, 0x8d, 0x64, 0xe0,
		0xb5, 0xcf, 0x59, 0xd3, 0x42, 0x87, 0x30, 0xbe,

		0xe3, 0x3d, 0xf7, 0x3f, 0x72, 0x98, 0x86, 0x21,
		0xf2, 0x91, 0x8e, 0xf7, 0x33, 0x72, 0x52, 0x1e,
		0xe8, 0x74, 0x20, 0xeb, 0x71, 0x96, 0xb9, 0xe9,
		0x10, 0xb5, 0x21, 0x24, 0x11, 0xb1, 0x7b, 0x70,

		0x25, 0x5a, 0x82, 0xbe, 0xcf, 0x86, 0x94, 0x8f,
		0x6f, 0x41, 0xb3, 0xef, 0xa1, 0x59, 0xf3, 0x31,
		0x53, 0x46, 0x88, 0x94, 0x1a, 0x92, 0x93, 0x47,
		0x69, 0x4e, 0xa3, 0x10, 0x50, 0x2e, 0x35, 0x77,

		0xa4, 0x70, 0x4c, 0x41, 0x38, 0x09, 0x8c, 0xfd,
		0xcd, 0x46, 0xee, 0x25, 0x1c, 0x1c, 0x99, 0x9c,
		0xac, 0x3f, 0xf9, 0x79, 0xdc, 0x37, 0xb1, 0x5b,
		0x29, 0x04, 0x6c, 0xfc, 0x27, 0x4a, 0x84, 0x4c,


		0xc9, 0x19, 0x07, 0x93, 0x71, 0xf5, 0x85, 0x2e,
		0xa7, 0xdd, 0x69, 0x28, 0xc1, 0xbb, 0x92, 0x64,
		0xf4, 0x91, 0x5e, 0x52, 0x6b, 0x58, 0xcc, 0xbf,
		0x9f, 0x49, 0x9f, 0x7b, 0x42, 0x7f, 0x2f, 0xd2,

		0xa6, 0xb4, 0x14, 0x91, 0x64, 0x45, 0x88, 0xeb,
		0x1e, 0x82, 0x42, 0xd0, 0x6f, 0xb5, 0x45, 0x3f,
		0xda, 0x8d, 0x47, 0xcd, 0x6d, 0x8d, 0xc1, 0x15,
		0x90, 0xe5, 0xe3, 0x52, 0xc0, 0x85, 0xbe, 0xd6,

		0x88, 0xfd, 0xcd, 0x25, 0x77, 0x55, 0x33, 0x0a,
		0x79, 0x27, 0xfa, 0x34, 0xf7, 0x8d, 0x6b, 0x8f,
		0x48, 0xe2, 0x70, 0x0d, 0x45, 0x68, 0x87, 0x29,
		0x66, 0xbb, 0xd1, 0x79, 0x5f, 0x6f, 0xcb, 0xb7,

		0x2b, 0x90, 0x25, 0x89, 0xad, 0xf9, 0x3d, 0x48,
		0xf5, 0x87, 0xf9, 0x58, 0x9f, 0x82, 0x7e, 0x67,
		0xfb, 0x52, 0xad, 0x24, 0x1d, 0xda, 0xec, 0xa3,
		0xf8, 0x5d, 0xf2, 0x58, 0xd3, 0x7a, 0x78, 0x3e,


		0x39, 0x89, 0x58, 0x5d, 0x47, 0xa0, 0xdb, 0x0c,
		0xf3, 0xb1, 0x3a, 0x4d, 0xa1, 0x1f, 0xf2, 0xe5,
		0x11, 0x43, 0x16, 0xb9, 0x17, 0x6a, 0xe7, 0x07,
		0x1a, 0x4e, 0x3a, 0xcb, 0x42, 0x14, 0xe0, 0xe3,

		0xb2, 0x4d, 0xb8, 0x8c, 0x32, 0xaa, 0x27, 0xf6,
		0x89, 0xe5, 0xeb, 0xf2, 0xc7, 0xab, 0x8f, 0x88,
		0x42, 0x73, 0x11, 0x4a, 0xa3, 0x15, 0x63, 0x5b,
		0x19, 0xfc, 0x1a, 0x6a, 0xc0, 0xb4, 0x79, 0x8c,

		0x02, 0xd1, 0x56, 0x93, 0x53, 0xd7, 0x00, 0x53,
		0x6f, 0xba, 0x5d, 0x5d, 0x2b, 0xf7, 0xf9, 0xa1,
		0xa3, 0xbe, 0xee, 0x56, 0xeb, 0x33, 0x8f, 0x93,
		0x1f, 0xdc, 0xca, 0x14, 0xc6, 0x2f, 0xf9, 0x32,

		0xdc, 0x9e, 0xee, 0x2d, 0x9d, 0xba, 0x3d, 0x79,
		0x03, 0x3e, 0x43, 0x54, 0x34, 0x1d, 0xc8, 0xbb,
		0x56, 0x64, 0x66, 0x11, 0xf0, 0xd6, 0x1d, 0x01,
		0xd9, 0x03, 0x4a, 0x45, 0x09, 0x0e, 0x6f, 0xe6,


		0xa0, 0xcc, 0x86, 0x0b, 0x46, 0x33, 0xac, 0x84,
		0x0b, 0xd4, 0xe3, 0x6a, 0xe8, 0xf6, 0x5d, 0x6f,
		0x81, 0x28, 0x96, 0x4d, 0xda, 0x44, 0x47, 0x68,
		0x68, 0x62, 0x8f, 0x37, 0xb7, 0x03, 0xbf, 0xba,

		0x13, 0x2b, 0xfd, 0xbe, 0x8c, 0x3e, 0x08, 0x3c,
		0xe1, 0x1f, 0xe6, 0xd7, 0x32, 0x3d, 0xad, 0x91,
		0xaa, 0x9a, 0xf0, 0x0a, 0x78, 0xae, 0x68, 0x62,
		0x6c, 0x63, 0xda, 0xf1, 0xe9, 0xe1, 0x98, 0x39,

		0x63, 0x36, 0x71, 0x0d, 0xbd, 0x58, 0xb5, 0x03,
		0x8c, 0xd2, 0xf0, 0xb8, 0x2d, 0x57, 0x1a, 0xc6,
		0x54, 0xbb, 0x3d, 0x1d, 0xc4, 0x74, 0x3f, 0x3b,
		0x19, 0xc3, 0x92, 0x54, 0xb0, 0x18, 0x3b, 0x1e,

		0xd7, 0x61, 0xdd, 0x02, 0xfb, 0x12, 0x89, 0x14,
		0xa5, 0xfc, 0x37, 0xb1, 0x11, 0xb6, 0x36, 0xe1,
		0x00, 0x37, 0xde, 0xf7, 0x68, 0x6c, 0xde, 0x6b,
		0x04, 0xd5, 0xcc, 0xa6, 0x2f, 0x1a, 0x67, 0x37,


		0xbd, 0xc6, 0xd4, 0xbd, 0xb0, 0x5f, 0x87, 0xa8,
		0x26, 0xfe, 0x09, 0x75, 0x7e, 0x08, 0x19, 0x75,
		0xd6, 0xd7, 0x25, 0x4a, 0x5d, 0xbf, 0xfb, 0x4b,
		0xf2, 0xdd, 0xb3, 0xe0, 0xbe, 0xde, 0x6c, 0x07,

		0x4c, 0x91, 0x25, 0xea, 0x64, 0x6c, 0x7d, 0xd8,
		0x52, 0x5e, 0x51, 0x18, 0x46, 0x03, 0x82, 0xbd,
		0xf5, 0x16, 0xd5, 0xab, 0x33, 0x4a, 0xd4, 0x38,
		0x3a, 0x77, 0x9f, 0x73, 0x5a, 0x3c, 0x81, 0x2b,

		0x62, 0x49, 0xab, 0x21, 0x89, 0xb1, 0x64, 0xe1,
		0x53, 0x12, 0x56, 0xa0, 0xeb, 0xb8, 0x4f, 0x9d,
		0x8c, 0x13, 0x56, 0x3a, 0x7d, 0x90, 0x53, 0x0e,
		0x78, 0x76, 0x74, 0x8e, 0x27, 0xde, 0x0d, 0x18,

		0x7e, 0x30, 0xf9, 0xf3, 0x59, 0x1c, 0x84, 0x80,
		0xe1, 0x55, 0x2a, 0x77, 0x5d, 0xa0, 0x6b, 0xd3,
		0x67, 0x2f, 0x84, 0xa7, 0x7c, 0xdb, 0x3d, 0xb8,
		0xd8, 0xf5, 0x27, 0x49, 0xc0, 0xa7, 0xa6, 0x6f,


		0xd9, 0xd3, 0x2f, 0xff, 0xff, 0x0d, 0x39, 0x63,
		0xfd, 0xe6, 0x49, 0xdb, 0x90, 0x26, 0x38, 0xf7,
		0x56, 0xd7, 0xe1, 0x4c, 0x78, 0x55, 0x62, 0x4b,
		0xda, 0x87, 0xd0, 0xd8, 0xeb, 0x1d, 0x95, 0x27,

		0x46, 0x75, 0x29, 0x9f, 0xda, 0xf7, 0x6d, 0x1d,
		0x49, 0xdc, 0x47, 0x3f, 0xde, 0xf9, 0x9e, 0x8a,
		0x26, 0xdb, 0x0e, 0xec, 0x64, 0x66, 0xde, 0x35,
		0x4c, 0x8a, 0xa7, 0x18, 0xc9, 0x7b, 0x1d, 0x61,

		0x00, 0x11, 0x95, 0x4f, 0x78, 0xa6, 0xd8, 0x91,
		0x19, 0x22, 0xff, 0xab, 0xc8, 0xcc, 0xfb, 0xcb,
		0xe6, 0x49, 0xb5, 0x7b, 0x76, 0x62, 0x5d, 0x26,
		0xd4, 0x16, 0x6b, 0xf2, 0xec, 0xc1, 0x9f, 0xa1
	};

	unsigned char const x_exp[SPHINCS_BYTES*WOTS_L] = {
		0x19, 0xcd, 0x8d, 0x06, 0xee, 0x49, 0x7b, 0xd1,
		0xc7, 0xa2, 0x78, 0x94, 0x6b, 0x2f, 0x4d, 0x51,
		0xff, 0x72, 0xa3, 0xaa, 0x9c, 0xbd, 0x99, 0xb4,
		0xf9, 0xee, 0x23, 0xed, 0xbe, 0x94, 0xee, 0xfc,

		0xb3, 0xe6, 0x4d, 0x2f, 0x42, 0x88, 0x4b, 0x41,
		0x8f, 0xfb, 0xd0, 0xe7, 0xda, 0x76, 0xf0, 0x76,
		0x42, 0xdf, 0x52, 0xee, 0x7a, 0xaa, 0xf8, 0x0c,
		0xcb, 0x45, 0xac, 0xa8, 0x21, 0xbc, 0x66, 0x73,

		0x23, 0x47, 0x5b, 0x3c, 0x23, 0xf9, 0x44, 0x1c,
		0x64, 0x8e, 0xfe, 0x5c, 0x41, 0xb2, 0x9d, 0xf0,
		0x8a, 0x0d, 0x5b, 0x70, 0x90, 0x8c, 0xcb, 0x2a,
		0x21, 0x71, 0xeb, 0xdf, 0x69, 0x73, 0xe3, 0x0f,

		0x0c, 0x0e, 0x41, 0x07, 0xf7, 0xe7, 0x35, 0xea,
		0xb4, 0xc8, 0xd1, 0x62, 0x4d, 0x94, 0xfa, 0x8f,
		0xb4, 0xf7, 0x28, 0xa2, 0x35, 0x01, 0x81, 0xf8,
		0x08, 0xd1, 0xa0, 0x8f, 0x3f, 0x26, 0x7e, 0x9d,


		0x8e, 0xf4, 0x27, 0xab, 0x56, 0x5a, 0xf7, 0x8b,
		0xf3, 0x58, 0xcd, 0x7f, 0x6b, 0xe6, 0xc2, 0x4f,
		0x3d, 0x9e, 0xfd, 0xfc, 0x99, 0x4f, 0x51, 0xb7,
		0xd4, 0x41, 0x1e, 0x23, 0x18, 0x19, 0x76, 0x0b,

		0x96, 0x79, 0xfd, 0x80, 0xab, 0xb4, 0x32, 0x09,
		0x83, 0xdc, 0xf1, 0xfb, 0xa3, 0xc7, 0x64, 0x37,
		0x98, 0x35, 0xe2, 0x95, 0xf4, 0x9f, 0x84, 0xd8,
		0xf6, 0x6d, 0x01, 0x42, 0x86, 0x30, 0xc8, 0x80,

		0xed, 0x3d, 0x74, 0x47, 0x7c, 0xa1, 0x1e, 0x06,
		0x89, 0x77, 0x7f, 0xee, 0x8d, 0xaa, 0x72, 0x44,
		0x59, 0xdc, 0x18, 0x59, 0x40, 0xe3, 0x83, 0x63,
		0x42, 0x67, 0x45, 0x9a, 0xb2, 0x96, 0x78, 0xb5,

		0x90, 0x5d, 0x47, 0xe8, 0x2f, 0xf1, 0x1f, 0x0b,
		0x64, 0x17, 0x75, 0x52, 0xa6, 0xb3, 0x09, 0xeb,
		0x2c, 0xed, 0xd3, 0x97, 0x52, 0xcf, 0xe6, 0xff,
		0xbb, 0x12, 0x30, 0x73, 0xf5, 0x53, 0x11, 0x6d,


		0xc2, 0xee, 0x8b, 0xdb, 0x49, 0x1a, 0x0d, 0x72,
		0xab, 0x3d, 0x98, 0x4a, 0x37, 0x99, 0x28, 0xe3,
		0xbc, 0x8a, 0x23, 0x22, 0x2b, 0x1c, 0x3a, 0xf7,
		0x12, 0xb0, 0xf3, 0x68, 0x82, 0xd7, 0x6f, 0x7a,

		0x22, 0xb9, 0xe2, 0x77, 0x04, 0x0b, 0xdb, 0x78,
		0xdb, 0x5e, 0x14, 0x81, 0x83, 0x78, 0xcb, 0x17,
		0x2b, 0x12, 0x2f, 0x2c, 0x07, 0x06, 0x42, 0xd0,
		0x94, 0x5d, 0xe9, 0x09, 0x72, 0xa6, 0x4d, 0xf6,

		0x94, 0x2f, 0x14, 0x5e, 0x73, 0x06, 0x9b, 0x76,
		0x99, 0x45, 0xf3, 0xe5, 0x4f, 0x2b, 0xfe, 0x64,
		0x9f, 0x2b, 0x80, 0xf2, 0x6d, 0xe1, 0xcb, 0x17,
		0x2b, 0xdb, 0x65, 0x63, 0xd8, 0x36, 0xa4, 0xc7,

		0xaa, 0x3c, 0x1c, 0xe8, 0x94, 0xcd, 0xa2, 0xdf,
		0x8a, 0x11, 0xa2, 0x77, 0x3e, 0xb1, 0x28, 0x61,
		0x4f, 0xed, 0x63, 0x80, 0x4d, 0xfd, 0xaa, 0xb9,
		0x77, 0x97, 0x73, 0x7c, 0x3e, 0x47, 0xe5, 0x8a,


		0xfd, 0x57, 0x00, 0xf0, 0xcd, 0xc8, 0x7e, 0x64,
		0x89, 0x10, 0xa5, 0x29, 0xb9, 0x26, 0x7c, 0xab,
		0xe2, 0xc5, 0x47, 0x02, 0x5e, 0xb8, 0xf9, 0x65,
		0x58, 0x65, 0x6a, 0xec, 0x5a, 0xb8, 0x69, 0x7a,

		0x64, 0x37, 0xdb, 0x97, 0xf5, 0xd1, 0xb9, 0xf8,
		0x46, 0x45, 0xd2, 0xf3, 0xe6, 0x53, 0xf6, 0x08,
		0x41, 0xf2, 0xbf, 0x0b, 0xcc, 0x90, 0xb6, 0x2d,
		0x57, 0x77, 0x62, 0xa8, 0xc3, 0x55, 0x04, 0x8c,

		0xa6, 0xe4, 0x34, 0x18, 0x36, 0x63, 0xfa, 0x8b,
		0xe9, 0xf8, 0xc2, 0xdc, 0x8c, 0xf1, 0xef, 0xbf,
		0xdc, 0xc3, 0x30, 0x8b, 0x43, 0x45, 0x45, 0x0b,
		0x1f, 0xbb, 0xb3, 0xe6, 0x7a, 0x9a, 0x62, 0x8d,

		0xe3, 0x77, 0x4d, 0x68, 0xaf, 0x19, 0xd9, 0xf2,
		0x9f, 0x9e, 0xb9, 0x67, 0xfc, 0x6d, 0xed, 0xfd,
		0x6e, 0xbe, 0x55, 0xb1, 0x9a, 0x5f, 0x3d, 0xa3,
		0x24, 0x3a, 0x9a, 0xd3, 0xcc, 0x2e, 0xc3, 0xf4,


		0x6f, 0x14, 0x52, 0x20, 0xc4, 0xb6, 0xb9, 0xef,
		0x28, 0x17, 0x60, 0x6e, 0x51, 0x6e, 0xa3, 0x03,
		0xc0, 0x49, 0xcb, 0x6a, 0xf9, 0x5c, 0xdc, 0x4b,
		0xc5, 0x4d, 0xff, 0xf1, 0x0d, 0xe9, 0x8a, 0x02,

		0xf8, 0x86, 0x8d, 0xa0, 0x6a, 0xbf, 0x74, 0x8b,
		0x52, 0x37, 0x07, 0x35, 0xc1, 0x68, 0xf4, 0x66,
		0x3c, 0x2e, 0x99, 0x67, 0xc8, 0x16, 0x2c, 0x71,
		0x23, 0xfc, 0xe0, 0x98, 0xe4, 0xc2, 0x51, 0x18,

		0x25, 0xe4, 0xc8, 0x2a, 0x4f, 0x05, 0x69, 0x95,
		0x80, 0x05, 0xe0, 0x5d, 0x4c, 0xbe, 0x06, 0xee,
		0x48, 0x66, 0xbe, 0xe8, 0x59, 0x1a, 0x9a, 0xc8,
		0xb5, 0x52, 0x41, 0xc3, 0x88, 0x7a, 0xd7, 0x6a,

		0x23, 0x1d, 0x79, 0x18, 0xd5, 0x81, 0x54, 0xc1,
		0xa5, 0x39, 0x63, 0xe3, 0x94, 0x9c, 0x79, 0xdb,
		0x4f, 0x38, 0x77, 0x6f, 0xbc, 0x56, 0x91, 0xf2,
		0x91, 0xa4, 0x78, 0x04, 0x7e, 0xbc, 0xce, 0x39,


		0x57, 0xeb, 0x19, 0xda, 0xad, 0x8a, 0x14, 0x85,
		0xf1, 0x58, 0x44, 0x94, 0x9a, 0x2f, 0xa5, 0x7b,
		0x24, 0xc7, 0x0a, 0x05, 0xc5, 0x57, 0x70, 0x34,
		0x75, 0x8b, 0xac, 0x78, 0x11, 0x10, 0x1a, 0xd1,

		0xb2, 0xf4, 0x64, 0xd8, 0x7f, 0xc9, 0xe2, 0x18,
		0x33, 0x92, 0x2f, 0x99, 0xca, 0xce, 0x6e, 0x6f,
		0xf3, 0x25, 0x8e, 0x1c, 0xf9, 0x95, 0xe6, 0xd4,
		0x6c, 0x89, 0xc5, 0x29, 0x7c, 0xc0, 0x91, 0x60,

		0xe2, 0xe8, 0x7c, 0x81, 0xef, 0x1f, 0xef, 0x4b,
		0x2b, 0x0b, 0x38, 0xe0, 0xdf, 0xdd, 0x90, 0x45,
		0x2d, 0xc1, 0x61, 0xe6, 0x67, 0x08, 0x49, 0x29,
		0x28, 0x99, 0x8b, 0x66, 0xec, 0x1e, 0x20, 0xb0,

		0x90, 0x50, 0x82, 0xaa, 0x2a, 0x6b, 0xa1, 0x98,
		0x6e, 0xae, 0x7b, 0x79, 0xce, 0xfb, 0x9c, 0x0b,
		0xb3, 0xe5, 0x1d, 0x46, 0x61, 0x33, 0x1c, 0x9e,
		0x55, 0x8f, 0x87, 0x3b, 0x3b, 0x4b, 0x7c, 0xba,


		0x32, 0x9a, 0xdd, 0x5f, 0x21, 0x89, 0xac, 0x76,
		0x25, 0xa7, 0x25, 0xad, 0x4b, 0x63, 0x4b, 0x8c,
		0x84, 0x76, 0x54, 0xee, 0x77, 0x98, 0xc4, 0xc7,
		0xb7, 0xb6, 0x78, 0x50, 0x8b, 0x8a, 0x1f, 0x17,

		0x45, 0xe7, 0x7f, 0xc5, 0x88, 0x39, 0xc6, 0x2d,
		0xa5, 0xd9, 0x35, 0x31, 0x4c, 0xdb, 0x3f, 0xdb,
		0x42, 0xc8, 0x81, 0x64, 0x59, 0xc6, 0x32, 0x9a,
		0x78, 0x7a, 0x4c, 0xc5, 0x1d, 0x74, 0x42, 0xc1,

		0x9c, 0xae, 0x88, 0x6e, 0x9a, 0x3e, 0x6a, 0x99,
		0x6a, 0x12, 0x81, 0xd1, 0x39, 0x70, 0xfe, 0x83,
		0xc1, 0xd9, 0xed, 0x5c, 0xaf, 0x7a, 0x72, 0x5c,
		0x3d, 0x0d, 0x35, 0x0f, 0x33, 0xcf, 0x14, 0x8b,

		0xc6, 0xe0, 0x73, 0x8b, 0xf7, 0x2a, 0x2b, 0x08,
		0x24, 0x47, 0x7e, 0xbf, 0x5e, 0x63, 0x41, 0x04,
		0x2a, 0x0f, 0x7a, 0x81, 0x21, 0x89, 0x51, 0x33,
		0x7b, 0x7c, 0x56, 0x3a, 0x30, 0x7f, 0x20, 0x49,


		0x49, 0xdb, 0x9c, 0x8b, 0x7f, 0x5c, 0x0d, 0x58,
		0x97, 0x66, 0x19, 0x55, 0x2b, 0xf2, 0x76, 0x7d,
		0x54, 0xe7, 0x08, 0x23, 0x1a, 0x10, 0xf5, 0x11,
		0xce, 0x11, 0xd0, 0x36, 0x85, 0x9c, 0x30, 0x35,

		0x64, 0x6a, 0xc8, 0xa7, 0xe1, 0x74, 0x45, 0x8f,
		0x87, 0x02, 0xed, 0x0f, 0xba, 0x1f, 0x12, 0x11,
		0x5f, 0x1e, 0x0e, 0xc1, 0x33, 0x08, 0xe7, 0xad,
		0xd2, 0x8c, 0x1b, 0x1e, 0x65, 0xa2, 0xe5, 0x06,

		0x16, 0x2d, 0xf8, 0xb8, 0x72, 0x91, 0x7c, 0x3d,
		0xc7, 0x3d, 0x2d, 0xbf, 0xcf, 0x3b, 0x17, 0x27,
		0x59, 0x4a, 0xc9, 0xc7, 0xe3, 0x83, 0xf3, 0x3a,
		0x17, 0x80, 0x6c, 0x99, 0x2d, 0x8d, 0x74, 0x07,

		0x00, 0xfe, 0x2c, 0x01, 0x7f, 0xf2, 0xf1, 0x2e,
		0x26, 0x78, 0xca, 0x4f, 0xc1, 0x84, 0xdc, 0x3d,
		0xf3, 0xa5, 0x5c, 0xc6, 0x08, 0x36, 0xde, 0xb4,
		0x27, 0x62, 0x8e, 0xaa, 0x3b, 0x9f, 0x97, 0xf7,


		0xc3, 0x5a, 0xbf, 0x70, 0x59, 0xdf, 0xf4, 0xc4,
		0x6b, 0xb8, 0x39, 0x70, 0x15, 0x2d, 0x88, 0x70,
		0x9b, 0x25, 0x12, 0x61, 0x73, 0x2a, 0x63, 0x77,
		0x98, 0x17, 0xaa, 0x72, 0xb6, 0x69, 0xc0, 0x4d,

		0xfc, 0x1c, 0x83, 0xf3, 0xab, 0xed, 0x46, 0xf8,
		0xde, 0x25, 0x05, 0x6d, 0xfa, 0xba, 0x4b, 0x20,
		0x52, 0x60, 0x18, 0x85, 0x61, 0x8d, 0xb5, 0x16,
		0x64, 0x8d, 0xad, 0x0b, 0xae, 0xd1, 0x21, 0x06,

		0xee, 0x00, 0x4a, 0x3b, 0x92, 0xd9, 0xf7, 0x66,
		0x05, 0xde, 0xd1, 0x6b, 0x0b, 0x92, 0xa2, 0xf0,
		0x03, 0xe8, 0x6d, 0x22, 0xe6, 0x47, 0x1d, 0xd9,
		0xe7, 0xaa, 0xd7, 0xf1, 0x16, 0x53, 0x15, 0x59,

		0x0d, 0x39, 0x8b, 0xf0, 0x96, 0x71, 0xfd, 0xfe,
		0xf8, 0x7d, 0xc1, 0x61, 0xab, 0xf3, 0x3d, 0xc7,
		0xf2, 0x84, 0xf7, 0xfa, 0x29, 0x2c, 0x0f, 0xb6,
		0x26, 0x2d, 0xeb, 0x74, 0x91, 0xed, 0xbb, 0x48,


		0x11, 0xee, 0xc0, 0x22, 0x65, 0x9a, 0xeb, 0xfc,
		0xaa, 0x3c, 0x31, 0x08, 0xef, 0xae, 0x99, 0x1a,
		0xf0, 0x1e, 0xdb, 0x09, 0xbe, 0x8d, 0xa7, 0x26,
		0x39, 0xd7, 0x2f, 0x3e, 0x7e, 0x16, 0x47, 0x81,

		0x00, 0x00, 0x08, 0x22, 0x8f, 0x4e, 0x8e, 0xdb,
		0x51, 0x60, 0x2b, 0xd8, 0xaa, 0xbd, 0x83, 0x07,
		0xbe, 0x1e, 0x91, 0x01, 0x56, 0x3e, 0x8b, 0x72,
		0xa5, 0x19, 0xb8, 0xca, 0x6e, 0x47, 0x29, 0x0e,

		0x07, 0x48, 0x2c, 0x62, 0x59, 0x0f, 0x15, 0xdb,
		0xe9, 0x86, 0x6d, 0x45, 0xd4, 0x01, 0xfb, 0x67,
		0x22, 0x43, 0x95, 0x5b, 0xec, 0x3b, 0x04, 0x07,
		0x1a, 0x63, 0x08, 0x92, 0xa4, 0x74, 0xdc, 0x18,

		0x6a, 0x9c, 0xa8, 0x1c, 0x6d, 0x2f, 0x0d, 0x3e,
		0x3e, 0xfc, 0x52, 0x4c, 0xfa, 0x8b, 0x8f, 0x7e,
		0x9c, 0xc5, 0x76, 0xc1, 0xb1, 0xce, 0x60, 0x45,
		0xaf, 0xee, 0x33, 0x20, 0x7e, 0x32, 0x5b, 0x3a,


		0xb7, 0xbf, 0x2c, 0x69, 0x8e, 0x05, 0x42, 0x3f,
		0x77, 0xf7, 0xe6, 0xce, 0x25, 0x44, 0x35, 0x09,
		0x33, 0xb7, 0xd5, 0x42, 0x5f, 0x62, 0x19, 0xd3,
		0x23, 0x33, 0xa8, 0xd0, 0xb1, 0xee, 0xc1, 0x7d,

		0x53, 0xf7, 0x41, 0x30, 0x10, 0x65, 0x81, 0x78,
		0xba, 0x11, 0x17, 0x90, 0x7b, 0x68, 0xe4, 0xaa,
		0x0f, 0xeb, 0xb6, 0xb4, 0x89, 0x7d, 0x1a, 0x29,
		0x57, 0x02, 0x94, 0xd3, 0x3a, 0x08, 0x84, 0x1e,

		0x29, 0x1f, 0x91, 0xa3, 0xf6, 0x62, 0x9f, 0x98,
		0xbf, 0xad, 0x2b, 0x83, 0xfe, 0x35, 0xca, 0xb2,
		0xb7, 0x9c, 0x02, 0x9d, 0xc3, 0xa7, 0x64, 0xe1,
		0x99, 0x16, 0x8c, 0x85, 0x6e, 0xcb, 0x5d, 0x1a,

		0xe1, 0x0b, 0xc8, 0xd8, 0x21, 0x49, 0x8e, 0x19,
		0x97, 0x7f, 0x30, 0x19, 0x0e, 0xc2, 0x7d, 0x89,
		0x0c, 0xed, 0xa8, 0x59, 0x12, 0x9c, 0xb6, 0xff,
		0x67, 0x83, 0x12, 0x42, 0x01, 0xaa, 0x59, 0x7f,


		0x06, 0x0d, 0x68, 0x4e, 0x1f, 0x16, 0xbd, 0xef,
		0xdf, 0xbb, 0x1f, 0x7f, 0xa4, 0xf9, 0xc7, 0xe9,
		0x23, 0x55, 0x55, 0xbf, 0xd0, 0x29, 0xb7, 0x1c,
		0xe2, 0x29, 0xd3, 0xe3, 0xb3, 0xfd, 0x4d, 0x5d,

		0xc9, 0x80, 0xf2, 0xac, 0x83, 0x2d, 0xce, 0xb1,
		0xa2, 0x2d, 0x44, 0xf8, 0xaa, 0xd8, 0xac, 0xbb,
		0xa7, 0x61, 0xdb, 0x12, 0x45, 0x8f, 0xe2, 0x51,
		0x08, 0xf1, 0x4f, 0x43, 0xf3, 0x76, 0xb9, 0x30,

		0xcb, 0xf9, 0xd3, 0x9a, 0xfc, 0x61, 0xbe, 0x3d,
		0x00, 0x53, 0xa3, 0x01, 0xbd, 0xef, 0x26, 0x0d,
		0x68, 0x63, 0xc5, 0x57, 0x51, 0x9d, 0x9e, 0xec,
		0x4c, 0x1b, 0xfb, 0xdf, 0xbe, 0x1b, 0x91, 0x68,

		0x95, 0xf3, 0xc4, 0x55, 0x32, 0x89, 0xe6, 0xed,
		0xb2, 0xe1, 0x6b, 0xbf, 0x6f, 0x36, 0xbb, 0x67,
		0xa2, 0xd3, 0xe5, 0x61, 0x07, 0x20, 0x10, 0xa4,
		0xa8, 0xed, 0xdc, 0x00, 0x99, 0x8e, 0x14, 0x92,


		0xe6, 0x83, 0xfb, 0xf0, 0xf7, 0x50, 0x0e, 0x75,
		0x51, 0x04, 0x51, 0xe7, 0xc0, 0x1a, 0xb6, 0xff,
		0x52, 0x98, 0x26, 0x3c, 0xbb, 0x33, 0x9b, 0x12,
		0x21, 0x96, 0x2d, 0x02, 0x57, 0x7f, 0xf0, 0xf7,

		0x47, 0x4d, 0xa0, 0x6a, 0x3e, 0x15, 0xf7, 0x54,
		0x30, 0xcb, 0x18, 0x35, 0xe6, 0xe0, 0x85, 0x34,
		0x62, 0x15, 0x30, 0x62, 0xeb, 0xd1, 0xe3, 0xc8,
		0xa8, 0xc0, 0x47, 0xbe, 0xe9, 0xf4, 0x9c, 0xad,

		0x65, 0xa0, 0x66, 0xc8, 0xa7, 0x1d, 0x7b, 0xcd,
		0xb6, 0xfd, 0xb8, 0x2a, 0x0b, 0x4f, 0xbc, 0x0e,
		0x69, 0x12, 0x75, 0x23, 0xd4, 0xbb, 0xd5, 0x76,
		0x8a, 0xd8, 0x6d, 0x33, 0xbf, 0xba, 0xb0, 0x54,

		0x5c, 0xca, 0xd2, 0x39, 0x2b, 0xfa, 0x0a, 0xd5,
		0x8d, 0x73, 0x93, 0x5e, 0x49, 0x60, 0x0e, 0xcc,
		0x7f, 0x0d, 0x4e, 0xbb, 0xa2, 0x81, 0x8f, 0xa4,
		0xaa, 0xdd, 0x60, 0x0f, 0x31, 0x9b, 0x44, 0x0c,


		0x7d, 0x40, 0x59, 0x32, 0xbb, 0x91, 0xdf, 0xdf,
		0x4f, 0xce, 0xf4, 0x32, 0xd8, 0xb2, 0xe5, 0x46,
		0x0a, 0xff, 0x50, 0x28, 0xa9, 0xcd, 0x57, 0x86,
		0xdf, 0xc8, 0x16, 0xec, 0x86, 0x90, 0x0d, 0xae,

		0x41, 0x25, 0x53, 0xff, 0x0f, 0xd7, 0xeb, 0x2b,
		0x96, 0x4d, 0x71, 0xc9, 0xea, 0x65, 0x3c, 0x87,
		0x57, 0x36, 0x71, 0x5f, 0xf5, 0x08, 0x4e, 0xc2,
		0xea, 0xe2, 0x26, 0xc7, 0x1f, 0x0a, 0x94, 0x82,

		0x74, 0x76, 0x10, 0x96, 0xfb, 0xf0, 0xbf, 0xf4,
		0x55, 0x83, 0xd8, 0xc7, 0xc9, 0x0f, 0xb0, 0x31,
		0xff, 0xcc, 0x9f, 0x4b, 0x1a, 0xe7, 0xda, 0x26,
		0x84, 0xf8, 0x92, 0x00, 0x1e, 0x5c, 0x52, 0x01,

		0x52, 0xd4, 0x49, 0xf2, 0xf5, 0xcf, 0xcc, 0x40,
		0x89, 0xb4, 0x64, 0xd3, 0x94, 0xfb, 0xef, 0x70,
		0xbd, 0x64, 0xef, 0xa8, 0xd1, 0x17, 0xc0, 0x86,
		0x27, 0x1c, 0xda, 0xd3, 0xfc, 0x01, 0x3f, 0xb5,


		0x69, 0x3e, 0x54, 0xf2, 0x04, 0xfc, 0x17, 0x18,
		0x9c, 0x55, 0x43, 0x23, 0x4b, 0x95, 0x12, 0xc6,
		0x62, 0x22, 0xe7, 0xb6, 0x25, 0xbd, 0x33, 0x5e,
		0x8f, 0x2a, 0x9b, 0x29, 0xf8, 0x22, 0x98, 0x8c,

		0x78, 0x2b, 0xba, 0xb6, 0x90, 0xb5, 0xd7, 0x28,
		0x96, 0x14, 0x40, 0x5d, 0xbe, 0xa1, 0x2a, 0xcc,
		0x5a, 0x71, 0x4c, 0x47, 0x1d, 0x72, 0x5e, 0x99,
		0x22, 0x70, 0xfa, 0xfc, 0x87, 0xaa, 0xce, 0x26,

		0xc8, 0xee, 0x48, 0x4e, 0xec, 0xf9, 0x0a, 0xeb,
		0x77, 0xc9, 0x66, 0x13, 0x32, 0x93, 0x4d, 0x2c,
		0x7b, 0x00, 0x76, 0x4a, 0xf2, 0xf6, 0x56, 0x8a,
		0xb0, 0xe4, 0x59, 0x5b, 0xca, 0xef, 0x4d, 0xfc,

		0x95, 0x54, 0x19, 0x49, 0x65, 0x07, 0x58, 0x27,
		0x1e, 0x64, 0x38, 0xf2, 0x30, 0xdc, 0x84, 0x10,
		0x15, 0xd2, 0x3a, 0x6d, 0x32, 0xe9, 0x8a, 0x5a,
		0x15, 0x8b, 0x7a, 0xab, 0x2c, 0x32, 0xc1, 0x2b,


		0x27, 0x94, 0xe3, 0x34, 0xf1, 0x0e, 0x0b, 0x5d,
		0x6d, 0x87, 0x98, 0xb8, 0x45, 0x33, 0xc9, 0x20,
		0x39, 0x8f, 0xb2, 0x96, 0xa5, 0xfe, 0x8c, 0x80,
		0xad, 0x50, 0x77, 0x23, 0xd1, 0x0a, 0x6f, 0xaf,

		0x4b, 0xe4, 0xf6, 0xb3, 0x66, 0x82, 0xbc, 0x91,
		0xb4, 0xcf, 0xe3, 0x55, 0xa5, 0xd9, 0xdc, 0x01,
		0xa2, 0xf7, 0x9d, 0x7e, 0xb5, 0x48, 0xa1, 0xf5,
		0x02, 0x72, 0xc5, 0xfb, 0x6d, 0x40, 0x08, 0xeb,

		0xd0, 0x10, 0xc9, 0x11, 0xd3, 0x12, 0x82, 0x42,
		0x11, 0x42, 0x3e, 0xb8, 0xf9, 0x5a, 0x3d, 0x7d,
		0xc4, 0x43, 0xfe, 0x25, 0x6a, 0x93, 0x25, 0xca,
		0x38, 0xd5, 0x59, 0xa1, 0x6c, 0xc0, 0x7f, 0x40,

		0xbe, 0x46, 0x26, 0x94, 0x0a, 0xec, 0x03, 0x97,
		0x46, 0xbe, 0xae, 0x35, 0x6b, 0xc9, 0x2e, 0xd9,
		0x65, 0xd5, 0x6f, 0x53, 0xef, 0x1f, 0x78, 0x67,
		0x6b, 0x63, 0xcd, 0x9e, 0x85, 0x0c, 0xe2, 0x14,


		0x17, 0x89, 0xbf, 0xd9, 0xd7, 0x90, 0x82, 0xc1,
		0xb2, 0x8c, 0x7b, 0x82, 0x57, 0x28, 0xc4, 0x3e,
		0xb7, 0x9e, 0xe9, 0x9a, 0x4a, 0x90, 0xca, 0x0f,
		0xe3, 0x66, 0x6b, 0x02, 0x48, 0xe0, 0x12, 0xeb,

		0x3c, 0xb4, 0x29, 0x76, 0x1b, 0xf6, 0x65, 0x06,
		0x3d, 0x10, 0xa1, 0x24, 0xa8, 0xc4, 0xeb, 0x3d,
		0xa4, 0xbf, 0xc4, 0x7c, 0x2c, 0x5d, 0xc4, 0xd1,
		0xf7, 0x56, 0x1e, 0x5b, 0x00, 0x12, 0x34, 0x6f,

		0x04, 0x79, 0x73, 0xfb, 0xa7, 0xce, 0x93, 0x91,
		0xd9, 0x7f, 0xd8, 0xdd, 0x53, 0x07, 0x51, 0x64,
		0xb3, 0xdf, 0x40, 0x11, 0x70, 0xfa, 0x7e, 0x00,
		0xe4, 0x40, 0x6b, 0xf2, 0xd7, 0xb7, 0x7f, 0xb9
	};

	/* keygen with in_sk and in_masks */
	wotsp_keygen(y, x, in_sk1, in_masks);

	mu_assert("Test case for X failed.", array_cmp(x, x_exp, SPHINCS_BYTES*WOTS_L));
	mu_assert("Test case for Y failed.", array_cmp(y, y_exp, SPHINCS_BYTES*WOTS_L));

	free(x);
	free(y);

	return NULL; /* Pass */
}

void run_test_wotsp(void)
{
	printf("### TEST_WOTSP ###\n\n");

	mu_run_test(test_wotsp_keygen, "test_wotsp_keygen()");

	printf("\n");
}
