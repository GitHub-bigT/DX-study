 /***************************************************************************\
|*                                                                           *|
|*      Copyright 2005-2010 NVIDIA Corporation.  All rights reserved.        *|
|*                                                                           *|
|*   NOTICE TO USER:                                                         *|
|*                                                                           *|
|*   This source code is subject to NVIDIA ownership rights under U.S.       *|
|*   and international Copyright laws.                                       *|
|*                                                                           *|
|*   This software and the information contained herein is PROPRIETARY       *|
|*   and CONFIDENTIAL to NVIDIA and is being provided under the terms        *|
|*   and conditions of a Non-Disclosure Agreement. Any reproduction or       *|
|*   disclosure to any third party without the express written consent of    *|
|*   NVIDIA is prohibited.                                                   *|
|*                                                                           *|
|*   NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE     *|
|*   CODE FOR ANY PURPOSE. IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR         *|
|*   IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH     *|
|*   REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF         *|
|*   MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR          *|
|*   PURPOSE. IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL,            *|
|*   INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES          *|
|*   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN      *|
|*   AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING     *|
|*   OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOURCE      *|
|*   CODE.                                                                   *|
|*                                                                           *|
|*   U.S. Government End Users. This source code is a "commercial item"      *|
|*   as that term is defined at 48 C.F.R. 2.101 (OCT 1995), consisting       *| 
|*   of "commercial computer software" and "commercial computer software     *|
|*   documentation" as such terms are used in 48 C.F.R. 12.212 (SEPT 1995)   *|
|*   and is provided to the U.S. Government only as a commercial end item.   *|
|*   Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through        *|
|*   227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the       *|
|*   source code with only those rights set forth herein.                    *|
|*                                                                           *|
|*                                                                           *|
 \***************************************************************************/
///////////////////////////////////////////////////////////////////////////////
//
// Date: Jun 5, 2011
// File: nvapi.h
//
// NvAPI provides an interface to NVIDIA devices. This file contains the 
// interface constants, structure definitions and function prototypes.
//
//   Target Profile: NDA-developer
//  Target Platform: windows
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _NVAPI_H
#define _NVAPI_H

#pragma pack(push,8) // Make sure we have consistent structure packings

#ifdef __cplusplus
extern "C" {
#endif

// ====================================================
// Universal NvAPI Definitions
// ====================================================
#ifndef _WIN32
#define __cdecl
#endif

// ====================================================
// SAL related support
// ====================================================
#ifndef __ecount
    #define __nvapi_undef__ecount
    #define __ecount(size)
#endif
#ifndef __bcount
    #define __nvapi_undef__bcount
    #define __bcount(size)
#endif
#ifndef __in
    #define __nvapi_undef__in
    #define __in
#endif
#ifndef __in_ecount
    #define __nvapi_undef__in_ecount
    #define __in_ecount(size)
#endif
#ifndef __in_bcount
    #define __nvapi_undef__in_bcount
    #define __in_bcount(size)
#endif
#ifndef __in_z
    #define __nvapi_undef__in_z
    #define __in_z
#endif
#ifndef __in_ecount_z
    #define __nvapi_undef__in_ecount_z
    #define __in_ecount_z(size)
#endif
#ifndef __in_bcount_z
    #define __nvapi_undef__in_bcount_z
    #define __in_bcount_z(size)
#endif
#ifndef __in_nz
    #define __nvapi_undef__in_nz
    #define __in_nz
#endif
#ifndef __in_ecount_nz
    #define __nvapi_undef__in_ecount_nz
    #define __in_ecount_nz(size)
#endif
#ifndef __in_bcount_nz
    #define __nvapi_undef__in_bcount_nz
    #define __in_bcount_nz(size)
#endif
#ifndef __out
    #define __nvapi_undef__out
    #define __out
#endif
#ifndef __out_ecount
    #define __nvapi_undef__out_ecount
    #define __out_ecount(size)
#endif
#ifndef __out_bcount
    #define __nvapi_undef__out_bcount
    #define __out_bcount(size)
#endif
#ifndef __out_ecount_part
    #define __nvapi_undef__out_ecount_part
    #define __out_ecount_part(size,length)
#endif
#ifndef __out_bcount_part
    #define __nvapi_undef__out_bcount_part
    #define __out_bcount_part(size,length)
#endif
#ifndef __out_ecount_full
    #define __nvapi_undef__out_ecount_full
    #define __out_ecount_full(size)
#endif
#ifndef __out_bcount_full
    #define __nvapi_undef__out_bcount_full
    #define __out_bcount_full(size)
#endif
#ifndef __out_z
    #define __nvapi_undef__out_z
    #define __out_z
#endif
#ifndef __out_z_opt
    #define __nvapi_undef__out_z_opt
    #define __out_z_opt
#endif
#ifndef __out_ecount_z
    #define __nvapi_undef__out_ecount_z
    #define __out_ecount_z(size)
#endif
#ifndef __out_bcount_z
    #define __nvapi_undef__out_bcount_z
    #define __out_bcount_z(size)
#endif
#ifndef __out_ecount_part_z
    #define __nvapi_undef__out_ecount_part_z
    #define __out_ecount_part_z(size,length)
#endif
#ifndef __out_bcount_part_z
    #define __nvapi_undef__out_bcount_part_z
    #define __out_bcount_part_z(size,length)
#endif
#ifndef __out_ecount_full_z
    #define __nvapi_undef__out_ecount_full_z
    #define __out_ecount_full_z(size)
#endif
#ifndef __out_bcount_full_z
    #define __nvapi_undef__out_bcount_full_z
    #define __out_bcount_full_z(size)
#endif
#ifndef __out_nz
    #define __nvapi_undef__out_nz
    #define __out_nz
#endif
#ifndef __out_nz_opt
    #define __nvapi_undef__out_nz_opt
    #define __out_nz_opt
#endif
#ifndef __out_ecount_nz
    #define __nvapi_undef__out_ecount_nz
    #define __out_ecount_nz(size)
#endif
#ifndef __out_bcount_nz
    #define __nvapi_undef__out_bcount_nz
    #define __out_bcount_nz(size)
#endif
#ifndef __inout
    #define __nvapi_undef__inout
    #define __inout
#endif
#ifndef __inout_ecount
    #define __nvapi_undef__inout_ecount
    #define __inout_ecount(size)
#endif
#ifndef __inout_bcount
    #define __nvapi_undef__inout_bcount
    #define __inout_bcount(size)
#endif
#ifndef __inout_ecount_part
    #define __nvapi_undef__inout_ecount_part
    #define __inout_ecount_part(size,length)
#endif
#ifndef __inout_bcount_part
    #define __nvapi_undef__inout_bcount_part
    #define __inout_bcount_part(size,length)
#endif
#ifndef __inout_ecount_full
    #define __nvapi_undef__inout_ecount_full
    #define __inout_ecount_full(size)
#endif
#ifndef __inout_bcount_full
    #define __nvapi_undef__inout_bcount_full
    #define __inout_bcount_full(size)
#endif
#ifndef __inout_z
    #define __nvapi_undef__inout_z
    #define __inout_z
#endif
#ifndef __inout_ecount_z
    #define __nvapi_undef__inout_ecount_z
    #define __inout_ecount_z(size)
#endif
#ifndef __inout_bcount_z
    #define __nvapi_undef__inout_bcount_z
    #define __inout_bcount_z(size)
#endif
#ifndef __inout_nz
    #define __nvapi_undef__inout_nz
    #define __inout_nz
#endif
#ifndef __inout_ecount_nz
    #define __nvapi_undef__inout_ecount_nz
    #define __inout_ecount_nz(size)
#endif
#ifndef __inout_bcount_nz
    #define __nvapi_undef__inout_bcount_nz
    #define __inout_bcount_nz(size)
#endif
#ifndef __ecount_opt
    #define __nvapi_undef__ecount_opt
    #define __ecount_opt(size)
#endif
#ifndef __bcount_opt
    #define __nvapi_undef__bcount_opt
    #define __bcount_opt(size)
#endif
#ifndef __in_opt
    #define __nvapi_undef__in_opt
    #define __in_opt
#endif
#ifndef __in_ecount_opt
    #define __nvapi_undef__in_ecount_opt
    #define __in_ecount_opt(size)
#endif
#ifndef __in_bcount_opt
    #define __nvapi_undef__in_bcount_opt
    #define __in_bcount_opt(size)
#endif
#ifndef __in_z_opt
    #define __nvapi_undef__in_z_opt
    #define __in_z_opt
#endif
#ifndef __in_ecount_z_opt
    #define __nvapi_undef__in_ecount_z_opt
    #define __in_ecount_z_opt(size)
#endif
#ifndef __in_bcount_z_opt
    #define __nvapi_undef__in_bcount_z_opt
    #define __in_bcount_z_opt(size)
#endif
#ifndef __in_nz_opt
    #define __nvapi_undef__in_nz_opt
    #define __in_nz_opt
#endif
#ifndef __in_ecount_nz_opt
    #define __nvapi_undef__in_ecount_nz_opt
    #define __in_ecount_nz_opt(size)
#endif
#ifndef __in_bcount_nz_opt
    #define __nvapi_undef__in_bcount_nz_opt
    #define __in_bcount_nz_opt(size)
#endif
#ifndef __out_opt
    #define __nvapi_undef__out_opt
    #define __out_opt
#endif
#ifndef __out_ecount_opt
    #define __nvapi_undef__out_ecount_opt
    #define __out_ecount_opt(size)
#endif
#ifndef __out_bcount_opt
    #define __nvapi_undef__out_bcount_opt
    #define __out_bcount_opt(size)
#endif
#ifndef __out_ecount_part_opt
    #define __nvapi_undef__out_ecount_part_opt
    #define __out_ecount_part_opt(size,length)
#endif
#ifndef __out_bcount_part_opt
    #define __nvapi_undef__out_bcount_part_opt
    #define __out_bcount_part_opt(size,length)
#endif
#ifndef __out_ecount_full_opt
    #define __nvapi_undef__out_ecount_full_opt
    #define __out_ecount_full_opt(size)
#endif
#ifndef __out_bcount_full_opt
    #define __nvapi_undef__out_bcount_full_opt
    #define __out_bcount_full_opt(size)
#endif
#ifndef __out_ecount_z_opt
    #define __nvapi_undef__out_ecount_z_opt
    #define __out_ecount_z_opt(size)
#endif
#ifndef __out_bcount_z_opt
    #define __nvapi_undef__out_bcount_z_opt
    #define __out_bcount_z_opt(size)
#endif
#ifndef __out_ecount_part_z_opt
    #define __nvapi_undef__out_ecount_part_z_opt
    #define __out_ecount_part_z_opt(size,length)
#endif
#ifndef __out_bcount_part_z_opt
    #define __nvapi_undef__out_bcount_part_z_opt
    #define __out_bcount_part_z_opt(size,length)
#endif
#ifndef __out_ecount_full_z_opt
    #define __nvapi_undef__out_ecount_full_z_opt
    #define __out_ecount_full_z_opt(size)
#endif
#ifndef __out_bcount_full_z_opt
    #define __nvapi_undef__out_bcount_full_z_opt
    #define __out_bcount_full_z_opt(size)
#endif
#ifndef __out_ecount_nz_opt
    #define __nvapi_undef__out_ecount_nz_opt
    #define __out_ecount_nz_opt(size)
#endif
#ifndef __out_bcount_nz_opt
    #define __nvapi_undef__out_bcount_nz_opt
    #define __out_bcount_nz_opt(size)
#endif
#ifndef __inout_opt
    #define __nvapi_undef__inout_opt
    #define __inout_opt
#endif
#ifndef __inout_ecount_opt
    #define __nvapi_undef__inout_ecount_opt
    #define __inout_ecount_opt(size)
#endif
#ifndef __inout_bcount_opt
    #define __nvapi_undef__inout_bcount_opt
    #define __inout_bcount_opt(size)
#endif
#ifndef __inout_ecount_part_opt
    #define __nvapi_undef__inout_ecount_part_opt
    #define __inout_ecount_part_opt(size,length)
#endif
#ifndef __inout_bcount_part_opt
    #define __nvapi_undef__inout_bcount_part_opt
    #define __inout_bcount_part_opt(size,length)
#endif
#ifndef __inout_ecount_full_opt
    #define __nvapi_undef__inout_ecount_full_opt
    #define __inout_ecount_full_opt(size)
#endif
#ifndef __inout_bcount_full_opt
    #define __nvapi_undef__inout_bcount_full_opt
    #define __inout_bcount_full_opt(size)
#endif
#ifndef __inout_z_opt
    #define __nvapi_undef__inout_z_opt
    #define __inout_z_opt
#endif
#ifndef __inout_ecount_z_opt
    #define __nvapi_undef__inout_ecount_z_opt
    #define __inout_ecount_z_opt(size)
#endif
#ifndef __inout_ecount_z_opt
    #define __nvapi_undef__inout_ecount_z_opt
    #define __inout_ecount_z_opt(size)
#endif
#ifndef __inout_bcount_z_opt
    #define __nvapi_undef__inout_bcount_z_opt
    #define __inout_bcount_z_opt(size)
#endif
#ifndef __inout_nz_opt
    #define __nvapi_undef__inout_nz_opt
    #define __inout_nz_opt
#endif
#ifndef __inout_ecount_nz_opt
    #define __nvapi_undef__inout_ecount_nz_opt
    #define __inout_ecount_nz_opt(size)
#endif
#ifndef __inout_bcount_nz_opt
    #define __nvapi_undef__inout_bcount_nz_opt
    #define __inout_bcount_nz_opt(size)
#endif
#ifndef __deref_ecount
    #define __nvapi_undef__deref_ecount
    #define __deref_ecount(size)
#endif
#ifndef __deref_bcount
    #define __nvapi_undef__deref_bcount
    #define __deref_bcount(size)
#endif
#ifndef __deref_out
    #define __nvapi_undef__deref_out
    #define __deref_out
#endif
#ifndef __deref_out_ecount
    #define __nvapi_undef__deref_out_ecount
    #define __deref_out_ecount(size)
#endif
#ifndef __deref_out_bcount
    #define __nvapi_undef__deref_out_bcount
    #define __deref_out_bcount(size)
#endif
#ifndef __deref_out_ecount_part
    #define __nvapi_undef__deref_out_ecount_part
    #define __deref_out_ecount_part(size,length)
#endif
#ifndef __deref_out_bcount_part
    #define __nvapi_undef__deref_out_bcount_part
    #define __deref_out_bcount_part(size,length)
#endif
#ifndef __deref_out_ecount_full
    #define __nvapi_undef__deref_out_ecount_full
    #define __deref_out_ecount_full(size)
#endif
#ifndef __deref_out_bcount_full
    #define __nvapi_undef__deref_out_bcount_full
    #define __deref_out_bcount_full(size)
#endif
#ifndef __deref_out_z
    #define __nvapi_undef__deref_out_z
    #define __deref_out_z
#endif
#ifndef __deref_out_ecount_z
    #define __nvapi_undef__deref_out_ecount_z
    #define __deref_out_ecount_z(size)
#endif
#ifndef __deref_out_bcount_z
    #define __nvapi_undef__deref_out_bcount_z
    #define __deref_out_bcount_z(size)
#endif
#ifndef __deref_out_nz
    #define __nvapi_undef__deref_out_nz
    #define __deref_out_nz
#endif
#ifndef __deref_out_ecount_nz
    #define __nvapi_undef__deref_out_ecount_nz
    #define __deref_out_ecount_nz(size)
#endif
#ifndef __deref_out_bcount_nz
    #define __nvapi_undef__deref_out_bcount_nz
    #define __deref_out_bcount_nz(size)
#endif
#ifndef __deref_inout
    #define __nvapi_undef__deref_inout
    #define __deref_inout
#endif
#ifndef __deref_inout_z
    #define __nvapi_undef__deref_inout_z
    #define __deref_inout_z
#endif
#ifndef __deref_inout_ecount
    #define __nvapi_undef__deref_inout_ecount
    #define __deref_inout_ecount(size)
#endif
#ifndef __deref_inout_bcount
    #define __nvapi_undef__deref_inout_bcount
    #define __deref_inout_bcount(size)
#endif
#ifndef __deref_inout_ecount_part
    #define __nvapi_undef__deref_inout_ecount_part
    #define __deref_inout_ecount_part(size,length)
#endif
#ifndef __deref_inout_bcount_part
    #define __nvapi_undef__deref_inout_bcount_part
    #define __deref_inout_bcount_part(size,length)
#endif
#ifndef __deref_inout_ecount_full
    #define __nvapi_undef__deref_inout_ecount_full
    #define __deref_inout_ecount_full(size)
#endif
#ifndef __deref_inout_bcount_full
    #define __nvapi_undef__deref_inout_bcount_full
    #define __deref_inout_bcount_full(size)
#endif
#ifndef __deref_inout_z
    #define __nvapi_undef__deref_inout_z
    #define __deref_inout_z
#endif
#ifndef __deref_inout_ecount_z
    #define __nvapi_undef__deref_inout_ecount_z
    #define __deref_inout_ecount_z(size)
#endif
#ifndef __deref_inout_bcount_z
    #define __nvapi_undef__deref_inout_bcount_z
    #define __deref_inout_bcount_z(size)
#endif
#ifndef __deref_inout_nz
    #define __nvapi_undef__deref_inout_nz
    #define __deref_inout_nz
#endif
#ifndef __deref_inout_ecount_nz
    #define __nvapi_undef__deref_inout_ecount_nz
    #define __deref_inout_ecount_nz(size)
#endif
#ifndef __deref_inout_bcount_nz
    #define __nvapi_undef__deref_inout_bcount_nz
    #define __deref_inout_bcount_nz(size)
#endif
#ifndef __deref_ecount_opt
    #define __nvapi_undef__deref_ecount_opt
    #define __deref_ecount_opt(size)
#endif
#ifndef __deref_bcount_opt
    #define __nvapi_undef__deref_bcount_opt
    #define __deref_bcount_opt(size)
#endif
#ifndef __deref_out_opt
    #define __nvapi_undef__deref_out_opt
    #define __deref_out_opt
#endif
#ifndef __deref_out_ecount_opt
    #define __nvapi_undef__deref_out_ecount_opt
    #define __deref_out_ecount_opt(size)
#endif
#ifndef __deref_out_bcount_opt
    #define __nvapi_undef__deref_out_bcount_opt
    #define __deref_out_bcount_opt(size)
#endif
#ifndef __deref_out_ecount_part_opt
    #define __nvapi_undef__deref_out_ecount_part_opt
    #define __deref_out_ecount_part_opt(size,length)
#endif
#ifndef __deref_out_bcount_part_opt
    #define __nvapi_undef__deref_out_bcount_part_opt
    #define __deref_out_bcount_part_opt(size,length)
#endif
#ifndef __deref_out_ecount_full_opt
    #define __nvapi_undef__deref_out_ecount_full_opt
    #define __deref_out_ecount_full_opt(size)
#endif
#ifndef __deref_out_bcount_full_opt
    #define __nvapi_undef__deref_out_bcount_full_opt
    #define __deref_out_bcount_full_opt(size)
#endif
#ifndef __deref_out_z_opt
    #define __nvapi_undef__deref_out_z_opt
    #define __deref_out_z_opt
#endif
#ifndef __deref_out_ecount_z_opt
    #define __nvapi_undef__deref_out_ecount_z_opt
    #define __deref_out_ecount_z_opt(size)
#endif
#ifndef __deref_out_bcount_z_opt
    #define __nvapi_undef__deref_out_bcount_z_opt
    #define __deref_out_bcount_z_opt(size)
#endif
#ifndef __deref_out_nz_opt
    #define __nvapi_undef__deref_out_nz_opt
    #define __deref_out_nz_opt
#endif
#ifndef __deref_out_ecount_nz_opt
    #define __nvapi_undef__deref_out_ecount_nz_opt
    #define __deref_out_ecount_nz_opt(size)
#endif
#ifndef __deref_out_bcount_nz_opt
    #define __nvapi_undef__deref_out_bcount_nz_opt
    #define __deref_out_bcount_nz_opt(size)
#endif
#ifndef __deref_inout_opt
    #define __nvapi_undef__deref_inout_opt
    #define __deref_inout_opt
#endif
#ifndef __deref_inout_ecount_opt
    #define __nvapi_undef__deref_inout_ecount_opt
    #define __deref_inout_ecount_opt(size)
#endif
#ifndef __deref_inout_bcount_opt
    #define __nvapi_undef__deref_inout_bcount_opt
    #define __deref_inout_bcount_opt(size)
#endif
#ifndef __deref_inout_ecount_part_opt
    #define __nvapi_undef__deref_inout_ecount_part_opt
    #define __deref_inout_ecount_part_opt(size,length)
#endif
#ifndef __deref_inout_bcount_part_opt
    #define __nvapi_undef__deref_inout_bcount_part_opt
    #define __deref_inout_bcount_part_opt(size,length)
#endif
#ifndef __deref_inout_ecount_full_opt
    #define __nvapi_undef__deref_inout_ecount_full_opt
    #define __deref_inout_ecount_full_opt(size)
#endif
#ifndef __deref_inout_bcount_full_opt
    #define __nvapi_undef__deref_inout_bcount_full_opt
    #define __deref_inout_bcount_full_opt(size)
#endif
#ifndef __deref_inout_z_opt
    #define __nvapi_undef__deref_inout_z_opt
    #define __deref_inout_z_opt
#endif
#ifndef __deref_inout_ecount_z_opt
    #define __nvapi_undef__deref_inout_ecount_z_opt
    #define __deref_inout_ecount_z_opt(size)
#endif
#ifndef __deref_inout_bcount_z_opt
    #define __nvapi_undef__deref_inout_bcount_z_opt
    #define __deref_inout_bcount_z_opt(size)
#endif
#ifndef __deref_inout_nz_opt
    #define __nvapi_undef__deref_inout_nz_opt
    #define __deref_inout_nz_opt
#endif
#ifndef __deref_inout_ecount_nz_opt
    #define __nvapi_undef__deref_inout_ecount_nz_opt
    #define __deref_inout_ecount_nz_opt(size)
#endif
#ifndef __deref_inout_bcount_nz_opt
    #define __nvapi_undef__deref_inout_bcount_nz_opt
    #define __deref_inout_bcount_nz_opt(size)
#endif
#ifndef __deref_opt_ecount
    #define __nvapi_undef__deref_opt_ecount
    #define __deref_opt_ecount(size)
#endif
#ifndef __deref_opt_bcount
    #define __nvapi_undef__deref_opt_bcount
    #define __deref_opt_bcount(size)
#endif
#ifndef __deref_opt_out
    #define __nvapi_undef__deref_opt_out
    #define __deref_opt_out
#endif
#ifndef __deref_opt_out_z
    #define __nvapi_undef__deref_opt_out_z
    #define __deref_opt_out_z
#endif
#ifndef __deref_opt_out_ecount
    #define __nvapi_undef__deref_opt_out_ecount
    #define __deref_opt_out_ecount(size)
#endif
#ifndef __deref_opt_out_bcount
    #define __nvapi_undef__deref_opt_out_bcount
    #define __deref_opt_out_bcount(size)
#endif
#ifndef __deref_opt_out_ecount_part
    #define __nvapi_undef__deref_opt_out_ecount_part
    #define __deref_opt_out_ecount_part(size,length)
#endif
#ifndef __deref_opt_out_bcount_part
    #define __nvapi_undef__deref_opt_out_bcount_part
    #define __deref_opt_out_bcount_part(size,length)
#endif
#ifndef __deref_opt_out_ecount_full
    #define __nvapi_undef__deref_opt_out_ecount_full
    #define __deref_opt_out_ecount_full(size)
#endif
#ifndef __deref_opt_out_bcount_full
    #define __nvapi_undef__deref_opt_out_bcount_full
    #define __deref_opt_out_bcount_full(size)
#endif
#ifndef __deref_opt_inout
    #define __nvapi_undef__deref_opt_inout
    #define __deref_opt_inout
#endif
#ifndef __deref_opt_inout_ecount
    #define __nvapi_undef__deref_opt_inout_ecount
    #define __deref_opt_inout_ecount(size)
#endif
#ifndef __deref_opt_inout_bcount
    #define __nvapi_undef__deref_opt_inout_bcount
    #define __deref_opt_inout_bcount(size)
#endif
#ifndef __deref_opt_inout_ecount_part
    #define __nvapi_undef__deref_opt_inout_ecount_part
    #define __deref_opt_inout_ecount_part(size,length)
#endif
#ifndef __deref_opt_inout_bcount_part
    #define __nvapi_undef__deref_opt_inout_bcount_part
    #define __deref_opt_inout_bcount_part(size,length)
#endif
#ifndef __deref_opt_inout_ecount_full
    #define __nvapi_undef__deref_opt_inout_ecount_full
    #define __deref_opt_inout_ecount_full(size)
#endif
#ifndef __deref_opt_inout_bcount_full
    #define __nvapi_undef__deref_opt_inout_bcount_full
    #define __deref_opt_inout_bcount_full(size)
#endif
#ifndef __deref_opt_inout_z
    #define __nvapi_undef__deref_opt_inout_z
    #define __deref_opt_inout_z
#endif
#ifndef __deref_opt_inout_ecount_z
    #define __nvapi_undef__deref_opt_inout_ecount_z
    #define __deref_opt_inout_ecount_z(size)
#endif
#ifndef __deref_opt_inout_bcount_z
    #define __nvapi_undef__deref_opt_inout_bcount_z
    #define __deref_opt_inout_bcount_z(size)
#endif
#ifndef __deref_opt_inout_nz
    #define __nvapi_undef__deref_opt_inout_nz
    #define __deref_opt_inout_nz
#endif
#ifndef __deref_opt_inout_ecount_nz
    #define __nvapi_undef__deref_opt_inout_ecount_nz
    #define __deref_opt_inout_ecount_nz(size)
#endif
#ifndef __deref_opt_inout_bcount_nz
    #define __nvapi_undef__deref_opt_inout_bcount_nz
    #define __deref_opt_inout_bcount_nz(size)
#endif
#ifndef __deref_opt_ecount_opt
    #define __nvapi_undef__deref_opt_ecount_opt
    #define __deref_opt_ecount_opt(size)
#endif
#ifndef __deref_opt_bcount_opt
    #define __nvapi_undef__deref_opt_bcount_opt
    #define __deref_opt_bcount_opt(size)
#endif
#ifndef __deref_opt_out_opt
    #define __nvapi_undef__deref_opt_out_opt
    #define __deref_opt_out_opt
#endif
#ifndef __deref_opt_out_ecount_opt
    #define __nvapi_undef__deref_opt_out_ecount_opt
    #define __deref_opt_out_ecount_opt(size)
#endif
#ifndef __deref_opt_out_bcount_opt
    #define __nvapi_undef__deref_opt_out_bcount_opt
    #define __deref_opt_out_bcount_opt(size)
#endif
#ifndef __deref_opt_out_ecount_part_opt
    #define __nvapi_undef__deref_opt_out_ecount_part_opt
    #define __deref_opt_out_ecount_part_opt(size,length)
#endif
#ifndef __deref_opt_out_bcount_part_opt
    #define __nvapi_undef__deref_opt_out_bcount_part_opt
    #define __deref_opt_out_bcount_part_opt(size,length)
#endif
#ifndef __deref_opt_out_ecount_full_opt
    #define __nvapi_undef__deref_opt_out_ecount_full_opt
    #define __deref_opt_out_ecount_full_opt(size)
#endif
#ifndef __deref_opt_out_bcount_full_opt
    #define __nvapi_undef__deref_opt_out_bcount_full_opt
    #define __deref_opt_out_bcount_full_opt(size)
#endif
#ifndef __deref_opt_out_z_opt
    #define __nvapi_undef__deref_opt_out_z_opt
    #define __deref_opt_out_z_opt
#endif
#ifndef __deref_opt_out_ecount_z_opt
    #define __nvapi_undef__deref_opt_out_ecount_z_opt
    #define __deref_opt_out_ecount_z_opt(size)
#endif
#ifndef __deref_opt_out_bcount_z_opt
    #define __nvapi_undef__deref_opt_out_bcount_z_opt
    #define __deref_opt_out_bcount_z_opt(size)
#endif
#ifndef __deref_opt_out_nz_opt
    #define __nvapi_undef__deref_opt_out_nz_opt
    #define __deref_opt_out_nz_opt
#endif
#ifndef __deref_opt_out_ecount_nz_opt
    #define __nvapi_undef__deref_opt_out_ecount_nz_opt
    #define __deref_opt_out_ecount_nz_opt(size)
#endif
#ifndef __deref_opt_out_bcount_nz_opt
    #define __nvapi_undef__deref_opt_out_bcount_nz_opt
    #define __deref_opt_out_bcount_nz_opt(size)
#endif
#ifndef __deref_opt_inout_opt
    #define __nvapi_undef__deref_opt_inout_opt
    #define __deref_opt_inout_opt
#endif
#ifndef __deref_opt_inout_ecount_opt
    #define __nvapi_undef__deref_opt_inout_ecount_opt
    #define __deref_opt_inout_ecount_opt(size)
#endif
#ifndef __deref_opt_inout_bcount_opt
    #define __nvapi_undef__deref_opt_inout_bcount_opt
    #define __deref_opt_inout_bcount_opt(size)
#endif
#ifndef __deref_opt_inout_ecount_part_opt
    #define __nvapi_undef__deref_opt_inout_ecount_part_opt
    #define __deref_opt_inout_ecount_part_opt(size,length)
#endif
#ifndef __deref_opt_inout_bcount_part_opt
    #define __nvapi_undef__deref_opt_inout_bcount_part_opt
    #define __deref_opt_inout_bcount_part_opt(size,length)
#endif
#ifndef __deref_opt_inout_ecount_full_opt
    #define __nvapi_undef__deref_opt_inout_ecount_full_opt
    #define __deref_opt_inout_ecount_full_opt(size)
#endif
#ifndef __deref_opt_inout_bcount_full_opt
    #define __nvapi_undef__deref_opt_inout_bcount_full_opt
    #define __deref_opt_inout_bcount_full_opt(size)
#endif
#ifndef __deref_opt_inout_z_opt
    #define __nvapi_undef__deref_opt_inout_z_opt
    #define __deref_opt_inout_z_opt
#endif
#ifndef __deref_opt_inout_ecount_z_opt
    #define __nvapi_undef__deref_opt_inout_ecount_z_opt
    #define __deref_opt_inout_ecount_z_opt(size)
#endif
#ifndef __deref_opt_inout_bcount_z_opt
    #define __nvapi_undef__deref_opt_inout_bcount_z_opt
    #define __deref_opt_inout_bcount_z_opt(size)
#endif
#ifndef __deref_opt_inout_nz_opt
    #define __nvapi_undef__deref_opt_inout_nz_opt
    #define __deref_opt_inout_nz_opt
#endif
#ifndef __deref_opt_inout_ecount_nz_opt
    #define __nvapi_undef__deref_opt_inout_ecount_nz_opt
    #define __deref_opt_inout_ecount_nz_opt(size)
#endif
#ifndef __deref_opt_inout_bcount_nz_opt
    #define __nvapi_undef__deref_opt_inout_bcount_nz_opt
    #define __deref_opt_inout_bcount_nz_opt(size)
#endif


#define NVAPI_INTERFACE extern NvAPI_Status __cdecl

#if defined(WIN32) || defined(_WIN32)
#define __nvapi_deprecated_function(NewFunction, FirstRelease) __declspec(deprecated("Do not use this function - it is deprecated in release " #FirstRelease ". Instead, use " #NewFunction "."))
#define __nvapi_deprecated_datatype(FirstRelease) __declspec(deprecated("Do not use this data type - it is deprecated in release " #FirstRelease "."))
#else
#define __nvapi_deprecated_function(NewFunction, FirstRelease)
#define __nvapi_deprecated_datatype(FirstRelease)
#endif


/* 64-bit types for compilers that support them, plus some obsolete variants */
#if defined(__GNUC__) || defined(__arm) || defined(__IAR_SYSTEMS_ICC__) || defined(__ghs__) || defined(_WIN64)
typedef unsigned long long NvU64; /* 0 to 18446744073709551615  */
#else
typedef unsigned __int64   NvU64; /* 0 to 18446744073709551615  */
#endif

// mac os 32-bit still needs this
#if (defined(macintosh) || defined(__APPLE__)) && !defined(__LP64__)
typedef signed long        NvS32; /* -2147483648 to 2147483647  */   
#else
typedef signed int         NvS32; /* -2147483648 to 2147483647 */  
#endif

// mac os 32-bit still needs this
#if ( (defined(macintosh) && defined(__LP64__) && (__NVAPI_RESERVED0__)) || \
      (!defined(macintosh) && defined(__NVAPI_RESERVED0__)) ) 
typedef unsigned int       NvU32; /* 0 to 4294967295                         */
#else
typedef unsigned long      NvU32; /* 0 to 4294967295                         */
#endif

typedef signed   short   NvS16;
typedef unsigned short   NvU16;
typedef unsigned char    NvU8;


typedef struct _NV_RECT
{
    NvU32    left;
    NvU32    top;
    NvU32    right;
    NvU32    bottom;
} NV_RECT;



#define NV_DECLARE_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__ *name

//! \addtogroup nvapihandles
//! NVAPI Handles - These handles are retrieved from various calls and passed in to others in NvAPI
//!                 These are meant to be opaque types.  Do not assume they correspond to indices, HDCs,
//!                 display indexes or anything else.
//!
//!                 Most handles remain valid until a display re-configuration (display mode set) or GPU
//!                 reconfiguration (going into or out of SLI modes) occurs.  If NVAPI_HANDLE_INVALIDATED
//!                 is received by an app, it should discard all handles, and re-enumerate them.
//! @{  
NV_DECLARE_HANDLE(NvDisplayHandle);                //!< Display Device driven by NVIDIA GPU(s) (an attached display)
NV_DECLARE_HANDLE(NvMonitorHandle);                //!< Monitor handle
NV_DECLARE_HANDLE(NvUnAttachedDisplayHandle);      //!< Unattached Display Device driven by NVIDIA GPU(s)
NV_DECLARE_HANDLE(NvLogicalGpuHandle);             //!< One or more physical GPUs acting in concert (SLI)
NV_DECLARE_HANDLE(NvPhysicalGpuHandle);            //!< A single physical GPU
NV_DECLARE_HANDLE(NvEventHandle);                  //!< A handle to an event registration instance
NV_DECLARE_HANDLE(NvVisualComputingDeviceHandle);  //!< A handle to a Visual Computing Device
NV_DECLARE_HANDLE(NvHICHandle);                    //!< A handle to a Host Interface Card
NV_DECLARE_HANDLE(NvGSyncDeviceHandle);            //!< A handle to a G-Sync device
NV_DECLARE_HANDLE(NvVioHandle);                    //!< A handle to an SDI device
NV_DECLARE_HANDLE(NvTransitionHandle);             //!< A handle to address a single transition request
NV_DECLARE_HANDLE(NvAudioHandle);                  //!< NVIDIA HD Audio Device
NV_DECLARE_HANDLE(Nv3DVPContextHandle);            //!< A handle for a 3D Vision Pro (3DVP) context
NV_DECLARE_HANDLE(Nv3DVPTransceiverHandle);        //!< A handle for a 3DVP RF transceiver
NV_DECLARE_HANDLE(Nv3DVPGlassesHandle);            //!< A handle for a pair of 3DVP RF shutter glasses

typedef void* StereoHandle;                        //!< A stereo handle, that corresponds to the device interface

NV_DECLARE_HANDLE(NvSourceHandle);                 //!< Unique source handle on the system
NV_DECLARE_HANDLE(NvTargetHandle);                 //!< Unique target handle on the system
NV_DECLARE_HANDLE(NVDX_SwapChainHandle);           //!< DirectX SwapChain objects
static const NVDX_SwapChainHandle NVDX_SWAPCHAIN_NONE = 0;
//! @}

//! \ingroup nvapihandles
//! @{
#define NVAPI_DEFAULT_HANDLE        0
#define NV_BIT(x)    (1 << (x)) 
//! @}



//! \addtogroup nvapitypes
//! @{
#define NVAPI_GENERIC_STRING_MAX    4096
#define NVAPI_LONG_STRING_MAX       256
#define NVAPI_SHORT_STRING_MAX      64


typedef struct 
{
    NvS32   sX;
    NvS32   sY;
    NvS32   sWidth;
    NvS32   sHeight;
} NvSBox;

#ifndef NvGUID_Defined
#define NvGUID_Defined

typedef struct
{
    NvU32 data1;
    NvU16 data2;
    NvU16 data3;
    NvU8  data4[8];
} NvGUID, NvLUID;

#endif //#ifndef NvGUID_Defined


#define NVAPI_MAX_PHYSICAL_GPUS             64
#define NVAPI_PHYSICAL_GPUS                 32
#define NVAPI_MAX_LOGICAL_GPUS              64
#define NVAPI_MAX_AVAILABLE_GPU_TOPOLOGIES  256
#define NVAPI_MAX_AVAILABLE_SLI_GROUPS      256
#define NVAPI_MAX_GPU_TOPOLOGIES            NVAPI_MAX_PHYSICAL_GPUS
#define NVAPI_MAX_GPU_PER_TOPOLOGY          8
#define NVAPI_MAX_DISPLAY_HEADS             2
#define NVAPI_ADVANCED_DISPLAY_HEADS        4
#define NVAPI_MAX_DISPLAYS                  NVAPI_PHYSICAL_GPUS * NVAPI_ADVANCED_DISPLAY_HEADS
#define NVAPI_MAX_ACPI_IDS                  16
#define NVAPI_MAX_VIEW_MODES                8
#define NV_MAX_HEADS                        4   //!< Maximum heads, each with NVAPI_DESKTOP_RES resolution
#define NVAPI_MAX_HEADS_PER_GPU             32

#define NV_MAX_HEADS        4   //!< Maximum number of heads, each with #NVAPI_DESKTOP_RES resolution
#define NV_MAX_VID_STREAMS  4   //!< Maximum number of input video streams, each with a #NVAPI_VIDEO_SRC_INFO
#define NV_MAX_VID_PROFILES 4   //!< Maximum number of output video profiles supported

#define NVAPI_SYSTEM_MAX_DISPLAYS           NVAPI_MAX_PHYSICAL_GPUS * NV_MAX_HEADS

#define NVAPI_SYSTEM_MAX_HWBCS              128
#define NVAPI_SYSTEM_HWBC_INVALID_ID        0xffffffff
#define NVAPI_MAX_AUDIO_DEVICES             16


typedef char NvAPI_String[NVAPI_GENERIC_STRING_MAX];
typedef char NvAPI_LongString[NVAPI_LONG_STRING_MAX];
typedef char NvAPI_ShortString[NVAPI_SHORT_STRING_MAX];
//! @}


// =========================================================================================
//!  NvAPI Version Definition \n
//!  Maintain per structure specific version define using the MAKE_NVAPI_VERSION macro. \n
//!  Usage: #define NV_GENLOCK_STATUS_VER  MAKE_NVAPI_VERSION(NV_GENLOCK_STATUS, 1)
//!  \ingroup nvapitypes
// =========================================================================================
#define MAKE_NVAPI_VERSION(typeName,ver) (NvU32)(sizeof(typeName) | ((ver)<<16))

//!  \ingroup nvapitypes
#define GET_NVAPI_VERSION(ver) (NvU32)((ver)>>16)

//!  \ingroup nvapitypes
#define GET_NVAPI_SIZE(ver) (NvU32)((ver) & 0xffff)


// ====================================================
//! NvAPI Status Values
//!   All NvAPI functions return one of these codes.
//!   \ingroup nvapistatus 
// ====================================================


typedef enum _NvAPI_Status
{
    NVAPI_OK                                    =  0,      //!< Success. Request is completed.
    NVAPI_ERROR                                 = -1,      //!< Generic error
    NVAPI_LIBRARY_NOT_FOUND                     = -2,      //!< NVAPI support library cannot be loaded.
    NVAPI_NO_IMPLEMENTATION                     = -3,      //!< not implemented in current driver installation
    NVAPI_API_NOT_INITIALIZED                   = -4,      //!< NvAPI_Initialize has not been called (successfully)
    NVAPI_INVALID_ARGUMENT                      = -5,      //!< The argument/parameter value is not valid or NULL.
    NVAPI_NVIDIA_DEVICE_NOT_FOUND               = -6,      //!< No NVIDIA display driver, or NVIDIA GPU driving a display, was found.
    NVAPI_END_ENUMERATION                       = -7,      //!< No more items to enumerate
    NVAPI_INVALID_HANDLE                        = -8,      //!< Invalid handle
    NVAPI_INCOMPATIBLE_STRUCT_VERSION           = -9,      //!< An argument's structure version is not supported
    NVAPI_HANDLE_INVALIDATED                    = -10,     //!< The handle is no longer valid (likely due to GPU or display re-configuration)
    NVAPI_OPENGL_CONTEXT_NOT_CURRENT            = -11,     //!< No NVIDIA OpenGL context is current (but needs to be)
    NVAPI_INVALID_POINTER                       = -14,     //!< An invalid pointer, usually NULL, was passed as a parameter
    NVAPI_NO_GL_EXPERT                          = -12,     //!< OpenGL Expert is not supported by the current drivers
    NVAPI_INSTRUMENTATION_DISABLED              = -13,     //!< OpenGL Expert is supported, but driver instrumentation is currently disabled
    NVAPI_NO_GL_NSIGHT                          = -15,     //!< OpenGL does not support Nsight

    NVAPI_EXPECTED_LOGICAL_GPU_HANDLE           = -100,    //!< Expected a logical GPU handle for one or more parameters
    NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE          = -101,    //!< Expected a physical GPU handle for one or more parameters
    NVAPI_EXPECTED_DISPLAY_HANDLE               = -102,    //!< Expected an NV display handle for one or more parameters
    NVAPI_INVALID_COMBINATION                   = -103,    //!< The combination of parameters is not valid. 
    NVAPI_NOT_SUPPORTED                         = -104,    //!< Requested feature is not supported in the selected GPU
    NVAPI_PORTID_NOT_FOUND                      = -105,    //!< No port ID was found for the I2C transaction
    NVAPI_EXPECTED_UNATTACHED_DISPLAY_HANDLE    = -106,    //!< Expected an unattached display handle as one of the input parameters.
    NVAPI_INVALID_PERF_LEVEL                    = -107,    //!< Invalid perf level 
    NVAPI_DEVICE_BUSY                           = -108,    //!< Device is busy; request not fulfilled
    NVAPI_NV_PERSIST_FILE_NOT_FOUND             = -109,    //!< NV persist file is not found
    NVAPI_PERSIST_DATA_NOT_FOUND                = -110,    //!< NV persist data is not found
    NVAPI_EXPECTED_TV_DISPLAY                   = -111,    //!< Expected a TV output display
    NVAPI_EXPECTED_TV_DISPLAY_ON_DCONNECTOR     = -112,    //!< Expected a TV output on the D Connector - HDTV_EIAJ4120.
    NVAPI_NO_ACTIVE_SLI_TOPOLOGY                = -113,    //!< SLI is not active on this device.
    NVAPI_SLI_RENDERING_MODE_NOTALLOWED         = -114,    //!< Setup of SLI rendering mode is not possible right now.
    NVAPI_EXPECTED_DIGITAL_FLAT_PANEL           = -115,    //!< Expected a digital flat panel.
    NVAPI_ARGUMENT_EXCEED_MAX_SIZE              = -116,    //!< Argument exceeds the expected size.
    NVAPI_DEVICE_SWITCHING_NOT_ALLOWED          = -117,    //!< Inhibit is ON due to one of the flags in NV_GPU_DISPLAY_CHANGE_INHIBIT or SLI active.
    NVAPI_TESTING_CLOCKS_NOT_SUPPORTED          = -118,    //!< Testing of clocks is not supported.
    NVAPI_UNKNOWN_UNDERSCAN_CONFIG              = -119,    //!< The specified underscan config is from an unknown source (e.g. INF)
    NVAPI_TIMEOUT_RECONFIGURING_GPU_TOPO        = -120,    //!< Timeout while reconfiguring GPUs
    NVAPI_DATA_NOT_FOUND                        = -121,    //!< Requested data was not found
    NVAPI_EXPECTED_ANALOG_DISPLAY               = -122,    //!< Expected an analog display
    NVAPI_NO_VIDLINK                            = -123,    //!< No SLI video bridge is present
    NVAPI_REQUIRES_REBOOT                       = -124,    //!< NVAPI requires a reboot for the settings to take effect
    NVAPI_INVALID_HYBRID_MODE                   = -125,    //!< The function is not supported with the current Hybrid mode.
    NVAPI_MIXED_TARGET_TYPES                    = -126,    //!< The target types are not all the same
    NVAPI_SYSWOW64_NOT_SUPPORTED                = -127,    //!< The function is not supported from 32-bit on a 64-bit system.
    NVAPI_IMPLICIT_SET_GPU_TOPOLOGY_CHANGE_NOT_ALLOWED = -128,    //!< There is no implicit GPU topology active. Use NVAPI_SetHybridMode to change topology.
    NVAPI_REQUEST_USER_TO_CLOSE_NON_MIGRATABLE_APPS = -129,      //!< Prompt the user to close all non-migratable applications.    
    NVAPI_OUT_OF_MEMORY                         = -130,    //!< Could not allocate sufficient memory to complete the call.
    NVAPI_WAS_STILL_DRAWING                     = -131,    //!< The previous operation that is transferring information to or from this surface is incomplete.
    NVAPI_FILE_NOT_FOUND                        = -132,    //!< The file was not found.
    NVAPI_TOO_MANY_UNIQUE_STATE_OBJECTS         = -133,    //!< There are too many unique instances of a particular type of state object.
    NVAPI_INVALID_CALL                          = -134,    //!< The method call is invalid. For example, a method's parameter may not be a valid pointer.
    NVAPI_D3D10_1_LIBRARY_NOT_FOUND             = -135,    //!< d3d10_1.dll cannot be loaded.
    NVAPI_FUNCTION_NOT_FOUND                    = -136,    //!< Couldn't find the function in the loaded DLL.
    NVAPI_INVALID_USER_PRIVILEGE                = -137,    //!< Current User is not Admin.
    NVAPI_EXPECTED_NON_PRIMARY_DISPLAY_HANDLE   = -138,    //!< The handle corresponds to GDIPrimary.
    NVAPI_EXPECTED_COMPUTE_GPU_HANDLE           = -139,    //!< Setting Physx GPU requires that the GPU is compute-capable.
    NVAPI_STEREO_NOT_INITIALIZED                = -140,    //!< The Stereo part of NVAPI failed to initialize completely. Check if the stereo driver is installed.
    NVAPI_STEREO_REGISTRY_ACCESS_FAILED         = -141,    //!< Access to stereo-related registry keys or values has failed.
    NVAPI_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED = -142, //!< The given registry profile type is not supported.
    NVAPI_STEREO_REGISTRY_VALUE_NOT_SUPPORTED   = -143,    //!< The given registry value is not supported.
    NVAPI_STEREO_NOT_ENABLED                    = -144,    //!< Stereo is not enabled and the function needed it to execute completely.
    NVAPI_STEREO_NOT_TURNED_ON                  = -145,    //!< Stereo is not turned on and the function needed it to execute completely.
    NVAPI_STEREO_INVALID_DEVICE_INTERFACE       = -146,    //!< Invalid device interface.
    NVAPI_STEREO_PARAMETER_OUT_OF_RANGE         = -147,    //!< Separation percentage or JPEG image capture quality is out of [0-100] range.
    NVAPI_STEREO_FRUSTUM_ADJUST_MODE_NOT_SUPPORTED = -148, //!< The given frustum adjust mode is not supported.
    NVAPI_TOPO_NOT_POSSIBLE                     = -149,    //!< The mosaic topology is not possible given the current state of the hardware.
    NVAPI_MODE_CHANGE_FAILED                    = -150,    //!< An attempt to do a display resolution mode change has failed.        
    NVAPI_D3D11_LIBRARY_NOT_FOUND               = -151,    //!< d3d11.dll/d3d11_beta.dll cannot be loaded.
    NVAPI_INVALID_ADDRESS                       = -152,    //!< Address is outside of valid range.
    NVAPI_STRING_TOO_SMALL                      = -153,    //!< The pre-allocated string is too small to hold the result.
    NVAPI_MATCHING_DEVICE_NOT_FOUND             = -154,    //!< The input does not match any of the available devices.
    NVAPI_DRIVER_RUNNING                        = -155,    //!< Driver is running.
    NVAPI_DRIVER_NOTRUNNING                     = -156,    //!< Driver is not running.
    NVAPI_ERROR_DRIVER_RELOAD_REQUIRED          = -157,    //!< A driver reload is required to apply these settings.
    NVAPI_SET_NOT_ALLOWED                       = -158,    //!< Intended setting is not allowed.
    NVAPI_ADVANCED_DISPLAY_TOPOLOGY_REQUIRED    = -159,    //!< Information can't be returned due to "advanced display topology".
    NVAPI_SETTING_NOT_FOUND                     = -160,    //!< Setting is not found.
    NVAPI_SETTING_SIZE_TOO_LARGE                = -161,    //!< Setting size is too large.
    NVAPI_TOO_MANY_SETTINGS_IN_PROFILE          = -162,    //!< There are too many settings for a profile. 
    NVAPI_PROFILE_NOT_FOUND                     = -163,    //!< Profile is not found.
    NVAPI_PROFILE_NAME_IN_USE                   = -164,    //!< Profile name is duplicated.
    NVAPI_PROFILE_NAME_EMPTY                    = -165,    //!< Profile name is empty.
    NVAPI_EXECUTABLE_NOT_FOUND                  = -166,    //!< Application not found in the Profile.
    NVAPI_EXECUTABLE_ALREADY_IN_USE             = -167,    //!< Application already exists in the other profile.
    NVAPI_DATATYPE_MISMATCH                     = -168,    //!< Data Type mismatch 
    NVAPI_PROFILE_REMOVED                       = -169,    //!< The profile passed as parameter has been removed and is no longer valid.
    NVAPI_UNREGISTERED_RESOURCE                 = -170,    //!< An unregistered resource was passed as a parameter. 
    NVAPI_ID_OUT_OF_RANGE                       = -171,    //!< The DisplayId corresponds to a display which is not within the normal outputId range.
    NVAPI_DISPLAYCONFIG_VALIDATION_FAILED       = -172,    //!< Display topology is not valid so the driver cannot do a mode set on this configuration.
    NVAPI_DPMST_CHANGED                         = -173,    //!< Display Port Multi-Stream topology has been changed.
    NVAPI_INSUFFICIENT_BUFFER                   = -174,    //!< Input buffer is insufficient to hold the contents.    
    NVAPI_ACCESS_DENIED                         = -175,    //!< No access to the caller.
    NVAPI_MOSAIC_NOT_ACTIVE                     = -176,    //!< The requested action cannot be performed without Mosaic being enabled.
    NVAPI_SHARE_RESOURCE_RELOCATED              = -177,    //!< The surface is relocated away from video memory.
    NVAPI_REQUEST_USER_TO_DISABLE_DWM           = -178,    //!< The user should disable DWM before calling NvAPI.
    NVAPI_D3D_DEVICE_LOST                       = -179,    //!< D3D device status is D3DERR_DEVICELOST or D3DERR_DEVICENOTRESET - the user has to reset the device.
    NVAPI_INVALID_CONFIGURATION                 = -180,    //!< The requested action cannot be performed in the current state.
    NVAPI_STEREO_HANDSHAKE_NOT_DONE             = -181,    //!< Call failed as stereo handshake not completed.
    NVAPI_EXECUTABLE_PATH_IS_AMBIGUOUS          = -182,    //!< The path provided was too short to determine the correct NVDRS_APPLICATION
} NvAPI_Status;

//!   \ingroup nvapistatus 
#define NVAPI_API_NOT_INTIALIZED        NVAPI_API_NOT_INITIALIZED       //!< Fix typo in error code

//!   \ingroup nvapistatus 
#define NVAPI_INVALID_USER_PRIVILEDGE   NVAPI_INVALID_USER_PRIVILEGE    //!< Fix typo in error code




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Initialize
//
//! This function initializes the NvAPI library. 
//! This must be called before calling other NvAPI_ functions. 
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since 
//!  Version: 82.61
//!
//! \retval  NVAPI_ERROR            An error occurred during the initialization process (generic error)
//! \retval  NVAPI_LIBRARYNOTFOUND  Failed to load the NVAPI support library
//! \retval  NVAPI_OK               Initialized
//! \sa nvapistatus
//! \ingroup nvapifunctions
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Initialize();


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Unload
//
//!   DESCRIPTION: Unloads NVAPI library. This must be the last function called. 
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//!  !! This is not thread safe. In a multithreaded environment, calling NvAPI_Unload       !! \n
//!  !! while another thread is executing another NvAPI_XXX function, results in           !!  \n
//!  !! undefined behaviour and might even cause the application to crash. Developers       !! \n
//!  !! must make sure that they are not in any other function before calling NvAPI_Unload. !! \n
//!
//!
//!  Unloading NvAPI library is not supported when the library is in a resource locked state.
//!  Some functions in the NvAPI library initiates an operation or allocates certain resources
//!  and there are corresponding functions available, to complete the operation or free the
//!  allocated resources. All such function pairs are designed to prevent unloading NvAPI library.
//!
//!  For example, if NvAPI_Unload is called after NvAPI_XXX which locks a resource, it fails with
//!  NVAPI_ERROR. Developers need to call the corresponding NvAPI_YYY to unlock the resources, 
//!  before calling NvAPI_Unload again.
//!
//! \retval ::NVAPI_ERROR            One or more resources are locked and hence cannot unload NVAPI library
//! \retval ::NVAPI_OK               NVAPI library unloaded
//!
//! \ingroup nvapifunctions
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Unload();





///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetErrorMessage
//
//! This function converts an NvAPI error code into a null terminated string.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since 
//!  Version: 82.61
//!
//! \param nr      The error code to convert
//! \param szDesc  The string corresponding to the error code
//!
//! \return NULL terminated string (always, never NULL)
//! \ingroup nvapifunctions
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetErrorMessage(NvAPI_Status nr,NvAPI_ShortString szDesc);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetInterfaceVersionString
//
//! This function returns a string describing the version of the NvAPI library.
//!               The contents of the string are human readable.  Do not assume a fixed
//!                format.
//!
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since 
//!  Version: 82.61
//!
//! \param  szDesc User readable string giving NvAPI version information
//!
//! \return See \ref nvapistatus for the list of possible return values.
//! \ingroup nvapifunctions
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetInterfaceVersionString(NvAPI_ShortString szDesc);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetDisplayDriverVersion
//! \fn NvAPI_GetDisplayDriverVersion(NvDisplayHandle hNvDisplay, NV_DISPLAY_DRIVER_VERSION *pVersion)
//! This function returns a struct that describes aspects of the display driver
//!                build.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since
//!  Version: 82.61
//!
//! \param [in]  hNvDisplay NVIDIA display handle.
//! \param [out] pVersion Pointer to NV_DISPLAY_DRIVER_VERSION struc
//!
//! \retval NVAPI_ERROR
//! \retval NVAPI_OK
///////////////////////////////////////////////////////////////////////////////

//! \ingroup driverapi
//! Used in NvAPI_GetDisplayDriverVersion()
typedef struct 
{
    NvU32              version;             // Structure version
    NvU32              drvVersion;           
    NvU32              bldChangeListNum;     
    NvAPI_ShortString  szBuildBranchString; 
    NvAPI_ShortString  szAdapterString;
} NV_DISPLAY_DRIVER_VERSION;

//! \ingroup driverapi
#define NV_DISPLAY_DRIVER_VERSION_VER  MAKE_NVAPI_VERSION(NV_DISPLAY_DRIVER_VERSION,1)


//! \ingroup driverapi
NVAPI_INTERFACE NvAPI_GetDisplayDriverVersion(NvDisplayHandle hNvDisplay, NV_DISPLAY_DRIVER_VERSION *pVersion);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_SYS_GetDriverAndBranchVersion
//
//!   DESCRIPTION: This API returns display driver version and driver-branch string.
//!
//  SUPPORTED OS: Windows XP and higher
//! 
//! \param [out]  pDriverVersion         Contains the driver version after successful return.
//! \param [out]  szBuildBranchString    Contains the driver-branch string after successful return.
//!
//! \retval ::NVAPI_INVALID_ARGUMENT: either pDriverVersion is NULL or enum index too big
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized
//! \retval ::NVAPI_ERROR - miscellaneous error occurred
//! 
//! \ingroup driverapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SYS_GetDriverAndBranchVersion(NvU32* pDriverVersion, NvAPI_ShortString szBuildBranchString);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_EnumNvidiaDisplayHandle
//
//! This function returns the handle of the NVIDIA display specified by the enum 
//!                index (thisEnum). The client should keep enumerating until it
//!                returns NVAPI_END_ENUMERATION.
//!
//!                Note: Display handles can get invalidated on a modeset, so the calling applications need to
//!                renum the handles after every modeset.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since
//!   Version: 82.61
//!
//! \param [in]  thisEnum      The index of the NVIDIA display.   
//! \param [out] pNvDispHandle Pointer to the NVIDIA display handle.
//!
//! \retval NVAPI_INVALID_ARGUMENT        Either the handle pointer is NULL or enum index too big
//! \retval NVAPI_OK                      Return a valid NvDisplayHandle based on the enum index
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND No NVIDIA device found in the system
//! \retval NVAPI_END_ENUMERATION         No more display device to enumerate
//! \ingroup disphandle
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_EnumNvidiaDisplayHandle(NvU32 thisEnum, NvDisplayHandle *pNvDispHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_EnumNvidiaUnAttachedDisplayHandle
//
//! This function returns the handle of the NVIDIA unattached display specified by the enum 
//!                index (thisEnum). The client should keep enumerating until it
//!                returns error.
//!                Note: Display handles can get invalidated on a modeset, so the calling applications need to
//!                renum the handles after every modeset.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since
//!  Version: 82.61
//!
//! \param [in]  thisEnum                  The index of the NVIDIA display.
//! \param [out] pNvUnAttachedDispHandle   Pointer to the NVIDIA display handle of the unattached display.
//!
//! \retval NVAPI_INVALID_ARGUMENT         Either the handle pointer is NULL or enum index too big
//! \retval NVAPI_OK                       Return a valid NvDisplayHandle based on the enum index
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA device found in the system
//! \retval NVAPI_END_ENUMERATION          No more display device to enumerate.
//! \ingroup disphandle
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_EnumNvidiaUnAttachedDisplayHandle(NvU32 thisEnum, NvUnAttachedDisplayHandle *pNvUnAttachedDispHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_EnumPhysicalGPUs
//
//! This function returns an array of physical GPU handles.
//! Each handle represents a physical GPU present in the system.
//! That GPU may be part of an SLI configuration, or may not be visible to the OS directly.
//!
//! At least one GPU must be present in the system and running an NVIDIA display driver.
//!
//! The array nvGPUHandle will be filled with physical GPU handle values. The returned
//! gpuCount determines how many entries in the array are valid.
//!
//! \note In drivers older than 105.00, all physical GPU handles get invalidated on a
//!       modeset. So the calling applications need to renum the handles after every modeset.\n
//!       With drivers 105.00 and up, all physical GPU handles are constant.
//!       Physical GPU handles are constant as long as the GPUs are not physically moved and 
//!       the SBIOS VGA order is unchanged.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \par Introduced in
//!  Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT         nvGPUHandle or pGpuCount is NULL
//! \retval NVAPI_OK                       One or more handles were returned
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_EnumPhysicalGPUs(NvPhysicalGpuHandle nvGPUHandle[NVAPI_MAX_PHYSICAL_GPUS], NvU32 *pGpuCount);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_EnumLogicalGPUs
//
//! This function returns an array of logical GPU handles.
//!
//! Each handle represents one or more GPUs acting in concert as a single graphics device.
//!
//! At least one GPU must be present in the system and running an NVIDIA display driver.
//!
//! The array nvGPUHandle will be filled with logical GPU handle values.  The returned
//! gpuCount determines how many entries in the array are valid.
//!
//! \note All logical GPUs handles get invalidated on a GPU topology change, so the calling 
//!       application is required to renum the logical GPU handles to get latest physical handle
//!       mapping after every GPU topology change activated by a call to NvAPI_SetGpuTopologies().
//!
//! To detect if SLI rendering is enabled, use NvAPI_D3D_GetCurrentSLIState().
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since 
//!  Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT         nvGPUHandle or pGpuCount is NULL
//! \retval NVAPI_OK                       One or more handles were returned
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_EnumLogicalGPUs(NvLogicalGpuHandle nvGPUHandle[NVAPI_MAX_LOGICAL_GPUS], NvU32 *pGpuCount);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetPhysicalGPUsFromDisplay
//
//! This function returns an array of physical GPU handles associated with the specified display.
//!
//! At least one GPU must be present in the system and running an NVIDIA display driver.
//!
//! The array nvGPUHandle will be filled with physical GPU handle values.  The returned
//! gpuCount determines how many entries in the array are valid.
//!
//! If the display corresponds to more than one physical GPU, the first GPU returned
//! is the one with the attached active output.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since 
//!  Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT         hNvDisp is not valid; nvGPUHandle or pGpuCount is NULL
//! \retval NVAPI_OK                       One or more handles were returned
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND  no NVIDIA GPU driving a display was found
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetPhysicalGPUsFromDisplay(NvDisplayHandle hNvDisp, NvPhysicalGpuHandle nvGPUHandle[NVAPI_MAX_PHYSICAL_GPUS], NvU32 *pGpuCount);
 

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetPhysicalGPUFromUnAttachedDisplay
//
//! This function returns a physical GPU handle associated with the specified unattached display.
//! The source GPU is a physical render GPU which renders the frame buffer but may or may not drive the scan out.
//!
//! At least one GPU must be present in the system and running an NVIDIA display driver.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since
//!  Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT         hNvUnAttachedDisp is not valid or pPhysicalGpu is NULL.
//! \retval NVAPI_OK                       One or more handles were returned
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetPhysicalGPUFromUnAttachedDisplay(NvUnAttachedDisplayHandle hNvUnAttachedDisp, NvPhysicalGpuHandle *pPhysicalGpu);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_CreateDisplayFromUnAttachedDisplay
//
//! This function converts the unattached display handle to an active attached display handle.
//!
//! At least one GPU must be present in the system and running an NVIDIA display driver.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT         hNvUnAttachedDisp is not valid or pNvDisplay is NULL.
//! \retval NVAPI_OK                       One or more handles were returned
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_CreateDisplayFromUnAttachedDisplay(NvUnAttachedDisplayHandle hNvUnAttachedDisp, NvDisplayHandle *pNvDisplay);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetLogicalGPUFromDisplay
//
//! This function returns the logical GPU handle associated with the specified display.
//! At least one GPU must be present in the system and running an NVIDIA display driver.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT         hNvDisp is not valid; pLogicalGPU is NULL
//! \retval NVAPI_OK                       One or more handles were returned
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetLogicalGPUFromDisplay(NvDisplayHandle hNvDisp, NvLogicalGpuHandle *pLogicalGPU);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetLogicalGPUFromPhysicalGPU
//
//! This function returns the logical GPU handle associated with specified physical GPU handle.
//! At least one GPU must be present in the system and running an NVIDIA display driver.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT         hPhysicalGPU is not valid; pLogicalGPU is NULL
//! \retval NVAPI_OK                       One or more handles were returned
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetLogicalGPUFromPhysicalGPU(NvPhysicalGpuHandle hPhysicalGPU, NvLogicalGpuHandle *pLogicalGPU);
   
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetPhysicalGPUsFromLogicalGPU
//
//!  This function returns the physical GPU handles associated with the specified logical GPU handle.
//!  At least one GPU must be present in the system and running an NVIDIA display driver.
//!
//!  The array hPhysicalGPU will be filled with physical GPU handle values.  The returned
//!  gpuCount determines how many entries in the array are valid.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT             hLogicalGPU is not valid; hPhysicalGPU is NULL
//! \retval NVAPI_OK                           One or more handles were returned
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND      No NVIDIA GPU driving a display was found
//! \retval NVAPI_EXPECTED_LOGICAL_GPU_HANDLE  hLogicalGPU was not a logical GPU handle
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetPhysicalGPUsFromLogicalGPU(NvLogicalGpuHandle hLogicalGPU,NvPhysicalGpuHandle hPhysicalGPU[NVAPI_MAX_PHYSICAL_GPUS], NvU32 *pGpuCount);
   
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetAssociatedNVidiaDisplayHandle
//
//!  This function returns the handle of the NVIDIA display that is associated
//!  with the given display "name" (such as "\\.\DISPLAY1").
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT         Either argument is NULL
//! \retval NVAPI_OK                      *pNvDispHandle is now valid
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA device maps to that display name
//! \ingroup disphandle
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetAssociatedNvidiaDisplayHandle(const char *szDisplayName, NvDisplayHandle *pNvDispHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DISP_GetAssociatedUnAttachedNvidiaDisplayHandle
//
//!   DESCRIPTION: This function returns the handle of an unattached NVIDIA display that is 
//!                associated with the given display name (such as "\\DISPLAY1"). 
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 187.07
//!
//! \retval ::NVAPI_INVALID_ARGUMENT          Either argument is NULL.
//! \retval ::NVAPI_OK                       *pNvUnAttachedDispHandle is now valid.
//! \retval ::NVAPI_NVIDIA_DEVICE_NOT_FOUND   No NVIDIA device maps to that display name.
//!
//! \ingroup disphandle
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_GetAssociatedUnAttachedNvidiaDisplayHandle(const char *szDisplayName, NvUnAttachedDisplayHandle *pNvUnAttachedDispHandle);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetAssociatedNVidiaDisplayName
//
//!  For a given NVIDIA display handle, this function returns a string (such as "\\.\DISPLAY1") to identify the display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT          Either argument is NULL
//! \retval NVAPI_OK                       *pNvDispHandle is now valid
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND   No NVIDIA device maps to that display name
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetAssociatedNvidiaDisplayName(NvDisplayHandle NvDispHandle, NvAPI_ShortString szDisplayName);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetUnAttachedAssociatedDisplayName
//
//!  This function returns the display name given, for example, "\\DISPLAY1", using the unattached NVIDIA display handle
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.60, 100.06
//!
//! \retval NVAPI_INVALID_ARGUMENT          Either argument is NULL
//! \retval NVAPI_OK                       *pNvDispHandle is now valid
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND   No NVIDIA device maps to that display name
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetUnAttachedAssociatedDisplayName(NvUnAttachedDisplayHandle hNvUnAttachedDisp, NvAPI_ShortString szDisplayName);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_EnableHWCursor
//
//!  This function enables hardware cursor support
//!
//  SUPPORTED OS: Windows XP
//!  
//!
//! \since Version: 82.61
//!
//! \return NVAPI_ERROR or NVAPI_OK
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_EnableHWCursor(NvDisplayHandle hNvDisplay);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DisableHWCursor
//
//! This function disables hardware cursor support
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since   Version: 82.61
//!
//! \return  NVAPI_ERROR or NVAPI_OK
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DisableHWCursor(NvDisplayHandle hNvDisplay);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetVBlankCounter
//
//!  This function gets the V-blank counter
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \return NVAPI_ERROR or NVAPI_OK
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetVBlankCounter(NvDisplayHandle hNvDisplay, NvU32 *pCounter);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME: NvAPI_OverrideRefreshRate
//
//!  This function overrides the refresh rate on the given display/outputsMask.
//!  The new refresh rate can be applied right away in this API call or deferred to be applied with the
//!  next OS modeset. The override is good for only one modeset (regardless whether it's deferred or immediate).
//!               
//!
//  SUPPORTED OS: Windows XP
//!
//! \since Version: 82.61
//!
//!  \param [in] hNvDisplay    The NVIDIA display handle. It can be NVAPI_DEFAULT_HANDLE or a handle
//!                           enumerated from NvAPI_EnumNVidiaDisplayHandle().
//!  \param [in] outputsMask  A set of bits that identify all target outputs which are associated with the NVIDIA 
//!                           display handle to apply the refresh rate override. When SLI is enabled, the
//!                           outputsMask only applies to the GPU that is driving the display output.
//!  \param [in] refreshRate  The override value. "0.0" means cancel the override.
//!  \param [in] bSetDeferred 
//!              - "0": Apply the refresh rate override immediately in this API call.\p
//!              - "1": Apply refresh rate at the next OS modeset.
//!
//!  \retval  NVAPI_INVALID_ARGUMENT hNvDisplay or outputsMask is invalid
//!  \retval  NVAPI_OK               The refresh rate override is correct set
//!  \retval  NVAPI_ERROR            The operation failed
//!  \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetRefreshRateOverride(NvDisplayHandle hNvDisplay, NvU32 outputsMask, float refreshRate, NvU32 bSetDeferred);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetAssociatedDisplayOutputId
//
//! This function gets the active outputId associated with the display handle.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 93.60
//!
//! \param [in]  hNvDisplay  NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [out] outputId    The active display output ID associated with the selected display handle hNvDisplay.
//!                          The outputid will have only one bit set. In the case of Clone or Span mode, this will indicate the
//!                          display outputId of the primary display that the GPU is driving. See \ref handles.
//!
//! \retval  NVAPI_OK                      Call successful.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_DISPLAY_HANDLE hNvDisplay is not a valid display handle.
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetAssociatedDisplayOutputId(NvDisplayHandle hNvDisplay, NvU32 *pOutputId);



///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetDisplayPortInfo
//
//! \fn NvAPI_GetDisplayPortInfo(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_DISPLAY_PORT_INFO *pInfo)
//! DESCRIPTION:     This function returns the current DisplayPort-related information on the specified device (monitor).
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 165.22
//!
//! \param [in]     hNvDisplay    NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from 
//!                               NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]     outputId      The display output ID. If "0", then the default outputId from
//!                               NvAPI_GetAssociatedDisplayOutputId() will be used. See \ref handles.
//! \param [out]    pInfo         The DisplayPort information
//!
//! \retval         NVAPI_OK                Completed request
//! \retval         NVAPI_ERROR             Miscellaneous error occurred
//! \retval         NVAPI_INVALID_ARGUMENT  Invalid input parameter.
//
///////////////////////////////////////////////////////////////////////////////


//! \ingroup dispcontrol
//! Used in NV_DISPLAY_PORT_INFO.
typedef enum
{
    NV_DP_1_62GBPS            = 6,
    NV_DP_2_70GBPS            = 0xA,
} NV_DP_LINK_RATE;


//! \ingroup dispcontrol
//! Used in NV_DISPLAY_PORT_INFO.
typedef enum
{
    NV_DP_1_LANE              = 1,
    NV_DP_2_LANE              = 2,
    NV_DP_4_LANE              = 4,
} NV_DP_LANE_COUNT;


//! \ingroup dispcontrol
//! Used in NV_DISPLAY_PORT_INFO.
typedef enum
{
    NV_DP_COLOR_FORMAT_RGB     = 0,
    NV_DP_COLOR_FORMAT_YCbCr422,
    NV_DP_COLOR_FORMAT_YCbCr444,
} NV_DP_COLOR_FORMAT;


//! \ingroup dispcontrol
//! Used in NV_DISPLAY_PORT_INFO.
typedef enum
{
    NV_DP_COLORIMETRY_RGB     = 0,
    NV_DP_COLORIMETRY_YCbCr_ITU601,
    NV_DP_COLORIMETRY_YCbCr_ITU709,
} NV_DP_COLORIMETRY;


//! \ingroup dispcontrol
//! Used in NV_DISPLAY_PORT_INFO.
typedef enum
{
    NV_DP_DYNAMIC_RANGE_VESA  = 0,
    NV_DP_DYNAMIC_RANGE_CEA,
} NV_DP_DYNAMIC_RANGE;


//! \ingroup dispcontrol
//! Used in NV_DISPLAY_PORT_INFO.
typedef enum
{
    NV_DP_BPC_DEFAULT         = 0,
    NV_DP_BPC_6,
    NV_DP_BPC_8,
    NV_DP_BPC_10,
    NV_DP_BPC_12,
    NV_DP_BPC_16,
} NV_DP_BPC;


//! \ingroup dispcontrol
//! Used in NvAPI_GetDisplayPortInfo().
typedef struct
{
    NvU32               version;                     //!< Structure version
    NvU32               dpcd_ver;                    //!< DPCD version of the monitor
    NV_DP_LINK_RATE     maxLinkRate;                 //!< Maximum supported link rate
    NV_DP_LANE_COUNT    maxLaneCount;                //!< Maximum supported lane count
    NV_DP_LINK_RATE     curLinkRate;                 //!< Current link rate
    NV_DP_LANE_COUNT    curLaneCount;                //!< Current lane count
    NV_DP_COLOR_FORMAT  colorFormat;                 //!< Current color format
    NV_DP_DYNAMIC_RANGE dynamicRange;                //!< Dynamic range
    NV_DP_COLORIMETRY   colorimetry;                 //!< Ignored in RGB space
    NV_DP_BPC           bpc;                         //!< Current bit-per-component;
    NvU32               isDp                   : 1;  //!< If the monitor is driven by a DisplayPort 
    NvU32               isInternalDp           : 1;  //!< If the monitor is driven by an NV Dp transmitter
    NvU32               isColorCtrlSupported   : 1;  //!< If the color format change is supported
    NvU32               is6BPCSupported        : 1;  //!< If 6 bpc is supported
    NvU32               is8BPCSupported        : 1;  //!< If 8 bpc is supported    
    NvU32               is10BPCSupported       : 1;  //!< If 10 bpc is supported
    NvU32               is12BPCSupported       : 1;  //!< If 12 bpc is supported        
    NvU32               is16BPCSupported       : 1;  //!< If 16 bpc is supported
    NvU32               isYCrCb422Supported    : 1;  //!< If YCrCb422 is supported                                                  
    NvU32               isYCrCb444Supported    : 1;  //!< If YCrCb444 is supported
    
 } NV_DISPLAY_PORT_INFO; 

//! Macro for constructing the version field of NV_DISPLAY_PORT_INFO.
#define NV_DISPLAY_PORT_INFO_VER  MAKE_NVAPI_VERSION(NV_DISPLAY_PORT_INFO,1)



//! \ingroup        dispcontrol
NVAPI_INTERFACE NvAPI_GetDisplayPortInfo(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_DISPLAY_PORT_INFO *pInfo);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetDisplayPort
//
//! \fn NvAPI_SetDisplayPort(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_DISPLAY_PORT_CONFIG *pCfg)
//! DESCRIPTION:     This function sets up DisplayPort-related configurations.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version:   165.22
//!
//! \param [in]       hNvDisplay  NVIDIA display handle. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from
//!                               NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]       outputId    This display output ID, when it's "0" it means the default outputId generated from the return of
//!                               NvAPI_GetAssociatedDisplayOutputId(). See \ref handles.
//! \param [in]       pCfg        The display port config structure. If pCfg is NULL, it means to use the driver's default value to setup.
//!
//! \retval           NVAPI_OK                Completed request
//! \retval           NVAPI_ERROR             Miscellaneous error occurred
//! \retval           NVAPI_INVALID_ARGUMENT  Invalid input parameter
///////////////////////////////////////////////////////////////////////////////


//! \ingroup dispcontrol
//! DisplayPort configuration settings - used in NvAPI_SetDisplayPort().
typedef struct
{
    NvU32               version;                     //!< Structure version - 2 is the latest
    NV_DP_LINK_RATE     linkRate;                    //!< Link rate
    NV_DP_LANE_COUNT    laneCount;                   //!< Lane count
    NV_DP_COLOR_FORMAT  colorFormat;                 //!< Color format to set
    NV_DP_DYNAMIC_RANGE dynamicRange;                //!< Dynamic range
    NV_DP_COLORIMETRY   colorimetry;                 //!< Ignored in RGB space
    NV_DP_BPC           bpc;                         //!< Bit-per-component
    NvU32               isHPD               : 1;     //!< If the control panel is making this call due to HPD
    NvU32               isSetDeferred       : 1;     //!< Requires an OS modeset to finalize the setup if set
    NvU32               isChromaLpfOff      : 1;     //!< Force the chroma low_pass_filter to be off
    NvU32               isDitherOff         : 1;     //!< Force to turn off dither
    NvU32               testLinkTrain       : 1;     //!< If testing mode, skip validation
    NvU32               testColorChange     : 1;     //!< If testing mode, skip validation

} NV_DISPLAY_PORT_CONFIG;

//! \addtogroup dispcontrol
//! @{
//! Macro for constructing the version field of NV_DISPLAY_PORT_CONFIG
#define NV_DISPLAY_PORT_CONFIG_VER   MAKE_NVAPI_VERSION(NV_DISPLAY_PORT_CONFIG,2)
//! Macro for constructing the version field of NV_DISPLAY_PORT_CONFIG
#define NV_DISPLAY_PORT_CONFIG_VER_1 MAKE_NVAPI_VERSION(NV_DISPLAY_PORT_CONFIG,1)
//! Macro for constructing the version field of NV_DISPLAY_PORT_CONFIG
#define NV_DISPLAY_PORT_CONFIG_VER_2 MAKE_NVAPI_VERSION(NV_DISPLAY_PORT_CONFIG,2)
//! @}


//! \ingroup          dispcontrol
NVAPI_INTERFACE NvAPI_SetDisplayPort(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_DISPLAY_PORT_CONFIG *pCfg);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetHDMISupportInfo
//
//! \fn NvAPI_GetHDMISupportInfo(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_HDMI_SUPPORT_INFO *pInfo)
//!   This API returns the current infoframe data on the specified device(monitor).
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 97.00
//!
//! \param [in]  hvDisplay  NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  outputId   The display output id. If it's "0" then the default outputId from NvAPI_GetAssociatedDisplayOutputId() will be used. See \ref handles.
//! \param [out] pInfo      The monitor and GPU's HDMI support info
//!
//! \retval  NVAPI_OK                Completed request
//! \retval  NVAPI_ERROR             Miscellaneous error occurred
//! \retval  NVAPI_INVALID_ARGUMENT  Invalid input parameter.
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dispcontrol
//! Used in NvAPI_GetHDMISupportInfo().
typedef struct
{
    NvU32      version;                     //!< Structure version
    NvU32      isGpuHDMICapable       : 1;  //!< If the GPU can handle HDMI
    NvU32      isMonUnderscanCapable  : 1;  //!< If the monitor supports underscan
    NvU32      isMonBasicAudioCapable : 1;  //!< If the monitor supports basic audio
    NvU32      isMonYCbCr444Capable   : 1;  //!< If YCbCr 4:4:4 is supported
    NvU32      isMonYCbCr422Capable   : 1;  //!< If YCbCr 4:2:2 is supported
    NvU32      isMonxvYCC601Capable   : 1;  //!< If xvYCC 601 is supported
    NvU32      isMonxvYCC709Capable   : 1;  //!< If xvYCC 709 is supported
    NvU32      isMonHDMI              : 1;  //!< If the monitor is HDMI (with IEEE's HDMI registry ID)
    NvU32      EDID861ExtRev;               //!< Revision number of the EDID 861 extension
 } NV_HDMI_SUPPORT_INFO; 


//! \ingroup dispcontrol
#define NV_HDMI_SUPPORT_INFO_VER  MAKE_NVAPI_VERSION(NV_HDMI_SUPPORT_INFO,1)



//! \ingroup dispcontrol
NVAPI_INTERFACE NvAPI_GetHDMISupportInfo(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_HDMI_SUPPORT_INFO *pInfo);



//! \ingroup dispcontrol
//! @{

#define NVAPI_HDMI_STEREO_MAX_MODES 256 

//! See ::NV_HDMI_STEREO_MODE.
typedef enum 
{
    NV_HDMI_STEREO_3D_NONE                = 0x00,
    NV_STEREO_NVISION,
    NV_HDMI_STEREO_3D_FRAME_PACKING,
    NV_HDMI_STEREO_3D_FRAME_PACKING_INT,
    NV_HDMI_STEREO_3D_LINE_ALT,
    NV_HDMI_STEREO_3D_SIDE_BY_SIDE_FULL,
    NV_HDMI_STEREO_3D_SIDE_BY_SIDE_HALF_HORIZONTAIL_ODD_LEFT_ODD_RIGHT,
    NV_HDMI_STEREO_3D_SIDE_BY_SIDE_HALF_HORIZONTAIL_ODD_LEFT_EVEN_RIGHT,
    NV_HDMI_STEREO_3D_SIDE_BY_SIDE_HALF_HORIZONTAIL_EVEN_LEFT_ODD_RIGHT,
    NV_HDMI_STEREO_3D_SIDE_BY_SIDE_HALF_HORIZONTAIL_EVEN_LEFT_EVEN_RIGHT,
    NV_HDMI_STEREO_3D_SIDE_BY_SIDE_HALF_QUINCUX_ODD_LEFT_ODD_RIGHT,
    NV_HDMI_STEREO_3D_SIDE_BY_SIDE_HALF_QUINCUX_ODD_LEFT_EVEN_RIGHT,
    NV_HDMI_STEREO_3D_SIDE_BY_SIDE_HALF_QUINCUX_EVEN_LEFT_ODD_RIGHT,
    NV_HDMI_STEREO_3D_SIDE_BY_SIDE_HALF_QUINCUX_EVEN_LEFT_EVEN_RIGHT,
    NV_HDMI_STEREO_3D_FIELD_ALT,
    NV_HDMI_STEREO_3D_L_DEPTH,
    NV_HDMI_STEREO_3D_L_DEPTH_GFX,
    NV_HDMI_STEREO_3D_ANY                 = 0xff,

} NV_HDMI_STEREO_TYPE;

//! See ::NV_HDMI_STEREO_MODES_LIST_V1.
typedef struct
{
    NvU16 HVisible;                     //!< Horizontal visible (size of single visible surface)
    NvU16 VVisible;                     //!< Vertical visible   (size of single visible surface)
    NvU16 HActive;                      //!< Horizontal active  (active frame size - i.e. both right & left surfaces, plus any padding)
    NvU16 VActive ;                     //!< Vertical active    (active frame size - i.e. both right & left surfaces, plus any padding)
    NvU16 VActiveSpace[2];              //!< Vertical active space

    NvU16   rr;                         //!< The refresh rate

    NV_HDMI_STEREO_TYPE stereoType;     //!< HDMI Stereo type

} NV_HDMI_STEREO_MODE;

//! See NvAPI_DISP_EnumHDMIStereoModes().
typedef struct
{
    // IN
    NvU32    version;             //!< structure version
    NvU32    displayId;           //!< (IN)Monitor Identifier. Retrieved from NvAPI_SYS_GetDisplayIdFromGpuAndOutputId
    NvU16    enumIndex;           //!< (IN)mode index 0 = 1st HDMI stereo mode
    NvU16    count;               //!< (IN)the max number of modes to return
    NvU32    width;               //!< (IN)visible desktop width, only required when bMatchDimension is true to do optional resolution filtering
    NvU32    height;              //!< (IN)visible desktop height, only required when bMatchDimension is true to do optional resolution filtering
    NvU32    refreshRate;         //!< (IN)desktop refresh rate, only required when bMatchRR is true to do optional refreshrate filtering
    NvU32    bMatchDimension : 1; //!< (IN)if true, return modes that match specified dimensions (height/width)
    NvU32    bMatchRR : 1;        //!< (IN)if true, return modes that match specified refresh rates
    NvU32    bPassThroughMode:1;  //!< (IN)if true, return pass-through capable modes. If false, return modeset capable modes
    NvU32    reserved : 29;       //!< reserved. Must be 0
    // OUT
    NvU16   numberOfModes;        //!< (OUT)number of modes returned
    NV_HDMI_STEREO_MODE modeList[NVAPI_HDMI_STEREO_MAX_MODES];    //!<(OUT) mode list

} NV_HDMI_STEREO_MODES_LIST_V1;

typedef NV_HDMI_STEREO_MODES_LIST_V1 NV_HDMI_STEREO_MODES_LIST;
#define NV_HDMI_STEREO_MODES_LIST_VER1  MAKE_NVAPI_VERSION(NV_HDMI_STEREO_MODES_LIST_V1,1)
#define NV_HDMI_STEREO_MODES_LIST_VER    NV_HDMI_STEREO_MODES_LIST_VER1

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_DISP_EnumHDMIStereoModes
//
//! DESCRIPTION:     This API returns HDMI stereo modes supported by the specified monitor with indices between [enumIndex, enumIndex+count].
//!                  numberOfModes returned would be min(count, number of stereo modes available for the monitor).
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in,out]   pHDMIStereoModes  As input, it contains displayID and enumIndex. After successful return, it contains the HDMI stereo mode list.
//!                  
//! \retval ::NVAPI_OK                             Completed request
//! \retval ::NVAPI_END_ENUMERATION                No more entries
//! \retval ::NVAPI_ERROR                          Miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT               Invalid input parameter.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION    NV_HDMI_STEREO_MODES_LIST structure version mismatch. see pHDMIStereoModes->version.
//! \retval ::NVAPI_ID_OUT_OF_RANGE                Incorrect displayId.
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_EnumHDMIStereoModes(NV_HDMI_STEREO_MODES_LIST *pHDMIStereoModes);

//! @}


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetInfoFrame
//
//! \fn NvAPI_GetInfoFrame(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_INFOFRAME_TYPE type, NV_INFOFRAME *pInfoFrame)
//!  This API returns the current infoframe data on the specified device(monitor).
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.00
//!
//! \param [in] hNvDisplay      NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in] outputId        The display output id. If it's "0" then the default outputId from NvAPI_GetAssociatedDisplayOutputId() will be used. See \ref handles.
//! \param [in] type            The type of infoframe to get. See NV_INFOFRAME_TYPE .
//! \param [out] pInfoFrame     Pointer to the The infoframe data.
//!
//! \retval  NVAPI_OK                Completed request
//! \retval  NVAPI_ERROR             Miscellaneous error occurred
//! \retval  NVAPI_INVALID_ARGUMENT  Invalid input parameter.
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dispcontrol
//! Use in NvAPI_GetInfoFrame(), NvAPI_SetInfoFrame(), NvAPI_GetInfoFrameState(), and NvAPI_SetInfoFrameState().
typedef enum _NV_INFOFRAME_TYPE
{
    NV_INFOFRAME_TYPE_AVI   = 2,
    NV_INFOFRAME_TYPE_SPD   = 3,
    NV_INFOFRAME_TYPE_AUDIO = 4,
    NV_INFOFRAME_TYPE_MS    = 5,
} NV_INFOFRAME_TYPE;


//! Used in \ref NV_INFOFRAME
//! \ingroup dispcontrol
typedef struct
{
    NvU8 type;
    NvU8 version;
    NvU8 length;
} NV_INFOFRAME_HEADER;

//! Since this is for Windows OS so far, we use this bit little endian definition
//! to handle the translation.
//! Used in \ref NV_INFOFRAME
//! \ingroup dispcontrol
typedef struct
{
    // byte 1
    NvU8 channelCount     : 3;
    NvU8 rsvd_bits_byte1  : 1;
    NvU8 codingType       : 4;

    // byte 2
    NvU8 sampleSize       : 2;
    NvU8 sampleRate       : 3;
    NvU8 rsvd_bits_byte2  : 3;

    // byte 3
    NvU8 codingExtensionType  : 5;
    NvU8 rsvd_bits_byte3      : 3;


    // byte 4
    NvU8  speakerPlacement;

    // byte 5
    NvU8 lfePlaybackLevel     : 2;
    NvU8 rsvd_bits_byte5      : 1;
    NvU8 levelShift           : 4;
    NvU8 downmixInhibit       : 1;

    // byte 6~10
    NvU8 rsvd_byte6;
    NvU8 rsvd_byte7;
    NvU8 rsvd_byte8;
    NvU8 rsvd_byte9;
    NvU8 rsvd_byte10;

}NV_AUDIO_INFOFRAME;


//! Used in \ref NV_INFOFRAME
//! \ingroup dispcontrol
typedef struct
{
    // byte 1
    NvU8 scanInfo                : 2;
    NvU8 barInfo                 : 2;
    NvU8 activeFormatInfoPresent : 1;
    NvU8 colorSpace              : 2;
    NvU8 rsvd_bits_byte1         : 1;

    // byte 2
    NvU8 activeFormatAspectRatio : 4;
    NvU8 picAspectRatio          : 2;
    NvU8 colorimetry             : 2;

    // byte 3
    NvU8 nonuniformScaling       : 2;
    NvU8 rgbQuantizationRange    : 2;
    NvU8 extendedColorimetry     : 3;
    NvU8 itContent               : 1;

    // byte 4
    NvU8 vic                     : 7;
    NvU8 rsvd_bits_byte4         : 1;

    // byte 5
    NvU8 pixelRepeat             : 4;
    NvU8 contentTypes            : 2;
    NvU8 yccQuantizationRange    : 2;

    // byte 6~13 
    NvU8 topBarLow;
    NvU8 topBarHigh;
    NvU8 bottomBarLow;
    NvU8 bottomBarHigh;
    NvU8 leftBarLow;
    NvU8 leftBarHigh;
    NvU8 rightBarLow;
    NvU8 rightBarHigh;

} NV_VIDEO_INFOFRAME;

//! \ingroup dispcontrol
//! \sa NvAPI_GetInfoFrame(); NvAPI_SetInfoFrame
typedef struct
{
    NV_INFOFRAME_HEADER    header;
    union
    {
        NV_AUDIO_INFOFRAME audio;
        NV_VIDEO_INFOFRAME video;
    }u;
} NV_INFOFRAME;



//! \ingroup dispcontrol
NVAPI_INTERFACE NvAPI_GetInfoFrame(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_INFOFRAME_TYPE type, NV_INFOFRAME *pInfoFrame);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetInfoFrame
//
//!  This API returns the current infoframe data on the specified device(monitor).
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.00
//!
//! \param [in]  hNvDisplay     NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  outputId       The display output ID. If it's "0" then the default outputId from NvAPI_GetAssociatedDisplayOutputId() will be used. See \ref handles.
//! \param [in]  type           The type of infoframe to set. See NV_INFOFRAME_TYPE .
//! \param [in]  pInfoFrame     Pointer to the The infoframe data. NULL means reset to the default value.
//!
//! \retval  NVAPI_OK                Completed request
//! \retval  NVAPI_ERROR             Miscellaneous error occurred
//! \retval  NVAPI_INVALID_ARGUMENT  Invalid input parameter.
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetInfoFrame(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_INFOFRAME_TYPE type, NV_INFOFRAME *pInfoFrame);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetInfoFrameState
//
//! \fn NvAPI_SetInfoFrameState(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_INFOFRAME_TYPE type, NV_INFOFRAME_STATE *pState)
//! DESCRIPTION:    This API disables or enables the sending of infoframe packets. Currently, this is supported for audio packets only.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 177.78
//!
//! \param [in] hNvDisplay   NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in] outputId     The display output ID. If it's "0" then the default outputId from NvAPI_GetAssociatedDisplayOutputId() will be used.
//! \param [in] type         The type of infoframe to set
//! \param [in] state        state of infoframe to set
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_ARGUMENT
//
///////////////////////////////////////////////////////////////////////////////


//! ingroup dispcontrol
//! Used in NvAPI_SetInfoFrameState() and NvAPI_GetInfoFrameState().
typedef struct _NV_INFOFRAME_STATE
{
    NvU32 bDisabled    :    1;       //!< Enable or disable the infoframe when "bDriverCtrl" is 0.
    NvU32 bDriverCtrl  :    1;       //!< If set, let the driver control the infoframe state and ignore "bDisabled".
    NvU32 reserved     :   30;

} NV_INFOFRAME_STATE;

//! \ingroup dispcontrol
NVAPI_INTERFACE NvAPI_SetInfoFrameState(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_INFOFRAME_TYPE type, NV_INFOFRAME_STATE *pState);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetInfoFrameState
//
//! DESCRIPTION:    This API gets the state of the infoframe. Currently, this is supported for audio packets only.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 177.78
//!
//! \param [in]     hNvDisplay  NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]     outputId    The display output ID. If it's "0" then the default outputId from NvAPI_GetAssociatedDisplayOutputId() will be used.
//! \param [in]     type        The type of infoframe of which to get the state
//! \param [out]    state       State of the infoframe
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_ARGUMENT
//!
//! \ingroup dispcontrol 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetInfoFrameState(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_INFOFRAME_TYPE type, NV_INFOFRAME_STATE *pState);


//! \ingroup dispcontrol
//! @{
///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_Disp_InfoFrameControl
//
//! \fn NvAPI_Disp_InfoFrameControl(NvU32 displayId, NV_INFOFRAME_DATA *pInfoframeData)
//! DESCRIPTION:     This API controls the InfoFrame values.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]     displayId         Monitor Identifier
//! \param [in,out] pInfoframeData    Contains data corresponding to InfoFrame
//!                  
//! \return 
//! ::NVAPI_OK,  
//! ::NVAPI_ERROR,  
//! ::NVAPI_INVALID_ARGUMENT
//
///////////////////////////////////////////////////////////////////////////////

typedef enum
{
    NV_INFOFRAME_CMD_GET_DEFAULT = 0,     //!< Returns the fields in the infoframe with values set by the manufacturer - NVIDIA/OEM.
    NV_INFOFRAME_CMD_RESET,               //!< Sets the fields in the infoframe to auto, and infoframe to the default infoframe for use in a set.    
    NV_INFOFRAME_CMD_GET,                 //!< Get the current infoframe state.
    NV_INFOFRAME_CMD_SET,                 //!< Set the current infoframe state (flushed to the monitor), the values are one time and do not persist.
    NV_INFOFRAME_CMD_GET_OVERRIDE,        //!< Get the override infoframe state, non-override fields will be set to value = AUTO, overridden fields will have the current override values.
    NV_INFOFRAME_CMD_SET_OVERRIDE,        //!< Set the override infoframe state, non-override fields will be set to value = AUTO, other values indicate override; persist across modeset/reboot
    NV_INFOFRAME_CMD_GET_PROPERTY,        //!< get properties associated with infoframe (each of the infoframe type will have properties)
    NV_INFOFRAME_CMD_SET_PROPERTY,        //!< set properties associated with infoframe
} NV_INFOFRAME_CMD;


typedef enum
{
    NV_INFOFRAME_PROPERTY_MODE_AUTO           = 0, //!< Driver determines whether to send infoframes.
    NV_INFOFRAME_PROPERTY_MODE_ENABLE,             //!< Driver always sends infoframe.
    NV_INFOFRAME_PROPERTY_MODE_DISABLE,            //!< Driver never sends infoframe.
    NV_INFOFRAME_PROPERTY_MODE_ALLOW_OVERRIDE,     //!< Driver only sends infoframe when client requests it via infoframe escape call.
} NV_INFOFRAME_PROPERTY_MODE;


//! Returns whether the current monitor is in blacklist or force this monitor to be in blacklist.
typedef enum
{
    NV_INFOFRAME_PROPERTY_BLACKLIST_FALSE = 0,
    NV_INFOFRAME_PROPERTY_BLACKLIST_TRUE,
} NV_INFOFRAME_PROPERTY_BLACKLIST;

typedef struct
{
    NvU32 mode      :  4;
    NvU32 blackList :  2;
    NvU32 reserved  : 10;
    NvU32 version   :  8;
    NvU32 length    :  8;
} NV_INFOFRAME_PROPERTY;

//! Byte1 related
typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_SCANINFO_NODATA    = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_SCANINFO_OVERSCAN,
    NV_INFOFRAME_FIELD_VALUE_AVI_SCANINFO_UNDERSCAN,
    NV_INFOFRAME_FIELD_VALUE_AVI_SCANINFO_FUTURE,
    NV_INFOFRAME_FIELD_VALUE_AVI_SCANINFO_AUTO      = 7
} NV_INFOFRAME_FIELD_VALUE_AVI_SCANINFO;


typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_BARDATA_NOT_PRESENT         = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_BARDATA_VERTICAL_PRESENT,
    NV_INFOFRAME_FIELD_VALUE_AVI_BARDATA_HORIZONTAL_PRESENT,
    NV_INFOFRAME_FIELD_VALUE_AVI_BARDATA_BOTH_PRESENT,
    NV_INFOFRAME_FIELD_VALUE_AVI_BARDATA_AUTO                = 7
} NV_INFOFRAME_FIELD_VALUE_AVI_BARDATA;

typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_AFI_ABSENT   = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_AFI_PRESENT,
    NV_INFOFRAME_FIELD_VALUE_AVI_AFI_AUTO     = 3
} NV_INFOFRAME_FIELD_VALUE_AVI_ACTIVEFORMATINFO;


typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_COLORFORMAT_RGB      = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_COLORFORMAT_YCbCr422,
    NV_INFOFRAME_FIELD_VALUE_AVI_COLORFORMAT_YCbCr444,
    NV_INFOFRAME_FIELD_VALUE_AVI_COLORFORMAT_FUTURE,
    NV_INFOFRAME_FIELD_VALUE_AVI_COLORFORMAT_AUTO     = 7
} NV_INFOFRAME_FIELD_VALUE_AVI_COLORFORMAT;

typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_F17_FALSE = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_F17_TRUE,
    NV_INFOFRAME_FIELD_VALUE_AVI_F17_AUTO = 3
} NV_INFOFRAME_FIELD_VALUE_AVI_F17;

//! Byte2 related
typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_NO_AFD           = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_RESERVE01,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_RESERVE02,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_RESERVE03,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_LETTERBOX_GT16x9,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_RESERVE05,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_RESERVE06,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_RESERVE07,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_EQUAL_CODEDFRAME = 8,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_CENTER_4x3,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_CENTER_16x9,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_CENTER_14x9,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_RESERVE12,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_4x3_ON_14x9,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_16x9_ON_14x9,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_16x9_ON_4x3,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION_AUTO             = 31,
} NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOACTIVEPORTION;


typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOCODEDFRAME_NO_DATA = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOCODEDFRAME_4x3,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOCODEDFRAME_16x9,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOCODEDFRAME_FUTURE,
    NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOCODEDFRAME_AUTO    = 7
} NV_INFOFRAME_FIELD_VALUE_AVI_ASPECTRATIOCODEDFRAME;

typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_COLORIMETRY_NO_DATA                   = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_COLORIMETRY_SMPTE_170M,
    NV_INFOFRAME_FIELD_VALUE_AVI_COLORIMETRY_ITUR_BT709,
    NV_INFOFRAME_FIELD_VALUE_AVI_COLORIMETRY_USE_EXTENDED_COLORIMETRY,
    NV_INFOFRAME_FIELD_VALUE_AVI_COLORIMETRY_AUTO                      = 7
} NV_INFOFRAME_FIELD_VALUE_AVI_COLORIMETRY;

//! Byte 3 related
typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_NONUNIFORMPICTURESCALING_NO_DATA    = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_NONUNIFORMPICTURESCALING_HORIZONTAL,
    NV_INFOFRAME_FIELD_VALUE_AVI_NONUNIFORMPICTURESCALING_VERTICAL,
    NV_INFOFRAME_FIELD_VALUE_AVI_NONUNIFORMPICTURESCALING_BOTH,
    NV_INFOFRAME_FIELD_VALUE_AVI_NONUNIFORMPICTURESCALING_AUTO       = 7
} NV_INFOFRAME_FIELD_VALUE_AVI_NONUNIFORMPICTURESCALING;

typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_RGBQUANTIZATION_DEFAULT       = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_RGBQUANTIZATION_LIMITED_RANGE,
    NV_INFOFRAME_FIELD_VALUE_AVI_RGBQUANTIZATION_FULL_RANGE,
    NV_INFOFRAME_FIELD_VALUE_AVI_RGBQUANTIZATION_RESERVED,
    NV_INFOFRAME_FIELD_VALUE_AVI_RGBQUANTIZATION_AUTO          = 7
} NV_INFOFRAME_FIELD_VALUE_AVI_RGBQUANTIZATION;

typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_EXTENDEDCOLORIMETRY_XVYCC601     = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_EXTENDEDCOLORIMETRY_XVYCC709,
    NV_INFOFRAME_FIELD_VALUE_AVI_EXTENDEDCOLORIMETRY_SYCC601,
    NV_INFOFRAME_FIELD_VALUE_AVI_EXTENDEDCOLORIMETRY_ADOBEYCC601,
    NV_INFOFRAME_FIELD_VALUE_AVI_EXTENDEDCOLORIMETRY_ADOBERGB,
    NV_INFOFRAME_FIELD_VALUE_AVI_EXTENDEDCOLORIMETRY_RESERVED05,
    NV_INFOFRAME_FIELD_VALUE_AVI_EXTENDEDCOLORIMETRY_RESERVED06,
    NV_INFOFRAME_FIELD_VALUE_AVI_EXTENDEDCOLORIMETRY_RESERVED07,
    NV_INFOFRAME_FIELD_VALUE_AVI_EXTENDEDCOLORIMETRY_AUTO         = 15
} NV_INFOFRAME_FIELD_VALUE_AVI_EXTENDEDCOLORIMETRY;

typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_ITC_VIDEO_CONTENT = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_ITC_ITCONTENT,
    NV_INFOFRAME_FIELD_VALUE_AVI_ITC_AUTO          = 3
} NV_INFOFRAME_FIELD_VALUE_AVI_ITC;

//! Byte 4 related
typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_NONE = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_X02,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_X03,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_X04,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_X05,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_X06,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_X07,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_X08,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_X09,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_X10,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_RESERVED10,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_RESERVED11,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_RESERVED12,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_RESERVED13,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_RESERVED14,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_RESERVED15,
    NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION_AUTO         = 31
} NV_INFOFRAME_FIELD_VALUE_AVI_PIXELREPETITION;


typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_CONTENTTYPE_GRAPHICS = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_CONTENTTYPE_PHOTO,
    NV_INFOFRAME_FIELD_VALUE_AVI_CONTENTTYPE_CINEMA,
    NV_INFOFRAME_FIELD_VALUE_AVI_CONTENTTYPE_GAME,
    NV_INFOFRAME_FIELD_VALUE_AVI_CONTENTTYPE_AUTO     = 7
} NV_INFOFRAME_FIELD_VALUE_AVI_CONTENTTYPE;

typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AVI_YCCQUANTIZATION_LIMITED_RANGE = 0,
    NV_INFOFRAME_FIELD_VALUE_AVI_YCCQUANTIZATION_FULL_RANGE,
    NV_INFOFRAME_FIELD_VALUE_AVI_YCCQUANTIZATION_RESERVED02,
    NV_INFOFRAME_FIELD_VALUE_AVI_YCCQUANTIZATION_RESERVED03,
    NV_INFOFRAME_FIELD_VALUE_AVI_YCCQUANTIZATION_AUTO          = 7
} NV_INFOFRAME_FIELD_VALUE_AVI_YCCQUANTIZATION;

//! Adding an Auto bit to each field
typedef struct
{
    NvU32 vic                     : 8;
    NvU32 pixelRepeat             : 5;
    NvU32 colorSpace              : 3;
    NvU32 colorimetry             : 3;
    NvU32 extendedColorimetry     : 4;
    NvU32 rgbQuantizationRange    : 3;
    NvU32 yccQuantizationRange    : 3;
    NvU32 itContent               : 2;
    NvU32 contentTypes            : 3;
    NvU32 scanInfo                : 3;
    NvU32 activeFormatInfoPresent : 2;
    NvU32 activeFormatAspectRatio : 5;
    NvU32 picAspectRatio          : 3;
    NvU32 nonuniformScaling       : 3;
    NvU32 barInfo                 : 3;    
    NvU32 top_bar                 : 17;
    NvU32 bottom_bar              : 17;
    NvU32 left_bar                : 17;
    NvU32 right_bar               : 17;
    NvU32 Future17                : 2;
    NvU32 Future47                : 2;
} NV_INFOFRAME_VIDEO;

//! Byte 1 related
typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELCOUNT_IN_HEADER = 0,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELCOUNT_2,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELCOUNT_3,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELCOUNT_4,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELCOUNT_5,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELCOUNT_6,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELCOUNT_7,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELCOUNT_8,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELCOUNT_AUTO      = 15
} NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELCOUNT;

typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_IN_HEADER                  = 0,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_PCM,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_AC3,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_MPEG1,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_MP3,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_MPEG2,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_AACLC,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_DTS,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_ATRAC,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_DSD,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_EAC3,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_DTSHD,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_MLP,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_DST,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_WMAPRO,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_USE_CODING_EXTENSION_TYPE,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE_AUTO                      = 31
} NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGTYPE;

//! Byte 2 related
typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLESIZE_IN_HEADER = 0,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLESIZE_16BITS,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLESIZE_20BITS,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLESIZE_24BITS,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLESIZE_AUTO      = 7
} NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLESIZE;

typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLEFREQUENCY_IN_HEADER = 0,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLEFREQUENCY_32000HZ,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLEFREQUENCY_44100HZ,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLEFREQUENCY_48000HZ,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLEFREQUENCY_88200KHZ,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLEFREQUENCY_96000KHZ,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLEFREQUENCY_176400KHZ,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLEFREQUENCY_192000KHZ,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLEFREQUENCY_AUTO      = 15
} NV_INFOFRAME_FIELD_VALUE_AUDIO_SAMPLEFREQUENCY;



//! Byte 3 related
typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_USE_CODING_TYPE = 0,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_HEAAC,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_HEAACV2,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_MPEGSURROUND,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE04,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE05,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE06,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE07,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE08,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE09,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE10,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE11,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE12,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE13,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE14,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE15,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE16,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE17,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE18,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE19,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE20,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE21,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE22,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE23,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE24,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE25,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE26,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE27,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE28,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE29,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE30,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_RESERVE31,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE_AUTO           = 63
} NV_INFOFRAME_FIELD_VALUE_AUDIO_CODINGEXTENSIONTYPE;


//! Byte 4 related
typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_X_X_X_X_FR_FL           =0,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_X_X_X_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_X_X_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_X_X_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_X_RC_X_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_X_RC_X_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_X_RC_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_X_RC_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_RR_RL_X_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_RR_RL_X_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_X_RR_RL_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_RC_RR_RL_X_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_RC_RR_RL_X_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_RC_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_RC_RR_RL_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_RRC_RLC_RR_RL_X_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_RRC_RLC_RR_RL_X_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_RRC_RLC_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_RRC_RLC_RR_RL_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_X_X_X_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_X_X_X_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_X_X_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_X_X_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_X_RC_X_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_X_RC_X_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_X_RC_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_X_RC_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_RR_RL_X_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_RR_RL_X_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRC_FLC_RR_RL_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_FCH_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_X_FCH_RR_RL_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_TC_X_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_TC_X_RR_RL_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRH_FLH_RR_RL_X_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRH_FLH_RR_RL_X_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRW_FLW_RR_RL_X_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRW_FLW_RR_RL_X_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_TC_RC_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_TC_RC_RR_RL_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FCH_RC_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FCH_RC_RR_RL_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_TC_FCH_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_TC_FCH_RR_RL_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRH_FLH_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRH_FLH_RR_RL_FC_LFE_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRW_FLW_RR_RL_FC_X_FR_FL,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_FRW_FLW_RR_RL_FC_LFE_FR_FL  = 0X31,
    // all other values should default to auto
    NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION_AUTO                        = 0x1FF
} NV_INFOFRAME_FIELD_VALUE_AUDIO_CHANNELALLOCATION;

//! Byte 5 related
typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LFEPLAYBACKLEVEL_NO_DATA    = 0,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LFEPLAYBACKLEVEL_0DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LFEPLAYBACKLEVEL_PLUS10DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LFEPLAYBACKLEVEL_RESERVED03,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LFEPLAYBACKLEVEL_AUTO       = 7
} NV_INFOFRAME_FIELD_VALUE_AUDIO_LFEPLAYBACKLEVEL;

typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_0DB  = 0,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_1DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_2DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_3DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_4DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_5DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_6DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_7DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_8DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_9DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_10DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_11DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_12DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_13DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_14DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_15DB,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES_AUTO = 31
} NV_INFOFRAME_FIELD_VALUE_AUDIO_LEVELSHIFTVALUES;


typedef enum
{
    NV_INFOFRAME_FIELD_VALUE_AUDIO_DOWNMIX_PERMITTED  = 0,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_DOWNMIX_PROHIBITED,
    NV_INFOFRAME_FIELD_VALUE_AUDIO_DOWNMIX_AUTO       = 3
} NV_INFOFRAME_FIELD_VALUE_AUDIO_DOWNMIX;

typedef struct
{
    NvU32 codingType          : 5;
    NvU32 codingExtensionType : 6;
    NvU32 sampleSize          : 3;
    NvU32 sampleRate          : 4;
    NvU32 channelCount        : 4;
    NvU32 speakerPlacement    : 9;
    NvU32 downmixInhibit      : 2;
    NvU32 lfePlaybackLevel    : 3;
    NvU32 levelShift          : 5; 
    NvU32 Future12            : 2;
    NvU32 Future2x            : 4;
    NvU32 Future3x            : 4;
    NvU32 Future52            : 2;
    NvU32 Future6             : 9;
    NvU32 Future7             : 9;
    NvU32 Future8             : 9;
    NvU32 Future9             : 9;
    NvU32 Future10            : 9;
} NV_INFOFRAME_AUDIO;

typedef struct
{
    NvU32 version; //!< version of this structure
    NvU16 size;    //!< size of this structure
    NvU8  cmd;     //!< The actions to perform from NV_INFOFRAME_CMD
    NvU8  type;    //!< type of infoframe
    
    union
    {
        NV_INFOFRAME_PROPERTY     property;  //!< This is NVIDIA-specific and corresponds to the property cmds and associated infoframe.
        NV_INFOFRAME_AUDIO        audio;
        NV_INFOFRAME_VIDEO        video;
    } infoframe;
} NV_INFOFRAME_DATA;

//! Macro for constructing the version field of ::NV_INFOFRAME_DATA
#define NV_INFOFRAME_DATA_VER   MAKE_NVAPI_VERSION(NV_INFOFRAME_DATA,1)

NVAPI_INTERFACE NvAPI_Disp_InfoFrameControl(NvU32 displayId, NV_INFOFRAME_DATA *pInfoframeData);

//! @}



//! \ingroup dispcontrol
//! @{
///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_Disp_ColorControl
//
//! \fn NvAPI_Disp_ColorControl(NvU32 displayId, NV_COLOR_DATA *pColorData)
//! DESCRIPTION:    This API controls the Color values.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]     displayId         Monitor Identifier
//! \param [in,out] pColorData        Contains data corresponding to color information
//!                  
//! \return  RETURN STATUS:
//! ::NVAPI_OK,  
//! ::NVAPI_ERROR, 
//! ::NVAPI_INVALID_ARGUMENT
//
///////////////////////////////////////////////////////////////////////////////

typedef enum
{
    NV_COLOR_CMD_GET                 = 1,
    NV_COLOR_CMD_SET,
    NV_COLOR_CMD_IS_SUPPORTED_COLOR,
    NV_COLOR_CMD_GET_DEFAULT
} NV_COLOR_CMD;

//!  See Table 14 of CEA-861E.  Not all of this is supported by the GPU.
typedef enum
{
    NV_COLOR_FORMAT_RGB             = 0,
    NV_COLOR_FORMAT_YUV422,
    NV_COLOR_FORMAT_YUV444,
    NV_COLOR_FORMAT_DEFAULT         = 0xFE,
    NV_COLOR_FORMAT_AUTO            = 0xFF
} NV_COLOR_FORMAT;



typedef enum
{
    NV_COLOR_COLORIMETRY_RGB             = 0,
    NV_COLOR_COLORIMETRY_YCC601,
    NV_COLOR_COLORIMETRY_YCC709,
    NV_COLOR_COLORIMETRY_XVYCC601,
    NV_COLOR_COLORIMETRY_XVYCC709,
    NV_COLOR_COLORIMETRY_SYCC601,
    NV_COLOR_COLORIMETRY_ADOBEYCC601,
    NV_COLOR_COLORIMETRY_ADOBERGB,
    NV_COLOR_COLORIMETRY_DEFAULT         = 0xFE,
    NV_COLOR_COLORIMETRY_AUTO            = 0xFF
} NV_COLOR_COLORIMETRY;

typedef struct
{
    NvU32 version; //!< Version of this structure
    NvU16 size;    //!< Size of this structure
    NvU8  cmd;
    struct
    {
        NvU8  colorFormat;
        NvU8  colorimetry;
    } data;
} NV_COLOR_DATA;

NVAPI_INTERFACE NvAPI_Disp_ColorControl(NvU32 displayId, NV_COLOR_DATA *pColorData);

//! Macro for constructing the version field of ::NV_COLOR_DATA
#define NV_COLOR_DATA_VER   MAKE_NVAPI_VERSION(NV_COLOR_DATA,1)

//! @}


//! \ingroup dispcontrol
//! @{
 
///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_DISP_GetVirtualModeData
//
//! \fn NvAPI_DISP_GetVirtualModeData(NvU32 displayId, NV_VIRTUALMODE_DATA *virtualModeData)
//! DESCRIPTION:     This API lets the caller get state information related to
//!                  virtual mode.  See NvAPI_DISP_OverrideDisplayModeList().
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]      displayId        Display ID of display to override the
//!                                            mode list. Retrieved from 
//!                                            NvAPI_SYS_GetDisplayIdFromGpuAndOutputId().
//! \param [in,out]  virtualModeData  The type of information to retrieve
//!
//! \return 
//! ::NVAPI_OK,  
//! ::NVAPI_API_NOT_INTIALIZED,  
//! ::NVAPI_ERROR,  
//! ::NVAPI_INVALID_ARGUMENT
//
///////////////////////////////////////////////////////////////////////////////
typedef enum
{
    NV_VIRTUALMODE_CMD_GET_INFO = 1,
} NV_VIRTUALMODE_CMD;

typedef struct
{
    NvU32 isCapableOfVirtualMode : 1;  //!< Set to 1 if system is capable of supporting virtual mode
    NvU32 isInVirtualMode        : 1;  //!< Set to 1 if system is currently in virtual mode; 0, otherwise
    NvU32 reserved               : 30;
} NV_VIRTUALMODE_INFO;

typedef struct
{
    NvU32               version;
    NV_VIRTUALMODE_CMD  cmd;
    union
    {
        NV_VIRTUALMODE_INFO virtualModeInfo;
    } data;
} NV_VIRTUALMODE_DATA;

//! Macro for constructing the version field of ::NV_VIRTUALMODE_DATA
#define NV_VIRTUALMODE_DATA_VER   MAKE_NVAPI_VERSION(NV_VIRTUALMODE_DATA,1)

NVAPI_INTERFACE NvAPI_DISP_GetVirtualModeData(NvU32 displayId, NV_VIRTUALMODE_DATA *virtualModeData);

//! @}




//! \ingroup dispcontrol
//! @{
///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_DISP_OverrideDisplayModeList
//
//! \fn NvAPI_DISP_OverrideDisplayModeList(NvU32 displayId, NvU32 modeCount, NV_DISPLAY_MODE_INFO* modeList, NvU32 enableOutput)
//! DESCRIPTION:     This API lets the caller override the Display Mode List.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]       displayId     Display ID of display to override the
//!                                 mode list. Retrieved from 
//!                                 NvAPI_SYS_GetDisplayIdFromGpuAndOutputId().
//! \param [in]       modeCount     Number of supplied elements in modeList - 
//!                                 passing in 0 will disable mode list override.
//! \param [in]       modeList      Array of NV_DISPLAY_MODE_INFO elements. Pass
//!                                 in NULL with modeCount is 0.
//! \param [in]       enableOutput  when set allows monitor output; must be 0
//!                                 if modeCount is 0.
//!
//! \return 
//! ::NVAPI_OK,  
//! ::NVAPI_API_NOT_INTIALIZED,  
//! ::NVAPI_ERROR,  
//! ::NVAPI_INVALID_ARGUMENT 
//
///////////////////////////////////////////////////////////////////////////////


typedef struct _NV_DISPLAY_MODE_INFO
{
    NvU32    version;
    NvU32    width;
    NvU32    height;
    NvU32    depth;
    NvU32    refreshRate1K;         //!< Refresh rate * 1000
    NvU32    preferred      :  1;   //!< Set to true if a preferred mode, false for non-preferred
    NvU32    reserved       : 31;
} NV_DISPLAY_MODE_INFO;

//! Macro for contructing the version field of ::NV_DISPLAY_MODE_INFO
#define NV_DISPLAY_MODE_INFO_VER   MAKE_NVAPI_VERSION(NV_DISPLAY_MODE_INFO,1)

NVAPI_INTERFACE NvAPI_DISP_OverrideDisplayModeList(NvU32 displayId, NvU32 modeCount, NV_DISPLAY_MODE_INFO* modeList, NvU32 enableOutput);

//! @}




//! \ingroup driverapi
//! Used in NvAPI_GPU_GetMemoryInfo().
typedef struct 
{
    NvU32   version;                        //!< Version info
    NvU32   dedicatedVideoMemory;           //!< Size(in kb) of the physical framebuffer.
    NvU32   availableDedicatedVideoMemory;  //!< Size(in kb) of the available physical framebuffer for allocating video memory surfaces.
    NvU32   systemVideoMemory;              //!< Size(in kb) of system memory the driver allocates at load time.
    NvU32   sharedSystemMemory;             //!< Size(in kb) of shared system memory that driver is allowed to commit for surfaces across all allocations.

} NV_DISPLAY_DRIVER_MEMORY_INFO_V1;

//! \ingroup driverapi
//! Used in NvAPI_GPU_GetMemoryInfo().
typedef struct
{
    NvU32   version;                           //!< Version info
    NvU32   dedicatedVideoMemory;              //!< Size(in kb) of the physical framebuffer.
    NvU32   availableDedicatedVideoMemory;     //!< Size(in kb) of the available physical framebuffer for allocating video memory surfaces.
    NvU32   systemVideoMemory;                 //!< Size(in kb) of system memory the driver allocates at load time.
    NvU32   sharedSystemMemory;                //!< Size(in kb) of shared system memory that driver is allowed to commit for surfaces across all allocations.
    NvU32   curAvailableDedicatedVideoMemory;  //!< Size(in kb) of the current available physical framebuffer for allocating video memory surfaces.

} NV_DISPLAY_DRIVER_MEMORY_INFO_V2;


//! \ingroup driverapi
typedef NV_DISPLAY_DRIVER_MEMORY_INFO_V2 NV_DISPLAY_DRIVER_MEMORY_INFO;

//! \ingroup driverapi
//! Macro for constructing the version field of NV_DISPLAY_DRIVER_MEMORY_INFO_V1
#define NV_DISPLAY_DRIVER_MEMORY_INFO_VER_1  MAKE_NVAPI_VERSION(NV_DISPLAY_DRIVER_MEMORY_INFO_V1,1)

//! \ingroup driverapi
//! Macro for constructing the version field of NV_DISPLAY_DRIVER_MEMORY_INFO_V2
#define NV_DISPLAY_DRIVER_MEMORY_INFO_VER_2  MAKE_NVAPI_VERSION(NV_DISPLAY_DRIVER_MEMORY_INFO_V2,2)

//! \ingroup driverapi
#define NV_DISPLAY_DRIVER_MEMORY_INFO_VER    NV_DISPLAY_DRIVER_MEMORY_INFO_VER_2



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetDisplayDriverMemoryInfo
//
//! This function retrieves the display driver memory information for the active display handle. \n 
//! In a multi-GPU scenario, the physical framebuffer information is obtained for the GPU associated with active display handle. \n
//! In an SLI-mode scenario, the physical framebuffer information is obtained only from the display owner GPU. \n
//!
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 96.60
//!
//! \param [in]  hNvDisplay   NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [out] pMemoryInfo  The memory footprint available in the driver.
//!
//! \retval  NVAPI_INVALID_ARGUMENT             pMemoryInfo is NULL.
//! \retval  NVAPI_OK                           Call successful.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND      No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_DISPLAY_HANDLE      hNvDisplay is not a valid display handle.
//! \retval  NVAPI_INCOMPATIBLE_STRUCT_VERSION  NV_DISPLAY_DRIVER_MEMORY_INFO structure version mismatch.
//! \ingroup driverapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetDisplayDriverMemoryInfo(NvDisplayHandle hNvDisplay, NV_DISPLAY_DRIVER_MEMORY_INFO *pMemoryInfo);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetDriverMemoryInfo
//
//! \fn NvAPI_GetDriverMemoryInfo(NvDisplayHandle hNvDisplay, NV_DRIVER_MEMORY_INFO *pMemoryInfo)
//!   DESCRIPTION: This function retrieves the display driver memory information for the active display handle. 
//!                In case of a multi-GPU scenario the physical framebuffer information is obtained for the GPU
//!                associated with the active display handle.
//!                In the case of SLI, the physical framebuffer information is obtained only from the display owner GPU.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 177.32
//!
//! \param [in]   hNvDisplay        NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [out]  pMemoryInfo       The memory footprint available in the driver.
//!
//! \retval ::NVAPI_INVALID_ARGUMENT
//! \retval ::NVAPI_OK
//! \retval ::NVAPI_NVIDIA_DEVICE_NOT_FOUND
//! \retval ::NVAPI_EXPECTED_DISPLAY_HANDLE 
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION   NV_DISPLAY_DRIVER_MEMORY_INFO structure version mismatch.
//
///////////////////////////////////////////////////////////////////////////////

 
//! \ingroup driverapi
//! Driver memory information - used in NvAPI_GetDriverMemoryInfo().
typedef struct 
{
    NvU32   version;                        //!< Version info
    NvU32   dedicatedVideoMemory;           //!< Size(in kb) of the physical framebuffer.
    NvU32   systemVideoMemory;              //!< Size(in kb) of system memory the driver allocates at load time.
    NvU32   sharedSystemMemory;             //!< Size(in kb) of shared system memory that driver is allowed to commit for surfaces across all allocations.

} NV_DRIVER_MEMORY_INFO;

//! \ingroup driverapi
//! Used in NV_DRIVER_MEMORY_INFO.
#define NV_DRIVER_MEMORY_INFO_VER   MAKE_NVAPI_VERSION(NV_DRIVER_MEMORY_INFO,1)


//! \ingroup driverapi 
NVAPI_INTERFACE NvAPI_GetDriverMemoryInfo(NvDisplayHandle hNvDisplay, NV_DRIVER_MEMORY_INFO *pMemoryInfo);





//! \ingroup dispcontrol
//! Used in NvAPI_GetDVCInfo()
typedef struct
{
    NvU32   version;            //!< [IN] Version info  
    NvU32   currentLevel;       //!< [OUT] The current DVC level
    NvU32   minLevel;           //!< [OUT] Minimim range level
    NvU32   maxLevel;           //!< [OUT] Maximum range level
} NV_DISPLAY_DVC_INFO;

//! \ingroup dispcontrol
#define NV_DISPLAY_DVC_INFO_VER  MAKE_NVAPI_VERSION(NV_DISPLAY_DVC_INFO,1)


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetDVCInfo
//
//! This function retrieves the Digital Vibrance Control (DVC) information of the selected display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 96.80
//!
//! \param [in]  hNvDisplay  NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  outputId    One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or NvAPI_GetView(), to identify the target 
//!                          output in case multiple targets are associated with the selected hNvDisplay. 
//!                          Can be NULL to pick the display output ID associated with hNvDisplay. See \ref handles.
//! \param [out] pDVCInfo    The returned DVC information.
//!
//! \retval  NVAPI_OK                           Call successful.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND      No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_DISPLAY_HANDLE      hNvDisplay is not a valid display handle.
//! \retval  NVAPI_INVALID_ARGUMENT             pDVCInfo is NULL.
//! \retval  NVAPI_INCOMPATIBLE_STRUCT_VERSION  The version of the NV_DISPLAY_DVC_INFO struct is not supported
//! \retval  NVAPI_NOT_SUPPORTED                DVC feature is not supported on the selected GPU
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetDVCInfo(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_DISPLAY_DVC_INFO *pDVCInfo);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_SetDVCLevel
//
//!  This function sets the DVC level for the selected display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 96.80
//!
//! \param [in]  hNvDisplay      NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  outputId        One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or NvAPI_GetView(), to identify the target 
//!                              output in case multiple targets are associated with the selected hNvDisplay.
//!                              Can be NULL to pick the display output id associated with hNvDisplay. See \ref handles.
//! \param [out] level           The new level to apply. Value should be within the range of min and max.
//!
//! \retval  NVAPI_OK                       Call successful.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_DISPLAY_HANDLE  hNvDisplay is not a valid display handle.
//! \retval  NVAPI_NOT_SUPPORTED            DVC is not supported on the selected GPU
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetDVCLevel(NvDisplayHandle hNvDisplay, NvU32 outputId, NvU32 level);



//! \ingroup dispcontrol
//! Used in NvAPI_GetDVCInfoEx() and NvAPI_SetDVCLevelEx()
typedef struct
{
    NvU32   version;            //!< IN version info  
    NvS32   currentLevel;       //!< OUT current DVC level
    NvS32   minLevel;           //!< OUT min range level
    NvS32   maxLevel;           //!< OUT max range level
    NvS32   defaultLevel;       //!< OUT default DVC level
} NV_DISPLAY_DVC_INFO_EX;

//! \ingroup dispcontrol
//! Macro for constucting the version field of NV_DISPLAY_DVC_INFO_EX
#define NV_DISPLAY_DVC_INFO_EX_VER  MAKE_NVAPI_VERSION(NV_DISPLAY_DVC_INFO_EX,1)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetDVCInfoEx
//
//!   DESCRIPTION: This API retrieves the Digital Vibrance Control(DVC) information of the selected display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.50
//!
//! \param [in]  hNvDisplay   NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  outputId     One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or NvAPI_GetView(), to identify the target
//!                           output in case multiple targets are associated with the selected hNvDisplay.
//!                           Can be NULL to pick the display output ID associated with hNvDisplay.
//! \param [out] pDVCInfo     The returned DVC information.
//!
//! \retval ::NVAPI_OK: call successful.
//! \retval ::NVAPI_NVIDIA_DEVICE_NOT_FOUND: no NVIDIA GPU driving a display was found.
//! \retval ::NVAPI_EXPECTED_DISPLAY_HANDLE: hNvDisplay is not a valid display handle.
//! \retval ::NVAPI_INVALID_ARGUMENT: pDVCInfo is NULL.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION - the version of the NV_DISPLAY_DVC_INFO struct is not supported
//! \retval ::NVAPI_NOT_SUPPORTED - DVC feature is not supported on the selected GPU
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetDVCInfoEx(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_DISPLAY_DVC_INFO_EX *pDVCInfo);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_SetDVCLevelEx
//
//!   DESCRIPTION: This API sets the DVC level for the selected display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.50
//!
//! \param [in] hNvDisplay  NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in] outputId    One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or NvAPI_GetView(), to identify the target
//!                         output in case multiple targets are associated with the selected hNvDisplay.
//!                         Can be NULL to pick the display output ID associated with hNvDisplay.
//! \param [in] dvcInfo     The new DVC to apply. This structure can be accessed by GetDVCInfo() API.
//!
//! \retval ::NVAPI_OK                       Call successful.
//! \retval ::NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found.
//! \retval ::NVAPI_EXPECTED_DISPLAY_HANDLE  hNvDisplay is not a valid display handle.
//! \retval ::NVAPI_NOT_SUPPORTED            DVC is not supported on the selected GPU
//!
//! \ingroup dispcontrol 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetDVCLevelEx(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_DISPLAY_DVC_INFO_EX *pDVCInfo);



//! \ingroup dispcontrol
//! Used in NvAPI_GetHUEInfo()
typedef struct
{
    NvU32   version;            //!< IN Version info
    NvU32   currentHueAngle;    //!< OUT Current HUE Angle. Typically between 0 - 360 degrees
    NvU32   defaultHueAngle;    //!< OUT Default HUE Angle
} NV_DISPLAY_HUE_INFO;

//! \ingroup dispcontrol
//! Macro for constructing the version field of NV_DISPLAY_HUE_INFO 
#define NV_DISPLAY_HUE_INFO_VER  MAKE_NVAPI_VERSION(NV_DISPLAY_HUE_INFO,1)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetHUEInfo
//
//!   DESCRIPTION: This API retrieves the HUE information of the selected display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.50
//!
//! \param [in] hNvDisplay   NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in] outputId     One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or NvAPI_GetView(), to identify the target 
//!                          output in case multiple targets are associated with the selected hNvDisplay.
//!                          Can be NULL to pick the display output id associated with hNvDisplay.
//! \param [out] pHUEInfo    The returned HUE information.
//!
//! \retval ::NVAPI_OK                        Call successful.
//! \retval ::NVAPI_NVIDIA_DEVICE_NOT_FOUND   No NVidia GPU driving a display was found.
//! \retval ::NVAPI_EXPECTED_DISPLAY_HANDLE   hNvDisplay is not a valid display handle.
//! \retval ::NVAPI_INVALID_ARGUMENT          pHUEInfo is NULL.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  The version of the NV_DISPLAY_HUE_INFO struct is not supported
//! \retval ::NVAPI_NOT_SUPPORTED             HUE feature is not supported on the selected GPU
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetHUEInfo(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_DISPLAY_HUE_INFO *pHUEInfo);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_SetHUEAngle
//
//!  DESCRIPTION: This API sets the HUE level for the selected display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.50
//!
//! \param [in]  hNvDisplay  NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  outputId    One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or NvAPI_GetView(), to identify the target 
//!                          output in case multiple targets are associated with the selected hNvDisplay.
//!                          Can be NULL to pick the display output ID associated with hNvDisplay.
//! \param [in]  level       The new level to apply. Value should be within the range of minimum and maximum.
//!
//! \retval ::NVAPI_OK                        Call successful.
//! \retval ::NVAPI_NVIDIA_DEVICE_NOT_FOUND   No NVidia GPU driving a display was found.
//! \retval ::NVAPI_EXPECTED_DISPLAY_HANDLE   hNvDisplay is not a valid display handle.
//! \retval ::NVAPI_NOT_SUPPORTED             HUE feature is not supported on the selected GPU.
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetHUEAngle(NvDisplayHandle hNvDisplay, NvU32 outputId, NvU32 hueAngle);





//! \ingroup dispcontrol
//! Used in NvAPI_GetImageSharpeningInfo()
typedef struct
{
    NvU32   version;            //!< IN version info
    NvU32   currentLevel;       //!< OUT current Image Sharpening level
    NvU32   minLevel;           //!< OUT min range level
    NvU32   maxLevel;           //!< OUT max range level
} NV_DISPLAY_IMAGE_SHARPENING_INFO;

//! \ingroup dispcontrol
#define NV_DISPLAY_IMAGE_SHARPENING_INFO_VER  MAKE_NVAPI_VERSION(NV_DISPLAY_IMAGE_SHARPENING_INFO,1)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetImageSharpeningInfo
//
//!  This function retrieves the Image Sharpening information of the selected display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 96.80
//!
//! \param [in]  hNvDisplay            NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  outputId              One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or NvAPI_GetView(), to identify the target 
//!                                    output in case multiple targets are associated with the selected hNvDisplay.
//!                                    Can be NULL to pick the display output id associated with hNvDisplay. See \ref handles.
//! \param [out] pImageSharpeningInfo  The returned Image Sharpening information.
//!
//! \retval  NVAPI_OK: call successful.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND      No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_DISPLAY_HANDLE      hNvDisplay is not a valid display handle.
//! \retval  NVAPI_INVALID_ARGUMENT             pImageSharpeningInfo is NULL.
//! \retval  NVAPI_INCOMPATIBLE_STRUCT_VERSION  The version of the NV_DISPLAY_IMAGE_SHARPENING_INFO struct is not supported
//! \retval  NVAPI_NOT_SUPPORTED                Image Sharpening is not supported on the selected GPU
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetImageSharpeningInfo(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_DISPLAY_IMAGE_SHARPENING_INFO *pImageSharpeningInfo);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_SetImageSharpeningLevel
//
//!  This function sets the Image Sharpening level for the selected display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 96.80
//!
//! \param [in]   hNvDisplay  NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]   outputId    One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or NvAPI_GetView(), to identify the target 
//!                           output in case multiple targets are associated with the selected hNvDisplay. 
//!                           Can be NULL to pick the display output id associated with hNvDisplay. See \ref handles.
//! \param [in]   level       The new level to apply. Value should be within the range of min and max.
//!
//! \retval  NVAPI_OK                       Call successful.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_DISPLAY_HANDLE  hNvDisplay is not a valid display handle.
//! \retval  NVAPI_NOT_SUPPORTED            Image Sharpening is not supported on the selected GPU
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetImageSharpeningLevel(NvDisplayHandle hNvDisplay, NvU32 outputId, NvU32 level);



//-----------------------------------------------------------------------------
// DirectX APIs
//-----------------------------------------------------------------------------


//! \ingroup dx
//! Used in NvAPI_D3D10_GetCurrentSLIState(), and NvAPI_D3D_GetCurrentSLIState().
typedef struct
{
    NvU32 version;                    //!< Structure version
    NvU32 maxNumAFRGroups;            //!< [OUT] The maximum possible value of numAFRGroups
    NvU32 numAFRGroups;               //!< [OUT] The number of AFR groups enabled in the system
    NvU32 currentAFRIndex;            //!< [OUT] The AFR group index for the frame currently being rendered
    NvU32 nextFrameAFRIndex;          //!< [OUT] What the AFR group index will be for the next frame (i.e. after calling Present)
    NvU32 previousFrameAFRIndex;      //!< [OUT] The AFR group index that was used for the previous frame (~0 if more than one frame has not been rendered yet)
    NvU32 bIsCurAFRGroupNew;          //!< [OUT] Boolean: Is this frame the first time running on the current AFR group

} NV_GET_CURRENT_SLI_STATE;

//! \ingroup dx
#define NV_GET_CURRENT_SLI_STATE_VER  MAKE_NVAPI_VERSION(NV_GET_CURRENT_SLI_STATE,1)




#if defined(_D3D9_H_) || defined(__d3d10_h__) || defined(__d3d11_h__)

NV_DECLARE_HANDLE(NVDX_ObjectHandle);  // DX Objects
static const NVDX_ObjectHandle NVDX_OBJECT_NONE = 0;

#endif //if defined(_D3D9_H_) || defined(__d3d10_h__) || defined(__d3d11_h__)



#if defined(_D3D9_H_) || defined(__d3d10_h__) || defined(__d3d11_h__)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D_GetCurrentSLIState
//
//! DESCRIPTION:     This function returns the current SLI state for the specified device.  The structure
//!                  contains the number of AFR groups, the current AFR group index,
//!                  and what the AFR group index will be for the next frame. \p
//!                  pDevice can be either a IDirect3DDevice9 or ID3D10Device pointer.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 174.80
//!
//! \retval         NVAPI_OK     Completed request
//! \retval         NVAPI_ERROR  Error occurred
//!
//! \ingroup  dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D_GetCurrentSLIState(IUnknown *pDevice, NV_GET_CURRENT_SLI_STATE *pSliState);

#endif //if defined(_D3D9_H_) || defined(__d3d10_h__) || defined(__d3d11_h__)

#if defined(_D3D9_H_)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_RegisterResource
//
//! DESCRIPTION:    This API binds a resource (surface/texture) so that it can be retrieved
//!                 internally by NVAPI.
//!
//  SUPPORTED OS: Windows XP and higher
//! \param [in]     pResource      surface/texture
//!
//! \return ::NVAPI_OK, ::NVAPI_ERROR 
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_RegisterResource(IDirect3DResource9* pResource);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_UnregisterResource
//
//! DESCRIPTION:     This API unbinds a resource (surface/texture) after use.
//!
//  SUPPORTED OS: Windows XP and higher
//! 
//! \param [in]     pResource    surface/texture
//!
//! \return ::NVAPI_OK, ::NVAPI_ERROR 
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_UnregisterResource(IDirect3DResource9* pResource);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_AliasSurfaceAsTexture
//
//! \fn NvAPI_D3D9_AliasSurfaceAsTexture(IDirect3DDevice9* pDev,
//!                                              IDirect3DSurface9* pSurface,
//!                                              IDirect3DTexture9 **ppTexture,
//!                                              DWORD dwFlag);
//!   DESCRIPTION: Create a texture that is an alias of a surface registered with NvAPI.  The
//!                new texture can be bound with IDirect3DDevice9::SetTexture().  Note that the texture must
//!                be unbound before drawing to the surface again.
//!                Unless the USE_SUPER flag is passed, MSAA surfaces will be resolved before
//!                being used as a texture.  MSAA depth buffers are resolved with a point filter,
//!                and non-depth MSAA surfaces are resolved with a linear filter.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]    pDev         The D3D device that owns the objects
//! \param [in]    pSurface     Pointer to a surface that has been registered with NvAPI 
//!                             to which a texture alias is to be provided
//! \param [out]   ppTexture    Fill with the texture created
//! \param [in]    dwFlag       NVAPI_ALIAS_SURFACE_FLAG to describe how to handle the texture
//!
//! \retval ::NVAPI_OK                  completed request
//! \retval ::NVAPI_INVALID_POINTER     A null pointer was passed as an argument
//! \retval ::NVAPI_INVALID_ARGUMENT    One of the arguments was invalid, probably dwFlag.
//! \retval ::NVAPI_UNREGISTERED_RESOURCE pSurface has not been registered with NvAPI
//! \retval ::NVAPI_ERROR               error occurred
//
///////////////////////////////////////////////////////////////////////////////


//! \ingroup dx
//! See NvAPI_D3D9_AliasSurfaceAsTexture().
typedef enum {
    NVAPI_ALIAS_SURFACE_FLAG_NONE                     = 0x00000000,
    NVAPI_ALIAS_SURFACE_FLAG_USE_SUPER                = 0x00000001,  //!< Use the surface's msaa buffer directly as a texture, rather than resolving. (This is much slower, but potentially has higher quality.)
    NVAPI_ALIAS_SURFACE_FLAG_MASK                     = 0x00000001
} NVAPI_ALIAS_SURFACE_FLAG;


//! \ingroup dx
NVAPI_INTERFACE NvAPI_D3D9_AliasSurfaceAsTexture(IDirect3DDevice9* pDev,
                                                 IDirect3DSurface9* pSurface,
                                                 IDirect3DTexture9 **ppTexture,
                                                 DWORD dwFlag);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_StretchRectEx
//
//! DESCRIPTION:     This API copies the contents of the source resource to the destination
//!                  resource.  This function can convert
//!                  between a wider range of surfaces than
//!                  IDirect3DDevice9::StretchRect.  For example, it can copy
//!                  from a depth/stencil surface to a texture.
//!
//!                  The source and destination resources *must* be registered
//!                  with NvAPI before being used with NvAPI_D3D9_StretchRectEx().
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]     pDevice             The D3D device that owns the objects.
//! \param [in]     pSourceResource     Pointer to the source resource.
//! \param [in]     pSrcRect            Defines the rectangle on the source to copy from.  If NULL, copy from the entire resource.
//! \param [in]     pDestResource       Pointer to the destination resource.
//! \param [in]     pDstRect            Defines the rectangle on the destination to copy to.  If NULL, copy to the entire resource.
//! \param [in]     Filter              Choose a filtering method: D3DTEXF_NONE, D3DTEXF_POINT, D3DTEXF_LINEAR.
//!
//! \retval ::NVAPI_OK                       completed request
//! \retval ::NVAPI_INVALID_POINTER          An invalid pointer was passed as an argument (probably NULL)
//! \retval ::NVAPI_INVALID_ARGUMENT         One of the arguments was invalid
//! \retval ::NVAPI_UNREGISTERED_RESOURCE    a resource was passed in without being registered
//! \retval ::NVAPI_ERROR                    error occurred
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_StretchRectEx(IDirect3DDevice9 * pDevice,
                                         IDirect3DResource9 * pSourceResource,
                                         CONST RECT * pSourceRect,
                                         IDirect3DResource9 * pDestResource,
                                         CONST RECT * pDestRect,
                                         D3DTEXTUREFILTERTYPE Filter);


#endif //if defined(_D3D9_H_)




#if defined(_D3D9_H_) || defined(__d3d10_h__)

///////////////////////////////////////////////////////////////////////////////
// NVAPI Query Types
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dx
//! Used in NvAPI_D3D_CreateQuery() and NvAPI_D3D_Query_GetType().
typedef enum _NVAPI_D3D_QUERY_TYPE
{
    NVAPI_D3D_QUERY_TYPE_RESERVED0       = 0,
    NVAPI_D3D_QUERY_TYPE_RESERVED1       = 1,
    NVAPI_D3D_QUERY_TYPE_RESERVED2       = 2,
    NVAPI_D3D_QUERY_TYPE_RESERVED3       = 3,
    NVAPI_D3D_QUERY_TYPE_RESERVED4       = 4,
}NVAPI_D3D_QUERY_TYPE;


//! \ingroup dx
//! See NvAPI_D3D_Query_GetData().
typedef enum _NVAPI_D3D_QUERY_GETDATA_FLAGS
{
    NVAPI_D3D_QUERY_GETDATA_FLUSH      = 0,
    NVAPI_D3D_QUERY_GETDATA_DONOTFLUSH = 1
}NVAPI_D3D_QUERY_GETDATA_FLAGS;


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D_CreateQuery
//
//! DESCRIPTION:     This API creates NVIDIA-specific D3D Query Objects. For DirectX 11, if a device is supplied the query will
//!                  always execute on the immediate context.  This makes sense for almost all queries since GetData is
//!                  invalid on deferred contexts. If a DirectX 11 context is supplied, the query will always execute on that context.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 185.20
//!
//! \param [in]      pDeviceOrContext    The D3D9, D3D10, D3D11 device, or D3D11 device context to create this query object on
//! \param [in]      type                Type of the query to be created (see NVAPI_D3D_QUERY_TYPE)
//! \param [out]     pHandle             The handle to the Query object
//!
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_INVALID_POINTER - pDevice was NULL
//! \retval ::NVAPI_INVALID_ARGUMENT - one of the arguments was not valid
//! \retval ::NVAPI_OUT_OF_MEMORY - unable to allocate sufficient memory to complete the call
//! \retval ::NVAPI_ERROR - error occurred
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D_CreateQuery(IUnknown *pDeviceOrContext, NVAPI_D3D_QUERY_TYPE type, NVDX_ObjectHandle *pHandle);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D_DestroyQuery
//
//! DESCRIPTION:    This API destroys NVIDIA-specific Direct3D query objects.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 185.20
//!
//! \param [in]    queryHandle      The handle to the Query object
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_INVALID_HANDLE  The Query object handle is invalid.
//! \retval ::NVAPI_INVALID_CALL    The call could not be completed.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D_DestroyQuery(NVDX_ObjectHandle queryHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D_Query_Begin
//
//! DESCRIPTION:     This API mark the beginning of a series of commands.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 185.20
//!
//! \param [in]    queryHandle      The handle to the Query object
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_INVALID_HANDLE  The Query object handle is invalid.
//! \retval ::NVAPI_INVALID_CALL    The call could not be completed.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D_Query_Begin(NVDX_ObjectHandle queryHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D_Query_End
//
//! DESCRIPTION:    This API marks the end of a series of commands.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 185.20
//!
//! \param [in]    queryHandle      The handle to the Query object
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_INVALID_HANDLE  The Query object handle is invalid.
//! \retval ::NVAPI_INVALID_CALL    The call could not be completed.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D_Query_End(NVDX_ObjectHandle queryHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D_Query_GetData
//
//! DESCRIPTION:     This API polls a queried resource to get the query state or a query result.
//!                  This makes it possible to get data from the GPU or the driver asynchronously.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 185.20
//!
//! \param [in]     queryHandle         The handle to the Query object
//! \param [in]     dwSize              Size of the data to retrieve or 0;
//!                                     This value can be obtained with NvAPI_D3D_Query_GetDataSize().
//! \param [in]     dwGetDataFlags      Optional flags; can be 0 or any combination of NVAPI_D3D_QUERY_GETDATA_FLAGS
//! \param [out]    pData               Address of memory that will receive the data 
//!                                     If NULL, GetData will be used only to check status.
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_INVALID_HANDLE  The Query object handle is invalid
//! \retval ::NVAPI_INVALID_CALL    The call could not be completed
//! \retval ::NVAPI_DATA_NOT_FOUND  The Queried data was not yet available
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D_Query_GetData(NVDX_ObjectHandle queryHandle, void* pData, UINT dwSize, UINT dwGetDataFlags);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D_Query_GetDataSize
//
//! DESCRIPTION:    This API gets the size of the data (in bytes) that is output when calling
//!                 NvAPI_D3D_Query_GetData().
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 185.20
//!
//! \param [in]     queryHandle         The handle to the Query object
//! \param [out]    pDwSize             The requested size
//! 
//! \retval ::NVAPI_OK             
//! \retval ::NVAPI_INVALID_HANDLE   the Query object handle is invalid
//! \retval ::NVAPI_INVALID_POINTER  pDwSize is NULL
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D_Query_GetDataSize(NVDX_ObjectHandle queryHandle, UINT *pDwSize);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D_Query_GetType
//
//! DESCRIPTION:    This API gets the NVAPI_D3D_QUERY_TYPE of the given query object.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 185.20
//!
//! \param [in]    queryHandle         The handle to the Query object
//! \param [out]   pType               The requested NVAPI_D3D_QUERY_TYPE value
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_INVALID_HANDLE   the Query object handle is invalid
//! \retval ::NVAPI_INVALID_POINTER  pType is NULL
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D_Query_GetType(NVDX_ObjectHandle queryHandle, NVAPI_D3D_QUERY_TYPE *pType);




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D_RegisterApp
//
//! DESCRIPTION:    This API allows known DirectX 11, DirectX 10, or DirectX 9 applications to register themselves in order to enable specific driver modes.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 180.80
//!
//! \param [in] userAppId  A predetermined NVIDIA-specified number that the driver uses to 
//!                        turn on application-specific features.
//!                        If the code is not recognized, it would return ::NVAPI_NOT_SUPPORTED.
//!                        Otherwise, it would return ::NVAPI_OK.
//!
//! \retval ::NVAPI_ERROR             Registration failed.
//! \retval ::NVAPI_OK                The application is supported.
//! \retval ::NVAPI_INVALID_ARGUMENT  Bad parameters were given.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D_RegisterApp(IUnknown *pDev, NvU32 userAppId);


#endif // defined(_D3D9_H_) || defined(__d3d10_h__)




//-----------------------------------------------------------------------------
// Direct3D9 APIs
//-----------------------------------------------------------------------------

#if defined(_D3D9_H_) && defined(__cplusplus)

//! \ingroup dx
//! @{

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_CreatePathContextNV
//
//! \fn NvAPI_D3D9_CreatePathContextNV(IDirect3DDevice9* pDevice, NvU32* context)
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Creates a new NVPL context.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   pDevice  Direct3D 9 device
//! \param [out]  context  NVPL context
//!
//!\return NvAPI status code or DX HRESULT code
//
///////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------------------
// NV Path Library data types
//--------------------------------------------------------------------------------------

typedef enum _NV_PATH_DATATYPE
{
    NV_BYTE						= 0,
    NV_UNSIGNED_BYTE,
    NV_SHORT,
    NV_UNSIGNED_SHORT,
    NV_INT,
    NV_UNSIGNED_INT,
    NV_FLOAT,
    NV_FIXED
} NvPathDataType;

typedef enum _NV_PATH_PARAMTYPE
{
    PATH_QUALITY_NV             = 0x8ED8,
    FILL_RULE_NV                = 0x8ED9,
    STROKE_CAP0_STYLE_NV        = 0x8EE0,
    STROKE_CAP1_STYLE_NV        = 0x8EE1,
    STROKE_CAP2_STYLE_NV        = 0x8EE2,
    STROKE_CAP3_STYLE_NV        = 0x8EE3,
    STROKE_JOIN_STYLE_NV        = 0x8EE8,
    STROKE_MITER_LIMIT_NV       = 0x8EE9
} NVPathParamType;

typedef enum _NV_PATH_FILLRULE
{
    EVEN_ODD_NV                 = 0x8EF0,
    NON_ZERO_NV                 = 0x8EF1
} NVPathFillRule;

typedef enum _NV_PATH_CAPSTYLE
{
    CAP_BUTT_NV                 = 0x8EF4,
    CAP_ROUND_NV                = 0x8EF5,
    CAP_SQUARE_NV               = 0x8EF6,
    CAP_TRIANGLE_NV             = 0x8EF7
} NVPathCapStyle;

typedef enum _NV_PATH_JOINSTYLE
{
    JOIN_MITER_NV               = 0x8EFC,
    JOIN_ROUND_NV               = 0x8EFD,
    JOIN_BEVEL_NV               = 0x8EFE,
    JOIN_CLIPPED_MITER_NV       = 0x8EFF
} NVPathJoinStyle;

typedef enum _NV_PATH_TARGETTYPE
{
    MATRIX_PATH_TO_CLIP_NV      = 0x8F04,
    MATRIX_STROKE_TO_PATH_NV    = 0x8F05,
    MATRIX_PATH_COORD0_NV       = 0x8F08,
    MATRIX_PATH_COORD1_NV       = 0x8F09,
    MATRIX_PATH_COORD2_NV       = 0x8F0A,
    MATRIX_PATH_COORD3_NV       = 0x8F0B
} NVPathTargetType;

typedef enum _NV_PATH_MODE
{
    FILL_PATH_NV                = 0x8F18,
    STROKE_PATH_NV              = 0x8F19
} NVPathMode;

typedef enum _NV_PATH_CMD
{
    MOVE_TO_NV                  = 0x00,
    LINE_TO_NV                  = 0x01,
    QUADRATIC_BEZIER_TO_NV      = 0x02,
    CUBIC_BEZIER_TO_NV          = 0x03,
    START_MARKER_NV             = 0x20,
    CLOSE_NV                    = 0x21,
    STROKE_CAP0_NV              = 0x40,
    STROKE_CAP1_NV              = 0x41,
    STROKE_CAP2_NV              = 0x42,
    STROKE_CAP3_NV              = 0x43,
} NVPathCmd;


NVAPI_INTERFACE NvAPI_D3D9_CreatePathContextNV(IDirect3DDevice9* pDevice, NvU32* context);

//! @}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_DestroyPathContextNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Destroys a NVPL context. This function *MUST* be called
//!					on all created path contexts or else memory leaks will
//!					occur.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]	  context  NVPL context
//!
//! \return ::NVAPI_OK or ::NVAPI_INVALID_ARGUMENT
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_DestroyPathContextNV(NvU32 context);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_CreatePathNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Creates a NVPL path. 
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]	    context	  NVPL context
//! \param [in]	    datatype	  Type of path vertex data
//! \param [in]	    numCommands	  Number of commands in path
//! \param [in]	    commands	  Path command buffer
//!
//! \param [out]    path          Path handle
//!
//! \return   NvAPI status code or DX HRESULT code
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_CreatePathNV(NvU32 context, NvPathDataType datatype, NvU32 numCommands, const NvU8* commands, NvU32* path);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_DeletePathNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Destroys a NVPL path. This function *MUST* be called
//!					on all created paths or else memory leaks will occur.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]    path  NVPL path handle
//!
//! \return ::NVAPI_OK or ::NVAPI_INVALID_ARGUMENT
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_DeletePathNV(NvU32 path);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_PathVerticesNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Sets vertex data for a path.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]	  	path  NVPL path handle
//! \param [in		vertices  vertex data
//!
//! \return  NvAPI status code or DX HRESULT code
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_PathVerticesNV(NvU32 path, const void* vertices);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_PathParameterfNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Sets a path rendering parameter of type float
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!	       INPUT:	path - NVPL path handle
//!		   INPUT:	paramType - parameter name
//!		   INPUT:	param - parameter value
//!
//! \return   NvAPI status code or DX HRESULT code
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_PathParameterfNV(NvU32 path, NVPathParamType paramType, float param);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_PathParameteriNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Sets a path rendering parameter of type int
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]	    path      NVPL path handle
//! \param [in]	    paramType parameter name
//! \param [in]	    param     parameter value
//!
//! \return   NvAPI status code or DX HRESULT code
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_PathParameteriNV(NvU32 path, NVPathParamType paramType, int param);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_PathMatrixNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Sets a transformation matrix
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]	 context  NVPL context handle
//! \param [in]	 target   type of transformation
//! \param [in]	 value  matrix values
//!
//! \return  NvAPI status code or DX HRESULT code
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_PathMatrixNV(NvU32 context, NVPathTargetType paramType, const float* value);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_PathDepthNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Sets the current path depth
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]    context   NVPL context handle
//! \param [in]	   value     depth value
//!
//! \return  NvAPI status code or DX HRESULT code
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_PathDepthNV(NvU32 context, float value);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_PathClearDepthNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Clears the depth buffer
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  context  NVPL context handle
//! \param [in]  value    depth value
//!
//! \return  NvAPI status code or DX HRESULT code
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_PathClearDepthNV(NvU32 context, float value);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_PathEnableDepthTestNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                 NV Path Library.
//!                  Enables / Disables depth testing
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!	       INPUT:	context - NVPL context handle
//!		   INPUT:	enable - enable depth test if true, else disable
//!
//! RETURN STATUS: a NvAPI status code or DX HRESULT code
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_PathEnableDepthTestNV(NvU32 context, bool enable);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_PathEnableColorWriteNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Enables / Disables color write
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]	context  NVPL context handle
//! \param [in] enable   enable color write if true, else disable
//!
//! \return NvAPI status code or DX HRESULT code
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_PathEnableColorWriteNV(NvU32 context, bool enable);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_DrawPathNV
//
//!	 DESCRIPTION:   This API call is part of the DX implementation of the 
//!                  NV Path Library.
//!                  Draws the path.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]	path  NVPL path handle
//! \param [in] mode  path rendering mode
//!
//! \return NvAPI status code or DX HRESULT code
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_DrawPathNV(NvU32 path, NVPathMode mode);





///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GetSurfaceHandle
//
//!  This function gets the handle of a given surface. This handle uniquely 
//!  identifies the surface through all NvAPI entries.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \param [in]     pSurface  Surface to be identified
//! \param [out]    pHandle    Will be filled by the return handle
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GetSurfaceHandle(IDirect3DSurface9 *pSurface, 
                                        NVDX_ObjectHandle *pHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GetSurfaceHandle
//
//! \fn NvAPI_D3D9_GetOverlaySurfaceHandles(IDirect3DDevice9 *pDev, NV_OVLY_SURFS_INFO *pInfo)
//!   DESCRIPTION: This function gets the surface handles for the YUY2 overlay surfaces created.
//!
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 175.76
//!
//!   \param [in]  pDev  Device whose YUY2 surface handles need to be retrieved.
//!
//!   \param [out] pInfo Array (see NV_OVLY_SURFS_INFO) of surface handles (NVDX_ObjectHandle) that will be filled by
//!                the driver. The array has to initialized before it is passed on to 
//!                the function. The handles are populated in the order in which they 
//!                are created. For example, the handle of the first surface created will be
//!                stored in pHandle[0], second surface will be stored in pHandle[1], and so on.
//!
//! \return  An int which could be an NvAPI status or DX HRESULT code
//////////////////////////////////////////////////////////////////////////////


//! \ingroup dx
//! Used in NV_OVLY_SURFS_INFO.
#define MAX_OVLY_SURFS     6

//! \ingroup dx
//! Overlay surface handle and other information - used in NvAPI_D3D9_GetOverlaySurfaceHandles().
typedef struct _NV_OVLY_SURFS_INFO
{
    NVDX_ObjectHandle  handle[MAX_OVLY_SURFS];
    unsigned int       numSurfs;
}NV_OVLY_SURFS_INFO;


//! \ingroup dx
NVAPI_INTERFACE NvAPI_D3D9_GetOverlaySurfaceHandles(IDirect3DDevice9 *pDev, NV_OVLY_SURFS_INFO *pInfo);

                                       
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GetTextureHandle
//
//!  This function gets the handle of a given DirectX 9 texture.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \param [in]    pTexture   Surface to be identified
//! \param [out]   pHandle    Will be filled by the return handle
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GetTextureHandle(IDirect3DTexture9 *pTexture, 
                                        NVDX_ObjectHandle *pHandle);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GpuSyncGetHandleSize
//
//!  This function returns the size of the init and copy sync handles. These handles are
//!  then allocated and initialized to zero by the application.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 92.00 (Rel90) / 95.40 (Rel95)
//!
//! \param [out]    pInitHandleSize   size of GpuSync init handle
//! \param [out]    pMapHandleSize    size of GpuSync copy handle
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GpuSyncGetHandleSize(IDirect3DDevice9 *pDev, 
                                            unsigned int *pInitHandleSize,
                                            unsigned int *pMapHandleSize);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GpuSyncInit
//
//! This function sets up sync functionality.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 92.00 (Rel90) / 95.40 (Rel95)
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GpuSyncInit(IDirect3DDevice9 *pDev, 
                                            void * syncInitData);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GpuSyncEnd
//
//! This function tears down sync structures.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 92.00 (Rel90) / 95.40 (Rel95)
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GpuSyncEnd(IDirect3DDevice9 *pDev, 
                                            void * syncData);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GpuSyncMapTexBuffer
//
//! This function maps a texture to receive OpenGL data.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 92.00 (Rel90) / 95.40 (Rel95)
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GpuSyncMapTexBuffer(IDirect3DDevice9 *pDev, 
                                            IDirect3DTexture9 *pTexture,
                                            void * syncData);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GpuSyncMapSurfaceBuffer
//
//!  This function maps a texture to receive OpenGL data.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: (R177_00)
//!
//!  \return    An int which could be an NvAPI status or DX HRESULT code
//!  \ingroup   dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GpuSyncMapSurfaceBuffer(IDirect3DDevice9 *pDev, 
                                                   IDirect3DSurface9 *pSurface,
                                                   void * syncData);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GpuSyncMapVertexBuffer
//
//! This function maps a vertex buffer to receive OpenGL data.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 92.00 (Rel90) / 95.40 (Rel95)
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GpuSyncMapVertexBuffer(IDirect3DDevice9 *pDev, 
                                            IDirect3DVertexBuffer9 *pVertexBuffer,
                                            void * syncData);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GpuSyncMapIndexBuffer
//
//!   This function maps an index buffer to receive OpenGL data.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!  \since Version: (R177_00)
//!
//!  \return  An int which could be an NvAPI status or DX HRESULT code
//!  \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GpuSyncMapIndexBuffer(IDirect3DDevice9 *pDev, 
                                            IDirect3DIndexBuffer9 *pIndexBuffer,
                                            void * syncData);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_SetPitchLinearSurfaceCreation
//
//!   This function forces the next CreateTexture()/CreateRenderTarget() call to use pitch surfaces.
//!   The action is applied only once for the next surface. Set Signature==0 to make sure this is disabled.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!  \since Version: (R177_00)
//!
//!  \return   An int which could be an NvAPI status or DX HRESULT code
//!  \ingroup  dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_SetPitchSurfaceCreation(IDirect3DDevice9 *pDev, 
                                                   NvU32 Signature);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GpuSyncAcquire
//
//! This function acquires a semaphore for synchronization control of a mapped buffer.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 92.00 (Rel90) / 95.40 (Rel95)
//!
//! \param [in] accessMode Acquire mapped buffer read/write access
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GpuSyncAcquire(IDirect3DDevice9 *pDev, 
                                            void * syncData);
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GpuSyncRelease
//
//! This function releases a semaphore for synchronization control of a mapped buffer.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 92.00 (Rel90) / 95.40 (Rel95)
//!
//! \param [in] accessMode  Release mapped buffer read/write access
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GpuSyncRelease(IDirect3DDevice9 *pDev, 
                                            void * syncData);
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GetCurrentRenderTargetHandle
//
//!  This function gets the handle of the current render target or z-buffer.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \param [in]  pDev     Device whose current render target is to be identified
//!
//! \param [out] pHandle  Will be filled by the return handle
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GetCurrentRenderTargetHandle(IDirect3DDevice9 *pDev,
                                            NVDX_ObjectHandle *pHandle);
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GetCurrentZBufferHandle
//
//! 
//!  This function gets the handle of the current z-buffer.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \param [in]  pDev     Device whose current z-buffer is to be identified
//!
//! \param [out] pHandle  Will be filled by the return handle
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GetCurrentZBufferHandle(IDirect3DDevice9 *pDev,
                                               NVDX_ObjectHandle *pHandle);
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GetIndexBufferHandle
//
//!  This function gets the handle of a given DirectX 9 index buffer.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \param [in]   pIndexBuffer  Index Buffer to be identified
//! \param [out]  pHandle       Will be filled by the return handle
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GetIndexBufferHandle(IDirect3DIndexBuffer9 *pIndexBuffer, 
                                        NVDX_ObjectHandle *pHandle);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GetVertexBufferHandle
//
//!  This function gets the handle of a given DirectX 9 vertex buffer.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \param [in]    pVertexBuffer  Vertex Buffer to be identified
//! \param [out]   pHandle        Will be filled by the return handle
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GetVertexBufferHandle(IDirect3DVertexBuffer9 *pVertexBuffer, 
                                        NVDX_ObjectHandle *pHandle);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_CreateTexture
//
//! \fn NvAPI_D3D9_CreateTexture(IDirect3DDevice9 *pDev,
//!   DESCRIPTION: This function creates a texture with special properties. \note The texture 
//!                is always created in "POOL_DEFAULT", not managed. \p
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 174.80
//!
//!   \param [in]  pDev         The device to get primary surface from Width,Height,Levels,Format 
//!   \param [in]  Width        Width of the top-level of the texture, in pixels. 
//!                             (See MS DirectX interface Direct3D9Device::CreateTexture.)
//!   \param [in]  Height       Height of the top-level of the texture, in pixels.
//!                             (See MS DirectX interface Direct3D9Device::CreateTexture.)
//!   \param [in]  Level        Number of levels in the texture. 
//!                             (See MS DirectX interface Direct3D9Device::CreateTexture.)
//!   \param [in]  Flags        The flags for special texture creation - \p
//!                - FORCEVIDMEM  This will force the texture into video memory, 
//!                               if that cannot be done, the texture creation will fail.
//!                - FORCELINEAR  Ensure the texture is stored in pitched-linear layout.
//!                - NOTMOVABLE   Indicates the texture should not be moved once allocated.
//!                               This is usually used to accommodate a 3rd party DMA engine.
//!                               \note This is only a hint, the OS may still move the texture
//!                                     under memory-constrained circumstances.
//!   \param [in]  format       Describes the format of all levels in the texture. (See the MS DirectX SDK D3DFORMAT enumerated type) 
//!   \param [out] ppTexture    Fill with the texture created. (See MS DirectX SDK IDirect3DTexture9 interface) 
//!   \param [out] pHandle      If non-NULL, fill with the NVDX handle of the created texture.
//
//////////////////////////////////////////////////////////////////////////////


//!  \addtogroup dx
//! @{
#define NV_SURFACEFLAG_FORCEVIDMEM      0x00000001  //!< Flag for texture creation in NvAPI_D3D9_CreateTexture() 
#define NV_SURFACEFLAG_FORCELINEAR      0x00000010  //!< Flag for texture creation in NvAPI_D3D9_CreateTexture() 
#define NV_SURFACEFLAG_NOTMOVABLE       0x00000100  //!< Flag for texture creation in NvAPI_D3D9_CreateTexture() 
//! @}


//!   \ingroup  dx
NVAPI_INTERFACE NvAPI_D3D9_CreateTexture(IDirect3DDevice9 *pDev,
                                         NvU32 Width, NvU32 Height, NvU32 Level,
                                         NvU32 Flags, D3DFORMAT Format,
                                         IDirect3DTexture9 **ppTexture,
                                         NVDX_ObjectHandle *pHandle = 0);


////////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_AliasPrimaryAsTexture
//
//!  This function creates a texture that is an alias of the current device's primary surface.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \param [in]     pDev       The device from which to get the primary surface
//! \param [in]     dwIndex    The index to the primary flipchain of device (usually 0)
//! \param [out]    ppTexture  Fill with the texture created
//! \param [out]    pHandle    If non-NULL, fill with the NVDX handle of the created texture
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_AliasPrimaryAsTexture(IDirect3DDevice9 *pDev, 
                                            NvU32 dwIndex,
                                            IDirect3DTexture9 **ppTexture,
                                            NVDX_ObjectHandle *pHandle = 0);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_PresentSurfaceToDesktop
//
//! \fn NvAPI_D3D9_PresentSurfaceToDesktop(IDirect3DDevice9 *pDev,
//!  This function presents a given surface to the desktop. This interface can be
//!  used to start a full-screen flipping mode even within windowed Direct 3D application.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \param [in]    pDev              The device (display) to present to 
//! \param [in]    surfaceHandle     The surface handle obtained from NVD3D9_GetSurfaceHandle().
//!                                  NOTE: NVDX_OBJECT_NONE means restore
//! \param [in]    dwFlipFlags       Flags to indicate SYNC mode (other bits reserved and must be 0)
//! \param [in]    dwExcludeDevices  This is a bitmask (usually 0) to indicate which device
//!                                  will be EXCLUDED from this present. This is only
//!                                  effective when used in a Clone mode configuration where
//!                                  the application wants one monitor to show the specially
//!                                  rendered screen and the other the normal desktop.
//!
//! \note It is application's responsibility to determine which devices are
//!       available on the current Clone mode configuration, through nvcpl interfaces.
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//
///////////////////////////////////////////////////////////////////////////////


//! Parameters used for dwFlipFlags (All other bits reserved) - See NvAPI_D3D9_PresentSurfaceToDesktop()
//! \addtogroup dwFlipFlags
//! @{
#define NV_FLIPFLAG_VSYNC               0x00000001  //!< SYNCMODE         (bit 0:1) - 0:NOSYNC, 1:VSYNC, 2:HSYNC
#define NV_FLIPFLAG_HSYNC               0x00000002
#define NV_FLIPFLAG_TRIPLEBUFFERING     0x00000004  //!< TRIPLEBUFFERING  (bit 2)   - 0: DoubleBuffer, 1:TripleBuffer or more
//! @}


//! \ingroup dx
NVAPI_INTERFACE NvAPI_D3D9_PresentSurfaceToDesktop(IDirect3DDevice9 *pDev, 
                                               NVDX_ObjectHandle surfaceHandle, 
                                               NvU32 dwFlipFlags,
                                               NvU32 dwExcludeDevices = 0);

///////////////////////////////////////////////////////////////////////////////
// 
// FUNCTION_NAME: NvAPI_D3D9_CreateVideoBegin
//
//!  DESCRIPTION:  This function signals the driver that the application will next create a set of 
//!                D3DFMT_X8R8G8B8 render targets for overlay use. The call will fail 
//!                if the driver/hardware doesn't support this mode, in which case the 
//!                application should fall back to the traditional overlay (with driver 
//!                internal overlay buffers). If this call returns successfully, then 
//!                before the driver sees _CreateVideoEnd, all D3DFMT_A8R8G8B8 render 
//!                targets will be allocated as overlay surfaces. 
//!                See _CreateVideo, \ref NV_CVFLAG_EXTERNAL_OVERLAY flag for more details.
//!                This interface is only available on Windows Vista.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 165.22
//!
//! \param [in]    pDev        The device (display) to present to
//!
//! \return        An int which could be an NvAPI status or DX HRESULT code
//! \ingroup       dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_CreateVideoBegin(IDirect3DDevice9 *pDev);

///////////////////////////////////////////////////////////////////////////////
// 
// FUNCTION_NAME: NvAPI_D3D9_CreateVideoEnd
//
//!  DESCRIPTION:  This function signals the driver that the application has finished creating 
//!                D3DFMT_X8R8G8B8 render targets for overlays.
//!                See _CreateVideo, \ref NV_CVFLAG_EXTERNAL_OVERLAY flag for more details.
//!                This interface is only available on Windows Vista.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 165.22
//!
//!  \param [in]   pDev    The device (display) to present to
//!
//!  \return       An int which could be an NvAPI status or DX HRESULT code
//!  \ingroup      dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_CreateVideoEnd(IDirect3DDevice9 *pDev);


///////////////////////////////////////////////////////////////////////////////
// 
// FUNCTION_NAME: NvAPI_D3D9_CreateVideo
//
//! \fn NvAPI_D3D9_CreateVideo(IDirect3DDevice9 *pDev,
//!  This function allocates and initializes video resources for playback within a D3D9 context.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 91.80 / 96.50
//!
//! \param [in]  pDev              The device (display) to present to
//! \param [in]  pCVParams         Pointer to the create video paramater structures. See NV_DX_CREATE_VIDEO_PARAMS1.
//!
//! \return  An int which could be an NvAPI status or DX HRESULT code
//
///////////////////////////////////////////////////////////////////////////////////////



//! \addtogroup cvflags
//! Create Video Flags - See NV_DX_CREATE_VIDEO_PARAMS1
//! @{

//! Overlay will be used
#define NV_CVFLAG_OVERLAY                   0x00000001 

//! Change source size or flip queue hint once overlay
//! resources have already been allocated.  Be wary
//! of upward allocating new resources, if there is
//! a failure, be prepared to deallocate everything
//! and start from scratch.     
#define NV_CVFLAG_OVERLAY_REINIT            0x00000002      

//! Use overlay surfaces allocated by the application. This flag
//! is supported only in NV_DX_CREATE_VIDEO_PARAMS_VER2 and above 
//! on Windows Vista. 
//!
//! The application sets this flag to indicate that the driver should
//! not allocate any internal overlay buffers, and the first
//! dwNumOvlSurfs surfaces in pCVParams->hOvlSurfs[] will be used for
//! overlay scan-out directly. The driver will validate these surfaces
//! against the following conditions, and fail the call otherwise: 
//!
//! -# No less than NV_CV_MIN_OVERLAY_SURFACE_NUMBER and no more than
//!    NV_CV_MAX_OVERLAY_SURFACE_NUMBER should be passed in.
//! -# Only surface handles of D3DFMT_A8R8G8B8 render targets created
//!    inside a pair of _CreateVideoBegin ()/_CreateVideoEnd() should be
//!    used.
//! -# The size of the surfaces must be identical to the target display.
//!
//! If all of the above condictions are met for each of the surfaces,
//! then the driver will not allocate any internal overlay buffers. Upon
//! _PresentVideo(), the source surface will be used for overlay scan-
//! out directly without the driver copying the content to an overlay
//! buffer first.
#define NV_CVFLAG_EXTERNAL_OVERLAY          0x00000004      

//! Forces full screen video on secondary device to be
//! disabled in multihead modes, regardless of user setting
#define NV_CVFLAG_2ND_FORCE_DISABLE         0x00010000

//! Forces full screen video on secondary device to be
//! enabled on the default device in multihead modes, 
//! regardless of user setting      
#define NV_CVFLAG_2ND_FORCE_ENABLE          0x00020000

//! Forces full screen video on secondary device to be
//! enabled on the primary device in clone mode, 
//! regardless of user setting      
#define NV_CVFLAG_2ND_FORCE_ENABLE1         0x00040000

//! If another application owns the secondary full-screen
//! device, forcibly take possession of it.      
#define NV_CVFLAG_2ND_COMMANDEER            0x00100000 

//! Is the target display secondary display when in Dualview mode     
#define NV_CVFLAG_SECONDARY_DISPLAY         0x01000000     
//! @}

//! \ingroup dx
//! Used in NvAPI_D3D9_CreateVideo()
typedef struct
{
    NvU32 version;       //!< Version of the CreateVideoParams structure
    NvU32 cvFlags;       //!< Initialization flags (See \ref cvflags for description)
    NvU32 flipQueueHint; //!< If an overlay is allocated, this indicates the desired number of flips
                         //!  to be queued (minimum of 1). A larger number is better for performance,
                         //!  but also consumes more frame buffer resources. This number should be
                         //!  set according to the number of fields/frames that can be decoded in
                         //!  advance of presentation. For example, if the decoder cannot decode in advance and
                         //!  must display immediately after decoding a frame, then set this to 1.
                         //!  If the decoder is decoding field content one frame at a time, then it
                         //!  is decoding one field ahead - set this to 2.  If the decoder
                         //!  can decode n flips ahead, then set this to n+1.  If the GPU has
                         //!  constrained frame buffer resources, then set this number lower, and also
                         //!  reduce the decode-ahead pipeline resources accordingly.
    NvU32 maxSrcWidth;   //!< Maximum video source width
    NvU32 maxSrcHeight;  //!< Maximum video source height
} NV_DX_CREATE_VIDEO_PARAMS1;

//! \ingroup dx
#define NV_CV_MIN_OVERLAY_SURFACE_NUMBER    2

//! \ingroup dx
#define NV_CV_MAX_OVERLAY_SURFACE_NUMBER    6

//! \ingroup dx
//! Used in NvAPI_D3D9_CreateVideo()
typedef struct
{
    NvU32 version;       //!< Version of the CreateVideoParams structure 
    NvU32 cvFlags;       //!< Initialization flags (See \ref cvflags for description)
    NvU32 flipQueueHint; //!< If an overlay is allocated, this indicates the desired number of flips
                         //!  to be queued (minimum of 1). A larger number is better for performance,
                         //!  but also consumes more frame buffer resources. This number should be
                         //!  set according to the number of fields/frames that can be decoded in
                         //!  advance of presentation. For example, if the decoder cannot decode in advance and
                         //!  must display immediately after decoding a frame, then set this to 1.
                         //!  If the decoder is decoding field content one frame at a time, then it
                         //!  is decoding one field ahead - set this to 2.  If the decoder
                         //!  can decode n flips ahead, then set this to n+1.  If the GPU has
                         //!  constrained frame buffer resources, then set this number lower, and also
                         //!  reduce the decode-ahead pipeline resources accordingly.
    NvU32 maxSrcWidth;   //!< Maximum video source width
    NvU32 maxSrcHeight;  //!< Maximum video source height
    NvU32 dwNumOvlSurfs; //!< Number of surfaces that the application intends to use for the   
                         //!  overlay (also refer to the NV_CVFLAG_EXTERNAL_OVERLAY flag)
    NVDX_ObjectHandle hOvlSurfs[NV_CV_MAX_OVERLAY_SURFACE_NUMBER];  //!< Handles to the surfaces that the application intends to use
                                                                    //!  for the overlay (also refer to the NV_CVFLAG_EXTERNAL_OVERLAY flag)
} NV_DX_CREATE_VIDEO_PARAMS2;

//! \ingroup dx
typedef NV_DX_CREATE_VIDEO_PARAMS2  NV_DX_CREATE_VIDEO_PARAMS;

//! \ingroup dx
#define NV_DX_CREATE_VIDEO_PARAMS_VER1  MAKE_NVAPI_VERSION(NV_DX_CREATE_VIDEO_PARAMS1,1)

//! \ingroup dx
#define NV_DX_CREATE_VIDEO_PARAMS_VER2  MAKE_NVAPI_VERSION(NV_DX_CREATE_VIDEO_PARAMS2,2)

//! \ingroup dx
#define NV_DX_CREATE_VIDEO_PARAMS_VER   NV_DX_CREATE_VIDEO_PARAMS_VER2



//! \ingroup dx
NVAPI_INTERFACE NvAPI_D3D9_CreateVideo(IDirect3DDevice9 *pDev, 
                                       NV_DX_CREATE_VIDEO_PARAMS *pCVParams);

///////////////////////////////////////////////////////////////////////////////
// 
// FUNCTION_NAME: NvAPI_D3D9_FreeVideo
//
//! This function releases all video resources.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 96.60
//!      
//! \param [in] pDev   The device (display) to present to
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_FreeVideo(IDirect3DDevice9 *pDev);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_PresentVideo
//
//! \fn NvAPI_D3D9_PresentVideo(IDirect3DDevice9 *pDev, 
//!   This function signals a final and complete frame ready for presentation.
//!   It can optionally render to the overlay, but should be called
//!   regardless of whether any actual rendering occurs.  If the
//!   user has enabled full screen video in a multi-head mode,
//!   this frame will also be rendered on the secondary device.
//!
//! \note Use NV_DX_PRESENT_VIDEO_PARAMS_VER in the "version" method for both 32 bit and 64 bit
//!       callers.  For older drivers that do not support 64 bit callers, 32 bit callers
//!       should use the evaluation of MAKE_NVAPI_VERSION(NV_DX_PRESENT_VIDEO_PARAMS1,1)
//!       in that field.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61 (Updated in 91.80 (Rel90)/96.50(Rel95))
//!
//! \param [in]   pDev             The device (display) to present to
//! \param [in]   pPVParams        The present video parameters structure. See NV_DX_PRESENT_VIDEO_PARAMS1. 
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//!
//!                NVAPI_DEVICE_BUSY - This return value indicates the flip request was dropped 
//!                because the hardware flip queue was too deep, thus no more present requests can be 
//!                accepted at the moment. \n
//!
//!                When an external overlay is used (for "external overlay" please refer to NvAPI_D3D9_CreateVideoBegin(),  
//!                NvAPI_D3D9_CreateVideoEnd(), and VER2-only descriptions of NvAPI_D3D9_CreateVideo()), 
//!                a failure in _PresentVideo means the current front (on-screen) buffer will remain  
//!                unchanged. In this case the application should be careful not to render to the current 
//!                front buffer, as it will cause video tearing. The application could retry presenting 
//!                the same frame during the next V-Sync, or continue with rendering the next frame to a 
//!                back buffer.
//
///////////////////////////////////////////////////////////////////////////////

//! \addtogroup pvflags
//! PresentVideo flags - See NV_DX_PRESENT_VIDEO_PARAMS1
//! @{

//! Field is odd
#define NV_PVFLAG_ODD           0x00000001      

//! Field is even
#define NV_PVFLAG_EVEN          0x00000002 

//! Indicates that this frame is protected and guarantees full 
//! screen video will not display this frame on any secondary device.
//! Conversely, not setting this indicates an unprotected frame.     
#define NV_PVFLAG_PROTECTED     0x00000004 
     
//! Indicates progressive frame. If the odd or even flags are set
//! in conjunction with this, it indicates the original field that
//! generated this deinterlaced frame, and attempts to synchronize
//! this presentation to the corresponding display field of an
//! interlaced display
#define NV_PVFLAG_PROGRESSIVE   0x00000008      

//! Show the overlay. \n
//! If the application is minimized or obscured, continue to call NvAPI_D3D9_PresentVideo()
//! for every complete frame without this flag set. \n
//! If enabled, the unprotected video will continue to play in full-screen mode
//! on the secondary device, using the pixel aspect cached from
//! the last time a frame was shown. To change the pixel aspect while hidden,
//! the caller must "show" a frame at least once with a new clipped source and 
//! destination rectangle.  This shown frame can be rendered invisible with
//! appropriate color key selection.
#define NV_PVFLAG_SHOW          0x00000010      

//! Move overlay position without waiting for vblank.
//! The only parameters used are dwDstX, dwDstY, and NV_PVFLAG_SHOW.
#define NV_PVFLAG_FAST_MOVE     0x00000020     

//! If set, blocking flips, wait until the flip queue can accept another flip.
//! A non-blocking flip will return an error if the flip cannot be queued yet.
#define NV_PVFLAG_WAIT          0x00000040      

//! Video data is completely unchanged from the previous flip (used for telecine)
#define NV_PVFLAG_REPEAT        0x00000080

//! Use destination color key.
#define NV_PVFLAG_DST_KEY       0x00000100     

//! Indicates that the overlay is playing full-screen on the desktop.
//! This bit is used to automatically overscan the image on TVs.
#define NV_PVFLAG_FULLSCREEN    0x00000200      

//! Set the current time.
#define NV_PVFLAG_SET_STAMP     0x00001000 

//! If set, use timestamps. \n
//! If not set, flip on the next vblank.     
#define NV_PVFLAG_USE_STAMP     0x00002000     
//! @}

//! \ingroup dxvidcontrol
//! Used in NvAPI_D3D9_PresentVideo().
typedef struct 
{
    NvU32 version;                   //!< Structure version
    NVDX_ObjectHandle surfaceHandle; //!< The surface handle obtained from NvAPI_D3D9_GetSurfaceHandle
                                     //!  or NvAPI_D3D9_GetCurrentRenderTargetHandle
    NvU32 pvFlags;                   //!< Presentation flags (See \ref pvflags for description)
    NvU32 colourKey;                 //!< Colour key to use if NV_PVFLAG_DST_KEY is set
    NvU32 timeStampLow;              //
                                     //
    NvU32 timeStampHigh;             //
    NvU32 flipRate;                  //!< Set to the current flip rate.
                                     //!  Set to zero if the frame to be presented is a still frame.
    NvSBox srcUnclipped;             //!< Unclipped source rectangle of the entire frame of data
    NvSBox srcClipped;               //!< Cropped source rectangle.  It is the caller's responsibility to crop
                                     //!  the source if the desktop crops the destination.
    NvSBox dst;                      // 
} NV_DX_PRESENT_VIDEO_PARAMS1;

//! \ingroup dxvidcontrol
typedef NV_DX_PRESENT_VIDEO_PARAMS1 NV_DX_PRESENT_VIDEO_PARAMS;

#ifdef _WIN32
//! \ingroup dxvidcontrol
#define NV_DX_PRESENT_VIDEO_PARAMS_VER1  MAKE_NVAPI_VERSION(NV_DX_PRESENT_VIDEO_PARAMS1,1)
#endif //_WIN32


//! \ingroup dxvidcontrol
#define NV_DX_PRESENT_VIDEO_PARAMS_VER  MAKE_NVAPI_VERSION(NV_DX_PRESENT_VIDEO_PARAMS1,2)



//! \ingroup dxvidcontrol
NVAPI_INTERFACE NvAPI_D3D9_PresentVideo(IDirect3DDevice9 *pDev, 
                                        NV_DX_PRESENT_VIDEO_PARAMS *pPVParams);


//  SUPPORTED OS: Windows XP and higher
//! \addtogroup dxvidcontrol
//! @{

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION_NAME: NvAPI_D3D9_VideoSetStereoInfo
//
//! \fn NvAPI_D3D9_VideoSetStereoInfo(IDirect3DDevice9 *pDev,
//!                                            NV_DX_VIDEO_STEREO_INFO *pStereoInfo);
//! \code
//!   DESCRIPTION: This api specifies the stereo format of a surface, so that the
//!                surface could be used for stereo video processing or compositing. 
//!                In particular, this api could be used to link the left and right 
//!                views of a decoded picture.
//!
//!         INPUT: pDev        - The device on which the stereo surface will be used
//!                pStereoInfo - The stereo format of the surface
//!
//! RETURN STATUS: an int which could be an NvAPI status or DX HRESULT code
//! \endcode
///////////////////////////////////////////////////////////////////////////////

#ifndef NV_STEREO_VIDEO_FORMAT_DEFINE
#define NV_STEREO_VIDEO_FORMAT_DEFINE


typedef enum _NV_STEREO_VIDEO_FORMAT
{
    NV_STEREO_VIDEO_FORMAT_NOT_STEREO         = 0,

    NV_STEREO_VIDEO_FORMAT_SIDE_BY_SIDE_LR    = 1,
    NV_STEREO_VIDEO_FORMAT_SIDE_BY_SIDE_RL    = 2,
    NV_STEREO_VIDEO_FORMAT_TOP_BOTTOM_LR      = 3,
    NV_STEREO_VIDEO_FORMAT_TOP_BOTTOM_RL      = 4,
    NV_STEREO_VIDEO_FORMAT_ROW_INTERLEAVE_LR  = 5,
    NV_STEREO_VIDEO_FORMAT_ROW_INTERLEAVE_RL  = 6,
    NV_STEREO_VIDEO_FORMAT_TWO_FRAMES_LR      = 7,
    NV_STEREO_VIDEO_FORMAT_MONO_PLUS_OFFSET   = 8,

    NV_STEREO_VIDEO_FORMAT_LAST               = 9,
} NV_STEREO_VIDEO_FORMAT;

#endif // NV_STEREO_VIDEO_FORMAT_DEFINE


typedef struct _NV_DX_VIDEO_STEREO_INFO {
    NvU32                     dwVersion;         //!< Must be NV_DX_VIDEO_STEREO_INFO_VER
    NVDX_ObjectHandle         hSurface;          //!< The surface whose stereo format is to be set
    NVDX_ObjectHandle         hLinkedSurface;    //!< The linked surface (must be valid when eFormat==NV_STEREO_VIDEO_FORMAT_TWO_FRAMES_LR)
    NV_STEREO_VIDEO_FORMAT    eFormat;           //!< Stereo format of the surface
    NvS32                     sViewOffset;       //!< Signed offset of each view (positive offset indicating left view is shifted left)
    BOOL                      bStereoEnable;     //!< Whether stereo rendering should be enabled (if FALSE, only left view will be used)
} NV_DX_VIDEO_STEREO_INFO;

//! Macro for constructing the version field of ::NV_DX_VIDEO_STEREO_INFO
#define NV_DX_VIDEO_STEREO_INFO_VER  MAKE_NVAPI_VERSION(NV_DX_VIDEO_STEREO_INFO,1)

NVAPI_INTERFACE NvAPI_D3D9_VideoSetStereoInfo(IDirect3DDevice9 *pDev,
                                              NV_DX_VIDEO_STEREO_INFO *pStereoInfo);

//! @}

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_SetGamutData
//
//! \fn NvAPI_D3D9_SetGamutData(IDirect3DDevice9 *pDev, NvU32 outputId, NV_GAMUT_FORMAT format, NV_GAMUT_METADATA *pGamutData)
//! DESCRIPTION:     This API sets the Gamut Boundary Description (GBD) data.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 175.76
//!
//! \param [in]     pDev        The device (display) to present to.
//! \param [in]     outputId    The display output ID, which can be determined using NvAPI_GetAssociatedDisplayOutputId()
//!                             for an intended display. 
//! \param [in]     format      The format of GBD data structure.					
//! \param [in]     pGamutData  The GBD data.
//!
//! \retval  ::NVAPI_OK 
//! \retval  ::NVAPI_ERROR 
//! \retval  ::NVAPI_INVALID_ARGUMENT
//
/////////////////////////////////////////////////////////////////////////////////


//! \ingroup dx
//! Gamut format data - used in NvAPI_D3D9_SetGamutData().
typedef enum _NV_GAMUT_FORMAT
{
    NV_GAMUT_FORMAT_VERTICES   = 0,
    NV_GAMUT_FORMAT_RANGE,
} NV_GAMUT_FORMAT;


//! \ingroup dx
//! Gamut range metadata - used in NV_GAMUT_METADATA.
typedef struct _NV_GAMUT_METADATA_RANGE
{
    // Header
    NvU32    GBD_Color_Space:3;
    NvU32    GBD_Color_Precision:2;
    NvU32    Rsvd:2;                    //!< Must be set to 0
    NvU32    Format_Flag:1;             //!< Must be set to 1

    // Packaged data
    NvU32    Min_Red_Data:12;
    NvU32    Max_Red_Data:12;
    NvU32    Min_Green_Data:12;
    NvU32    Max_Green_Data:12;
    NvU32    Min_Blue_Data:12;
    NvU32    Max_Blue_Data:12;
} NV_GAMUT_METADATA_RANGE;


//! \ingroup dx
//! Gamut vertices metadata - used in NV_GAMUT_METADATA.
typedef struct _NV_GAMUT_METADATA_VERTICES
{
    // Header  
    NvU32    GBD_Color_Space:3;
    NvU32    GBD_Color_Precision:2;
    NvU32    Rsvd:1;
    NvU32    Facet_Mode:1;			//!< Must be set to 0
    NvU32    Format_Flag:1;		        //!< Must be set to 0
    NvU32    Number_Vertices_H:8;		//!< Must be set to 0
    NvU32    Number_Vertices_L:8;		//!< Must be set to 4
   
    // Packaged data
    NvU32    Black_Y_R:12;
    NvU32    Black_Cb_G:12;
    NvU32    Black_Cr_B:12;
    NvU32    Red_Y_R:12;
    NvU32    Red_Cb_G:12;
    NvU32    Red_Cr_B:12;
    NvU32    Green_Y_R:12;
    NvU32    Green_Cb_G:12;
    NvU32    Green_Cr_B:12;
    NvU32    Blue_Y_R:12;
    NvU32    Blue_Cb_G:12;
    NvU32    Blue_Cr_B:12;
} NV_GAMUT_METADATA_VERTICES;


//! \ingroup dx
//! Gamut boundary description data - used in NvAPI_D3D9_SetGamutData().
typedef struct _NV_GAMUT_METADATA
{
   union
   {
        NV_GAMUT_METADATA_RANGE     rangeData;
        NV_GAMUT_METADATA_VERTICES  verticesData;        
   }data;
}NV_GAMUT_METADATA;


//! \ingroup dx
NVAPI_INTERFACE NvAPI_D3D9_SetGamutData(IDirect3DDevice9 *pDev, NvU32 outputId, NV_GAMUT_FORMAT format, NV_GAMUT_METADATA *pGamutData);



//! \ingroup dx
//! @{
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_SetSurfaceCreationLayout
//
//! \fn NvAPI_D3D9_SetSurfaceCreationLayout(IDirect3DDevice9            *pDev,
//!                                                 NVAPI_SURFACE_LAYOUT_STRUCT *pSurfaceLayout);
//! \code
//!   DESCRIPTION: This call will be used primarily for testing VIC for MCP89.
//!                This will set up the layout of surfaces that are created through CreateSurface calls
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//!         INPUT: pDev                          The device (display) to present to
//!                pSurfaceLayout                The pointer to the surface layout
//!                Surface layouts supported right now include Block-Linear (BL), 
//!                Pitch-Linear (PL) and Tiled (16x16)
//! 
//! RETURN STATUS: an int which could be an NvAPI status or DX HRESULT code
//! \endcode
///////////////////////////////////////////////////////////////////////////////
typedef enum _NVAPI_SURFACE_LAYOUT
{
    NVAPI_SURFACE_LAYOUT_BL    = 0,
    NVAPI_SURFACE_LAYOUT_PL    = 1,
    NVAPI_SURFACE_LAYOUT_TILED = 2,
} NVAPI_SURFACE_LAYOUT;

typedef struct _NVAPI_SURFACE_LAYOUT_STRUCT
{
    BOOL                 bEnableLayoutOverride;
    NVAPI_SURFACE_LAYOUT slLayout;
    DWORD                reserved[4];
    
} NVAPI_SURFACE_LAYOUT_STRUCT;


NVAPI_INTERFACE NvAPI_D3D9_SetSurfaceCreationLayout(IDirect3DDevice9            *pDev,
                                                    NVAPI_SURFACE_LAYOUT_STRUCT *pSurfaceLayout);

//! @}


 
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_Video_GetVideoCapabilities
//
//! \fn NvAPI_D3D9_GetVideoCapabilities(IDirect3DDevice9 *pDev,
//!   DESCRIPTION: This function gets the GPU's video processing capabilities. The caller is responsible for furnishing
//!                the inputs within the NVAPI_VIDEO_CAPS_PACKET. This packet shall contain the output 
//!                consisting of the supported video features for the current configuration. The number of 
//!                NVAPI_VIDEO_CAPS will match the number of input video streams for which the capabilites
//!                have been requested. Multiple supported video profiles may be returned that would include
//!                a combination of various video features.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 158.31
//!                
//!   \param [in]  pDev             The device (display) to present to
//!   \param [in]  version          Version of the NV_DX_VIDEO_CAPS structure
//!   \param [in]  videoCaps        NVAPI_VIDEO_CAPS_PACKET containing both the 
//!                                 input Video Source information for which the capabilities
//!                                 are requested, as well as the output available 
//!                                 supported video features for the current configuration.
//!
//!  \return  An int which could be an NvAPI status or DX HRESULT code
//
///////////////////////////////////////////////////////////////////////////////



//! \ingroup dxvidcontrol
//! Used in _NVAPI_VIDEO_SRC_INFO.
typedef enum _NV_CODEC
{
    NV_CODEC_TYPE_NONE,     
    NV_CODEC_TYPE_MPEG2, 
    NV_CODEC_TYPE_H264,
    NV_CODEC_TYPE_VC1,
    NV_CODEC_TYPE_MVC,
} NV_CODEC;




//! Current video surface to be played back. \n
//! Used in _NVAPI_VIDEO_CAPS_PACKET.
//! \ingroup dxvidcontrol
typedef struct _NVAPI_VIDEO_SRC_INFO
{
    NvU32       srcWidth;   //!< Input video width 
    NvU32       srcHeight;  //!< Input video height
    NV_CODEC    codecType;  //!< One of the available NV_CODEC's
    NvU32       avgBitrate; //!< Average bit rate for each stream in Kbps
    NvU64       reserved1;  //!< reserved for future expansion
    NvU64       reserved2;
} NVAPI_VIDEO_SRC_INFO;



//! Current desktop resolution. \n
//! Used in _NVAPI_VIDEO_CAPS_PACKET.
//! \ingroup dxvidcontrol
typedef struct _NVAPI_DESKTOP_RES
{
    NvU32 width;            //!< Current resolution width
    NvU32 height;           //!< Current resolution height
    NvU32 bitsPerPixel;     //!< Current resolution depth
    NvU32 refreshRate;      //!< Current display refresh rate
    NvU64 reserved1;        //!< Reserved for future expansion
    NvU64 reserved2;
} NVAPI_DESKTOP_RES;


//! \addtogroup dxvidcontrol
//! @{
#define NV_DEINTERLACE_PIXADAPTIVE_BIT      0   //!< Hardware pixel adaptive deinterlacing available
#define NV_VID_ENHANCE_EDGE_ENHANCE_BIT     0   //!< Edge enhancement present
#define NV_VID_ENHANCE_NOISE_REDUCTION_BIT  1   //!< Noise reduction present
 
#define NV_COLOR_CTRL_PROCAMP_BIT           0   //!< ProCamp is supported
#define NV_COLOR_CTRL_COLOR_TEMP_BIT        1   //!< Color temp control supported
#define NV_COLOR_CTRL_COLORSPACE_601_BIT    2   //!< Color space format ITU-R BT.601 supported
#define NV_COLOR_CTRL_COLORSPACE_709_BIT    3   //!< Color space format ITU-R BT.709 supported
#define NV_COLOR_CTRL_COLORSPACE_RGB_BIT    4   //!< Color space format RGB supported
 
#define NV_GAMMA_Y_BIT                      0   //!< Y-Gamma controls present
#define NV_GAMMA_RGB_BIT                    1   //!< RGB-Gamma controls present
#define NV_MISC_CAPS_INV_TELECINE_BIT       0   //!< Inverse telecine is available
//! @}


//! Available video post-process features.\n
//! Used in _NVAPI_VIDEO_CAPS.
//! \ingroup dxvidcontrol
typedef struct _NVAPI_VIDEO_PROCESSING_CAPS 
{
    NvU64               deinterlaceMode;    //!< Possible deinterlace modes supported, "check NV_DEINTERLACE_xxx bits"
    NvU64               videoEnhance;       //!< Possible HW postproc enhancements e.g. NR, EE, "check NV_VID_ENHANCE_xxx bits"
    NvU64               colorControl;       //!< Color control is supported, "check NV_COLOR_xxx bits"
    NvU64               gamma;              //!< Available gamma conversions, "check NV_GAMMA_xxx bits"
    NvU64               miscCaps;           //!< Miscellaneous post processing caps supported, "check NV_MISC_CAPS_xxx bits"
    NvU64               reserved1;          //!< Rserved for future use
    NvU64               reserved2;
    NvU64               reserved3;
} NVAPI_VIDEO_PROCESSING_CAPS;



//! \addtogroup vidFeature
//! Video feature cap bits. \n
//! Used in \ref _NVAPI_VIDEO_CAPS.
//! @{
#define NV_VID_FEATURE_NO_SYNC_FLIPS_BIT            0   //!< When this bit is set, the application needs to lock the RGB render target
                                                        //!< before calling RGB overlay to present video.
                                                        //!< In general this bit is set for G7x, and not set for G8x and later chips.
#define NV_VID_FEATURE_HALF_RES_ON_INTERLACED_BIT   1   //!< When this bit is set, it means that GPU can only show half resolution
                                                        //!< video on the interlaced display, which is true for G7x. The application
                                                        //!< needs a special workaround to show full-resolution video.
#define NV_VID_FEATURE_DX_PROTECTION_VERSION_2      2   //!< When this bit it set, the driver supports version 2 of
                                                        //!< DirectX video protection.
#define NV_VID_FEATURE_STEREO_VIDEO_BIT             3   //!< When this bit is set, the driver supports stereo
                                                        //!< VPBlit/VBBlitHD using NvAPI_D3D9_VideoSetStereoInfo().
//! @}


//! \addtogroup perfLevel
//! Performance level bits. \n
//! Used in \ref _NVAPI_VIDEO_CAPS.
//! @{
#define NV_PERF_LEVEL_RED_BIT                       0   //!< When this bit is set, the GPU CANNOT support HD DVD/BluRay disc playback
#define NV_PERF_LEVEL_YELLOW_BIT                    1   //!< When this bit is set, the GPU meets the minimum requirement for
                                                        //!< HD DVD/BluRay disc playback
#define NV_PERF_LEVEL_GREEN_BIT                     2   //!< When this bit is set, the GPU can support HD DVD/BluRay disc playback.
#define NV_PERF_LEVEL_AERO_BIT                      3   //!< When this bit is set, it means the GPU can support HD/BD playback with Aero enabled.
#define NV_PERF_LEVEL_FRUC_BIT                      4   //!< When this bit is set, it means the GPU can support FRUC.
#define NV_PERF_LEVEL_3DBD_COMPOSITE_BIT            6   //!< When this bit is set, it means the GPU can support compositing for 3DBD
//! @}


//! Available video decode and post-process features \n
//! Used in _NVAPI_VIDEO_CAPS_PACKET.
//! \ingroup dxvidcontrol
typedef struct _NVAPI_VIDEO_CAPS
{
    NvU32                       maxFlipRate;    //!< Maximum flipping rate supported 
    NV_CODEC                    hwDecode;       //!< Supported codec for HW decoding
    NvU64                       vidFeature;     //!< Indicates presence of special video processing features
    NvU32                       perfLevel;      //!< GPU dependent level; can be red, yellow, or green
    NvU32                       numVidProfiles; //!< Number of returned video profiles              
    NvU32                       maxResPixels;   //!< Number of pixels in the max screen resolution supported at maxFlipRate for the input
                                                //!  codecType (refer to codecType field of the NVAPI_VIDEO_SRC_INFO structure).
    NvU32                       reserved1;
    NVAPI_VIDEO_PROCESSING_CAPS vidProcCaps[NV_MAX_VID_PROFILES];
} NVAPI_VIDEO_CAPS;

//! \addtogroup dxvidcontrol
//! @{
#define NVAPI_VIDEO_CAPS_PACKET_VER 2
#define RENDER_MODE_DWM_BIT         0
#define RENDER_MODE_OVERLAY_BIT     1
#define RENDER_MODE_STEREO_FULLSCREEN_BIT 2
//! @}



//! Used in _NV_DX_VIDEO_CAPS. 
//! \ingroup dxvidcontrol
typedef struct _NVAPI_VIDEO_CAPS_PACKET
{              
    NvU32                   packetVer;                      //!< (IN) Packet version that needs to match NVAPI_VIDEO_CAPS_PACKET_VER
    NvU32                   numVidStreams;                  //!< (IN) Number of streams for which the video caps are requested
    NVAPI_VIDEO_SRC_INFO    vidSrcInfo[NV_MAX_VID_STREAMS]; //!< (IN) Video source info
    NVAPI_DESKTOP_RES       res[NV_MAX_HEADS];              //!< (IN) Current desktop resolution(s)
    NvU64                   renderMode;                     //!< (IN) Requested rendering mode for the video source
    NvU64                   totalFB;                        //!< (OUT) Total framebuffer supported
    NvU16                   NumExtOvlBufNeeded;             //!< (OUT) Recommended number of external overlay buffers
    NvU16                   reserved1;                      //!< (IN/OUT) Reserved for future expansion
    NvU32                   reserved2;                      //!< (IN/OUT)
    NVAPI_VIDEO_CAPS        videoCaps[NV_MAX_VID_STREAMS];  //!< (OUT) Available video features for requested video streams
} NVAPI_VIDEO_CAPS_PACKET;



//! Used in NvAPI_D3D9_GetVideoCapabilities().
//! \ingroup dxvidcontrol
typedef struct _NV_DX_VIDEO_CAPS
{
    NvU32                   version;                        //!< (IN) NVAPI version that matched NV_DX_VIDEO_CAPS_VER
    NVAPI_VIDEO_CAPS_PACKET videoCapsPacket;                //!< (IN/OUT)
} NV_DX_VIDEO_CAPS;


//! \ingroup dxvidcontrol 
#define NV_DX_VIDEO_CAPS_VER  MAKE_NVAPI_VERSION(NV_DX_VIDEO_CAPS,1)


//  SUPPORTED OS: Windows XP and higher
//!  \ingroup dxvidcontrol
NVAPI_INTERFACE NvAPI_D3D9_GetVideoCapabilities(IDirect3DDevice9 *pDev, 
                                                NV_DX_VIDEO_CAPS *pVideoCaps);



//! \ingroup dx
//! @{
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_QueryVideoInfo
//
//! \fn NvAPI_D3D9_QueryVideoInfo(IDirect3DDevice9 *pDev,
//!                                       NVAPI_D3D9_QUERY_VIDEO_INFO *pQueryInfo)
//!   DESCRIPTION: Extensible NvAPI command for mechanism to retrieve various video related information
//!                The information may not be specific to the GPU, but will appear like it is from the 
//!                application's POV. The calling application can various query commands, and fill in the
//!                appropriate structure packet (if necessary), for the specified command. The list of 
//!                queries available to the application and exposed through this command is intended to be
//!                customizable so we only need to expose as much as needed.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   pDev              The D3D9 device
//! \param [in]   pQueryInfo        NVAPI_D3D9_QUERY_VIDEO_INFO containing the type of query to 
//!                                 perform and returned information.
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//!
///////////////////////////////////////////////////////////////////////////////



//! Query video info commands
typedef enum _NVAPI_D3D9_QUERY_COMMAND
{
    NVAPI_D3D9_QUERY_NULL_CMD                       = 0,    //!< Null command
    NVAPI_D3D9_QUERY_STEREO_INFO_CMD                = 1,    //!< Stereo video information
    NVAPI_D3D9_QUERY_COLOR_INFO_CMD                 = 2,    //!< Color space and range information
} NVAPI_D3D9_QUERY_COMMAND;


//! Query stereo input formats
typedef enum _NV_QUERY_STEREO_INFO_FORMAT
{
    NVAPI_QUERY_STEREO_INFO_FORMAT_NOT_STEREO           = 0x00000000,
    NVAPI_QUERY_STEREO_INFO_FORMAT_SIDE_BY_SIDE_LR      = 0x00000001,
    NVAPI_QUERY_STEREO_INFO_FORMAT_SIDE_BY_SIDE_RL      = 0x00000002,
    NVAPI_QUERY_STEREO_INFO_FORMAT_TOP_BOTTOM_LR        = 0x00000004,
    NVAPI_QUERY_STEREO_INFO_FORMAT_TOP_BOTTOM_RL        = 0x00000008,
    NVAPI_QUERY_STEREO_INFO_FORMAT_ROW_INTERLEAVE_LR    = 0x00000010,
    NVAPI_QUERY_STEREO_INFO_FORMAT_ROW_INTERLEAVE_RL    = 0x00000020,
    NVAPI_QUERY_STEREO_INFO_FORMAT_TWO_FRAMES_LR        = 0x00000040,
    NVAPI_QUERY_STEREO_INFO_FORMAT_MONO_PLUS_OFFSET     = 0x00000080,
} NV_QUERY_STEREO_INFO_FORMAT;

#define NVAPI_QUERY_STEREO_INFO_FORMAT_ALL              NVAPI_QUERY_STEREO_INFO_FORMAT_SIDE_BY_SIDE_LR      | \
                                                        NVAPI_QUERY_STEREO_INFO_FORMAT_SIDE_BY_SIDE_RL      | \
                                                        NVAPI_QUERY_STEREO_INFO_FORMAT_TOP_BOTTOM_LR        | \
                                                        NVAPI_QUERY_STEREO_INFO_FORMAT_TOP_BOTTOM_RL        | \
                                                        NVAPI_QUERY_STEREO_INFO_FORMAT_ROW_INTERLEAVE_LR    | \
                                                        NVAPI_QUERY_STEREO_INFO_FORMAT_ROW_INTERLEAVE_RL    | \
                                                        NVAPI_QUERY_STEREO_INFO_FORMAT_TWO_FRAMES_LR        | \
                                                        NVAPI_QUERY_STEREO_INFO_FORMAT_MONO_PLUS_OFFSET

//! Query stereo info packet
typedef struct _NVAPI_QUERY_STEREO_INFO
{
    NvU32   dwFormats;                              //!< (OUT) Mask of supported stereo formats
    NvU32   bIsSupported        : 1;                //!< (OUT) Whether stereo is supported
    NvU32   bIsEnabled          : 1;                //!< (OUT) Whether stereo is current enabled
    NvU32   dwReserved1         :30;                //!< (IN/OUT) Future expansion
    NvU32   dwReserved2[4];                         //!< (IN/OUT) Future expansion
} NVAPI_QUERY_STEREO_INFO;

//! Query color colorspace formats
typedef enum _NVAPI_QUERY_COLOR_INFO_COLORSPACE
{
    NVAPI_QUERY_COLOR_INFO_COLORSPACE_NONE          = 0x00000000,
    NVAPI_QUERY_COLOR_INFO_COLORSPACE_601           = 0x00000001,
    NVAPI_QUERY_COLOR_INFO_COLORSPACE_709           = 0x00000002,
    NVAPI_QUERY_COLOR_INFO_COLORSPACE_RGB           = 0x00000004,

} NVAPI_QUERY_COLOR_INFO_COLORSPACE;

#define NVAPI_QUERY_COLOR_INFO_COLORSPACE_ALL       NVAPI_QUERY_COLOR_INFO_COLORSPACE_601   | \
                                                    NVAPI_QUERY_COLOR_INFO_COLORSPACE_709   | \
                                                    NVAPI_QUERY_COLOR_INFO_COLORSPACE_RGB

//! Query color info packet
typedef struct _NVAPI_QUERY_COLOR_INFO
{
    NvU32   dwColorSpaces;                          //!< (OUT) Mask of supported color spaces
    NvU32   dwReserved[4];                          //!< (IN/OUT) Future expansion
} NVAPI_QUERY_COLOR_INFO;

//! Query video info packet
typedef struct _NVAPI_DX_QUERY_VIDEO_INFO
{
    NvU32                               dwVersion;          //!< (IN) NVAPI version that matched NV_DX_QUERY_INFO_VER
    NVAPI_D3D9_QUERY_COMMAND            eQueryCommand;      //!< (IN) Type of query to perform or information requested
    union
    {
        NVAPI_QUERY_STEREO_INFO         stStereoInfo;       //!< (OUT)
        NVAPI_QUERY_COLOR_INFO          stColorInfo;        //!< (OUT)
    };
} NVAPI_D3D9_QUERY_VIDEO_INFO;

//! Macro for constructing the version field of ::NVAPI_D3D9_QUERY_VIDEO_INFO
#define NVAPI_D3D9_QUERY_VIDEO_INFO_VER  MAKE_NVAPI_VERSION(NVAPI_D3D9_QUERY_VIDEO_INFO,1)


NVAPI_INTERFACE NvAPI_D3D9_QueryVideoInfo(IDirect3DDevice9 *pDev,
                                          NVAPI_D3D9_QUERY_VIDEO_INFO *pQueryInfo);

//! @}



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_RestoreDesktop
//
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \return  NVAPI_ERROR or NVAPI_OK
//!
//! \note This is not an interface, this is just a short-hand helper
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
inline int NvAPI_D3D9_RestoreDesktop(IDirect3DDevice9 *pDev)
{
    return NvAPI_D3D9_PresentSurfaceToDesktop(pDev,NVDX_OBJECT_NONE,0);
}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_AliasPrimaryFromDevice
//
//! This function creates an alias surface from the given pDevFrom's primary swap chain.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \param [in]    pDevTo      Where new surfaces created in
//! \param [in]    pDevFrom    Where the surfaces aliased from
//! \param [in]    dwIndex     Index to the primary flipchain of pDevFrom
//!          
//! \param [out]   ppSurf      Filled with new surface pointer (to be released by the caller)
//! \param [out]   pHandle     (optional) If non-NULL, filled with SurfaceHandle of the surface
//!                            The same can be achieved by calling NVD3D9_GetSurfaceHandle afterwards.
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
//////////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_AliasPrimaryFromDevice(IDirect3DDevice9 *pDevTo, 
                                              IDirect3DDevice9 *pDevFrom, 
                                              NvU32 dwIndex,
                                              IDirect3DSurface9 **ppSurf,
                                              NVDX_ObjectHandle *pHandle = 0);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_SetResourceHint
//
//! \fn NvAPI_D3D9_SetResourceHint(IDirect3DDevice9 *pDev, NVDX_ObjectHandle obj,
//!                This API has been deprecated.  
//!                This is a general purpose function for passing down various resource 
//!                related hints to the driver. Hints are divided into categories
//!                and types within each cateroy. 
//!
//  SUPPORTED OS: Windows XP
//!
//! \since Version: 96.40
//!
//! \param [in]   pDev           Valid device context
//! \param [in]   obj            Previously obtained HV resource handle 
//! \param [in]   dwHintCategory Category of the hints
//! \param [in]   dwHintType     A hint within this category
//! \param [in]  *pdwHintValue   Pointer to location containing hint value
//! \param [out] *dwHintValue    Receives previous value of this hint.
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//
////////////////////////////////////////////////////////////////////////////////

//! Available hint categories / hint names:
//! - SLI:
//! \ingroup dx
typedef enum _NVAPI_SETRESOURCEHINT_CATEGORY
{
    NvApiHints_Sli = 1,

}  NVAPI_SETRESOURCEHINT_CATEGORY;


  //! Types of SLI hints;
  //! NvApiHints_Sli_InterframeAwareForTexturing - deprecated
  //!
  //! Default value: zero
  //! \ingroup dx
typedef enum _NVAPI_SETRESOURCEHINT_SLI_HINTS
{
    NvApiHints_Sli_InterframeAwareForTexturing = 1,

}  NVAPI_SETRESOURCEHINT_SLI_HINTS;

//
// end of categories


//! \ingroup dx
NVAPI_INTERFACE NvAPI_D3D9_SetResourceHint(IDirect3DDevice9 *pDev, NVDX_ObjectHandle obj, 
                            NVAPI_SETRESOURCEHINT_CATEGORY dwHintCategory, NvU32 dwHintName, NvU32 *pdwHintValue);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_Lock
//
//! \fn NvAPI_D3D9_Lock(IDirect3DDevice9 *pDev, NVDX_ObjectHandle obj, NvU32 dwLockFlags,
//!  This function locks and unlocks a given surface identified by handle. This
//!  function can provide CPU access to all object including
//!  RTs, ZBs, textures, VBs and IBs.
//!
//! \note 
//! - (a) Do not use this if an object can be accessed using normal DX9 means.
//! - (b) Lock should be called right before CPU access, and Unlock called right after
//!     the access is completed. Any 3D rendering or state change may cause the locked
//!     surface to be lost. When that happens, trying to access the cached CPU 
//!     address may cause the application to crash.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//
///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------

//! \ingroup dx
#define NV_ACCESSFLAG_READONLY  0x00000001 // TBD: do these go with dwLockFlags?

//! \ingroup dx
#define NV_ACCESSFLAG_DISCARD   0x00000002


//! \ingroup dx
NVAPI_INTERFACE NvAPI_D3D9_Lock(IDirect3DDevice9 *pDev, NVDX_ObjectHandle obj, NvU32 dwLockFlags,
                            void **ppAddress, NvU32 *pPitch);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_Unlock
//
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_Unlock(IDirect3DDevice9 *pDev, NVDX_ObjectHandle obj);


#ifndef NV_VIDEO_COMPONENTS_DEFINE
#define NV_VIDEO_COMPONENTS_DEFINE

///////////////////////////////////////////////////////////////////////////////
// Structs and enums related to Video state
///////////////////////////////////////////////////////////////////////////////


//! \ingroup dxvidstate
//! Used in NVAPI_GET_VIDEO_STATE_COMPONENT \n
//! Components related to the video state
typedef enum _NVAPI_VIDEO_STATE_COMPONENT_ID
{
    NVAPI_VIDEO_STATE_COMPONENT_ID_NONE     = -1,   //!< Placeholder for invalid component ID
    NVAPI_VIDEO_STATE_COMPONENT_BRIGHTNESS      ,   //!< Permits control of video's brightness value
    NVAPI_VIDEO_STATE_COMPONENT_CONTRAST        ,   //!< Allows control of video's contrast value
    NVAPI_VIDEO_STATE_COMPONENT_HUE             ,   //!< To control the hue value
    NVAPI_VIDEO_STATE_COMPONENT_SATURATION      ,   //!< Allows control of video's saturation value
    NVAPI_VIDEO_STATE_COMPONENT_COLORTEMP       ,   //!< Allows control of the color temperature value
    NVAPI_VIDEO_STATE_COMPONENT_Y_GAMMA         ,   //!< To set the Y-gamma values
    NVAPI_VIDEO_STATE_COMPONENT_RGB_GAMMA_R     ,   //!< To set the R value of RGB gamma
    NVAPI_VIDEO_STATE_COMPONENT_RGB_GAMMA_G     ,   //!< To set the G value of RGB gamma
    NVAPI_VIDEO_STATE_COMPONENT_RGB_GAMMA_B     ,   //!< To set the B value of RGB gamma
    NVAPI_VIDEO_STATE_COMPONENT_COLOR_SPACE     ,   //!< Permits choice of various color spaces using VIDEO_COMP_ALGO_COLOR_SPACE_xxx
    NVAPI_VIDEO_STATE_COMPONENT_COLOR_RANGE     ,   //!< Allows setting between a limited/full color range using VIDEO_COMP_ALGO_COLOR_RANGE_xxx
    NVAPI_VIDEO_STATE_COMPONENT_PLAYBACK_PROFILE,   //!< Permits using special postprocessing for Adobe Flash 9 Content
    NVAPI_VIDEO_STATE_COMPONENT_DEINTERLACE     ,   //!< To set various types of deinterlacing algorithms
    NVAPI_VIDEO_STATE_COMPONENT_SCALING         ,   //!< Allows setting video scaling algorithms
    NVAPI_VIDEO_STATE_COMPONENT_CADENCE         ,   //!< Allows control of the cadence algorithms
    NVAPI_VIDEO_STATE_COMPONENT_NOISE_REDUCE    ,   //!< Allows setting post-processing noise reduction values
    NVAPI_VIDEO_STATE_COMPONENT_EDGE_ENHANCE    ,   //!< Permits post-processing edge enhancement value adjustment
    NVAPI_VIDEO_STATE_COMPONENT_OVERDRIVE       ,   //!< To control the overdrive feature
    NVAPI_VIDEO_STATE_COMPONENT_SPLITSCREEN     ,   //!< To permit setting a splitscreen using one of VIDEO_COMP_ALGO_SPLITSCREEN_xxx
    NVAPI_VIDEO_STATE_COMPONENT_DEBLOCKING      ,   //!< Allows out-of-loop deblocking
    NVAPI_VIDEO_STATE_COMPONENT_DYNAMIC_CONTRAST,   //!< Permits control of video's dynamic contrast value
    NVAPI_VIDEO_STATE_COMPONENT_GREEN_STRETCH   ,   //!< Permits control of green stretch
    NVAPI_VIDEO_STATE_COMPONENT_BLUE_STRETCH    ,   //!< Allows control of blue enhancement
    NVAPI_VIDEO_STATE_COMPONENT_SKIN_TONE_CORRECTION, //!< Allows skin-tone correction for video
    NVAPI_VIDEO_STATE_COMPONENT_GAMUT_REMAPPING ,   //!< Applies gamut remapping on video
    NVAPI_VIDEO_STATE_COMPONENT_2DTO3D          ,   //!< Converts 2D video to 3D stereo video
    NVAPI_VIDEO_STATE_COMPONENT_3D_ANALYSIS     ,   //!< Analyzing 3D stereo video
    NVAPI_VIDEO_STATE_COMPONENT_FRC             ,   //!< Frame Rate Converter
    NVAPI_VIDEO_STATE_COMPONENT_ID_LAST         ,   //!< All valid components defined before this one
} NVAPI_VIDEO_STATE_COMPONENT_ID;


//! Dynamic contrast value - kept for backward compatibility.  
#define NVAPI_VIDEO_STATE_COMPONENT_DYNAMIC_CONSTRAST  NVAPI_VIDEO_STATE_COMPONENT_DYNAMIC_CONTRAST  


//! \ingroup dxvidstateypes
//! See \ref #NVAPI_VIDEO_COMPONENT_ALGORITHM.
#define VIDEO_COMP_ALGO_CUSTOM_BASE 64


//! \ingroup dxvidstate
//! Used in NVAPI_GET_VIDEO_STATE_COMPONENT. \n
//! Algorithms controlling various video components
typedef enum _NVAPI_VIDEO_COMPONENT_ALGORITHM
{
    VIDEO_COMP_ALGO_COLOR_SPACE_601                  = 0,  //!< Use the ITU-R BT.601 standard in color-space conversion for xxx_COLOR_SPACE component
    VIDEO_COMP_ALGO_COLOR_SPACE_709                  = 1,  //!< Use the ITU-R BT.709 standard in color-space conversion for xxx_COLOR_SPACE component
    VIDEO_COMP_ALGO_COLOR_SPACE_CUSTOM_04            = VIDEO_COMP_ALGO_CUSTOM_BASE+4, //!< Use custom color matrix
    VIDEO_COMP_ALGO_COLOR_RANGE_STD                  = 0,  //!< Full range of (0-255) for xxx_COLOR_RANGE component, equivalent to Microsoft's DXVADDI_NOMINALRANGE::DXVADDI_NominalRange_0_255
    VIDEO_COMP_ALGO_COLOR_RANGE_EXT                  = 1,  //!< Limited range of (16-235) for xxx_COLOR_RANGE component, equivalent to Microsoft's DXVADDI_NOMINALRANGE::DXVADDI_NominalRange_16_235
    VIDEO_COMP_ALGO_PLAYBACK_PROFILE_NONE            = 0,  //!< Use no playback profile
    VIDEO_COMP_ALGO_PLAYBACK_PROFILE_ADOBE_FLASH_9   = 1,  //!< Use the internet video enhancement postprocessing for Adobe Flash 9 
    VIDEO_COMP_ALGO_DEINTERLACE_NONE                 = 0,  //!< No deinterlacing is done
    VIDEO_COMP_ALGO_DEINTERLACE_BOB                  = 1,  //!< Perform Bob deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_WEAVE                = 2,  //!< Use weave deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_SIMPLE_ADAPTIVE      = 3,  //!< Perform a simple motion adaptive deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_GRADIENT_SIMPLE      = 4,  //!< Use a simple gradient deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_GRADIENT_FULL        = 5,  //!< Use advanced gradient deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_ADAPTIVE_FOUR_FIELD  = 6,  //!< Perform four field motion adaptive deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_DIR_SPATIAL          = 7,  //!< User directional spatial deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_ADVANCED             = 8,  //!< Perform proprietary advanced deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_GPU_CAPABLE          = 9,  //!< Best available but GPU dependent. (video driver decides dynamically)
    VIDEO_COMP_ALGO_DEINTERLACE_MEDIAN               = 10,  //!< Best available but GPU dependent. (video driver decides dynamically)
    VIDEO_COMP_ALGO_DEINTERLACE_DIR_SPATIAL_LIGHT    = 11,  //!< Best available but GPU dependent. (video driver decides dynamically)
    VIDEO_COMP_ALGO_DEINTERLACE_DIR_SPATIAL_SD       = 12,  //!< Best available but GPU dependent. (video driver decides dynamically)
    VIDEO_COMP_ALGO_DEINTERLACE_DIR_SPATIAL_HD       = 13,  //!< Best available but GPU dependent. (video driver decides dynamically)
    VIDEO_COMP_ALGO_DEINTERLACE_ONE_PASS             = 14,  //!< Best available but GPU dependent. (video driver decides dynamically)
    VIDEO_COMP_ALGO_DEINTERLACE_COMPUTE              = 15,  //!< Best available but GPU dependent. (video driver decides dynamically)
    VIDEO_COMP_ALGO_DEINTERLACE_CUSTOM_00            = VIDEO_COMP_ALGO_CUSTOM_BASE+0,    //!< Use custom Deinterlacing algorithm
    VIDEO_COMP_ALGO_DEINTERLACE_CUSTOM_01            = VIDEO_COMP_ALGO_CUSTOM_BASE+1,    //!< Use custom Deinterlacing algorithm
    VIDEO_COMP_ALGO_SCALING_ALG_SIMPLE               = 0,  //!< Do scaling using a simple algorithm       
    VIDEO_COMP_ALGO_SCALING_ALG_4x4FILTER            = 1,  //!< Perform scaling using a 4x4 filter
    VIDEO_COMP_ALGO_SCALING_ALG_8x8FILTER            = 2,  //!< Perform scaling using a 8x8 filter
    VIDEO_COMP_ALGO_SCALING_ALG_CUSTOM_00            = VIDEO_COMP_ALGO_CUSTOM_BASE+0,    //!< Use custom scaling component
    VIDEO_COMP_ALGO_SCALING_ALG_CUSTOM_01            = VIDEO_COMP_ALGO_CUSTOM_BASE+1,    //!< Use custom scaling component
    VIDEO_COMP_ALGO_CADENCE_NONE                     = 0,  //!< Turn cadence OFF
    VIDEO_COMP_ALGO_CADENCE_SIMPLE                   = 1,  //!< Use simple cadence detection
    VIDEO_COMP_ALGO_CADENCE_VOF                      = 2,  //!< Use video on film cadence detection
    VIDEO_COMP_ALGO_CADENCE_COMPUTE                  = 3,  //!< Use compute cadence detection
    VIDEO_COMP_ALGO_CADENCE_GPU_CAPABLE              = 4,  //!< Best available but GPU dependent. (video driver decides dynamically)
    VIDEO_COMP_ALGO_NOISE_REDUCE_PUREVIDEO           = 0,  //!< Use PureVideo noise reduction
    VIDEO_COMP_ALGO_NOISE_REDUCE_CUSTOM_00           = VIDEO_COMP_ALGO_CUSTOM_BASE+0,  //!< Use custom noise reduction
    VIDEO_COMP_ALGO_NOISE_REDUCE_CUSTOM_01           = VIDEO_COMP_ALGO_CUSTOM_BASE+1,  //!< Use custom noise reduction
    VIDEO_COMP_ALGO_EDGE_ENHANCE_PUREVIDEO           = 0,  //!< Use PureVideo Sharpening Filter
    VIDEO_COMP_ALGO_EDGE_ENHANCE_CUSTOM_00           = VIDEO_COMP_ALGO_CUSTOM_BASE+0,  //!< Use custom Sharpening Filter
    VIDEO_COMP_ALGO_EDGE_ENHANCE_CUSTOM_01           = VIDEO_COMP_ALGO_CUSTOM_BASE+1,  //!< Use custom Sharpening Filter
    VIDEO_COMP_ALGO_OVERDRIVE_SIMPLE                 = 0,  //!< Use simple overdrive algorithm
    VIDEO_COMP_ALGO_SPLITSCREEN_TYPE_NORMAL          = 0,  //!< Set the splitscreen in normal mode
    VIDEO_COMP_ALGO_SPLITSCREEN_TYPE_REPEATED        = 1,  //!< Set the splitscreen to be repeated
    VIDEO_COMP_ALGO_SPLITSCREEN_TYPE_ON_MIRROR       = 2,  //!< Set the splitscreen as a mirror
    VIDEO_COMP_ALGO_DYNAMIC_CONTRAST_PRESET_NONE     = 0,  //!< Use the value setting for dynamic contrast instead of a preset
    VIDEO_COMP_ALGO_DYNAMIC_CONTRAST_PRESET_LOW      = 1,  //!< Turn the dynamic contrast to a low setting
    VIDEO_COMP_ALGO_DYNAMIC_CONTRAST_PRESET_MEDIUM   = 2,  //!< Turn the dynamic contrast to a medium setting
    VIDEO_COMP_ALGO_DYNAMIC_CONTRAST_PRESET_HIGH     = 3,  //!< Turn the dynamic contrast to a high setting
    VIDEO_COMP_ALGO_GREEN_STRETCH_PRESET_NONE        = 0,  //!< Use the value setting for green stretch instead of a preset
    VIDEO_COMP_ALGO_GREEN_STRETCH_PRESET_LOW         = 1,  //!< Set the green stretch to a low setting
    VIDEO_COMP_ALGO_GREEN_STRETCH_PRESET_MEDIUM      = 2,  //!< Set the green stretch to a medium setting
    VIDEO_COMP_ALGO_GREEN_STRETCH_PRESET_HIGH        = 3,  //!< Set the green stretch to a high setting
    VIDEO_COMP_ALGO_BLUE_STRETCH_PRESET_NONE         = 0,  //!< Use the value setting for blue stretch instead of a preset   
    VIDEO_COMP_ALGO_BLUE_STRETCH_PRESET_LOW          = 1,  //!< Set the blue stretch to a low setting
    VIDEO_COMP_ALGO_BLUE_STRETCH_PRESET_MEDIUM       = 2,  //!< Set the blue stretch to a medium setting
    VIDEO_COMP_ALGO_BLUE_STRETCH_PRESET_HIGH         = 3,  //!< Set the blue stretch to a high setting
    VIDEO_COMP_ALGO_SKIN_TONE_CORRECTION_PRESET_NONE = 0,  //!< Use the value setting for skin tone correction instead of a preset  
    VIDEO_COMP_ALGO_SKIN_TONE_CORRECTION_PRESET_SQUEEZE = 1,  //!< Turn the skin tone correction to a low setting
    VIDEO_COMP_ALGO_SKIN_TONE_CORRECTION_PRESET_RED     = 2,  //!< Turn the skin tone correction to a medium setting
    VIDEO_COMP_ALGO_SKIN_TONE_CORRECTION_PRESET_YELLOW  = 3,  //!< Turn the skin tone correction to a high setting
    VIDEO_COMP_ALGO_GAMUT_REMAPPING_CUSTOM_00        = VIDEO_COMP_ALGO_CUSTOM_BASE+0, //!< Use custom 3x3 gamut remapping matrix
    VIDEO_COMP_ALGO_GAMUT_REMAPPING_CUSTOM_01        = VIDEO_COMP_ALGO_CUSTOM_BASE+1, //!< Use custom 3x3 gamut remapping matrix
    VIDEO_COMP_ALGO_2DTO3D_CUSTOM_00                 = VIDEO_COMP_ALGO_CUSTOM_BASE+0, //!< Use custom 2Dto3D conversion
    VIDEO_COMP_ALGO_2DTO3D_CUSTOM_01                 = VIDEO_COMP_ALGO_CUSTOM_BASE+1, //!< Use custom 2Dto3D conversion
    VIDEO_COMP_ALGO_3D_ANALYSIS_CUSTOM_00            = VIDEO_COMP_ALGO_CUSTOM_BASE+0, //!< Use custom 3DAnalysis algorithm
    VIDEO_COMP_ALGO_3D_ANALYSIS_CUSTOM_01            = VIDEO_COMP_ALGO_CUSTOM_BASE+1, //!< Use custom 3DAnalysis algorithm
    VIDEO_COMP_ALGO_FRC_CUSTOM_00                    = VIDEO_COMP_ALGO_CUSTOM_BASE+0, //!< Use custom frame rate converter
    VIDEO_COMP_ALGO_FRC_CUSTOM_01                    = VIDEO_COMP_ALGO_CUSTOM_BASE+1, //!< Use custom frame rate converter

} NVAPI_VIDEO_COMPONENT_ALGORITHM;


//! \ingroup dxvidstate
//! Used in NVAPI_GET_VIDEO_STATE_COMPONENT. \n
//! Bit masks for enabling video components at various resolutions
typedef enum _NVAPI_VIDEO_COMPONENT_ENABLE
{
    VIDEO_COMP_ENA_480i     = 0x00000001, //!< component is enabled at 480i video resolution
    VIDEO_COMP_ENA_480p     = 0x00000002, //!< component is enabled at 480p video resolution
    VIDEO_COMP_ENA_576i     = 0x00000004, //!< component is enabled at 576i video resolution
    VIDEO_COMP_ENA_576p     = 0x00000008, //!< component is enabled at 576p video resolution
    VIDEO_COMP_ENA_720p     = 0x00000010, //!< component is enabled at 720p video resolution
    VIDEO_COMP_ENA_1080i    = 0x00000020, //!< component is enabled at 1080i video resolution
    VIDEO_COMP_ENA_1080p    = 0x00000040, //!< component is enabled at 1080p video resolution
} NVAPI_VIDEO_COMPONENT_ENABLE;


//! \ingroup dxvidstate
//! Used in NvAPI_D3D9_GetVideoState(). \n
//! Packet that facilitates retrieving information about a video component
typedef struct _NVAPI_GET_VIDEO_STATE_COMPONENT
{
    NvU32   version;                    //!< (IN)  NVAPI version that matches NVAPI_GET_VIDEO_STATE_COMPONENT_VER
    NvU32   componentID;                //!< (IN)  identify the individual component, one of NVAPI_VIDEO_STATE_COMPONENT_xxx enums
    NvU32   bIsSupported        : 1;    //!< (OUT) set if this component feature is supported
    NvU32   bIsOverridenByUser  : 1;    //!< (OUT) set if component is overriden by user's choice
    NvU32   reserved1           : 30;   //!< (OUT) reserved for future expansion
    NvU32   isEnabled;                  //!< (OUT) set if component is enabled, one or more of NVAPI_VIDEO_COMPONENT_ENABLE bitmasks
    NvU32   minValue;                   //!< (OUT) minimum valid value
    NvU32   maxValue;                   //!< (OUT) maximum valid value
    NvU32   totalSteps;                 //!< (OUT) number of steps between min and max
    NvU32   defaultValue;               //!< (OUT) pre-defined NVIDIA default
    NvU32   unityValue;                 //!< (OUT) unity is the disable value for a component
    NvU32   currentValueActive;         //!< (OUT) value in use
    NvU64   defaultAlgo;                //!< (OUT) default algorithm, one or more of NVAPI_VIDEO_COMPONENT_ALGORITHM enums
    NvU64   currentAlgoActive;          //!< (OUT) algorithm in use, one or more of NVAPI_VIDEO_COMPONENT_ALGORITHM enums
    union
    {
        NvU64 qwReserved[9];
        struct
        {            
            NvU32   dwAppKey;           //!< (IN) Secret key to authenticate the caller, ONLY used in NvAPI_SetVideoState
            NvU32   bTopPriority   : 1; //!< (OUT)Indicates that these settings have precedence over D3D NvAPI settings, ONLY valid in NvAPI_GetVideoState
            NvU32   bHasCustomAlgo : 1; //!< (OUT)Indicates whether an out-of-process application has custom algorithm data
            NvU32   bReserved      : 30;//!< (OUT)Reserved for expansion   
            struct
            {
                NvU64   pData;          //!< (IN) Buffer to hold the retrieved custom algo data
                NvU32   dwSize;         //!< (IN) Size in bytes of the above buffer, must be <= NVAPI_VIDEO_STATE_MAX_CUSTOM_ALGO_SIZE.
            } customAlgo;

        } appInfo; 
    };         
} NVAPI_GET_VIDEO_STATE_COMPONENT;


//! \ingroup dxvidstate
//! Used in NVAPI_GET_VIDEO_STATE_COMPONENT.
#define NVAPI_GET_VIDEO_STATE_COMPONENT_VER  MAKE_NVAPI_VERSION(NVAPI_GET_VIDEO_STATE_COMPONENT,1)


//! \ingroup dxvidstate
//! Used in NVAPI_SET_VIDEO_STATE_COMPONENT. \n
//! Return status after attempting to set a video component 
typedef enum _NVAPI_VIDEO_COMP_RETURN_STATUS
{
    VIDEO_COMP_STATUS_SUCCESS                   = 0x00000000, //!< Video component is set successfully
    VIDEO_COMP_STATUS_UNSUCCESSFUL              = 0x00000001, //!< Failed to set video component
    VIDEO_COMP_STATUS_COMPONENT_NOT_SUPPORTED   = 0x00000002, //!< Video component is not supported
    VIDEO_COMP_STATUS_VALUE_OUT_OF_RANGE        = 0x00000004, //!< Video component's value is invalid and does not fall into range
    VIDEO_COMP_STATUS_ALGO_NOT_RECOGNIZED       = 0x00000008, //!< Video component's algorithm is invalid 
    VIDEO_COMP_STATUS_OVERRIDDEN_BY_USER        = 0x00000010, //!< Request not completed because of user-mandated override
    VIDEO_COMP_STATUS_Y_GAMMA_ENABLED           = 0x00000020, //!< Cannot set RGB-gamma because Y-Gamma is already enabled
    VIDEO_COMP_STATUS_RGB_GAMMA_ENABLED         = 0x00000040, //!< Cannot set Y-gamma because RGB-Gamma is already enabled
} NVAPI_VIDEO_COMP_RETURN_STATUS;


// Packet containing information to allow setting the video component

//! \ingroup dxvidstate 
#define NVAPI_VIDEO_STATE_MAX_CUSTOM_ALGO_SIZE 128


//! \ingroup dxvidstate
//! Packet containing information to allow setting the video component. \n
//! Used in NvAPI_D3D9_SetVideoState().
typedef struct _NVAPI_SET_VIDEO_STATE_COMPONENT
{
    NvU32   version;                        //!< (IN) NVAPI version that matches NVAPI_SET_VIDEO_STATE_COMPONENT_VER
    NvU32   componentID;                    //!< (IN) identify the individual component, one of NVAPI_VIDEO_STATE_COMPONENT_xxx enums
    NvU32   enable;                         //!< (IN) flag to enable setting of component, one or more of NVAPI_VIDEO_COMPONENT_ENABLE bitmasks
    NvU32   setToValue;                     //!< (IN) value to use
    NvU64   setToAlgo;                      //!< (IN) algorithm to use
    NvU32   retStatus;                      //!< (OUT) result of video-component-set operation; a combination of VIDEO_COMP_STATUS_xxx bitmasks 
    NvU32   reserved;
    union
    {
        NvU64 qwReserved[4];
        struct
        {
            NvU32   dwAppKey;               //!< (IN) Secret key to authenticate the caller, ONLY used in NvAPI_SetVideoState()
            NvU32   bTopPriority       : 1; //!< (IN) Force these settings to have priority over D3D NvAPI settings, ONLY valid in NvAPI_GetVideoState()
            NvU32   bHasCustomAlgo     : 1; //!< (IN) Out-of-process application has custom algorithm data
            NvU32   bReserved          : 30;//!< (IN) reserved for expansion
            struct
            {
                NvU64   pData;              //!< (IN) (Used only when bHasCustomAlgo == 1) Pointer to the custom algorithm data.
                NvU32   dwSize;             //!< (IN) (Used only when bHasCustomAlgo == 1) Size in Bytes of the custom algorithm data, must be <= NVAPI_VIDEO_STATE_MAX_CUSTOM_ALGO_SIZE.
            } customAlgo;
        } appInfo; 
    }; 
} NVAPI_SET_VIDEO_STATE_COMPONENT;


//! \ingroup dxvidstate
//! Used in NVAPI_SET_VIDEO_STATE_COMPONENT.
#define NVAPI_SET_VIDEO_STATE_COMPONENT_VER  MAKE_NVAPI_VERSION(NVAPI_SET_VIDEO_STATE_COMPONENT,1)

#endif // NV_VIDEO_COMPONENTS_DEFINE


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GetVideoState
//
//!   DESCRIPTION: This function returns the video state component for the specified component ID.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//!   \since Version: 171.08
//!
//!   \param [in]     pDev              The Direct3D device for which the component is requested
//!   \param [in,out] pGetVidStateComp  NVAPI_GET_VIDEO_STATE_COMPONENT packet containing
//!                                     a valid component ID
//!
//!   \return  An int which could be an NvAPI status (NVAPI_OK, NVAPI_INVALID_ARGUMENT,
//!            NVAPI_INCOMPATIBLE_STRUCT_VERSION, NVAPI_ERROR) or DX HRESULT code
//!
//!   \ingroup dxvidstate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_GetVideoState(IDirect3DDevice9 *pDev, 
                                         NVAPI_GET_VIDEO_STATE_COMPONENT *pGetVidStateComp);

/////////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_SetVideoState
//
//!   DESCRIPTION: This function sets a particular video state component for the specific component ID.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//!   \since Version: 171.08
//! 
//!   \param [in]       pDev              The Direct3D device for which the component-set is requested
//!   \param [in,out]   pSetVidStateComp  NVAPI_SET_VIDEO_STATE_COMPONENT packet containing
//!                                       the video component information to be applied 
//!
//!   \return  An int which could be an NvAPI status (NVAPI_OK, NVAPI_INVALID_ARGUMENT,
//!            NVAPI_INCOMPATIBLE_STRUCT_VERSION, NVAPI_ERROR) or DX HRESULT code
//!
//!   \ingroup dxvidstate                
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_SetVideoState(IDirect3DDevice9 *pDev, 
                                         NVAPI_SET_VIDEO_STATE_COMPONENT *pSetVidStateComp);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_EnumVideoFeatures
//
//! \fn NvAPI_D3D9_EnumVideoFeatures(IDirect3DDevice9 *pDev, NVAPI_DX_VIDEO_FEATURE_DETAILS *pVideoFeatureDetails)
//!   DESCRIPTION:  This API enumerates all video features supported on the current configuration.
//! 
//!                 - First, the client should call the function with VF_GET_COUNT flag set. This will return the total 
//!                  feature count. 
//!                 - Then the client calls this function again iteratively, with the VF_GET_DETAILS flag until all of 
//!                  the features are enumerated.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//!
//! \return An int which could be an NvAPI status or DX HRESULT code
//
///////////////////////////////////////////////////////////////////////////////
// enums and structs related to Video Features

//! \addtogroup dxvidfeatures
//! @{


#define NVAPI_MAX_FEATURES_PER_PACKET   3 //!< Maximum number of structs that can fit into dwArgs[20] of nvdxExtensionData struct

// Update the nvVidFeatureNames[] array in nvd3d.cpp when adding a new Feature ID.
//! Video feature IDs; used in _NVAPI_VIDEO_FEATURE_DETAILS
typedef enum _NVAPI_VIDEO_FEATURE
{
    NVAPI_VF_UNKNOWN = 0,
    NVAPI_VF_MPEG2SDDecodeAcceleration,
    NVAPI_VF_MPEG2HDDecodeAcceleration,
    NVAPI_VF_VC1SDDecodeAcceleration,
    NVAPI_VF_VC1HDDecodeAcceleration,
    NVAPI_VF_H264SDDecodeAcceleration,
    NVAPI_VF_H264HDDecodeAcceleration,
    NVAPI_VF_WMV9SDDecodeAcceleration,
    NVAPI_VF_WMV9HDDecodeAcceleration,
    NVAPI_VF_ProcAmp,
    NVAPI_VF_ColorTemperatureCorrection,
    NVAPI_VF_ColorSpaceConversion,
    NVAPI_VF_GammaCorrection,
    NVAPI_VF_OverDrive,
    NVAPI_VF_DynamicContrastEnhancement,
    NVAPI_VF_StretchBlueGreenSkin,
    NVAPI_VF_AdaptiveDeInterlacing,
    NVAPI_VF_NoiseReduction,
    NVAPI_VF_EdgeEnhancement,
    NVAPI_VF_InverseTelecine,
    NVAPI_VF_Scaling,
    NVAPI_VF_VideoMirror,
    NVAPI_VF_Blend,
    NVAPI_VF_DxvaHDTest,
    NVAPI_VF_GamutRemap,
    NVAPI_VF_MftXcode,
    NVAPI_VF_SkinToneCorrection,
    NVAPI_VF_MftYUY2Xcode,
    NVAPI_VF_MftDivxXcode,
    NVAPI_VF_MftWmv9Encode,
    NVAPI_VF_DynamicPState,    
    NVAPI_VF_PostProcessVIC,
    NVAPI_VF_MVCHDDecodeAcceleration,
    NVAPI_VF_SVCHDDecodeAcceleration,
    NVAPI_VF_SimpleScaling,
    NVAPI_VF_ID_LAST,
} NVAPI_VIDEO_FEATURE;

// Update the nvVidEngineNames[] array in nvd3d.cpp when adding a new Engine name.
//! Video feature engine names; used in _NVAPI_VIDEO_FEATURE_DETAILS
typedef enum _NVAPI_VIDEO_ENGINES
{
    NVAPI_VE_UNKNOWN = 0,
    NVAPI_VE_PixelShader,
    NVAPI_VE_MPEG2Decoder,
    NVAPI_VE_VideoProcessor1,
    NVAPI_VE_VideoProcessor2,
    NVAPI_VE_MSDEC,
    NVAPI_VE_VIC,
} NVAPI_VIDEO_ENGINES;

// Update the nvVidEntryPointNames[] array in nvd3d.cpp when adding a new Entry point in this enum.
//! Video driver entry point; used in _NVAPI_VIDEO_FEATURE_DETAILS 
typedef enum _NVAPI_VIDEO_DRIVER_ENTRY_POINT
{
    NVAPI_EP_UNKNOWN = 0,
    NVAPI_EP_DecodeEndFrame,
    NVAPI_EP_OverlayTransfer,
    NVAPI_EP_DIBlitEx,
    NVAPI_EP_VideoProcessBlt,
    NVAPI_EP_D3DBlt,
    NVAPI_EP_Blit32,
    NVAPI_EP_VPBltHD,
} NVAPI_VIDEO_DRIVER_ENTRY_POINT;



//! Used in _NVAPI_VIDEO_FEATURE_DESCRIPTOR
typedef enum _NVAPI_VIDEO_FEATURE_GET_FLAG
{
    NVAPI_VF_GET_COUNT = 0,
    NVAPI_VF_GET_DETAILS,
} NVAPI_VIDEO_FEATURE_GET_FLAG;


//! Used in _NVAPI_VIDEO_FEATURE_DESCRIPTOR
typedef struct _NVAPI_VIDEO_FEATURE_DETAILS
{
    NVAPI_VIDEO_FEATURE            eFeature;
    NVAPI_VIDEO_ENGINES            eEngine;
    NVAPI_VIDEO_DRIVER_ENTRY_POINT eEntryPoint;
    NvU32                          dwReserved;
} NVAPI_VIDEO_FEATURE_DETAILS;

//! Returns the strings for each feature to the client. \n
//! Used in _NVAPI_DX_VIDEO_FEATURE_DETAILS
typedef struct _NVAPI_VID_FEATURE_STRINGS
{
    NVAPI_VIDEO_FEATURE eFeature;
    NvAPI_ShortString   szFeature; //!< Feature name
    NvAPI_ShortString   szEngine; //!< Video engine name
    NvAPI_ShortString   szDrvEntryPoint; //!< drv Entry Point name
    NvAPI_ShortString   szReserved1; //!< Reserved for future expansion
} NVAPI_VID_FEATURE_STRINGS;


//! Macro for constructing the version field of NVAPI_VIDEO_FEATURE_DESCRIPTOR
#define NVAPI_VIDEO_FEATURE_DESCRIPTOR_VER  1


//! Used in _NVAPI_DX_VIDEO_FEATURE_DETAILS
typedef struct _NVAPI_VIDEO_FEATURE_DESCRIPTOR
{
    NvU32                          version;                     //!< (IN) Version that matches NVAPI_VIDEO_FEATURE_DETAILS_PACKET_VER
    NVAPI_VIDEO_FEATURE_GET_FLAG   eVideoFeatureGetID;          //!< (IN) Get total feature count or feature details
    NvU32                          dwVFCount;                   //!< (OUT) Feature count returned
    NvU32                          dwStartVFCount;              //!< (IN) Starting surface count when reading the data
    NVAPI_VIDEO_FEATURE_DETAILS    astFeatureDetails[NVAPI_MAX_FEATURES_PER_PACKET]; //!< (OUT) Array of video feature details
    NvU32                          adwReserved[4];              //!< (IN/OUT) Reserved for future expansion
} NVAPI_VIDEO_FEATURE_DESCRIPTOR;


//! Used in NvAPI_D3D9_EnumVideoFeatures().
typedef struct _NVAPI_DX_VIDEO_FEATURE_DETAILS
{
    NvU32                           version;              //!< (IN) NVAPI version that matched NVAPI_DX_VIDEO_FEATURE_DETAILS_VER
    NVAPI_VIDEO_FEATURE_DESCRIPTOR  videoFeaturesPacket;  //!< (IN/OUT)
    NVAPI_VID_FEATURE_STRINGS       astFeatureDescNames[NVAPI_MAX_FEATURES_PER_PACKET]; //!< (OUT) Descriptor strings 
} NVAPI_DX_VIDEO_FEATURE_DETAILS;

//! Macro for constructing the version field of _NVAPI_DX_VIDEO_FEATURE_DETAILS
#define NVAPI_DX_VIDEO_FEATURE_DETAILS_VER MAKE_NVAPI_VERSION(NVAPI_DX_VIDEO_FEATURE_DETAILS,1)

//! @}

//! \ingroup dxvidfeatures
NVAPI_INTERFACE NvAPI_D3D9_EnumVideoFeatures(IDirect3DDevice9 *pDev, NVAPI_DX_VIDEO_FEATURE_DETAILS *pVideoFeatureDetails);






//////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_GetSLIInfo
//
//! \fn NvAPI_D3D9_GetSLIInfo(IDirect3DDevice9 *pDev, NV_SLI_INFO *pSliInfo)
//! This API is obsolete, please use NvAPI_D3D_GetCurrentSLIState().
//!
//  SUPPORTED OS: Windows XP
//!
//! \since Version: 100.04
//!
//!
//! \retval   NVAPI_OK                      Completed request
//! \retval   NVAPI_NO_ACTIVE_SLI_TOPOLOGY  SLI is not active on this device
//! \retval   NVAPI_ERROR                   Error occurred
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dx
//! Used in NV_SLI_INFO
typedef enum _NV_SLI_MODE
{
    NV_SLI_RENDERING_MODE_AUTOSELECT  = 0,     //!< AutoSelect
    NV_SLI_RENDERING_MODE_AFR         = 1,     //!< Alternate Frames
    NV_SLI_RENDERING_MODE_SFR         = 2,     //!< Split Frame
    NV_SLI_RENDERING_MODE_SINGLE      = 3,      //!< Single GPU
    NV_SLI_RENDERING_MODE_AFR_OF_SFR  = 4      //!< AFR of SFR

} NV_SLI_MODE;

//! \ingroup dx
//! Used in NvAPI_D3D9_GetSLIInfo()
typedef struct
{
    NvU32 version;                       //!< Structure version

    NV_SLI_MODE         mode;            //!< [OUT] Current SLI mode
    NvU32               gpus;            //!< [OUT] Number of GPUs
} NV_SLI_INFO;


//! \ingroup dx
#define NV_SLI_INFO_VER  MAKE_NVAPI_VERSION(NV_SLI_INFO,1)



//! \ingroup dx
NVAPI_INTERFACE NvAPI_D3D9_GetSLIInfo(IDirect3DDevice9 *pDev, NV_SLI_INFO *pSliInfo);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_SetSLIMode
//
//! This function sets the SLI rendering mode for the Direct 3D device. The NVAPI_SLI_RENDERING_MODE_NOTALLOWED
//!                 return status occurs when SLI mode is enabled in the middle of a rendering. An application may try
//!                 to recreate/reset device and perform the call again. The normal way to set up SLI mode
//!                 is immediately after CreateDevice() or Reset(). The NVAPI_NO_ACTIVE_SLI_TOPOLOGY value is
//!                 returned when SLI is not active on this device.
//!
//  SUPPORTED OS: Windows XP
//!
//! \since Version: 100.04
//!
//! \retval    NVAPI_OK                             Completed request
//! \retval    NVAPI_NO_ACTIVE_SLI_TOPOLOGY         SLI is not active on this device
//! \retval    NVAPI_SLI_RENDERING_MODE_NOTALLOWED  Setup of SLI mode is not possible right now
//! \retval    NVAPI_INVALID_ARGUMENT               Invalid rendering mode
//! \retval    NVAPI_ERROR                          Error occurred
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_SetSLIMode(IDirect3DDevice9 *pDev, NV_SLI_MODE SliMode);




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_QueryAAOverrideMode
//
//! \fn NvAPI_D3D9_QueryAAOverrideMode(IDirect3DDevice9 *pDev, NvU32* pRenderingSampleCount, NvU32* pBufferSampleCount, NvU32* pAAMode)
//! DESCRIPTION:    This function returns the antialiasing level selected through NVCPL, 
//!                 the corresponding buffer requirement, and the equivalent multisample quality.                  
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 177.61
//!                   
//! \param [in]     pDev                    The Direct3D device for which the component is requested
//! \param [out]    pRenderingSampleCount   The number of equivalent sample counts for this AA method, 0 indicates no AA set in the control panel
//! \param [out]    pBufferSampleCount      The number of buffer samples required for every pixel, 0 indicates no AA set in the control panel
//! \param [out]    pAAMode                 The AA mode that is currently selected
//!                                             
//! \retval         NVAPI_OK                Completed request
//! \retval         NVAPI_ERROR             Error occurred
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dx
//! Used in NvAPI_D3D9_QueryAAOverrideMode().
enum
{
    NVAPI_AAMODE_VCAA             = 0x00000001,    //!< The current AA method is one of the VCAA methods
    NVAPI_AAMODE_SLIAA            = 0x00000002,    //!< The current AA method is one of the SLI-AA methods
    NVAPI_AAMODE_VCAA_HIGHQUALITY = 0x00000004     //!< The current AA method is a VCAA high-quality method
};



//! \ingroup dx
NVAPI_INTERFACE NvAPI_D3D9_QueryAAOverrideMode(IDirect3DDevice9 *pDev, NvU32* pRenderingSampleCount, NvU32* pBufferSampleCount, NvU32* pAAMode);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_D3D9_VideoSurfaceEncryptionControl
//
//! \fn NvAPI_D3D9_VideoSurfaceEncryptionControl(IDirect3DDevice9 *pDev, NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS *pVidSurfEncrCtrlParams)
//!  DESCRIPTION:   This API is deprecated. 
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 165.02
//! 
//! \retval  NVAPI_NOT_SUPPORTED               Deprecated 
//
///////////////////////////////////////////////////////////////////////////////

//! \addtogroup dxvidcontrol
//! @{

//! Video Surface Encryption Control Commands, 
//! used in \ref NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS.
typedef enum 
{
    NVAPI_VIDSURF_ENCRYPT_CMD_NULL              = 0x00, //!< Null command
    NVAPI_VIDSURF_ENCRYPT_CMD_GET_GUID_COUNT    = 0x01, //!< Get GUID count
    NVAPI_VIDSURF_ENCRYPT_CMD_GET_GUIDS         = 0x02, //!< Get GUIDs
    NVAPI_VIDSURF_ENCRYPT_CMD_SET_GUID          = 0x03, //!< Set GUID
    NVAPI_VIDSURF_ENCRYPT_CMD_ENABLE            = 0x04, //!< Enable encryption
    NVAPI_VIDSURF_ENCRYPT_CMD_SET_KEY           = 0x05, //!< Set key
    NVAPI_VIDSURF_ENCRYPT_CMD_SET_IV            = 0x06  //!< Set IV
} NVAPI_VIDSURF_ENCRYPT_COMMANDS;


//! Used in NVAPI_VIDSURF_ENCRYPT_CTRL_GET_GUIDS
#define NVAPI_VIDSURF_ENCRYPT_MAX_GUIDS        (4)


//! Used in NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS
typedef struct
{
    NvU32   dwGuidCount;                                // (OUT)
} NVAPI_VIDSURF_ENCRYPT_CTRL_GET_GUID_COUNT;


//! Used in NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS
typedef struct
{
    GUID    guids[NVAPI_VIDSURF_ENCRYPT_MAX_GUIDS];     // (OUT)
} NVAPI_VIDSURF_ENCRYPT_CTRL_GET_GUIDS;


//! Used in NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS
typedef struct
{
    GUID    guid;                                       // (IN)
} NVAPI_VIDSURF_ENCRYPT_CTRL_SET_GUID;


//! Used in NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS
typedef struct
{
    IDirect3DSurface9  *pSurface;                       // D3D9 surface ptr (IN)
    NvU32               bEnable;                        // (IN)
} NVAPI_VIDSURF_ENCRYPT_CTRL_ENABLE;


//! Used in NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS
typedef struct
{
    NvU32   dwEncryptKeyProtectionMode;
    NvU32   dwEncryptKeyProtectionIdentifier;
    NvU32   dwKey[4];                                   // (IN)
} NVAPI_VIDSURF_ENCRYPT_CTRL_SET_KEY;


//! Used in NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS
typedef struct
{
    NvU32   dwEncryptKeyProtectionMode;
    NvU32   dwEncryptKeyProtectionIdentifier;
    NvU32   dwIV[4];                                    // (IN)
} NVAPI_VIDSURF_ENCRYPT_CTRL_SET_IV;


//! Used in NvAPI_D3D9_VideoSurfaceEncryptionControl()
typedef struct
{
    NvU32               version;                        // structure version (IN)
    NvU32               dwCommand;                      // command (IN)
    union
    {
        NVAPI_VIDSURF_ENCRYPT_CTRL_GET_GUID_COUNT       GetGuidCount;
        NVAPI_VIDSURF_ENCRYPT_CTRL_GET_GUIDS            GetGuids;
        NVAPI_VIDSURF_ENCRYPT_CTRL_SET_GUID             SetGuid;
        NVAPI_VIDSURF_ENCRYPT_CTRL_ENABLE               Enable;
        NVAPI_VIDSURF_ENCRYPT_CTRL_SET_KEY              SetKey;
        NVAPI_VIDSURF_ENCRYPT_CTRL_SET_IV               SetIV;
    };
} NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS;


#define NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS_VER \
    MAKE_NVAPI_VERSION(NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS,1)

//! @}



//! \ingroup dxvidcontrol
NVAPI_INTERFACE NvAPI_D3D9_VideoSurfaceEncryptionControl(IDirect3DDevice9 *pDev, NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS *pVidSurfEncrCtrlParams);



///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_D3D9_DMA
//
//! \fn NvAPI_D3D9_DMA(IDirect3DDevice9 *pDev, NVAPI_D3D9_DMA_PARAMS *pVideoDMAParams)
//!
//! DESCRIPTION:     This API lets the caller perform a number of functions related to
//!                  the efficient DMA transfer of data between a Direct3D/DirectX 9 surface and
//!                  user-allocated system memory.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 190.17
//!
//! \retval ::NVAPI_OK                           Completed request
//! \retval ::NVAPI_ERROR                        Miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT             Invalid input parameter.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  The version of struct NVAPI_D3D9_DMA_PARAMS
//!                                              is not supported.
///////////////////////////////////////////////////////////////////////////////

//! \addtogroup dxdma
//! @{

//! Direct3D/DirectX 9 DMA commands used in _NVAPI_D3D9_DMA_PARAMS.
typedef enum _NVAPI_D3D9_DMA_COMMANDS
{
    NVAPI_D3D9_DMA_CMD_NULL         = 0x00,             //!< Null command
    NVAPI_D3D9_DMA_CMD_DESCRIBE     = 0x01,             //!< Describe allocation requirements - See _NVAPI_D3D9_DMA_DESCRIBE_PARAMS for parameters.
    NVAPI_D3D9_DMA_CMD_MAP          = 0x02,             //!< Map user-allocated system memory - See _NVAPI_D3D9_DMA_MAP_PARAMS for parameters.
    NVAPI_D3D9_DMA_CMD_UNMAP        = 0x03,             //!< Unmap user-allocated system memory - See _NVAPI_D3D9_DMA_UNMAP_PARAMS for parameters.
    NVAPI_D3D9_DMA_CMD_REG_EVENT    = 0x04,             //!< Register user-mode event handle - See _NVAPI_D3D9_DMA_EVENT_PARAMS for parameters.
    NVAPI_D3D9_DMA_CMD_UNREG_EVENT  = 0x05,             //!< Unregister user-mode event handle - See _NVAPI_D3D9_DMA_EVENT_PARAMS for parameters. 
    NVAPI_D3D9_DMA_CMD_TRANSFER     = 0x06,             //!< Transfer between user system memory and Direct3D/DirectX 9 surface
                                                        //!< See  _NVAPI_D3D9_DMA_TRANSFER_PARAMS for parameters.
    NVAPI_D3D9_DMA_CMD_COLOR_MATRIX = 0x07,             //!< Set up the color matrix for the transfer
} NVAPI_D3D9_DMA_COMMANDS;


//! Specifies the direction of the DMA transfer.
//! See NVAPI_D3D9_DMA_TRANSFER_PARAMS for more details.
typedef enum _NVAPI_D3D9_DMA_TRANSFER_DIR
{
    NVAPI_D3D9_DMA_TRANSFER_DIR_UPLOAD     = 0x00,      //!< Transfer from user system memory to Direct3D/DirectX 9 surface.
    NVAPI_D3D9_DMA_TRANSFER_DIR_DOWNLOAD   = 0x01,      //!< Transfer from Direct3D/DirectX 9 surface to user system memory.
} NVAPI_D3D9_DMA_TRANSFER_DIR;


//! Specifies the type of the DMA transfer.
//! See NVAPI_D3D9_DMA_TRANSFER_PARAMS for more details.
typedef enum _NVAPI_D3D9_DMA_TRANSFER_TYPE
{
    NVAPI_D3D9_DMA_TRANSFER_TYPE_PROGRESSIVE    = 0x00, //!< Transfer progressive frame.
    NVAPI_D3D9_DMA_TRANSFER_TYPE_INTERLACED     = 0x01, //!< Transfer both fields and keep the result interleaved.
    NVAPI_D3D9_DMA_TRANSFER_TYPE_BOB_TOP_FIELD  = 0x02, //!< Perform bob deinterlacing on the top field.
    NVAPI_D3D9_DMA_TRANSFER_TYPE_BOB_BTM_FIELD  = 0x03, //!< Perform bob deinterlacing on the bottom field.
} NVAPI_D3D9_DMA_TRANSFER_TYPE;


#define NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_STD_MASK (NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_STD_601|NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_STD_709|NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_STD_240|NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_STD_CUSTOM)

#define NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_RANGE_MASK (NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_RANGE_FULL| NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_RANGE_LIM)

//! Specifies the type of the color space and range.
//! See ::NVAPI_D3D9_DMA_CMD_COLOR_MATRIX for more details
typedef enum _NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS
{
    NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_STD_601         = 0x01, //!< Color Standard: 601
    NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_STD_709         = 0x02, //!< Color Standard: 709
    NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_STD_240         = 0x04, //!< Color Standard: 240
    NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_STD_CUSTOM      = 0x08, //!< Color Standard: Custom
    NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_RANGE_FULL      = 0x10, //!< Color Range: Full [0 .. 255]
    NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_RANGE_LIM       = 0x20, //!< Color Range: Limited [16 .. 235]
} NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS;



//! Parameter data structure for the NVAPI_D3D9_DMA_CMD_DESCRIBE command (See ::_NVAPI_D3D9_DMA_COMMANDS.)
//! Given the surface dimension and format as input, the command
//! provides the driver requirements (such as alignment) for memory allocation.
typedef struct _NVAPI_D3D9_DMA_DESCRIBE_PARAMS
{
    NvU32                       dwWidth;                //!< width (IN)
    NvU32                       dwHeight;               //!< height (IN)
    NvU32                       dwFormat;               //!< FOURCC format (IN)
    NvU32                       dwPitch;                //!< pitch (OUT)
    NvU32                       dwSize;                 //!< size (OUT)
    NvU32                       dwAlignment;            //!< alignment (OUT)
} NVAPI_D3D9_DMA_DESCRIBE_PARAMS;


//! Parameter data structure for the NVAPI_D3D9_DMA_CMD_MAP command. (See ::_NVAPI_D3D9_DMA_COMMANDS.)
//! The command maps user-allocated system memory buffer to an NVIDIA DirectX object handle.
//! The pMemory buffer must satisfy the driver requirements.
//! Supported FOURCC formats are: NV12, YV12, YUY2
typedef struct _NVAPI_D3D9_DMA_MAP_PARAMS
{
    NvU32                       dwWidth;                //!< width (IN)
    NvU32                       dwHeight;               //!< height (IN)
    NvU32                       dwFormat;               //!< FOURCC format (IN)
    void                       *pMemory;                //!< memory pointer (IN)
    NVDX_ObjectHandle           hSysmemSurface;         //!< sysmem surface handle (OUT)
} NVAPI_D3D9_DMA_MAP_PARAMS;


//! Parameter data structure for the NVAPI_D3D9_DMA_CMD_UNMAP command. (See ::_NVAPI_D3D9_DMA_COMMANDS.)
//! The command unmaps the user-allocated system memory buffer.
typedef struct _NVAPI_D3D9_DMA_UNMAP_PARAMS
{
    NVDX_ObjectHandle           hSysmemSurface;         //<! sysmem surface handle (IN)
} NVAPI_D3D9_DMA_UNMAP_PARAMS;


//! Parameter data structure for the NVAPI_D3D9_DMA_CMD_REG_EVENT
//! command and the NVAPI_D3D9_DMA_CMD_UNREG_EVENT command. (See ::_NVAPI_D3D9_DMA_COMMANDS.)
//! The commands register or unregister a user-mode event handle with the Direct3D/DireectX 9 device.
typedef struct _NVAPI_D3D9_DMA_EVENT_PARAMS
{
    HANDLE                      hCompletionEvent;       //!< user-mode event handle (IN)
} NVAPI_D3D9_DMA_EVENT_PARAMS;



//! Parameter data structure for the NVAPI_D3D9_DMA_CMD_TRANSFER command. (See ::_NVAPI_D3D9_DMA_COMMANDS.)
//! The command performs DMA transfers between system memory buffer and the Direct3D/DirectX 9 surface.
//! It supports both upload and download directions, and supports scaling, color space and pixel format conversion.
//! A NULL rectangle indicates that the entire surface is used. \n
//! The last reserved word is used to specify the scaling interpolation method
//! and whether the source transfer rect has floating point co-ordinates.
//! Floating point rects and smoothing levels are applied to NV12/IYUV/YV12->ARGB transfers only.
typedef struct _NVAPI_D3D9_DMA_TRANSFER_PARAMS
{
    NVAPI_D3D9_DMA_TRANSFER_DIR     direction;          //!< Direction of the transfer (IN)
    NVDX_ObjectHandle               hSysmemSurface;     //!< sysmem surface handle (IN)
    RECT*                           pSysmemSurfaceRect; //!< sysmem surface rectangle (IN)
    NVDX_ObjectHandle               hD3D9Surface;       //!< D3D9 surface handle (IN)
    RECT*                           pD3D9SurfaceRect;   //!< floatSrcRectFlag=0 => (RECT *) D3D9 Surface rectangle with integral co-ords (IN)
                                                        //!< floatSrcRectFlag=1 => (RECTF *)D3D9 Surface rectangle with float co-ords appended to integral co-ords (IN)

    HANDLE                          hCompletionEvent;   //!< Completion event handle (IN)
    NVAPI_D3D9_DMA_TRANSFER_TYPE    transferType;       //!< Type of the transfer (IN)
    NvU32                           floatSrcRectFlag:1; //!< 1=>pD3D9SurfaceRectF has float co-ords appended (IN)
    NvU32                           smoothingLevel:2;   //!< Type of interpolation for scaling. 
                                                        //!< 0=>Bilinear, 1=>Nearest Neighbor, 2,3=>Reserved for future.
    NvU32                           reserved:17;           //!< Reserved for future expansion (IN / OUT)
    NvU32                           reservedFlagValid:12;//!< Secret keyword that implies floatSrcRectFlag/smoothingLevel flags are valid (IN)
} NVAPI_D3D9_DMA_TRANSFER_PARAMS;



//! Used in _NVAPI_D3D9_DMA_COLOR_MATRIX_PARAMS.
#define NVAPI_D3D9_DMA_COLOR_MATRIX_SIZE            12

//! parameter data structure for the NVAPI_D3D9_DMA_CMD_COLOR_MATRIX command \n
//! Specifies the flags for the color spaces and color range.
//! Currently color Spaces 601 and 709 are available inside the driver. For others, the input
//! color matrix [cm0-cm11] will be used. It has the following format for a YUV to RGB color conversion
//! \code   
//!   | cm0  cm1  cm2 |    | y |   | cm9  |    | r |
//!   | cm3  cm4  cm5 | * (| u | + | cm10 |) = | g |
//!   | cm6  cm7  cm8 |    | v |   | cm11 |    | b |
//!  i.e.  MATRIX * (YUV + const) = RGB
//! \endcode
//!  The offsets cm9..cm11 are divided by 255.
typedef struct _NVAPI_D3D9_DMA_COLOR_MATRIX_PARAMS
{
   NvU32                             colorMatrixFlags;  //!< NVAPI_D3D9_DMA_COLOR_MATRIX_FLAGS_XX flags to define the color space and range.
   float*                            colorMatrix;       //!< 4x3 float array containing the matrix (NVAPI_D3D9_DMA_COLOR_MATRIX_SIZE)
} NVAPI_D3D9_DMA_COLOR_MATRIX_PARAMS;



//! Used in NvAPI_D3D9_DMA(). 
typedef struct _NVAPI_D3D9_DMA_PARAMS
{
    NvU32               version;                        //!< Structure version (IN)
    NvU32               dwCommand;                      //!< Command (IN)
    union
    {
        NVAPI_D3D9_DMA_DESCRIBE_PARAMS     DescribeParams;
        NVAPI_D3D9_DMA_MAP_PARAMS          MapParams;
        NVAPI_D3D9_DMA_UNMAP_PARAMS        UnmapParams;
        NVAPI_D3D9_DMA_EVENT_PARAMS        EventParams;
        NVAPI_D3D9_DMA_TRANSFER_PARAMS     TransferParams;
        NVAPI_D3D9_DMA_COLOR_MATRIX_PARAMS ColorMatrixParams;
    };
} NVAPI_D3D9_DMA_PARAMS;


//! Macro for constructing the version field of _NVAPI_D3D9_DMA_PARAMS.
#define NVAPI_D3D9_DMA_PARAMS_VER \
    MAKE_NVAPI_VERSION(NVAPI_D3D9_DMA_PARAMS, 1)

//! @}


//! \ingroup dxdma
NVAPI_INTERFACE NvAPI_D3D9_DMA(IDirect3DDevice9 *pDev,
    NVAPI_D3D9_DMA_PARAMS *pVideoDMAParams);


//  SUPPORTED OS: Windows XP and higher

//! \ingroup dx
//! @{

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION_NAME: NvAPI_D3D9_EnableStereo
//
//! \fn NvAPI_D3D9_EnableStereo(IDirect3DDevice9 *pDev,
//!     NVAPI_D3D9_ENABLE_STEREO_PARAMS *pEnableStereoParams)
//!   DESCRIPTION:   This API allows an approved application to enable stereo viewing
//!                  on an HDMI 1.4 TV.
//!
//! \retval ::NVAPI_OK                 completed request
//! \retval ::NVAPI_INVALID_ARGUMENT   the vendor ID and/or response is invalid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION   the version of NVAPI_D3D9_ENABLE_STEREO_PARAMS struct not supported.
//
///////////////////////////////////////////////////////////////////////////////

//! D3D9 Enable Stereo Commands
typedef enum _NVAPI_D3D9_ENABLE_STEREO_COMMANDS
{
    NVAPI_D3D9_ENABLE_STEREO_CMD_CHALLENGE = 0x01,
    NVAPI_D3D9_ENABLE_STEREO_CMD_RESPONSE  = 0x02,
} NVAPI_D3D9_ENABLE_STEREO_COMMANDS;

//! D3D9 Enable Stereo Constants
#define NVAPI_D3D9_ENABLE_STEREO_CHALLENGE_SIZE     16
//! D3D9 Enable Stereo Constants
#define NVAPI_D3D9_ENABLE_STEREO_RESPONSE_SIZE      20

//
//! Parameter data structure for the NVAPI_D3D9_ENABLE_STEREO_CMD_CHALLENGE command - 
//! This command requests a random challenge from driver.
//! It must be invoked before the NVAPI_D3D9_ENABLE_STEREO_CMD_RESPONSE command.
typedef struct _NVAPI_D3D9_ENABLE_STEREO_CHALLENGE_PARAMS
{
    NvU8 challenge[NVAPI_D3D9_ENABLE_STEREO_CHALLENGE_SIZE];    //!< random challenge from driver (OUT)
} NVAPI_D3D9_ENABLE_STEREO_CHALLENGE_PARAMS;

//
//! Parameter data structure for the NVAPI_D3D9_ENABLE_STEREO_CMD_RESPONSE command
//!
//! The application must possess the following information in order to calculate a valid response:
//! - vendorGUID: a unique ID assigned to the application vendor by NVIDIA;
//! - vendorKEY:  a secret key issued to the application vendor by NVIDIA;
//!
//! The response is calculated as HMAC(vendorKEY, (vendorGUID || challenge))
//! where HMAC is the Keyed-Hash Message Authentication Code using SHA-1 as the
//! underlying hash function. See FIPS Publication 198 for details of the algorithm.
typedef struct _NVAPI_D3D9_ENABLE_STEREO_RESPONSE_PARAMS
{
    NvGUID vendorGUID;                                          //!< vendor GUID from app (IN)
    NvU8   response[NVAPI_D3D9_ENABLE_STEREO_RESPONSE_SIZE];    //!< response from the app (IN)
} NVAPI_D3D9_ENABLE_STEREO_RESPONSE_PARAMS;

typedef struct _NVAPI_D3D9_ENABLE_STEREO_PARAMS
{
    NvU32 version;                      //!< structure version (IN)
    NvU32 dwCommand;                    //!< command (IN)
    union
    {
        NVAPI_D3D9_ENABLE_STEREO_CHALLENGE_PARAMS   ChallengeParams;
        NVAPI_D3D9_ENABLE_STEREO_RESPONSE_PARAMS    ResponseParams;
    };
} NVAPI_D3D9_ENABLE_STEREO_PARAMS_V1;

typedef NVAPI_D3D9_ENABLE_STEREO_PARAMS_V1      NVAPI_D3D9_ENABLE_STEREO_PARAMS;
#define NVAPI_D3D9_ENABLE_STEREO_PARAMS_VER1    MAKE_NVAPI_VERSION(NVAPI_D3D9_ENABLE_STEREO_PARAMS_V1, 1)
#define NVAPI_D3D9_ENABLE_STEREO_PARAMS_VER     NVAPI_D3D9_ENABLE_STEREO_PARAMS_VER1

NVAPI_INTERFACE NvAPI_D3D9_EnableStereo(IDirect3DDevice9 *pDev,
    NVAPI_D3D9_ENABLE_STEREO_PARAMS *pEnableStereoParams);

//! @}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_StretchRect
//
//! DESCRIPTION:    This API copies the contents of the source rectangle to the
//!                  destination rectangle.  This function can convert
//!                  between a wider range of surfaces than
//!                  IDirect3DDevice9::StretchRect. For example, it can copy
//!                  from a depth/stencil surface to a texture.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 177.84
//!
//! \param [in]      pDev       The D3D device that owns the objects.
//! \param [in]      hSrcObj    Handle to the source object.
//! \param [in]      pSrcRect   Defines the rectangle on the source to copy from.  If NULL, copy from the entire object.
//! \param [in]      hDstObj    Handle to the destination object.
//! \param [in]      pDstRect   Defines the rectangle on the destination to copy to.  If NULL, copy to the entire object.
//! \param [in]      Filter     Choose a filtering method: D3DTEXF_NONE, D3DTEXF_POINT, D3DTEXF_LINEAR.
//!
//! \return ::NVAPI_OK,    
//!         ::NVAPI_INVALID_POINTER, 
//!         ::NVAPI_INVALID_ARGUMENT, 
//!         ::NVAPI_ERROR 
//!
//! \ingroup dxvidcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_StretchRect(IDirect3DDevice9 *pDev,
                                       NVDX_ObjectHandle hSrcObj,
                                       CONST RECT * pSourceRect,
                                       NVDX_ObjectHandle hDstObj,
                                       CONST RECT * pDestRect,
                                       D3DTEXTUREFILTERTYPE Filter);




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_D3D9_CreateRenderTarget
//
//! DESCRIPTION:     This API is deprecated.
//! 
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 190.05
//!
//! \retval ::NVAPI_NOT_SUPPORTED  deprecated
//
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_CreateRenderTarget(IDirect3DDevice9 *pDev,
                                              UINT Width,
                                              UINT Height,
                                              D3DFORMAT Format,
                                              D3DMULTISAMPLE_TYPE MultiSample,
                                              DWORD MultisampleQuality,
                                              BOOL Lockable,
                                              IDirect3DSurface9** ppSurface,
                                              NVDX_ObjectHandle *pHandle = NULL);


#endif //defined(_D3D9_H_) && defined(__cplusplus)



#if defined(__cplusplus)


//! \ingroup dx
typedef enum 
{

    // include in NDA for IFR
    NVFBC_FORMAT_ARGB               =      0,      //!< ARGB 
    NVFBC_FORMAT_RGB                =      1,      //!< RGB packed
    NVFBC_FORMAT_YUV_420            =      2,      //!< YYYYUV
    NVFBC_FORMAT_RGB_PLANAR         =      3,      // RGB planar, RRRRRRRR GGGGGGGG BBBBBBBB



}NVFBC_BUFFER_FORMAT;

#endif //defined(__cplusplus)



#if defined(_D3D9_H_) && defined(__cplusplus)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_IFR_SetUpTargetBufferToSys
//
//!   DESCRIPTION: This API requests the driver to allocate n buffers (up to a maximum of 3). 
//!                Additional calls to NvAPI_D3D9_IFR_SetUpTargetBufferToSys() will free the buffers that were allocated previously with the same call on the d3d device. 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   pDev       The device to get primary surface on
//! \param [in]   eFormat    The format of the blit
//! \param [in]   dwNBuffers The number of buffers in ppBuffer (max 3).
//! \param [in]   ppBuffer   A pointer to an array of dwNBuffers (max 3) pointers. Virtual memory buffers will be allocated by the driver.
//! \param [in]   ppDiffmap  Reserved
//!
//! \return ::NVAPI_OK
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_IFR_SetUpTargetBufferToSys(IDirect3DDevice9 *pDev, NVFBC_BUFFER_FORMAT eFormat, DWORD dwNBuffers, unsigned char ** ppBuffer, unsigned char ** ppDiffMap);
 

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_GPUBasedCPUSleep
//
//! \fn NvAPI_D3D9_GPUBasedCPUSleep(IDirect3DDevice9 *pDev, NvU64 qwMicroSeconds)
//!   DESCRIPTION: This API provides sub-quantum (usually 16 ms) sleep that does not burn CPU cycles. 
//!
//! \param [in] pDev           The device for which to get the primary surface 
//! \param [in] qwMicroSeconds The number of micro-seconds to block the CPU thread
//!
//! \return ::NVAPI_OK if the call succeeded
//
///////////////////////////////////////////////////////////////////////////////

//  SUPPORTED OS: Windows Vista and higher
//! \ingroup dx
NVAPI_INTERFACE NvAPI_D3D9_GPUBasedCPUSleep(IDirect3DDevice9 *pDev, NvU64 qwMicroSeconds);






///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_IFR_TransferRenderTarget
//
//!  DESCRIPTION: This API copies the current rendertarget into the provided system memory buffer.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]      pDev      The device to get primary surface on
//! \param [in]      pEvent    When not NULL, will receive a handle to an event that the driver will signal 
//!                            upon completion of NvAPI_D3D9_IFR_TransferRenderTarget().
//! \param [in]      dwBufferIndex  The index of the buffer that will receive a copy of the rendertarget. 
//!                                 This ordinal is between 0 and the number of buffer created by NvAPI_D3D9_IFR_SetUpTargetBufferToSys().
//! \param [in]      dwTargetWidth  When dwTargetWidth and dwTargetHeight are not 0, a bilinear filtered scaling 
//!                                 will be done before the blit to system memory.
//! \param [in]      dwTargetHeight When dwTargetWidth and dwTargetHeight are not 0, a bilinear filtered scaling 
//!                                 will be done before the blit to system memory.
//!
//! \return ::NVAPI_OK 
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_IFR_TransferRenderTarget(IDirect3DDevice9 *pDev, HANDLE * pEvent, DWORD dwBufferIndex, DWORD dwTargetWidth, DWORD dwTargetHeight);
    

#endif // defined(_D3D9_H_) && defined(__cplusplus)



//-----------------------------------------------------------------------------
// Direct3D10 APIs
//-----------------------------------------------------------------------------

#if defined(__cplusplus) && defined(__d3d10_h__)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D10_AliasPrimaryAsTexture
//
//!   DESCRIPTION: This function creates a texture that is an alias of the current device's
//!                primary surface
//!
//!  \note The texture returned is created without any CPU access flags. Locking
//!        to read from the texture should be done by creating a second
//!        application. Otherwise, this texture can be used as any normal
//!        Direct3D texture (it can be blitted from, used as a texture in a
//!        pixel shader, etc.)
//!
//!        This texture is not a render target and cannot be rendered to.
//!
//!        Before this texture is used, the application must call
//!        NvAPI_D3D10_ProcessFlipChainCallbacks() to properly update any internal
//!        driver state.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!   \since Version: 174.80 
//!
//!   \param [in]  pDev        The device to get the primary surface from
//!   \param [in]  dwHeadIndex The index to the head to alias
//!   \param [out] ppTexture   Filled with the texture created
//!
//!   \retval      NVAPI_OK    The texture was successfully created.
//!   \retval      NVAPI_ERROR The texture could not be created.
//!
//!   \ingroup dx
/////////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D10_AliasPrimaryAsTexture(ID3D10Device *pDev,
                                             NvU32 headIndex,
                                             ID3D10Texture2D **ppTexture);

//! \ingroup dx
typedef void (*NVAPI_PRIMARY_FLIP_CHAIN_CALLBACK)(NvU32);

//! \ingroup dx
//! Used by NVAPI_PRIMARY_FLIP_CHAIN_CALLBACK.
typedef struct
{
    NvU32                     version;              //!< structure version (IN)

    NVAPI_PRIMARY_FLIP_CHAIN_CALLBACK pPrimaryFlipped; //!< A callback function to be notified
                                                       //!  when the primary flip occurred.

    NVAPI_PRIMARY_FLIP_CHAIN_CALLBACK pPrimaryFlipChainModified; //!< A callback function to be notified
                                                                 //!  when the primary flip chain has
                                                                 //!  been modified, either due to a new
                                                                 //!  surface being added, an existing
                                                                 //!  surface being removed, or the resolution
                                                                 //!  being changed. In response to this
                                                                 //!  an application MUST recreate any
                                                                 //!  aliased primary surfaces with
                                                                 //!  NvAPI_D3D10_AliasPrimaryAsTexture()
                                                                 //!  as the existing texture will be invalid.

    NVAPI_PRIMARY_FLIP_CHAIN_CALLBACK pPrimaryAliasInvalid; //!< An error occured while using a texture
                                                            //!  created with NvAPI_D3D10_AliasPrimaryAsTexture().
                                                            //!  The texture needs to be re-created.

    NVAPI_PRIMARY_FLIP_CHAIN_CALLBACK pPrimaryAliasOperationDropped; //!< An operation using the primary alias
                                                                     //!  was not completed because a flip
                                                                     //!  happened while the operation
                                                                     //!  was in progress. The last operation
                                                                     //!  may have operated on an incomplete
                                                                     //!  primary, and should be retried.

    NVAPI_PRIMARY_FLIP_CHAIN_CALLBACK pCursorVisibleUpdated;  //!< A callback function to be notified
                                                              //!  when the cursor visibility has been toggled

    NVAPI_PRIMARY_FLIP_CHAIN_CALLBACK pCursorShapeUpdated; //!< A callback function to be notified
                                                           //!  when the cursor shape has been updated

} NVAPI_FLIP_CHAIN_CALLBACK_PARAMS;

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D10_SetPrimaryFlipChainCallbacks
//
//!   DESCRIPTION: Defines callback functions to receive notification about
//!                certain events relating to the primary flip chain.
//!
//!   \note The events will only be registered at this time. To receive the events
//!         an application must call NvAPI_D3D10_ProcessFlipChainCallbacks().
//!
//!         An application may change it's callback functions at any time, and may
//!         unregister from any function by passing NULL in as a function pointer.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//!   \since Version: 174.80 
//!
//!   \param [in]  pDev             The device to receive events on
//!   \param [in]  pCallbackParams  A structure containing function
//!                                 pointers that will receive the events.
//!                                 A pointer may be set to NULL if
//!                                 an application does not wish to receive
//!                                 the notification.
//!
//!  \return NVAPI_OK if the events were registered successfully
//!
//!  \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D10_SetPrimaryFlipChainCallbacks(ID3D10Device *pDev,
                                             const NVAPI_FLIP_CHAIN_CALLBACK_PARAMS* pCallbackParams);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D10_ProcessCallbacks
//
//!   DESCRIPTION: This function processes pending events. 
//!
//! \note All callback functions are passed the head index for the event.
//!
//!       This will call the registered callbacks for any events pending. With
//!       the exeception of the primary flipped callback, an application cannot
//!       "miss" an event if the event were to be notified while the
//!       application was not calling ProcessCallbacks. The application
//!       will receive this event the first time it calls ProcessCallbacks
//!       after the event happened.
//!
//!       The flipped event is an exception to this rule. This callback will
//!       only be fired for flips that occur after the application calls
//!       ProcessCallbacks.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!   \since Version: 174.80 
//!
//!   \param [in]  pDev            The device to process events on
//!   \param [in]  dwMilliseconds  The number of milliseconds to sleep while
//!                                waiting for events before returning. This
//!                                can be zero to only process any outstanding
//!                                events, or INFINITE if the application
//!                                wishes to wait forever.
//!
//!   \return  NVAPI_OK if events were properly processed
//!
//!   \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D10_ProcessCallbacks(ID3D10Device *pDev,
                                             NvU32 dwMilliseconds);


 

//! \ingroup dx
//! Used in 
typedef enum
{
    NV_HW_CURSOR_COLOR_FORMAT_MONOCHROME     = 0,
    NV_HW_CURSOR_COLOR_FORMAT_COLOR          = 1,
    NV_HW_CURSOR_COLOR_FORMAT_MASKED_COLOR   = 2
} NV_HW_CURSOR_COLOR_FORMAT_FLAGS;

//! \ingroup dx
//! Used in NvAPI_D3D10_GetRenderedCursorAsBitmap().
typedef struct _NVAPI_RENDERED_CURSOR_BITMAP_DATA
{
    NvU32 version;     //!< (in) version info
    NvU32 headIndex;   //!< (in) head index to get cursor on
    NvU32 bufferSize;  //!< (in) size of raw bitmap data buffer
    PBITMAP pBitmap;   //!< (in/out) bitmap data for rendered cursor
    NvU32 xHot;        //!< (out) x value for Hotspot
    NvU32 yHot;        //!< (out) y value for Hotspot
    NV_HW_CURSOR_COLOR_FORMAT_FLAGS formatFlag; //!, (out) cursor color format
    NvU32 bVisible;    //!< (out) cursor visibility (0 = not visible, 1 = visible)
} NVAPI_RENDERED_CURSOR_BITMAP_DATA;


//! \ingroup dx
//! Macro for constructing theversion field of _NVAPI_RENDERED_CURSOR_BITMAP_DATA
#define NVAPI_RENDERED_CURSOR_BITMAP_DATA_VER  MAKE_NVAPI_VERSION(NVAPI_RENDERED_CURSOR_BITMAP_DATA,1)



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D10_GetRenderedCursorAsBitmap
//
//!   DESCRIPTION:  This function provides a bitmap of the hardware cursor and the visible
//!                 state of the cursor at the time the bitmap is captured.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!   \since Version: 174.80 
//!
//!   \param [in]     pDev                       The device from which to get the rendered cursor
//!   \param [in,out] pRenderedCursorBitmapData  Structure for input/output with fields as follows:
//!                                              - headIndex:  [input] The display head from which to get the cursor  
//!                                              - bufferSize: [input] The size of the buffer for storing raw bitmap data
//!                                              - pBitmap:    [output] Bitmap data for the rendered cursor.  
//!                                                                     Note that this result data is undefined in the
//!                                                                     case where NVAPI_OK is not the return status
//!                                              - xHot: [output] Location of the X hot spot in the bitmap
//!                                              - yHot: [output] Location of the Y hot spot in the bitmap
//!                                              - formatFlag: [output] Cursor format (monochrome, color, or masked color)
//!                                                                     For monochrome or masked color formats, the corresponding bitmap
//!                                                                     format is ROP1R5G5B5.  For color format, the bitmap format is A8R8G8B8.   //!   
//!                                              - pVisible: [output]  Boolean:  zero=not visible, one=visible
//!
//!   \return NVAPI_OK if the cursor bitmap is successfully returned
//!
//!  \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D10_GetRenderedCursorAsBitmap(ID3D10Device *pDev,
                                                      NVAPI_RENDERED_CURSOR_BITMAP_DATA *pRenderedCursorBitmapData);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D10_BeginShareResource
//
//!   DESCRIPTION:  This API recreates the resource as a shared resource.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   pResource   The resource to recreate as shared
//! \param [out]  pHandle     The shared resource handle
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status. 
//!                 If there are return error codes with specific meaning for this API, they are listed below.
//!                 (None)
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D10_BeginShareResource(ID3D10Resource *pResource,
                                               HANDLE         *pHandle);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D10_BeginShareResourceEx
//
//!   DESCRIPTION:  This API is similar to NvAPI_D3D10_BeginShareResource(), except it takes an additional flag parameter.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]  pResource   The resource to recreate as shared
//! \param [in]  flags       Should be one of NVAPI_SHARE_RESOURCE_FLAGS
//! \param [out] pHandle     The shared resource handle
//!
//!
//! \return  This API can return any of the error codes enumerated in #NvAPI_Status. 
//!                 If there are return error codes with specific meaning for this API, they are listed below.
//!                 (None)
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D10_BeginShareResourceEx(ID3D10Resource *pResource,
                                                 UINT32          flags,
                                                 HANDLE         *pHandle);




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D10_EndShareResource
//
//!   DESCRIPTION:  This API restores the original resource.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in] pResource    The resource that was shared using NvAPI_D3D10_BeginShareResource
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status. 
//!                 If there are return error codes with specific meaning for this API, they are listed below.
//!                 (None)
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D10_EndShareResource(ID3D10Resource *pResource);




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D10_SetDepthBoundsTest
//
//!   DESCRIPTION: This function enables/disables the depth bounds test.
//!
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!   \param [in]  pDev         The device to set the depth bounds test
//!   \param [in]  bEnable      Enable(non-zero)/disable(zero) the depth bounds test
//!   \param [in]  fMinDepth    The minimum depth for the depth bounds test
//!   \param [in]  fMaxDepth    The maximum depth for the depth bounds test \n
//!                             The valid values for fMinDepth and fMaxDepth
//!                             are such that 0 <= fMinDepth <= fMaxDepth <= 1
//!
//!   \return NVAPI_OK if the depth bounds test was correctly enabled or disabled 
//!
//!   \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D10_SetDepthBoundsTest(ID3D10Device *pDev,
                                               NvU32 bEnable,
                                               float fMinDepth,
                                               float fMaxDepth);


#ifdef __d3d10_1_h__


//////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D10_CreateDevice
//
//!   DESCRIPTION: This function creates a d3d10 device. The function call is the 
//!                same as D3D10CreateDevice1(), but with an extra argument 
//!                (#D3D10_FEATURE_LEVEL supported by the device) that the function fills in.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!   \since Version: 177.32 
//!
//!   \param [in]     pAdapter
//!   \param [in]     DriverType
//!   \param [in]     Software
//!   \param [in]     Flags
//!   \param [in]     HardwareLevel
//!   \param [in]     SDKVersion
//!   \param [in]     ppDevice
//!   \param [in]     *pLevel  D3D10_FEATURE_LEVEL supported - see #NVAPI_DEVICE_FEATURE_LEVEL
//!
//!   \return  NVAPI_OK if the createDevice call succeeded.
//
//////////////////////////////////////////////////////////////////////////

//! \ingroup dx
//! D3D10_FEATURE_LEVEL supported - used in NvAPI_D3D10_CreateDevice() and NvAPI_D3D10_CreateDeviceAndSwapChain()
typedef enum
{
    NVAPI_DEVICE_FEATURE_LEVEL_NULL       = -1,
    NVAPI_DEVICE_FEATURE_LEVEL_10_0       = 0,
    NVAPI_DEVICE_FEATURE_LEVEL_10_0_PLUS  = 1,
    NVAPI_DEVICE_FEATURE_LEVEL_10_1       = 2,
    NVAPI_DEVICE_FEATURE_LEVEL_11_0       = 3,
} NVAPI_DEVICE_FEATURE_LEVEL;


//!   \ingroup dx
NVAPI_INTERFACE NvAPI_D3D10_CreateDevice(IDXGIAdapter* pAdapter,
                                         D3D10_DRIVER_TYPE DriverType,
                                         HMODULE Software,
                                         UINT32 Flags,
                                         D3D10_FEATURE_LEVEL1 HardwareLevel,
                                         UINT SDKVersion,
                                         ID3D10Device1** ppDevice,
                                         NVAPI_DEVICE_FEATURE_LEVEL *pLevel);
////////////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D10_CreateDeviceAndSwapChain
//
//!   DESCRIPTION: This function creates a d3d10 device and swap chain. The function call is the 
//!                same as D3D10CreateDeviceAndSwapChain1(), but with an extra argument 
//!                (D3D10_FEATURE_LEVEL supported by the device) that the function fills in .
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!   \since Version: 177.32 
//!
//!   \param [in]   pAdapter
//!   \param [in]   DriverType
//!   \param [in]   Software
//!   \param [in]   Flags
//!   \param [in]   HardwareLevel
//!   \param [in]   SDKVersion
//!   \param [in]   pSwapChainDesc
//!   \param [in]   ppSwapChain
//!   \param [in]   ppDevice
//!   \param [in]   pLevel       D3D10_FEATURE_LEVEL supported - see see #NVAPI_DEVICE_FEATURE_LEVEL
//!
//!   \return  NVAPI_OK if the createDevice with swap chain call succeeded.
//!
//!   \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D10_CreateDeviceAndSwapChain(IDXGIAdapter* pAdapter,
                                                     D3D10_DRIVER_TYPE DriverType,
                                                     HMODULE Software,
                                                     UINT32 Flags,
                                                     D3D10_FEATURE_LEVEL1 HardwareLevel,
                                                     UINT SDKVersion,
                                                     DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
                                                     IDXGISwapChain** ppSwapChain,
                                                     ID3D10Device1** ppDevice,
                                                     NVAPI_DEVICE_FEATURE_LEVEL *pLevel);


#endif //defined(__d3d10_1_h__)





//-----------------------------------------------------------------------------
// Private Direct3D10 APIs
//-----------------------------------------------------------------------------
#endif // defined(__cplusplus) && defined(__d3d10_h__)



//-----------------------------------------------------------------------------
// Direct3D11 APIs
//-----------------------------------------------------------------------------


#if defined(__cplusplus) && defined(__d3d11_h__)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D11_CreateDevice
//
//!   DESCRIPTION: This function tries to create a DirectX 11 device. If the call fails (if we are running
//!                on pre-DirectX 11 hardware), depending on the type of hardware it will try to create a DirectX 10.1 OR DirectX 10.0+
//!                OR DirectX 10.0 device. The function call is the same as D3D11CreateDevice(), but with an extra 
//!                argument (D3D_FEATURE_LEVEL supported by the device) that the function fills in. This argument
//!                can contain -1 (NVAPI_DEVICE_FEATURE_LEVEL_NULL), if the requested featureLevel is less than DirecX 10.0.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//!
//! \param [in]   pAdapter
//! \param [in]   DriverType
//! \param [in]   Software
//! \param [in]   Flags
//! \param [in]   *pFeatureLevels
//! \param [in]   FeatureLevels
//! \param [in]   SDKVersion
//! \param [in]   **ppDevice
//! \param [in]   *pFeatureLevel
//! \param [in]   **ppImmediateContext
//! \param [in]   *pSupportedLevel  D3D_FEATURE_LEVEL supported
//!
//! \return NVAPI_OK if the createDevice call succeeded.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D11_CreateDevice(IDXGIAdapter* pAdapter,
                                         D3D_DRIVER_TYPE DriverType,
                                         HMODULE Software,
                                         UINT Flags,
                                         CONST D3D_FEATURE_LEVEL *pFeatureLevels,
                                         UINT FeatureLevels,
                                         UINT SDKVersion,
                                         ID3D11Device **ppDevice,
                                         D3D_FEATURE_LEVEL *pFeatureLevel,
                                         ID3D11DeviceContext **ppImmediateContext,
                                         NVAPI_DEVICE_FEATURE_LEVEL *pSupportedLevel);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D11_CreateDeviceAndSwapChain
//
//!   DESCRIPTION: This function tries to create a DirectX 11 device and swap chain. If the call fails (if we are 
//!                running on pre=DirectX 11 hardware), depending on the type of hardware it will try to create a DirectX 10.1 OR 
//!                DirectX 10.0+ OR DirectX 10.0 device. The function call is the same as D3D11CreateDeviceAndSwapChain,  
//!                but with an extra argument (D3D_FEATURE_LEVEL supported by the device) that the function fills
//!                in. This argument can contain -1 (NVAPI_DEVICE_FEATURE_LEVEL_NULL), if the requested featureLevel
//!                is less than DirectX 10.0.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//!
//! \param [in]     pAdapter
//! \param [in]     DriverType
//! \param [in]     Software
//! \param [in]     Flags
//! \param [in]     *pFeatureLevels
//! \param [in]     FeatureLevels
//! \param [in]     SDKVersion
//! \param [in]     *pSwapChainDesc
//! \param [in]     **ppSwapChain
//! \param [in]     **ppDevice
//! \param [in]     *pFeatureLevel
//! \param [in]     **ppImmediateContext
//! \param [in]     *pSupportedLevel  D3D_FEATURE_LEVEL supported
//!
//!return  NVAPI_OK if the createDevice with swap chain call succeeded.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D11_CreateDeviceAndSwapChain(IDXGIAdapter* pAdapter,
                                         D3D_DRIVER_TYPE DriverType,
                                         HMODULE Software,
                                         UINT Flags,
                                         CONST D3D_FEATURE_LEVEL *pFeatureLevels,
                                         UINT FeatureLevels,
                                         UINT SDKVersion,
                                         CONST DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
                                         IDXGISwapChain **ppSwapChain,
                                         ID3D11Device **ppDevice,
                                         D3D_FEATURE_LEVEL *pFeatureLevel,
                                         ID3D11DeviceContext **ppImmediateContext,
                                         NVAPI_DEVICE_FEATURE_LEVEL *pSupportedLevel);




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D11_BeginShareResource
//
//!   DESCRIPTION:  This API recreates the resource as a shared resource.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//!  \param [in]  pResource   The resource to recreate as shared
//!  \param [in]  flags       Should be one of NVAPI_SHARE_RESOURCE_FLAGS
//!  \param [out] pHandle     The shared resource handle
//!
//!
//!  \return This API can return any of the error codes enumerated in #NvAPI_Status. 
//!                 If there are return error codes with specific meaning for this API, they are listed below.
//!                 (None)
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D11_BeginShareResource(ID3D11Resource *pResource,
                                               UINT32          flags,
                                               HANDLE         *pHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D11_EndShareResource
//
//!   DESCRIPTION:  This API restores the original resource.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in] pResource    The resource that was shared using NvAPI_D3D11_BeginShareResource
//!
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status. 
//!                 If there are return error codes with specific meaning for this API, they are listed below.
//!                 (None)
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D11_EndShareResource(ID3D11Resource *pResource);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D11_SetDepthBoundsTest
//
//!   DESCRIPTION: This function enables/disables the depth bounds test
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]        pDev         The device to set depth bounds test
//! \param [in]        bEnable      Enable(non-zero)/disable(zero) the depth bounds test
//! \param [in]        fMinDepth    The minimum depth for depth bounds test
//! \param [in]        fMaxDepth    The maximum depth for depth bounds test
//!                                 The valid values for fMinDepth and fMaxDepth
//!                                 are such that 0 <= fMinDepth <= fMaxDepth <= 1
//!
//! \return  ::NVAPI_OK if the depth bounds test was correcly enabled or disabled
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D11_SetDepthBoundsTest(ID3D11Device *pDev,
                                               NvU32 bEnable,
                                               float fMinDepth,
                                               float fMaxDepth);






#endif //defined(__cplusplus) && defined(__d3d11_h__)



//-----------------------------------------------------------------------------
// Private Direct3D11 APIs
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetShaderPipeCount
//
//!  This function retrieves the number of Shader Pipes on the GPU.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \retval NVAPI_INVALID_ARGUMENT              pCount is NULL.
//! \retval NVAPI_OK                           *pCount is set.
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetShaderPipeCount(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pCount);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetShaderSubPipeCount
//
//!   DESCRIPTION: This function retrieves the number of Shader SubPipes on the GPU
//!                On newer architectures, this corresponds to the number of SM units
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 171.08
//!
//! RETURN STATUS: NVAPI_INVALID_ARGUMENT: pCount is NULL
//!                NVAPI_OK: *pCount is set
//!                NVAPI_NVIDIA_DEVICE_NOT_FOUND: no NVIDIA GPU driving a display was found
//!                NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE: hPhysicalGpu was not a physical GPU handle
//!
//! \ingroup   gpu  
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetShaderSubPipeCount(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pCount);




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetPartitionCount
//
//!  This function retrieves the number of frame buffer partitions on the GPU.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version:  95.50
//!
//! \retval NVAPI_INVALID_ARGUMENT              pCount is NULL.
//! \retval NVAPI_OK                           *pCount is set.
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPartitionCount(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pCount);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetMemPartitionMask
//
//!   DESCRIPTION: This function retrieves a 32-bit mask showing which memory partitions are enabled.
//!                NvAPI_GPU_GetPartitionCount() returns the count of enabled partitions.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version:  177.61
//! 
//!  \retval  NVAPI_INVALID_ARGUMENT              pMask is NULL
//!  \retval  NVAPI_OK                           *pMask is set
//!  \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//!  \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//!
//!  \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetMemPartitionMask(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pMask);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetTPCMask
//
//!   DESCRIPTION: This function retrieves a 32-bit mask showing which TPCs 
//!                (Texture Processor Cluster) are enabled.  
//!                Returns 0 on architectures that don't have TPCs.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version:  177.61
//! 
//!  \retval  NVAPI_INVALID_ARGUMENT              pMask is NULL
//!  \retval  NVAPI_OK                           *pMask is set
//!  \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//!  \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//!  \retval  NVAPI_NOT_SUPPORTED                 API call is not supported on current architecture
//!
//!  \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetTPCMask(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pMask);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetSMMask
//
//!   DESCRIPTION: This function retrieves a 32-bit mask showing which SMs 
//!                (Streaming Multiprocessors) are enabled on the TPC identified by tpcNdx. \n
//!                tpcNdx values start at 0 and correspond to the position of bits
//!                returned by NvAPI_GPU_GetTPCMask().  [mask bit = 2^tpcNdx]
//!                Returns 0 on architectures that don't have SMs.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version:  177.61
//!  
//!  \retval   NVAPI_INVALID_ARGUMENT              pMask is NULL, or tpcId does not match a TPC
//!  \retval   NVAPI_OK                           *pMask is set
//!  \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//!  \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE: hPhysicalGpu was not a physical GPU handle
//!  \retval  NVAPI_NOT_SUPPORTED                 API call is not supported on current architecture
//!
//!  \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetSMMask(NvPhysicalGpuHandle hPhysicalGpu,NvU32 tpcId,NvU32 *pMask);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetTotalTPCCount
//
//!   DESCRIPTION: This function retrieves the total number of enabled TPCs (Texture Processor Clusters)
//!                Returns 0 on architectures that don't have TPCs.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version:  177.61
//!  
//! \retval  NVAPI_INVALID_ARGUMENT              pCount is NULL
//! \retval  NVAPI_OK                           *pCount is set
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE: hPhysicalGpu was not a physical GPU handle
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetTotalTPCCount(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pCount);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetTotalSMCount
//
//!   DESCRIPTION: This function retrieves the total number of enabled SMs 
//!               (Streaming Multiprocessors) across all TPCs (Texture Processor Clusters). \n 
//!                Returns 0 on architectures that don't have SMs.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version:  177.61
//!   
//! \retval  NVAPI_INVALID_ARGUMENT: pCount is NULL
//! \retval  NVAPI_OK: *pCount is set
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND: no NVIDIA GPU driving a display was found
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE: hPhysicalGpu was not a physical GPU handle
//!  \retval  NVAPI_NOT_SUPPORTED                 API call is not supported on current architecture
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetTotalSMCount(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pCount);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetTotalSPCount
//
//!   DESCRIPTION: This function retrieves the total number of enabled SPs across all SMs 
//!                (Streaming Multiprocessors) on all TPCs (Texture Processor Clusters). \n
//!                Returns 0 on architectures that don't have SPs.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version:  177.61
//!   
//! \retval  NVAPI_INVALID_ARGUMENT: pCount is NULL
//! \retval  NVAPI_OK: *pCount is set
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND: no NVIDIA GPU driving a display was found
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE: hPhysicalGpu was not a physical GPU handle
//!  \retval  NVAPI_NOT_SUPPORTED                 API call is not supported on current architecture
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetTotalSPCount(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pCount);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetGpuCoreCount
//
//!   DESCRIPTION: Retrieves the total number of cores defined for a GPU.
//!                Returns 0 on architectures that don't define GPU cores.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \retval ::NVAPI_INVALID_ARGUMENT              pCount is NULL
//! \retval ::NVAPI_OK                            *pCount is set
//! \retval ::NVAPI_NVIDIA_DEVICE_NOT_FOUND       no NVIDIA GPU driving a display was found
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//! \retval ::NVAPI_NOT_SUPPORTED                 API call is not supported on current architecture
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetGpuCoreCount(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pCount);







///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetAllOutputs
//
//!  This function returns set of all GPU-output identifiers as a bitmask.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 87.00
//!
//! \retval   NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pOutputsMask is NULL.
//! \retval   NVAPI_OK                           *pOutputsMask contains a set of GPU-output identifiers.
//! \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetAllOutputs(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pOutputsMask);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetConnectedOutputs
//
//! This function is the same as NvAPI_GPU_GetAllOutputs() but returns only the set of GPU output 
//! identifiers that are connected to display devices.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 82.61
//!
//! \retval   NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pOutputsMask is NULL.
//! \retval   NVAPI_OK                           *pOutputsMask contains a set of GPU-output identifiers.
//! \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetConnectedOutputs(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pOutputsMask);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetConnectedSLIOutputs
//
//!   DESCRIPTION: This function is the same as NvAPI_GPU_GetConnectedOutputs() but returns only the set of GPU-output 
//!                identifiers that can be selected in an SLI configuration. 
//!                 NOTE: This function matches NvAPI_GPU_GetConnectedOutputs()
//!                 - On systems which are not SLI capable.
//!                 - If the queried GPU is not part of a valid SLI group.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 171.14
//!
//! \retval   NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pOutputsMask is NULL
//! \retval   NVAPI_OK                           *pOutputsMask contains a set of GPU-output identifiers
//! \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE: hPhysicalGpu was not a physical GPU handle
//! 
//! \ingroup gpu  
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetConnectedSLIOutputs(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pOutputsMask);




//! \ingroup gpu
typedef enum
{
    NV_MONITOR_CONN_TYPE_UNINITIALIZED = 0,
    NV_MONITOR_CONN_TYPE_VGA,
    NV_MONITOR_CONN_TYPE_COMPONENT,
    NV_MONITOR_CONN_TYPE_SVIDEO,
    NV_MONITOR_CONN_TYPE_HDMI,
    NV_MONITOR_CONN_TYPE_DVI,
    NV_MONITOR_CONN_TYPE_LVDS,
    NV_MONITOR_CONN_TYPE_DP,
    NV_MONITOR_CONN_TYPE_COMPOSITE,
    NV_MONITOR_CONN_TYPE_UNKNOWN =  -1
} NV_MONITOR_CONN_TYPE;


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetConnectedOutputsWithLidState
//
//!  This function is similar to NvAPI_GPU_GetConnectedOutputs(), and returns the connected display identifiers that are connected 
//!  as an output mask but unlike NvAPI_GPU_GetConnectedOutputs() this API "always" reflects the Lid State in the output mask.
//!  Thus if you expect the LID close state to be available in the connection mask use this API.
//!  - If LID is closed then this API will remove the LID panel from the connected display identifiers. 
//!  - If LID is open then this API will reflect the LID panel in the connected display identifiers. 
//!
//! \note This API should be used on notebook systems and on systems where the LID state is required in the connection 
//!       output mask. On desktop systems the returned identifiers will match NvAPI_GPU_GetConnectedOutputs().
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.20
//!
//! \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pOutputsMask is NULL
//! \retval  NVAPI_OK                           *pOutputsMask contains a set of GPU-output identifiers
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetConnectedOutputsWithLidState(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pOutputsMask);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetConnectedSLIOutputsWithLidState
//
//!   DESCRIPTION: This function is the same as NvAPI_GPU_GetConnectedOutputsWithLidState() but returns only the set
//!                of GPU-output identifiers that can be selected in an SLI configuration. With SLI disabled,
//!                this function matches NvAPI_GPU_GetConnectedOutputsWithLidState().
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 171.14
//!
//! \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pOutputsMask is NULL
//! \retval  NVAPI_OK                           *pOutputsMask contains a set of GPU-output identifiers
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetConnectedSLIOutputsWithLidState(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pOutputsMask);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetSystemType
//
//! \fn NvAPI_GPU_GetSystemType(NvPhysicalGpuHandle hPhysicalGpu, NV_SYSTEM_TYPE *pSystemType)
//!  This function identifies whether the GPU is a notebook GPU or a desktop GPU.
//!       
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.20
//!         
//! \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pOutputsMask is NULL
//! \retval  NVAPI_OK                           *pSystemType contains the GPU system type
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE: hPhysicalGpu was not a physical GPU handle
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup gpu
//! Used in NvAPI_GPU_GetSystemType()
typedef enum
{
    NV_SYSTEM_TYPE_UNKNOWN = 0,
    NV_SYSTEM_TYPE_LAPTOP  = 1,
    NV_SYSTEM_TYPE_DESKTOP = 2,

} NV_SYSTEM_TYPE;



//! \ingroup gpu
NVAPI_INTERFACE NvAPI_GPU_GetSystemType(NvPhysicalGpuHandle hPhysicalGpu, NV_SYSTEM_TYPE *pSystemType);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetActiveOutputs
//
//!  This function is the same as NvAPI_GPU_GetAllOutputs but returns only the set of GPU output 
//!  identifiers that are actively driving display devices.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 87.10
//!
//! \retval    NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pOutputsMask is NULL.
//! \retval    NVAPI_OK                           *pOutputsMask contains a set of GPU-output identifiers.
//! \retval    NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval    NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetActiveOutputs(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pOutputsMask);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetEDID
//
//! \fn NvAPI_GPU_GetEDID(NvPhysicalGpuHandle hPhysicalGpu, NvU32 displayOutputId, NV_EDID *pEDID)
//!  This function returns the EDID data for the specified GPU handle and connection bit mask.
//!  displayOutputId should have exactly 1 bit set to indicate a single display. See \ref handles.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 88.50
//!
//! \retval    NVAPI_INVALID_ARGUMENT              pEDID is NULL; displayOutputId has 0 or > 1 bits set
//! \retval    NVAPI_OK                           *pEDID contains valid data.
//! \retval    NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval    NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \retval    NVAPI_DATA_NOT_FOUND                The requested display does not contain an EDID.
//
///////////////////////////////////////////////////////////////////////////////


//! \ingroup gpu
//! @{

#define NV_EDID_V1_DATA_SIZE   256

#define NV_EDID_DATA_SIZE      NV_EDID_V1_DATA_SIZE

typedef struct
{
    NvU32   version;        //structure version
    NvU8    EDID_Data[NV_EDID_DATA_SIZE];
} NV_EDID_V1;

//! Used in NvAPI_GPU_GetEDID()
typedef struct
{
    NvU32   version;        //!< Structure version
    NvU8    EDID_Data[NV_EDID_DATA_SIZE];
    NvU32   sizeofEDID;
} NV_EDID_V2;

//! Used in NvAPI_GPU_GetEDID()
typedef struct
{
    NvU32   version;        //!< Structure version
    NvU8    EDID_Data[NV_EDID_DATA_SIZE];
    NvU32   sizeofEDID;
    NvU32   edidId;     //!< ID which always returned in a monotonically increasing counter.
                       //!< Across a split-EDID read we need to verify that all calls returned the same edidId.
                       //!< This counter is incremented if we get the updated EDID. 
    NvU32   offset;    //!< Which 256-byte page of the EDID we want to read. Start at 0.
                       //!< If the read succeeds with edidSize > NV_EDID_DATA_SIZE,
                       //!< call back again with offset+256 until we have read the entire buffer
} NV_EDID_V3;



typedef NV_EDID_V3    NV_EDID;

#define NV_EDID_VER1    MAKE_NVAPI_VERSION(NV_EDID_V1,1)
#define NV_EDID_VER2    MAKE_NVAPI_VERSION(NV_EDID_V2,2)
#define NV_EDID_VER3    MAKE_NVAPI_VERSION(NV_EDID_V3,3)
#define NV_EDID_VER   NV_EDID_VER3

//! @}



//! \ingroup gpu
NVAPI_INTERFACE NvAPI_GPU_GetEDID(NvPhysicalGpuHandle hPhysicalGpu, NvU32 displayOutputId, NV_EDID *pEDID);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_SetEDID
//
//!  Thus function sets the EDID data for the specified GPU handle and connection bit mask.
//!  displayOutputId should have exactly 1 bit set to indicate a single display. See \ref handles.
//!  \note The EDID will be cached across the boot session and will be enumerated to the OS in this call.
//!        To remove the EDID set sizeofEDID to zero.
//!        OS and NVAPI connection status APIs will reflect the newly set or removed EDID dynamically.
//!
//!                This feature will NOT be supported on the following boards:
//!                - GeForce
//!                - Quadro VX 
//!                - Tesla  
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 100.40
//!
//! \retval  NVAPI_INVALID_ARGUMENT              pEDID is NULL; displayOutputId has 0 or > 1 bits set
//! \retval  NVAPI_OK                           *pEDID data was applied to the requested displayOutputId.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE: hPhysicalGpu was not a physical GPU handle.
//! \retval  NVAPI_NOT_SUPPORTED                 For the above mentioned GPUs
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetEDID(NvPhysicalGpuHandle hPhysicalGpu, NvU32 displayOutputId, NV_EDID *pEDID);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetOutputType
//
//! \fn NvAPI_GPU_GetOutputType(NvPhysicalGpuHandle hPhysicalGpu, NvU32 outputId, NV_GPU_OUTPUT_TYPE *pOutputType)
//!  This function returns the output type for a specific physical GPU handle and outputId (exactly 1 bit set - see \ref handles).
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \Version Earliest supported ForceWare version: 82.61
//!
//! \retval     NVAPI_INVALID_ARGUMENT              hPhysicalGpu, outputId, or pOutputsMask is NULL; or outputId has > 1 bit set
//! \retval     NVAPI_OK                           *pOutputType contains a NvGpuOutputType value
//! \retval     NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//! \retval     NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup gpu
//! used in NvAPI_GPU_GetOutputType()
typedef enum _NV_GPU_OUTPUT_TYPE
{
    NVAPI_GPU_OUTPUT_UNKNOWN  = 0,
    NVAPI_GPU_OUTPUT_CRT      = 1,     //!<  CRT display device
    NVAPI_GPU_OUTPUT_DFP      = 2,     //!<  Digital Flat Panel display device
    NVAPI_GPU_OUTPUT_TV       = 3,     //!<  TV display device
} NV_GPU_OUTPUT_TYPE;




//! \ingroup gpu
NVAPI_INTERFACE NvAPI_GPU_GetOutputType(NvPhysicalGpuHandle hPhysicalGpu, NvU32 outputId, NV_GPU_OUTPUT_TYPE *pOutputType);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetDeviceDisplayMode
//
//! \fn NvAPI_GPU_GetDeviceDisplayMode(NvPhysicalGpuHandle hPhysicalGpu, NvU32 displayId, NV_GPU_DISPLAY_MODE *pDeviceDisplayMode)
//!   DESCRIPTION: For the specified physical GPU handle and single active displayId (exactly 1 bit set), this API
//!                returns the device display mode (see NV_GPU_DISPLAY_MODE) according to hardware (including raster extension). This
//!                includes the backend timing info.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 177.05
//!
//!  \retval   NVAPI_INVALID_ARGUMENT              hPhysicalGpu, displayId or pOutputsMask is NULL; displayId has > 1 bit set;
//!                                                displayId is not an active display.
//!  \retval   NVAPI_OK                           *pDeviceDisplayMode contains the returned display mode information.
//!  \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//!  \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup gpu
//! Used in NvAPI_GPU_GetDeviceDisplayMode().
typedef struct
{
    NvU32 version;          //!< Structure version
    NvU32 activeWidth;      //!< Number of active horizontal pixels
    NvU32 activeHeight;     //!< Number of active vertical pixels
    NvU32 totalWidth;       //!< Total size of raster width (including blanking)
    NvU32 totalHeight;      //!< Total size of raster height (including blanking)
    NvU32 depth;            //!< Color depth
    NvU32 frequency;        //!< Calculated refresh rate based upon current raster and pixel clock
} NV_GPU_DISPLAY_MODE;

//! \ingroup gpu
#define NV_GPU_DISPLAY_MODE_VER  MAKE_NVAPI_VERSION(NV_GPU_DISPLAY_MODE,1)


//!  \ingroup  gpu
NVAPI_INTERFACE NvAPI_GPU_GetDeviceDisplayMode(NvPhysicalGpuHandle hPhysicalGpu, NvU32 displayId, NV_GPU_DISPLAY_MODE *pDeviceDisplayMode);




//DISPLAYPORT is all private for now. Do not change category until that info is public.
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetFlatPanelInfo
//
//! \fn NvAPI_GPU_GetFlatPanelInfo(NvPhysicalGpuHandle hPhysicalGpu, NvU32 outputId, NV_GPU_FLAT_PANEL_INFO *pFlatPanelInfo)
//!  Given a physical GPU handle and a single display outputId of the flat panel (see \ref handles), this API 
//!  returns the flat panel attributes.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.70
//!
//! \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu, outputId, or pFlatPanelInfo is NULL; or outputId has > 1 bit set.
//! \retval  NVAPI_OK                           *pFlatPanelInfo contains the returned flat panel information.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \retval  NVAPI_EXPECTED_DIGITAL_FLAT_PANEL   outputId is not associated with digital flat panel.
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup gpu
//! Used in NV_GPU_FLAT_PANEL_INFO
typedef enum _NV_GPU_FLATPANEL_SIGNAL_TYPE
{
  NV_GPU_FLATPANEL_SIGNAL_TYPE_TMDS         = 0,
  NV_GPU_FLATPANEL_SIGNAL_TYPE_LVDS         = 1,
  NV_GPU_FLATPANEL_SIGNAL_TYPE_SDI          = 2,
  NV_GPU_FLATPANEL_SIGNAL_TYPE_DISPLAYPORT  = 3,
    
} NV_GPU_FLATPANEL_SIGNAL_TYPE;


//! \ingroup gpu
//! Used in NV_GPU_FLAT_PANEL_INFO
typedef enum _NV_GPU_FLATPANEL_SIGNAL_LINK
{
  NV_GPU_FLATPANEL_SIGNAL_SINGLE_LINK       = 1,
  NV_GPU_FLATPANEL_SIGNAL_DUAL_LINK         = 2,
    
} NV_GPU_FLATPANEL_SIGNAL_LINK;


//! \ingroup gpu
//! Used in NV_GPU_FLAT_PANEL_INFO
typedef enum _NV_GPU_FLATPANEL_SIGNAL_DISPLAYPORT_LANES
{
  NV_GPU_FLATPANEL_SIGNAL_DISPLAYPORT_NONE              = 0,
  NV_GPU_FLATPANEL_SIGNAL_DISPLAYPORT_SINGLE_LANE       = 1,
  NV_GPU_FLATPANEL_SIGNAL_DISPLAYPORT_DUAL_LANE         = 2,
  NV_GPU_FLATPANEL_SIGNAL_DISPLAYPORT_QUAD_LANE         = 3,
    
} NV_GPU_FLATPANEL_SIGNAL_DISPLAYPORT_LANES;


//! \ingroup gpu
//! Used in NV_GPU_FLAT_PANEL_INFO
typedef enum _NV_GPU_FLATPANEL_SIGNAL_COLOR_FLAGS
{
  NV_GPU_FLATPANEL_SIGNAL_COLOR_LIMITED_RANGE           = 0x00000001,   //!< Flatpanel supports limited color range.
  NV_GPU_FLATPANEL_SIGNAL_COLOR_AUTO_CONFIGURE          = 0x00000002,   //!< Flatpanel supports auto-configuring the color range.
  NV_GPU_FLATPANEL_SIGNAL_COLOR_FORMAT_YCBCR422_CAPABLE = 0x00000004,   //!< Flatpanel is YCBCR422 color format capable.
  NV_GPU_FLATPANEL_SIGNAL_COLOR_FORMAT_YCBCR444_CAPABLE = 0x00000008,   //!< Flatpanel is YCBCR444 color format capable.
   
} NV_GPU_FLATPANEL_SIGNAL_COLOR_FLAGS;


//! \ingroup gpu
//! Used in NvAPI_GPU_GetFlatPanelInfo()
typedef struct
{
    NvU32                                       version;                    //!< Structure version
    NV_GPU_FLATPANEL_SIGNAL_TYPE                signalType;                 //!< Flat panel signal type
    NV_GPU_FLATPANEL_SIGNAL_LINK                linkType;                   //!< Link type
    NV_GPU_FLATPANEL_SIGNAL_DISPLAYPORT_LANES   displayPortLanes;           //!< 1, 2 or 4 DisplayPort lanesconnected panel. 
    NvU32                                       colorFlags;                 //!< One or more bits from NV_GPU_FLATPANEL_SIGNAL_COLOR_FLAGS
    NvU32                                       hdmiCapable:1;              //!< HMDI status
    NvU32                                       scalerDisabled:1;           //!< Indicates if GPU scaling is disabled (possible with SLI active on certain GPUs)

    NvU32                                       refreshRateLocked:1;        //!< Flat panel supports 60 Hz only
}
NV_GPU_FLAT_PANEL_INFO;


//! \ingroup gpu
#define NV_GPU_FLAT_PANEL_INFO_VER  MAKE_NVAPI_VERSION(NV_GPU_FLAT_PANEL_INFO,1)


//! \ingroup gpu  
NVAPI_INTERFACE NvAPI_GPU_GetFlatPanelInfo(NvPhysicalGpuHandle hPhysicalGpu, NvU32 outputId, NV_GPU_FLAT_PANEL_INFO *pFlatPanelInfo);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_ValidateOutputCombination
//
//!  This function determines if a set of GPU outputs can be active 
//!  simultaneously.  While a GPU may have <n> outputs, typically they cannot 
//!  all be active at the same time due to internal resource sharing.
//!
//!  Given a physical GPU handle and a mask of candidate outputs, this call
//!  will return NVAPI_OK if all of the specified outputs can be driven
//!  simultaneously.  It will return NVAPI_INVALID_COMBINATION if they cannot.
//!                
//!  Use NvAPI_GPU_GetAllOutputs() to determine which outputs are candidates.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 87.10
//!
//! \retval  NVAPI_OK                            Combination of outputs in outputsMask are valid (can be active simultaneously).
//! \retval  NVAPI_INVALID_COMBINATION           Combination of outputs in outputsMask are NOT valid.
//! \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu or outputsMask does not have at least 2 bits set.
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_ValidateOutputCombination(NvPhysicalGpuHandle hPhysicalGpu, NvU32 outputsMask);




//! \ingroup gpu
//! Used in NV_GPU_CONNECTOR_DATA
typedef enum _NV_GPU_CONNECTOR_TYPE
{
    NVAPI_GPU_CONNECTOR_VGA_15_PIN                      = 0x00000000,
    NVAPI_GPU_CONNECTOR_TV_COMPOSITE                    = 0x00000010,
    NVAPI_GPU_CONNECTOR_TV_SVIDEO                       = 0x00000011,
    NVAPI_GPU_CONNECTOR_TV_HDTV_COMPONENT               = 0x00000013,
    NVAPI_GPU_CONNECTOR_TV_SCART                        = 0x00000014,
    NVAPI_GPU_CONNECTOR_TV_COMPOSITE_SCART_ON_EIAJ4120  = 0x00000016,
    NVAPI_GPU_CONNECTOR_TV_HDTV_EIAJ4120                = 0x00000017,
    NVAPI_GPU_CONNECTOR_PC_POD_HDTV_YPRPB               = 0x00000018,
    NVAPI_GPU_CONNECTOR_PC_POD_SVIDEO                   = 0x00000019,
    NVAPI_GPU_CONNECTOR_PC_POD_COMPOSITE                = 0x0000001A,
    NVAPI_GPU_CONNECTOR_DVI_I_TV_SVIDEO                 = 0x00000020,
    NVAPI_GPU_CONNECTOR_DVI_I_TV_COMPOSITE              = 0x00000021,
    NVAPI_GPU_CONNECTOR_DVI_I                           = 0x00000030,
    NVAPI_GPU_CONNECTOR_DVI_D                           = 0x00000031,
    NVAPI_GPU_CONNECTOR_ADC                             = 0x00000032,
    NVAPI_GPU_CONNECTOR_LFH_DVI_I_1                     = 0x00000038,
    NVAPI_GPU_CONNECTOR_LFH_DVI_I_2                     = 0x00000039,
    NVAPI_GPU_CONNECTOR_SPWG                            = 0x00000040,
    NVAPI_GPU_CONNECTOR_OEM                             = 0x00000041,
    NVAPI_GPU_CONNECTOR_DISPLAYPORT_EXTERNAL            = 0x00000046,
    NVAPI_GPU_CONNECTOR_DISPLAYPORT_INTERNAL            = 0x00000047,
    NVAPI_GPU_CONNECTOR_DISPLAYPORT_MINI_EXT            = 0x00000048,
    NVAPI_GPU_CONNECTOR_HDMI_A                          = 0x00000061,
    NVAPI_GPU_CONNECTOR_HDMI_C_MINI                     = 0x00000063,
    NVAPI_GPU_CONNECTOR_LFH_DISPLAYPORT_1               = 0x00000064,
    NVAPI_GPU_CONNECTOR_LFH_DISPLAYPORT_2               = 0x00000065,    
    NVAPI_GPU_CONNECTOR_UNKNOWN                         = 0xFFFFFFFF,
} NV_GPU_CONNECTOR_TYPE;


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetConnectorInfo
//
//! \fn NvAPI_GPU_GetConnectorInfo(NvPhysicalGpuHandle hPhysicalGpu, NvU32 outputId, NV_GPU_CONNECTOR_INFO *pConnectorInfo)
//!   Given a physical GPU handle and a single outputId (exactly 1 bit set - see \ref handles),
//!   this API fills the NV_GPU_CONNECTOR_INFO with connector specific data. 
//!   \note If outputId is connected or active then the current attached connector information is returned.
//!         If there is no connector attached for the outputId then all possible connections on the board are returned.
//!         Some TV outputs may have multiple connectors attached or could have an ambiguous connector layout on the board.
//!         In that case the connector[] array will list all connectors without indicating 
//!         which one is 'active'. To get the active TV connector use NvAPI_GetTVOutputInfo.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 96.10
//!
//! \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu, outputId or pOutputsMask is NULL; or outputId has > 1 bit set
//! \retval  NVAPI_OK                           *pConnectorInfo contains valid NV_GPU_CONNECTOR_INFO data
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//! \retval  NVAPI_INCOMPATIBLE_STRUCT_VERSION   NV_GPU_CONNECTOR_INFO version not compatible with driver
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////





//! \ingroup gpu
//! Used in NV_GPU_CONNECTOR_INFO
typedef enum _NV_GPU_CONNECTOR_PLATFORM
{
    NVAPI_GPU_CONNECTOR_PLATFORM_DEFAULT_ADD_IN_CARD   = 0x00000000,
    NVAPI_GPU_CONNECTOR_PLATFORM_TWO_PLATE_ADD_IN_CARD = 0x00000001,
    NVAPI_GPU_CONNECTOR_PLATFORM_MOBILE_ADD_IN_CARD    = 0x00000008,
    NVAPI_GPU_CONNECTOR_PLATFORM_MOBILE_BACK           = 0x00000010,
    NVAPI_GPU_CONNECTOR_PLATFORM_MOBILE_BACK_LEFT      = 0x00000011,
    NVAPI_GPU_CONNECTOR_PLATFORM_MOBILE_BACK_DOCK      = 0x00000018,
    NVAPI_GPU_CONNECTOR_PLATFORM_MAINBOARD_DEFAULT     = 0x00000020,
    NVAPI_GPU_CONNECTOR_PLATFORM_UNKNOWN               = 0xFFFFFFFF,
} NV_GPU_CONNECTOR_PLATFORM;

//! \ingroup gpu
//! Used in NV_GPU_CONNECTOR_INFO
typedef struct
{
    NV_GPU_CONNECTOR_TYPE   type;           //!< Connector type
    NvU32                   locationIndex;  //!< Connector location
} NV_GPU_CONNECTOR_DATA;

//! \ingroup gpu
#define NV_API_MAX_CONNECTOR_PER_OUTPUT     4

//! \ingroup gpu
//! Used in NvAPI_GPU_GetConnectorInfo()
typedef struct
{
    NvU32                       version;            //!<  Structure version
    NV_GPU_CONNECTOR_PLATFORM   connectorPlatform;  //!<  Connector platform
    NvU32                       connectorCount;     //!<  Number of valid entries in connector[]
    NV_GPU_CONNECTOR_DATA       connector[NV_API_MAX_CONNECTOR_PER_OUTPUT];
} NV_GPU_CONNECTOR_INFO;


//! \ingroup gpu
#define NV_GPU_CONNECTOR_INFO_VER  MAKE_NVAPI_VERSION(NV_GPU_CONNECTOR_INFO,1)


//! \ingroup gpu
NVAPI_INTERFACE NvAPI_GPU_GetConnectorInfo(NvPhysicalGpuHandle hPhysicalGpu, NvU32 outputId, NV_GPU_CONNECTOR_INFO *pConnectorInfo);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetFullName
//
//!  This function retrieves the full GPU name as an ASCII string - for example, "Quadro FX 1400".
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \return  NVAPI_ERROR or NVAPI_OK
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetFullName(NvPhysicalGpuHandle hPhysicalGpu, NvAPI_ShortString szName);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetPCIIdentifiers
//
//!  This function returns the PCI identifiers associated with this GPU.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \param   DeviceId      The internal PCI device identifier for the GPU.
//! \param   SubSystemId   The internal PCI subsystem identifier for the GPU.
//! \param   RevisionId    The internal PCI device-specific revision identifier for the GPU.
//! \param   ExtDeviceId   The external PCI device identifier for the GPU.
//!
//! \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu or an argument is NULL
//! \retval  NVAPI_OK                            Arguments are populated with PCI identifiers
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPCIIdentifiers(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pDeviceId,NvU32 *pSubSystemId,NvU32 *pRevisionId,NvU32 *pExtDeviceId);
    


//! \ingroup gpu
//! Used in NvAPI_GPU_GetGPUType().    
typedef enum _NV_GPU_TYPE
{
    NV_SYSTEM_TYPE_GPU_UNKNOWN     = 0, 
    NV_SYSTEM_TYPE_IGPU            = 1, //!< Integrated GPU
    NV_SYSTEM_TYPE_DGPU            = 2, //!< Discrete GPU
} NV_GPU_TYPE; 

/////////////////////////////////////////////////////////////////////////////// 
// 
// FUNCTION NAME: NvAPI_GPU_GetGPUType 
// 
//!  DESCRIPTION: This function returns the GPU type (integrated or discrete).
//!               See ::NV_GPU_TYPE. 
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 174.32
//!
//! \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu 
//! \retval  NVAPI_OK                           *pGpuType contains the GPU type 
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found 
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE: hPhysicalGpu was not a physical GPU handle 
//!
//!  \ingroup gpu 
///////////////////////////////////////////////////////////////////////////////     
NVAPI_INTERFACE NvAPI_GPU_GetGPUType(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_TYPE *pGpuType);




//! \ingroup gpu
//! Used in NvAPI_GPU_GetBusType()
typedef enum _NV_GPU_BUS_TYPE
{
    NVAPI_GPU_BUS_TYPE_UNDEFINED    = 0,
    NVAPI_GPU_BUS_TYPE_PCI          = 1,
    NVAPI_GPU_BUS_TYPE_AGP          = 2,
    NVAPI_GPU_BUS_TYPE_PCI_EXPRESS  = 3,
    NVAPI_GPU_BUS_TYPE_FPCI         = 4,
} NV_GPU_BUS_TYPE;
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetBusType
//
//!  This function returns the type of bus associated with this GPU.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \retval NVAPI_INVALID_ARGUMENT             hPhysicalGpu or pBusType is NULL.
//! \retval NVAPI_OK                          *pBusType contains bus identifier.
//! \retval NVAPI_NVIDIA_DEVICE_NOT_FOUND      No NVIDIA GPU driving a display was found.
//! \retval NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetBusType(NvPhysicalGpuHandle hPhysicalGpu,NV_GPU_BUS_TYPE *pBusType);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetBusId
//
//!   DESCRIPTION: Returns the ID of the bus associated with this GPU.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 167.00
//!
//!  \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pBusId is NULL.
//!  \retval  NVAPI_OK                           *pBusId contains the bus ID.
//!  \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//!  \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//!
//!  \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetBusId(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pBusId);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetBusSlotId
//
//!   DESCRIPTION: Returns the ID of the bus slot associated with this GPU.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 167.00
//!
//!  \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pBusSlotId is NULL.
//!  \retval  NVAPI_OK                           *pBusSlotId contains the bus slot ID.
//!  \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//!  \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//!
//!  \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetBusSlotId(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pBusSlotId);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetIRQ
//
//!  This function returns the interrupt number associated with this GPU.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \retval  NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pIRQ is NULL.
//! \retval  NVAPI_OK                           *pIRQ contains interrupt number.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetIRQ(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pIRQ);
    
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetVbiosRevision
//
//!  This function returns the revision of the video BIOS associated with this GPU.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \retval    NVAPI_INVALID_ARGUMENT               hPhysicalGpu or pBiosRevision is NULL.
//! \retval    NVAPI_OK                            *pBiosRevision contains revision number.
//! \retval    NVAPI_NVIDIA_DEVICE_NOT_FOUND        No NVIDIA GPU driving a display was found.
//! \retval    NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE   hPhysicalGpu was not a physical GPU handle.
//! \ingroup   gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetVbiosRevision(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pBiosRevision);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetVbiosOEMRevision
//
//!  This function returns the OEM revision of the video BIOS associated with this GPU.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \retval    NVAPI_INVALID_ARGUMENT              hPhysicalGpu or pBiosRevision is NULL
//! \retval    NVAPI_OK                           *pBiosRevision contains revision number
//! \retval    NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//! \retval    NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//! \ingroup   gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetVbiosOEMRevision(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pBiosRevision);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetVbiosVersionString
//
//!  This function returns the full video BIOS version string in the form of xx.xx.xx.xx.yy where
//!  - xx numbers come from NvAPI_GPU_GetVbiosRevision() and 
//!  - yy comes from NvAPI_GPU_GetVbiosOEMRevision().
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \retval   NVAPI_INVALID_ARGUMENT              hPhysicalGpu is NULL.
//! \retval   NVAPI_OK                            szBiosRevision contains version string.
//! \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetVbiosVersionString(NvPhysicalGpuHandle hPhysicalGpu,NvAPI_ShortString szBiosRevision);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetAGPAperture
//
//!  This function returns the AGP aperture in megabytes.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \retval   NVAPI_INVALID_ARGUMENT              pSize is NULL.
//! \retval   NVAPI_OK                            Call successful.
//! \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetAGPAperture(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pSize);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetCurrentAGPRate
//
//!  This function returns the current AGP Rate (0 = AGP not present, 1 = 1x, 2 = 2x, etc.).
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \retval   NVAPI_INVALID_ARGUMENT              pRate is NULL.
//! \retval   NVAPI_OK                            Call successful.
//! \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetCurrentAGPRate(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pRate);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetCurrentPCIEDownstreamWidth
//
//!  This function returns the number of PCIE lanes being used for the PCIE interface 
//!  downstream from the GPU.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \retval  NVAPI_INVALID_ARGUMENT              pWidth is NULL.
//! \retval  NVAPI_OK                            Call successful.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetCurrentPCIEDownstreamWidth(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pWidth);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetPhysicalFrameBufferSize
//
//!   This function returns the physical size of framebuffer in KB.  This does NOT include any
//!   system RAM that may be dedicated for use by the GPU.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \retval  NVAPI_INVALID_ARGUMENT              pSize is NULL
//! \retval  NVAPI_OK                            Call successful
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPhysicalFrameBufferSize(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pSize);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetVirtualFrameBufferSize
//
//!  This function returns the virtual size of framebuffer in KB.  This includes the physical RAM plus any
//!  system RAM that has been dedicated for use by the GPU.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 92.10
//!
//! \retval  NVAPI_INVALID_ARGUMENT              pSize is NULL.
//! \retval  NVAPI_OK                            Call successful.
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//! \retval  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetVirtualFrameBufferSize(NvPhysicalGpuHandle hPhysicalGpu,NvU32 *pSize);


 
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetQuadroStatus
//
//!  This function retrieves the Quadro status for the GPU (1 if Quadro, 0 if GeForce)
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 82.80
//!
//! \return  NVAPI_ERROR or NVAPI_OK
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetQuadroStatus(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pStatus); 




//! \ingroup gpu
typedef struct _NV_BOARD_INFO
{
    NvU32 version;                   //!< structure version
    NvU8 BoardNum[16];               //!< Board Serial Number

}NV_BOARD_INFO_V1;

//! \ingroup gpu
typedef NV_BOARD_INFO_V1    NV_BOARD_INFO;
//! \ingroup gpu
#define NV_BOARD_INFO_VER1  MAKE_NVAPI_VERSION(NV_BOARD_INFO_V1,1)
//! \ingroup gpu
#define NV_BOARD_INFO_VER   NV_BOARD_INFO_VER1

//  SUPPORTED OS: Windows XP and higher
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetBoardInfo
//
//!   DESCRIPTION: This API Retrieves the Board information (a unique GPU Board Serial Number) stored in the InfoROM.
//!
//! \param [in]      hPhysicalGpu       Physical GPU Handle.
//! \param [in,out]  NV_BOARD_INFO      Board Information.
//!
//! \retval ::NVAPI_OK                     completed request
//! \retval ::NVAPI_ERROR                  miscellaneous error occurred
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  handle passed is not a physical GPU handle
//! \retval ::NVAPI_API_NOT_INTIALIZED            NVAPI not initialized
//! \retval ::NVAPI_INVALID_POINTER               pBoardInfo is NULL
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION   the version of the INFO struct is not supported
//! 
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetBoardInfo(NvPhysicalGpuHandle hPhysicalGpu, NV_BOARD_INFO *pBoardInfo);






//! \ingroup gpu
//! Used in NvAPI_GPU_GetRamType()
typedef enum
{
    NV_GPU_RAM_TYPE_UNKNOWN = 0,
    NV_GPU_RAM_TYPE_SDRAM   = 1,
    NV_GPU_RAM_TYPE_DDR1    = 2,
    NV_GPU_RAM_TYPE_DDR2    = 3,
    NV_GPU_RAM_TYPE_GDDR2   = 4,
    NV_GPU_RAM_TYPE_GDDR3   = 5,
    NV_GPU_RAM_TYPE_GDDR4   = 6,
    NV_GPU_RAM_TYPE_DDR3    = 7,
    NV_GPU_RAM_TYPE_GDDR5   = 8
} NV_GPU_RAM_TYPE;

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetRamType
//
//! This function retrieves the type of VRAM associated with this GPU
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.60 
//!
//! \return NVAPI_ERROR or NVAPI_OK
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetRamType(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_RAM_TYPE *pRamType);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetFBWidthAndLocation
//
//! \fn NvAPI_GPU_GetFBWidthAndLocation(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pBusWidth, NV_GPU_FB_LOCATION *pFBLocation)
//!   DESCRIPTION: This API returns the width and location of the GPU's RAM memory bus.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.72
//!
//! \return ::NVAPI_ERROR or ::NVAPI_OK
//
///////////////////////////////////////////////////////////////////////////////


//! \ingroup gpu
//! Used in NvAPI_GPU_GetFBWidthAndLocation().
typedef enum _NV_GPU_FB_LOCATION
{
    NV_GPU_FB_RAM_LOCATION_UNKNOWN       = 0,
    NV_GPU_FB_RAM_LOCATION_GPU_DEDICATED = 1,
    NV_GPU_FB_RAM_LOCATION_SYS_SHARED    = 2,
    NV_GPU_FB_RAM_LOCATION_SYS_DEDICATED = 3,
} NV_GPU_FB_LOCATION;

//! \ingroup gpu
NVAPI_INTERFACE NvAPI_GPU_GetFBWidthAndLocation(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pBusWidth, NV_GPU_FB_LOCATION *pFBLocation);



///////////////////////////////////////////////////////////////////////////////
//
//  GPU Clock Control
//
//  These APIs allow the user to get and set individual clock domains
//  on a per-GPU basis.
//
///////////////////////////////////////////////////////////////////////////////


//! \ingroup gpuclock
//! @{
#define NVAPI_MAX_GPU_CLOCKS 32
#define NVAPI_MAX_GPU_PUBLIC_CLOCKS     32
#define NVAPI_MAX_GPU_PERF_CLOCKS       32
#define NVAPI_MAX_GPU_PERF_VOLTAGES     16
#define NVAPI_MAX_GPU_PERF_PSTATES      16
//! @}

//! \ingroup gpuclock
//!  NV_GPU_CLOCK_INFO_DOMAIN_ID is obsolete.  Use ::NV_GPU_PUBLIC_CLOCK_ID.
//!  Remove after ::NV_GPU_PUBLIC_CLOCK_ID propagates and all applications are updated.
typedef enum _NV_GPU_CLOCK_INFO_DOMAIN_ID
{
    NVAPI_GPU_CLOCK_INFO_DOMAIN_NV      = 0,
    NVAPI_GPU_CLOCK_INFO_DOMAIN_M       = 4,
    NVAPI_GPU_CLOCK_INFO_DOMAIN_HOTCLK  = 7,
    NVAPI_GPU_CLOCK_INFO_DOMAIN_UNDEFINED = NVAPI_MAX_GPU_CLOCKS,
} NV_GPU_CLOCK_INFO_DOMAIN_ID;


//! \ingroup gpuclock
//!  NV_GPU_CLOCK_INFO_DOMAIN_ID is obsolete.  Use ::NV_GPU_PUBLIC_CLOCK_ID.
//!  Remove after ::NV_GPU_PUBLIC_CLOCK_ID propagates and all applications are updated.
typedef enum _NV_GPU_PERF_CLOCK_DOMAIN_ID
{
    NVAPI_GPU_PERF_CLOCK_DOMAIN_GRAPHICS_CLK  = 0,
    NVAPI_GPU_PERF_CLOCK_DOMAIN_MEMORY_CLK    = 4,   
    NVAPI_GPU_PERF_CLOCK_DOMAIN_PROCESSOR_CLK = 7, 
} NV_GPU_PERF_CLOCK_DOMAIN_ID;


//! \ingroup gpuclock
typedef enum _NV_GPU_PUBLIC_CLOCK_ID
{
    NVAPI_GPU_PUBLIC_CLOCK_GRAPHICS  = 0,
    NVAPI_GPU_PUBLIC_CLOCK_MEMORY    = 4,
    NVAPI_GPU_PUBLIC_CLOCK_PROCESSOR = 7,
    NVAPI_GPU_PUBLIC_CLOCK_UNDEFINED = NVAPI_MAX_GPU_PUBLIC_CLOCKS,
} NV_GPU_PUBLIC_CLOCK_ID;


//! \ingroup gpuclock
typedef enum _NV_GPU_PERF_VOLTAGE_INFO_DOMAIN_ID
{
    NVAPI_GPU_PERF_VOLTAGE_INFO_DOMAIN_CORE      = 0,
    NVAPI_GPU_PERF_VOLTAGE_INFO_DOMAIN_UNDEFINED = NVAPI_MAX_GPU_PERF_VOLTAGES,
} NV_GPU_PERF_VOLTAGE_INFO_DOMAIN_ID;



//Performance table overclocking 


//! \addtogroup gpuclock 
//! @{

#define NVAPI_MAX_PERF_CLOCK_LEVELS     12
#define NVAPI_TARGET_ALL_PERF_LEVELS    0xffffffff

#define NV_PERF_CLOCK_LEVEL_STATE_DEFAULT                   0x00000000 //!< Level is in its default state
#define NV_PERF_CLOCK_LEVEL_STATE_OVERCLOCKED               0x00000001 //!< Level is overclocked
#define NV_PERF_CLOCK_LEVEL_STATE_DESKTOP                   0x00000002 //!< 2D Desktop perf level
#define NV_PERF_CLOCK_LEVEL_STATE_PERFORMANCE               0x00000004 //!< 3D applications perf level
#define NV_PERF_CLOCK_LEVEL_STATE_TEST                      0x00000008 //!< Test the new clocks for this level. Does not apply.
#define NV_PERF_CLOCK_LEVEL_STATE_TEST_SUCCESS              0x00000010 //!< Test result
      
#define NV_PERF_CLOCK_GPU_STATE_DEFAULT                     0x00000000 //!< Default state
#define NV_PERF_CLOCK_GPU_STATE_DYNAMIC_SUPPORTED           0x00000001 //!< GPU supports dynamic performance level transitions
#define NV_PERF_CLOCK_GPU_STATE_DESKTOP                     0x00000002 //!< GPU in desktop level
#define NV_PERF_CLOCK_GPU_STATE_PERFORMANCE                 0x00000004 //!< GPU in performance level
#define NV_PERF_CLOCK_GPU_STATE_ACTIVE_CLOCKING_SUPPORTED   0x00000008 //!< Active clocking supported
#define NV_PERF_CLOCK_GPU_STATE_ACTIVE_CLOCKING_ENABLE      0x00000010 //!< Enable active clocking
#define NV_PERF_CLOCK_GPU_STATE_ACTIVE_CLOCKING_DISABLE     0x00000020 //!< Disable active clocking
#define NV_PERF_CLOCK_GPU_STATE_MEMCLK_CONTROL_DISABLED     0x00000040 //!< Memory clock control disabled
#define NV_PERF_CLOCK_GPU_STATE_GFXCLK_CONTROL_DISABLED     0x00000080 //!< Core clock control disabled
#define NV_PERF_CLOCK_GPU_STATE_SET_DEFERRED                0x00000100 //!< No immediate perf transitions. Deferred until perf triggers kick in.
#define NV_PERF_CLOCK_GPU_STATE_TESTING_CLOCKS_SUPPORTED    0x00000200 //!< Testing clocks supported
//! @}


//! \ingroup  gpuclock 
//! Used in NvAPI_GPU_GetPerfClocks() and NvAPI_GPU_GetPerfClocks() 
typedef struct
{
    NvU32   version;                                //!< IN perf clock table version
    NvU32   levelCount;                             //!< number of the performance levels. count increases everytime a level is overclocked
    NvU32   gpuPerflevel;                           //!< OUT the current perf level. This is a dynamic level which can possibly change on every call
    NvU32   domainCount;                            //!< IN/OUT number of domains
    NvU32   gpuPerfFlags;                           //!< IN/OUT gpu flags - one of the flags defined in NV_PERF_CLOCK_GPU_STATE
    struct
    {
        NvU32   level;                              //!< IN/OUT performance level indicator, range 0 to levelCount - 1.
        NvU32   flags;                              //!< IN/OUT per level flags - one of more flags defined in NV_PERF_CLOCK_LEVEL_STATE 
        struct
        {
            NV_GPU_PUBLIC_CLOCK_ID      domainId;       //!< IN/OUT current domain indicator - one of the ids from NV_GPU_PUBLIC_CLOCK_ID
            NvU32                       domainFlags;    //!< reserved unused domain flags 
            NvU32                       currentFreq;    //!< IN/OUT current clock KHz
            NvU32                       defaultFreq;    //!< default clock KHz
            NvU32                       minFreq;        //!< min KHz
            NvU32                       maxFreq;        //!< max KHz
            NvU32                       bSetClock:1;    //!< IN if set during NvAPI_GPU_SetPerfClocks call, this domain currentFreq will be applied
        } domain[NVAPI_MAX_GPU_PERF_CLOCKS];
    } perfLevel[NVAPI_MAX_PERF_CLOCK_LEVELS];
    
} NV_GPU_PERF_CLOCK_TABLE;

//! \ingroup  gpuclock 
#define NV_GPU_PERF_CLOCK_TABLE_VER  MAKE_NVAPI_VERSION(NV_GPU_PERF_CLOCK_TABLE,1)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetPerfClocks
//
//!  This function retrieves the performance clock table information for one or all the supported levels.
//!                  NOTE: This call will return 0 for system memory.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 88.90 (Rel85), 92.40 (Rel90)
//!
//! \param [in]     hPhysicalGPU    GPU selection.
//! \param [in]     level           Specific level selection. Zero for all levels. Number of levels increases with overclocking of the levels.
//! \param [out]    pPerfClkTable   Table of performance levels retrieved.
//!
//! \retval   NVAPI_OK                             Completed request
//! \retval   NVAPI_ERROR                          Miscellaneous error occurred
//! \retval   NVAPI_HANDLE_INVALIDATED             Handle passed has been invalidated (see user guide)
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE   Handle passed is not a physical GPU handle
//! \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION    The version of the PERF_CLOCK_TABLE struct is not supported
//! \ingroup  gpuclock 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPerfClocks(NvPhysicalGpuHandle hPhysicalGpu, NvU32 level, NV_GPU_PERF_CLOCK_TABLE *pPerfClkTable);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_SetPerfClocks
//
//!  This function sets the Overclock to a specific level in the performance table or overclocks all levels with bSetClock set.
//! \note           The clocks represented by NV_GPU_PUBLIC_CLOCK_ID are interlocked on some GPU families. 
//!                 The API will fail to set the clocks if the interlocking ratios are violated.
//!                 For the Fermi family : PROCESSOR_CLK = 2 x GRAPHICS_CLK
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 88.90 (Rel85), 92.40 (Rel90)
//!
//! \param [in]      hPhysicalGPU    GPU selection.
//! \param [in]      level           Specific level selection. Zero for all levels. Number of levels increases with overclocking of the levels.
//! \param [in]      pPerfClkTable   Table of performance levels to set.
//!                                  Any other than DEFAULT for GPU and Level flags - gpuPerfFlags and level flags gets applied.
//!                                  If bSetClock is set, currentFreq gets applied.
//!                                  Overclocking DOMAIN_NV requires simulteneous overclocking of DOMAIN_M, else overclocking will fail.
//!
//!  \retval   NVAPI_OK                            Completed request
//!  \retval   NVAPI_ERROR                         Miscellaneous error occurred
//!  \retval   NVAPI_HANDLE_INVALIDATED            Handle passed has been invalidated (see user guide)
//!  \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle
//!  \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION   The version of the PERF_CLOCK_TABLE struct is not supported
//!  \retval   NVAPI_TESTING_CLOCKS_NOT_SUPPORTED  Testing clocks not supported
//!
//!  \ingroup  gpuclock
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetPerfClocks(NvPhysicalGpuHandle hPhysicalGpu, NvU32 level, NV_GPU_PERF_CLOCK_TABLE *pPerfClkTable);



 

///////////////////////////////////////////////////////////////////////////////////
//  GPU Cooler Controls
//  Provides ability to Get and Set the fan level or equivalent cooler levels for various target devices associated with the GPU


//! \addtogroup gpucooler
//! @{

#define NVAPI_MAX_COOLERS_PER_GPU_VER1  3
#define NVAPI_MAX_COOLERS_PER_GPU_VER2  20
#define NVAPI_MAX_COOLERS_PER_GPU_VER3  NVAPI_MAX_COOLERS_PER_GPU_VER2

#define NVAPI_MAX_COOLERS_PER_GPU       NVAPI_MAX_COOLERS_PER_GPU_VER3
#define NVAPI_MIN_COOLER_LEVEL      0
#define NVAPI_MAX_COOLER_LEVEL      100
#define NVAPI_MAX_COOLER_LEVELS 24

//! Used in NV_GPU_GETCOOLER_SETTINGS_V1 and NV_GPU_GETCOOLER_SETTINGS_V2
typedef enum 
{
    NVAPI_COOLER_TYPE_NONE = 0,
    NVAPI_COOLER_TYPE_FAN,
    NVAPI_COOLER_TYPE_WATER,
    NVAPI_COOLER_TYPE_LIQUID_NO2,
} NV_COOLER_TYPE;


//! Used in NV_GPU_GETCOOLER_SETTINGS_V1 and NV_GPU_GETCOOLER_SETTINGS_V2
typedef enum 
{
    NVAPI_COOLER_CONTROLLER_NONE = 0,
    NVAPI_COOLER_CONTROLLER_ADI,
    NVAPI_COOLER_CONTROLLER_INTERNAL,
} NV_COOLER_CONTROLLER;

//! Used in NV_GPU_GETCOOLER_SETTINGS_V1 and NV_GPU_GETCOOLER_SETTINGS_V2
typedef enum
{
    NVAPI_COOLER_POLICY_NONE                      = 0x00000000,
    NVAPI_COOLER_POLICY_MANUAL                    = 0x00000001, //!<Manual adjustment of cooler level. Gets applied right away independent of temperature or performance level.
    NVAPI_COOLER_POLICY_PERF                      = 0x00000002, //!<GPU performance controls the cooler level.
    NVAPI_COOLER_POLICY_TEMPERATURE_DISCRETE      = 0x00000004, //!<Discrete thermal levels control the cooler level.
    NVAPI_COOLER_POLICY_TEMPERATURE_CONTINUOUS    = 0x00000008, //!<Cooler level adjusted at continuous thermal levels by HW.
    NVAPI_COOLER_POLICY_TEMPERATURE_CONTINUOUS_SW = 0x00000010, //!<Cooler level adjusted at continuous thermal levels by SW.
    NVAPI_COOLER_POLICY_DEFAULT                   = 0x00000020, //!<Default is used to allowe system to chose system's default policy.
} NV_COOLER_POLICY;

//! Used in NV_GPU_GETCOOLER_SETTINGS_V1 and NV_GPU_GETCOOLER_SETTINGS_V2
typedef enum
{
    NVAPI_COOLER_TARGET_NONE = 0,
    NVAPI_COOLER_TARGET_GPU,                //!< GPU cooler requires NvPhysicalGpuHandle
    NVAPI_COOLER_TARGET_MEMORY,             //!< GPU memory cooler requires NvPhysicalGpuHandle
    NVAPI_COOLER_TARGET_POWER_SUPPLY = 4,   //!< GPU power supply cooler requires NvPhysicalGpuHandle
    NVAPI_COOLER_TARGET_ALL = 7,            //!< This cooler cools all of the components related to its target GPU.
    NVAPI_COOLER_TARGET_VCD_COOLER1 = 8,    //!< Visual Computing Device cooler 1; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER2,    //!< Visual Computing Device cooler 2; Requires NvVisualComputingDeviceHandle        
    NVAPI_COOLER_TARGET_VCD_COOLER3,    //!< Visual Computing Device cooler 3; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER4,    //!< Visual Computing Device cooler 4; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER5,    //!< Visual Computing Device cooler 5; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER6,    //!< Visual Computing Device cooler 6; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER7,    //!< Visual Computing Device cooler 7; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER8,    //!< Visual Computing Device cooler 8; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER9,    //!< Visual Computing Device cooler 9; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER10,    //!< Visual Computing Device cooler 10; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER11,    //!< Visual Computing Device cooler 11; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER12,    //!< Visual Computing Device cooler 12; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER13,    //!< Visual Computing Device cooler 13; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER14,    //!< Visual Computing Device cooler 14; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER15,    //!< Visual Computing Device cooler 15; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER16,    //!< Visual Computing Device cooler 16; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER17,    //!< Visual Computing Device cooler 17; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER18,    //!< Visual Computing Device cooler 18; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER19,    //!< Visual Computing Device cooler 19; Requires NvVisualComputingDeviceHandle
    NVAPI_COOLER_TARGET_VCD_COOLER20,    //!< Visual Computing Device cooler 20; Requires NvVisualComputingDeviceHandle

} NV_COOLER_TARGET;

//! Used in NV_GPU_GETCOOLER_SETTINGS_V1 and NV_GPU_GETCOOLER_SETTINGS_V2
typedef enum
{
    NVAPI_COOLER_CONTROL_NONE = 0,
    NVAPI_COOLER_CONTROL_TOGGLE,                   //!< ON/OFF
    NVAPI_COOLER_CONTROL_VARIABLE,                 //!< Supports variable control.
} NV_COOLER_CONTROL;

//! Used in NV_GPU_GETCOOLER_SETTINGS_V1 and NV_GPU_GETCOOLER_SETTINGS_V2
typedef enum
{
    NVAPI_INACTIVE = 0,             //!< Inactive or unsupported
    NVAPI_ACTIVE = 1,               //!< Active and spinning (in the case of a fan)
} NV_COOLER_ACTIVITY_LEVEL;


//! Used in NV_GPU_GETCOOLER_SETTINGS_V3.
typedef struct
{
    NvU32   speedRPM;       //!< current tachometer reading in RPM
    NvU8    bSupported;     //!< cooler supports tach function?
    NvU32   maxSpeedRPM;    //!< Maximum RPM corresponding to 100% defaultMaxLevel
    NvU32   minSpeedRPM;    //!< Minimum RPM corresponding to 100% defaultMinLevel
} NV_COOLER_TACHOMETER;




//! Used in NvAPI_GPU_GetCoolerSettings()
typedef struct
{
    NvU32   version;                //!< Structure version 
    NvU32   count;                  //!< Number of associated coolers with the selected GPU
    struct 
    {
        NV_COOLER_TYPE              type;               //!< Type of cooler - FAN, WATER, LIQUID_NO2...
        NV_COOLER_CONTROLLER        controller;         //!< Internal, ADI...
        NvU32                       defaultMinLevel;    //!< The min default value % of the cooler
        NvU32                       defaultMaxLevel;    //!< The max default value % of the cooler
        NvU32                       currentMinLevel;    //!< The current allowed min value % of the cooler
        NvU32                       currentMaxLevel;    //!< The current allowed max value % of the cooler
        NvU32                       currentLevel;       //!< The current value % of the cooler
        NV_COOLER_POLICY            defaultPolicy;      //!< Cooler control policy - auto-perf, auto-thermal, manual, hybrid...
        NV_COOLER_POLICY            currentPolicy;      //!< Cooler control policy - auto-perf, auto-thermal, manual, hybrid...
        NV_COOLER_TARGET            target;             //!< Cooling target - GPU, memory, chipset, powersupply, canoas...
        NV_COOLER_CONTROL           controlType;        //!< Toggle or variable
        NV_COOLER_ACTIVITY_LEVEL    active;             //!< Is the cooler active - fan spinning...
    } cooler[NVAPI_MAX_COOLERS_PER_GPU_VER1];
} NV_GPU_GETCOOLER_SETTINGS_V1;

//! Used in NvAPI_GPU_GetCoolerSettings()
//! In Version 2, the NVAPI_MAX_COOLERS_PER_GPU changed from 3 to 20 to account for 20 fans on VCD.
typedef struct
{
    NvU32   version;                //!< structure version
    NvU32   count;                  //!< number of associated coolers with the selected GPU
    struct
    {
        NV_COOLER_TYPE              type;               //!< Type of cooler - FAN, WATER, LIQUID_NO2...
        NV_COOLER_CONTROLLER        controller;         //!< Internal, ADI...
        NvU32                       defaultMinLevel;    //!< The min default value % of the cooler
        NvU32                       defaultMaxLevel;    //!< The max default value % of the cooler
        NvU32                       currentMinLevel;    //!< The current allowed min value % of the cooler
        NvU32                       currentMaxLevel;    //!< The current allowed max value % of the cooler
        NvU32                       currentLevel;       //!< The current value % of the cooler
        NV_COOLER_POLICY            defaultPolicy;      //!< Cooler control policy - auto-perf, auto-thermal, manual, hybrid...
        NV_COOLER_POLICY            currentPolicy;      //!< Cooler control policy - auto-perf, auto-thermal, manual, hybrid...
        NV_COOLER_TARGET            target;             //!< Cooling target - GPU, memory, chipset, powersupply, Visual Computing Device...
        NV_COOLER_CONTROL           controlType;        //!< Toggle or variable
        NV_COOLER_ACTIVITY_LEVEL    active;             //!< Is the cooler active - fan spinning...
    } cooler[NVAPI_MAX_COOLERS_PER_GPU_VER2];
} NV_GPU_GETCOOLER_SETTINGS_V2;


typedef struct
{
    NvU32   version;                //!< structure version
    NvU32   count;                  //!< number of associated coolers with the selected GPU
    struct
    {
        NV_COOLER_TYPE              type;               //!< type of cooler - FAN, WATER, LIQUID_NO2...
        NV_COOLER_CONTROLLER        controller;         //!< internal, ADI...
        NvU32                       defaultMinLevel;    //!< the min default value % of the cooler
        NvU32                       defaultMaxLevel;    //!< the max default value % of the cooler
        NvU32                       currentMinLevel;    //!< the current allowed min value % of the cooler
        NvU32                       currentMaxLevel;    //!< the current allowed max value % of the cooler
        NvU32                       currentLevel;       //!< the current value % of the cooler
        NV_COOLER_POLICY            defaultPolicy;      //!< cooler control policy - auto-perf, auto-thermal, manual, hybrid...
        NV_COOLER_POLICY            currentPolicy;      //!< cooler control policy - auto-perf, auto-thermal, manual, hybrid...
        NV_COOLER_TARGET            target;             //!< cooling target - GPU, memory, chipset, powersupply, Visual Computing Device...
        NV_COOLER_CONTROL           controlType;        //!< toggle or variable
        NV_COOLER_ACTIVITY_LEVEL    active;             //!< is the cooler active - fan spinning...
        NV_COOLER_TACHOMETER        tachometer;         //!< cooler tachometer info
    } cooler[NVAPI_MAX_COOLERS_PER_GPU_VER3];
} NV_GPU_GETCOOLER_SETTINGS_V3;


//!#Between ver1 and ver2 the NVAPI_MAX_COOLERS_PER_GPU changed from 3 to 20 to account for 20 fans on VCD

#define NV_GPU_GETCOOLER_SETTINGS           NV_GPU_GETCOOLER_SETTINGS_V3

#define NV_GPU_GETCOOLER_SETTINGS_VER1      MAKE_NVAPI_VERSION(NV_GPU_GETCOOLER_SETTINGS_V1,1)
#define NV_GPU_GETCOOLER_SETTINGS_VER2A     MAKE_NVAPI_VERSION(NV_GPU_GETCOOLER_SETTINGS_V2,1)  //!< For shipped R180 compatibility
#define NV_GPU_GETCOOLER_SETTINGS_VER2      MAKE_NVAPI_VERSION(NV_GPU_GETCOOLER_SETTINGS_V2,2)
#define NV_GPU_GETCOOLER_SETTINGS_VER3      MAKE_NVAPI_VERSION(NV_GPU_GETCOOLER_SETTINGS_V3,3)

#define NV_GPU_GETCOOLER_SETTINGS_VER       NV_GPU_GETCOOLER_SETTINGS_VER3


//! Used in NvAPI_GPU_SetCoolerLevels()
typedef struct 
{
    NvU32   version;        //!< Structure version 
    struct 
    {
        NvU32               currentLevel;           //!< The new value % of the cooler
        NV_COOLER_POLICY    currentPolicy;          //!< The new cooler control policy - auto-perf, auto-thermal, manual, hybrid...
    } cooler[NVAPI_MAX_COOLERS_PER_GPU_VER1];

} NV_GPU_SETCOOLER_LEVEL_V1;


//! Used in NvAPI_GPU_SetCoolerLevels()
typedef struct
{
    NvU32   version;        //structure version
    struct
    {
        NvU32               currentLevel;           //!< The new value % of the cooler
        NV_COOLER_POLICY    currentPolicy;          //!< The new cooler control policy - auto-perf, auto-thermal, manual, hybrid...
    } cooler[NVAPI_MAX_COOLERS_PER_GPU_VER2];
} NV_GPU_SETCOOLER_LEVEL_V2;

#define NV_GPU_SETCOOLER_LEVEL          NV_GPU_SETCOOLER_LEVEL_V2


#define NV_GPU_SETCOOLER_LEVEL_VER1     MAKE_NVAPI_VERSION(NV_GPU_SETCOOLER_LEVEL_V1,1)
#define NV_GPU_SETCOOLER_LEVEL_VER2     MAKE_NVAPI_VERSION(NV_GPU_SETCOOLER_LEVEL_V2,1)

#define NV_GPU_SETCOOLER_LEVEL_VER      NV_GPU_SETCOOLER_LEVEL_VER2


//! Used in NvAPI_GPU_GetCoolerPolicyTable()
typedef struct
{
    NvU32               version;        //!< Structure version
    NV_COOLER_POLICY    policy;         //!< selected policy to update the cooler levels for, example NVAPI_COOLER_POLICY_PERF
    struct 
    {
        NvU32 levelId;      //!< Level indicator for a policy
        NvU32 currentLevel; //!< New cooler level for the selected policy level indicator
        NvU32 defaultLevel; //!< Default cooler level for the selected policy level indicator
    } policyCoolerLevel[NVAPI_MAX_COOLER_LEVELS];
} NV_GPU_COOLER_POLICY_TABLE;

#define NV_GPU_COOLER_POLICY_TABLE_VER MAKE_NVAPI_VERSION(NV_GPU_COOLER_POLICY_TABLE,1)

//! @}

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetCoolerSettings
//
//!  This function retrieves the cooler information of all coolers or a specific cooler associated with the selected GPU.
//!  Coolers are indexed 0 to NVAPI_MAX_COOLERS_PER_GPU-1.
//!  - To retrieve specific cooler info, set the coolerIndex to the appropriate cooler index. 
//!  - To retrieve info for all coolers, set coolerIndex to NVAPI_COOLER_TARGET_ALL. 
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 87.60 (Rel85), 92.40 (Rel90)
//!
//! \param [in]     hPhysicalGPU    GPU selection.
//! \param [in]     coolerIndex     Explicit cooler index selection. 
//! \param [out]    pCoolerInfo     Array of cooler settings.
//!
//! \retval   NVAPI_OK                             Completed request
//! \retval   NVAPI_ERROR                          Miscellaneous error occurred.
//! \retval   NVAPI_INVALID_ARGUMENT               pCoolerInfo is NULL.
//! \retval   NVAPI_HANDLE_INVALIDATED             Handle passed has been invalidated (see user guide).
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE   Handle passed is not a physical GPU handle.
//! \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION    The version of the INFO struct is not supported.
//! \ingroup  gpucooler
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetCoolerSettings(NvPhysicalGpuHandle hPhysicalGpu, NvU32 coolerIndex, NV_GPU_GETCOOLER_SETTINGS *pCoolerInfo);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_SetCoolerLevels
//
//!  This function sets the cooler levels for all coolers or a specific cooler associated with the selected GPU.
//!  Coolers are indexed 0 to NVAPI_MAX_COOLERS_PER_GPU-1. Every cooler level with non-zero currentpolicy gets applied.          
//!  The new level should be in the range of minlevel and maxlevel retrieved from GetCoolerSettings API or between 
//!  and NVAPI_MIN_COOLER_LEVEL to MAX_COOLER_LEVEL.
//!  - To set level for a specific cooler, set the coolerIndex to the appropriate cooler index. 
//!  - To set level for all coolers, set coolerIndex to NVAPI_COOLER_TARGET_ALL. 
//!
//! \note      To lock the fan speed independent of the temperature or performance changes, set the cooler currentPolicy to 
//!            NVAPI_COOLER_POLICY_MANUAL, else set it to the current policy retrieved from the GetCoolerSettings API.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 87.60 (Rel85), 92.40 (Rel90)
//! 
//! \param [in]       hPhysicalGPU    GPU selection.
//! \param [in]       coolerIndex     Explicit cooler index selection.
//! \param [in]       pCoolerLevels   Updated cooler level and cooler policy.
//!
//! \retval   NVAPI_OK                            Completed request
//! \retval   NVAPI_ERROR                         Miscellaneous error occurred.
//! \retval   NVAPI_INVALID_ARGUMENT              pCoolerLevels is NULL.
//! \retval   NVAPI_HANDLE_INVALIDATED            Handle passed has been invalidated (see user guide).
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle.
//! \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION   The version of the INFO struct is not supported.
//! \ingroup  gpucooler
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetCoolerLevels(NvPhysicalGpuHandle hPhysicalGpu, NvU32 coolerIndex, NV_GPU_SETCOOLER_LEVEL *pCoolerLevels);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_RestoreCoolerSettings
//
//!  This function restores the modified cooler settings to NVIDIA defaults.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 87.60 (Rel85), 92.40 (Rel90)
//!
//! \param [in]       hPhysicalGPU     GPU selection.
//! \param [in]       pCoolerIndex     Array containing absolute cooler indexes to restore. Pass NULL restore all coolers.
//! \param            CoolerCount      Number of coolers to restore.
//!
//! \retval   NVAPI_OK                            Completed request
//! \retval   NVAPI_ERROR                         Miscellaneous error occurred.
//! \retval   NVAPI_HANDLE_INVALIDATED            Handle passed has been invalidated (see user guide).
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle.
//! \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION   The version of the INFO struct is not supported.
//! \ingroup  gpucooler
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_RestoreCoolerSettings(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pCoolerIndex, NvU32 coolerCount);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetCoolerPolicyTable
//
//!  This function retrieves the table of cooler and policy levels for the selected policy.
//!  Supported only for NVAPI_COOLER_POLICY_PERF.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 87.60 (Rel85), 92.40 (Rel90)
//!
//! \param [in]     hPhysicalGPU       GPU selection.
//! \param [in]     coolerIndex        Cooler index selection.
//! \param [out]    pCoolerTable       Table of policy levels and associated cooler levels.
//! \param [out]    count              Count of the number of valid levels for the selected policy.
//!
//! \retval   NVAPI_OK                            Completed request
//! \retval   NVAPI_ERROR                         Miscellaneous error occurred.
//! \retval   NVAPI_HANDLE_INVALIDATED            Handle passed has been invalidated (see user guide).
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle.
//! \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION   The version of the INFO struct is not supported.
//! \ingroup  gpucooler
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetCoolerPolicyTable(NvPhysicalGpuHandle hPhysicalGpu, NvU32 coolerIndex, NV_GPU_COOLER_POLICY_TABLE *pCoolerTable, NvU32 *count);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_SetCoolerPolicyTable
//
// DESCRIPTION:     Restore the modified cooler settings to NVIDIA defaults. Supported only for NVAPI_COOLER_POLICY_PERF.
//
//!  This function restores the modified cooler settings to NVIDIA defaults. Supported only for NVAPI_COOLER_POLICY_PERF.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 87.60 (Rel85), 92.40 (Rel90)
//!
//! \param [in]     hPhysicalGPU  GPU selection.
//! \param [in]     coolerIndex   Cooler index selection.
//! \param [in]     pCoolerTable  Updated table of policy levels and associated cooler levels. Every non-zero policy level gets updated.
//! \param [in]     count         Number of valid levels in the policy table.
//!
//! \retval   NVAPI_OK                            Completed request
//! \retval   NVAPI_ERROR                         Miscellaneous error occurred.
//! \retval   NVAPI_HANDLE_INVALIDATED            Handle passed has been invalidated (see user guide).
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle.
//! \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION   The version of the INFO struct is not supported.
//! \ingroup  gpucooler
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetCoolerPolicyTable(NvPhysicalGpuHandle hPhysicalGpu, NvU32 coolerIndex, NV_GPU_COOLER_POLICY_TABLE *pCoolerTable, NvU32 count);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_RestoreCoolerPolicyTable
//
//! DESCRIPTION:    This function restores the perf table policy levels to the defaults.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 87.60 (Rel85), 92.40 (Rel90)
//!
//! \param [in]   hPhysicalGPU   GPU selection.
//! \param [in]   coolerIndex    Cooler index selection.
//! \param [in]   pCoolerIndex   Array containing absolute cooler indexes to restore. Pass NULL restore all coolers.
//! \param        coolerCount    Number of coolers to restore.
//! \param        policy         Restore for the selected policy
//!
//! \retval   NVAPI_OK                           Completed request
//! \retval   NVAPI_ERROR                        Miscellaneous error occurred.
//! \retval   NVAPI_HANDLE_INVALIDATED           Handle passed has been invalidated (see user guide).
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE Handle passed is not a physical GPU handle.
//! \ingroup  gpucooler
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_RestoreCoolerPolicyTable(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pCoolerIndex, NvU32 coolerCount, NV_COOLER_POLICY policy);




//! \addtogroup gpupstate
//! @{

#define NV_GPU_PERF_INPUT_FLAGS_DEFAULT_SETTINGS         0x00000001 


#define NV_GPU_PERF_PSTATES_FLAGS_PERFMON_ENABLED        0x00000001 
#define NV_GPU_PERF_PSTATES_FLAGS_DYN_PSTATES_CAPABLE    0x00000002 
#define NV_GPU_PERF_PSTATES_FLAGS_DYNAMIC_PSTATE_ENABLED 0x00000004 
#define NV_GPU_PERF_PSTATES_FLAGS_MODE_INTERNAL_TEST     0x00000008 

#define NV_GPU_PERF_SET_FORCE_PSTATE_FLAGS_ASYNC       0x00000001 

#define NV_GPU_PERF_PSTATE_FLAGS_PCIELIMIT_GEN1       0x00000001 
#define NV_GPU_PERF_PSTATE_FLAGS_OVERCLOCKED_TRUE     0x00000002 
#define NV_GPU_PERF_PSTATE_FLAGS_OVERCLOCKABLE        0x00000004 

#define NV_GPU_PERF_PSTATE_CLOCK_FLAGS_OVERCLOCKABLE  0x00000001 



typedef enum _NV_GPU_PERF_PSTATE_ID
{
    NVAPI_GPU_PERF_PSTATE_P0 = 0,
    NVAPI_GPU_PERF_PSTATE_P1,
    NVAPI_GPU_PERF_PSTATE_P2,
    NVAPI_GPU_PERF_PSTATE_P3,
    NVAPI_GPU_PERF_PSTATE_P4,
    NVAPI_GPU_PERF_PSTATE_P5,
    NVAPI_GPU_PERF_PSTATE_P6,
    NVAPI_GPU_PERF_PSTATE_P7,
    NVAPI_GPU_PERF_PSTATE_P8,
    NVAPI_GPU_PERF_PSTATE_P9,
    NVAPI_GPU_PERF_PSTATE_P10,
    NVAPI_GPU_PERF_PSTATE_P11,
    NVAPI_GPU_PERF_PSTATE_P12,
    NVAPI_GPU_PERF_PSTATE_P13,
    NVAPI_GPU_PERF_PSTATE_P14,
    NVAPI_GPU_PERF_PSTATE_P15,
    NVAPI_GPU_PERF_PSTATE_UNDEFINED = NVAPI_MAX_GPU_PERF_PSTATES,

} NV_GPU_PERF_PSTATE_ID;

//! @}


//! \ingroup gpupstate
//! Used in NvAPI_GPU_GetPstatesInfo(). p-states has a valid index range of 0 to numPstates - 1.
//! pstates[i].clocks has a valid index range of 0 to numClocks -1. 
typedef struct
{
    NvU32   version;
    NvU32   flags;           //!< Reserved for future use
    NvU32   numPstates;      //!< The number of available p-states 
    NvU32   numClocks;       //!< The number of clock domains supported by each P-State
    struct
    {
        NV_GPU_PERF_PSTATE_ID   pstateId; //!< ID of the p-state.  
        NvU32                   flags;    //!< - bit 0 indicates if the PCIE limit is GEN1 or GEN2
                                          //!< - bit 1 indicates if the Pstate is overclocked or not
        struct
        {
            NV_GPU_PUBLIC_CLOCK_ID           domainId;  //!< ID of the clock domain   
            NvU32                               flags;  //!< Reserved for future use
            NvU32                                freq;  //!< Clock frequency in kHz

        } clocks[NVAPI_MAX_GPU_PERF_CLOCKS];
    } pstates[NVAPI_MAX_GPU_PERF_PSTATES];

} NV_GPU_PERF_PSTATES_INFO_V1;


//! \ingroup gpupstate
typedef struct
{
    NvU32   version;
    NvU32   flags;             //!< Reserved for future use
    NvU32   numPstates;        //!< The number of available p-states 
    NvU32   numClocks;         //!< The number of clock domains supported by each P-State   
    NvU32   numVoltages; 
    struct
    {
        NV_GPU_PERF_PSTATE_ID   pstateId;  //!< ID of the p-state. 
        NvU32                   flags;     
        struct
        {
            NV_GPU_PUBLIC_CLOCK_ID            domainId;       
            NvU32                                flags;
            NvU32                                freq;

        } clocks[NVAPI_MAX_GPU_PERF_CLOCKS];
        struct
        {
            NV_GPU_PERF_VOLTAGE_INFO_DOMAIN_ID domainId; //!< ID of the voltage domain, containing flags and mvolt info 
            NvU32                       flags;           //!< Reserved for fuure use
            NvU32                       mvolt;           //!< Voltage in mV  

        } voltages[NVAPI_MAX_GPU_PERF_VOLTAGES];

    } pstates[NVAPI_MAX_GPU_PERF_PSTATES];  //!< Valid index range is 0 to numVoltages-1

} NV_GPU_PERF_PSTATES_INFO_V2;

//! \ingroup gpupstate
typedef  NV_GPU_PERF_PSTATES_INFO_V2 NV_GPU_PERF_PSTATES_INFO;





//! \ingroup gpupstate
//! @{
//! Macro for constructing the version field of NV_GPU_PERF_PSTATES_INFO_V1 
#define NV_GPU_PERF_PSTATES_INFO_VER1  MAKE_NVAPI_VERSION(NV_GPU_PERF_PSTATES_INFO_V1,1)

//! Macro for constructing the version field of NV_GPU_PERF_PSTATES_INFO_V2 
#define NV_GPU_PERF_PSTATES_INFO_VER2  MAKE_NVAPI_VERSION(NV_GPU_PERF_PSTATES_INFO_V2,2)

//! Macro for constructing the version field of NV_GPU_PERF_PSTATES_INFO 
#define NV_GPU_PERF_PSTATES_INFO_VER   NV_GPU_PERF_PSTATES_INFO_VER2

//! @}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetPstatesInfo
//
//! DESCRIPTION:     This API retrieves all performance states (P-States) information.
//!
//!                  P-States are GPU active/executing performance capability and power consumption states.
//!                  P-States range from P0 to P15, with P0 being the highest performance/power state, and
//!                  P15 being the lowest performance/power state. Each P-State, if available, maps to a
//!                  performance level. Not all P-States are available on a given system. The definition
//!                  of each P-States are currently as follow:
//!                  - P0/P1 - Maximum 3D performance
//!                  - P2/P3 - Balanced 3D performance-power
//!                  - P8 - Basic HD video playback
//!                  - P10 - DVD playback
//!                  - P12 - Minimum idle power consumption
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version 185.55
//!
//! \param [in]   hPhysicalGPU   GPU selection.
//! \param [out]  pPerfPstates   P-States information retrieved, as detailed below:
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_HANDLE_INVALIDATED 
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE 
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  The version of the NV_GPU_PERF_PSTATES struct is not supported
//!
//! \ingroup gpupstate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPstatesInfo(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_PERF_PSTATES_INFO *pPerfPstatesInfo);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetPstatesInfoEx
//
//! DESCRIPTION:     This API retrieves all performance states (P-States) information. This is the same as
//!                  NvAPI_GPU_GetPstatesInfo(), but supports an input flag for various options.
//!
//!                  P-States are GPU active/executing performance capability and power consumption states.
//!
//!                  P-States ranges from P0 to P15, with P0 being the highest performance/power state, and
//!                  P15 being the lowest performance/power state. Each P-State, if available, maps to a
//!                  performance level. Not all P-States are available on a given system. The definitions
//!                  of each P-State are currently as follows: \n
//!                  - P0/P1 - Maximum 3D performance
//!                  - P2/P3 - Balanced 3D performance-power
//!                  - P8 - Basic HD video playback
//!                  - P10 - DVD playback
//!                  - P12 - Minimum idle power consumption
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \param [in]     hPhysicalGPU       GPU selection.
//! \param [out]    pPerfPstatesInfo   P-States information retrieved, as detailed below: \n
//!                  - flags is reserved for future use.
//!                  - numPstates is the number of available P-States
//!                  - numClocks is the number of clock domains supported by each P-State
//!                  - pstates has valid index range from 0 to numPstates - 1
//!                  - pstates[i].pstateId is the ID of the P-State,
//!                      containing the following info:
//!                    - pstates[i].flags containing the following info:
//!                        - bit 0 indicates if the PCIE limit is GEN1 or GEN2
//!                        - bit 1 indicates if the Pstate is overclocked or not
//!                        - bit 2 indicates if the Pstate is overclockable or not
//!                    - pstates[i].clocks has valid index range from 0 to numClocks -1
//!                    - pstates[i].clocks[j].domainId is the public ID of the clock domain,
//!                        containing the following info:
//!                      - pstates[i].clocks[j].flags containing the following info:
//!                          bit 0 indicates if the clock domain is overclockable or not
//!                      - pstates[i].clocks[j].freq is the clock frequency in kHz
//!                    - pstates[i].voltages has a valid index range from 0 to numVoltages - 1
//!                    - pstates[i].voltages[j].domainId is the ID of the voltage domain,
//!                        containing the following info:
//!                      - pstates[i].voltages[j].flags is reserved for future use.
//!                      - pstates[i].voltages[j].mvolt is the voltage in mV
//!                  inputFlags(IN)   - This can be used to select various options:
//!                    - if bit 0 is set, pPerfPstatesInfo would contain the default settings
//!                        instead of the current, possibily overclocked settings.
//!
//! \retval ::NVAPI_OK                            Completed request
//! \retval ::NVAPI_ERROR                         Miscellaneous error occurred
//! \retval ::NVAPI_HANDLE_INVALIDATED            Handle passed has been invalidated (see user guide)
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION   The version of the NV_GPU_PERF_PSTATES struct is not supported
//!
//! \ingroup gpupstate 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPstatesInfoEx(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_PERF_PSTATES_INFO *pPerfPstatesInfo, NvU32 inputFlags);





///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_SetPstatesInfo
//
//! DESCRIPTION:     This API set the performance states (P-States) of the specified GPU.
//!
//!                  P-States are GPU active/executing performance capability and power consumption states.
//!                  P-States ranges from P0 to P15, with P0 being the highest performance/power state, and
//!                  P15 being the lowest performance/power state. Each P-State, if available, maps to a
//!                  performance level. Not all P-States are available on a given system. The definition
//!                  of each P-States are currently as follow:
//!                    - P0/P1 - Maximum 3D performance
//!                    - P2/P3 - Balanced 3D performance-power
//!                    - P8 - Basic HD video playback
//!                    - P10 - DVD playback
//!                    - P12 - Minimum idle power consumption
//!
//!                  The changes this API makes are *not* persistent across a driver unload or reboot.  
//!                  Client applications must handle enforcing persistence.  However, client apps should
//!                  also be careful not to persist bad pstate configurations across reboots (i.e. if the
//!                  bad pstate configuration hangs the chip and the client application always applies that
//!                  configuration on boot, the user will never be able to boot and revert those changes
//!                  without booting to safe mode).
//!
//!                  NOTE: This API was introduced starting with NV_GPU_PERF_PSTATES_INFO structure version 
//!                  NV_GPU_PERF_PSTATES_INFO_VER2.  This API must be called with structure version 
//!                  >= NV_GPU_PERF_PSTATES_INFO_VER2.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \param [in]      hPhysicalGPU   GPU selection.
//! \param [in]      pPerfPstates   P-States information retrieved, as detailed below:
//!                  - flags is reserved for future use.
//!                  - numPstates the number of p-states specified
//!                  - numClocks is the number of clock domains specified in each p-state.
//!                  - numVoltages is the number of voltage domains specified in each p-State
//!                  - pstates has valid index range from 0 to numPstates - 1
//!                  - pstates[i].pstateId is the ID of the P-State,
//!                      containing the following info:
//!                    - pstates[i].flags is reserved for future use
//!                    - pstates[i].clocks has valid index range from 0 to numClocks -1
//!                    - pstates[i].clocks[j].domainId is the public ID of the clock domain,
//!                        containing the following info:
//!                      - pstates[i].clocks[j].flags is reserved for future use.
//!                      - pstates[i].clocks[j].freq is the clock frequency in kHz
//!                    - pstates[i].voltages has a valid index range from 0 to numVoltages - 1
//!                    - pstates[i].voltages[j].domainId is the ID of the voltage domain,
//!                        containing the following info:
//!                      - pstates[i].voltages[j].flags is reserved for future use.
//!                      - pstates[i].voltages[j].mvolt is the voltage in mV
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_ERROR - miscellaneous error occurred
//! \retval ::NVAPI_HANDLE_INVALIDATED - handle passed has been invalidated (see user guide)
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE - handle passed is not a physical GPU handle
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION - the version of the NV_GPU_PERF_PSTATES struct is not supported
//!
//! \ingroup gpupstate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetPstatesInfo(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_PERF_PSTATES_INFO *pPerfPstatesInfo);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetCurrentPstate
//
//! DESCRIPTION:     This function retrieves the current performance state (P-State).
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 165.22
//!
//! \param [in]      hPhysicalGPU     GPU selection
//! \param [out]     pCurrentPstate   The ID of the current P-State of the GPU - see \ref NV_GPU_PERF_PSTATES.
//!
//! \retval    NVAPI_OK                             Completed request
//! \retval    NVAPI_ERROR                          Miscellaneous error occurred.
//! \retval    NVAPI_HANDLE_INVALIDATED             Handle passed has been invalidated (see user guide).
//! \retval    NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE   Handle passed is not a physical GPU handle.
//! \retval    NVAPI_NOT_SUPPORTED                  P-States is not supported on this setup.
//!
//! \ingroup   gpupstate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetCurrentPstate(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_PERF_PSTATE_ID *pCurrentPstate);


//! \ingroup gpupstate
//! Used in NvAPI_GPU_GetPstateClientLimits().
typedef enum _NV_PERF_PSTATE_CLIENT_LIMIT_ID
{
    NVAPI_PERF_PSTATE_CLIENT_LIMIT_HARD                 = 0x00000001,       //!< P-States Hard limit 
    NVAPI_PERF_PSTATE_CLIENT_LIMIT_SOFT                 = 0x00000002,       //!< P-States Soft limit 
    NVAPI_PERF_PSTATE_CLIENT_LIMIT_BOTH                 = 0x00000003        //!< For both hard and soft P-States limits
} NV_GPU_PERF_PSTATE_CLIENT_LIMIT_ID;


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetPstateClientLimits
//
//! DESCRIPTION:     This API gets the soft or hard performance state (P-State) limit
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version 185.20
//! 
//! \param [in]    hPhysicalGPU   GPU selection.
//! \param [in]    limitId        Indicates hard limit or soft limit 
//! \param [out]   PstateLimit    The ID of the P-State that is the current limit
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_HANDLE_INVALIDATED 
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//! \retval ::NVAPI_NOT_SUPPORTED P-States is not supported on this setup
//!
//! \ingroup gpupstate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPstateClientLimits(NvPhysicalGpuHandle hPhysicalGpu,
                                                NV_GPU_PERF_PSTATE_CLIENT_LIMIT_ID limitId,
                                                NV_GPU_PERF_PSTATE_ID* PstateLimit);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_SetPstateClientLimits
//
//! DESCRIPTION:     This API sets the soft or hard performance state (P-State) limit.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version 185.20
//!
//! \param [in]     hPhysicalGPU    GPU selection.
//! \param [in]     limitId         To indicate hard limit, soft limit or both
//! \param [in]     PstateLimit     The ID of the P-State to be the new limit
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_HANDLE_INVALIDATED 
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//! \retval ::NVAPI_NOT_SUPPORTED  P-States is not supported on this setup
//!
//! \ingroup gpupstate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetPstateClientLimits(NvPhysicalGpuHandle hPhysicalGpu,
                                                NV_GPU_PERF_PSTATE_CLIENT_LIMIT_ID limitId,
                                                NV_GPU_PERF_PSTATE_ID PstateLimit);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_EnableOverclockedPstates
//
//! DESCRIPTION:     This API allows overclocked P-states. 
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version 185.20
//!
//! \param [in]     hPhysicalGP    GPU selection
//! \param [in]     bEnable        (Boolean) Enables or disables overclocked P-states 
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_HANDLE_INVALIDATED 
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//! \retval ::NVAPI_NOT_SUPPORTED  P-States or overclocked P-states is not supported on this setup
//!
//! \ingroup gpupstate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_EnableOverclockedPstates(NvPhysicalGpuHandle hPhysicalGpu,
                                                   NvU8 bEnable);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_EnableDynamicPstates
//
//! DESCRIPTION:     This API enables or disables dynamic P-states 
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version 185.20
//!
//! \param [in]     hPhysicalGPU   GPU selection.
//! \param [in]     bEnable        (Boolean) Enables or disables dynamic P-states 
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_HANDLE_INVALIDATED 
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//! \retval ::NVAPI_NOT_SUPPORTED  P-States is not supported on this setup
//!
//! \ingroup gpupstate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_EnableDynamicPstates(NvPhysicalGpuHandle hPhysicalGpu,
                                               NvU8 bEnable);





//! \addtogroup gpupstate
//! @{


//! Used in NV_GPU_DYNAMIC_PSTATES_INFO.
#define NVAPI_MAX_GPU_UTILIZATIONS 8


//! Used in NV_GPU_DYNAMIC_PSTATES_INFO -> utilization[].
typedef enum _NV_GPU_UTILIZATION_DOMAIN_ID
{
    NVAPI_GPU_UTILIZATION_DOMAIN_GPU    = 0, //!< Graphics engine domain
    NVAPI_GPU_UTILIZATION_DOMAIN_FB     = 1, //!< Frame buffer domain
    NVAPI_GPU_UTILIZATION_DOMAIN_VID    = 2, //!< Video engine domain
} NV_GPU_UTILIZATION_DOMAIN_ID;

//! @}



//! \ingroup gpupstate
#define NVAPI_MAX_GPU_UTILIZATIONS 8



//! \ingroup gpupstate
//! Used in NvAPI_GPU_GetDynamicPstatesInfoEx().
typedef struct
{
    NvU32       version;        //!< Structure version
    NvU32       flags;          //!< bit 0 indicates if the dynamic Pstate is enabled or not
    struct
    {
        NvU32   bIsPresent:1;   //!< Set if this utilization domain is present on this GPU
        NvU32   percentage;     //!< Percentage of time where the domain is considered busy in the last 1 second interval
    } utilization[NVAPI_MAX_GPU_UTILIZATIONS];
} NV_GPU_DYNAMIC_PSTATES_INFO_EX;

//! \ingroup gpupstate
//! Macro for constructing the version field of NV_GPU_DYNAMIC_PSTATES_INFO_EX
#define NV_GPU_DYNAMIC_PSTATES_INFO_EX_VER MAKE_NVAPI_VERSION(NV_GPU_DYNAMIC_PSTATES_INFO_EX,1)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetDynamicPstatesInfoEx
//
//! DESCRIPTION:   This API retrieves the NV_GPU_DYNAMIC_PSTATES_INFO_EX structure for the specified physical GPU.
//!                Each domain's info is indexed in the array.  For example: 
//!                - pDynamicPstatesInfo->utilization[NVAPI_GPU_UTILIZATION_DOMAIN_GPU] holds the info for the GPU domain. \p
//!                There are currently 3 domains for which GPU utilization and dynamic P-State thresholds can be retrieved:
//!                   graphic engine (GPU), frame buffer (FB), and video engine (VID).
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since version 185.50
//! 
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_ARGUMENT  pDynamicPstatesInfo is NULL
//! \retval ::NVAPI_HANDLE_INVALIDATED 
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE 
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION The version of the INFO struct is not supported
//!
//! \ingroup gpupstate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetDynamicPstatesInfoEx(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_DYNAMIC_PSTATES_INFO_EX *pDynamicPstatesInfoEx);




//! \ingroup gpupstate
#define NVAPI_MAX_GPU_PERF_DOMAIN_VOLTAGES   128

//! \ingroup gpupstate
typedef struct
{
    NvU32   version;
    NvU32   flags;       //!< Currently unsupported
    NvU32   numDomains;  //!< The number of voltage domains supported on the board

    struct
    {
        NV_GPU_PERF_VOLTAGE_INFO_DOMAIN_ID domainId;     //!< Domain ID
        NvU32                              flags;        //!< Currently unsupported
        NvU32                              numVoltages;  //!< The number of voltage levels defined for this domain
        struct
        {
            NvU32                       flags;           //!< Currently unsupported  
            NvU32                       mvolt;           //!< Voltage in mV
        } voltages[NVAPI_MAX_GPU_PERF_DOMAIN_VOLTAGES];  //!< Valid index range from 0 to domains[i].numVoltages - 1
    } domains[NVAPI_MAX_GPU_PERF_VOLTAGES];              //!< Valid index range from 0 to numDomains-1

} NV_GPU_PERF_VOLTAGES;  

//! \ingroup gpupstate
//! Macro for contructing the version field of NV_GPU_PERF_VOLTAGES
#define NV_GPU_PERF_VOLTAGES_VER  MAKE_NVAPI_VERSION(NV_GPU_PERF_VOLTAGES,1)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetVoltages
//
//! DESCRIPTION:     This API returns the supported voltage levels for each supported voltage domain on the board.
//!                  These are the valid voltage levels which can be used for NvAPI_GPU_SetPstates() and
//!                  NvAPI_GPU_SetPstatesInfo().
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \param [in]      hPhysicalGPU    GPU selection.
//! \param [out]     pPerfVoltages   Voltage information retrieved, as detailed below:
//!                  - flags - currently unsupported
//!                  - numDomains - the number of voltage domains supported on the board
//!                  - domains - valid index range from 0 to numDomains - 1
//!                    - domains[i].domainId - the ID of the voltage domain
//!                    - domains[i].flags - currently unsupported
//!                    - domains[i].numVoltages - number of voltage levels defined for this domain
//!                    - domains[i].voltages -  valid index range from 0 to domains[i].numVoltages - 1
//!                      - domains[i].voltages[j].flags - currently unsupported
//!                      - domains[i].voltages[j].mvolt - voltage in mV
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_ERROR - miscellaneous error occurred
//! \retval ::NVAPI_HANDLE_INVALIDATED - handle passed has been invalidated (see user guide)
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE - handle passed is not a physical GPU handle
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION - the version of the NV_GPU_PERF_PSTATES struct is not supported
//!
//! \ingroup gpupstate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetVoltages(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_PERF_VOLTAGES *pPerfVoltages);



///////////////////////////////////////////////////////////////////////////////////
//  Thermal API
//  Provides ability to get temperature levels from the various thermal sensors associated with the GPU

//! \ingroup gputhermal
#define NVAPI_MAX_THERMAL_SENSORS_PER_GPU 3

//! \ingroup gputhermal
//! Used in NV_GPU_THERMAL_SETTINGS
typedef enum 
{
    NVAPI_THERMAL_TARGET_NONE          = 0,
    NVAPI_THERMAL_TARGET_GPU           = 1,     //!< GPU core temperature requires NvPhysicalGpuHandle
    NVAPI_THERMAL_TARGET_MEMORY        = 2,     //!< GPU memory temperature requires NvPhysicalGpuHandle
    NVAPI_THERMAL_TARGET_POWER_SUPPLY  = 4,     //!< GPU power supply temperature requires NvPhysicalGpuHandle
    NVAPI_THERMAL_TARGET_BOARD         = 8,     //!< GPU board ambient temperature requires NvPhysicalGpuHandle
    NVAPI_THERMAL_TARGET_VCD_BOARD     = 9,     //!< Visual Computing Device Board temperature requires NvVisualComputingDeviceHandle
    NVAPI_THERMAL_TARGET_VCD_INLET     = 10,    //!< Visual Computing Device Inlet temperature requires NvVisualComputingDeviceHandle
    NVAPI_THERMAL_TARGET_VCD_OUTLET    = 11,    //!< Visual Computing Device Outlet temperature requires NvVisualComputingDeviceHandle

    NVAPI_THERMAL_TARGET_ALL           = 15,
    NVAPI_THERMAL_TARGET_UNKNOWN       = -1,
} NV_THERMAL_TARGET;

//! \ingroup gputhermal
//! Used in NV_GPU_THERMAL_SETTINGS
typedef enum
{
    NVAPI_THERMAL_CONTROLLER_NONE = 0,
    NVAPI_THERMAL_CONTROLLER_GPU_INTERNAL,  
    NVAPI_THERMAL_CONTROLLER_ADM1032,
    NVAPI_THERMAL_CONTROLLER_MAX6649,       
    NVAPI_THERMAL_CONTROLLER_MAX1617,      
    NVAPI_THERMAL_CONTROLLER_LM99,      
    NVAPI_THERMAL_CONTROLLER_LM89,         
    NVAPI_THERMAL_CONTROLLER_LM64,         
    NVAPI_THERMAL_CONTROLLER_ADT7473,
    NVAPI_THERMAL_CONTROLLER_SBMAX6649,
    NVAPI_THERMAL_CONTROLLER_VBIOSEVT,  
    NVAPI_THERMAL_CONTROLLER_OS,    
    NVAPI_THERMAL_CONTROLLER_UNKNOWN = -1,
} NV_THERMAL_CONTROLLER;

//! \ingroup gputhermal
//! Used in NvAPI_GPU_GetThermalSettings()
typedef struct
{
    NvU32   version;                //!< structure version 
    NvU32   count;                  //!< number of associated thermal sensors
    struct 
    {
        NV_THERMAL_CONTROLLER       controller;        //!< internal, ADM1032, MAX6649...
        NvU32                       defaultMinTemp;    //!< The min default temperature value of the thermal sensor in degrees centigrade 
        NvU32                       defaultMaxTemp;    //!< The max default temperature value of the thermal sensor in degrees centigrade 
        NvU32                       currentTemp;       //!< The current temperature value of the thermal sensor in degrees centigrade 
        NV_THERMAL_TARGET           target;            //!< Thermal sensor targeted @ GPU, memory, chipset, powersupply, Visual Computing Device, etc.
    } sensor[NVAPI_MAX_THERMAL_SENSORS_PER_GPU];

} NV_GPU_THERMAL_SETTINGS_V1;

//! \ingroup gputhermal
typedef struct
{
    NvU32   version;                //!< structure version
    NvU32   count;                  //!< number of associated thermal sensors
    struct
    {
        NV_THERMAL_CONTROLLER       controller;         //!< internal, ADM1032, MAX6649...
        NvS32                       defaultMinTemp;     //!< Minimum default temperature value of the thermal sensor in degrees C
        NvS32                       defaultMaxTemp;     //!< Maximum default temperature value of the thermal sensor in degrees C
        NvS32                       currentTemp;        //!< Current temperature value of the thermal sensor in degrees C
        NV_THERMAL_TARGET           target;             //!< Thermal sensor targeted - GPU, memory, chipset, powersupply, Visual Computing Device, etc
    } sensor[NVAPI_MAX_THERMAL_SENSORS_PER_GPU];

} NV_GPU_THERMAL_SETTINGS_V2;

//! \ingroup gputhermal
typedef NV_GPU_THERMAL_SETTINGS_V2  NV_GPU_THERMAL_SETTINGS;

//! \ingroup gputhermal
//! @{

//! Macro for constructing the version field of NV_GPU_THERMAL_SETTINGS_V1
#define NV_GPU_THERMAL_SETTINGS_VER_1   MAKE_NVAPI_VERSION(NV_GPU_THERMAL_SETTINGS_V1,1)

//! Macro for constructing the version field of NV_GPU_THERMAL_SETTINGS_V2
#define NV_GPU_THERMAL_SETTINGS_VER_2   MAKE_NVAPI_VERSION(NV_GPU_THERMAL_SETTINGS_V2,2)

//! Macro for constructing the version field of NV_GPU_THERMAL_SETTINGS
#define NV_GPU_THERMAL_SETTINGS_VER     NV_GPU_THERMAL_SETTINGS_VER_2
//! @}




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetThermalSettings
//
//!  This function retrieves the thermal information of all thermal sensors or specific thermal sensor associated with the selected GPU.
//!  Thermal sensors are indexed 0 to NVAPI_MAX_THERMAL_SENSORS_PER_GPU-1.
//!
//!  - To retrieve specific thermal sensor info, set the sensorIndex to the required thermal sensor index. 
//!  - To retrieve info for all sensors, set sensorIndex to NVAPI_THERMAL_TARGET_ALL. 
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 87.60 (Rel85), 92.40 (Rel90)
//!
//! \param [in]   hPhysicalGPU      GPU selection.
//! \param [in]   sensorIndex       Explicit thermal sensor index selection. 
//! \param [out]  pThermalSettings  Array of thermal settings.
//!
//! \retval   NVAPI_OK                           Completed request
//! \retval   NVAPI_ERROR                        Miscellaneous error occurred.
//! \retval   NVAPI_INVALID_ARGUMENT             pThermalInfo is NULL.
//! \retval   NVAPI_HANDLE_INVALIDATED           Handle passed has been invalidated (see user guide).
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE Handle passed is not a physical GPU handle.
//! \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION  The version of the INFO struct is not supported.
//! \ingroup gputhermal
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetThermalSettings(NvPhysicalGpuHandle hPhysicalGpu, NvU32 sensorIndex, NV_GPU_THERMAL_SETTINGS *pThermalSettings);




//! \ingroup gpu
//! Used in NvAPI_GPU_SetDitherControl(). 
typedef enum _NVAPI_DITHER_TYPE
{
    NVAPI_DITHER_TYPE_DEFAULT = 0,  //!< enable/disable based on the default behavior
    NVAPI_DITHER_TYPE_ENABLE  = 1,  //!< enable dithering
    NVAPI_DITHER_TYPE_DISABLE = 2,  //!< disable dithering
} NVAPI_DITHER_TYPE;


//! \ingroup gpu
//! Used in NvAPI_GPU_SetDitherControl().
typedef enum _NVAPI_DITHER_BITS
{
    NVAPI_DITHER_BITS_6BITS = 0,
    NVAPI_DITHER_BITS_8BITS = 1,
} NVAPI_DITHER_BITS;


//! \ingroup gpu
//! Used in NvAPI_GPU_SetDitherControl().
typedef enum _NVAPI_DITHER_MODE
{
    NVAPI_DITHER_MODE_DYNAMIC_ERR_ACC = 0,
    NVAPI_DITHER_MODE_STATIC_ERR_ACC  = 1,
    NVAPI_DITHER_MODE_DYNAMIC_2X2     = 2,
    NVAPI_DITHER_MODE_STATIC_2X2      = 3,
} NVAPI_DITHER_MODE;


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_SetDitherControl
//
//! DESCRIPTION: This API sets display related hardware dither controls (for example, dithering a higher bpp framebuffer to a lower bpp display).
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 187.01
//!
//! \param [in]  outputId     One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or
//!                           NvAPI_GetView(), to identify the targeted TV.
//! \param [in]  type         The dithering mode to apply (default, enable, or disable)
//! \param [in]  bits         The bits to dither to
//! \param [in]  mode         The dither mode
//!
//! \retval ::NVAPI_OK                             Dither controls successfully set.
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE   Handle passed is not a physical GPU handle.
//! \retval ::NVAPI_INVALID_ARGUMENT               Parameters passed do not match the hardware implementation.
//! \retval ::NVAPI_NOT_SUPPORTED                  Dither control feature is not supported on the selected GPU.
//! \retval ::NVAPI_NO_IMPLEMENTATION              No implementation for dither controls implemented for this GPU.
//! \retval ::NVAPI_ERROR                          Dither controls were not successfully propogated
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetDitherControl(NvPhysicalGpuHandle hPhysicalGpu,
                                           NvU32 outputId,
                                           NVAPI_DITHER_TYPE type,
                                           NVAPI_DITHER_BITS bits,
                                           NVAPI_DITHER_MODE mode);



//! \ingroup gpu
//! @{

typedef enum _NVAPI_DITHER_CONTROL_CAP_MODE
{
    NVAPI_DITHER_CONTROL_CAP_MODE_DYNAMIC_ERR_ACC     = NV_BIT(NVAPI_DITHER_MODE_DYNAMIC_ERR_ACC),
    NVAPI_DITHER_CONTROL_CAP_MODE_STATIC_ERR_ACC      = NV_BIT(NVAPI_DITHER_MODE_STATIC_ERR_ACC),
    NVAPI_DITHER_CONTROL_CAP_MODE_DYNAMIC_2X2         = NV_BIT(NVAPI_DITHER_MODE_DYNAMIC_2X2),
    NVAPI_DITHER_CONTROL_CAP_MODE_STATIC_2X2          = NV_BIT(NVAPI_DITHER_MODE_STATIC_2X2),
} NVAPI_DITHER_CONTROL_CAP_MODE;

typedef enum _NVAPI_DITHER_CONTROL_CAP_BITS
{
    NVAPI_DITHER_CONTROL_CAP_BITS_6BITS               = NV_BIT(NVAPI_DITHER_BITS_6BITS),
    NVAPI_DITHER_CONTROL_CAP_BITS_8BITS               = NV_BIT(NVAPI_DITHER_BITS_8BITS),
} NVAPI_DITHER_CONTROL_CAP_BITS;

typedef struct _NV_GPU_DITHER_CONTROL_V1
{
    NvU32               version;            //!< Structure version

    NVAPI_DITHER_TYPE   ditherEnable;       //!< The dithering mode to apply (default, enable, or disable)
    NVAPI_DITHER_BITS   ditherBitDepth;     //!< The bits per component of the output
    NVAPI_DITHER_MODE   ditherMode;         //!< The dither mode

    NvU32               ditherBitDepths;    //!< Bitfield of supported NVAPI_DITHER_CONTROL_CAP_MODEs
    NvU32               ditherModes;        //!< Bitfield of supported NVAPI_DITHER_CONTROL_CAP_BITS


} NV_GPU_DITHER_CONTROL_V1;

typedef NV_GPU_DITHER_CONTROL_V1           NV_GPU_DITHER_CONTROL;

#define NV_GPU_DITHER_CONTROL_VER1         MAKE_NVAPI_VERSION(NV_GPU_DITHER_CONTROL_V1,1)
#define NV_GPU_DITHER_CONTROL_VER          NV_GPU_DITHER_CONTROL_VER1

//! @}



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetDitherControl
//
//! DESCRIPTION: This API returns display-related GPU dither controls. 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]    displayId     Address of target active GPU output
//! \param [out]   pDitherData   Struct containing dithering state information
//!
//! \retval ::NVAPI_OK                            Dither controls successfully received.
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle.
//! \retval ::NVAPI_INVALID_ARGUMENT              Parameters passed do not match the hardware implementation
//! \retval ::NVAPI_NOT_SUPPORTED                 Dither control feature is not supported on the selected GPU
//! \retval ::NVAPI_NO_IMPLEMENTATION             No implementation for dither controls implemented for this GPU
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetDitherControl(NvU32 displayId, 
                                           NV_GPU_DITHER_CONTROL *pDitherData);


//! \ingroup gpucsc  
//! @{

#define NVAPI_CSC_MATRIX_WIDTH 3
#define NVAPI_CSC_MATRIX_HEIGHT 4

//! Colorspace conversion
typedef struct _NVAPI_CSC_MATRIX
{
    NvU32   useCustomMatrix : 1;                                           //!< If this value is 0, aCSCCoeff values are ignored.
    NvU32   reserved        : 31;                                          //!< Reserved for future expansion
    float   aCSCCoeff [NVAPI_CSC_MATRIX_WIDTH][NVAPI_CSC_MATRIX_HEIGHT];   //!< 3x4 matrix of CSC coefficients
} NVAPI_CSC_MATRIX;

//! Enum of predefined colorspaces that are supported
typedef enum _NV_STANDARD_COLORSPACE
{
    NV_STANDARD_COLORSPACE_DISABLED            = 0,                             //!< CSC disabled, user matrices ignored
    NV_STANDARD_COLORSPACE_AUTOSELECT          = 1,                             //!< Use the display-specific info, user matrices ignored.
    NV_STANDARD_COLORSPACE_sRGB                = 2,                             //!< Only user matrices are applied, output is sRGB
    NV_STANDARD_COLORSPACE_MONITOR_RGB         = 3,                             //!< Use the display-specific info, plus user matrices if indicated
    NV_STANDARD_COLORSPACE_ADOBE_RGB           = 4,                             //!< output is in Adobe RGB, plus user matrices if indicated
    NV_STANDARD_COLORSPACE_ADOBE_WIDE_GAMUT    = 5,                             //!< output is in Adobe Wide Gamut RGB, plus user matrices if indicated
    NV_STANDARD_COLORSPACE_APPLE               = 6,                             //!< output is in Apple RGB, plus user matrices if indicated
    NV_STANDARD_COLORSPACE_NTSC                = 7,                             //!< output is in NTSC RGB, plus user matrices if indicated
    NV_STANDARD_COLORSPACE_HDTV                = 8,                             //!< output is in HDTV RGB, plus user matrices if indicated
    NV_STANDARD_COLORSPACE_PAL                 = 9,                             //!< output is in PAL/SECAM RGB, plus user matrices if indicated
    NV_STANDARD_COLORSPACE_DCIP3               = 10,                            //!< output is in DCI-P3 (SMPTE-431-2)

    NV_STANDARD_COLORSPACE_MAX                                                  //!< Max valid value +1, for range checking
} NV_STANDARD_COLORSPACE;

//! Enum of colorspace status flags
typedef enum _NV_COLORSPACE_CONVERSION_STATUS_FLAG
{
    NV_COLORSPACE_CONVERSION_STATUS_FLAG_USER_MATRIX_RANGE_CLAMPED = NV_BIT(0),  //!< If User Matrix coefficients were out of range, this flag means some values were automatically clamped to range
    NV_COLORSPACE_CONVERSION_STATUS_FLAG_SW_EMULATION              = NV_BIT(1),  //!< If present, CSC is performed by pixel shaders.  Otherwise, CSC is done in dedicated hardware
} NV_COLORSPACE_CONVERSION_STATUS_FLAG;




//! Param struct used by SetCSC and GetCSC
typedef struct _NV_GPU_COLORSPACE_CONVERSION_V1
{   
     NvU32                    version;                            //!<  Structure version

    NV_STANDARD_COLORSPACE   sourceColorSpace;                   //!<  Specify a predefined colorspace configuration that represents the source material
    NV_STANDARD_COLORSPACE   outputColorSpace;                   //!<  Specify a predefined colorspace configuration to output
    NvU32                    flags;                              //!<  Combination of NV_COLORSPACE_CONVERSION_STATUS_FLAGs
    NvU32                    reserved;                           //!< Reserved for future expansion

    NVAPI_CSC_MATRIX         MatrixPre;                          //!<  Custom CSC Matrix, applied in preorder to colorspace config transform 
    NVAPI_CSC_MATRIX         MatrixPost;                         //!<  Custom CSC Matrix, applied in postorder to colorspace config transform 
} NV_GPU_COLORSPACE_CONVERSION_V1;

typedef NV_GPU_COLORSPACE_CONVERSION_V1     NV_GPU_COLORSPACE_CONVERSION;

#define NV_GPU_COLORSPACE_CONVERSION_VER1   MAKE_NVAPI_VERSION(NV_GPU_COLORSPACE_CONVERSION_V1,1)
#define NV_GPU_COLORSPACE_CONVERSION_VER    NV_GPU_COLORSPACE_CONVERSION_VER1

//! @}



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetColorSpaceConversion
//
//
//! DESCRIPTION: Returns the colorspace conversion matrix currently applied by the GPU
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]    displayId     Address of target active GPU output
//! \param [out]   pColorData    Current color space conversion data
//!
//! \retval ::NVAPI_OK                            Colorspace configuration successfully recieved.
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle.
//! \retval ::NVAPI_INVALID_ARGUMENT              Parameters passed do not match the hardware implementation
//! \retval ::NVAPI_NOT_SUPPORTED                 Colorspace conversion feature is not supported on the selected GPU
//! \retval ::NVAPI_NO_IMPLEMENTATION             No implementation for colorspace conversion implemented for this GPU
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION   The version of the NV_GPU_COLORSPACE_CONVERSION struct is not supported.
//!
//! \ingroup gpucsc
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetColorSpaceConversion(NvU32 displayId, 
                                                  NV_GPU_COLORSPACE_CONVERSION *pColorData);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_SetColorSpaceConversion
//
//
//! DESCRIPTION: Sets the colorspace conversion matrix 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   displayId      Address of target active GPU output
//! \param [in]   colorData      New color space conversion data
//!
//! \retval ::NVAPI_OK - Colorspace configuration successfully applied.
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE - handle passed is not a physical GPU handle.
//! \retval ::NVAPI_INVALID_ARGUMENT - Parameters passed do not match the hardware implementation
//! \retval ::NVAPI_NOT_SUPPORTED - Colorspace conversion feature is not supported on the selected GPU
//! \retval ::NVAPI_NO_IMPLEMENTATION - No implementation for colorspace conversion implemented for this GPU
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION: the version of the NV_GPU_COLORSPACE_CONVERSION struct is not supported.
//! 
//! \ingropup gpucsc
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetColorSpaceConversion(NvU32 displayId, 
                                                  NV_GPU_COLORSPACE_CONVERSION *pColorData);






////////////////////////////////////////////////////////////////////////////////
//
// NvAPI_TVOutput Information
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup tvapi
//! Used in NV_DISPLAY_TV_OUTPUT_INFO
typedef enum _NV_DISPLAY_TV_FORMAT
{
    NV_DISPLAY_TV_FORMAT_NONE         = 0,
    NV_DISPLAY_TV_FORMAT_SD_NTSCM     = 0x00000001,
    NV_DISPLAY_TV_FORMAT_SD_NTSCJ     = 0x00000002,
    NV_DISPLAY_TV_FORMAT_SD_PALM      = 0x00000004,
    NV_DISPLAY_TV_FORMAT_SD_PALBDGH   = 0x00000008,
    NV_DISPLAY_TV_FORMAT_SD_PALN      = 0x00000010,
    NV_DISPLAY_TV_FORMAT_SD_PALNC     = 0x00000020,
    NV_DISPLAY_TV_FORMAT_SD_576i      = 0x00000100,
    NV_DISPLAY_TV_FORMAT_SD_480i      = 0x00000200,
    NV_DISPLAY_TV_FORMAT_ED_480p      = 0x00000400,
    NV_DISPLAY_TV_FORMAT_ED_576p      = 0x00000800,
    NV_DISPLAY_TV_FORMAT_HD_720p      = 0x00001000,
    NV_DISPLAY_TV_FORMAT_HD_1080i     = 0x00002000,
    NV_DISPLAY_TV_FORMAT_HD_1080p     = 0x00004000,
    NV_DISPLAY_TV_FORMAT_HD_720p50    = 0x00008000,
    NV_DISPLAY_TV_FORMAT_HD_1080p24   = 0x00010000,
    NV_DISPLAY_TV_FORMAT_HD_1080i50   = 0x00020000,
    NV_DISPLAY_TV_FORMAT_HD_1080p50   = 0x00040000,

    NV_DISPLAY_TV_FORMAT_SD_OTHER     = 0x01000000,
    NV_DISPLAY_TV_FORMAT_ED_OTHER     = 0x02000000,
    NV_DISPLAY_TV_FORMAT_HD_OTHER     = 0x04000000,

    NV_DISPLAY_TV_FORMAT_ANY          = 0x80000000,

} NV_DISPLAY_TV_FORMAT;


//! \ingroup tvapi
//! Used in NvAPI_SetGpuTopologies() and NvAPI_GetGpuTopologies()
typedef struct
{
    NvU32                   version;                            //!< [IN]       Structure version.
    NvU32                   supportedFormats;                   //!< [OUT only] One or more TV formats defined in NV_DISPLAY_TV_FORMAT matching, encoder supported formats for analog TVs or EDID exposed modes for digital TVs.
    NV_DISPLAY_TV_FORMAT    currentFormat;                      //!< [IN/OUT]   One of the selected TV output format from supportedFormats defined in NV_DISPLAY_TV_FORMAT.
    NV_GPU_CONNECTOR_TYPE   currentConnector;                   //!< [IN/OUT]   For Analog TV, valid TV output connector is one of the NVAPI_GPU_CONNECTOR_TV types.
                                                                //!<            For Digital TV, valid TV output connector is one of the NVAPI_GPU_CONNECTOR_DVI types.
} NV_DISPLAY_TV_OUTPUT_INFO;    

//! \ingroup tvapi
#define NV_DISPLAY_TV_OUTPUT_INFO_VER MAKE_NVAPI_VERSION(NV_DISPLAY_TV_OUTPUT_INFO, 1)

 
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetTVOutputInfo
//
//!  This function retrieves the TV display output information of the selected display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.00
//!
//! \param [in]  hNvDisplay         NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  outputId           One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs or NvAPI_GetView, to identify the targeted TV. See \ref handles.
//!                                 Can be NULL to auto pick the TV output associated with hNvDisplay.
//!                                 The outputId must be of type #NVAPI_GPU_OUTPUT_TV or #NVAPI_GPU_OUTPUT_DFP in case of a digital HDTV.
//! \param [out] pTVOutInfo         The returned TV output information.
//!                                 With digital HDTV, the supportedFormats are limited to the available EIA-861B modes in the EDID 
//!                                 or the custom 861B modes if added by the user.
//!                                 
//!
//! \retval   NVAPI_OK                           Call successful.
//! \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND      No NVIDIA GPU driving a display was found.
//! \retval   NVAPI_EXPECTED_DISPLAY_HANDLE      hNvDisplay is not a valid display handle.
//! \retval   NVAPI_INVALID_ARGUMENT             pTVOutInfo is NULL.
//! \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION  The version of the NV_DISPLAY_TV_OUTPUT_INFO_VER struct is not supported.
//! \retval   NVAPI_EXPECTED_TV_DISPLAY          Expected TV output display in outputId.
//! \ingroup tvapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetTVOutputInfo(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_DISPLAY_TV_OUTPUT_INFO *pTVOutInfo);



//! \ingroup tvapi
//! Use in NvAPI_SetTVEncoderControls() and NvAPI_GetTVEncoderControls().
typedef struct
{
    NvU32   version;                //!< [IN] Version info  

    struct
    {
        NvU32   defaultLevel;       //!< [OUT] Default level
        NvU32   currentLevel;       //!< [IN/OUT] Current level
        NvU32   minLevel;           //!< [OUT] Minimum range level
        NvU32   maxLevel;           //!< [OUT] Maximum range level
    }   flicker, saturation;

} NV_TV_ENCODER_CONTROLS;

//! \ingroup tvapi
#define NV_TV_ENCODER_CONTROLS_VER  MAKE_NVAPI_VERSION(NV_TV_ENCODER_CONTROLS,1)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetTVEncoderControls
//
//!   DESCRIPTION: This function retrieves the flicker and saturation levels for the selected TV.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 167.10
//!
//!  \param [in]   hNvDisplay      NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or 
//!                                a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//!  \param [in]   outputId        One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or 
//!                                NvAPI_GetView(), to identify the target output in case multiple targets are 
//!                                associated with the selected hNvDisplay. 
//!                                Can be NULL to pick the display output ID associated with hNvDisplay. See \ref handles.
//!  \param [out]  pTvEncoderInfo  The returned TV encoder controls and its levels. See \ref NV_TV_ENCODER_CONTROLS.
//! 
//!  \note If maxLevel and minLevel are both zero then that control is not supported on this GPU and should not be used.
//!
//!  \retval  NVAPI_OK                            Call successful.
//!  \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//!  \retval  NVAPI_EXPECTED_DISPLAY_HANDLE       hNvDisplay is not a valid display handle.
//!  \retval  NVAPI_INVALID_ARGUMENT              pTvEncoderInfo is NULL.
//!  \retval  NVAPI_INCOMPATIBLE_STRUCT_VERSION   The version of the NV_TV_ENCODER_CONTROLS struct is not supported.
//!  \retval  NVAPI_NOT_SUPPORTED                 TV or this API is not supported on the selected GPU.
//!
//!  \ingroup tvapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetTVEncoderControls(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_TV_ENCODER_CONTROLS *pTvEncoderInfo);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_SetTVEncoderControls
//
//!   DESCRIPTION: This function sets the flicker and saturation levels for the selected TV.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 167.10
//!
//!  \param [in]   hNvDisplay      NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or 
//!                                a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//!  \param [in]   outputId        One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or 
//!                                NvAPI_GetView(), to identify the target output in case multiple targets are 
//!                                associated with the selected hNvDisplay. See \ref handles.
//!                                Can be NULL to pick the display output ID associated with hNvDisplay.
//!  \param [in]   pTvEncoderInfo  The selected TV encoder controls and its levels that are applied. See \ref NV_TV_ENCODER_CONTROLS.
//!
//!  \retval  NVAPI_OK                            Call successful.
//!  \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND       No NVIDIA GPU driving a display was found.
//!  \retval  NVAPI_EXPECTED_DISPLAY_HANDLE       hNvDisplay is not a valid display handle.
//!  \retval  NVAPI_INCOMPATIBLE_STRUCT_VERSION   The version of the NV_TV_ENCODER_CONTROLS struct is not supported.
//!  \retval  NVAPI_NOT_SUPPORTED                 TV or this API is not supported on the selected GPU.
//!
//!  \ingroup tvapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetTVEncoderControls(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_TV_ENCODER_CONTROLS *pTvEncoderInfo);


//! \ingroup tvapi
//! Used in NvAPI_SetTVOutputBorderColor() and NvAPI_GetTVOutputBorderColor().
typedef enum
{ 
    NV_TV_BORDER_COLOR_BLACK    = 0,
    NV_TV_BORDER_COLOR_GREY     = 1,
} NV_TV_BORDER_COLOR;

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetTVOutputBorderColor
//
//!   DESCRIPTION: This function retrieves the color of the TV border.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!   \since Version: 167.10
//!
//!   \param [in]  hNvDisplay     NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or 
//!                               a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//!   \param [in]  outputId       One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs() or 
//!                               NvAPI_GetView(), to identify the target output in case multiple targets are 
//!                               associated with the selected hNvDisplay.
//!                               Can be NULL to pick the display output ID associated with hNvDisplay. See \ref handles.
//!   \param [out] pBorderColor   The returned TV border color.
//!
//!   \retval   NVAPI_OK                       Call successful.
//!   \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found.
//!   \retval   NVAPI_EXPECTED_DISPLAY_HANDLE  hNvDisplay is not a valid display handle.
//!   \retval   NVAPI_INVALID_ARGUMENT         pBorderColor is NULL.
//!   \retval   NVAPI_NOT_SUPPORTED            TV or this API is not supported on the selected GPU.
//!
//!   \ingroup tvapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetTVOutputBorderColor(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_TV_BORDER_COLOR *pBorderColor);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_SetTVOutputBorderColor
//
//!   DESCRIPTION: This function sets the color of the TV border.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!   \since Version: 167.10
//!
//!   \param [in]  hNvDisplay     NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or 
//!                               a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//!   \param [in]  outputId       One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs or 
//!                               NvAPI_GetView, to identify the target output in case multiple targets are 
//!                               associated with the selected hNvDisplay. See \ref handles.
//!                               Can be NULL to pick the display output ID associated with hNvDisplay.
//!   \param [in]  pBorderColor   The TV border color to set.
//!
//!   \retval   NVAPI_OK                       Call successful.
//!   \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found.
//!   \retval   NVAPI_EXPECTED_DISPLAY_HANDLE  hNvDisplay is not a valid display handle.
//!   \retval   NVAPI_NOT_SUPPORTED            TV or this API is not supported on the selected GPU.
//!
//!   \ingroup tvapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetTVOutputBorderColor(NvDisplayHandle hNvDisplay, NvU32 outputId, NV_TV_BORDER_COLOR borderColor);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetDisplayPosition
//
//!   DESCRIPTION: This function retrieves the display position of the associated analog display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!   \since Version: 167.10
//!
//!   \param [in]  hNvDisplay     NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or 
//!                               a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//!   \param [in]  outputId       One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs or 
//!                               NvAPI_GetView, to identify the target output in case multiple targets are 
//!                               associated with the selected hNvDisplay. See \ref handles.
//!                               Can be NULL to pick the display output ID associated with hNvDisplay.
//!   \param [out] pXOffset       The returned display position x-offset.  
//!   \param [out] pYOffset       The returned display position y-offset.
//!
//!   \retval   NVAPI_OK                       Call successful.
//!   \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found.
//!   \retval   NVAPI_EXPECTED_DISPLAY_HANDLE  hNvDisplay is not a valid display handle.
//!   \retval   NVAPI_INVALID_ARGUMENT         pXOffset or pYOffset is NULL.
//!   \retval   NVAPI_NOT_SUPPORTED            This API is not supported.
//!   \retval   NVAPI_EXPECTED_ANALOG_DISPLAY  The selected display is not an analog display.
//!
//!   \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetDisplayPosition(NvDisplayHandle hNvDisplay, NvU32 outputId, NvU32 *pXOffset, NvU32 *pYOffset);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_SetDisplayPosition
//
//!   DESCRIPTION: This function sets the display position of the associated analog display.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//!   \since Version: 167.10
//!
//!   \param [in]  hNvDisplay     NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or 
//!                               a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//!   \param [in]  outputId       One of the selected outputId retrieved from NvAPI_GPU_GetActiveOutputs or 
//!                               NvAPI_GetView, to identify the target output in case multiple targets are 
//!                               associated with the selected hNvDisplay. See \ref handles.
//!                               Can be NULL to pick the display output ID associated with hNvDisplay.
//!   \param [in]  XOffset        The set display position x-offset.  
//!   \param [in]  YOffset        The set display position y-offset.
//!
//!   \retval   NVAPI_OK                       Call successful.
//!   \retval   NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found.
//!   \retval   NVAPI_EXPECTED_DISPLAY_HANDLE  hNvDisplay is not a valid display handle.
//!   \retval   NVAPI_NOT_SUPPORTED            This API is not supported.
//!   \retval   NVAPI_EXPECTED_ANALOG_DISPLAY  The selected display is not an analog display.
//!
//!   \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetDisplayPosition(NvDisplayHandle hNvDisplay, NvU32 outputId, NvU32 xOffset, NvU32 yOffset);



///////////////////////////////////////////////////////////////////////////////////
//  GPU topology reconfiguration APIs.
//  Provides ability to define one or more SLI devices and standalone GPU topology.
//
//  NV_GPU_TOPOLOGY - this structure defines a set of all GPUs present in a system.  All GPUs with
//  the same parentNdx value describe a single logical GPU.  GPUs that have a unique parentNdx
//  represent standalone GPUs. 
//
//  The values returned in parentNdx are arbitrary.  They are only used to determine which
//  physical GPUs will belong to the same logical-GPU.
//   

//! \addtogroup gputopology
//! @{

//! Used in NV_GPU_TOPOLOGY
typedef enum
{ 
    NV_GPU_TOPOLOGY_STATUS_OK                       = 0x00000000,//!< SLI is capable, topology "status" field indicates this state.
    NV_GPU_TOPOLOGY_STATUS_INVALID_GPU_COUNT        = 0x00000001,//!< SLI is NOT capable, "pStatus" param in NvAPI_GetValidGpuTopologies() indicates these states.
    NV_GPU_TOPOLOGY_STATUS_OS_NOT_SUPPORTED         = 0x00000002,
    NV_GPU_TOPOLOGY_STATUS_OS_ERROR                 = 0x00000004,
    NV_GPU_TOPOLOGY_STATUS_NO_VIDLINK               = 0x00000008,
    NV_GPU_TOPOLOGY_STATUS_INSUFFICIENT_LINK_WIDTH  = 0x00000010,
    NV_GPU_TOPOLOGY_STATUS_CPU_NOT_SUPPORTED        = 0x00000020,
    NV_GPU_TOPOLOGY_STATUS_GPU_NOT_SUPPORTED        = 0x00000040,
    NV_GPU_TOPOLOGY_STATUS_BUS_NOT_SUPPORTED        = 0x00000080,
    NV_GPU_TOPOLOGY_STATUS_NON_APPROVED_CHIPSET     = 0x00000100,
    NV_GPU_TOPOLOGY_STATUS_VBIOS_NOT_SUPPORTED      = 0x00000200,
    NV_GPU_TOPOLOGY_STATUS_GPU_MISMATCH             = 0x00000400,
    NV_GPU_TOPOLOGY_STATUS_ARCH_MISMATCH            = 0x00000800,
    NV_GPU_TOPOLOGY_STATUS_IMPL_MISMATCH            = 0x00001000,
    NV_GPU_TOPOLOGY_STATUS_REV_MISMATCH             = 0x00002000,
    NV_GPU_TOPOLOGY_STATUS_NON_PCIE_BUS             = 0x00004000,
    NV_GPU_TOPOLOGY_STATUS_FB_MISMATCH              = 0x00008000,
    NV_GPU_TOPOLOGY_STATUS_VBIOS_MISMATCH           = 0x00010000,
    NV_GPU_TOPOLOGY_STATUS_QUADRO_MISMATCH          = 0x00020000,
    NV_GPU_TOPOLOGY_STATUS_BUS_TOPOLOGY_ERROR       = 0x00040000,
    NV_GPU_TOPOLOGY_STATUS_PCI_ID_MISMATCH          = 0x00080000,
    NV_GPU_TOPOLOGY_STATUS_CONFIGSPACE_ACCESS_ERROR = 0x00100000,
    NV_GPU_TOPOLOGY_STATUS_INCONSISTENT_CONFIG_SPACE= 0x00200000,
    NV_GPU_TOPOLOGY_STATUS_CONFIG_NOT_SUPPORTED     = 0x00400000,
    NV_GPU_TOPOLOGY_STATUS_RM_NOT_SUPPORTED         = 0x00800000,
    NV_GPU_TOPOLOGY_STATUS_TOPOLOGY_NOT_ALLOWED     = 0x01000000,
    NV_GPU_TOPOLOGY_STATUS_MOBILE_MISMATCH          = 0x02000000,//!< The system has a mix of notebook and desktop GPUs.
    NV_GPU_TOPOLOGY_STATUS_NO_TOPOLOGIES_IN_HYBRID_POWER_MODE = 0x04000000,
    NV_GPU_TOPOLOGY_STATUS_INSUFFICIENT_FB          = 0x08000000,
} NV_GPU_TOPOLOGY_STATUS_FLAGS;

//! Used in NvAPI_SetGpuTopologies()
typedef enum
{ 
    NV_SET_GPU_TOPOLOGY_DEFER_APPLY                 = 0x00000001,//!< Calling application controls the reload of the display driver
    NV_SET_GPU_TOPOLOGY_DEFER_3D_APP_SHUTDOWN       = 0x00000002,//!< Calling application will control the shutdown of 3d applications holding hw resources
    NV_SET_GPU_TOPOLOGY_DEFER_DISPLAY_RECONFIG      = 0x00000004,//!< Calling application will control the display configuration required for the settopology to work
    NV_SET_GPU_TOPOLOGY_RELOAD_DRIVER               = 0x80000000,//!< Calling application requesting force reload given correct topology.
    NV_SET_GPU_TOPOLOGY_DEFER_DISPLAY_REAPPLY       = 0x00000008,//!< Calling application will control the display configuration after the settopology returns.
} NV_SET_GPU_TOPOLOGY_FLAGS;


//! Used in NV_GPU_TOPOLOGY.
//! All of these flags are read-only unless otherwise noted in NvAPI_SetGpuTopologies().
typedef enum
{
    NV_GPU_TOPOLOGY_ACTIVE                          = 0x00000001,//!< This topology is currently active.
    NV_GPU_TOPOLOGY_VIDLINK_PRESENT                 = 0x00000002,//!< Video link betweem all GPUs is present (physically bridged).
    NV_GPU_TOPOLOGY_MULTIGPU                        = 0x00000004,//!< This is a "multi-GPU" labelled topology. 
    NV_GPU_TOPOLOGY_GX2_BOARD                       = 0x00000008,//!< GPUs comprising this topology are "Dagwoods".
    NV_GPU_TOPOLOGY_DYNAMIC_NOT_ALLOWED             = 0x00000010,//!< Dynamically switching to SLI is not allowed, but requires a reboot.
    NV_GPU_TOPOLOGY_ACTIVE_IMPLICIT                 = 0x00000020,//!< Implicit read only SLI is ACTIVE on this topology of GPU. NvAPI_SetHybridMode() can be used to disable this topology.
    
    NV_GPU_TOPOLOGY_ENABLE_SLI_BY_DEFAULT           = 0x00000040,//!< SLI must be enabled by default, otherwise SLI is optional
    NV_GPU_TOPOLOGY_ENABLE_CORELOGIC_BROADCAST      = 0x00000080,//!< Broadcast mode is enabled in the core logic chipset.
    NV_GPU_TOPOLOGY_BROADCAST                       = 0x00000100,//!< Broadcast mode is enabled
    NV_GPU_TOPOLOGY_UNICAST                         = 0x00000200,//!< Unicast mode enabled
    NV_GPU_TOPOLOGY_4_WAY_SLI                       = 0x00000400,//!< This is a "4-Way-SLI"-labeled topology.
    NV_GPU_TOPOLOGY_COMPUTE                         = 0x00010000,//!< GPUs in this topology are for SLI compute.
                                                                 //!< All GPUs of this SLI compute group can be enumerated using NvAPI_GPU_CudaEnumComputeCapableGpus().
    NV_GPU_TOPOLOGY_SLIMULTIMON                     = 0x00020000,//!< This topology allows multi-display SLI output. 
    NV_GPU_TOPOLOGY_VIDLINK_CONNECTOR_PRESENT       = 0x00040000,//!< Video link connectors on all GPUs are present (but not necessarily connected).
    NV_GPU_TOPOLOGY_VIEW_CAN_SPAN_GPUS              = 0x00080000,//!< This topology allows multi-display SLI output across GPUs.
    NV_GPU_TOPOLOGY_DRIVER_RELOADING                = 0x00100000,//!< The display driver for this topology is currently being reloaded.
    NV_GPU_TOPOLOGY_BASE_MOSAIC                     = 0x00200000,//!< This topology is only for Base Mosaic mode.
    NV_GPU_TOPOLOGY_ALLOW_SLI_MOSAIC                = 0x00400000,//!< This topology will allow SLI Mosaic mode.
} NV_GPU_TOPOLOGY_FLAGS;



typedef enum
{
    NV_SLI_GROUP_ACTIVE                          = 0x00000001,//!< This SLI group is currently active.
} NV_SLI_GROUP_FLAGS;



//! Used in NV_GPU_TOPOLOGIES. 
//! This structure defines a set of all GPUs present in a system.  All GPUs with
//! the same parentNdx value describe a single logical GPU.  GPUs that have a unique parentNdx
//! represent standalone GPUs. \n
//! The values returned in parentNdx are arbitrary.  They are only used to determine which
//! physical GPUs belong to the same logical-GPU.
typedef struct
{
    NvU32                   version;                                    //!< Structure version
    NvU32                   gpuCount;                                   //!< Count of GPUs in this topology
    NvPhysicalGpuHandle     hPhysicalGpu[NVAPI_MAX_GPU_PER_TOPOLOGY];   //!< Array of GPU handles
    NvU32                   displayGpuIndex;                            //!< Index of the display GPU owner in the GPU array
    NvU32                   displayOutputTargetMask;                    //!< Target device mask 
    NvU32                   flags;                                      //!< One or more topology flags from NV_GPU_TOPOLOGY_FLAGS
    NvU32                   status;                                     //!< Indicates one of the flags in NV_GPU_TOPOLOGY_STATUS_FLAGS
} NV_GPU_TOPOLOGY_V1;


//! Macro for constructingteh version field of NV_GPU_TOPOLOGY_V1
#define NV_GPU_TOPOLOGY_VER_1  MAKE_NVAPI_VERSION(NV_GPU_TOPOLOGY_V1,1)

//! Used in NV_GPU_TOPOLOGIES. 
//! This structure defines a set of all GPUs present in a system.  All GPUs with
//! the same parentNdx value describe a single logical GPU.  GPUs that have a unique parentNdx
//! represent standalone GPUs. \n
//! The values returned in parentNdx are arbitrary.  They are only used to determine which
//! physical GPUs belong to the same logical-GPU.
typedef struct
{
    NvU32                   version;                                    //!< Structure version
    NvU32                   gpuCount;                                   //!< Count of GPUs in this topology
    NvPhysicalGpuHandle     hPhysicalGpu[NVAPI_MAX_GPU_PER_TOPOLOGY];   //!< Array of GPU handles
    NvU32                   displayGpuIndex;                            //!< Index of the display GPU owner in the GPU array
    NvU32                   displayOutputTargetMask;                    //!< Target device mask
    NvU32                   noDisplayGpuMask;                           //!< Index mask in the hPhysicalGpu[] array pointing to GPUs that cannot display when SLI is enabled
    NvU32                   flags;                                      //!< One or more topology flags from NV_GPU_TOPOLOGY_FLAGS
    NvU32                   status;                                     //!< Indicates one of the flags in NV_GPU_TOPOLOGY_STATUS_FLAGS
} NV_GPU_TOPOLOGY;



//! Macro for constructingteh version field of NV_GPU_TOPOLOGY
#define NV_GPU_TOPOLOGY_VER  MAKE_NVAPI_VERSION(NV_GPU_TOPOLOGY,2)


typedef struct
{
    NvU32                   version;                                    //!< Structure version
    NvU64                   topologyMask;                               //!< Mask of indexes in gpuTopo
    NvU32                   flags;                                      //!< One or more SLI group flags from NV_GPU_SLI_GROUP_FLAGS
} NV_SLI_GROUP;


//! Macro for constucting the version field of NV_SLI_GROUP
#define NV_GPU_SLI_GROUP_VER  MAKE_NVAPI_VERSION(NV_SLI_GROUP,1)


//! First version of NV_GPU_TOPOLOGIES
typedef struct
{
    NvU32                   version;                                    //!< Structure version
    NvU32                   gpuTopoCount;                               //!< Count of valid topologies
    NV_GPU_TOPOLOGY_V1      gpuTopo[NVAPI_MAX_AVAILABLE_GPU_TOPOLOGIES];//!< Maximum number of GPU topologies
} NV_GPU_TOPOLOGIES_V1;


//! Macro for constructing the version field of NV_GPU_TOPOLOGIES_V1
#define NV_GPU_TOPOLOGIES_VER_1  MAKE_NVAPI_VERSION(NV_GPU_TOPOLOGIES_V1,1)


//! Second version of NV_GPU_TOPOLOGIES
typedef struct
{
    NvU32                   version;                                    //!< Structure version
    NvU32                   gpuTopoCount;                               //!< Count of valid topologies
    NV_GPU_TOPOLOGY_V1      gpuTopo[NVAPI_MAX_AVAILABLE_GPU_TOPOLOGIES];//!< Maximum gputopologies
    NvU32                   sliGroupCount;                              //!< Count of valid SLI groups
    NV_SLI_GROUP            sliGroup[NVAPI_MAX_AVAILABLE_SLI_GROUPS];   //!< Maximum SLI groups
} NV_GPU_TOPOLOGIES_V2;

//! Macro for constructing the version field of NV_GPU_TOPOLOGIES_V2
#define NV_GPU_TOPOLOGIES_VER_2  MAKE_NVAPI_VERSION(NV_GPU_TOPOLOGIES_V2,2)




//! Used in NvAPI_GetValidGpuTopologies() and NvAPI_SetGpuTopologies()
typedef struct 
{
    NvU32                   version;                                    //!< Structure version
    NvU32                   gpuTopoCount;                               //!< Count of valid topologies
    NV_GPU_TOPOLOGY         gpuTopo[NVAPI_MAX_AVAILABLE_GPU_TOPOLOGIES];//!< Maximum number of GPU topologies
    NvU32                   sliGroupCount;                              //!< Count of valid SLI groups
    NV_SLI_GROUP            sliGroup[NVAPI_MAX_AVAILABLE_SLI_GROUPS];   //!< Maximum number of SLI groups
} NV_GPU_TOPOLOGIES;

//! Macro for constructing the version field of NV_GPU_TOPOLOGIES
#define NV_GPU_TOPOLOGIES_VER  MAKE_NVAPI_VERSION(NV_GPU_TOPOLOGIES,3)

#define NV_GPU_VALID_GPU_TOPOLOGIES NV_GPU_TOPOLOGIES
#define NV_GPU_INVALID_GPU_TOPOLOGIES NV_GPU_TOPOLOGIES
#define NV_GPU_VALID_GPU_TOPOLOGIES_VER  NV_GPU_TOPOLOGIES_VER
#define NV_GPU_INVALID_GPU_TOPOLOGIES_VER  NV_GPU_TOPOLOGIES_VER
#define NV_GPU_VALID_GPU_TOPOLOGIES_V1 NV_GPU_TOPOLOGIES_V1
#define NV_GPU_INVALID_GPU_TOPOLOGIES_V1 NV_GPU_TOPOLOGIES_V1
#define NV_GPU_VALID_GPU_TOPOLOGIES_VER_1  NV_GPU_TOPOLOGIES_VER_1
#define NV_GPU_INVALID_GPU_TOPOLOGIES_VER_1  NV_GPU_TOPOLOGIES_VER_1
#define NV_GPU_VALID_GPU_TOPOLOGIES_V2 NV_GPU_TOPOLOGIES_V2
#define NV_GPU_INVALID_GPU_TOPOLOGIES_V2 NV_GPU_TOPOLOGIES_V2
#define NV_GPU_VALID_GPU_TOPOLOGIES_VER_2  NV_GPU_TOPOLOGIES_VER_2
#define NV_GPU_INVALID_GPU_TOPOLOGIES_VER_2  NV_GPU_TOPOLOGIES_VER_2


//! @}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GetValidGpuTopologies
//
//!  This function returns all valid GPU topologies that can be used to configure the physical GPUs 
//!  using the NvAPI_SetGpuTopologies API. It also returns the current active topologies.
//! 
//!  This call returns an array of NV_GPU_TOPOLOGY structs; one for each valid configuration 
//!  of GPUs present in the system.  Note that this list is constant as long as GPUs remain in the 
//!  same slots in the system.  It is not affected by which GPUs are presently in use.
//!  NV_GPU_TOPOLOGY.displayGpuIndex returned will match the boot GPU if it exists as an active topology.  
//!  If it not an active topology, it points to the "first" GPU that has a display monitor connected.
//!
//!  This call also returns an array of NV_SLI_GROUP, describing the list of topology combinations 
//!  that can be enabled at the same time.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 87.80
//!
//! \param [out]      ptopology  An array of *pCount (OUT) topology structures. Use NvAPI_SetGpuTopologies() to set up
//!                              one or several of these GPU topologies.
//! \param [out]      sliGroup   An array of *sliGroupCount (OUT) SLI goup structures, describing which topologies
//!                              can be set up concurrently.
//! \param [out]      pStatus    Any system status returned in case zero topology is retrieved.
//!                              System status is one or more flags in ::NV_GPU_TOPOLOGY_STATUS_FLAGS when SLI is NOT capable.
//!
//! \retval    ::NVAPI_OK                       Call succeeded; one or more GPU topologies were returned.
//! \retval    ::NVAPI_INVALID_ARGUMENT         One or more arguments are invalid.
//! \retval    ::NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found.
//! \retval    ::NVAPI_ERROR                    Miscellaneous Error.
//!
//! \ingroup    gputopology
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetValidGpuTopologies(NV_GPU_VALID_GPU_TOPOLOGIES *pTopology, NvU32 *pStatus);



///////////////////////////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GetInvalidGpuTopologies
//
//! DESCRIPTION:     This API returns all invalid GPU topologies and the current active topologies.
//!                  This call returns an array of NV_GPU_TOPOLOGY structs; one for each invalid configuration 
//!                  of GPUs present in the system. Note that this list is constant while GPUs remain in the 
//!                  same slots in the system.  It is not affected by which GPUs that are presently in use.
//!
//!                  The topologies with the status ::NV_GPU_TOPOLOGY_STATUS_TOPOLOGY_NOT_ALLOWED are valid for
//!                  the system but not for productization.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 167.00
//!
//!
//! \param [out]    ptopology      An array of *pCount (OUT) topology structures.
//! \param [out]    sliGroup       No SLI groups returned here.
//! \param [out]    sliGroupCount  *sliGroupCount = 0.
//!
//! \retval         NVAPI_OK                       Call succeeded; one or more GPU topologies were returned.
//! \retval         NVAPI_INVALID_ARGUMENT         One or more arguments are invalid.
//! \retval         NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found.
//! \retval         NVAPI_ERROR                    Miscellaneous Error.
//!
//! \ingroup gputopology
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetInvalidGpuTopologies(NV_GPU_INVALID_GPU_TOPOLOGIES *pTopology);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_SetGpuTopologies
//
//! This function configures the physical GPUs in the system into one or more logical devices
//!                  defined by the NV_GPU_TOPOLOGY structure. After successful execution of this call, the caller needs to enumerate  
//!                  all the GPU handles again.
//!
//! It is recommended that the calling application:
//!                  - Save the current GPU topology retrieved from NvAPI_EnumLogicalGPUs and NvAPI_GetPhysicalGPUsFromLogicalGPU APIs.
//!                  - Save the current view state for associated displays on these GPUs using the GetView and GetDisplayTargets APIs.
//!                  - Set NV_GPU_TOPOLOGY.displayGpuIndex to the GPU index in the topology with an active display connection.
//!                  - If DEFER_3D_APP_SHUTDOWN is not set, notify the user that all 3D application will be forced to close.
//!                  - Itself does not create 3D handles or objects that can block the topology transition.
//!
//! On Windows Vista:
//!                  - The calling application must run in elevated mode for the transition to succeed. 
//!                  - This API can be called from a system service to derive the elevated context of the System service.
//! 
//! - Running non-migratable applications can prevent a successful transition if DEFER_3D_APP_SHUTDOWN is set. 
//! - To query non-migratable applications, use the NvAPI_QueryNonMigratableApps() API.
//!
//! - When enabling more than one multi-GPU topology, set the NV_GPU_TOPOLOGY_SLI_GROUPS flag.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 87.80
//!
//! \param [in]  pTopology     a pointer to the NV_GPU_VALID_GPU_TOPOLOGIES structure defining the desired GPU topologies to be set.
//!                                  The set of possible GPU topologies can be first queried using NvAPI_GetValidGpuTopologies.
//! \param [in]  flags         \see NV_SET_GPU_TOPOLOGY_FLAGS
//!
//! \return      This API can return any of the error codes enumerated in #NvAPI_Status. If there are return error codes with 
//!              specific meaning for this API, they are listed below.
//! 
//! \retval      NVAPI_TIMEOUT_RECONFIGURING_GPU_TOPO  Timeout occurred while reconfiguring GPUs.
//! \retval      NVAPI_IMPLICIT_SET_GPU_TOPOLOGY_CHANGE_NOT_ALLOWED   There is any implicit GPU topology active. Use NVAPI_SetHybridMode() to change the topology.
//! \retval      NVAPI_REQUEST_USER_TO_CLOSE_NON_MIGRATABLE_APPS Prompt the user to close all non-migratable applications.
//!
//! \ingroup     gputopology
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetGpuTopologies(NV_GPU_VALID_GPU_TOPOLOGIES *pTopology, NvU32 flags);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:  NvAPI_GPU_GetPerGpuTopologyStatus
//
//! This function returns per-GPU topology state flags from NV_GPU_TOPOLOGY_STATUS_FLAGS for the queried GPU handle.
//!  \note The per-GPU topology status can be queried independent of the whether the queried GPU is part of a topology or not.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.30
//!
//! \param [out]  hPhysicalGPU    GPU selection.
//! \param [out]  pStatus         Indicates one or more flags from NV_GPU_TOPOLOGY_STATUS_FLAGS which are the subset of the 
//!                               same flags retrieved from NV_GPU_TOPOLOGY.status or pStatus in NvAPI_GetValidGpuTopologies() API.
//!
//! \retval    NVAPI_OK                            Completed request
//! \retval    NVAPI_ERROR                         Miscellaneous error occurred
//! \retval    NVAPI_HANDLE_INVALIDATED            Handle passed has been invalidated (see user guide)
//! \retval    NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle
//! \ingroup gputopology
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPerGpuTopologyStatus(NvPhysicalGpuHandle hPhysicalGpu, NvU32 *pStatus);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_SYS_GetChipSetTopologyStatus
//
//!  This function returns topology state flags from NV_GPU_TOPOLOGY_STATUS_FLAGS possible with the System ChipSet.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.60 
//!
//! \param [out] pStatus  Indicates one or more flags from NV_GPU_TOPOLOGY_STATUS_FLAGS which are the subset of the 
//!                       same flags retrieved from NV_GPU_TOPOLOGY.status or pStatus in NvAPI_GetValidGpuTopologies() API.
//!  
//! \retval  NVAPI_OK     Completed request
//! \retval  NVAPI_ERROR  Miscellaneous error occurred
//! \ingroup gputopology
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SYS_GetChipSetTopologyStatus(NvU32 *pStatus);





//! \ingroup gpu
//! Used in NvAPI_GPU_Get_DisplayPort_DongleInfo().
typedef struct
{
    NvU32      version;        //!< Structure version
    struct{
        NvU32   displayMask;  //!< This field name should be outputid and will have only one bit set.
    } input;
    struct{
        NvU32   isDP2DVI:1;
        NvU32   isDP2HDMI:1;
        NvU32   reserved : 30;
    } output;

} NV_NVAPI_GET_DP_DONGLE_INFO;

//! \ingroup gpu
//! Macro for constructing the version field of NV_NVAPI_GET_DP_DONGLE_INFO
#define NV_NVAPI_GET_DP_DONGLE_INFO_VER  MAKE_NVAPI_VERSION(NV_NVAPI_GET_DP_DONGLE_INFO,1)


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_Get_DisplayPort_DongleInfo
//
//! DESCRIPTION: This API gets DisplayPort dongle information, such as DP2DVI or DP2HDMI. 
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 182.42
//! 
//! \param [in]     hPhysicalGPU   GPU selection.
//! \param [in,out] pDongleInfo    Data input/output structure
//!            
//! \retval ::NVAPI_OK                            Completed request
//! \retval ::NVAPI_ERROR                         Miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT              One or more args are invalid
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_Get_DisplayPort_DongleInfo(NvPhysicalGpuHandle hPhysicalGpu, NV_NVAPI_GET_DP_DONGLE_INFO *pDongleInfo);




///////////////////////////////////////////////////////////////////////////////////
//  I2C API
//  Provides ability to read or write data using I2C protocol.
//  These APIs allow I2C access only to DDC monitors


//! \addtogroup i2capi
//! @{
#define NVAPI_MAX_SIZEOF_I2C_DATA_BUFFER 4096
#define NVAPI_MAX_SIZEOF_I2C_REG_ADDRESS 4
#define NVAPI_DISPLAY_DEVICE_MASK_MAX 24

//! Used in NvAPI_I2CRead() and NvAPI_I2CWrite()
typedef struct 
{
    NvU32                   version;            //!< The structure version.
    NvU32                   displayMask;        //!< The Display Mask of the concerned display.
    NvU8                    bIsDDCPort;         //!< This flag indicates either the DDC port (TRUE) or the communication port
                                                //!< (FALSE) of the concerned display.
    NvU8                    i2cDevAddress;      //!< The address of the I2C slave.  The address should be shifted left by one.  For
                                                //!< example, the I2C address 0x50, often used for reading EDIDs, would be stored
                                                //!< here as 0xA0.  This matches the position within the byte sent by the master, as
                                                //!< the last bit is reserved to specify the read or write direction.
    NvU8*                   pbI2cRegAddress;    //!< The I2C target register address.  May be NULL, which indicates no register
                                                //!< address should be sent.
    NvU32                   regAddrSize;        //!< The size in bytes of target register address.  If pbI2cRegAddress is NULL, this
                                                //!< field must be 0.
    NvU8*                   pbData;             //!< The buffer of data which is to be read or written (depending on the command).
    NvU32                   cbSize;             //!< The size of the data buffer, pbData, to be read or written.
    NvU32                   i2cSpeed;           //!< The target speed of the transaction (between 28kbps to 40kbps; not guaranteed).
} NV_I2C_INFO;

#define NV_I2C_INFO_VER  MAKE_NVAPI_VERSION(NV_I2C_INFO,1)
//! @}

/***********************************************************************************/


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:  NvAPI_I2CRead
//
//!  This function reads the data buffer from the I2C port.
//!                 The I2C request must be for a DDC port: pI2cInfo->bIsDDCPort = 1.
//!
//!                 A data buffer size larger than 16 bytes may be rejected if a register address is specified.  In such a case,
//!                 NVAPI_ARGUMENT_EXCEED_MAX_SIZE would be returned.
//!
//!                 If a register address is specified (i.e. regAddrSize is positive), then the transaction will be performed in
//!                 the combined format described in the I2C specification.  The register address will be written, followed by
//!                 reading into the data buffer.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 87.90
//!
//! \param [in]   hPhysicalGPU     GPU selection.
//! \param [out]  NV_I2C_INFO     *pI2cInfo The I2C data input structure
//!
//! \retval   NVAPI_OK                            Completed request
//! \retval   NVAPI_ERROR                         Miscellaneous error occurred.
//! \retval   NVAPI_HANDLE_INVALIDATED            Handle passed has been invalidated (see user guide).
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle.
//! \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION   Structure version is not supported.
//! \retval   NVAPI_INVALID_ARGUMENT - argument does not meet specified requirements
//! \retval   NVAPI_ARGUMENT_EXCEED_MAX_SIZE - an argument exceeds the maximum 
//!
//! \ingroup i2capi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_I2CRead(NvPhysicalGpuHandle hPhysicalGpu, NV_I2C_INFO *pI2cInfo);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:  NvAPI_I2CWrite
//
//!  This function writes the data buffer to the I2C port.
//!
//!                 The I2C request must be for a DDC port: pI2cInfo->bIsDDCPort = 1.
//!
//!                 A data buffer size larger than 16 bytes may be rejected if a register address is specified.  In such a case,
//!                 NVAPI_ARGUMENT_EXCEED_MAX_SIZE would be returned.
//!
//!                 If a register address is specified (i.e. regAddrSize is positive), then the register address will be written
//!                 and the data buffer will immediately follow without a restart.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 87.90
//!
//! \param [in]   hPhysicalGPU     GPU selection.
//! \param [in]   pI2cInfo         The I2C data input structure
//!
//! \retval   NVAPI_OK                            Completed request
//! \retval   NVAPI_ERROR                         Miscellaneous error occurred.
//! \retval   NVAPI_HANDLE_INVALIDATED            Handle passed has been invalidated (see user guide).
//! \retval   NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle.
//! \retval   NVAPI_INCOMPATIBLE_STRUCT_VERSION    Structure version is not supported.
//! \retval   NVAPI_INVALID_ARGUMENT              Argument does not meet specified requirements
//! \retval   NVAPI_ARGUMENT_EXCEED_MAX_SIZE      Argument exceeds the maximum 
//!
//! \ingroup i2capi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_I2CWrite(NvPhysicalGpuHandle hPhysicalGpu, NV_I2C_INFO *pI2cInfo);


//! \addtogroup i2capi
//! @{
#define NVAPI_I2C_FLAGS_PRIVILEGE           0x1 //!< Used in NV_I2C_INFO_EX.
#define NVAPI_I2C_FLAGS_DATA_ENCRYPTED      0x2 //!< Encrypted I2C has been deprecated. 
#define NVAPI_I2C_FLAGS_NONSTD_SI1930UC     0x4 //!< Used in NV_I2C_INFO_EX.
#define NVAPI_I2C_FLAGS_PX3540              0x10 //!< Used in NV_I2C_INFO_EX.
//! @}


//! \ingroup i2capi
//! Used in NvAPI_I2CWriteEx() and NvAPI_I2CReadEx().
typedef struct 
{
    NvU32                   flags;        //!< I2C flags for Privileged, encrypted and non-standard Si1930uC i2c access
    NvU32                   encrClientID; //!< Client ID for Encrypted I2C (unused)
} NV_I2C_INFO_EX;

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:  NvAPI_I2CWriteEx
//
//! DESCRIPTION:   This function writes the data buffer to the I2C port. \n
//!                 Pass displayMask as zero, if I2C access is required for non-display devices.
//!
//!                 A data buffer size larger than 16 bytes may be rejected if a register address is specified.  In such a case,
//!                 NVAPI_ARGUMENT_EXCEED_MAX_SIZE would be returned.
//!
//!                 If a register address is specified (i.e. regAddrSize is positive), then the register address will be written
//!                 and the data buffer will immediately follow without a restart.
//!
//!                 If a DDC port is passed (bIsDDCPort = 1), then displayMask is a required parameter.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 171.08
//!
//! \param [in]  hPhysicalGPU                  GPU selection
//! \param       NV_I2C_INFO     *pI2cInfo     The I2C data input structure
//! \param       NV_I2C_INFO_EX  *pI2cInfoEx   The I2C extended data input structure
//!
//! \retval      NVAPI_OK                           Completed request
//! \retval      NVAPI_ERROR                        Miscellaneous error occurred
//! \retval      NVAPI_HANDLE_INVALIDATED           Handle passed has been invalidated (see user guide)
//! \retval      NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE Handle passed is not a physical GPU handle
//! \retval      NVAPI_INCOMPATIBLE_STRUCT_VERSION  Structure version is not supported
//! \retval      NVAPI_INVALID_ARGUMENT             Argument does not meet specified requirements
//! \retval      NVAPI_ARGUMENT_EXCEED_MAX_SIZE     Argument exceeds the maximum 
//!
//! \ingroup i2capi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_I2CWriteEx(NvPhysicalGpuHandle hPhysicalGpu, NV_I2C_INFO *pI2cInfo, NV_I2C_INFO_EX *pI2cInfoEx);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:  NvAPI_I2CReadEx
//
//! DESCRIPTION:   This function reads the data buffer from the I2C port.
//!                 Please pass displayMask as zero, if I2C access required for non-display devices.
//!
//!                 A data buffer size larger than 16 bytes may be rejected if a register address is specified.  In such a case,
//!                 NVAPI_ARGUMENT_EXCEED_MAX_SIZE would be returned.
//!
//!                 If a register address is specified (i.e. regAddrSize is positive), then the transaction will be performed in
//!                 the combined format described in the I2C specification.  The register address will be written, followed by
//!                 reading into the data buffer.
//!
//!                 If a DDC port is passed (bIsDDCPort = 1), then displayMask is a required parameter.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 171.08
//!
//! \param [in] hPhysicalGPU                 GPU selection.
//! \param      NV_I2C_INFO     *pI2cInfo    The I2C data input structure
//! \param      NV_I2C_INFO_EX  *pI2cInfoEx  The I2C extended data input structure
//!
//! \retval    NVAPI_OK                            Completed request
//! \retval    NVAPI_ERROR                         Miscellaneous error occurred
//! \retval    NVAPI_HANDLE_INVALIDATED            Handle passed has been invalidated (see user guide)
//! \retval    NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  Handle passed is not a physical GPU handle
//! \retval    NVAPI_INCOMPATIBLE_STRUCT_VERSION   Structure version is not supported
//! \retval    NVAPI_INVALID_ARGUMENT              Argument does not meet specified requirements
//! \retval    NVAPI_ARGUMENT_EXCEED_MAX_SIZE      An argument exceeds the maximum 
//!
//! \ingroup i2capi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_I2CReadEx(NvPhysicalGpuHandle hPhysicalGpu, NV_I2C_INFO *pI2cInfo, NV_I2C_INFO_EX *pI2cInfoEx);

///////////////////////////////////////////////////////////////////////////////
// POWERMIZER APIs
//
// Provides the ability to Limit PowerMizer's Maximum Performance.
// Grants access on Adaptive Clocking turn on and off.
// PowerMizer can be either Soft Limited or Hard Limited.
// Soft Limit can be exceeded by the adaptive systems in the GPU if there is a need.
// Hard Limit cannot be exceeded even if there is a need to exceed this limit.
//
//////////////////////////////////////////////////////////////////////////////

//! \ingroup powermizerapi
//! Used in NvAPI_GPU_GetPowerMizerInfo() and NvAPI_GPU_GetPowerMizerInfo()
typedef enum _NV_LEVEL_INFO
{
    NVAPI_PWR_MZR_HARD_LIMIT_MAX           = 0x00000001,       //!< Power Mizer Maximum Performance for Hard limit
    NVAPI_PWR_MZR_HARD_LIMIT_BAL           = 0x00000002,       //!< Power Mizer Balanced Performance for Hard limit
    NVAPI_PWR_MZR_MAX_BATT                 = 0x00000003,       //!< Power Mizer Maximum Battery Performance
    NVAPI_PWR_MZR_SOFT_LIMIT_MAX           = 0x00000004,       //!< Power mizer Maximum performance for Soft limit
    NVAPI_PWR_MZR_SOFT_LIMIT_BAL           = 0x00000005,       //!< Power mizer Balanced performance for Soft limit
    NVAPI_ADC_OFF                          = 0x00000006,       //!< Adaptive Clocking Disable
    NVAPI_ADC_ON                           = 0x00000007,       //!< Adaptive Clocking Enable
} NV_LEVEL_INFO;


//! \ingroup powermizerapi
//! Used in NvAPI_GPU_GetPowerMizerInfo() and NvAPI_GPU_GetPowerMizerInfo()
typedef enum _NV_PWR_SOURCE_INFO
{
    NVAPI_PWR_SOURCE_AC                                 = 0x00000001,       //!<  Power source AC
    NVAPI_PWR_SOURCE_BATT                               = 0x00000002,       //!<  Power source Battery
} NV_PWR_SOURCE_INFO;

//! \ingroup powermizerapi
//! Used in NvAPI_GPU_GetPowerMizerInfo() and NvAPI_GPU_GetPowerMizerInfo()
typedef enum _NV_SELECT_INFO
{
    NVAPI_INDEX_PWR_MZR_HARD                            = 0x00000001,       //!<  To set/get PowerMizer Hard limits. Hard Limits modifies the hardware limits. 
    NVAPI_INDEX_PWR_MZR_SOFT                            = 0x00000002,       //!<  To set/get PowerMizer Soft limits. Soft Limits sets the application preference and could be exceeded upto Hard limits if required by the system.
    NVAPI_INDEX_ADC                                     = 0x00000003,       //!<  To set/get Adaptive Clocking parameters where the driver automatically selects the limits. 
} NV_SELECT_INFO;


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:    NvAPI_GPU_GetPowerMizerInfo
//
//!  This function gets 
//!              - the PowerMizer Maximum Limit for both Battery or AC 
//!              - the Adaptive Clocking status for Battery or AC 
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 100.60
//!
//! \param [in]  hPhysicalGPU         GPU selection.
//! \param [in]  powerSourceInfo      Power source selection with one of the values from ::NV_PWR_SOURCE_INFO.
//! \param [in]  select               PowerMizer type selection with one of the values from ::NV_SELECT_INFO.
//! \param [out] pLevelInfo           Pointer to return value 
//!
//!  
//! \retval  NVAPI_OK                 Completed request
//! \retval  NVAPI_NOT_SUPPORTED      Power Mizer Not supported.
//! \retval  NVAPI_ERROR              Invalid return to API.
//! \ingroup powermizerapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPowerMizerInfo(NvPhysicalGpuHandle hPhysicalGpu, NV_PWR_SOURCE_INFO powerSourceInfo,
                                          NV_SELECT_INFO select, NV_LEVEL_INFO *pLevelInfo);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:    NvAPI_GPU_SetPowerMizerInfo
//
//!  This function sets 
//!              - the PowerMizer Maximum Limit for both Battery and/or AC 
//!              - the Adaptive Clocking status for Battery or AC  
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 100.60
//!
//! \param [in]  hPhysicalGpu              GPU selection.
//! \param [in]  powerSourceInfo           Power source selection with one of the values from ::NV_PWR_SOURCE_INFO.
//! \param [in]  select                    PowerMizer type selection with one of the values from ::NV_SELECT_INFO.
//! \param [out] levelInfo                 Level that has to be set on PwrMzr /Adaptive clocking 
//!
//! \retval      NVAPI_OK                  Completed request
//! \retval      NVAPI_NOT_SUPPORTED       PowerMizer not supported
//! \retval      NVAPI_INVALID_ARGUMENT    Invalid arguments
//!
//! \ingroup     powermizerapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetPowerMizerInfo(NvPhysicalGpuHandle hPhysicalGpu, NV_PWR_SOURCE_INFO powerSourceInfo, 
                                            NV_SELECT_INFO select, NV_LEVEL_INFO levelInfo);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_WorkstationFeatureSetup
//
//! \fn NvAPI_GPU_WorkstationFeatureSetup(NvPhysicalGpuHandle hPhysicalGpu, NvU32 featureEnableMask, NvU32 featureDisableMask)
//!   DESCRIPTION: This API configures the driver for a set of workstation features.
//!                The driver can allocate the memory resources accordingly.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   hPhysicalGpu       Physical GPU Handle of the display adapter to be configured. GPU handles may be retrieved
//!                                  with NvAPI_EnumPhysicalGPUs
//! \param [in]   featureEnableMask  Mask of features the caller requests to enable for use
//! \param [in]   featureDisableMask Mask of features the caller requests to disable 
//!
//!                As a general rule, features in the enable and disable masks are expected to be disjoint, although the disable 
//!                mask has precedence and a feature flagged in both masks will be disabled.
//!
//! \retval ::NVAPI_OK                            configuration request succeeded
//! \retval ::NVAPI_ERROR                         configuration request failed
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  hPhysicalGpu was not a physical GPU handle.
//! \retval ::NVAPI_NO_IMPLEMENTATION             only implemented for Win7+
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup gpu 
typedef enum
{
    NVAPI_GPU_WORKSTATION_FEATURE_MASK_SWAPGROUP     = 0x00000001,
    NVAPI_GPU_WORKSTATION_FEATURE_MASK_STEREO        = 0x00000010,
    NVAPI_GPU_WORKSTATION_FEATURE_MASK_WARPING       = 0x00000100,
    NVAPI_GPU_WORKSTATION_FEATURE_MASK_PIXINTENSITY  = 0x00000200,
    NVAPI_GPU_WORKSTATION_FEATURE_MASK_GRAYSCALE     = 0x00000400,
    NVAPI_GPU_WORKSTATION_FEATURE_MASK_BPC10         = 0x00001000
} NVAPI_GPU_WORKSTATION_FEATURE_MASK;

//! \ingroup gpu
NVAPI_INTERFACE NvAPI_GPU_WorkstationFeatureSetup(NvPhysicalGpuHandle hPhysicalGpu, NvU32 featureEnableMask, NvU32 featureDisableMask);





//! \addtogroup sysgeneral
//! @{

typedef struct
{
    NvU32               version;            //!< structure version
    NvU32               vendorId;           //!< Chipset vendor identification
    NvU32               deviceId;           //!< Chipset device identification
    NvAPI_ShortString   szVendorName;       //!< Chipset vendor Name
    NvAPI_ShortString   szChipsetName;      //!< Chipset device Name
    NvU32               flags;              //!< Chipset info flags - obsolete
    NvU32               subSysVendorId;     //!< Chipset subsystem vendor identification
    NvU32               subSysDeviceId;     //!< Chipset subsystem device identification 
    NvAPI_ShortString   szSubSysVendorName; //!< subsystem vendor Name
    NvU32               HBvendorId;         //!< Host bridge vendor identification
    NvU32               HBdeviceId;         //!< Host bridge device identification
    NvU32               HBsubSysVendorId;   //!< Host bridge subsystem vendor identification
    NvU32               HBsubSysDeviceId;   //!< Host bridge subsystem device identification

} NV_CHIPSET_INFO_v4;

typedef struct
{
    NvU32               version;            //!< structure version
    NvU32               vendorId;           //!< vendor ID
    NvU32               deviceId;           //!< device ID
    NvAPI_ShortString   szVendorName;       //!< vendor Name
    NvAPI_ShortString   szChipsetName;      //!< device Name
    NvU32               flags;              //!< Chipset info flags - obsolete
    NvU32               subSysVendorId;     //!< subsystem vendor ID
    NvU32               subSysDeviceId;     //!< subsystem device ID
    NvAPI_ShortString   szSubSysVendorName; //!< subsystem vendor Name
} NV_CHIPSET_INFO_v3;

typedef enum
{
    NV_CHIPSET_INFO_HYBRID          = 0x00000001,
} NV_CHIPSET_INFO_FLAGS;

typedef struct
{
    NvU32               version;        //!< structure version
    NvU32               vendorId;       //!< vendor ID
    NvU32               deviceId;       //!< device ID
    NvAPI_ShortString   szVendorName;   //!< vendor Name
    NvAPI_ShortString   szChipsetName;  //!< device Name
    NvU32               flags;          //!< Chipset info flags
} NV_CHIPSET_INFO_v2;

typedef struct
{
    NvU32               version;        //structure version
    NvU32               vendorId;       //vendor ID
    NvU32               deviceId;       //device ID
    NvAPI_ShortString   szVendorName;   //vendor Name
    NvAPI_ShortString   szChipsetName;  //device Name
} NV_CHIPSET_INFO_v1;

#define NV_CHIPSET_INFO_VER_1  MAKE_NVAPI_VERSION(NV_CHIPSET_INFO_v1,1)
#define NV_CHIPSET_INFO_VER_2   MAKE_NVAPI_VERSION(NV_CHIPSET_INFO_v2,2)
#define NV_CHIPSET_INFO_VER_3   MAKE_NVAPI_VERSION(NV_CHIPSET_INFO_v3,3)
#define NV_CHIPSET_INFO_VER_4   MAKE_NVAPI_VERSION(NV_CHIPSET_INFO_v4,4)

#define NV_CHIPSET_INFO         NV_CHIPSET_INFO_v4
#define NV_CHIPSET_INFO_VER     NV_CHIPSET_INFO_VER_4

//! @}




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_SYS_GetChipSetInfo
//
//!  This function returns information about the system's chipset.
//!
//  SUPPORTED OS: Mac OS X, Windows XP and higher
//!
//! \since Version: 96.60
//!
//! \retval  NVAPI_INVALID_ARGUMENT              pChipSetInfo is NULL.
//! \retval  NVAPI_OK                           *pChipSetInfo is now set.
//! \retval  NVAPI_INCOMPATIBLE_STRUCT_VERSION   NV_CHIPSET_INFO version not compatible with driver.
//! \ingroup sysgeneral
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SYS_GetChipSetInfo(NV_CHIPSET_INFO *pChipSetInfo);



//! \ingroup sysgeneral
//! Lid and dock information - used in NvAPI_GetLidDockInfo()
typedef struct 
{
    NvU32 version;    //! Structure version, constructed from the macro #NV_LID_DOCK_PARAMS_VER
    NvU32 currentLidState;
    NvU32 currentDockState;
    NvU32 currentLidPolicy;
    NvU32 currentDockPolicy;
    NvU32 forcedLidMechanismPresent;
    NvU32 forcedDockMechanismPresent;
}NV_LID_DOCK_PARAMS;


//! ingroup sysgeneral
#define NV_LID_DOCK_PARAMS_VER  MAKE_NVAPI_VERSION(NV_LID_DOCK_PARAMS,1)



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GetLidDockInfo
//
//! DESCRIPTION: This function returns the current lid and dock information.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 177.61
//!
//! \retval ::NVAPI_OK  
//! \retval ::NVAPI_ERROR
//! \retval ::NVAPI_NOT_SUPPORTED
//! \retval ::NVAPI_HANDLE_INVALIDATED
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//!
//! \ingroup sysgeneral
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SYS_GetLidAndDockInfo(NV_LID_DOCK_PARAMS *pLidAndDock);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_OGL_ExpertModeSet[Get]
//
//! \name NvAPI_OGL_ExpertModeSet[Get] Functions
//@{
//!  This function configures OpenGL Expert Mode, an API usage feedback and
//!  advice reporting mechanism. The effects of this call are
//!  applied only to the current context, and are reset to the
//!  defaults when the context is destroyed.
//!
//!  \note  This feature is valid at runtime only when GLExpert
//!         functionality has been built into the OpenGL driver
//!         installed on the system. All Windows Vista OpenGL
//!         drivers provided by NVIDIA have this instrumentation
//!         included by default. Windows XP, however, requires a
//!         special display driver available with the NVIDIA
//!         PerfSDK found at developer.nvidia.com.
//!
//!  \note These functions are valid only for the current OpenGL
//!        context. Calling these functions prior to creating a
//!        context and calling MakeCurrent with it will result
//!        in errors and undefined behavior.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 84.11 (Rel80) / 88.00 (Rel85)
//!
//! \param   expertDetailMask  Mask made up of NVAPI_OGLEXPERT_DETAIL bits,
//!                            this parameter specifies the detail level in
//!                            the feedback stream.
//!
//! \param   expertReportMask  Mask made up of NVAPI_OGLEXPERT_REPORT bits,
//!                            this parameter specifies the areas of
//!                            functional interest.
//!
//! \param   expertOutputMask  Mask made up of NVAPI_OGLEXPERT_OUTPUT bits,
//!                            this parameter specifies the feedback output
//!                            location.
//!
//! \param   expertCallback    Used in conjunction with OUTPUT_TO_CALLBACK,
//!                            this is a simple callback function the user
//!                            may use to obtain the feedback stream. The
//!                            function will be called once per fully
//!                            qualified feedback stream extry.
//!
//! \retval  NVAPI_API_NOT_INTIALIZED          NVAPI not initialized
//! \retval  NVAPI_NVIDIA_DEVICE_NOT_FOUND     No NVIDIA GPU found
//! \retval  NVAPI_OPENGL_CONTEXT_NOT_CURRENT  No NVIDIA OpenGL context
//!                                            which supports GLExpert
//!                                            has been made current
//! \retval  NVAPI_ERROR                       OpenGL driver failed to load properly
//! \retval  NVAPI_OK                          Success
//
///////////////////////////////////////////////////////////////////////////////

//! \addtogroup oglapi
//! @{
#define NVAPI_OGLEXPERT_DETAIL_NONE                 0x00000000
#define NVAPI_OGLEXPERT_DETAIL_ERROR                0x00000001
#define NVAPI_OGLEXPERT_DETAIL_SWFALLBACK           0x00000002
#define NVAPI_OGLEXPERT_DETAIL_BASIC_INFO           0x00000004
#define NVAPI_OGLEXPERT_DETAIL_DETAILED_INFO        0x00000008
#define NVAPI_OGLEXPERT_DETAIL_PERFORMANCE_WARNING  0x00000010
#define NVAPI_OGLEXPERT_DETAIL_QUALITY_WARNING      0x00000020
#define NVAPI_OGLEXPERT_DETAIL_USAGE_WARNING        0x00000040
#define NVAPI_OGLEXPERT_DETAIL_ALL                  0xFFFFFFFF

#define NVAPI_OGLEXPERT_REPORT_NONE                 0x00000000
#define NVAPI_OGLEXPERT_REPORT_ERROR                0x00000001
#define NVAPI_OGLEXPERT_REPORT_SWFALLBACK           0x00000002
#define NVAPI_OGLEXPERT_REPORT_PIPELINE_VERTEX      0x00000004
#define NVAPI_OGLEXPERT_REPORT_PIPELINE_GEOMETRY    0x00000008
#define NVAPI_OGLEXPERT_REPORT_PIPELINE_XFB         0x00000010
#define NVAPI_OGLEXPERT_REPORT_PIPELINE_RASTER      0x00000020
#define NVAPI_OGLEXPERT_REPORT_PIPELINE_FRAGMENT    0x00000040
#define NVAPI_OGLEXPERT_REPORT_PIPELINE_ROP         0x00000080
#define NVAPI_OGLEXPERT_REPORT_PIPELINE_FRAMEBUFFER 0x00000100
#define NVAPI_OGLEXPERT_REPORT_PIPELINE_PIXEL       0x00000200
#define NVAPI_OGLEXPERT_REPORT_PIPELINE_TEXTURE     0x00000400
#define NVAPI_OGLEXPERT_REPORT_OBJECT_BUFFEROBJECT  0x00000800
#define NVAPI_OGLEXPERT_REPORT_OBJECT_TEXTURE       0x00001000
#define NVAPI_OGLEXPERT_REPORT_OBJECT_PROGRAM       0x00002000
#define NVAPI_OGLEXPERT_REPORT_OBJECT_FBO           0x00004000
#define NVAPI_OGLEXPERT_REPORT_FEATURE_SLI          0x00008000
#define NVAPI_OGLEXPERT_REPORT_ALL                  0xFFFFFFFF


#define NVAPI_OGLEXPERT_OUTPUT_TO_NONE       0x00000000
#define NVAPI_OGLEXPERT_OUTPUT_TO_CONSOLE    0x00000001
#define NVAPI_OGLEXPERT_OUTPUT_TO_DEBUGGER   0x00000004
#define NVAPI_OGLEXPERT_OUTPUT_TO_CALLBACK   0x00000008
#define NVAPI_OGLEXPERT_OUTPUT_TO_ALL        0xFFFFFFFF

//! @}

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION TYPE: NVAPI_OGLEXPERT_CALLBACK
//
//!   DESCRIPTION: Used in conjunction with OUTPUT_TO_CALLBACK, this is a simple 
//!                callback function the user may use to obtain the feedback 
//!                stream. The function will be called once per fully qualified 
//!                feedback stream entry.
//!
//!   \param   categoryId    Contains the bit from the NVAPI_OGLEXPERT_REPORT 
//!                          mask that corresponds to the current message
//!   \param   messageId     Unique ID for the current message
//!   \param   detailLevel   Contains the bit from the NVAPI_OGLEXPERT_DETAIL
//!                          mask that corresponds to the current message
//!   \param   objectId      Unique ID of the object that corresponds to the
//!                          current message
//!   \param   messageStr    Text string from the current message
//!
//!   \ingroup oglapi
///////////////////////////////////////////////////////////////////////////////
typedef void (* NVAPI_OGLEXPERT_CALLBACK) (unsigned int categoryId, unsigned int messageId, unsigned int detailLevel, int objectId, const char *messageStr);



//! \ingroup oglapi
//  SUPPORTED OS: Windows XP and higher
NVAPI_INTERFACE NvAPI_OGL_ExpertModeSet(NvU32 expertDetailLevel,
                                        NvU32 expertReportMask,
                                        NvU32 expertOutputMask,
                     NVAPI_OGLEXPERT_CALLBACK expertCallback);

//! \addtogroup oglapi
//  SUPPORTED OS: Windows XP and higher
NVAPI_INTERFACE NvAPI_OGL_ExpertModeGet(NvU32 *pExpertDetailLevel,
                                        NvU32 *pExpertReportMask,
                                        NvU32 *pExpertOutputMask,
                     NVAPI_OGLEXPERT_CALLBACK *pExpertCallback);

//@}

///////////////////////////////////////////////////////////////////////////////
//
//! \name NvAPI_OGL_ExpertModeDefaultsSet[Get] Functions
//!
//@{
//!  This function configures OpenGL Expert Mode global defaults. These settings
//!  apply to any OpenGL application which starts up after these
//!  values are applied (i.e. these settings *do not* apply to
//!  currently running applications).
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 84.11 (Rel80) / 88.00 (Rel85)
//!
//! \param   expertDetailLevel Value which specifies the detail level in
//!                            the feedback stream. This is a mask made up
//!                            of NVAPI_OGLEXPERT_LEVEL bits.
//!
//! \param   expertReportMask  Mask made up of NVAPI_OGLEXPERT_REPORT bits,
//!                            this parameter specifies the areas of
//!                            functional interest.
//!
//! \param   expertOutputMask  Mask made up of NVAPI_OGLEXPERT_OUTPUT bits,
//!                            this parameter specifies the feedback output
//!                            location. Note that using OUTPUT_TO_CALLBACK
//!                            here is meaningless and has no effect, but
//!                            using it will not cause an error.
//!
//! \return  ::NVAPI_ERROR or ::NVAPI_OK
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup oglapi
//  SUPPORTED OS: Windows XP and higher
NVAPI_INTERFACE NvAPI_OGL_ExpertModeDefaultsSet(NvU32 expertDetailLevel,
                                                NvU32 expertReportMask,
                                                NvU32 expertOutputMask);

//! \addtogroup oglapi
//  SUPPORTED OS: Windows XP and higher
NVAPI_INTERFACE NvAPI_OGL_ExpertModeDefaultsGet(NvU32 *pExpertDetailLevel,
                                                NvU32 *pExpertReportMask,
                                                NvU32 *pExpertOutputMask);
//@}


//! \ingroup dispcontrol
//! @{
#define NVAPI_MAX_VIEW_TARGET  2
#define NVAPI_ADVANCED_MAX_VIEW_TARGET 4

#ifndef _NV_TARGET_VIEW_MODE_
#define _NV_TARGET_VIEW_MODE_

//! Used in NvAPI_SetView().
typedef enum _NV_TARGET_VIEW_MODE
{
    NV_VIEW_MODE_STANDARD  = 0,
    NV_VIEW_MODE_CLONE     = 1,
    NV_VIEW_MODE_HSPAN     = 2,
    NV_VIEW_MODE_VSPAN     = 3,
    NV_VIEW_MODE_DUALVIEW  = 4,
    NV_VIEW_MODE_MULTIVIEW = 5,
} NV_TARGET_VIEW_MODE;
#endif


//! @}



// Following definitions are used in NvAPI_SetViewEx.

//! Scaling modes - used in NvAPI_SetViewEx().
//! \ingroup dispcontrol
typedef enum _NV_SCALING
{
    NV_SCALING_DEFAULT          = 0,        //!< No change

    // New Scaling Declarations
    NV_SCALING_GPU_SCALING_TO_CLOSEST                   = 1,  //!< Balanced  - Full Screen
    NV_SCALING_GPU_SCALING_TO_NATIVE                    = 2,  //!< Force GPU - Full Screen
    NV_SCALING_GPU_SCANOUT_TO_NATIVE                    = 3,  //!< Force GPU - Centered\No Scaling
    NV_SCALING_GPU_SCALING_TO_ASPECT_SCANOUT_TO_NATIVE  = 5,  //!< Force GPU - Aspect Ratio
    NV_SCALING_GPU_SCALING_TO_ASPECT_SCANOUT_TO_CLOSEST = 6,  //!< Balanced  - Aspect Ratio
    NV_SCALING_GPU_SCANOUT_TO_CLOSEST                   = 7,  //!< Balanced  - Centered\No Scaling
    
    // Legacy Declarations
    NV_SCALING_MONITOR_SCALING                          = NV_SCALING_GPU_SCALING_TO_CLOSEST,
    NV_SCALING_ADAPTER_SCALING                          = NV_SCALING_GPU_SCALING_TO_NATIVE,
    NV_SCALING_CENTERED                                 = NV_SCALING_GPU_SCANOUT_TO_NATIVE,
    NV_SCALING_ASPECT_SCALING                           = NV_SCALING_GPU_SCALING_TO_ASPECT_SCANOUT_TO_NATIVE,

    NV_SCALING_CUSTOMIZED       = 255       //!< For future use
} NV_SCALING;

//! Rotate modes- used in NvAPI_SetViewEx().
//! \ingroup dispcontrol
typedef enum _NV_ROTATE
{
    NV_ROTATE_0           = 0,
    NV_ROTATE_90          = 1,
    NV_ROTATE_180         = 2,
    NV_ROTATE_270         = 3,
    NV_ROTATE_IGNORED     = 4,
} NV_ROTATE;

//! Color formats- used in NvAPI_SetViewEx().
//! \ingroup dispcontrol
#define NVFORMAT_MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
                         ((NvU32)(NvU8)(ch0) | ((NvU32)(NvU8)(ch1) << 8) |   \
                     ((NvU32)(NvU8)(ch2) << 16) | ((NvU32)(NvU8)(ch3) << 24 ))



//! Color formats- used in NvAPI_SetViewEx().
//! \ingroup dispcontrol
typedef enum _NV_FORMAT
{
    NV_FORMAT_UNKNOWN           =  0,       //!< unknown. Driver will choose one as following value.
    NV_FORMAT_P8                = 41,       //!< for 8bpp mode
    NV_FORMAT_R5G6B5            = 23,       //!< for 16bpp mode
    NV_FORMAT_A8R8G8B8          = 21,       //!< for 32bpp mode
    NV_FORMAT_A16B16G16R16F     = 113,      //!< for 64bpp(floating point) mode.

} NV_FORMAT;

// TV standard


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetDisplaySettings
///////////////////////////////////////////////////////////////////////////////


//! \ingroup dispcontrol
//! The connector is not supported yet; must be set to _AUTO
typedef enum _NV_CONNECTOR
{
    NV_CONN_AUTO = 0,
}NV_CONNECTOR;




//! \ingroup dispcontrol
//! The timing override is not supported yet; must be set to _AUTO. \n
//! Keep this in sync with NVL_TIMING_OVERRIDE from drivers/common/inc/nvlEscDef.h. \n
//! Used in NV_DISP_PATH .
typedef enum _NV_TIMING_OVERRIDE
{
    NV_TIMING_OVERRIDE_CURRENT = 0,          //!< get the current timing
    NV_TIMING_OVERRIDE_AUTO,                 //!< the timing the driver will use based the current policy
    NV_TIMING_OVERRIDE_EDID,                 //!< EDID timing
    NV_TIMING_OVERRIDE_DMT,                  //!< VESA DMT timing
    NV_TIMING_OVERRIDE_DMT_RB,               //!< VESA DMT timing with reduced blanking
    NV_TIMING_OVERRIDE_CVT,                  //!< VESA CVT timing
    NV_TIMING_OVERRIDE_CVT_RB,               //!< VESA CVT timing with reduced blanking
    NV_TIMING_OVERRIDE_GTF,                  //!< VESA GTF timing
    NV_TIMING_OVERRIDE_EIA861,               //!< EIA 861x pre-defined timing
    NV_TIMING_OVERRIDE_ANALOG_TV,            //!< analog SD/HDTV timing
    NV_TIMING_OVERRIDE_CUST,                 //!< NV custom timings
    NV_TIMING_OVERRIDE_NV_PREDEFINED,        //!< NV pre-defined timing (basically the PsF timings)
    NV_TIMING_OVERRIDE_NV_PSF                = NV_TIMING_OVERRIDE_NV_PREDEFINED,
    NV_TIMING_OVERRIDE_NV_ASPR,
    NV_TIMING_OVERRIDE_SDI,                  //!< Override for SDI timing

    NV_TIMING_OVRRIDE_MAX,                   
}NV_TIMING_OVERRIDE;



//! \ingroup dispcontrol
//! Used in NV_DISP_PATH .
typedef struct 
{
    float x;    //!<  x-coordinate of the viewport top-left point
    float y;    //!<  y-coordinate of the viewport top-left point
    float w;    //!<  Width of the viewport
    float h;    //!<  Height of the viewport
} NV_VIEWPORTF;




//***********************
// The Timing Structure
//***********************
//
//! \ingroup dispcontrol
//!  NVIDIA-specific timing extras \n
//! Used in NV_TIMING.
typedef struct tagNV_TIMINGEXT
{
    NvU32   flag;          //!< Reserved for NVIDIA hardware-based enhancement, such as double-scan.
    NvU16   rr;            //!< Logical refresh rate to present
    NvU32   rrx1k;         //!< Physical vertical refresh rate in 0.001Hz
    NvU32   aspect;        //!< Display aspect ratio Hi(aspect):horizontal-aspect, Low(aspect):vertical-aspect
    NvU16   rep;           //!< Bit-wise pixel repetition factor: 0x1:no pixel repetition; 0x2:each pixel repeats twice horizontally,..
    NvU32   status;        //!< Timing standard 
    NvU8    name[40];      //!< Timing name
}NV_TIMINGEXT;



//! \ingroup dispcontrol
//!The very basic timing structure based on the VESA standard:
//! \code
//!            |<----------------------------htotal--------------------------->| 
//!             ---------"active" video-------->|<-------blanking------>|<-----  
//!            |<-------hvisible-------->|<-hb->|<-hfp->|<-hsw->|<-hbp->|<-hb->| 
//! --------- -+-------------------------+      |       |       |       |      | 
//!   A      A |                         |      |       |       |       |      | 
//!   :      : |                         |      |       |       |       |      | 
//!   :      : |                         |      |       |       |       |      | 
//!   :vertical|    addressable video    |      |       |       |       |      | 
//!   : visible|                         |      |       |       |       |      | 
//!   :      : |                         |      |       |       |       |      | 
//!   :      : |                         |      |       |       |       |      | 
//! vertical V |                         |      |       |       |       |      | 
//!  total   --+-------------------------+      |       |       |       |      | 
//!   :      vb         border                  |       |       |       |      | 
//!   :      -----------------------------------+       |       |       |      |  
//!   :      vfp        front porch                     |       |       |      |  
//!   :      -------------------------------------------+       |       |      | 
//!   :      vsw        sync width                              |       |      | 
//!   :      ---------------------------------------------------+       |      | 
//!   :      vbp        back porch                                      |      | 
//!   :      -----------------------------------------------------------+      | 
//!   V      vb         border                                                 | 
//! ---------------------------------------------------------------------------+ 
//! \endcode
typedef struct tagNV_TIMING
{
    // VESA scan out timing parameters:
    NvU16 HVisible;         //!< horizontal visible 
    NvU16 HBorder;          //!< horizontal border 
    NvU16 HFrontPorch;      //!< horizontal front porch
    NvU16 HSyncWidth;       //!< horizontal sync width
    NvU16 HTotal;           //!< horizontal total
    NvU8  HSyncPol;         //!< horizontal sync polarity: 1-negative, 0-positive

    NvU16 VVisible;         //!< vertical visible
    NvU16 VBorder;          //!< vertical border
    NvU16 VFrontPorch;      //!< vertical front porch
    NvU16 VSyncWidth;       //!< vertical sync width
    NvU16 VTotal;           //!< vertical total
    NvU8  VSyncPol;         //!< vertical sync polarity: 1-negative, 0-positive
    
    NvU16 interlaced;       //!< 1-interlaced, 0-progressive
    NvU32 pclk;             //!< pixel clock in 10KHz

    //other timing related extras
    NV_TIMINGEXT etc;          
}NV_TIMING;


//! \addtogroup dispcontrol
//! Timing-related constants
//! @{
#define NV_TIMING_H_SYNC_POSITIVE                             0
#define NV_TIMING_H_SYNC_NEGATIVE                             1
#define NV_TIMING_H_SYNC_DEFAULT                              NV_TIMING_H_SYNC_NEGATIVE
//
#define NV_TIMING_V_SYNC_POSITIVE                             0
#define NV_TIMING_V_SYNC_NEGATIVE                             1
#define NV_TIMING_V_SYNC_DEFAULT                              NV_TIMING_V_SYNC_POSITIVE
//
#define NV_TIMING_PROGRESSIVE                                 0
#define NV_TIMING_INTERLACED                                  1
#define NV_TIMING_INTERLACED_EXTRA_VBLANK_ON_FIELD2           1
#define NV_TIMING_INTERLACED_NO_EXTRA_VBLANK_ON_FIELD2        2
//! @}


//! \ingroup dispcontrol
typedef enum _NVAPI_TIMING_TYPE
{
    NV_TIMING_TYPE_DMT = 1,                                 //!< DMT 
    NV_TIMING_TYPE_GTF,                                     //!< GTF
    NV_TIMING_TYPE_ASPR,                                    //!< wide aspect ratio timing, for legacy support only
    NV_TIMING_TYPE_NTSC_TV,                                 //!< NTSC TV timing. for legacy support only
    NV_TIMING_TYPE_PAL_TV,                                  //!< PAL TV timing, legacy support only
    NV_TIMING_TYPE_CVT,                                     //!< CVT timing
    NV_TIMING_TYPE_CVT_RB,                                  //!< CVT timing with reduced blanking
    NV_TIMING_TYPE_CUST,                                    //!< Customized timing
    NV_TIMING_TYPE_EDID_DTD,                                //!< EDID detailed timing
    NV_TIMING_TYPE_EDID_STD,                                //!< EDID standard timing
    NV_TIMING_TYPE_EDID_EST,                                //!< EDID established timing
    NV_TIMING_TYPE_EDID_CVT,                                //!< EDID defined CVT timing (EDID 1.4)
    NV_TIMING_TYPE_EDID_861ST,                              //!< EDID defined CEA/EIA 861 timing (in the EDID 861 extension)
    NV_TIMING_TYPE_NV_PREDEFINED,                           //!< NV pre-defined timings (PsF timings)
    NV_TIMING_TYPE_DMT_RB,                                  //!< DMT timing with reduced blanking
    NV_TIMING_TYPE_EDID_EXT_DTD,                            //!< EDID detailed timing in the extension
    NV_TIMING_TYPE_SDTV,                                    //!< SDTV timing (including NTSC, PAL etc)
    NV_TIMING_TYPE_HDTV,                                    //!< HDTV timing (480p,480i,720p, 1080i etc)
}NVAPI_TIMING_TYPE;





//! \ingroup dispcontrol
//! Config on the specified display is not supported yet.
#define NV_DISP_INDEX_AUTO 0



//! \ingroup dispcontrol
//! The generic display target configuration info, independent of any specific mode. \n
//! Used in NvAPI_SetDisplaySettings() and NvAPI_GetDisplaySettings()
typedef struct 
{
    NvU32                   version;    //!<  Structure version

    NvU32                   device;     //!<  Target display ID or target device mask 
    NV_GPU_CONNECTOR_TYPE   connector;

    NvU32                   srcID;        //!<  The source display index

    NvU32                   srcImportance;   //!< (OUT) Indicates if this is the GPU's primary view target. This is not the desktop GDI primary.
                                             //!< NvAPI_SetDisplaySettings automatically selects the first target in NV_DISP_PATH index 0 as the GPU's primary view.
    
    // the source mode information
    NvU32                   width;      
    NvU32                   height;
    NvU32                   depth;
    NV_ROTATE               rotation;
    NV_FORMAT               colorFormat;       //!< Color format. Not used now.
  
    // the section of the source surface for scan out, defined in normalized desktop coordinates
    NV_VIEWPORTF            srcPartition;      // not used now

    // the scan out viewport in (at the front end, i.e. the compositor/CRTC).
    // defined in the normalized desktop coordinates
    NV_VIEWPORTF            viewportIn ;       // not used now

    // the scaling mode
    NV_SCALING              scaling;
    
    // the scan out viewport out (at the front end, i.e. the compositor/CRTC). 
    // this is for the future arbitrary scaling support (not supported by any the current GPUs)
    // defined in the normalized raster/backend timing coordinates
    // viewportOut is not supported yet, must be set to {0.0, 0.0, 0.0, 0.0}
    NV_VIEWPORTF            viewportOut;       // not used now

    // the backend (raster) timing standard
    NV_TIMING_OVERRIDE      timingOverride; 

    NvU32                   refreshRate;        //!< only used for backward compatible when NV_DISP_PATH_VER1 is specified
    NvU32                   interlaced    :1;   //!< only used for backward compatible when NV_DISP_PATH_VER1 is specified
    NvU32                   hwModeSetOnly :1;   //!< if this flag is set, the modeset is a pure h/w modeset without OS update. Only used with NV_DISP_PATH_VER;
    NvU32                   SelectCustomTiming:1;    //!< For HD modes over DVI to select custom timings
    NvU32                   needNullModeset   :1;    //!< Read only - indicating a NULL modeset is needed on this monitor (for internal DP link training)
    NvU32                   need6x4Modeset    :1;    //!< Read only - indicating a 640x480x32 at 60Hz modeset is needed (for bad EDID on DP fallback)
    NvU32                   forceModeSet      :1;    //!< Used only on Win7 and higher during a call to NvAPI_SetDisplaySettings(). Turns off optimization & forces OS to set supplied mode.
    NvU32                   gpuId             :24;   //!< The display/target physical Gpu ID which is the owner of the scan out (for SLI multimon, display from the slave Gpu)
    NvU32                   isSliFocusDisplay :1;    //!< this display path is the sli focus (so far it's read only)
    NvU32                   forceModeEnum     :1;    //!< Used only on Windows7 and higher during a call to NvAPI_SetDisplaySettings(). Requests a modeset after forced mode enumeration.

    NV_DISPLAY_TV_FORMAT    tvFormat;           //!<  Valid only on TV device. Set to 0 for other devices.
    NV_TIMING               timing;             //!<  The scan out timing, NV_DISP_PATH_VER2 only, ignored it's on analog TV.
} NV_DISP_PATH_V1;

//! \ingroup dispcontrol
typedef struct
{
    NvU32                   version;    //!< Structure version

    NvU32                   device;     //!< target display ids or target device mask
    NV_GPU_CONNECTOR_TYPE   connector;

    // the source display index
    NvU32                   srcID;

    // the source importance
    NvU32                   srcImportance; //!<(OUT) Indicates if this is the GPU's primary view target. This is not the desktop GDI primary.
                                           //!<NvAPI_SetDisplaySettings automatically selects the first target in NV_DISP_PATH index 0 as the GPU's primary view.
    // the source mode information
    NvU32                   width;
    NvU32                   height;
    NvU32                   depth;
    NV_ROTATE               rotation;
    NV_FORMAT               colorFormat;       //!< Color format. Not used now.

    // the section of the source surface for scan out, defined in normalized desktop coordinates
    NV_VIEWPORTF            srcPartition;      //!< Not used now.

    // the scan out viewport in (at the front end, i.e. the compositor/CRTC).
    // defined in the normalized desktop coordinates
    NV_VIEWPORTF            viewportIn ;       //!< Not used now.


    // the scaling mode
    NV_SCALING              scaling;

    // the scan out viewport out (at the front end, i.e. the compositor/CRTC).
    // this is for the future arbitrary scaling support (not supported by any the current GPUs)
    // defined in the normalized raster/backend timing coordinates
    // viewportOut is not supported yet, must be set to {0.0, 0.0, 0.0, 0.0}
    NV_VIEWPORTF            viewportOut;       // not used now

    // the backend (raster) timing standard
    NV_TIMING_OVERRIDE      timingOverride;

    NvU32                   refreshRate;        //!< Only used for backward compatible when NV_DISP_PATH_VER1 is specified.
    NvU32                   interlaced    :1;   //!< Only used for backward compatible when NV_DISP_PATH_VER1 is specified.
    NvU32                   hwModeSetOnly :1;   //!< If this flag is set, the modeset is a pure h/w modeset without OS update. Only used with NV_DISP_PATH_VER.
    NvU32                   SelectCustomTiming:1;    //!< For HD modes over DVI to select custom timings.
    NvU32                   needNullModeset   :1;    //!< For read only - indicating a NULL modeset is needed on this monitor (for internal DP link training)
    NvU32                   need6x4Modeset    :1;    //!< For read only - indicating a 640x480x32bppx60Hz modeset is needed (for DP bad EDID fallback)
    NvU32                   forceModeSet      :1;    //!< Used only on Win7 and higher during a call to NvAPI_SetDisplaySettings. Turns off optimization & forces the OS to set supplied mode.
    NvU32                   gpuId             :24;   //!< The display/target physical GPU id which is the owner of the scan out (for SLI multimon, display from the slave GPU)
    NvU32                   isSliFocusDisplay :1;    //!< This display path is the SLI focus (so far it's read only).
    NvU32                   forceModeEnum     :1;    //!< Used only on Win7 and higher during a call to NvAPI_SetDisplaySettings. Requests a modeset after forced mode enumeration.

    NV_DISPLAY_TV_FORMAT    tvFormat;           //!< Valid only on TV device. set to 0 for other devices.

    NV_TIMING               timing;             //!< The scan out timing, NV_DISP_PATH_VER2 only, ignored if it's on analog TV.
    
    NvU32                   refreshRate1K;      //!< Refresh rate reported to the OS.
} NV_DISP_PATH_V2;


//! \ingroup dispcontrol
typedef NV_DISP_PATH_V2 NV_DISP_PATH;


//! \addtogroup dispcontrol
//! Macros for constructing the version field of NV_DISP_PATH
//! @{
#define NV_DISP_PATH_VER3 MAKE_NVAPI_VERSION(NV_DISP_PATH_V1, 3)
#define NV_DISP_PATH_VER2 MAKE_NVAPI_VERSION(NV_DISP_PATH_V1, 2)
#define NV_DISP_PATH_VER1 MAKE_NVAPI_VERSION(NV_DISP_PATH_V1, 1)
#define NV_DISP_PATH_VER4 MAKE_NVAPI_VERSION(NV_DISP_PATH_V2, 4)

#define NV_DISP_PATH_VER  NV_DISP_PATH_VER4

//! @}


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetDisplaySettings
//
//!  This function sets the display settings for the selected display sources.
//!   \note Display PATH with this API is limited to a single GPU. DualView across GPUs cannot be enabled with this API. 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 100.01
//!
//! \param [in]  hNvDisplay      NVIDIA Display selection \n
//!                              #NVAPI_DEFAULT_HANDLE is not allowed, it must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  paths          Detailed target display arrangement for clone, span and edge blending display modes.
//! \param [in]  pathCount       Count of targets for the selected display source.
//!
//! \retval  NVAPI_OK                Completed request
//! \retval  NVAPI_ERROR             Miscellaneous error occurred.
//! \retval  NVAPI_INVALID_ARGUMENT  Invalid input parameter
//! \retval  NVAPI_INCOMPATIBLE_STRUCT_VERSION  Incorrect struct version specified.
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetDisplaySettings(NvDisplayHandle hNvDisplay, NV_DISP_PATH *paths, NvU32 pathCount);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetDisplaySettings
//
//!  This function retrieves the target display arrangement for a selected display source.
//!  \note Display PATH with this API is limited to a single GPU. DUALVIEW across GPUs will be returned as STANDARD VIEW. 
//!        Use NvAPI_SYS_GetDisplayTopologies() to query views across GPUs.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 100.01
//!
//! \param [in]   hNvDisplay      NVIDIA Display selection \n
//!                               #NVAPI_DEFAULT_HANDLE is not allowed, it must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [out]  pPaths          Detailed target display arrangement for clone, span, and edge blending display modes.
//! \param [out]  pathCount       Count of targets for the selected display source.
//!
//! \retval  NVAPI_OK                Completed request
//! \retval  NVAPI_ERROR             Miscellaneous error occurred.
//! \retval  NVAPI_INVALID_ARGUMENT  Invalid input parameter
//! \retval  NVAPI_INCOMPATIBLE_STRUCT_VERSION  Incorrect struct version specified.
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetDisplaySettings(NvDisplayHandle hNvDisplay, NV_DISP_PATH *pPaths, NvU32 *pPathCount);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetTiming
//
//! \fn NvAPI_GetTiming(NvDisplayHandle hNvDisplay, NvU32 width, NvU32 height, float rr, NV_TIMING_FLAG flag, NvU32 outputId,
//! DESCRIPTION:  This function calculates the timing from the visible width/height/refresh-rate and timing type info.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 171.08
//!
//! \param [in]   hNvDisplay  NVIDIA Display selection \n
//!                           #NVAPI_DEFAULT_HANDLE is not allowed, it has to be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]   width       Visible horizontal size
//! \param [in]   height      Visible vertical size 
//! \param [in]   rr          Timing refresh rate 
//! \param [in]   flag        Flag containing additional info for timing calculation.
//! \param [in]   outputId    The monitor Id(mask) - only used to get the EDID timing or custom timing or NV policy related timing. See \ref handles.
//!                           (NV_TIMING_OVERRIDE_AUTO).
//! \param [in]   type        Timing type(formula) to use for calculating the timing
//! \param [out]  pT          Pointer to the NV_TIMING structure 
//!
//! \retval                 NVAPI_OK                Completed request
//! \retval                 NVAPI_ERROR             Miscellaneous error occurred
//! \retval                 NVAPI_INVALID_ARGUMENT  Invalid input parameter.
//
///////////////////////////////////////////////////////////////////////////////

//! \addtogroup dispcontrol
//! @{
//! Used in NvAPI_GetTiming().
typedef struct
{
    NvU32                   isInterlaced   : 4;  //!< To retrieve interlaced/progressive timing
    NvU32                   reserved0      : 12;
    union
    {
        NvU32               tvFormat       : 8;  //!< The actual analog HD/SDTV format. Used when the timing type is 
                                                 //!  NV_TIMING_OVERRIDE_ANALOG_TV and width==height==rr==0.
        NvU32               ceaId          : 8;  //!< The EIA/CEA 861B/D predefined short timing descriptor ID. 
                                                 //!  Used when the timing type is NV_TIMING_OVERRIDE_EIA861
                                                 //!  and width==height==rr==0.
        NvU32               nvPsfId        : 8;  //!< The NV predefined PsF format Id. 
                                                 //!  Used when the timing type is NV_TIMING_OVERRIDE_NV_PREDEFINED.
    };
    NvU32                   scaling        : 8;  //!< Define preferred scaling
}NV_TIMING_FLAG;


//! Get CEA format (digital TV format) from NV_TIMING(::etc.status)
#define NV_GET_CEA_FORMAT(n) (((n)&0x3F800000)>>23)     

//! Get the analog TV format from NV_TIMING(::etc.status)
#define NV_GET_ANALOG_TV_FORMAT(n) ((((n)&0x0FF00)==0x1100||((n)&0x0FF00)==0x1200)?((n)&0x0FF):0)   

//! Check if the timing(NV_TIMING::etc.status) is an analog TV format
#define NV_IS_ANALOG_TV_FORMAT(n)  ((((n)&0x0FF00)==0x1100||((n)&0x0FF00)==0x1200)?1:0)    

//! @}


//! \ingroup dispcontrol 
NVAPI_INTERFACE NvAPI_GetTiming(NvDisplayHandle hNvDisplay, NvU32 width, NvU32 height, float rr, NV_TIMING_FLAG flag, NvU32 outputId, NV_TIMING_OVERRIDE type, NV_TIMING *pT); 





///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_DISP_GetMonitorCapabilities
//
//! \fn NvAPI_DISP_GetMonitorCapabilities(NvU32 displayId, NV_MONITOR_CAPABILITIES *pMonitorCapabilities)
//! DESCRIPTION:     This API returns the Monitor capabilities 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]      displayId                Monitor Identifier
//! \param [out]     pMonitorCapabilities     The monitor support info
//!
//! \return ::NVAPI_OK, 
//!         ::NVAPI_ERROR, 
//!         ::NVAPI_INVALID_ARGUMENT
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dispcontrol
//! @{


//! HDMI-related and extended CAPs
typedef enum
{
    // hdmi related caps
    NV_MONITOR_CAPS_TYPE_HDMI_VSDB = 0x1000,
    NV_MONITOR_CAPS_TYPE_HDMI_VCDB = 0x1001,
} NV_MONITOR_CAPS_TYPE;



typedef struct _NV_MONITOR_CAPS_VCDB
{
    NvU8    quantizationRangeYcc         : 1;
    NvU8    quantizationRangeRgb         : 1;
    NvU8    scanInfoPreferredVideoFormat : 2;
    NvU8    scanInfoITVideoFormats       : 2;
    NvU8    scanInfoCEVideoFormats       : 2;
} NV_MONITOR_CAPS_VCDB;


//! See NvAPI_DISP_GetMonitorCapabilities().
typedef struct _NV_MONITOR_CAPS_VSDB
{
    // byte 1
    NvU8    sourcePhysicalAddressB         : 4; //!< Byte 1
    NvU8    sourcePhysicalAddressA         : 4; //!< Byte 1
    // byte 2
    NvU8    sourcePhysicalAddressD         : 4; //!< Byte 2
    NvU8    sourcePhysicalAddressC         : 4; //!< Byte 2
    // byte 3
    NvU8    supportDualDviOperation        : 1; //!< Byte 3
    NvU8    reserved6                      : 2; //!< Byte 3
    NvU8    supportDeepColorYCbCr444       : 1; //!< Byte 3
    NvU8    supportDeepColor30bits         : 1; //!< Byte 3
    NvU8    supportDeepColor36bits         : 1; //!< Byte 3
    NvU8    supportDeepColor48bits         : 1; //!< Byte 3
    NvU8    supportAI                      : 1; //!< Byte 3 
    // byte 4
    NvU8    maxTmdsClock;  //!< Bye 4
    // byte 5
    NvU8    cnc0SupportGraphicsTextContent : 1; //!< Byte 5
    NvU8    cnc1SupportPhotoContent        : 1; //!< Byte 5
    NvU8    cnc2SupportCinemaContent       : 1; //!< Byte 5
    NvU8    cnc3SupportGameContent         : 1; //!< Byte 5
    NvU8    reserved8                      : 1; //!< Byte 5
    NvU8    hasVicEntries                  : 1; //!< Byte 5
    NvU8    hasInterlacedLatencyField      : 1; //!< Byte 5
    NvU8    hasLatencyField                : 1; //!< Byte 5    
    // byte 6
    NvU8    videoLatency; //!< Byte 6
    // byte 7
    NvU8    audioLatency; //!< Byte 7
    // byte 8
    NvU8    interlacedVideoLatency; //!< Byte 8
    // byte 9
    NvU8    interlacedAudioLatency; //!< Byte 9
    // byte 10
    NvU8    reserved13                     : 7; //!< Byte 10
    NvU8    has3dEntries                   : 1; //!< Byte 10   
    // byte 11
    NvU8    hdmi3dLength                   : 5; //!< Byte 11
    NvU8    hdmiVicLength                  : 3; //!< Byte 11
    // Remaining bytes
    NvU8    hdmi_vic[7];  //!< Keeping maximum length for 3 bits
    NvU8    hdmi_3d[31];  //!< Keeping maximum length for 5 bits 
} NV_MONITOR_CAPS_VSDB;




//! See NvAPI_DISP_GetMonitorCapabilities().
typedef struct _NV_MONITOR_CAPABILITIES
{
    NvU32    version;
    NvU16    size;
    NvU32    infoType;
    NvU32    connectorType;        //!< Out: VGA, TV, DVI, HDMI, DP
    NvU8     bIsValidInfo : 1;     //!< Boolean : Returns invalid if requested info is not present such as VCDB not present
    union {
        NV_MONITOR_CAPS_VSDB  vsdb;
        NV_MONITOR_CAPS_VCDB  vcdb;
    } data;
} NV_MONITOR_CAPABILITIES;

//! Macro for constructing the version field of ::NV_MONITOR_CAPABILITIES
#define NV_MONITOR_CAPABILITIES_VER   MAKE_NVAPI_VERSION(NV_MONITOR_CAPABILITIES,1)

//! @}

//  SUPPORTED OS: Windows Vista and higher
//! \ingroup dispcontrol
NVAPI_INTERFACE NvAPI_DISP_GetMonitorCapabilities(NvU32 displayId, NV_MONITOR_CAPABILITIES *pMonitorCapabilities);



///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_EnumCustomDisplay
//
//! \fn NvAPI_EnumCustomDisplay(NvDisplayHandle hNvDisplay, NvU32 index, NvU32 outputId, NV_CUSTOM_DISPLAY *pC)
//! DESCRIPTION:     This function enumerates the custom displays.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 171.08
//!
//! \param [in]      hNvDisplay  NVIDIA Display selection \n 
//!                              #NVAPI_DEFAULT_HANDLE is not allowed. It must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]      index       Enum index
//! \param [in]      outputId    Monitor Id to which the custom display configuration should be obtained.
//!                              "-1" is to enum all custom display configurations. See \ref handles.
//! \param [out]     pC          Pointer to the NV_CUSTOM_DISPLAY structure 
//!
//! \retval          NVAPI_OK                Completed request
//! \retval          NVAPI_ERROR             Miscellaneous error occurred
//! \retval          NVAPI_INVALID_ARGUMENT  Invalid input parameter.
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dispcontrol
//! Used in NvAPI_EnumCustomDisplay() and NvAPI_TryCustomDisplay().
typedef struct
{
    NvU32                   version;
    
    // the source mode information
    NvU32                   width;             //!< Source surface(source mode) width
    NvU32                   height;            //!< Source surface(source mode) height
    NvU32                   depth;             //!< Source surface color depth."0" means all 8/16/32bpp
    NV_FORMAT               colorFormat;       //!< Color format (optional)
  
    NV_VIEWPORTF            srcPartition;      //!< For multimon support, should be set to (0,0,1.0,1.0) for now.
  
    float                   xRatio;            //!< Horizontal scaling ratio
    float                   yRatio;            //!< Vertical scaling ratio
                                                             
    NV_TIMING               timing;            //!< Timing used to program TMDS/DAC/LVDS/HDMI/TVEncoder, etc.
    NvU32                   hwModeSetOnly : 1; //!< If set, it means a hardware modeset without OS update
    
}NV_CUSTOM_DISPLAY; 

//! \ingroup dispcontrol
//! Used in NV_CUSTOM_DISPLAY.
#define NV_CUSTOM_DISPLAY_VER  MAKE_NVAPI_VERSION(NV_CUSTOM_DISPLAY,1)


//! \ingroup dispcontrol 
NVAPI_INTERFACE NvAPI_EnumCustomDisplay(NvDisplayHandle hNvDisplay, NvU32 index, NvU32 outputId, NV_CUSTOM_DISPLAY *pC); 


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_TryCustomDisplay
//
//! DESCRIPTION:    This API is a wrapper function of NvAPI_SetDisplaySettings() to set up a custom display without saving the configuration.
//!
//! \note
//!  In clone mode the timings can applied to both the target monitors but only one target at a time. \n
//!  For the secondary target the applied timings works under the following conditions:
//!  - If the secondary monitor EDID supports the selected timing, OR
//!  - If the selected custom timings can be scaled by the secondary monitor for the selected source resolution on the primary, OR
//!  - If the selected custom timings matches the existing source resolution on the primary.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 171.08
//!
//! \param [in]    hNvDisplay     NVIDIA Display selection \n
//!                               #NVAPI_DEFAULT_HANDLE is not allowed, it must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]    pDispOutId     Array of the target monitor output IDs - See \ref handles.
//! \param [in]    pCustDisp      Pointer to the NV_CUSTOM_DISPLAY structure
//! \param [in]    count          Total number of the incoming NV_CUSTOM_DISPLAY structure. This is for the multi-head support.
//! \param [in]    hwModeSetOnly  Option to let the user flush the timing without OS update
//!
//! \retval        NVAPI_OK                           Completed request
//! \retval        NVAPI_ERROR                        Miscellaneous error occurred
//! \retval        NVAPI_INVALID_ARGUMENT             Invalid input parameter.
//! \retval        NVAPI_NO_IMPLEMENTATION            Not implemented.
//! \retval        NVAPI_INCOMPATIBLE_STRUCT_VERSION  The version of NV_CUSTOM_DISPLAY is not supported.
//! 
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_TryCustomDisplay(NvDisplayHandle hNvDisplay, NvU32 *pDispOutputId, NV_CUSTOM_DISPLAY *pCustDisp, NvU32 count, NvU32 hwModeSetOnly);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_RevertCustomDisplayTrial
//
//! DESCRIPTION:    This API is used to restore the old display configuration before NvAPI_TryCustomDisplay() was called. This function
//!                 must be called only after a custom display configuration is tested on the hardware, using NvAPI_TryCustomDisplay(),  
//!                 otherwise no action is taken.
//!                 This API is not supported under Windows XP, in which case it returns NVAPI_NO_IMPLEMENTATION.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 171.08
//!
//! \param [in]    hNvDisplay)  NVIDIA Display selection
//!                             #NVAPI_DEFAULT_HANDLE is not allowed, it must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//!
//! \retval        NVAPI_OK                Completed request
//! \retval        NVAPI_ERROR             Miscellaneous error occurred
//! \retval        NVAPI_INVALID_ARGUMENT  Invalid input parameter.
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_RevertCustomDisplayTrial(NvDisplayHandle hNvDisplay);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_DeleteCustomDisplay
//
//! DESCRIPTION:    This function deletes the index-specified custom display configuration from the registry.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 171.08
//!
//! \param [in]     hNvDisplay       NVIDIA Display selection \n
//!                                  #NVAPI_DEFAULT_HANDLE is not allowed. It must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]     displayOutputId  Display ID on which the underscan configuration is to be applied. It must be a legal display Id (one bit set)
//!                                  -"0" is allowed, and indicates the default display used by the hNvDisplay handle.
//!                                  -"-1" is allowed, and indicates that the "index" is the absolute index and not a displayOutputId-related
//!                                   index - the index of the custom display
//!
//! \retval                   NVAPI_OK - completed request
//! \retval                   NVAPI_ERROR - miscellaneous error occurred
//! \retval                   NVAPI_INVALID_ARGUMENT: Invalid input parameter.
//!
//! \ingroup dispcontrol 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DeleteCustomDisplay(NvDisplayHandle hNvDisplay, NvU32 displayOutputId, NvU32 index); 

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SaveCustomDisplay
//
//! DESCRIPTION:    This function saves the current hardware display configuration on the specified output ID as a custom display configuration.
//!                 This function should be called right after NvAPI_TryCustomDisplay() to save the custom display from the current
//!                 hardware context. This function will not do anything if the custom display configuration is not tested on the hardware.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 171.08
//!
//! \param [in]     hNvDisplay          NVIDIA Display selection \n
//!                                     NVAPI_DEFAULT_HANDLE not allowed, it has to be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]     isThisOutputIdOnly  If set, the saved custom display will only be applied on the monitor with the same outputId (see \ref handles).
//! \param [in      isThisMonitorIdOnly If set, the saved custom display will only be applied on the monitor with the same EDID ID or 
//!                                     the same TV connector in case of analog TV.
//!
//! \retval         NVAPI_OK                Completed request
//! \retval         NVAPI_ERROR             Miscellaneous error occurred
//! \retval         NVAPI_INVALID_ARGUMENT  Invalid input parameter.
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SaveCustomDisplay(NvDisplayHandle hNvDisplay, NvU32 isThisOutputIdOnly, NvU32 isThisMonitorIdOnly);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_QueryUnderscanCap
//
//! \fn NvAPI_QueryUnderscanCap(NvDisplayHandle hNvDisplay, NvU32 displayOutputId, NV_UNDERSCAN_CAP* cap)
//!  DESCRIPTION:  This function gets the maximum underscan/overscan ratio and the supported underscan type(s).
//! 
//! <b> Supported Underscan Options for GPU and Display Outputs</b>
//! <table cellspacing="2" cellpadding="2" border="1">
//! <tr>
//!     <th>GPU</th>
//!     <th>Display Output</th>
//!     <th>Available Underscan Options</th>
//! </tr>
//! <tr>
//!     <td>GeForce8/post-GeForce8 </td>
//!     <td>CRT/TV/DFP/HDMI </td>
//!     <td>Source and scaler underscan</td>
//! </tr>
//! <tr>
//!     <td>GeForce7/pre-GeForce7</td>
//!     <td>TV/DFP/HDMI </td>
//!     <td>Source underscan only</td>
//! </tr>
//! <tr>
//!     <td>GeForce7/pre-GeForce7</td>
//!     <td>CRT  </td>
//!     <td>No underscan option yet</td>
//! </tr>
//! </table>
//!
//! <b> EDID Checking Behavior</b>
//! <table cellspacing="2" cellpadding="2" border="1">
//! <tr>
//!     <th>supportMonitorIdMatch</th>
//!     <th>supportDisplayOutputIdMatch</th>
//!     <th>Behavior</th>
//! </tr>
//! <tr>
//!     <td>0</td>
//!    <td>0</td>
//!     <td>No EDID check, apply to all devices (not recommended).</td>
//! </tr>
//! <tr>
//!     <td>0</td>
//!     <td>1</td>
//!     <td>No EDID check, apply to a specified device only (the old WinXP style).</td>
//! </tr>
//! <tr>
//!     <td>1</td>
//!     <td>0</td>
//!     <td>Apply to the specified EDID regardless of the device mask.</td>
//! </tr>
//! <tr>
//!     <td>1</td>
//!     <td>1</td>
//!     <td>Apply to the specified EDID on a specified device.</td>
//! </tr>
//! </table>
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 165.25
//!
//! \param [in]    hNvDisplay       NVIDIA Display selection \n
//!                                 #NVAPI_DEFAULT_HANDLE is not allowed. It must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]    displayOutputId  The display ID on which to apply the underscan configuration. 
//!                                 It must be a legal display ID (one bit set). \n
//!                                 "0" is allowed, indicating the default display used by the hNvDisplay handle. See \ref handles.
//! \param [out]   cap              The pointer to the NV_UNDERSCAN_CAP structure
//!
//! \retval  NVAPI_OK                Completed request
//! \retval  NVAPI_ERROR             Miscellaneous error occurred
//! \retval  NVAPI_INVALID_ARGUMENT  Invalid input parameter
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dispcontrol
//! Used in NvAPI_QueryUnderscanCap().
typedef struct
{
    NvU32 version;                           //!< Structure version
    
    float xRatioMin;                         //!< The supported min horizontal underscan ratio (e.g. 0.75 ~ 1.25 etc)
    float xRatioMax;                         //!< The supported max horizontal underscan ratio
    float yRatioMin;                         //!< The supported min vertical underscan ratio (e.g. 0.75 ~ 1.25)
    float yRatioMax;                         //!< The supported max vertical underscan ratio
    
    NvU32 supportSourceUnderscan       : 1;  //!< Indicate if source underscan is supported.
    NvU32 supportScalerUnderscan       : 1;  //!< Indicate if the scaler-based underscan is supported.
    NvU32 supportMonitorIdMatch        : 1;  //!< Indicate if the underscan configuration can be set for the monitors with the same EDID.
    NvU32 supportDisplayOutputIdMatch  : 1;  //!< Indicate if the underscan configuration can be set for monitors connected to the same display output ID.
    NvU32 supportXYIndependentCtrl     : 1;  //!< Indicate if we can independently control in the X and Y direction.
//! \code
//! Note 1: 
//!------------------------+--------------------+------------------------------------------------
//!          GPU           |    DisplayOutput   |  Available Underscan option
//!------------------------+--------------------+------------------------------------------------
//! GeForce8/post-GeForce8 |   CRT/TV/DFP/HDMI  |  source and scaler underscan
//! GeForce7/pre-GeForce7  |      TV/DFP/HDMI   |  source under only, the API will automatically
//!                        |                    |  fall back if scaler underscan is specified
//! GeForce7/pre-GeForce7  |         CRT        |  no underscan option yet, the API will return  
//!                        |                    |  failure
//!------------------------+--------------------+-------------------------------------------------
//!
//! Note 2:
//!-------------------+-----------------------------+-------------------------------------------
//! supportEdidMatch  | supportDisplayOutputIdMatch |                        behavior
//!-------------------+-----------------------------+---------------------------------------------
//!       0           |        0                    |  no EDID check, apply to all devices 
//!                   |                             | (not recommended)
//!       0           |        1                    |  no EDID check, apply to a specified device 
//!                   |                             |  only (the old XP style)
//!       1           |        0                    |  apply to the specified Edid regardless of   
//!                   |                             |  the device mask (new)
//!       1           |        1                    |  apply to the specified Edid on a specified
//!                   |                             |  device (new)
//!-------------------+-----------------------------+---------------------------------------------
//! \endcode
    NvU32 isSourceUnderscanRecommended : 1;  //!< Indicate if source underscan is recommended under the current display context.
    NvU32 isScalerUnderscanRecommended : 1;  //!< Indicate if the scaler based underscan is recommended under the current display context.
} NV_UNDERSCAN_CAP;


//! \ingroup dispcontrol
//! Macro for constructing the version field of NV_UNDERSCAN_CAP
#define NV_UNDERSCAN_CAP_VER  MAKE_NVAPI_VERSION(NV_UNDERSCAN_CAP,1)


//! \ingroup dispcontrol
NVAPI_INTERFACE NvAPI_QueryUnderscanCap(NvDisplayHandle hNvDisplay, NvU32 displayOutputId, NV_UNDERSCAN_CAP* cap);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_EnumUnderscanConfig
//
//! \fn NvAPI_EnumUnderscanConfig(NvDisplayHandle hNvDisplay, NvU32 displayOutputId, NvU32 index, NV_UNDERSCAN_CONFIG* config)
//! DESCRIPTION:    This function enumerates the user-customized underscan configurations on the given device.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 165.25
//!
//!  \param [in]    hNvDisplay         NVIDIA Display selection \n 
//!                                    #NVAPI_DEFAULT_HANDLE is not allowed - it must be a handle enumerated with
//!                                    NvAPI_EnumNVidiaDisplayHandle().
//!
//!  \param [in]    displayOutputId  The display ID to which the underscan configuration applies. See \ref handles.
//!                                  It must be a legal display ID (one bit set). 
//!                                  - Use "0" to specify the default display used by the hNvDisplay handle.
//!                                  - Use "-1" to enumerate all saved underscan configurations regardless of
//!                                    the target display
//!
//!   \param [in]   index            The regular the enum index. 
//!                                  - Use "-1"(0xFFFFFFFF) to enumerate the current active underscan config on 
//!                                    the display uniquely indicated by displayOutId
//!
//!   \param [out]  config             The output pointer for the API to populate the underscan config info.
//!                                    See \ref NV_UNDERSCAN_CONFIG.
//!
//!   \retval       NVAPI_OK                Completed request
//!   \retval       NVAPI_ERROR             Miscellaneous error occurred
//!   \retval       NVAPI_INVALID_ARGUMENT  Invalid input parameter.
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dispcontrol
//! @{
//! Used in NvAPI_EnumUnderscanConfig().
typedef struct
{
    NvU32 version;                           //!< Structure version
    
    float xRatio;                            //!< Horizontal underscan ratio
    float yRatio;                            //!< Vertical undercan ratio \n
                                             //! The API may modify the client passed in config due to the
                                             //! hardware restrictions. For example, the xRatio/yRatio may be
                                             //! fine tuned so that they're aligned on a certain number
                                             //! because of the tiled memory restriction. Also "isSrcUnderscan" 
                                             //! may also be changed if the hardware can't do backend underscan.

    NvU32 nativeWidth;                       //!< Width of the native mode
    NvU32 nativeHeight;                      //!< Height of the native mode
    NvU32 nativeRR;                          //!< Refresh rate of the native mode
    NvU32 isInterlaced                 : 1;  //!< Whether native timing is interlaced or not
    
    NvU32 isScalerUnderscan            : 1;  //!< Scaler-based underscan or sourcedbased underscan
    NvU32 isOnThisMonitorOnly          : 1;  //!< Whether this config is applied only to this specific monitor (EDID)
    NvU32 isOnThisDisplayOutputIdOnly  : 1;  //!< Whether this underscan configuration is applied only to this display output ID
    NvU32 isEnabled                    : 1;  //!< whether this underscan config is enabled or not.

    NvU32 reserved                     : 27;
} NV_UNDERSCAN_CONFIG;

#define NV_UNDERSCAN_CONFIG_VER1  MAKE_NVAPI_VERSION(NV_UNDERSCAN_CONFIG,1)
#define NV_UNDERSCAN_CONFIG_VER2  MAKE_NVAPI_VERSION(NV_UNDERSCAN_CONFIG,2)
#define NV_UNDERSCAN_CONFIG_VER   NV_UNDERSCAN_CONFIG_VER2

//! @}


//!   \ingroup      dispcontrol
NVAPI_INTERFACE NvAPI_EnumUnderscanConfig(NvDisplayHandle hNvDisplay, NvU32 displayOutputId, NvU32 index, NV_UNDERSCAN_CONFIG* config);


//!   \ingroup      dispcontrol
#define NVAPI_INDEX_CURRENT_ENTRY  -1

//!   \ingroup      dispcontrol
#define NVAPI_INDEX_ALL_ENTRIES    -2



///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_DeleteUnderscanConfig
//
//! DESCRIPTION:    This function deletes the specified underscan configuration entry.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 165.25
//!
//! \param [in]     hNvDisplay       NVIDIA Display selection \n
//!                                  #NVAPI_DEFAULT_HANDLE is not allowed, it must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//!
//! \param [in]     displayOutputId  The display ID to which the underscan config is applied. See \ref handles.
//!                                  It must be a legal display Id (one bit set)
//!                                  - Use "0" to specify the default display used by the hNvDisplay handle.
//!                                  - Use "-1" to indicate that "index" is the absolute index and not
//!                                    displayOutputId related
//!
//! \param [in]      index           The config index enumerated from NvAPI_EnumUnderScanConfig
//!                                  - Use "-1" for the current active underscan config being applied on
//!                                    the specified display output ID.
//!
//! \retval          NVAPI_OK                        Completed request
//! \retval          NVAPI_ERROR                     Miscellaneous error occurred
//! \retval          NVAPI_INVALID_ARGUMENT          Invalid input parameter.
//! \retval          NVAPI_UNKNOWN_UNDERSCAN_CONFIG  The current active underscan config is from an unknown source 
//!                                                  and can't be deleted.
//!
//! \ingroup         dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DeleteUnderscanConfig(NvDisplayHandle hNvDisplay, NvU32 displayOutputId, NvU32 index);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetUnderscanConfig
//
//! DESCRIPTION:    This function adds and sets a custom underscan configuration on the given device.  
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 165.25
//!
//! \param [in]      hNvDisplay       NVIDIA Display selection. #NVAPI_DEFAULT_HANDLE is not allowed, 
//!                                   it must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//!
//! \param [in]      displayOutputId  The display Id on which the underscan config is to apply. See \ref handles.
//!                                   It must be a legal display ID (one bit set).
//!                                   - Use "0" to indicate the default display used by the hNvDisplay handle.
//!                                     NOTE: 0xFFFFFFFF(-1) is not allowed in NvAPI_SetUnderScanConfig()
//!
//! \param [in,out]  config           The underscan config to set. See \ref NV_UNDERSCAN_CONFIG.
//! \param [in]      setDeferred      
//!                                   - "0": Apply the setup immediately.
//!                                   - "1": Apply refresh at the next OS modeset.
//!
//! \retval       NVAPI_OK                 Completed request
//! \retval       NVAPI_ERROR              Miscellaneous error occurred
//! \retval       NVAPI_INVALID_ARGUMENT   Invalid input parameter
//!
//! \ingroup      dispcontrol 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetUnderscanConfig(NvDisplayHandle hNvDisplay, NvU32 displayOutputId, NV_UNDERSCAN_CONFIG* config, NvU32 setDeferred);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetDisplayFeatureConfig
//
//! \fn NvAPI_GetDisplayFeatureConfig(NvDisplayHandle hNvDisplay, NV_DISPLAY_FEATURE* pFeature)
//! DESCRIPTION:     This function returns the current display feature configuration.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 171.08
//!
//! \param [in]      hNvDisplay   NVIDIA Display selection \n
//!                                #NVAPI_DEFAULT_HANDLE is not allowed, it must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [in,out]   feature      Pointer to NV_DISPLAY_FEATURE structure to retrieve the current feature configuration.
//! 
//! \retval           NVAPI_OK                Completed request
//! \retval           NVAPI_ERROR             Miscellaneous error occurred
//! \retval           NVAPI_INVALID_ARGUMENT  Invalid input parameter.
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dispcontrol
//! Used in NvAPI_GetDisplayFeatureConfig() and NvAPI_SetDisplayFeatureConfig().
typedef struct _NV_DISPLAY_FEATURE
{
    NvU32      enableScalerUnderscan  : 1;          //!< Enable/disable HDTV scaler-based resizing.
    NvU32      enableCEoverHDMI       : 1;          //!< Enable/disable the feature to force CE timings over HDMI.
                                                    //!< If this feature is enabled, then CE timings will only be used for HDMI displays.
    NvU32      reservedOEM            : 1;          //!< Reserved bit for OEM configuration
    NvU32      isDriverCtrlCEoverHDMI : 1;          //!< if == 1, the feature "Force CE timing over HDMI" is dynamically controlled by the driver so
                                                    //!< it's selectively enabled/disabled based on internal driver policy.
                                                    //!< if == 0, this feature is statically controlled by the application. 
    NvU32      reserved               : 28;

} NV_DISPLAY_FEATURE; 


//! \ingroup dispcontrol
NVAPI_INTERFACE NvAPI_GetDisplayFeatureConfig(NvDisplayHandle hNvDisplay, NV_DISPLAY_FEATURE* pFeature);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetDisplayFeatureConfig
//
//! DESCRIPTION:    This sets the display feature configuration.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 171.08
//!
//! \param [in]     hNvDisplay  NVIDIA Display selection \n
//!                 #NVAPI_DEFAULT_HANDLE is not allowed, it must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [in,out] feature     Copy of NV_DISPLAY_FEATURE structure to set up the new feature configuration
//! 
//! \retval         ::NVAPI_OK                
//! \retval         ::NVAPI_ERROR             
//! \retval         ::NVAPI_INVALID_ARGUMENT  
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetDisplayFeatureConfig(NvDisplayHandle hNvDisplay, NV_DISPLAY_FEATURE feature);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetDisplayFeatureConfigDefaults
//
//! DESCRIPTION:     This function returns the default display feature configuration.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 177.61
//!
//!  \param [in]     hNvDisplay   NVIDIA display selection.  \n
//!                  #NVAPI_DEFAULT_HANDLE is not allowed, it must be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//!  \param [in,out] feature      A copy of the NV_DISPLAY_FEATURE structure to set up the default feature configuration
//! 
//!  \retval ::NVAPI_OK             
//!  \retval ::NVAPI_ERROR           
//!  \retval ::NVAPI_INVALID_ARGUMENT 
//!
//!  \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetDisplayFeatureConfigDefaults(NvDisplayHandle hNvDisplay, NV_DISPLAY_FEATURE* pFeature);





///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_SetView
//
//! \fn NvAPI_SetView(NvDisplayHandle hNvDisplay, NV_VIEW_TARGET_INFO *pTargetInfo, NV_TARGET_VIEW_MODE targetView)
//!  This function lets the caller modify the target display arrangement of the selected source display handle in any nView mode.
//!  It can also modify or extend the source display in Dualview mode.
//!  \note Maps the selected source to the associated target Ids.
//!  \note Display PATH with this API is limited to single GPU. DUALVIEW across GPUs cannot be enabled with this API. 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 90.18
//!
//! \param [in]  hNvDisplay       NVIDIA Display selection. #NVAPI_DEFAULT_HANDLE is not allowed, it has to be a handle enumerated with NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  pTargetInfo      Pointer to array of NV_VIEW_TARGET_INFO, specifying device properties in this view.
//!                               The first device entry in the array is the physical primary.
//!                               The device entry with the lowest source id is the desktop primary.
//! \param [in]  targetCount      Count of target devices specified in pTargetInfo.
//! \param [in]  targetView       Target view selected from NV_TARGET_VIEW_MODE.
//!
//! \retval  NVAPI_OK               Completed request
//! \retval  NVAPI_ERROR            Miscellaneous error occurred
//! \retval  NVAPI_INVALID_ARGUMENT Invalid input parameter.
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dispcontrol
//! Used in NvAPI_SetView() and NvAPI_GetView()
typedef struct
{
    NvU32 version;     //!< (IN) structure version
    NvU32 count;       //!< (IN) target count
    struct 
    {
        NvU32 deviceMask;    //!< (IN/OUT) Device mask
        NvU32 sourceId;      //!< (IN/OUT) Source ID - values will be based on the number of heads exposed per GPU.
        NvU32 bPrimary:1;    //!< (OUT) Indicates if this is the GPU's primary view target. This is not the desktop GDI primary.
                             //!< NvAPI_SetView automatically selects the first target in NV_VIEW_TARGET_INFO index 0 as the GPU's primary view.
        NvU32 bInterlaced:1; //!< (IN/OUT) Indicates if the timing being used on this monitor is interlaced.
        NvU32 bGDIPrimary:1; //!< (IN/OUT) Indicates if this is the desktop GDI primary.
        NvU32 bForceModeSet:1;//!< (IN) Used only on Win7 and higher during a call to NvAPI_SetView(). Turns off optimization & forces OS to set supplied mode.
    } target[NVAPI_MAX_VIEW_TARGET];
} NV_VIEW_TARGET_INFO; 

//! \ingroup dispcontrol
#define NV_VIEW_TARGET_INFO_VER  MAKE_NVAPI_VERSION(NV_VIEW_TARGET_INFO,2)


//! \ingroup dispcontrol
NVAPI_INTERFACE NvAPI_SetView(NvDisplayHandle hNvDisplay, NV_VIEW_TARGET_INFO *pTargetInfo, NV_TARGET_VIEW_MODE targetView);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetView
//
//! This API lets caller retrieve the target display arrangement for selected source display handle.
//! \note Display PATH with this API is limited to single GPU. DUALVIEW across GPUs will be returned as STANDARD VIEW. 
//!       Use NvAPI_SYS_GetDisplayTopologies() to query views across GPUs.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 86.90
//!
//!  \param [in]     hNvDisplay             NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from 
//!                                         NvAPI_EnumNVidiaDisplayHandle().
//!  \param [out]    pTargets               User allocated storage to retrieve an array of  NV_VIEW_TARGET_INFO. Can be NULL to retrieve 
//!                                         the targetCount.
//!  \param [in,out] targetMaskCount        Count of target device mask specified in pTargetMask.
//!  \param [out]    targetView             Target view selected from NV_TARGET_VIEW_MODE.
//!
//!  \retval         NVAPI_OK               Completed request
//!  \retval         NVAPI_ERROR            Miscellaneous error occurred
//!  \retval         NVAPI_INVALID_ARGUMENT Invalid input parameter.
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetView(NvDisplayHandle hNvDisplay, NV_VIEW_TARGET_INFO *pTargets, NvU32 *pTargetMaskCount, NV_TARGET_VIEW_MODE *pTargetView);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_SetViewEx
//
//!  \fn NvAPI_SetViewEx(NvDisplayHandle hNvDisplay, NV_DISPLAY_PATH_INFO *pPathInfo, NV_TARGET_VIEW_MODE displayView)
//!  This function lets caller to modify the display arrangement for selected source display handle in any of the nview modes.
//!  It also allows to modify or extend the source display in dualview mode.
//!   \note Maps the selected source to the associated target Ids.
//!   \note Display PATH with this API is limited to single GPU. DUALVIEW across GPUs cannot be enabled with this API. 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 97.20
//!
//! \param [in]  hNvDisplay   NVIDIA Display selection. #NVAPI_DEFAULT_HANDLE is not allowed, it has to be a handle enumerated with 
//!                           NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]  pPathInfo    Pointer to array of NV_VIEW_PATH_INFO, specifying device properties in this view.
//!                           The first device entry in the array is the physical primary.
//!                           The device entry with the lowest source id is the desktop primary.
//! \param [in]  pathCount    Count of paths specified in pPathInfo.
//! \param [in]  displayView  Display view selected from NV_TARGET_VIEW_MODE.
//!
//! \retval  NVAPI_OK                Completed request
//! \retval  NVAPI_ERROR             Miscellaneous error occurred
//! \retval  NVAPI_INVALID_ARGUMENT  Invalid input parameter.
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup dispcontrol
#define NVAPI_MAX_DISPLAY_PATH  NVAPI_MAX_VIEW_TARGET

//! \ingroup dispcontrol
#define NVAPI_ADVANCED_MAX_DISPLAY_PATH  NVAPI_ADVANCED_MAX_VIEW_TARGET



//! \ingroup dispcontrol
//! Used in NV_DISPLAY_PATH_INFO.
typedef struct
{
    NvU32                   deviceMask;     //!< (IN) Device mask
    NvU32                   sourceId;       //!< (IN) Values will be based on the number of heads exposed per GPU(0, 1?)
    NvU32                   bPrimary:1;     //!< (IN/OUT) Indicates if this is the GPU's primary view target. This is not the desktop GDI primary.
                                            //!< NvAPI_SetViewEx() automatically selects the first target in NV_DISPLAY_PATH_INFO index 0 as the GPU's primary view.
    NV_GPU_CONNECTOR_TYPE   connector;      //!< (IN) Specify connector type. For TV only.

    // source mode information
    NvU32                   width;          //!< (IN) Width of the mode
    NvU32                   height;         //!< (IN) Height of the mode
    NvU32                   depth;          //!< (IN) Depth of the mode
    NV_FORMAT               colorFormat;    //!<      Color format if it needs to be specified. Not used now.

    //rotation setting of the mode
    NV_ROTATE               rotation;       //!< (IN) Rotation setting.

    // the scaling mode
    NV_SCALING              scaling;        //!< (IN) Scaling setting

    // Timing info
    NvU32                   refreshRate;    //!< (IN) Refresh rate of the mode
    NvU32                   interlaced:1;   //!< (IN) Interlaced mode flag

    NV_DISPLAY_TV_FORMAT    tvFormat;       //!< (IN) To choose the last TV format set this value to NV_DISPLAY_TV_FORMAT_NONE

    // Windows desktop position
    NvU32                   posx;           //!< (IN/OUT) X-offset of this display on the Windows desktop
    NvU32                   posy;           //!< (IN/OUT) Y-offset of this display on the Windows desktop
    NvU32                   bGDIPrimary:1;  //!< (IN/OUT) Indicates if this is the desktop GDI primary.

    NvU32                   bForceModeSet:1;//!< (IN) Used only on Win7 and higher during a call to NvAPI_SetViewEx(). Turns off optimization & forces OS to set supplied mode.
    NvU32                   bFocusDisplay:1;//!< (IN) If set, this display path should have the focus after the GPU topology change
    NvU32                   gpuId:24;       //!< (IN) the physical display/target Gpu id which is the owner of the scan out (for SLI multimon, display from the slave Gpu)

} NV_DISPLAY_PATH;


//! \ingroup dispcontrol
//! Used in NvAPI_SetViewEx() and NvAPI_GetViewEx().
typedef struct
{
    NvU32 version;     //!< (IN) Structure version
    NvU32 count;       //!< (IN) Path count
    NV_DISPLAY_PATH path[NVAPI_MAX_DISPLAY_PATH];
} NV_DISPLAY_PATH_INFO; 

//! \addtogroup dispcontrol
//! Macro for constructing the version fields of NV_DISPLAY_PATH_INFO
//! @{
#define NV_DISPLAY_PATH_INFO_VER  NV_DISPLAY_PATH_INFO_VER3
#define NV_DISPLAY_PATH_INFO_VER3 MAKE_NVAPI_VERSION(NV_DISPLAY_PATH_INFO,3)
#define NV_DISPLAY_PATH_INFO_VER2 MAKE_NVAPI_VERSION(NV_DISPLAY_PATH_INFO,2)
#define NV_DISPLAY_PATH_INFO_VER1 MAKE_NVAPI_VERSION(NV_DISPLAY_PATH_INFO,1)
//! @}


//! \ingroup dispcontrol
NVAPI_INTERFACE NvAPI_SetViewEx(NvDisplayHandle hNvDisplay, NV_DISPLAY_PATH_INFO *pPathInfo, NV_TARGET_VIEW_MODE displayView);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetViewEx
//
//! DESCRIPTION:    This API lets caller retrieve the target display arrangement for selected source display handle.
//!                 \note Display PATH with this API is limited to single GPU. DUALVIEW across GPUs will be returned as STANDARD VIEW. 
//!                       Use NvAPI_SYS_GetDisplayTopologies() to query views across GPUs.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 165.02
//!
//! \param [in]     hNvDisplay       NVIDIA Display selection. #NVAPI_DEFAULT_HANDLE is not allowed, it has to be a handle enumerated with
//!                                  NvAPI_EnumNVidiaDisplayHandle().
//! \param [in,out] pPathInfo        Count field should be set to NVAPI_MAX_DISPLAY_PATH. Can be NULL to retrieve just the pathCount.
//! \param [in,out] pPathCount       Number of elements in array pPathInfo->path.
//! \param [out]    pTargetViewMode  Display view selected from NV_TARGET_VIEW_MODE.
//!
//! \retval         NVAPI_OK                      Completed request
//! \retval         NVAPI_API_NOT_INTIALIZED      NVAPI not initialized
//! \retval         NVAPI_ERROR                   Miscellaneous error occurred
//! \retval         NVAPI_INVALID_ARGUMENT        Invalid input parameter.
//! \retval         NVAPI_EXPECTED_DISPLAY_HANDLE hNvDisplay is not a valid display handle.
//! 
//! \ingroup dispcontrol   
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetViewEx(NvDisplayHandle hNvDisplay, NV_DISPLAY_PATH_INFO *pPathInfo, NvU32 *pPathCount, NV_TARGET_VIEW_MODE *pTargetViewMode);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetSupportedViews
//
//!  This API lets caller enumerate all the supported NVIDIA display views - nView and Dualview modes.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 86.90
//!
//!  \param [in]     hNvDisplay             NVIDIA Display selection. It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from
//!                                         NvAPI_EnumNVidiaDisplayHandle().
//!  \param [out]    pTargetViews           Array of supported views. Can be NULL to retrieve the pViewCount first.
//!  \param [in,out] pViewCount             Count of supported views.
//!
//!  \retval         NVAPI_OK               Completed request
//!  \retval         NVAPI_ERROR            Miscellaneous error occurred
//!  \retval         NVAPI_INVALID_ARGUMENT Invalid input parameter.
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetSupportedViews(NvDisplayHandle hNvDisplay, NV_TARGET_VIEW_MODE *pTargetViews, NvU32 *pViewCount);



///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetHDCPLinkParameters
//
//!    \fn NvAPI_GetHDCPLinkParameters(NvDisplayHandle hNvDisplay, NV_HDCP_INFO *pNvHdcpInfo
//!    This function enumerate fields within the NV_HDCP_INFO.
//!
//!    The API provides support for the HDCP Upstream Protocol. The caller is responsible to fill the input fields 
//!    within NV_HDCP_PACKET to ensure that the specified HDCP_COMMANDS can be fulfilled. Different HDCP_COMMANDS will 
//!    enumerate different fields inside NV_HDCP_INFO. The following are the HDCP_COMMANDS supported   
//!
//!    - (A) HDCP_CMD_QUERY_HEAD_CONFIG  : Enumerates ports attached to a head. 
//!    - (B) HDCP_CMD_READ_LINK_STATUS   : Reads the Status of the cipher returning a signed status and connection state. 
//!    - (C) HDCP_CMD_VALIDATE_LINK      : Returns the parameters necessary to validate the links for the specified attach-point.
//!    - (D) HDCP_CMD_RENEGOTIATE        : Forced renegotiation of the link.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 97.60
//!
//! \param [in]     hNvDisplay        NVIDIA Display selection. It should be a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]     pNvHdcpInfo       Pointer to NV_HDCP_INFO that contains the requested command and input parameters.
//!
//! \retval         NVAPI_OK                           Completed request
//! \retval         NVAPI_ERROR                        Miscellaneous error occurred.
//! \retval         NVAPI_INVALID_ARGUMENT             pNvHdcpPacket is NULL.
//! \retval         NVAPI_INCOMPATIBLE_STRUCT_VERSION  The version of NV_HDCP_INFO struct is not supported.
//
///////////////////////////////////////////////////////////////////////////////


//! \addtogroup dispcontrol
//! @{

#define NVAPI_MAX_NUM_AP        16      //!< Max number of ports / attach points supported in HDCP Connection State
#define NVAPI_MAX_DEVICES       127     //!< Max number of Receiver & Repeater devices



//! Used in NV_HDCP_PACKET
typedef struct 
{
    union 
    {
        NvU32  data1;
        struct 
        {
            NvU8    revMin;
            NvU8    revMaj;
            NvU8    verMin;
            NvU8    verMaj;
        } ver;
    };
    NvU16 data2;
    NvU16 data3;
    NvU8  data4[8];
} NV_UID;


//! Used in NV_HDCP_PACKET
typedef struct 
{
#pragma pack(1)
    NvU64 uSessionID    : 37;   //!< [36:0] Random number
    NvU64 uDisplay      : 3;    //!< [39:37] O/S level display device
    NvU64 uReserved     : 24;   //!< [63:40] Reserved
#pragma pack()
} NV_HDCP_CN;


//! Used in NV_HDCP_PACKET
typedef struct 
{
    union 
    {
        NvU64   quadWord;
        struct 
        {
            NvU64 hugePart      : 40; // lower 40 in little endian
            NvU64 unusedPart    : 24;
        } parts;
    };
} NV_U40;


//! Used in NV_HDCP_PACKET
typedef struct
{
    union 
    {
        NvU64   quadWord;
        struct 
        {
            NvU64 hugePart      : 56; // lower 56 in little endian
            NvU64 unusedPart    : 8;
        } parts;
    };
} NV_U56;


//! Structure of data returned from monitor - as defined in HDCP Spec \n
//! Used in NV_HDCP_PACKET
typedef struct 
{
#pragma pack(1)
    NvU32 ucDeviceCount         : 7;    //!< [6:0] Total Receivers (except rep)
    NvU32 bMaxDevicesExceeded   : 1;    //!< [7] Topology Error > 127 devices 
    NvU32 bRepeaterDepth        : 3;    //!< [10:8] Repeater depth 
    NvU32 bMaxCascadeExceeded   : 1;    //!< [11] Topology Error > 7 levels repeater 
    NvU32 bHDMImode             : 1;    //!< [12] HDCP Receiver in HDMI mode
    NvU32 bReserved             : 19;   //!< [31:13] Reserved for future expansion
#pragma pack()
} NV_HDCP_BSTATUS;

//! The Connection State \n
//! Used in NV_HDCP_PACKET
typedef struct 
{
#pragma pack(1)
    NvU64 uAttachPoints         : 16;       //!< [15:0] Transmitting Attach Point	
    NvU64 bNonHDCP              : 1;        //!< [16] Transmitting Attach Point 
    NvU64 uHeadIndex            : 4;        //!< [20:17] Index of Head
    NvU64 uRFUPlanes            : 8;        //!< [28:21] *NOT* yet supported
    NvU64 uNumberOfActiveHeads  : 2;        //!< [30:29] Number of Heads - 1 
    NvU64 uReserved2            : 9;        //!< [39:31] Reserved for future use
    NvU64 uAttachedPlanes       : 8;        //!< [47:40] Will be moved to 28:21 in future chips
    NvU64 bCloneMode            : 1;        //!< [48] Dual-Display Clone Mode *NOT* yet supported
    NvU64 bSpanMode             : 1;        //!< [49] Dual-Display Span Mode *NOT* yet supported
    NvU64 reserved              : 14;       //!< [63:50] To fill up qword
#pragma pack()
} NV_HDCP_CS;

//! The Status of the Attach-Point (HDCP-capable or other) \n
//! Used in NV_HDCP_PACKET
typedef struct
{
#pragma pack(1)
    NvU64 bEncrypting           : 1;        //!<  [0] This Attach Point is Transmitting and has Output Encryption Enabled
    NvU64 bRepeater             : 1;        //!<  [1] This Attach Point is Transmitting to a Repeater 
    NvU64 bUserAccessible       : 1;        //!<  [2] This Attach Point is Transmitting on a user-accessible external digital port
    NvU64 bExtUnprotected       : 1;        //!<  [3] This Attach-point is Transmitting externally and is unprotected
    NvU64 uPortIndex            : 4;        //!<  [7:4] Port/Attach-point index
    NvU64 uNumPorts             : 4;        //!<  [11:8] Number of Connectable
    NvU64 bInternalPanel        : 1;        //!<  [12] Compliant Internal / Non-User accessible Port Panel without HDCP Encryption
    NvU64 bWideScope            : 1;        //!<  [13] Cs:16 is not enough to determine presence of non-compliant outputs+	(always ??
    NvU64 bHasCs                : 1;        //!<  [14] Supports Connection State (always ??
    NvU64 bReadZ                : 1;        //!<  [15] Supports ReadZ (always ??
    NvU64 uReserved             : 24;       //!<  [39:16] Reserved for Future Expansion
    NvU64 bDualLinkEven         : 1;        //!<  [40] The Even half of a Dual-Link (0x74)
    NvU64 bDualLinkOdd          : 1;        //!<  [41] The Odd half of a Dual-Link (0x76)
    NvU64 bDualLinkCapable      : 1;        //!<  [42] This Attach Point has Dual-Link capability
    NvU64 reserved              : 21;       //!<  [63:43] To fill up qword
    NvU32 DisplayId;                        //!<  ID of the Display on this attach point
#pragma pack()
} NV_HDCP_STATUS; 

//! Flags used for indicating active member elements \n
//! Used in NV_HDCP_PACKET
typedef enum 
{
    NV_HDCP_FLAGS_NULL          = 0x00000000, //!< Get AP Status
    NV_HDCP_FLAGS_APINDEX       = 0x00000001, //!< Index of Attach Point
    NV_HDCP_FLAGS_AN            = 0x00000010, //!< Downstream Session ID
    NV_HDCP_FLAGS_AKSV          = 0x00000020, //!< Downstream/Xmtr KSV
    NV_HDCP_FLAGS_BKSV          = 0x00000040, //!< Downstream/Rcvr KSV
    NV_HDCP_FLAGS_BSTATUS       = 0x00000080, //!< Link/Repeater Status
    NV_HDCP_FLAGS_CN            = 0x00000100, //!< Upstream Session ID
    NV_HDCP_FLAGS_CKSV          = 0x00000200, //!< Upstream ClientApp KSV
    NV_HDCP_FLAGS_DKSV          = 0x00000400, //!< Upstream/Xmtr KSV
    NV_HDCP_FLAGS_KP            = 0x00001000, //!< Signature
    NV_HDCP_FLAGS_S             = 0x00002000, //!< Status 
    NV_HDCP_FLAGS_CS            = 0x00004000, //!< Connection State
    NV_HDCP_FLAGS_V             = 0x00010000, //!< V of the KSVList
    NV_HDCP_FLAGS_MP            = 0x00020000, //!< Encrypted initializer for KSV List
    NV_HDCP_FLAGS_BKSVLIST      = 0x00040000, //!< NumKsvs & BksvList[NumKsvs]
    NV_HDCP_FLAGS_DUAL_LINK     = 0x00100000, //!< Two sets of An, Aksv, Kp, Bksv, Dksv
    NV_HDCP_FLAGS_ALWAYS_AUTH   = 0x00200000, //!< Always authenticate
    NV_HDCP_FLAGS_ON_BY_DEMAND  = 0x00000000, //!< Authenticate on demand
    NV_HDCP_FLAGS_ABORT_UNTRUST = 0x00400000, //!< Abort, Kp didn�t match
    NV_HDCP_FLAGS_ABORT_UNRELBL = 0x00800000, //!< Abort, Repeated Link Failures
    NV_HDCP_FLAGS_ABORT_KSV_LEN = 0x01000000, //!< Abort, incorrect KSV Length
    NV_HDCP_FLAGS_ABORT_KSV_SIG = 0x02000000, //!< Abort, bad KSV Signature
    NV_HDCP_FLAGS_ABORT_SRM_SIG = 0x04000000, //!< Abort, bad SRM Signature
    NV_HDCP_FLAGS_ABORT_SRM_REV = 0x08000000, //!< Abort due to SRM Revocation
    NV_HDCP_FLAGS_ABORT_NORDY   = 0x10000000, //!< Abort, Repeater Not Ready
    NV_HDCP_FLAGS_ABORT_KSVTOP  = 0x20000000, //!< Abort, KSV Topology Error
    NV_HDCP_FLAGS_ABORT_BADBKSV = 0x40000000, //!< Abort due to invalid Bksv
} NV_HDCP_FLAGS;

//! HDCP Commands \n
//! Used in NV_HDCP_PACKET
typedef enum 
{
    NV_HDCP_CMD_NULL               = 0x00, //!< Null command
    NV_HDCP_CMD_QUERY_HEAD_CONFIG  = 0x01, //!< Status of the head attach-points
    NV_HDCP_CMD_READ_LINK_STATUS   = 0x02, //!< Get the Status 
    NV_HDCP_CMD_VALIDATE_LINK      = 0x03, //!< Gets M & V 
    NV_HDCP_CMD_RENEGOTIATE        = 0x04, //!< Forced renegotiation of the link
    NV_HDCP_CMD_ABORTAUTHENTICATION= 0x05, //!< Abort authentication protocol
    NV_HDCP_CMD_SETLINKPOLICY      = 0x06, //!< Set the link policy  
} NV_HDCP_COMMANDS;


//! HDCP Return Status \n
//! Used in NV_HDCP_PACKET 
typedef enum 
{
    NV_HDCP_STATUS_SUCCESS                 = (0x00000000L), //!< Function completed successfully
    NV_HDCP_STATUS_UNSUCCESSFUL            = (0xC0000001L), //!< Function failed
    NV_HDCP_STATUS_PENDING                 = (0x00000103L), //!< Renegotiation is not complete, check status later
    NV_HDCP_STATUS_LINK_FAILED             = (0xC000013EL), //!< Renegotiation could not complete
    NV_HDCP_STATUS_INVALID_PARAMETER       = (0xC000000DL), //!< One or more of the calling parameters was invalid
    NV_HDCP_STATUS_INVALID_PARAMETER_MIX   = (0xC0000030L), //!< The combination of flFlags was invalid
    NV_HDCP_STATUS_NO_MEMORY               = (0xC0000017L), //!< Insufficient buffer space was allocated. Re-allocate using the size returned in the dwSize member
    NV_HDCP_STATUS_BAD_TOKEN_TYPE          = (0xC00000A8L), //!< The Session ID &/or KSV supplied were rejected
} NV_HDCP_RET_STATUS;


//! HDCP Packet \n
//! Used in NV_HDCP_INFO
typedef struct 
{
#pragma pack(4)
    NV_UID              uidHDCP;                        //!<  (IN) 
    NvU32               packetSize;                     //!<  (IN/OUT)
    NvU32               hDisplayContext;                //!<  (IN/OUT) 
    NV_HDCP_COMMANDS    cmdCommand;                     //!<  (IN)
    NV_HDCP_FLAGS       flFlags;                        //!<  (IN/OUT) 
    NV_HDCP_RET_STATUS  hdcpPacketStatus;               //!<  (OUT)

    NvU32               apIndex;                        //!<  (IN) Attach point index
    NV_HDCP_CN          cN;                             //!<  (IN) Client Session ID
    NV_U40              cKsv;                           //!<  (IN)

    NV_HDCP_BSTATUS     bStatus[NVAPI_MAX_NUM_AP];      //!<  (OUT) 
    NV_HDCP_STATUS      hdcpStatus[NVAPI_MAX_NUM_AP];   //!<  (OUT)
    NV_HDCP_CS          cS;                             //!<  (OUT) Connection State
         
    NV_U56              kP[2];                          //!<  (OUT) KPRIME value
    NV_U40              aN[2];                          //!<  (OUT)
    NV_U40              aKsv[2];                        //!<  (OUT)
    NV_U40              dKsv[2];                        //!<  (OUT) 
    NvU8                vP[20];                         //!<  (OUT) VPRIME value
    NvU64               mP;                             //!<  (OUT) MPRIME value
    NvU32               numBKSVs;                       //!<  (OUT) Valid KSVs in the bKsvList. Maximum is 127 devices 
    NV_U40              bKsvList[NVAPI_MAX_DEVICES];    //!<  (OUT) Up to 127 receivers & repeaters
#pragma pack()
} NV_HDCP_PACKET;

//! Used in NvAPI_GetHDCPLinkParameters()
typedef struct
{
    NvU32 version;
    NV_HDCP_PACKET nvHdcpPacket;
} NV_HDCP_INFO;

#define NV_HDCP_INFO_VER  MAKE_NVAPI_VERSION(NV_HDCP_INFO,1)

//! @}


//! \ingroup dispcontrol
NVAPI_INTERFACE NvAPI_GetHDCPLinkParameters(NvDisplayHandle hNvDisplay, NV_HDCP_INFO *pNvHdcpInfo);



//! \ingroup discontroltypes
//! See _NV_DPCD_PARAMS.
#define NVAPI_DPCD_MAX_DATA_SIZE 16

//! \ingroup discontroltypes 
//! Used in _NV_DPCD_PARAMS.
typedef enum _NV_DPCD_CMD
{
    NV_DP_AUXCH_CMD_REQ_TYPE_WRITE = 0,             //!< DisplayPort Aux Channel write
    NV_DP_AUXCH_CMD_REQ_TYPE_READ,                  //!< DisplayPort Aux Channel read	
    NV_DP_AUXCH_CMD_REQ_TYPE_I2C_WRITE,             //!< I2C write request
    NV_DP_AUXCH_CMD_REQ_TYPE_I2C_READ,              //!< I2C read request
    NV_DP_AUXCH_CMD_REQ_TYPE_I2C_WRITE_STATUS,      //!< I2C write status request
    NV_DP_AUXCH_CMD_REQ_TYPE_MOT_I2C_WRITE,         //!< I2C write request in the middle of the transaction 	
    NV_DP_AUXCH_CMD_REQ_TYPE_MOT_I2C_READ           //!< I2C read request in the middle of the transaction 

} NV_DPCD_CMD;

//! \ingroup discontroltypes
//! Used in _NV_DPCD_PARAMS.
typedef enum _NV_DPCD_REPLY_TYPE
{
    NV_DP_AUXCH_REPLYTYPE_ACK = 0,                  //!< For write: transaction completed and all data bytes are written.
                                                    //!< For read: ACK indicates it is ready for another read request.
    NV_DP_AUXCH_REPLYTYPE_NACK,                     //!< For write: the first return size bytes have been written.
                                                    //!< For read: there is no requested data for the read request transaction.
    NV_DP_AUXCH_REPLYTYPE_DEFER,                    //!< Not ready for the write/read request and client should retry later.	
    NV_DP_AUXCH_REPLYTYPE_TIMEOUT = 0xFF            //!< The receiver did not respond within the time-out period defined in the DisplayPort 1.1a specification.
} NV_DPCD_REPLY_TYPE;

//! \ingroup discontroltypes
//! Used in NvAPI_Disp_DpAuxChannelControl().
typedef struct _NV_DPCD_PARAMS
{
    NvU32                version;                        //!< Structure version
    NvU32                displayId;                      //!< DisplayId of the DisplayPort 
    NV_DPCD_CMD          cmd;                            //!< See ::_NV_DPCD_CMD
    NvU32                addr;                           //!< Address for read/write
    NvU8                 data[NVAPI_DPCD_MAX_DATA_SIZE]; //!< Data for the read/write command
    NvU32                size;                           //!< Number of bytes to read/write. The input size value should be indexed from 0. Returns
                                                         //!  the total number of data bytes successfully read/written, indexed from 1.
    NV_DPCD_REPLY_TYPE   replyType;                      //!< See ::_NV_DPCD_REPLY_TYPE
} NV_DPCD_PARAMS;

//! \ingroup discontroltypes
//! Macro for constructing the version field of _NV_DPCD_PARAMS
#define NV_DPCD_PARAMS_VER  MAKE_NVAPI_VERSION(NV_DPCD_PARAMS,1)


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Disp_DpAuxChannelControl
//
//! DESCRIPTION:  This API read/writes to the DisplayPort Aux Channel 
//!               The DisplayPort display needs to be active for this NvAPI call.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.33
//!
//! \param [in]     hNvDisplay   Display handle associated with the attached DisplayPort monitor
//! \param [in,out] pDpcdParams  Pointer to _NV_DPCD_PARAMS structure for input/output parameters
//! \param [in]     size         Length of the pDpcdParams struct 
//!
//! \return ::NVAPI_ERROR or ::NVAPI_OK or ::NVAPI_NOT_SUPPORTED or 
//!                ::NVAPI_INVALID_ARGUMENT or ::NVAPI_API_NOT_INTIALIZED
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Disp_DpAuxChannelControl(NvDisplayHandle hNvDisplay, NV_DPCD_PARAMS *pDpcdParams, NvU32 size);





///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetHybridMode
//
//! \fn NvAPI_SetHybridMode(NV_HYBRID_MODE mode)
//! DESCRIPTION: This API sets Hybrid mode. Supported on Vista and higher.
//!              Applications calling this API are required to run in elevated mode. 
//!              This API can be called from a system service to derive the elevated context of the System service. 
//!              \note Non-migratable applications that are running can prevent a successful transition.
//!              To query non-migratable applications use NvAPI_QueryNonMigratableApps().
//!
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 173.56
//!
//! \param [in]     mode     hybrid mode; see ::NV_HYBRID_MODE
//!
//! \retval         NVAPI_OK                 Completed request
//! \retval         NVAPI_ERROR              Miscellaneous error occurred
//! \retval         NVAPI_INVALID_ARGUMENT   Invalid input parameter
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup hybridapi
//! Used in NvAPI_SetHybridMode(), NvAPI_GetHybridMode(), and NvAPI_SetHybridModeEx().
typedef enum _NV_HYBRID_MODE
{
    NV_HYBRID_MODE_IGPU                 = 0x00,  //!< Integrated GPU
    NV_HYBRID_MODE_DGPU                 = 0x01,  //!< Discrete GPU
    NV_HYBRID_MODE_MULTI_ADAPTER        = 0x02,  //!< Multiple adapters
    NV_HYBRID_MODE_INVALID              = 0x03,  //!< Invalid mode
    NV_HYBRID_MODE_DGPU_WARMUP          = 0x04,
    NV_HYBRID_MODE_DGPU_DEEP_IDLE       = 0x05,
    NV_HYBRID_MODE_INSTALL              = 0x06,
    NV_HYBRID_MODE_ADAPTIVE             = 0x07, //!< This mode is only applicable for GetSwitchSettings.
} NV_HYBRID_MODE;



//! \ingroup hybridapi
NVAPI_INTERFACE NvAPI_SetHybridMode(NV_HYBRID_MODE mode);

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetHybridMode
//
//! DESCRIPTION:    This function gets the current Hybrid mode. Supported on Vista and higher.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version: 173.56
//!
//! \param [out]    pMode     hybrid mode; see ::NV_HYBRID_MODE
//!
//! \retval         NVAPI_OK                 Completed request
//! \retval         NVAPI_ERROR              Miscellaneous error occurred
//! \retval         NVAPI_INVALID_ARGUMENT   Invalid input parameter
//!
//! \ingroup hybridapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetHybridMode(NV_HYBRID_MODE *pMode);


//! \ingroup hybridapi
//! Reference: Hybrid Spec 3.0 DSM Function HYBRIDCAPS bit 28:27
typedef enum _NV_HYBRID_SWITCH_METHOD
{
    NV_HYBRID_SWITCH_METHOD_NONE				= 0x00, //!< None of physical selector available 
                                    //!< (no hotkey, no physical button/switch, etc.)
    NV_HYBRID_SWITCH_METHOD_UNKNOWN				= 0x01, //!< Uses unspecified means to pass required state via 
                                    //!< POLICYSELECT, or other API
    NV_HYBRID_SWITCH_METHOD_HOTKEY				= 0x02,  
    NV_HYBRID_SWITCH_METHOD_PHYSICAL_SWITCH			= 0x03,
} NV_HYBRID_SWITCH_METHOD;


//! \ingroup hybridapi
typedef struct
{
    NV_HYBRID_SWITCH_METHOD method;
    NvU32					numberOfWays;	
} NV_HYBRID_TRANSITION_METHOD;






///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_Coproc_GetCoprocStatus
//
//! \fn NvAPI_Coproc_GetCoprocStatus(NvU32 *pCoprocStatus, NV_COPROC_STATE* pCoprocState)
//! DESCRIPTION:     This API queries the the coproc status and state. 
//!                  Supported on Vista and higher.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in,out]      pCoprocStatus  The coproc status
//! \param [in,out]      pCoprocState   The coproc state
//!
//! \retval ::NVAPI_OK              Completed request
//! \retval ::NVAPI_NOT_SUPPORTED   This feature is not supported on Windows XP
//! \retval ::NVAPI_API_NOT_INTIALIZED  You must call NvAPI_Initialize first
//! \retval ::NVAPI_ERROR               Miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT    Invalid input parameter
///////////////////////////////////////////////////////////////////////////////

//! \ingroup coprocapi
//! Used in NvAPI_Coproc_GetCoprocStatus().
typedef enum
{
    NV_COPROC_STATUS_OK                        = 0x00000000,
    NV_COPROC_STATUS_CHIPSET_NOT_SUPPORTED     = 0x00000001,
    NV_COPROC_STATUS_MGPU_NOT_SUPPORTED        = 0x00000002,
    NV_COPROC_STATUS_DGPU_NOT_SUPPORTED        = 0x00000004,
    NV_COPROC_STATUS_INVALID_GPU_COUNT         = 0x00000008,
    NV_COPROC_STATUS_DISABLED_BY_REG_KEY       = 0x00000010,
    NV_COPROC_STATUS_DGPU_POSTING_DEVICE       = 0x00000020,
    NV_COPROC_STATUS_DISABLED_BY_HYBRID        = 0x00000040,
    NV_COPROC_STATUS_OS_NOT_SUPPORTED          = 0x00000080,
    NV_COPROC_STATUS_SBIOS_NOT_CONFIGURED      = 0x00000100,
} NV_COPROC_STATUS;


//! \ingroup coprocapi
//! Used in NvAPI_Coproc_GetCoprocStatus().
typedef enum 
{
    NV_COPROC_STATE_DGPU_GOLD              = 0x00000000,
    NV_COPROC_STATE_DGPU_ON                = 0x00000001,
} NV_COPROC_STATE;

//! \ingroup coprocapi
NVAPI_INTERFACE NvAPI_Coproc_GetCoprocStatus(NvU32 *pCoprocStatus, NV_COPROC_STATE* pCoprocState);




//! \ingroup coprocapi
typedef struct 
{
    NvU32  version;
    NvU32  is_IGPU_MODE_ONLY : 1;   //!< Indicates if the IGPU_MODE_ONLY flag is set or needs to be set
    NvU32  is_DGPU_MODE_ONLY : 1;   //!< Indicates if the DGPU_MODE_ONLY flag is set or needs to be set
    NvU32  reserved          : 30;  //!< Should be set to ZERO
} NV_COPROC_FLAGS_EX;

//! \ingroup coprocapi
#define NV_COPROC_FLAGS_EX_VER          MAKE_NVAPI_VERSION(NV_COPROC_FLAGS_EX, 1)

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_Coproc_SetCoprocInfoFlagsEx
//
//! DESCRIPTION:     This API sets the coproc info flags.
//!
//! \param [in]      coprocInfoExFlags  pointer to the NV_COPROC_FLAGS_EX indicating the mask to be set
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                  completed request
//! \retval ::NVAPI_ERROR               miscellaneous error occurred
//! \retval ::NVAPI_INVALID_POINTER     null input parameter
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION
//!
//! \ingroup coprocapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Coproc_SetCoprocInfoFlagsEx(NV_COPROC_FLAGS_EX* coprocInfoExFlags);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_Coproc_GetCoprocInfoFlagsEx
//
//! DESCRIPTION:     This API gets the coproc info flags.
//!
//! \param [out]     coprocInfoExFlags   pointer to the NV_COPROC_FLAGS_EX indicating the mask to get
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                  completed request
//! \retval ::NVAPI_ERROR               miscellaneous error occurred
//! \retval ::NVAPI_INVALID_POINTER     null input parameter
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION
//!
//! \ingroup coprocapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Coproc_GetCoprocInfoFlagsEx(NV_COPROC_FLAGS_EX* coprocInfoExFlags);





///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_Coproc_NotifyCoprocPowerState
//
//! \fn NvAPI_Coproc_NotifyCoprocPowerState(NvU32 IsSafetoPowerOff, NvU64 SequenceNumber, NvU32 *pStatus)
//! \code
//! DESCRIPTION:     This API tells driver that now it is safe to power off dGPU since No running Application is using the coproc.
//!                  
//  SUPPORTED OS: Windows Vista and higher
//!
//! PARAMETERS:      IsSafetoPowerOff (IN)     - decides if it is safe to power off the dGPU. TRUE to turn off dGPU.
//!					SequenceNumber (IN)       - In response to event with matching sequence number
//!                  pStatus(OUT)              - returns the status if powering off dGPU has started.
//!
//! RETURN STATUS:
//!                  NVAPI_OK - completed request
//!                  NVAPI_ERROR - miscellaneous error occurred
//!                  NVAPI_INVALID_ARGUMENT - Invalid input parameter
//! \endcode
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup coprocapi
typedef enum
{
    NV_COPROC_POWER_OFF_MODE_UNSAFE = 0,
    NV_COPROC_POWER_OFF_MODE_GPU_OFF = 1,
    NV_COPROC_POWER_OFF_MODE_HDA_REMOVE = 0xff10,
} NV_COPROC_POWER_OFF_MODE;


//! \ingroup coprocapi
NVAPI_INTERFACE NvAPI_Coproc_NotifyCoprocPowerState(NvU32 IsSafetoPowerOff, NvU64 SequenceNumber, NvU32 *pStatus);




///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_Coproc_GetApplicationCoprocInfo
//
//! \fn NvAPI_Coproc_GetApplicationCoprocInfo(NV_COPROC_APP_INFO *pCoprocAppInfo)
//! DESCRIPTION:     This API queries the the coproc status for the application
//!                  running in the current process.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   pCoprocAppInfo   The coproc application info structure
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_ERROR - miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT - Invalid input parameter
//! \retval ::NVAPI_NOT_SUPPORTED - function is not supported in this platform
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION 
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup coprocapi
//! Used in NvAPI_Coproc_GetApplicationCoprocInfo().
typedef struct
{
    NvU32 version;                      //!< the structure version
    NvU32 appStatus;			//!< the application status  
} NV_COPROC_APP_INFO;

//! \ingroup coprocapi
//! Macro for onstructing the version field of NV_COPROC_APP_INFO
#define NV_COPROC_APP_INFO_VER          MAKE_NVAPI_VERSION(NV_COPROC_APP_INFO, 1)

//! \ingroup coprocapi
//! See .NV_COPROC_APP_INFO
typedef enum
{
    NV_COPROC_APP_STATUS_ENABLED           = 0x00000000, //!< coproc mode has been enabled
    NV_COPROC_APP_STATUS_DISABLED          = 0x00000001, //!< copro mode has been disabled.
} NV_COPROC_APP_STATUS;

//! \ingroup coprocapi
NVAPI_INTERFACE NvAPI_Coproc_GetApplicationCoprocInfo(NV_COPROC_APP_INFO *pCoprocAppInfo);



///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetVideoState
//
//! \fn NvAPI_GetVideoState(NvDisplayHandle hNvDisplay, NVAPI_GET_VIDEO_STATE_COMPONENT *pGetVidStateComp)
//! DESCRIPTION:     This function return the video state component for the component ID passed in. It is the responsibility
//!                  of the caller to fill secret application key that enables authentication of the caller.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 171.08
//!
//! \param [in]      hNvDisplay        NVIDIA Display selection \n
//!                                    It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [out]     pGetVidStateComp  NVAPI_GET_VIDEO_STATE_COMPONENT packet containing
//!                                    a valid component ID and a valid application secret key.
//!
//! \retval ::NVAPI_OK  
//! \retval ::NVAPI_ERROR
//! \retval ::NVAPI_INVALID_ARGUMENT
//
///////////////////////////////////////////////////////////////////////////////

#ifndef NV_VIDEO_COMPONENTS_DEFINE
#define NV_VIDEO_COMPONENTS_DEFINE

///////////////////////////////////////////////////////////////////////////////
// Structs and enums related to Video state
///////////////////////////////////////////////////////////////////////////////


//! \ingroup vidcontrol
//! Components related to video state \n
//! Used in NVAPI_GET_VIDEO_STATE_COMPONENT and NVAPI_SET_VIDEO_STATE_COMPONENT.
typedef enum _NVAPI_VIDEO_STATE_COMPONENT_ID
{
    NVAPI_VIDEO_STATE_COMPONENT_ID_NONE     = -1,   //!< Placeholder for invalid component ID
    NVAPI_VIDEO_STATE_COMPONENT_BRIGHTNESS      ,   //!<  Permits control of video's brightness value
    NVAPI_VIDEO_STATE_COMPONENT_CONTRAST        ,   //!<  Allows control of video's contrast value
    NVAPI_VIDEO_STATE_COMPONENT_HUE             ,   //!<  To control the hue value
    NVAPI_VIDEO_STATE_COMPONENT_SATURATION      ,   //!<  Allows control of video's saturation value
    NVAPI_VIDEO_STATE_COMPONENT_COLORTEMP       ,   //!<  Allows control of the color temperature value
    NVAPI_VIDEO_STATE_COMPONENT_Y_GAMMA         ,   //!<  To set the Y-gamma values
    NVAPI_VIDEO_STATE_COMPONENT_RGB_GAMMA_R     ,   //!<  To set the R value of RGB gamma
    NVAPI_VIDEO_STATE_COMPONENT_RGB_GAMMA_G     ,   //!<  To set the G value of RGB gamma
    NVAPI_VIDEO_STATE_COMPONENT_RGB_GAMMA_B     ,   //!<  To set the B value of RGB gamma
    NVAPI_VIDEO_STATE_COMPONENT_COLOR_SPACE     ,   //!<  Permits choice of various color spaces using VIDEO_COMP_ALGO_COLOR_SPACE_xxx
    NVAPI_VIDEO_STATE_COMPONENT_COLOR_RANGE     ,   //!<  Allows setting between a limited/full color range using VIDEO_COMP_ALGO_COLOR_RANGE_xxx
    NVAPI_VIDEO_STATE_COMPONENT_PLAYBACK_PROFILE,   //!<  Permits using special postprocessing for Adobe Flash 9 Content
    NVAPI_VIDEO_STATE_COMPONENT_DEINTERLACE     ,   //!<  To set various types of deinterlacing algorithms
    NVAPI_VIDEO_STATE_COMPONENT_SCALING         ,   //!<  Allows setting video scaling algorithms
    NVAPI_VIDEO_STATE_COMPONENT_CADENCE         ,   //!<  Allows control of the cadence algorithms
    NVAPI_VIDEO_STATE_COMPONENT_NOISE_REDUCE    ,   //!<  Allows setting post-processing noise reduction values
    NVAPI_VIDEO_STATE_COMPONENT_EDGE_ENHANCE    ,   //!<  Permits post-processing edge enhancement value adjustment
    NVAPI_VIDEO_STATE_COMPONENT_OVERDRIVE       ,   //!<  To control the overdrive feature
    NVAPI_VIDEO_STATE_COMPONENT_SPLITSCREEN     ,   //!<  To permit setting a splitscreen using one of VIDEO_COMP_ALGO_SPLITSCREEN_xxx
    NVAPI_VIDEO_STATE_COMPONENT_DEBLOCKING      ,   //!<  Allows out-of-loop deblocking
    NVAPI_VIDEO_STATE_COMPONENT_DYNAMIC_CONTRAST,   //!<  Permits control of video's dynamic contrast value
    NVAPI_VIDEO_STATE_COMPONENT_GREEN_STRETCH   ,   //!<  Permits control of green stretch
    NVAPI_VIDEO_STATE_COMPONENT_BLUE_STRETCH    ,   //!<  Allows control of blue enhancement
    NVAPI_VIDEO_STATE_COMPONENT_SKIN_TONE_CORRECTION, //!<  Allows skin-tone correction for video 
    NVAPI_VIDEO_STATE_COMPONENT_GAMUT_REMAPPING ,   //!<  Applies gamut remapping on video
    NVAPI_VIDEO_STATE_COMPONENT_2DTO3D          ,   //!< Converts 2D video to 3D stereo video
    NVAPI_VIDEO_STATE_COMPONENT_3D_ANALYSIS     ,   //!< Analyzing 3D stereo video
    NVAPI_VIDEO_STATE_COMPONENT_FRC             ,   //!< Frame Rate Converter
    NVAPI_VIDEO_STATE_COMPONENT_ID_LAST         ,   //!< All valid components defined before this one
} NVAPI_VIDEO_STATE_COMPONENT_ID;

//! \ingroup vidcontrol 
//! Dynamic contrast value. Kept this for backward compatibility.
#define NVAPI_VIDEO_STATE_COMPONENT_DYNAMIC_CONSTRAST  NVAPI_VIDEO_STATE_COMPONENT_DYNAMIC_CONTRAST  


//! \ingroup vidcontrol
//! Used in #_NVAPI_VIDEO_COMPONENT_ALGORITHM.
#define VIDEO_COMP_ALGO_CUSTOM_BASE 64

//! \ingroup vidcontrol
//! Algorithms controlling various video components
//! Used in NVAPI_GET_VIDEO_STATE_COMPONENT and NVAPI_SET_VIDEO_STATE_COMPONENT.
typedef enum _NVAPI_VIDEO_COMPONENT_ALGORITHM
{
    VIDEO_COMP_ALGO_COLOR_SPACE_601                  = 0,  //!<  Use the ITU-R BT.601 standard in color-space conversion for xxx_COLOR_SPACE component
    VIDEO_COMP_ALGO_COLOR_SPACE_709                  = 1,  //!<  Use the ITU-R BT.709 standard in color-space conversion for xxx_COLOR_SPACE component
    VIDEO_COMP_ALGO_COLOR_SPACE_CUSTOM_04            = VIDEO_COMP_ALGO_CUSTOM_BASE+4,   //!< Use custom color matrix.
    VIDEO_COMP_ALGO_COLOR_RANGE_STD                  = 0,  //!<  Full range of (0-255) for xxx_COLOR_RANGE component, equivalent to Microsoft's DXVADDI_NOMINALRANGE::DXVADDI_NominalRange_0_255
    VIDEO_COMP_ALGO_COLOR_RANGE_EXT                  = 1,  //!<  Limited range of (16-235) for xxx_COLOR_RANGE component, equivalent to Microsoft's DXVADDI_NOMINALRANGE::DXVADDI_NominalRange_16_235
    VIDEO_COMP_ALGO_PLAYBACK_PROFILE_NONE            = 0,  //!<  Use no playback profile
    VIDEO_COMP_ALGO_PLAYBACK_PROFILE_ADOBE_FLASH_9   = 1,  //!<  Use the internet video enhancement postprocessing for Adobe Flash 9 
    VIDEO_COMP_ALGO_DEINTERLACE_BOB                  = 0,  //!<  Perform Bob deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_WEAVE                = 1,  //!<  Use weave deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_SIMPLE_ADAPTIVE      = 2,  //!<  Perform a simple motion adaptive deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_GRADIENT_SIMPLE      = 3,  //!<  Use a simple gradient deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_GRADIENT_FULL        = 4,  //!<  Use advanced gradient deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_ADAPTIVE_FOUR_FIELD  = 5,  //!<  Perform four field motion adaptive deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_DIR_SPATIAL          = 6,  //!<  User directional spatial deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_ADVANCED             = 7,  //!<  Perform proprietary advanced deinterlacing
    VIDEO_COMP_ALGO_DEINTERLACE_GPU_CAPABLE          = 8,  //!<  Best available but GPU dependent. (video driver decides dynamically) 
    VIDEO_COMP_ALGO_DEINTERLACE_CUSTOM_00            = VIDEO_COMP_ALGO_CUSTOM_BASE+0,    //!< Use custom Deinterlacing algorithm
    VIDEO_COMP_ALGO_DEINTERLACE_CUSTOM_01            = VIDEO_COMP_ALGO_CUSTOM_BASE+1,    //!< Use custom Deinterlacing algorithm
    VIDEO_COMP_ALGO_SCALING_ALG_SIMPLE               = 0,  //!<  Do scaling using a simple algorithm       
    VIDEO_COMP_ALGO_SCALING_ALG_4x4FILTER            = 1,  //!<  Perform scaling using a 4x4 filter
    VIDEO_COMP_ALGO_SCALING_ALG_8x8FILTER            = 2,  //!< Perform scaling using a 8x8 filter
    VIDEO_COMP_ALGO_SCALING_ALG_CUSTOM_00            = VIDEO_COMP_ALGO_CUSTOM_BASE+0,    //!< Use custom scaling component
    VIDEO_COMP_ALGO_SCALING_ALG_CUSTOM_01            = VIDEO_COMP_ALGO_CUSTOM_BASE+1,    //!< Use custom scaling component
    VIDEO_COMP_ALGO_CADENCE_NONE                     = 0,  //!<  Turn cadence OFF
    VIDEO_COMP_ALGO_CADENCE_SIMPLE                   = 1,  //!<  Use simple cadence detection
    VIDEO_COMP_ALGO_CADENCE_VOF                      = 2,  //!<  Use video on film cadence detection
    VIDEO_COMP_ALGO_CADENCE_COMPUTE                  = 3,  //!<  Use compute cadence detection
    VIDEO_COMP_ALGO_CADENCE_GPU_CAPABLE              = 4,  //!<  Best available but GPU dependent. (video driver decides dynamically)
    VIDEO_COMP_ALGO_NOISE_REDUCE_PUREVIDEO           = 0,  //!<  Use PureVideo noise reduction
    VIDEO_COMP_ALGO_NOISE_REDUCE_CUSTOM_00           = VIDEO_COMP_ALGO_CUSTOM_BASE+0,  //!< Use custom noise reduction
    VIDEO_COMP_ALGO_NOISE_REDUCE_CUSTOM_01           = VIDEO_COMP_ALGO_CUSTOM_BASE+1,  //!< Use custom noise reduction
    VIDEO_COMP_ALGO_EDGE_ENHANCE_PUREVIDEO           = 0,  //!<  Use PureVideo Sharpening Filter
    VIDEO_COMP_ALGO_EDGE_ENHANCE_CUSTOM_00           = VIDEO_COMP_ALGO_CUSTOM_BASE+0,  //!< Use custom Sharpening Filter
    VIDEO_COMP_ALGO_EDGE_ENHANCE_CUSTOM_01           = VIDEO_COMP_ALGO_CUSTOM_BASE+1,  //!< Use custom Sharpening Filter
    VIDEO_COMP_ALGO_OVERDRIVE_SIMPLE                 = 0,  //!<  Use simple overdrive algorithm
    VIDEO_COMP_ALGO_SPLITSCREEN_TYPE_NORMAL          = 0,  //!<  Set the splitscreen in normal mode
    VIDEO_COMP_ALGO_SPLITSCREEN_TYPE_REPEATED        = 1,  //!<  Set the splitscreen to be repeated
    VIDEO_COMP_ALGO_SPLITSCREEN_TYPE_ON_MIRROR       = 2,  //!<  Set the splitscreen as a mirror
    VIDEO_COMP_ALGO_DYNAMIC_CONTRAST_PRESET_NONE     = 0,  //!<  Use the value setting for dynamic contrast instead of a preset
    VIDEO_COMP_ALGO_DYNAMIC_CONTRAST_PRESET_LOW      = 1,  //!<  Turn the dynamic contrast to a low setting
    VIDEO_COMP_ALGO_DYNAMIC_CONTRAST_PRESET_MEDIUM   = 2,  //!<  Turn the dynamic contrast to a medium setting
    VIDEO_COMP_ALGO_DYNAMIC_CONTRAST_PRESET_HIGH     = 3,  //!<  Turn the dynamic contrast to a high setting
    VIDEO_COMP_ALGO_GREEN_STRETCH_PRESET_NONE        = 0,  //!<  Use the value setting for green stretch instead of a preset
    VIDEO_COMP_ALGO_GREEN_STRETCH_PRESET_LOW         = 1,  //!<  Set the green strech to a low setting
    VIDEO_COMP_ALGO_GREEN_STRETCH_PRESET_MEDIUM      = 2,  //!<  Set the green strech to a medium setting
    VIDEO_COMP_ALGO_GREEN_STRETCH_PRESET_HIGH        = 3,  //!<  Set the green strech to a high setting
    VIDEO_COMP_ALGO_BLUE_STRETCH_PRESET_NONE         = 0,  //!<  Use the value setting for blue stretch instead of a preset   
    VIDEO_COMP_ALGO_BLUE_STRETCH_PRESET_LOW          = 1,  //!<  Set the blue strech to a low setting
    VIDEO_COMP_ALGO_BLUE_STRETCH_PRESET_MEDIUM       = 2,  //!<  Set the blue strech to a medium setting
    VIDEO_COMP_ALGO_BLUE_STRETCH_PRESET_HIGH         = 3,  //!<  Set the blue strech to a high setting
    VIDEO_COMP_ALGO_SKIN_TONE_CORRECTION_PRESET_NONE = 0,  //!<  Use the value setting for skin tone correction instead of a preset  
    VIDEO_COMP_ALGO_SKIN_TONE_CORRECTION_PRESET_SQUEEZE = 1,  //!<  Turn the skin tone correction to a low setting
    VIDEO_COMP_ALGO_SKIN_TONE_CORRECTION_PRESET_RED     = 2,  //!<  Turn the skin tone correction to a medium setting
    VIDEO_COMP_ALGO_SKIN_TONE_CORRECTION_PRESET_YELLOW  = 3,  //!<  Turn the skin tone correction to a high setting
    VIDEO_COMP_ALGO_GAMUT_REMAPPING_CUSTOM_00        = VIDEO_COMP_ALGO_CUSTOM_BASE+0, //!< Use custom 3x3 gamut remapping matrix
    VIDEO_COMP_ALGO_GAMUT_REMAPPING_CUSTOM_01        = VIDEO_COMP_ALGO_CUSTOM_BASE+1, //!< Use custom 3x3 gamut remapping matrix
    VIDEO_COMP_ALGO_2DTO3D_CUSTOM_00                 = VIDEO_COMP_ALGO_CUSTOM_BASE+0, //!< Use custom 2Dto3D conversion
    VIDEO_COMP_ALGO_2DTO3D_CUSTOM_01                 = VIDEO_COMP_ALGO_CUSTOM_BASE+1, //!< Use custom 2Dto3D conversion
    VIDEO_COMP_ALGO_3D_ANALYSIS_CUSTOM_00            = VIDEO_COMP_ALGO_CUSTOM_BASE+0, //!< Use custom 3DAnalysis algorithm
    VIDEO_COMP_ALGO_3D_ANALYSIS_CUSTOM_01            = VIDEO_COMP_ALGO_CUSTOM_BASE+1, //!< Use custom 3DAnalysis algorithm
    VIDEO_COMP_ALGO_FRC_CUSTOM_00                    = VIDEO_COMP_ALGO_CUSTOM_BASE+0, //!< Use custom frame rate converter
    VIDEO_COMP_ALGO_FRC_CUSTOM_01                    = VIDEO_COMP_ALGO_CUSTOM_BASE+1, //!< Use custom frame rate converter
} NVAPI_VIDEO_COMPONENT_ALGORITHM;


//! \ingroup vidcontrol
//! Bitmasks for video components' enable at various resolutions
//! Used in NVAPI_GET_VIDEO_STATE_COMPONENT and NVAPI_SET_VIDEO_STATE_COMPONENT.
typedef enum _NVAPI_VIDEO_COMPONENT_ENABLE
{
    VIDEO_COMP_ENA_480i     = 0x00000001, //!<  component is enabled at 480i video resolution
    VIDEO_COMP_ENA_480p     = 0x00000002, //!<  component is enabled at 480p video resolution
    VIDEO_COMP_ENA_576i     = 0x00000004, //!<  component is enabled at 576i video resolution
    VIDEO_COMP_ENA_576p     = 0x00000008, //!<  component is enabled at 576p video resolution
    VIDEO_COMP_ENA_720p     = 0x00000010, //!<  component is enabled at 720p video resolution
    VIDEO_COMP_ENA_1080i    = 0x00000020, //!<  component is enabled at 1080i video resolution
    VIDEO_COMP_ENA_1080p    = 0x00000040, //!<  component is enabled at 1080p video resolution
} NVAPI_VIDEO_COMPONENT_ENABLE;


//! \ingroup vidcontrol
//! Packet that facilitates retrieving information about a video component \n
//! Used in NvAPI_GetVideoState().
typedef struct _NVAPI_GET_VIDEO_STATE_COMPONENT
{
    NvU32   version;                    //!<  (IN)  NVAPI version that matches NVAPI_GET_VIDEO_STATE_COMPONENT_VER
    NvU32   componentID;                //!<  (IN)  identify the individual component, one of NVAPI_VIDEO_STATE_COMPONENT_xxx enums
    NvU32   bIsSupported        : 1;    //!<  (OUT) set if this component feature is supported
    NvU32   bIsOverridenByUser  : 1;    //!<  (OUT) set if component is overriden by user's choice
    NvU32   reserved1           : 30;   //!<  (OUT) reserved for future expansion
    NvU32   isEnabled;                  //!<  (OUT) set if component is enabled, one or more of NVAPI_VIDEO_COMPONENT_ENABLE bitmasks
    NvU32   minValue;                   //!<  (OUT) min valid value
    NvU32   maxValue;                   //!<  (OUT) max valid value
    NvU32   totalSteps;                 //!<  (OUT) number of steps between min and max
    NvU32   defaultValue;               //!<  (OUT) pre-defined NVIDIA default
    NvU32   unityValue;                 //!<  (OUT) unity is the disable value for a component
    NvU32   currentValueActive;         //!<  (OUT) value in use
    NvU64   defaultAlgo;                //!<  (OUT) default algo, one or more of #NVAPI_VIDEO_COMPONENT_ALGORITHM enums
    NvU64   currentAlgoActive;          //!<  (OUT) Algorithm in use, one or more of #NVAPI_VIDEO_COMPONENT_ALGORITHM enums
    union
    {
        NvU64 qwReserved[9];            
        struct
        {
            NvU32   dwAppKey;           //!< (IN) Secret key to authenticate the caller, used ONLY in NvAPI_SetVideoState()
            NvU32   bTopPriority   : 1; //!< (OUT)Indicates that these settings have precedence over D3D NvAPI settings;  valid ONLY in NvAPI_GetVideoState()
            NvU32   bHasCustomAlgo : 1; //!< (OUT)Indicates whether Out-of-process application has custom algorithm data
            NvU32   bReserved      : 30;//!< (OUT)Reserved for expansion   
            struct
            {
                NvU64   pData;          //!< (IN) Buffer to hold the retrieved custom algorithm data
                NvU32   dwSize;         //!< (IN) Size in Bytes of the above buffer, must be <= NVAPI_VIDEO_STATE_MAX_CUSTOM_ALGO_SIZE.
            } customAlgo;
        } appInfo; 
    }; 
} NVAPI_GET_VIDEO_STATE_COMPONENT;

//! \ingroup vidcontrol
//! Used in NVAPI_GET_VIDEO_STATE_COMPONENT.
#define NVAPI_GET_VIDEO_STATE_COMPONENT_VER  MAKE_NVAPI_VERSION(NVAPI_GET_VIDEO_STATE_COMPONENT,1)

//! \ingroup vidcontrol
//! Return status after attempting to set a video component
//! Used in NVAPI_SET_VIDEO_STATE_COMPONENT.
typedef enum _NVAPI_VIDEO_COMP_RETURN_STATUS
{
    VIDEO_COMP_STATUS_SUCCESS                   = 0x00000000, //!< Video component is set successfully
    VIDEO_COMP_STATUS_UNSUCCESSFUL              = 0x00000001, //!< Failed to set video component
    VIDEO_COMP_STATUS_COMPONENT_NOT_SUPPORTED   = 0x00000002, //!< Video component is not supported
    VIDEO_COMP_STATUS_VALUE_OUT_OF_RANGE        = 0x00000004, //!< Video component's value is invalid and does not fall into range
    VIDEO_COMP_STATUS_ALGO_NOT_RECOGNIZED       = 0x00000008, //!< Video component's algorithm is invalid 
    VIDEO_COMP_STATUS_OVERRIDDEN_BY_USER        = 0x00000010, //!< Request not completed because of user-mandated override
    VIDEO_COMP_STATUS_Y_GAMMA_ENABLED           = 0x00000020, //!< Cannot set RGB-gamma because Y-Gamma is already enabled
    VIDEO_COMP_STATUS_RGB_GAMMA_ENABLED         = 0x00000040, //!< Cannot set Y-gamma because RGB-Gamma is already enabled
} NVAPI_VIDEO_COMP_RETURN_STATUS;

// Packet containing information to allow setting the video component

#define NVAPI_VIDEO_STATE_MAX_CUSTOM_ALGO_SIZE 128

//! \ingroup vidcontrol
//! Used in NvAPI_SetVideoState().
typedef struct _NVAPI_SET_VIDEO_STATE_COMPONENT
{
    NvU32   version;                        //!< (IN) NVAPI version that matches NVAPI_SET_VIDEO_STATE_COMPONENT_VER
    NvU32   componentID;                    //!< (IN) identify the individual component, one of NVAPI_VIDEO_STATE_COMPONENT_xxx enums
    NvU32   enable;                         //!< (IN) flag to enable setting of component, one or more of NVAPI_VIDEO_COMPONENT_ENABLE bitmasks
    NvU32   setToValue;                     //!< (IN) value to use
    NvU64   setToAlgo;                      //!< (IN) algorithm to use
    NvU32   retStatus;                      //!< (OUT) result of video-component-set operation; a combination of VIDEO_COMP_STATUS_xxx bitmasks 
    NvU32   reserved;

    union
    {
        NvU64 qwReserved[4];
        struct
        {
            NvU32   dwAppKey;               //!< (IN) Secret key to authenticate the caller, ONLY used in NvAPI_SetVideoState
            NvU32   bTopPriority       : 1; //!< (IN) Force these settings to have priority over D3D NvAPI settings, ONLY valid in NvAPI_GetVideoState
            NvU32   bHasCustomAlgo     : 1; //!< (IN) Out-of-process application has custom algorithm data
            NvU32   bReserved          : 30;//!< (IN) reserved for expansion
            struct
            {
                NvU64   pData;              //!< (IN) (Used only when bHasCustomAlgo == 1) Pointer to the custom algorithm data.
                NvU32   dwSize;             //!< (IN) (Used only when bHasCustomAlgo == 1) Size in Bytes of the custom algorithm data, must be <= NVAPI_VIDEO_STATE_MAX_CUSTOM_ALGO_SIZE.
            } customAlgo;
        } appInfo; 
    }; 
} NVAPI_SET_VIDEO_STATE_COMPONENT;


//! \ingroup vidcontrol
//! Used in NVAPI_SET_VIDEO_STATE_COMPONENT.
#define NVAPI_SET_VIDEO_STATE_COMPONENT_VER  MAKE_NVAPI_VERSION(NVAPI_SET_VIDEO_STATE_COMPONENT,1)

#endif // ifndef NV_VIDEO_COMPONENTS_DEFINE



//!
//! \ingroup vidcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetVideoState(NvDisplayHandle hNvDisplay, NVAPI_GET_VIDEO_STATE_COMPONENT *pGetVidStateComp);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetVideoState
//
//! DESCRIPTION:    This API that allows callers to set a particular video state component. It is the responsibility
//!                  of the caller to fill the secret application key that enables authentication of the caller.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 171.08
//!
//! \param [in]     hNvDisplay(IN)     NVIDIA Display selection \n
//!                                    It can be #NVAPI_DEFAULT_HANDLE or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]     pSetVidStateComp   NVAPI_SET_VIDEO_STATE_COMPONENT packet containing 
//!                                    a valid component ID and a valid application secret key.                                  
//! \retval ::NVAPI_OK  
//! \retval ::NVAPI_ERROR
//! \retval ::NVAPI_INVALID_ARGUMENT
//!
//! \ingroup vidcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetVideoState(NvDisplayHandle hNvDisplay, NVAPI_SET_VIDEO_STATE_COMPONENT *pSetVidStateComp);



///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetFrameRateNotify
//
//! \fn NvAPI_SetFrameRateNotify(NvDisplayHandle hNvDisplay, NVAPI_FRAME_RATE_NOTIFY_INFO* pFRNotifyInfo)
//! DESCRIPTION:     This API signals the driver to turn on/off notification to
//!                  the service application of the video frame rate. 
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 175.76  
//!
//!  \param [in]    hNvDisplay     NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated 
//!                                from NvAPI_EnumNVidiaDisplayHandle().
//!  \param [in]    pFRNotifyInfo  Pointer to the supplied NVAPI_FRAME_RATE_NOTIFY_INFO struct.
//!
//!  \retval ::NVAPI_OK 
//!  \retval ::NVAPI_ERROR 
//!  \retval ::NVAPI_INVALID_ARGUMENT
//!
//!  \ingroup vidcontrol
//
///////////////////////////////////////////////////////////////////////////////    


//! \ingroup vidcontrol
//! Structure containing the video frame rate notification instructions - used in NvAPI_SetFrameRateNotify()
typedef struct _NVAPI_FRAME_RATE_NOTIFY_INFO
{
    NvU32   version;                //!< (IN) Version of this struct constructed from the macro #NVAPI_FRAME_RATE_NOTIFY_INFO_VER
    NvU64   hWnd;                   //!< (IN) The window handle of the service application handling the RR adjust
    NvU32   bEnable         : 1;    //!< (IN) To turn feature ON/OFF
    NvU32   bReserved       : 31;   //!< (IN/OUT) Reserved for later use
} NVAPI_FRAME_RATE_NOTIFY_INFO;


//! \ingroup vidcontrol
//! Macro for constructing the version field of  NVAPI_FRAME_RATE_NOTIFY_INFO
#define NVAPI_FRAME_RATE_NOTIFY_INFO_VER  MAKE_NVAPI_VERSION(NVAPI_FRAME_RATE_NOTIFY_INFO,1)


//! \ingroup vidcontrol
NVAPI_INTERFACE NvAPI_SetFrameRateNotify(NvDisplayHandle hNvDisplay, NVAPI_FRAME_RATE_NOTIFY_INFO* pFRNotifyInfo);



///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetPVExtName
//
//! DESCRIPTION:     This API specifies the name of the PureVideo extension DLL
//!                  to be used when custom algorithms are
//!                  enabled via NvAPI_SetVideoState() calls.
//!
//  SUPPORTED OS: Windows XP and higher
//! 
//! \since Version 185.74
//!
//! \param [in]    hNvDisplay   NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated
//!                             from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]    szDllName    Name of the DLL to be used for custom algorithms
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//!
//! \ingroup vidcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetPVExtName(NvDisplayHandle hNvDisplay, const char *szDllName);



///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetPVExtName
//
//! DESCRIPTION:     This API retrieves the name of the PureVideo extension DLL
//!                  to be used when custom algorithms are
//!                  enabled via NvAPI_SetVideoState() calls.
//!
//  SUPPORTED OS: Windows XP and higher
//! 
//! \since Version 190.60
//!
//! \param [in]      hNvDisplay  NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE or a handle enumerated
//!                              from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]      szDllName   Name of the DLL that's currently registered with the driver
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//!
//! \ingroup vidcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetPVExtName(NvDisplayHandle hNvDisplay, NvAPI_String szDllName);


//  SUPPORTED OS: Windows XP and higher

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SetPVExtProfile
//
//! DESCRIPTION:     This API specifies the profile number that the PureVideo 
//!                  extension DLL should use.
//!
//!
//  SUPPORTED OS: Windows XP and higher
//! 
//! \since Version 190.60
//!
//! \param [in]     hNvDisplay  NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE
//!                             or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]     dwProfile   The profile number 
//!
//! \retval ::NVAPI_OK                completed request
//! \retval ::NVAPI_ERROR             miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT  Invalid input parameter
//!
//! \ingroup vidcontrol 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetPVExtProfile(NvDisplayHandle hNvDisplay, NvU32 dwProfile);


//  SUPPORTED OS: Windows XP and higher

///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_GetPVExtProfile
//
//! DESCRIPTION:     This API retrieves the profile number that the PureVideo 
//!                  extension DLL is set to use.
//!
//  SUPPORTED OS: Windows XP and higher
//! 
//! \since Version 190.60
//!
//! \param [in]     hNvDisplay    NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE
//!                               or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle()
//! \param [out]    pProfile      The returned profile number
//!
//! \retval ::NVAPI_OK                completed request
//! \retval ::NVAPI_ERROR             miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT  Invalid input parameter
//!
//! \ingroup vidcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetPVExtProfile(NvDisplayHandle hNvDisplay, NvU32* pProfile);



#ifndef NV_STEREO_VIDEO_FORMAT_DEFINE
#define NV_STEREO_VIDEO_FORMAT_DEFINE


//! \ingroup vidcontrol
typedef enum _NV_STEREO_VIDEO_FORMAT
{
    NV_STEREO_VIDEO_FORMAT_NOT_STEREO         = 0,

    NV_STEREO_VIDEO_FORMAT_SIDE_BY_SIDE_LR    = 1,
    NV_STEREO_VIDEO_FORMAT_SIDE_BY_SIDE_RL    = 2,
    NV_STEREO_VIDEO_FORMAT_TOP_BOTTOM_LR      = 3,
    NV_STEREO_VIDEO_FORMAT_TOP_BOTTOM_RL      = 4,
    NV_STEREO_VIDEO_FORMAT_ROW_INTERLEAVE_LR  = 5,
    NV_STEREO_VIDEO_FORMAT_ROW_INTERLEAVE_RL  = 6,
    NV_STEREO_VIDEO_FORMAT_TWO_FRAMES_LR      = 7,
    NV_STEREO_VIDEO_FORMAT_MONO_PLUS_OFFSET   = 8,

    NV_STEREO_VIDEO_FORMAT_LAST               = 9,
} NV_STEREO_VIDEO_FORMAT;

#endif // NV_STEREO_VIDEO_FORMAT_DEFINE

//! \ingroup vidcontrol
typedef struct _NV_VIDEO_STEREO_INFO {
    NvU32                     dwVersion;         //!< Must be NV_VIDEO_STEREO_INFO_VER
    NV_STEREO_VIDEO_FORMAT    eFormat;           //!< Stereo format of the surface (please note that format NV_STEREO_VIDEO_FORMAT_TWO_FRAMES_LR is invalid for this NvAPI)
    NvS32                     sViewOffset;       //!< Signed offset of each view (positive offset indicating left view is shifted left)
    NvU32                     bStereoEnable : 1; //!< Whether stereo rendering should be enabled (if FALSE, only left view will be used)
} NV_VIDEO_STEREO_INFO;

//! \ingroup vidcontrol
//! Macro for constructing the version field of ::_NV_VIDEO_STEREO_INFO
#define NV_VIDEO_STEREO_INFO_VER  MAKE_NVAPI_VERSION(NV_VIDEO_STEREO_INFO, 1)



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION_NAME:   NvAPI_VideoSetStereoInfo
//
//!   DESCRIPTION:   This API specifies the stereo format of the video source.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]      hNvDisplay   NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE
//!                               or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in]      pStereoInfo  The stereo format.
//!
//! \retval ::NVAPI_OK                completed request
//! \retval ::NVAPI_ERROR             miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT  Invalid input parameter
//!
//! \ingroup vidcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VideoSetStereoInfo(NvDisplayHandle hNvDisplay, NV_VIDEO_STEREO_INFO* pStereoInfo);

//  SUPPORTED OS: Windows XP and higher
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION_NAME:   NvAPI_VideoGetStereoInfo
//
//!   DESCRIPTION:   This API retrieves the stereo format of the video source (as set by 
//!                  NvAPI_VideoSetStereoInfo()). 
//!
//! \param [in]     hNvDisplay        NVIDIA Display selection. It can be NVAPI_DEFAULT_HANDLE
//!                                   or a handle enumerated from NvAPI_EnumNVidiaDisplayHandle().
//! \param [in,out] pStereoInfo       The stereo format returned
//!
//! \retval ::NVAPI_OK                 completed request
//! \retval ::NVAPI_ERROR              miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT   Invalid input parameter
//!
//! \ingroup vidcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VideoGetStereoInfo(NvDisplayHandle hNvDisplay, NV_VIDEO_STEREO_INFO* pStereoInfo);





////////////////////////////////////////////////////////////////////////////////////////
//
// MOSAIC allows a multi display target output scanout on a single source. 
//
// SAMPLE of MOSAIC 1x4 topo with 8 pixel horizontal overlap
//
//+-------------------------++-------------------------++-------------------------++-------------------------+
//|                         ||                         ||                         ||                         |
//|                         ||                         ||                         ||                         |
//|                         ||                         ||                         ||                         |
//|        DVI1             ||           DVI2          ||         DVI3            ||          DVI4           |
//|                         ||                         ||                         ||                         |
//|                         ||                         ||                         ||                         |
//|                         ||                         ||                         ||                         |
//|                         ||                         ||                         ||                         |
//+-------------------------++-------------------------++-------------------------++-------------------------+


//! \addtogroup mosaicapi
//! @{

#define NVAPI_MAX_MOSAIC_DISPLAY_ROWS       8
#define NVAPI_MAX_MOSAIC_DISPLAY_COLUMNS    8

#define NV_MOSAIC_MAX_DISPLAYS      (64)

//
// These bits are used to describe the validity of a topo.
//
#define NV_MOSAIC_TOPO_VALIDITY_VALID               0x00000000  //!< The topology is valid
#define NV_MOSAIC_TOPO_VALIDITY_MISSING_GPU         0x00000001  //!< Not enough SLI GPUs were found to fill the entire
                                                                //! topology. hPhysicalGPU will be 0 for these.
#define NV_MOSAIC_TOPO_VALIDITY_MISSING_DISPLAY     0x00000002  //!< Not enough displays were found to fill the entire
                                                                //! topology. displayOutputId will be 0 for these.
#define NV_MOSAIC_TOPO_VALIDITY_MIXED_DISPLAY_TYPES 0x00000004  //!< The topoogy is only possible with displays of the same
                                                                //! NV_GPU_OUTPUT_TYPE. Check displayOutputIds to make
                                                                //! sure they are all CRTs, or all DFPs.


//
//! This structure defines the topology details.
typedef struct 
{
    NvU32                version;              //!< Version of this structure
    NvLogicalGpuHandle   hLogicalGPU;          //!< Logical GPU for this topology 
    NvU32                validityMask;         //!< 0 means topology is valid with the current hardware.
                                               //! If not 0, inspect bits against NV_MOSAIC_TOPO_VALIDITY_*.
    NvU32                rowCount;             //!< Number of displays in a row
    NvU32                colCount;             //!< Number of displays in a column

    struct 
    {
        NvPhysicalGpuHandle hPhysicalGPU;      //!< Physical GPU to be used in the topology (0 if GPU missing)
        NvU32               displayOutputId;   //!< Connected display target (0 if no display connected)
        NvS32               overlapX;          //!< Pixels of overlap on left of target: (+overlap, -gap)
        NvS32               overlapY;          //!< Pixels of overlap on top of target: (+overlap, -gap)

    } gpuLayout[NVAPI_MAX_MOSAIC_DISPLAY_ROWS][NVAPI_MAX_MOSAIC_DISPLAY_COLUMNS];

} NV_MOSAIC_TOPO_DETAILS;

//! Macro for constructing te vesion field of NV_MOSAIC_TOPO_DETAILS
#define NVAPI_MOSAIC_TOPO_DETAILS_VER         MAKE_NVAPI_VERSION(NV_MOSAIC_TOPO_DETAILS,1)


//
//! These values refer to the different types of Mosaic topologies that are possible.  When
//! getting the supported Mosaic topologies, you can specify one of these types to narrow down
//! the returned list to only those that match the given type.
typedef enum
{
    NV_MOSAIC_TOPO_TYPE_ALL,                          //!< All mosaic topologies
    NV_MOSAIC_TOPO_TYPE_BASIC,                        //!< Basic Mosaic topologies
    NV_MOSAIC_TOPO_TYPE_PASSIVE_STEREO,               //!< Passive Stereo topologies
    NV_MOSAIC_TOPO_TYPE_SCALED_CLONE,                 //!< Not supported at this time
    NV_MOSAIC_TOPO_TYPE_PASSIVE_STEREO_SCALED_CLONE,  //!< Not supported at this time
    NV_MOSAIC_TOPO_TYPE_MAX,                          //!< Always leave this at end of the enum
} NV_MOSAIC_TOPO_TYPE;


//
//! This is a complete list of supported Mosaic topologies.
//!
//! Using a "Basic" topology combines multiple monitors to create a single desktop.
//!
//! Using a "Passive" topology combines multiples monitors to create a passive stereo desktop.
//! In passive stereo, two identical topologies combine - one topology is used for the right eye and the other identical //! topology (targeting different displays) is used for the left eye.  \n  
//! NOTE: common\inc\nvEscDef.h shadows a couple PASSIVE_STEREO enums.  If this
//!       enum list changes and effects the value of NV_MOSAIC_TOPO_BEGIN_PASSIVE_STEREO
//!       please update the corresponding value in nvEscDef.h
typedef enum
{
    NV_MOSAIC_TOPO_NONE,

    // 'BASIC' topos start here
    //
    // The result of using one of these Mosaic topos is that multiple monitors
    // will combine to create a single desktop.
    //
    NV_MOSAIC_TOPO_BEGIN_BASIC,
    NV_MOSAIC_TOPO_1x2_BASIC = NV_MOSAIC_TOPO_BEGIN_BASIC,
    NV_MOSAIC_TOPO_2x1_BASIC,
    NV_MOSAIC_TOPO_1x3_BASIC,
    NV_MOSAIC_TOPO_3x1_BASIC,
    NV_MOSAIC_TOPO_1x4_BASIC,
    NV_MOSAIC_TOPO_4x1_BASIC,
    NV_MOSAIC_TOPO_2x2_BASIC,
    NV_MOSAIC_TOPO_2x3_BASIC,
    NV_MOSAIC_TOPO_2x4_BASIC,
    NV_MOSAIC_TOPO_3x2_BASIC,
    NV_MOSAIC_TOPO_4x2_BASIC,
    NV_MOSAIC_TOPO_1x5_BASIC,
    NV_MOSAIC_TOPO_1x6_BASIC,
    NV_MOSAIC_TOPO_7x1_BASIC,

    // Add padding for 10 more entries. 6 will be enough room to specify every
    // possible topology with 8 or fewer displays, so this gives us a little
    // extra should we need it.
    NV_MOSAIC_TOPO_END_BASIC = NV_MOSAIC_TOPO_7x1_BASIC + 9,

    // 'PASSIVE_STEREO' topos start here
    //
    // The result of using one of these Mosaic topos is that multiple monitors
    // will combine to create a single PASSIVE STEREO desktop.  What this means is
    // that there will be two topos that combine to create the overall desktop.
    // One topo will be used for the left eye, and the other topo (of the
    // same rows x cols), will be used for the right eye.  The difference between
    // the two topos is that different GPUs and displays will be used.
    //
    NV_MOSAIC_TOPO_BEGIN_PASSIVE_STEREO,    // value shadowed in nvEscDef.h
    NV_MOSAIC_TOPO_1x2_PASSIVE_STEREO = NV_MOSAIC_TOPO_BEGIN_PASSIVE_STEREO,
    NV_MOSAIC_TOPO_2x1_PASSIVE_STEREO,
    NV_MOSAIC_TOPO_1x3_PASSIVE_STEREO,
    NV_MOSAIC_TOPO_3x1_PASSIVE_STEREO,
    NV_MOSAIC_TOPO_1x4_PASSIVE_STEREO,
    NV_MOSAIC_TOPO_4x1_PASSIVE_STEREO,
    NV_MOSAIC_TOPO_2x2_PASSIVE_STEREO,
    NV_MOSAIC_TOPO_END_PASSIVE_STEREO = NV_MOSAIC_TOPO_2x2_PASSIVE_STEREO + 4,


    //
    // Total number of topos.  Always leave this at the end of the enumeration.
    //
    NV_MOSAIC_TOPO_MAX  //! Total number of topologies.

} NV_MOSAIC_TOPO;


//
//! This is a "topology brief" structure.  It tells you what you need to know about
//! a topology at a high level. A list of these is returned when you query for the
//! supported Mosaic information.
//!
//! If you need more detailed information about the topology, call
//! NvAPI_Mosaic_GetTopoGroup() with the topology value from this structure.
typedef struct 
{
    NvU32                        version;            //!< Version of this structure
    NV_MOSAIC_TOPO               topo;               //!< The topology
    NvU32                        enabled;            //!< 1 if topo is enabled, else 0
    NvU32                        isPossible;         //!< 1 if topo *can* be enabled, else 0

} NV_MOSAIC_TOPO_BRIEF;

//! Macro for constructing the version field of NV_MOSAIC_TOPO_BRIEF
#define NVAPI_MOSAIC_TOPO_BRIEF_VER         MAKE_NVAPI_VERSION(NV_MOSAIC_TOPO_BRIEF,1)


//
//! Basic per-display settings that are used in setting/getting the Mosaic mode
typedef struct 
{
    NvU32                        version;            //!< Version of this structure
    NvU32                        width;              //!< Per-display width
    NvU32                        height;             //!< Per-display height
    NvU32                        bpp;                //!< Bits per pixel
    NvU32                        freq;               //!< Display frequency
} NV_MOSAIC_DISPLAY_SETTING;

//! Macro for constructing the version field of NV_MOSAIC_DISPLAY_SETTING
#define NVAPI_MOSAIC_DISPLAY_SETTING_VER         MAKE_NVAPI_VERSION(NV_MOSAIC_DISPLAY_SETTING,1)


//
// Set a reasonable max number of display settings to support
// so arrays are bound.
//
#define NV_MOSAIC_DISPLAY_SETTINGS_MAX 40  //!< Set a reasonable maximum number of display settings to support
                                           //! so arrays are bound.


//
//! This structure is used to contain a list of supported Mosaic topologies
//! along with the display settings that can be used.
typedef struct 
{
    NvU32                       version;                                         //!< Version of this structure
    NvU32                       topoBriefsCount;                                 //!< Number of topologies in below array
    NV_MOSAIC_TOPO_BRIEF        topoBriefs[NV_MOSAIC_TOPO_MAX];                  //!< List of supported topologies with only brief details
    NvU32                       displaySettingsCount;                            //!< Number of display settings in below array
    NV_MOSAIC_DISPLAY_SETTING   displaySettings[NV_MOSAIC_DISPLAY_SETTINGS_MAX]; //!< List of per display settings possible

} NV_MOSAIC_SUPPORTED_TOPO_INFO;

//! Macro forconstructing  the version field of NV_MOSAIC_SUPPORTED_TOPO_INFO
#define NVAPI_MOSAIC_SUPPORTED_TOPO_INFO_VER         MAKE_NVAPI_VERSION(NV_MOSAIC_SUPPORTED_TOPO_INFO,1)


//
// Indices to use to access the topos array within the mosaic topology
#define NV_MOSAIC_TOPO_IDX_DEFAULT       0

#define NV_MOSAIC_TOPO_IDX_LEFT_EYE      0
#define NV_MOSAIC_TOPO_IDX_RIGHT_EYE     1
#define NV_MOSAIC_TOPO_NUM_EYES          2


//
//! This defines the maximum number of topos that can be in a topo group.
//! At this time, it is set to 2 because our largest topo group (passive
//! stereo) only needs 2 topos (left eye and right eye).
//!
//! If a new topo group with more than 2 topos is added above, then this
//! number will also have to be incremented.
#define NV_MOSAIC_MAX_TOPO_PER_TOPO_GROUP 2 


//
//! This structure defines a group of topologies that work together to create one
//! overall layout.  All of the supported topologies are represented with this
//! structure.
//!
//! For example, a 'Passive Stereo' topology would be represented with this
//! structure, and would have separate topology details for the left and right eyes.
//! The count would be 2.  A 'Basic' topology is also represented by this structure,
//! with a count of 1.
//!
//! The structure is primarily used internally, but is exposed to applications in a
//! read-only fashion because there are some details in it that might be useful
//! (like the number of rows/cols, or connected display information).  A user can
//! get the filled-in structure by calling NvAPI_Mosaic_GetTopoGroup().
//!
//! You can then look at the detailed values within the structure.  There are no
//! entrypoints which take this structure as input (effectively making it read-only).
typedef struct 
{
    NvU32                      version;              //!< Version of this structure
    NV_MOSAIC_TOPO_BRIEF       brief;                //!< The brief details of this topo
    NvU32                      count;                //!< Number of topos in array below
    NV_MOSAIC_TOPO_DETAILS     topos[NV_MOSAIC_MAX_TOPO_PER_TOPO_GROUP];

} NV_MOSAIC_TOPO_GROUP;

//! Macro for constructing the version field of NV_MOSAIC_TOPO_GROUP
#define NVAPI_MOSAIC_TOPO_GROUP_VER         MAKE_NVAPI_VERSION(NV_MOSAIC_TOPO_GROUP,1)

//! @}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_GetSupportedTopoInfo
//
//! DESCRIPTION:     This API returns information on the topologies and display resolutions
//!                  supported by Mosaic mode.
//!
//!                  NOTE: Not all topologies returned can be set immediately.
//!                        See 'OUT' Notes below.
//!
//!                  Once you get the list of supported topologies, you can call
//!                  NvAPI_Mosaic_GetTopoGroup() with one of the Mosaic topologies if you need
//!                  more information about it.
//!
//!     <b>'IN' Notes:</b>  pSupportedTopoInfo->version must be set before calling this function.
//!                  If the specified version is not supported by this implementation,
//!                  an error will be returned (NVAPI_INCOMPATIBLE_STRUCT_VERSION).
//!
//!     <b>'OUT' Notes:</b> Some of the topologies returned might not be valid for one reason or
//!                  another.  It could be due to mismatched or missing displays.  It
//!                  could also be because the required number of GPUs is not found.
//!                  At a high level, you can see if the topology is valid and can be enabled
//!                  by looking at the pSupportedTopoInfo->topoBriefs[xxx].isPossible flag.
//!                  If this is true, the topology can be enabled. If it
//!                  is false, you can find out why it cannot be enabled by getting the
//!                  details of the topology via NvAPI_Mosaic_GetTopoGroup().  From there,
//!                  look at the validityMask of the individual topologies.  The bits can
//!                  be tested against the NV_MOSAIC_TOPO_VALIDITY_* bits.
//!
//!                  It is possible for this function to return NVAPI_OK with no topologies
//!                  listed in the return structure.  If this is the case, it means that
//!                  the current hardware DOES support Mosaic, but with the given configuration
//!                  no valid topologies were found.  This most likely means that SLI was not
//!                  enabled for the hardware. Once enabled, you should see valid topologies
//!                  returned from this function.
//!    
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//!
//!
//! \param [in,out]  pSupportedTopoInfo  Information about what topologies and display resolutions
//!                                      are supported for Mosaic.
//! \param [in]      type                The type of topologies the caller is interested in
//!                                      getting. See NV_MOSAIC_TOPO_TYPE for possible values.
//!
//! \retval ::NVAPI_OK                          No errors in returning supported topologies.
//! \retval ::NVAPI_NOT_SUPPORTED               Mosaic is not supported with the existing hardware.
//! \retval ::NVAPI_INVALID_ARGUMENT            One or more arguments passed in are invalid.
//! \retval ::NVAPI_API_NOT_INTIALIZED          The NvAPI API needs to be initialized first.
//! \retval ::NVAPI_NO_IMPLEMENTATION           This entrypoint not available.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION The version of the structure passed in is not
//                                              compatible with this entry point.
//! \retval ::NVAPI_ERROR:                      Miscellaneous error occurred.
//!
//! \ingroup mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Mosaic_GetSupportedTopoInfo(NV_MOSAIC_SUPPORTED_TOPO_INFO *pSupportedTopoInfo, NV_MOSAIC_TOPO_TYPE type);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_GetTopoGroup
//
//! DESCRIPTION:     This API returns a structure filled with the details
//!                  of the specified Mosaic topology.
//!
//!                  If the pTopoBrief passed in matches the current topology,
//!                  then information in the brief and group structures
//!                  will reflect what is current. Thus the brief would have
//!                  the current 'enable' status, and the group would have the
//!                  current overlap values. If there is no match, then the
//!                  returned brief has an 'enable' status of FALSE (since it
//!                  is obviously not enabled), and the overlap values will be 0.
//!
//!     <b>'IN' Notes:</b>  pTopoGroup->version must be set before calling this function.
//!                  If the specified version is not supported by this implementation,
//!                  an error will be returned (NVAPI_INCOMPATIBLE_STRUCT_VERSION).
//!
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//!
//! \param [in]     pTopoBrief        The topology for getting the details
//!                                   This must be one of the topology briefs
//!                                   returned from NvAPI_Mosaic_GetSupportedTopoInfo().
//! \param [in,out] pTopoGroup        The topology details matching the brief
//!
//! \retval ::NVAPI_OK                          Details were retrieved successfully.
//! \retval ::NVAPI_NOT_SUPPORTED               Mosaic is not supported with the existing hardware.
//! \retval ::NVAPI_INVALID_ARGUMENT            One or more argumentss passed in are invalid.
//! \retval ::NVAPI_API_NOT_INTIALIZED          The NvAPI API needs to be initialized first.
//! \retval ::NVAPI_NO_IMPLEMENTATION           This entrypoint not available.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION The version of the structure passed in is not
//                                              compatible with this entry point.
//! \retval ::NVAPI_ERROR:                      Miscellaneous error occurred.
//!
//! \ingroup mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Mosaic_GetTopoGroup(NV_MOSAIC_TOPO_BRIEF *pTopoBrief, NV_MOSAIC_TOPO_GROUP *pTopoGroup);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_GetOverlapLimits
//
//! DESCRIPTION:     This API returns the X and Y overlap limits required if
//!                  the given Mosaic topology and display settings are to be used.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//!
//! \param [in]   pTopoBrief          The topology for getting limits
//!                                   This must be one of the topo briefs
//!                                   returned from NvAPI_Mosaic_GetSupportedTopoInfo().
//! \param [in]   pDisplaySetting     The display settings for getting the limits.
//!                                   This must be one of the settings
//!                                   returned from NvAPI_Mosaic_GetSupportedTopoInfo().
//! \param [out]  pMinOverlapX        X overlap minimum
//! \param [out]  pMaxOverlapX        X overlap maximum
//! \param [out]  pMinOverlapY        Y overlap minimum
//! \param [out]  pMaxOverlapY        Y overlap maximum
//!
//! \retval ::NVAPI_OK                          Details were retrieved successfully.
//! \retval ::NVAPI_NOT_SUPPORTED               Mosaic is not supported with the existing hardware.
//! \retval ::NVAPI_INVALID_ARGUMENT            One or more argumentss passed in are invalid.
//! \retval ::NVAPI_API_NOT_INTIALIZED          The NvAPI API needs to be initialized first.
//! \retval ::NVAPI_NO_IMPLEMENTATION           This entrypoint not available.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION The version of the structure passed in is not
//!                                             compatible with this entry point.
//! \retval ::NVAPI_ERROR                       Miscellaneous error occurred.
//!
//! \ingroup mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Mosaic_GetOverlapLimits(NV_MOSAIC_TOPO_BRIEF *pTopoBrief, NV_MOSAIC_DISPLAY_SETTING *pDisplaySetting, NvS32 *pMinOverlapX, NvS32 *pMaxOverlapX, NvS32 *pMinOverlapY, NvS32 *pMaxOverlapY);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_SetCurrentTopo
//
//! DESCRIPTION:     This API sets the Mosaic topology and performs a mode switch 
//!                  using the given display settings.
//!
//!                  If NVAPI_OK is returned, the current Mosaic topology was set
//!                  correctly.  Any other status returned means the
//!                  topology was not set, and remains what it was before this
//!                  function was called.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//!
//! \param [in]     pTopoBrief        The topology to set. This must be one of the topologies returned from
//!                                   NvAPI_Mosaic_GetSupportedTopoInfo(), and it must have an isPossible value of 1.
//! \param [in]     pDisplaySetting   The per display settings to be used in the Mosaic mode. This must be one of the
//!                                   settings returned from NvAPI_Mosaic_GetSupportedTopoInfo().
//! \param [in]     overlapX          The pixel overlap to use between horizontal displays (use positive a number for
//!                                   overlap, or a negative number to create a gap.) If the overlap is out of bounds
//!                                   for what is possible given the topo and display setting, the overlap will be clamped.
//! \param [in]     overlapY          The pixel overlap to use between vertical displays (use positive a number for
//!                                   overlap, or a negative number to create a gap.) If the overlap is out of bounds for
//!                                   what is possible given the topo and display setting, the overlap will be clamped.
//! \param [in]     enable            If 1, the topology being set will also be enabled, meaning that the mode set will
//!                                   occur.  \n
//!                                   If 0, you don't want to be in Mosaic mode right now, but want to set the current
//!                                   Mosaic topology so you can enable it later with NvAPI_Mosaic_EnableCurrentTopo().
//!
//! \retval  ::NVAPI_OK                          The Mosaic topology was set.
//! \retval  ::NVAPI_NOT_SUPPORTED               Mosaic is not supported with the existing hardware.
//! \retval  ::NVAPI_INVALID_ARGUMENT            One or more argumentss passed in are invalid.
//! \retval  ::NVAPI_TOPO_NOT_POSSIBLE           The topology passed in is not currently possible.
//! \retval  ::NVAPI_API_NOT_INTIALIZED          The NvAPI API needs to be initialized first.
//! \retval  ::NVAPI_NO_IMPLEMENTATION           This entrypoint not available.
//! \retval  ::NVAPI_INCOMPATIBLE_STRUCT_VERSION The version of the structure passed in is not
//!                                              compatible with this entrypoint.
//! \retval  ::NVAPI_MODE_CHANGE_FAILED          There was an error changing the display mode.
//! \retval  ::NVAPI_ERROR                       Miscellaneous error occurred.
//!
//! \ingroup mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Mosaic_SetCurrentTopo(NV_MOSAIC_TOPO_BRIEF *pTopoBrief, NV_MOSAIC_DISPLAY_SETTING *pDisplaySetting, NvS32 overlapX, NvS32 overlapY, NvU32 enable);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_GetCurrentTopo
//
//! DESCRIPTION:     This API returns information for the current Mosaic topology.
//!                  This includes topology, display settings, and overlap values.
//!
//!                  You can call NvAPI_Mosaic_GetTopoGroup() with the topology
//!                  if you require more information.
//!
//!                  If there isn't a current topology, then pTopoBrief->topo will
//!                  be NV_MOSAIC_TOPO_NONE.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//!
//! \param [out]     pTopoBrief       The current Mosaic topology
//! \param [out]     pDisplaySetting  The current per-display settings
//! \param [out]     pOverlapX        The pixel overlap between horizontal displays
//! \param [out]     pOverlapY        The pixel overlap between vertical displays
//!
//! \retval ::NVAPI_OK                          Success getting current info.
//! \retval ::NVAPI_NOT_SUPPORTED               Mosaic is not supported with the existing hardware.
//! \retval ::NVAPI_INVALID_ARGUMENT            One or more argumentss passed in are invalid.
//! \retval ::NVAPI_API_NOT_INTIALIZED          The NvAPI API needs to be initialized first.
//! \retval ::NVAPI_NO_IMPLEMENTATION           This entry point not available.
//! \retval ::NVAPI_ERROR                       Miscellaneous error occurred.
//!
//! \ingroup mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Mosaic_GetCurrentTopo(NV_MOSAIC_TOPO_BRIEF *pTopoBrief, NV_MOSAIC_DISPLAY_SETTING *pDisplaySetting, NvS32 *pOverlapX, NvS32 *pOverlapY);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_EnableCurrentTopo
//
//! DESCRIPTION:     This API enables or disables the current Mosaic topology
//!                  based on the setting of the incoming 'enable' parameter.
//!
//!                  An "enable" setting enables the current (previously set) Mosaic topology.
//!                  Note that when the current Mosaic topology is retrieved, it must have an isPossible value of 1 or
//!                  an error will occur.
//!
//!                  A "disable" setting disables the current Mosaic topology.
//!                  The topology information will persist, even across reboots.
//!                  To re-enable the Mosaic topology, call this function
//!                  again with the enable parameter set to 1.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//!
//! \param [in]   enable               1 to enable the current Mosaic topo, 0 to disable it.
//!
//! \retval ::NVAPI_OK                 The Mosaic topo was enabled/disabled.
//! \retval ::NVAPI_NOT_SUPPORTED      Mosaic is not supported with the existing hardware.
//! \retval ::NVAPI_INVALID_ARGUMENT   One or more arguments passed in are invalid.
//! \retval ::NVAPI_TOPO_NOT_POSSIBLE  The current topology is not currently possible.
//! \retval ::NVAPI_MODE_CHANGE_FAILED There was an error changing the display mode.
//! \retval ::NVAPI_ERROR:             Miscellaneous error occurred.
//!
//! \ingroup mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Mosaic_EnableCurrentTopo(NvU32 enable);



//! \ingroup mosaicapi
//! @{
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_SetGridTopology
//
//! \fn NvAPI_Mosaic_SetGridTopology(NV_MOSAIC_GRID_TOPO *pGridTopology, NvU32 enable)
//! DESCRIPTION:     This API sets a grid-based Mosaic topology and does a 
//!                  mode change using the given display settings.
//!
//!                  If NVAPI_OK is returned, the requested Mosaic topo was set
//!                  correctly.  Any other status returned means the
//!                  topo was not set, and remains what it was before this
//!                  function was called. It is possible for this API to return
//!                  success, but the displays enabled have an issue, leading
//!                  to a black screen.
//!
//!                  Note: Not all exposed features are available on all 
//!                  platforms.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]     pGridTopology     The topology details to set.
//! \param [in]     enable            If 1, the topo being set will also be enabled,
//!                                   meaning that the mode set will occur.  
//!                                   Passing a 0 means you don't want to be in
//!                                   Mosaic mode right now, but want to set the current
//!                                   Mosaic topo so you can enable it later with
//!                                   NvAPI_Mosaic_EnableCurrentTopo().
//!
//! \return    This API can return any of the error codes enumerated in #NvAPI_Status. If there are return error codes with 
//!            specific meaning for this API, they are listed below.
//! \retval ::NVAPI_NO_ACTIVE_SLI_TOPOLOGY        GPUs are not currently in SLI
//! \retval ::NVAPI_INVALID_COMBINATION           The current SLI set does not support Mosaic SLI or Immersive Gaming
//! \retval ::NVAPI_SLI_RENDERING_MODE_NOTALLOWED The current display configuration cannot be used for the requested 
//!                                               mosaic topology (for instance, having the displays only in the center 
//!                                               of the SLI topology), or does not support center display
//!                                               acceleration
//
///////////////////////////////////////////////////////////////////////////////


//
//! This structure is used for applying topologies using NvAPI_Mosaic_SetCurrentTopoEx()
//! and retrieving them with NvAPI_Mosaic_GetCurrentTopology()
typedef struct
{
    NvU32                       displayId;              //!< DisplayID of the display
    NvS32                       overlapX;               //!< (+overlap, -gap)
    NvS32                       overlapY;               //!< (+overlap, -gap)
    NV_ROTATE                   rotation;               //!< Rotation of display
    NvU32                       cloneGroup;             //!< Reserved, must be 0
} NV_MOSAIC_GRID_TOPO_DISPLAY;

typedef struct
{
    NvU32                       version;                            //!< Version of this structure
    NvU32                       rows;                               //!< Number of rows
    NvU32                       columns;                            //!< Number of columns
    NvU32                       displayCount;                       //!< Number of display details
    NvU32                       applyWithBezelCorrect : 1;          //!< When enabling and doing the modeset, do we switch to the bezel-corrected resolution
    NvU32                       immersiveGaming : 1;                //!< Enable as immersive gaming instead of Mosaic SLI (for Quadro-boards only)
    NvU32                       baseMosaic : 1;                     //!< Enable as Base Mosaic (Panoramic) instead of Mosaic SLI (for NVS and Quadro-boards only)
    NvU32                       driverReloadAllowed : 1;            //!< If necessary, reloading the driver is permitted (for Vista and above only). Will not be persisted. Value undefined on get.
    NvU32                       acceleratePrimaryDisplay : 1;       //!< Enable SLI acceleration on the primary display while in single-wide mode (For Immersive Gaming only). Will not be persisted. Value undefined on get.
    NvU32                       reserved : 27;                      //!< Reserved, must be 0
     NV_MOSAIC_GRID_TOPO_DISPLAY displays[NV_MOSAIC_MAX_DISPLAYS];  //!< Displays are done as [(row * columns) + column]
    NV_MOSAIC_DISPLAY_SETTING   displaySettings;                    //!< Display settings
} NV_MOSAIC_GRID_TOPO;

//! Macro for constructing the version field of ::NV_MOSAIC_GRID_TOPO
#define NV_MOSAIC_GRID_TOPO_VER         MAKE_NVAPI_VERSION(NV_MOSAIC_GRID_TOPO,1)

NVAPI_INTERFACE NvAPI_Mosaic_SetGridTopology(NV_MOSAIC_GRID_TOPO *pGridTopology, NvU32 enable);

//! @}

//! \ingroup mosaicapi
//! @{
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_GetMosaicCapabilities
//
//! \fn NvAPI_Mosaic_GetMosaicCapabilities(NV_GPU_VALID_GPU_TOPOLOGIES *pSliTopology, NV_MOSAIC_CAPS *pCaps) 
//! DESCRIPTION:     This API returns a set of capabilities based on a provided
//!                  SLI topology. The pSliTopology is the same parameter as
//!                  used for NvAPI_SetGpuTopologies. If more than one SLI 
//!                  topology is marked to be active, only the first active 
//!                  topology will be validated.
//!                  At least one topology in pSliTopology must have the 
//!                  NV_GPU_TOPOLOGY_ACTIVE flag set. This does not require the
//!                  topology to be currently active, but marks which topology
//!                  will have the capabilities retrieved for.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]       pSliTopology    SLI topology for capabilties query
//! \param [out]      pCaps           Capabilities for Mosaic SLI
//!
//! \retval ::NVAPI_OK                          Capabilities have been returned.
//! \retval ::NVAPI_INVALID_ARGUMENT            One or more argumenets passed in are invalid.
//! \retval ::NVAPI_API_NOT_INTIALIZED          The NvAPI API needs to be initialized first.
//! \retval ::NVAPI_NO_ACTIVE_SLI_TOPOLOGY      No topology had the ::NV_GPU_TOPOLOGY_ACTIVE flag marked.
//! \retval ::NVAPI_NO_IMPLEMENTATION           This entrypoint is not available.
//! \retval ::NVAPI_ERROR                       Miscellaneous error occurred.
//
///////////////////////////////////////////////////////////////////////////////

//! See NvAPI_Mosaic_GetMosaicCapabilities{}.
typedef struct
{
    NvU32  version;                          //!< Must be set to ::NV_MOSAIC_CAPS_VER.
    NvU32  bSupportsImmersiveGaming : 1;     //!< These GPUs could enter immersive gaming if proper display are attached.
    NvU32  bSupportsMosaicSli : 1;           //!< Supports QuadroPlex Mosaic SLI.
    NvU32  bSupportsGlobalRotation : 1;      //!< All displays must share rotation.
    NvU32  bSupportsPerDisplayRotation : 1;  //!< Each display may have a different rotation.
    NvU32  bSupportsPerDisplaySettings : 1;  //!< Each display may have a different resolution.
    NvU32  bSupportsOverlap : 1;             //!< Overlap is supported (+overlap).
    NvU32  bSupportsGaps : 1;                //!< Gap is supported (-overlap).
    NvU32  bSupportsUnevenGapping : 1;       //!< Allows for each display to have different overlap values.
    NvU32  bSupportsBaseMosaic : 1;          //!< These GPUs could enter base Mosaic if proper display are attached
    NvU32  reserved : 23;                    //!< Reserved, must be 0

} NV_MOSAIC_CAPS;

//! Macro for constructing the version field of NV_MOSAIC_CAPS
#define NV_MOSAIC_CAPS_VER                  MAKE_NVAPI_VERSION(NV_MOSAIC_CAPS,1)

NVAPI_INTERFACE NvAPI_Mosaic_GetMosaicCapabilities(NV_GPU_VALID_GPU_TOPOLOGIES *pSliTopology, NV_MOSAIC_CAPS *pCaps);
//! @}



//! \ingroup mosaicapi
//! @{
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_GetDisplayCapabilities
//
//! \fn NvAPI_Mosaic_GetDisplayCapabilities(NV_MOSAIC_DISPLAY_CAPS *pDisplayCaps)
//! DESCRIPTION:     This API returns a set of capabilities based on a provided
//!                  displays. The caller uses this function to determine if a
//!                  given set of displays, regardless of SLI topology, would
//!                  support Mosaic SLI / Immersive Gaming. This API can also
//!                  assist in identifying if a display would be compatible, 
//!                  but is currently plugged into the wrong connector of a GPU.
//! 
//!                  Problem flags are SLI-agnostic. This API will not verify
//!                  that all displays are on the same SLI topology.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in,out]      pDisplayCaps   List of display capabilities and 
//!                                     problem codes, as well as list of
//!                                     valid display settings shared by the
//!                                     selected monitors.
//!
//! \retval ::NVAPI_OK                          The display capabilities have been returned.
//! \retval ::NVAPI_INVALID_ARGUMENT            One or more arguments passed in are invalid.
//! \retval ::NVAPI_API_NOT_INTIALIZED          The NvAPI API needs to be initialized first.
//! \retval ::NVAPI_NO_IMPLEMENTATION           This entrypoint is not available.
//! \retval ::NVAPI_ERROR                       Miscellaneous error occurred.
//
///////////////////////////////////////////////////////////////////////////////

#define NV_MOSAIC_DISPLAYCAPS_PROBLEM_DISPLAY_ON_INVALID_GPU        NV_BIT(0)
#define NV_MOSAIC_DISPLAYCAPS_PROBLEM_DISPLAY_ON_WRONG_CONNECTOR    NV_BIT(1)
#define NV_MOSAIC_DISPLAYCAPS_PROBLEM_NO_COMMON_TIMINGS             NV_BIT(2)
#define NV_MOSAIC_DISPLAYCAPS_PROBLEM_NO_EDID_AVAILABLE             NV_BIT(3)
#define NV_MOSAIC_DISPLAYCAPS_PROBLEM_MISMATCHED_OUTPUT_TYPE        NV_BIT(4)
#define NV_MOSAIC_DISPLAYCAPS_PROBLEM_NO_DISPLAY_CONNECTED          NV_BIT(5)
#define NV_MOSAIC_DISPLAYCAPS_PROBLEM_NO_GPU_TOPOLOGY               NV_BIT(6)
#define NV_MOSAIC_DISPLAYCAPS_PROBLEM_NOT_SUPPORTED                 NV_BIT(7)

//! See ::NV_MOSAIC_DISPLAY_CAPS.
typedef struct
{
    NvU32  displayId;                       //!< (IN) DisplayID of display
    NvU32  problemFlags;                    //!< (OUT) Any problem flags found (NV_MOSAIC_DISPLAYCAPS_PROBLEM_*)
    NvU32  supportsRotation : 1;            //!< (OUT) This display can be rotated
    NvU32  reserved : 31;                   //!< (OUT) reserved
} NV_MOSAIC_DISPLAY_DETAILS;

//! See NvAPI_Mosaic_GetDisplayCapabilities().
typedef struct
{
    NvU32  version;                         //!< (IN) Must be NV_MOSAIC_DISPLAY_CAPS_VER
    NvU32  displayCount;                    //!< (IN) Number of valid displays in displays array
    NV_MOSAIC_DISPLAY_DETAILS   displays[NVAPI_MAX_DISPLAYS];   //!< (IN/OUT) Array of individual displays, the first 
                                                                //!< display will be used to validate the remaining displays 
                                                                //!< for EDID matching. There is other order dependency.
    NvU32  displaySettingsCount;            //!< (OUT) Number of valid display settings found
    NV_MOSAIC_DISPLAY_SETTING   displaySettings[NV_MOSAIC_DISPLAY_SETTINGS_MAX];    //!< (OUT) List of common timings
    NvU32  problemFlags;                    //!< (OUT) Any problem flags found (NV_MOSAIC_DISPLAYCAPS_PROBLEM_*)
} NV_MOSAIC_DISPLAY_CAPS_V1;


#define NV_MOSAIC_DISPLAY_CAPS_MAX      1600

//! See NvAPI_Mosaic_GetDisplayCapabilities().
typedef struct
{
    NvU32  version;                         //!< (IN) Must be NV_MOSAIC_DISPLAY_CAPS_VER
    NvU32  displayCount;                    //!< (IN) Number of valid displays in displays array
    NV_MOSAIC_DISPLAY_DETAILS   displays[NVAPI_MAX_DISPLAYS];   //!< (IN/OUT) Array of individual displays, the first
                                                                //!< display will be used to validate the remaining displays
                                                                //!< for EDID matching. There is other order dependency.
    NvU32  displaySettingsCount;            //!< (OUT) Number of valid display settings found
    NV_MOSAIC_DISPLAY_SETTING   displaySettings[NV_MOSAIC_DISPLAY_CAPS_MAX];    // (OUT) List of common timings
    NvU32  problemFlags;                    //!< (OUT) Any problem flags found (NV_MOSAIC_DISPLAYCAPS_PROBLEM_*)
} NV_MOSAIC_DISPLAY_CAPS_V2;


typedef NV_MOSAIC_DISPLAY_CAPS_V2           NV_MOSAIC_DISPLAY_CAPS;

//! Macro for constructing the version field of ::NV_MOSAIC_DISPLAY_CAPS_V1
#define NV_MOSAIC_DISPLAY_CAPS_VER1         MAKE_NVAPI_VERSION(NV_MOSAIC_DISPLAY_CAPS_V1,1)

//! Macro for constructing the version field of ::NV_MOSAIC_DISPLAY_CAPS_V2
#define NV_MOSAIC_DISPLAY_CAPS_VER2         MAKE_NVAPI_VERSION(NV_MOSAIC_DISPLAY_CAPS_V2,2)

//! Macro for constructing the version field of ::NV_MOSAIC_DISPLAY_CAPS
#define NV_MOSAIC_DISPLAY_CAPS_VER          NV_MOSAIC_DISPLAY_CAPS_VER2


NVAPI_INTERFACE NvAPI_Mosaic_GetDisplayCapabilities(NV_MOSAIC_DISPLAY_CAPS *pDisplayCaps);

//! @}



//! \ingroup mosaicapi
//! @{
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_EnumGridTopologies
//
//! \fn NvAPI_Mosaic_EnumGridTopologies(NvU32 index, NvU32 flags, NV_MOSAIC_GRID_TOPO *pGridTopology, NvU8* bEnabled)
//! DESCRIPTION:     This API retrieves the current grid topology information
//!                  for Mosaic SLI.
//!
//!                  If there has been no existing call to set a topology
//!                  (either enabled or disable), this call will return 
//!                  ::NVAPI_DATA_NOT_FOUND. If the existing data is no longer
//!                  valid due to display connectors being moved, or GPUs
//!                  being moved, ::NVAPI_DATA_NOT_FOUND will also be returned.
//!                  This API does not validate whether SLI is currently 
//!                  enabled.
//!
//!                  When enumerating all current grid topologies, ::NVAPI_DATA_NOT_FOUND will
//!                  be returned when there are no more topologies.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]     index               A zero-based index to enumerate
//!                                     multiple applied grid topologies.
//! \param [in]     flags               This field controls which data is returned.
//!                                          By default, all known topologies are returned.
//!                                          A known topology is either an active topology
//!                                          or a topology which has been disabled and not
//!                                          included in another topology. Unless specified,
//!                                          topology validity will be applied during enum,
//!                                          and topologies which are no longer valid will
//!                                          not be returned (ex: a monitor was disconnected).
//!                                          Only topologies which have been enabled in the 
//!                                          past will be returned, this API will not 
//!                                          enumerate all possible topologies. To determine 
//!                                          all possible topologies, manually create each 
//!                                          possible topology and validate each using 
//!                                          NvAPI_Mosaic_GetDisplayCapabilities. 
//!
//! \param [in,out] pGridTopology       The topology details of the current
//!                                     topology. On input, version must be
//!                                     properly set, all other fields are ignored.
//! \param [out] bEnabled            (May pass in NULL to ignore)
//!                                     -1 if Mosaic is enabled, 
//!                                     -0 if Mosaic is currently disabled.
//!
//! \retval ::NVAPI_OK                          Mosaic topology was set.
//! \retval ::NVAPI_NOT_SUPPORTED               Mosaic is not supported with the existing hardware.
//! \retval ::NVAPI_INVALID_ARGUMENT            One or more arguments passed in are invalid.
//! \retval ::NVAPI_API_NOT_INTIALIZED          The NvAPI API needs to be initialized first.
//! \retval ::NVAPI_NO_IMPLEMENTATION           This entrypoint is not available.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION The version of the structure passed in is not
//!                                             compatible with this entrypoint.
//! \retval ::NVAPI_DATA_NOT_FOUND              There was no existing valid topology information.
//! \retval ::NVAPI_ERROR                       Miscellaneous error occurred.
//
///////////////////////////////////////////////////////////////////////////////


#define NVAPI_MOSAIC_ENUMGRIDTOPOS_FLAG_ACTIVE_ONLY       NV_BIT(0)
#define NVAPI_MOSAIC_ENUMGRIDTOPOS_FLAG_NO_VALIDATION     NV_BIT(1)

NVAPI_INTERFACE NvAPI_Mosaic_EnumGridTopologies(NvU32 index, NvU32 flags, NV_MOSAIC_GRID_TOPO *pGridTopology, NvU8* bEnabled);

//! @}



//  SUPPORTED OS: Windows Vista and higher
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_GetDisplayViewportsByResolution
//
//! DESCRIPTION:     This API returns the viewports that would be applied on
//!                  the requested display.
//!
//! \param [in]      displayId       Display ID of a single display in the active
//!                                  mosaic topology to query.
//! \param [in]      srcWidth        Width of full display topology. If both
//!                                  width and height are 0, the current
//!                                  resolution is used.
//! \param [in]      srcHeight       Height of full display topology. If both
//!                                  width and height are 0, the current
//!                                  resolution is used.
//! \param [out]     viewports       Array of NV_RECT viewports which represent
//!                                  the displays as identified in
//!                                  NvAPI_Mosaic_EnumGridTopologies. If the
//!                                  requested resolution is a single-wide
//!                                  resolution, only viewports[0] will
//!                                  contain the viewport details, regardless
//!                                  of which display is driving the display.
//! \param [out]     bezelCorrected  Returns 1 if the requested resolution is
//!                                  bezel corrected. May be NULL.
//!
//! \retval ::NVAPI_OK                          Capabilties have been returned.
//! \retval ::NVAPI_INVALID_ARGUMENT            One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INTIALIZED          The NvAPI API needs to be initialized first
//! \retval ::NVAPI_MOSAIC_NOT_ACTIVE           The display does not belong to an active Mosaic Topology
//! \retval ::NVAPI_NO_IMPLEMENTATION           This entrypoint not available
//! \retval ::NVAPI_ERROR                       Miscellaneous error occurred
//!
//! \ingroup mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Mosaic_GetDisplayViewportsByResolution(NvU32 displayId, NvU32 srcWidth, NvU32 srcHeight, NV_RECT viewports[NV_MOSAIC_MAX_DISPLAYS], NvU8* bezelCorrected);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Mosaic_GetMosaicViewports
//
//! DESCRIPTION:     This API returns the viewport information for a mosaic mode
//!                  passed in by the user.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]      pGridTopology        A grid topology to calculate the
//!                                       viewport information. Does not need
//!                                       to be currently active.
//! \param [in]      baseWidth            Width of a single display in the 
//!                                       topology.
//! \param [in]      baseHeight           Height of a single display in the 
//!                                       topology.
//! \param [in]      bezelCorrected       If set to 1, returns the details for
//!                                       bezel corrected. If set to 0, returns
//!                                       the details without bezel correction.
//! \param [out]     totalWidth           May be NULL. If passed, will return
//!                                       the total width of the mosaic.
//! \param [out]     totalHeight          May be NULL. If passed, will return
//!                                       the total height of the mosaic.
//! \param [out]     viewports            Array will be filled in with the
//!                                       individual viewport details for
//!                                       the topology.
//! 
//! \retval ::NVAPI_OK                          Capabilities have been returned.
//! \retval ::NVAPI_INVALID_ARGUMENT            One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED         The NvAPI API needs to be initialized first
//! \retval ::NVAPI_NO_IMPLEMENTATION           This entrypoint not available
//! \retval ::NVAPI_ERROR                       Miscellaneous error occurred
//! \ingroup mosaciapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Mosaic_GetMosaicViewports(NV_MOSAIC_GRID_TOPO *pGridTopology, 
                                                NvU32 baseWidth, 
                                                NvU32 baseHeight, 
                                                NvU8 bezelCorrected, 
                                                NvU32* totalWidth, 
                                                NvU32* totalHeight, 
                                                NV_RECT viewports[NV_MOSAIC_MAX_DISPLAYS]);



////////////////////////////////////////////////////////////////////////////////////////
//
// ###########################################################################
// DELME_RUSS - DELME_RUSS - DELME_RUSS - DELME_RUSS - DELME_RUSS - DELME_RUSS
//
//   Below is the Phase 1 Mosaic stuff, the Phase 2 stuff above is what will remain
//   once Phase 2 is complete.  For a small amount of time, the two will co-exist.  As
//   soon as apps (nvapichk, NvAPITestMosaic, and CPL) are updated to use the Phase 2
//   entrypoints, the code below will be deleted.
//
// DELME_RUSS - DELME_RUSS - DELME_RUSS - DELME_RUSS - DELME_RUSS - DELME_RUSS
// ###########################################################################
//
// Supported topos 1x4, 4x1 and 2x2 to start with.
// 
// Selected scan out targets can be one per GPU or more than one on the same GPU.
//
// SAMPLE of MOSAIC 1x4 SCAN OUT TOPO with 8 pixel horizontal overlap
//
//+-------------------------++-------------------------++-------------------------++-------------------------+
//|                         ||                         ||                         ||                         |
//|                         ||                         ||                         ||                         |
//|                         ||                         ||                         ||                         |
//|        DVI1             ||           DVI2          ||         DVI3            ||          DVI4           |
//|                         ||                         ||                         ||                         |
//|                         ||                         ||                         ||                         |
//|                         ||                         ||                         ||                         |
//|                         ||                         ||                         ||                         |
//+-------------------------++-------------------------++-------------------------++-------------------------+


//! \addtogroup mosaicapi
//! @{

//! Used in NV_MOSAIC_TOPOLOGY.
#define NVAPI_MAX_MOSAIC_DISPLAY_ROWS       8

//! Used in NV_MOSAIC_TOPOLOGY.
#define NVAPI_MAX_MOSAIC_DISPLAY_COLUMNS    8 

//! Used in NV_MOSAIC_TOPOLOGY.
#define NVAPI_MAX_MOSAIC_TOPOS              16

//! Used in NvAPI_GetCurrentMosaicTopology() and NvAPI_SetCurrentMosaicTopology().
typedef struct 
{
    NvU32 version;                             //!< Version number of the mosaic topology
    NvU32 rowCount;                            //!< Horizontal display count
    NvU32 colCount;                            //!< Vertical display count

    struct 
    {
        NvPhysicalGpuHandle hPhysicalGPU;      //!< Physical GPU to be used in the topology
        NvU32               displayOutputId;   //!< Connected display target
        NvS32               overlapX;          //!< Pixels of overlap on the left of target: (+overlap, -gap)
        NvS32               overlapY;          //!< Pixels of overlap on the top of target: (+overlap, -gap)

    } gpuLayout[NVAPI_MAX_MOSAIC_DISPLAY_ROWS][NVAPI_MAX_MOSAIC_DISPLAY_COLUMNS];

} NV_MOSAIC_TOPOLOGY;

//! Used in NV_MOSAIC_TOPOLOGY.
#define NVAPI_MOSAIC_TOPOLOGY_VER         MAKE_NVAPI_VERSION(NV_MOSAIC_TOPOLOGY,1)

//! Used in NvAPI_GetSupportedMosaicTopologies().
typedef struct 
{
    NvU32                   version;                                    
    NvU32                   totalCount;                     //!< Count of valid topologies
    NV_MOSAIC_TOPOLOGY      topos[NVAPI_MAX_MOSAIC_TOPOS];  //!< Maximum number of topologies

} NV_MOSAIC_SUPPORTED_TOPOLOGIES;

//! Used in NV_MOSAIC_SUPPORTED_TOPOLOGIES. 
#define NVAPI_MOSAIC_SUPPORTED_TOPOLOGIES_VER         MAKE_NVAPI_VERSION(NV_MOSAIC_SUPPORTED_TOPOLOGIES,1)

//!@}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GetSupportedMosaicTopologies
//
//! DESCRIPTION:     This API returns all valid Mosaic topologies.
//!
//  SUPPORTED OS: Windows XP
//!
//! \since Version: R177_00
//!
//! \param [out] pMosaicTopos                   An array of valid Mosaic topologies.
//!
//! \retval      NVAPI_OK                       Call succeeded; 1 or more topologies were returned
//! \retval      NVAPI_INVALID_ARGUMENT         One or more arguments are invalid
//! \retval      NVAPI_MIXED_TARGET_TYPES       Mosaic topology is only possible with all targets of the same NV_GPU_OUTPUT_TYPE.
//! \retval      NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found
//! \retval      NVAPI_NOT_SUPPORTED            Mosaic is not supported with GPUs on this system.
//! \retval      NVAPI_NO_ACTIVE_SLI_TOPOLOGY   SLI is not enabled, yet needs to be, in order for this function to succeed.
//!
//! \ingroup     mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetSupportedMosaicTopologies(NV_MOSAIC_SUPPORTED_TOPOLOGIES *pMosaicTopos);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GetCurrentMosaicTopology
//
//! DESCRIPTION:     This API gets the current Mosaic topology.
//!
//  SUPPORTED OS: Windows XP
//!
//! \since Version: R177_00
//!
//! \param [out] pMosaicTopo                    The current Mosaic topology
//! \param [out] pEnabled                       TRUE if returned topology is currently enabled, else FALSE
//!
//! \retval      NVAPI_OK                       Call succeeded
//! \retval      NVAPI_INVALID_ARGUMENT         One or more arguments are invalid
//! \retval      NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found
//! \retval      NVAPI_NOT_SUPPORTED            Mosaic is not supported with GPUs on this system.
//! \retval      NVAPI_NO_ACTIVE_SLI_TOPOLOGY   SLI is not enabled, yet needs to be, in order for this function to succeed.
//!
//! \ingroup     mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GetCurrentMosaicTopology(NV_MOSAIC_TOPOLOGY *pMosaicTopo, NvU32 *pEnabled);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_SetCurrentMosaicTopology
//
//! DESCRIPTION:     This API sets the Mosaic topology, and enables it so that the
//!                  Mosaic display settings are enumerated upon request.
//!
//  SUPPORTED OS: Windows XP
//!
//! \since Version: R177_00
//!
//! \param [in]  pMosaicTopo                    A valid Mosaic topology
//!
//! \retval      NVAPI_OK                       Call succeeded
//! \retval      NVAPI_INVALID_ARGUMENT         One or more arguments are invalid
//! \retval      NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found
//! \retval      NVAPI_NOT_SUPPORTED            Mosaic is not supported with GPUs on this system.
//! \retval      NVAPI_NO_ACTIVE_SLI_TOPOLOGY   SLI is not enabled, yet needs to be, in order for this function to succeed.
//!
//! \ingroup     mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetCurrentMosaicTopology(NV_MOSAIC_TOPOLOGY *pMosaicTopo);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_EnableCurrentMosaicTopology
//
//! DESCRIPTION:    This API enables or disables the current Mosaic topology. 
//!                 When enabling, the last Mosaic topology will be set.
//!
//!                  - If enabled, enumeration of display settings will include valid Mosaic resolutions.  
//!                  - If disabled, enumeration of display settings will not include Mosaic resolutions.
//!
//  SUPPORTED OS: Windows XP
//!
//! \since Version: R177_00
//!
//! \param [in]  enable                         TRUE to enable the Mosaic Topology, FALSE to disable it.
//!
//! \retval      NVAPI_OK                       Call succeeded
//! \retval      NVAPI_INVALID_ARGUMENT         One or more arguments are invalid
//! \retval      NVAPI_NVIDIA_DEVICE_NOT_FOUND  No NVIDIA GPU driving a display was found
//! \retval      NVAPI_NOT_SUPPORTED            Mosaic is not supported with GPUs on this system.
//! \retval      NVAPI_NO_ACTIVE_SLI_TOPOLOGY   SLI is not enabled, yet needs to be, in order for this function to succeed.
//!
//! \ingroup     mosaicapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_EnableCurrentMosaicTopology(NvU32 enable);





//! \ingroup hybridapi
#define NVAPI_MAX_3D_Apps 128

//! \ingroup hybridapi
//! Structure to get application processIds and processNames. \n
//! Used in NvAPI_QueryNonMigratableApps(). 
typedef struct
{
  NvU32 version;    //!< Structure version
  NvU32 processId;
  NvAPI_ShortString   processName;
}NV_3D_APP_INFO_V1;

typedef struct
{
  NvU32 version;    // Structure version
  NvU32 processId;
  NvAPI_LongString   processName;
} NV_3D_APP_INFO_V2;

typedef NV_3D_APP_INFO_V2     NV_3D_APP_INFO;



//! \ingroup hybridapi
//! Used in NV_3D_APP_INFO.
//! Macro for constructing the version field of NV_3D_APP_INFO
//! @{
#define NV_3D_APP_INFO_VER_1  MAKE_NVAPI_VERSION(NV_3D_APP_INFO_V1,1)
#define NV_3D_APP_INFO_VER_2  MAKE_NVAPI_VERSION(NV_3D_APP_INFO_V2,2)
#define NV_3D_APP_INFO_VER    NV_3D_APP_INFO_VER_2
//! @}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_QueryNonMigratableApps
//
//!  This function queries all non-migratable applications which block successful driver reload such 
//!  as for SLI or Hybrid transitions.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 174.32
//!
//! \param [in,out]  apps       Empty structure passed as an input and upon successful exit, 
//!                             contains a list of non-migratable applications and processIDs.
//! \param [in,out]  total      Total number of non-migratable applications currently running in the system.
//! 
//! \retval          NVAPI_OK                 Completed request
//! \retval          NVAPI_ERROR              Miscellaneous error occurred
//! \retval          NVAPI_INVALID_ARGUMENT   Invalid input parameter
//!
//! \ingroup hybridapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_QueryNonMigratableApps(NV_3D_APP_INFO apps[NVAPI_MAX_3D_Apps], NvU32 *total);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_QueryActiveApps
//
//! DESCRIPTION:     Query all applications running on the specified GPU.
//!
//! \param [in]      hPhysicalGpu   Physical GPU Handle for which apps will be retrieved. To get the list of apps on all GPUs, pass NVAPI_DEFAULT_HANDLE.
//! \param [in,out]  apps           Empty structure passed as an input and upon successful exit, it contains list of apps.
//! \param [in,out]  total          Total number of apps currently running.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! RETURN STATUS:
//!                  NVAPI_OK - completed request
//!                  NVAPI_ERROR - miscellaneous error occurred
//!                  NVAPI_INVALID_ARGUMENT - Invalid input parameter
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_QueryActiveApps(NvPhysicalGpuHandle hPhysicalGpu, NV_3D_APP_INFO apps[NVAPI_MAX_3D_Apps] , NvU32 *total);






//! \ingroup hybridapi
typedef struct
{
  NvU32 version;    //!< Structure version
  NvAPI_LongString   appName;
  NvAPI_LongString   friendlyName;
}NV_HYBRID_APP_INFO;

//! \ingroup hybridapi
//! Macro for constructing the version field of NV_HYBRID_APP_INFO 
#define NV_HYBRID_APP_INFO_VER  MAKE_NVAPI_VERSION(NV_HYBRID_APP_INFO,1)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Hybrid_QueryUnblockedNonMigratableApps
//
//! DESCRIPTION:     This API queries the user white-list applications for Hybrid transition.
//!
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in,out]     apps     Empty structure passed as an input and upon successfull exit, it contains list of Unblocked(user white-list) applications.
//! \param [in,out]     total    Total number of applications returned from the white list.
//!
//! \retval ::NVAPI_OK                 completed request.
//! \retval ::NVAPI_ERROR              miscellaneous error occurred.
//! \retval ::NVAPI_INVALID_ARGUMENT   invalid input parameter.
//! \retval ::NVAPI_NO_IMPLEMENTATION  not implemented.
//!
//! \ingroup hybridapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Hybrid_QueryUnblockedNonMigratableApps(NV_HYBRID_APP_INFO apps[NVAPI_MAX_3D_Apps] , NvU32 *total);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Hybrid_QueryBlockedMigratableApps
//
//! DESCRIPTION:     This API queries the user black-list applications for Hybrid transition.
//!
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in,out]     apps     Empty structure passed as an input and upon successfull exit, it contains list of Unblocked(user black-list) applications..
//! \param [in,out]     total    Total number of applications returned from the black list.
//!
//! \retval ::NVAPI_OK                 completed request.
//! \retval ::NVAPI_ERROR              miscellaneous error occurred.
//! \retval ::NVAPI_INVALID_ARGUMENT   invalid input parameter.
//! \retval ::NVAPI_NO_IMPLEMENTATION  not implemented.
//!
//! \ingroup hybridapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Hybrid_QueryBlockedMigratableApps(NV_HYBRID_APP_INFO apps[NVAPI_MAX_3D_Apps] , NvU32 *total);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Hybrid_SetAppMigrationState
//
//! DESCRIPTION:     This API overrides the pre-determined application migration state.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]     app  Application executable name that is to be blocked, unblocked, reset or removed
//! \param [in]     flag Decides on the block, unblock, reset or remove operation. \n
//!                      block =0, unblock =1, reset =2, remove =3
//!
//! \retval ::NVAPI_OK  completed request.
//! \retval ::NVAPI_ERROR  miscellaneous error occurred.
//! \retval ::NVAPI_INVALID_ARGUMENT  invalid input parameter.
//! \retval ::NVAPI_SET_NOT_ALLOWED  the application list override is not allowed.  
//! \retval ::NVAPI_NO_IMPLEMENTATION  not implemented.
//!
//! \ingroup hybridapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Hybrid_SetAppMigrationState(NV_HYBRID_APP_INFO app , NvU32 flag);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_Hybrid_IsAppMigrationStateChangeable
//
//! DESCRIPTION:     This API queries if an application's migration state can be changed by the user.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]      app      Application executable name which user is querying about
//! \param [out]     allowed  Change in migration state of app is allowed or not. \n
//!                           not_allowed =0, allowed =1
//!
//! \retval ::NVAPI_OK  completed request.
//! \retval ::NVAPI_ERROR  miscellaneous error occurred.
//! \retval ::NVAPI_INVALID_ARGUMENT  invalid input parameter.
//!
//! \ingroup hybridapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Hybrid_IsAppMigrationStateChangeable(NV_HYBRID_APP_INFO app , NvU32 *allowed);




//! \ingroup gpugpio
//! Used in NV_GPU_GPIO_LEGAL_PINS.
#define NVAPI_GPIO_SIZE_QUERY_ARRAY 0x00000020


//! \ingroup gpugpio
//! Used in NV_GPU_GPIO_PIN_DATA.
typedef enum 
{
    NVAPI_GPIO_DIRECTION_INPUT,
    NVAPI_GPIO_DIRECTION_OUTPUT
} NVAPI_GPIO_DIRECTION;


//! \ingroup gpugpio
//! Used in NvAPI_GPU_GPIOQueryLegalPins().
typedef struct
{
    NvU32         version;
    NvU32         gpioPinCount;
    NvU32         gpioLegalPins[NVAPI_GPIO_SIZE_QUERY_ARRAY];
} NV_GPU_GPIO_LEGAL_PINS;


//! \ingroup gpugpio
//! Macro for generating the version for structure NV_GPU_GPIO_LEGAL_PINS
#define NV_GPU_GPIO_LEGAL_PINS_VER MAKE_NVAPI_VERSION(NV_GPU_GPIO_LEGAL_PINS,1)


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GPIOQueryLegalPins
//
//! DESCRIPTION:   This function returns the number of available GPIO customer asyncrw instances.
//!
//! HOW TO USE:    
//!                - NV_GPU_GPIO_LEGAL_PINS gpioLegalPins = {0};       
//!                - gpioLegalPins.version = NV_GPU_GPIO_LEGAL_PINS_VER;
//!                - ret = NvAPI_GPU_GPIOQueryLegalPins(hPhysicalGpu, &gpioLegalPins); 
//!
//!                On call success:
//!                - The gpioLegalPins.gpioPinCount would contain some integer (for example, on some G96 GPUs it contains 3)  
//!                - The gpioLegalPins.gpioLegalPins array would contain some values (for example, on some G96 GPUs it contains 0xd, 0xe & 0xf, others
//!                  0) to be used in NvAPI_GPU_GPIOReadFromPin() & NvAPI_GPU_GPIOWriteToPin() calls.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 176.02
//! 
//!  \param [in]   hPhysicalGpu        GPU selection.
//!  \param [out]  pgpioLegalPins      Pointer to a versioned structure to get the number of the pin(s) associated with the 
//!                                    CUSTOMER_ASYNCRW functions and an array of size NVAPI_GPIO_SIZE_QUERY_ARRAY in 
//!                                    which the legal pin numbers are retrieved. These legal pin numbers are to be used
//!                                    while performing read and write operations on the GPIO port.                 
//!                 
//!  \retval ::NVAPI_OK      
//!  \retval ::NVAPI_ERROR            
//!  \retval ::NVAPI_INVALID_HANDLE   physical GPU not found
//!  \retval ::NVAPI_HANDLE_INVALIDATED 
//!  \retval ::NVAPI_NOT_SUPPORTED 
//!  \retval ::NVAPI_INVALID_ARGUMENT 
//!  \retval ::NVAPI_API_NOT_INITIALIZED 
//!  \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION 
//!
//!  \ingroup gpugpio 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GPIOQueryLegalPins(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_GPIO_LEGAL_PINS *pgpioLegalPins);



//! ingroup gpugpio
//! Contains GPIO pin, data, and data direction - used in NvAPI_GPU_GPIOReadFromPin() and NvAPI_GPU_GPIOWriteToPin()
typedef struct
{
    NvU32         version;
    NvU32         gpioPinNumber;
    NvU32         gpioDataReadWrite;
    NVAPI_GPIO_DIRECTION         gpioDirection;
} NV_GPU_GPIO_PIN_DATA;


//! \ingroup gpugpio
//! Macro for generating the version of structure NV_GPU_GPIO_PIN_DATA
#define NV_GPU_GPIO_PIN_DATA_VER MAKE_NVAPI_VERSION(NV_GPU_GPIO_PIN_DATA,1)


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GPIOReadFromPin
//
//! DESCRIPTION:  This function reads the data from the specified GPIO pin.
//!
//! HOW TO USE:    First make a NvAPI_GPU_GPIOQueryLegalPins() call. 
//!                - NV_GPU_GPIO_PIN_DATA gpioReadPin = {0};
//!                - gpioReadPin.version = NV_GPU_GPIO_PIN_DATA_VER;
//!                - gpioReadPingpioDirection = NVAPI_GPIO_DIRECTION_INPUT;
//!                - gpioReadPin.gpioPinNumber = any legal pin data from gpioLegalPins array after successful call to NvAPI_GPU_GPIOQueryLegalPins() 
//!                - ret = NvAPI_GPU_GPIOReadFromPin(hPhysicalGpu, &gpioReadPin);
//!
//!                On call success:
//!                - The gpioReadPingpioDataReadWrite would contain the data value read (0 or 1) from the specified pin.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 176.02
//!
//!  \param [in]  hPhysicalGpu   GPU selection.
//!  \param       pgpioReadPin   Pointer to a versioned structure to pass the GPIO pin number from which the data is
//!                              to be read, the GPIO direction and the variable in which the data is collected.
//!                              The gpioPinNumber parameter is selected from pgpioLegalPins array by calling 
//!                              NvAPI_GPU_GPIOQueryLegalPins().   
//!
//!  \retval ::NVAPI_OK 
//!  \retval ::NVAPI_ERROR 
//!  \retval ::NVAPI_INVALID_HANDLE 
//!  \retval ::NVAPI_HANDLE_INVALIDATED
//!  \retval ::NVAPI_INVALID_ARGUMENT 
//!  \retval ::NVAPI_API_NOT_INITIALIZED
//!  \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION 
//!  \ingroup gpugpio   
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GPIOReadFromPin(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_GPIO_PIN_DATA *pgpioReadPin);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GPIOWriteToPin
//
//! DESCRIPTION:   This function writes data to the specified GPIO pin.
//!
//! HOW TO USE:    First make NvAPI_GPU_GPIOQueryLegalPins() call. 
//!                - NV_GPU_GPIO_PIN_DATA gpioWritePin = {0};
//!                - gpioWritePin.version = NV_GPU_GPIO_PIN_DATA_VER;
//!                - gpioWritePingpioDirection = NVAPI_GPIO_DIRECTION_OUTPUT;
//!                - gpioWritePingpioReadPin.gpioPinNumber = any legal pin data from gpioLegalPins array after successful call to NvAPI_GPU_GPIOQueryLegalPins() 
//!                - gpioWritePin.gpioDataReadWrite = any bit value (0 or 1)
//!                - ret = NvAPI_GPU_GPIOReadFromPin(hPhysicalGpu, &gpioReadPin);
//!
//!                On call success:
//!                - The gpioWritePingpioDataReadWrite value (0 or 1) is written to the specified pin.    
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 176.02
//!
//! \param [in]  hPhysicalGpu(IN)    GPU selection.
//! \param       pgpioWritePin       Pointer to a versioned structure to pass gpio pin number to which the data is
//!                                  to be written, the GPIO direction and the data value. The gpioPinNumber parameter
//!                                  is selected from pgpioLegalPins array by calling NvAPI_GPU_GPIOQueryLegalPins.   
//! 
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_HANDLE 
//! \retval ::NVAPI_HANDLE_INVALIDATED
//! \retval ::NVAPI_INVALID_ARGUMENT 
//! \retval ::NVAPI_API_NOT_INITIALIZED
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION 
//!
//! \ingroup gpugpio                 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GPIOWriteToPin(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_GPIO_PIN_DATA *pgpioWritePin);




/////////////////////////////////////////////////////////////////////////////// 
// 
// FUNCTION NAME: NvAPI_GPU_GetHDCPSupportStatus 
//
//! \fn NvAPI_GPU_GetHDCPSupportStatus(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_GET_HDCP_SUPPORT_STATUS *pGetHDCPSupportStatus)
//! DESCRIPTION: This function returns a GPU's HDCP support status. 
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version: 175.86
//!
//!  \retval ::NVAPI_OK 
//!  \retval ::NVAPI_ERROR 
//!  \retval ::NVAPI_INVALID_ARGUMENT 
//!  \retval ::NVAPI_HANDLE_INVALIDATED 
//!  \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE 
//!  \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION 
// 
////////////////////////////////////////////////////////////////////////////////
    

//! \addtogroup gpu
//! @{


//! HDCP fuse states - used in NV_GPU_GET_HDCP_SUPPORT_STATUS
typedef enum _NV_GPU_HDCP_FUSE_STATE
{
    NV_GPU_HDCP_FUSE_STATE_UNKNOWN  = 0,
    NV_GPU_HDCP_FUSE_STATE_DISABLED = 1,
    NV_GPU_HDCP_FUSE_STATE_ENABLED  = 2,
} NV_GPU_HDCP_FUSE_STATE;


//! HDCP key sources - used in NV_GPU_GET_HDCP_SUPPORT_STATUS
typedef enum _NV_GPU_HDCP_KEY_SOURCE
{
    NV_GPU_HDCP_KEY_SOURCE_UNKNOWN    = 0,
    NV_GPU_HDCP_KEY_SOURCE_NONE       = 1,
    NV_GPU_HDCP_KEY_SOURCE_CRYPTO_ROM = 2,
    NV_GPU_HDCP_KEY_SOURCE_SBIOS      = 3,
    NV_GPU_HDCP_KEY_SOURCE_I2C_ROM    = 4,
    NV_GPU_HDCP_KEY_SOURCE_FUSES      = 5,
} NV_GPU_HDCP_KEY_SOURCE;


//! HDCP key source states - used in NV_GPU_GET_HDCP_SUPPORT_STATUS
typedef enum _NV_GPU_HDCP_KEY_SOURCE_STATE
{
    NV_GPU_HDCP_KEY_SOURCE_STATE_UNKNOWN = 0,
    NV_GPU_HDCP_KEY_SOURCE_STATE_ABSENT  = 1,
    NV_GPU_HDCP_KEY_SOURCE_STATE_PRESENT = 2,
} NV_GPU_HDCP_KEY_SOURCE_STATE;


//! HDPC support status - used in NvAPI_GPU_GetHDCPSupportStatus()
typedef struct 
{
    NvU32                        version;               //! Structure version constucted by macro #NV_GPU_GET_HDCP_SUPPORT_STATUS
    NV_GPU_HDCP_FUSE_STATE       hdcpFuseState;         //! GPU's HDCP fuse state
    NV_GPU_HDCP_KEY_SOURCE       hdcpKeySource;         //! GPU's HDCP key source
    NV_GPU_HDCP_KEY_SOURCE_STATE hdcpKeySourceState;    //! GPU's HDCP key source state    
} NV_GPU_GET_HDCP_SUPPORT_STATUS;


//! Macro for constructing the version for structure NV_GPU_GET_HDCP_SUPPORT_STATUS
#define NV_GPU_GET_HDCP_SUPPORT_STATUS_VER MAKE_NVAPI_VERSION(NV_GPU_GET_HDCP_SUPPORT_STATUS,1)


//! @}


//!  \ingroup gpu 
NVAPI_INTERFACE NvAPI_GPU_GetHDCPSupportStatus(NvPhysicalGpuHandle hPhysicalGpu, NV_GPU_GET_HDCP_SUPPORT_STATUS *pGetHDCPSupportStatus);




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_SetTopologyFocusDisplayAndView
//! DESCRIPTION:     This API works on the active display GPU and lets the calling application switch
//!                  the focus display. It accepts path information to specify single, Clone or Dualview. \n
//!                  Note : If SLI is not active then this API returns ::NVAPI_NO_ACTIVE_SLI_TOPOLOGY.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.03
//!
//! \param [in]     hLogicalGPU              Active logical gpu topology containing more than one physical gpus.
//! \param [in]     focusDisplayOutputId     Connected display output Id on the target GPU which should be focused.
//! \param [in]     pPathInfo                Pointer to NV_VIEW_PATH_INFO, specifying device properties in this view.
//!                                          The first device entry in the array is the physical primary.
//!                                          The device entry with the lowest source ID is the desktop primary.
//! \param [in]     displayView              Display view selected from NV_TARGET_VIEW_MODE.
//!
//! \retval ::NVAPI_OK  
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//! \retval ::NVAPI_NO_ACTIVE_SLI_TOPOLOGY  SLI is not active on this device.
//!
//! \ingroup gputopology
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SetTopologyFocusDisplayAndView(NvLogicalGpuHandle hLogicalGPU, NvU32 focusDisplayOutputId, NV_DISPLAY_PATH_INFO *pPathInfo, NV_TARGET_VIEW_MODE displayView);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_CreateConfigurationProfileRegistryKey
//
//! \fn NvAPI_Stereo_CreateConfigurationProfileRegistryKey(NV_STEREO_REGISTRY_PROFILE_TYPE registryProfileType)
//!
//! DESCRIPTION:   Creates new configuration registry key for current application.
//!
//!                If there is no configuration profile prior to the function call,
//!                this API tries to create a new configuration profile registry key
//!                for a given application and fill it with the default values.
//!                If an application already has a configuration profile registry key, the API does nothing.
//!                The name of the key is automatically set to the name of the executable that calls this function.
//!                Because of this, the executable should have a distinct and unique name.
//!                If the application is using only one version of DirectX, then the default profile type will be appropriate.
//!                If the application is using more than one version of DirectX from the same executable,
//!                it should use the appropriate profile type for each configuration profile.
//!
//! HOW TO USE:    When there is a need for an application to have default stereo parameter values,
//!                use this function to create a key to store the values.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]    registryProfileType  Type of profile the application wants to create. It should be one of the symbolic constants defined in
//!                                     ::NV_STEREO_REGISTRY_PROFILE_TYPE. Any other value will cause function to do nothing and return
//!                                     ::NV_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED.
//!
//! \retval ::NVAPI_OK                                           Key exists in the registry.
//! \retval ::NVAPI_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED   This profile type is not supported.
//! \retval ::NVAPI_STEREO_REGISTRY_ACCESS_FAILED                Access to registry failed.
//! \retval ::NVAPI_API_NOT_INTIALIZED           
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED                       Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
///////////////////////////////////////////////////////////////////////////////


//! \ingroup stereoapi
//! Used in NvAPI_Stereo_CreateConfigurationProfileRegistryKey() 
typedef enum _NV_StereoRegistryProfileType
{
    NVAPI_STEREO_DEFAULT_REGISTRY_PROFILE, //!< Default registry configuration profile.
    NVAPI_STEREO_DX9_REGISTRY_PROFILE,     //!< Separate registry configuration profile for a DirectX 9 executable.
    NVAPI_STEREO_DX10_REGISTRY_PROFILE     //!< Separate registry configuration profile for a DirectX 10 executable.
} NV_STEREO_REGISTRY_PROFILE_TYPE;


//! \ingroup stereoapi
NVAPI_INTERFACE NvAPI_Stereo_CreateConfigurationProfileRegistryKey(NV_STEREO_REGISTRY_PROFILE_TYPE registryProfileType);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_DeleteConfigurationProfileRegistryKey
//
//! DESCRIPTION:   Removes configuration registry key for current application.
//!
//!                If an application already has a configuration profile prior to this function call,
//!                the function attempts to remove the application's configuration profile registry key from the registry.
//!                If there is no configuration profile registry key prior to the function call,
//!                the function does nothing and does not report an error.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]   registryProfileType   Type of profile that the application wants to delete. This should be one of the symbolic 
//!                                     constants defined in ::NV_STEREO_REGISTRY_PROFILE_TYPE. Any other value will cause the function 
//!                                     to do nothing and return ::NV_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED.
//!
//! \retval ::NVAPI_OK                                           Key does not exist in the registry any more.
//! \retval ::NVAPI_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED   This profile type is not supported.
//! \retval ::NVAPI_STEREO_REGISTRY_ACCESS_FAILED                Access to registry failed.
//! \retval ::NVAPI_API_NOT_INTIALIZED                           NVAPI is not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED                       Stereo part of NVAPI is not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_DeleteConfigurationProfileRegistryKey(NV_STEREO_REGISTRY_PROFILE_TYPE registryProfileType);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_SetConfigurationProfileValue
//
//! \fn NvAPI_Stereo_SetConfigurationProfileValue(NV_STEREO_REGISTRY_PROFILE_TYPE registryProfileType, NV_STEREO_REGISTRY_ID valueRegistryID, void *pValue)
//!
//! DESCRIPTION:   This API sets the given parameter value under the application's registry key.
//!
//!                If the value does not exist under the application's registry key,
//!                the value will be created under the key.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     registryProfileType  The type of profile the application wants to access. It should be one of the 
//!                                      symbolic constants defined in ::NV_STEREO_REGISTRY_PROFILE_TYPE. Any other value 
//!                                      will cause function to do nothing and return ::NV_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED.
//! \param [in]     valueRegistryID      ID of the value that is being set. It should be one of the symbolic constants defined in
//!                                      ::NV_STEREO_REGISTRY_PROFILE_TYPE. Any other value will cause function to do nothing
//!                                      and return ::NVAPI_STEREO_REGISTRY_VALUE_NOT_SUPPORTED.
//! \param [in]     pValue               Address of the value that is being set. It should be either address of a DWORD or of a float,
//!                                      dependent on the type of the stereo parameter whose value is being set. The API will then cast that
//!                                      address to DWORD* and write whatever is in those 4 bytes as a DWORD to the registry.
//!
//! \retval ::NVAPI_OK                                           Value is written to registry.
//! \retval ::NVAPI_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED   This profile type is not supported.
//! \retval ::NVAPI_STEREO_REGISTRY_VALUE_NOT_SUPPORTED          This value is not supported.
//! \retval ::NVAPI_STEREO_REGISTRY_ACCESS_FAILED                Access to registry failed.
//! \retval ::NVAPI_API_NOT_INTIALIZED                           NVAPI is not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED                       Stereo part of NVAPI is not initialized.
//! \retval ::NVAPI_ERROR                                        Something is wrong (generic error).
//
///////////////////////////////////////////////////////////////////////////////


//! \ingroup stereoapi
//! Used in NvAPI_Stereo_SetConfigurationProfileValue()
typedef enum _NV_StereoRegistryID
{
    NVAPI_CONVERGENCE_ID,         //!< Symbolic constant for convergence registry ID.
    NVAPI_FRUSTUM_ADJUST_MODE_ID, //!< Symbolic constant for frustum adjust mode registry ID.
} NV_STEREO_REGISTRY_ID;


//! \ingroup stereoapi
NVAPI_INTERFACE NvAPI_Stereo_SetConfigurationProfileValue(NV_STEREO_REGISTRY_PROFILE_TYPE registryProfileType, NV_STEREO_REGISTRY_ID valueRegistryID, void *pValue);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_DeleteConfigurationProfileValue
//
//! DESCRIPTION:   This API removes the given value from the application's configuration profile registry key.
//!                If there is no such value, the function does nothing and does not report an error.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     registryProfileType   The type of profile the application wants to access. It should be one of the 
//!                                       symbolic constants defined in ::NV_STEREO_REGISTRY_PROFILE_TYPE. Any other value will 
//!                                       cause function to do nothing and return ::NV_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED.
//! \param [in]     valueRegistryID       ID of the value that is being deleted. It should be one of the symbolic constants defined in
//!                                       ::NV_STEREO_REGISTRY_PROFILE_TYPE. Any other value will cause function to do nothing and return
//!                                       ::NVAPI_STEREO_REGISTRY_VALUE_NOT_SUPPORTED.
//!
//! \retval ::NVAPI_OK                                           Value does not exist in registry any more.
//! \retval ::NVAPI_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED   This profile type is not supported.
//! \retval ::NVAPI_STEREO_REGISTRY_VALUE_NOT_SUPPORTED          This value is not supported.
//! \retval ::NVAPI_STEREO_REGISTRY_ACCESS_FAILED                Access to registry failed.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED                       Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_DeleteConfigurationProfileValue(NV_STEREO_REGISTRY_PROFILE_TYPE registryProfileType, NV_STEREO_REGISTRY_ID valueRegistryID);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_Enable
//
//! DESCRIPTION:   This APU enables stereo mode in the registry.
//!                Calls to this function affect the entire system.
//!                If stereo is not enabled, then calls to functions that require that stereo is enabled have no effect,
//!                and will return the appropriate error code.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \retval ::NVAPI_OK                      Stereo is now enabled.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED  Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_Enable(void);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_Disable
//
//! DESCRIPTION:   This API disables stereo mode in the registry.
//!                Calls to this function affect the entire system.
//!                If stereo is not enabled, then calls to functions that require that stereo is enabled have no effect,
//!                and will return the appropriate error code.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \retval ::NVAPI_OK                     Stereo is now disabled.
//! \retval ::NVAPI_API_NOT_INTIALIZED  
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_Disable(void);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_IsEnabled
//
//! DESCRIPTION:   This API checks if stereo mode is enabled in the registry.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [out]     pIsStereoEnabled   Address where the result of the inquiry will be placed.
//!
//! \retval ::NVAPI_OK                       Check was sucessfully completed and result reflects current state of stereo availability.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED   Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_IsEnabled(NvU8 *pIsStereoEnabled);




//! \addtogroup stereoapi
//! @{

typedef struct _NVAPI_STEREO_CAPS
{
    NvU32 version;
    NvU32 supportsWindowedModeOff        : 1;
    NvU32 supportsWindowedModeAutomatic  : 1;
    NvU32 supportsWindowedModePersistent : 1;
    NvU32 reserved                       : 29;  // must be 0
    NvU32 reserved2[3];                         // must be 0
} NVAPI_STEREO_CAPS_V1;

#define NVAPI_STEREO_CAPS_VER1  MAKE_NVAPI_VERSION(NVAPI_STEREO_CAPS,1)
#define NVAPI_STEREO_CAPS_VER   NVAPI_STEREO_CAPS_VER1

typedef NVAPI_STEREO_CAPS_V1    NVAPI_STEREO_CAPS;

//! @}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_GetStereoCaps
//
//! DESCRIPTION:   This API checks if the system is capable of stereo features, e.g., windowed mode stereo.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [out]    pCaps    Address where the result of the inquiry will be placed.
//!                           *pCaps is defined in NVAPI_STEREO_CAPS.
//!
//! \retval ::NVAPI_OK
//! \retval ::NVAPI_API_NOT_INTIALIZED
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED
//! \retval ::NVAPI_ERROR
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_GetStereoCaps(NVAPI_STEREO_CAPS *pCaps);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_GetStereoSupport
//
//! DESCRIPTION:  This API checks what kind of stereo support is currently supported on a particular display.
//!               If the the display is prohibited from showing stereo (e.g. secondary in a multi-mon setup), we will 
//!               return 0 for all stereo modes (full screen exclusive, automatic windowed, persistent windowed).
//!               Otherwise, we will check which stereo mode is supported. On 120Hz display, this will be what
//!               the user chooses in control panel. On HDMI 1.4 display, persistent windowed mode is always assumed to be
//!               supported. Note that this function does not check if the CURRENT RESOLUTION/REFRESH RATE can support
//!               stereo. For HDMI 1.4, it is the app's responsibility to change the resolution/refresh rate to one that is
//!               3D compatible. For 120Hz, the driver will ALWAYS force 120Hz anyway.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]     hMonitor handle to monitor that app is going to run on
//! \param [out]    pCaps    Address where the result of the inquiry will be placed.
//!                          *pCaps is defined in NVAPI_STEREO_CAPS.
//! \return       This API can return any of the following error codes enumerated in #NvAPI_Status
//! \retval ::NVAPI_OK
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_GetStereoSupport(__in NvMonitorHandle hMonitor, __out NVAPI_STEREO_CAPS *pCaps);



#if defined(_D3D9_H_) || defined(__d3d10_h__) || defined(__d3d11_h__)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_CreateHandleFromIUnknown
//
//! DESCRIPTION:   This API creates a stereo handle that is used in subsequent calls related to a given device interface.
//!                This must be called before any other NvAPI_Stereo_ function for that handle.
//!                Multiple devices can be used at one time using multiple calls to this function (one per each device). 
//!
//! HOW TO USE:    After the Direct3D device is created, create the stereo handle.
//!                On call success:
//!                -# Use all other NvAPI_Stereo_ functions that have stereo handle as first parameter.
//!                -# After the device interface that corresponds to the the stereo handle is destroyed,
//!                the application should call NvAPI_DestroyStereoHandle() for that stereo handle. 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     pDevice        Pointer to IUnknown interface that is IDirect3DDevice9* in DX9, ID3D10Device*.
//! \param [out]    pStereoHandle  Pointer to the newly created stereo handle.
//!
//! \retval ::NVAPI_OK                       Stereo handle is created for given device interface.
//! \retval ::NVAPI_INVALID_ARGUMENT         Provided device interface is invalid.
//! \retval ::NVAPI_API_NOT_INTIALIZED  
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED   Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_CreateHandleFromIUnknown(IUnknown *pDevice, StereoHandle *pStereoHandle);

#endif // defined(_D3D9_H_) || defined(__d3d10_h__)



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_DestroyHandle
//
//! DESCRIPTION:   This API destroys the stereo handle created with one of the NvAPI_Stereo_CreateHandleFrom() functions.
//!                This should be called after the device corresponding to the handle has been destroyed.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle  Stereo handle that is to be destroyed.
//!
//! \retval ::NVAPI_OK                      Stereo handle is destroyed.
//! \retval ::NVAPI_API_NOT_INTIALIZED      
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED  Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR                   
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_DestroyHandle(StereoHandle stereoHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_Activate
//
//! DESCRIPTION:   This API activates stereo for the device interface corresponding to the given stereo handle.
//!                Activating stereo is possible only if stereo was enabled previously in the registry.
//!                If stereo is not activated, then calls to functions that require that stereo is activated have no effect,
//!                and will return the appropriate error code. 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]    stereoHandle  Stereo handle corresponding to the device interface.
//!
//! \retval ::NVAPI_OK                                Stereo is turned on.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE   Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED            Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_Activate(StereoHandle stereoHandle);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_Deactivate
//
//! DESCRIPTION:   This API deactivates stereo for the given device interface.
//!                If stereo is not activated, then calls to functions that require that stereo is activated have no effect,
//!                and will return the appropriate error code. 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle  Stereo handle that corresponds to the device interface.
//!
//! \retval ::NVAPI_OK                               Stereo is turned off.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE  Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED           Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_Deactivate(StereoHandle stereoHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_IsActivated
//
//! DESCRIPTION:   This API checks if stereo is activated for the given device interface. 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]    stereoHandle  Stereo handle that corresponds to the device interface.
//! \param [in]    pIsStereoOn   Address where result of the inquiry will be placed.
//! 
//! \retval ::NVAPI_OK - Check was sucessfully completed and result reflects current state of stereo (on/off).
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE - Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED - Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR - Something is wrong (generic error).
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_IsActivated(StereoHandle stereoHandle, NvU8 *pIsStereoOn);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_GetSeparation
//
//! DESCRIPTION:   This API gets current separation value (in percents). 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle           Stereo handle that corresponds to the device interface.
//! \param [out]    pSeparationPercentage  Address of @c float type variable to store current separation percentage in.
//!
//! \retval ::NVAPI_OK                                Retrieval of separation percentage was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE   Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED  
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED            Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR  
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_GetSeparation(StereoHandle stereoHandle, float *pSeparationPercentage);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_SetSeparation
//
//! DESCRIPTION:   This API sets separation to given percentage. 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle             Stereo handle that corresponds to the device interface.
//! \param [in]     newSeparationPercentage  New value for separation percentage.
//!
//! \retval ::NVAPI_OK                               Setting of separation percentage was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE  Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED               NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED           Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_STEREO_PARAMETER_OUT_OF_RANGE    Given separation percentage is out of [0..100] range.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_SetSeparation(StereoHandle stereoHandle, float newSeparationPercentage);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_DecreaseSeparation
//
//! DESCRIPTION:   This API decreases separation for the given device interface (just like the Ctrl+F3 hotkey). 
//!
//! WHEN TO USE:   After the stereo handle for device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]   stereoHandle  Stereo handle that corresponds to the device interface.
//!
//! \retval ::NVAPI_OK - Decrease of separation percentage was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE - Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED - Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR - Something is wrong (generic error).
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_DecreaseSeparation(StereoHandle stereoHandle);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_IncreaseSeparation
//
//! DESCRIPTION:   This API increases separation for the given device interface (just like the Ctrl+F4 hotkey).
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]    stereoHandle  Stereo handle that corresponds to the device interface.
//!
//! \retval ::NVAPI_OK                               Increase of separation percentage was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE  Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED               NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED           Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR                            Something is wrong (generic error).
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_IncreaseSeparation(StereoHandle stereoHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_GetConvergence
//
//! DESCRIPTION:   This API gets the current convergence value.
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle   Stereo handle that corresponds to the device interface.
//! \param [out]    pConvergence   Address of @c float type variable to store current convergence value in.
//!
//! \retval ::NVAPI_OK                               Retrieval of convergence value was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE  Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED  
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED           Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_GetConvergence(StereoHandle stereoHandle, float *pConvergence);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_SetConvergence
//
//! DESCRIPTION:   This API sets convergence to the given value.
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle              Stereo handle that corresponds to the device interface.
//! \param [in]     newConvergencePercentage  New value for convergence.
//! 
//! \retval ::NVAPI_OK                                Setting of convergence value was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE   Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED  
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED            Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_SetConvergence(StereoHandle stereoHandle, float newConvergencePercentage);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_DecreaseConvergence
//
//! DESCRIPTION:   This API decreases convergence for the given device interface (just like the Ctrl+F5 hotkey). 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle  Stereo handle that corresponds to the device interface.
//!
//! \retval ::NVAPI_OK - Decrease of convergence was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE - Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED - Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR - Something is wrong (generic error).
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_DecreaseConvergence(StereoHandle stereoHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_IncreaseConvergence
//
//! DESCRIPTION:   This API increases convergence for given the device interface (just like the Ctrl+F5 hotkey). 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]    stereoHandle  Stereo handle that corresponds to the device interface.
//!
//! \retval ::NVAPI_OK                               Increase of convergence was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE  Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED           Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_IncreaseConvergence(StereoHandle stereoHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_GetFrustumAdjustMode
//
//! \fn NvAPI_Stereo_GetFrustumAdjustMode(StereoHandle stereoHandle, NV_FRUSTUM_ADJUST_MODE *pFrustumAdjustMode)
//! DESCRIPTION:   This API gets the current frustum adjust mode value. 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle         Stereo handle that corresponds to the device interface.
//! \param [out]    pFrustumAdjustMode   Address of the NV_FRUSTUM_ADJUST_MODE type variable to store current frustum value in.
//!
//! \retval ::NVAPI_OK - Retrieval of frustum adjust mode was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE - Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED - Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR - Something is wrong (generic error).
//!
///////////////////////////////////////////////////////////////////////////////

//! \ingroup stereoapi
//! Used in NvAPI_Stereo_GetFrustumAdjustMode().
typedef enum _NV_FrustumAdjustMode
{
    NVAPI_NO_FRUSTUM_ADJUST,    //!< Do not adjust frustum.
    NVAPI_FRUSTUM_STRETCH,      //!< Stretch images in X.
    NVAPI_FRUSTUM_CLEAR_EDGES   //!< Clear corresponding edges for each eye.
} NV_FRUSTUM_ADJUST_MODE;

//! \ingroup stereoapi
NVAPI_INTERFACE NvAPI_Stereo_GetFrustumAdjustMode(StereoHandle stereoHandle, NV_FRUSTUM_ADJUST_MODE *pFrustumAdjustMode);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_SetFrustumAdjustMode
//
//! DESCRIPTION:   This API sets the current frustum adjust mode value. 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle                Stereo handle that corresponds to the device interface.
//! \param [in]     newFrustumAdjustModeValue   New value for frustum adjust mode. It should be one of the symbolic constants defined in
//!                                             ::NV_FRUSTUM_ADJUST_MODE. Any other value will cause function to do nothing and return
//!                                             ::NVAPI_STEREO_FRUSTUM_ADJUST_MODE_NOT_SUPPORTED.
//!
//! \retval ::NVAPI_OK                                         Retrieval of frustum adjust mode was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE            Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED                     Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_STEREO_FRUSTUM_ADJUST_MODE_NOT_SUPPORTED   Given frustum adjust mode is not supported.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_SetFrustumAdjustMode(StereoHandle stereoHandle, NV_FRUSTUM_ADJUST_MODE newFrustumAdjustModeValue);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_CaptureJpegImage
//
//! DESCRIPTION:   This API captures the current stereo image in JPEG stereo format with the given quality.
//!                Only the last capture call per flip will be effective. 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle  Stereo handle that corresponds to the device interface.
//! \param [in]     quality        Quality of the JPEG image to be captured. Integer value betweeen 0 and 100.
//! 
//! \retval ::NVAPI_OK                              Image captured.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED 
//! \retval ::NVAPI_STEREO_PARAMETER_OUT_OF_RANGE   Given quality is out of [0..100] range.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_CaptureJpegImage(StereoHandle stereoHandle, NvU32 quality);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_CapturePngImage
//
//! DESCRIPTION:   This API captures the current stereo image in PNG stereo format.
//!                Only the last capture call per flip will be effective. 
//!
//! WHEN TO USE:   After the stereo handle for the device interface is created via successfull call to the appropriate NvAPI_Stereo_CreateHandleFrom() function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 180.51
//!
//! \param [in]     stereoHandle  Stereo handle corresponding to the device interface.
//!
//! \retval ::NVAPI_OK                               Image captured.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE  Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED           Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_CapturePngImage(StereoHandle stereoHandle);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_ReverseStereoBlitControl
//
//! DESCRIPTION:   This API turns on/off reverse stereo blit.
//!
//! HOW TO USE:    Use after the stereo handle for the device interface is created via successfull call to the appropriate 
//!                NvAPI_Stereo_CreateHandleFrom() function.
//!                After reversed stereo blit control is turned on, blits from the stereo surface will
//!                produce the right-eye image in the left side of the destination surface and the left-eye
//!                image in the right side of the destination surface.
//!
//!                In DirectX 9, the destination surface must be created as the render target, and StretchRect must be used.
//!                Conditions:
//!                - DstWidth == 2*SrcWidth
//!                - DstHeight == SrcHeight
//!                - Src surface is the stereo surface.
//!                - SrcRect must be {0,0,SrcWidth,SrcHeight}
//!                - DstRect must be {0,0,DstWidth,DstHeight}
//!
//!                In DirectX 10, ResourceCopyRegion must be used. 
//!                Conditions:
//!                - DstWidth == 2*SrcWidth
//!                - DstHeight == SrcHeight
//!                - dstX == 0,
//!                - dstY == 0,
//!                - dstZ == 0,
//!                - SrcBox: left=top=front==0; right==SrcWidth; bottom==SrcHeight; back==1;
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 185.87
//!
//! \param [in]    stereoHandle  Stereo handle corresponding to the device interface.
//! \param [in]    TurnOn         != 0 : Turns on \n 
//!                               == 0 : Turns off 
//!
//!
//! \retval ::NVAPI_OK                                Retrieval of frustum adjust mode was successfull.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE   Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED            Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_ReverseStereoBlitControl(StereoHandle hStereoHandle, NvU8 TurnOn);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_SetNotificationMessage
//
//! DESCRIPTION:   This API is a Setup notification message that the stereo driver uses to notify the application
//!                when the user changes the stereo driver state. 
//!
//!                When the user changes the stereo state (Activated or Deactivated, separation or conversion)
//!                the stereo driver posts a defined message with the following parameters:
//!
//!                lParam  is the current conversion. (Actual conversion is *(float*)&lParam )
//!          
//!                wParam == MAKEWPARAM(l, h) where
//!                - l == 0 if stereo is deactivated
//!                - l == 1 if stereo is deactivated
//!                - h is the current separation. (Actual separation is float(h*100.f/0xFFFF)  
//!                
//!                Call this API with NULL hWnd to prohibit notification.
//!
//! WHEN TO USE:   Use after the stereo handle for device interface is created via successful call to appropriate
//!                NvAPI_Stereo_CreateHandleFrom() function.
//!                
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 182.42
//!
//!
//! \param [in]     stereoHandle  Stereo handle corresponding to the device interface.
//! \param [in]     hWnd          Window HWND that will be notified when the user changes the stereo driver state.
//!                               Actual HWND must be cast to an NvU64.
//! \param [in]     messageID     MessageID of the message that will be posted to hWnd
//!
//! \retval ::NVAPI_OK                                Notification set.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE   Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED            Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR 
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_SetNotificationMessage(StereoHandle hStereoHandle, NvU64 hWnd,NvU64 messageID);




///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_SetActiveEye
//
//! \fn NvAPI_Stereo_SetActiveEye(StereoHandle hStereoHandle, NV_STEREO_ACTIVE_EYE StereoEye);
//! DESCRIPTION:   This API sets the back buffer to left or right in Direct stereo mode.
//!                  
//! HOW TO USE:    After the stereo handle for device interface is created via successfull call to appropriate 
//!                NvAPI_Stereo_CreateHandleFrom function.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   stereoHandle  Stereo handle that corresponds to the device interface.
//! \param [in]   StereoEye     Defines active eye in Direct stereo mode
//!
//! \retval ::NVAPI_OK - Active eye is set.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE - Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED - Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_INVALID_ARGUMENT - StereoEye parameter has not allowed value.
//! \retval ::NVAPI_SET_NOT_ALLOWED  - Current stereo mode is not Direct
//! \retval ::NVAPI_ERROR - Something is wrong (generic error).
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup stereoapi
typedef enum _NV_StereoActiveEye
{
    NVAPI_STEREO_EYE_RIGHT = 1,
    NVAPI_STEREO_EYE_LEFT = 2,
    NVAPI_STEREO_EYE_MONO = 3,
} NV_STEREO_ACTIVE_EYE;

//! \ingroup stereoapi
NVAPI_INTERFACE NvAPI_Stereo_SetActiveEye(StereoHandle hStereoHandle, NV_STEREO_ACTIVE_EYE StereoEye);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_SetDriverMode
//
//! \fn NvAPI_Stereo_SetDriverMode( NV_STEREO_DRIVER_MODE mode );
//! DESCRIPTION:   This API sets the 3D stereo driver mode: Direct or Automatic
//!                  
//! HOW TO USE:    This API must be called before the device is created.
//!                Applies to DirectX 9 and higher.
//!
//  SUPPORTED OS: Windows Vista and higher
//!      
//! \param [in]    mode       Defines the 3D stereo driver mode: Direct or Automatic
//!
//! \retval ::NVAPI_OK                      Active eye is set.
//! \retval ::NVAPI_API_NOT_INTIALIZED      NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED  Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_INVALID_ARGUMENT        mode parameter has not allowed value.
//! \retval ::NVAPI_ERROR                   Something is wrong (generic error).
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup stereoapi
typedef enum _NV_StereoDriverMode
{
    NVAPI_STEREO_DRIVER_MODE_AUTOMATIC = 0,
    NVAPI_STEREO_DRIVER_MODE_DIRECT    = 2,
} NV_STEREO_DRIVER_MODE;

//! \ingroup stereoapi
NVAPI_INTERFACE NvAPI_Stereo_SetDriverMode( NV_STEREO_DRIVER_MODE mode );


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_GetEyeSeparation
//
//! DESCRIPTION:   This API returns eye separation as a ratio of <between eye distance>/<physical screen width>.
//! 
//! HOW TO USE:    After the stereo handle for device interface is created via successfull call to appropriate API. Applies only to DirectX 9 and up.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   stereoHandle  Stereo handle that corresponds to the device interface.
//! \param [out]  pSeparation   Eye separation.
//!
//! \retval ::NVAPI_OK                               Active eye is set.
//! \retval ::NVAPI_STEREO_INVALID_DEVICE_INTERFACE  Device interface is not valid. Create again, then attach again.
//! \retval ::NVAPI_API_NOT_INTIALIZED               NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED           Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR  (generic error).
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_GetEyeSeparation(StereoHandle hStereoHandle,  float *pSeparation );





///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_IsWindowedModeSupported
//
//! DESCRIPTION:   This API returns availability of windowed mode stereo
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [out] bSupported(OUT)    != 0  - supported,  \n
//!                                 == 0  - is not supported 
//!
//!
//! \retval ::NVAPI_OK                      Retrieval of frustum adjust mode was successfull.
//! \retval ::NVAPI_API_NOT_INTIALIZED      NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED  Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR                   Something is wrong (generic error).
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_IsWindowedModeSupported(NvU8* bSupported);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_AppHandShake
//
//! \fn NvAPI_Stereo_AppHandShake(StereoHandle hStereoHandle, NVAPI_STEREO_HANDSHAKE_PARAMS* pStereoHandshakeParams)
//! DESCRIPTION:   This API allows an approved application to enable stereo viewing through
//!                a handshake with the driver instead of via a hardcoded application exe name.
//!
//! HOW TO USE:    Call this function immediately after device creation, then follow with a reset. \n 
//!                Very generically:
//!                Create Device->Create Stereo Handle->Do Handshake->Reset Device
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   stereoHandle            Stereo handle corresponding to the device interface.
//! \param [in]   pStereoHandshakeParams  pointer to struct NVAPI_STEREO_HANDSHAKE_PARAMS
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED - Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_INVALID_ARGUMENT - the vendor ID and/or response is invalid
//! \retval ::NVAPI_STEREO_HANDSHAKE_NOT_DONE - Stereo handshake failed
//! \retval ::NVAPI_ERROR - Something is wrong (generic error).
//
///////////////////////////////////////////////////////////////////////////////

//! \addtogroup stereoapi
//! @{

//! Stereo Handshake Commands
typedef enum _NVAPI_STEREO_HANDSHAKE_COMMANDS
{
    NVAPI_STEREO_HANDSHAKE_CMD_CHALLENGE = 0x01,
    NVAPI_STEREO_HANDSHAKE_CMD_RESPONSE  = 0x02,
} NVAPI_STEREO_HANDSHAKE_COMMANDS;

//! Stereo Handshake Constants
#define NVAPI_STEREO_HANDSHAKE_CHALLENGE_SIZE     16
#define NVAPI_STEREO_HANDSHAKE_RESPONSE_SIZE      20

//
//! Parameter data structure for the NVAPI_STEREO_HANDSHAKE_CMD_CHALLENGE command:
//! This command requests a random challenge from driver.
//! It must be invoked before the NVAPI_STEREO_HANDSHAKE_CMD_RESPONSE command.
typedef struct _NVAPI_STEREO_HANDSHAKE_CHALLENGE_PARAMS
{
    NvU8 challenge[NVAPI_STEREO_HANDSHAKE_CHALLENGE_SIZE];    //!< random challenge from driver (OUT)
} NVAPI_STEREO_HANDSHAKE_CHALLENGE_PARAMS;

//
//! Parameter data structure for the NVAPI_STEREO_HANDSHAKE_CMD_RESPONSE command
//!
//! The application must possess the following information in order to calculate a valid response:
//! - vendorGUID: a unique ID assigned to the application vendor by NVIDIA;
//! - vendorKEY:  a secret key issued to the application vendor by NVIDIA;
//!
//! The response is calculated as HMAC(vendorKEY, (vendorGUID || challenge))
//! where HMAC is the Keyed-Hash Message Authentication Code using SHA-1 as the
//! underlying hash function. See FIPS Publication 198 for details of the algorithm.
typedef struct _NVAPI_STEREO_HANDSHAKE_RESPONSE_PARAMS
{
    NvGUID vendorGUID;                                          //!< vendor GUID from app (IN)
    NvU8   response[NVAPI_STEREO_HANDSHAKE_RESPONSE_SIZE];    //!< response from app (IN)
    NvU32  flags;                                               //!< Flags set by application (IN/OPTIONAL)
} NVAPI_STEREO_HANDSHAKE_RESPONSE_PARAMS;

typedef struct _NVAPI_STEREO_HANDSHAKE_PARAMS
{
    NvU32 version;                      //!< structure version (IN)
    NvU32 dwCommand;                    //!< command (IN)
    union
    {
        NVAPI_STEREO_HANDSHAKE_CHALLENGE_PARAMS   ChallengeParams;
        NVAPI_STEREO_HANDSHAKE_RESPONSE_PARAMS    ResponseParams;
    };
} NVAPI_STEREO_HANDSHAKE_PARAMS_V1;

typedef NVAPI_STEREO_HANDSHAKE_PARAMS_V1      NVAPI_STEREO_HANDSHAKE_PARAMS;
#define NVAPI_STEREO_HANDSHAKE_PARAMS_VER1    MAKE_NVAPI_VERSION(NVAPI_STEREO_HANDSHAKE_PARAMS_V1, 1)
#define NVAPI_STEREO_HANDSHAKE_PARAMS_VER     NVAPI_STEREO_HANDSHAKE_PARAMS_VER1

NVAPI_INTERFACE NvAPI_Stereo_AppHandShake(StereoHandle hStereoHandle, NVAPI_STEREO_HANDSHAKE_PARAMS* pStereoHandshakeParams);

//! @}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_HandShake_Trigger_Activation
//
//! DESCRIPTION:   This API allows an approved application (approved through handshake) to 
//!                trigger creation of a stereo desktop, in case the creation was stopped on application
//!                launch. 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   stereoHandle   Stereo handle that corresponds to the device interface.
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_STEREO_HANDSHAKE_NOT_DONE - Stereo handshake not done prior to call
//! \retval ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED - Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR - Something is wrong (generic error).
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_HandShake_Trigger_Activation(StereoHandle hStereoHandle);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Stereo_HandShake_Message_Control
//
//! DESCRIPTION:   This API allows an approved application (approved through handshake) to 
//!                turn on/off the stereo message displayed onscreen.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   stereoHandle  Stereo handle that corresponds to the device interface.
//! \param [in]   TurnOn       != 0  - turns on,
//!                              == 0  - turns off
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_STEREO_HANDSHAKE_NOT_DONE - Stereo handshake not done prior to call
//! \retval ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized.
//! \retval ::NVAPI_STEREO_NOT_INITIALIZED - Stereo part of NVAPI not initialized.
//! \retval ::NVAPI_ERROR - Something is wrong (generic error).
//!
//! \ingroup stereoapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Stereo_HandShake_Message_Control(StereoHandle hStereoHandle, NvU8 TurnOn);



//! \ingroup vidio
//! Unique identifier for VIO owner (process identifier or NVVIOOWNERID_NONE)
typedef NvU32   NVVIOOWNERID;                               


//! \addtogroup vidio
//! @{


#define NVVIOOWNERID_NONE                   0      //!< Unregistered ownerId        


//! Owner type for device
typedef enum _NVVIOOWNERTYPE                               
{
    NVVIOOWNERTYPE_NONE                             ,       //!<  No owner for the device
    NVVIOOWNERTYPE_APPLICATION                      ,       //!<  Application owns the device
    NVVIOOWNERTYPE_DESKTOP                          ,       //!<  Desktop transparent mode owns the device (not applicable for video input)
}NVVIOOWNERTYPE;

// Access rights for NvAPI_VIO_Open()

//! Read access             (not applicable for video output)
#define NVVIO_O_READ                        0x00000000      

//! Write exclusive access  (not applicable for video input)
#define NVVIO_O_WRITE_EXCLUSIVE             0x00010001      

//! 
#define NVVIO_VALID_ACCESSRIGHTS            (NVVIO_O_READ              | \
                                             NVVIO_O_WRITE_EXCLUSIVE   )

              
//! VIO_DATA.ulOwnerID high-bit is set only if device has been initialized by VIOAPI
//! examined at NvAPI_GetCapabilities|NvAPI_VIO_Open to determine if settings need to be applied from registry or POR state read
#define NVVIO_OWNERID_INITIALIZED  0x80000000

//! VIO_DATA.ulOwnerID next-bit is set only if device is currently in exclusive write access mode from NvAPI_VIO_Open()
#define NVVIO_OWNERID_EXCLUSIVE    0x40000000
                                              
//! VIO_DATA.ulOwnerID lower bits are:
//!  NVGVOOWNERTYPE_xxx enumerations indicating use context
#define NVVIO_OWNERID_TYPEMASK     0x0FFFFFFF //!< mask for NVVIOOWNERTYPE_xxx


//! @}
              
//---------------------------------------------------------------------
// Enumerations
//---------------------------------------------------------------------


//! \addtogroup vidio
//! @{

//! Video signal format and resolution
typedef enum _NVVIOSIGNALFORMAT
{
    NVVIOSIGNALFORMAT_NONE,			    //!< Invalid signal format 
    NVVIOSIGNALFORMAT_487I_59_94_SMPTE259_NTSC,     //!< 01  487i    59.94Hz  (SMPTE259) NTSC
    NVVIOSIGNALFORMAT_576I_50_00_SMPTE259_PAL,      //!< 02  576i    50.00Hz  (SMPTE259) PAL
    NVVIOSIGNALFORMAT_1035I_60_00_SMPTE260,         //!< 03  1035i   60.00Hz  (SMPTE260)
    NVVIOSIGNALFORMAT_1035I_59_94_SMPTE260,         //!< 04  1035i   59.94Hz  (SMPTE260)
    NVVIOSIGNALFORMAT_1080I_50_00_SMPTE295,         //!< 05  1080i   50.00Hz  (SMPTE295)
    NVVIOSIGNALFORMAT_1080I_60_00_SMPTE274,         //!< 06  1080i   60.00Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080I_59_94_SMPTE274,         //!< 07  1080i   59.94Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080I_50_00_SMPTE274,         //!< 08  1080i   50.00Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080P_30_00_SMPTE274,         //!< 09  1080p   30.00Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080P_29_97_SMPTE274,         //!< 10  1080p   29.97Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080P_25_00_SMPTE274,         //!< 11  1080p   25.00Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080P_24_00_SMPTE274,         //!< 12  1080p   24.00Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080P_23_976_SMPTE274,        //!< 13  1080p   23.976Hz (SMPTE274)
    NVVIOSIGNALFORMAT_720P_60_00_SMPTE296,          //!< 14  720p    60.00Hz  (SMPTE296)
    NVVIOSIGNALFORMAT_720P_59_94_SMPTE296,          //!< 15  720p    59.94Hz  (SMPTE296)
    NVVIOSIGNALFORMAT_720P_50_00_SMPTE296,          //!< 16  720p    50.00Hz  (SMPTE296)
    NVVIOSIGNALFORMAT_1080I_48_00_SMPTE274,         //!< 17  1080I   48.00Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080I_47_96_SMPTE274,         //!< 18  1080I   47.96Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_720P_30_00_SMPTE296,          //!< 19  720p    30.00Hz  (SMPTE296)
    NVVIOSIGNALFORMAT_720P_29_97_SMPTE296,          //!< 20  720p    29.97Hz  (SMPTE296)
    NVVIOSIGNALFORMAT_720P_25_00_SMPTE296,          //!< 21  720p    25.00Hz  (SMPTE296)
    NVVIOSIGNALFORMAT_720P_24_00_SMPTE296,          //!< 22  720p    24.00Hz  (SMPTE296)
    NVVIOSIGNALFORMAT_720P_23_98_SMPTE296,          //!< 23  720p    23.98Hz  (SMPTE296)
    NVVIOSIGNALFORMAT_2048P_30_00_SMPTE372,         //!< 24  2048p   30.00Hz  (SMPTE372)
    NVVIOSIGNALFORMAT_2048P_29_97_SMPTE372,         //!< 25  2048p   29.97Hz  (SMPTE372)
    NVVIOSIGNALFORMAT_2048I_60_00_SMPTE372,         //!< 26  2048i   60.00Hz  (SMPTE372)
    NVVIOSIGNALFORMAT_2048I_59_94_SMPTE372,         //!< 27  2048i   59.94Hz  (SMPTE372)
    NVVIOSIGNALFORMAT_2048P_25_00_SMPTE372,         //!< 28  2048p   25.00Hz  (SMPTE372)
    NVVIOSIGNALFORMAT_2048I_50_00_SMPTE372,         //!< 29  2048i   50.00Hz  (SMPTE372)
    NVVIOSIGNALFORMAT_2048P_24_00_SMPTE372,         //!< 30  2048p   24.00Hz  (SMPTE372)
    NVVIOSIGNALFORMAT_2048P_23_98_SMPTE372,         //!< 31  2048p   23.98Hz  (SMPTE372)
    NVVIOSIGNALFORMAT_2048I_48_00_SMPTE372,         //!< 32  2048i   48.00Hz  (SMPTE372)
    NVVIOSIGNALFORMAT_2048I_47_96_SMPTE372,         //!< 33  2048i   47.96Hz  (SMPTE372)
    
    NVVIOSIGNALFORMAT_1080PSF_25_00_SMPTE274,       //!< 34  1080PsF 25.00Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080PSF_29_97_SMPTE274,       //!< 35  1080PsF 29.97Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080PSF_30_00_SMPTE274,       //!< 36  1080PsF 30.00Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080PSF_24_00_SMPTE274,       //!< 37  1080PsF 24.00Hz  (SMPTE274)
    NVVIOSIGNALFORMAT_1080PSF_23_98_SMPTE274,       //!< 38  1080PsF 23.98Hz  (SMPTE274)

    NVVIOSIGNALFORMAT_1080P_50_00_SMPTE274_3G_LEVEL_A, //!< 39  1080P   50.00Hz  (SMPTE274) 3G Level A
    NVVIOSIGNALFORMAT_1080P_59_94_SMPTE274_3G_LEVEL_A, //!< 40  1080P   59.94Hz  (SMPTE274) 3G Level A
    NVVIOSIGNALFORMAT_1080P_60_00_SMPTE274_3G_LEVEL_A, //!< 41  1080P   60.00Hz  (SMPTE274) 3G Level A
    
    NVVIOSIGNALFORMAT_1080P_60_00_SMPTE274_3G_LEVEL_B, //!< 42  1080p   60.00Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_1080I_60_00_SMPTE274_3G_LEVEL_B, //!< 43  1080i   60.00Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_2048I_60_00_SMPTE372_3G_LEVEL_B, //!< 44  2048i   60.00Hz  (SMPTE372) 3G Level B
    NVVIOSIGNALFORMAT_1080P_50_00_SMPTE274_3G_LEVEL_B, //!< 45  1080p   50.00Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_1080I_50_00_SMPTE274_3G_LEVEL_B, //!< 46  1080i   50.00Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_2048I_50_00_SMPTE372_3G_LEVEL_B, //!< 47  2048i   50.00Hz  (SMPTE372) 3G Level B
    NVVIOSIGNALFORMAT_1080P_30_00_SMPTE274_3G_LEVEL_B, //!< 48  1080p   30.00Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_2048P_30_00_SMPTE372_3G_LEVEL_B, //!< 49  2048p   30.00Hz  (SMPTE372) 3G Level B
    NVVIOSIGNALFORMAT_1080P_25_00_SMPTE274_3G_LEVEL_B, //!< 50  1080p   25.00Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_2048P_25_00_SMPTE372_3G_LEVEL_B, //!< 51  2048p   25.00Hz  (SMPTE372) 3G Level B
    NVVIOSIGNALFORMAT_1080P_24_00_SMPTE274_3G_LEVEL_B, //!< 52  1080p   24.00Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_2048P_24_00_SMPTE372_3G_LEVEL_B, //!< 53  2048p   24.00Hz  (SMPTE372) 3G Level B
    NVVIOSIGNALFORMAT_1080I_48_00_SMPTE274_3G_LEVEL_B, //!< 54  1080i   48.00Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_2048I_48_00_SMPTE372_3G_LEVEL_B, //!< 55  2048i   48.00Hz  (SMPTE372) 3G Level B
    NVVIOSIGNALFORMAT_1080P_59_94_SMPTE274_3G_LEVEL_B, //!< 56  1080p   59.94Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_1080I_59_94_SMPTE274_3G_LEVEL_B, //!< 57  1080i   59.94Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_2048I_59_94_SMPTE372_3G_LEVEL_B, //!< 58  2048i   59.94Hz  (SMPTE372) 3G Level B
    NVVIOSIGNALFORMAT_1080P_29_97_SMPTE274_3G_LEVEL_B, //!< 59  1080p   29.97Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_2048P_29_97_SMPTE372_3G_LEVEL_B, //!< 60  2048p   29.97Hz  (SMPTE372) 3G Level B
    NVVIOSIGNALFORMAT_1080P_23_98_SMPTE274_3G_LEVEL_B, //!< 61  1080p   29.98Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_2048P_23_98_SMPTE372_3G_LEVEL_B, //!< 62  2048p   29.98Hz  (SMPTE372) 3G Level B
    NVVIOSIGNALFORMAT_1080I_47_96_SMPTE274_3G_LEVEL_B, //!< 63  1080i   47.96Hz  (SMPTE274) 3G Level B
    NVVIOSIGNALFORMAT_2048I_47_96_SMPTE372_3G_LEVEL_B, //!< 64  2048i   47.96Hz  (SMPTE372) 3G Level B
    
    NVVIOSIGNALFORMAT_END                              //!< 65  To indicate end of signal format list

}NVVIOSIGNALFORMAT;

//! SMPTE standards format
typedef enum _NVVIOVIDEOSTANDARD
{
    NVVIOVIDEOSTANDARD_SMPTE259                        ,       //!< SMPTE259
    NVVIOVIDEOSTANDARD_SMPTE260                        ,       //!< SMPTE260
    NVVIOVIDEOSTANDARD_SMPTE274                        ,       //!< SMPTE274
    NVVIOVIDEOSTANDARD_SMPTE295                        ,       //!< SMPTE295
    NVVIOVIDEOSTANDARD_SMPTE296                        ,       //!< SMPTE296
    NVVIOVIDEOSTANDARD_SMPTE372                        ,       //!< SMPTE372
}NVVIOVIDEOSTANDARD;

//! HD or SD video type
typedef enum _NVVIOVIDEOTYPE
{
    NVVIOVIDEOTYPE_SD                                  ,       //!< Standard-definition (SD)
    NVVIOVIDEOTYPE_HD                                  ,       //!< High-definition     (HD)
}NVVIOVIDEOTYPE;

//! Interlace mode
typedef enum _NVVIOINTERLACEMODE 
{
    NVVIOINTERLACEMODE_PROGRESSIVE                     ,       //!< Progressive               (p)
    NVVIOINTERLACEMODE_INTERLACE                       ,       //!< Interlace                 (i)
    NVVIOINTERLACEMODE_PSF                             ,       //!< Progressive Segment Frame (psf)
}NVVIOINTERLACEMODE;

//! Video data format
typedef enum _NVVIODATAFORMAT
{
    NVVIODATAFORMAT_UNKNOWN   = -1                     ,       //!< Invalid DataFormat
    NVVIODATAFORMAT_R8G8B8_TO_YCRCB444                 ,       //!< R8:G8:B8                => YCrCb  (4:4:4)
    NVVIODATAFORMAT_R8G8B8A8_TO_YCRCBA4444             ,       //!< R8:G8:B8:A8             => YCrCbA (4:4:4:4)
    NVVIODATAFORMAT_R8G8B8Z10_TO_YCRCBZ4444            ,       //!< R8:G8:B8:Z10            => YCrCbZ (4:4:4:4)
    NVVIODATAFORMAT_R8G8B8_TO_YCRCB422                 ,       //!< R8:G8:B8                => YCrCb  (4:2:2)
    NVVIODATAFORMAT_R8G8B8A8_TO_YCRCBA4224             ,       //!< R8:G8:B8:A8             => YCrCbA (4:2:2:4)
    NVVIODATAFORMAT_R8G8B8Z10_TO_YCRCBZ4224            ,       //!< R8:G8:B8:Z10            => YCrCbZ (4:2:2:4)
    NVVIODATAFORMAT_X8X8X8_444_PASSTHRU                ,       //!< R8:G8:B8                => RGB    (4:4:4)
    NVVIODATAFORMAT_X8X8X8A8_4444_PASSTHRU             ,       //!< R8:G8:B8:A8             => RGBA   (4:4:4:4)
    NVVIODATAFORMAT_X8X8X8Z10_4444_PASSTHRU            ,       //!< R8:G8:B8:Z10            => RGBZ   (4:4:4:4)
    NVVIODATAFORMAT_X10X10X10_444_PASSTHRU             ,       //!< Y10:CR10:CB10           => YCrCb  (4:4:4)
    NVVIODATAFORMAT_X10X8X8_444_PASSTHRU               ,       //!< Y10:CR8:CB8             => YCrCb  (4:4:4)
    NVVIODATAFORMAT_X10X8X8A10_4444_PASSTHRU           ,       //!< Y10:CR8:CB8:A10         => YCrCbA (4:4:4:4)
    NVVIODATAFORMAT_X10X8X8Z10_4444_PASSTHRU           ,       //!< Y10:CR8:CB8:Z10         => YCrCbZ (4:4:4:4)
    NVVIODATAFORMAT_DUAL_R8G8B8_TO_DUAL_YCRCB422       ,       //!< R8:G8:B8 + R8:G8:B8     => YCrCb  (4:2:2 + 4:2:2)
    NVVIODATAFORMAT_DUAL_X8X8X8_TO_DUAL_422_PASSTHRU   ,       //!< Y8:CR8:CB8 + Y8:CR8:CB8 => YCrCb  (4:2:2 + 4:2:2)
    NVVIODATAFORMAT_R10G10B10_TO_YCRCB422              ,       //!< R10:G10:B10             => YCrCb  (4:2:2)
    NVVIODATAFORMAT_R10G10B10_TO_YCRCB444              ,       //!< R10:G10:B10             => YCrCb  (4:4:4)
    NVVIODATAFORMAT_X12X12X12_444_PASSTHRU             ,       //!< X12:X12:X12             => XXX    (4:4:4)
    NVVIODATAFORMAT_X12X12X12_422_PASSTHRU             ,       //!< X12:X12:X12             => XXX    (4:2:2)
    NVVIODATAFORMAT_Y10CR10CB10_TO_YCRCB422            ,       //!< Y10:CR10:CB10           => YCrCb  (4:2:2)
    NVVIODATAFORMAT_Y8CR8CB8_TO_YCRCB422               ,       //!< Y8:CR8:CB8              => YCrCb  (4:2:2)
    NVVIODATAFORMAT_Y10CR8CB8A10_TO_YCRCBA4224         ,       //!< Y10:CR8:CB8:A10         => YCrCbA (4:2:2:4)
    NVVIODATAFORMAT_R10G10B10_TO_RGB444                ,       //!< R10:G10:B10             => RGB    (4:4:4)
    NVVIODATAFORMAT_R12G12B12_TO_YCRCB444              ,       //!< R12:G12:B12             => YCrCb  (4:4:4)
    NVVIODATAFORMAT_R12G12B12_TO_YCRCB422              ,       //!< R12:G12:B12             => YCrCb  (4:2:2)
}NVVIODATAFORMAT;

//! Video output area
typedef enum _NVVIOOUTPUTAREA
{
    NVVIOOUTPUTAREA_FULLSIZE                           ,       //!< Output to entire video resolution (full size)
    NVVIOOUTPUTAREA_SAFEACTION                         ,       //!< Output to centered 90% of video resolution (safe action)
    NVVIOOUTPUTAREA_SAFETITLE                          ,       //!< Output to centered 80% of video resolution (safe title)
}NVVIOOUTPUTAREA;

//! Synchronization source
typedef enum _NVVIOSYNCSOURCE
{
    NVVIOSYNCSOURCE_SDISYNC                            ,       //!< SDI Sync  (Digital input)
    NVVIOSYNCSOURCE_COMPSYNC                           ,       //!< COMP Sync (Composite input)
}NVVIOSYNCSOURCE;

//! Composite synchronization type
typedef enum _NVVIOCOMPSYNCTYPE
{
    NVVIOCOMPSYNCTYPE_AUTO                             ,       //!< Auto-detect
    NVVIOCOMPSYNCTYPE_BILEVEL                          ,       //!< Bi-level signal
    NVVIOCOMPSYNCTYPE_TRILEVEL                         ,       //!< Tri-level signal
}NVVIOCOMPSYNCTYPE;

//! Video input output status
typedef enum _NVVIOINPUTOUTPUTSTATUS
{
    NVINPUTOUTPUTSTATUS_OFF                            ,       //!< Not in use
    NVINPUTOUTPUTSTATUS_ERROR                          ,       //!< Error detected
    NVINPUTOUTPUTSTATUS_SDI_SD                         ,       //!< SDI (standard-definition)
    NVINPUTOUTPUTSTATUS_SDI_HD                         ,       //!< SDI (high-definition)
}NVVIOINPUTOUTPUTSTATUS;

//! Synchronization input status
typedef enum _NVVIOSYNCSTATUS
{
    NVVIOSYNCSTATUS_OFF                                ,       //!< Sync not detected
    NVVIOSYNCSTATUS_ERROR                              ,       //!< Error detected
    NVVIOSYNCSTATUS_SYNCLOSS                           ,       //!< Genlock in use, format mismatch with output
    NVVIOSYNCSTATUS_COMPOSITE                          ,       //!< Composite sync
    NVVIOSYNCSTATUS_SDI_SD                             ,       //!< SDI sync (standard-definition)
    NVVIOSYNCSTATUS_SDI_HD                             ,       //!< SDI sync (high-definition)
}NVVIOSYNCSTATUS;

//! Video Capture Status
typedef enum _NVVIOCAPTURESTATUS
{
    NVVIOSTATUS_STOPPED                                ,       //!< Sync not detected
    NVVIOSTATUS_RUNNING                                ,       //!< Error detected
    NVVIOSTATUS_ERROR                                  ,       //!< Genlock in use, format mismatch with output
}NVVIOCAPTURESTATUS;

//! Video Capture Status
typedef enum _NVVIOSTATUSTYPE
{
    NVVIOSTATUSTYPE_IN                                 ,       //!< Input Status
    NVVIOSTATUSTYPE_OUT                                ,       //!< Output Status
}NVVIOSTATUSTYPE;


//! Assumption, maximum 4 SDI input and 4 SDI output cards supported on a system
#define NVAPI_MAX_VIO_DEVICES                 8   

//! 4 physical jacks supported on each SDI input card.
#define NVAPI_MAX_VIO_JACKS                   4   


//! Each physical jack an on SDI input card can have
//! two "channels" in the case of "3G" VideoFormats, as specified
//! by SMPTE 425; for non-3G VideoFormats, only the first channel within
//! a physical jack is valid.
#define NVAPI_MAX_VIO_CHANNELS_PER_JACK       2   

//! 4 Streams, 1 per physical jack
#define NVAPI_MAX_VIO_STREAMS                 4   

#define NVAPI_MIN_VIO_STREAMS                 1   

//! SDI input supports a max of 2 links per stream
#define NVAPI_MAX_VIO_LINKS_PER_STREAM        2   


#define NVAPI_MAX_FRAMELOCK_MAPPING_MODES     20

//! Min number of capture images 
#define NVAPI_GVI_MIN_RAW_CAPTURE_IMAGES      1   

//! Max number of capture images        
#define NVAPI_GVI_MAX_RAW_CAPTURE_IMAGES      32  

//! Default number of capture images
#define NVAPI_GVI_DEFAULT_RAW_CAPTURE_IMAGES  5   



// Data Signal notification events. These need a event handler in RM.
// Register/Unregister and PopEvent NVAPI's are already available.

//! Device configuration
typedef enum _NVVIOCONFIGTYPE
{
    NVVIOCONFIGTYPE_IN                                 ,       //!< Input Status
    NVVIOCONFIGTYPE_OUT                                ,       //!< Output Status
}NVVIOCONFIGTYPE;

typedef enum _NVVIOCOLORSPACE
{
    NVVIOCOLORSPACE_UNKNOWN,
    NVVIOCOLORSPACE_YCBCR,
    NVVIOCOLORSPACE_YCBCRA,
    NVVIOCOLORSPACE_YCBCRD,
    NVVIOCOLORSPACE_GBR,
    NVVIOCOLORSPACE_GBRA,
    NVVIOCOLORSPACE_GBRD,
} NVVIOCOLORSPACE;

//! Component sampling
typedef enum _NVVIOCOMPONENTSAMPLING
{
    NVVIOCOMPONENTSAMPLING_UNKNOWN,
    NVVIOCOMPONENTSAMPLING_4444,
    NVVIOCOMPONENTSAMPLING_4224,
    NVVIOCOMPONENTSAMPLING_444,
    NVVIOCOMPONENTSAMPLING_422
} NVVIOCOMPONENTSAMPLING;

typedef enum _NVVIOBITSPERCOMPONENT
{
    NVVIOBITSPERCOMPONENT_UNKNOWN,
    NVVIOBITSPERCOMPONENT_8,
    NVVIOBITSPERCOMPONENT_10,
    NVVIOBITSPERCOMPONENT_12,
} NVVIOBITSPERCOMPONENT;

typedef enum _NVVIOLINKID 
{
    NVVIOLINKID_UNKNOWN,
    NVVIOLINKID_A,
    NVVIOLINKID_B,
    NVVIOLINKID_C,
    NVVIOLINKID_D
} NVVIOLINKID;


typedef enum _NVVIOANCPARITYCOMPUTATION
{
    NVVIOANCPARITYCOMPUTATION_AUTO,
    NVVIOANCPARITYCOMPUTATION_ON,
    NVVIOANCPARITYCOMPUTATION_OFF
} NVVIOANCPARITYCOMPUTATION;



//! @}


//---------------------------------------------------------------------
// Structures
//---------------------------------------------------------------------

//! \addtogroup vidio
//! @{


//! Supports Serial Digital Interface (SDI) output
#define NVVIOCAPS_VIDOUT_SDI                0x00000001      

//! Supports Internal timing source
#define NVVIOCAPS_SYNC_INTERNAL             0x00000100      

//! Supports Genlock timing source
#define NVVIOCAPS_SYNC_GENLOCK              0x00000200      

//! Supports Serial Digital Interface (SDI) synchronization input
#define NVVIOCAPS_SYNCSRC_SDI               0x00001000      

//! Supports Composite synchronization input
#define NVVIOCAPS_SYNCSRC_COMP              0x00002000      

//! Supports Desktop transparent mode
#define NVVIOCAPS_OUTPUTMODE_DESKTOP        0x00010000      

//! Supports OpenGL application mode
#define NVVIOCAPS_OUTPUTMODE_OPENGL         0x00020000      

//! Supports Serial Digital Interface (SDI) input
#define NVVIOCAPS_VIDIN_SDI                 0x00100000  

//! Supports Packed ANC
#define NVVIOCAPS_PACKED_ANC_SUPPORTED      0x00200000      

//! SDI-class interface: SDI output with two genlock inputs
#define NVVIOCLASS_SDI                      0x00000001      

//! Device capabilities
typedef struct _NVVIOCAPS
{
    NvU32             version;                              //!< Structure version
    NvAPI_String      adapterName;                          //!< Graphics adapter name
    NvU32             adapterClass;                         //!< Graphics adapter classes (NVVIOCLASS_SDI mask)
    NvU32             adapterCaps;                          //!< Graphics adapter capabilities (NVVIOCAPS_* mask)
    NvU32             dipSwitch;                            //!< On-board DIP switch settings bits
    NvU32             dipSwitchReserved;                    //!< On-board DIP switch settings reserved bits
    NvU32             boardID;                              //!< Board ID
    //! Driver version
    struct                                                  //
    {                                                      
        NvU32          majorVersion;                        //!< Major version
        NvU32          minorVersion;                        //!< Minor version
    } driver;                                               //
    //! Firmware version 
    struct                                                  
    {                                                       
        NvU32          majorVersion;                        //!< Major version
        NvU32          minorVersion;                        //!< Minor version
    } firmWare;                                             //
    NVVIOOWNERID      ownerId;                              //!< Unique identifier for owner of video output (NVVIOOWNERID_INVALID if free running)
    NVVIOOWNERTYPE    ownerType;                            //!< Owner type (OpenGL application or Desktop mode)
} NVVIOCAPS;

//! Macro for constructing the version field of NVVIOCAPS
#define NVVIOCAPS_VER   MAKE_NVAPI_VERSION(NVVIOCAPS,1)

//! Input channel status
typedef struct _NVVIOCHANNELSTATUS
{
    NvU32                  smpte352;                         //!< 4-byte SMPTE 352 video payload identifier
    NVVIOSIGNALFORMAT      signalFormat;                     //!< Signal format
    NVVIOBITSPERCOMPONENT  bitsPerComponent;                 //!< Bits per component
    NVVIOCOMPONENTSAMPLING samplingFormat;                   //!< Sampling format
    NVVIOCOLORSPACE        colorSpace;                       //!< Color space
    NVVIOLINKID            linkID;                           //!< Link ID
} NVVIOCHANNELSTATUS;

//! Input device status
typedef struct _NVVIOINPUTSTATUS
{
    NVVIOCHANNELSTATUS     vidIn[NVAPI_MAX_VIO_JACKS][NVAPI_MAX_VIO_CHANNELS_PER_JACK];     //!< Video input status per channel within a jack
    NVVIOCAPTURESTATUS     captureStatus;                  //!< status of video capture
} NVVIOINPUTSTATUS;

//! Output device status
typedef struct _NVVIOOUTPUTSTATUS
{
    NVVIOINPUTOUTPUTSTATUS	vid1Out;                        //!< Video 1 output status
    NVVIOINPUTOUTPUTSTATUS	vid2Out;                        //!< Video 2 output status
    NVVIOSYNCSTATUS		sdiSyncIn;                      //!< SDI sync input status
    NVVIOSYNCSTATUS		compSyncIn;                     //!< Composite sync input status
    NvU32			syncEnable;                     //!< Sync enable (TRUE if using syncSource)
    NVVIOSYNCSOURCE		syncSource;                     //!< Sync source
    NVVIOSIGNALFORMAT		syncFormat;                     //!< Sync format
    NvU32			frameLockEnable;                //!< Framelock enable flag
    NvU32			outputVideoLocked;              //!< Output locked status
    NvU32			dataIntegrityCheckErrorCount;   //!< Data integrity check error count
    NvU32			dataIntegrityCheckEnabled;      //!< Data integrity check status enabled 
    NvU32			dataIntegrityCheckFailed;       //!< Data integrity check status failed 
    NvU32                       uSyncSourceLocked;              //!< genlocked to framelocked to ref signal
    NvU32                       uPowerOn;                       //!< TRUE: indicates there is sufficient power
} NVVIOOUTPUTSTATUS;

//! Video device status.
typedef struct _NVVIOSTATUS
{
    NvU32                 version;                        //!< Structure version
    NVVIOSTATUSTYPE       nvvioStatusType;                //!< Input or Output status
    union                                                   
    {
        NVVIOINPUTSTATUS  inStatus;                       //!<  Input device status
        NVVIOOUTPUTSTATUS outStatus;                      //!<  Output device status
    }vioStatus;      
} NVVIOSTATUS;

//! Macro for constructingthe version field of NVVIOSTATUS
#define NVVIOSTATUS_VER   MAKE_NVAPI_VERSION(NVVIOSTATUS,1)

//! Output region
typedef struct _NVVIOOUTPUTREGION
{
    NvU32              x;                                    //!< Horizontal origin in pixels
    NvU32              y;                                    //!< Vertical origin in pixels
    NvU32              width;                                //!< Width of region in pixels
    NvU32              height;                               //!< Height of region in pixels
} NVVIOOUTPUTREGION;

//! Gamma ramp (8-bit index)
typedef struct _NVVIOGAMMARAMP8
{
    NvU16              uRed[256];                            //!< Red channel gamma ramp (8-bit index, 16-bit values)
    NvU16              uGreen[256];                          //!< Green channel gamma ramp (8-bit index, 16-bit values)
    NvU16              uBlue[256];                           //!< Blue channel gamma ramp (8-bit index, 16-bit values)
} NVVIOGAMMARAMP8;

//! Gamma ramp (10-bit index)
typedef struct _NVVIOGAMMARAMP10
{
    NvU16              uRed[1024];                           //!< Red channel gamma ramp (10-bit index, 16-bit values)
    NvU16              uGreen[1024];                         //!< Green channel gamma ramp (10-bit index, 16-bit values)
    NvU16              uBlue[1024];                          //!< Blue channel gamma ramp (10-bit index, 16-bit values)
} NVVIOGAMMARAMP10;


//! Sync delay
typedef struct _NVVIOSYNCDELAY
{
    NvU32              version;                              //!< Structure version
    NvU32              horizontalDelay;                      //!< Horizontal delay in pixels
    NvU32              verticalDelay;                        //!< Vertical delay in lines
} NVVIOSYNCDELAY;

//! Macro for constructing the version field of NVVIOSYNCDELAY
#define NVVIOSYNCDELAY_VER   MAKE_NVAPI_VERSION(NVVIOSYNCDELAY,1)


//! Video mode information
typedef struct _NVVIOVIDEOMODE
{
    NvU32                horizontalPixels;                   //!< Horizontal resolution (in pixels)
    NvU32                verticalLines;                      //!< Vertical resolution for frame (in lines)
    float                fFrameRate;                         //!< Frame rate
    NVVIOINTERLACEMODE   interlaceMode;                      //!< Interlace mode 
    NVVIOVIDEOSTANDARD   videoStandard;                      //!< SMPTE standards format
    NVVIOVIDEOTYPE       videoType;                          //!< HD or SD signal classification
} NVVIOVIDEOMODE;

//! Signal format details
typedef struct _NVVIOSIGNALFORMATDETAIL
{   
    NVVIOSIGNALFORMAT    signalFormat;                       //!< Signal format enumerated value
    NVVIOVIDEOMODE       videoMode;                          //!< Video mode for signal format
}NVVIOSIGNALFORMATDETAIL;


//! R8:G8:B8
#define NVVIOBUFFERFORMAT_R8G8B8                  0x00000001
 
//! R8:G8:B8:Z24  
#define NVVIOBUFFERFORMAT_R8G8B8Z24               0x00000002
   
//! R8:G8:B8:A8
#define NVVIOBUFFERFORMAT_R8G8B8A8                0x00000004   

//! R8:G8:B8:A8:Z24       
#define NVVIOBUFFERFORMAT_R8G8B8A8Z24             0x00000008   

//! R16FP:G16FP:B16FP
#define NVVIOBUFFERFORMAT_R16FPG16FPB16FP         0x00000010   

//! R16FP:G16FP:B16FP:Z24
#define NVVIOBUFFERFORMAT_R16FPG16FPB16FPZ24      0x00000020   

//! R16FP:G16FP:B16FP:A16FP
#define NVVIOBUFFERFORMAT_R16FPG16FPB16FPA16FP    0x00000040   

//! R16FP:G16FP:B16FP:A16FP:Z24
#define NVVIOBUFFERFORMAT_R16FPG16FPB16FPA16FPZ24 0x00000080   



//! Data format details
typedef struct _NVVIODATAFORMATDETAIL
{
    NVVIODATAFORMAT   dataFormat;                              //!< Data format enumerated value
    NvU32             vioCaps;                                 //!< Data format capabilities (NVVIOCAPS_* mask)
}NVVIODATAFORMATDETAIL;

//! Colorspace conversion
typedef struct _NVVIOCOLORCONVERSION
{
    NvU32       version;                                    //!<  Structure version
    float       colorMatrix[3][3];                          //!<  Output[n] =
    float       colorOffset[3];                             //!<  Input[0] * colorMatrix[n][0] +
    float       colorScale[3];                              //!<  Input[1] * colorMatrix[n][1] +
                                                            //!<  Input[2] * colorMatrix[n][2] +
                                                            //!<  OutputRange * colorOffset[n]
                                                            //!<  where OutputRange is the standard magnitude of
                                                            //!<  Output[n][n] and colorMatrix and colorOffset 
                                                            //!<  values are within the range -1.0 to +1.0
    NvU32      compositeSafe;                               //!<  compositeSafe constrains luminance range when using composite output
} NVVIOCOLORCONVERSION;

//! macro for constructing the version field of _NVVIOCOLORCONVERSION.
#define NVVIOCOLORCONVERSION_VER   MAKE_NVAPI_VERSION(NVVIOCOLORCONVERSION,1)

//! Gamma correction
typedef struct _NVVIOGAMMACORRECTION
{
    NvU32            version;                               //!< Structure version
    NvU32            vioGammaCorrectionType;                //!< Gamma correction type (8-bit or 10-bit)
    //! Gamma correction:
    union                                                   
    {                                                       
        NVVIOGAMMARAMP8  gammaRamp8;                        //!< Gamma ramp (8-bit index, 16-bit values)
        NVVIOGAMMARAMP10 gammaRamp10;                       //!< Gamma ramp (10-bit index, 16-bit values)
    }gammaRamp;                                      
    float            fGammaValueR;			//!< Red Gamma value within gamma ranges. 0.5 - 6.0
    float            fGammaValueG;			//!< Green Gamma value within gamma ranges. 0.5 - 6.0
    float            fGammaValueB;			//!< Blue Gamma value within gamma ranges. 0.5 - 6.0
} NVVIOGAMMACORRECTION;

//! Macro for constructing thevesion field of _NVVIOGAMMACORRECTION
#define NVVIOGAMMACORRECTION_VER   MAKE_NVAPI_VERSION(NVVIOGAMMACORRECTION,1)

//! Maximum number of ranges per channel
#define MAX_NUM_COMPOSITE_RANGE      2                      


typedef struct _NVVIOCOMPOSITERANGE
{
    NvU32   uRange;
    NvU32   uEnabled;
    NvU32   uMin;
    NvU32   uMax;
} NVVIOCOMPOSITERANGE;



// Device configuration (fields masks indicating NVVIOCONFIG fields to use for NvAPI_VIO_GetConfig/NvAPI_VIO_SetConfig() )
//
#define NVVIOCONFIG_SIGNALFORMAT            0x00000001      //!< fields: signalFormat
#define NVVIOCONFIG_DATAFORMAT              0x00000002      //!< fields: dataFormat
#define NVVIOCONFIG_OUTPUTREGION            0x00000004      //!< fields: outputRegion
#define NVVIOCONFIG_OUTPUTAREA              0x00000008      //!< fields: outputArea
#define NVVIOCONFIG_COLORCONVERSION         0x00000010      //!< fields: colorConversion
#define NVVIOCONFIG_GAMMACORRECTION         0x00000020      //!< fields: gammaCorrection
#define NVVIOCONFIG_SYNCSOURCEENABLE        0x00000040      //!< fields: syncSource and syncEnable
#define NVVIOCONFIG_SYNCDELAY               0x00000080      //!< fields: syncDelay
#define NVVIOCONFIG_COMPOSITESYNCTYPE       0x00000100      //!< fields: compositeSyncType
#define NVVIOCONFIG_FRAMELOCKENABLE         0x00000200      //!< fields: EnableFramelock
#define NVVIOCONFIG_422FILTER               0x00000400      //!< fields: bEnable422Filter
#define NVVIOCONFIG_COMPOSITETERMINATE      0x00000800      //!< fields: bCompositeTerminate (Not supported on Quadro FX 4000 SDI)         
#define NVVIOCONFIG_DATAINTEGRITYCHECK      0x00001000      //!< fields: bEnableDataIntegrityCheck (Not supported on Quadro FX 4000 SDI)
#define NVVIOCONFIG_CSCOVERRIDE             0x00002000      //!< fields: colorConversion override
#define NVVIOCONFIG_FLIPQUEUELENGTH         0x00004000      //!< fields: flipqueuelength control
#define NVVIOCONFIG_ANCTIMECODEGENERATION   0x00008000      //!< fields: bEnableANCTimeCodeGeneration
#define NVVIOCONFIG_COMPOSITE               0x00010000      //!< fields: bEnableComposite
#define NVVIOCONFIG_ALPHAKEYCOMPOSITE       0x00020000      //!< fields: bEnableAlphaKeyComposite
#define NVVIOCONFIG_COMPOSITE_Y             0x00040000      //!< fields: compRange
#define NVVIOCONFIG_COMPOSITE_CR            0x00080000      //!< fields: compRange
#define NVVIOCONFIG_COMPOSITE_CB            0x00100000      //!< fields: compRange
#define NVVIOCONFIG_FULL_COLOR_RANGE        0x00200000      //!< fields: bEnableFullColorRange
#define NVVIOCONFIG_RGB_DATA                0x00400000      //!< fields: bEnableRGBData
#define NVVIOCONFIG_RESERVED_SDIOUTPUTENABLE         0x00800000      //!< fields: bEnableSDIOutput
#define NVVIOCONFIG_STREAMS                 0x01000000      //!< fields: streams
#define NVVIOCONFIG_ANC_PARITY_COMPUTATION  0x02000000      //!< fields: ancParityComputation
 

// Don't forget to update NVVIOCONFIG_VALIDFIELDS in nvapi.spec when NVVIOCONFIG_ALLFIELDS changes.
#define NVVIOCONFIG_ALLFIELDS   ( NVVIOCONFIG_SIGNALFORMAT          | \
                                  NVVIOCONFIG_DATAFORMAT            | \
                                  NVVIOCONFIG_OUTPUTREGION          | \
                                  NVVIOCONFIG_OUTPUTAREA            | \
                                  NVVIOCONFIG_COLORCONVERSION       | \
                                  NVVIOCONFIG_GAMMACORRECTION       | \
                                  NVVIOCONFIG_SYNCSOURCEENABLE      | \
                                  NVVIOCONFIG_SYNCDELAY             | \
                                  NVVIOCONFIG_COMPOSITESYNCTYPE     | \
                                  NVVIOCONFIG_FRAMELOCKENABLE       | \
                                  NVVIOCONFIG_422FILTER             | \
                                  NVVIOCONFIG_COMPOSITETERMINATE    | \
                                  NVVIOCONFIG_DATAINTEGRITYCHECK    | \
                                  NVVIOCONFIG_CSCOVERRIDE           | \
                                  NVVIOCONFIG_FLIPQUEUELENGTH       | \
                                  NVVIOCONFIG_ANCTIMECODEGENERATION | \
                                  NVVIOCONFIG_COMPOSITE             | \
                                  NVVIOCONFIG_ALPHAKEYCOMPOSITE     | \
                                  NVVIOCONFIG_COMPOSITE_Y           | \
                                  NVVIOCONFIG_COMPOSITE_CR          | \
                                  NVVIOCONFIG_COMPOSITE_CB          | \
                                  NVVIOCONFIG_FULL_COLOR_RANGE      | \
                                  NVVIOCONFIG_RGB_DATA              | \
                                  NVVIOCONFIG_RESERVED_SDIOUTPUTENABLE | \
                                  NVVIOCONFIG_STREAMS               | \
                                  NVVIOCONFIG_ANC_PARITY_COMPUTATION)

#define NVVIOCONFIG_VALIDFIELDS  ( NVVIOCONFIG_SIGNALFORMAT          | \
                                   NVVIOCONFIG_DATAFORMAT            | \
                                   NVVIOCONFIG_OUTPUTREGION          | \
                                   NVVIOCONFIG_OUTPUTAREA            | \
                                   NVVIOCONFIG_COLORCONVERSION       | \
                                   NVVIOCONFIG_GAMMACORRECTION       | \
                                   NVVIOCONFIG_SYNCSOURCEENABLE      | \
                                   NVVIOCONFIG_SYNCDELAY             | \
                                   NVVIOCONFIG_COMPOSITESYNCTYPE     | \
                                   NVVIOCONFIG_FRAMELOCKENABLE       | \
                                   NVVIOCONFIG_RESERVED_SDIOUTPUTENABLE | \
                                   NVVIOCONFIG_422FILTER             | \
                                   NVVIOCONFIG_COMPOSITETERMINATE    | \
                                   NVVIOCONFIG_DATAINTEGRITYCHECK    | \
                                   NVVIOCONFIG_CSCOVERRIDE           | \
                                   NVVIOCONFIG_FLIPQUEUELENGTH       | \
                                   NVVIOCONFIG_ANCTIMECODEGENERATION | \
                                   NVVIOCONFIG_COMPOSITE             | \
                                   NVVIOCONFIG_ALPHAKEYCOMPOSITE     | \
                                   NVVIOCONFIG_COMPOSITE_Y           | \
                                   NVVIOCONFIG_COMPOSITE_CR          | \
                                   NVVIOCONFIG_COMPOSITE_CB          | \
                                   NVVIOCONFIG_FULL_COLOR_RANGE      | \
                                   NVVIOCONFIG_RGB_DATA              | \
                                   NVVIOCONFIG_RESERVED_SDIOUTPUTENABLE | \
                                   NVVIOCONFIG_STREAMS               | \
                                   NVVIOCONFIG_ANC_PARITY_COMPUTATION)

#define NVVIOCONFIG_DRIVERFIELDS ( NVVIOCONFIG_OUTPUTREGION          | \
                                   NVVIOCONFIG_OUTPUTAREA            | \
                                   NVVIOCONFIG_COLORCONVERSION       | \
                                   NVVIOCONFIG_FLIPQUEUELENGTH)

#define NVVIOCONFIG_GAMMAFIELDS  ( NVVIOCONFIG_GAMMACORRECTION       )

#define NVVIOCONFIG_RMCTRLFIELDS ( NVVIOCONFIG_SIGNALFORMAT          | \
                                   NVVIOCONFIG_DATAFORMAT            | \
                                   NVVIOCONFIG_SYNCSOURCEENABLE      | \
                                   NVVIOCONFIG_COMPOSITESYNCTYPE     | \
                                   NVVIOCONFIG_FRAMELOCKENABLE       | \
                                   NVVIOCONFIG_422FILTER             | \
                                   NVVIOCONFIG_COMPOSITETERMINATE    | \
                                   NVVIOCONFIG_DATAINTEGRITYCHECK    | \
                                   NVVIOCONFIG_COMPOSITE             | \
                                   NVVIOCONFIG_ALPHAKEYCOMPOSITE     | \
                                   NVVIOCONFIG_COMPOSITE_Y           | \
                                   NVVIOCONFIG_COMPOSITE_CR          | \
                                   NVVIOCONFIG_COMPOSITE_CB)

#define NVVIOCONFIG_RMSKEWFIELDS ( NVVIOCONFIG_SYNCDELAY             )

#define NVVIOCONFIG_ALLOWSDIRUNNING_FIELDS ( NVVIOCONFIG_DATAINTEGRITYCHECK     | \
                                             NVVIOCONFIG_SYNCDELAY              | \
                                             NVVIOCONFIG_CSCOVERRIDE            | \
                                             NVVIOCONFIG_ANCTIMECODEGENERATION  | \
                                             NVVIOCONFIG_COMPOSITE              | \
                                             NVVIOCONFIG_ALPHAKEYCOMPOSITE      | \
                                             NVVIOCONFIG_COMPOSITE_Y            | \
                                             NVVIOCONFIG_COMPOSITE_CR           | \
                                             NVVIOCONFIG_COMPOSITE_CB           | \
                                             NVVIOCONFIG_ANC_PARITY_COMPUTATION)

                                             
 #define NVVIOCONFIG_RMMODESET_FIELDS ( NVVIOCONFIG_SIGNALFORMAT         | \
                                        NVVIOCONFIG_DATAFORMAT           | \
                                        NVVIOCONFIG_SYNCSOURCEENABLE     | \
                                        NVVIOCONFIG_FRAMELOCKENABLE      | \
                                        NVVIOCONFIG_COMPOSITESYNCTYPE )                                            
                                             

//! Output device configuration 
// No members can be deleted from below structure. Only add new members at the 
// end of the structure.
typedef struct _NVVIOOUTPUTCONFIG_V1
{
    NVVIOSIGNALFORMAT    signalFormat;                         //!< Signal format for video output
    NVVIODATAFORMAT      dataFormat;                           //!< Data format for video output
    NVVIOOUTPUTREGION    outputRegion;                         //!< Region for video output (Desktop mode)
    NVVIOOUTPUTAREA      outputArea;                           //!< Usable resolution for video output (safe area)
    NVVIOCOLORCONVERSION colorConversion;                      //!< Color conversion.
    NVVIOGAMMACORRECTION gammaCorrection;
    NvU32                syncEnable;                           //!< Sync enable (TRUE to use syncSource)
    NVVIOSYNCSOURCE      syncSource;                           //!< Sync source
    NVVIOSYNCDELAY       syncDelay;                            //!< Sync delay
    NVVIOCOMPSYNCTYPE    compositeSyncType;                    //!< Composite sync type
    NvU32                frameLockEnable;                      //!< Flag indicating whether framelock was on/off
    NvU32                psfSignalFormat;                      //!< Indicates whether contained format is PSF Signal format
    NvU32                enable422Filter;                      //!< Enables/Disables 4:2:2 filter
    NvU32                compositeTerminate;                   //!< Composite termination
    NvU32                enableDataIntegrityCheck;             //!< Enable data integrity check: true - enable, false - disable
    NvU32                cscOverride;                          //!< Use provided CSC color matrix to overwrite 
    NvU32                flipQueueLength;                      //!< Number of buffers used for the internal flipqueue
    NvU32                enableANCTimeCodeGeneration;          //!< Enable SDI ANC time code generation
    NvU32                enableComposite;                      //!< Enable composite
    NvU32                enableAlphaKeyComposite;              //!< Enable Alpha key composite
    NVVIOCOMPOSITERANGE  compRange;                            //!< Composite ranges
    NvU8                 reservedData[256];                    //!< Inicates last stored SDI output state TRUE-ON / FALSE-OFF
    NvU32                enableFullColorRange;                 //!< Flag indicating Full Color Range
    NvU32                enableRGBData;                        //!< Indicates data is in RGB format
} NVVIOOUTPUTCONFIG_V1;

typedef struct _NVVIOOUTPUTCONFIG_V2
{
    NVVIOSIGNALFORMAT    signalFormat;                         //!< Signal format for video output
    NVVIODATAFORMAT      dataFormat;                           //!< Data format for video output
    NVVIOOUTPUTREGION    outputRegion;                         //!< Region for video output (Desktop mode)
    NVVIOOUTPUTAREA      outputArea;                           //!< Usable resolution for video output (safe area)
    NVVIOCOLORCONVERSION colorConversion;                      //!< Color conversion.
    NVVIOGAMMACORRECTION gammaCorrection;
    NvU32                syncEnable;                           //!< Sync enable (TRUE to use syncSource)
    NVVIOSYNCSOURCE      syncSource;                           //!< Sync source
    NVVIOSYNCDELAY       syncDelay;                            //!< Sync delay
    NVVIOCOMPSYNCTYPE    compositeSyncType;                    //!< Composite sync type
    NvU32                frameLockEnable;                      //!< Flag indicating whether framelock was on/off
    NvU32                psfSignalFormat;                      //!< Indicates whether contained format is PSF Signal format
    NvU32                enable422Filter;                      //!< Enables/Disables 4:2:2 filter
    NvU32                compositeTerminate;                   //!< Composite termination
    NvU32                enableDataIntegrityCheck;             //!< Enable data integrity check: true - enable, false - disable
    NvU32                cscOverride;                          //!< Use provided CSC color matrix to overwrite
    NvU32                flipQueueLength;                      //!< Number of buffers used for the internal flip queue
    NvU32                enableANCTimeCodeGeneration;          //!< Enable SDI ANC time code generation
    NvU32                enableComposite;                      //!< Enable composite
    NvU32                enableAlphaKeyComposite;              //!< Enable Alpha key composite
    NVVIOCOMPOSITERANGE  compRange;                            //!< Composite ranges
    NvU8                 reservedData[256];                    //!< Indicates last stored SDI output state TRUE-ON / FALSE-OFF
    NvU32                enableFullColorRange;                 //!< Flag indicating Full Color Range
    NvU32                enableRGBData;                        //!< Indicates data is in RGB format
    NVVIOANCPARITYCOMPUTATION ancParityComputation;            //!< Enable HW ANC parity bit computation (auto/on/off)
} NVVIOOUTPUTCONFIG_V2;


//! Stream configuration
typedef struct _NVVIOSTREAM
{
    NvU32                   bitsPerComponent;                     //!< Bits per component
    NVVIOCOMPONENTSAMPLING  sampling;                             //!< Sampling   
    NvU32                   expansionEnable;                      //!< Enable/disable 4:2:2->4:4:4 expansion
    NvU32                   numLinks;                             //!< Number of active links
    struct
    {
        NvU32               jack;                                 //!< This stream's link[i] will use the specified (0-based) channel within the
        NvU32               channel;                              //!< specified (0-based) jack
    } links[NVAPI_MAX_VIO_LINKS_PER_STREAM];
} NVVIOSTREAM;

//! Input device configuration
typedef struct _NVVIOINPUTCONFIG
{
    NvU32                numRawCaptureImages;                  //!< numRawCaptureImages is the number of frames to keep in the capture queue. 
                                                               //!< must be between NVAPI_GVI_MIN_RAW_CAPTURE_IMAGES and NVAPI_GVI_MAX_RAW_CAPTURE_IMAGES, 
    NVVIOSIGNALFORMAT    signalFormat;                         //!< Signal format.
                                                               //!< Please note that both numRawCaptureImages and signalFormat should be set together.
    NvU32                numStreams;                           //!< Number of active streams.
    NVVIOSTREAM          streams[NVAPI_MAX_VIO_STREAMS];       //!< Stream configurations
    NvU32                bTestMode;                            //!< This attribute controls the GVI test mode.
                                                               //!< Possible values 0/1. When testmode enabled, the
                                                               //!< GVI device will generate fake data as quickly as possible.
} NVVIOINPUTCONFIG;

typedef struct _NVVIOCONFIG_V1
{
    NvU32                version;                              //!< Structure version
    NvU32                fields;                               //!< Caller sets to NVVIOCONFIG_* mask for fields to use
    NVVIOCONFIGTYPE      nvvioConfigType;                      //!< Input or Output configuration
    union                                                   
    {
        NVVIOINPUTCONFIG  inConfig;                            //!<  Input device configuration
        NVVIOOUTPUTCONFIG_V1 outConfig;                           //!<  Output device configuration
    }vioConfig; 
} NVVIOCONFIG_V1;


typedef struct _NVVIOCONFIG_V2
{
    NvU32                version;                              //!< Structure version
    NvU32                fields;                               //!< Caller sets to NVVIOCONFIG_* mask for fields to use
    NVVIOCONFIGTYPE      nvvioConfigType;                      //!< Input or Output configuration
    union
    {
        NVVIOINPUTCONFIG     inConfig;                         //!< Input device configuration
        NVVIOOUTPUTCONFIG_V2 outConfig;                        //!< Output device configuration
    }vioConfig;
} NVVIOCONFIG_V2;

typedef NVVIOOUTPUTCONFIG_V2 NVVIOOUTPUTCONFIG;
typedef NVVIOCONFIG_V2 NVVIOCONFIG;

#define NVVIOCONFIG_VER1  MAKE_NVAPI_VERSION(NVVIOCONFIG_V1,1)
#define NVVIOCONFIG_VER2  MAKE_NVAPI_VERSION(NVVIOCONFIG_V2,2)
#define NVVIOCONFIG_VER   NVVIOCONFIG_VER2


typedef struct
{
    NvPhysicalGpuHandle					hPhysicalGpu;					//!< Handle to Physical GPU (This could be NULL for GVI device if its not binded)
    NvVioHandle                         hVioHandle;                     //!<handle to SDI Input/Output device
    NvU32                               vioId;                          //!<device Id of SDI Input/Output device
    NvU32                               outputId;			//!<deviceMask of the SDI display connected to GVO device. 
                                                                        //!<outputId will be 0 for GVI device.
} NVVIOTOPOLOGYTARGET;													

typedef struct _NV_VIO_TOPOLOGY
{
    NvU32                       version;
    NvU32                       vioTotalDeviceCount;                    //!<How many video I/O targets are valid
    NVVIOTOPOLOGYTARGET         vioTarget[NVAPI_MAX_VIO_DEVICES];       //!<Array of video I/O targets
}NV_VIO_TOPOLOGY, NVVIOTOPOLOGY;


//! Macro for constructing the version field of NV_VIO_TOPOLOGY
#define NV_VIO_TOPOLOGY_VER  MAKE_NVAPI_VERSION(NV_VIO_TOPOLOGY,1)

//! Macro for constructing the version field of NVVIOTOPOLOGY
#define NVVIOTOPOLOGY_VER    MAKE_NVAPI_VERSION(NVVIOTOPOLOGY,1)



//! @} 



//! \addtogroup vidio
//! @{
///////////////////////////////////////////////////////////////////////////////
//!   
//!   Function:    NvAPI_VIO_GetCapabilities
//!  
//!   Description: This API determine the graphics adapter video I/O capabilities.
//!  
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!  
//! \param [in]  NvVioHandle   The caller provides the SDI device handle as input.
//! \param [out] pAdapterCaps  Pointer to receive capabilities
//!  
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  NVVIOCAPS struct version used by the app is not compatible
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_GetCapabilities(NvVioHandle     hVioHandle,
                                          NVVIOCAPS       *pAdapterCaps);

////////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_Open
//!  
//!   Description: This API opens the graphics adapter for video I/O operations
//!                using the OpenGL application interface.  Read operations
//!                are permitted in this mode by multiple clients, but Write 
//!                operations are application exclusive.
//!  
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!  
//! \param [in]  NvVioHandle      The caller provides the SDI output device handle as input.
//! \param [in]  vioClass         Class interface (NVVIOCLASS_* value)
//! \param [in]  ownerType        Specify NVVIOOWNERTYPE_APPLICATION or NVVIOOWNERTYPE_DESKTOP.
//!  
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
//! \retval ::NVAPI_DEVICE_BUSY                  Access denied for requested access
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_Open(NvVioHandle       hVioHandle,
                               NvU32             vioClass,
                               NVVIOOWNERTYPE    ownerType);


///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_Close
//!  
//!   Description: This API closes the graphics adapter for graphics-to-video operations
//!                using the OpenGL application interface.  Closing an 
//!                OpenGL handle releases the device.
//!  
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!  
//! \param [in]  NvVioHandle   The caller provides the SDI output device handle as input.
//! \param [in]  bRelease      boolean value to either keep or release ownership
//!  
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
//! \retval ::NVAPI_DEVICE_BUSY                  Access denied for requested access
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_Close(NvVioHandle       hVioHandle,
                                NvU32             bRelease);

///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_Status
//!  
//!   Description: This API gets the Video I/O LED status.
//!  
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!  
//! \param [in]  NvVioHandle   The caller provides the SDI device handle as input.
//! \param [out] pStatus       Return pointer to NVVIOSTATUS
//!  
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  Invalid structure version
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_Status(NvVioHandle     hVioHandle, 
                                 NVVIOSTATUS     *pStatus);


////////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_SyncFormatDetect
//!  
//!   Description: This API detects the Video I/O incoming sync video format.
//!  
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!  
//! \param [in]  NvVioHandle  The caller provides the SDI device handle as input.
//! \param [out] pWait        Pointer to receive how many milliseconds will lapse 
//!                           before VIOStatus returns the detected syncFormat.
//!  
//! \retval ::NVAPI_OK                          Success
//! \retval ::NVAPI_API_NOT_INTIALIZED          NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT            Arguments passed to API are not valid
//! \retval ::NVAPI_NOT_SUPPORTED               Video I/O not supported
//! \retval ::NVAPI_ERROR                       NVAPI Random errors
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_SyncFormatDetect(NvVioHandle hVioHandle,
                                           NvU32       *pWait);

///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_GetConfig
//!  
//!   Description: This API gets the graphics-to-video configuration.
//!  
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!  
//! \param [in]  NvVioHandle   The caller provides the SDI device handle as input.
//! \param [out] pConfig       Pointer to the graphics-to-video configuration
//!  
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  Invalid structure version
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_GetConfig(NvVioHandle        hVioHandle,
                                    NVVIOCONFIG        *pConfig); 


///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_SetConfig
//!  
//!   Description: This API sets the graphics-to-video configuration.
//!  
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!  
//! \param [in]  NvVioHandle      The caller provides the SDI device handle as input.
//! \param [in]  pConfig          Pointer to Graphics-to-Video configuration
//!  
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  Stucture version invalid
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
//! \retval ::NVAPI_DEVICE_BUSY                  Access denied for requested access
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_SetConfig(NvVioHandle            hVioHandle,
                                    const NVVIOCONFIG      *pConfig);


///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_SetCSC
//!  
//!   Description: This API sets the colorspace conversion parameters.
//!  
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!
//! \param [in]  NvVioHandle      The caller provides the SDI device handle as input.
//! \param [in]  pCSC             Pointer to CSC parameters
//!  
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  Stucture version invalid
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
//! \retval ::NVAPI_DEVICE_BUSY                  Access denied for requested access
////////////////////////////////////////////////////////////////////////////////----
NVAPI_INTERFACE NvAPI_VIO_SetCSC(NvVioHandle           hVioHandle,
                                 NVVIOCOLORCONVERSION  *pCSC);

////////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_GetCSC
//! 
//!   Description: This API gets the colorspace conversion parameters.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!
//! \param [in]  NvVioHandle      The caller provides the SDI device handle as input.
//! \param [out] pCSC             Pointer to CSC parameters
//! 
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  Stucture version invalid
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
////////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_GetCSC(NvVioHandle           hVioHandle,
                                 NVVIOCOLORCONVERSION  *pCSC);

///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_SetGamma
//! 
//!   Description: This API sets the gamma conversion parameters.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!
//! \param [in]  NvVioHandle       The caller provides the SDI device handle as input.
//! \param [in]  pGamma            Pointer to gamma parameters
//! 
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  Stucture version invalid
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
//! \retval ::NVAPI_DEVICE_BUSY                  Access denied for requested access
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_SetGamma(NvVioHandle           hVioHandle,
                                   NVVIOGAMMACORRECTION  *pGamma);


///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_GetGamma
//! 
//!   Description: This API gets the gamma conversion parameters.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!
//! \param [in]  NvVioHandle      The caller provides the SDI device handle as input.
//! \param [out] pGamma           Pointer to gamma parameters
//! 
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  Stucture version invalid
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_GetGamma(NvVioHandle           hVioHandle,
                                   NVVIOGAMMACORRECTION* pGamma);
 
////////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_SetSyncDelay
//! 
//!   Description: This API sets the sync delay parameters.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//! 
//! \param [in]  NvVioHandle   The caller provides the SDI device handle as input.
//! \param [in]  pSyncDelay    Pointer to sync delay parameters
//! 
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  Stucture version invalid
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
//! \retval ::NVAPI_DEVICE_BUSY                  Access denied for requested access
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_SetSyncDelay(NvVioHandle            hVioHandle,
                                       const NVVIOSYNCDELAY   *pSyncDelay);


////////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_GetSyncDelay
//! 
//!   Description: This API gets the sync delay parameters.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//! 
//! \param [in]  NvVioHandle      The caller provides the SDI device handle as input.
//! \param [out] pSyncDelay       Pointer to sync delay parameters
//! 
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  Stucture version invalid
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_GetSyncDelay(NvVioHandle      hVioHandle,
                                       NVVIOSYNCDELAY   *pSyncDelay);

////////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_IsRunning
//! 
//!   Description: This API determines if Video I/O is running.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//! 
//! \param [in]  NvVioHandle[IN]          The caller provides the SDI device handle as input.
//! 
//! \retval ::NVAPI_DRIVER_RUNNING        Video I/O running
//! \retval ::NVAPI_DRIVER_NOTRUNNING     Video I/O not running
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_IsRunning(NvVioHandle   hVioHandle);


///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_Start
//! 
//!   Description: This API starts Video I/O.
//!              This API should be called for NVVIOOWNERTYPE_DESKTOP only and will not work for OGL applications.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!
//! \param [in]  NvVioHandle[IN]     The caller provides the SDI device handle as input.
//! 
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
//! \retval ::NVAPI_DEVICE_BUSY                  Access denied for requested access
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_Start(NvVioHandle     hVioHandle);


///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_Stop
//! 
//!   Description: This API stops Video I/O.
//!              This API should be called for NVVIOOWNERTYPE_DESKTOP only and will not work for OGL applications.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//! 
//! \param [in]  NvVioHandle[IN]     The caller provides the SDI device handle as input.
//! 
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
//! \retval ::NVAPI_DEVICE_BUSY                  Access denied for requested access
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_Stop(NvVioHandle     hVioHandle);


                                               
///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_IsFrameLockModeCompatible
//! 
//!   Description: This API checks whether modes are compatible in frame lock mode.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//! 
//! \param [in]   NvVioHandle          The caller provides the SDI device handle as input.
//! \param [in]   srcEnumIndex         Source Enumeration index
//! \param [in]   destEnumIndex        Destination Enumeration index
//! \param [out]  pbCompatible         Pointer to receive compatibility
//! 
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_NOT_SUPPORTED                Video I/O not supported
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_IsFrameLockModeCompatible(NvVioHandle              hVioHandle,
                                                    NvU32                    srcEnumIndex,
                                                    NvU32                    destEnumIndex,
                                                    NvU32*                   pbCompatible);



///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_EnumDevices
//! 
//!   Description: This API enumerate all VIO devices connected to the system.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!
//! \param [out]  NvVioHandle                  User passes the pointer of NvVioHandle[] array to get handles to
//!                                            all the connected video I/O devices.
//! \param [out]  vioDeviceCount               User gets total number of VIO devices connected to the system.
//! 
//! \retval ::NVAPI_OK                         Success
//! \retval ::NVAPI_API_NOT_INTIALIZED         NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT           Arguments passed to API are not valid
//! \retval ::NVAPI_ERROR                      NVAPI Random errors
//! \retval ::NVAPI_NVIDIA_DEVICE_NOT_FOUND    No SDI Device found
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_EnumDevices(NvVioHandle       hVioHandle[NVAPI_MAX_VIO_DEVICES],
                                      NvU32             *vioDeviceCount);
                                                                                          

///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_QueryTopology
//! 
//!   Description: This API queries the valid SDI topologies.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!
//! \param [out] pNvVIOTopology     User passes the pointer to NVVIOTOPOLOGY to fetch all valid SDI topologies.
//! 
//! \retval ::NVAPI_OK                           Success
//! \retval ::NVAPI_API_NOT_INTIALIZED           NVAPI Not Initialized
//! \retval ::NVAPI_INVALID_ARGUMENT             Arguments passed to API are not valid
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  Invalid structure version
//! \retval ::NVAPI_ERROR                        NVAPI Random errors
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_QueryTopology(NV_VIO_TOPOLOGY   *pNvVIOTopology);


///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_EnumSignalFormats
//! 
//!   Description: This API enumerates signal formats supported by Video I/O.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//!
//! \param [in]   NvVioHandle          The caller provides the SDI device handle as input.
//! \param [in]   enumIndex            Enumeration index
//! \param [out]  pSignalFormatDetail  Pointer to receive detail or NULL
//! 
//! \retval ::NVAPI_OK                  Success
//! \retval ::NVAPI_API_NOT_INTIALIZED  NVAPI not initialized
//! \retval ::NVAPI_INVALID_ARGUMENT    Invalid argument passed
//! \retval ::NVAPI_END_ENUMERATION     No more signal formats to enumerate
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_EnumSignalFormats(NvVioHandle              hVioHandle,
                                            NvU32                    enumIndex,
                                            NVVIOSIGNALFORMATDETAIL  *pSignalFormatDetail);
                                            
///////////////////////////////////////////////////////////////////////////////
//!   Function:    NvAPI_VIO_EnumDataFormats
//! 
//!   Description: This API enumerates data formats supported by Video I/O.
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 190.50
//! 
//! \param [in]  NvVioHandle         The caller provides the SDI device handle as input.
//! \param [in]  enumIndex           Enumeration index
//! \param [out] pDataFormatDetail   Pointer to receive detail or NULL
//! 
//! \retval ::NVAPI_OK                Success
//! \retval ::NVAPI_END_ENUMERATION   No more data formats to enumerate
//! \retval ::NVAPI_NOT_SUPPORTED     Unsupported NVVIODATAFORMAT_ enumeration
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_VIO_EnumDataFormats(NvVioHandle            hVioHandle,
                                          NvU32                  enumIndex,
                                          NVVIODATAFORMATDETAIL  *pDataFormatDetail);
                                                                                      

//! @}



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetTachReading
//
//!   DESCRIPTION: This API retrieves the fan speed tachometer reading for the specified physical GPU.
//!
//!   HOW TO USE:   
//!                 - NvU32 Value = 0;
//!                 - ret = NvAPI_GPU_GetTachReading(hPhysicalGpu, &Value);  
//!                 - On call success:
//!                 - Value contains the tachometer reading
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]    hPhysicalGpu   GPU selection.
//! \param [out]   pValue         Pointer to a variable to get the tachometer reading
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_ERROR - miscellaneous error occurred
//! \retval ::NVAPI_NOT_SUPPORTED - functionality not supported 
//! \retval ::NVAPI_API_NOT_INTIALIZED - nvapi not initialized
//! \retval ::NVAPI_INVALID_ARGUMENT - invalid argument passed
//! \retval ::NVAPI_HANDLE_INVALIDATED - handle passed has been invalidated (see user guide)
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE - handle passed is not a physical GPU handle
//!
//! \ingroup gpucooler
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetTachReading(NvPhysicalGpuHandle hPhysicalGPU, NvU32 *pValue);









//
// NV_GET_SCALING_CAPS
//
// Interface structure used in NvAPI_GetScalingCaps call.
//
// This NvAPI_GetScalingCaps returns scaling capability info for the specified display device
//



// 3D profile for one key cinema feature



//! \addtogroup appprofileapi
//! @{

//! See NV_3D_SETTING_RANGE.
#define NV_3D_MAX_RANGE         25


//! 3D property names used in NV_3D_SETTING and NV_3D_SETTING_RANGE
typedef enum
{
    NV_3D_PROPERTY_AS         = 1,  //!< Anti-Aliasing selector
    NV_3D_PROPERTY_AA         = 2,  //!< Anti-Aliasing setting
    NV_3D_PROPERTY_AF         = 3,  //!< Anisotropic filtering
    NV_3D_PROPERTY_MAX_FRAMES = 4,  //!< Maximum pre-rendered frames
    NV_3D_PROPERTY_TEX_FILTER = 5,  //!< Texture filtering
} NV_3D_PROPERTY;


//! Used in NvAPI_3D_GetProperty() and NvAPI_3D_SetProperty().
typedef struct
{
    NvU32           version;                //!< [in] Structure version
    NV_3D_PROPERTY  settingName;            //!< [in] 3D setting
    NvU32           flags;                  //!< [out] Indicates whether the settings are read only
    NvU32           defaultValue;           //!< [out] Default base value at driver install
    NvU32           currentValue;           //!< [in/out] Current value or new value to update
} NV_3D_SETTING;


//! Used in NvAPI_3D_GetPropertyRange().
typedef struct
{
    NvU32           version;                //!< [in] Structure version
    NV_3D_PROPERTY  settingName;            //!< [in] 3D setting
    NvU32           value[NV_3D_MAX_RANGE]; //!< [out] Range of values as unique array of numbers
    NvU32           validRangeCount;        //!< [out] Number of valid items in the property
} NV_3D_SETTING_RANGE;


//! Macro for constructing the version field of NV_3D_SETTING
#define NV_3D_PROFILE_VERSION           MAKE_NVAPI_VERSION(NV_3D_SETTING,1)


//! Macro for constructing the version field of NV_3D_SETTING_RANGE
#define NV_3D_PROFILE_RANGE_VERSION     MAKE_NVAPI_VERSION(NV_3D_SETTING_RANGE,1)


//! @}

/////////////////////////////////////////////////////////////////////////////// 
// 
// FUNCTION NAME:  NvAPI_3D_GetProperty 
// 
//! DESCRIPTION:    This API gets the specific 3D profile property. \n
//! HOW TO USE:    
//!                -# Set profileName to "Base Profile"
//!                -# Set 3D property name to settingName of NV_3D_SETTING
//!                -# On call success: It returns the specific profile property setting
//!
//! \param [in]     profileName  Which profile to access
//! \param [in,out] p3dSettings  Setting of the 3D profile property 
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//! 
//! \retval ::NVAPI_OK  
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//!
//! \ingroup appprofileapi
/////////////////////////////////////////////////////////////////////////////// 
NVAPI_INTERFACE NvAPI_3D_GetProperty(NvAPI_ShortString szProfileName, NV_3D_SETTING* p3dSetting);


/////////////////////////////////////////////////////////////////////////////// 
// 
// FUNCTION NAME:  NvAPI_3D_SetProperty 
// 
//! DESCRIPTION:    This API sets the specific 3D profile property. \n
//! HOW TO USE:    
//!                -# Set profileName to "Base Profile"
//!                -# Set 3D property name to settingName of NV_3D_SETTING
//!                -# On call success: It returns the specific profile property setting
//!
//! \param [in]     profileName  Which profile to access
//! \param [in,out] p3dSettings  Setting of the 3D profile property 
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//! 
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//!
//! \ingroup appprofileapi
/////////////////////////////////////////////////////////////////////////////// 
NVAPI_INTERFACE NvAPI_3D_SetProperty(NvAPI_ShortString szProfileName, NV_3D_SETTING* p3dSetting);


/////////////////////////////////////////////////////////////////////////////// 
// 
// FUNCTION NAME:  NvAPI_3D_GetPropertyRange 
//
//! DESCRIPTION:    This API gets the specific 3D profile property setting range. \n
//! HOW TO USE:    -# Set profileName to "Base Profile".
//!                -# Set 3D property name to settingName of NV_3D_SETTING_RANGE.
//!                -# On call success: It returns the specific profile property setting.
//!
//! \param [in]     profileName      Which profile to access
//! \param [in,out] p3dSettingRange  Setting range of the 3D profile property 
//! 
//  SUPPORTED OS: Windows XP and higher
//!
//! \since Version 185.20
//! 
//! \retval ::NVAPI_OK  
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//!
//! \ingroup appprofileapi
/////////////////////////////////////////////////////////////////////////////// 
NVAPI_INTERFACE NvAPI_3D_GetPropertyRange(NvAPI_ShortString szProfileName, NV_3D_SETTING_RANGE* p3dsettingRange);







///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SYS_GetDisplayIdFromGpuAndOutputId
//
//! DESCRIPTION:     This API converts a Physical GPU handle and output ID to a
//!                  display ID.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]     hPhysicalGpu   Handle to the physical GPU
//! \param [in]     outputId       Connected display output ID on the 
//!                                target GPU - must only have one bit set
//! \param [out]    displayId      Pointer to an NvU32 which contains
//!                                 the display ID
//!
//! \retval  ::NVAPI_OK - completed request
//! \retval  ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized
//! \retval  ::NVAPI_ERROR - miscellaneous error occurred
//! \retval  ::NVAPI_INVALID_ARGUMENT - Invalid input parameter.
//!
//! \ingroup sysgeneral
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SYS_GetDisplayIdFromGpuAndOutputId(NvPhysicalGpuHandle hPhysicalGpu, NvU32 outputId, NvU32* displayId);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_SYS_GetGpuAndOutputIdFromDisplayId
//
//! DESCRIPTION:     This API converts a display ID to a Physical GPU handle and output ID.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]     displayId       Display ID of display to retrieve 
//!                                 GPU and outputId for
//! \param [out]    hPhysicalGpu    Handle to the physical GPU
//! \param [out]    outputId )      Connected display output ID on the 
//!                                 target GPU will only have one bit set.
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//! \retval ::NVAPI_ID_OUT_OF_RANGE    The DisplayId corresponds to a 
//!                                    display which is not within the
//!                                    normal outputId range.
//! \retval ::NVAPI_ERROR   
//! \retval ::NVAPI_INVALID_ARGUMENT 
//!
//! \ingroup sysgeneral
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SYS_GetGpuAndOutputIdFromDisplayId(NvU32 displayId, NvPhysicalGpuHandle *hPhysicalGpu, NvU32 *outputId);


//  SUPPORTED OS: Windows XP and higher
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_DISP_GetDisplayIdByDisplayName
//
//! DESCRIPTION:     This API retrieves the Display Id of a given display by
//!                  display name. The display must be active to retrieve the
//!                  displayId. In the case of clone mode or Surround gaming,
//!                  the primary or top-left display will be returned.
//!
//! \param [in]     displayName  Name of display (Eg: "\\DISPLAY1" to
//!                              retrieve the displayId for.
//! \param [out]    displayId    Display ID of the requested display.
//!
//! retval ::NVAPI_OK:                          Capabilties have been returned.
//! retval ::NVAPI_INVALID_ARGUMENT:            One or more args passed in are invalid.
//! retval ::NVAPI_API_NOT_INTIALIZED:          The NvAPI API needs to be initialized first
//! retval ::NVAPI_NO_IMPLEMENTATION:           This entrypoint not available
//! retval ::NVAPI_ERROR:                       Miscellaneous error occurred
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_GetDisplayIdByDisplayName(const char *displayName, NvU32* displayId);



//  SUPPORTED OS: Windows XP and higher
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_DISP_GetGDIPrimaryDisplayId
//
//! DESCRIPTION:     This API returns the Display ID of the GDI Primary.
//!
//! \param [out]     displayId   Display ID of the GDI Primary display.
//!
//! \retval ::NVAPI_OK:                          Capabilties have been returned.
//! \retval ::NVAPI_NVIDIA_DEVICE_NOT_FOUND:     GDI Primary not on an NVIDIA GPU.
//! \retval ::NVAPI_INVALID_ARGUMENT:            One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INTIALIZED:          The NvAPI API needs to be initialized first
//! \retval ::NVAPI_NO_IMPLEMENTATION:           This entrypoint not available
//! \retval ::NVAPI_ERROR:                       Miscellaneous error occurred
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_GetGDIPrimaryDisplayId(NvU32* displayId);






///////////////////////////////////////////////////////////////////////////////
// SetDisplayConfig/GetDisplayConfig
///////////////////////////////////////////////////////////////////////////////


//! \ingroup dispcontrol
typedef struct _NV_POSITION
{
    NvS32   x;
    NvS32   y;
} NV_POSITION;

//! \ingroup dispcontrol
typedef struct _NV_RESOLUTION
{
    NvU32   width;
    NvU32   height;
    NvU32   colorDepth;
} NV_RESOLUTION;

//! \ingroup dispcontrol
typedef struct _NV_DISPLAYCONFIG_PATH_ADVANCED_TARGET_INFO_V1
{
    NvU32                   version;

    // Rotation and Scaling
    NV_ROTATE               rotation;       //!< (IN) rotation setting.
    NV_SCALING              scaling;        //!< (IN) scaling setting.

    // Refresh Rate
    NvU32                   refreshRate1K;  //!< (IN) Non-interlaced Refresh Rate of the mode, multiplied by 1000, 0 = ignored
                                            //!< This is the value which driver reports to the OS.
    // Flags
    NvU32                   interlaced:1;   //!< (IN) Interlaced mode flag, ignored if refreshRate == 0
    NvU32                   primary:1;      //!< (IN) Declares primary display in clone configuration. This is *NOT* GDI Primary.
                                            //!< Only one target can be primary per source. If no primary is specified, the first 
                                            //!< target will automatically be primary.
    NvU32                   reserved:30;    //!< (IN) Reserved, must be 0

    // TV format information
    NV_GPU_CONNECTOR_TYPE   connector;      //!< Specify connector type. For TV only, ignored if tvFormat == NV_DISPLAY_TV_FORMAT_NONE
    NV_DISPLAY_TV_FORMAT    tvFormat;       //!< (IN) to choose the last TV format set this value to NV_DISPLAY_TV_FORMAT_NONE

    // Backend (raster) timing standard
    NV_TIMING_OVERRIDE      timingOverride;     //!< Ignored if timingOverride == NV_TIMING_OVERRIDE_CURRENT
    NV_TIMING               timing;             //!< Scan out timing, valid only if timingOverride == NV_TIMING_OVERRIDE_CUST
                                                //!< The value NV_TIMING::NV_TIMINGEXT::rrx1k is obtained from the EDID. The driver may 
                                                //!< tweak this value for HDTV, stereo, etc., before reporting it to the OS. 
} NV_DISPLAYCONFIG_PATH_ADVANCED_TARGET_INFO_V1;

//! \ingroup dispcontrol
typedef NV_DISPLAYCONFIG_PATH_ADVANCED_TARGET_INFO_V1 NV_DISPLAYCONFIG_PATH_ADVANCED_TARGET_INFO;

//! \ingroup dispcontrol
#define NV_DISPLAYCONFIG_PATH_ADVANCED_TARGET_INFO_VER1     MAKE_NVAPI_VERSION(NV_DISPLAYCONFIG_PATH_ADVANCED_TARGET_INFO_V1,1)

//! \ingroup dispcontrol
#define NV_DISPLAYCONFIG_PATH_ADVANCED_TARGET_INFO_VER      NV_DISPLAYCONFIG_PATH_ADVANCED_TARGET_INFO_VER1

//! \ingroup dispcontrol
typedef struct _NV_DISPLAYCONFIG_PATH_TARGET_INFO_V1
{
    NvU32                                           displayId;  //!< Display ID
    NV_DISPLAYCONFIG_PATH_ADVANCED_TARGET_INFO*     details;    //!< May be NULL if no advanced settings are required. NULL for Non-NVIDIA Display.
} NV_DISPLAYCONFIG_PATH_TARGET_INFO_V1;

//! \ingroup dispcontrol
typedef struct _NV_DISPLAYCONFIG_PATH_TARGET_INFO_V2
{
    NvU32                                           displayId;  //!< Display ID
    NV_DISPLAYCONFIG_PATH_ADVANCED_TARGET_INFO*     details;    //!< May be NULL if no advanced settings are required
    NvU32                                           targetId;   //!< Windows CCD target ID. Must be present only for non-NVIDIA adapter, for NVIDIA adapter this parameter is ignored.
} NV_DISPLAYCONFIG_PATH_TARGET_INFO_V2;


//! \ingroup dispcontrol
//! As version is not defined for this structure we will be using version of NV_DISPLAYCONFIG_PATH_INFO
typedef NV_DISPLAYCONFIG_PATH_TARGET_INFO_V2 NV_DISPLAYCONFIG_PATH_TARGET_INFO; 


//! \ingroup dispcontrol
typedef enum _NV_DISPLAYCONFIG_SPANNING_ORIENTATION
{
    NV_DISPLAYCONFIG_SPAN_NONE          = 0,
    NV_DISPLAYCONFIG_SPAN_HORIZONTAL    = 1,
    NV_DISPLAYCONFIG_SPAN_VERTICAL      = 2,
} NV_DISPLAYCONFIG_SPANNING_ORIENTATION;

//! \ingroup dispcontrol
typedef struct _NV_DISPLAYCONFIG_SOURCE_MODE_INFO_V1
{
    NV_RESOLUTION                           resolution;
    NV_FORMAT                               colorFormat;                //!< Ignored at present, must be NV_FORMAT_UNKNOWN (0)
    NV_POSITION                             position;                   //!< Is all positions are 0 or invalid, displays will be automatically
                                                                        //!< positioned from left to right with GDI Primary at 0,0, and all
                                                                        //!< other displays in the order of the path array.
    NV_DISPLAYCONFIG_SPANNING_ORIENTATION   spanningOrientation;        //!< Spanning is only supported on XP
    NvU32                                   bGDIPrimary : 1;
    NvU32                                   bSLIFocus : 1;
    NvU32                                   reserved : 30;              //!< Must be 0
} NV_DISPLAYCONFIG_SOURCE_MODE_INFO_V1;

//! \ingroup dispcontrol
//! As version is not defined for this structure we will be using version of NV_DISPLAYCONFIG_PATH_INFO
typedef NV_DISPLAYCONFIG_SOURCE_MODE_INFO_V1 NV_DISPLAYCONFIG_SOURCE_MODE_INFO; 

//! \ingroup dispcontrol
typedef struct _NV_DISPLAYCONFIG_PATH_INFO_V1
{
    NvU32                                   version;
    NvU32                                   reserved_sourceId;     //!< This field is reserved. There is ongoing debate if we need this field.
                                                                        //!< Identifies sourceIds used by Windows. If all sourceIds are 0, 
                                                                        //!< these will be computed automatically.
    NvU32                                   targetInfoCount;            //!< Number of elements in targetInfo array
    NV_DISPLAYCONFIG_PATH_TARGET_INFO_V1*   targetInfo;
    NV_DISPLAYCONFIG_SOURCE_MODE_INFO*      sourceModeInfo;             //!< May be NULL if mode info is not important
} NV_DISPLAYCONFIG_PATH_INFO_V1;

//! \ingroup dispcontrol
//! This define is temporary and must be removed once DVS failure is fixed.
#define _NV_DISPLAYCONFIG_PATH_INFO_V2 _NV_DISPLAYCONFIG_PATH_INFO

//! \ingroup dispcontrol
typedef struct _NV_DISPLAYCONFIG_PATH_INFO_V2
{
    NvU32                                   version;
    union {
        NvU32                                   sourceId;            //!< Identifies sourceId used by Windows CCD. This can be optionally set.
        NvU32                                   reserved_sourceId;      //!< Only for compatibility
    };

    NvU32                                   targetInfoCount;            //!< Number of elements in targetInfo array
    NV_DISPLAYCONFIG_PATH_TARGET_INFO*      targetInfo;
    NV_DISPLAYCONFIG_SOURCE_MODE_INFO*      sourceModeInfo;             //!< May be NULL if mode info is not important
    NvU32                                   IsNonNVIDIAAdapter : 1;     //!< True for non-NVIDIA adapter.
    NvU32                                   reserved : 31;              //!< Must be 0
    void                                    *pOSAdapterID;              //!< Used by Non-NVIDIA adapter for pointer to OS Adapter of LUID 
                                                                        //!< type, type casted to void *.
} NV_DISPLAYCONFIG_PATH_INFO_V2;

typedef NV_DISPLAYCONFIG_PATH_INFO_V2 NV_DISPLAYCONFIG_PATH_INFO;

//! \ingroup dispcontrol
#define NV_DISPLAYCONFIG_PATH_INFO_VER1                 MAKE_NVAPI_VERSION(NV_DISPLAYCONFIG_PATH_INFO_V1,1)

//! \ingroup dispcontrol
#define NV_DISPLAYCONFIG_PATH_INFO_VER2                 MAKE_NVAPI_VERSION(NV_DISPLAYCONFIG_PATH_INFO_V2,2)

//! \ingroup dispcontrol
#define NV_DISPLAYCONFIG_PATH_INFO_VER                  NV_DISPLAYCONFIG_PATH_INFO_VER2

//! \ingroup dispcontrol
typedef enum _NV_DISPLAYCONFIG_FLAGS
{
    NV_DISPLAYCONFIG_VALIDATE_ONLY          = 0x00000001,
    NV_DISPLAYCONFIG_SAVE_TO_PERSISTENCE    = 0x00000002, 
    NV_DISPLAYCONFIG_DRIVER_RELOAD_ALLOWED  = 0x00000004,               //!< Driver reload is permitted if necessary
    NV_DISPLAYCONFIG_FORCE_MODE_ENUMERATION = 0x00000008,               //!< Refresh OS mode list.
} NV_DISPLAYCONFIG_FLAGS;


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_DISP_GetDisplayConfig
//
// DESCRIPTION:     This API lets caller retrieve the current global display
//                  configuration.
//       USAGE:     The caller might have to call this three times to fetch all the required configuration details as following 
//                  First  Pass: 
//                               Caller should Call NvAPI_DISP_GetDisplayConfig() with pathInfo set to NULL to fetch pathInfoCount
//                  Second Pass:
//                               Allocate memory for pathInfo with respect to number of pathInfoCount(from First Pass) to fetch targetInfoCount,
//								 If sourceModeInfo is needed allocate memory or it can be initialized to NULL
//					Third  Pass(Optional, only required if target information is required):
//					             Allocate memory for targetInfo with respect to number of targetInfoCount(from Second Pass)			   
//  SUPPORTED OS: Windows Vista and higher
//
// PARAMETERS:      pathInfoCount(IN/OUT) - Number of elements in pathInfo array, returns number of valid topologies, this cannot be null.
//                  pathInfo(IN/OUT) - Array of path information
//
// RETURN STATUS:   This API can return any of the error codes enumerated in #NvAPI_Status. If there are return error codes with 
//                  specific meaning for this API, they are listed below.
//
//                 
//                  NVAPI_INVALID_ARGUMENT  -   Invalid input parameter. Following can be the reason for this return value:
//                                              1. pathInfoCount is NULL.
//                                              2. *pathInfoCount is 0 and pathInfo is not NULL.
//                                              3. *pathInfoCount is not 0 and pathInfo is NULL.
//
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_GetDisplayConfig(__inout NvU32 *pathInfoCount, __out_ecount_full_opt(*pathInfoCount) NV_DISPLAYCONFIG_PATH_INFO *pathInfo);




///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:   NvAPI_DISP_SetDisplayConfig
//
//
//! DESCRIPTION:     This API lets caller apply a global display configuration
//!                  across multiple GPUs.
//!
//!                  If all sourceIds are zero, then NvAPI will pick up sourceId's based on the following criteria :
//!                  - If user provides sourceModeInfo then we are trying to assign 0th sourceId always to GDIPrimary. 
//!                     This is needed since active windows always moves along with 0th sourceId.
//!                  - For the rest of paths we are incremementally assigning the sourceId per adapter basis.
//!                  - If user doesn't provide sourceModeInfo then NVAPI just picks up some default sourceId's in incremental order. \p
//!                  Note : NVAPI will not intelligently choose the sourceIDs for any configs that does not need a modeset.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]      pathInfoCount   Number of supplied elements in pathInfo
//! \param [in]      pathInfo        Array of path information
//! \param [in]      flags           Flags for applying settings
//! 
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_API_NOT_INTIALIZED - NVAPI not initialized
//! \retval ::NVAPI_ERROR - miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT - Invalid input parameter.
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_SetDisplayConfig(__in NvU32 pathInfoCount, __in_ecount(pathInfoCount) NV_DISPLAYCONFIG_PATH_INFO* pathInfo, __in NvU32 flags);





#define MAX_PCLK_RANGES 10

//! \addtogroup gpuclock
//! @{

//! Used in NV_SET_PCLK and NV_GET_PCLK.
typedef struct
{
    NvU32           uMaxPixClk;                         //!< Maximum Upper Frequency
    NvU32           uMinPixClk;                         //!< Minimum Upper Frequency
} NV_PCLK_RANGE;


//! Used in NvAPI_GPU_GetPixelClockRange().
typedef struct
{
    NvU32           uOrgPixelClock;                     //!< Original Frequency in Hz
    NvU32           uCurrPixelClock;                    //!< Frequency in Hz
    NvU32           uCurrSpreadSpectrum;                //!< Spread Spectrum Range in Hz
    NV_PCLK_RANGE   uFineAdjustBounds;                  //!< Optional: Upper/Lower bounds
                                                        //!< If not present then only 
                                                        //!< course adjustment is supported. 
    NV_PCLK_RANGE   uCourseAdjustBounds;                //!< Timing Shift Upper/Lower
} NV_GET_PCLK;


//! Used in NvAPI_GPU_SetPixelClockRange().
typedef struct
{
    NV_PCLK_RANGE   uAllowedRanges[MAX_PCLK_RANGES];    //!< Allowed List
    NV_PCLK_RANGE   uDisallowedRanges[MAX_PCLK_RANGES]; //!< Disallowed List
} NV_SET_PCLK;


//! @}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetPixelClockRange
//
//! DESCRIPTION:   This API retrieves the current pixel clock settings from the driver.
//!
//!                  NOTE 1: use hPhysicalGpu=NULL and outputId=0 to specify the
//!                  first internal panel.
//!
//!                  NOTE 2: the outputId must refer to an internal panel
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]    hPhysicalGpu    GPU selection
//! \param [in]    outputId        Display output id
//! \param [out]   pTimings        Current pixel clock settings
//!
//! 
//! \retval ::NVAPI_OK                   completed request
//! \retval ::NVAPI_API_NOT_INITIALIZED  NVAPI not initialized
//! \retval ::NVAPI_ERROR                miscellaneous error occurred
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPixelClockRange(NvPhysicalGpuHandle hPhysicalGpu, NvU32 outputId, NV_GET_PCLK *pTimings);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_SetPixelClockRange
//
//! DESCRIPTION:   This API passes allowed and disallowed pixel clock values to the 
//!                driver.  If the driver finds a potential timing, it sets the modes 
//!                to this timing.
//!
//!                  NOTE: use hPhysicalGpu=NULL and outputId=0 to specify the
//!                  first internal panel.
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]    hPhysicalGpu    GPU selection
//! \param [in]    outputId        Display output id
//! \param [in]    pTimings         Allowed and disallowed pixel clock ranges
//!
//! 
//! \retval ::NVAPI_OK                   completed request
//! \retval ::NVAPI_API_NOT_INITIALIZED  NVAPI not initialized
//! \retval ::NVAPI_ERROR                miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT     no suitable pixel clock was found
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetPixelClockRange(NvPhysicalGpuHandle hPhysicalGpu, NvU32 outputId, NV_SET_PCLK *pTimings);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetECCStatusInfo
//
//! \fn NvAPI_GPU_GetECCStatusInfo(NvPhysicalGpuHandle hPhysicalGpu, 
//!                                           NV_GPU_ECC_STATUS_INFO *pECCStatusInfo);
//! DESCRIPTION:     This function returns ECC memory status information.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]      hPhysicalGpu      A handle identifying the physical GPU for which ECC 
//!                                    status information is to be retrieved.
//! \param [out]     pECCStatusInfo    A pointer to an ECC status structure.
//! 
//! \retval ::NVAPI_OK                  The request was completed successfully.
//! \retval ::NVAPI_ERROR               An unknown error occurred.
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE The provided GPU handle is not a physical GPU handle.
//! \retval ::NVAPI_INVALID_HANDLE      The provided GPU handle is invalid.
//! \retval ::NVAPI_HANDLE_INVALIDATED  The provided GPU handle is no longer valid.
//! \retval ::NVAPI_INVALID_POINTER     An invalid argument pointer was provided.
//! \retval ::NVAPI_NOT_SUPPORTED       The request is not supported.
//! \retval ::NVAPI_API_NOT_INTIALIZED  NvAPI was not yet initialized.
//
///////////////////////////////////////////////////////////////////////////////

//! \addtogroup gpuecc
//! Used in NV_GPU_ECC_STATUS_INFO.
typedef enum _NV_ECC_CONFIGURATION
{
    NV_ECC_CONFIGURATION_NOT_SUPPORTED = 0,
    NV_ECC_CONFIGURATION_DEFERRED,           //!< Changes require a POST to take effect
    NV_ECC_CONFIGURATION_IMMEDIATE,          //!< Changes can optionally be made to take effect immediately
} NV_ECC_CONFIGURATION;

//! \ingroup gpuecc
//! Used in NvAPI_GPU_GetECCStatusInfo().
typedef struct
{
    NvU32                 version;               //!< Structure version
    NvU32                 isSupported : 1;       //!< ECC memory feature support
    NV_ECC_CONFIGURATION  configurationOptions;  //!< Supported ECC memory feature configuration options
    NvU32                 isEnabled : 1;         //!< Active ECC memory setting
} NV_GPU_ECC_STATUS_INFO;

//! \ingroup gpuecc
//! Macro for constructing the version field of NV_GPU_ECC_STATUS_INFO
#define NV_GPU_ECC_STATUS_INFO_VER MAKE_NVAPI_VERSION(NV_GPU_ECC_STATUS_INFO,1)

//! \ingroup gpuecc
NVAPI_INTERFACE NvAPI_GPU_GetECCStatusInfo(NvPhysicalGpuHandle hPhysicalGpu, 
                                           NV_GPU_ECC_STATUS_INFO *pECCStatusInfo);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetECCErrorInfo
//
//! \fn NvAPI_GPU_GetECCErrorInfo(NvPhysicalGpuHandle hPhysicalGpu, 
//!                                          NV_GPU_ECC_ERROR_INFO *pECCErrorInfo);
//!
//! DESCRIPTION:     This function returns ECC memory error information.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]      hPhysicalGpu  A handle identifying the physical GPU for
//!                                which ECC error information is to be
//!                                retrieved.
//! \param [out]     pECCErrorInfo A pointer to an ECC error structure.
//! 
//! \retval ::NVAPI_OK  The request was completed successfully.
//! \retval ::NVAPI_ERROR  An unknown error occurred.
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  The provided GPU handle is not a physical GPU handle.
//! \retval ::NVAPI_INVALID_ARGUMENT  incorrect param value
//! \retval ::NVAPI_INVALID_POINTER  An invalid argument pointer was provided.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  structure version is not supported, initialize to NV_GPU_ECC_ERROR_INFO_VER.
//! \retval ::NVAPI_HANDLE_INVALIDATED  The provided GPU handle is no longer valid.
//! \retval ::NVAPI_NOT_SUPPORTED  The request is not supported.
//! \retval ::NVAPI_API_NOT_INTIALIZED  NvAPI was not yet initialized.
//
///////////////////////////////////////////////////////////////////////////////


//! \ingroup gpuecc
//! Used in NvAPI_GPU_GetECCErrorInfo()/
typedef struct
{
    NvU32   version;             //!< Structure version
    struct {
        NvU64  singleBitErrors;  //!< Number of single-bit ECC errors detected since last boot
        NvU64  doubleBitErrors;  //!< Number of double-bit ECC errors detected since last boot
    } current;
    struct {
        NvU64  singleBitErrors;  //!< Number of single-bit ECC errors detected since last counter reset
        NvU64  doubleBitErrors;  //!< Number of double-bit ECC errors detected since last counter reset
    } aggregate;
} NV_GPU_ECC_ERROR_INFO;

//! \ingroup gpuecc
//! Macro for constructing the version field of NV_GPU_ECC_ERROR_INFO
#define NV_GPU_ECC_ERROR_INFO_VER MAKE_NVAPI_VERSION(NV_GPU_ECC_ERROR_INFO,1)

//! \ingroup gpuecc
NVAPI_INTERFACE NvAPI_GPU_GetECCErrorInfo(NvPhysicalGpuHandle hPhysicalGpu, 
                                          NV_GPU_ECC_ERROR_INFO *pECCErrorInfo);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_ResetECCErrorInfo
//
//! DESCRIPTION:     This function resets ECC memory error counters.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]     hPhysicalGpu     A handle identifying the physical GPU for
//!                                  which ECC error information is to be
//!                                  cleared.
//! \param [in]     bResetCurrent    Reset the current ECC error counters.
//! \param [in]     bResetAggregate  Reset the aggregate ECC error counters.
//! 
//! \retval ::NVAPI_OK  The request was completed successfully.
//! \retval ::NVAPI_ERROR  An unknown error occurred.
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  The provided GPU handle is not a physical GPU handle.
//! \retval ::NVAPI_INVALID_HANDLE  The provided GPU handle is invalid.
//! \retval ::NVAPI_HANDLE_INVALIDATED  The provided GPU handle is no longer valid.
//! \retval ::NVAPI_NOT_SUPPORTED  The request is not supported.
//! \retval ::NVAPI_API_NOT_INTIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup gpuecc
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_ResetECCErrorInfo(NvPhysicalGpuHandle hPhysicalGpu, NvU8 bResetCurrent,
                                            NvU8 bResetAggregate);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_GetECCConfigurationInfo
//
//! \fn NvAPI_GPU_GetECCConfigurationInfo(NvPhysicalGpuHandle hPhysicalGpu, 
//!                             NV_GPU_ECC_CONFIGURATION_INFO *pECCConfigurationInfo);
//! DESCRIPTION:     This function returns ECC memory configuration information.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]      hPhysicalGpu  A handle identifying the physical GPU for
//!                                which ECC configuration information
//!                               is to be retrieved.
//! \param [out]     pECCConfigurationInfo  A pointer to an ECC 
//!                                                configuration structure.
//! 
//! \retval ::NVAPI_OK  The request was completed successfully.
//! \retval ::NVAPI_ERROR  An unknown error occurred.
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  The provided GPU handle is not a physical GPU handle.
//! \retval ::NVAPI_INVALID_HANDLE  The provided GPU handle is invalid.
//! \retval ::NVAPI_HANDLE_INVALIDATED  The provided GPU handle is no longer valid.
//! \retval ::NVAPI_INVALID_POINTER  An invalid argument pointer was provided.
//! \retval ::NVAPI_NOT_SUPPORTED  The request is not supported.
//! \retval ::NVAPI_API_NOT_INTIALIZED  NvAPI was not yet initialized.
//
///////////////////////////////////////////////////////////////////////////////

//! \ingroup gpuecc
//! Used in NvAPI_GPU_GetECCConfigurationInfo(). 
typedef struct
{
    NvU32  version;                 //! Structure version
    NvU32  isEnabled : 1;           //! Current ECC configuration stored in non-volatile memory
    NvU32  isEnabledByDefault : 1;  //! Factory default ECC configuration (static)
} NV_GPU_ECC_CONFIGURATION_INFO;

//! \ingroup gpuecc
//! Macro for consstructing the verion field of NV_GPU_ECC_CONFIGURATION_INFO
#define NV_GPU_ECC_CONFIGURATION_INFO_VER MAKE_NVAPI_VERSION(NV_GPU_ECC_CONFIGURATION_INFO,1)

//! \ingroup gpuecc
NVAPI_INTERFACE NvAPI_GPU_GetECCConfigurationInfo(NvPhysicalGpuHandle hPhysicalGpu, 
                                                  NV_GPU_ECC_CONFIGURATION_INFO *pECCConfigurationInfo);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_GPU_SetECCConfiguration
//
//! DESCRIPTION:     This function updates the ECC memory configuration setting.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]      hPhysicalGpu    A handle identifying the physical GPU for
//!                                  which to update the ECC configuration
//!                                  setting.
//! \param [in]      bEnable         The new ECC configuration setting.
//! \param [in]      bEnableImmediately   Request that the new setting take effect immediately.
//! 
//! \retval ::NVAPI_OK  The request was completed successfully.
//! \retval ::NVAPI_ERROR  An unknown error occurred.
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE  The provided GPU handle is not a physical GPU handle.
//! \retval ::NVAPI_INVALID_HANDLE  The provided GPU handle is invalid.
//! \retval ::NVAPI_HANDLE_INVALIDATED  The provided GPU handle is no longer valid.
//! \retval ::NVAPI_NOT_SUPPORTED  The request is not supported.
//! \retval ::NVAPI_API_NOT_INTIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup gpuecc
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_SetECCConfiguration(NvPhysicalGpuHandle hPhysicalGpu, NvU8 bEnable,
                                              NvU8 bEnableImmediately);



#if defined(_D3D9_H_) || defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D_SetFPSIndicatorState
//
//!   DESCRIPTION: Display an overlay that tracks the number of times the app presents per second, or,   
//!      the number of frames-per-second (FPS)
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in] bool    Whether or not to enable the fps indicator.
//!                
//! \return ::NVAPI_OK, 
//!         ::NVAPI_ERROR
//!
//! \ingroup dx 
/////////////////////////////////////////////////////////////////////////////// 
NVAPI_INTERFACE NvAPI_D3D_SetFPSIndicatorState(IUnknown *pDev, NvU8 doEnable);

#endif //if defined(_D3D9_H_) || defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)


#if defined(_D3D9_H_)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_Present
//
//! DESCRIPTION: This API presents the contents of the next buffer in the sequence of back buffers 
//!              owned by a IDirect3DDevice9 device.
//!              This Present operation supports using a SwapGroup and SwapBarrier on the SwapChain
//!              that owns the back buffer to be presented.
//!
//!          NOTE: NvAPI_D3D9_Present is a wrapper of the method IDirect3DDevice9::Present which
//!                additionally notifies the D3D driver of the SwapChain used by the runtime for
//!                presentation, thus allowing the D3D driver to apply SwapGroup and SwapBarrier
//!                functionality to that SwapChain.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]    pDevice 	The IDirect3DDevice9 interface that is used to issue the Present, 
//!				using the following IDirect3DDevice9::Present input parameters
//! \param [in]    pSwapChain   Optional pointer to a IDirect3DSwapChain9 interface. If provided, the presentation is executed
//!                             using this interface (i.e. pSwapChain->Present()) for the given swapchain only.
//!                             If NULL, the presentation is executed on the device for all swapchains as in pDevice->Present()
//! \param [in]    pSourceRect  A pointer to a RECT structure containing the source rectangle. 
//!                             If NULL, the entire source surface is presented.
//! \param [in]    pDestRect  	A pointer to a RECT structure containing the destination rectangle, in window client coordinates. 
//!   				If NULL, the entire client area is filled. 
//! \param [in]    hDestWindowOverride  A pointer to a destination window whose client area is taken as the target for this presentation. 
//!                                     If this value is NULL, then the hWndDeviceWindow member of D3DPRESENT_PARAMTERS is taken. 
//! \param [in]    pDirtyRegion (IN)   A pointer to a region to be presented. It must be NULL unless the swap chain was reated with 
//!                                    D3DSWAPEFFECT_COPY. If this value is non-NULL, the contained region is expressed in back buffer coordinates.
//!
//! \retval ::NVAPI_OK                 the Present operation was successfully executed
//! \retval ::NVAPI_D3D_DEVICE_LOST    D3D device status is D3DERR_DEVICELOST or D3DERR_DEVICENOTRESET, the caller has to reset device   
//! \retval ::NVAPI_DEVICE_BUSY        the Present operation failed with an error other than D3DERR_DEVICELOST or D3DERR_DEVICENOTRESET
//! \retval ::NVAPI_ERROR              the communication with the D3D driver failed, SwapGroup/SwapBarrier may not be possible.
//! \retval ::NVAPI_API_NOT_INITIALIZED NvAPI was not yet initialized.
//!
//!\ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_Present(IDirect3DDevice9 *pDevice,
                                   IDirect3DSwapChain9 *pSwapChain,
                                   const RECT *pSourceRect,
                                   const RECT *pDestRect,
                                   HWND hDestWindowOverride,
                                   const RGNDATA *pDirtyRegion);
#endif //if defined(_D3D9_H_)

#if defined(_D3D9_H_)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_QueryFrameCount
//
//!   DESCRIPTION: This API queries the universal framecounter of the G-Sync master device.
//!
//! \param [in]   pDevice            The caller provides the DX9 device that has access to the GSync device
//! \param [out]  pFrameCount        The caller provides the storage space where the framecount is stored.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                  *pFrameCount populated with framecount value.
//! \retval ::NVAPI_ERROR               The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT    One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_QueryFrameCount(IDirect3DDevice9 *pDevice,
                                           NvU32 *pFrameCount);
#endif //if defined(_D3D9_H_)

#if defined(_D3D9_H_)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_ResetFrameCount
//
//!   DESCRIPTION: This API resets the universal framecounter on the G-Sync master device.
//!
//! \param [in]   pDevice            The caller provides the DX9 device that has access to the GSync device
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                   framecounter has been reset
//! \retval ::NVAPI_ERROR                The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT     One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_ResetFrameCount(IDirect3DDevice9 *pDevice);
#endif //if defined(_D3D9_H_)

#if defined(_D3D9_H_)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_QueryMaxSwapGroup
//
//!   DESCRIPTION: This API queries the number of supported SwapGroups and SwapBarriers in the graphics system.
//!
//! \param [in]   pDevice              The caller provides the DirectX 9 device that is used as a swapgroup client
//! \param [out]  pMaxGroups           The caller provides the storage space where the number of available SwapGroups is stored.
//! \param [out]  pMaxBarriers         The caller provides the storage space where the number of available SwapBarriers is stored.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                   the number of SwapGroups and SwapBarriers has been stored
//! \retval ::NVAPI_ERROR                The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT     One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_QueryMaxSwapGroup(IDirect3DDevice9 *pDevice, 
                                             NvU32 *pMaxGroups, 
                                             NvU32 *pMaxBarriers); 
#endif //if defined(_D3D9_H_)

#if defined(_D3D9_H_)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_QuerySwapGroup
//
//!   DESCRIPTION: This API queries the current SwapGroup and SwapBarrier that a SwapChain of a specific client device is bound to.
//!
//! \param [in]   pDevice            The caller provides the DirectX 9 device that is used as a swapgroup client
//! \param [in]   pSwapChain         The caller provides the IDirect3DSwapChain9 interface as a handle to the SwapChain  
//!                                  that belongs to the swapgroup client device
//! \param [out]  pSwapGroup         The caller provides the storage space where the current SwapGroup is stored.
//! \param [out]  pSwapBarrier       The caller provides the storage space where the current SwapBarrier is stored.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                   the current SwapGroup and SwapBarrier has been stored
//! \retval ::NVAPI_ERROR                The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT     One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_QuerySwapGroup(IDirect3DDevice9 *pDevice, 
                                          IDirect3DSwapChain9 *pSwapChain, 
                                          NvU32 *pSwapGroup, 
                                          NvU32 *pSwapBarrier); 
#endif //if defined(_D3D9_H_)

#if defined(_D3D9_H_)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_JoinSwapGroup
//
//!   DESCRIPTION: This API causes the SwapChain of a SwapGroup client to join or leave the specified SwapGroup.
//!
//! \param [in]    pDevice               The caller provides the DirectX 9 device that is used as a swapgroup client
//! \param [in]    pSwapChain            The caller provides the IDirect3DSwapChain9 interface as a handle to the SwapChain  
//!                                      that belongs to the swapgroup client device
//! \param [in]    group                 The caller specifies the SwapGroup which the SwapChain should join.
//!                                      - If the value of group is zero, the SwapChain leaves the SwapGroup.
//!                                      - The SwapChain joins a SwapGroup if the SwapGroup number is a positive integer less than or
//!                                        equal to the maximum number of SwapGroups queried by NvAPI_SwapGroup_QueryMaxSwapGroup.
//! \param [in]    blocking              The caller specifies that a presentation of this SwapChain should return immediately or block
//!                                      until all members of the SwapGroup are ready and the presentation was actually executed.
//!                                      A boolean value of false means the Present operation returns immediately and a value of true
//!                                      means the Present operation is blocking.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                   the SwapChain joined/left the SwapGroup accordingly
//! \retval ::NVAPI_ERROR                The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT     One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_JoinSwapGroup(IDirect3DDevice9 *pDevice, 
                                         IDirect3DSwapChain9 *pSwapChain, 
                                         NvU32 group,
                                         BOOL blocking); 
#endif //if defined(_D3D9_H_)

#if defined(_D3D9_H_)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D9_BindSwapBarrier
//
//!   DESCRIPTION: This API causes a SwapGroup to be bound to or released from the specified SwapBarrier.
//!
//! \param [in]    pDevice    The caller provides the DirectX 9 device that is used as a swapgroup client
//! \param [in]    group      The caller specifies the SwapGroup to be bound to the SwapBarrier.
//! \param [in]    barrier    The caller specifies the SwapBarrier that the SwapGroup should be bound to.
//!                              - If the value of barrier is zero, the SwapGroup will be released from the SwapBarrier.
//!                              - The SwapGroup will be bound to the SwapBarrier if the value of barrier is a positive 
//!                                integer less than or equal to the maximum number of SwapBarriers queried by NvAPI_SwapGroup_QueryMaxSwapGroup.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                  the SwapGroup is bound to or released from the specified SwapBarrier
//! \retval ::NVAPI_ERROR               The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT    One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D9_BindSwapBarrier(IDirect3DDevice9 *pDevice, 
                                           NvU32 group, 
                                           NvU32 barrier); 
#endif //if defined(_D3D9_H_)

#if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D1x_Present
//
//! DESCRIPTION: Presents the contents of the next buffer in the sequence of back buffers 
//!              owned by a D3D device.
//!              This Present operation supports using a SwapGroup and SwapBarrier on the SwapChain
//!              that owns the back buffer to be presented.
//!
//!          NOTE: NvAPI_D3D1x_Present is a wrapper of the method IDXGISwapChain::Present which
//!                additionally notifies the D3D driver of the SwapChain used by the runtime for
//!                presentation, thus allowing the D3D driver to apply SwapGroup and SwapBarrier
//!                functionality to that SwapChain.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]     pDevice          The D3D device interface that is used to issue the Present operation, 
//!	                             using the following IDirect3DDevice9::Present input parameters.
//!                                  pDevice can be either ID3D10Device or ID3D10Device1 or ID3D11Device.
//! \param [in]     pSwapChain       The IDXGISwapChain interface that is intended to present
//! \param [in]     SyncInterval     An integer that specifies the how to synchronize presentation of a frame with the vertical blank.
//!                                          Values are: 
//!                                          - 0:  The presentation occurs immediately, there is no synchronization.
//!                                          - 1,2,3,4 : Synchronize presentation after the n'th vertical blank.
//! \param [in]     Flags            An integer value that contains swap-chain presentation options as defined in DXGI_PRESENT.
//!
//! \retval ::NVAPI_OK                 the Present operation was successfully executed
//! \retval ::NVAPI_DEVICE_BUSY        the Present operation failed with an error DXGI_ERROR_DEVICE_RESET or DXGI_ERROR_DEVICE_REMOVED, 
//                                     DXGI_STATUS_OCCLUDED, or D3DDDIERR_DEVICEREMOVED. 
//! \retval ::NVAPI_ERROR              the communication with the D3D driver failed, SwapGroup/SwapBarrier may not be possible.
//! \retval ::NVAPI_API_NOT_INITIALIZED NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D1x_Present(IUnknown *pDevice,
                                    IDXGISwapChain *pSwapChain,
                                    UINT SyncInterval,
                                    UINT Flags);

#endif //if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)

#if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D1x_QueryFrameCount
//
//!   DESCRIPTION: This API queries the universal framecounter of the G-Sync master device.
//!
//! \param [in]    pDevice           The caller provides the D3D device that has access to the G-Sync device,
//!                                  pDevice can be either ID3D10Device or ID3D10Device1 or ID3D11Device.
//! \param [out]   pFrameCount       The caller provides the storage space where the framecount is stored.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                   *pFrameCount populated with framecount value.
//! \retval ::NVAPI_ERROR                The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT     One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D1x_QueryFrameCount(IUnknown *pDevice,
                                            NvU32 *pFrameCount);
#endif //if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)

#if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D1x_ResetFrameCount
//
//!   DESCRIPTION: This API resets the universal framecounter on the G-Sync master device.
//!
//! \param [in]    pDevice         The caller provides the D3D device that has access to the GSync device,
//!                                pDevice can be either ID3D10Device or ID3D10Device1 or ID3D11Device.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                   framecounter has been reset
//! \retval ::NVAPI_ERROR                The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT     pDevice arg passed in is invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D1x_ResetFrameCount(IUnknown *pDevice);
#endif //if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)

#if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D1x_QueryMaxSwapGroup
//
//!   DESCRIPTION: This API queries the number of supported SwapGroups and SwapBarriers in the graphics system.
//!
//! \param [in]    pDevice        The caller provides the D3D device that is intended to use SwapGroup functionality.
//!                               pDevice can be either ID3D10Device or ID3D10Device1 or ID3D11Device.
//! \param [out]   pMaxGroups     The caller provides the storage space where the number of available SwapGroups is stored.
//! \param [out]   pMaxBarriers   The caller provides the storage space where the number of available SwapBarriers is stored.
//! 
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                  the number of SwapGroups and SwapBarriers has been stored
//! \retval ::NVAPI_ERROR               The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT    One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D1x_QueryMaxSwapGroup(IUnknown *pDevice, 
                                              NvU32 *pMaxGroups, 
                                              NvU32 *pMaxBarriers); 
#endif //if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)

#if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D1x_QuerySwapGroup
//
//!   DESCRIPTION: This API queries the current SwapGroup and SwapBarrier that a SwapChain of a specific client device is bound to.
//!
//! \param [in]    pDevice            The caller provides the D3D device that owns the SwapChain used as a SwapGroup client.
//!                                   pDevice can be either ID3D10Device or ID3D10Device1 or ID3D11Device.
//! \param [in]    pSwapChain         The IDXGISwapChain interface that is used as the SwapGroup client.
//!
//! \param [out]   pSwapGroup         The caller provides the storage space where the current SwapGroup is stored.
//! \param [out]   pSwapBarrier       The caller provides the storage space where the current SwapBarrier is stored.
//! 
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                   the current SwapGroup and SwapBarrier has been stored
//! \retval ::NVAPI_ERROR                The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT     One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D1x_QuerySwapGroup(IUnknown *pDevice, 
                                           IDXGISwapChain  *pSwapChain, 
                                           NvU32 *pSwapGroup, 
                                           NvU32 *pSwapBarrier); 
#endif //if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)

#if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D1x_JoinSwapGroup
//
//!   DESCRIPTION: This API causes the SwapChain of a SwapGroup client to join or leave the specified SwapGroup.
//!
//! \param [in]   pDevice            The caller provides the D3D device that owns the SwapChain used as a SwapGroup client.
//!                                  pDevice can be either ID3D10Device or ID3D10Device1 or ID3D11Device.
//! \param [in]   pSwapChain         The IDXGISwapChain interface that is used as the SwapGroup client.
//! \param [in]   group              The caller specifies the SwapGroup which the SwapChain should join.
//!                                      - If the value of group is zero, the SwapChain leaves the SwapGroup.
//!                                      - The SwapChain joins a SwapGroup if the SwapGroup number is a positive integer less than or
//!                                        equal to the maximum number of SwapGroups queried by NvAPI_SwapGroup_QueryMaxSwapGroup.
//! \param [in]   blocking           The caller specifies that a presentation of this SwapChain should return immediately or block
//!                                  until all members of the SwapGroup are ready and the presentation was actually executed.
//!                                  A boolean value of false means the Present operation returns immediately and a value of true
//!                                  means the Present operation is blocking.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                   the SwapChain joined/left the SwapGroup accordingly
//! \retval ::NVAPI_ERROR                The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT     One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D1x_JoinSwapGroup(IUnknown *pDevice, 
                                          IDXGISwapChain  *pSwapChain, 
                                          NvU32 group,
                                          BOOL blocking);
#endif //if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)

#if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D1x_BindSwapBarrier
//
//!   DESCRIPTION: This API causes a SwapGroup to be bound to or released from the specified SwapBarrier.
//!
//! \param [in]   pDevice            The caller provides the D3D device that owns the SwapChain used as a SwapGroup client.
//!                                  pDevice can be either ID3D10Device or ID3D10Device1 or ID3D11Device.
//! \param [in]   group              The caller specifies the SwapGroup to be bound to the SwapBarrier.
//! \param [in]   barrier            The caller specifies the SwapBarrier that the SwapGroup should be bound to.
//!                                      - If the value of barrier is zero, the SwapGroup releases the SwapBarrier.
//!                                      - The SwapGroup will be bound to the SwapBarrier if the value of barrier is a positive 
//!                                        integer less than or equal to the maximum number of SwapBarriers queried by NvAPI_D3D1x_QueryMaxSwapGroup.
//  SUPPORTED OS: Windows Vista and higher
//!
//! \retval ::NVAPI_OK                  the SwapGroup is bound to the specified SwapBarrier
//! \retval ::NVAPI_ERROR                The operation failed.
//! \retval ::NVAPI_INVALID_ARGUMENT     One or more args passed in are invalid.
//! \retval ::NVAPI_API_NOT_INITIALIZED  NvAPI was not yet initialized.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D1x_BindSwapBarrier(IUnknown *pDevice, 
                                            NvU32 group, 
                                            NvU32 barrier); 
#endif //if defined(__d3d10_h__) || defined(__d3d10_1_h__) || defined(__d3d11_h__)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_SYS_VenturaGetState
//
//! \fn NvAPI_SYS_VenturaGetState(NVAPI_VENTURA_STATE *state)
//!
//!  DESCRIPTION:   This API queries the current Ventura state.
//!                  If the call succeeds, the variable state holds one of the following
//!                  values:
//!                  - NVAPI_VENTURA_STATE_UNSUPPORTED - when executed on 
//!                  Ventura non-capable system
//!                  - NVAPI_VENTURA_STATE_DISABLED - Ventura control is not
//!                  active (but system is Ventura capable)
//!                  - NVAPI_VENTURA_STATE_ENABLED - Ventura is actively
//!                  managing power consumption to stay within defined budget
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since 187.02
//!
//! \param [out]   state    The current Ventura state
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_POINTER   NULL argument passed
//! \retval ::NVAPI_INVALID_ARGUMENT  Incorrect param value
//! \retval ::NVAPI_NOT_SUPPORTED 
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//!
///////////////////////////////////////////////////////////////////////////////

//! \ingroup sysgeneral
//! Used in NvAPI_SYS_VenturaSetState() and NvAPI_SYS_VenturaGetState().
typedef enum _NVAPI_VENTURA_STATE
{
    NVAPI_VENTURA_STATE_UNSUPPORTED,
    NVAPI_VENTURA_STATE_DISABLED,    //!< Deactivate Ventura 
    NVAPI_VENTURA_STATE_ENABLED      //!< Activate Ventura

} NVAPI_VENTURA_STATE;

//! \ingroup sysgeneral
NVAPI_INTERFACE NvAPI_SYS_VenturaGetState(NVAPI_VENTURA_STATE *state);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_SYS_VenturaSetState
//
//! DESCRIPTION:     This API controls the Ventura state.
//!                  See ::NVAPI_VENTURA_STATE for valid state values. 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 187.02
//!
//! \param [in]    state    The new Ventura state
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR
//! \retval ::NVAPI_INVALID_ARGUMENT 
//! \retval ::NVAPI_NOT_SUPPORTED 
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//!
//! \ingroup sysgeneral
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SYS_VenturaSetState(NVAPI_VENTURA_STATE state);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_SYS_VenturaGetCoolingBudget
//
//! DESCRIPTION:     This API retrieves the cooling budget that is
//!                  currently being used by Ventura.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 187.02
//!
//! \param [out]     budget   The current cooling budget (in mW)
//!
//! \retval ::NVAPI_OK 
//! \retval ::NVAPI_ERROR 
//! \retval ::NVAPI_INVALID_POINTER 
//! \retval ::NVAPI_INVALID_ARGUMENT 
//! \retval ::NVAPI_NOT_SUPPORTED 
//! \retval ::NVAPI_API_NOT_INTIALIZED 
//!
//! \ingroup sysgeneral
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SYS_VenturaGetCoolingBudget(NvU32 *budget);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_SYS_VenturaSetCoolingBudget
//
//! DESCRIPTION:     This API call sets the new cooling budget
//!                  that will be used by Ventura.
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \since Version 187.02
//!
//! \param [in]      budget    The new cooling budget (in mW)
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_ERROR - miscellaneous error occurred
//! \retval ::NVAPI_INVALID_ARGUMENT - incorrect param value
//! \retval ::NVAPI_NOT_SUPPORTED - call is not supported
//! \retval ::NVAPI_API_NOT_INTIALIZED - NvAPI not initialized
//!
//! \ingroup sysgeneral
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_SYS_VenturaSetCoolingBudget(NvU32 budget);

//! \ingroup sysgeneral
//! @{
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:   NvAPI_SYS_VenturaGetPowerReading
//
//! \fn NvAPI_SYS_VenturaGetPowerReading(NVAPI_VENTURA_DEVICE device, NvU32 *power)
//!
//! \param [in]     device          targeted device
//! \param [out]    power           latest power reading [mW]
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! DESCRIPTION:     This API call is used to query for latest power reading.
//!                  'Device' describes desired target device .
//!                  If call succeeds, variable 'power' holds device's latest
//!                  power reading in [mW] (1/1000 of Watt).
//!
//!                  Power measurement for device 'system' can be greater than
//!                  sum of power measurements for devices 'cpu_0' and 'gpu_0'
//!                  since additional devices can be introduced in the future.
//!
//! \return 
//!    ::NVAPI_OK,  
//!    ::NVAPI_ERROR, 
//!    ::NVAPI_INVALID_POINTER, 
//!    ::NVAPI_INVALID_ARGUMENT, 
//!    ::NVAPI_NOT_SUPPORTED, 
//!    ::NVAPI_API_NOT_INTIALIZED, 
//
///////////////////////////////////////////////////////////////////////////////

//! See NvAPI_SYS_VenturaGetPowerReading().
typedef enum _NVAPI_VENTURA_DEVICE
{
    NVAPI_VENTURA_DEVICE_SYSTEM,
    NVAPI_VENTURA_DEVICE_CPU_0,
    NVAPI_VENTURA_DEVICE_GPU_0

} NVAPI_VENTURA_DEVICE;


NVAPI_INTERFACE NvAPI_SYS_VenturaGetPowerReading(NVAPI_VENTURA_DEVICE device, NvU32 *power);

//! @}


//! \ingroup dispcontrol
typedef struct
{
    //! numerator / denominator gives the refresh rate in Hz
    NvU32   numerator;
    NvU32   denominator;

} NV_DISPLAY_REFRESH_RATE;






//! \ingroup dispcontrol
//! @{

typedef struct _NV_DISPLAY_BLANKING_INFO_V1 
{ 
   NvU32 version;
   NvU32 blankingState                      : 1;  //!< 1 - Set    , 0 - Unset.
   NvU32 persistBlankingAcrossHotPlugUnplug : 1;  //!< 1 - Persist, 0 - Do Not persist.
   NvU32 reserved                           : 30;
}NV_DISPLAY_BLANKING_INFO_V1; 

typedef NV_DISPLAY_BLANKING_INFO_V1   NV_DISPLAY_BLANKING_INFO;

#define NV_DISPLAY_BLANKING_INFO_VER1 MAKE_NVAPI_VERSION(NV_DISPLAY_BLANKING_INFO_V1, 1) 
#define NV_DISPLAY_BLANKING_INFO_VER  NV_DISPLAY_BLANKING_INFO_VER1 

//! @}


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:  NvAPI_DISP_GetDisplayBlankingState 
//
//! DESCRIPTION:    This API returns the information about the display's blanking state. 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]     displayId              - NVIDIA Display selection.
//! \param [out]    pDisplayBlankingState  - Pointer to the structure containing the flags about the display's current blanking state.
//!
//! \retval ::NVAPI_OK                           - Completed request.
//! \retval ::NVAPI_ERROR                        - Miscellaneous error occurred.
//! \retval ::NVAPI_NOT_SUPPORTED                - Feature not supported on GPU. Will work on Quadro's only.
//! \retval ::NVAPI_ID_OUT_OF_RANGE              - Incorrect display ID.
//! \retval ::NVAPI_INVALID_POINTER              - Invalid pointer to NV_DISPLAY_BLANKING_INFO structure.
//! \retval ::NVAPI_NO_IMPLEMENTATION            - API not implemented. Will return this error in case of WinXP.    
//! \retval ::NVAPI_API_NOT_INTIALIZED           - NvAPI_Initialize() has not been called or was not successfull.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  - The struture version passed is invalid.
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_GetDisplayBlankingState(NvU32 displayId, NV_DISPLAY_BLANKING_INFO *pDisplayBlankingState); 



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME:  NvAPI_DISP_SetDisplayBlankingState 
//
//! DESCRIPTION:    This API sets the display's blanking state information provided by the user. 
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]     displayId               - NVIDIA Display selection.
//! \param [in]     pDisplayBlankingState   - Pointer to the structure containing the blanking flags which the user 
//!                                              wants to set on the display.
//!
//! \retval ::NVAPI_OK                           - Completed request.
//! \retval ::NVAPI_ERROR                        - Miscellaneous error occurred.
//! \retval ::NVAPI_ACCESS_DENIED                - Access denied to the current caller process of this API. 
//!                                                Until the process which has blanked the display doesn't unblank the display
//!                                                or exits, no other process can set the blanking state.
//! \retval ::NVAPI_NOT_SUPPORTED                - Feature not supported on GPU. Will work on Quadro's only.
//! \retval ::NVAPI_ID_OUT_OF_RANGE              - Incorrect display ID.
//! \retval ::NVAPI_INVALID_POINTER              - Invalid pointer to NV_DISPLAY_BLANKING_INFO structure.
//! \retval ::NVAPI_NO_IMPLEMENTATION            - API not implemented. Will return this error in case of WinXP.    
//! \retval ::NVAPI_API_NOT_INTIALIZED           - NvAPI_Initialize() has not been called or was not successfull.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION  - The struture version passed is invalid.
//!
//! \ingroup dispcontrol
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_SetDisplayBlankingState(NvU32 displayId, NV_DISPLAY_BLANKING_INFO * pDisplayBlankingState); 




//! \addtogroup drsapi
//! @{

// GPU Profile APIs

#define NVAPI_UNICODE_STRING_MAX                             2048
#define NVAPI_BINARY_DATA_MAX                                4096
#define NVAPI_SETTING_MAX_VALUES                             100

NV_DECLARE_HANDLE(NvDRSSessionHandle);
NV_DECLARE_HANDLE(NvDRSProfileHandle);

#define NVAPI_DRS_GLOBAL_PROFILE                             ((NvDRSProfileHandle) -1)

typedef NvU16 NvAPI_UnicodeString[NVAPI_UNICODE_STRING_MAX];

typedef enum _NVDRS_SETTING_TYPE
{
     NVDRS_DWORD_TYPE,
     NVDRS_BINARY_TYPE,
     NVDRS_STRING_TYPE,
     NVDRS_WSTRING_TYPE
} NVDRS_SETTING_TYPE;

typedef enum _NVDRS_SETTING_LOCATION
{
     NVDRS_CURRENT_PROFILE_LOCATION,
     NVDRS_GLOBAL_PROFILE_LOCATION,
     NVDRS_BASE_PROFILE_LOCATION
} NVDRS_SETTING_LOCATION;


typedef struct _NVDRS_GPU_SUPPORT
{
    NvU32 geforce    :  1;
    NvU32 quadro     :  1;
    NvU32 nvs        :  1;
    NvU32 reserved4  :  1;
    NvU32 reserved5  :  1;
    NvU32 reserved6  :  1;
    NvU32 reserved7  :  1;
    NvU32 reserved8  :  1;
    NvU32 reserved9  :  1;
    NvU32 reserved10 :  1;
    NvU32 reserved11 :  1;
    NvU32 reserved12 :  1;
    NvU32 reserved13 :  1;
    NvU32 reserved14 :  1;
    NvU32 reserved15 :  1;
    NvU32 reserved16 :  1;
    NvU32 reserved17 :  1;
    NvU32 reserved18 :  1;
    NvU32 reserved19 :  1;
    NvU32 reserved20 :  1;
    NvU32 reserved21 :  1;
    NvU32 reserved22 :  1;
    NvU32 reserved23 :  1;
    NvU32 reserved24 :  1;
    NvU32 reserved25 :  1;
    NvU32 reserved26 :  1;
    NvU32 reserved27 :  1;
    NvU32 reserved28 :  1;
    NvU32 reserved29 :  1;
    NvU32 reserved30 :  1;
    NvU32 reserved31 :  1;
    NvU32 reserved32 :  1;
} NVDRS_GPU_SUPPORT;

//! Enum to decide on the datatype of setting value.
typedef struct _NVDRS_BINARY_SETTING 
{
     NvU32                valueLength;               //!< valueLength should always be in number of bytes.
     NvU8                 valueData[NVAPI_BINARY_DATA_MAX];
} NVDRS_BINARY_SETTING;

typedef struct _NVDRS_SETTING_VALUES
{
     NvU32                      version;                //!< Structure Version
     NvU32                      numSettingValues;       //!< Total number of values available in a setting.
     NVDRS_SETTING_TYPE         settingType;            //!< Type of setting value.  
     union                                              //!< Setting can hold either DWORD or Binary value or string. Not mixed types.
     {
         NvU32                      u32DefaultValue;    //!< Accessing default DWORD value of this setting.
         NVDRS_BINARY_SETTING       binaryDefaultValue; //!< Accessing default Binary value of this setting.
                                                        //!< Must be allocated by caller with valueLength specifying buffer size, or only valueLength will be filled in.
         NvAPI_UnicodeString        wszDefaultValue;    //!< Accessing default unicode string value of this setting.
     };
     union											    //!< Setting values can be of either DWORD, Binary values or String type,
     {												    //!< NOT mixed types.
         NvU32                      u32Value;           //!< All possible DWORD values for a setting
         NVDRS_BINARY_SETTING       binaryValue;        //!< All possible Binary values for a setting
         NvAPI_UnicodeString        wszValue;           //!< Accessing current unicode string value of this setting.
     }settingValues[NVAPI_SETTING_MAX_VALUES];
} NVDRS_SETTING_VALUES;

//! Macro for constructing the version field of ::_NVDRS_SETTING_VALUES
#define NVDRS_SETTING_VALUES_VER    MAKE_NVAPI_VERSION(NVDRS_SETTING_VALUES,1)
     
typedef struct _NVDRS_SETTING
{
     NvU32                      version;                //!< Structure Version
     NvAPI_UnicodeString        settingName;            //!< String name of setting
     NvU32                      settingId;              //!< 32 bit setting Id
     NVDRS_SETTING_TYPE         settingType;            //!< Type of setting value.  
     NVDRS_SETTING_LOCATION     settingLocation;        //!< Describes where the value in CurrentValue comes from. 
     NvU32                      isCurrentPredefined;    //!< It is different than 0 if the currentValue is a predefined Value, 
                                                        //!< 0 if the currentValue is a user value. 
     NvU32                      isPredefinedValid;      //!< It is different than 0 if the PredefinedValue union contains a valid value. 
     union                                              //!< Setting can hold either DWORD or Binary value or string. Not mixed types.
     {
         NvU32                      u32PredefinedValue;    //!< Accessing default DWORD value of this setting.
         NVDRS_BINARY_SETTING       binaryPredefinedValue; //!< Accessing default Binary value of this setting.
                                                           //!< Must be allocated by caller with valueLength specifying buffer size, 
                                                           //!< or only valueLength will be filled in.
         NvAPI_UnicodeString        wszPredefinedValue;    //!< Accessing default unicode string value of this setting.
     };
     union                                              //!< Setting can hold either DWORD or Binary value or string. Not mixed types.
     {
         NvU32                      u32CurrentValue;    //!< Accessing current DWORD value of this setting.
         NVDRS_BINARY_SETTING       binaryCurrentValue; //!< Accessing current Binary value of this setting.
                                                        //!< Must be allocated by caller with valueLength specifying buffer size, 
                                                        //!< or only valueLength will be filled in.
         NvAPI_UnicodeString        wszCurrentValue;    //!< Accessing current unicode string value of this setting.
     };                                                 
} NVDRS_SETTING;

//! Macro for constructing the version field of ::_NVDRS_SETTING
#define NVDRS_SETTING_VER        MAKE_NVAPI_VERSION(NVDRS_SETTING,1)

typedef struct _NVDRS_APPLICATION_V1
{
     NvU32                      version;            //!< Structure Version
     NvU32                      isPredefined;       //!< Is the application userdefined/predefined
     NvAPI_UnicodeString        appName;            //!< String name of the Application
     NvAPI_UnicodeString        userFriendlyName;   //!< UserFriendly name of the Application
     NvAPI_UnicodeString        launcher;           //!< Indicates the name (if any) of the launcher that starts the application  
} NVDRS_APPLICATION_V1;

typedef struct _NVDRS_APPLICATION_V2
{
     NvU32                      version;            //!< Structure Version
     NvU32                      isPredefined;       //!< Is the application userdefined/predefined
     NvAPI_UnicodeString        appName;            //!< String name of the Application
     NvAPI_UnicodeString        userFriendlyName;   //!< UserFriendly name of the Application
     NvAPI_UnicodeString        launcher;           //!< Indicates the name (if any) of the launcher that starts the Application
     NvAPI_UnicodeString        fileInFolder;       //!< Select this application only if this file is found.
                                                    //!< When specifying multiple files, separate them using the ':' character.
} NVDRS_APPLICATION_V2;

#define NVDRS_APPLICATION_VER_V1        MAKE_NVAPI_VERSION(NVDRS_APPLICATION_V1,1)
#define NVDRS_APPLICATION_VER_V2        MAKE_NVAPI_VERSION(NVDRS_APPLICATION_V2,2)

typedef NVDRS_APPLICATION_V2 NVDRS_APPLICATION;
#define NVDRS_APPLICATION_VER NVDRS_APPLICATION_VER_V2

typedef struct _NVDRS_PROFILE
{
     NvU32                      version;            //!< Structure Version
     NvAPI_UnicodeString        profileName;        //!< String name of the Profile
     NVDRS_GPU_SUPPORT          gpuSupport;         //!< This read-only flag indicates the profile support on either
                                                    //!< Quadro, or Geforce, or both.
     NvU32                      isPredefined;       //!< Is the Profile user-defined, or predefined
     NvU32                      numOfApps;          //!< Total number of applications that belong to this profile. Read-only
     NvU32                      numOfSettings;      //!< Total number of settings applied for this Profile. Read-only
} NVDRS_PROFILE;

//! Macro for constructing the version field of ::_NVDRS_PROFILE
#define NVDRS_PROFILE_VER        MAKE_NVAPI_VERSION(NVDRS_PROFILE,1)


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_CreateSession
//
//!   DESCRIPTION: This API allocates memory and initializes the session.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [out]  *phSession Return pointer to the session handle.
//!                
//! \retval ::NVAPI_OK SUCCESS
//! \retval ::NVAPI_ERROR: For miscellaneous errors.
//
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_CreateSession(NvDRSSessionHandle *phSession);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_DestroySession
//
//!   DESCRIPTION: This API frees the allocation: cleanup of NvDrsSession.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in] hSession Input to the session handle.
//!                
//! \retval ::NVAPI_OK SUCCESS
//! \retval ::NVAPI_ERROR For miscellaneous errors.
//
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_DestroySession(NvDRSSessionHandle hSession);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_LoadSettings
//
//!   DESCRIPTION: This API loads and parses the settings data.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in] hSession  Input to the session handle.
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_LoadSettings(NvDRSSessionHandle hSession);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_SaveSettings
//
//!   DESCRIPTION: This API saves the settings data to the system.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in] hSession  Input to the session handle.
//!                
//! \retval ::NVAPI_OK    SUCCESS
//! \retval ::NVAPI_ERROR For miscellaneous errors.
//
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_SaveSettings(NvDRSSessionHandle hSession);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_LoadSettingsFromFile
//
//!   DESCRIPTION: This API loads settings from the given file path.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession Input to the session handle
//! \param [in]  fileName Binary File Name/Path
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_LoadSettingsFromFile(NvDRSSessionHandle hSession, NvAPI_UnicodeString fileName);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_SaveSettingsToFile
//
//!   DESCRIPTION: This API saves settings to the given file path.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession  Input to the session handle.
//! \param [in]  fileName  Binary File Name/Path
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_SaveSettingsToFile(NvDRSSessionHandle hSession, NvAPI_UnicodeString fileName);

//! @}



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_CreateProfile
//
//!   DESCRIPTION: This API creates an empty profile.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession        Input to the session handle.
//! \param [in]  *pProfileInfo   Input pointer to NVDRS_PROFILE.
//! \param [in]  *phProfile      Returns pointer to profile handle.
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_CreateProfile(NvDRSSessionHandle hSession, NVDRS_PROFILE *pProfileInfo, NvDRSProfileHandle *phProfile);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_DeleteProfile
//
//!   DESCRIPTION: This API deletes a profile or sets it back to a predefined value.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in] hSession  Input to the session handle.
//! \param [in] hProfile  Input profile handle.
//!                
//! \retval ::NVAPI_OK     SUCCESS if the profile is found
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_DeleteProfile(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_SetCurrentGlobalProfile
//
//!   DESCRIPTION: This API sets the current global profile in the driver.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in] hSession                Input to the session handle.
//! \param [in] wszGlobalProfileName    Input current Global profile name.
//!               
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_SetCurrentGlobalProfile(NvDRSSessionHandle hSession, NvAPI_UnicodeString wszGlobalProfileName);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_GetCurrentGlobalProfile
//
//!   DESCRIPTION: This API returns the handle to the current global profile.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   hSession     Input to the session handle.
//! \param [out]  *phProfile   Returns current Global profile handle.
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_GetCurrentGlobalProfile(NvDRSSessionHandle hSession, NvDRSProfileHandle *phProfile);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_GetProfileInfo
//
//!   DESCRIPTION: This API gets information about the given profile. User needs to specify the name of the Profile.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession       Input to the session handle.
//! \param [in]  hProfile       Input profile handle.
//! \param [out] *pProfileInfo  Return the profile info.
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_GetProfileInfo(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NVDRS_PROFILE *pProfileInfo);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_SetProfileInfo
//
//!   DESCRIPTION: Specifies flags for a given profile. Currently only the NVDRS_GPU_SUPPORT is
//!                used to update the profile. Neither the name, number of settings or applications
//!                or other profile information can be changed with this function. 
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession       Input to the session handle.
//! \param [in]  hProfile       Input profile handle.
//! \param [in]  *pProfileInfo  Input the new profile info.
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_SetProfileInfo(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NVDRS_PROFILE *pProfileInfo);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_FindProfileByName
//
//!   DESCRIPTION: This API finds a profile in the current session.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   hSession      Input to the session handle.
//! \param [in]   profileName   Input profileName.
//! \param [out]  phProfile     Input profile handle.
//!                
//! \retval ::NVAPI_OK                SUCCESS if the profile is found
//! \retval ::NVAPI_PROFILE_NOT_FOUND if profile is not found
//! \retval ::NVAPI_ERROR             For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_FindProfileByName(NvDRSSessionHandle hSession, NvAPI_UnicodeString profileName, NvDRSProfileHandle* phProfile);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_EnumProfiles
//
//!   DESCRIPTION: This API enumerates through all the profiles in the session.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   hSession        Input to the session handle.
//! \param [in]   index           Input the index for enumeration.
//! \param [out]  *phProfile      Returns profile handle.
//!                
//!   RETURN STATUS: NVAPI_OK: SUCCESS if the profile is found
//!                  NVAPI_ERROR: For miscellaneous errors.
//!                  NVAPI_END_ENUMERATION: index exceeds the total number of available Profiles in DB.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_EnumProfiles(NvDRSSessionHandle hSession, NvU32 index, NvDRSProfileHandle *phProfile);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_GetNumProfiles
//
//!   DESCRIPTION: This API obtains the number of profiles in the current session object.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession       Input to the session handle.
//! \param out]  *numProfiles   Returns count of profiles in the current hSession.
//!                
//! \retval ::NVAPI_OK                  SUCCESS
//! \retval ::NVAPI_API_NOT_INTIALIZED  Failed to initialize.
//! \retval ::NVAPI_INVALID_ARGUMENT    Invalid Arguments.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_GetNumProfiles(NvDRSSessionHandle hSession, NvU32 *numProfiles);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_CreateApplication
//
//!   DESCRIPTION: This API adds an executable name to a profile.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession       Input to the session handle.
//! \param [in]  hProfile       Input profile handle.
//! \param [in]  *pApplication  Input NVDRS_APPLICATION struct with the executable name to be added.
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_CreateApplication(NvDRSSessionHandle hSession, NvDRSProfileHandle  hProfile, NVDRS_APPLICATION *pApplication);
 

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_DeleteApplicationEx
//
//!   DESCRIPTION: This API removes an executable from a profile.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   hSession  - Input to the session handle.
//! \param [in]   hProfile  - Input profile handle.
//! \param [in]   *pApp     - Input all the information about the application to be removed.
//!
//! \retval ::NVAPI_OK  SUCCESS
//! \retval ::NVAPI_ERROR For miscellaneous errors.
//! \retval ::NVAPI_EXECUTABLE_PATH_IS_AMBIGUOUS If the path provided could refer to two different executables,
//!                                              this error will be returned.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_DeleteApplicationEx(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NVDRS_APPLICATION *pApp);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_DeleteApplication
//
//!   DESCRIPTION: This API removes an executable name from a profile.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSessionPARAMETERS   Input to the session handle.
//! \param [in]  hProfile             Input profile handle.
//! \param [in]  appName              Input the executable name to be removed.
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//! \retval ::NVAPI_EXECUTABLE_PATH_IS_AMBIGUOUS If the path provided could refer to two different executables,
//!                                              this error will be returned
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_DeleteApplication(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NvAPI_UnicodeString appName);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_GetApplicationInfo
//
//!   DESCRIPTION: This API gets information about the given application.  The input application name
//!                must match exactly what the Profile has stored for the application. 
//!                This function is better used to retrieve application information from a previous
//!                enumeration.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   hSession       Input to the session handle.
//! \param [in]   hProfile       Input profile handle.
//! \param [in]   appName        Input application name.
//! \param [out]  *pApplication  Returns NVDRS_APPLICATION struct with all the attributes.
//!                
//! \return  This API can return any of the error codes enumerated in #NvAPI_Status. 
//!          If there are return error codes with specific meaning for this API, 
//!          they are listed below.
//! \retval ::NVAPI_EXECUTABLE_PATH_IS_AMBIGUOUS   The application name could not 
//                                                single out only one executable.
//! \retval ::NVAPI_EXECUTABLE_NOT_FOUND           No application with that name is found on the profile.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_GetApplicationInfo(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NvAPI_UnicodeString appName, NVDRS_APPLICATION *pApplication);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_EnumApplications
//
//!   DESCRIPTION: This API enumerates all the applications in a given profile from the starting index to the maximum length.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]      hSession         Input to the session handle.
//! \param [in]      hProfile         Input profile handle.
//! \param [in]      startIndex       Indicates starting index for enumeration.
//! \param [in,out]  *appCount        Input maximum length of the passed in arrays. Returns the actual length.
//! \param [out]     *pApplication    Returns NVDRS_APPLICATION struct with all the attributes.
//!                
//! \retval ::NVAPI_OK               SUCCESS
//! \retval ::NVAPI_ERROR            For miscellaneous errors.
//! \retval ::NVAPI_END_ENUMERATION  startIndex exceeds the total appCount.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_EnumApplications(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NvU32 startIndex, NvU32 *appCount, NVDRS_APPLICATION *pApplication);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_FindApplicationByName
//
//!   DESCRIPTION: This API searches the application and the associated profile for the given application name.
//!                If a fully qualified path is provided, this function will always return the profile
//!                the driver will apply upon running the application (on the path provided).
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   hSession       Input to the hSession handle
//! \param [in]   appName        Input appName. For best results, provide a fully qualified path of the type
//!                                         c:\\Folder1\\Folder2\\App.exe
//! \param [out]  *phProfile     Returns profile handle.
//! \param [out]  *pApplication  Returns NVDRS_APPLICATION struct pointer.
//!                
//! \return  This API can return any of the error codes enumerated in #NvAPI_Status. 
//!                  If there are return error codes with specific meaning for this API, 
//!                  they are listed below:
//! \retval ::NVAPI_APPLICATION_NOT_FOUND          If App not found
//! \retval ::NVAPI_EXECUTABLE_PATH_IS_AMBIGUOUS   If the input appName was not fully qualified, this error might return in the case of multiple matches
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_FindApplicationByName(NvDRSSessionHandle hSession, NvAPI_UnicodeString appName, NvDRSProfileHandle *phProfile, NVDRS_APPLICATION *pApplication);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_SetSetting
//
//!   DESCRIPTION: This API adds/modifies a setting to a profile.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession     Input to the session handle.
//! \param [in]  hProfile     Input profile handle.
//! \param [in]   *pSetting   Input NVDRS_SETTING struct pointer.
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_SetSetting(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NVDRS_SETTING *pSetting);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_GetSetting
//
//!   DESCRIPTION: This API gets information about the given setting.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   hSession   Input to the session handle.
//! \param [in]   hProfile   Input profile handle.
//! \param [in]   settingId  Input settingId.
//! \param [out]  *pSetting  Returns all the setting info
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_GetSetting(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NvU32 settingId, NVDRS_SETTING *pSetting);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_EnumSettings
//
//!   DESCRIPTION: This API enumerates all the settings of a given profile from startIndex to the maximum length.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]      hSession        Input to the session handle.
//! \param [in]      hProfile        Input profile handle.
//! \param [in]      startIndex      Indicates starting index for enumeration.
//! \param [in,out]  *settingsCount  Input max length of the passed in arrays, Returns the actual length.
//! \param [out]     *pSetting       Returns all the settings info.
//!                
//! \retval ::NVAPI_OK              SUCCESS
//! \retval ::NVAPI_ERROR           For miscellaneous errors.
//! \retval ::NVAPI_END_ENUMERATION startIndex exceeds the total appCount.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_EnumSettings(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NvU32 startIndex, NvU32 *settingsCount, NVDRS_SETTING *pSetting);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_EnumAvaliableSettingIds
//
//!   DESCRIPTION: This API enumerates all the Ids of all the settings recognized by NVAPI.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [out]    pSettingIds     User-provided array of length *pMaxCount that NVAPI will fill with IDs.
//! \param [in,out] pMaxCount       Input max length of the passed in array, Returns the actual length.
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!                  NVAPI_END_ENUMERATION: the provided pMaxCount is not enough to hold all settingIds.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_EnumAvailableSettingIds(NvU32 *pSettingIds, NvU32 *pMaxCount);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_EnumAvailableSettingValues
//
//!   DESCRIPTION: This API enumerates all available setting values for a given setting.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]      settingId          Input settingId.
//! \param [in,out]  maxNumCount        Input max length of the passed in arrays, Returns the actual length.
//! \param [out]     *pSettingValues    Returns all available setting values and its count.
//!                
//! \retval ::NVAPI_OK     SUCCESS
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_EnumAvailableSettingValues(NvU32 settingId, NvU32 *pMaxNumValues, NVDRS_SETTING_VALUES *pSettingValues);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_GetSettingIdFromName
//
//!   DESCRIPTION: This API gets the binary ID of a setting given the setting name.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   settingName  Input Unicode settingName.
//! \param [out]  *pSettingId  Returns corresponding settingId.
//!                
//! \retval ::NVAPI_OK                 SUCCESS if the profile is found
//! \retval ::NVAPI_PROFILE_NOT_FOUND  if profile is not found
//! \retval ::NVAPI_SETTING_NOT_FOUND  if setting is not found
//! \retval ::NVAPI_ERROR              For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_GetSettingIdFromName(NvAPI_UnicodeString settingName, NvU32 *pSettingId);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_GetSettingNameFromId
//
//!   DESCRIPTION: This API gets the setting name given the binary ID.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  settingId        Input settingId.
//! \param [in]  *pSettingName    Returns corresponding Unicode settingName.
//!                
//! \retval ::NVAPI_OK                 SUCCESS if the profile is found
//! \retval ::NVAPI_PROFILE_NOT_FOUND  if profile is not found
//! \retval ::NVAPI_SETTING_NOT_FOUND  if setting is not found
//! \retval ::NVAPI_ERROR              For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_GetSettingNameFromId(NvU32 settingId, NvAPI_UnicodeString *pSettingName);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_DeleteProfileSetting
//
//!   DESCRIPTION: This API deletes a setting or sets it back to predefined value.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession            Input to the session handle.
//! \param [in]  hProfile            Input profile handle.
//! \param [in]  settingId           Input settingId to be deleted.
//!                
//! \retval ::NVAPI_OK     SUCCESS if the profile is found
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
/////////////////////////////////////////////////////////////////////////////// 
NVAPI_INTERFACE NvAPI_DRS_DeleteProfileSetting(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NvU32 settingId);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_RestoreAllDefaults
//
//!   DESCRIPTION: This API restores the whole system to predefined(default) values.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession  Input to the session handle.
//!                
//! \retval ::NVAPI_OK     SUCCESS if the profile is found
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
/////////////////////////////////////////////////////////////////////////////// 
NVAPI_INTERFACE NvAPI_DRS_RestoreAllDefaults(NvDRSSessionHandle hSession);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_RestoreProfileDefaults
//
//!   DESCRIPTION: This API restores the given profile to predefined(default) values.
//!                Any and all user specified modifications will be removed. 
//!                If the whole profile was set by the user, the profile will be removed.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession  Input to the session handle.
//! \param [in]  hProfile  Input profile handle.
//!                
//! \retval ::NVAPI_OK              SUCCESS if the profile is found
//! \retval ::NVAPI_ERROR           For miscellaneous errors.
//! \retval ::NVAPI_PROFILE_REMOVED SUCCESS, and the hProfile is no longer valid.
//! \retval ::NVAPI_ERROR           For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_RestoreProfileDefault(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_RestoreProfileDefaultSetting
//
//!   DESCRIPTION: This API restores the given profile setting to predefined(default) values.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession  Input to the session handle.
//! \param [in]  hProfile  Input profile handle.
//! \param [in]  settingId Input settingId.
//!                
//! \retval ::NVAPI_OK     SUCCESS if the profile is found
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_RestoreProfileDefaultSetting(NvDRSSessionHandle hSession, NvDRSProfileHandle hProfile, NvU32 settingId);


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_DRS_GetBaseProfile
//
//!   DESCRIPTION: Returns the handle to the current global profile.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  hSession    Input to the session handle.
//! \param [in]  *phProfile   Returns Base profile handle.
//!                
//! \retval ::NVAPI_OK     SUCCESS if the profile is found
//! \retval ::NVAPI_ERROR  For miscellaneous errors.
//!
//! \ingroup drsapi
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DRS_GetBaseProfile(NvDRSSessionHandle hSession, NvDRSProfileHandle *phProfile);




//! \ingroup gpu
//! @{

//! Enum for Event IDs
typedef enum
{
    NV_EVENT_TYPE_NONE = 0,
    NV_EVENT_TYPE_FAN_SPEED_CHANGE = 1,
    NV_EVENT_TYPE_THERMAL_CHANGE = 2,
} NV_EVENT_TYPE;

typedef enum
{
    UNKNOWN_LEVEL  = 0,
    NORMAL_LEVEL   = 1,
    WARNING_LEVEL  = 2, 
    CRITICAL_LEVEL = 3,
} NV_EVENT_LEVEL;

//! Callback for thermal
typedef void (__cdecl *NVAPI_CALLBACK_THERMALEVENT)(NvPhysicalGpuHandle gpuHandle, NV_EVENT_LEVEL thermalLevel, void *callbackParam);

//! Callback for fan speed
typedef void (__cdecl *NVAPI_CALLBACK_FANSPEEDEVENT)(NvPhysicalGpuHandle gpuHandle, NV_EVENT_LEVEL fanSpeedLevel, void *callbackParam);

//! Core NV_EVENT_REGISTER_CALLBACK structure declaration
typedef struct
{
    NvU32                 version;          //!< version field to ensure minimum version compatibility
    NV_EVENT_TYPE         eventId;          //!< ID of the event being sent
    void                  *callbackParam;   //!< This value will be passed back to the callback function when an event occurs
    union
    {
        NVAPI_CALLBACK_THERMALEVENT  nvThermalCallback;   //!< Callback function pointer for thermal                               
        NVAPI_CALLBACK_FANSPEEDEVENT nvFanSpeedCallback;  //!< Callback function pointer for fanSpeed
        
    }nvCallBackFunc;
    
} NV_EVENT_REGISTER_CALLBACK, *PNV_EVENT_REGISTER_CALLBACK;

//! Macro for constructing the version field of ::NV_EVENT_REGISTER_CALLBACK
#define NV_EVENT_REGISTER_CALLBACK_VERSION        MAKE_NVAPI_VERSION(NV_EVENT_REGISTER_CALLBACK,1);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Event_RegisterCallback
//
//! DESCRIPTION:   This API registers the process for events. This API should be called for each eventcallback.
//!                The handle returned to the client will be common across all eventCallbacks.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]  eventCallback  Pointer to NV_EVENT_REGISTER_CALLBACK structure to call
//!                             on new events
//! \param [out] phClient       Handle to client for use with 
//!                             unregister function
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_API_NOT_INTIALIZED - NvAPI not initialized
//! \retval ::NVAPI_INVALID_ARGUMENT - Invalid argument
//! \retval ::NVAPI_ERROR - miscellaneous error occurred
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Event_RegisterCallback(PNV_EVENT_REGISTER_CALLBACK eventCallback,
                                             NvEventHandle* phClient);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_Event_UnregisterCallback
//
//! DESCRIPTION:   This API unregister an event handle. 
//!                This API should be called only once per process(irrespective of the number of callbacks registered).
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]    hClient  Handle associated with this listeners
//!                         event queue. Same as returned from
//!                         NvAPI_Event_RegisterCallback().
//!
//! \retval ::NVAPI_OK - completed request
//! \retval ::NVAPI_API_NOT_INTIALIZED - NvAPI not initialized
//! \retval ::NVAPI_INVALID_ARGUMENT - Invalid argument
//! \retval ::NVAPI_ERROR - miscellaneous error occurred
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_Event_UnregisterCallback(NvEventHandle hClient);



/////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetCurrentThermalLevel
//
//
//! DESCRIPTION:   This API returns the current Level (Normal, Medium or 
//!                Critical) of the thermal sensor.
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]    nvGPUHandle       Physical GPU handle.
//! \param [out]   pThermalLevel     Returns Thermal Level. 
//!
//! \retval ::NVAPI_OK                                 - Success
//! \retval ::NVAPI_API_NOT_INTIALIZED                 - NvAPI not initialized
//! \retval ::NVAPI_INVALID_ARGUMENT                   - Invalid argument
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE       - Invalid GPU handle
//! \retval ::NVAPI_NOT_SUPPORTED                      - API not supported
//! \retval ::NVAPI_ERROR                              - miscellaneous error occurred
//!
//! \ingroup gputhermal
/////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetCurrentThermalLevel(NvPhysicalGpuHandle nvGPUHandle, NV_EVENT_LEVEL *pThermalLevel);


///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME: NvAPI_GPU_GetCurrentFanSpeedLevel
//
//! DESCRIPTION:   This API returns the current fan speed Level (Normal, Medium or 
//!                Critical).
//!
//  SUPPORTED OS: Windows XP and higher
//!
//! \param [in]   nvGPUHandle     Physical GPU handle.
//! \param [out]  pFanSpeedLevel  Returns fan speed Level. 
//!
//! \retval ::NVAPI_OK                                 Success
//! \retval ::NVAPI_API_NOT_INTIALIZED                 NvAPI not initialized
//! \retval ::NVAPI_INVALID_ARGUMENT                   Invalid argument
//! \retval ::NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE       Invalid GPU handle
//! \retval ::NVAPI_NOT_SUPPORTED                      API not supported
//! \retval ::NVAPI_ERROR                              Miscellaneous error occurred
//!
//! \ingroup gpucooler
/////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetCurrentFanSpeedLevel(NvPhysicalGpuHandle nvGPUHandle, NV_EVENT_LEVEL *pFanSpeedLevel);



///////////////////////////////////////////////////////////////////////////////
// Heterogeneous Clone related APIs.
///////////////////////////////////////////////////////////////////////////////



//! \ingroup hcloneapi
typedef struct
{
    NvU32   width;
    NvU32   height;
    NV_FORMAT colorFormat;
    NV_DISPLAY_REFRESH_RATE   refreshRate;
    NvU32   reserved; //!< Must be initialized to zero.
} NV_DISPLAY_SETTING;

//! \ingroup hcloneapi
typedef struct
{
    NvU32       version;
    NvU32       isNonNVIDIA :1; //!< True for non-NVIDIA GPU and False for NVIDIA GPU. We assume there is only one non-NVIDIA iGPU in the system.
    NvU32       isAttachedToDesktop :1;//!< True for path attached to desktop (currently path index 0 and until primary path is different from attached one).
    NvU32       reserved :30;
    NvU32       sourceId;  //!< For SET call: 
                          //!< IN: For the main adapter which is the primary of this HClone node that is attached and visible to the desktop,
                          //!< pass in the sourceId as seen by the OS.
                          //!< N/A: For the paths not visible to the OS, Driver will internally pick the sourceId. Note that this sourceId can
                          //!< dynamically be changed by Driver at runtime such as when MSPanel extends a monitor on the main adapter.
                          //!< For the GET call:
                          //!< OUT: Driver will return the sourceId for all the paths involved in this Hclone Node. The main adapter's 
                          //!< sourceId, is guaranteed to remain the same as passed in at the SET time but the value might have changed for
                          //!< the other paths
    union {
        NvU32       targetId; //!< same as in SDC() and QDC() for non NVIDIA display. This will be used when isNonNVIDIA is 1.
        NvU32       displayId; //!, NVIDIA display ID only for NVIDIA displays. This will be used when isNonNVIDIA is 0.
    };
    NV_DISPLAY_SETTING   dispSetting;
    NvU32      reserved1; //!< Must be initialized to zero.
} NV_HCLONE_PATH_V1;


//! \ingroup hcloneapi
typedef NV_HCLONE_PATH_V1    NV_HCLONE_PATH;

//! \ingroup hcloneapi
#define NV_HCLONE_PATH_VER1  MAKE_NVAPI_VERSION(NV_HCLONE_PATH_V1,1)

//! \ingroup hcloneapi
#define NV_HCLONE_PATH_VER   NV_HCLONE_PATH_VER1

//! \ingroup hcloneapi
typedef struct 
{
    NvU32 version;
    NvU32 numPaths; //!< Number of paths in this node.
    NV_HCLONE_PATH *pHClonePathArray;//!< index 0 is primary (of highest priority)
    NvU32  reserved1; //!< Must be initialized to zero.
} NV_HCLONE_NODE_V1;

//! \ingroup hcloneapi
typedef NV_HCLONE_NODE_V1    NV_HCLONE_NODE;

//! \ingroup hcloneapi
#define NV_HCLONE_NODE_VER1  MAKE_NVAPI_VERSION(NV_HCLONE_NODE_V1,1)

//! \ingroup hcloneapi
#define NV_HCLONE_NODE_VER   NV_HCLONE_NODE_VER1

//! \ingroup hcloneapi
typedef enum NV_HCLONE_HOTPLUG_BEHAVIOR
{
    NV_HCLONE_HOTPLUG_BEHAVIOR_CCD=0,   //!< Default behavior, using CCD rules for hotplug behavior
    NV_HCLONE_HOTPLUG_BEHAVIOR_EXTENDED,//!< Override Hotplug for the 1st display - will ignore persistence and go to extended mode
    NV_HCLONE_HOTPLUG_BEHAVIOR_UI,      //!< Override Hotplug for the 1st display - will invoke the Hotplug Dialog interraction
                                        //!< (note, also depends on 
                                        //!< the additional setting persisted within the dialog)
} NV_HCLONE_HOTPLUG_BEHAVIOR;

//! \ingroup hcloneapi
typedef struct 
{
    NvU32 version;
    NvU32 numHCloneNodes;
    NV_HCLONE_NODE *pHCloneNodeArray;
    NvU32 isMultiHClonePairsEnabled:1; //!< True: allow more than 1 hclone pairs simultaneously. 
                                       //!< False: Only a single pair is allowed with integrated adapter as primary display.
    NvU32 isNWayHCloneNodesEnabled:1;  //!< True: 3-way and 4-way nodes are enabled. False: Only 2-way hclone nodes are enabled.
    NvU32 reserved1:30;                //!< Must be initialized to zero.
    NV_HCLONE_HOTPLUG_BEHAVIOR HCloneHotPlugBehavior;      //!< Different flavors of behaviors on hotplug.
} NV_HCLONE_TOPOLOGY_V1;



//! \ingroup hcloneapi
typedef NV_HCLONE_TOPOLOGY_V1    NV_HCLONE_TOPOLOGY;

//! \ingroup hcloneapi
#define NV_HCLONE_TOPOLOGY_VER1  MAKE_NVAPI_VERSION(NV_HCLONE_TOPOLOGY_V1,1)

//! \ingroup hcloneapi
#define NV_HCLONE_TOPOLOGY_VER   NV_HCLONE_TOPOLOGY_VER1


/////////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME: NvAPI_DISP_SetHCloneTopology   
//!   DESCRIPTION: This API applies the Heterogeneous clone over displays given in pHCloneTopology.  
//!                Caller should first set the topology over all primary display using OS-API and then call this NVAPI.
//!  
//  SUPPORTED OS: Windows Vista and higher
//! \param [in] pHCloneTopology    Heterogeneous clone topology information              
//!
//! \retval ::NVAPI_INVALID_ARGUMENT: invalid arguments.
//! \retval ::NVAPI_OK: Display topology successfully applied.
//! \retval ::NVAPI_NOT_SUPPORTED: This software feature is not supported on the system.
//! \retval ::NVAPI_OUT_OF_MEMORY: Could not allocate sufficient memory to complete the call
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION: NV_HCLONE_TOPOLOGY/NV_HCLONE_NODE structure version mismatch. see pDispTopology->version.
//!
//! \ingroup hcloneapi
//////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_SetHCloneTopology(__in NV_HCLONE_TOPOLOGY *pHCloneTopology);




///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:  NvAPI_DISP_GetHCloneTopology
//
//! DESCRIPTION:   This API retrieves the current HClone topology information.
//!                Use the following steps to retrieve pHCloneTopology completely:
//!                -# Call this function with pHCloneTopology->pHCloneNodeArray set to NULL, to get the total number nodes in the HClone.
//!                -# Allocate memory to pHCloneTopology->pHCloneNodeArray of size sizeof(NV_HCLONE_NODE)*pHCloneTopology->numHCloneNodes.
//!                -# Assign NULL to all pHCloneTopology->pHCloneNodeArray[count].pHClonePathArray in a loop and call this function
//!                   to get all the pHCloneTopology->pHCloneNodeArray[count].numPaths.
//!                -# In loop allocate memory to pHCloneTopology->pHCloneNodeArray[code].pHClonePathArray
//!                   of size sizeof(NV_HCLONE_PATH)*pHCloneTopology->pHCloneNodeArray[count].numPaths.
//!                -# Call this function to get entire topology.
//!
//!                In step 5, if HClone is not completed, return value will be NVAPI_DEVICE_BUSY. \p
//!                In step 1 and step 3, even if HClone is not completed you will get return value as ::NVAPI_OK.
//!                
//  SUPPORTED OS: Windows Vista and higher
//! 
//! \param [out]    pHCloneTopology(gives current Heterogeneous clone topology information.
//!
//! \retval ::NVAPI_INVALID_ARGUMENT invalid arguments.
//! \retval ::NVAPI_OK  successfully returned.
//! \retval ::NVAPI_DEVICE_BUSY It means HClone is not completed yet and pHCloneTopology will contain topology that is being set.
//! \retval ::NVAPI_NOT_SUPPORTED This software feature is not supported on the system.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION NV_HCLONE_TOPOLOGY/NV_HCLONE_NODE structure version mismatch. See pHCloneTopology->version.
//!
//! \ingroup hcloneapi
//////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_GetHCloneTopology(__out NV_HCLONE_TOPOLOGY *pHCloneTopology);




///////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:  NvAPI_DISP_ValidateHCloneTopology
//
//! DESCRIPTION:   This API validates the HClone topology if that is supported/valid.It will validate only topology (Not the display setting)
//!                any NV_DISPLAY_SETTING in pHCloneTopology would be ignored
//!
//  SUPPORTED OS: Windows Vista and higher
//!
//! \param [in]   pHCloneTopology    Heterogenous clone topology information.
//! \param [out]  pValid             TRUE if valid/supported otherwise FALSE
//! 
//! \retval ::NVAPI_INVALID_ARGUMENT invalid arguments.
//! \retval ::NVAPI_OK  succesfully returned.
//! \retval ::NVAPI_NOT_SUPPORTED This software feature is not supported on the system.
//! \retval ::NVAPI_INCOMPATIBLE_STRUCT_VERSION NV_HCLONE_TOPOLOGY/NV_HCLONE_NODE structure version mismatch. see pHCloneTopology->version.
//! \ingroup hcloneapi
//////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_DISP_ValidateHCloneTopology(__in NV_HCLONE_TOPOLOGY *pHCloneTopology, __out NvU32 *pValid);



//! Used in NvAPI_GPU_GetPerfDecreaseInfo.
//! Bit masks for knowing the exact reason for performance decrease
typedef enum _NVAPI_GPU_PERF_DECREASE
{
    NV_GPU_PERF_DECREASE_NONE                        = 0,          //!< No Slowdown detected
    NV_GPU_PERF_DECREASE_REASON_THERMAL_PROTECTION   = 0x00000001, //!< Thermal slowdown/shutdown/POR thermal protection
    NV_GPU_PERF_DECREASE_REASON_POWER_CONTROL        = 0x00000002, //!< Power capping / pstate cap 
    NV_GPU_PERF_DECREASE_REASON_AC_BATT              = 0x00000004, //!< AC->BATT event
    NV_GPU_PERF_DECREASE_REASON_API_TRIGGERED        = 0x00000008, //!< API triggered slowdown
    NV_GPU_PERF_DECREASE_REASON_INSUFFICIENT_POWER   = 0x00000010, //!< Power connector missing
    NV_GPU_PERF_DECREASE_REASON_UNKNOWN              = 0x80000000, //!< Unknown reason
} NVAPI_GPU_PERF_DECREASE;


///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_GPU_GetPerfDecreaseInfo
//
//! DESCRIPTION:   This function retrieves - in NvU32 variable - reasons for the current performance decrease.
//!
//  SUPPORTED OS: Windows XP and higher
//! \param [in]	  hPhysicalGPU	(IN)	- GPU for which performance decrease is to be evaluated.
//! \param [out]  pPerfDecrInfo	(OUT)	- Pointer to a NvU32 variable containing performance decrease info
//!
//! \return      This API can return any of the error codes enumerated in #NvAPI_Status. 
//!
//! \ingroup gpu
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_GPU_GetPerfDecreaseInfo(__in NvPhysicalGpuHandle hPhysicalGpu, __inout NvU32 *pPerfDecrInfo);

//  SUPPORTED OS: Windows Vista and higher
//-----------------------------------------------------------------------------
// DirectX1x IFR API
//-----------------------------------------------------------------------------

#if defined (__cplusplus) && ( defined(__d3d10_h__) || defined(__d3d10_1_h__) ||defined(__d3d11_h__) ) 

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D1x_IFR_SetUpTargetBufferToSys
//
//!   DESCRIPTION: This API allocates n buffers (up to a maximum of 6). 
//!                Additional calls to NvAPI_D3D10_IFR_SetUpTargetBufferToSys() will free the buffers that were allocated previously with the same call on the d3d device. 
//!
//! \param [in]    pDev       The device to get primary surface on. pDevice can be either ID3D10Device or ID3D10Device1 or ID3D11Device.
//! \param [in]    eFormat    The format of the blit
//! \param [in]    dwNBuffers The number of buffers in ppBuffer (max 6).
//! \param [in]    ppBuffer   A pointer to an array of dwNBuffers (max 6) pointers. Virtual memory buffers will be allocated by the driver.
//! \param [in]    ppDiffmap  Reserved
//!
//! \return ::NVAPI_OK if the call succeeded
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D1x_IFR_SetUpTargetBufferToSys(IUnknown *pDevice, NVFBC_BUFFER_FORMAT eFormat, DWORD dwNBuffers, void** ppBuffers, void** ppDiffMaps);

#endif //defined(__cplusplus) && ( defined(__d3d10_h__) || defined(__d3d10_1_h__) ||defined(__d3d11_h__) )

//  SUPPORTED OS: Windows Vista and higher
#if defined (__cplusplus) && ( defined(__d3d10_h__) || defined(__d3d10_1_h__) ||defined(__d3d11_h__) ) 

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D1x_IFR_TransferRenderTarget
//
//!   DESCRIPTION: This API copies the current rendertarget into the provided system memory buffer.
//!
//! \param [in]   pDev                      The device to get primary surface on. pDevice can be either ID3D10Device or ID3D10Device1 or ID3D11Device.
//! \param [in]   pEvent                    When not NULL, will receive a handle to an even that the driver will signal upon completion of NvAPI_D3D10_IFR_TransferRenderTarget
//! \param [in]   dwBufferIndex             The index of the buffer that will receive a copy of the rendertarget. 
//!!                                        This ordinal is between 0 and the number of buffer created by NvAPI_D3D10_IFR_SetUpTargetBufferToSys.
//! \param [in]   dwTargetWidth             When dwTargetWidth and dwTargetHeight are not 0, a bilinear filtered scaling will be done before the blit to system memory.
//! \param [in]   dwTargetHeight            When dwTargetWidth and dwTargetHeight are not 0, a bilinear filtered scaling will be done before the blit to system memory.
//! \param [in]   dwRenderTargetIndex       The index of the rendertarget that will be copied.
//! \param [in]   dwRenderTargetArraySlice  The array slice we want copied
//!
//! \return ::NVAPI_OK if the call succeeded
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D1x_IFR_TransferRenderTarget(IUnknown *pDevice, HANDLE * pEvent, DWORD dwBufferIndex, 
                                                        DWORD dwTargetWidth, DWORD dwTargetHeight,
                                                        DWORD dwRenderTargetIndex, DWORD dwRenderTargetArraySlice);

#endif //defined(__cplusplus) && ( defined(__d3d10_h__) || defined(__d3d10_1_h__) ||defined(__d3d11_h__) )





#ifndef __NVAPI_EMPTY_SAL
#ifdef __nvapi_undef__ecount
    #undef __ecount
    #undef __nvapi_undef__ecount
#endif
#ifdef __nvapi_undef__bcount
    #undef __bcount
    #undef __nvapi_undef__bcount
#endif
#ifdef __nvapi_undef__in
    #undef __in
    #undef __nvapi_undef__in
#endif
#ifdef __nvapi_undef__in_ecount
    #undef __in_ecount
    #undef __nvapi_undef__in_ecount
#endif
#ifdef __nvapi_undef__in_bcount
    #undef __in_bcount
    #undef __nvapi_undef__in_bcount
#endif
#ifdef __nvapi_undef__in_z
    #undef __in_z
    #undef __nvapi_undef__in_z
#endif
#ifdef __nvapi_undef__in_ecount_z
    #undef __in_ecount_z
    #undef __nvapi_undef__in_ecount_z
#endif
#ifdef __nvapi_undef__in_bcount_z
    #undef __in_bcount_z
    #undef __nvapi_undef__in_bcount_z
#endif
#ifdef __nvapi_undef__in_nz
    #undef __in_nz
    #undef __nvapi_undef__in_nz
#endif
#ifdef __nvapi_undef__in_ecount_nz
    #undef __in_ecount_nz
    #undef __nvapi_undef__in_ecount_nz
#endif
#ifdef __nvapi_undef__in_bcount_nz
    #undef __in_bcount_nz
    #undef __nvapi_undef__in_bcount_nz
#endif
#ifdef __nvapi_undef__out
    #undef __out
    #undef __nvapi_undef__out
#endif
#ifdef __nvapi_undef__out_ecount
    #undef __out_ecount
    #undef __nvapi_undef__out_ecount
#endif
#ifdef __nvapi_undef__out_bcount
    #undef __out_bcount
    #undef __nvapi_undef__out_bcount
#endif
#ifdef __nvapi_undef__out_ecount_part
    #undef __out_ecount_part
    #undef __nvapi_undef__out_ecount_part
#endif
#ifdef __nvapi_undef__out_bcount_part
    #undef __out_bcount_part
    #undef __nvapi_undef__out_bcount_part
#endif
#ifdef __nvapi_undef__out_ecount_full
    #undef __out_ecount_full
    #undef __nvapi_undef__out_ecount_full
#endif
#ifdef __nvapi_undef__out_bcount_full
    #undef __out_bcount_full
    #undef __nvapi_undef__out_bcount_full
#endif
#ifdef __nvapi_undef__out_z
    #undef __out_z
    #undef __nvapi_undef__out_z
#endif
#ifdef __nvapi_undef__out_z_opt
    #undef __out_z_opt
    #undef __nvapi_undef__out_z_opt
#endif
#ifdef __nvapi_undef__out_ecount_z
    #undef __out_ecount_z
    #undef __nvapi_undef__out_ecount_z
#endif
#ifdef __nvapi_undef__out_bcount_z
    #undef __out_bcount_z
    #undef __nvapi_undef__out_bcount_z
#endif
#ifdef __nvapi_undef__out_ecount_part_z
    #undef __out_ecount_part_z
    #undef __nvapi_undef__out_ecount_part_z
#endif
#ifdef __nvapi_undef__out_bcount_part_z
    #undef __out_bcount_part_z
    #undef __nvapi_undef__out_bcount_part_z
#endif
#ifdef __nvapi_undef__out_ecount_full_z
    #undef __out_ecount_full_z
    #undef __nvapi_undef__out_ecount_full_z
#endif
#ifdef __nvapi_undef__out_bcount_full_z
    #undef __out_bcount_full_z
    #undef __nvapi_undef__out_bcount_full_z
#endif
#ifdef __nvapi_undef__out_nz
    #undef __out_nz
    #undef __nvapi_undef__out_nz
#endif
#ifdef __nvapi_undef__out_nz_opt
    #undef __out_nz_opt
    #undef __nvapi_undef__out_nz_opt
#endif
#ifdef __nvapi_undef__out_ecount_nz
    #undef __out_ecount_nz
    #undef __nvapi_undef__out_ecount_nz
#endif
#ifdef __nvapi_undef__out_bcount_nz
    #undef __out_bcount_nz
    #undef __nvapi_undef__out_bcount_nz
#endif
#ifdef __nvapi_undef__inout
    #undef __inout
    #undef __nvapi_undef__inout
#endif
#ifdef __nvapi_undef__inout_ecount
    #undef __inout_ecount
    #undef __nvapi_undef__inout_ecount
#endif
#ifdef __nvapi_undef__inout_bcount
    #undef __inout_bcount
    #undef __nvapi_undef__inout_bcount
#endif
#ifdef __nvapi_undef__inout_ecount_part
    #undef __inout_ecount_part
    #undef __nvapi_undef__inout_ecount_part
#endif
#ifdef __nvapi_undef__inout_bcount_part
    #undef __inout_bcount_part
    #undef __nvapi_undef__inout_bcount_part
#endif
#ifdef __nvapi_undef__inout_ecount_full
    #undef __inout_ecount_full
    #undef __nvapi_undef__inout_ecount_full
#endif
#ifdef __nvapi_undef__inout_bcount_full
    #undef __inout_bcount_full
    #undef __nvapi_undef__inout_bcount_full
#endif
#ifdef __nvapi_undef__inout_z
    #undef __inout_z
    #undef __nvapi_undef__inout_z
#endif
#ifdef __nvapi_undef__inout_ecount_z
    #undef __inout_ecount_z
    #undef __nvapi_undef__inout_ecount_z
#endif
#ifdef __nvapi_undef__inout_bcount_z
    #undef __inout_bcount_z
    #undef __nvapi_undef__inout_bcount_z
#endif
#ifdef __nvapi_undef__inout_nz
    #undef __inout_nz
    #undef __nvapi_undef__inout_nz
#endif
#ifdef __nvapi_undef__inout_ecount_nz
    #undef __inout_ecount_nz
    #undef __nvapi_undef__inout_ecount_nz
#endif
#ifdef __nvapi_undef__inout_bcount_nz
    #undef __inout_bcount_nz
    #undef __nvapi_undef__inout_bcount_nz
#endif
#ifdef __nvapi_undef__ecount_opt
    #undef __ecount_opt
    #undef __nvapi_undef__ecount_opt
#endif
#ifdef __nvapi_undef__bcount_opt
    #undef __bcount_opt
    #undef __nvapi_undef__bcount_opt
#endif
#ifdef __nvapi_undef__in_opt
    #undef __in_opt
    #undef __nvapi_undef__in_opt
#endif
#ifdef __nvapi_undef__in_ecount_opt
    #undef __in_ecount_opt
    #undef __nvapi_undef__in_ecount_opt
#endif
#ifdef __nvapi_undef__in_bcount_opt
    #undef __in_bcount_opt
    #undef __nvapi_undef__in_bcount_opt
#endif
#ifdef __nvapi_undef__in_z_opt
    #undef __in_z_opt
    #undef __nvapi_undef__in_z_opt
#endif
#ifdef __nvapi_undef__in_ecount_z_opt
    #undef __in_ecount_z_opt
    #undef __nvapi_undef__in_ecount_z_opt
#endif
#ifdef __nvapi_undef__in_bcount_z_opt
    #undef __in_bcount_z_opt
    #undef __nvapi_undef__in_bcount_z_opt
#endif
#ifdef __nvapi_undef__in_nz_opt
    #undef __in_nz_opt
    #undef __nvapi_undef__in_nz_opt
#endif
#ifdef __nvapi_undef__in_ecount_nz_opt
    #undef __in_ecount_nz_opt
    #undef __nvapi_undef__in_ecount_nz_opt
#endif
#ifdef __nvapi_undef__in_bcount_nz_opt
    #undef __in_bcount_nz_opt
    #undef __nvapi_undef__in_bcount_nz_opt
#endif
#ifdef __nvapi_undef__out_opt
    #undef __out_opt
    #undef __nvapi_undef__out_opt
#endif
#ifdef __nvapi_undef__out_ecount_opt
    #undef __out_ecount_opt
    #undef __nvapi_undef__out_ecount_opt
#endif
#ifdef __nvapi_undef__out_bcount_opt
    #undef __out_bcount_opt
    #undef __nvapi_undef__out_bcount_opt
#endif
#ifdef __nvapi_undef__out_ecount_part_opt
    #undef __out_ecount_part_opt
    #undef __nvapi_undef__out_ecount_part_opt
#endif
#ifdef __nvapi_undef__out_bcount_part_opt
    #undef __out_bcount_part_opt
    #undef __nvapi_undef__out_bcount_part_opt
#endif
#ifdef __nvapi_undef__out_ecount_full_opt
    #undef __out_ecount_full_opt
    #undef __nvapi_undef__out_ecount_full_opt
#endif
#ifdef __nvapi_undef__out_bcount_full_opt
    #undef __out_bcount_full_opt
    #undef __nvapi_undef__out_bcount_full_opt
#endif
#ifdef __nvapi_undef__out_ecount_z_opt
    #undef __out_ecount_z_opt
    #undef __nvapi_undef__out_ecount_z_opt
#endif
#ifdef __nvapi_undef__out_bcount_z_opt
    #undef __out_bcount_z_opt
    #undef __nvapi_undef__out_bcount_z_opt
#endif
#ifdef __nvapi_undef__out_ecount_part_z_opt
    #undef __out_ecount_part_z_opt
    #undef __nvapi_undef__out_ecount_part_z_opt
#endif
#ifdef __nvapi_undef__out_bcount_part_z_opt
    #undef __out_bcount_part_z_opt
    #undef __nvapi_undef__out_bcount_part_z_opt
#endif
#ifdef __nvapi_undef__out_ecount_full_z_opt
    #undef __out_ecount_full_z_opt
    #undef __nvapi_undef__out_ecount_full_z_opt
#endif
#ifdef __nvapi_undef__out_bcount_full_z_opt
    #undef __out_bcount_full_z_opt
    #undef __nvapi_undef__out_bcount_full_z_opt
#endif
#ifdef __nvapi_undef__out_ecount_nz_opt
    #undef __out_ecount_nz_opt
    #undef __nvapi_undef__out_ecount_nz_opt
#endif
#ifdef __nvapi_undef__out_bcount_nz_opt
    #undef __out_bcount_nz_opt
    #undef __nvapi_undef__out_bcount_nz_opt
#endif
#ifdef __nvapi_undef__inout_opt
    #undef __inout_opt
    #undef __nvapi_undef__inout_opt
#endif
#ifdef __nvapi_undef__inout_ecount_opt
    #undef __inout_ecount_opt
    #undef __nvapi_undef__inout_ecount_opt
#endif
#ifdef __nvapi_undef__inout_bcount_opt
    #undef __inout_bcount_opt
    #undef __nvapi_undef__inout_bcount_opt
#endif
#ifdef __nvapi_undef__inout_ecount_part_opt
    #undef __inout_ecount_part_opt
    #undef __nvapi_undef__inout_ecount_part_opt
#endif
#ifdef __nvapi_undef__inout_bcount_part_opt
    #undef __inout_bcount_part_opt
    #undef __nvapi_undef__inout_bcount_part_opt
#endif
#ifdef __nvapi_undef__inout_ecount_full_opt
    #undef __inout_ecount_full_opt
    #undef __nvapi_undef__inout_ecount_full_opt
#endif
#ifdef __nvapi_undef__inout_bcount_full_opt
    #undef __inout_bcount_full_opt
    #undef __nvapi_undef__inout_bcount_full_opt
#endif
#ifdef __nvapi_undef__inout_z_opt
    #undef __inout_z_opt
    #undef __nvapi_undef__inout_z_opt
#endif
#ifdef __nvapi_undef__inout_ecount_z_opt
    #undef __inout_ecount_z_opt
    #undef __nvapi_undef__inout_ecount_z_opt
#endif
#ifdef __nvapi_undef__inout_ecount_z_opt
    #undef __inout_ecount_z_opt
    #undef __nvapi_undef__inout_ecount_z_opt
#endif
#ifdef __nvapi_undef__inout_bcount_z_opt
    #undef __inout_bcount_z_opt
    #undef __nvapi_undef__inout_bcount_z_opt
#endif
#ifdef __nvapi_undef__inout_nz_opt
    #undef __inout_nz_opt
    #undef __nvapi_undef__inout_nz_opt
#endif
#ifdef __nvapi_undef__inout_ecount_nz_opt
    #undef __inout_ecount_nz_opt
    #undef __nvapi_undef__inout_ecount_nz_opt
#endif
#ifdef __nvapi_undef__inout_bcount_nz_opt
    #undef __inout_bcount_nz_opt
    #undef __nvapi_undef__inout_bcount_nz_opt
#endif
#ifdef __nvapi_undef__deref_ecount
    #undef __deref_ecount
    #undef __nvapi_undef__deref_ecount
#endif
#ifdef __nvapi_undef__deref_bcount
    #undef __deref_bcount
    #undef __nvapi_undef__deref_bcount
#endif
#ifdef __nvapi_undef__deref_out
    #undef __deref_out
    #undef __nvapi_undef__deref_out
#endif
#ifdef __nvapi_undef__deref_out_ecount
    #undef __deref_out_ecount
    #undef __nvapi_undef__deref_out_ecount
#endif
#ifdef __nvapi_undef__deref_out_bcount
    #undef __deref_out_bcount
    #undef __nvapi_undef__deref_out_bcount
#endif
#ifdef __nvapi_undef__deref_out_ecount_part
    #undef __deref_out_ecount_part
    #undef __nvapi_undef__deref_out_ecount_part
#endif
#ifdef __nvapi_undef__deref_out_bcount_part
    #undef __deref_out_bcount_part
    #undef __nvapi_undef__deref_out_bcount_part
#endif
#ifdef __nvapi_undef__deref_out_ecount_full
    #undef __deref_out_ecount_full
    #undef __nvapi_undef__deref_out_ecount_full
#endif
#ifdef __nvapi_undef__deref_out_bcount_full
    #undef __deref_out_bcount_full
    #undef __nvapi_undef__deref_out_bcount_full
#endif
#ifdef __nvapi_undef__deref_out_z
    #undef __deref_out_z
    #undef __nvapi_undef__deref_out_z
#endif
#ifdef __nvapi_undef__deref_out_ecount_z
    #undef __deref_out_ecount_z
    #undef __nvapi_undef__deref_out_ecount_z
#endif
#ifdef __nvapi_undef__deref_out_bcount_z
    #undef __deref_out_bcount_z
    #undef __nvapi_undef__deref_out_bcount_z
#endif
#ifdef __nvapi_undef__deref_out_nz
    #undef __deref_out_nz
    #undef __nvapi_undef__deref_out_nz
#endif
#ifdef __nvapi_undef__deref_out_ecount_nz
    #undef __deref_out_ecount_nz
    #undef __nvapi_undef__deref_out_ecount_nz
#endif
#ifdef __nvapi_undef__deref_out_bcount_nz
    #undef __deref_out_bcount_nz
    #undef __nvapi_undef__deref_out_bcount_nz
#endif
#ifdef __nvapi_undef__deref_inout
    #undef __deref_inout
    #undef __nvapi_undef__deref_inout
#endif
#ifdef __nvapi_undef__deref_inout_z
    #undef __deref_inout_z
    #undef __nvapi_undef__deref_inout_z
#endif
#ifdef __nvapi_undef__deref_inout_ecount
    #undef __deref_inout_ecount
    #undef __nvapi_undef__deref_inout_ecount
#endif
#ifdef __nvapi_undef__deref_inout_bcount
    #undef __deref_inout_bcount
    #undef __nvapi_undef__deref_inout_bcount
#endif
#ifdef __nvapi_undef__deref_inout_ecount_part
    #undef __deref_inout_ecount_part
    #undef __nvapi_undef__deref_inout_ecount_part
#endif
#ifdef __nvapi_undef__deref_inout_bcount_part
    #undef __deref_inout_bcount_part
    #undef __nvapi_undef__deref_inout_bcount_part
#endif
#ifdef __nvapi_undef__deref_inout_ecount_full
    #undef __deref_inout_ecount_full
    #undef __nvapi_undef__deref_inout_ecount_full
#endif
#ifdef __nvapi_undef__deref_inout_bcount_full
    #undef __deref_inout_bcount_full
    #undef __nvapi_undef__deref_inout_bcount_full
#endif
#ifdef __nvapi_undef__deref_inout_z
    #undef __deref_inout_z
    #undef __nvapi_undef__deref_inout_z
#endif
#ifdef __nvapi_undef__deref_inout_ecount_z
    #undef __deref_inout_ecount_z
    #undef __nvapi_undef__deref_inout_ecount_z
#endif
#ifdef __nvapi_undef__deref_inout_bcount_z
    #undef __deref_inout_bcount_z
    #undef __nvapi_undef__deref_inout_bcount_z
#endif
#ifdef __nvapi_undef__deref_inout_nz
    #undef __deref_inout_nz
    #undef __nvapi_undef__deref_inout_nz
#endif
#ifdef __nvapi_undef__deref_inout_ecount_nz
    #undef __deref_inout_ecount_nz
    #undef __nvapi_undef__deref_inout_ecount_nz
#endif
#ifdef __nvapi_undef__deref_inout_bcount_nz
    #undef __deref_inout_bcount_nz
    #undef __nvapi_undef__deref_inout_bcount_nz
#endif
#ifdef __nvapi_undef__deref_ecount_opt
    #undef __deref_ecount_opt
    #undef __nvapi_undef__deref_ecount_opt
#endif
#ifdef __nvapi_undef__deref_bcount_opt
    #undef __deref_bcount_opt
    #undef __nvapi_undef__deref_bcount_opt
#endif
#ifdef __nvapi_undef__deref_out_opt
    #undef __deref_out_opt
    #undef __nvapi_undef__deref_out_opt
#endif
#ifdef __nvapi_undef__deref_out_ecount_opt
    #undef __deref_out_ecount_opt
    #undef __nvapi_undef__deref_out_ecount_opt
#endif
#ifdef __nvapi_undef__deref_out_bcount_opt
    #undef __deref_out_bcount_opt
    #undef __nvapi_undef__deref_out_bcount_opt
#endif
#ifdef __nvapi_undef__deref_out_ecount_part_opt
    #undef __deref_out_ecount_part_opt
    #undef __nvapi_undef__deref_out_ecount_part_opt
#endif
#ifdef __nvapi_undef__deref_out_bcount_part_opt
    #undef __deref_out_bcount_part_opt
    #undef __nvapi_undef__deref_out_bcount_part_opt
#endif
#ifdef __nvapi_undef__deref_out_ecount_full_opt
    #undef __deref_out_ecount_full_opt
    #undef __nvapi_undef__deref_out_ecount_full_opt
#endif
#ifdef __nvapi_undef__deref_out_bcount_full_opt
    #undef __deref_out_bcount_full_opt
    #undef __nvapi_undef__deref_out_bcount_full_opt
#endif
#ifdef __nvapi_undef__deref_out_z_opt
    #undef __deref_out_z_opt
    #undef __nvapi_undef__deref_out_z_opt
#endif
#ifdef __nvapi_undef__deref_out_ecount_z_opt
    #undef __deref_out_ecount_z_opt
    #undef __nvapi_undef__deref_out_ecount_z_opt
#endif
#ifdef __nvapi_undef__deref_out_bcount_z_opt
    #undef __deref_out_bcount_z_opt
    #undef __nvapi_undef__deref_out_bcount_z_opt
#endif
#ifdef __nvapi_undef__deref_out_nz_opt
    #undef __deref_out_nz_opt
    #undef __nvapi_undef__deref_out_nz_opt
#endif
#ifdef __nvapi_undef__deref_out_ecount_nz_opt
    #undef __deref_out_ecount_nz_opt
    #undef __nvapi_undef__deref_out_ecount_nz_opt
#endif
#ifdef __nvapi_undef__deref_out_bcount_nz_opt
    #undef __deref_out_bcount_nz_opt
    #undef __nvapi_undef__deref_out_bcount_nz_opt
#endif
#ifdef __nvapi_undef__deref_inout_opt
    #undef __deref_inout_opt
    #undef __nvapi_undef__deref_inout_opt
#endif
#ifdef __nvapi_undef__deref_inout_ecount_opt
    #undef __deref_inout_ecount_opt
    #undef __nvapi_undef__deref_inout_ecount_opt
#endif
#ifdef __nvapi_undef__deref_inout_bcount_opt
    #undef __deref_inout_bcount_opt
    #undef __nvapi_undef__deref_inout_bcount_opt
#endif
#ifdef __nvapi_undef__deref_inout_ecount_part_opt
    #undef __deref_inout_ecount_part_opt
    #undef __nvapi_undef__deref_inout_ecount_part_opt
#endif
#ifdef __nvapi_undef__deref_inout_bcount_part_opt
    #undef __deref_inout_bcount_part_opt
    #undef __nvapi_undef__deref_inout_bcount_part_opt
#endif
#ifdef __nvapi_undef__deref_inout_ecount_full_opt
    #undef __deref_inout_ecount_full_opt
    #undef __nvapi_undef__deref_inout_ecount_full_opt
#endif
#ifdef __nvapi_undef__deref_inout_bcount_full_opt
    #undef __deref_inout_bcount_full_opt
    #undef __nvapi_undef__deref_inout_bcount_full_opt
#endif
#ifdef __nvapi_undef__deref_inout_z_opt
    #undef __deref_inout_z_opt
    #undef __nvapi_undef__deref_inout_z_opt
#endif
#ifdef __nvapi_undef__deref_inout_ecount_z_opt
    #undef __deref_inout_ecount_z_opt
    #undef __nvapi_undef__deref_inout_ecount_z_opt
#endif
#ifdef __nvapi_undef__deref_inout_bcount_z_opt
    #undef __deref_inout_bcount_z_opt
    #undef __nvapi_undef__deref_inout_bcount_z_opt
#endif
#ifdef __nvapi_undef__deref_inout_nz_opt
    #undef __deref_inout_nz_opt
    #undef __nvapi_undef__deref_inout_nz_opt
#endif
#ifdef __nvapi_undef__deref_inout_ecount_nz_opt
    #undef __deref_inout_ecount_nz_opt
    #undef __nvapi_undef__deref_inout_ecount_nz_opt
#endif
#ifdef __nvapi_undef__deref_inout_bcount_nz_opt
    #undef __deref_inout_bcount_nz_opt
    #undef __nvapi_undef__deref_inout_bcount_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_ecount
    #undef __deref_opt_ecount
    #undef __nvapi_undef__deref_opt_ecount
#endif
#ifdef __nvapi_undef__deref_opt_bcount
    #undef __deref_opt_bcount
    #undef __nvapi_undef__deref_opt_bcount
#endif
#ifdef __nvapi_undef__deref_opt_out
    #undef __deref_opt_out
    #undef __nvapi_undef__deref_opt_out
#endif
#ifdef __nvapi_undef__deref_opt_out_z
    #undef __deref_opt_out_z
    #undef __nvapi_undef__deref_opt_out_z
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount
    #undef __deref_opt_out_ecount
    #undef __nvapi_undef__deref_opt_out_ecount
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount
    #undef __deref_opt_out_bcount
    #undef __nvapi_undef__deref_opt_out_bcount
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_part
    #undef __deref_opt_out_ecount_part
    #undef __nvapi_undef__deref_opt_out_ecount_part
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_part
    #undef __deref_opt_out_bcount_part
    #undef __nvapi_undef__deref_opt_out_bcount_part
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_full
    #undef __deref_opt_out_ecount_full
    #undef __nvapi_undef__deref_opt_out_ecount_full
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_full
    #undef __deref_opt_out_bcount_full
    #undef __nvapi_undef__deref_opt_out_bcount_full
#endif
#ifdef __nvapi_undef__deref_opt_inout
    #undef __deref_opt_inout
    #undef __nvapi_undef__deref_opt_inout
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount
    #undef __deref_opt_inout_ecount
    #undef __nvapi_undef__deref_opt_inout_ecount
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount
    #undef __deref_opt_inout_bcount
    #undef __nvapi_undef__deref_opt_inout_bcount
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_part
    #undef __deref_opt_inout_ecount_part
    #undef __nvapi_undef__deref_opt_inout_ecount_part
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_part
    #undef __deref_opt_inout_bcount_part
    #undef __nvapi_undef__deref_opt_inout_bcount_part
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_full
    #undef __deref_opt_inout_ecount_full
    #undef __nvapi_undef__deref_opt_inout_ecount_full
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_full
    #undef __deref_opt_inout_bcount_full
    #undef __nvapi_undef__deref_opt_inout_bcount_full
#endif
#ifdef __nvapi_undef__deref_opt_inout_z
    #undef __deref_opt_inout_z
    #undef __nvapi_undef__deref_opt_inout_z
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_z
    #undef __deref_opt_inout_ecount_z
    #undef __nvapi_undef__deref_opt_inout_ecount_z
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_z
    #undef __deref_opt_inout_bcount_z
    #undef __nvapi_undef__deref_opt_inout_bcount_z
#endif
#ifdef __nvapi_undef__deref_opt_inout_nz
    #undef __deref_opt_inout_nz
    #undef __nvapi_undef__deref_opt_inout_nz
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_nz
    #undef __deref_opt_inout_ecount_nz
    #undef __nvapi_undef__deref_opt_inout_ecount_nz
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_nz
    #undef __deref_opt_inout_bcount_nz
    #undef __nvapi_undef__deref_opt_inout_bcount_nz
#endif
#ifdef __nvapi_undef__deref_opt_ecount_opt
    #undef __deref_opt_ecount_opt
    #undef __nvapi_undef__deref_opt_ecount_opt
#endif
#ifdef __nvapi_undef__deref_opt_bcount_opt
    #undef __deref_opt_bcount_opt
    #undef __nvapi_undef__deref_opt_bcount_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_opt
    #undef __deref_opt_out_opt
    #undef __nvapi_undef__deref_opt_out_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_opt
    #undef __deref_opt_out_ecount_opt
    #undef __nvapi_undef__deref_opt_out_ecount_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_opt
    #undef __deref_opt_out_bcount_opt
    #undef __nvapi_undef__deref_opt_out_bcount_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_part_opt
    #undef __deref_opt_out_ecount_part_opt
    #undef __nvapi_undef__deref_opt_out_ecount_part_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_part_opt
    #undef __deref_opt_out_bcount_part_opt
    #undef __nvapi_undef__deref_opt_out_bcount_part_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_full_opt
    #undef __deref_opt_out_ecount_full_opt
    #undef __nvapi_undef__deref_opt_out_ecount_full_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_full_opt
    #undef __deref_opt_out_bcount_full_opt
    #undef __nvapi_undef__deref_opt_out_bcount_full_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_z_opt
    #undef __deref_opt_out_z_opt
    #undef __nvapi_undef__deref_opt_out_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_z_opt
    #undef __deref_opt_out_ecount_z_opt
    #undef __nvapi_undef__deref_opt_out_ecount_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_z_opt
    #undef __deref_opt_out_bcount_z_opt
    #undef __nvapi_undef__deref_opt_out_bcount_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_nz_opt
    #undef __deref_opt_out_nz_opt
    #undef __nvapi_undef__deref_opt_out_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_nz_opt
    #undef __deref_opt_out_ecount_nz_opt
    #undef __nvapi_undef__deref_opt_out_ecount_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_nz_opt
    #undef __deref_opt_out_bcount_nz_opt
    #undef __nvapi_undef__deref_opt_out_bcount_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_opt
    #undef __deref_opt_inout_opt
    #undef __nvapi_undef__deref_opt_inout_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_opt
    #undef __deref_opt_inout_ecount_opt
    #undef __nvapi_undef__deref_opt_inout_ecount_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_opt
    #undef __deref_opt_inout_bcount_opt
    #undef __nvapi_undef__deref_opt_inout_bcount_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_part_opt
    #undef __deref_opt_inout_ecount_part_opt
    #undef __nvapi_undef__deref_opt_inout_ecount_part_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_part_opt
    #undef __deref_opt_inout_bcount_part_opt
    #undef __nvapi_undef__deref_opt_inout_bcount_part_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_full_opt
    #undef __deref_opt_inout_ecount_full_opt
    #undef __nvapi_undef__deref_opt_inout_ecount_full_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_full_opt
    #undef __deref_opt_inout_bcount_full_opt
    #undef __nvapi_undef__deref_opt_inout_bcount_full_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_z_opt
    #undef __deref_opt_inout_z_opt
    #undef __nvapi_undef__deref_opt_inout_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_z_opt
    #undef __deref_opt_inout_ecount_z_opt
    #undef __nvapi_undef__deref_opt_inout_ecount_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_z_opt
    #undef __deref_opt_inout_bcount_z_opt
    #undef __nvapi_undef__deref_opt_inout_bcount_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_nz_opt
    #undef __deref_opt_inout_nz_opt
    #undef __nvapi_undef__deref_opt_inout_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_nz_opt
    #undef __deref_opt_inout_ecount_nz_opt
    #undef __nvapi_undef__deref_opt_inout_ecount_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_nz_opt
    #undef __deref_opt_inout_bcount_nz_opt
    #undef __nvapi_undef__deref_opt_inout_bcount_nz_opt
#endif
#endif // __NVAPI_EMPTY_SAL


#ifdef __cplusplus
}; //extern "C" {

#endif

#pragma pack(pop)

#endif // _NVAPI_H
