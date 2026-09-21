//
//  PAGInterfaceBaseAdProtocol.h
//  PAGAdSDK
//
//  Created by bytedance on 2022/9/29.
//

#import <UIKit/UIKit.h>
#import "PAGInterfaceBaseAdEventDelegate.h"
#import "PAGAdSize.h"

@class PAGRequest,PAGAdEcpmInfo;

@protocol PAGInterfaceBaseAdProtocol, PAGInterfaceBaseAdEventDelegate;
NS_ASSUME_NONNULL_BEGIN

typedef id<PAGInterfaceBaseAdEventDelegate>_Nullable (^PAGFactoryBaseAdCompletionHandler)(id<PAGInterfaceBaseAdProtocol> _Nullable ad,NSError * _Nullable error);

@protocol PAGInterfaceBaseAdProtocol <NSObject>

@property (nonatomic, weak) UIViewController *rootViewController;

- (instancetype)initWithSlotID:(NSString *)slotID;
- (void)loadAdWithRequest:(PAGRequest *)request
       completionHandler:(PAGFactoryBaseAdCompletionHandler)completionHandler;
- (nullable id)getExtraInfoWithKey:(NSString *)key;

@optional

- (BOOL)isReady;
- (nullable PAGAdEcpmInfo *)getWinEcpm;
- (nullable PAGAdEcpmInfo *)getShowEcpm;

@end

//MARK: - banner
@protocol PAGInterfaceBannerAdProtocol <PAGInterfaceBaseAdProtocol>

- (UIView *)bannerView;
- (PAGBannerAdSize)adSize;

@end

//MARK: - appOpenAd

@protocol PAGInterfaceAppOpenAdProtocol <PAGInterfaceBaseAdProtocol>

///@param rootViewController rootViewController
///@param extraInfo the extra information is displayed in the Show stage. This information will be merged with request.extrainfo, and the value of the same key will be overwritten.
- (void)presentFromRootViewController:(UIViewController *)rootViewController extraInfo:(NSDictionary *_Nullable)extraInfo;

@end

//MARK: - Interstitial
@protocol PAGInterfaceInterstitialAdProtocol <PAGInterfaceBaseAdProtocol>

///@param rootViewController rootViewController
///@param extraInfo the extra information is displayed in the Show stage. This information will be merged with request.extrainfo, and the value of the same key will be overwritten.
- (void)presentFromRootViewController:(UIViewController *)rootViewController extraInfo:(NSDictionary *_Nullable)extraInfo;

@end

//MARK: - rewarded
@protocol PAGInterfaceRewardedAdProtocol <PAGInterfaceBaseAdProtocol>

///@param rootViewController rootViewController
///@param extraInfo the extra information is displayed in the Show stage. This information will be merged with request.extrainfo, and the value of the same key will be overwritten.
- (void)presentFromRootViewController:(UIViewController *)rootViewController extraInfo:(NSDictionary *_Nullable)extraInfo;

@end



NS_ASSUME_NONNULL_END

