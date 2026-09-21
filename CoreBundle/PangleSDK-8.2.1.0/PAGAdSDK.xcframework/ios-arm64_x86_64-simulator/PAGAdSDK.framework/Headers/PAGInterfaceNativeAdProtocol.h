//
//  PAGInterfaceNativeAdProtocol.h
//  PAGAdSDK
//
//  Created by bytedance on 2023/4/10.
//
// !!!: 这个是private, 需要在生成头文件后删除

#import "PAGInterfaceBaseAdProtocol.h"
#import "PAGNativeAdAssetIdentifier.h"
#import "PAGLImage.h"
#import "PAGSdkEnumHeader.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PAGInterfaceNativeAdProtocol <PAGInterfaceBaseAdProtocol>

@property (nonatomic, strong, readonly, nullable) PAGLImage *icon;

@property (nonatomic, copy, readonly, nullable) NSString *AdTitle;

@property (nonatomic, copy, readonly, nullable) NSString *AdDescription;

@property (nonatomic, copy, readonly, nullable) NSString *buttonText;

@property (nonatomic, assign, readonly) PAGLNativeMediaType mediaType;

@property (nonatomic, strong, readonly, nullable) UIView *dislikeButton;

@property (nonatomic, strong, readonly, nullable) UIView *logoADImageView;

@property (nonatomic, strong, readonly, nullable) UIView *adChoicesView;

@property (nonatomic, strong, readonly, nullable) UIView *mediaView;

- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews
               buildViews:(nullable NSDictionary<PAGNativeAdAssetIdentifier,UIView *> *)buildViews;

- (void)unregisterView;

@optional

/// 获取logoADImageView最终size
/// - Parameter finalSizeBlock: size回调
- (void)registerGetFinalLogoADImageViewSize:(void(^)(CGSize size))finalSizeBlock;

@end

NS_ASSUME_NONNULL_END
