// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SendEvent.proto

#ifndef PROTOBUF_SendEvent_2eproto__INCLUDED
#define PROTOBUF_SendEvent_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003002 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace proto {
class SendEventRequest;
class SendEventRequestDefaultTypeInternal;
extern SendEventRequestDefaultTypeInternal _SendEventRequest_default_instance_;
class SendEvnetResponse;
class SendEvnetResponseDefaultTypeInternal;
extern SendEvnetResponseDefaultTypeInternal _SendEvnetResponse_default_instance_;
}  // namespace proto

namespace proto {

namespace protobuf_SendEvent_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_SendEvent_2eproto

// ===================================================================

class SendEventRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:proto.SendEventRequest) */ {
 public:
  SendEventRequest();
  virtual ~SendEventRequest();

  SendEventRequest(const SendEventRequest& from);

  inline SendEventRequest& operator=(const SendEventRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SendEventRequest& default_instance();

  static inline const SendEventRequest* internal_default_instance() {
    return reinterpret_cast<const SendEventRequest*>(
               &_SendEventRequest_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(SendEventRequest* other);

  // implements Message ----------------------------------------------

  inline SendEventRequest* New() const PROTOBUF_FINAL { return New(NULL); }

  SendEventRequest* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SendEventRequest& from);
  void MergeFrom(const SendEventRequest& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SendEventRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string appId = 1;
  void clear_appid();
  static const int kAppIdFieldNumber = 1;
  const ::std::string& appid() const;
  void set_appid(const ::std::string& value);
  #if LANG_CXX11
  void set_appid(::std::string&& value);
  #endif
  void set_appid(const char* value);
  void set_appid(const char* value, size_t size);
  ::std::string* mutable_appid();
  ::std::string* release_appid();
  void set_allocated_appid(::std::string* appid);

  // string event = 2;
  void clear_event();
  static const int kEventFieldNumber = 2;
  const ::std::string& event() const;
  void set_event(const ::std::string& value);
  #if LANG_CXX11
  void set_event(::std::string&& value);
  #endif
  void set_event(const char* value);
  void set_event(const char* value, size_t size);
  ::std::string* mutable_event();
  ::std::string* release_event();
  void set_allocated_event(::std::string* event);

  // string extra = 3;
  void clear_extra();
  static const int kExtraFieldNumber = 3;
  const ::std::string& extra() const;
  void set_extra(const ::std::string& value);
  #if LANG_CXX11
  void set_extra(::std::string&& value);
  #endif
  void set_extra(const char* value);
  void set_extra(const char* value, size_t size);
  ::std::string* mutable_extra();
  ::std::string* release_extra();
  void set_allocated_extra(::std::string* extra);

  // @@protoc_insertion_point(class_scope:proto.SendEventRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr appid_;
  ::google::protobuf::internal::ArenaStringPtr event_;
  ::google::protobuf::internal::ArenaStringPtr extra_;
  mutable int _cached_size_;
  friend struct protobuf_SendEvent_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SendEvnetResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:proto.SendEvnetResponse) */ {
 public:
  SendEvnetResponse();
  virtual ~SendEvnetResponse();

  SendEvnetResponse(const SendEvnetResponse& from);

  inline SendEvnetResponse& operator=(const SendEvnetResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SendEvnetResponse& default_instance();

  static inline const SendEvnetResponse* internal_default_instance() {
    return reinterpret_cast<const SendEvnetResponse*>(
               &_SendEvnetResponse_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(SendEvnetResponse* other);

  // implements Message ----------------------------------------------

  inline SendEvnetResponse* New() const PROTOBUF_FINAL { return New(NULL); }

  SendEvnetResponse* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SendEvnetResponse& from);
  void MergeFrom(const SendEvnetResponse& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SendEvnetResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string response = 1;
  void clear_response();
  static const int kResponseFieldNumber = 1;
  const ::std::string& response() const;
  void set_response(const ::std::string& value);
  #if LANG_CXX11
  void set_response(::std::string&& value);
  #endif
  void set_response(const char* value);
  void set_response(const char* value, size_t size);
  ::std::string* mutable_response();
  ::std::string* release_response();
  void set_allocated_response(::std::string* response);

  // @@protoc_insertion_point(class_scope:proto.SendEvnetResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr response_;
  mutable int _cached_size_;
  friend struct protobuf_SendEvent_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// SendEventRequest

// string appId = 1;
inline void SendEventRequest::clear_appid() {
  appid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendEventRequest::appid() const {
  // @@protoc_insertion_point(field_get:proto.SendEventRequest.appId)
  return appid_.GetNoArena();
}
inline void SendEventRequest::set_appid(const ::std::string& value) {
  
  appid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto.SendEventRequest.appId)
}
#if LANG_CXX11
inline void SendEventRequest::set_appid(::std::string&& value) {
  
  appid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:proto.SendEventRequest.appId)
}
#endif
inline void SendEventRequest::set_appid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  appid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto.SendEventRequest.appId)
}
inline void SendEventRequest::set_appid(const char* value, size_t size) {
  
  appid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto.SendEventRequest.appId)
}
inline ::std::string* SendEventRequest::mutable_appid() {
  
  // @@protoc_insertion_point(field_mutable:proto.SendEventRequest.appId)
  return appid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendEventRequest::release_appid() {
  // @@protoc_insertion_point(field_release:proto.SendEventRequest.appId)
  
  return appid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendEventRequest::set_allocated_appid(::std::string* appid) {
  if (appid != NULL) {
    
  } else {
    
  }
  appid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), appid);
  // @@protoc_insertion_point(field_set_allocated:proto.SendEventRequest.appId)
}

// string event = 2;
inline void SendEventRequest::clear_event() {
  event_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendEventRequest::event() const {
  // @@protoc_insertion_point(field_get:proto.SendEventRequest.event)
  return event_.GetNoArena();
}
inline void SendEventRequest::set_event(const ::std::string& value) {
  
  event_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto.SendEventRequest.event)
}
#if LANG_CXX11
inline void SendEventRequest::set_event(::std::string&& value) {
  
  event_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:proto.SendEventRequest.event)
}
#endif
inline void SendEventRequest::set_event(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  event_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto.SendEventRequest.event)
}
inline void SendEventRequest::set_event(const char* value, size_t size) {
  
  event_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto.SendEventRequest.event)
}
inline ::std::string* SendEventRequest::mutable_event() {
  
  // @@protoc_insertion_point(field_mutable:proto.SendEventRequest.event)
  return event_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendEventRequest::release_event() {
  // @@protoc_insertion_point(field_release:proto.SendEventRequest.event)
  
  return event_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendEventRequest::set_allocated_event(::std::string* event) {
  if (event != NULL) {
    
  } else {
    
  }
  event_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), event);
  // @@protoc_insertion_point(field_set_allocated:proto.SendEventRequest.event)
}

