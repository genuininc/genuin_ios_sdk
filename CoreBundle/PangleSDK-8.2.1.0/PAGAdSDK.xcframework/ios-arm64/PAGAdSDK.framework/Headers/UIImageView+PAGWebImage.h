//
//  UIImageView+PAGWebImage.h
//  PAGWebImage
//
//  Created by Kevin on 2025/2/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImageView (PAGWebImage)

/// Load image from URL
/// @param url The URL of image
- (void)pag_setImageWithURL:(nonnull NSURL *)url;

/// Load image from URL with placeholder and completion callback
/// @param url The URL of image
/// @param completion completion callback
- (void)pag_setImageWithURL:(nonnull NSURL *)url completion:(nullable void(^)(UIImage * _Nullable image, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END 
