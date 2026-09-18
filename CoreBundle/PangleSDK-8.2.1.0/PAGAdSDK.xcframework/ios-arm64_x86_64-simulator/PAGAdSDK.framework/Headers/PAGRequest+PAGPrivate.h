//
//  PAGRequest+PAGPrivate.h
//  PAGAdSDK
//
//  Created by bytedance on 2022/11/8.
//

#import "PAGRequest.h"
#import "PAGRequestDefines.h"

NS_ASSUME_NONNULL_BEGIN
@protocol PAGMAdNetworkExtras;

@interface PAGRequest (PAGPrivate)

- (NSDictionary<NSString *,id<PAGMAdNetworkExtras>> *)getAdNetworkExtras;

- (PAGMuteStatus)getMuteStatus;

@end

NS_ASSUME_NONNULL_END
