//
//  PAGLMaterialMeta.h
//  Pangle Ads SDK
//
//  Copyright 2022 ByteDance Ltd. All rights reserved.
//

#import "PAGSdkEnumHeader.h"

NS_ASSUME_NONNULL_BEGIN

@class PAGLImage;

/// A class that encapsulates advertising information
@interface PAGLMaterialMeta : NSObject

/// ad logo icon.
@property (nonatomic, strong, readonly) PAGLImage *icon;

/// ad headline.
@property (nonatomic, copy, readonly) NSString *AdTitle;

/// ad description.
@property (nonatomic, copy, readonly) NSString *AdDescription;

/// text displayed on the creative button.
@property (nonatomic, copy, readonly) NSString *buttonText;

/// media type of ad
@property (nonatomic, assign, readonly) PAGLNativeMediaType mediaType;

@end

NS_ASSUME_NONNULL_END
