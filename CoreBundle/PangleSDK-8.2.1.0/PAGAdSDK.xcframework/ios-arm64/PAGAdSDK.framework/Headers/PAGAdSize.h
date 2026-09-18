//
//  PAGAdSize.h
//  Pangle Ads SDK
//
//  Copyright 2022 ByteDance Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

struct PAGAdSize {
    CGSize size;
    NSInteger type;
    CGFloat maxHeight;
};

typedef struct PAGAdSize PAGBannerAdSize;

CG_EXTERN PAGBannerAdSize const kPAGBannerSize320x50;
CG_EXTERN PAGBannerAdSize const kPAGBannerSize300x250;
/// Only for iPad banner ad
CG_EXTERN PAGBannerAdSize const kPAGBannerSize728x90;

// MARK: - Anchored Banner Size

/// Returns a PAGBannerAdSize with the given width and  height to create a banner ad.
/// - Parameter width: view width
CG_EXTERN PAGBannerAdSize PAGCurrentOrientationAnchoredAdaptiveBannerAdSizeWithWidth(CGFloat width);

// MARK: - Inline Adaptive Banner Size

/// Returns a PAGBannerAdSize with the given width and the device's current orientation height. This ad size
/// allows Pangle servers to choose an optimal ad size less than or equal to the returned size. The
/// exact size of the ad returned is passed through the banner's ad size delegate and is indicated
/// by the banner's intrinsicContentSize. This ad size is most suitable for ads intended for scroll
/// views.
CG_EXTERN PAGBannerAdSize PAGCurrentOrientationInlineAdaptiveBannerAdSizeWithWidth(CGFloat width);

/// Returns a PAGBannerAdSize with the given width and max height. This ad size allows Pangle servers to
/// choose an optimal ad size less than or equal to the returned size. The exact size of the ad
/// returned is passed through the banner's ad size delegate and is indicated by the banner's
/// intrinsicContentSize. This ad size is most suitable for ads intended for scroll views.
///
/// @param width The ad width.
/// @param maxHeight The maximum height a loaded ad will have. Must be at least 32 px, but a max
/// height of 50 px or higher is recommended.
CG_EXTERN PAGBannerAdSize PAGInlineAdaptiveBannerAdSizeWithWidthAndMaxHeight(CGFloat width, CGFloat maxHeight);

