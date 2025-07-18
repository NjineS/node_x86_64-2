// This file is generated by TypeBuilder_cpp.template.

// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/inspector/protocol/HeapProfiler.h"

#include "src/inspector/protocol/Protocol.h"

#include "../../deps/v8/third_party/inspector_protocol/crdtp/cbor.h"
#include "../../deps/v8/third_party/inspector_protocol/crdtp/find_by_first.h"
#include "../../deps/v8/third_party/inspector_protocol/crdtp/span.h"

namespace v8_inspector {
namespace protocol {
namespace HeapProfiler {

using v8_crdtp::DeserializerState;
using v8_crdtp::ProtocolTypeTraits;

// ------------- Enum values from types.

const char Metainfo::domainName[] = "HeapProfiler";
const char Metainfo::commandPrefix[] = "HeapProfiler.";
const char Metainfo::version[] = "1.3";


V8_CRDTP_BEGIN_DESERIALIZER(SamplingHeapProfileNode)
    V8_CRDTP_DESERIALIZE_FIELD("callFrame", m_callFrame),
    V8_CRDTP_DESERIALIZE_FIELD("children", m_children),
    V8_CRDTP_DESERIALIZE_FIELD("id", m_id),
    V8_CRDTP_DESERIALIZE_FIELD("selfSize", m_selfSize),
V8_CRDTP_END_DESERIALIZER()

V8_CRDTP_BEGIN_SERIALIZER(SamplingHeapProfileNode)
    V8_CRDTP_SERIALIZE_FIELD("callFrame", m_callFrame);
    V8_CRDTP_SERIALIZE_FIELD("selfSize", m_selfSize);
    V8_CRDTP_SERIALIZE_FIELD("id", m_id);
    V8_CRDTP_SERIALIZE_FIELD("children", m_children);
V8_CRDTP_END_SERIALIZER();


V8_CRDTP_BEGIN_DESERIALIZER(SamplingHeapProfileSample)
    V8_CRDTP_DESERIALIZE_FIELD("nodeId", m_nodeId),
    V8_CRDTP_DESERIALIZE_FIELD("ordinal", m_ordinal),
    V8_CRDTP_DESERIALIZE_FIELD("size", m_size),
V8_CRDTP_END_DESERIALIZER()

V8_CRDTP_BEGIN_SERIALIZER(SamplingHeapProfileSample)
    V8_CRDTP_SERIALIZE_FIELD("size", m_size);
    V8_CRDTP_SERIALIZE_FIELD("nodeId", m_nodeId);
    V8_CRDTP_SERIALIZE_FIELD("ordinal", m_ordinal);
V8_CRDTP_END_SERIALIZER();


V8_CRDTP_BEGIN_DESERIALIZER(SamplingHeapProfile)
    V8_CRDTP_DESERIALIZE_FIELD("head", m_head),
    V8_CRDTP_DESERIALIZE_FIELD("samples", m_samples),
V8_CRDTP_END_DESERIALIZER()

V8_CRDTP_BEGIN_SERIALIZER(SamplingHeapProfile)
    V8_CRDTP_SERIALIZE_FIELD("head", m_head);
    V8_CRDTP_SERIALIZE_FIELD("samples", m_samples);
V8_CRDTP_END_SERIALIZER();


// ------------- Enum values from params.


// ------------- Frontend notifications.

void Frontend::addHeapSnapshotChunk(const String& chunk)
{
    if (!frontend_channel_)
        return;
    v8_crdtp::ObjectSerializer serializer;
    serializer.AddField(v8_crdtp::MakeSpan("chunk"), chunk);
    frontend_channel_->SendProtocolNotification(v8_crdtp::CreateNotification("HeapProfiler.addHeapSnapshotChunk", serializer.Finish()));
}

void Frontend::heapStatsUpdate(std::unique_ptr<protocol::Array<int>> statsUpdate)
{
    if (!frontend_channel_)
        return;
    v8_crdtp::ObjectSerializer serializer;
    serializer.AddField(v8_crdtp::MakeSpan("statsUpdate"), statsUpdate);
    frontend_channel_->SendProtocolNotification(v8_crdtp::CreateNotification("HeapProfiler.heapStatsUpdate", serializer.Finish()));
}

void Frontend::lastSeenObjectId(int lastSeenObjectId, double timestamp)
{
    if (!frontend_channel_)
        return;
    v8_crdtp::ObjectSerializer serializer;
    serializer.AddField(v8_crdtp::MakeSpan("lastSeenObjectId"), lastSeenObjectId);
    serializer.AddField(v8_crdtp::MakeSpan("timestamp"), timestamp);
    frontend_channel_->SendProtocolNotification(v8_crdtp::CreateNotification("HeapProfiler.lastSeenObjectId", serializer.Finish()));
}

void Frontend::reportHeapSnapshotProgress(int done, int total, std::optional<bool> finished)
{
    if (!frontend_channel_)
        return;
    v8_crdtp::ObjectSerializer serializer;
    serializer.AddField(v8_crdtp::MakeSpan("done"), done);
    serializer.AddField(v8_crdtp::MakeSpan("total"), total);
    serializer.AddField(v8_crdtp::MakeSpan("finished"), finished);
    frontend_channel_->SendProtocolNotification(v8_crdtp::CreateNotification("HeapProfiler.reportHeapSnapshotProgress", serializer.Finish()));
}

void Frontend::resetProfiles()
{
    if (!frontend_channel_)
        return;
    frontend_channel_->SendProtocolNotification(v8_crdtp::CreateNotification("HeapProfiler.resetProfiles"));
}

void Frontend::flush()
{
    frontend_channel_->FlushProtocolNotifications();
}

void Frontend::sendRawNotification(std::unique_ptr<Serializable> notification)
{
    frontend_channel_->SendProtocolNotification(std::move(notification));
}

// --------------------- Dispatcher.

class DomainDispatcherImpl : public protocol::DomainDispatcher {
public:
    DomainDispatcherImpl(FrontendChannel* frontendChannel, Backend* backend)
        : DomainDispatcher(frontendChannel)
        , m_backend(backend) {}
    ~DomainDispatcherImpl() override { }

