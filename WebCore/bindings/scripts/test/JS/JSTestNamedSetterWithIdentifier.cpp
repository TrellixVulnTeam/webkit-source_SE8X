/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSTestNamedSetterWithIdentifier.h"

#include "JSDOMAbstractOperations.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "ScriptExecutionContext.h"
#include <JavaScriptCore/FunctionPrototype.h>
#include <JavaScriptCore/HeapAnalyzer.h>
#include <JavaScriptCore/JSCInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>


namespace WebCore {
using namespace JSC;

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsTestNamedSetterWithIdentifierPrototypeFunctionNamedSetter(JSC::ExecState*);

// Attributes

JSC::EncodedJSValue jsTestNamedSetterWithIdentifierConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestNamedSetterWithIdentifierConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);

class JSTestNamedSetterWithIdentifierPrototype : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestNamedSetterWithIdentifierPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestNamedSetterWithIdentifierPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestNamedSetterWithIdentifierPrototype>(vm.heap)) JSTestNamedSetterWithIdentifierPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestNamedSetterWithIdentifierPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};

using JSTestNamedSetterWithIdentifierConstructor = JSDOMConstructorNotConstructable<JSTestNamedSetterWithIdentifier>;

template<> JSValue JSTestNamedSetterWithIdentifierConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestNamedSetterWithIdentifierConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestNamedSetterWithIdentifier::prototype(vm, globalObject), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(vm, String("TestNamedSetterWithIdentifier"_s)), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

template<> const ClassInfo JSTestNamedSetterWithIdentifierConstructor::s_info = { "TestNamedSetterWithIdentifier", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestNamedSetterWithIdentifierConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestNamedSetterWithIdentifierPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestNamedSetterWithIdentifierConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestNamedSetterWithIdentifierConstructor) } },
    { "namedSetter", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestNamedSetterWithIdentifierPrototypeFunctionNamedSetter), (intptr_t) (2) } },
};

const ClassInfo JSTestNamedSetterWithIdentifierPrototype::s_info = { "TestNamedSetterWithIdentifierPrototype", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestNamedSetterWithIdentifierPrototype) };

void JSTestNamedSetterWithIdentifierPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestNamedSetterWithIdentifier::info(), JSTestNamedSetterWithIdentifierPrototypeTableValues, *this);
}

const ClassInfo JSTestNamedSetterWithIdentifier::s_info = { "TestNamedSetterWithIdentifier", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestNamedSetterWithIdentifier) };

JSTestNamedSetterWithIdentifier::JSTestNamedSetterWithIdentifier(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestNamedSetterWithIdentifier>&& impl)
    : JSDOMWrapper<TestNamedSetterWithIdentifier>(structure, globalObject, WTFMove(impl))
{
}

void JSTestNamedSetterWithIdentifier::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

}

JSObject* JSTestNamedSetterWithIdentifier::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestNamedSetterWithIdentifierPrototype::create(vm, &globalObject, JSTestNamedSetterWithIdentifierPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestNamedSetterWithIdentifier::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestNamedSetterWithIdentifier>(vm, globalObject);
}

JSValue JSTestNamedSetterWithIdentifier::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestNamedSetterWithIdentifierConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestNamedSetterWithIdentifier::destroy(JSC::JSCell* cell)
{
    JSTestNamedSetterWithIdentifier* thisObject = static_cast<JSTestNamedSetterWithIdentifier*>(cell);
    thisObject->JSTestNamedSetterWithIdentifier::~JSTestNamedSetterWithIdentifier();
}

bool JSTestNamedSetterWithIdentifier::getOwnPropertySlot(JSObject* object, ExecState* state, PropertyName propertyName, PropertySlot& slot)
{
    auto* thisObject = jsCast<JSTestNamedSetterWithIdentifier*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    using GetterIDLType = IDLDOMString;
    auto getterFunctor = [] (auto& thisObject, auto propertyName) -> Optional<typename GetterIDLType::ImplementationType> {
        auto result = thisObject.wrapped().namedItem(propertyNameToAtomString(propertyName));
        if (!GetterIDLType::isNullValue(result))
            return typename GetterIDLType::ImplementationType { GetterIDLType::extractValueFromNullable(result) };
        return WTF::nullopt;
    };
    if (auto namedProperty = accessVisibleNamedProperty<OverrideBuiltins::No>(*state, *thisObject, propertyName, getterFunctor)) {
        auto value = toJS<IDLDOMString>(*state, WTFMove(namedProperty.value()));
        slot.setValue(thisObject, static_cast<unsigned>(0), value);
        return true;
    }
    return JSObject::getOwnPropertySlot(object, state, propertyName, slot);
}

