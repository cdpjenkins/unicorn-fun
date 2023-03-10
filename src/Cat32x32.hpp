#ifndef UNICORN_FUN_Cat32x32_HPP
#define UNICORN_FUN_Cat32x32_HPP

#include <cstdint>

class Cat32x32 {
public:
    constexpr static uint8_t image[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xc4, 0xc1, 0xb9, 0xb4, 0xaf, 0xa6, 0xff, 0xbc, 0x7d, 0xcb, 0xb0, 0x98,
  0xcb, 0x84, 0x42, 0xce, 0x79, 0x26, 0xc9, 0x71, 0x1f, 0xbd, 0x61, 0x16,
  0xdb, 0x7f, 0x1a, 0xa8, 0x4b, 0x0f, 0xb4, 0x58, 0x10, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xd0, 0x7f, 0x04, 0xd1, 0x81, 0x03, 0xcf, 0x7f, 0x07,
  0xcc, 0x79, 0x06, 0xcf, 0x7e, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xd6, 0xd4, 0xcf, 0xdb, 0xda, 0xd6, 0xd4, 0xd2, 0xcd, 0xe5, 0xe2, 0xdf,
  0xe8, 0xbd, 0x87, 0xe5, 0x9b, 0x3d, 0xdf, 0x8d, 0x29, 0xd1, 0x78, 0x1b,
  0xc1, 0x64, 0x14, 0xd4, 0x78, 0x18, 0x7f, 0x26, 0x07, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xca, 0x74, 0x0a, 0xca, 0x74, 0x0a, 0xce, 0x7e, 0x1b,
  0xc9, 0x74, 0x0f, 0xbf, 0x60, 0x03, 0xc1, 0x64, 0x06, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xca, 0x81, 0x19, 0xcd, 0x82, 0x10, 0xac, 0x71, 0x69, 0xd8, 0x85, 0x00,
  0xcc, 0x73, 0x00, 0xd0, 0x7f, 0x05, 0xcb, 0x78, 0x05, 0x00, 0x00, 0x00,
  0xcb, 0xc8, 0xc2, 0xc4, 0xc1, 0xb9, 0xe2, 0xe1, 0xde, 0xf3, 0xf3, 0xf3,
  0xea, 0xde, 0xcb, 0xe0, 0xc2, 0x9a, 0xdf, 0x94, 0x37, 0xe1, 0x8c, 0x20,
  0xcf, 0x74, 0x16, 0xb9, 0x5b, 0x10, 0xbc, 0x5f, 0x12, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xca, 0x72, 0x08, 0xca, 0x72, 0x08, 0xcd, 0x7a, 0x17,
  0xca, 0x73, 0x0c, 0xbf, 0x59, 0x00, 0xbc, 0x5c, 0x04, 0xbb, 0x5d, 0x01,
  0xd0, 0x73, 0x1d, 0xd1, 0x74, 0x1e, 0xd1, 0x74, 0x1e, 0xd2, 0x6e, 0x13,
  0xc3, 0x7b, 0x1e, 0xdf, 0x90, 0x00, 0xc4, 0x7e, 0x34, 0xc8, 0x83, 0x4c,
  0xd0, 0x85, 0x3b, 0xc9, 0x6a, 0x00, 0xca, 0x75, 0x04, 0x00, 0x00, 0x00,
  0xd6, 0xd5, 0xd0, 0xd3, 0xd1, 0xcc, 0xeb, 0xeb, 0xe9, 0xed, 0xed, 0xec,
  0xce, 0xcd, 0xca, 0xba, 0xbb, 0xbe, 0xca, 0x77, 0x27, 0xdc, 0x87, 0x21,
  0xdb, 0x82, 0x19, 0xc4, 0x68, 0x13, 0xcb, 0x6f, 0x14, 0xb6, 0x59, 0x11,
  0x00, 0x00, 0x00, 0xcf, 0x84, 0x2a, 0xd0, 0x83, 0x25, 0xc9, 0x82, 0x4d,
  0xc2, 0x7a, 0x3b, 0xc2, 0x6b, 0x0f, 0xb9, 0x55, 0x01, 0xd5, 0x80, 0x1b,
  0xc1, 0x56, 0x15, 0xcc, 0x6b, 0x1b, 0xca, 0x68, 0x1a, 0xa4, 0x0f, 0x00,
  0xc5, 0x7c, 0x16, 0xb2, 0x70, 0x32, 0xa2, 0x64, 0x41, 0xae, 0x6f, 0x56,
  0xcb, 0x84, 0x4c, 0xd2, 0x7f, 0x03, 0xce, 0x7c, 0x09, 0x00, 0x00, 0x00,
  0xe5, 0xe4, 0xe3, 0xd4, 0xd2, 0xcf, 0xea, 0xea, 0xe9, 0xe2, 0xe1, 0xdf,
  0xc1, 0xbe, 0xb8, 0xc3, 0xb0, 0x9d, 0xaf, 0x54, 0x18, 0xd4, 0x7d, 0x1e,
  0xe0, 0x8a, 0x1c, 0xcc, 0x70, 0x15, 0x00, 0x00, 0x00, 0xb4, 0x57, 0x10,
  0x00, 0x00, 0x00, 0xca, 0x85, 0x35, 0xcc, 0x85, 0x2e, 0xac, 0x6d, 0x4a,
  0x95, 0x59, 0x40, 0xae, 0x67, 0x2a, 0xb8, 0x5e, 0x0a, 0xd2, 0x7a, 0x1d,
  0xdd, 0x8a, 0x24, 0xdf, 0x8e, 0x26, 0xdf, 0x8e, 0x26, 0xd9, 0x88, 0x23,
  0xb5, 0x71, 0x35, 0x8b, 0x50, 0x33, 0x78, 0x3f, 0x27, 0x98, 0x5c, 0x44,
  0xc5, 0x80, 0x4a, 0xd3, 0x81, 0x0b, 0xce, 0x7c, 0x0b, 0x00, 0x00, 0x00,
  0xd9, 0xda, 0xd9, 0xc5, 0xc4, 0xc0, 0xd9, 0xd9, 0xd9, 0xd2, 0xd1, 0xcf,
  0xb7, 0xb5, 0xb0, 0xb8, 0xb6, 0xb1, 0xfc, 0xab, 0x24, 0xd0, 0x79, 0x1c,
  0xe2, 0x8e, 0x1d, 0xd2, 0x78, 0x16, 0xab, 0x4c, 0x0e, 0xb8, 0x5b, 0x12,
  0x00, 0x00, 0x00, 0xc6, 0x81, 0x28, 0xca, 0x83, 0x28, 0x9e, 0x60, 0x3a,
  0x6d, 0x36, 0x1e, 0x92, 0x52, 0x29, 0xcf, 0x81, 0x22, 0xe8, 0x9f, 0x2a,
  0xf1, 0xaf, 0x30, 0xf5, 0xb5, 0x32, 0xf5, 0xb5, 0x32, 0xf0, 0xad, 0x30,
  0xd8, 0x93, 0x30, 0x97, 0x58, 0x1f, 0x6c, 0x34, 0x18, 0x98, 0x5c, 0x43,
  0xc8, 0x82, 0x47, 0xcf, 0x7b, 0x02, 0xca, 0x77, 0x06, 0x00, 0x00, 0x00,
  0xad, 0xac, 0xa8, 0xab, 0xa9, 0xa5, 0xb4, 0xb3, 0xb0, 0xb1, 0xaf, 0xac,
  0xa3, 0xa1, 0x9c, 0xa5, 0xa3, 0x9e, 0xe1, 0x8c, 0x20, 0xd0, 0x79, 0x1c,
  0xe5, 0x92, 0x1f, 0xd6, 0x7f, 0x19, 0xb4, 0x56, 0x11, 0xba, 0x5e, 0x13,
  0x00, 0x00, 0x00, 0xc8, 0x80, 0x19, 0xce, 0x85, 0x1d, 0xa7, 0x68, 0x3d,
  0x8a, 0x4b, 0x25, 0xc9, 0x81, 0x22, 0xf1, 0xb0, 0x2f, 0xfb, 0xc2, 0x39,
  0xfe, 0xd0, 0x5c, 0xff, 0xd5, 0x6c, 0xff, 0xc9, 0x42, 0xfe, 0xc5, 0x38,
  0xfa, 0xbe, 0x34, 0xe7, 0xa5, 0x2b, 0xb5, 0x71, 0x25, 0xab, 0x6b, 0x4c,
  0xcc, 0x84, 0x46, 0xc6, 0x6e, 0x00, 0xc3, 0x6e, 0x05, 0x00, 0x00, 0x00,
  0x54, 0x50, 0x46, 0xff, 0xff, 0xff, 0x82, 0x7f, 0x79, 0x7b, 0x78, 0x72,
  0xb1, 0xae, 0xaa, 0xbf, 0xb4, 0xa8, 0xea, 0x98, 0x23, 0xd1, 0x7b, 0x1d,
  0xe7, 0x96, 0x21, 0xd8, 0x82, 0x1b, 0xb4, 0x57, 0x11, 0xbb, 0x5f, 0x13,
  0x00, 0x00, 0x00, 0xc3, 0x79, 0x08, 0xca, 0x80, 0x00, 0xbe, 0x79, 0x40,
  0xcf, 0x86, 0x30, 0xf2, 0xb2, 0x2e, 0xff, 0xc7, 0x36, 0xff, 0xcf, 0x53,
  0xff, 0xf0, 0xcb, 0xff, 0xf6, 0xe0, 0xff, 0xd0, 0x60, 0xff, 0xc7, 0x38,
  0xff, 0xc9, 0x38, 0xfd, 0xc4, 0x35, 0xee, 0xac, 0x2d, 0xd5, 0x8b, 0x3e,
  0xcc, 0x80, 0x39, 0xa5, 0x48, 0x00, 0xbb, 0x64, 0x0e, 0xbf, 0x67, 0x19,
  0xb2, 0x73, 0x3a, 0xb2, 0x6f, 0x33, 0xb2, 0x79, 0x42, 0xc3, 0x7a, 0x2e,
  0xd0, 0x7e, 0x22, 0xcb, 0x77, 0x20, 0xff, 0xc0, 0x30, 0xd6, 0x82, 0x1f,
  0xeb, 0x9c, 0x24, 0xd7, 0x82, 0x1c, 0xad, 0x4e, 0x10, 0xbb, 0x5f, 0x14,
  0x00, 0x00, 0x00, 0xce, 0x72, 0x19, 0x9f, 0x2c, 0x00, 0xd7, 0x86, 0x27,
  0xed, 0xa9, 0x2d, 0xf1, 0xbd, 0x34, 0xdc, 0xaf, 0x39, 0xf7, 0xd0, 0x6d,
  0xff, 0xfb, 0xf2, 0xff, 0xf9, 0xeb, 0xff, 0xd1, 0x64, 0xf6, 0xbe, 0x38,
  0xdc, 0xae, 0x3c, 0xf0, 0xbe, 0x37, 0xfc, 0xc4, 0x34, 0xea, 0xa4, 0x2c,
  0xd1, 0x7e, 0x20, 0xbb, 0x60, 0x14, 0x9b, 0x3a, 0x0c, 0xd2, 0x7f, 0x21,
  0xd5, 0x83, 0x23, 0x33, 0x00, 0x00, 0xbf, 0x67, 0x1a, 0xc9, 0x74, 0x1f,
  0xcd, 0x79, 0x21, 0xc9, 0x74, 0x1f, 0xc0, 0x69, 0x1b, 0xde, 0x8e, 0x24,
  0xef, 0xa4, 0x28, 0xd7, 0x83, 0x1d, 0x98, 0x35, 0x0a, 0xb8, 0x5e, 0x14,
  0x00, 0x00, 0x00, 0xd4, 0x7b, 0x1f, 0xd2, 0x76, 0x1e, 0xe2, 0x94, 0x26,
  0xf6, 0xbb, 0x31, 0x8c, 0x71, 0x25, 0x4b, 0x49, 0x3d, 0xae, 0x99, 0x64,
  0xff, 0xfe, 0xf4, 0xff, 0xf5, 0xdf, 0xff, 0xcd, 0x5a, 0x8e, 0x6f, 0x25,
  0x45, 0x44, 0x3a, 0x72, 0x5d, 0x23, 0xf8, 0xc5, 0x35, 0xf5, 0xb9, 0x31,
  0xde, 0x8f, 0x24, 0xdb, 0x89, 0x22, 0xd7, 0x85, 0x22, 0xce, 0x7a, 0x1f,
  0xcf, 0x7c, 0x21, 0xd9, 0x8a, 0x25, 0xe3, 0x98, 0x2b, 0xea, 0xa3, 0x31,
  0xee, 0xa7, 0x32, 0xea, 0xa2, 0x2f, 0xe8, 0x9e, 0x2c, 0xf0, 0xa9, 0x2d,
  0xf1, 0xa8, 0x2a, 0xd6, 0x82, 0x1e, 0x00, 0x00, 0x00, 0xb5, 0x5a, 0x14,
  0x5e, 0x3c, 0x19, 0xd5, 0x81, 0x21, 0xd8, 0x80, 0x20, 0xe9, 0xa1, 0x2a,
  0xfb, 0xc4, 0x35, 0x7c, 0x72, 0x22, 0x2c, 0x48, 0x11, 0xa9, 0x9b, 0x5e,
  0xff, 0xff, 0xf6, 0xff, 0xf5, 0xdc, 0xfe, 0xca, 0x56, 0x79, 0x6a, 0x20,
  0x28, 0x4a, 0x0f, 0x62, 0x62, 0x1c, 0xf7, 0xc4, 0x36, 0xfc, 0xc5, 0x34,
  0xe8, 0x9f, 0x29, 0xeb, 0x9f, 0x28, 0xf2, 0xab, 0x2d, 0xec, 0xa3, 0x2c,
  0xed, 0xa5, 0x2d, 0xf5, 0xb1, 0x33, 0xfb, 0xbd, 0x3e, 0xfd, 0xc3, 0x47,
  0xfe, 0xc3, 0x42, 0xfe, 0xc0, 0x3c, 0xfc, 0xbc, 0x37, 0xfa, 0xb8, 0x33,
  0xf2, 0xa9, 0x2b, 0xd6, 0x82, 0x1f, 0xff, 0xf1, 0x3c, 0xb2, 0x57, 0x14,
  0x5e, 0x3c, 0x19, 0xff, 0xff, 0x39, 0xcc, 0x7c, 0x21, 0xe3, 0xa2, 0x2b,
  0xf7, 0xc2, 0x33, 0xe8, 0xc3, 0x44, 0xca, 0xc2, 0x65, 0xf3, 0xde, 0xa9,
  0xfe, 0xe7, 0xec, 0xfd, 0xe9, 0xe7, 0xff, 0xe0, 0x9d, 0xe9, 0xc8, 0x6b,
  0xbf, 0xbe, 0x66, 0xe2, 0xc2, 0x4f, 0xfc, 0xc7, 0x37, 0xf3, 0xbf, 0x33,
  0xe0, 0x9e, 0x2a, 0xe0, 0x96, 0x27, 0xf6, 0xb3, 0x2f, 0xfa, 0xb7, 0x32,
  0xfb, 0xba, 0x34, 0xfc, 0xbd, 0x38, 0xfd, 0xc1, 0x41, 0xfe, 0xc4, 0x49,
  0xfe, 0xc4, 0x45, 0xff, 0xc4, 0x42, 0xfd, 0xc1, 0x3f, 0xfb, 0xbb, 0x38,
  0xf5, 0xaf, 0x2e, 0xd9, 0x87, 0x20, 0xaf, 0x52, 0x12, 0xbc, 0x62, 0x16,
  0x5e, 0x3c, 0x19, 0x23, 0x0f, 0x11, 0xb7, 0x71, 0x20, 0xc9, 0x8e, 0x27,
  0xcb, 0xa1, 0x3d, 0xd3, 0xbb, 0x89, 0xf1, 0xea, 0xdb, 0xf1, 0xd5, 0xdb,
  0xd8, 0x76, 0x93, 0xe0, 0x93, 0xaa, 0xfb, 0xf6, 0xf6, 0xfc, 0xf8, 0xf0,
  0xec, 0xe2, 0xd4, 0xd6, 0xc4, 0xa3, 0xcb, 0xad, 0x69, 0xce, 0xa0, 0x33,
  0xcb, 0x8e, 0x27, 0xd1, 0x8b, 0x25, 0xf2, 0xaf, 0x2f, 0xfa, 0xb7, 0x32,
  0xfb, 0xba, 0x34, 0xfc, 0xbc, 0x37, 0xfd, 0xbf, 0x3d, 0xfe, 0xc2, 0x41,
  0xff, 0xc4, 0x44, 0xff, 0xc8, 0x4f, 0xfe, 0xc6, 0x4e, 0xfb, 0xbe, 0x40,
  0xf7, 0xb4, 0x32, 0xdf, 0x8f, 0x23, 0xbe, 0x63, 0x16, 0xc1, 0x69, 0x18,
  0x5e, 0x3c, 0x19, 0x2e, 0x1e, 0x15, 0xaf, 0x69, 0x1e, 0xc6, 0x87, 0x25,
  0xc9, 0xad, 0x78, 0xcb, 0xc4, 0xbd, 0xdd, 0xd8, 0xd3, 0xeb, 0xdf, 0xe3,
  0xc2, 0x84, 0x96, 0xe2, 0xc2, 0xcb, 0xf9, 0xf9, 0xf9, 0xef, 0xec, 0xea,
  0xd4, 0xcc, 0xc3, 0xcb, 0xc2, 0xb9, 0xc7, 0xbe, 0xb4, 0xca, 0xa8, 0x64,
  0xc7, 0x85, 0x23, 0xcf, 0x8a, 0x25, 0xf1, 0xaf, 0x2f, 0xfa, 0xb8, 0x32,
  0xfb, 0xba, 0x34, 0xfc, 0xbc, 0x36, 0xfd, 0xbe, 0x39, 0xfe, 0xc0, 0x3b,
  0xfe, 0xc3, 0x43, 0xfe, 0xc8, 0x52, 0xfd, 0xc7, 0x52, 0xfb, 0xbf, 0x44,
  0xf8, 0xb6, 0x35, 0xe3, 0x94, 0x25, 0xc4, 0x6b, 0x18, 0xc6, 0x6e, 0x19,
  0x5e, 0x3c, 0x19, 0x22, 0x1d, 0x16, 0xad, 0x63, 0x1b, 0xd7, 0x88, 0x25,
  0xda, 0xc1, 0x9a, 0xe6, 0xe6, 0xe8, 0xe6, 0xe4, 0xe4, 0xe7, 0xe6, 0xe7,
  0xce, 0xcc, 0xcd, 0xdd, 0xdb, 0xdc, 0xec, 0xea, 0xeb, 0xe3, 0xe1, 0xe2,
  0xed, 0xec, 0xec, 0xf0, 0xf0, 0xef, 0xe2, 0xe3, 0xe5, 0xd9, 0xbb, 0x90,
  0xd9, 0x8a, 0x23, 0xe4, 0x9d, 0x28, 0xf5, 0xb2, 0x2f, 0xfa, 0xb7, 0x32,
  0xfb, 0xb9, 0x34, 0xfc, 0xbc, 0x36, 0xfd, 0xbd, 0x37, 0xfd, 0xbe, 0x39,
  0xfe, 0xc2, 0x41, 0xfe, 0xc6, 0x4e, 0xfd, 0xc4, 0x4a, 0xfb, 0xbe, 0x41,
  0xf8, 0xb5, 0x34, 0xe4, 0x95, 0x25, 0xc6, 0x6d, 0x18, 0xc8, 0x70, 0x19,
  0x5e, 0x3c, 0x19, 0x5e, 0x3b, 0x19, 0xb0, 0x6e, 0x22, 0xd6, 0x79, 0x19,
  0xca, 0xa8, 0x83, 0xd0, 0xd0, 0xd0, 0xdf, 0xdf, 0xdf, 0xdc, 0xdb, 0xdc,
  0xdf, 0xde, 0xde, 0xe3, 0xe2, 0xe2, 0xdf, 0xdd, 0xde, 0xe3, 0xe2, 0xe3,
  0xea, 0xea, 0xea, 0xe0, 0xe0, 0xe0, 0xcc, 0xcb, 0xcb, 0xcd, 0xa0, 0x66,
  0xe2, 0x96, 0x23, 0xf2, 0xad, 0x2c, 0xf9, 0xb4, 0x30, 0xf9, 0xb7, 0x32,
  0xfa, 0xb8, 0x33, 0xfb, 0xb6, 0x31, 0xfc, 0xb4, 0x2f, 0xfd, 0xb2, 0x2e,
  0xfd, 0xbf, 0x45, 0xfd, 0xc5, 0x4e, 0xfc, 0xc0, 0x42, 0xfa, 0xbb, 0x3c,
  0xf7, 0xb3, 0x32, 0xe0, 0x90, 0x23, 0xc0, 0x66, 0x17, 0xc3, 0x6a, 0x18,
  0x00, 0x00, 0x00, 0xd0, 0x73, 0x1c, 0xc4, 0x56, 0x0c, 0xc1, 0x9f, 0x74,
  0xb4, 0x9b, 0x83, 0xb3, 0xb2, 0xb1, 0xc0, 0xc0, 0xc0, 0xd0, 0xd0, 0xd0,
  0xda, 0xda, 0xda, 0xde, 0xde, 0xde, 0xde, 0xde, 0xde, 0xd8, 0xd8, 0xd8,
  0xcc, 0xcc, 0xcc, 0xb9, 0xba, 0xbb, 0xb8, 0xa3, 0x84, 0xda, 0x96, 0x2c,
  0xed, 0xa5, 0x27, 0xf6, 0xb1, 0x2d, 0xf8, 0xb4, 0x2f, 0xf9, 0xb5, 0x31,
  0xf9, 0xb0, 0x2c, 0xfa, 0xaa, 0x27, 0xfa, 0xa6, 0x24, 0xfa, 0xa2, 0x23,
  0xfc, 0xbe, 0x43, 0xfc, 0xc0, 0x41, 0xfb, 0xbc, 0x3b, 0xfa, 0xb8, 0x36,
  0xf5, 0xae, 0x2e, 0xdb, 0x88, 0x20, 0xb3, 0x56, 0x13, 0xbd, 0x63, 0x17,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x73, 0x1d, 0x4e, 0xff, 0xff,
  0xb7, 0x9e, 0x87, 0x94, 0x95, 0x96, 0xa3, 0xa3, 0xa3, 0xaa, 0xaa, 0xaa,
  0xad, 0xad, 0xad, 0xae, 0xae, 0xad, 0xad, 0xad, 0xac, 0xab, 0xaa, 0xa9,
  0xaa, 0xa7, 0xa6, 0xa8, 0xa3, 0xa0, 0xc6, 0x97, 0x50, 0xe9, 0x9e, 0x22,
  0xf4, 0xac, 0x2a, 0xf6, 0xb0, 0x2c, 0xf7, 0xb3, 0x2e, 0xf8, 0xb1, 0x2e,
  0xf8, 0xa8, 0x26, 0xf8, 0xa6, 0x24, 0xf8, 0x9c, 0x1e, 0xf6, 0x9d, 0x21,
  0xfb, 0xbc, 0x3a, 0xfb, 0xbc, 0x38, 0xfa, 0xb9, 0x36, 0xf9, 0xb6, 0x32,
  0xf1, 0xa8, 0x2a, 0xd5, 0x81, 0x1e, 0x00, 0x00, 0x00, 0xb6, 0x5c, 0x15,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9b, 0x9b, 0x9b,
  0xa2, 0xa2, 0xa2, 0x9e, 0x9e, 0x9e, 0xa9, 0xa9, 0xa9, 0xff, 0xff, 0xff,
  0x94, 0x93, 0x92, 0x9a, 0x97, 0x95, 0x9f, 0x9a, 0x96, 0xaa, 0xa3, 0x9f,
  0xb4, 0xad, 0xa8, 0xbc, 0xb2, 0xa9, 0xde, 0x9d, 0x41, 0xf1, 0x9e, 0x1f,
  0xf4, 0xac, 0x2c, 0xf6, 0xb0, 0x2d, 0xf7, 0xb0, 0x2c, 0xf6, 0xa6, 0x26,
  0xf7, 0xa3, 0x23, 0xf8, 0xa4, 0x23, 0xf6, 0x95, 0x1a, 0xf1, 0x98, 0x1f,
  0xfb, 0xb9, 0x34, 0xfa, 0xb9, 0x34, 0xf9, 0xb6, 0x32, 0xf8, 0xb4, 0x2f,
  0xed, 0xa2, 0x28, 0xd1, 0x7c, 0x1d, 0xd8, 0x84, 0x1f, 0xc1, 0x67, 0x16,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x93, 0x93, 0x93, 0x93, 0x93, 0x92,
  0xb4, 0xac, 0xa5, 0xad, 0xa8, 0xa2, 0xb8, 0xb0, 0xaa, 0xbf, 0xb7, 0xb2,
  0xc6, 0xbf, 0xba, 0xd2, 0xcd, 0xc9, 0xe6, 0xa8, 0x56, 0xef, 0x95, 0x17,
  0xf2, 0xaa, 0x30, 0xf6, 0xaf, 0x2c, 0xf6, 0xaf, 0x2b, 0xf4, 0x9d, 0x1f,
  0xf6, 0x9e, 0x1d, 0xf7, 0xa1, 0x1f, 0xf3, 0x9b, 0x2d, 0xe9, 0xa2, 0x41,
  0xf9, 0xb5, 0x30, 0xf9, 0xb6, 0x31, 0xf8, 0xb4, 0x30, 0xf7, 0xb1, 0x2d,
  0xee, 0xa4, 0x27, 0xd3, 0x7e, 0x1c, 0xb7, 0x59, 0x0f, 0xc0, 0x67, 0x19,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x97, 0x96, 0x94,
  0xb7, 0x93, 0x71, 0xbf, 0x63, 0x12, 0xc7, 0x9c, 0x74, 0xd1, 0xc6, 0xbc,
  0xdd, 0xdc, 0xdb, 0xe1, 0xe1, 0xe2, 0xe3, 0xcf, 0xb4, 0xe6, 0xb2, 0x6b,
  0xec, 0xaf, 0x47, 0xf5, 0xae, 0x2a, 0xf5, 0xae, 0x2a, 0xf1, 0xa8, 0x3f,
  0xf3, 0xb1, 0x54, 0xf4, 0xbf, 0x70, 0xed, 0xd7, 0xba, 0xd7, 0xc2, 0xa3,
  0xf0, 0xae, 0x36, 0xf9, 0xb4, 0x2f, 0xf7, 0xb2, 0x2e, 0xf6, 0xaf, 0x2b,
  0xf3, 0xaa, 0x27, 0xe2, 0x90, 0x1f, 0xcb, 0x76, 0x23, 0xd2, 0x70, 0x04,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xbf, 0xa0, 0x83, 0xc9, 0x7d, 0x33, 0xc6, 0x70, 0x1f, 0xcd, 0xa9, 0x83,
  0xca, 0xc9, 0xc6, 0xd7, 0xd7, 0xd7, 0xde, 0xdf, 0xe0, 0xd7, 0xd6, 0xd3,
  0xe5, 0xb3, 0x5b, 0xf5, 0xac, 0x27, 0xf4, 0xac, 0x29, 0xe7, 0xc5, 0x8a,
  0xea, 0xe8, 0xe6, 0xec, 0xeb, 0xea, 0xe0, 0xe1, 0xe2, 0xc2, 0xc0, 0xbd,
  0xcc, 0x9c, 0x55, 0xf4, 0xac, 0x2a, 0xf6, 0xb0, 0x2b, 0xf5, 0xad, 0x29,
  0xf2, 0xa8, 0x25, 0xe9, 0x9b, 0x26, 0xda, 0xa2, 0x62, 0xe2, 0x67, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xc1, 0x69, 0x1b, 0xc0, 0x61, 0x0b, 0xd2, 0x94, 0x55,
  0xc6, 0xbf, 0xb4, 0xb6, 0xb5, 0xb2, 0xbb, 0xbb, 0xba, 0xbd, 0xba, 0xb4,
  0xde, 0xa6, 0x49, 0xf4, 0xaa, 0x26, 0xf4, 0xac, 0x2c, 0xdf, 0xc4, 0x96,
  0xce, 0xcf, 0xd0, 0xca, 0xc9, 0xc8, 0xbb, 0xbb, 0xb9, 0xbd, 0xbd, 0xbb,
  0xc0, 0xb6, 0xaa, 0xd9, 0xa3, 0x57, 0xe9, 0x9e, 0x29, 0xeb, 0x9e, 0x24,
  0xef, 0xa2, 0x21, 0xe9, 0xa1, 0x36, 0xe1, 0xc7, 0xa8, 0xe8, 0xa6, 0x56,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xbb, 0x64, 0x1b, 0xb0, 0x51, 0x07, 0xd1, 0x7e, 0x2d,
  0xdf, 0xc4, 0xa5, 0xcd, 0xcd, 0xcb, 0xae, 0xad, 0xa8, 0xa0, 0x92, 0x86,
  0xd8, 0x92, 0x33, 0xf2, 0xa7, 0x25, 0xf1, 0xa9, 0x2f, 0xe5, 0xc8, 0x9b,
  0xb5, 0xbf, 0xce, 0x70, 0x6f, 0x6b, 0xe5, 0xe4, 0xe3, 0xd3, 0xd2, 0xcf,
  0xd7, 0xd7, 0xd8, 0xc6, 0xc1, 0xbb, 0xbb, 0x95, 0x6b, 0xd0, 0x78, 0x18,
  0xe3, 0x90, 0x1c, 0xeb, 0xb8, 0x6f, 0xe1, 0xdc, 0xd7, 0xeb, 0xe3, 0xd9,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xb1, 0x5b, 0x19, 0xf6, 0x9b, 0x2a, 0xc9, 0x70, 0x1b,
  0xde, 0xa1, 0x5d, 0xde, 0xda, 0xd4, 0xcb, 0xcd, 0xcd, 0xbd, 0x2d, 0x00,
  0xdb, 0x87, 0x1e, 0xf0, 0xa5, 0x23, 0xee, 0xa8, 0x34, 0xe6, 0xcc, 0xa8,
  0xff, 0xff, 0xff, 0xa9, 0xa8, 0xa6, 0x8e, 0x8d, 0x8b, 0xcf, 0xce, 0xcc,
  0xe0, 0xe0, 0xdf, 0xc5, 0xc5, 0xc5, 0x99, 0xa2, 0xaa, 0xbf, 0x98, 0x77,
  0xe4, 0xc2, 0x99, 0xed, 0xe4, 0xd7, 0xd2, 0xd2, 0xd2, 0xdd, 0xdc, 0xdb,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xb7, 0x60, 0x1a, 0xcc, 0x75, 0x20, 0xc0, 0x6b, 0x1b,
  0xd8, 0x86, 0x2d, 0xdb, 0xc2, 0xa5, 0xc1, 0xca, 0xd3, 0xa6, 0x44, 0x00,
  0xd7, 0x84, 0x1c, 0xf0, 0xa3, 0x21, 0xec, 0xa8, 0x3b, 0xde, 0xcb, 0xb0,
  0xf7, 0x64, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbb, 0xb9, 0xdc, 0xdb, 0xdb,
  0xd9, 0xd9, 0xd8, 0xb2, 0xb1, 0xaf, 0xcf, 0xce, 0xcd, 0xbd, 0xbd, 0xbb,
  0xe7, 0xe8, 0xe9, 0xe6, 0xe6, 0xe7, 0xbe, 0xbe, 0xbc, 0xc4, 0xc3, 0xc1,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xd2, 0xd1, 0xcf, 0xc4, 0x84, 0x44, 0xb7, 0x68, 0x1c,
  0xd7, 0x84, 0x2a, 0xd2, 0xae, 0x84, 0xa8, 0xb2, 0xbb, 0x89, 0x25, 0x00,
  0xd1, 0x80, 0x18, 0xef, 0xa0, 0x1e, 0xe9, 0xa8, 0x41, 0xd2, 0xc3, 0xb0,
  0xe8, 0xc0, 0x8b, 0x69, 0x68, 0x65, 0xa9, 0xa8, 0xa6, 0xbf, 0xbe, 0xbc,
  0xb4, 0xb4, 0xb2, 0x8e, 0x8d, 0x8b, 0xd6, 0xd5, 0xd5, 0xc2, 0xc2, 0xc0,
  0xe5, 0xe5, 0xe4, 0xd9, 0xd8, 0xd8, 0xaa, 0xa9, 0xa7, 0xac, 0xab, 0xa9,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xae, 0xad, 0xab, 0xa4, 0xa5, 0xa4, 0xca, 0xbb, 0xac,
  0xe0, 0xc9, 0xb0, 0xd1, 0xca, 0xc1, 0xa1, 0xa4, 0xa6, 0x92, 0x65, 0x45,
  0xd1, 0x8d, 0x35, 0xee, 0xa3, 0x2a, 0xe5, 0xb1, 0x60, 0xc3, 0xbd, 0xb4,
  0xe3, 0xd6, 0xc5, 0x00, 0x00, 0x00, 0x7e, 0x7c, 0x79, 0x8a, 0x88, 0x85,
  0x85, 0x83, 0x81, 0x22, 0x20, 0x1d, 0x91, 0x90, 0x8c, 0xc0, 0xbf, 0xbd,
  0xd3, 0xd3, 0xd2, 0xbc, 0xbb, 0xba, 0x85, 0x84, 0x81, 0x90, 0x8f, 0x8d,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xae, 0xad, 0xaa, 0xa5, 0xa3, 0xa0, 0xc7, 0xc7, 0xc6,
  0xd2, 0xd3, 0xd3, 0xc0, 0xc0, 0xbf, 0x8a, 0x89, 0x87, 0xaa, 0xa7, 0xa5,
  0xd0, 0xc7, 0xbb, 0xde, 0xce, 0xb4, 0xd7, 0xcf, 0xc3, 0xb6, 0xb6, 0xb5,
  0xe4, 0xe4, 0xe4, 0x00, 0x00, 0x00, 0x81, 0x80, 0x7d, 0x8e, 0x8c, 0x88,
  0x89, 0x87, 0x85, 0x82, 0x81, 0x7e, 0x87, 0x85, 0x82, 0x99, 0x97, 0x94,
  0xa0, 0x9e, 0x9b, 0x96, 0x94, 0x92, 0x00, 0x00, 0x00, 0x6d, 0x6c, 0x68,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x89, 0x87, 0x84, 0x85, 0x84, 0x81, 0x9d, 0x9b, 0x98,
  0xa6, 0xa3, 0xa0, 0x9e, 0x9c, 0x9a, 0x53, 0x51, 0x4d, 0x96, 0x94, 0x92,
  0xad, 0xac, 0xaa, 0xb5, 0xb4, 0xb4, 0xb3, 0xb3, 0xb2, 0x9c, 0x9b, 0x99,
  0xaf, 0xae, 0xac, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x8f, 0x8e, 0x8b, 0x84, 0x82, 0x7f, 0xb2, 0xb1, 0xae,
  0xd6, 0xd3, 0xd1, 0xa0, 0x9f, 0x9d, 0x51, 0x50, 0x4c, 0x78, 0x76, 0x73,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x9a, 0x99, 0x96, 0x91, 0x90, 0x8d, 0xff, 0xff, 0xff,
  0x00, 0x00, 0x00, 0xda, 0xdb, 0xda, 0x73, 0x71, 0x6d, 0x5c, 0x59, 0x55,
  0x78, 0x75, 0x71, 0x84, 0x80, 0x7c, 0x7d, 0x7b, 0x77, 0x00, 0x00, 0x00,
  0x52, 0x51, 0x4d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

};


#endif //UNICORN_FUN__HPP