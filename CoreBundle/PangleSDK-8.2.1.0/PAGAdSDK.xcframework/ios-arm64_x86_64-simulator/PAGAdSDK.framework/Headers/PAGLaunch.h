//
//  PAGLaunch.h
//  PAGAdSDK
//
//  Created by ByteDance on 2025/9/24.
//

#import <Foundation/Foundation.h>
#import "PAGInnerHeader.h"

NS_ASSUME_NONNULL_BEGIN

/**
 app启动状态判断
 */
@interface PAGLaunch : NSObject

/// 获取设备启动状态
+ (PAGLaunchType)deviceLaunchType;

@end

NS_ASSUME_NONNULL_END
