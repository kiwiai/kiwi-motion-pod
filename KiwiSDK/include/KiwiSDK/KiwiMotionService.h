//
//  KiwiMotionService.h
//  KiwiSDK
//
//  Created by Kiwi Wearable Technologies Ltd. on 2014-04-26.
//  Copyright (c) 2014 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>

#define kKIWI_SOFT_TAP_NOTIFICATION @"KIWI_SOFT_TAP_NOTIFICATION"
#define kKIWI_WAVE_NOTIFICATION @"KIWI_WAVE_NOTIFICATION"
#define kKIWI_KNOCK_NOTIFICATION @"KIWI_KNOCK_NOTIFICATION"

@interface KiwiMotionService : NSObject

@property (strong, nonatomic) CMMotionManager* motionManager;
@property (strong, nonatomic) CMDeviceMotion *referenceDeviceMotion;

@property (nonatomic) NSUInteger rollingMotionDataSampleSize;
@property (strong, nonatomic) NSMutableArray* rollingMotionDataArray;

@property (nonatomic) int softtapSensitivity; //set between 10 - 20
@property (nonatomic) int knockSensitivity; //set between 60 - 90
@property (nonatomic) int waveSensitivity; //set between -5 and -15

+ (id)sharedInstance;
- (instancetype) init;

- (void) startMotionDetection;
- (void) stopMotionDetection;

#pragma mark - Motion Tap, Knock, Wave Methods

- (void) addSoftTapObserver:(id)object withSelector:(SEL)selector;
- (void) addWaveObserver:(id)object withSelector:(SEL)selector;
- (void) addKnockObserver:(id)object withSelector:(SEL)selector;

@end
