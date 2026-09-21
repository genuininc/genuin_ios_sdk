//
//  NSJSONSerialization+BUSafeSerializaiton.h
//  BUFoundation
//
//  Created by bytedance on 2020/10/10.
//  Copyright © 2020 Union. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSJSONSerialization (PAGSafeSerializaiton)
+ (nonnull NSString *)pag_stringJsonSerializationWithObject:(id)object options:(NSJSONWritingOptions)opt error:(NSError **)error;
+ (nullable NSData *)pag_dataJsonSerializationWithObject:(id)object options:(NSJSONWritingOptions)opt error:(NSError **)error;
+ (nullable id)pag_jsonObjWithJSONString:(NSString *)string error:(NSError **)error;
@end

NS_ASSUME_NONNULL_END
