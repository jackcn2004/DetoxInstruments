//
//  DTXProfilingConfiguration.h
//  DTXProfiler
//
//  Created by Leo Natan (Wix) on 06/07/2017.
//  Copyright © 2017 Wix. All rights reserved.
//

@import Foundation;

@class DTXMutableProfilingConfiguration;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Profiling configuration object for the Profiler.
 */
@interface DTXProfilingConfiguration : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>

- (instancetype)copy;
- (__kindof DTXMutableProfilingConfiguration*)mutableCopy;

/**
 *  Returns a newly created default profiling configuration object.
 */
+ (instancetype)defaultProfilingConfiguration;

/**
 *  Returns a newly created default profiling configuration object fore remote profiling.
 */
+ (instancetype)defaultProfilingConfigurationForRemoteProfiling;

// Sampling Configuration

/**
 *  The sampling interval of the Profiler.
 *
 *  The default value is 1.0.
 */
@property (nonatomic, readonly) NSTimeInterval samplingInterval;

/**
 *  The minimum number of samples to keep in memory before flushing to disk.
 *
 *  Larger number of samples in memory will improve performance at the cost of memory use.
 *
 *  The default value is @c 200.
 */
@property (nonatomic, readonly) NSUInteger numberOfSamplesBeforeFlushToDisk;

//Recording Configuration

/**
 *  Collect the names of open files for each sample.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readonly) BOOL collectOpenFileNames;

/**
 *  Record network requests during profiling.
 *
 *  The default value is @c true.
 */
@property (nonatomic, readonly) BOOL recordNetwork;

/**
 *  Record localhost network requests during profiling.
 *
 *  Only relevant if @c recordNetwork is set to @c true.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readonly) BOOL recordLocalhostNetwork;

/**
 *  Disables cache for network requests.
 *
 *  Only relevant if @c recordNetwork is set to @c true.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readonly) BOOL disableNetworkCache;

/**
 *  Record thread information during profiling.
 *
 *  The default value is @c true.
 */
@property (nonatomic, readonly) BOOL recordThreadInformation;

/**
 *  Collect stack trace information where appropriate.
 *
 *  Collecting stack traces may introduce some performance hit.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readonly) BOOL collectStackTraces;

/**
 *  Symbolicate stack traces at runtime.
 *
 *  Symbolicating stack traces may introduce some performance hit.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readonly) BOOL symbolicateStackTraces;

/**
 *  Record log output during profiling.
 *
 *  The default value is @c true.
 */
@property (nonatomic, readonly) BOOL recordLogOutput;

/**
 *  Profile React Native application.
 *
 *  Currently, only one active React Native bridge is supported.
 *  If you have different needs, open an issue at @ref https://github.com/wix/DetoxInstruments/issues
 *
 *  The default value is @c true.
 */
@property (nonatomic, readonly) BOOL profileReactNative;

/**
 *  Record React Native bridge data during profiling.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readonly) BOOL recordReactNativeBridgeData;

/**
 *  Record React Native timers (created using @c setTimeout() in Java Script) as events.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readonly) BOOL recordReactNativeTimersAsEvents;

/* Output Configuration */

/**
 *  The recording file URL to save to.
 *
 *  If this URL is a directory URL, a new recording will be created in that directory with the date and time of the recording.
 *
 *  If the URL is a file URL, a new recording will be created with that name.
 *
 *  The extension of the recording package is always @c .dtxprof.
 *
 *  If set to @c nil, the value will reset to the default value.
 *
 *  The default value is a file name with the date and time of the recording, in the documents folder of the device.
 */
@property (nonatomic, copy, null_resettable, readonly) NSURL* recordingFileURL;

@end

#pragma mark -

/**
 *  Profiling configuration object for the Profiler.
 */
@interface DTXMutableProfilingConfiguration : DTXProfilingConfiguration

/**
 *  The sampling interval of the Profiler.
 *
 *  The default value is 0.5.
 */
@property (nonatomic, readwrite) NSTimeInterval samplingInterval;

/**
 *  The minimum number of samples to keep in memory before flushing to disk.
 *
 *  Larger number of samples in memory will improve performance at the cost of memory use.
 *
 *  The default value is @c 200.
 */
@property (nonatomic, readwrite) NSUInteger numberOfSamplesBeforeFlushToDisk;

//Recording Configuration

/**
 *  Collect the names of open files for each sample.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readwrite) BOOL collectOpenFileNames;

/**
 *  Record network requests during profiling.
 *
 *  The default value is @c true.
 */
@property (nonatomic, readwrite) BOOL recordNetwork;

/**
 *  Record localhost network requests during profiling.
 *
 *  Only relevant if @c recordNetwork is set to @c true.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readwrite) BOOL recordLocalhostNetwork;

/**
 *  Disables cache for network requests.
 *
 *  Only relevant if @c recordNetwork is set to @c true.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readwrite) BOOL disableNetworkCache;

/**
 *  Record thread information during profiling.
 *
 *  The default value is @c true.
 */
@property (nonatomic, readwrite) BOOL recordThreadInformation;

/**
 *  Collect stack trace information where appropriate.
 *
 *  Collecting stack traces may introduce some performance hit.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readwrite) BOOL collectStackTraces;

/**
 *  Symbolicate stack traces at runtime.
 *
 *  Symbolicating stack traces may introduce some performance hit.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readwrite) BOOL symbolicateStackTraces;

/**
 *  Record log output during profiling.
 *
 *  The default value is @c true.
 */
@property (nonatomic, readwrite) BOOL recordLogOutput;

/**
 *  Profile React Native application.
 *
 *  Currently, only one active React Native bridge is supported.
 *  If you have different needs, open an issue at @ref https://github.com/wix/DetoxInstruments/issues
 *
 *  The default value is @c true.
 */
@property (nonatomic, readwrite) BOOL profileReactNative;

/**
 *  Record React Native bridge data during profiling.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readwrite) BOOL recordReactNativeBridgeData;

/**
 *  Record React Native timers (created using @c setTimeout() in Java Script) as events.
 *  Timers will appear as interval events in the Events instrument.
 *
 *  The default value is @c false.
 */
@property (nonatomic, readonly) BOOL recordReactNativeTimersAsEvents;

/* Output Configuration */

/**
 *  The recording file URL to save to.
 *
 *  If this URL is a directory URL, a new recording will be created in that directory with the date and time of the recording.
 *
 *  If the URL is a file URL, a new recording will be created with that name.
 *
 *  The extension of the recording package is always @c .dtxprof.
 *
 *  If set to @c nil, the value will reset to the default value.
 *
 *  The default value is a file name with the date and time of the recording, in the documents folder of the device.
 */
@property (nonatomic, copy, null_resettable, readwrite) NSURL* recordingFileURL;

@end

NS_ASSUME_NONNULL_END
