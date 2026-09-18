//
//  PAGAdDelegate.h
//  Pangle Ads SDK
//
//  Copyright 2022 ByteDance Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class PAGAdEcpmInfo;
@protocol PAGAdProtocol;

@protocol PAGAdDelegate <NSObject>

@optional

/// This method is called when the ad has been shown
- (void)adDidShow:(id<PAGAdProtocol>)ad;

/// This method is called when the add has been clicked
- (void)adDidClick:(id<PAGAdProtocol>)ad;

///This method is called when the ad has been dismissed.
- (void)adDidDismiss:(id<PAGAdProtocol>)ad;

///This method is called when the ad has been show fail
- (void)adDidShowFail:(id<PAGAdProtocol>)ad error:(NSError *)error DEPRECATED_MSG_ATTRIBUTE("This method is deprecated");

@end

NS_ASSUME_NONNULL_END
