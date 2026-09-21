//
//  PAGInterfaceBaseAdEventDelegate.h
//  PangleAPI
//
//  Created by bytedance on 2022/9/28.
//

#import "PAGInterfaceBaseAdProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class PAGRewardModel,PAGAdEcpmInfo;
@protocol PAGInterfaceBaseAdProtocol,PAGInterfaceRewardedAdProtocol;

@protocol PAGInterfaceBaseAdEventDelegate <NSObject>

- (void)adDidShow:(id<PAGInterfaceBaseAdProtocol>)adapter;

- (void)adDidClick:(id<PAGInterfaceBaseAdProtocol>)adapter;
 
- (void)adDidDismiss:(id<PAGInterfaceBaseAdProtocol>)adapter;

@optional

- (void)adDidShowFail:(id<PAGInterfaceBaseAdProtocol>)adapter error:(NSError *)error;

- (void)adDidReturnRevenue:(id<PAGInterfaceBaseAdProtocol>)adapter info:(PAGAdEcpmInfo *)revenueInfo;

@end

//MARK: Banner ad 事件代理
@protocol PAGInterfaceBannerAdEventDelegate <PAGInterfaceBaseAdEventDelegate>

@end

//MARK: open ad 事件代理
@protocol PAGInterfaceAppOpenAdEventDelegate <PAGInterfaceBaseAdEventDelegate>


@end

//MARK: Interstitial 事件代理
@protocol PAGInterfaceInterstitialAdEventDelegate <PAGInterfaceBaseAdEventDelegate>

@end

//MARK: Rewarded 事件代理
@protocol PAGInterfaceRewardedAdEventDelegate <PAGInterfaceBaseAdEventDelegate>

- (void)rewardedAd:(id<PAGInterfaceRewardedAdProtocol>)rewardedAd userDidEarnReward:(PAGRewardModel *)rewardModel;
- (void)rewardedAd:(id<PAGInterfaceRewardedAdProtocol>)rewardedAd userEarnRewardFailWithError:(NSError *)error;


@end

// MARK: native ad 事件代理
@protocol PAGInterfaceNativeAdEventDelegate <PAGInterfaceBaseAdEventDelegate>

@end

NS_ASSUME_NONNULL_END
