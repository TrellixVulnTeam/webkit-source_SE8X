/*
 * Copyright (C) 2018 Apple Inc. All rights reserved.
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

#if ENABLE(LAYOUT_FORMATTING_CONTEXT)

#include "FloatingState.h"
#include "FormattingContext.h"
#include "LayoutContainer.h"
#include "LayoutUnits.h"
#include <wtf/IsoMalloc.h>

namespace WebCore {

namespace Layout {

class FloatAvoider;
class Box;
class FloatingPair;
class LayoutState;

// FloatingContext is responsible for adjusting the position of a box in the current formatting context
// by taking the floating boxes into account.
class FloatingContext {
    WTF_MAKE_ISO_ALLOCATED(FloatingContext);
public:
    FloatingContext(const FormattingContext&, FloatingState&);

    FloatingState& floatingState() const { return m_floatingState; }

    Point positionForFloat(const Box&) const;
    Optional<Point> positionForFormattingContextRoot(const Box&) const;

    struct ClearancePosition {
        Optional<Position> position;
        Optional<LayoutUnit> clearance;
    };
    ClearancePosition verticalPositionWithClearance(const Box&) const;

    bool isEmpty() const { return m_floatingState.floats().isEmpty(); }

    struct Constraints {
        Optional<PointInContextRoot> left;
        Optional<PointInContextRoot> right;
    };
    Constraints constraints(PositionInContextRoot verticalPosition) const;
    void append(const Box&);
    void remove(const Box&);

private:
    LayoutState& layoutState() const { return m_floatingState.layoutState(); }
    const FormattingContext& formattingContext() const { return m_formattingContext; }
    const Container& root() const { return downcast<Container>(formattingContext().root()); }

    void findPositionForFloatBox(FloatBox&) const;
    void findPositionForFormattingContextRoot(FloatAvoider&) const;

    struct AbsoluteCoordinateValuesForFloatAvoider;
    AbsoluteCoordinateValuesForFloatAvoider absoluteDisplayBoxCoordinates(const Box&) const;
    Display::Box mapToFloatingStateRoot(const Box&) const;
    LayoutUnit mapTopToFloatingStateRoot(const Box&) const;
    Point mapPointFromFormattingContextRootToFloatingStateRoot(Point) const;

    const FormattingContext& m_formattingContext;
    FloatingState& m_floatingState;
};

}
}
#endif
