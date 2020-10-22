/**
 * \file src/core/include/megbrain_build_config.h
 * MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Copyright (c) 2014-2020 Megvii Inc. All rights reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT ARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

#ifndef _HEADER_MGB_BUILD_CONFIG
#define _HEADER_MGB_BUILD_CONFIG

#define MGB_CUDA 0
#define MGB_ROCM 0
#define MGB_CAMBRICON 0
#define MGB_ATLAS 0
#define MGB_ASSERT_LOC 0
#define MGB_ENABLE_DEBUG_UTIL 0
#define MGB_ENABLE_LOGGING 1
#define MGB_ENABLE_GRAD 0
#define MGB_ENABLE_CPUINFO 0
#define MGB_VERBOSE_TYPEINFO_NAME 1
#define MGB_BUILD_SLIM_SERVING 1
#define MGB_ENABLE_EXCEPTION 1
#define MGB_JIT 0
#define MGB_JIT_MLIR 0
#define MGB_JIT_HALIDE 0
#define MGB_ENABLE_TENSOR_RT 0
#define MGB_ENABLE_JSON 1
#define MGB_HAVE_THREAD 1
#define MGB_ENABLE_OPR_MM 0
#define MGB_ENABLE_FBS_SERIALIZATION 1
#define MGB_IS_DEV 0

// DNN related flags
// Platform macro's
#define MEGDNN_WITH_CUDA 0

#define MEGDNN_WITH_ROCM 0
#define MEGDNN_ARMV7 0
#define MEGDNN_AARCH64 1
#define MEGDNN_ENABLE_FP16_NEON 0

#define MEGDNN_X86_WITH_MKL 0
#define MEGDNN_X86_WITH_OPENBLAS 0
#define MEGDNN_X86_WITH_MKL_DNN 0
#define MEGDNN_ENABLE_RTTI 1
#define MEGDNN_ENABLE_LOGGING 1
#define MEGDNN_ENABLE_MANGLING 0
#define MEGDNN_ENABLE_EXCEPTIONS 1
#define MEGDNN_NAIVE 0
#define MEGDNN_X86 0
#define MEGDNN_X86_64 0
#define MEGDNN_64_BIT 1
#define MEGDNN_THREADS_512 0
#define MEGDNN_ENABLE_MULTI_THREADS 0

// whether atlas is available
#ifndef MGB_ATLAS
#define MGB_ATLAS  0
#endif

// whether cuda is available
#ifndef MGB_CUDA
#define MGB_CUDA    1
#endif


// whether to include file/line location for assert message
#ifndef MGB_ASSERT_LOC
#define MGB_ASSERT_LOC          1
#endif

// whether to enable utils/debug.h and other debug methods
#ifndef MGB_ENABLE_DEBUG_UTIL
#define MGB_ENABLE_DEBUG_UTIL   1
#endif

// whether to enable logging
#ifndef MGB_ENABLE_LOGGING
#define MGB_ENABLE_LOGGING      1
#endif

// whether to enable registering opr grad functions
#ifndef MGB_ENABLE_GRAD
#define MGB_ENABLE_GRAD         1
#endif

// whether to enable cpuinfo
#ifndef MGB_ENABLE_CPUINFO
#define MGB_ENABLE_CPUINFO      1
#endif

#ifdef IOS
#undef MGB_ENABLE_CPUINFO
#define MGB_ENABLE_CPUINFO      0
#endif

// whether to include actual class name in mgb::Typeinfo object; if this is
// disabled, mgb::serialization::OprRegistry::find_opr_by_name would not work.
#ifndef MGB_VERBOSE_TYPEINFO_NAME
#define MGB_VERBOSE_TYPEINFO_NAME   1
#endif

// whether to enbale configuing megbrain internals through env vars
#ifndef MGB_ENABLE_GETENV
#define MGB_ENABLE_GETENV       1
#endif

// whether to remove unnecessary features when used for serving
#ifndef MGB_BUILD_SLIM_SERVING
#define MGB_BUILD_SLIM_SERVING  0
#endif

// whether to enable exception
#ifndef MGB_ENABLE_EXCEPTION
#if __EXCEPTIONS
#define MGB_ENABLE_EXCEPTION    1
#else
#define MGB_ENABLE_EXCEPTION    0
#endif
#endif

// whether <thread> is available and usable
#ifndef MGB_HAVE_THREAD
#define MGB_HAVE_THREAD         1
#endif

// whether to trade thread safety for memory usage
#ifndef MGB_THREAD_SAFE
#define MGB_THREAD_SAFE MGB_HAVE_THREAD
#endif

// whether to enable JIT
#ifndef MGB_JIT
#define MGB_JIT     1
#endif
#ifndef MGB_JIT_HALIDE
#define MGB_JIT_HALIDE 0
#endif


#ifndef MEGDNN_WITH_CAMBRICON
#define MEGDNN_WITH_CAMBRICON 0
#endif

#ifndef MGB_CAMBRICON
#define MGB_CAMBRICON MEGDNN_WITH_CAMBRICON
#endif


// whether to enable TensorRT support
#ifndef MGB_ENABLE_TENSOR_RT
#define MGB_ENABLE_TENSOR_RT    MGB_CUDA
#endif

// whether to enable fastrun profile
#ifndef MGB_ENABLE_FASTRUN
#define MGB_ENABLE_FASTRUN 1
#endif


/* ================= following are more finegrind controls ================= */

// whether to enable json dumper
#ifndef MGB_ENABLE_JSON
#define MGB_ENABLE_JSON !MGB_BUILD_SLIM_SERVING
#endif

// whether to enable distributed communication
#ifndef MGB_ENABLE_OPR_MM
#define MGB_ENABLE_OPR_MM 0
#endif

/* ================= DNN related flags ================= */

// whether to use mkl lib
#ifndef MEGDNN_X86_WITH_MKL
#define MEGDNN_X86_WITH_MKL 0
#endif

// whether to enable rtti
#ifndef MEGDNN_ENABLE_RTTI
#define MEGDNN_ENABLE_RTTI 1
#endif

// whether to enable mangling
#ifndef MEGDNN_ENABLE_MANGLING
#define MEGDNN_ENABLE_MANGLING !MEGDNN_ENABLE_RTTI
#endif

// whether to enable logging
#ifndef MEGDNN_ENABLE_LOGGING
#define MEGDNN_ENABLE_LOGGING MGB_ENABLE_LOGGING
#endif

// whether to enable exception
#ifndef MEGDNN_ENABLE_EXCEPTIONS
#define MEGDNN_ENABLE_EXCEPTIONS MGB_ENABLE_EXCEPTION
#endif

// whether to build naive
#ifndef MEGDNN_NAIVE
#define MEGDNN_NAIVE 0
#endif

// whether to build x86
#ifndef MEGDNN_X86
#define MEGDNN_X86 0
#endif

// whether to use cuda thread 512
#ifndef MEGDNN_THREADS_512
#define MEGDNN_THREADS_512 0
#endif

// whether to enable intra-op multi threads
#ifndef MEGDNN_ENABLE_MULTI_THREADS
#define MEGDNN_ENABLE_MULTI_THREADS 1
#endif

#ifndef MEGDNN_X86_WITH_OPENBLAS
#define MEGDNN_X86_WITH_OPENBLAS 0
#endif

#ifndef MEGDNN_X86_WITH_MKL_DNN
#define MEGDNN_X86_WITH_MKL_DNN 0
#endif

#endif // _HEADER_MGB_BUILD_CONFIG
