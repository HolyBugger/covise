/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "network.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace
{

const ::google::protobuf::Descriptor *Marker_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection *
    Marker_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor *Marker_MODE_descriptor_ = NULL;
const ::google::protobuf::Descriptor *DataSet_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection *
    DataSet_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor *DataSet_DATASET_descriptor_ = NULL;

} // namespace

void protobuf_AssignDesc_network_2eproto()
{
    protobuf_AddDesc_network_2eproto();
    const ::google::protobuf::FileDescriptor *file = ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
        "network.proto");
    GOOGLE_CHECK(file != NULL);
    Marker_descriptor_ = file->message_type(0);
    static const int Marker_offsets_[3] = {
        GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Marker, id_),
        GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Marker, mode_),
        GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Marker, matrix_),
    };
    Marker_reflection_ = new ::google::protobuf::internal::GeneratedMessageReflection(
        Marker_descriptor_,
        Marker::default_instance_,
        Marker_offsets_,
        GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Marker, _has_bits_[0]),
        GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Marker, _unknown_fields_),
        -1,
        ::google::protobuf::DescriptorPool::generated_pool(),
        ::google::protobuf::MessageFactory::generated_factory(),
        sizeof(Marker));
    Marker_MODE_descriptor_ = Marker_descriptor_->enum_type(0);
    DataSet_descriptor_ = file->message_type(1);
    static const int DataSet_offsets_[2] = {
        GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataSet, id_),
        GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataSet, dataset_),
    };
    DataSet_reflection_ = new ::google::protobuf::internal::GeneratedMessageReflection(
        DataSet_descriptor_,
        DataSet::default_instance_,
        DataSet_offsets_,
        GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataSet, _has_bits_[0]),
        GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataSet, _unknown_fields_),
        -1,
        ::google::protobuf::DescriptorPool::generated_pool(),
        ::google::protobuf::MessageFactory::generated_factory(),
        sizeof(DataSet));
    DataSet_DATASET_descriptor_ = DataSet_descriptor_->enum_type(0);
}

namespace
{

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce()
{
    ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                                       &protobuf_AssignDesc_network_2eproto);
}

void protobuf_RegisterTypes(const ::std::string &)
{
    protobuf_AssignDescriptorsOnce();
    ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
        Marker_descriptor_, &Marker::default_instance());
    ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
        DataSet_descriptor_, &DataSet::default_instance());
}

} // namespace

void protobuf_ShutdownFile_network_2eproto()
{
    delete Marker::default_instance_;
    delete Marker_reflection_;
    delete DataSet::default_instance_;
    delete DataSet_reflection_;
}

void protobuf_AddDesc_network_2eproto()
{
    static bool already_here = false;
    if (already_here)
        return;
    already_here = true;
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
        "\n\rnetwork.proto\"a\n\006Marker\022\n\n\002id\030\001 \002(\005\022\032\n"
        "\004mode\030\002 \002(\0162\014.Marker.MODE\022\016\n\006matrix\030\003 \003("
        "\002\"\037\n\004MODE\022\n\n\006ENABLE\020\000\022\013\n\007DISABLE\020\001\"_\n\007Da"
        "taSet\022\n\n\002id\030\001 \002(\005\022!\n\007dataSet\030\002 \002(\0162\020.Dat"
        "aSet.DATASET\"%\n\007DATASET\022\014\n\010PRESSURE\020\000\022\014\n"
        "\010VELOCITY\020\001",
        211);
    ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
        "network.proto", &protobuf_RegisterTypes);
    Marker::default_instance_ = new Marker();
    DataSet::default_instance_ = new DataSet();
    Marker::default_instance_->InitAsDefaultInstance();
    DataSet::default_instance_->InitAsDefaultInstance();
    ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_network_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_network_2eproto
{
    StaticDescriptorInitializer_network_2eproto()
    {
        protobuf_AddDesc_network_2eproto();
    }
} static_descriptor_initializer_network_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor *Marker_MODE_descriptor()
{
    protobuf_AssignDescriptorsOnce();
    return Marker_MODE_descriptor_;
}
bool Marker_MODE_IsValid(int value)
{
    switch (value)
    {
    case 0:
    case 1:
        return true;
    default:
        return false;
    }
}

#ifndef _MSC_VER
const Marker_MODE Marker::ENABLE;
const Marker_MODE Marker::DISABLE;
const Marker_MODE Marker::MODE_MIN;
const Marker_MODE Marker::MODE_MAX;
const int Marker::MODE_ARRAYSIZE;
#endif // _MSC_VER
#ifndef _MSC_VER
const int Marker::kIdFieldNumber;
const int Marker::kModeFieldNumber;
const int Marker::kMatrixFieldNumber;
#endif // !_MSC_VER

