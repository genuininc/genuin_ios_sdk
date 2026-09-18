//
//  PAGSdk.h
//  Pangle Ads SDK
//
//  Copyright 2022 ByteDance Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PAGConfig.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PAGSDKInitializationState) {
    PAGSDKInitializationStateNotReady = 0,
    PAGSDKInitializationStateReady = 1
};

typedef void (^PAGAdsCompletionHandler)(BOOL success, NSError * __nullable error);

@class PAGBiddingRequest;
@interface PAGSdk : NSObject

/// Pangle SDK version
@property (nonatomic, copy, readonly, class) NSString *SDKVersion;

/// The SDK initialization state
@property (nonatomic, assign, readonly, class) PAGSDKInitializationState initializationState;

/// Starts the Pangle SDK
/// @warning Call this method as early as possible to reduce  ad request fail.
/// @param config SDK configuration
/// @param completionHandler Callback for starting the Pangle SDK
+ (void)startWithConfig:(PAGConfig *)config completionHandler:(nullable PAGAdsCompletionHandler)completionHandler;

/// Get bidding token asynchronously
/// @param request An instance of a  bidding request.
/// @param completion Callback to return the bidding token.
+ (void)getBiddingTokenWithRequest:(nullable PAGBiddingRequest *)request
             completion:(void (^)(NSString * biddingToken))completion;


/// Get bidding token asynchronously with error info
/// @param request t An instance of a  bidding request.
/// @param completionHandler Callback to return the bidding token and error info. If the bidding token is obtained successfully, the error parameter will be nil.
+ (void)getBiddingTokenWithRequest:(nullable PAGBiddingRequest *)request
                 completionHandler:(void (^)(NSString * _Nullable biddingToken, NSError * _Nullable error))completionHandler;

/// Set a ad revenue info obtained from mediation.
/// You can get sample code from the Pangle platform to learn how to use this method.
/// @param adRevenue Assemble a dictionary of ad revenue info.
+ (void)setAdRevenue:(NSDictionary *)adRevenue;

@end

NS_ASSUME_NONNULL_END