// string extra = 3;
inline void SendEventRequest::clear_extra() {
  extra_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendEventRequest::extra() const {
  // @@protoc_insertion_point(field_get:proto.SendEventRequest.extra)
  return extra_.GetNoArena();
}
inline void SendEventRequest::set_extra(const ::std::string& value) {
  
  extra_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto.SendEventRequest.extra)
}
#if LANG_CXX11
inline void SendEventRequest::set_extra(::std::string&& value) {
  
  extra_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:proto.SendEventRequest.extra)
}
#endif
inline void SendEventRequest::set_extra(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  extra_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto.SendEventRequest.extra)
}
inline void SendEventRequest::set_extra(const char* value, size_t size) {
  
  extra_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto.SendEventRequest.extra)
}
inline ::std::string* SendEventRequest::mutable_extra() {
  
  // @@protoc_insertion_point(field_mutable:proto.SendEventRequest.extra)
  return extra_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendEventRequest::release_extra() {
  // @@protoc_insertion_point(field_release:proto.SendEventRequest.extra)
  
  return extra_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendEventRequest::set_allocated_extra(::std::string* extra) {
  if (extra != NULL) {
    
  } else {
    
  }
  extra_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), extra);
  // @@protoc_insertion_point(field_set_allocated:proto.SendEventRequest.extra)
}

// -------------------------------------------------------------------

// SendEvnetResponse

// string response = 1;
inline void SendEvnetResponse::clear_response() {
  response_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendEvnetResponse::response() const {
  // @@protoc_insertion_point(field_get:proto.SendEvnetResponse.response)
  return response_.GetNoArena();
}
inline void SendEvnetResponse::set_response(const ::std::string& value) {
  
  response_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto.SendEvnetResponse.response)
}
#if LANG_CXX11
inline void SendEvnetResponse::set_response(::std::string&& value) {
  
  response_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:proto.SendEvnetResponse.response)
}
#endif
inline void SendEvnetResponse::set_response(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  response_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto.SendEvnetResponse.response)
}
inline void SendEvnetResponse::set_response(const char* value, size_t size) {
  
  response_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto.SendEvnetResponse.response)
}
inline ::std::string* SendEvnetResponse::mutable_response() {
  
  // @@protoc_insertion_point(field_mutable:proto.SendEvnetResponse.response)
  return response_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendEvnetResponse::release_response() {
  // @@protoc_insertion_point(field_release:proto.SendEvnetResponse.response)
  
  return response_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendEvnetResponse::set_allocated_response(::std::string* response) {
  if (response != NULL) {
    
  } else {
    
  }
  response_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), response);
  // @@protoc_insertion_point(field_set_allocated:proto.SendEvnetResponse.response)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace proto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_SendEvent_2eproto__INCLUDED
