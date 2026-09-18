//
//  PAGLImage.h
//  Pangle Ads SDK
//
//  Copyright 2022 ByteDance Ltd. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/// A class that encapsulates image information
@interface PAGLImage : NSObject

/// image address URL
@property (nonatomic, copy, readonly) NSString *imageURL;

/// image width
@property (nonatomic, assign, readonly) CGFloat width;

/// image height
@property (nonatomic, assign, readonly) CGFloat height;

@end

NS_ASSUME_NONNULL_END
