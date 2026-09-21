//
//  PAGBiddingRequest.h
//  Pangle Ads SDK
//
//  Copyright 2025 ByteDance Ltd. All rights reserved.
//

#import <PAGAdSDK/PAGAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAGBiddingRequest : NSObject

/// The unique identifier of  ad.
@property (nonatomic, copy, nullable) NSString *slotID;
/// Banner ad size.
@property (nonatomic, assign) PAGBannerAdSize bannerSize;
/// The mediation adx id.
@property (nonatomic, copy, nullable) NSString *adxID;

@end

NS_ASSUME_NONNULL_END