Marker::Marker()
    : ::google::protobuf::Message()
{
    SharedCtor();
}

void Marker::InitAsDefaultInstance()
{
}

Marker::Marker(const Marker &from)
    : ::google::protobuf::Message()
{
    SharedCtor();
    MergeFrom(from);
}

void Marker::SharedCtor()
{
    _cached_size_ = 0;
    id_ = 0;
    mode_ = 0;
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Marker::~Marker()
{
    SharedDtor();
}

void Marker::SharedDtor()
{
    if (this != default_instance_)
    {
    }
}

void Marker::SetCachedSize(int size) const
{
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor *Marker::descriptor()
{
    protobuf_AssignDescriptorsOnce();
    return Marker_descriptor_;
}

const Marker &Marker::default_instance()
{
    if (default_instance_ == NULL)
        protobuf_AddDesc_network_2eproto();
    return *default_instance_;
}

Marker *Marker::default_instance_ = NULL;

Marker *Marker::New() const
{
    return new Marker;
}

void Marker::Clear()
{
    if (_has_bits_[0 / 32] & (0xffu << (0 % 32)))
    {
        id_ = 0;
        mode_ = 0;
    }
    matrix_.Clear();
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
    mutable_unknown_fields()->Clear();
}

bool Marker::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream *input)
{
#define DO_(EXPRESSION) \
    if (!(EXPRESSION))  \
    return false
    ::google::protobuf::uint32 tag;
    while ((tag = input->ReadTag()) != 0)
    {
        switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag))
        {
        // required int32 id = 1;
        case 1:
        {
            if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) == ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT)
            {
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive< ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                    input, &id_)));
                set_has_id();
            }
            else
            {
                goto handle_uninterpreted;
            }
            if (input->ExpectTag(16))
                goto parse_mode;
            break;
        }

        // required .Marker.MODE mode = 2;
        case 2:
        {
            if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) == ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT)
            {
            parse_mode:
                int value;
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                    input, &value)));
                if (::Marker_MODE_IsValid(value))
                {
                    set_mode(static_cast< ::Marker_MODE>(value));
                }
                else
                {
                    mutable_unknown_fields()->AddVarint(2, value);
                }
            }
            else
            {
                goto handle_uninterpreted;
            }
            if (input->ExpectTag(29))
                goto parse_matrix;
            break;
        }

        // repeated float matrix = 3;
        case 3:
        {
            if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) == ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32)
            {
            parse_matrix:
                DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                    1, 29, input, this->mutable_matrix())));
            }
            else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                     == ::google::protobuf::internal::WireFormatLite::
                            WIRETYPE_LENGTH_DELIMITED)
            {
                DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                    input, this->mutable_matrix())));
            }
            else
            {
                goto handle_uninterpreted;
            }
            if (input->ExpectTag(29))
                goto parse_matrix;
            if (input->ExpectAtEnd())
                return true;
            break;
        }

        default:
        {
        handle_uninterpreted:
            if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) == ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP)
            {
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

void Marker::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream *output) const
{
    // required int32 id = 1;
    if (has_id())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
    }

    // required .Marker.MODE mode = 2;
    if (has_mode())
    {
        ::google::protobuf::internal::WireFormatLite::WriteEnum(
            2, this->mode(), output);
    }

    // repeated float matrix = 3;
    for (int i = 0; i < this->matrix_size(); i++)
    {
        ::google::protobuf::internal::WireFormatLite::WriteFloat(
            3, this->matrix(i), output);
    }

    if (!unknown_fields().empty())
    {
        ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
            unknown_fields(), output);
    }
}

::google::protobuf::uint8 *Marker::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8 *target) const
{
    // required int32 id = 1;
    if (has_id())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
    }

    // required .Marker.MODE mode = 2;
    if (has_mode())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
            2, this->mode(), target);
    }

    // repeated float matrix = 3;
    for (int i = 0; i < this->matrix_size(); i++)
    {
        target = ::google::protobuf::internal::WireFormatLite::
            WriteFloatToArray(3, this->matrix(i), target);
    }

    if (!unknown_fields().empty())
    {
        target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
            unknown_fields(), target);
    }
    return target;
}

