//
//  PAGUserAgentHelper.h
//  BUAdSDK
//
//  Created by cuiyanan on 2019/9/3.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PAGUserAgentHelper : NSObject
// !!!: yy 这个方法先注释
//PAG_SINGLETION(PAGUserAgentHelper);
+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

- (NSString *)userAgent;
- (NSString *)customUserAgent;

@end

