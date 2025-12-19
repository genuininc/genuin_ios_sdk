#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "RSCrashReporter.h"
#import "RSCrashReporterApp.h"
#import "RSCrashReporterAppWithState.h"
#import "RSCrashReporterBreadcrumb.h"
#import "RSCrashReporterClient.h"
#import "RSCrashReporterConfiguration.h"
#import "RSCrashReporterDefines.h"
#import "RSCrashReporterDevice.h"
#import "RSCrashReporterDeviceWithState.h"
#import "RSCrashReporterEndpointConfiguration.h"
#import "RSCrashReporterError.h"
#import "RSCrashReporterErrorTypes.h"
#import "RSCrashReporterEvent.h"
#import "RSCrashReporterFeatureFlag.h"
#import "RSCrashReporterFeatureFlagStore.h"
#import "RSCrashReporterLastRunInfo.h"
#import "RSCrashReporterMetadata.h"
#import "RSCrashReporterMetadataStore.h"
#import "RSCrashReporterPlugin.h"
#import "RSCrashReporterSession.h"
#import "RSCrashReporterStackframe.h"
#import "RSCrashReporterThread.h"
#import "RSCrashReporterUser.h"
#import "RSC_KSCrashReportWriter.h"

FOUNDATION_EXPORT double RSCrashReporterVersionNumber;
FOUNDATION_EXPORT const unsigned char RSCrashReporterVersionString[];