bool JSTestNamedSetterWithIdentifier::getOwnPropertySlotByIndex(JSObject* object, ExecState* state, unsigned index, PropertySlot& slot)
{
    VM& vm = state->vm();
    auto* thisObject = jsCast<JSTestNamedSetterWithIdentifier*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    auto propertyName = Identifier::from(vm, index);
    using GetterIDLType = IDLDOMString;
    auto getterFunctor = [] (auto& thisObject, auto propertyName) -> Optional<typename GetterIDLType::ImplementationType> {
        auto result = thisObject.wrapped().namedItem(propertyNameToAtomString(propertyName));
        if (!GetterIDLType::isNullValue(result))
            return typename GetterIDLType::ImplementationType { GetterIDLType::extractValueFromNullable(result) };
        return WTF::nullopt;
    };
    if (auto namedProperty = accessVisibleNamedProperty<OverrideBuiltins::No>(*state, *thisObject, propertyName, getterFunctor)) {
        auto value = toJS<IDLDOMString>(*state, WTFMove(namedProperty.value()));
        slot.setValue(thisObject, static_cast<unsigned>(0), value);
        return true;
    }
    return JSObject::getOwnPropertySlotByIndex(object, state, index, slot);
}

void JSTestNamedSetterWithIdentifier::getOwnPropertyNames(JSObject* object, ExecState* state, PropertyNameArray& propertyNames, EnumerationMode mode)
{
    VM& vm = state->vm();
    auto* thisObject = jsCast<JSTestNamedSetterWithIdentifier*>(object);
    ASSERT_GC_OBJECT_INHERITS(object, info());
    for (auto& propertyName : thisObject->wrapped().supportedPropertyNames())
        propertyNames.add(Identifier::fromString(vm, propertyName));
    JSObject::getOwnPropertyNames(object, state, propertyNames, mode);
}

bool JSTestNamedSetterWithIdentifier::put(JSCell* cell, ExecState* state, PropertyName propertyName, JSValue value, PutPropertySlot& putPropertySlot)
{
    auto* thisObject = jsCast<JSTestNamedSetterWithIdentifier*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());

    if (!propertyName.isSymbol()) {
        PropertySlot slot { thisObject, PropertySlot::InternalMethodType::VMInquiry };
        JSValue prototype = thisObject->getPrototypeDirect(state->vm());
        if (!(prototype.isObject() && asObject(prototype)->getPropertySlot(state, propertyName, slot))) {
            auto throwScope = DECLARE_THROW_SCOPE(state->vm());
            auto nativeValue = convert<IDLDOMString>(*state, value);
            RETURN_IF_EXCEPTION(throwScope, true);
            thisObject->wrapped().namedSetter(propertyNameToString(propertyName), WTFMove(nativeValue));
            return true;
        }
    }

    return JSObject::put(thisObject, state, propertyName, value, putPropertySlot);
}

bool JSTestNamedSetterWithIdentifier::putByIndex(JSCell* cell, ExecState* state, unsigned index, JSValue value, bool shouldThrow)
{
    VM& vm = state->vm();
    auto* thisObject = jsCast<JSTestNamedSetterWithIdentifier*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());

    auto propertyName = Identifier::from(vm, index);
    PropertySlot slot { thisObject, PropertySlot::InternalMethodType::VMInquiry };
    JSValue prototype = thisObject->getPrototypeDirect(vm);
    if (!(prototype.isObject() && asObject(prototype)->getPropertySlot(state, propertyName, slot))) {
        auto throwScope = DECLARE_THROW_SCOPE(state->vm());
        auto nativeValue = convert<IDLDOMString>(*state, value);
        RETURN_IF_EXCEPTION(throwScope, true);
        thisObject->wrapped().namedSetter(propertyNameToString(propertyName), WTFMove(nativeValue));
        return true;
    }

    return JSObject::putByIndex(cell, state, index, value, shouldThrow);
}

