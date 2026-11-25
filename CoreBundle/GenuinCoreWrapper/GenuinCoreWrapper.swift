//
//  GenuinCoreWrapper.swift
//  GenuinCore
//
//  Created by Ankit Gabani on 10/07/25.
//

import GoogleMobileAds

/// Keeps the Google Mobile Ads classes GenuinCore looks up by name in SPM apps.
/// SPM links GMA statically; without a reference (or `-ObjC`) the app's linker drops them.
public enum GenuinGMALinkAnchor {
    public static let classes: [AnyClass] = [
        AdManagerBannerView.self, NativeAdView.self, MediaView.self, AdManagerRequest.self,
        Extras.self, AdLoader.self, NativeAdMediaAdLoaderOptions.self,
    ]
}
