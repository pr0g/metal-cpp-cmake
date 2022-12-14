//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// QuartzCore/CAMetalLayer.hpp
//
// Copyright 2021, 2022 Alex Betts
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Modifications Notice
//
// 2022/10/02 - Added 'void setPixelFormat(MTL::PixelFormat pixelFormat);'
//              Changes by Tom Hulton-Harrop (pr0g).
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "../Metal/MTLDevice.hpp"

#include "CADefines.hpp"
#include "CAPrivate.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace CA
{
class MetalLayer : public NS::Referencing<MetalLayer>
{
public:
    MTL::Device*      device() const;
    class MetalDrawable*    nextDrawable() const;
    MTL::PixelFormat pixelFormat() const;
    void setPixelFormat(MTL::PixelFormat pixelFormat);
};
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE MTL::Device* CA::MetalLayer::device() const
{
    return Object::sendMessage<MTL::Device*>(this, _CA_PRIVATE_SEL(device));
}

_CA_INLINE CA::MetalDrawable* CA::MetalLayer::nextDrawable() const
{
    return Object::sendMessage<MetalDrawable*>(this, _CA_PRIVATE_SEL(nextDrawable));
}

_CA_INLINE MTL::PixelFormat CA::MetalLayer::pixelFormat() const
{
    return Object::sendMessage<MTL::PixelFormat>(this, _CA_PRIVATE_SEL(pixelFormat));
}

_MTL_INLINE void CA::MetalLayer::setPixelFormat(MTL::PixelFormat pixelFormat)
{
    Object::sendMessage<void>(this, _MTL_PRIVATE_SEL(setPixelFormat_), pixelFormat);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