bool JSTestNamedSetterWithIdentifier::defineOwnProperty(JSObject* object, ExecState* state, PropertyName propertyName, const PropertyDescriptor& propertyDescriptor, bool shouldThrow)
{
    auto* thisObject = jsCast<JSTestNamedSetterWithIdentifier*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());

    if (!propertyName.isSymbol()) {
        PropertySlot slot { thisObject, PropertySlot::InternalMethodType::VMInquiry };
        if (!JSObject::getOwnPropertySlot(thisObject, state, propertyName, slot)) {
            if (!propertyDescriptor.isDataDescriptor())
                return false;
            auto throwScope = DECLARE_THROW_SCOPE(state->vm());
            auto nativeValue = convert<IDLDOMString>(*state, propertyDescriptor.value());
            RETURN_IF_EXCEPTION(throwScope, true);
            thisObject->wrapped().namedSetter(propertyNameToString(propertyName), WTFMove(nativeValue));
            return true;
        }
    }

    PropertyDescriptor newPropertyDescriptor = propertyDescriptor;
    newPropertyDescriptor.setConfigurable(true);
    return JSObject::defineOwnProperty(object, state, propertyName, newPropertyDescriptor, shouldThrow);
}

template<> inline JSTestNamedSetterWithIdentifier* IDLOperation<JSTestNamedSetterWithIdentifier>::cast(ExecState& state)
{
    return jsDynamicCast<JSTestNamedSetterWithIdentifier*>(state.vm(), state.thisValue());
}

EncodedJSValue jsTestNamedSetterWithIdentifierConstructor(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestNamedSetterWithIdentifierPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(state, throwScope);
    return JSValue::encode(JSTestNamedSetterWithIdentifier::getConstructor(state->vm(), prototype->globalObject()));
}

bool setJSTestNamedSetterWithIdentifierConstructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestNamedSetterWithIdentifierPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype)) {
        throwVMTypeError(state, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return prototype->putDirect(vm, vm.propertyNames->constructor, JSValue::decode(encodedValue));
}

static inline JSC::EncodedJSValue jsTestNamedSetterWithIdentifierPrototypeFunctionNamedSetterBody(JSC::ExecState* state, typename IDLOperation<JSTestNamedSetterWithIdentifier>::ClassParameter castedThis, JSC::ThrowScope& throwScope)
{
    UNUSED_PARAM(state);
    UNUSED_PARAM(throwScope);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(state->argumentCount() < 2))
        return throwVMError(state, throwScope, createNotEnoughArgumentsError(state));
    auto name = convert<IDLDOMString>(*state, state->uncheckedArgument(0));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto value = convert<IDLDOMString>(*state, state->uncheckedArgument(1));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    impl.namedSetter(WTFMove(name), WTFMove(value));
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsTestNamedSetterWithIdentifierPrototypeFunctionNamedSetter(ExecState* state)
{
    return IDLOperation<JSTestNamedSetterWithIdentifier>::call<jsTestNamedSetterWithIdentifierPrototypeFunctionNamedSetterBody>(*state, "namedSetter");
}

void JSTestNamedSetterWithIdentifier::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestNamedSetterWithIdentifier*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestNamedSetterWithIdentifierOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestNamedSetterWithIdentifierOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestNamedSetterWithIdentifier = static_cast<JSTestNamedSetterWithIdentifier*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestNamedSetterWithIdentifier->wrapped(), jsTestNamedSetterWithIdentifier);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestNamedSetterWithIdentifier@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore29TestNamedSetterWithIdentifierE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject* globalObject, Ref<TestNamedSetterWithIdentifier>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl.ptr()));
#if PLATFORM(WIN)
    void* expectedVTablePointer = WTF_PREPARE_VTBL_POINTER_FOR_INSPECTION(__identifier("??_7TestNamedSetterWithIdentifier@WebCore@@6B@"));
#else
    void* expectedVTablePointer = WTF_PREPARE_VTBL_POINTER_FOR_INSPECTION(&_ZTVN7WebCore29TestNamedSetterWithIdentifierE[2]);
#endif

    // If this fails TestNamedSetterWithIdentifier does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(std::is_polymorphic<TestNamedSetterWithIdentifier>::value, "TestNamedSetterWithIdentifier is not polymorphic");

    // If you hit this assertion you either have a use after free bug, or
    // TestNamedSetterWithIdentifier has subclasses. If TestNamedSetterWithIdentifier has subclasses that get passed
    // to toJS() we currently require TestNamedSetterWithIdentifier you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestNamedSetterWithIdentifier>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, TestNamedSetterWithIdentifier& impl)
{
    return wrap(state, globalObject, impl);
}

TestNamedSetterWithIdentifier* JSTestNamedSetterWithIdentifier::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestNamedSetterWithIdentifier*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}