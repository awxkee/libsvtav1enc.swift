/*
* Copyright(c) 2020 Intel Corporation
*
* This source code is subject to the terms of the BSD 2 Clause License and
* the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
* was not distributed with this source code in the LICENSE file, you can
* obtain it at https://www.aomedia.org/license/software-license. If the Alliance for Open
* Media Patent License 1.0 was not distributed with this source code in the
* PATENTS file, you can obtain it at https://www.aomedia.org/license/patent-license.
*/


/*
* This file contains only debug macros that are used during the development
* and are supposed to be cleaned up every tag cycle
* all macros must have the following format:
* - adding a new feature should be prefixed by FTR_
* - tuning a feature should be prefixed by TUNE_
* - enabling a feature should be prefixed by EN_
* - disabling a feature should be prefixed by DIS_
* - bug fixes should be prefixed by FIX_
* - code refactors should be prefixed by RFCTR_
* - code cleanups should be prefixed by CLN_
* - all macros must have a coherent comment explaining what the MACRO is doing
* - #if 0 / #if 1 are not to be used
*/


#ifndef EbDebugMacros_h
#define EbDebugMacros_h

// clang-format off

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define OPT_TPL_4L              1 // optimize TPL for 4L
#define UPDATE_CDEF_INTRINSICS  1 // Compute CDEF direction for two 8x8 block at a time
#define UPDATE_CDEF_COPY        1 // Add AVX2 intrinsics for copy function in CDEF; combine 8bit/10bit copy funcs
#define CLN_CDEF_FRAME          1 // Merge 8bit/16bit CDEF application functions
#define CLN_CDEF_SEARCH         1 // Merge 8bit/16bit CDEF search functions
#define CLN_RENAME_CDEF_BUFFS   1 // Rename picture buffers storing CDEF input frames
#define CLN_CDEF_BUFFS          1 // Remove unused var from CdefList struct
#define OPT_CDEF_DIR_PAD        1 // Pad cdef directions array for faster accesses
#define TUNE_MDS0_DIST          1 // Use variance as MDS0 distortion metric in M12 and below
#define CLN_REST                1 // Cleanup signaling for loop restoration filtering and remove unnecessary operations
#define FTR_REST_LUMA_ONLY      1 // Allow restoration filtering to be performed for luma only
#define OPT_PRED_ONLY           1 // Use pred depth only shortcuts when depth refinement selects pred depth only (not only when it's forced at the pic level)
#define EN_REST_M8_M9           1 // Enable restoration in M8/M9; enable LPD1 in M9 to compensate for speed loss
#define OPT_LPD0                1 // Add detector to LPD0 for all levels
#define CLN_REST_2              1 // Cleanup restoration signalling


#define FTR_FORCE_KF            1 // Add the ability to force key frames from ffpmeg cli
//FOR DEBUGGING - Do not remove
#define LOG_ENC_DONE            0 // log encoder job one
#define NO_ENCDEC               0 // bypass encDec to test cmpliance of MD. complained achieved when skip_flag is OFF. Port sample code from VCI-SW_AV1_Candidate1 branch
#define DEBUG_TPL               0 // Prints to debug TPL
#define DETAILED_FRAME_OUTPUT   0 // Prints detailed frame output from the library for debugging
#define TUNE_CHROMA_SSIM        0 // Allows for Chroma and SSIM BDR-based Tuning

#define MIN_PIC_PARALLELIZATION 0 // Use the minimum amount of picture parallelization
#define SRM_REPORT              0 // Report SRM status
#define LAD_MG_PRINT            0 // Report LAD
#define RC_NO_R2R               0 // This is a debugging flag for RC and makes encoder to run with no R2R in RC mode
                                  // Note that the speed might impacted significantly
#if RC_NO_R2R
#define REMOVE_LP1_LPN_DIFF     1 // Disallow single-thread/multi-thread differences
#else
#define REMOVE_LP1_LPN_DIFF     0 // Disallow single-thread/multi-thread differences
#endif
// Super-resolution debugging code
#define DEBUG_SCALING           0
#define DEBUG_TF                0
#define DEBUG_UPSCALING         0
#define DEBUG_SUPERRES_RECODE   0
#define DEBUG_SUPERRES_ENERGY   0
#define DEBUG_RC_CAP_LOG        0 // Prints for RC cap

// Switch frame debugging code
#define DEBUG_SFRAME            0

#ifdef __cplusplus
}
#endif // __cplusplus

// clang-format on

#endif // EbDebugMacros_h
