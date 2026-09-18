//
//  NSString+URLEncoding.h
//  BUAdSDK
//
//  Created by carl on 2017/10/26.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (PAG_URLCoding)

- (nullable NSString *)pag_URLEncodedString;
- (nullable NSString *)pag_URLDecodedString;

- (nullable NSString *)pag_URLEncodedStringWithCustomSet;

@end

@interface NSString (PAG_Encryption)
/**
 * @brief 返回自身的md5
 * @return 返回自身的md5的16进制字串
 */
- (nullable NSString *)pag_MD5HashString;
@end

@interface NSString (PAG_NumberToWan)

/// 大于1w就用k表示，不大于就直接展示多少个评分
+ (NSString *)pag_numberToThousand:(NSInteger)target;

@end

@interface NSString (PAG_URLStringAppend)
/*
 *
 string转URL
 */
+ (nullable NSURL *)pag_URLWithURLString:(NSString *)str;
/*
 *
 string转字典
 */
+ (NSDictionary*)pag_parametersOfURLQueryString:(NSString*)urlString;

/*
 *
 url字符串拼接参数,需要判断是否是第一个
 */
+ (NSString *)pag_urlStringWithOriginUrlString:(NSString *)originUrlString appendParameters:(NSDictionary *)parameters;

+ (NSString *)pag_urlStringWithBaseUrlString:(NSString *)baseUrlString requestURLString:(NSString *)requestURLString;

+ (NSString *)pag_urlStringWithUrlString:(NSString *)urlString parameterString:(NSString *)parameterString;

@end


@interface NSString (PAG_Sandbox)
/**
 *  获取缓存路径
 *
 *  @return path where to cache
 */
- (NSString *)pag_CachePath;

@end


@interface NSString(PAG_JSONValue)


/// Allows parsing of complete JSON strings or fragments of JSON strings, but returns NSDictionary
/// - Parameter error: parsing error
- (nullable id)pag_JSONValue:(NSError **)error;

/// Allows parsing of complete JSON strings or fragments of JSON strings
/// - Parameter error: parsing error
- (nullable id)pag_jsonValueWithError:(NSError **)error;

@end


@interface NSString(PAG_Time)

+ (NSString*)pag_dateNowString;

+ (NSNumber*)pag_currentInterval;

+ (NSDateFormatter*)pag_formatter;

@end

@interface NSString (PAG_Size)

- (CGSize)pag_boundingRectWithSize:(CGSize)size font:(UIFont *)font;

@end

@interface NSString (PAG_CheckingResult)

- (nullable NSString *)pag_substringWithPattern:(NSString *)pattern;

- (BOOL)pag_characterAtIndex:(NSInteger)index writeToChar:(char *)charactor;

- (nullable NSString *)pag_substringToIndex:(NSInteger)index;

- (nullable NSString *)pag_substringWithRange:(NSRange)range;

@end

@interface NSString (PAGAttributedString)

- (NSAttributedString *)pag_attributedStringWithColor:(UIColor *)color
                                               font:(UIFont *)font
                                 lineHeightMultiple:(CGFloat)lineHeightMultiple
                                            alignment:(NSTextAlignment)alignment;

@end

@interface NSString (Numeric)

- (BOOL)isNumeric;

@end

@interface NSString (PAGURL)

- (NSDictionary<NSString *, NSString *> *)parseURLParameters;

@end

NS_ASSUME_NONNULL_END
