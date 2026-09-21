
//  PAGThreadSafeDictionary.h
//  Created by Siwant on 2018/1/22.
//  Copyright © 2018年 bytedance. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAGThreadSafeDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
- (nullable ObjectType)objectForKey:(KeyType)aKey;
- (id)valueForKey:(KeyType)aKey;
- (void)setObject:(ObjectType)object forKey:(KeyType)aKey;
- (void)setValue:(nullable ObjectType)value forKey:(NSString *)key;
- (void)removeAllObjects;
- (void)removeObjectForKey:(KeyType)aKey;
- (NSDictionary<KeyType, ObjectType> *)dictionary;
- (NSArray<KeyType> *)allKeys;
- (NSArray<ObjectType> *)allValues;
- (void)removeObjectsForKeys:(NSArray<KeyType> *)keyArray;
@end

NS_ASSUME_NONNULL_END