int Marker::ByteSize() const
{
    int total_size = 0;

    if (_has_bits_[0 / 32] & (0xffu << (0 % 32)))
    {
        // required int32 id = 1;
        if (has_id())
        {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(
                                  this->id());
        }

        // required .Marker.MODE mode = 2;
        if (has_mode())
        {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::EnumSize(this->mode());
        }
    }
    // repeated float matrix = 3;
    {
        int data_size = 0;
        data_size = 4 * this->matrix_size();
        total_size += 1 * this->matrix_size() + data_size;
    }

    if (!unknown_fields().empty())
    {
        total_size += ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
            unknown_fields());
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = total_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    return total_size;
}

void Marker::MergeFrom(const ::google::protobuf::Message &from)
{
    GOOGLE_CHECK_NE(&from, this);
    const Marker *source = ::google::protobuf::internal::dynamic_cast_if_available<const Marker *>(
        &from);
    if (source == NULL)
    {
        ::google::protobuf::internal::ReflectionOps::Merge(from, this);
    }
    else
    {
        MergeFrom(*source);
    }
}

void Marker::MergeFrom(const Marker &from)
{
    GOOGLE_CHECK_NE(&from, this);
    matrix_.MergeFrom(from.matrix_);
    if (from._has_bits_[0 / 32] & (0xffu << (0 % 32)))
    {
        if (from.has_id())
        {
            set_id(from.id());
        }
        if (from.has_mode())
        {
            set_mode(from.mode());
        }
    }
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Marker::CopyFrom(const ::google::protobuf::Message &from)
{
    if (&from == this)
        return;
    Clear();
    MergeFrom(from);
}

void Marker::CopyFrom(const Marker &from)
{
    if (&from == this)
        return;
    Clear();
    MergeFrom(from);
}

bool Marker::IsInitialized() const
{
    if ((_has_bits_[0] & 0x00000003) != 0x00000003)
        return false;

    return true;
}

void Marker::Swap(Marker *other)
{
    if (other != this)
    {
        std::swap(id_, other->id_);
        std::swap(mode_, other->mode_);
        matrix_.Swap(&other->matrix_);
        std::swap(_has_bits_[0], other->_has_bits_[0]);
        _unknown_fields_.Swap(&other->_unknown_fields_);
        std::swap(_cached_size_, other->_cached_size_);
    }
}

::google::protobuf::Metadata Marker::GetMetadata() const
{
    protobuf_AssignDescriptorsOnce();
    ::google::protobuf::Metadata metadata;
    metadata.descriptor = Marker_descriptor_;
    metadata.reflection = Marker_reflection_;
    return metadata;
}

// ===================================================================

const ::google::protobuf::EnumDescriptor *DataSet_DATASET_descriptor()
{
    protobuf_AssignDescriptorsOnce();
    return DataSet_DATASET_descriptor_;
}
bool DataSet_DATASET_IsValid(int value)
{
    switch (value)
    {
    case 0:
    case 1:
        return true;
    default:
        return false;
    }
}

#ifndef _MSC_VER
const DataSet_DATASET DataSet::PRESSURE;
const DataSet_DATASET DataSet::VELOCITY;
const DataSet_DATASET DataSet::DATASET_MIN;
const DataSet_DATASET DataSet::DATASET_MAX;
const int DataSet::DATASET_ARRAYSIZE;
#endif // _MSC_VER
#ifndef _MSC_VER
const int DataSet::kIdFieldNumber;
const int DataSet::kDataSetFieldNumber;
#endif // !_MSC_VER

DataSet::DataSet()
    : ::google::protobuf::Message()
{
    SharedCtor();
}

void DataSet::InitAsDefaultInstance()
{
}

DataSet::DataSet(const DataSet &from)
    : ::google::protobuf::Message()
{
    SharedCtor();
    MergeFrom(from);
}

void DataSet::SharedCtor()
{
    _cached_size_ = 0;
    id_ = 0;
    dataset_ = 0;
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DataSet::~DataSet()
{
    SharedDtor();
}

void DataSet::SharedDtor()
{
    if (this != default_instance_)
    {
    }
}

void DataSet::SetCachedSize(int size) const
{
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor *DataSet::descriptor()
{
    protobuf_AssignDescriptorsOnce();
    return DataSet_descriptor_;
}

const DataSet &DataSet::default_instance()
{
    if (default_instance_ == NULL)
        protobuf_AddDesc_network_2eproto();
    return *default_instance_;
}

DataSet *DataSet::default_instance_ = NULL;

DataSet *DataSet::New() const
{
    return new DataSet;
}

void DataSet::Clear()
{
    if (_has_bits_[0 / 32] & (0xffu << (0 % 32)))
    {
        id_ = 0;
        dataset_ = 0;
    }
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
    mutable_unknown_fields()->Clear();
}

bool DataSet::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream *input)
{
#define DO_(EXPRESSION) \
    if (!(EXPRESSION))  \
    return false
    ::google::protobuf::uint32 tag;
    while ((tag = input->ReadTag()) != 0)
    {
        switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag))
        {
        // required int32 id = 1;
        case 1:
        {
            if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) == ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT)
            {
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive< ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                    input, &id_)));
                set_has_id();
            }
            else
            {
                goto handle_uninterpreted;
            }
            if (input->ExpectTag(16))
                goto parse_dataSet;
            break;
        }

        // required .DataSet.DATASET dataSet = 2;
        case 2:
        {
            if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) == ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT)
            {
            parse_dataSet:
                int value;
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                    input, &value)));
                if (::DataSet_DATASET_IsValid(value))
                {
                    set_dataset(static_cast< ::DataSet_DATASET>(value));
                }
                else
                {
                    mutable_unknown_fields()->AddVarint(2, value);
                }
            }
            else
            {
                goto handle_uninterpreted;
            }
            if (input->ExpectAtEnd())
                return true;
            break;
        }

        default:
        {
        handle_uninterpreted:
            if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) == ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP)
            {
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

void DataSet::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream *output) const
{
    // required int32 id = 1;
    if (has_id())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
    }

    // required .DataSet.DATASET dataSet = 2;
    if (has_dataset())
    {
        ::google::protobuf::internal::WireFormatLite::WriteEnum(
            2, this->dataset(), output);
    }

    if (!unknown_fields().empty())
    {
        ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
            unknown_fields(), output);
    }
}

