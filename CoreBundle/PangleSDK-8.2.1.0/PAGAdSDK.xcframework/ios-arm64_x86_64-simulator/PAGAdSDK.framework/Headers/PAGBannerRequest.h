//
//  PAGBannerRequest.h
//  Pangle Ads SDK
//
//  Copyright 2022 ByteDance Ltd. All rights reserved.
//

#import "PAGRequest.h"
#import "PAGAdSize.h"

NS_ASSUME_NONNULL_BEGIN

@interface PAGBannerRequest : PAGRequest

+(instancetype)request UNAVAILABLE_ATTRIBUTE;
+ (instancetype)requestWithBannerSize:(PAGBannerAdSize)bannerSize;

@end

NS_ASSUME_NONNULL_END
