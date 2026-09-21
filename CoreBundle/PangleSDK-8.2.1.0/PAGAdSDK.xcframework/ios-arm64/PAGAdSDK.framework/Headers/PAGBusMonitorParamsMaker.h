//
//  PAGBusMonitorParamsMaker.h
//  PAGAdSDK
//
//  Created by yy on 3/6/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PAGMonitorServiceStatus) {
    PAGMonitorServiceStatus_None    = 0,
    PAGMonitorServiceStatus_Start   = 1,
    PAGMonitorServiceStatus_Success = 2,
    PAGMonitorServiceStatus_Fail    = 3,
};

@interface PAGBusMonitorParamsMaker : NSObject

@property (nonatomic, copy, nullable) NSString *extra;
@property (nonatomic, copy, nullable) NSString *sdk_version;
@property (nonatomic, copy, nullable) NSString *rit;
@property (nonatomic, copy, nullable) NSString *tag;
@property (nonatomic, copy, nullable) NSString *label;
@property (nonatomic, copy, nullable) NSString *mediation;
@property (nonatomic, strong, nullable) NSNumber *is_init;

@end

NS_ASSUME_NONNULL_END