    using CallHandler = void (DomainDispatcherImpl::*)(const v8_crdtp::Dispatchable& dispatchable);

    std::function<void(const v8_crdtp::Dispatchable&)> Dispatch(v8_crdtp::span<uint8_t> command_name) override;

    void addInspectedHeapObject(const v8_crdtp::Dispatchable& dispatchable);
    void collectGarbage(const v8_crdtp::Dispatchable& dispatchable);
    void disable(const v8_crdtp::Dispatchable& dispatchable);
    void enable(const v8_crdtp::Dispatchable& dispatchable);
    void getHeapObjectId(const v8_crdtp::Dispatchable& dispatchable);
    void getObjectByHeapObjectId(const v8_crdtp::Dispatchable& dispatchable);
    void getSamplingProfile(const v8_crdtp::Dispatchable& dispatchable);
    void startSampling(const v8_crdtp::Dispatchable& dispatchable);
    void startTrackingHeapObjects(const v8_crdtp::Dispatchable& dispatchable);
    void stopSampling(const v8_crdtp::Dispatchable& dispatchable);
    void stopTrackingHeapObjects(const v8_crdtp::Dispatchable& dispatchable);
    void takeHeapSnapshot(const v8_crdtp::Dispatchable& dispatchable);
 protected:
    Backend* m_backend;
};

namespace {
// This helper method with a static map of command methods (instance methods
// of DomainDispatcherImpl declared just above) by their name is used immediately below,
// in the DomainDispatcherImpl::Dispatch method.
DomainDispatcherImpl::CallHandler CommandByName(v8_crdtp::span<uint8_t> command_name) {
  static auto* commands = [](){
    auto* commands = new std::vector<std::pair<v8_crdtp::span<uint8_t>,
                              DomainDispatcherImpl::CallHandler>>{
    {
          v8_crdtp::SpanFrom("addInspectedHeapObject"),
          &DomainDispatcherImpl::addInspectedHeapObject
    },
    {
          v8_crdtp::SpanFrom("collectGarbage"),
          &DomainDispatcherImpl::collectGarbage
    },
    {
          v8_crdtp::SpanFrom("disable"),
          &DomainDispatcherImpl::disable
    },
    {
          v8_crdtp::SpanFrom("enable"),
          &DomainDispatcherImpl::enable
    },
    {
          v8_crdtp::SpanFrom("getHeapObjectId"),
          &DomainDispatcherImpl::getHeapObjectId
    },
    {
          v8_crdtp::SpanFrom("getObjectByHeapObjectId"),
          &DomainDispatcherImpl::getObjectByHeapObjectId
    },
    {
          v8_crdtp::SpanFrom("getSamplingProfile"),
          &DomainDispatcherImpl::getSamplingProfile
    },
    {
          v8_crdtp::SpanFrom("startSampling"),
          &DomainDispatcherImpl::startSampling
    },
    {
          v8_crdtp::SpanFrom("startTrackingHeapObjects"),
          &DomainDispatcherImpl::startTrackingHeapObjects
    },
    {
          v8_crdtp::SpanFrom("stopSampling"),
          &DomainDispatcherImpl::stopSampling
    },
    {
          v8_crdtp::SpanFrom("stopTrackingHeapObjects"),
          &DomainDispatcherImpl::stopTrackingHeapObjects
    },
    {
          v8_crdtp::SpanFrom("takeHeapSnapshot"),
          &DomainDispatcherImpl::takeHeapSnapshot
    },
    };
    return commands;
  }();
  return v8_crdtp::FindByFirst<DomainDispatcherImpl::CallHandler>(*commands, command_name, nullptr);
}
}  // namespace

std::function<void(const v8_crdtp::Dispatchable&)> DomainDispatcherImpl::Dispatch(v8_crdtp::span<uint8_t> command_name) {
  CallHandler handler = CommandByName(command_name);
  if (!handler) return nullptr;

  return [this, handler](const v8_crdtp::Dispatchable& dispatchable) {
    (this->*handler)(dispatchable);
  };
}


namespace {

struct addInspectedHeapObjectParams : public v8_crdtp::DeserializableProtocolObject<addInspectedHeapObjectParams> {
    String heapObjectId;
    DECLARE_DESERIALIZATION_SUPPORT();
};

V8_CRDTP_BEGIN_DESERIALIZER(addInspectedHeapObjectParams)
    V8_CRDTP_DESERIALIZE_FIELD("heapObjectId", heapObjectId),
V8_CRDTP_END_DESERIALIZER()

}  // namespace

void DomainDispatcherImpl::addInspectedHeapObject(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.
    auto deserializer = v8_crdtp::DeferredMessage::FromSpan(dispatchable.Params())->MakeDeserializer();
    addInspectedHeapObjectParams params;
    if (!addInspectedHeapObjectParams::Deserialize(&deserializer, &params)) {
      ReportInvalidParams(dispatchable, deserializer);
      return;
    }

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->addInspectedHeapObject(params.heapObjectId);
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.addInspectedHeapObject"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

class CollectGarbageCallbackImpl : public Backend::CollectGarbageCallback, public DomainDispatcher::Callback {
public:
    CollectGarbageCallbackImpl(std::unique_ptr<DomainDispatcher::WeakPtr> backendImpl, int callId, v8_crdtp::span<uint8_t> message)
        : DomainDispatcher::Callback(std::move(backendImpl), callId,
v8_crdtp::SpanFrom("HeapProfiler.collectGarbage"), message) { }

    void sendSuccess() override
    {
        v8_crdtp::ObjectSerializer serializer;
        sendIfActive(serializer.Finish(), DispatchResponse::Success());
    }

    void fallThrough() override
    {
        fallThroughIfActive();
    }

    void sendFailure(const DispatchResponse& response) override
    {
        DCHECK(response.IsError());
        sendIfActive(nullptr, response);
    }
};

namespace {


}  // namespace

void DomainDispatcherImpl::collectGarbage(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.

    m_backend->collectGarbage(std::make_unique<CollectGarbageCallbackImpl>(weakPtr(), dispatchable.CallId(), dispatchable.Serialized()));
}

namespace {


}  // namespace

void DomainDispatcherImpl::disable(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->disable();
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.disable"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

namespace {


}  // namespace

void DomainDispatcherImpl::enable(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->enable();
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.enable"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

namespace {

struct getHeapObjectIdParams : public v8_crdtp::DeserializableProtocolObject<getHeapObjectIdParams> {
    String objectId;
    DECLARE_DESERIALIZATION_SUPPORT();
};

V8_CRDTP_BEGIN_DESERIALIZER(getHeapObjectIdParams)
    V8_CRDTP_DESERIALIZE_FIELD("objectId", objectId),
V8_CRDTP_END_DESERIALIZER()

}  // namespace

void DomainDispatcherImpl::getHeapObjectId(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.
    auto deserializer = v8_crdtp::DeferredMessage::FromSpan(dispatchable.Params())->MakeDeserializer();
    getHeapObjectIdParams params;
    if (!getHeapObjectIdParams::Deserialize(&deserializer, &params)) {
      ReportInvalidParams(dispatchable, deserializer);
      return;
    }
    // Declare output parameters.
    String out_heapSnapshotObjectId;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->getHeapObjectId(params.objectId, &out_heapSnapshotObjectId);
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.getHeapObjectId"), dispatchable.Serialized());
        return;
    }
      if (weak->get()) {
        std::unique_ptr<v8_crdtp::Serializable> result;
        if (response.IsSuccess()) {
          v8_crdtp::ObjectSerializer serializer;
          serializer.AddField(v8_crdtp::MakeSpan("heapSnapshotObjectId"), out_heapSnapshotObjectId);
          result = serializer.Finish();
        } else {
          result = Serializable::From({});
        }
        weak->get()->sendResponse(dispatchable.CallId(), response, std::move(result));
      }
    return;
}

namespace {

struct getObjectByHeapObjectIdParams : public v8_crdtp::DeserializableProtocolObject<getObjectByHeapObjectIdParams> {
    String objectId;
    std::optional<String> objectGroup;
    DECLARE_DESERIALIZATION_SUPPORT();
};

V8_CRDTP_BEGIN_DESERIALIZER(getObjectByHeapObjectIdParams)
    V8_CRDTP_DESERIALIZE_FIELD_OPT("objectGroup", objectGroup),
    V8_CRDTP_DESERIALIZE_FIELD("objectId", objectId),
V8_CRDTP_END_DESERIALIZER()

}  // namespace

void DomainDispatcherImpl::getObjectByHeapObjectId(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.
    auto deserializer = v8_crdtp::DeferredMessage::FromSpan(dispatchable.Params())->MakeDeserializer();
    getObjectByHeapObjectIdParams params;
    if (!getObjectByHeapObjectIdParams::Deserialize(&deserializer, &params)) {
      ReportInvalidParams(dispatchable, deserializer);
      return;
    }
    // Declare output parameters.
    std::unique_ptr<protocol::Runtime::RemoteObject> out_result;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->getObjectByHeapObjectId(params.objectId, std::move(params.objectGroup), &out_result);
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.getObjectByHeapObjectId"), dispatchable.Serialized());
        return;
    }
      if (weak->get()) {
        std::unique_ptr<v8_crdtp::Serializable> result;
        if (response.IsSuccess()) {
          v8_crdtp::ObjectSerializer serializer;
          serializer.AddField(v8_crdtp::MakeSpan("result"), out_result);
          result = serializer.Finish();
        } else {
          result = Serializable::From({});
        }
        weak->get()->sendResponse(dispatchable.CallId(), response, std::move(result));
      }
    return;
}

namespace {


}  // namespace

void DomainDispatcherImpl::getSamplingProfile(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.
    // Declare output parameters.
    std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfile> out_profile;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->getSamplingProfile(&out_profile);
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.getSamplingProfile"), dispatchable.Serialized());
        return;
    }
      if (weak->get()) {
        std::unique_ptr<v8_crdtp::Serializable> result;
        if (response.IsSuccess()) {
          v8_crdtp::ObjectSerializer serializer;
          serializer.AddField(v8_crdtp::MakeSpan("profile"), out_profile);
          result = serializer.Finish();
        } else {
          result = Serializable::From({});
        }
        weak->get()->sendResponse(dispatchable.CallId(), response, std::move(result));
      }
    return;
}

namespace {

struct startSamplingParams : public v8_crdtp::DeserializableProtocolObject<startSamplingParams> {
    std::optional<double> samplingInterval;
    std::optional<bool> includeObjectsCollectedByMajorGC;
    std::optional<bool> includeObjectsCollectedByMinorGC;
    DECLARE_DESERIALIZATION_SUPPORT();
};

V8_CRDTP_BEGIN_DESERIALIZER(startSamplingParams)
    V8_CRDTP_DESERIALIZE_FIELD_OPT("includeObjectsCollectedByMajorGC", includeObjectsCollectedByMajorGC),
    V8_CRDTP_DESERIALIZE_FIELD_OPT("includeObjectsCollectedByMinorGC", includeObjectsCollectedByMinorGC),
    V8_CRDTP_DESERIALIZE_FIELD_OPT("samplingInterval", samplingInterval),
V8_CRDTP_END_DESERIALIZER()

}  // namespace

void DomainDispatcherImpl::startSampling(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.
    auto deserializer = v8_crdtp::DeferredMessage::FromSpan(dispatchable.Params())->MakeDeserializer();
    startSamplingParams params;
    if (!startSamplingParams::Deserialize(&deserializer, &params)) {
      ReportInvalidParams(dispatchable, deserializer);
      return;
    }

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->startSampling(std::move(params.samplingInterval), std::move(params.includeObjectsCollectedByMajorGC), std::move(params.includeObjectsCollectedByMinorGC));
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.startSampling"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

namespace {

struct startTrackingHeapObjectsParams : public v8_crdtp::DeserializableProtocolObject<startTrackingHeapObjectsParams> {
    std::optional<bool> trackAllocations;
    DECLARE_DESERIALIZATION_SUPPORT();
};

V8_CRDTP_BEGIN_DESERIALIZER(startTrackingHeapObjectsParams)
    V8_CRDTP_DESERIALIZE_FIELD_OPT("trackAllocations", trackAllocations),
V8_CRDTP_END_DESERIALIZER()

}  // namespace

void DomainDispatcherImpl::startTrackingHeapObjects(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.
    auto deserializer = v8_crdtp::DeferredMessage::FromSpan(dispatchable.Params())->MakeDeserializer();
    startTrackingHeapObjectsParams params;
    if (!startTrackingHeapObjectsParams::Deserialize(&deserializer, &params)) {
      ReportInvalidParams(dispatchable, deserializer);
      return;
    }

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->startTrackingHeapObjects(std::move(params.trackAllocations));
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.startTrackingHeapObjects"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

namespace {


}  // namespace

void DomainDispatcherImpl::stopSampling(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.
    // Declare output parameters.
    std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfile> out_profile;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->stopSampling(&out_profile);
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.stopSampling"), dispatchable.Serialized());
        return;
    }
      if (weak->get()) {
        std::unique_ptr<v8_crdtp::Serializable> result;
        if (response.IsSuccess()) {
          v8_crdtp::ObjectSerializer serializer;
          serializer.AddField(v8_crdtp::MakeSpan("profile"), out_profile);
          result = serializer.Finish();
        } else {
          result = Serializable::From({});
        }
        weak->get()->sendResponse(dispatchable.CallId(), response, std::move(result));
      }
    return;
}

namespace {

struct stopTrackingHeapObjectsParams : public v8_crdtp::DeserializableProtocolObject<stopTrackingHeapObjectsParams> {
    std::optional<bool> reportProgress;
    std::optional<bool> treatGlobalObjectsAsRoots;
    std::optional<bool> captureNumericValue;
    std::optional<bool> exposeInternals;
    DECLARE_DESERIALIZATION_SUPPORT();
};

V8_CRDTP_BEGIN_DESERIALIZER(stopTrackingHeapObjectsParams)
    V8_CRDTP_DESERIALIZE_FIELD_OPT("captureNumericValue", captureNumericValue),
    V8_CRDTP_DESERIALIZE_FIELD_OPT("exposeInternals", exposeInternals),
    V8_CRDTP_DESERIALIZE_FIELD_OPT("reportProgress", reportProgress),
    V8_CRDTP_DESERIALIZE_FIELD_OPT("treatGlobalObjectsAsRoots", treatGlobalObjectsAsRoots),
V8_CRDTP_END_DESERIALIZER()

}  // namespace

void DomainDispatcherImpl::stopTrackingHeapObjects(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.
    auto deserializer = v8_crdtp::DeferredMessage::FromSpan(dispatchable.Params())->MakeDeserializer();
    stopTrackingHeapObjectsParams params;
    if (!stopTrackingHeapObjectsParams::Deserialize(&deserializer, &params)) {
      ReportInvalidParams(dispatchable, deserializer);
      return;
    }

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->stopTrackingHeapObjects(std::move(params.reportProgress), std::move(params.treatGlobalObjectsAsRoots), std::move(params.captureNumericValue), std::move(params.exposeInternals));
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.stopTrackingHeapObjects"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

class TakeHeapSnapshotCallbackImpl : public Backend::TakeHeapSnapshotCallback, public DomainDispatcher::Callback {
public:
    TakeHeapSnapshotCallbackImpl(std::unique_ptr<DomainDispatcher::WeakPtr> backendImpl, int callId, v8_crdtp::span<uint8_t> message)
        : DomainDispatcher::Callback(std::move(backendImpl), callId,
v8_crdtp::SpanFrom("HeapProfiler.takeHeapSnapshot"), message) { }

    void sendSuccess() override
    {
        v8_crdtp::ObjectSerializer serializer;
        sendIfActive(serializer.Finish(), DispatchResponse::Success());
    }

    void fallThrough() override
    {
        fallThroughIfActive();
    }

    void sendFailure(const DispatchResponse& response) override
    {
        DCHECK(response.IsError());
        sendIfActive(nullptr, response);
    }
};

namespace {

struct takeHeapSnapshotParams : public v8_crdtp::DeserializableProtocolObject<takeHeapSnapshotParams> {
    std::optional<bool> reportProgress;
    std::optional<bool> treatGlobalObjectsAsRoots;
    std::optional<bool> captureNumericValue;
    std::optional<bool> exposeInternals;
    DECLARE_DESERIALIZATION_SUPPORT();
};

V8_CRDTP_BEGIN_DESERIALIZER(takeHeapSnapshotParams)
    V8_CRDTP_DESERIALIZE_FIELD_OPT("captureNumericValue", captureNumericValue),
    V8_CRDTP_DESERIALIZE_FIELD_OPT("exposeInternals", exposeInternals),
    V8_CRDTP_DESERIALIZE_FIELD_OPT("reportProgress", reportProgress),
    V8_CRDTP_DESERIALIZE_FIELD_OPT("treatGlobalObjectsAsRoots", treatGlobalObjectsAsRoots),
V8_CRDTP_END_DESERIALIZER()

}  // namespace

void DomainDispatcherImpl::takeHeapSnapshot(const v8_crdtp::Dispatchable& dispatchable)
{
    // Prepare input parameters.
    auto deserializer = v8_crdtp::DeferredMessage::FromSpan(dispatchable.Params())->MakeDeserializer();
    takeHeapSnapshotParams params;
    if (!takeHeapSnapshotParams::Deserialize(&deserializer, &params)) {
      ReportInvalidParams(dispatchable, deserializer);
      return;
    }

    m_backend->takeHeapSnapshot(std::move(params.reportProgress), std::move(params.treatGlobalObjectsAsRoots), std::move(params.captureNumericValue), std::move(params.exposeInternals), std::make_unique<TakeHeapSnapshotCallbackImpl>(weakPtr(), dispatchable.CallId(), dispatchable.Serialized()));
}

namespace {
// This helper method (with a static map of redirects) is used from Dispatcher::wire
// immediately below.
const std::vector<std::pair<v8_crdtp::span<uint8_t>, v8_crdtp::span<uint8_t>>>& SortedRedirects() {
  static auto* redirects = [](){
    auto* redirects = new std::vector<std::pair<v8_crdtp::span<uint8_t>, v8_crdtp::span<uint8_t>>>{
    };
    return redirects;
  }();
  return *redirects;
}
}  // namespace

// static
void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
{
    auto dispatcher = std::make_unique<DomainDispatcherImpl>(uber->channel(), backend);
    uber->WireBackend(v8_crdtp::SpanFrom("HeapProfiler"), SortedRedirects(), std::move(dispatcher));
}

} // HeapProfiler
} // namespace v8_inspector
} // namespace protocol
