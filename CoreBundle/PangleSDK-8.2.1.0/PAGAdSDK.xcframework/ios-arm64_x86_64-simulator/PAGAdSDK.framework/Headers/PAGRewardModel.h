//
//  PAGRewardModel.h
//  Pangle Ads SDK
//
//  Copyright 2022 ByteDance Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAGRewardModel : NSObject

@property (nonatomic, copy, readonly) NSString *rewardName;
@property (nonatomic, assign, readonly) NSInteger rewardAmount;

- (instancetype)initWithRewardName:(NSString *)rewardName rewardAmount:(NSInteger)rewardAmount;

@end

NS_ASSUME_NONNULL_END
