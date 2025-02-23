/*
 * Copyright (C) 2007, 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2009 Torch Mobile Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer. 
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution. 
 * 3.  Neither the name of Apple Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include <wtf/MainThread.h>

#include <wtf/Assertions.h>
#include <wtf/RunLoop.h>
#include <wtf/Threading.h>
#include <wtf/WindowsExtras.h>

namespace WTF {

static HWND threadingWindowHandle;
static UINT threadingFiredMessage;
const LPCWSTR kThreadingWindowClassName = L"ThreadingWindowClass";
static ThreadIdentifier mainThread { 0 };

LRESULT CALLBACK ThreadingWindowWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (message == threadingFiredMessage)
        dispatchFunctionsFromMainThread();
    else
        return DefWindowProc(hWnd, message, wParam, lParam);
    return 0;
}

void initializeMainThreadPlatform()
{
    if (threadingWindowHandle)
        return;

    WNDCLASSW wcex;
    memset(&wcex, 0, sizeof(WNDCLASSW));
    wcex.lpfnWndProc    = ThreadingWindowWndProc;
    wcex.lpszClassName  = kThreadingWindowClassName;
    RegisterClassW(&wcex);

    threadingWindowHandle = CreateWindowW(kThreadingWindowClassName, 0, 0,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, HWND_MESSAGE, 0, 0, 0);
    threadingFiredMessage = RegisterWindowMessageW(L"com.apple.WebKit.MainThreadFired");

    mainThread = Thread::currentID();

    Thread::initializeCurrentThreadInternal("Main Thread");
    RunLoop::registerRunLoopMessageWindowClass();
}

bool isMainThread()
{
    return mainThread == Thread::currentID();
}

bool isMainThreadIfInitialized()
{
    return isMainThread();
}

bool isMainThreadInitialized()
{
    return true;
}

void scheduleDispatchFunctionsOnMainThread()
{
    ASSERT(threadingWindowHandle);
    PostMessage(threadingWindowHandle, threadingFiredMessage, 0, 0);
}

} // namespace WTF
