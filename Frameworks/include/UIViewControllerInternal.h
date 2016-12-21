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

#ifndef _UIVIEWCONTROLLERPRIVATE_H_
#define _UIVIEWCONTROLLERPRIVATE_H_

enum ControllerVisibiltyState {
    controllerNotVisible,
    controllerWillAppear,
    controllerWillAppearAnimated,
    controllerVisible,
    controllerWillDisappear,
    controllerWillDisappearAnimated
};

@class WXCPage;

struct UIViewControllerPriv {
    idretaintype(UINavigationItem) navigationItem;
    idretaintype(UITabBarItem) tabBarItem;
    idretaintype(NSArray) toolbarItems;
    idretaintype(UIBarButtonItem) editButtonItem;
    idretaintype(UINavigationController) navigationController;
    idretaintype(UISearchDisplayController) _searchDisplayController;
    StrongId<UIViewController> _presentedViewController;
    StrongId<UIPopoverPresentationController> _popoverPresentationController;
    StrongId<UIPresentationController> _presentationController;
    idretaintype(NSDictionary) _externalObjects;
    __unsafe_unretained UIViewController* _parentViewController;
    __unsafe_unretained UIViewController* _presentingViewController;
    idretaintype(NSString) nibName;
    idretaintype(NSBundle) nibBundle;
    idretaintype(NSString) _title;
    StrongId<UIStoryboard> _storyboard;
    BOOL hasLoaded, isLoading;
    BOOL _isEditing;
    UIInterfaceOrientation _curOrientation;
    BOOL _didSetRotation;
    BOOL _resizeToScreen;
    enum ControllerVisibiltyState _visibility;
    BOOL _wantsFullScreenLayout;
    BOOL _autoresize;
    UIModalPresentationStyle _presentationStyle;
    BOOL _hidesBottomBar;
    UIModalTransitionStyle _modalTransitionStyle;
    StrongId<UIView> _modalOverlayView;
    BOOL _isRootView;
    idretainp<void (^)(void)> _dismissCompletionBlock;
    idretainp<void (^)(void)> _presentCompletionBlock;
    idretaintype(UIViewController) _dismissController;
    CGSize _contentSizeForViewInPopover;
    unsigned _edgesForExtendedLayout;
    BOOL _modalInPopover;
    CGSize _preferredContentSize;

    idretaintype(NSArray) _modalTemplates;
    idretaintype(UIView) view;
    idretaintype(NSMutableArray) _childViewControllers;

    idretaintype(WXCPage) _page;
    idretaintype(NSString) _xamlClassName;
};

@interface _UIViewControllerContextTransitioning : NSObject <UIViewControllerContextTransitioning>
- (instancetype)initWithContainerView:containerView
                         withFromView:oldControllerView
                           withToView:curControllerView
               withFromViewController:oldController
                 withToViewController:curController
                         withAnimator:animator;
@end

@interface UIViewController () {
@public
    struct UIViewControllerPriv* priv;
}

- (void)_notifyViewWillAppear:(BOOL)isAnimated;
- (void)_notifyViewDidAppear:(BOOL)isAnimated;
- (void)_notifyViewWillDisappear:(BOOL)isAnimated;
- (void)_notifyViewDidDisappear:(BOOL)isAnimated;

- (void)_setResizeToScreen:(BOOL)resize;
- (void)_doResizeToScreen;
- (int)_edgesForExtendedLayout;
- (void)_setRotation:(UIInterfaceOrientation)orientation animated:(BOOL)animated;
- (BOOL)_rotationLocked:(UIInterfaceOrientation)curOrientation;
@end

#endif
