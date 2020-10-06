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
// $hash=6c8c654be3e69d872b3cfa6bdfb1adf615bff3ac$
//

#ifndef CEF_INCLUDE_CAPI_CEF_DRAG_DATA_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_DRAG_DATA_CAPI_H_
#pragma once

#include "capi/cef_base_capi.h"
#include "capi/cef_image_capi.h"
#include "capi/cef_stream_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
// Structure used to represent drag data. The functions of this structure may be
// called on any thread.
///
typedef struct _cef_drag_data_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Returns a copy of the current object.
  ///
  struct _cef_drag_data_t*(CEF_CALLBACK* clone)(struct _cef_drag_data_t* self);

  ///
  // Returns true (1) if this object is read-only.
  ///
  int(CEF_CALLBACK* is_read_only)(struct _cef_drag_data_t* self);

  ///
  // Returns true (1) if the drag data is a link.
  ///
  int(CEF_CALLBACK* is_link)(struct _cef_drag_data_t* self);

  ///
  // Returns true (1) if the drag data is a text or html fragment.
  ///
  int(CEF_CALLBACK* is_fragment)(struct _cef_drag_data_t* self);

  ///
  // Returns true (1) if the drag data is a file.
  ///
  int(CEF_CALLBACK* is_file)(struct _cef_drag_data_t* self);

  ///
  // Return the link URL that is being dragged.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_link_url)(
      struct _cef_drag_data_t* self);

  ///
  // Return the title associated with the link being dragged.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_link_title)(
      struct _cef_drag_data_t* self);

  ///
  // Return the metadata, if any, associated with the link being dragged.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_link_metadata)(
      struct _cef_drag_data_t* self);

  ///
  // Return the plain text fragment that is being dragged.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_fragment_text)(
      struct _cef_drag_data_t* self);

  ///
  // Return the text/html fragment that is being dragged.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_fragment_html)(
      struct _cef_drag_data_t* self);

  ///
  // Return the base URL that the fragment came from. This value is used for
  // resolving relative URLs and may be NULL.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_fragment_base_url)(
      struct _cef_drag_data_t* self);

  ///
  // Return the name of the file being dragged out of the browser window.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_file_name)(
      struct _cef_drag_data_t* self);

  ///
  // Write the contents of the file being dragged out of the web view into
  // |writer|. Returns the number of bytes sent to |writer|. If |writer| is NULL
  // this function will return the size of the file contents in bytes. Call
  // get_file_name() to get a suggested name for the file.
  ///
  size_t(CEF_CALLBACK* get_file_contents)(struct _cef_drag_data_t* self,
                                          struct _cef_stream_writer_t* writer);

  ///
  // Retrieve the list of file names that are being dragged into the browser
  // window.
  ///
  int(CEF_CALLBACK* get_file_names)(struct _cef_drag_data_t* self,
                                    cef_string_list_t names);

  ///
  // Set the link URL that is being dragged.
  ///
  void(CEF_CALLBACK* set_link_url)(struct _cef_drag_data_t* self,
                                   const cef_string_t* url);

  ///
  // Set the title associated with the link being dragged.
  ///
  void(CEF_CALLBACK* set_link_title)(struct _cef_drag_data_t* self,
                                     const cef_string_t* title);

  ///
  // Set the metadata associated with the link being dragged.
  ///
  void(CEF_CALLBACK* set_link_metadata)(struct _cef_drag_data_t* self,
                                        const cef_string_t* data);

  ///
  // Set the plain text fragment that is being dragged.
  ///
  void(CEF_CALLBACK* set_fragment_text)(struct _cef_drag_data_t* self,
                                        const cef_string_t* text);

  ///
  // Set the text/html fragment that is being dragged.
  ///
  void(CEF_CALLBACK* set_fragment_html)(struct _cef_drag_data_t* self,
                                        const cef_string_t* html);

  ///
  // Set the base URL that the fragment came from.
  ///
  void(CEF_CALLBACK* set_fragment_base_url)(struct _cef_drag_data_t* self,
                                            const cef_string_t* base_url);

  ///
  // Reset the file contents. You should do this before calling
  // cef_browser_host_t::DragTargetDragEnter as the web view does not allow us
  // to drag in this kind of data.
  ///
  void(CEF_CALLBACK* reset_file_contents)(struct _cef_drag_data_t* self);

  ///
  // Add a file that is being dragged into the webview.
  ///
  void(CEF_CALLBACK* add_file)(struct _cef_drag_data_t* self,
                               const cef_string_t* path,
                               const cef_string_t* display_name);

  ///
  // Get the image representation of drag data. May return NULL if no image
  // representation is available.
  ///
  struct _cef_image_t*(CEF_CALLBACK* get_image)(struct _cef_drag_data_t* self);

  ///
  // Get the image hotspot (drag start location relative to image dimensions).
  ///
  cef_point_t(CEF_CALLBACK* get_image_hotspot)(struct _cef_drag_data_t* self);

  ///
  // Returns true (1) if an image representation of drag data is available.
  ///
  int(CEF_CALLBACK* has_image)(struct _cef_drag_data_t* self);
} cef_drag_data_t;

///
// Create a new cef_drag_data_t object.
///
CEF_EXPORT cef_drag_data_t* cef_drag_data_create();

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_DRAG_DATA_CAPI_H_
