//
//  NSObject+PAGYYModel.h
//  PAGYYModel
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

/*
* This file may have been modified by ByteDance Ltd.
* Original Files：YYClassInfo/YYModel (https://github.com/ibireme/YYModel)
* Copyright 2015 ibireme.
* SPDX-License-Identifier: MIT
*/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (PAGYYModel)

+ (nullable instancetype)PAGYY_modelWithDictionary:(NSDictionary *)dictionary;

- (BOOL)PAGYY_modelSetWithDictionary:(NSDictionary *)dic;
- (nullable id)PAGYY_modelToJSONObject;

@end

@protocol PAGYYModel <NSObject>
@optional

+ (nullable NSDictionary<NSString *, id> *)modelCustomPropertyMapper;

+ (nullable NSDictionary<NSString *, id> *)modelContainerPropertyGenericClass;

+ (nullable Class)modelCustomClassForDictionary:(NSDictionary *)dictionary;

+ (nullable NSArray<NSString *> *)modelPropertyBlacklist;

+ (nullable NSArray<NSString *> *)modelPropertyWhitelist;

- (NSDictionary *)modelCustomWillTransformFromDictionary:(NSDictionary *)dic;

- (BOOL)modelCustomTransformFromDictionary:(NSDictionary *)dic;

- (BOOL)modelCustomTransformToDictionary:(NSMutableDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
