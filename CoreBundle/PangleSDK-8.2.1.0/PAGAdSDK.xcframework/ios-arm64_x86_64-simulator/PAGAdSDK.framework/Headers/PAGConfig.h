//
//  PAGConfig.h
//  Pangle Ads SDK
//
//  Copyright 2022 ByteDance Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PAGPAConsentType) {
    PAGPAConsentTypeNoConsent   =  0,   ///< User doesn't grant consent
    PAGPAConsentTypeConsent     =  1,   ///< User has granted the consent
};

NS_ASSUME_NONNULL_BEGIN

///Pangle SDK configuration class
@interface PAGConfig : NSObject

///appId the unique identifier of the App
///@warning required
@property (nonatomic, copy) NSString *appID;

///adxID: the mediation ID
@property (nonatomic, copy) NSString *adxID;

/// Custom set the debugLog to print debug Log.
/// debugLog NO: close debug log, YES: open debug log.
@property (nonatomic, assign) BOOL debugLog;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
/// Initialization method of PAGConfig
+ (instancetype)shareConfig;

@end

@interface PAGConfig (Settings)

/// Set whether the user consents to be served Personalized Ads.
@property (nonatomic, assign) PAGPAConsentType PAConsent;

/// additional user information.
@property (nonatomic, copy) NSString *userDataString;

///Whether to allow SDK to modify the category and options of AVAudioSession when playing audio, default is NO.
///The category set by the SDK is AVAudioSessionCategoryAmbient, and the options are AVAudioSessionCategoryOptionDuckOthers
@property (nonatomic, assign) BOOL allowModifyAudioSessionSetting;

@end

NS_ASSUME_NONNULL_END
