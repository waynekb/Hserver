// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: hmessage.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_hmessage_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_hmessage_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_hmessage_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_hmessage_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_hmessage_2eproto;
class HPR_MsgBody;
class HPR_MsgBodyDefaultTypeInternal;
extern HPR_MsgBodyDefaultTypeInternal _HPR_MsgBody_default_instance_;
class HPR_MsgHead;
class HPR_MsgHeadDefaultTypeInternal;
extern HPR_MsgHeadDefaultTypeInternal _HPR_MsgHead_default_instance_;
class HPR_SvrMsg;
class HPR_SvrMsgDefaultTypeInternal;
extern HPR_SvrMsgDefaultTypeInternal _HPR_SvrMsg_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::HPR_MsgBody* Arena::CreateMaybeMessage<::HPR_MsgBody>(Arena*);
template<> ::HPR_MsgHead* Arena::CreateMaybeMessage<::HPR_MsgHead>(Arena*);
template<> ::HPR_SvrMsg* Arena::CreateMaybeMessage<::HPR_SvrMsg>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class HPR_MsgBody PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:HPR_MsgBody) */ {
 public:
  inline HPR_MsgBody() : HPR_MsgBody(nullptr) {}
  virtual ~HPR_MsgBody();

  HPR_MsgBody(const HPR_MsgBody& from);
  HPR_MsgBody(HPR_MsgBody&& from) noexcept
    : HPR_MsgBody() {
    *this = ::std::move(from);
  }

  inline HPR_MsgBody& operator=(const HPR_MsgBody& from) {
    CopyFrom(from);
    return *this;
  }
  inline HPR_MsgBody& operator=(HPR_MsgBody&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const HPR_MsgBody& default_instance();

  static inline const HPR_MsgBody* internal_default_instance() {
    return reinterpret_cast<const HPR_MsgBody*>(
               &_HPR_MsgBody_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(HPR_MsgBody& a, HPR_MsgBody& b) {
    a.Swap(&b);
  }
  inline void Swap(HPR_MsgBody* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HPR_MsgBody* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline HPR_MsgBody* New() const final {
    return CreateMaybeMessage<HPR_MsgBody>(nullptr);
  }

  HPR_MsgBody* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<HPR_MsgBody>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const HPR_MsgBody& from);
  void MergeFrom(const HPR_MsgBody& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HPR_MsgBody* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "HPR_MsgBody";
  }
  protected:
  explicit HPR_MsgBody(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_hmessage_2eproto);
    return ::descriptor_table_hmessage_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kAgeFieldNumber = 2,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // uint32 age = 2;
  void clear_age();
  ::PROTOBUF_NAMESPACE_ID::uint32 age() const;
  void set_age(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_age() const;
  void _internal_set_age(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:HPR_MsgBody)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::uint32 age_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_hmessage_2eproto;
};
// -------------------------------------------------------------------

class HPR_MsgHead PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:HPR_MsgHead) */ {
 public:
  inline HPR_MsgHead() : HPR_MsgHead(nullptr) {}
  virtual ~HPR_MsgHead();

  HPR_MsgHead(const HPR_MsgHead& from);
  HPR_MsgHead(HPR_MsgHead&& from) noexcept
    : HPR_MsgHead() {
    *this = ::std::move(from);
  }

  inline HPR_MsgHead& operator=(const HPR_MsgHead& from) {
    CopyFrom(from);
    return *this;
  }
  inline HPR_MsgHead& operator=(HPR_MsgHead&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const HPR_MsgHead& default_instance();

  static inline const HPR_MsgHead* internal_default_instance() {
    return reinterpret_cast<const HPR_MsgHead*>(
               &_HPR_MsgHead_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(HPR_MsgHead& a, HPR_MsgHead& b) {
    a.Swap(&b);
  }
  inline void Swap(HPR_MsgHead* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HPR_MsgHead* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline HPR_MsgHead* New() const final {
    return CreateMaybeMessage<HPR_MsgHead>(nullptr);
  }

  HPR_MsgHead* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<HPR_MsgHead>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const HPR_MsgHead& from);
  void MergeFrom(const HPR_MsgHead& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HPR_MsgHead* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "HPR_MsgHead";
  }
  protected:
  explicit HPR_MsgHead(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_hmessage_2eproto);
    return ::descriptor_table_hmessage_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSeqFieldNumber = 2,
    kCmdFieldNumber = 1,
  };
  // uint64 seq = 2;
  void clear_seq();
  ::PROTOBUF_NAMESPACE_ID::uint64 seq() const;
  void set_seq(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_seq() const;
  void _internal_set_seq(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // uint32 cmd = 1;
  void clear_cmd();
  ::PROTOBUF_NAMESPACE_ID::uint32 cmd() const;
  void set_cmd(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_cmd() const;
  void _internal_set_cmd(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:HPR_MsgHead)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::uint64 seq_;
  ::PROTOBUF_NAMESPACE_ID::uint32 cmd_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_hmessage_2eproto;
};
// -------------------------------------------------------------------

class HPR_SvrMsg PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:HPR_SvrMsg) */ {
 public:
  inline HPR_SvrMsg() : HPR_SvrMsg(nullptr) {}
  virtual ~HPR_SvrMsg();

  HPR_SvrMsg(const HPR_SvrMsg& from);
  HPR_SvrMsg(HPR_SvrMsg&& from) noexcept
    : HPR_SvrMsg() {
    *this = ::std::move(from);
  }

  inline HPR_SvrMsg& operator=(const HPR_SvrMsg& from) {
    CopyFrom(from);
    return *this;
  }
  inline HPR_SvrMsg& operator=(HPR_SvrMsg&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const HPR_SvrMsg& default_instance();

  static inline const HPR_SvrMsg* internal_default_instance() {
    return reinterpret_cast<const HPR_SvrMsg*>(
               &_HPR_SvrMsg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(HPR_SvrMsg& a, HPR_SvrMsg& b) {
    a.Swap(&b);
  }
  inline void Swap(HPR_SvrMsg* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HPR_SvrMsg* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline HPR_SvrMsg* New() const final {
    return CreateMaybeMessage<HPR_SvrMsg>(nullptr);
  }

  HPR_SvrMsg* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<HPR_SvrMsg>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const HPR_SvrMsg& from);
  void MergeFrom(const HPR_SvrMsg& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HPR_SvrMsg* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "HPR_SvrMsg";
  }
  protected:
  explicit HPR_SvrMsg(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_hmessage_2eproto);
    return ::descriptor_table_hmessage_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kHeadFieldNumber = 1,
    kBodyFieldNumber = 2,
  };
  // .HPR_MsgHead head = 1;
  bool has_head() const;
  private:
  bool _internal_has_head() const;
  public:
  void clear_head();
  const ::HPR_MsgHead& head() const;
  ::HPR_MsgHead* release_head();
  ::HPR_MsgHead* mutable_head();
  void set_allocated_head(::HPR_MsgHead* head);
  private:
  const ::HPR_MsgHead& _internal_head() const;
  ::HPR_MsgHead* _internal_mutable_head();
  public:
  void unsafe_arena_set_allocated_head(
      ::HPR_MsgHead* head);
  ::HPR_MsgHead* unsafe_arena_release_head();

  // .HPR_MsgBody body = 2;
  bool has_body() const;
  private:
  bool _internal_has_body() const;
  public:
  void clear_body();
  const ::HPR_MsgBody& body() const;
  ::HPR_MsgBody* release_body();
  ::HPR_MsgBody* mutable_body();
  void set_allocated_body(::HPR_MsgBody* body);
  private:
  const ::HPR_MsgBody& _internal_body() const;
  ::HPR_MsgBody* _internal_mutable_body();
  public:
  void unsafe_arena_set_allocated_body(
      ::HPR_MsgBody* body);
  ::HPR_MsgBody* unsafe_arena_release_body();

  // @@protoc_insertion_point(class_scope:HPR_SvrMsg)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::HPR_MsgHead* head_;
  ::HPR_MsgBody* body_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_hmessage_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HPR_MsgBody

// string name = 1;
inline void HPR_MsgBody::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& HPR_MsgBody::name() const {
  // @@protoc_insertion_point(field_get:HPR_MsgBody.name)
  return _internal_name();
}
inline void HPR_MsgBody::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:HPR_MsgBody.name)
}
inline std::string* HPR_MsgBody::mutable_name() {
  // @@protoc_insertion_point(field_mutable:HPR_MsgBody.name)
  return _internal_mutable_name();
}
inline const std::string& HPR_MsgBody::_internal_name() const {
  return name_.Get();
}
inline void HPR_MsgBody::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void HPR_MsgBody::set_name(std::string&& value) {
  
  name_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:HPR_MsgBody.name)
}
inline void HPR_MsgBody::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:HPR_MsgBody.name)
}
inline void HPR_MsgBody::set_name(const char* value,
    size_t size) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:HPR_MsgBody.name)
}
inline std::string* HPR_MsgBody::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* HPR_MsgBody::release_name() {
  // @@protoc_insertion_point(field_release:HPR_MsgBody.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void HPR_MsgBody::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:HPR_MsgBody.name)
}

// uint32 age = 2;
inline void HPR_MsgBody::clear_age() {
  age_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 HPR_MsgBody::_internal_age() const {
  return age_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 HPR_MsgBody::age() const {
  // @@protoc_insertion_point(field_get:HPR_MsgBody.age)
  return _internal_age();
}
inline void HPR_MsgBody::_internal_set_age(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  age_ = value;
}
inline void HPR_MsgBody::set_age(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_age(value);
  // @@protoc_insertion_point(field_set:HPR_MsgBody.age)
}

// -------------------------------------------------------------------

// HPR_MsgHead

// uint32 cmd = 1;
inline void HPR_MsgHead::clear_cmd() {
  cmd_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 HPR_MsgHead::_internal_cmd() const {
  return cmd_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 HPR_MsgHead::cmd() const {
  // @@protoc_insertion_point(field_get:HPR_MsgHead.cmd)
  return _internal_cmd();
}
inline void HPR_MsgHead::_internal_set_cmd(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  cmd_ = value;
}
inline void HPR_MsgHead::set_cmd(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_cmd(value);
  // @@protoc_insertion_point(field_set:HPR_MsgHead.cmd)
}

// uint64 seq = 2;
inline void HPR_MsgHead::clear_seq() {
  seq_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 HPR_MsgHead::_internal_seq() const {
  return seq_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 HPR_MsgHead::seq() const {
  // @@protoc_insertion_point(field_get:HPR_MsgHead.seq)
  return _internal_seq();
}
inline void HPR_MsgHead::_internal_set_seq(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  seq_ = value;
}
inline void HPR_MsgHead::set_seq(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_seq(value);
  // @@protoc_insertion_point(field_set:HPR_MsgHead.seq)
}

// -------------------------------------------------------------------

// HPR_SvrMsg

// .HPR_MsgHead head = 1;
inline bool HPR_SvrMsg::_internal_has_head() const {
  return this != internal_default_instance() && head_ != nullptr;
}
inline bool HPR_SvrMsg::has_head() const {
  return _internal_has_head();
}
inline void HPR_SvrMsg::clear_head() {
  if (GetArena() == nullptr && head_ != nullptr) {
    delete head_;
  }
  head_ = nullptr;
}
inline const ::HPR_MsgHead& HPR_SvrMsg::_internal_head() const {
  const ::HPR_MsgHead* p = head_;
  return p != nullptr ? *p : reinterpret_cast<const ::HPR_MsgHead&>(
      ::_HPR_MsgHead_default_instance_);
}
inline const ::HPR_MsgHead& HPR_SvrMsg::head() const {
  // @@protoc_insertion_point(field_get:HPR_SvrMsg.head)
  return _internal_head();
}
inline void HPR_SvrMsg::unsafe_arena_set_allocated_head(
    ::HPR_MsgHead* head) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(head_);
  }
  head_ = head;
  if (head) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:HPR_SvrMsg.head)
}
inline ::HPR_MsgHead* HPR_SvrMsg::release_head() {
  
  ::HPR_MsgHead* temp = head_;
  head_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::HPR_MsgHead* HPR_SvrMsg::unsafe_arena_release_head() {
  // @@protoc_insertion_point(field_release:HPR_SvrMsg.head)
  
  ::HPR_MsgHead* temp = head_;
  head_ = nullptr;
  return temp;
}
inline ::HPR_MsgHead* HPR_SvrMsg::_internal_mutable_head() {
  
  if (head_ == nullptr) {
    auto* p = CreateMaybeMessage<::HPR_MsgHead>(GetArena());
    head_ = p;
  }
  return head_;
}
inline ::HPR_MsgHead* HPR_SvrMsg::mutable_head() {
  // @@protoc_insertion_point(field_mutable:HPR_SvrMsg.head)
  return _internal_mutable_head();
}
inline void HPR_SvrMsg::set_allocated_head(::HPR_MsgHead* head) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete head_;
  }
  if (head) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(head);
    if (message_arena != submessage_arena) {
      head = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, head, submessage_arena);
    }
    
  } else {
    
  }
  head_ = head;
  // @@protoc_insertion_point(field_set_allocated:HPR_SvrMsg.head)
}

// .HPR_MsgBody body = 2;
inline bool HPR_SvrMsg::_internal_has_body() const {
  return this != internal_default_instance() && body_ != nullptr;
}
inline bool HPR_SvrMsg::has_body() const {
  return _internal_has_body();
}
inline void HPR_SvrMsg::clear_body() {
  if (GetArena() == nullptr && body_ != nullptr) {
    delete body_;
  }
  body_ = nullptr;
}
inline const ::HPR_MsgBody& HPR_SvrMsg::_internal_body() const {
  const ::HPR_MsgBody* p = body_;
  return p != nullptr ? *p : reinterpret_cast<const ::HPR_MsgBody&>(
      ::_HPR_MsgBody_default_instance_);
}
inline const ::HPR_MsgBody& HPR_SvrMsg::body() const {
  // @@protoc_insertion_point(field_get:HPR_SvrMsg.body)
  return _internal_body();
}
inline void HPR_SvrMsg::unsafe_arena_set_allocated_body(
    ::HPR_MsgBody* body) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(body_);
  }
  body_ = body;
  if (body) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:HPR_SvrMsg.body)
}
inline ::HPR_MsgBody* HPR_SvrMsg::release_body() {
  
  ::HPR_MsgBody* temp = body_;
  body_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::HPR_MsgBody* HPR_SvrMsg::unsafe_arena_release_body() {
  // @@protoc_insertion_point(field_release:HPR_SvrMsg.body)
  
  ::HPR_MsgBody* temp = body_;
  body_ = nullptr;
  return temp;
}
inline ::HPR_MsgBody* HPR_SvrMsg::_internal_mutable_body() {
  
  if (body_ == nullptr) {
    auto* p = CreateMaybeMessage<::HPR_MsgBody>(GetArena());
    body_ = p;
  }
  return body_;
}
inline ::HPR_MsgBody* HPR_SvrMsg::mutable_body() {
  // @@protoc_insertion_point(field_mutable:HPR_SvrMsg.body)
  return _internal_mutable_body();
}
inline void HPR_SvrMsg::set_allocated_body(::HPR_MsgBody* body) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete body_;
  }
  if (body) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(body);
    if (message_arena != submessage_arena) {
      body = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, body, submessage_arena);
    }
    
  } else {
    
  }
  body_ = body;
  // @@protoc_insertion_point(field_set_allocated:HPR_SvrMsg.body)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_hmessage_2eproto