::google::protobuf::uint8 *DataSet::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8 *target) const
{
    // required int32 id = 1;
    if (has_id())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
    }

    // required .DataSet.DATASET dataSet = 2;
    if (has_dataset())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
            2, this->dataset(), target);
    }

    if (!unknown_fields().empty())
    {
        target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
            unknown_fields(), target);
    }
    return target;
}

int DataSet::ByteSize() const
{
    int total_size = 0;

    if (_has_bits_[0 / 32] & (0xffu << (0 % 32)))
    {
        // required int32 id = 1;
        if (has_id())
        {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(
                                  this->id());
        }

        // required .DataSet.DATASET dataSet = 2;
        if (has_dataset())
        {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::EnumSize(this->dataset());
        }
    }
    if (!unknown_fields().empty())
    {
        total_size += ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
            unknown_fields());
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = total_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    return total_size;
}

void DataSet::MergeFrom(const ::google::protobuf::Message &from)
{
    GOOGLE_CHECK_NE(&from, this);
    const DataSet *source = ::google::protobuf::internal::dynamic_cast_if_available<const DataSet *>(
        &from);
    if (source == NULL)
    {
        ::google::protobuf::internal::ReflectionOps::Merge(from, this);
    }
    else
    {
        MergeFrom(*source);
    }
}

void DataSet::MergeFrom(const DataSet &from)
{
    GOOGLE_CHECK_NE(&from, this);
    if (from._has_bits_[0 / 32] & (0xffu << (0 % 32)))
    {
        if (from.has_id())
        {
            set_id(from.id());
        }
        if (from.has_dataset())
        {
            set_dataset(from.dataset());
        }
    }
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DataSet::CopyFrom(const ::google::protobuf::Message &from)
{
    if (&from == this)
        return;
    Clear();
    MergeFrom(from);
}

void DataSet::CopyFrom(const DataSet &from)
{
    if (&from == this)
        return;
    Clear();
    MergeFrom(from);
}

bool DataSet::IsInitialized() const
{
    if ((_has_bits_[0] & 0x00000003) != 0x00000003)
        return false;

    return true;
}

void DataSet::Swap(DataSet *other)
{
    if (other != this)
    {
        std::swap(id_, other->id_);
        std::swap(dataset_, other->dataset_);
        std::swap(_has_bits_[0], other->_has_bits_[0]);
        _unknown_fields_.Swap(&other->_unknown_fields_);
        std::swap(_cached_size_, other->_cached_size_);
    }
}

::google::protobuf::Metadata DataSet::GetMetadata() const
{
    protobuf_AssignDescriptorsOnce();
    ::google::protobuf::Metadata metadata;
    metadata.descriptor = DataSet_descriptor_;
    metadata.reflection = DataSet_reflection_;
    return metadata;
}

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)