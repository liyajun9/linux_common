// Copyright (c) 2009 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This provides a wrapper around system calls which may be interrupted by a
// signal and return EINTR. See man 7 signal.

#ifndef PUBLIC_BASE_EINTR_WRAPPER_H_
#define PUBLIC_BASE_EINTR_WRAPPER_H_

#include <errno.h>

#define HANDLE_EINTR(x) ({ \
  decltype(x) __eintr_result__; \
  do { \
    __eintr_result__ = x; \
  } while (__eintr_result__ == -1 && errno == EINTR); \
  __eintr_result__;\
})

#endif  // PUBLIC_BASE_EINTR_WRAPPER_H_
