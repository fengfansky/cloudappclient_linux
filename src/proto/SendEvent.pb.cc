// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SendEvent.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "SendEvent.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace proto {

namespace {

const ::google::protobuf::Descriptor* SendEventRequest_descriptor_ = nullptr;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SendEventRequest_reflection_ = nullptr;
const ::google::protobuf::Descriptor* SendEvnetResponse_descriptor_ = nullptr;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SendEvnetResponse_reflection_ = nullptr;

}  // namespace


void protobuf_AssignDesc_SendEvent_2eproto() {
  protobuf_AddDesc_SendEvent_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "SendEvent.proto");
  GOOGLE_CHECK(file != nullptr);
  SendEventRequest_descriptor_ = file->message_type(0);
  static const int SendEventRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendEventRequest, appid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendEventRequest, event_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendEventRequest, extra_),
  };
  SendEventRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SendEventRequest_descriptor_,
      SendEventRequest::default_instance_,
      SendEventRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendEventRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendEventRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SendEventRequest));
  SendEvnetResponse_descriptor_ = file->message_type(1);
  static const int SendEvnetResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendEvnetResponse, response_),
  };
  SendEvnetResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SendEvnetResponse_descriptor_,
      SendEvnetResponse::default_instance_,
      SendEvnetResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendEvnetResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendEvnetResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SendEvnetResponse));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_SendEvent_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SendEventRequest_descriptor_, &SendEventRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SendEvnetResponse_descriptor_, &SendEvnetResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_SendEvent_2eproto() {
  delete SendEventRequest::default_instance_;
  delete SendEventRequest_reflection_;
  delete SendEvnetResponse::default_instance_;
  delete SendEvnetResponse_reflection_;
}

void protobuf_AddDesc_SendEvent_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017SendEvent.proto\022\005proto\"\?\n\020SendEventReq"
    "uest\022\r\n\005appId\030\001 \002(\t\022\r\n\005event\030\002 \002(\t\022\r\n\005ex"
    "tra\030\003 \002(\t\"%\n\021SendEvnetResponse\022\020\n\010respon"
    "se\030\001 \002(\t", 128);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "SendEvent.proto", &protobuf_RegisterTypes);
  SendEventRequest::default_instance_ = new SendEventRequest();
  SendEvnetResponse::default_instance_ = new SendEvnetResponse();
  SendEventRequest::default_instance_->InitAsDefaultInstance();
  SendEvnetResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_SendEvent_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_SendEvent_2eproto {
  StaticDescriptorInitializer_SendEvent_2eproto() {
    protobuf_AddDesc_SendEvent_2eproto();
  }
} static_descriptor_initializer_SendEvent_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int SendEventRequest::kAppIdFieldNumber;
const int SendEventRequest::kEventFieldNumber;
const int SendEventRequest::kExtraFieldNumber;
#endif  // !_MSC_VER

SendEventRequest::SendEventRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SendEventRequest::InitAsDefaultInstance() {
}

