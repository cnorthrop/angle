//
// Copyright 2017 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// LoggingAnnotator.cpp: DebugAnnotator implementing logging
//

#include "libANGLE/LoggingAnnotator.h"

#include <platform/Platform.h>

namespace angle
{

void LoggingAnnotator::logMessage(const gl::LogMessage &msg) const
{
    angle::Platform *plat = ANGLEPlatformCurrent();
    if (plat != nullptr)
    {
        switch (msg.getSeverity())
        {
            case gl::LOG_ERR:
                plat->logError(msg.getMessage().c_str());
                break;
            case gl::LOG_WARN:
                plat->logWarning(msg.getMessage().c_str());
                break;
            default:
                UNREACHABLE();
        }
    }
    else
    {
        msg.trace();
    }
}

}  // namespace angle