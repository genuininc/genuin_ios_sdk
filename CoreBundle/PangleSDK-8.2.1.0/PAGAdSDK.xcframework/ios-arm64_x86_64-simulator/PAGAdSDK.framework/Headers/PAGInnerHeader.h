//
//  PAGInnerHeader.h
//  PAGAdSDK
//
//  Created by yy on 11/5/25.
//
// !!!: - ADN和SDK 共用的头文件，不要引入其他文件

#ifndef PAGInnerHeader_h
#define PAGInnerHeader_h

typedef NSTimeInterval PAGSeconds;
typedef NSInteger PAGMilliseconds;

typedef NS_ENUM(NSInteger, PAGLaunchType) {
    PAGLaunchType_Unknown    = 0, ///< 默认, 未知状态
    PAGLaunchType_Col        = 1, ///< 冷启动状态, 即app启动时新建了线程
    PAGLaunchType_Hot        = 2, ///< 热启动状态, 即app启动时未新建线程

};

// 常用关联策略的快捷宏（可选，简化调用）
#define PAGM_ASSOCIATION_COPY OBJC_ASSOCIATION_COPY_NONATOMIC
#define PAGM_ASSOCIATION_RETAIN OBJC_ASSOCIATION_RETAIN_NONATOMIC

// objc 定义setter和getter的宏（参数：属性名、首字母大写属性名、类型、关联策略）
#define PAGM_SYNTHESIZE_CATEGORY_OBJ_PROPERTY(propertyName,capitalizeFirstPropertyName, propertyType, associationPolicy) \
static const void *PAGMk##propertyName##CategoryKey = &PAGMk##propertyName##CategoryKey; \
- (void)set##capitalizeFirstPropertyName:(propertyType)propertyName { \
    objc_setAssociatedObject(self, PAGMk##propertyName##CategoryKey, propertyName, associationPolicy); \
} \
- (propertyType)propertyName { \
    return objc_getAssociatedObject(self, PAGMk##propertyName##CategoryKey); \
}

// 基础类型 定义setter和getter的宏（参数：属性名、类型、关联策略）
#define PAGM_SYNTHESIZE_CATEGORY_PRIMITIVE_PROPERTY(propertyName,capitalizeFirstPropertyName, propertyType, numberGetter) \
static const void *PAGMk##propertyName##CategoryKey = &PAGMk##propertyName##CategoryKey; \
- (void)set##capitalizeFirstPropertyName:(propertyType)propertyName { \
objc_setAssociatedObject(self, PAGMk##propertyName##CategoryKey, @(propertyName), PAGM_ASSOCIATION_RETAIN); \
} \
- (propertyType)propertyName { \
NSNumber *value = objc_getAssociatedObject(self, PAGMk##propertyName##CategoryKey); \
return value ? value.numberGetter : 0; \
}


#endif /* PAGInnerHeader_h */
