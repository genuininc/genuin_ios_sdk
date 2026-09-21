//
//  PAGNetInfoHelper.h
//  BUAdSDK
//
//  Created by 曹清然 on 2017/5/27.
//  Copyright © 2017年 chenren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PAGReachability.h"
#import <CoreTelephony/CTTelephonyNetworkInfo.h>

@class CTTelephonyNetworkInfo;

NS_ASSUME_NONNULL_BEGIN

CTTelephonyNetworkInfo *PAGDefaultTelephonyNetworkInfo(void);

@interface PAGNetInfoHelper : NSObject

///@Warning :  该api的改动需要同步到 PAGBaseRequest 中  --zth
+ (nullable NSString *)bu_userAgentString;

/// 网络连接状态的字符串描述
+ (NSString *)GetNetWorkType;

+ (PAGNetWorkTypeCode)GetNetWorkTypeCode;

/// 获取IP地址
+ (nullable NSDictionary *)bu_getIPAddresses;

/**
 *  @param preferIPv4 是否ipv4格式
 *  @return ip地址
 */
+ (NSString *)bu_getIPAddress:(BOOL)preferIPv4;

@end

NS_ASSUME_NONNULL_END
