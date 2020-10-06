// Copyright (c) 2020 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=5b2602702a13a71ac012808eecb09bb8b9494551$
//

#ifndef CEF_INCLUDE_CAPI_CEF_RESPONSE_FILTER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_RESPONSE_FILTER_CAPI_H_
#pragma once

#include "capi/cef_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
// Implement this structure to filter resource response content. The functions
// of this structure will be called on the browser process IO thread.
///
typedef struct _cef_response_filter_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Initialize the response filter. Will only be called a single time. The
  // filter will not be installed if this function returns false (0).
  ///
  int(CEF_CALLBACK* init_filter)(struct _cef_response_filter_t* self);

  ///
  // Called to filter a chunk of data. Expected usage is as follows:
  //
  //  A. Read input data from |data_in| and set |data_in_read| to the number of
  //     bytes that were read up to a maximum of |data_in_size|. |data_in| will
  //     be NULL if |data_in_size| is zero.
  //  B. Write filtered output data to |data_out| and set |data_out_written| to
  //     the number of bytes that were written up to a maximum of
  //     |data_out_size|. If no output data was written then all data must be
  //     read from |data_in| (user must set |data_in_read| = |data_in_size|).
  //  C. Return RESPONSE_FILTER_DONE if all output data was written or
  //     RESPONSE_FILTER_NEED_MORE_DATA if output data is still pending.
  //
  // This function will be called repeatedly until the input buffer has been
  // fully read (user sets |data_in_read| = |data_in_size|) and there is no more
  // input data to filter (the resource response is complete). This function may
  // then be called an additional time with an NULL input buffer if the user
  // filled the output buffer (set |data_out_written| = |data_out_size|) and
  // returned RESPONSE_FILTER_NEED_MORE_DATA to indicate that output data is
  // still pending.
  //
  // Calls to this function will stop when one of the following conditions is
  // met:
  //
  //  A. There is no more input data to filter (the resource response is
  //     complete) and the user sets |data_out_written| = 0 or returns
  //     RESPONSE_FILTER_DONE to indicate that all data has been written, or;
  //  B. The user returns RESPONSE_FILTER_ERROR to indicate an error.
  //
  // Do not keep a reference to the buffers passed to this function.
  ///
  cef_response_filter_status_t(CEF_CALLBACK* filter)(
      struct _cef_response_filter_t* self,
      void* data_in,
      size_t data_in_size,
      size_t* data_in_read,
      void* data_out,
      size_t data_out_size,
      size_t* data_out_written);
} cef_response_filter_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_RESPONSE_FILTER_CAPI_H_
