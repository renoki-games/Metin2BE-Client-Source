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
// $hash=2aa57426a91e10985a5e92830bc3bcd9287708d4$
//

#ifndef CEF_INCLUDE_CAPI_CEF_FIND_HANDLER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_FIND_HANDLER_CAPI_H_
#pragma once

#include "capi/cef_base_capi.h"
#include "capi/cef_browser_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
// Implement this structure to handle events related to find results. The
// functions of this structure will be called on the UI thread.
///
typedef struct _cef_find_handler_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Called to report find results returned by cef_browser_host_t::find().
  // |identifer| is the identifier passed to find(), |count| is the number of
  // matches currently identified, |selectionRect| is the location of where the
  // match was found (in window coordinates), |activeMatchOrdinal| is the
  // current position in the search results, and |finalUpdate| is true (1) if
  // this is the last find notification.
  ///
  void(CEF_CALLBACK* on_find_result)(struct _cef_find_handler_t* self,
                                     struct _cef_browser_t* browser,
                                     int identifier,
                                     int count,
                                     const cef_rect_t* selectionRect,
                                     int activeMatchOrdinal,
                                     int finalUpdate);
} cef_find_handler_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_FIND_HANDLER_CAPI_H_
