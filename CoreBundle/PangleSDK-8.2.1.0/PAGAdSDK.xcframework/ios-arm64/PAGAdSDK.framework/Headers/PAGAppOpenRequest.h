//
//  PAGAppOpenRequest.h
//  Pangle Ads SDK
//
//  Copyright 2022 ByteDance Ltd. All rights reserved.
//

#import "PAGRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface PAGAppOpenRequest : PAGRequest


/// If the ad data is not successfully loaded within the timeout period,
/// a timeout error from the invoked completion handler will be non-nil.
/// default is 3.5s
@property (nonatomic, assign) NSTimeInterval timeout;

@end

NS_ASSUME_NONNULL_END
