﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.


namespace RuntimeProfiler
{
    typedef enum
    {
        PG_Class = 0
    } ProfileGroup;

    //  We use these id's on reports so please don't remove or move these
    //  definitions.  Add any new id's immediately preceding ProfId_Size
    //  since it's used to determine the size of this list.
    typedef enum
    {
        ProfId_ColorPicker = 0,
        ProfId_NavigationView,
        ProfId_ParallaxView,
        ProfId_PersonPicture,
        ProfId_RefreshContainer,
        ProfId_RefreshVisualizer,
        ProfId_RatingControl,
        ProfId_SwipeControl,
        ProfId_SwipeItem,
        ProfId_TreeView,
        ProfId_TwoPaneView,
        ProfId_Reveal,
        ProfId_Acrylic,
        ProfId_SplitButton,
        ProfId_DropDownButton,
        ProfId_CommandBarFlyout,
        ProfId_TextCommandBarFlyout,
        ProfId_RadioButtons,
        ProfId_RadioMenuFlyoutItem,
        ProfId_ItemsRepeater,
        ProfId_NonVirtualizingLayout,
        ProfId_StackLayout,
        ProfId_UniformGridLayout,
        ProfId_VirtualizingLayout,
        ProfId_TeachingTip,
        ProfId_Size
    } ProfilerClassId;

    void FireEvent(bool Suspend) noexcept;
    void RegisterMethod(ProfileGroup group, UINT16 TypeIndex, UINT16 MethodIndex, volatile LONG *Count) noexcept;
}

#define __RP_Marker_ClassById(typeindex) \
    { \
        __pragma (warning ( suppress : 28112)) \
        static volatile LONG __RuntimeProfiler_Counter = -1; \
        if (0 == ::InterlockedIncrement(&__RuntimeProfiler_Counter)) \
        { \
            RuntimeProfiler::RegisterMethod(RuntimeProfiler::PG_Class, (UINT16)typeindex, 9999, &__RuntimeProfiler_Counter); \
        } \
    }
    

