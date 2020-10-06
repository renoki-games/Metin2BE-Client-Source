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
// $hash=3755121a7b89de52a67885ac1c6d12de23f4b657$
//

#ifndef CEF_INCLUDE_CAPI_CEF_SSL_STATUS_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_SSL_STATUS_CAPI_H_
#pragma once

#include "capi/cef_base_capi.h"
#include "capi/cef_values_capi.h"
#include "capi/cef_x509_certificate_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
// Structure representing the SSL information for a navigation entry.
///
typedef struct _cef_sslstatus_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Returns true (1) if the status is related to a secure SSL/TLS connection.
  ///
  int(CEF_CALLBACK* is_secure_connection)(struct _cef_sslstatus_t* self);

  ///
  // Returns a bitmask containing any and all problems verifying the server
  // certificate.
  ///
  cef_cert_status_t(CEF_CALLBACK* get_cert_status)(
      struct _cef_sslstatus_t* self);

  ///
  // Returns the SSL version used for the SSL connection.
  ///
  cef_ssl_version_t(CEF_CALLBACK* get_sslversion)(
      struct _cef_sslstatus_t* self);

  ///
  // Returns a bitmask containing the page security content status.
  ///
  cef_ssl_content_status_t(CEF_CALLBACK* get_content_status)(
      struct _cef_sslstatus_t* self);

  ///
  // Returns the X.509 certificate.
  ///
  struct _cef_x509certificate_t*(CEF_CALLBACK* get_x509certificate)(
      struct _cef_sslstatus_t* self);
} cef_sslstatus_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_SSL_STATUS_CAPI_H_