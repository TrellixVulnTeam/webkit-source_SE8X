/*
 * Copyright (C) 2016-2019 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "SVGLength.h"
#include "SVGValuePropertyList.h"

namespace WebCore {

class SVGLengthList : public SVGValuePropertyList<SVGLength> {
    using Base = SVGValuePropertyList<SVGLength>;
    using Base::Base;

public:
    static Ref<SVGLengthList> create(SVGLengthMode lengthMode = LengthModeOther)
    {
        return adoptRef(*new SVGLengthList(lengthMode));
    }

    static Ref<SVGLengthList> create(SVGPropertyOwner* owner, SVGPropertyAccess access, SVGLengthMode lengthMode)
    {
        return adoptRef(*new SVGLengthList(owner, access, lengthMode));
    }

    static Ref<SVGLengthList> create(const SVGLengthList& other, SVGPropertyAccess access)
    {
        return adoptRef(*new SVGLengthList(other, access));
    }

    SVGLengthMode lengthMode() const { return m_lengthMode; }

    bool parse(const String& value)
    {
        clearItems();

        auto upconvertedCharacters = StringView(value).upconvertedCharacters();
        const UChar* ptr = upconvertedCharacters;
        const UChar* end = ptr + value.length();
        while (ptr < end) {
            const UChar* start = ptr;
            while (ptr < end && *ptr != ',' && !isSVGSpace(*ptr))
                ptr++;
            if (ptr == start)
                break;

            String valueString(start, ptr - start);
            SVGLengthValue value(m_lengthMode);
            if (value.setValueAsString(valueString).hasException())
                break;

            append(SVGLength::create(value));
            skipOptionalSVGSpacesOrDelimiter(ptr, end);
        }

        return ptr == end;
    }

    String valueAsString() const override
    {
        StringBuilder builder;

        for (const auto& length : m_items) {
            if (builder.length())
                builder.append(' ');

            builder.append(length->value().valueAsString());
        }

        return builder.toString();
    }
    
private:
    SVGLengthList(SVGLengthMode lengthMode)
        : m_lengthMode(lengthMode)
    {
    }

    SVGLengthList(SVGPropertyOwner* owner, SVGPropertyAccess access, SVGLengthMode lengthMode)
        : Base(owner, access)
        , m_lengthMode(lengthMode)
    {
    }

    SVGLengthList(const SVGLengthList& other, SVGPropertyAccess access)
        : Base(other, access)
        , m_lengthMode(other.lengthMode())
    {
    }

    SVGLengthMode m_lengthMode { LengthModeOther };
};

} // namespace WebCore
