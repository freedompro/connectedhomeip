/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/****************************************************************************
 * @file
 * @brief Implementation for the Fixed Label Server Cluster
 ***************************************************************************/

#include <app-common/zap-generated/cluster-objects.h>
#include <app-common/zap-generated/ids/Attributes.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <app/AttributeAccessInterface.h>
#include <app/util/attribute-storage.h>
#include <lib/support/CodeUtils.h>
#include <lib/support/logging/CHIPLogging.h>
#include <platform/DeviceInfoProvider.h>
#include <platform/PlatformManager.h>

using namespace chip;
using namespace chip::app;
using namespace chip::app::Clusters;
using namespace chip::app::Clusters::Freedompro;
using namespace chip::app::Clusters::Freedompro::Attributes;

namespace {

class FreedomproAttrAccess : public AttributeAccessInterface
{
public:
    // Register for the Fixed Label cluster on all endpoints.
    FreedomproAttrAccess() : AttributeAccessInterface(Optional<EndpointId>::Missing(), Freedompro::Id) {}

    CHIP_ERROR Read(const ConcreteReadAttributePath & aPath, AttributeValueEncoder & aEncoder) override;

private:
    CHIP_ERROR ReadLabelList(EndpointId endpoint, AttributeValueEncoder & aEncoder);
};

CHIP_ERROR FreedomproAttrAccess::ReadLabelList(EndpointId endpoint, AttributeValueEncoder & aEncoder)
{
    CHIP_ERROR err = CHIP_NO_ERROR;

    // DeviceLayer::DeviceInfoProvider * provider = DeviceLayer::GetDeviceInfoProvider();

    // if (provider)
    // {
    //     DeviceLayer::DeviceInfoProvider::FixedLabelIterator * it = provider->IterateFixedLabel(endpoint);

    //     if (it)
    //     {
    //         err = aEncoder.EncodeList([&it](const auto & encoder) -> CHIP_ERROR {
    //             Freedompro::Structs::LabelStruct::Type fixedlabel;

    //             while (it->Next(fixedlabel))
    //             {
    //                 ReturnErrorOnFailure(encoder.Encode(fixedlabel));
    //             }

    //             return CHIP_NO_ERROR;
    //         });

    //         it->Release();
    //     }
    //     else
    //     {
    //         err = aEncoder.EncodeEmptyList();
    //     }
    // }
    // else
    // {
    //     err = aEncoder.EncodeEmptyList();
    // }

    return err;
}

FreedomproAttrAccess gAttrAccess;

CHIP_ERROR FreedomproAttrAccess::Read(const ConcreteReadAttributePath & aPath, AttributeValueEncoder & aEncoder)
{
    ChipLogError(NotSpecified, "read pippo pluto %d", aPath.mClusterId);
    // LogInfo("read: %d", aPath.mClusterId);
    VerifyOrDie(aPath.mClusterId == Freedompro::Id);

    // switch (aPath.mAttributeId)
    // {
    // case LabelList::Id: {
    //     return ReadLabelList(aPath.mEndpointId, aEncoder);
    // }
    // default: {
    //     break;
    // }
    // }
    return CHIP_NO_ERROR;
}
} // anonymous namespace

void MatterFreedomproPluginServerInitCallback()
{
    registerAttributeAccessOverride(&gAttrAccess);
}
