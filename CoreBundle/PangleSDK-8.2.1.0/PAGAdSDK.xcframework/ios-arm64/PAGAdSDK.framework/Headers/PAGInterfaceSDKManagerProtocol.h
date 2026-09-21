//
//  PAGInterfaceSDKManagerProtocol.h
//  PAGAdSDK
//
//  Created by bytedance on 2023/3/2.
//
// !!!: 这个是private, 需要在生成头文件后删除

#import <Foundation/Foundation.h>
#import "PAGSdkEnumHeader.h"

NS_ASSUME_NONNULL_BEGIN

@class PAGUserInfoForSegment;
@class PAGMPreloadRequestInfo;

typedef void (^PAGInterfaceSDKInitCompletionHandler)(BOOL success,NSError * _Nullable error);

@protocol PAGInterfaceSDKManagerGetPangleInfoDelegate <NSObject>

- (NSInteger)getCoppa;
- (NSInteger)getGdpr;
- (NSInteger)GDPRConsent;
- (NSInteger)getCcpa;
- (NSInteger)getPersonalizedAd;
- (NSInteger)getGcfGdpr;
- (NSString *)getTcstring;
- (NSInteger)getLmt;
- (NSArray <NSString *>*)getSelectiveInitAdns;
- (NSArray <NSString *>*)getDisableInitAdns;
- (NSInteger)getPersonalizedAdNew;
- (BOOL)isInValidPersonalizedAdNew;
- (BOOL)isSDKDisabled;
- (NSString *)sdkVersion;

// MARK: - cypher
- (nullable NSString *)encryptToStringWithDictionary:(NSDictionary *)dictionary error:( NSError * _Nullable *)error;
- (nullable NSDictionary *)decryptToDictionaryWithString:(NSString *)string;

@end

@protocol PAGInterfaceSDKManagerProtocol <NSObject>

/// Starts the  SDK
/// @warning Call this method as early as possible to reduce  ad request fail.
/// @param completionHandler Callback for starting the Pangle SDK
+ (void)startWithAppId:(NSString *)appId completionHandler:(nullable PAGInterfaceSDKInitCompletionHandler)completionHandler;

// MARK: - 设置配置 参考Pangle API PAGConfig
+ (void)setAppID:(NSString *)appID;

+ (void)setDebugLog:(BOOL)debugLog;

////这个方法不用映射,因为使用的是pangle对外API,只要外部设置了,开屏就可以获取对应的图片
//+ (void)setAppLogoImage:(UIImage *)appLogoImage;

//+ (void)setThemeStatus:(NSInteger)themeStatus;

+ (void)setCustomLocalConfig:(NSString *)customLocalConfig;

+ (void)setUserInfoForSegment:(PAGUserInfoForSegment *)userInfo;

+ (void)setMaxSegment:(NSDictionary<NSNumber*, NSArray<NSNumber *> *> *)maxSegments;

+ (BOOL)isMediationSlotId:(NSString *)slotId;

+ (NSString *)customLocalConfig;

// MARK: - 获取隐私协议
+ (void)setDelegate:(id<PAGInterfaceSDKManagerGetPangleInfoDelegate>)delegate;

+ (void)preloadAdsWithInfos:(NSArray<__kindof PAGMPreloadRequestInfo *> *)infos andInterval:(NSInteger)interval andConcurrent:(NSInteger)concurrent;

// MARK: - 测试工具
+ (BOOL)isTestModeDirectMediaAd:(NSDictionary *)extraInfo;

// MARK: - 其他
+ (BOOL)hasConfig;

/// 当前区域是否可发起请求
+ (BOOL)isMediationWorkable;

/// 上报m_init 埋点
/// - Parameters:
///   - type: 即 init_type   1:调用初始化Pangle ADN     2:调用初始化Pangle m
///   - userData: userData信息, eg:[{\"name\":\"mediation\",\"value\":\"panglem\"},{\"name\":\"adapter_version\",\"value\":\"%@\"}]
+ (void)trackMInitWithType:(NSInteger)type userData:(NSString *)userData;

@end

NS_ASSUME_NONNULL_END
