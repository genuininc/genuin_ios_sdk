//
//  PAGBaseRequest.h
//  PAGAdSDK
//
//  Created by Chuanqi on 2/12/25.
//

#import <Foundation/Foundation.h>
#import "PAGInnerHeader.h"

NS_ASSUME_NONNULL_BEGIN

///  HTTP Request method.
typedef NS_ENUM(NSInteger, PAGRequestMethod) {
    PAGRequestMethod_GET     = 0,
    PAGRequestMethod_POST    = 1
};

///  Request serializer type.
typedef NS_ENUM(NSInteger, PAGRequestSerializerType) {
    PAGRequestSerializerType_HTTP        = 0,
    PAGRequestSerializerType_JSON        = 1,
};

///  Response serializer type, which determines response serialization process and
///  the type of `responseObject`.
typedef NS_ENUM(NSInteger, PAGResponseSerializerType) {
    /// NSData type
    PAGResponseSerializerType_HTTP       = 0,
    /// JSON object type
    PAGResponseSerializerType_JSON       = 1,
    /// XML object type
    PAGResponseSerializerType_XML        = 2,
};

@class PAGBaseRequest,PAGBusMonitorParamsMaker;

typedef void(^PAGRequestCompletionBlock)(__kindof PAGBaseRequest *request);

@interface PAGBaseRequest : NSObject

///  The underlying NSURLSessionTask.
///
///  @warning This value is actually nil and should not be accessed before the request starts.
@property (nonatomic, strong) NSURLSessionTask *requestTask;
@property (nonatomic, strong) id responseObject;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, assign) PAGRequestMethod requestMethod;
@property (nonatomic, assign) PAGRequestSerializerType requestSerializerType;
@property (nonatomic, assign) PAGResponseSerializerType responseSerializerType;

/// 7900 added, backup url list and total timeout
@property (nonatomic, copy) NSString *initialURL;
@property (nonatomic, copy, nullable) NSArray <NSString *> *backupURLs;
@property(nonatomic, strong, nullable) NSNumber *totalTimeoutValue;

/// For post method, set the parameter as dictionary or hex data.
@property (nonatomic, strong) id parameter;

///  The success callback. This block
///  will be called on the main queue.
@property (nonatomic, copy, nullable) PAGRequestCompletionBlock successCompletionBlock;

///  The failure callback. This block
///  will be called on the main queue.
@property (nonatomic, copy, nullable) PAGRequestCompletionBlock failureCompletionBlock;

///  Additional HTTP request header field.
- (nullable NSDictionary<NSString *, NSString *> *)requestHeaderFieldValueDictionary;

///  Request cache policy.
- (NSURLRequestCachePolicy)bu_requestCachePolicy;

- (NSString *)requestUrl;
- (NSString *)baseUrl;
- (PAGSeconds)requestTimeoutInterval;
#pragma mark - Request Action
///=============================================================================
/// @name Request Action
///=============================================================================

///  Append self to request queue and start the request.
- (void)start;

///  Remove self from request queue and cancel the request.
- (void)stop;

///  Convenience method to start the request with block callbacks.
- (void)startWithCompletionBlockWithSuccess:(nullable PAGRequestCompletionBlock)success
                                    failure:(nullable PAGRequestCompletionBlock)failure;

///  Return cancelled state of request task.
@property (nonatomic, readonly, getter=isCancelled) BOOL cancelled;

///  Executing state of request task.
@property (nonatomic, readonly, getter=isExecuting) BOOL executing;

///  Time the request starts.
@property (nonatomic, assign) PAGSeconds startTime;

/// 业务侧稳定性监控（BusMonitor）的需要上传的参数
/// @warning:请求前传递,不允许修改
@property (nonatomic, strong, nullable) PAGBusMonitorParamsMaker *monitorMaker;

@end

NS_ASSUME_NONNULL_END