SendEventRequest::SendEventRequest(const SendEventRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SendEventRequest::SharedCtor() {
  _cached_size_ = 0;
  appid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  event_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  extra_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SendEventRequest::~SendEventRequest() {
  SharedDtor();
}

void SendEventRequest::SharedDtor() {
  if (appid_ != &::google::protobuf::internal::kEmptyString) {
    delete appid_;
  }
  if (event_ != &::google::protobuf::internal::kEmptyString) {
    delete event_;
  }
  if (extra_ != &::google::protobuf::internal::kEmptyString) {
    delete extra_;
  }
  if (this != default_instance_) {
  }
}

void SendEventRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SendEventRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SendEventRequest_descriptor_;
}

const SendEventRequest& SendEventRequest::default_instance() {
  if (default_instance_ == nullptr) protobuf_AddDesc_SendEvent_2eproto();
  return *default_instance_;
}

SendEventRequest* SendEventRequest::default_instance_ = nullptr;

SendEventRequest* SendEventRequest::New() const {
  return new SendEventRequest;
}

void SendEventRequest::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_appid()) {
      if (appid_ != &::google::protobuf::internal::kEmptyString) {
        appid_->clear();
      }
    }
    if (has_event()) {
      if (event_ != &::google::protobuf::internal::kEmptyString) {
        event_->clear();
      }
    }
    if (has_extra()) {
      if (extra_ != &::google::protobuf::internal::kEmptyString) {
        extra_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SendEventRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string appId = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_appid()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->appid().data(), this->appid().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_event;
        break;
      }

      // required string event = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_event:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_event()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->event().data(), this->event().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_extra;
        break;
      }

      // required string extra = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_extra:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_extra()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->extra().data(), this->extra().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void SendEventRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string appId = 1;
  if (has_appid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->appid().data(), this->appid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->appid(), output);
  }

  // required string event = 2;
  if (has_event()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->event().data(), this->event().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->event(), output);
  }

  // required string extra = 3;
  if (has_extra()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->extra().data(), this->extra().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->extra(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SendEventRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string appId = 1;
  if (has_appid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->appid().data(), this->appid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->appid(), target);
  }

  // required string event = 2;
  if (has_event()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->event().data(), this->event().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->event(), target);
  }

  // required string extra = 3;
  if (has_extra()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->extra().data(), this->extra().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->extra(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SendEventRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string appId = 1;
    if (has_appid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->appid());
    }

    // required string event = 2;
    if (has_event()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->event());
    }

    // required string extra = 3;
    if (has_extra()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->extra());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SendEventRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SendEventRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SendEventRequest*>(
      &from);
  if (source == nullptr) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SendEventRequest::MergeFrom(const SendEventRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_appid()) {
      set_appid(from.appid());
    }
    if (from.has_event()) {
      set_event(from.event());
    }
    if (from.has_extra()) {
      set_extra(from.extra());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SendEventRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SendEventRequest::CopyFrom(const SendEventRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SendEventRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void SendEventRequest::Swap(SendEventRequest* other) {
  if (other != this) {
    std::swap(appid_, other->appid_);
    std::swap(event_, other->event_);
    std::swap(extra_, other->extra_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SendEventRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SendEventRequest_descriptor_;
  metadata.reflection = SendEventRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SendEvnetResponse::kResponseFieldNumber;
#endif  // !_MSC_VER

SendEvnetResponse::SendEvnetResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SendEvnetResponse::InitAsDefaultInstance() {
}

SendEvnetResponse::SendEvnetResponse(const SendEvnetResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SendEvnetResponse::SharedCtor() {
  _cached_size_ = 0;
  response_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SendEvnetResponse::~SendEvnetResponse() {
  SharedDtor();
}

void SendEvnetResponse::SharedDtor() {
  if (response_ != &::google::protobuf::internal::kEmptyString) {
    delete response_;
  }
  if (this != default_instance_) {
  }
}

void SendEvnetResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SendEvnetResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SendEvnetResponse_descriptor_;
}

const SendEvnetResponse& SendEvnetResponse::default_instance() {
  if (default_instance_ == nullptr) protobuf_AddDesc_SendEvent_2eproto();
  return *default_instance_;
}

SendEvnetResponse* SendEvnetResponse::default_instance_ = nullptr;

SendEvnetResponse* SendEvnetResponse::New() const {
  return new SendEvnetResponse;
}

void SendEvnetResponse::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_response()) {
      if (response_ != &::google::protobuf::internal::kEmptyString) {
        response_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SendEvnetResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string response = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_response()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->response().data(), this->response().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void SendEvnetResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string response = 1;
  if (has_response()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->response().data(), this->response().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->response(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SendEvnetResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string response = 1;
  if (has_response()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->response().data(), this->response().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->response(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SendEvnetResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string response = 1;
    if (has_response()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->response());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SendEvnetResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SendEvnetResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SendEvnetResponse*>(
      &from);
  if (source == nullptr) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SendEvnetResponse::MergeFrom(const SendEvnetResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_response()) {
      set_response(from.response());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SendEvnetResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SendEvnetResponse::CopyFrom(const SendEvnetResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SendEvnetResponse::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void SendEvnetResponse::Swap(SendEvnetResponse* other) {
  if (other != this) {
    std::swap(response_, other->response_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SendEvnetResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SendEvnetResponse_descriptor_;
  metadata.reflection = SendEvnetResponse_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto

// @@protoc_insertion_point(global_scope)