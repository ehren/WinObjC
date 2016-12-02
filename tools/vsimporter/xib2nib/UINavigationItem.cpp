//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include "UINavigationItem.h"
#include "UINavigationBar.h"

UINavigationItem::UINavigationItem() {
    _title = NULL;
    _leftBarButtonItem = NULL;
    _rightBarButtonItem = NULL;
    _navigationBar = NULL;
}

void UINavigationItem::InitFromXIB(XIBObject* obj) {
    ObjectConverterSwapper::InitFromXIB(obj);
    _title = GetString("IBUITitle", NULL);
    _leftBarButtonItem = FindMember("IBUILeftBarButtonItem");
    _rightBarButtonItem = FindMember("IBUIRightBarButtonItem");
    _leftBarButtonItems = (XIBArray*)obj->FindMember("IBUILeftBarButtonItems");
    _rightBarButtonItems = (XIBArray*)obj->FindMember("IBUIRightBarButtonItems");
    _navigationBar = (UINavigationBar*)FindMember("IBUINavigationBar");

    obj->_outputClassName = "UINavigationItem";
}

void UINavigationItem::InitFromStory(XIBObject* obj) {
    ObjectConverterSwapper::InitFromStory(obj);
    _title = obj->getAttrAndHandle("title");
    _leftBarButtonItems = (XIBArray*)obj->FindMemberAndHandle("leftBarButtonItems");
    _rightBarButtonItems = (XIBArray*)obj->FindMemberAndHandle("leftBarButtonItems");
    _leftBarButtonItem = obj->FindMemberAndHandle("leftBarButtonItem");
    _rightBarButtonItem = obj->FindMemberAndHandle("rightBarButtonItem");

    obj->_outputClassName = "UINavigationItem";
}

void UINavigationItem::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    ObjectConverterSwapper::ConvertStaticMappings(writer, obj);

    if (_title) {
        AddString(writer, "UITitle", _title);
    }

    if (!_leftBarButtonItems) {
        _leftBarButtonItems = new XIBArray();
    }

    if (!_rightBarButtonItems) {
        _rightBarButtonItems = new XIBArray();
    }

    if (_leftBarButtonItems->count()) {
        obj->AddOutputMember(writer, "UILeftBarButtonItems", _leftBarButtonItems);
    }

    if (_rightBarButtonItems->count()) {
        obj->AddOutputMember(writer, "UIRightBarButtonItems", _rightBarButtonItems);
    }

    if (_leftBarButtonItem) {
        AddOutputMember(writer, "UILeftBarButtonItem", _leftBarButtonItem);
    }

    if (_rightBarButtonItem) {
        AddOutputMember(writer, "UIRightBarButtonItem", _rightBarButtonItem);
    }

    if (_navigationBar) {
        AddOutputMember(writer, "UINavigationBar", _navigationBar);
    }
}
