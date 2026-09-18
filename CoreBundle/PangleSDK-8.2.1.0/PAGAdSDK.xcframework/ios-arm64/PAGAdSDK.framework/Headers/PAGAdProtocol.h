//
//  PAGAdProtocol.h
//  Pangle Ads SDK
//
//  Copyright 2022 ByteDance Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PAGAdProtocol <NSObject>

/// Returns the value corresponding to the specified key
/// - Parameter key: The value key
- (nullable id)getExtraInfoWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
