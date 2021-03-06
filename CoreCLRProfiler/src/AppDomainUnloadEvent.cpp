// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "AppDomainUnloadEvent.h"

AppDomainUnloadEvent::AppDomainUnloadEvent(int64_t appDomainId, int32_t appDomainFlags, portable_wide_string appDomainName, int32_t appDomainIndex, int16_t clrInstanceId) : EtwEvent(), appDomainId(appDomainId), appDomainFlags(appDomainFlags), appDomainName(std::move(appDomainName)), appDomainIndex(appDomainIndex), clrInstanceId(clrInstanceId)
{
}

void AppDomainUnloadEvent::Serialize(Serializer &t)
{
    EtwEvent::Serialize(t);

    t.Write(this->appDomainId);
    t.Write(this->appDomainFlags);
    t.Write(this->appDomainName);
    t.Write(this->appDomainIndex);
    t.Write(this->clrInstanceId);
}

int32_t AppDomainUnloadEvent::GetEventId()
{
    return 2;
}